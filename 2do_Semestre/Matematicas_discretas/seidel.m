% METODO ITERATIVO DE GAUSS SEIDEL

clc  %permite borrar el area de trabajo
clear  %permite borrar las variables almacenadas
format long %permite utilizar la maxima capacidad de la maquina

fprintf('                           METODO ITERATIVO DE GAUSS SEIDEL\n\n\n')
%fprintf me permite ingresar comentarios de manera textual que pueden
%orientar al usuario en el uso del programa

%input es un comando de solicitud de entrada de datos del usuario.
a=input('Ingrese la matriz de coeficientes:\n ');
b=input('\nIngrese los términos independientes:\n ');
x=input('\nIngrese el vector con las aproximacimaciones Iniciales:\n ');
iter=input('\nIngrese el número máximo de iteraciones:\n ');
tol=input('\nIngrese la tolerancia:\n ');

k=norm(a)*norm(a^-1);%Se calcula el condicional de la matriz de coeficientes
disp('condicional=')
disp(k)
% la funcion disp nos permite imprimir una variable en el espacio de trabajo
determinante=det(a);%se calcula el determinante de la matriz de coeficiente
if determinante==0
disp('El determinante es cero, el problema no tiene solución única')
end

n=length(b); %numero de elementos del vector b
d=diag(diag(a)); %obtencion de la matriz diagonal
l=d-tril(a); %obtencion de la matriz diagonal superior L
u=d-triu(a); %obtencion de la matriz diagonal inferior u

fprintf('\n     SOLUCION:\n')
fprintf('\nLa matriz de transicion de gauss seidel:\n')
T=((d-l)^-1)*u; % matriz de transicion de gauss
disp(T)
re=max(abs(eig(T))) %calculo del radio espectral

if re>1
disp('Radio Espectral mayor que 1')
disp('el método no converge')

return
end
fprintf('\nEl vector constante es::\n')
C=((d-l)^-1)*b; % vector constante C, para el metodo
disp(C)
i=0;

err=tol+1;
z=[i,x(1),x(2),x(3),err]; %vector que me permite graficar la tabla

while err>tol & i<iter
  xi=T*x+C;
%disp(xi)
i=i+1;
err=norm(xi-x); %norma 2
%err=max(abs(xi-x)); %norma 1
%err=norm(xi-x)/norm(xi); %norma relativa

x=xi;
z(i,1)=i; 
z(i,2)=x(1); 
z(i,3)=x(2); 
z(i,4)=x(3);
z(i,5)=err;
end
fprintf('\nTABLA:\n\n    n                  x1                  x2                  x3                 Error\n\n   ')
disp(z) %impresion de la tabla.