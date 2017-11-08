# -*- coding: utf-8 -*-
"""
Created on Wed Aug 23 21:17:10 2017

@author: HanKin
"""

from sklearn.neighbors import KNeighborsClassifier

if __name__ == '__main__':
    X = [[0],[1],[2],[3]]
    y = [0,0,1,1]
    # 实例
    neigh = KNeighborsClassifier(n_neighbors=3) 
    # 训练学习
    neigh.fit(X,y)
    print(neigh.predict([[1.1]]))
    
    
    
    
    
    
    
    
    
    