set(app.UITable,'Data',[])
        
            %%Variables
            dt = app.tEditField.Value;%%Delta t
            
            %%Proyectil 1 y 2
            x0 = 0;%%X inicial
            y0 = app.AlturaVolcanEditField.Value;%%Y inicial
            v = app.VelocidadinicialEditField.Value;%%Velocidad inicial
            a = app.AnguloEditField.Value*(pi/180);%%Angulo inicial
            m = app.MasaproyectilEditField.Value;%%Masa
            cfri = app.CoeficientefriccionEditField.Value*(-1);%%coeficiente de cuerpo circular en el aire

            %%Proyectil 3 y 4
            x02 = 0;%%X inicial
            y02 = app.AlturaVolcanEditField.Value;%%Y inicial
            v2 = app.VelocidadinicialEditField2.Value;%%Velocidad inicial
            a2 = app.AnguloEditField2.Value*(pi/180);%%Angulo inicial
            m2 = app.MasaproyectilEditField2.Value;%%Masa
            cfri2 = app.CoeficientefriccionEditField2.Value*(-1);%%coeficiente de cuerpo circular en el aire

            %%Proyectil 5 y 6
            x03 = 0;%%X inicial
            y03 = app.AlturaVolcanEditField.Value;%%Y inicial
            v3 = app.VelocidadinicialEditField3.Value;%%Velocidad inicial
            a3 = app.AnguloEditField3.Value*(pi/180);%%Angulo inicial
            m3 = app.MasaproyectilEditField3.Value;%%Masa
            cfri3 = app.CoeficientefriccionEditField3.Value*(-1);%%coeficiente de cuerpo circular en el aire
            
            %%Variables finales 
            AlturaMaxima = 0;
            AlturaMaxima2 = 0;
            AlturaMaxima3 = 0;
            VelocidadImpacto = 0;
            PuntoImpacto = "[0,0]";
            continue12 = true;
            continue34 = true;
            continue56 = true;
            
            %%Constantes 
            g = -9.81;%% gravedad
            
            %%Escala de la grafica
            xmove = 1000;
            maxheight = ((v^2*(sin(a))^2)/abs(2*g))+y0+500;
            maxheight2 = ((v2^2*(sin(a2)^2)/abs(2*g))+y02+500);
            maxheight3 = ((v3^2*(sin(a3)^2)/abs(2*g))+y03+500);
            maxs = [maxheight,maxheight2,maxheight3];
            maxheight = max(maxs);
            
            %%Image background
            img = imread('background.png');
            imagesc(app.UIAxes,img);
            img2 = flip(img ,1);
            imagesc(app.UIAxes, [-400 xmove], [-200 maxheight], img2);
            ax = app.UIAxes;
            ax.YDir = 'normal';
            
            %%Modelado
            i = 1;
            graphc = true;

            %Proyectil 1 y 2
            vx0 = v*cos(a);
            vy0 = v*sin(a);

            %Proyectil 3 y 4
            vx02 = v2*cos(a2);
            vy02 = v2*sin(a2);

            %Proyectil 5 y 6
            vx03 = v3*cos(a3);
            vy03 = v3*sin(a3);
            
            
            %%Caso 0
            %SIN FRICCION
                %Proyectil 1 y 2
                vx1 = vx0;
                vy1 = vy0;
                x1 = x0;
                y1 = y0;
                ay1 =0;

                %Proyectil 3 y 4
                vx3 = vx02;
                vy3 = vy02;
                x3 = x02;
                y3 = y02;
                ay3 =0;

                %Proyectil 5 y 6
                vx5 = vx03;
                vy5 = vy03;
                x5 = x03;
                y5 = y03;
                ay5 =0;
            
            %CON FRICCION
                %Proyectil 1 y 2
                vx2 = vx0;
                vy2 = vy0;
                fx = cfri*vx2;
                fy = cfri*vy2;
                ax = 0;
                ay = 0;
                x2 = x0;
                y2 = y0;
            
                fxa = fx;
                fya = fy;
                vx2a = vx2;
                vy2a = vy2;

                %Proyectil 3 y 4
                vx4 = vx02;
                vy4 = vy02;
                fx4 = cfri2*vx4;
                fy4 = cfri2*vy4;
                ax4 = 0;
                ay4 = 0;
                x4 = x02;
                y4 = y02;
            
                fxa4 = fx4;
                fya4 = fy4;
                vx4a = vx4;
                vy4a = vy4;

                %Proyectil 5 y 6
                vx6 = vx03;
                vy6 = vy03;
                fx6 = cfri3*vx6;
                fy6 = cfri3*vy6;
                ax6 = 0;
                ay6 = 0;
                x6 = x03;
                y6 = y03;
            
                fxa6 = fx6;
                fya6 = fy6;
                vx6a = vx6;
                vy6a = vy6;

            
            
            

            %Inicia el ploteo y calculo de datos    
            while graphc
                hold(app.UIAxes,"on");
                %%CASO 1
                if i == 1
                %%SF
                    %Caso 1 y 2
                    ay1 =g;
                    vx1 = vx1; %constante
                    vy1 = vy1;
                    x1 = x1+vx1*dt;
                    y1 = y1+vy1*dt;
                    
                    vy1a = vy1;
                    y1a = y1;
                    %Caso 3 y 4
                    ay3 =g;
                    vx3 = vx3; %constante
                    vy3 = vy3;
                    x3 = x3+vx3*dt;
                    y3 = y3+vy3*dt;
                    
                    vy3a = vy3;
                    y3a = y3;
                    %Caso 5 y 6
                    ay5 =g;
                    vx5 = vx5; %constante
                    vy5 = vy5;
                    x5 = x5+vx5*dt;
                    y5 = y5+vy5*dt;
                    
                    vy5a = vy5;
                    y5a = y5;
                    
                %%CF
                    %Caso 1 y 2
                    vx2 = vx2+ax*dt;
                    vy2 = vy2+ay*dt;
                    fx = cfri*vx2;
                    fy = cfri*vy2;
                    ax = fxa/m;
                    ay = fya/m+g;
                    x2 = x2+vx2a*dt;
                    y2 = y2+vy2a*dt;
                    
                    fxa = fx;
                    fya = fy;
                    vx2a = vx2;
                    vy2a = vy2;
                    %Caso 3 y 4
                    vx4 = vx4+ax4*dt;
                    vy4 = vy4+ay4*dt;
                    fx4 = cfri2*vx4;
                    fy4 = cfri2*vy4;
                    ax4 = fxa4/m2;
                    ay4 = fya4/m2+g;
                    x4 = x4+vx4a*dt;
                    y4 = y4+vy4a*dt;
                    
                    fxa4 = fx4;
                    fya4 = fy4;
                    vx4a = vx4;
                    vy4a = vy4;
                    %Caso 5 y 6
                    vx6 = vx6+ax6*dt;
                    vy6 = vy6+ay6*dt;
                    fx6 = cfri3*vx6;
                    fy6 = cfri3*vy6;
                    ax6 = fxa6/m3;
                    ay6 = fya6/m3+g;
                    x6 = x6+vx6a*dt;
                    y6 = y6+vy6a*dt;
                    
                    fxa6 = fx6;
                    fya6 = fy6;
                    vx6a = vx6;
                    vy6a = vy6;
                    
                end
                %%SF
                    %Caso 1 y 2
                    if continue12 == true
                        ay1 = g;
                        vx1 = vx1; %constante, aqui no va dt
                        vy1 = vy1+ay1*dt;
                        x1 = x1+vx1*dt;
                        y1 = y1a+vy1a*dt;
                        
                        vy1a = vy1;
                        y1a = y1;
                        
                    end
                    
                    %Caso 3 y 4
                    if continue34 == true
                        ay3 = g;
                        vx3 = vx3; %constante, aqui no va dt
                        vy3 = vy3+ay3*dt;
                        x3 = x3+vx3*dt;
                        y3 = y3a+vy3a*dt;
                    
                        vy3a = vy3;
                        y3a = y3;
                    end
                    %Caso 5 y 6
                    if continue56 == true
                        ay5 = g;
                        vx5 = vx5; %constante, aqui no va dt
                        vy5 = vy5+ay5*dt;
                        x5 = x5+vx5*dt;
                        y5 = y5a+vy5a*dt;
                        
                        vy5a = vy5;
                        y5a = y5;
                    end
                    
                %%CF
                    %Caso 1 y 2
                    if continue12 == true
                        vx2 = vx2+ax*dt;
                        vy2 = vy2+ay*dt;
                        fx = cfri*vx2;
                        fy = cfri*vy2;
                        ax = fxa/m;
                        ay = fya/m+g;
                        
                        y2a = y2;
                        
                        x2 = x2+vx2a*dt;
                        y2 = y2+vy2a*dt;
                        
                        fxa = fx;
                        fya = fy;
                        vx2a = vx2;
                        vy2a = vy2;
                        if y2 <= 0
                            continue12 = false;
                        end
                    end
                    %Caso 3 y 4
                    if continue34 == true
                        vx4 = vx4+ax4*dt;
                        vy4 = vy4+ay4*dt;
                        fx4 = cfri2*vx4;
                        fy4 = cfri2*vy4;
                        ax4 = fxa4/m2;
                        ay4 = fya4/m2+g;
                        
                        y4a = y4;
                        
                        x4 = x4+vx4a*dt;
                        y4 = y4+vy4a*dt;
                        
                        fxa4 = fx4;
                        fya4 = fy4;
                        vx4a = vx4;
                        vy4a = vy4;
                        if y4 <=0
                            continue34 = false;
                        end
                    end
                    %Caso 5 y 6
                    if continue56 == true
                        vx6 = vx6+ax6*dt;
                        vy6 = vy6+ay6*dt;
                        fx6 = cfri3*vx6;
                        fy6 = cfri3*vy6;
                        ax6 = fxa6/m3;
                        ay6 = fya6/m3+g;
                        
                        y6a = y4;
                        
                        x6 = x6+vx6a*dt;
                        y6 = y6+vy6a*dt;
                        
                        fxa6 = fx6;
                        fya6 = fy6;
                        vx6a = vx6;
                        vy6a = vy6;
                        if y6<=0
                            continue56 = false;
                        end
                    end
                
                 if y2 >= AlturaMaxima 
                     AlturaMaxima = y2;
                 end
                 if y4 >= AlturaMaxima2
                     AlturaMaxima2 = y4;
                 end
                 if y6 >= AlturaMaxima3
                     AlturaMaxima3 =y6;
                 end

                
                data=get(app.UITable, 'data'); % Get data as a string
                data(end+1,:)=[i x1 y1 x2 y2 x3 y3 x4 y4 x5 y5 x6 y6 vx1 vy1 vx2 vy2 vx3 vy3 vx4 vy4 vx5 vy5 vx6 vy6]; % Add new row of 0's as a cell type
                set(app.UITable, 'data', data);
                            
                ylim(app.UIAxes,[0 maxheight]);
                xlim(app.UIAxes,[0 xmove]);
                
                %Proyectil 1 y 2
                if y2 >=0
                    plot(app.UIAxes,x1,y1,'-or');
                    plot(app.UIAxes,x2,y2,'-ob');
                end
                %Proyectil 3 y 4
                if y4 >=0
                    plot(app.UIAxes,x3,y3,'-og');
                    plot(app.UIAxes,x4,y4,'-oc');
                end
                %Proyectil 
                if y6 >= 0
                    plot(app.UIAxes,x5,y5,'-om');
                    plot(app.UIAxes,x6,y6,'-oy');
                end
                
                title(app.UIAxes,'Modelado de la posicion de un proyectil volcanico');
                xlabel(app.UIAxes,'Posicion en x (m)');
                ylabel(app.UIAxes,'Posicion en y (m)');
                legend(app.UIAxes,{'Sin friccion P1','Con friccion P1','Sin friccion P2','Con friccion P2','Sin friccion P3','Con friccion P3'},'Location','southwest');
                    
                %%disp(vy);
                pause(0.1)
                hold(app.UIAxes,'off');
                
                i=i+dt;
                if continue12 == false && continue34 == false && continue56 == false
                    graphc = false;
                    %proyectil 1 y 2
                    app.AlturaMaxima.Value = AlturaMaxima;
                    app.VelocidadImpacto.Value = sqrt(vx2^2+vy2^2);
                    app.Impacto.Value = x2;
                    %Proyectil 3 y 4
                    app.AlturaMaxima_2.Value = AlturaMaxima2;
                    app.VelocidadImpacto_2.Value = sqrt(vx4^2+vy4^2);
                    app.Impacto_2.Value = x4;
                    %Proyectil 4 y 5
                    app.AlturaMaxima_3.Value = AlturaMaxima3;
                    app.VelocidadImpacto_3.Value = sqrt(vx6^2+vy6^2);
                    app.Impacto_3.Value = x6;
                end
            end