import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

#0.5*x^4+0.5y^4

x=np.arange(16)
y=np.arange(16)
z=np.arange(16)

def f(x, y):
    return (0.5*x**4+0.5*y**4)

x = np.linspace(-4000, 4000)
y = np.linspace(-4000, 4000)

X, Y = np.meshgrid(x, y)
Z = f(X, Y)


fig = plt.figure()
ax = plt.axes(projection='3d')
ax.contour3D(X, Y, Z, 80, cmap='binary')

ax.get_proj = lambda: np.dot(Axes3D.get_proj(ax), np.diag([0.5, 0.5, 1, 1]))

ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z');

plt.show()
