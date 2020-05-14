%Juan Carlos Garfias Tovar, A01652138
f=@(t,x) t/sqrt(1+t^2) + (0*x);
a =0; %inicial t
b=3.5; %tiempo
y0=10; %valor en 0
h=0.1; %altura

tiledlayout(3,2)

%%Ejercicio 1
disp('--------=Ejercicio 1=--------')
nexttile
[x,y]=rungeKutta(f,a,b,y0,h);
plot(x,y,'*-r');
disp('y tiempo')
disp([y' x']);
legend('t/sqrt(1+t^2) ')
title('Ejercicio 1: t/sqrt(1+t^2) ');
xlabel('x') 
ylabel('y') 

%%Ejercicio 2
disp('--------=Ejercicio 2=--------')
nexttile
f = @(x,y) sin(y)+(x*0);
a = 0;
b= 3;
y0=1;
h=0.01;
[x,y]=rungeKutta(f,a,b,y0,h);
plot(x,y,'*g');

disp('y tiempo');
disp([y' x']);
legend('sin(y)');
title('Ejercicio 2: sin(y)');
xlabel('x') 
ylabel('y')

%%Ejercicio 3
disp('--------=Ejercicio 3=--------')
nexttile
f = @(t,x) 20+7*sin(2*t);
a = 0;
b= 2.8;
y0=15;
h=0.01;
[x,y]=rungeKutta(f,a,b,y0,h);
plot(x,y,'-*b');

disp('y tiempo')
disp([y' x']);
legend('20+7*sin(2*t)');
title('Ejercicio 3: 20+7*sin(2*t)');
xlabel('x') 
ylabel('y')

%%Ejercicio 4
disp('--------=Ejercicio 4=--------')
nexttile
f = @(x,y) 3*y-4*exp(-x);
a = 0;
b= 2;
y0=1;
h=0.01;
[x,y]=rungeKutta(f,a,b,y0,h);
plot(x,y,'*b');
hold on

f2=@(x) exp(-x);
y2=f2(x);
plot(x,y2,'or');
legend('Aproximada','Exacta','Location','north');
disp([y' y2' (y2-y)']);
hold off
title('Ejercicio 4: 3*y-4*exp(-x) vs exp(-x)');
xlabel('x') 
ylabel('y')
%exaacta derivada analiticamente

%%Ejercicio 5
disp('--------=Ejercicio 5=--------')
nexttile([1 2])
f = @(x,y) (y+1)*(x+1)*cos(x^2+2*x);
a = 0;
b= 2;
y0=4;
h=0.01;
[x,y]=rungeKutta(f,a,b,y0,h);
plot(x,y,'*r');
hold on

f2=@(x) 5*exp((1/2)*sin(x.^2+2*x))-1;
y2=f2(x);
plot(x,y2,'ob');
legend('Aproximada','Exacta','Location','north');
disp([y' y2' (y2-y)']);
hold off
title('Ejercicio 5: (y+1)*(x+1)*cos(x^2+2*x) vs 5*exp((1/2)*sin(x.^2+2*x))-1');
xlabel('x') 
ylabel('y')
%exaacta derivada analiticamente
