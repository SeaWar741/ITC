function [x,y] = RungeKutta4(f,a,b,y0,h)
    x = a:h:b;
    n = length(x);
    y = zeros(1,n);
    y(1)=y0;
    for i=1:n-1
        k1=h*f(x(i),y(i));
        k2=h*f(x(i)+h/2,y(i)+1/2*k1);
        
        k3=h*f(x(i)+h/2,y(i)+1/2*k2);
        k4=h*f(x(i)+h,y(i)+k3);
        y(i+1)=y(i)+1/6*(k1+2*k2+2*k3+k4);
    end    
end

