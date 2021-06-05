-module(paralelo).
-export([readFile/1]).
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
  FileIn = File++".in",
  FileOut = File ++ ".out",
  {ok,Binary} = file:read_file(FileIn),
  List1 = [binary_to_list(Bin) || Bin <- binary:split(Binary,<<"\n">>,[global]),Bin =/= << >>],
  Data = [performOperation(string:tokens(H, " ")) || H <- List1],
  LineSep = io_lib:nl(),
  Print = [string:join(Data, LineSep), LineSep],
  file:write_file(FileOut, Print).


%Funcion en paralelo
%readFileParallel(File) ->




