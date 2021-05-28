%Juan Carlos Garfias Tovar, A01652138
node(a, b, c).
node(b, d, 0).
node(d, 0, g).
node(g, 0, 0).
node(c, e, f).
node(e, h, i).
node(h, 0, 0).
node(i, 0, 0).
node(f, 0, 0).

%se crea la lista
postorder(0,[]).

%metodo posorder, donde se toman los nodos de abajo hacia arriba hasta el central/raiz
postorder(N,R) :- node(N,I,D),postorder(I,RI),postorder(D,RD),append(RI,RD,RS),append(RS,[N],R).

%OUTPUT ESPERADO

%postorder(a, L).
%L = [g, d, b, h, i, e, f, c, a]