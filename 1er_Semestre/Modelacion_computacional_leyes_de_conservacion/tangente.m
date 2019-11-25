y=-0.000001044*x^3+0.004317333*x^2+-4.146117609*x+872.482131254;

puntox= 541;

yprim=diff(y);
m = subs(yprim,x,puntox);
puntoy=subs(y,x,puntox);
fprintf("Pendiente: %.9f\n",m);
fprintf("Puntos: (%.9f,%.9f)\n",puntox,puntoy);
y2=m*x-m*puntox+puntoy;
fprintf("La funcion es: y=");
disp(y2);

f1 = sqrt( (x-puntox)^2 + (y-puntoy) )==20;

x2= puntox+20*sqrt(1/(1+m^2));
y2= puntoy+m*20*sqrt(1/(1+m^2));
fprintf("Puntos: (%.9f,%.9f)\n",x2,y2);