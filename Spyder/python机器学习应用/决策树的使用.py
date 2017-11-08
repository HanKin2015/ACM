# -*- coding: utf-8 -*-
"""
Created on Thu Aug 24 09:52:28 2017

@author: HanKin
"""

from sklearn.datasets import load_iris
# 导入决策树分类器，同时导入计算交叉验证值的函数 cross_val_score
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import cross_val_score

clf = DecisionTreeClassifier() 
iris = load_iris()

cross_val_score(clf, iris.data, iris.target, cv=10)
# 利用 fit() 函数训练模型并使用predict() 函数预测
clf.fit(X,y)
clf.predict(x)







