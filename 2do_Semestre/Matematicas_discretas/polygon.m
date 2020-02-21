x = linspace(-8,8,200);
y = linspace(-8,8,200);
[X,Y] = meshgrid(x,y);
Z = (4-abs(X)) + (4-abs(Y));
Z(Z < 0) = NaN;
surf(X,Y,Z)