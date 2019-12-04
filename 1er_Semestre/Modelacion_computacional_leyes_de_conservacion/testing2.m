x = 100:.01:2800;
y = -0.000002249*x.^3+0.010770716*x.^2-13.061982421*x+1700.740063337;
px = 100;
py = 500;
for i=1:100
    %figure(100); %This is so it will replot over the previous figure, and not make a new one.
    ph = plot(x,y,px, py,'o');
    pause(0.1);
    px = px+2800/100;
    py = -0.000002249*px^3+0.010770716*px^2-13.061982421*px+1700.740063337;
end