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
disp(" ");
disp(matrix);
disp(" ");
if row== column
    disp("Elementos en diagonal:");
    disp(diag(matrix).');
else
    disp("No es cuadrada");
end