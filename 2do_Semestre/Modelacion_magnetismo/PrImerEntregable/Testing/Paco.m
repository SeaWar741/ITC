clc
grid on
 
%%Preambulo de quivers, se define la malla y sus parametros de tamaño
npuntos = 60;                   % Cantidad de agujas              
maxx = 100;
minx= -maxx;
maxy = 100;
miny = -maxy;
X = linspace(minx,maxx, npuntos);
Y = linspace(miny,maxy, npuntos);
[xquivers,yquivers] = meshgrid(X,Y);
% Se definen los vectores para almacenar los calculos de componentes
bex = zeros(npuntos);
bey = zeros(npuntos);
% Parametros básicos
niu = 4*pi*10^-7;
current = -1;
radius = 40;
% Se realizan los cálculos de campo mag. sobre cada componente
deltay = xquivers;
deltax = yquivers;
R = sqrt(deltax.^2 + deltay.^2);
bex = bex + ((niu * current .* radius^2 ./ (4.*R.^3)) .* ((3.*deltay.*deltax) ./(R.^2)));
bey = bey + ((niu * current .* radius^2 ./ (4.*R.^3)) .* ((3.*deltax.^2) ./(R.^2) -1)) ;
 
bet = sqrt(bex.^2 + bey.^2); % Obtenemos magnitud absoluta de cada punto
% Renderizado
%quiver(xquivers,yquivers,-bex ./bet,-bey./bet,'linewidth',0.8, "Color",'blue');
streamslice(xquivers,yquivers,-bex ./bet,-bey./bet);
last = 0;
hold on
% line([0,0],[-radius/2,radius/2],"Linewidth",6,"Color","r"); <- En caso de
% querer una linea vertical se invierten los parámetros
line([-radius/2,radius/2],[0,0],"Linewidth",6,"Color","green");