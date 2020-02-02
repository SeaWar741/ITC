
x = input("Dame el valor de x: >");
n = input("Dame la cantidad de apriximaciones: >");
taylorf(x,n);

function taylorf(x,n)
    acumulador = 1;
    for i =1:n
        acumulador = acumulador + x^ i/ factorial(i);
    end
    fprintf("La aproximacion es = %.2f \n",acumulador);
end


function [factor] = factorial(num)
    factor = 1;
    for x=1:num
        factor = factor*x;
    end
end