%Juan Carlos Garfias Tovar A01652138
%metodo newton raphson
function [r,xi,iter] = NewtonR(f,fdx,xi,error)
    iter = 0;
    
    while abs(subs(f,xi))>error
        xi = xi - subs(f,xi)/subs(fdx,xi);
        iter = iter +1;
    end
    
    r = double(subs(f,xi));
    xi= double(xi);
end