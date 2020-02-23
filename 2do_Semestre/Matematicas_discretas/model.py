import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

#0.5*x^4+0.5y^4

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
