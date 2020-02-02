%%Juan Carlos Garfias Tovar, A01652138
row = input("Ingresar renglones: >");
column = input("Ingresar columnas: >");
%%Fila,columna
matrix = zeros(row,column);
disp(matrix);
for i=1:row
  for j=1:column
    matrix(i, j)= input('> ');
  end
end
sumado = sum(matrix);
disp("");
disp(matrix);
disp("");
disp("La suma de cada columna es igual a:")
disp(sumado);