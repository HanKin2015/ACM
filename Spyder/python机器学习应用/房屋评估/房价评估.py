# -*- coding: utf-8 -*-
"""
Created on Fri Aug 25 17:34:39 2017

@author: HanKin
"""

import numpy as np
import matplotlib.pyplot as plt
from sklearn import linear_model

# 读取数据
def load_datasets(filePath): 
    file = open(filePath,'r')
    datasets_X = []
    datasets_Y = []
    lines = file.readlines()
    for line in lines:
        items = line.strip().split(',')
        datasets_X.append(int(items[0]))
        datasets_Y.append(int(items[1]))
#    datasets_X = np.ravel(datasets_X)
#    datasets_Y = np.ravel(datasets_Y)
    #将datasets_X转换为二维数组，以符合 linear.fit 函数的参数要求
    datasets_X = np.array(datasets_X).reshape([-1,1])
    datasets_Y = np.array(datasets_Y)
    print(type(datasets_X[2]))
    return dataset_X, dataset_Y    

if __name__ == '__main__':
    filePath = './prices.txt'
    # 传下来的时候里面的数据类型换了
    datasets_X, datasets_Y = load_datasets(filePath)
    print(datasets_X.shape)
    print(datasets_Y.shape)
    print(type(datasets_X[2]))
    
    #以数据datasets_X的最大值和最小值为范围，建立等差数列，方便后续画图。
    minX = int(min(datasets_X))
    maxX = int(max(datasets_X))
    print(type(minX))
    X = np.arange(minX,maxX).reshape([-1,1])
    
    linear = linear_model.LinearRegression()
    linear.fit(datasets_X, datasets_Y)
    
    # 图像中显示
    
    plt.scatter(datasets_X, datasets_Y, color = 'red',label='origin data')
    plt.plot(X, linear.predict(X), color = 'blue',label='linear regression prediction')
    plt.legend()#使label生效
    plt.xlabel('Area')
    plt.ylabel('Price')
    plt.show()
    plt.grid(True, linestyle = "-.", color = "b", linewidth = "3") 



