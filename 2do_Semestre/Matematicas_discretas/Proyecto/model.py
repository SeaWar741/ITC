import math  
import numpy as np
import sympy as sym
from mayavi import mlab
import tkinter as tk
import matplotlib.pyplot as plt
from mpl_toolkits import mplot3d


rho_cristal = 2.49 #g/cm^3
rho_poli = 1.18 #g/cm^3 Polimetilmetacrilato
rho_polie = 0.970 #gm/cm^3 Polietileno de alta densidad Plastico de semilla de aguacate
rho_acero = 7.8 #gm/cm^3 Acero inoxidable

selections =[0,0,0,0]#guardar valores binarios

                #material, forma, funcion
characteristics =[0,        0,      0]

        #volumen,   costo
result=[0.0,        0.0]

glass_a = [" ND "," ND "]

background='#D8D9DE'
btn1='#FE4365'
btn2='#FC9D9A'
btn3='#F9CDAD'
btn4='#C8C8A9'


#plots
def vaso_hexagonal():
    #parte superior
    x1,y1,z1 = (-1.5,2,2.5)
    x2,y2,z2 = (1.5,2,2.5)
    x3,y3,z3 = (-2.5,0,2.5)
    x4,y4,z4 = (-1.5,-2,2.5)
    x5,y5,z5 = (1.5,-2,2.5)
    x6,y6,z6 = (2.5,0,2.5)

    x7,y7,z7 = (-1.5,2,9.5)
    x8,y8,z8 = (1.5,2,9.5)
    x9,y9,z9 = (-2.5,0,9.5)
    x10,y10,z10 = (-1.5,-2,9.5)
    x11,y11,z11 = (1.5,-2,9.5)
    x12,y12,z12 = (2.5,0,9.5)

    #parte inferior
    x1a,y1a,z1a = (-1.25,1.5,0)
    x2a,y2a,z2a = (1.25,1.5,0)
    x3a,y3a,z3a = (-2,0,0)
    x4a,y4a,z4a = (-1.25,-1.5,0)
    x5a,y5a,z5a = (1.25,-1.5,0)
    x6a,y6a,z6a = (2,0,0)

    x7a,y7a,z7a = (-1.25,1.5,2.5)
    x8a,y8a,z8a = (1.25,1.5,2.5)
    x9a,y9a,z9a = (-2,0,2.5)
    x10a,y10a,z10a = (-1.25,-1.5,2.5)
    x11a,y11a,z11a = (1.25,-1.5,2.5)
    x12a,y12a,z12a = (2.0,0,2.5)

    #parte superior
    box_points = np.array([[x1,y1,z1],[x2,y2,z2],[x3,y3,z3],[x4,y4,z4],[x5,y5,z5],[x6,y6,z6],[x7,y7,z7,],[x8,y8,z8],[x9,y9,z9],[x10,y10,z10],[x11,y11,z11],[x12,y12,z12]])
    
    mlab.points3d(box_points[:, 0], box_points[:, 1], box_points[:, 2],
                        mode="axes", color=(1, 1, 1))
    '''
    mlab.mesh([[x1, x2],[x3, x4],[x5, x6],[x7, x8],[x9, x10],[x11, x12]],  # | => x coordinate

                    [[y1, y2],[y3, y4],[y5, y6],[y7, y8],[y9, y10],[y11, y12]],  # | => y coordinate

                    [[z1, z2],[z3, z4],[z5, z6],[z7, z8],[z9, z10],[z11, z12]],  # | => z coordinate

                    color=(0, 0, 0))  # black
    '''
    mlab.mesh([[x1, x3], [x7, x9]],
                    [[y1, y3], [y7, y9]],
                    [[z1, z3], [z7, z9]],
                    color=(1, 1, 1))

    mlab.mesh([[x3, x4], [x9, x10]],
                    [[y3, y4], [y9, y10]],
                    [[z3, z4], [z9, z10]],
                    color=(1, 1, 1))

    mlab.mesh([[x4, x5], [x10, x11]],
                    [[y4, y5], [y10, y11]],
                    [[z4, z5], [z10, z11]],
                    color=(1, 1, 1))

    mlab.mesh([[x5, x6], [x11, x12]],
                    [[y5, y6], [y11, y12]],
                    [[z5, z6], [z11, z12]],
                    color=(1, 1, 1))

    mlab.mesh([[x6, x2], [x12, x8]],
                    [[y6, y2], [y12, y8]],
                    [[z6, z2], [z12, z8]],
                    color=(1, 1, 1))

    mlab.mesh([[x2, x1], [x8, x7]],
                    [[y2, y1], [y8, y7]],
                    [[z2, z1], [z8, z7]],
                    color=(1, 1, 1))
    #parte inferior
    box_points1 = np.array([[x1a,y1a,z1a],[x2a,y2a,z2a],[x3a,y3a,z3a],[x4a,y4a,z4a],[x5a,y5a,z5a],[x6a,y6a,z6a],[x7a,y7a,z7a],[x8a,y8a,z8a],[x9a,y9a,z9a],[x10a,y10a,z10a],[x11a,y11a,z11a],[x12a,y12a,z12a]])
    mlab.points3d(box_points1[:, 0], box_points1[:, 1], box_points1[:, 2],
                        mode="axes", color=(1, 1, 1))
    '''
    mlab.mesh([[x1a, x2a],[x3a, x4a],[x5a, x6a],[x7a, x8a],[x9a, x10a],[x11a, x12a]],  # | => x coordinate

                    [[y1a, y2a],[y3a, y4a],[y5, y6a],[y7, y8a],[y9, y10a],[y11a, y12a]],  # | => y coordinate

                    [[z1a, z2a],[z3a, z4a],[z5a, z6a],[z7a, z8a],[z9a, z10a],[z11a, z12a]],  # | => z coordinate

                    color=(0, 0, 0))  # black
    '''
    mlab.mesh([[x1a, x3a], [x7a, x9a]],
                    [[y1a, y3a], [y7a, y9a]],
                    [[z1a, z3a], [z7a, z9a]],
                    color=(1, 1, 1))

    mlab.mesh([[x3a, x4a], [x9a, x10a]],
                    [[y3a, y4a], [y9a, y10a]],
                    [[z3a, z4a], [z9a, z10a]],
                    color=(1, 1, 1))

    mlab.mesh([[x4a, x5a], [x10a, x11a]],
                    [[y4a, y5a], [y10a, y11a]],
                    [[z4a, z5a], [z10a, z11a]],
                    color=(1, 1, 1))

    mlab.mesh([[x5a, x6a], [x11a, x12a]],
                    [[y5a, y6a], [y11a, y12a]],
                    [[z5a, z6a], [z11a, z12a]],
                    color=(1, 1, 1))

    mlab.mesh([[x6a, x2a], [x12a, x8a]],
                    [[y6a, y2a], [y12a, y8a]],
                    [[z6a, z2a], [z12a, z8a]],
                    color=(1, 1, 1))

    mlab.mesh([[x2a, x1a], [x8a, x7a]],
                    [[y2a, y1a], [y8a, y7a]],
                    [[z2a, z1a], [z8a, z7a]],
                    color=(1, 1, 1))
    #show hexagonal glass
    mlab.show()

