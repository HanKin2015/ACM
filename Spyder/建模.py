# -*- coding: utf-8 -*-
"""
Created on Sat Sep 16 16:29:07 2017

@author: HanKin
"""


import numpy as np
import pandas as pd  # 文件的读取
import matplotlib.pyplot as plt
import math

plt.rcParams['font.sans-serif']=['SimHei'] #用来正常显示中文标签

# 第一个参数是批注内容，xy是批注点，xytext是批注写在的位置
#plt.annotate("(3,6)", xy=(3, 6), xytext=(4, 5), arrowprops=dict(facecolor='black', shrink=0.1))
fig = plt.figure()
ax = fig.add_subplot(111)
plt.plot([1,3],[1,3])
plt.show()

arr = [2,3,1,3,4,6]
print(arr)
print(21 not in arr)

df = pd.DataFrame({0:[1,2,3,4,5],1:[6,7,8,9,10]})
print(df)
print(df.loc[2,1])
print(df.iloc[2][1])

df.loc[1:2,1] = 100
print(df)

ans = round(32.300320000002313,6)
print(ans)
n = 32.312362312
ans = format(n,'.4f')
print(ans)

struct = [['Z01','Z02','Z03','Z04','Z05','Z06'],[0,0,0,0,0,0]]
print(struct)
print(struct[1][1])



