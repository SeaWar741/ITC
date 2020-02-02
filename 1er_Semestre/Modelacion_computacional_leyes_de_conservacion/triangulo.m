%Juan Carlos Garfias Tovar, A01652138

number = input("Ingresar numero de renglones: >");
triangle(number);

%Triangulo
%Imprime un triangulo con *
%Entrada:
%   numero de filas/altura
%Salida:
%   triangulo de n de altura
function triangle(n)
    for i = 0:n
        for x = 0:i
            if x < i
                fprintf("*");
            else
                fprintf("*\n");
            end
        end
    end
end