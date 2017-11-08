# -*- coding: utf-8 -*-
"""
Created on Wed Aug 30 10:25:22 2017

@author: HanKin
"""
# 导入必要的库文件
import numpy as np   # 数组数据处理
import pandas as pd  # 文件的读取
from sklearn.model_selection import train_test_split  # 交叉验证

# 读取数据
trainSets = pd.read_csv('./train.csv', header=0) # header默认从0开始
testSets = pd.read_csv('./test.csv', header=0)
#print(type(trainSets))
#print(trainSets.shape)
#print(testSets.shape)
#print(trainSets.head(0))  # 查看DataFeame前0行
print('数据读取完成。')

'''
# 清洗数据  
#trainSets_p = trainSets.drop(['Ticket','Cabin'], axis=1)  
#testSets_p = testSets.drop(['Ticket','Cabin'], axis=1)  
#print(trainSets.shape)
#print(trainSets_p.shape) 

# 处理缺失值
trainSets_p.loc[trainSets_p['Age'].isnull(), 'Age'] = trainSets_p['Age'].median()
trainSets_p.loc[trainSets_p['Name'].isnull(), 'Name'] = trainSets_p['Name'].mode().values 
trainSets_p.loc[trainSets_p['Fare'].isnull(), 'Fare'] = trainSets_p['Fare'].mean()  
#print(trainSets_p[0:10])

# 字符转换数值化
#sex_to_digi = {'male':1,'female':0}  
#ebk_to_digi = {'C':-1,'Q':0,'S':1}  
#trainSets_p['Sex'] = trainSets_p['Sex'].map(sex_to_digi)  #将性别转化为数值  
#trainSets_p['Embarked'] = trainSets_p['Embarked'].map(ebk_to_digi)  #将上船地点转化为数值  
'''

# 归一化，为了简化运算，我们可以将其转化为二值图像，因此将所有非0的数字，即1～255都归一化为1
#trainSets[trainSets>0] = 1
#trainSets[trainSets>0] = 1

# 最终提取的数据
trainSets_labels = trainSets['label']
trainSets_p = trainSets.drop(['label'], axis=1) 
testSets_p = testSets

import matplotlib.pyplot as plt
#print(testSets_p[0:10])
#print(testSets_p[0])  # 这样会报错
#print(testSets_p.iloc[0])  # 正确的读取姿势
plt.imshow(trainSets_p.iloc[2311].reshape((28, 28)))

# runs for 10 seconds
classes = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]
num_classes = len(classes)
samples = 8

for y, cls in enumerate(classes):
    idxs = np.nonzero([i == y for i in trainSets_labels])
    idxs = np.random.choice(idxs[0], samples, replace=False)
    for i , idx in enumerate(idxs):
        plt_idx = i * num_classes + y + 1
        plt.subplot(samples, num_classes, plt_idx)
        plt.imshow(trainSets_p.iloc[idx].reshape((28, 28)))
        plt.axis("off")
        if i == 0:
            plt.title(cls)
plt.show()

'''
#trainSets_p[trainSets_p > 0] = 255
#testSets_p[testSets_p > 0] = 255
#print(type(trainSets_labels))
#print(trainSets_labels[0:10])
#print(trainSets_labels.shape)
#print(trainSets_p.shape)
#print(trainSets_p.head(2))
#print(testSets_p[0:10])
print('最终提取数据完成')

# 保存最终提取的数据
#trainSets_p.to_csv("trainSets.csv",index=False)
#testSets_p.to_csv("testSets.csv",index=False)

# 训练模型
## 使用train_test_split()函数，通过设置测试集比例test_size为0，将数据随机打乱，便于后续分类器的初始化和训练。
#x_train, x_test, y_train, y_test = train_test_split(trainSets_p, trainSets_labels, test_size = 0.2, random_state = 0)

## 导入分类器
from sklearn.neighbors import KNeighborsClassifier
from sklearn.tree import DecisionTreeClassifier
from sklearn.naive_bayes import GaussianNB
from pandas import DataFrame
from sklearn.ensemble import RandomForestClassifier  
from sklearn.linear_model import LogisticRegression  #导入逻辑回归模块 
from sklearn.neural_network import MLPClassifier 
from sklearn.svm import SVC

print('机器学习开始ing.....')
max_rate = 0
for i in range(1):
    x_train, x_test, y_train, y_test = train_test_split(trainSets_p, trainSets_labels, test_size = 0.2, random_state = 0)
    knn = KNeighborsClassifier(algorithm='kd_tree', n_neighbors=3).fit(x_train, y_train)
    tmp = np.mean(y_test == knn.predict(x_test))
    print(tmp)
    if tmp > max_rate:
        max_rate = tmp
        answer = knn.predict(testSets_p)
print(max_rate)
print(answer.shape)

sampleNum = answer.shape[0]
ImageId = []
for i in range(sampleNum):
    ImageId.append(i+1)
#ImageId = DataFrame(ImageId)
print(type(ImageId))
print(type(answer))

result_knn = DataFrame({
        'ImageId':ImageId,
        'Label':answer
        })
result_knn.to_csv("result_knn.csv",index=False)
print('机器学习完成，请查看输出文件。')
'''
#print('机器学习开始ing.....')
#max_rate = 0
#for i in range(1):
#    x_train, x_test, y_train, y_test = train_test_split(trainSets_p, trainSets_labels, test_size = 0.2, random_state = 0)
#    MLP = MLPClassifier(hidden_layer_sizes=(100,),
#                    activation='logistic', solver='adam',
#                    learning_rate_init = 0.001, max_iter=2000).fit(x_train, y_train)
#    tmp = np.mean(y_test == MLP.predict(x_test))
#    print(tmp)
#    if tmp > max_rate:
#        max_rate = tmp
#        answer = MLP.predict(testSets_p)
#print(max_rate)
#print(answer.shape)
#
#sampleNum = answer.shape[0]
#ImageId = []
#for i in range(sampleNum):
#    ImageId.append(i+1)
##ImageId = DataFrame(ImageId)
#print(type(ImageId))
#print(type(answer))
#
## 输出文件
#result_mlp = DataFrame({
#        'ImageId':ImageId,
#        'Label':answer
#        })
#result_mlp.to_csv("result_mlp.csv",index=False)
#print('机器学习完成，请查看输出文件。')





