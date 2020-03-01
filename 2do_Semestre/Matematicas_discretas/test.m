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

syms s t
r = 2 + sin(7*s + 5*t);
x = r*cos(s)*sin(t);
y = r*sin(s)*sin(t);
z = r*cos(t);
ezsurf(x, y, z, [0, 2*pi, 0, pi])
title('Parametric surface')