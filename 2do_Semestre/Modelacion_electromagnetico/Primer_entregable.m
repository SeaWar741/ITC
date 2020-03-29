
%campo
[x,y] = meshgrid(0:0.2:7,0:0.2:7);
u = cos(x)+y;
v = y;

h = quiver(x,y,u,v,'color',[1 0 1]);
set(h,'MaxHeadSize',1e5,'AutoScaleFactor',1.6);

hold on

%carga positiva
rectangle('Position',[2 4 1 1.2],'Curvature',[1,1],'FaceColor','b','EdgeColor',[0 0 1]);
%carga negativa
rectangle('Position',[4 4 1 1.2],'Curvature',[1,1],'FaceColor','r','EdgeColor',[1 0 0]);

%punto a evaluar
rectangle('Position',[3.5 6 0.5 0.6],'Curvature',[1,1],'FaceColor','k','EdgeColor',[1 1 1]);


hold off
axis([1 7 1 7])
axis square %define la proporcion cuadrada
title('Dos cargas con signos opuestos');
xlabel('Eje x (m)');
ylabel('Eje y (m)');