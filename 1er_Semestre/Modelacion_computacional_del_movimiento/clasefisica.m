t = -10:1:10
k = t.^2
a=[t' k']
plot(t,k)
x=[0,a(1)] %%definir como vector x=[x0,x1]�
y=[0,a(1,2)]
hold on
xlabel('tiempo')
ylabel('posicion')
title('vector R(t)')
%%hold on 
%%gird on
t = -10*pi:1:10*pi
x3=2*sin(t)
y3=4*cos(t)
z=t
plot3(x3,y3,z)
pause(30)    