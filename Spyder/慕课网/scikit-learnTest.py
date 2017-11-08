# -*- coding: utf-8 -*-
"""
Created on Tue Aug 15 22:19:11 2017

@author: HanKin
"""

import numpy as np
import pandas as pd

def main():
    #pre-processing 预处理
    from sklearn.datasets import load_iris  #导入IRIS数据集
    iris=load_iris()  #特征矩阵
#    print(iris)
    print(len(iris['data']))
    from sklearn.cross_validation import train_test_split
    #数据集大小为150*0.2=30，随机状态为1说明随机选取
    train_data,test_data,train_target,test_target=train_test_split(iris.data,iris.target,test_size=0.2,random_state=1)
    
    #Model
    from sklearn import tree
    clf=tree.DecisionTreeClassifier(criterion="entropy")
    clf.fit(train_data,train_target)
    y_pred = clf.predict(test_data)
    
    #Veriify准确率和混淆矩阵
    from sklearn import metrics
    print(metrics.accuracy_score(y_true=test_target,y_pred=y_pred))
    #横轴表示实际值，纵轴表示预测值
    print(metrics.confusion_matrix(y_true=test_target,y_pred=y_pred))
    #矩阵中的1实际值是第二类，预测值是第三类
    
    with open('./data/tree.dot','w') as fw:
        tree.export_graphviz(clf,out_file=fw)
    
if __name__=='__main__':
    main()


