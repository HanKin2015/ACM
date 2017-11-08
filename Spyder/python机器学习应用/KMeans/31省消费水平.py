import numpy as np
from sklearn.cluster import KMeans


def loadData(filePath):
    # r +：读写打开一个文本文件
    # .read()每次读取整个文件，它通常用于将文件内容放到一个字符串变量中
    # .readlines()一次读取整个文件（类似于.read() )
    # .readline()每次只读取一行，通常比.readlines()慢得多。仅当没有足够内存可以一次读取整个文件时，才应该使用.readline()。
    fr = open(filePath,'r+',encoding='utf-8')
    lines = fr.readlines()
    retData = []
    retCityName = []
    for line in lines:
        items = line.strip().split(",")
        retCityName.append(items[0])
        retData.append([float(items[i]) for i in range(1,len(items))])
    for i in range(1,len(items)):
        return retData,retCityName

if __name__ == '__main__':
    # 1.利用loadData方法读取数据
    # 2.创建实例
    # 3.调用Kmeans() fit_predict()方法进行计算
    data, cityName = loadData('./city.txt')
    km = KMeans(n_clusters=3)
    label = km.fit_predict(data)
    expenses = np.sum(km.cluster_centers_, axis=1)
    # print(expenses)
    CityCluster = [[], [], []]
    for i in range(len(cityName)):
        CityCluster[label[i]].append(cityName[i])
    for i in range(len(CityCluster)):
        print("Expenses:%.2f" % expenses[i])
        print(CityCluster[i])

