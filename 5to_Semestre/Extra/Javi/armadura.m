% RETO 1
% Programa que calcula el costo (dependiendo del presupuesto que posees y de
% la cantidad de materiales que requieras) de una armadura de una construccion
% A00833815 - Eduardo Javier Polanco Gutierrez

clear
clc

disp(" ")
disp("-------------------------------------------------------------------")
disp("                             MENU ")
disp("-------------------------------------------------------------------")
disp(" ")
disp(" a) Calcular el costo de los materiales para tu armadura ")
disp(" b) Calcular la cantidad de materiales segun tu presupuesto ")
disp(" c) Saber si el presupuesto te alcanza para la armadura determinada")
disp(" d) Graficar la armadura en 3d ")
disp(" ")
disp("-------------------------------------------------------------------") 
% Input para cambiar entre las opciones dadas
menu = input("Ingrese la opcion que desee elegir: ", 's');

switch menu
    case "a"
        % Dar a entender que por cada material que se le otorgue en esta
        % opcion se calculara con la formla designada por el costo de cada
        % material
        disp("-------------------------------------------------------------------")
        disp(" ")
        disp(" Para calcular el costo de los materiales de tu armadura necesitaras:")
        disp(" Ingresar la cantidad de metros de acero para definir el costo del ")
        disp(" total para este material")
        disp(" ")
        disp(" Ingresa la cantidad de metros en la siguiente opcion")
        disp("-------------------------------------------------------------------")
        disp(" ")
        % Pedirle al usuario que digite las cantidades de cada material
        % para calcular el costo de cada uno de ellos y el total por
        % material
        ma1 = input (" Metros de vigas de acero: ");
        ma2 = 5378;
        % Leer formula 
        [costo] = precio(ma1,ma2);
        % Desplegar resultado 
        disp(" ")
        disp("-------------------------------------------------------------------")
        disp(" EL precio total por metros de vigas de acero seria $" + costo)
        disp("-------------------------------------------------------------------")

    case "c"
        % Dar a entender que tanto presupuesto necesitas para una armadura
        % determinada y en este caso se te avisara si te falta o te sobra
        % presupuesto
        disp("-------------------------------------------------------------------")
        disp(" ")
        disp(" Para calcular si tu presupuesto para la armadura es suficiente o no")
        disp(" necesitaremos que nos otorgues tu presupuesto para determinar si te")
        disp(" falta o te sobra para una armadura basada en el diseño de HOWE.")
        disp(" ")
        disp(" Favor de ingresar la cantidad exacta o aproximada de tu presupuesto")
        disp("-------------------------------------------------------------------")
        disp(" ")
        % Pedirle al usuario que digite el presupuesto que posee para poder
        % ver si le falta o le sobra para poder concluir con la armadura
        p1 = input(" Tu presupuesto: ");
        p2 = 769054;
        % Leer formula 
        [presupuesto] = coste(p1,p2);
        % Desplegar si le sobra o le falta y cuanto seria
        disp(" ")
        disp("-------------------------------------------------------------------")
        disp(" Tu presupuesto actual es " + presupuesto)
        disp("-------------------------------------------------------------------")

    case "b"
        % Determinar la cantidad de material que podrias llegar a conseguir
        % segun tu presupuesto basandonos en los metros que recibirias para
        % tu armadura
        disp("-------------------------------------------------------------------")
        disp(" ")
        disp(" Para calcular la cantidad de materiales segun tu presupuesto, se")
        disp(" necesitara que otorgues tu presupuesto actual y te proporcionara")
        disp(" los materiales en metros")
        disp(" ")
        disp(" Favor de ingresar la cantidad exacta de tu presupuesto ")
        disp("-------------------------------------------------------------------")
        dips(" ")
        % Pedirle al usuario que digite el presupuesto que posee para poder
        % proporcionarle la cantidad de acero que le alcanza con ese dinero
        t1 = input(" Presupuesto: ");
        % Leer formula
        [material]=cantidad(t1);
        % Desplegar datos resultantes
        disp(" ")
        disp("-------------------------------------------------------------------")
        disp(" La cantidad de acero a la que te alcanza es " + material)
        dips("-------------------------------------------------------------------")

    case "d"
        
        c= input (" Introducir numero de triangulos que necesites (solo numero par)");
        [m] = howe(c,1);
        axis equal
        hold on 

        plot(m(:,1),m(:,2),'-k');
        % Funcion



end


function[costo] = precio(ma1,ma2)
precio = ma1*ma2;
costo = precio;
end


function[presupesto]=coste(p1)
end

function [ m ] = howe( c,l )

        m=zeros(5,2);

        m(1,1)=1;

        k=3;
        a=1;

   for i=1:c+1
     if mod(i,2)==0
            m(k,1)=m(k-1,1);
            m(k,2)=0;
      else
        m(k,1)=a;
        m(k,2)=l;
        a=a+l;
     end
    k=k+1;
    
end

for i=1:c+1
    if mod(i,2)==0
        m(k,1)=m(k-1,1);
        m(k,2)=l;
        a=a+l;
    else
        m(k,1)=a;
        m(k,2)=0;
        
    end
    k=k+1;
    
end

m(k,1)=l;
k=k+1;

m(k,1)=m(k-1,1);
m(k,2)=l;
k=k+1;

m(k,1)=l*(c+1);
m(k,2)=l;
k=k+1;

m(k,1)=l*((c/2)+1);
m(k,2)=l;
k=k+1;

m(k,1)=m(k-1,1);
m(k,2)=0;

end