def vaso_hexagonal_ply():
    #test con modelo ply
    vaso = 'Hexagonal.ply';

    mlab.pipeline.surface(mlab.pipeline.open(vaso))

    mlab.show()

def vaso_grueso():
    #0.5*x^4+0.5y^4 --> exterior
    #0.8x^4+0.8y^4+0.5 --> interior
    fig = plt.figure()
    ax = fig.add_subplot(1, 1, 1, projection='3d')

    u = np.linspace(0, 12, 60)
    v = np.linspace(0, 2*np.pi, 60)
    
    U, V = np.meshgrid(u, v)
    X1 = (U**0.4 + 3)*np.cos(V)
    Y1 = (U**0.4 + 3)*np.sin(V)
    Z1 = U
    X2 = (U**0.5 + 3)*np.cos(V)
    Y2 = (U**0.5 + 3)*np.sin(V)
    Z2 = U

    ax.plot_surface(X1, Y1, Z1, alpha=0.3, color='red', rstride=6, cstride=12)
    ax.plot_surface(X2, Y2, Z2, alpha=0.3, color='blue', rstride=6, cstride=12)
    plt.show()

def vaso_grueso_ply():
    vaso = "Grueso.ply"

    mlab.pipeline.surface(mlab.pipeline.open(vaso))

    mlab.show()

