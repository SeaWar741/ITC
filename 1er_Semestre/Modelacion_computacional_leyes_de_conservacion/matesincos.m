syms a b c d x

eq1 = a*sin(0.01*12)+b*cos(0.01*12)+c*sin(2*(0.001)*12)+d*cos(2*(0.01)*12) == 35;
eq2 = a*sin(0.01*35)+b*cos(0.01*35)+c*sin(2*(0.001)*35)+d*cos(2*(0.01)*35) == 10;
%eq3 = 0.01 * a * cos(0.12) - 0.01 * b * sin(0.12) + 0.02 * c * cos(0.24) - 0.02 * d * sin(0.24) == -2.08326;
eq3 = (a*cos(12/100))/100 - (d*sin(12/50))/50 - (b*sin(12/100))/100 + (c*cos(12/500))/500 == -2.08326;
%eq4 = 0.01 * a * cos(0.35) - 0.01 * b * sin(0.35) + 0.02 * c * cos(0.7) - 0.02 * d * sin(0.7) == 2.8659988;
eq4 = (a*cos(35/100))/100 - (d*sin(35/50))/50 - (b*sin(35/100))/100 + (c*cos(35/500))/500 == 2.8659988;

%eqd=(c*cos((1/100)*x)-b*sin((1/100)*x))/100+((q*cos((1/500)*x))/500)-(r*sin((1/50)*x)/50)

sol = solve([eq1, eq2, eq3, eq4], [a, b, c, d]);
v1 = double(sol.a);
v2 = double(sol.b);
v3 = double(sol.c);
v4 = double(sol.d);
fprintf("a = %.4f\n", v1);
fprintf("b = %.4f\n", v2);
fprintf("c = %.4f\n", v3);
fprintf("d = %.4f\n", v4);
%a = 10877.2418;
%b = -1847.2616;
%c = -5318.5881;
%d = 1885.1121;
fprintf("h(x)=%.15f*sin(0.01x)+%.15f*cos(0.01x)+%.15f*sin(2(0.001)x)+%.15f*cos(2(0.001)x)\n",v1,v2,v3,v4);
disp("Derivada:");
deriv = diff(a*sin(0.01*x)+b*cos(0.01*x)+c*sin(2*(0.001)*x)+d*cos(2*(0.01)*x));
disp(deriv)