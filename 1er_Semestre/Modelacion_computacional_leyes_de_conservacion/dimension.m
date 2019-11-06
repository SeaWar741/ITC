
[base,altura,profundidad] = Lee();
calculo_area(base,altura,profundidad);

function calculo_area(base,altura,profundidad)
    area = 2*base*altura+2*base*profundidad+2*altura*profundidad;
    fprintf("El area es %.2f \n",area)
end



function [base,altura,profundidad] = Lee()
    base = input("Dame la base >");
    altura = input("Dame la altura >");
    profundidad = input("Dame la profundidad >");
end