def vaso_alto():
    #0.5*x^4+0.5y^4 --> exterior
    #0.8x^4+0.8y^4+0.5 --> interior
    fig = plt.figure()
    ax = fig.add_subplot(1, 1, 1, projection='3d')

    u = np.linspace(0, 12, 60)
    v = np.linspace(0, 2*np.pi, 60)
    
    U, V = np.meshgrid(u, v)
    X1 = (7*U+1)*np.cos(V)
    Y1 = (-.7*U)*np.sin(V)
    Z1 = U
    X2 = (7*U+1)*np.cos(V)
    Y2 = (-.7*U)*np.sin(V)
    Z2 = U

    ax.plot_surface(X1, Y1, Z1, alpha=0.3, color='red', rstride=6, cstride=12)
    ax.plot_surface(X2, Y2, Z2, alpha=0.3, color='blue', rstride=6, cstride=12)
    plt.show()

def vaso_alto_ply():
    vaso = "Alto.ply"

    mlab.pipeline.surface(mlab.pipeline.open(vaso))

    mlab.show()


#costo y volumen
def volumen(selection):
    resulting= 0
    x = sym.Symbol('x')
    if selection == 1:
        #prisma hexagono pequeño/base
        perimetro1= 5.22*6
        apotema1 = 4.819
        area1 = (perimetro1*apotema1)/2
        volumen1 = area1*13
        #prisma hexagono grande/superior
        perimetro2= 6.25*6
        apotema2 = 6.26
        area2 = (perimetro2*apotema2)/2
        volumen2 = area2*13
        #paredes pequeñas
        v1=0.05*0.1*4.5*6
        v2=0.5*0.1*13*6
        resulting = volumen1+volumen2-(v1+v2)
    elif selection == 2:
        f=((x/0.5)**(1/4))**2
        f2=((x-1/0.5)**(1/4))**2
        volumen_ex = sym.integrate(math.pi*(f),(x,0,15))
        #volumen_in = sym.integrate(math.pi*(f2),(x,0,15))
        resulting = volumen_ex
    elif selection == 3:
        f1=((4.29*x)**(1/2))**2
        f2=((4.29*x-1)**(1/2))**2
        volumen_ex = sym.integrate(math.pi*(f1),(x,0,7.5))
        #volumen_in = sym.integrate(math.pi*(f2),(x,0,7.5))
        resulting = volumen_ex
    return resulting

def costo(material,volumen):
    resulting = 0
    if material == 1:
        resulting = volumen*rho_cristal*0.06
    elif material ==2:
        resulting = volumen*rho_polie*0.19
    return resulting


#funciones activadores


def biodegradable():
    selections[0]=1
def vidrio():
    selections[0]=0

def alto():
    selections[1]=0
    selections[2]=0
def ovalado():
    selections[1]=0
    selections[2]=1
def hexagono():
    selections[1]=1
    selections[2]=0
def otro():
    selections[1]=1
    selections[2]=1

def enfriar():
    selections[3]=0
def sinfuncion():
    selections[3]=1

#funcones de seleccion
def vaso_selection():
    if(characteristics[0]==1):
        glass_a[0]="Biodegradable"
    elif(characteristics[0]==2):
        glass_a[0]="Vidrio"
    else:
        glass_a[0]="No hay disponible"
    
    if(characteristics[1]==1):
        glass_a[1]="Alto"
    elif(characteristics[1]==2):
        glass_a[1]="Ovalado"
    elif(characteristics[1]==3):
        glass_a[1]="Hexagono"
    else:
        glass_a[1]="No hay disponible"

