%%Juan Carlos Garfias Tovar, A01652138
salario = input("Ingresar salario actual: ");
antiguedad = input("Ingresar antiguedad en la empresa: ");
utilidad =0;
if antiguedad <1
    utilidad = salario*0.05;
elseif antiguedad >=1 && antiguedad< 2
    utilidad = salario*0.07;
elseif antiguedad >=2 && antiguedad <5
    utilidad = salario*0.1;
elseif utilidad >=5 && antiguedad<10
    utilidad = salario*0.15;
else
    utilidad = salario*0.2;
end
fprintf('La utilidad será %d \n',utilidad);