# -*- coding: utf-8 -*-
"""
Created on Thu Sep 28 14:09:25 2017

@author: HanKin
"""

# 导入必要的库文件
import numpy as np   # 数组数据处理
import pandas as pd  # 文件的读取

df = pd.DataFrame({'first':[1,2,3,4],'second':[11,22,33,44]})
print(df)
df.to_csv("tsv.tsv",sep='\t',header=True,index=False)
df.to_csv("txt.txt",sep='*',index=False)