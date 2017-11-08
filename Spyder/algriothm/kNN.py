# -*- coding: utf-8 -*-
"""
Created on Fri Aug 18 12:33:54 2017

@author: HanKin
"""

import numpy as np  #科学计算包
#from numpy import *
import matplotlib.pyplot as plt   #绘图包
import operator   #运算符模块

def createDataSet():
    group = np.array([[1.0,1.1],[1.0,1.0],[0,0],[0,0.1]])
    labels = ['A','A','B','B']
    return group, labels

def scatter(X, Y):
    #产生测试数据  
    x = np.arange(1,10)  
    y = x  
    fig = plt.figure()  
    ax = fig.add_subplot(111)  
    #设置标题  
    ax.set_title('Scatter Plot')  
    #设置X轴标签  
    plt.xlabel('X')  
    #设置Y轴标签  
    plt.ylabel('Y')  
    #添加批注
    for i in range(4):
        ax.annotate(Y[i],xy=(X[i,0],X[i,1]), xytext=(X[i,0],X[i,1]))
    #画散点图  
    ax.scatter(X[:,0],X[:,1],s = 75,c = 'r',marker = 'o',alpha=.5)  
    #设置图标  
    plt.legend('X')  
    #显示所画的图  
    plt.show()
    
def classify0(inX, dataSet, labels, k):
    dataSetSize = dataSet.shape[0]
    diffMat = np.tile(inX, (dataSetSize,1)) - dataSet #前面是生成相同维数的矩阵相减
    sqDiffMat = diffMat**2
#    print(diffMat)
#    print(sqDiffMat)
    sqDistances = sqDiffMat.sum(axis=1)
    distances = sqDistances**0.5
#    print()
#    print(distances)
    sortedDistIndicies = distances.argsort()  #从小到大排序，获得索引值
#    print(sortedDistIndicies)    
    classCount={}          
    for i in range(k):
        voteIlabel = labels[sortedDistIndicies[i]]
        classCount[voteIlabel] = classCount.get(voteIlabel,0) + 1
    sortedClassCount = sorted(classCount.items(), key=operator.itemgetter(1), reverse=True)
    return sortedClassCount[0][0] 

if __name__=='__main__':
    group, labels = createDataSet()
    print(group)
    print(labels)
    print(group.shape)
    
    #散点图
    scatter(group,labels)
    
    #k-近邻算法
    result = classify0((0.8,0.6),group,labels,3)
    print(result)










