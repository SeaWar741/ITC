import numpy as np
from mayavi import mlab
from tkinter import *
from mpl_toolkits import mplot3d
import matplotlib.pyplot as plt

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
    X1 = (0.05*U**4 + 0.5*U**4)*np.cos(V)
    Y1 = (0.05*U**4 + 0.5*U**4)*np.sin(V)
    Z1 = U
    X2 = (0.08*U**4+0.8*U**4+0.5)*np.cos(V)
    Y2 = (0.08*U**4+0.8*U**4+0.5)*np.sin(V)
    Z2 = U

    ax.plot_surface(X1, Y1, Z1, alpha=0.3, color='red', rstride=6, cstride=12)
    ax.plot_surface(X2, Y2, Z2, alpha=0.3, color='blue', rstride=6, cstride=12)
    plt.show()

def vaso_alto_ply():
    vaso = "Alto.ply"

    mlab.pipeline.surface(mlab.pipeline.open(vaso))

    mlab.show()

def menu():
    continuation = True
    while continuation == True:
        selection = int(input("ingesa seleccion >"))
        if selection == 1:
            vaso_hexagonal()
            vaso_hexagonal_ply()
        if selection == 2:
            vaso_grueso()
            vaso_grueso_ply()
        if selection == 3:
            vaso_alto()
            vaso_alto_ply()
        else:
            continuation == False

menu()