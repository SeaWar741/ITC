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
m = 100;%%Masa
cfri = 0.47;%%coeficiente de cuerpo circular en el aire

%%Constantes
g = -9.81;%% gravedad

%%Escala de la grafica
xmove = 500;
maxheight = ((v^2*(sin(a))^2)/abs(2*g))+y0+500;

%Image background


%%Arrays para guardar posiciones
x1t = [];
y1t = [];
x2t = [];
y2t = [];
tt = [0];


%%Modelado
figure;

i = dt;
graphc = true;
vx0 = v*cos(a);
vy0 = v*sin(a);

%%Matriz


%%Caso 0
%SIN FRICCION
    vx1 = vx0;
    vy1 = vy0;
    x1 = 0;
    y1 = y0;

%CON FRICCION
    vx2 = vx0;
    vy2 = vy0;
    fx = cfri*vx2;
    fy = cfri*vy2;
    ax = 0;
    ay = 0;
    x2 = 0;
    y2 = y0;

    fxa = fx;
    fya = fy;
    vx2a = vx2;
    vy2a = vy2;



while graphc
    hold on
    %%SF
        vx1 = vx1;
        vy1 = vy1+g;
        x1 = x1+vx1;
        y1 = y1+vy1;
    %%CF
        fx = cfri*vx2;
        fy = cfri*vy2;
        ax = fxa/m;
        ay = fya/m+g;
        vx2 = vx2+ax;
        vy2 = vy2+ay;
        fxa = fx;
        fya = fy;
        x2 = x2+vx2a;
        y2 = y2+vy2a;
        fxa = fx;
        fya = fy;
        vx2a = vx2;
        vy2a = vy2;


    ylim([0 maxheight]);
    xlim([0 xmove])
    plot(x1,y1,'-or');
    plot(x2,y2,'-ob');
    title('Modelacion de la posicion de un proyectil volcanico')
    xlabel('Posicion en x (m)');
    ylabel('Posicion en y (m)') 
    legend({'Con friccion','Sin friccion'},'Location','southwest')
    %%disp(vy);
    pause(0.1)
    hold off
    i=i+dt;
    if y1 <=0
        graphc = false;
    end
end