#interpretador
def resultado():
    p = selections[0]
    r = selections[1]
    s = selections[2]
    q = selections[3]
    if(p==1 and r == 0 and s ==0 and q ==0):#1
        characteristics[0]=1
        characteristics[1]=1
        characteristics[2]=1
    elif(p==1 and r == 0 and s ==0 and q ==1):#2
        characteristics[0]=1
        characteristics[1]=1
        characteristics[2]=2
    elif(p==1 and r == 0 and s ==1 and q ==0):#3
        characteristics[0]=1
        characteristics[1]=2
        characteristics[2]=1
    elif(p==1 and r == 0 and s ==1 and q ==1):#4
        characteristics[0]=1
        characteristics[1]=2
        characteristics[2]=2
    elif(p==1 and r == 1 and s ==0 and q ==0):#5
        characteristics[0]=1
        characteristics[1]=3
        characteristics[2]=1
    elif(p==1 and r == 1 and s ==0 and q ==1):#6
        characteristics[0]=1
        characteristics[1]=3
        characteristics[2]=2
    elif(p==1 and r == 1 and s ==1 and q ==0):#67
        characteristics[0]=1
        characteristics[1]=4
        characteristics[2]=1
    elif(p==1 and r == 1 and s ==1 and q ==1):#8
        characteristics[0]=1
        characteristics[1]=4
        characteristics[2]=2
    elif(p==0 and r == 0 and s ==0 and q ==0):#9
        characteristics[0]=2
        characteristics[1]=1
        characteristics[2]=1
    elif(p==0 and r == 0 and s ==0 and q ==1):#10
        characteristics[0]=2
        characteristics[1]=1
        characteristics[2]=2
    elif(p==0 and r == 0 and s ==1 and q ==0):#11
        characteristics[0]=2
        characteristics[1]=2
        characteristics[2]=1
    elif(p==0 and r == 0 and s ==1 and q ==1):#12
        characteristics[0]=2
        characteristics[1]=2
        characteristics[2]=2
    elif(p==0 and r == 1 and s ==0 and q ==0):#13
        characteristics[0]=2
        characteristics[1]=3
        characteristics[2]=1
    elif(p==0 and r == 1 and s ==0 and q ==1):#14
        characteristics[0]=2
        characteristics[1]=3
        characteristics[2]=2
    elif(p==0 and r == 1 and s ==1 and q ==0):#15
        characteristics[0]=2
        characteristics[1]=4
        characteristics[2]=1
    elif(p==0 and r == 1 and s ==1 and q ==1):#16
        characteristics[0]=2
        characteristics[1]=4
        characteristics[2]=2
    else:
        characteristics[0]=-1
        characteristics[1]=-1
        characteristics[2]=-1
    
    if(characteristics[1]!=4):
        vol = volumen(characteristics[1])
        result[0]=vol
        result[1]=costo(characteristics[0],vol)
    else:
        result[0]=-1
        result[1]=-1
    vaso_selection()


#ventanas
def ventana1():
    root = tk.Tk()
    root.title('Seleccion material')
    root.iconbitmap('vaso.ico')
    root.configure(background=background)    

    option1 = tk.Button(root,bg= btn1,fg='white', text='Biodegradable', padx=20,pady=10, command = biodegradable)
    option2 = tk.Button(root,bg= btn2,fg='white', text='Vidrio', padx=20,pady=10, command = vidrio)

    option1.grid(row=0, padx=20,pady=50, column=0)
    option2.grid(row=0, padx=20,pady=50, column=1)
    
    screen_Width = root.winfo_screenwidth()
    screen_Height = root.winfo_screenheight()
    
    window_Width = 550
    window_Height = 160

    x = (screen_Width - window_Width)/2
    y = (screen_Height - window_Height)/2
    root.geometry("%dx%d+%d+%d" % (window_Width,window_Height,x,y))

    root.mainloop()

