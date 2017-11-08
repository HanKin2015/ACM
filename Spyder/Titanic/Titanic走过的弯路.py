# -*- coding: utf-8 -*-
"""
Created on Thu Aug 24 20:32:30 2017

@author: HanKin
"""
#导入numpy库和pandas库。
import numpy as np
import pandas as pd

#从sklearn库中导入预处理模块Imputer
#导入自动生成训练集和测试集的模块train_test_split
#导入预测结果评估模块classification_report
from sklearn.preprocessing import Imputer
from sklearn.model_selection import train_test_split
from sklearn.metrics import classification_report

#导入分类器
from sklearn.neighbors import KNeighborsClassifier
from sklearn.tree import DecisionTreeClassifier
from sklearn.naive_bayes import GaussianNB

from sklearn import svm
from sklearn import cross_validation

from pandas import DataFrame
from itertools import islice

def load_datasets(feature_paths, label_paths):
    '''
    读取特征文件和标签文件并返回
    '''
    #定义feature数组变量，列数量和特征维度一致为12；定义空的标签变量，列数量与标签维度一致为2
    feature = np.ndarray(shape=(0,12))
    label = np.ndarray(shape=(0,2))
    for path in feature_paths:
        #pandas.read_csv（数据源, encoding=编码格式为utf-8， parse_dates=第0列解析为日期， index_col=用作行索引的列编号）
#        data=pd.read_csv(path,encoding='utf-8')
        file = open(path, encoding='utf-8')
#        data = file.read()
        
#        sampleNum=data.shape[0]
#        featurenum=9*sampleNum  #选取9列数据作为特征
#        print(data.shape)
        
        newData = []
        print(type(file))
        
#        for line in file:
#            print(len(line))
#            print(line)
#            break
        
        #提取所需的特征值的数据
        for line in islice(file, 1, None):
            items = line.strip().split(",")
            #passenger
            passenger = items[0]
#            print(len(items))
#            if(len(items)!=13):
#                print(line)
            
#            newData.append(items[0])
            #数值化数据
            if items[5] == 'male':
                items[5] = 1
            else:
               items[5] = 2
            if items[-1] == 'C':
                items[-1] = 1
            elif items[-1] == 'Q':
                items[-1] = 2
            else:
               items[-1] = 3
            newData.append((items[0],items[2],items[5],items[6],items[7],items[8],items[10],items[-1]))
       
        pick_data = np.array(newData).reshape((-1,8))
#        print(real_data.shape)
        print(len(newData))
        print(newData[0])
        print(newData[6])
        print(type(pick_data))
        print(pick_data.shape)
        
        #保存提取的数据集
        pick_data = DataFrame(pick_data)
        pick_data.to_csv("pick_data.csv",index=False)
#        np.savetxt('newData.csv', real_data, delimiter = ',')
#        np.savetxt('newData.txt',real_data)
        
#        with open('/Users/michael/test.txt', 'w') as f:
#        f.write('Hello, world!')
        
        #使用pandas库的read_table函数读取一个特征文件的内容，其中指定分隔符为逗号、缺失值为问号且文件不包含表头行
        real_data = pd.read_table('./pick_data.csv', delimiter=',', na_values='?')
        #使用Imputer函数，通过设定strategy参数为‘mean’，使用平均值对缺失数据进行补全。 
        imp = Imputer(missing_values='NaN', strategy='mean', axis=0)
        #fit()函数用于训练预处理器，transform()函数用于生成预处理结果。
        imp.fit(real_data)
        real_data = imp.transform(real_data)
        
        print(type(real_data))
        real_data = DataFrame(real_data)
        real_data.to_csv("real_data.csv",index=False,header=False)
        
        
#        #将预处理后的数据加入feature，依次遍历完所有特征文件
#        feature = np.concatenate((feature, data))

#    #读取标签文件
#    for file in label_paths:
#        df = pd.read_table(file, header=None)
#        label = np.concatenate((label, df))
#    #将标签归整化为一维向量    
#    label = np.ravel(label)
    file.close()
    return feature, feature

if __name__ == '__main__':
    ''' 数据路径 '''
    featurePaths = ['./train.csv']
    labelPaths = ['./train.csv']

    ''' 读入数据  '''
    x_train,y_train = load_datasets(featurePaths[:],labelPaths[:])
#    x_test,y_test = load_datasets(featurePaths[:],labelPaths[:])

    #使用train_test_split()函数，通过设置测试集比例test_size为0，将数据随机打乱，便于后续分类器的初始化和训练。
    x_train, x_test, y_train, y_test = train_test_split(x_train, y_train, test_size = 0.1,random_state = 0)
    
    print('Start training knn')
    knn = KNeighborsClassifier().fit(x_train, y_train)
    print('Training done')
    answer_knn = knn.predict(x_test)
    print('Prediction done')

    print('Start training DT')
    dt = DecisionTreeClassifier().fit(x_train, y_train)
    print('Training done')
    answer_dt = dt.predict(x_test)
    print('Prediction done')

    print('Start training Bayes')
    gnb = GaussianNB().fit(x_train, y_train)
    print('Training done')
    answer_gnb = gnb.predict(x_test)
    print('Prediction done')

    print('\n\nThe classification report for knn:')
    print(classification_report(y_test, answer_knn))
    print('\n\nThe classification report for DT:')
    print(classification_report(y_test, answer_dt))
    print('\n\nThe classification report for Bayes:')
    print(classification_report(y_test, answer_gnb))