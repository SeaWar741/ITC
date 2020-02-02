syms x
ecuacion = 1-x-4*x^3+2*x^5;
inf = 2;
sup = 4;
n = 4;
resultado = trapecio(ecuacion,inf,sup,n);
fprintf("El Resultado es %f\n",resultado);

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
