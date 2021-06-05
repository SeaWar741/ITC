-module(testing).

-compile(export_all).

%PARALELO
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


worker() ->
    receive
        {TallierPid, L} ->
            Sum = lists:sum(lists:filter(fun(X)->isPrime(X) end, L)),
            TallierPid ! {self(), Sum}
    end.

solve() ->
    TallierPid = spawn(euler, tallier, [self(), [], 0, false]),
    solver(TallierPid, 2, 2000000),
    %% worker assignment has finished
    TallierPid ! { self(), true },

    receive
        {TallierPid, Result} ->
            io:format("Final tally: ~p ~n", [Result])
    end.

solver(TallierPid, From, To) ->
    case (To - From) of
         SmallRange when SmallRange =< 1000 ->
            List = lists:seq(From, To),
            WorkerPid = spawn(fun worker/0),
            %% register the worker with tallier
            TallierPid ! { self(), WorkerPid },
            %% send the problem for the worker to work out
            WorkerPid ! { TallierPid, List };
        _ ->
            Mid = trunc(math:floor((To + From) div 2)),
            solver(TallierPid, From, Mid),
            solver(TallierPid, Mid+1, To)
    end.


tallier(SolverPid, Workers, X, AssignFinished) ->

    receive
        {SolverPid, true} ->
            %% This message is from the solver
            %% It tells the tallier that
            %% worker assignment has finished
            tallier(SolverPid, Workers, X, true);
        {SolverPid, WorkerPid} ->
            %% This message is from the solver
            %% Register WorkerPid
            tallier(SolverPid, [WorkerPid | Workers], X, AssignFinished);
        {WorkerPid, Sum} ->
            Tally = X + Sum,
            %% Remove worker from Workers list
            NewWorkerList = Workers -- [WorkerPid],
            case AssignFinished of
                true ->
                    case NewWorkerList of
                        [] ->
                            SolverPid ! { self(), Tally };
                        _ -> tallier(SolverPid, NewWorkerList, Tally, AssignFinished)
                    end;
                _ -> tallier(SolverPid, NewWorkerList, Tally, AssignFinished)
            end
    end.