%Juan Carlos Garfias A01652138
%Solucion gauss jordan
a = [1 1 1 7;1 -1 1 3;2 3 -5 2]
R = rref(a)

disp("X:"+R(1,4))
disp("Y:"+R(2,4))
disp("Z:"+R(3,4))