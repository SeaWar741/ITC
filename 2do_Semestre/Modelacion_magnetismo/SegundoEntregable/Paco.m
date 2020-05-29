global m RP R mu a

t0 = 0;
tf = 20;
t = [t0,tf]; %tiempo
zdata = [10,0]; % Cae de 10m con una velocidad de 0m/s (inicial)

m = 10;             % MASA
RP =5000  ;         % PERMEABILIDAD RELATIVA MAXIMA HIERRO
R = 9.71 *10^-8;    % RESISTIVIDAD HIERRO 20°C
mu = 4*pi*(10^-7);  % PERMEABILIDAD MAG. K
a = 0.08;           % RADIO

[t,z] = ode45(@fall,t, zdata);
plot(t,z(:,1));



function sistema = fall(t,z)
    %     Z siendo un vector con los intervalos de Z inicial y diferencial de Z en ese punto,
    %     requerido asi por ODE45
    g = 9.81;           % GRAV
    
    global m RP R mu a
    
    % IMPLEMENTACIÓN DE ECUACION INICIAL
    k = (9*(mu * RP)^2 * (a^4))/(4*R);
    elem_1 = z(2);
    elem_2 = -((k.*(z(1).^2).*z(2))) ./(m.*((z(1).^2 + a^2).^5)) - g;
   
    sistema = [elem_1; elem_2];
end

