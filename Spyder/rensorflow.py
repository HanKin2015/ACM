# -*- coding: utf-8 -*-
"""
Created on Thu Sep  7 19:43:19 2017

@author: HanKin
"""

import tensorflow as tf #导入tensorflow库
mat1 = tf.constant([[3., 3.]]) #创建一个1*2的矩阵
mat2 = tf.constant([[2.],[2.]]) #创建一个2*1的矩阵
product = tf.matmul(mat1, mat2) #创建op执行两个矩阵的乘法
sess = tf.Session() #启动默认图
res = sess.run(product) #在默认图中执行op操作
print(res) #输出乘积结果 [[ 12.]]
sess.close() #关闭session
'''
交互式会话（InteractiveSession）：
为了方便使用Ipython之类的Python交互环境，可以使用交互式会
话（InteractiveSession）来代替Session，使用类似Tensor.run()
和Operation.eval()来代替Session.run()，避免使用一个变量来持
有会话。
'''

sess = tf.InteractiveSession() #创建交互式会话
a = tf.Variable([1.0, 2.0]) #创建变量数组
b = tf.constant([3.0, 4.0]) #创建常量数组
sess.run(tf.global_variables_initializer()) #变量初始化
res = tf.add(a,b,name=None)
res = tf.add(a, b) #创建加法操作
print(res.eval()) #执行操作并输出结果

'''
Feed操作：
前面的例子中，数据均以变量或常量的形式进行存储。Tensorflow
还提供了Feed机制，该机制可以临时替代图中任意操作中的tensor。最
常见的用例是使用tf.placeholder()创建占位符，相当于是作为图中的
输入，然后使用Feed机制向图中占位符提供数据进行计算，具体使用方
法见接下来的样例。
'''

#http://blog.csdn.net/caicai_zju/article/details/70477929
sess = tf.InteractiveSession() #创建交互式会话
input1 = tf.placeholder(tf.float32) #创建占位符
input2 = tf.placeholder(tf.float32) #创建占位符
res = tf.multiply(input1, input2) #创建乘法操作
print(res.eval(feed_dict={input1:[7.], input2:[2.]})) #求值array([ 14.], dtype=float32)
print(res)



