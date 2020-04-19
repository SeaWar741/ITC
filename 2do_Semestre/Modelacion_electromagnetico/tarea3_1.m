%Juan Carlos Garfias Tovar

syms x

f1 = (-1/10)*x^2+3;
b1 = -15:0.1:15;
y1 = subs(f1,b1);
x1 = 10;
fdx1 = diff(f1);%obtiene derivada

f2 = cos(x)-x^3;
b2 = -3:0.1:4;
y2 = subs(f2,b2);
x2 = 1;
fdx2 = diff(f2);%obtiene derivada

f3 = x^3+x+16;
b3 = -6:0.1:6;
y3 = subs(f3,b3);
x3 = -2;
fdx3 = diff(f3);%obtiene derivada

f4 = x^4+2*x-1;
b4 = -2:0.1:4;
y4 = subs(f4,b4);
x4 = 2;
fdx4 = diff(f4);%obtiene derivada

error = 10^-10;

%Graficar y sacarNR
tiledlayout(2,2);

nexttile
[r,xi,iter] = NewtonR(f1,fdx1,x1,error);

fprintf('El valor de y =%d\n',r)
fprintf('El valor de x =%d\n',xi)
fprintf('Las iteraciones son =%d\n',iter)
plot(xi,r,'o')
title(['el valor de x=' num2str(xi)])
grid on
hold on

plot(b1,y1)
title("(-1/10)*x^2+3")
xlabel('X') 
ylabel('Y') 
disp("--------------------------------------------")

nexttile
[r,xi,iter] = NewtonR(f2,fdx2,x2,error);

fprintf('El valor de y =%d\n',r)
fprintf('El valor de x =%d\n',xi)
fprintf('Las iteraciones son =%d\n',iter)
plot(xi,r,'o')
title(['el valor de x=' num2str(xi)])
grid on
hold on

plot(b2,y2)
title("cos(x)-x^3")
xlabel('X') 
ylabel('Y') 
disp("--------------------------------------------")

nexttile
[r,xi,iter] = NewtonR(f3,fdx3,x3,error);

fprintf('El valor de y =%d\n',r)
fprintf('El valor de x =%d\n',xi)
fprintf('Las iteraciones son =%d\n',iter)
plot(xi,r,'o')
title(['el valor de x=' num2str(xi)])
grid on
hold on

plot(b3,y3)
title("x^3+x+16")
xlabel('X') 
ylabel('Y')
disp("--------------------------------------------")

nexttile
[r,xi,iter] = NewtonR(f4,fdx4,x4,error);

fprintf('El valor de y =%d\n',r)
fprintf('El valor de x =%d\n',xi)
fprintf('Las iteraciones son =%d\n',iter)
plot(xi,r,'o')
title(['el valor de x=' num2str(xi)])
grid on
hold on
plot(b4,y4)
title("x^4+2*x-1")
xlabel('X') 
ylabel('Y') 


