import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

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
yy, zz = np.meshgrid(range(4), range(4))
xx = (yy-5)/2

yy1, zz1 = np.meshgrid(range(4), range(4))
xx1 = (yy1-5)/(-2)

yy2, zz2 = np.meshgrid(np.linspace(-4, 0, 4) , np.linspace(0, 4, 4))
xx2 = (yy2+5)/2

print(zz2)

yy3, zz3 = np.meshgrid(np.linspace(-4, 0, 4) , np.linspace(0, 4, 4))
xx3 = (yy3+5)/(-2)


yy4,xx4= np.meshgrid(np.linspace(-12, 12, 25), np.linspace(-5, 5, 11) )
zz4 = (0.5*(xx4**4))+(0.8*(yy4**4))

print(yy4)

ax = plt.subplot(projection='3d')
ax.plot_surface(xx, yy, zz)
ax.plot_surface(xx1, yy1, zz1)
ax.plot_surface(xx2, yy2, zz2)
ax.plot_surface(xx3, yy3, zz3)
ax.plot_surface(xx4, yy4, zz4)
plt.show()