from mpl_toolkits import mplot3d
import numpy as np
import matplotlib.pyplot as plt

a = 0.1
b = 0.1

def f(x, y):
    return (x+y)

x = np.linspace(-10, 10, 15)
y = np.linspace(-10, 10, 35)

X, Y = np.meshgrid(x, y)
Z = f(X, Y)

fig = plt.figure()
ax = plt.axes(projection='3d')
ax.contour3D(X, Y, Z, 50, cmap='binary')
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z');

plt.show()