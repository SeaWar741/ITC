syms x

fun = exp(-x.^2).*log(x).^2;%Funcion
inf=1;%Valor Inferior (A)
sup=20;%Valor Superior (B)
n=50;%Numero de trapecios
nr=16;%variable riemann
dx=(sup-inf)/nr;%delta x

%integral/area
q= int(fun,x,[inf,sup]);
fprintf("Integral: %0.4f\n\n",q);

%integral/area trapecios
qtrap = trapecio(ecuacion,inf,sup,n);
fprintf("Integral trapecios: %0.4f\n\n",qtrap);

%integral/area rieman izquierda
qsri=sri(fun,nr,sup,inf,dx);
fprintf("Integral SRI: %0.4f\n\n",qsri);

%integral/area rieman derecha
qsrd=srd(fun,nr,sup,inf,dx);
fprintf("Integral SRD: %0.4f\n\n",qsrd);

%integral/area rieman medio
qsrm=srm(fun,nr,sup,inf,dx);
fprintf("Integral SRM: %0.4f !Verificar formula y arreglar\n\n",qsrm);

%centros
xcentro=int(x*fun,x,[inf,sup])/q;
ycentro=(1/2)*int(fun^2,x,[inf,sup])/q;
fprintf("Centro funcion: (%0.4f,%0.4f)\n\n",xcentro,ycentro);

%volumen
vx=pi*int(fun^2,x,[inf,sup]);
vy=2*pi*int(x*fun,x,[inf,sup]);
fprintf("volumen en x: %0.4f\n\n",vx);
fprintf("Volumen en y: %0.4f\n\n",vy);

%longitud curva
fxd=diff(fun);
fxl=sqrt(1+(fxd^2));
lg=int(fxl,x,[inf,sup]);
fprintf("Longitud de arco: %0.4f\n\n",lg);

function [res]=trapecio(ecuacion,inf,sup,n)
    syms x
    deltax = (sup-inf)/n;
    f0=subs(ecuacion,{x},inf);
    res = 0;
    for i =inf+deltax:deltax:sup-deltax
        res = res+ 2*subs(ecuacion,{x},i);
    end
    fn = subs(ecuacion,{x},sup);
    res = f0+res+fn;
    res = deltax/2*res;
end

function [res]=sri(fun,sup,nr,inf,dx)
    syms x
    res=0;
    for i=1:dx:nr
        valx=inf+((sup-inf)/nr)*(i-1);
        res = res+(subs(fun,{x},valx)*dx);
    end
end

function [res]=srd(fun,sup,nr,inf,dx)
    syms x
    res=0;
    for i=1:dx:nr
        valx=inf+((sup-inf)/nr)*i;
        res = res+(subs(fun,{x},valx)*dx);
    end
end

function [res]=srm(fun,sup,nr,inf,dx)%%Checar esta formula
    syms x
    res=0;
    for i=1:dx:nr
        valx=inf+((sup-inf)/nr)*i;
        res = res+(subs(fun,{x},valx/2)*dx);
    end
end

