# -*- coding: utf-8 -*-
"""
Created on Sun Sep 17 09:44:35 2017

@author: HanKin
"""

from pandas import Series, DataFrame  
  
data = DataFrame({'k': [1, 1, 2, 2],'y':[2,2,4,1]})  
  
print(data)  
  
IsDuplicated = data.duplicated()  
  
print(IsDuplicated)  
print(type(IsDuplicated)) 
  
data = data.drop_duplicates()  
print(data)  