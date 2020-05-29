%Juan Carlos Garfias Tovar, A01652138

%% Ejercicio 1
figure('Name','DatosClase');
Matriz = readmatrix('datos.csv');
x = Matriz(1,:);
y = Matriz(2,:);
n = length(Matriz); % es para saber la cantidad de elementos

[m,b] = RegresionLineal(x,y,n);

plot(x,y,'ob');
hold on
y1 = m.*x+b;
plot(x,y1,'-r');
title(['m=' num2str(m) 'b=' num2str(b)]);
ylabel('valores de y');
xlabel('valores de x');
legend('Puntos dados','Recta de mejor ajuste');

%% Ejercicio 2
figure('Name','PuntosXY');
Matriz = readmatrix('PuntosXY.csv');
x = Matriz(1,:);
y = Matriz(2,:);
n = length(Matriz); % es para saber la cantidad de elementos

[m,b] = RegresionLineal(x,y,n);

plot(x,y,'*c');
hold on
y1 = m.*x+b;
plot(x,y1,'-b');
title(['m=' num2str(m) 'b=' num2str(b)]);
ylabel('valores de y');
xlabel('valores de x');
legend('Puntos dados','Recta de mejor ajuste');

%% Ejercicio 3
figure('Name','PuntosXY4');
Matriz = readmatrix('PuntosXY4.csv');
x = Matriz(1,:);
y = Matriz(2,:);
n = length(Matriz); % es para saber la cantidad de elementos

[m,b] = RegresionLineal(x,y,n);

plot(x,y,'.c');
hold on
y1 = m.*x+b;
plot(x,y1,'-m');
title(['m=' num2str(m) 'b=' num2str(b)]);
ylabel('valores de y');
xlabel('valores de x');
legend('Puntos dados','Recta de mejor ajuste');

%% Ejercicio 4
figure('Name','PuntosXY8');
Matriz = readmatrix('PuntosXY8.csv');
x = Matriz(1,:);
y = Matriz(2,:);
n = length(Matriz); % es para saber la cantidad de elementos

[m,b] = RegresionLineal(x,y,n);

plot(x,y,'+g');
hold on
y1 = m.*x+b;
plot(x,y1,'-c');
title(['m=' num2str(m) 'b=' num2str(b)]);
ylabel('valores de y');
xlabel('valores de x');
legend('Puntos dados','Recta de mejor ajuste');

%% Ejercicio 4
figure('Name','PuntosXY9');
Matriz = readmatrix('PuntosXY9.csv');
x = Matriz(1,:);
y = Matriz(2,:);
n = length(Matriz); % es para saber la cantidad de elementos

[m,b] = RegresionLineal(x,y,n);

plot(x,y,'*b');
hold on
y1 = m.*x+b;
plot(x,y1,'-g');
title(['m=' num2str(m) 'b=' num2str(b)]);
ylabel('valores de y');
xlabel('valores de x');
legend('Puntos dados','Recta de mejor ajuste');
