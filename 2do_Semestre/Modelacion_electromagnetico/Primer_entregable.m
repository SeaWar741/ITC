clear;
puntos = 25;%numero de puntos en la malla
cargas=[2,-2];%dos cargas de diferentes signos
radio = 0.2;%radio de las cargas

%Definir la posicion de las cargas
xcargas=[-0.5,0.5];
ycargas=[0,0];


epsilon = 8.854e-12;%Escribir el valor de epsilon
%es un valor para hacer la ecuacion del campo electrico
k = 1/(4 * pi * epsilon);

%Dimensiones de la grafica
minx= -1.5;
maxx=1.5;

maxy = 1.5;
miny= -1.5;

%campo electrico
campoex = zeros(puntos);
campoey = zeros(puntos);

%Crear 2 vectores
     %minimo y maximo para numero de divisiones
x =linspace(minx,maxx,puntos);%va de menos -1.5 a 1.5 dividido en npuntos
y =linspace(miny,maxy,puntos);%estos son vectores

%crear malla de puntos
[xpuntosmalla,ypuntosmalla]=meshgrid(x,y);

%crear un for que recorra las cargas para poder obtener el calculo de campo
%electrico

for i=1:2
    dx = xpuntosmalla-xcargas(i);%obtiene distancias
    dy = ypuntosmalla-ycargas(i);%obtiene distancias
    
    r = sqrt(dx.^2+dy.^2);%distancias totales/ magnitud
    r3 = r.^3;%distnacias entre donde esta la carga y los elementos que rodean la carga
    
    %aqui es por componentes
    campoex=campoex+k.*cargas(i).*dx./r3;
    campoey=campoey+k.*cargas(i).*dy./r3;
    
end

campoe_total = sqrt(campoex.^2+campoey.^2);
disp(campoe_total);

%graficar
quiver(xpuntosmalla,ypuntosmalla,campoex./campoe_total,campoey./campoe_total);%se aplica normalizacion
hold on
%usar rectangulo, usando la posicion con radio
%axis para el tamaño de la grafica}
%para el nombre de la carga, poner sobre el rectangulo, usar text
