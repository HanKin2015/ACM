# -*- coding: utf-8 -*-
"""
Created on Wed Aug 23 11:57:54 2017

@author: HanKin
"""

# 导入必要模块
from numpy import *
import operator
import matplotlib.pyplot as plt
from os import listdir
from pylab import mpl

# 设置中文字体
# mpl.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['font.sans-serif']=['SimHei'] #用来正常显示中文标签
plt.rcParams['axes.unicode_minus']=False #用来正常显示负号

# 准备数据
def file2matrix(filename):
    fr = open(filename)
    arrayOLines = fr.readlines()
    numberOfLines = len(arrayOLines)         #get the number of lines in the file
    returnMat = zeros((numberOfLines,3))        #prepare matrix to return
    classLabelVector = []                       #prepare labels return
    fr = open(filename)
    index = 0
    for line in fr.readlines():
        line = line.strip() #移除头尾的指定符（回车字符），默认空格
        listFromLine = line.split('\t')  #以行进行读取，以\t进行分割
        returnMat[index,:] = listFromLine[0:3]
        classLabelVector.append(int(listFromLine[-1]))
        index += 1
    return returnMat,classLabelVector

# 分析可视化数据
def scatter(data, datingLabels):
    fig = plt.figure()
    ax = fig.add_subplot(111)
    numData = len(data)
    r = tile(datingLabels[0],3)
    print(r)
#    print(type(datingLabels))
#    print(type(array(datingLabels)))
#    print(datingLabels)
#    print(array(datingLabels))
    # ax.scatter(data[:,1], data[:,2], s=20, c='r', marker='x')
#    ax.scatter(data[:, 1], data[:, 2], s = 15.0 * array(datingLabels), c = 15.0 * array(datingLabels), label = array(datingLabels))
    col = ['r','y','b','g']
    for i in range(numData):
#        ax.scatter(data[i,1], data[i,2], s = 15.0*datingLabels[i], c=tile(float(datingLabels[i])/4.0,3), label = datingLabels[i])
        ax.scatter(data[i,1], data[i,2], s = 15.0*datingLabels[i], c=col[datingLabels[i]], label = datingLabels[i])
    ax.set_title('scatter')
    plt.xlabel(u'玩视频游戏所消耗时间百分比')
    plt.ylabel(r'每周消费的冰淇淋公升数')
#    plt.grid(True)
    plt.legend(loc = 'upper left') #lower
    plt.show()

if __name__=='__main__':
    datingDataMat, datingLabels = file2matrix('./data.txt')
#    datingDataMat, datingLabels = file2matrix('./datingTestSet2.txt')
#    print(datingDataMat[0:3])
#    print(datingLabels[0:20])
    scatter(datingDataMat, datingLabels)


