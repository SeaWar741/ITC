%Juan Carlos Garfias Tovar A01652138
syms x

f= x^2-4*x+2;
b=-2:0.1:6;
y= subs(f,b);
plot(b,y,'-b');
grid on
hold on

xi = 4;
error = 10^-10;
fdx = diff(f);%obtiene derivada

[r,xi,iter] = NewtonR(f,fdx,xi,error);

fprintf('El valor de y =%d\n',r)
fprintf('El valor de x =%d\n',xi)
fprintf('Las iteraciones son =%d\n',iter)

plot(xi,r,'o')
title(['el valor de x=' num2str(xi)])

%metodo newton raphson
function [r,xi,iter] = NewtonR(f,fdx,xi,error)
    iter = 0;
    
    while abs(subs(f,xi))>error
        xi = xi - subs(f,xi)/subs(fdx,xi);
        iter = iter +1;
    end
    
    r = double(subs(f,xi));
    xi= double(xi);
end



