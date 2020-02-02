syms x

disp("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-=Bienvenido al programa de integracion=-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
continueg =true;
continueg2 =true;
while(continueg)
    inf=input("Ingresar Valor Inferior (A): >");%Valor Inferior (A)
    sup=input("Valor Superior (B): >");%Valor Superior (B)
    n=input("Numero de trapecios: >");%Numero de trapecios
    n2=input("Variable de Simpson: >");%Numero de trapecios
    nr=input("Variable riemann: >");%variable riemann
    dx=(sup-inf)/nr;%delta x
    fun = input("Ingresa la funcion en terminos de x: >");%Funcion
    while(continueg2)
        fprintf("\n1)Integral exacta\n2)Integral Simpson\n3)Integral Trapecios\n4)Integral Rieman Izquierda\n5)Integral Rieman Derecha");
        fprintf("\n6)Integral Rieman Medio\n7)Centro Funcion\n8)Volumen\n9)Longitud Curva\n10)Salir");
        opcion = input("\nIngresa la opcion de integracion: >");
        switch opcion
            case 1
                %integral/area
                q= int(fun,x,[inf,sup]);
                fprintf("\nIntegral: %0.4f\n\n",q);
            case 2
                %integral/area Simpson
                qsimp=simpson(fun,sup,inf,n2);
                fprintf("\nIntegral Simpson: %0.4f\n\n",qsimp);
            case 3
                %integral/area trapecios
                qtrap = trapecio(fun,inf,sup,n);
                fprintf("\nIntegral trapecios: %0.4f\n\n",qtrap);
            case 4
                %integral/area rieman izquierda
                qsri=sri(fun,nr,sup,inf,dx);
                fprintf("\nIntegral SRI: %0.4f\n\n",qsri);
            case 5
                %integral/area rieman derecha
                qsrd=srd(fun,nr,sup,inf,dx);
                fprintf("\nIntegral SRD: %0.4f\n\n",qsrd);
            case 6
                %integral/area rieman medio
                qsrm=srm(fun,inf,sup,nr);
                fprintf("\nIntegral SRM: %0.4f\n\n",qsrm);
            case 7
                %centros
                xcentro=int(x*fun,x,[inf,sup])/q;
                ycentro=(1/2)*int(fun^2,x,[inf,sup])/q;
                fprintf("\nCentro funcion: (%0.4f,%0.4f)\n\n",xcentro,ycentro);
            case 8
                %volumen
                vx=pi*int(fun^2,x,[inf,sup]);
                vy=2*pi*int(x*fun,x,[inf,sup]);
                fprintf("\nvolumen en x: %0.4f\n\n",vx);
                fprintf("Volumen en y: %0.4f\n\n",vy);
            case 9
                %longitud curva
                fxd=diff(fun);
                fxl=sqrt(1+(fxd^2));
                lg=int(fxl,x,[inf,sup]);
                fprintf("\nLongitud de arco: %0.4f\n\n",lg);
            case 10
                continueg = false;
            otherwise
                disp("\nValor invalido");
        end
    end
    opcion2=input("Deseas continuar? (s/n)");
    if(opcion2=='n')
        continueg2 = false;
    end
end
fprintf("\nHasta luego!\n\n");


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

function [res]=srm(ecuacion,inf,sup,n)%%Checar esta formula
    syms x
    dx = (sup - inf) / n;
    res = 0;
    for i = 1 : n
       res = res + subs(ecuacion, {x}, inf + (i - 1) * dx + dx / 2);
    end
    res = res * dx;
end

function [res]=simpson(ecuacion,sup,inf,n)
    syms x
    if(mod(n,2)==0)
        deltax = (sup-inf)/n;
        f0=subs(ecuacion,{x},inf);
        res = 0;
        for i =inf+deltax:deltax:sup-deltax
            if(mod(i,2)==0)
                res = res+ 2*subs(ecuacion,{x},i);
            else
                res = res+ 4*subs(ecuacion,{x},i);
            end
        end
        fn = subs(ecuacion,{x},sup);
        res = f0+res+fn;
        res = deltax/3*res;
    else
        disp("N no valida, tiene que ser par!");
        res = 0;
    end
end
