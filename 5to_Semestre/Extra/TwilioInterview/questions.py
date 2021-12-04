#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'validateImageSize' function below.
#
# The function is expected to return a 2D_STRING_ARRAY.
# The function accepts following parameters:
#  1. 2D_STRING_ARRAY imageUrls
#  2. STRING maxSize
#

def validateImageSize(imageUrls, maxSize):

    #maxSize to lower case
    maxSize = maxSize.lower()

    #check if maxSize is in mb
    if maxSize[-2:] == 'mb':
        maxSize = maxSize[:-2]
        maxSize = int(maxSize)
        maxSize = maxSize * 1000000
    #check if maxSize is in kb
    elif maxSize[-2:] == 'kb':
        maxSize = maxSize[:-2]
        maxSize = int(maxSize)
        maxSize = maxSize * 1000
    #check if maxSize is in gb
    elif maxSize[-2:] == 'gb':
        maxSize = maxSize[:-2]
        maxSize = int(maxSize)
        maxSize = maxSize * 1000000000
    #check if maxSize is g 
    elif maxSize[-1] == 'g':
        maxSize = maxSize[:-1]
        maxSize = int(maxSize)
        maxSize = maxSize * 1000000000

    #check if maxSize is in b
    elif maxSize[-1:] == 'b':
        maxSize = maxSize[:-1]
        maxSize = int(maxSize)

    #check if maxSize is none
    elif maxSize == 'none':
        maxSize = 1000000000

    # Write your code here
    images = []
    
    for image in imageUrls:
        #get the size of the image
        validity = True
        imageSize = image[1]
        if int(imageSize) > maxSize:
            validity = False
        images.append([image[0],str(validity).upper()])
    return images


data =[['https://svs.gsfc.nasa.gov/vis/a030000/a030800/a030877/frames/5760x3240_16x9_01p/BlackMarble_2016_928m_conus_labeled.png', '32000000']]
size = '122GB'

result = validateImageSize(data, size)

#print all the images
for image in result:
    print(image[0])
    print(image[1])