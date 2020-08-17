t0 = 0;
tf = 50;
t = [t0,tf]; %tiempo
zdata = [1,0]; % Cae de 10m con una velocidad de 0m/s (inicial)
[t,z] = ode45(@fall, t, zdata);
figure()
plot(t,z(:,1));

hold on;

disp(z);
%Ajuste
p = polyfit(t,z(:,1),12);
yy = polyval(p,t);

plot(t,yy);
disp(" ");
disp(num2str(mse(z(:,1) - yy) ));

%derivada 1 velocidad
figure()
d1 = polyder(p);
yy2 = polyval(d1,t);
plot(t,yy2);

%derivada 2 aceclearcion
figure()
d2 = polyder(d1);
yy3 = polyval(d2,t);
plot(t,yy3);



function sistema = fall(t,z)
%     Z siendo un vector con los intervalos de Z inicial y diferencial de Z en ese punto,
%     requerido asi por ODE45
    m = 0.01;             % MASA
    g = 9.81;           % GRAV
    RP =5000  ;         % PERMEABILIDAD RELATIVA MAXIMA HIERRO
    R = 9.71 *10^-8;    % RESISTIVIDAD HIERRO 20°C
    mu = 4*pi*(10^-7);  % PERMEABILIDAD MAG. K
    a = 0.08;           % RADIO
   
% IMPLEMENTACIÓN DE ECUACION INICIAL
    k = (9*(mu * RP)^2 * (a^4))/(4*R);
    elem_1 = z(2);
    elem_2 = -((k.*(z(1).^2).*z(2))) ./(m.*((z(1).^2 + a^2).^5)) - g;
   
    sistema = [elem_1; elem_2];
end