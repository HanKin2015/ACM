# -*- coding: utf-8 -*-
"""
Created on Fri Aug 11 19:14:04 2017

@author: HanKin
"""

import numpy as np
from numpy.linalg import *

def main():
    lst = [[1,3,5],[2,4,6]]
    print(type(lst))
    np_lst = np.array(lst)
    '''
    print(type(np_lst))
    np_lst = np.array(lst, dtype = np.float)
    #bool,int/8/16/32/64/128,uint8/16/32/64/128,float/16/32/64,complex64/128,string
    print(np_lst.shape)
    print(np_lst.ndim)
    print(np_lst.dtype)
    print(np_lst.itemsize)
    print(np_lst.size)
    
    #2 Some Arrays
    print(np.zeros([2,4]))
    print(np.ones([3,5]))
    print('Rand:')
    print(np.random.rand(2,4))
    print(np.random.rand())
    print('RandInt前面两个数是范围，后面表示连续生成3个随机数:')
    print(np.random.randint(1,10,3))
    print('Randn标准正态分布的随机数:')
    print(np.random.randn())
    print(np.random.randn(2,4))
    print('Choice:')
    print(np.random.choice([10,2,3,4]))
    print('Distribute满足数学的贝塔分布:')
    print(np.random.beta(1,10,3))
    #3 Array Opes
    lst =  (np.arange(1, 11)) #产生一个1-11（不含11）的等差数列
    lst =  (np.arange(1, 11).reshape([2, 5])) # 变成两行五列数组
    print(np.arange(1, 11))
    print(np.arange(1, 11).reshape([2, 5]))
    print (np.exp(lst))  # list 的自然指数
    print (np.exp2(lst)) # list 的自然指数的平方
    print (np.sqrt(lst)) # list 的开方
    print (np.square(lst)) # list 的平方
    print (np.sin(lst)) # list 的正弦值
    print (np.log(lst)) # list 的对数值
    print (lst.sum())  #求和
    '''
    '''
    list = np.array([[[1, 2, 3, 4],
                      [4, 5, 6, 7, ]],
                    [[7, 8, 9, 10],
                    [11, 12, 13, 14]],
                    [[15, 16, 17, 18],
                    [19, 20, 21, 22]]
                     ])
    print(list.shape)
    # axis取值跟维数有关，维数从 0 开始算起，axis值越大，深入的程度越深
    print (list.sum(axis=0))# axis表示维度，sxis=0,表示最外层的元素相加
    print (list.sum(axis=1))# 表示最外层减一层的元素相加
    print (list.max(axis=0)) # 最外层元素中的最大元素值
    print (list.min(axis=0)) # 最外层元素中的最小元素值
    list1 = np.array([10, 20, 30, 40])
    list2 = np.array(([4, 3, 2, 1]))
    print(list1 + list2) # 对两个list中的元素相加，ps:不是将一个数组中的元素放在另一个后面
    print (list1-list2) # 对两个list中的元素相
    print (list1*list2) #乘
    print (list1/list2)# 对两个list中的元素相除
    print (list1**2) # 对两个list中的元素平方
    print (list1.reshape([2, 2]))
    print (list2.reshape([2, 2]))
    print (np.dot(list1.reshape([2, 2]), list2.reshape([2, 2]))) # 数组点乘
    print(np.concatenate((list1,list2),axis = 0)) #将两个数组相连，即list2添加到list1中，传的是tup
    print (np.vstack((list1,list2))) #将两个数组分成两行组成一个数组也就是以行连接，注意传的是个tuple
    print (np.hstack((list1,list2))) #将两个数组相连组成一个一维数组，传的是tup
    print (np.split(list1,2)) #将数组 list1 切分成n个子数组
    print (np.copy(list1)) #对数组进行拷贝
    '''
    #矩阵操作与线性方程组liner
    # from numpy.linalg import *
    print (np.eye(3))  #他是一个3行3列的单位矩阵
    list = np.array(([1, 2],
                     [3, 4]))
    print (inv(list)) #逆矩阵
    print (list.transpose()) # 转置矩阵
    print (det(list)) #求行列式（算的是行列式的值）
    print (eig(list)) #特征值和特征向量
    y = np.array(([5.], [7.]))
    # {x+2y=5  3x+4y=7}
    print (solve(list, y)) #求list与y组成的二元一次方程组的解
    
    #numpy的其他操作
    print("FFT:") #使用fft函数对余弦波信号进行傅里叶变换。
    print (np.fft.fft(np.array([1,1,1,1,1,1,1,])))
    print (np.corrcoef([1, 0, 1],[0, 2, 1])) # 皮尔逊相关系数计算
    print (np.poly1d([3,1,3])) # 生成一元多次函数

if __name__=="__main__":
    main()
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    