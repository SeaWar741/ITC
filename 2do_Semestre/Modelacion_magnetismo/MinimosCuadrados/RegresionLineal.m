function [m,b] = RegresionLineal(x,y,n)
%REGRESIONLINEAL Summary of this function goes here
%   Detailed explanation goes here

Sx = sum(x);
Sy = sum(y);
Sx2 = sum(x.^2);
Sxy = sum(x.*y);

m = ( ( Sxy - ((Sx.*Sy)./n) )./( Sx2 - ( (Sx).^2 )./n) );
b = (Sy./n)-m.*(Sx./n);

end

