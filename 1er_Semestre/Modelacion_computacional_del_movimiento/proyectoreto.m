%%Proyecto simulacion de proyectiles de un volcan, empleando MATLAB

%%Miembros
%%Axel Giovanni Villanueva Cuéllar. A00828073
%%Juan Carlos Garfias Tovar. A01652138
%%Hernán Salinas Ibarra. A01570409
%%Alejandro Daniel Gonzalez Carrillo. A01570396
%%Abraham Cepeda Oseguera. A00827666

%%Movimiento parabólico sin resistencia
%%Movimiento parabólico con resistencia del viento con Euler

%%Euler es y(0+\delta T) = y0 + (y\prima(x) * \delta t)

%%Variables
x0 = 0;%%X inicial
y0 = 2547.429;%%Y inicial
v = 114.37;%%Velocidad inicial
a = 85*(pi/180);%%Angulo inicial
dt = 1;%%Delta t
ac = 0;%%Aceleracion
f = 11.79; %%Friccion
m = 11612.4426869536;%%Masa
cfri = 0.47;%%coeficiente de cuerpo circular en el aire

%%Constantes
g = -9.81;%% gravedad

%%Escala de la grafica
xmove = 500;
maxheight = ((v^2*(sin(a))^2)/abs(2*g))+y0+500;


%%Modelado
figure(1);
i = dt;
graphc = true;
vy0=v*sin(a);


%%Caso 0 con friccion
vx2 = v * cos(a);
vy2 = v * sin(a);
fx = cfri * vx2;
fy = cfri*vy2;
ax = 0;
ay= 0;
x2 = 0;
y2 = y0;

vx2a = vx2;
vy2a = vy2;
axa = ax;
aya = ay;


while graphc
    hold on
    if i == dt
        %%SF
            vx1 = v*cos(a);
            vy1 = vy0;
            x1 = vx1*i;
            y1 = vy1+(1/2)*(g*i^2)+y0;
        %%CF
            x2 = x2+vx2a;
            y2 = y2 +vy2a;
            vx2 = vx2a+axa;
            vy2 = vy2a+aya;
            ax = -fx/m+g;
            ay = -fy/m+g;
            fx = cfri*vx2;
            fy = cfri*vy2;
            vx2a = vx2;
            vy2a = vy2;
    else
        %%SF
            x1 = vx1*i;
            y1 = vy1+y1;
            vx1 = v*cos(a);
            vy1 = vy0+(g*i);
        %%CF
            x2 = x2+vx2;
            y2 = y2 +vy2;
            ay = -fy/m+g;
            ax = -fx/m+g;
            fx = cfri*vx2;
            fy = f*vy2;
            vx2 = axa+vx2a;
            vy2 = aya+vy2a;
            vx2a = vx2;
            vy2a = vy2;
    end
    disp(ay)
    ylim([0 maxheight]);
    xlim([0 xmove])
    plot(x1,y1,'-or');
    plot(x2,y2,'-ob');
    title('Modelacion de la posicion de un proyectil volcanico')
    xlabel('Posicion en x (m)');
    ylabel('Posicion en y (m)') 
    legend({'Sin friccion','Con friccion'},'Location','southwest')
    %%disp(vy);
    pause(0.1)
    hold off
    i=i+dt;
    if y1 <=0
        graphc = false;
    end
end
