# -*- coding: utf-8 -*-
"""
Created on Fri Aug 18 14:37:10 2017

@author: HanKin
"""
import numpy as np

def fun():
    arr = np.array([[2,3],[6,7],[1,2]])
    arr = np.mat(arr)   #增加这一行会出现错误，生成矩阵
    print(arr)
    brr = arr**2
    print(brr)
    crr = arr*arr
    print(crr)
    drr = np.mat(arr)
    print(drr)

if __name__=='__main__':
    fun()
    
    