num = 2;
if num == 1
    %ylim(app.UIAxes,[0 maxheight]);
    %xlim(app.UIAxes,[0 xmove]);
    ylim([1270 1330]);
    xlim([2320 2440]);
    figure(2);
    px = 2320;
    py = 1286;
    %Gradas 2
    plot(xgrada2_i,ygrada2_f,'o','color',[0 0 0]);  %Se grafica el punto izquierdo de la primer grada/barrera
    hold on
    plot(xgrada2_f,ygrada2_f,'o','color',[0 0 0]);  %Se grafica el punto izquierdo de la segunda grada/barrera
    plot([xgrada2_i, xgrada2_f], [ygrada2_f, ygrada2_f],'color',[0 0 0]) %Se grafica una linea horizontal entre el izquierdo 1 y derecho 1 
    gx2_i=[xgrada2_i xgrada2_i];
    gy2_i=[ygrada2_f ygrada2_f+10];
    plot(gx2_i,gy2_i,'color',[0 0 0]);  %Se grafica una linea vertical entre el punto izquierdo 1 e izquierdo 2

    hold on
    plot(xgrada2_i,ygrada2_f+10,'o','color',[0 0 0]);
    hold on
    plot(xgrada2_f,ygrada2_f+10,'o','color',[0 0 0]);
    plot([xgrada2_i, xgrada2_f], [ygrada2_f+10, ygrada2_f+10],'color',[0 0 0]) %Se grafica una linea horizontal entre el derecho 1 e izquierdo 2 

    gx2_f=[xgrada2_f xgrada2_f];
    gy2_f=[ygrada2_f ygrada2_f+10];
    plot(gx2_f,gy2_f,'color',[0 0 0]); %Se grafica una linea vertical entre el punto derecho 1 y derecho 2
    hold on
    fplot(fx,[2320,2500],'color',[0 0 0]);
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
    
    %ylim(app.UIAxes,[0 maxheight]);
    %xlim(app.UIAxes,[0 xmove]);
    ylim([-3080 -2920]);
    xlim([768 867]);
    figure(3);
    px = 768.2;
    py = -2997;
    %%Grada 1
    plot(xgrada1_i,ygrada1_f,'o','color',[0 0 0]);  %Se grafica el punto izquierdo de la primer grada/barrera
    hold on
    plot(xgrada1_f,ygrada1_f,'o','color',[0 0 0]);  %Se grafica el punto izquierdo de la segunda grada/barrera
    plot([xgrada1_i, xgrada1_f], [ygrada1_f, ygrada1_f],'color',[0 0 0]);   %Se grafica una linea horizontal entre el izquierdo 1 y derecho 1
    gx1_i=[xgrada1_i xgrada1_i];   
    gy1_i=[ygrada1_f ygrada1_f-10];
    plot(gx1_i,gy1_i,'color',[0 0 0]);  %Se grafica una linea vertical entre el punto izquierdo 1 e izquierdo 2

    hold on
    plot(xgrada1_i,ygrada1_f-10,'o','color',[0 0 0]);
    hold on
    plot(xgrada1_f,ygrada1_f-10,'o','color',[0 0 0]);
    plot([xgrada1_i, xgrada1_f], [ygrada1_f-10, ygrada1_f-10],'color',[0 0 0]); %Se grafica una linea horizontal entre el izquierdo 2 y derecho 2 
    gx1_f=[xgrada1_f xgrada1_f];
    gy1_f=[ygrada1_f ygrada1_f-10];
    plot(gx1_f,gy1_f,'color',[0 0 0]);  %Se grafica una linea vertical entre el punto derecho 1 y derecho 2

    hold on
    gx2_f=[xgrada2_f xgrada2_f];
    gy2_f=[ygrada2_f ygrada2_f+10];
    plot(gx2_f,gy2_f,'color',[0 0 0]); %Se grafica una linea vertical entre el punto derecho 1 y derecho 2
    hold on
    fplot(fx,[760,880],'color',[0 0 0]);
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
    %Gradas 2
    plot(xgrada2_i,ygrada2_f,'o','color',[0 0 0]);  %Se grafica el punto izquierdo de la primer grada/barrera
    hold on
    plot(xgrada2_f,ygrada2_f,'o','color',[0 0 0]);  %Se grafica el punto izquierdo de la segunda grada/barrera
    plot([xgrada2_i, xgrada2_f], [ygrada2_f, ygrada2_f],'color',[0 0 0]) %Se grafica una linea horizontal entre el izquierdo 1 y derecho 1 
    gx2_i=[xgrada2_i xgrada2_i];
    gy2_i=[ygrada2_f ygrada2_f+10];
    plot(gx2_i,gy2_i,'color',[0 0 0]);  %Se grafica una linea vertical entre el punto izquierdo 1 e izquierdo 2

    hold on
    plot(xgrada2_i,ygrada2_f+10,'o','color',[0 0 0]);
    hold on
    plot(xgrada2_f,ygrada2_f+10,'o','color',[0 0 0]);
    plot([xgrada2_i, xgrada2_f], [ygrada2_f+10, ygrada2_f+10],'color',[0 0 0]) %Se grafica una linea horizontal entre el derecho 1 e izquierdo 2 

    gx2_f=[xgrada2_f xgrada2_f];
    gy2_f=[ygrada2_f ygrada2_f+10];
    plot(gx2_f,gy2_f,'color',[0 0 0]); %Se grafica una linea vertical entre el punto derecho 1 y derecho 2
    fplot(fx,[2320,2390],'color',[0 0 0]);
    hold on
    fplot(y2t_2,[2320 2390], '--','color',[.32 .133 .9]);
    hold on
    px = 2320;
    py = 1286;
    for i=px:0.05:2373
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
    %%Grada 1
    plot(xgrada1_i,ygrada1_f,'o','color',[0 0 0]);  %Se grafica el punto izquierdo de la primer grada/barrera
    hold on
    plot(xgrada1_f,ygrada1_f,'o','color',[0 0 0]);  %Se grafica el punto izquierdo de la segunda grada/barrera
    plot([xgrada1_i, xgrada1_f], [ygrada1_f, ygrada1_f],'color',[0 0 0]);   %Se grafica una linea horizontal entre el izquierdo 1 y derecho 1
    gx1_i=[xgrada1_i xgrada1_i];   
    gy1_i=[ygrada1_f ygrada1_f-10];
    plot(gx1_i,gy1_i,'color',[0 0 0]);  %Se grafica una linea vertical entre el punto izquierdo 1 e izquierdo 2

    hold on
    plot(xgrada1_i,ygrada1_f-10,'o','color',[0 0 0]);
    hold on
    plot(xgrada1_f,ygrada1_f-10,'o','color',[0 0 0]);
    plot([xgrada1_i, xgrada1_f], [ygrada1_f-10, ygrada1_f-10],'color',[0 0 0]); %Se grafica una linea horizontal entre el izquierdo 2 y derecho 2 
    gx1_f=[xgrada1_f xgrada1_f];
    gy1_f=[ygrada1_f ygrada1_f-10];
    plot(gx1_f,gy1_f,'color',[0 0 0]);  %Se grafica una linea vertical entre el punto derecho 1 y derecho 2

    hold on
    gx2_f=[xgrada2_f xgrada2_f];
    gy2_f=[ygrada2_f ygrada2_f+10];
    plot(gx2_f,gy2_f,'color',[0 0 0]); %Se grafica una linea vertical entre el punto derecho 1 y derecho 2
    hold on
    fplot(fx,[760,880],'color',[0 0 0]);
    hold on
    fplot(y2t,[760,880], '--','color',[.32 .133 .9]);
    hold on
    for i=px:0.05:816
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