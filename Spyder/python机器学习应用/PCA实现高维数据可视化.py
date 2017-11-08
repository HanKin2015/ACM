# -*- coding: utf-8 -*-
"""
Created on Wed Aug 23 16:22:48 2017

@author: HanKin
"""

# 1. 建立工程，导入sklearn相关工具包
import matplotlib.pyplot as plt    #加载matplotlib用于数据的可视化
from sklearn.decomposition import PCA   #加载PCA算法包
from sklearn.datasets import load_iris   #加载鸢尾花数据集导入函数

if __name__ == '__main__':
    # 2. 加载数据并进行降维
    data = load_iris()    #以字典形式加载鸢尾花数据集
    print(type(data))
    y = data.target #使用y表示数据集中的标签,处理过了
    print(y[0:20])
    X = data.data #使用X表示数据集中的属性数据
    print(X[0:20])
    pca = PCA(n_components=2)    #加载PCA算法，设置降维后主成分数目为2
    reduced_X = pca.fit_transform(X)    #对原始数据进行降维，保存在reduced_X中
    
    # 3. 按类别对降维后的数据进行保存
    red_x, red_y = [], []#第一类数据点
    blue_x, blue_y = [], []#第二类数据点
    green_x, green_y = [], []#第三类数据点
    
    #按照鸢尾花的类别将降维后的数据点保存在不同的列表中。
    for i in range(len(reduced_X)):
        if y[i] == 0:
            red_x.append(reduced_X[i][0])
            red_y.append(reduced_X[i][1])
        elif y[i] == 1:
            blue_x.append(reduced_X[i][0])
            blue_y.append(reduced_X[i][1])
        else:
            green_x.append(reduced_X[i][0])
            green_y.append(reduced_X[i][1])

    # 4. 降维后数据点的可视化
    plt.scatter(red_x, red_y, c='r', marker='x')  #第一类数据点
    plt.scatter(blue_x, blue_y, c='b', marker='D')#第二类数据点
    plt.scatter(green_x, green_y, c='g', marker='.')#第三类数据点
    plt.show()#可视化







