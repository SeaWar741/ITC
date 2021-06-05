-module(prime).
-export([main/0, print_if_prime/0]).

%
%   This function hasa prime factor that it uses to test numbers
%   as they are received.  Numbers that contain the prime factor
%   are simply dropped.  Other numbers are sent to the next child
%   in the chain.  If any of those child can reject the number as
%   not being prime, they do.  If none of them can, the number is declared 
%   to be prime and displayed.  A new child is added to the end of the list
%   to reject future numbers that have this as a prime factor.
%
%   EvilTeach, Aug 2008
%
print_if_prime() ->
    receive
        % A quit message means shut down the whole chain
        {quit, _N} ->                   

            % Do we have a child?
            case ChildPid = get(child) of

                % No, so we are the last child in the chain
                undefined -> []; 

                % Yes, so we tell the next child to shutdown
                ChildPid -> 
                   ChildPid ! {quit, 0}
            end,

            % Erase my local dictionary 
            erase();

        % Tell the subprocess which prime factor it is to service
        {you_check, N} ->               

            %io:format("~p IS PRIME~n",[N]),

            put(myFactor, N),           
            print_if_prime();          

        % We need to check to see if N is prime
        {check, N} ->

            %io:format("~p check ~p against ~p~n", [self(), N, get(myFactor)]),

            case N rem get(myFactor) of
                
                % a remainder of zero, indicates that is is not a prime
                0       -> [];

                % all other values need shipped off down the chain
                _Other  -> 

                    % Do we have a child to pass it to?
                    case ChildPid = get(child) of

                       % No. So we create one
                       undefined -> 
                                         
                           % Create a child to check this new prime number
                           NewChildPid = spawn(fun prime:print_if_prime/0),

                           % io:format("Created PID ~p for ~p~n",[NewChildPid, N]),

                           % Save it so we can call it later
                           put(child, NewChildPid),

                           % Tell it which number it is responsible for checking N
                           NewChildPid ! {you_check, N};


                       % Yes, so we let the children deal with it
                       ChildPid -> 
                           % io:format("We do have a child~n",[]),
                                           
                           % tell it to check this value
                           ChildPid ! {check, N}
                       end
            end,

            print_if_prime()
    end.
    

generate_primes_from(N, Limit, _child) when N > Limit -> 
    % There are no more values to iterate through
    [];

generate_primes_from(N, Limit, FirstChild) ->

    %io:format("sending ~p~n",[N]),

    % Tell the first child in the chain, to check the next number
    FirstChild ! {check, N},

    % how every so often, we do a short delay to not overflow the message queue
    % 80 seems to be right for my machine for Limit =  10k
    % 20 seems to be right for my machine for Limit = 100k
    case N rem 80
      of 
        0 -> receive
	             after 1 -> ok
	         end;
        _ -> []
    end,


    % Continue processing the next number
    generate_primes_from(N + 1, Limit, FirstChild).


main() ->
    io:format("Prime main begins~n",[]),

    % Create a first child to process a value
    ChildFactors2 = spawn(fun prime:print_if_prime/0),

    % Tell the child to check values for a factor of 2
    ChildFactors2 ! {you_check, 2},

    % Throw a whole range of numbers at the child
    generate_primes_from(2, 5000000, ChildFactors2),

    % Tell the first child to tell the rest of the children to shutdown
    ChildFactors2 ! {quit, 0},

    io:format("Prime main ends~n",[]).