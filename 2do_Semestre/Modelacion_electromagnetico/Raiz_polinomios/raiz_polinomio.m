%Juan Carlos Garfias Tovar
clc;clear all;close;

p = @(x) x.^3-6.*x.^2+11.*x-6;
x = -1:0.1:5;
plot(x,p(x));
grid on
hold on
a= [1 -6 11 -6];

r= Raicesp(a);
disp('Las raices son:')
disp(r)
%evaluar raices
a=p(r);
%graficar raices
plot(r,a,'or');
