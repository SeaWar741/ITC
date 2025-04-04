-module(paralelo).
-export([readFile/1, readFileSec/1, readFileParallel/1, readFileWithTimer/1]).
-export([performOperation/1]).
-export([checkOperation/3]).

%Funcion para verificar el tipo de operacion y ejecutarla
checkOperation(NumUno,NumDos,Operation) ->
  if 
    Operation == "+" ->
      Total = NumUno+NumDos;
    Operation == "-" ->
      Total = NumUno-NumDos;
    Operation == "*" ->
      Total = NumUno*NumDos;
    Operation == "/" ->
      Total = NumUno/NumDos;
    Operation == "%" ->
      Total = NumUno rem NumDos
  end,
  Total.


%Funcion para ejecutar las operaciones
performOperation(Op) ->
  NumUno = list_to_integer(lists:nth(1, Op)),
  NumDos = list_to_integer(lists:nth(3, Op)),
  Operation = lists:nth(2, Op),
  Total = checkOperation(NumUno,NumDos,Operation),
  lists:flatten(io_lib:format("~p", [Total])).


%Funcion secuencial
readFile(File) ->
  FileIn = File ++ ".in",
  FileOut = File ++ ".out",
  {ok,Binary} = file:read_file(FileIn),
  List1 = [binary_to_list(Bin) || Bin <- binary:split(Binary,<<"\n">>,[global]),Bin =/= << >>],
  Data = [performOperation(string:tokens(H, " ")) || H <- List1],
  LineSep = io_lib:nl(),
  Print = [string:join(Data, LineSep), LineSep],
  file:write_file(FileOut, Print).

readFileWithTimer(File)->
    statistics(runtime),
    statistics(wall_clock),
    
    readFile(File),

    {_, Time1} = statistics(runtime),
    {_, Time2} = statistics(wall_clock),
    U1 = Time1 * 1000,
    U2 = Time2 * 1000,
    io:format("\nTiempo de Ejecucion: ~p (~p) microseconds~n",
    [U1,U2]).

%Funcion secuencial
runSequencial(File) ->
  File1 = File ++ "1",
  File2 = File ++ "2",
  File3 = File ++ "3",
  File4 = File ++ "4",
  readFileWithTimer(File1),
  readFileWithTimer(File2),
  readFileWithTimer(File3),
  readFileWithTimer(File4).


%Funcion en paralelo
runParallel (File) ->
  File1 = File ++ "1",
  File2 = File ++ "2",
  File3 = File ++ "3",
  File4 = File ++ "4",
  spawn(paralelo, readFileWithTimer, [File1]),
  spawn(paralelo, readFileWithTimer, [File2]),
  spawn(paralelo, readFileWithTimer, [File3]),
  spawn(paralelo, readFileWithTimer, [File4]).




