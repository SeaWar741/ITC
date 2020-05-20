%Juan Carlos Garfias Tovar, A10652138
clc
clear
disp(" ")
disp("   Juan Carlos Garfias Tovar A01652138")
disp(" ")

%% Ejecricio 1
f=@(x,y)-y+sin(x);
a =4;
b = 9.6;
y0=-1;
h=0.1;
[x,y]=RungeKutta4(f,a,b,y0,h);
[xi,yi]=rungeKutta(f,a,b,y0,h);
plot(x,y,"-g");
hold on
f2=@(x) 1.5*exp(-x)+0.5*sin(x)-0.5*cos(x);
y2=f2(x);
plot(x,y2,'-m');
disp("   Ejercicio 1 (-y+sin(x)):");
disp('   -------------------------------------');
legend('Aproximada','Exacta','Location','east');
disp('       x       Aprox.   Exacta    Difer.');
disp('   -------------------------------------');
disp([x' y' y2' (y2-y)']);
disp("   El promedio de la diferencia (4to orden) es:");
xlabel("X");
ylabel("y");
title("Runge-Kutta 4to orden: -y+sin(x)");
disp(mean((y2'-y')));
disp("   El promedio de la diferencia (2do orden) es:");
disp(mean((y2'-yi')));

%% Ejercicio 2
figure1 = figure();
f=@(x,y)y.*tan(x)+x;
a = 0;
b = 3;
y0 =10;
h = 0.1;
[x,y]=RungeKutta4(f,a,b,y0,h);
[xi,yi]=rungeKutta(f,a,b,y0,h);
plot(x,y,"-r");
hold on
f2=@(x) x.*tan(x)+2.*sec(x).*6+1;
y2=f2(x);
plot(x,y2,'-b');
disp("   Ejercicio 2 (ytan(x)+x-y+sin(x)):");
legend('Aproximada','Exacta','Location','east');
disp('   -------------------------------------');
disp('       x       Aprox.   Exacta    Difer.');
disp('   -------------------------------------');
disp([x' y' y2' (y2-y)']);
disp("   El promedio de la diferencia (4to orden) es:");
disp(mean((y2'-y')));
xlabel("X");
ylabel("y");
title("Runge-Kutta 4to orden: ytan(x)+x");
disp("   El promedio de la diferencia (2do orden) es:");
disp(mean((y2'-yi')));

%% Ejercicio 3
figure2 = figure();
f=@(x,y) (3.*x./y)-x.*y;
a = 0;
b = 2.5;
y0 =2;
h = 0.1;
[x,y]=RungeKutta4(f,a,b,y0,h);
[xi,yi]=rungeKutta(f,a,b,y0,h);
plot(x,y,"oc");
hold on
f2=@(x) sqrt(3+exp(-x.^2));
y2=f2(x);
plot(x,y2,'xr');
disp("   Ejercicio 3 ((3x/y)-xy):");
legend('Aproximada','Exacta','Location','east');
disp('   -------------------------------------');
disp('       x       Aprox.   Exacta    Difer.');
disp('   -------------------------------------');
disp([x' y' y2' (y2-y)']);
disp("   El promedio de la diferencia (4to orden) es:");
disp(mean((y2'-y')));
xlabel("X");
ylabel("y");
title("Runge-Kutta 4to orden: (3x/y)-xy");
disp("   El promedio de la diferencia (2do orden) es:");
disp(mean((y2'-yi')));

%% Ejercicio 4
figure3 = figure();
f=@(x,y) y*cos(x);
a = 0;
b = 4;
y0 =1;
h = 0.1;
[x,y]=RungeKutta4(f,a,b,y0,h);
[xi,yi]=rungeKutta(f,a,b,y0,h);
plot(x,y,"og");
hold on
f2=@(x) exp(sin(x));
y2=f2(x);
plot(x,y2,'xb');
disp("   Ejercicio 4 (ycos(x)):");
legend('Aproximada','Exacta','Location','east');
disp('   -------------------------------------');
disp('       x       Aprox.   Exacta    Difer.');
disp('   -------------------------------------');
disp([x' y' y2' (y2-y)']);
disp("   El promedio de la diferencia (4to orden) es:");
disp(mean((y2'-y')));
xlabel("X");
ylabel("y");
title("Runge-Kutta 4to orden: ycos(x)");
disp("   El promedio de la diferencia (2do orden) es:");
disp(mean((y2'-yi')));