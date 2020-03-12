%matriz3x3=[5, -1, 2;3,8,-2; 1,1,4];
matriz3x3=readtable('matriz3x3.csv')
matriz3x3=table2array(matriz3x3)
indepe=[12;-25;6]
triangsup=-1*triu(matriz3x3,1)
trianginf=-1*tril(matriz3x3,-1)
diagonal3x3=matriz3x3 +triangsup +trianginf
x1=0;
x2=0;
x3=0;
x1t=0;
x2t=0;
x3t=0;
actual=[x1;x2;x3]
futuro=[x1t; x2t;x3t]
lmasu=triangsup+trianginf
inversa=inv(diagonal3x3)
tmatrix=(inversa)*(lmasu)
bmatrix=(inversa)*indepe

for contador = 1:10
futuro=(tmatrix)*actual+bmatrix
actual
actual=futuro
end







