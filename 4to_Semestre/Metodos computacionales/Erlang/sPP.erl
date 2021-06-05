%Juan Carlos Garfias & Bohyeon Cha'

-module(sPP).
-author('Juan Carlos Garfias & Bohyeon Cha').

-export([solve/0, solve/1,solveP/1,isPrimeLista/1]).

isPrime(N) ->
    MaxTry = trunc(math:sqrt(N)),
    isPrime(N, 3, MaxTry).

isPrime(N, Try, MaxTry) ->
    if 
        Try > MaxTry ->
            true;
        true ->
            if
                N rem Try == 0 -> 
                    false;
                true ->
                    isPrime(N, Try+2, MaxTry)
            end
    end.

sumPrimes(Max) ->
    sumPrimes(3, 2, Max).

%metodo para hacer la suma del actual con la suma y
%el maximo. Si el actual es mayor al maximo entonces
sumPrimes(Current, Sum, Max) ->
    if
        Current >= Max ->
            Sum;
        true ->
            case isPrime(Current) of
                true -> NewSum = Sum + Current;
                false -> NewSum = Sum
            end,
            sumPrimes(Current+2, NewSum, Max)
    end.

%metodo para hacer solve de manera default, es decir 
%correrlo para cinco millones en caso de que no se ingrese
%un valor por parte del usuario
solve() ->
    solve(5000000).

%metodo solve el cual permite hacer la suma de primos con un numero
%como input por parte del usuario. Se hace una evalucacion del tiempo y 
%del resultado. 
%U1 es el tiempo de la CPU y U2 es el tiempo total transcurrido (tiempo del reloj)
solve(N) ->
    statistics(runtime),
    statistics(wall_clock),

    Result = sumPrimes(N),
    
    {_, Time1} = statistics(runtime),
    {_, Time2} = statistics(wall_clock),
    U1 = Time1 * 1000,
    U2 = Time2 * 1000,
    io:format("Resultado: ~p \nTiempo de Ejecucion: ~p (~p) microseconds~n",
    [Result, U1,U2]).

%%-----------------PARTE 2 PARALELO----------------------------

isPrimeLista(L) ->
    
    [isPrime(H) || H <- L].


solveP(N) ->
    %pmap(FuncSpec, ExtraArgs, List1)
    %[isPrime(H) || H <- lists:seq(1, N)].

    List = lists:seq(2, N),
    Sublist = [ lists:sublist(List, X, 2) || X <- lists:seq(1,length(List),2) ],
    rpc:pmap( { sPP, isPrimeLista }, [], Sublist).

    %[lists:sublist(List, X, 2) || X <- lists:seq(1,length(lists:seq(1, N)),2)].
    %pmap(isPrime(),lists:seq(1, N))