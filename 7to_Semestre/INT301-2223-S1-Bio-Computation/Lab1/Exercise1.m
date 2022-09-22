%%plot the training examples to see the classes

plot (p1(1,1:50), p1(2,1:50), 'b+', p1(1,51:100), p1(2,51:100), 'ro')

mm = minmax(p1); %expected rage for each of the inputs in the vector

%P  - RxQ matrix of Q1 representative input vectors.
%T  - SxQ matrix of Q2 representative target vectors.

net = newp(mm,1);


net = trainp_sh(net, p1, t1, 100);


%Second part

%plot the training examples to see the classes

plot (p2(1,1:50), p2(2,1:50), 'b+', p2(1,51:100), p2(2,51:100), 'ro')

mm2 = minmax(p2);

net2 = newp(mm2,1);

net2 = trainp_sh(net2, p2, t2, 100);


