# -*- coding: utf-8 -*-
"""
Created on Wed Aug 16 16:22:03 2017

@author: HanKin
"""

from keras.models import Sequential  #sequential神经网络各个层的容器
from keras.layers import Dense, Activation #dense是加权求和的层，后者是激活函数
from keras.optimizers import SGD
from sklearn.datasets import load_iris
from sklearn.cross_validation import train_test_split
from sklearn.preprocessing import LabelBinarizer
def main():
    iris = load_iris()
    print(iris["target"])
    LabelBinarizer().fit_transform(iris["target"])  #标签化，变成二进制
    train_data, test_data, train_target, test_target = train_test_split(iris.data, iris.target, test_size=0.2, random_state=1)
    labels_train = LabelBinarizer().fit_transform(train_target)
    labels_test = LabelBinarizer().fit_transform(test_target)
    model = Sequential( #网络结构
        [
            Dense(5, input_dim=4), #第一层输出5个，输入4个
            Activation("relu"), #激活函数
            Dense(3), # label 0 1 2 输入5个，输出3个结果
            Activation("sigmoid")
        ]
    )
#    model=Sequential()
#    model.add(Dense(5,input=4))
    sgd=SGD(lr=0.01, decay=1e-6, momentum=0.9)
    model.compile(optimizer=sgd, loss="categorical_crossentropy")
    model.fit(train_data, labels_train, nb_epoch=200, batch_size=40) 
    print(model.predict_classes(test_data))
    model.save_weights('./data/w')
    model.load_weights('./data/w')
    print(test_target)
    
if __name__=="__main__" :
    main()