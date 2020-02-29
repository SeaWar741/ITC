%Multiplicacion matriz por un escalar DIRECTO
A=randi(10,3);
VaEs=6;
disp(A)
disp(A*VaEs)

%multiplicacion manual
[rows, columns] = size(A);
for row = 1: rows 
  for column = 1:columns
      A(row,column)=VaEs*A(row,column);
  end
end
disp(A)