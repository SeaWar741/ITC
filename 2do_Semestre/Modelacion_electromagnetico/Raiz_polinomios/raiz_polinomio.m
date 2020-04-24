%Juan Carlos Garfias Tovar
clc;clear all;close;

%funcion1
figure(1)
p = @(x) x.^3-6.*x.^2+11.*x-6;
x = -1:0.1:5;
plot(x,p(x));
grid on
hold on
a= [1 -6 11 -6];

r= Raicesp(a);
disp('1)Las raices son:')
disp(r)
%evaluar raices
a=p(r);
%graficar raices
plot(r,a,'or');

%-------------------------------------------------------------------------
%funcion2
figure(2)
p=@(x)x.^3-x.^2-4.*x+4;
x = -5:0.1:5;
plot(x,p(x));
grid on
hold on
a= [1 -1 -4 4];

r= Raicesp(a);
disp('2)Las raices son:')
disp(r)
%evaluar raices
a=p(r);
%graficar raices
plot(r,a,'or');

%-------------------------------------------------------------------------
%funcion3
figure(3)
p=@(x)-x.^4+10.*x.^2-9;
x = -4:0.1:4;
plot(x,p(x));
grid on
hold on
a= [-1 0 10 0 -9];

r= Raicesp(a);
disp('3)Las raices son:')
disp(r)
%evaluar raices
a=p(r);
%graficar raices
plot(r,a,'or');

%-------------------------------------------------------------------------
%funcion4
figure(4)
p=@(x)2.*x.^3+x.^2-13.*x+6;
x = -4:0.1:4;
plot(x,p(x));
grid on
hold on
a= [2 1 -13 6];

r= Raicesp(a);
disp('4)Las raices son:')
disp(r)
%evaluar raices
a=p(r);
%graficar raices
plot(r,a,'or');

