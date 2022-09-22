%Design a perceptron with one output to decide if a digit represented by
%pattern is even or odd.

T   = [0,0,1,0,1,0,1,0,1,0];

ptest = [1,1,1,1,1,0,1,1,0,1,1,0,1,1,0;
         1,1,0,0,1,0,0,1,1,0,1,0,1,1,1]';

p1  = [1,1,1,1,0,1,0,1,1,1];
p2  = [1,1,1,1,1,1,1,1,1,1];
p3  = [1,0,1,1,0,1,1,1,1,1];
p4  = [1,0,1,1,1,1,1,1,1,1];
p5  = [0,1,0,1,1,1,1,0,0,0];
p6  = [1,0,1,1,0,0,0,1,1,1];
p7  = [1,0,0,0,1,0,1,0,1,1];
p8  = [0,1,1,1,1,1,1,1,1,1];
p9  = [1,1,1,1,0,1,1,0,1,1];
p10 = [1,0,1,0,1,0,1,0,1,0];
p11 = [0,1,1,0,1,0,0,1,0,1];
p12 = [1,0,0,1,1,1,1,0,1,1];
p13 = [1,1,1,1,0,1,1,0,1,1];
p14 = [1,1,1,1,1,1,1,1,1,1];
p15 = [1,1,1,1,0,1,1,0,1,0];

p = [p1;p2;p3;p4;p5;p6;p7;p8;p9;p10;p11;p12;p13;p14;p15];

%p = ppatterns;

net = perceptron;

net = configure(net,p,T);

inputweights = net.inputweights{1,1};

biases = net.biases{1};

w = net.iw{1,1};
b = net.b{1};
disp(w);
disp(b);

net.trainParam.epochs = 10;

net = train(net,p,T);

disp(w);
disp(b);

y = net(ptest);

disp(y);