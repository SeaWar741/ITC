node(a, b, c).
node(b, d, 0).
node(d, 0, g).
node(g, 0, 0).
node(c, e, f).
node(e, h, i).
node(h, 0, 0).
node(i, 0, 0).
node(f, 0, 0).

postorder(0,[]).
postorder(N,R) :- node(N,I,D),postorder(I,RI),postorder(D,RD),append(RI,RD,RS),append(RS,[N],R).
