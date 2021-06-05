%Juan Carlos Garfias & Bohyeon Cha'

-module(sumPrimes).
-author('Juan Carlos Garfias & Bohyeon Cha').

-export([solve/0, solve/2, solveC/1]).

%algoritmo base para evaluar si es primo
isPrime(N) ->
    MaxTry = trunc(math:sqrt(N)),
    isPrime(N, 3, MaxTry).

%algoritmo para evaluar si es primo
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

%metodo para agregar el 2 que es el unico numero primo par
sumPrimes(Inicio, Max) ->
    sumPrimes(Inicio, 2, Max).

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
    solve(3, 5000000).

%metodo solve el cual permite hacer la suma de primos con un numero
%como input por parte del usuario. Se hace una evalucacion del tiempo y 
%del resultado. 
%U1 es el tiempo de la CPU y U2 es el tiempo total transcurrido (tiempo del reloj)
solve(Inicio, Fin) ->
    statistics(runtime),
    statistics(wall_clock),

    Result = sumPrimes(Inicio, Fin),
    
    {_, Time1} = statistics(runtime),
    {_, Time2} = statistics(wall_clock),
    U1 = Time1 * 1000,
    U2 = Time2 * 1000,
    io:format("Resultado: ~p \nTiempo de Ejecucion: ~p (~p) microseconds~n",
    [Result, U1,U2]).

%metodo solveC (concurrente) el cual se llama dos veces spawn() el cual equivale a un nucleo.
%como input por parte del usuario recibe el numero el cual el metodo divide en dos partes.
%Lo manda ambos al metodo solve utilizando spawn.
%U1 es el tiempo de la CPU y U2 es el tiempo total transcurrido (tiempo del reloj)

solveC(N) ->
    Half = N div 2, %es variable para dividir en dos
    spawn(sumPrimes, solve, [3, Half]),
    spawn(sumPrimes, solve, [Half, N]).