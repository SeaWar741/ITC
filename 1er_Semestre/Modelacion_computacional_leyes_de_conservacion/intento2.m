num = 2;
if num == 1
    %ylim(app.UIAxes,[0 maxheight]);
    %xlim(app.UIAxes,[0 xmove]);
    ylim([1270 1330]);
    xlim([2320 2440]);
    figure(2);
    px = 2320;
    py = 1286;
    
    fplot(y,[2320,2500],'color',[0 0 0]);
    hold on
    fplot(y2t_2,[2320 2390], '--','color',[.32 .133 .9]);
    hold on
    for i=px:0.05:2440
        %figure(100); %This is so it will replot over the previous figure, and not make a new one.
        plot(i, py,'ob');
        pause(0.0001);
        py = -0.000002249*i.^3+0.010770716*i.^2-13.061982421*i+1700.740063337;
    end
    %----------------------------------------
    fplot(y,[760,880],'color',[0 0 0]);
    hold on
    fplot(y2t,[760,880], '--','color',[.32 .133 .9]);
    hold on
    for i=px:0.05:868
        %figure(100); %This is so it will replot over the previous figure, and not make a new one.
        plot(i, py,'ob');
        pause(0.0001);
        py = -0.000002249*i.^3+0.010770716*i.^2-13.061982421*i+1700.740063337;
    end
    
    
elseif num == 2
    ylim([1270 1340]);
    xlim([2320 2500]);
    figure(2);
    fplot(fx,[2320,2390],'color',[0 0 0]);
    hold on
    fplot(y2t_2,[2320 2390], '--','color',[.32 .133 .9]);
    hold on
    px = 2320;
    py = 1286;
    for i=px:1:2373
        %figure(100); %This is so it will replot over the previous figure, and not make a new one.
        plot(i, py,'ob');
        pause(0.0001);
        if i < 2354
            py = -0.000002249*i.^3+0.010770716*i.^2-13.061982421*i+1700.740063337;
        else
            py = m_2*i-m_2*puntox_2+puntoy_2;
        end
    end 
    
    %----------------------------------------
    figure(3);
    ylim([-3080 -2920]);
    xlim([768 867]);
    px = 768.2;
    py = -2997;
    fplot(fx,[760,880],'color',[0 0 0]);
    hold on
    fplot(y2t,[760,880], '--','color',[.32 .133 .9]);
    hold on
    for i=px:1:816
        %figure(100); %This is so it will replot over the previous figure, and not make a new one.
        plot(i, py,'ob');
        pause(0.0001);
        if i < 797
            py = -0.000002249*i.^3+0.010770716*i.^2-13.061982421*i+1700.740063337;
        else
            py = m*i-m*puntox+puntoy;
        end
    end 
    
end