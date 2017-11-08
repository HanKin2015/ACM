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

def load_datasets(feature_paths, label_paths):
    '''
    读取特征文件和标签文件并返回
    '''
    #定义feature数组变量，列数量和特征维度一致为41；定义空的标签变量，列数量与标签维度一致为1
    feature = np.ndarray(shape=(0,41))
    label = np.ndarray(shape=(0,1))
    for file in feature_paths:
        #使用pandas库的read_table函数读取一个特征文件的内容，其中指定分隔符为逗号、缺失值为问号且文件不包含表头行
        #df = pd.read_table(file, delimiter=',', na_values='?', header=None)
        
        #pandas.read_csv（数据源, encoding=编码格式为utf-8， parse_dates=第0列解析为日期， index_col=用作行索引的列编号）
        data=pd.read_csv(file,encoding='utf-8',parse_dates=[0],index_col=0)
        #DataFrame.sort_index(axis=0 (按0列排), ascending=True（升序）, inplace=False（排序后是否覆盖原数据））
        #data 按照时间升序排列
        #data.sort_index(0,ascending=True,inplace=True)
        
        #使用Imputer函数，通过设定strategy参数为‘mean’，使用平均值对缺失数据进行补全。 
        imp = Imputer(missing_values='NaN', strategy='mean', axis=0)
        #fit()函数用于训练预处理器，transform()函数用于生成预处理结果。
        imp.fit(df)
        df = imp.transform(df)
        #将预处理后的数据加入feature，依次遍历完所有特征文件
        feature = np.concatenate((feature, df))

    #读取标签文件
    for file in label_paths:
        df = pd.read_table(file, header=None)
        label = np.concatenate((label, df))
    #将标签归整化为一维向量    
    label = np.ravel(label)
    return feature, label

if __name__ == '__main__':
    ''' 数据路径 '''
    featurePaths = ['A/A.feature','B/B.feature','C/C.feature','D/D.feature','E/E.feature']
    labelPaths = ['A/A.label','B/B.label','C/C.label','D/D.label','E/E.label']

    ''' 读入数据  '''
    x_train,y_train = load_datasets(featurePaths[:4],labelPaths[:4])
    x_test,y_test = load_datasets(featurePaths[4:],labelPaths[4:])

    #使用train_test_split()函数，通过设置测试集比例test_size为0，将数据随机打乱，便于后续分类器的初始化和训练。
    x_train, x_, y_train, y_ = train_test_split(x_train, y_train, test_size = 0.0)
    
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