import numpy as np
from sklearn.datasets import load_boston
from sklearn.datasets import load_iris
from sklearn.datasets import load_digits
import matplotlib.pyplot as plt

if __name__ == '__main__':
    # 波士顿房价数据集
    boston = load_boston()
    print(boston.data.shape)

    data, target = load_boston(return_X_y=True)
    print(data.shape)
    print(target.shape)

    # 鸢尾花数据集
    iris = load_iris()
    print(iris.data.shape)
    print(iris.target.shape)
    print(list(iris.target_names))

    # 手写数字数据集
    digits = load_digits()
    print(digits.data.shape)
    print(digits.target.shape)
    print(digits.images.shape)
    plt.matshow(digits.images[1540])
    plt.show()

