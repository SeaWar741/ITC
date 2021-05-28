-module(arith).
-include_lib("eunit/include/eunit.hrl").

-export([ is_prime/1,  list_of_prime/2, sum/3,sum_primes/1 ]).
%% Determine whether a given integer number is prime.%%
%% Example:%% * (is-prime 7)
%% T

is_prime(N) when N =< 1 ->
    false;
is_prime(N) ->
    is_prime(N,2).    

is_prime(N,Count) when Count < N -> 
    case N rem Count == 0 of
	true ->
	    false;
	false ->
	    is_prime(N,Count+1)
    end;
is_prime(N,Count) when Count >= N-> 
    true.

%% Given a range of integers by its
%% lower and upper limit, construct a list of all prime numbers in
%% that range.
list_of_prime(A,B)->
    [ X || X <- lists:seq(A,B), is_prime(X) == true ]. 

% Sum of primes
sum(Func, Data, Acc) ->
    lists:foldr(Func, Acc, Data).

sum_primes(A) ->
    sum(fun(X, Acc) -> X+Acc end, list_of_prime(1,A), 0).
    
