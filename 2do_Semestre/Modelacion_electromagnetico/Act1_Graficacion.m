%% Juan Carlos Garfias Tovar A01652138

%% Actividad 1
x= -10:0.01:10;
y=x.^2;
plot(x,y,'-r','LineWidth',3)

hold on
y=2.5*x.^2;
plot(x,y,'b--');
comet(x,y)%gracica de manera animada, funciona para 2D

y= 3.7 * x.^2;
plot(x,y,'g--');
%comet(x,y)

y=0.75*x.^2;
plot(x,y,'c--');
%comet(x,y)

y=0.50*x.^2;
plot(x,y,'K--')
%comet(x,y)

title('Ejemplo 1');
xlabel('Eje x');
ylabel('Eje y');
legend('x^2','2.5*x.^2','3.7 * x.^2','0.75*x.^2','0.50*x.^2');
hold off

%%Actividad 2

