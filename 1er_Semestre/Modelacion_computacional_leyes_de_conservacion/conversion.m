seg = input("Dame la cantidad de segundos: >");
[horas,minutos,segundos]=calcula_Tiempo(seg);
fprintf("Cantidad de horas %i minutos %i segundos %i \n",horas,minutos,segundos);
disp("");

function [hr,min,ss] =calcula_Tiempo (seg)
    hr = floor(seg/3600);
    min = floor(mod(seg,3600)/60);
    ss = mod(mod(seg,3600),60);
end