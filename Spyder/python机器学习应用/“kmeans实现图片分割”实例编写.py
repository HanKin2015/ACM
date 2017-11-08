# -*- coding: utf-8 -*-
"""
Created on Wed Aug 23 19:37:59 2017

@author: HanKin
"""

import numpy as np
import PIL.Image as image  #加载PIL包，用于加载创建图片
from sklearn.cluster import KMeans   #加载Kmeans算法

def loadData(filePath):
    f = open(filePath,'rb')#以二进制形式读取文件
    data = []
    img = image.open(f)
    m,n = img.size
    print(m,n)
    #将每个像素点的RGB归一化并存入data
    for i in range(m):
        for j in range(n):
            x,y,z = img.getpixel((i,j))
            data.append([x/256.0,y/256.0,z/256.0])
    f.close()
    return np.mat(data),m,n

imgData,row,col = loadData('./bull.jpg')
#聚类获取每个像素点的类别
label = KMeans(n_clusters=4).fit_predict(imgData)
label = label.reshape([row,col])

#创建一张新的灰度图保存聚类后的结果
pic_new = image.new("L", (row, col))

#根据所属类别向图片中添加灰度值
for i in range(row):
    for j in range(col):
        pic_new.putpixel((i,j), int(256/(label[i][j]+1)))

#以JPEG形式保存图像
pic_new.save("result-bull-4.jpg", "JPEG")











