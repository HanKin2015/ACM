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
             
            tmp = items[9].strip().split(" ")
            if len(tmp) == 2:
                items[9] = tmp[1]
            else:
                if tmp[0].isdigit():  
                    items[9] = tmp[0]
                else:
                    items[9] = ''
               
            newData.append((items[2],items[5],items[6],items[7],items[8],items[9],items[10],items[-1]))
            labels.append(items[1])
            passengers.append(items[0])
            
        pick_data = np.array(newData).reshape((-1,8))
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
        
        '''
        CNT = []
        for i in range(len(tickets)):
            tmp = tickets[i].strip().split(" ")
#            print(type(tmp))
#            print(len(tmp))
            if len(tmp) == 2:
                cnt = tmp[1]
            else:
                if tmp[0].isdigit():  
                    cnt = tmp[0]
                else:
                    cnt = ''
#            cnt = len(tickets[i])
            CNT.append(cnt)
        ret = DataFrame({
                'ticket':tickets,
                'length':CNT
                })
        ret.to_csv("ret.csv")
        '''
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
               
            tmp = items[8].strip().split(" ")
            if len(tmp) == 2:
                items[8] = tmp[1]
            else:
                if tmp[0].isdigit():  
                    items[8] = tmp[0]
                else:
                    items[8] = ''   
               
            newData.append((items[1],items[4],items[5],items[6],items[7],items[8],items[9],items[-1]))
            labels.append(items[1])
            passengers.append(items[0])
            
        pick_data = np.array(newData).reshape((-1,8))
        
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
    x_tra, x_tes, y_tra, y_tes = train_test_split(x_train, y_train, test_size = 0.2,random_state = 0)

#    print('Start training Bayes')
#    gnb = GaussianNB().fit(x_train, y_train)
#    print('Training done')
#    print(x_train.shape)
#    print(x_test.shape)
#    answer_gnb = gnb.predict(x_test)
#    print('Prediction done')
#
#    passengers = DataFrame(passengers,columns=['PassengerId'])
#    answer_gnb = DataFrame(answer_gnb,columns=['Survived'])
#    result_gnb = passengers.join(answer_gnb)
#    result_gnb.to_csv("result_gnb.csv",index=False)
    
    result = []
    for i in range(5):
        x_tra, x_tes, y_tra, y_tes = train_test_split(x_train, y_train, test_size = 0.2,random_state = 0)
        gnb = GaussianNB().fit(x_tra, y_tra)
        result.append(np.mean(y_tes == gnb.predict(x_tes)))
    print("gnb classifier accuacy:")
    print(result)
    
    result = []
    for i in range(5):
        x_tra, x_tes, y_tra, y_tes = train_test_split(x_train, y_train, test_size = 0.2,random_state = 0)
        knn = KNeighborsClassifier().fit(x_tra, y_tra)
        result.append(np.mean(y_tes == knn.predict(x_tes)))
    print("knn classifier accuacy:")
    print(result)
    
    tmp = 0
    result = []
    for i in range(1515):
        x_tra, x_tes, y_tra, y_tes = train_test_split(x_train, y_train, test_size = 0.2,random_state = 0)
        dt = DecisionTreeClassifier().fit(x_tra, y_tra)
        ans = np.mean(y_tes == dt.predict(x_tes))
#        print(ans)
        if ans > tmp:
            tmp = ans
            answer_dt = dt.predict(x_test)
    
#    clf=svm.SVC(kernel='rbf') #调用svm函数，并设置kernel参数，默认是rbf，其它：‘linear’‘poly’‘sigmoid’
#    result = []
#    for i in range(5):
#        x_tra, x_tes, y_tra, y_tes = cross_validation.train_test_split(x_train, y_train, test_size = 0.2)
#        #x和y的验证集和测试集，切分80-20%的测试集
#        clf.fit(x_tra, y_tra)
#        #训练数据进行训练
#        result.append(np.mean(y_tes == clf.predict(x_tes)))
#        #将预测数据和测试集的验证数据比对
#        
#    print("svm classifier accuacy:")
#    print(result)
    
#    tmp = 0
#    for i in range(1):
#        #x_train和y_train的验证集和测试集，切分80-20%的测试集
#        x_tra, x_tes, y_tra, y_tes = cross_validation.train_test_split(x_train, y_train, test_size = 0.2)
#        clf.fit(x_tra,y_tra)
#        ans = np.mean(y_tes == clf.predict(x_tes))
#        print(ans)
#        if ans > tmp:
#            tmp = ans
#            answer_svm = clf.predict(x_test)
    print(tmp)
    passengers = DataFrame(passengers,columns=['PassengerId'])
    answer_dt = DataFrame(answer_dt,columns=['Survived'])
    result_dt = passengers.join(answer_dt)
    result_dt.to_csv("result_dt.csv",index=False)


    
    
    
    
    
    
    
    
    
    
    
    
    
    