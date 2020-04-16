%Juan Carlos Garfias Tovar A01652138

%funcion prueba
y = @(x)sqrt(9.81*x/0.23)*tanh(sqrt(9.881*0.25/x)*4)-36;
dy = @(x) 1/2*sqrt(9.81/x*0.25)*tanh((9.81*0.25)^(1/2)*4)-9.81/(2*x)*sech(sqrt(9.81*0.25/x)*4)^2;
disp(newtraphson(y,dy,140,0.00001));

%funcion newtrapshon
function raiz = newtraphson(func,dfunc,xr,es);

if nargin <3,
    error('Se requieren 3 argumentos');
end
if nargin <4|isempty(es),
    es = 0.00001;
end

x = xr; %valor inicial estimado
y = func(x);
yp = dfunc(x); %derivada de la funcion

while norm(y)>10e-7 %%se hacen iteraciones hasta lograrlo
    x = x-func(x)/dfunc(x);
    y=func(x);
end

raiz=x;
end