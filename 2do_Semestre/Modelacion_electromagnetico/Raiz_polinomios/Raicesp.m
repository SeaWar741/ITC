%Juan Carlos Garfias A01652138
function r = Raicesp(a)
    terminoi = a(end);
    divisores = divisors(terminoi);
    divisores = [divisores divisores*-1];
    
    nuevaa(1) = a(1);%el primer elemento de a no cambia
    r=[ ];
    for i = 1:length(divisores)
        div = divisores(i);
        mul(1) = div * nuevaa(1);
        for j=2:length(a)
            nuevaa(j)=a(j)+mul(j-1);
            mul(j)=div*nuevaa(j);
        end
        if nuevaa(end)==0
            r=[r,div];%se va aumentando mi r
            nuevaa(end) = [ ];%quitar el 0
            a = nuevaa;
        end    
    end
    
end