-module(pprimes).

% functions that will be called from command-line must be exported
-export([start/1]).

% functions that will be spawned must be exported
-export([prime/3]).
-export([queue/3]).
-export([accum/1]).

% functions that could be externally testable could be exported
-export([is_prime/1]).
-export([atom_to_integer/1]).
-export([pprimes/2]).

% called from command-line with atoms, e.g. ['10','1000']
start([NProcessesAtom,PLimitAtom]) ->
  NProcesses = atom_to_integer(NProcessesAtom),
  PLimit = atom_to_integer(PLimitAtom),
  T1 = erlang:now(),
  L = pprimes(NProcesses,PLimit),
  T2 = erlang:now(),
  T = timer:now_diff(T2,T1),
  io:format("~w processes computing the ~w primes under ~w took ~w microseconds~n",[NProcesses,length(L),PLimit,T]).

pprimes(NProcesses,PLimit) ->

  % the simple accumulator process will collect the results
  Accum_PID = spawn(pprimes, accum, [[]]),

  % the queue process will serve out the next number to check as a prime
  Queue_PID = spawn(pprimes, queue, [2,PLimit,self()]),

  % spawn the worker processes
  lists:map(fun(X) -> spawn(pprimes, prime, [X,Accum_PID,Queue_PID]) end, lists:seq(1,NProcesses)),

  % wait for the worker processes to signal completion
  wait_primes(NProcesses),

  % when the worker processes are done, tell the queue process to complete
  Queue_PID ! {done},

  % send message to the accumulator process and wait for response
  Accum_PID ! {get_primes, self()},
  receive {primes,L} -> Accum_PID ! {done} end,
  L.

% if there are no more worker processes to wait for...
wait_primes(0) -> noop;

% otherwise keep waiting...
wait_primes(N) ->
  receive
    {done} -> wait_primes(N-1)
  end.

% simple accumulator process:
% when it receives an add_prime message, adds the prime and re-loops with new list
% when it receievs a get_primes message, responds with the current list and re-loops
% when it receives the "done" message, ends.
accum(L) ->
  receive
    {add_prime,P} -> accum([P|L]);
    {get_primes,Client_PID} -> Client_PID ! {primes,L}, accum(L);
    {done} -> noop
  end.

% queue process end case: when the queue is empty, enter the queue_empty function.
queue(Cur,PLimit,Main_PID) when Cur == PLimit ->
  queue_empty(Main_PID);

% queue process main case: wait for next_prime messages and re-enter
queue(Cur,PLimit,Main_PID) ->
  receive
    {next_prime,Prime_PID} ->
      Prime_PID ! {ok,Cur}
    end,
  queue(Cur+1,PLimit,Main_PID).

% empty queue process: inform next_prime requesters that the queue is empty until we receive the "done" message
queue_empty(Main_PID) ->
  receive
    {next_prime,Prime_PID} ->
      Prime_PID ! {queue_empty, Main_PID},
      queue_empty(Main_PID);
    {done} -> noop end.

% main worker process: get the next prime from the queue...
prime(X,Accum_PID,Queue_PID) ->
  Queue_PID ! {next_prime, self()},
  receive
    {ok,N} ->
      % io:format("worker ~w testing ~w ~n",[X,N]),
      case is_prime(N) of
        true ->
          % io:format("worker ~w found ~w to be prime!~n",[X,N]),
          Accum_PID ! {add_prime,N};
        false ->
          % io:format("worker ~w found ~w to NOT be prime!~n",[X,N]),
          noop
      end,
      prime(X,Accum_PID,Queue_PID);
    {queue_empty, Main_PID} -> Main_PID ! {done} end.

% very poor, but we want the process to actually do "some" work...
is_prime(N) when N < 2 -> false;
is_prime(N) when N == 2; N == 3 -> true;
is_prime(N) ->
  lists:all(fun(A) -> N rem A =/= 0 end, lists:seq(2, N div 2)).

% utility funtion: we get our arguments as 'atoms' e.g. '12' but we want integers
atom_to_integer(Atom) ->
  erlang:list_to_integer(erlang:atom_to_list(Atom)).