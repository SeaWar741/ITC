'''
from mpl_toolkits.mplot3d import Axes3D
import mpl_toolkits.mplot3d.art3d as art3d
import matplotlib.pyplot as plt
import numpy as np
from matplotlib.patches import Circle
from tkinter import *
'''
#0.5*x^4+0.5y^4

'''

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Scatter graph
N = 100
X = np.random.uniform(-1, 1, N)
Y = np.random.uniform(-1, 1, N)
Z = np.random.uniform(-2, 2, N)
ax.scatter(X, Y, Z)

# Cylinder
x=np.linspace(-1, 1, 100)
z=np.linspace(-2, 2, 100)
Xc, Zc=np.meshgrid(x, z)
Yc = np.sqrt(1-Xc**2)

# Draw parameters
rstride = 20
cstride = 10
ax.plot_surface(Xc, Yc, Zc, alpha=0.2, rstride=rstride, cstride=cstride)
ax.plot_surface(Xc, -Yc, Zc, alpha=0.2, rstride=rstride, cstride=cstride)

ax.set_xlabel("X")
ax.set_ylabel("Y")
ax.set_zlabel("Z")
plt.show()
'''
# Create the data.



import numpy as np
from mayavi import mlab

x1,y1,z1 = (-1.5,2,0)
x2,y2,z2 = (1.5,2,0)
x3,y3,z3 = (-2.5,0,0)
x4,y4,z4 = (-1.5,-2,0)
x5,y5,z5 = (1.5,-2,0)
x6,y6,z6 = (2.5,0,0)

x7,y7,z7 = (-1.5,2,12)
x8,y8,z8 = (1.5,2,12)
x9,y9,z9 = (-2.5,0,12)
x10,y10,z10 = (-1.5,-2,12)
x11,y11,z11 = (1.5,-2,12)
x12,y12,z12 = (2.5,0,12)

box_piunts = np.array([x1,y1,z1],[x2,y2,z2],[x3,y3,z3],[x4,y4,z4],[x5,y5,z5],[x6,y6,z6],[x7,y7,z7,],[x8,y8,z8],[x9,y9,z9],[x10,y10,z10],[x11,y11,z11],[x12,y12,z12])
mlab.points3d(box_points[:, 0], box_points[:, 1], box_points[:, 2],
                     mode="axes", color=(1, 0, 0))

mlab.mesh([[x1, x2],[x3, x4],[x5, x5],[x6, x7],[x8, x8],[x9, x9],[x10, x10],
[x11, x11],[x12, x12]],  # | => x coordinate

                 [[y1, y2],
                  [y3, y4]],  # | => y coordinate

                 [[z1, z2],
                  [z3, z4]],  # | => z coordinate

                 color=(0, 0, 0))  # black


mlab.clf()
phi, theta = np.mgrid[0:np.pi:11j, 0:2*np.pi:11j]
x = np.sin(phi) * np.cos(theta)
y = np.sin(phi) * np.sin(theta)
z = np.cos(phi)
mlab.mesh(x, y, z)
mlab.mesh(x, y, z, representation='wireframe', color=(0, 0, 0))

mlab.show()
