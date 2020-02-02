syms x y muk z
eq1= x+y ==0;
eq2= 1154*muk-z+6440+400*x==0; %%doble igual para solucion de problemas con variable simboliica
eq3 = -z+8050-250*y==0;

[x,y,z]=solve(eq1,eq2,eq3);


x=vpa(x,2)
y=vpa(y,2)
z=vpa(z,2)

muk = 0:0.01:1;
a=(-7.7*muk)+11;

vB=sqrt(40*a);
plot(muk,vB);
xlabel('mu_k');
ylabel('v_B (ft(sec)');