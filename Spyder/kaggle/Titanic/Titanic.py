import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split

#导入分类器
from sklearn.neighbors import KNeighborsClassifier
from sklearn.tree import DecisionTreeClassifier
from sklearn.naive_bayes import GaussianNB
from pandas import DataFrame
from sklearn.ensemble import RandomForestClassifier  
from sklearn.linear_model import LogisticRegression  #导入逻辑回归模块   
from sklearn import cross_validation  #导入交叉检验  

# 读取数据
trainSets = pd.read_csv('./trainSets.csv',header=0)
testSets = pd.read_csv('./testSets.csv')
trainSets_Survived = pd.read_csv('./trainSets_Survived.csv')
passengers = pd.read_csv('./passengers.csv')

print(passengers[0:10])

#print('rfc start!!!')
#max_rate = 0
#result = []
#for i in range(5):
#    x_train, x_test, y_train, y_test = train_test_split(trainSets, trainSets_Survived, test_size = 0.2, random_state = 0)
#    rfc = RandomForestClassifier(n_estimators=1000, random_state=312, min_samples_leaf=3).fit(x_train, y_train)
#    tmp = np.mean(y_test == rfc.predict(x_test))
#    print(tmp)
#    if tmp > max_rate:
#        max_rate = tmp
#        answer_rfc = rfc.predict(testSets)
#result_rfc = DataFrame({
#        'PassengerId':passengers,
#        'Survived':answer_rfc
#        })
#result_rfc.to_csv("result_rfc.csv",index=False)
#
#print('clf start!!!')
#
#max_rate = 0
#result = []
#for i in range(5):
#    x_train, x_test, y_train, y_test = train_test_split(trainSets_p, trainSets_Survived, test_size = 0.2, random_state = 0)
#    clf = LogisticRegression(C=100).fit(x_train, y_train)
#    tmp = np.mean(y_test == clf.predict(x_test))
#    print(tmp)
#    if tmp > max_rate:
#        max_rate = tmp
#        answer_clf = clf.predict(testSets_p)
#result_clf = DataFrame({
#        'PassengerId':passengers,
#        'Survived':answer_clf
#        })
#result_clf.to_csv("result_clf.csv",index=False)
















