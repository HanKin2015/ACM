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
    for path in feature_paths:
        file = open(path, encoding='utf-8')
        newData = []
        labels = []
        passengers = []
        
        #提取所需的特征值的数据
        for line in islice(file, 1, None):
            items = line.strip().split(",")
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
            newData.append((items[2],items[5],items[6],items[7],items[8],items[10],items[-1]))
            labels.append(items[1])
            passengers.append(items[0])
            
        pick_data = np.array(newData).reshape((-1,7))
        sampleNum = len(newData)
        
        #保存提取的数据集
        pick_data = DataFrame(pick_data)
        pick_data.to_csv("pick_data.csv",index=False)
        
        #使用pandas库的read_table函数读取一个特征文件的内容，其中指定分隔符为逗号、缺失值为问号且文件不包含表头行
        real_data = pd.read_table('./pick_data.csv', delimiter=',', na_values='?')
        #使用Imputer函数，通过设定strategy参数为‘mean’，使用平均值对缺失数据进行补全。 
        imp = Imputer(missing_values='NaN', strategy='mean', axis=0)
        #fit()函数用于训练预处理器，transform()函数用于生成预处理结果。
        imp.fit(real_data)
        real_data = imp.transform(real_data)
        
        #保存完美的数据集
#        print(type(real_data))
        real_data = DataFrame(real_data)
        print(real_data.shape)
        real_data.to_csv("real_data.csv",index=False,header=False)
        
        labels = np.ravel(labels)
        print(labels.shape)
        passengers = np.ravel(passengers)
    file.close()
    return real_data, labels, passengers

def load_testDatasets(feature_paths, label_paths):
    '''
    读取特征文件和标签文件并返回
    '''
    for path in feature_paths:
        file = open(path, encoding='utf-8')
        newData = []
        labels = []
        passengers = []
        
        #提取所需的特征值的数据
        for line in islice(file, 1, None):
            items = line.strip().split(",")
            #数值化数据
            if items[4] == 'male':
                items[4] = 1
            else:
               items[4] = 2
            if items[-1] == 'C':
                items[-1] = 1
            elif items[-1] == 'Q':
                items[-1] = 2
            else:
               items[-1] = 3
            newData.append((items[1],items[4],items[5],items[6],items[7],items[9],items[-1]))
            labels.append(items[1])
            passengers.append(items[0])
            
        pick_data = np.array(newData).reshape((-1,7))
        
        #保存提取的数据集
        pick_data = DataFrame(pick_data)
        pick_data.to_csv("pick_data.csv",index=False)
        
        #使用pandas库的read_table函数读取一个特征文件的内容，其中指定分隔符为逗号、缺失值为问号且文件不包含表头行
        real_data = pd.read_table('./pick_data.csv', delimiter=',', na_values='?')
        #使用Imputer函数，通过设定strategy参数为‘mean’，使用平均值对缺失数据进行补全。 
        imp = Imputer(missing_values='NaN', strategy='mean', axis=0)
        #fit()函数用于训练预处理器，transform()函数用于生成预处理结果。
        imp.fit(real_data)
        real_data = imp.transform(real_data)
        
        #保存完美的数据集
#        print(type(real_data))
        real_data = DataFrame(real_data)
        print(real_data.shape)
        real_data.to_csv("real_data.csv",index=False,header=False)
        
        labels = np.ravel(labels)
        print(labels.shape)
        passengers = np.ravel(passengers)
    file.close()
    return real_data, labels, passengers

if __name__ == '__main__':
    ''' 数据路径 '''
    featurePaths = ['./train.csv']
    labelPaths = ['./train.csv']
    testPaths = ['./test.csv']
    testLabelPaths = ['./test.csv']

    ''' 读入数据  '''
    x_train,y_train,temp = load_datasets(featurePaths[:],labelPaths[:])
    x_test,y_test,passengers = load_testDatasets(testPaths[:],testLabelPaths[:])

    #使用train_test_split()函数，通过设置测试集比例test_size为0，将数据随机打乱，便于后续分类器的初始化和训练。
    x_train, x_, y_train, y_ = train_test_split(x_train, y_train, test_size = 0.0,random_state = 0)

    print('Start training Bayes')
    gnb = GaussianNB().fit(x_train, y_train)
    print('Training done')
    print(x_train.shape)
    print(x_test.shape)
    answer_gnb = gnb.predict(x_test)
    print('Prediction done')
    
    print('Start training DT')
    dt = DecisionTreeClassifier().fit(x_train, y_train)
    print('Training done')
    answer_dt = dt.predict(x_test)
    print('Prediction done')

    print('Start training knn')
    knn = KNeighborsClassifier().fit(x_train, y_train)
    print('Training done')
    answer_knn = knn.predict(x_test)
    print('Prediction done')
    
    passengers = DataFrame(passengers,columns=['PassengerId'])
    answer_gnb = DataFrame(answer_gnb,columns=['Survived'])
    result_gnb = passengers.join(answer_gnb)
    result_gnb.to_csv("result_gnb.csv",index=False)
    
    answer_dt = DataFrame(answer_dt,columns=['Survived'])
    result_dt = passengers.join(answer_dt)
    result_dt.to_csv("result_dt.csv",index=False)
    
    answer_knn = DataFrame(answer_knn,columns=['Survived'])
    result_knn = passengers.join(answer_knn)
    result_knn.to_csv("result_knn.csv",index=False)

#    print('\n\nThe classification report for Bayes:')
#    print(classification_report(y_test, answer_gnb))
    
    
    
    
    
    
    
    
    
    
    
    
    
    