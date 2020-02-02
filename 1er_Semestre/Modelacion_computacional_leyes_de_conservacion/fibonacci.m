%Juan Carlos Garfias Tovar, A01652138

numbers = input("Ingresar numeros a evaluar: >");
fprintf("Fibonacci: : %i \n",fibon(numbers));

%Fibonacci
%Calcula el numero en fibonacci
%Entrada:
%   numero de posiciones
%Salida:
%   Valor de la serie
function[numbers] = fibon(n)
    if n == 0
        numbers = 0;
    elseif n == 1
        numbers = 1;
    else
        numbers = (fibon(n-1)+fibon(n-2));
    end
end
