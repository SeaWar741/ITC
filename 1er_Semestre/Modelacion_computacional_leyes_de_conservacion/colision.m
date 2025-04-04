v1= 100;
m1 = 500;
v2=0;
m2 = 500;
vf1 = (m1-m2)/(m1+m2)*v1;
vf2=((2*m1)/(m1+m2))*v1;

hold on
plot([0,100],[v1,vf1]);
hold on
plot([0,100],[v2,vf2]);
hold on
title('Velocidad inicial vs final en coliciones');
xlabel('T(s)');
ylabel('V') ;
legend({'Objeto 1','Objeto 2'},'Location','southwest')
hold on
plot(v1,vf1,'b*');
plot(v1,vf2,'r*');

fprintf("La velocidad en 1 es: %.2f\n",vf1);
fprintf("La velocidad en 2 es: %.2f\n",vf2);

