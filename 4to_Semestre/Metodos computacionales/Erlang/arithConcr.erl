-module(arithConcr).
-include_lib("eunit/include/eunit.hrl").

-export([ is_prime/1,  list_of_prime/2, sum/3,sum_primes/2, sum_primes_concr/1]).
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

sum_primes(A,B) ->
    sum(fun(X, Acc) -> X+Acc end, list_of_prime(A,B), 0).
    
sum_primes_concr(A) ->
    Ref1=make_ref(), 
    Ref2=make_ref(),
    Ref3=make_ref(),
    Ref4=make_ref(),
    spawn(arithConcr, sum_primes, [1, A/4*1])+
    spawn(arithConcr, sum_primes, [A/4*1+1, A/4*2])+
    spawn(arithConcr, sum_primes, [A/4*2+1, A/4*3])+
    spawn(arithConcr, sum_primes, [A/4*3+1, A]).
    Res1=receive
%% Receives the value sum prime of first quarter

     end,
    Res2= receive
%% Receives the value sum prime of second quarter

      end,
    Res3= receive
%% Receives the value sum prime of third quarter

      end,
    Res4= receive
%% Receives the value sum prime of last quarter

      end,