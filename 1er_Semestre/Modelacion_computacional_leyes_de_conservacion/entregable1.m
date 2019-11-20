syms a0 a1 a2 a3 x
%%
%%obtener funcion
x1=100;
x2=2800;
x3=967;
x4=1933.33333;

y1=500;
y2=200;
y3=0;
y4=1000;

eq1= a3*x1^3+a2*x1^2+a1*x1+a0==y1;
eq2= a3*x2^3+a2*x2^2+a1*x2+a0==y2;
eq3= a3*x3^3+a2*x3^2+a1*x3+a0==y3;
eq4= a3*x4^3+a2*x4^2+a1*x4+a0==y4;

sol=solve([eq1,eq2,eq3,eq4],[a0,a1,a2,a3]);
v1=double(sol.a0);
v2=double(sol.a1);
v3=double(sol.a2);
v4=double(sol.a3);
%%
%%radio de curvatura

fx=v4*x^3+v3*x^2+v2*x+v1;
fxd=diff(fx);
fxl=sqrt(1+(fxd^2));
fprintf("y=%.9fx^3+%.9fx^2+%.9fx+%.9f\n",v4,v3,v2,v1);


lg=int(fxl,x,[100,2800]);
fprintf("Longitud de arco: %0.4f\n",lg);
%%
%%Radio de curvatura
rval= zeros(1,2800);
for i=100:1:2800
    p = ((fxl)^(2/3)) / (diff(fxd));
    psub = subs(p,x,i);
    rval(1,i) = psub;
    if(psub<=150&&psub>=0)
        fprintf("Radio: %.6f\n",psub);
    end
    %fprintf("El radio de curvatura es: \n");
end
%disp(rval);
