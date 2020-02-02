clear;
clc;
hold on
x1 = 10;
x4 = 280;
y1 = 170;
y4 = 20;
incx = (x4-x1)/3;
incy = (y4-y1)/2;
for i = 1:20:incx
    for j = 1:20:x4-incx
    x2 = x1+i;
    x3 = x4-i;
    y2 = y1+j;
    y3 = y4-j;

    matriz = [x1^3, x1^2, x1, 1;...
        x2^3, x2^2, x2, 1;...
        x3^3, x3^2, x3, 1;...
        x4^3, x4^2, x4, 1];
    xx = [x1;x2;x3;x4];
    yy = [y1;y2;y3;y4];
    coef = matriz \ yy;%Matriz inversa 
    f = @(x) coef(1)*x.^3 + coef(2)*x.^2 + coef(3)*x + coef(4);
    fdx = @(x) 3*coef(1)*x.^2 + 2*coef(2)*x + coef(3);
    f2dx = @(x) 6*coef(1)*x + 2*coef(2);
    [longitudCurva, puntoCritico] = ValidaCurva(f,fdx,f2dx,x1,x4,coef);
    if puntoCritico > 0 && longitudCurva >= 451 && longitudCurva <= 452
        fprintf("Longitud Curva: %0.2f\n",longitudCurva);
        fprintf("Radio: %0.2f\n",RadioCurva(fdx,f2dx,puntoCritico));
        fprintf("Derivadas: %0.10f",fdx(xx'));
        disp(xx');
        disp(yy');
        disp("---------------");
        disp("Coeficientes: ");
        fprintf(" %0.12f",coef')
        disp(coef');
        max=(-coef(2)-sqrt(coef(2)^2-3*coef(1)*coef(3)))/(3*coef(1));
        min=(-coef(2)+sqrt(coef(2)^2-3*coef(1)*coef(3)))/(3*coef(1));
        disp(max);
        disp(min);
        
        %Haciendo los plots
        x = x1:x4;
        y = f(x);
        plot(x,y);
        
        for i = 1:1:4          
            k=xx(i);
            t=k:0.001:k+30;
            y2=f(t);
            dy=diff(y2)./diff(t);
            tang=(t-t(k))*dy(k)+y2(k);
            hold on
            plot(t,tang)
            scatter(xx,yy)
            hold off
        end

%    else
%        fprintf("No cumple con radio < 100\n");
    end
    end
end

function [longitudCurva,puntoCritico] = ValidaCurva(f,fdx,f2dx,x1,x4,coef)
    % Funciones
    lc = @(x) sqrt(1+fdx(x).^2);
    longitudCurva = integral(lc,x1,x4);
    % Puntos máximo y mínimos
    max = (-coef(2)-sqrt(coef(2)^2-3*coef(1)*coef(3)))/(3*coef(1));
    min = (-coef(2)+sqrt(coef(2)^2-3*coef(1)*coef(3)))/(3*coef(1));
    radio = RadioCurva(fdx,f2dx,max);
    %fprintf("Radio de la curva en Max: %0.2f\n",radio);
    pc = false;
    puntoCritico = 0;
    for i = max-300:10:max
        if RadioCurva(fdx,f2dx,i) < 50
            %fprintf("Punto crítico: %d\n",i);
            pc = true;
            puntoCritico = i;
            break;
        end
    end

end

function radio = RadioCurva(fdx,f2dx,x)
    radio = (1+sqrt(fdx(x)^2))^(3/2)/abs(f2dx(x));
end