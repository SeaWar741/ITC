
%Constants for Baseball
  m=.145 %kg
  A=pi*(.0366*2)^2/4 %m^2
  C=.5 %Drag Coefficient of a sphere
  rho= 1.2 %kg/m^3 (density of air)
  D=rho*C*A/2
  g=9.81 %m/s^2 (acceleration due to gravity)
    %Initial Conditions
    delta_t= .001 %s
    x(1)=0
    y(1)=0
    v=50 %m/s
    theta=35 %deg
    vx=v*cosd(theta)
    vy=v*sind(theta)
    t(1)=0 
    %Start Loop
    i=1
    while min(y)> -.001
        ax=-(D/m)*v*vx;
        ay=-g-(D/m)*v*vy;
        vx=vx+ax*delta_t;
        vy=vy+ay*delta_t;
        x(i+1)=x(i)+vx*delta_t+.5*ax*delta_t^2;
        y(i+1)=y(i)+vy*delta_t+.5*ay*delta_t^2;
        t(i+1)=t(i)+delta_t;
        v = sqrt(vx^2 + vy^2);
        i=i+1;
    end
    plot(x,y)
    xlabel('x distance (m)')
    ylabel('y distance (m)')
    title('Projectile Path')
