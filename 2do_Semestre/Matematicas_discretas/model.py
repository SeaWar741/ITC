from mpl_toolkits.mplot3d import Axes3D
import mpl_toolkits.mplot3d.art3d as art3d
import matplotlib.pyplot as plt
import numpy as np
from matplotlib.patches import Circle
from tkinter import *
#0.5*x^4+0.5y^4
'''
x=np.arange(16)
y=np.arange(16)
z=np.arange(16)

#Funciones respecto a y
def f1(x, y):
    return (2*x+5)
def f2(x,y):
    return (-2*x+5)
def f3(x,y):
    return (2*x-5)
def f4(x,y):
    return (-2*x-5)

x = np.linspace(-4, 4)
y = np.linspace(-4, 4)

X, Y = np.meshgrid(x, y)
Z1 = f1(X,Y)
Z2 = f2(X,Y)
Z3 = f3(X,Y)
Z4 = f4(X,Y)

fig = plt.figure()
ax = plt.axes(projection='3d')

ax.contour3D(X, Y, Z1, 80, cmap='binary')
ax.contour3D(X, Y, Z2, 80, cmap='binary')
ax.contour3D(X, Y, Z3, 80, cmap='binary')
ax.contour3D(X, Y, Z4, 80, cmap='binary')

ax.get_proj = lambda: np.dot(Axes3D.get_proj(ax), np.diag([0.5, 0.5, 1, 1]))


ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z');

plt.show()
'''

#hexagonal
'''
yy, zz = np.meshgrid(range(4), range(4))
xx = (yy-5)/2

yy1, zz1 = np.meshgrid(range(4), range(4))
xx1 = (yy1-5)/(-2)

print(zz1)

yy2, zz2 = np.meshgrid(np.linspace(-4, 0, 4) , np.linspace(0, 4, 4))
xx2 = (yy2+5)/2

print(zz2)

yy3, zz3 = np.meshgrid(np.linspace(-4, 0, 4) , np.linspace(0, 4, 4))
xx3 = (yy3+5)/(-2)


xx4,zz4 = np.meshgrid(range(4),range(4))
yy4 = xx4*0

#yy4,xx4= np.meshgrid(np.linspace(-12, 12, 25), np.linspace(-5, 5, 11) )
#zz4 = (0.5*(xx4**4))+(0.8*(yy4**4))

#print(yy4)

ax = plt.subplot(projection='3d')
ax.plot_surface(xx, yy, zz)
ax.plot_surface(xx1, yy1, zz1)
ax.plot_surface(xx2, yy2, zz2)
ax.plot_surface(xx3, yy3, zz3)
ax.plot_surface(xx4, yy4, zz4)
#ax.plot_surface(xx4, yy4, zz4)
plt.show()
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