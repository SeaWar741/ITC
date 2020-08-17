%% Juan Carlos Garfias

clear;clc;
disp("Datos 1er ejercicio")
figure('Name','Ejercicio 1')
tiledlayout(3,2);
for c = 1:5
    disp("----------------------------------------");
    grado = int2str(c);
    disp("Grado: "+c);
    nexttile
    %1. Leer archivo ‘PuntosEntrenaCurva1.csv’
    m1 = csvread("PuntosEntrenaCurva1.csv");
    %2. Guardar primer renglón en x y segundo renglón en y
    x1 = m1(1,:);
    y1 = m1(2,:);
    %3. Leer archivo ‘PuntosPruebaCurva1.csv’
    m2 = csvread("PuntosPruebaCurva1.csv");
    %4. Guardar primer renglón en x2 y segundo renglón en y2
    x2 = m2(1,:);
    y2 = m2(2,:);
    %5. Graficar nube de datos de x contra y
    scatter(x1,y1,'*g');
    %6. Cálculo del polinomio de ajuste de grado (?)
    p =polyfit(x1,y1,c);
    %7. En la variable yy guardar la evaluación del polinomio en cada punto de x
    yy1 = polyval(p,x1);
    %8. Graficar el polinomio de ajuste respecto a x
    hold on;
    plot(x1,yy1,'-r');
    %9. Calcular el error cuadrático medio de y – yy
    error = mse(y1-yy1);
    disp(error);
    %10. Graficar nube de datos de x2 contra y2
    hold on;
    scatter(x2,y2,'+c');
    %11. En la variable yy2 guardar la evaluación polinomio en cada punto de x2
    yy2 = polyval(p,x2);
    %12. Graficar el polinomio de ajuste del paso anterior respecto a x2
    hold on;
    plot(x2,yy2,'-r');
    %13. Calcular el error cuadrático medio y2 – yy2
    error2 = mse(y2-yy2);
    disp(error2);
    title("Grado: "+c);
    legend({'Datos de entrenamiento',"Aproximacion de entrenamiento",'Datos de prueba',"Aproximacion de prueba"},'Location','northwest');
end


%% Ejercicio 2
disp("Datos 2do ejercicio")
figure('Name','Ejercicio 2')
tiledlayout(3,2);
for c = 1:5
    disp("----------------------------------------");
    grado = int2str(c);
    disp("Grado: "+c);
    nexttile
    %1. Leer archivo ‘PuntosEntrenaCurva2.csv’
    m1 = csvread("PuntosEntrenaCurva2.csv");
    %2. Guardar primer renglón en x y segundo renglón en y
    x1 = m1(1,:);
    y1 = m1(2,:);
    %3. Leer archivo ‘PuntosPruebaCurva2.csv’
    m2 = csvread("PuntosPruebaCurva2.csv");
    %4. Guardar primer renglón en x2 y segundo renglón en y2
    x2 = m2(1,:);
    y2 = m2(2,:);
    %5. Graficar nube de datos de x contra y
    scatter(x1,y1,'+m');
    %6. Cálculo del polinomio de ajuste de grado (?)
    p =polyfit(x1,y1,c);
    %7. En la variable yy guardar la evaluación del polinomio en cada punto de x
    yy1 = polyval(p,x1);
    %8. Graficar el polinomio de ajuste respecto a x
    hold on;
    plot(x1,yy1,'-r');
    %9. Calcular el error cuadrático medio de y – yy
    error = mse(y1-yy1);
    disp(error);
    %10. Graficar nube de datos de x2 contra y2
    hold on;
    scatter(x2,y2,'*b');
    %11. En la variable yy2 guardar la evaluación polinomio en cada punto de x2
    yy2 = polyval(p,x2);
    %12. Graficar el polinomio de ajuste del paso anterior respecto a x2
    hold on;
    plot(x2,yy2,'-r');
    %13. Calcular el error cuadrático medio y2 – yy2
    error2 = mse(y2-yy2);
    disp(error2);
    title("Grado: "+c);
    legend({'Datos de entrenamiento',"Aproximacion de entrenamiento",'Datos de prueba',"Aproximacion de prueba"},'Location','northwest');
end

