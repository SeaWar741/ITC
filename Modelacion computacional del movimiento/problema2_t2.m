%%Juan Carlos Garfias Tovar, A01652138
numb1 = input("Ingresar numero 1: ");
numb2 = input("Ingresar numero 2: ");
numb3 = input("Ingresar numero 3: ");
if numb1 + numb2 == numb3
    fprintf('El numero %d es la suma de los otros numeros \n',numb3)
elseif numb2 + numb3 == numb1
    fprintf('El numero %d es la suma de los otros numeros \n',numb1)
elseif numb3 +numb1 == numb2
    fprintf('El numero %d es la suma de los otros numeros \n',num2)
else
    fprintf('No hay numeros que sean la suma de los otros \n')
end
