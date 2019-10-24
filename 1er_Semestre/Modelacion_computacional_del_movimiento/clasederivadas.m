t = 0:0.1:5;
x = (4*t.^3-(10*t));
y = (9*t)-(t-t);
y =(9*t)-(t.*t);
xx=(12*t.^2)-10;
yy=9-(2*t);
xxx=24*t;
yyy=-2;
plot3(x,y,t);
hold on
plot3(xx,yy,t,'r');
plot3(xxx,yyy,t,'g');