def ventana2():
    root = tk.Tk()
    root.title('Forma')
    root.iconbitmap('vaso.ico')
    root.configure(background=background)  

    option1 = tk.Button(root,bg= btn1,fg='white', text='Alto', padx=20,pady=10, command = alto)
    option2 = tk.Button(root,bg= btn2,fg='white', text='Ovalado', padx=20,pady=10, command = ovalado)
    option3 = tk.Button(root,bg= btn3,fg='white', text='Hexagono', padx=20,pady=10, command = hexagono)
    option4 = tk.Button(root,bg= btn4,fg='white', text='Otro', padx=20,pady=10, command = otro)

    option1.grid(row=0, padx=20,pady=50, column=0)
    option2.grid(row=0, padx=20,pady=50, column=1)
    option3.grid(row=0, padx=20,pady=50, column=3)
    option4.grid(row=0, padx=20,pady=50, column=4)
    
    screen_Width = root.winfo_screenwidth()
    screen_Height = root.winfo_screenheight()
    
    window_Width = 550
    window_Height = 160

    x = (screen_Width - window_Width)/2
    y = (screen_Height - window_Height)/2
    root.geometry("%dx%d+%d+%d" % (window_Width,window_Height,x,y))

    root.mainloop()

def ventana3():
    root = tk.Tk()
    root.title('Funcion')
    root.iconbitmap('vaso.ico')
    root.configure(background=background)    

    option1 = tk.Button(root,bg= btn1,fg='white', text='Enfriar', padx=20,pady=10, command = enfriar)
    option2 = tk.Button(root,bg= btn2,fg='white', text='Sin Funcion', padx=20,pady=10, command = sinfuncion)
   
    option1.grid(row=0, padx=20,pady=50, column=0)
    option2.grid(row=0, padx=20,pady=50, column=1)
    
    screen_Width = root.winfo_screenwidth()
    screen_Height = root.winfo_screenheight()
    
    window_Width = 550
    window_Height = 160

    x = (screen_Width - window_Width)/2
    y = (screen_Height - window_Height)/2
    root.geometry("%dx%d+%d+%d" % (window_Width,window_Height,x,y))

    root.mainloop()

def ventana_alt():
    root = tk.Tk()
    root.title('No hay vaso dispoible')
    root.iconbitmap('vaso.ico')
    root.configure(background=background)    
   
    T = tk.Text(root, height=2, width=30)
    T.pack()
    T.insert(tk.END, "Vaso no disponible")
    
   
    T.grid(row=0, padx=20,pady=50, column=0)
   
    
    
    screen_Width = root.winfo_screenwidth()
    screen_Height = root.winfo_screenheight()
    
    window_Width = 550
    window_Height = 160

    x = (screen_Width - window_Width)/2
    y = (screen_Height - window_Height)/2
    root.geometry("%dx%d+%d+%d" % (window_Width,window_Height,x,y))

    root.mainloop()

def ver_vaso():
    if characteristics[1] == 3:
        vaso_hexagonal()
        vaso_hexagonal_ply()
    elif characteristics[1] == 2:
        vaso_grueso()
        vaso_grueso_ply()
    elif characteristics[1] == 1:
        vaso_alto_ply()
    else:
        print("vaso no disponible")
        ventana_alt()

def ventana4():
    root = tk.Tk()
    root.title('Funcion')
    resultado()
    root.iconbitmap('vaso.ico')
    print(characteristics)
    print(result)
    print(glass_a)

    vaso_selection()

    root.configure(background=background)      
    T = tk.Text(root, height=2, width=30)
    T.pack()
    T.insert(tk.END, "Material: "+glass_a[0]+"\nForma: "+str(glass_a[1])+"\nVolumen: "+str(result[0])+"\nCosto por unidad: $"+str(result[1]))
    
    option1 = tk.Button(root,bg= btn1,fg='white', text='Ver vaso', padx=20,pady=10, command = ver_vaso)
   
    T.grid(row=0, padx=20,pady=50, column=0)
    option1.grid(row=0, padx=20,pady=50, column=1)
    
    screen_Width = root.winfo_screenwidth()
    screen_Height = root.winfo_screenheight()
    
    window_Width = 450
    window_Height = 160

    x = (screen_Width - window_Width)/2
    y = (screen_Height - window_Height)/2
    root.geometry("%dx%d+%d+%d" % (window_Width,window_Height,x,y))

    root.mainloop()

def gui():
    ventana1()
    ventana2()
    ventana3()
    ventana4()

gui()

