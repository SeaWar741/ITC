-module(example).

-export([multiply/2, loop/2]).

multiply(X, Y) ->
    Pid = spawn(example, loop, [0, Y]),
    lists:foreach(fun(_) -> spawn(fun() -> Pid ! X  end) end, lists:seq(1, Y)).

loop(Result, 0) -> io:format("Result: ~w~n", [Result]);

loop(Result, Count) ->
    receive
        X -> loop(Result + X, Count - 1)
    end.