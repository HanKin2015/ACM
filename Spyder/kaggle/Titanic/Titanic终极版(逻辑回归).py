# -*- coding: utf-8 -*-
"""
Created on Sat Aug 26 11:49:46 2017

@author: HanKin
"""

import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split


# 读取数据
trainSets = pd.read_csv('./train.csv',header=0)
testSets = pd.read_csv('./test.csv')
#print(type(trainSets))
#print(trainSets.shape)

# 清洗数据  
## 去除乘客姓名、船票信息和客舱编号三个不打算使用的列
trainSets_p = trainSets.drop(['Name','Ticket','Cabin'], axis=1)  
testSets_p = testSets.drop(['Name','Ticket','Cabin'], axis=1)  
#print(trainSets_p.shape) 
#print(trainSets.shape)

## 接着是兄弟姐妹配偶（SibSP）以及父母子女（ParCh），在此我将两者数字加和，作为亲属的数据（没有什么必要分开计算吧），模式也是与上一个类似的，分组聚合，然后画图：
trainSets_p['Relatives'] = trainSets_p['SibSp'] + trainSets_p['Parch']
testSets_p['Relatives'] = testSets_p['SibSp'] + testSets_p['Parch']
#print(trainSets_p.shape)

## 处理缺失值
#print(trainSets_p['Age'].isnull())
#print(trainSets_p['Age'].median())
#print(trainSets_p['Embarked'].mode().values)
#trainSets_p.loc[trainSets_p['Age'].isnull(), 'Age'] = trainSets_p['Age'].median()
#trainSets_p.loc[trainSets_p['Fare'].isnull(), 'Fare'] = trainSets_p['Fare'].median()  
#trainSets_p.loc[trainSets_p['Embarked'].isnull(), 'Embarked'] = trainSets_p['Embarked'].mode().values  
#
#testSets_p.loc[testSets_p['Age'].isnull(), 'Age'] = testSets_p['Age'].median()
#testSets_p.loc[testSets_p['Fare'].isnull(), 'Fare'] = testSets_p['Fare'].median()  
#testSets_p.loc[testSets_p['Embarked'].isnull(), 'Embarked'] = testSets_p['Embarked'].mode().values  
#print(trainSets_p[0:10])

## 字符转换数值化
sex_to_digi = {'male':1,'female':0}  
ebk_to_digi = {'C':-1,'Q':0,'S':1}  
trainSets_p['Sex'] = trainSets_p['Sex'].map(sex_to_digi)  #将性别转化为数值  
trainSets_p['Embarked'] = trainSets_p['Embarked'].map(ebk_to_digi)  #将上船地点转化为数值  
#trainSets_p['Sex'] = pd.factorize(trainSets_p['Sex'])[0]  
#trainSets_p['Embarked'] = pd.factorize(trainSets_p['Embarked'])[0] 
#
testSets_p['Sex'] = pd.factorize(testSets_p['Sex'])[0]  
testSets_p['Embarked'] = pd.factorize(testSets_p['Embarked'])[0] 

## 最终提取的数据
trainSets_Survived = trainSets_p['Survived']
passengers = testSets_p['PassengerId']
trainSets_p = trainSets_p.drop(['PassengerId', 'SibSp', 'Parch'], axis=1) 
testSets_p = testSets_p.drop(['PassengerId', 'SibSp', 'Parch'], axis=1) 
#print(trainSets_p[0:10])
#print(testSets_p[0:10])

## 训练模型
#使用train_test_split()函数，通过设置测试集比例test_size为0，将数据随机打乱，便于后续分类器的初始化和训练。
x_train, x_test, y_train, y_test = train_test_split(trainSets_p, trainSets_Survived, test_size = 0.2, random_state = 0)

#导入分类器
from sklearn.neighbors import KNeighborsClassifier
from sklearn.tree import DecisionTreeClassifier
from sklearn.naive_bayes import GaussianNB
from pandas import DataFrame
from sklearn.ensemble import RandomForestClassifier  
from sklearn.linear_model import LogisticRegression  #导入逻辑回归模块   
from sklearn import cross_validation  #导入交叉检验  

trainSets_NA = trainSets_p[np.isnan(trainSets_p['Age'])]  #不含Age项  
trainSets_A = trainSets_p.dropna()  #含Age项，与上一句顺序不要颠倒  

print(trainSets_p.shape)
print(trainSets_NA.shape)
print(trainSets_A.shape)
  
trainSets_A_features  = trainSets_A[['Pclass','Sex','Age','Embarked','Relatives']]  #选取features  
trainSets_NA_features  = trainSets_NA[['Pclass','Sex','Embarked','Relatives']]  #选取features  
trainSets_A_target = trainSets_A['Survived']  #选取target  
trainSets_NA_target = trainSets_NA['Survived']  #选取target 

classifier = LogisticRegression()  #有Age  默认C=1
classifierNA = LogisticRegression()  #无Age  
  
#拟合  
classifier.fit(trainSets_A_features,trainSets_A_target)  
classifierNA.fit(trainSets_NA_features,trainSets_NA_target)  

testSets_p = testSets_p[['Pclass','Sex','Age','Embarked','Relatives']] 

result = []
#分情况预测  
for i in range(len(testSets_p)):    
    if np.isnan(testSets_p['Age'][i]):  
        x_test = testSets_p[['Pclass','Sex','Embarked','Relatives']].iloc[i]
        x_test = x_test.reshape(1,-1)
        ans = classifierNA.predict(x_test)
        result.append(ans)
#        testSets_features.iloc[i]=testSets_p[['Pclass','Sex','Embarked','Relatives']].iloc[i]  
#        testSets_p['Predict'][i]=classifierNA.predict(testSets_features.iloc[i].dropna())  
    else:  
        x_test = testSets_p[['Pclass','Sex','Age','Embarked','Relatives']].iloc[i]
#        print(x_test.shape)
        x_test = x_test.reshape(1,-1)
#        print(x_test.shape)
        ans = classifier.predict(x_test)
        result.append(ans)
#        print(ans)
result = np.array(result)
result = result.ravel()
print(result.shape) 

#max_rate = 0
#result = []
#for i in range(12):
#    x_train, x_test, y_train, y_test = train_test_split(trainSets_p, trainSets_Survived, test_size = 0.2, random_state = 0)
#    rfc = RandomForestClassifier(n_estimators=1000, random_state=312, min_samples_leaf=3).fit(x_train, y_train)
#    tmp = np.mean(y_test == rfc.predict(x_test))
#    print(tmp)
#    if tmp > max_rate:
#        max_rate = tmp
#        answer_dt = rfc.predict(x_test)
#print(max_rate)
print(passengers.shape)
#print(answer_dt.shape)
result_clf = DataFrame({
        'PassengerId':passengers,
        'Survived':result
        })
result_clf.to_csv("result_clf.csv",index=False)


#print(trainSets_p[0:10])





