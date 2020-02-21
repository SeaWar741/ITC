import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

xs = np.linspace(0, 10, 100)
zs = np.linspace(0, 10, 100)

X, Z = np.meshgrid(xs, zs)
Y = 0

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X, Y, Z)



xs = np.linspace(0, 10, 100)
zs = np.linspace(0, 10, 100)

X, Z = np.meshgrid(xs, zs)
Y = 5



ax.plot_surface(X, Y, Z)
plt.show()