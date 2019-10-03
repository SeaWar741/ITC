import numpy as np
from matplotlib import pyplot as plt
import matplotlib
import glob


for filename in glob.glob("*.*"):
    if '.npy' in filename:
        img_array = np.load(filename)
        plt.imshow(img_array, cmap="gray")
        img_name = filename+".png"
        matplotlib.image.imsave(img_name, img_array)
        print(filename)