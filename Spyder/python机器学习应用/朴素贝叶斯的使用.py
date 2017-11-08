# -*- coding: utf-8 -*-
"""
Created on Thu Aug 24 10:27:57 2017

@author: HanKin
"""

import numpy as np
from sklearn.naive_bayes import GaussianNB

X = np.array([[-1, -1], [-2, -1], [-3, -2], [1, 1], [2, 1], [3, 2]])
Y = np.array([1, 1, 1, 2, 2, 2]) 

# 使用默认参数，创建一个高斯朴素贝叶斯分类器，并将该分类器赋给变量clf。
clf = GaussianNB(priors=None)
clf.fit(X, Y)
print(clf.predict([[-0.8, -1]]))










