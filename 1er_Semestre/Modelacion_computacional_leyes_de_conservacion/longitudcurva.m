syms x
ecuacion1 = 10877.241845988148270*sin(0.01*x)-1847.261575431158462*cos(0.01*x)-5318.588107004328776*sin(2*(0.01)*x)+1885.112106698415573*cos(2*(0.01)*x);
ecuacion2 = (0.005589 * x^3) - (0.286441 * x^2) + (2.37683 * x) + 38.0676;
pt2 = 35;
pt1 = 12;
n = 1000;
resultado = trapezium(ecuacion1, pt1, pt2, n);
fprintf("El resultado es: %f\n", resultado);
resultado2 = trapezium(ecuacion2, pt1, pt2, n);
fprintf("El resultado2 es: %f\n", resultado2);

function [res] = trapezium(ecuacion, inf, sup, n)
    syms x
    deltax = (sup - inf) / n;
    ecudif = diff(ecuacion);
    ecu = sqrt(1 + (ecudif)^2);
    f0 = subs(ecu, {x}, inf);
    res = 0;
    for i = (inf + deltax):deltax:(sup - deltax)
        res = res + (subs(ecu, {x}, i)) * 2;
    end    
    fn = subs(ecu, {x}, sup);
    res = (f0 + res + fn) * (deltax / 2);
end