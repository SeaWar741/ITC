syms x
fx = 0.005589*x^3-0.286441*x^2+2.37683*x+38.0676;
fxd = diff(fx);
fprintf("D:");
disp(fxd);
fprintf("h'(12): ");
disp(subs(fxd,{x},12));
fprintf("h'(35): ");
disp(subs(fxd,{x},35));