# -*- coding: utf-8 -*-
"""
Created on Wed Aug 30 10:48:48 2017

@author: HanKin
"""

# 导入必要的库文件
import numpy as np   # 数组数据处理
import pandas as pd  # 文件的读取
from sklearn.model_selection import train_test_split  # 交叉验证

# 读取数据
#trainSets = pd.read_csv('./train.csv', header=0) # header默认从0开始

#从labels和trainSets可以看出都是42000行数据，按道理讲，trainSets应该是42001行(打开csv源文件的确如此)。
#labels中没有trainSets中的第0行属性名称，只有数值。
#so：DataFrame的第0行不需要处理。注意的是他没有删除列属性名称(一般不存在)

