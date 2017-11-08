# -*- coding: utf-8 -*-
"""
Created on Wed Aug 30 16:22:59 2017

@author: HanKin
"""

from pandas import DataFrame
ImageId = []
for i in range(140):
    ImageId.append(i+1)
ImageId = DataFrame(ImageId)
print(ImageId.shape)
print(ImageId.head(3))

arr = [2,3,4,5]
brr = [1,2,3,4]
arr = DataFrame(arr)
crr = DataFrame({
        'r':arr,
        'e':brr
        })
print(crr)
