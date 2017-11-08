'''
Created on Aug 19, 2017
kNN: k Nearest Neighbors

Input:      inX: vector to compare to existing dataset (1xN)
            dataSet: size m data set of known vectors (NxM)
            labels: data set labels (1xM vector)
            k: number of neighbors to use for comparison (should be an odd number)

Output:     the most popular class label

@author: HanKin
'''

# 导入必要模块
from numpy import *
import operator
import matplotlib.pyplot as plt
from os import listdir
from pylab import mpl

# 设置中文字体
# mpl.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['font.sans-serif']=['SimHei'] #用来正常显示中文标签
plt.rcParams['axes.unicode_minus']=False #用来正常显示负号

# 准备数据
def file2matrix(filename):
    fr = open(filename)
    arrayOLines = fr.readlines()
    print(type(arrayOLines))
    print(arrayOLines[1:10])
    numberOfLines = len(arrayOLines)         #get the number of lines in the file
    print(numberOfLines)
    returnMat = zeros((numberOfLines,3))        #prepare matrix to return
    classLabelVector = []                       #prepare labels return
    fr = open(filename)
    index = 0
    for line in fr.readlines():
        line = line.strip() #移除头尾的指定符（回车字符），默认空格
        listFromLine = line.split('\t')  #以行进行读取，以\t进行分割
        returnMat[index,:] = listFromLine[0:3]
        classLabelVector.append(int(listFromLine[-1]))
        index += 1
    return returnMat,classLabelVector

'''
数据解释：
类别：不喜欢的人；魅力一般的人；极具魅力的人。
属性：每年获得的飞行常客里程数
      玩视频游戏所耗时间百分比
      每周消费的冰淇淋公升数
'''

# 分析可视化数据
def scatter(data, datingLabels):
    fig = plt.figure()
    ax = fig.add_subplot(111)
    # ax.scatter(data[:,1], data[:,2], s=20, c='r', marker='x')
    ax.scatter(data[:, 1], data[:, 2], s = 15.0 * array(datingLabels), c = 15.0 * array(datingLabels), label = datingLabels)
    ax.set_title('scatter')
    plt.xlabel(u'玩视频游戏所消耗时间百分比')
    plt.ylabel(r'每周消费的冰淇淋公升数')
    plt.grid(True)
    plt.legend('uppter right')
    plt.show()

# 归一化数据
def autoNorm(dataSet):
    minVals = dataSet.min(0)    #0代表按列进行计算最小，省略了参数axis，axes坐标轴
    maxVals = dataSet.max(0)
    print(minVals)
    ranges = maxVals - minVals
    normDataSet = zeros(shape(dataSet))
    print(shape(dataSet))
    m = dataSet.shape[0]
    print(m)
    normDataSet = dataSet - tile(minVals, (m,1))
    normDataSet = normDataSet/tile(ranges, (m,1))   #element wise divide
    return normDataSet, ranges, minVals

# 处理数据分类
def classify0(inX, dataSet, labels, k):
    dataSetSize = dataSet.shape[0]
    diffMat = tile(inX, (dataSetSize, 1)) - dataSet
    sqDiffMat = diffMat ** 2
    sqDistances = sqDiffMat.sum(axis=1)
    distances = sqDistances ** 0.5
    sortedDistIndicies = distances.argsort()
    classCount = {}
    for i in range(k):
        voteIlabel = labels[sortedDistIndicies[i]]
        classCount[voteIlabel] = classCount.get(voteIlabel, 0) + 1 #统计同一个类别的数量
    sortedClassCount = sorted(classCount.items(), key=operator.itemgetter(1), reverse=True)
    # ascending/descending order  顺序有reverse决定
    return sortedClassCount[0][0]

# 测试算法，错误率
def datingClassTest():
    hoRatio = 0.10      #hold out 10%
    datingDataMat,datingLabels = file2matrix('datingTestSet2.txt')       #load data setfrom file
    normMat, ranges, minVals = autoNorm(datingDataMat)
    m = normMat.shape[0]
    numTestVecs = int(m*hoRatio)
    print(numTestVecs)
    errorCount = 0.0
    for i in range(numTestVecs):
        # 以前100个数据进行测试样本，后面900为训练数据，以3个为一组
        classifierResult = classify0(normMat[i,:],normMat[numTestVecs:m,:],datingLabels[numTestVecs:m],3)
        print("the classifier came back with: %d, the real answer is: %d" % (classifierResult, datingLabels[i]))
        if (classifierResult != datingLabels[i]): errorCount += 1.0
    print("the total error rate is: %f" % (errorCount/float(numTestVecs)))
    print(errorCount)

def classifyPerson():
    resultList = ['not at all','in small does','in large doses']
    percentTats = float(input("percentage of time spent playing video games?"))
    ffMiles = float(input("percentage of time spent playing video games?"))
    iceCream = float(input("percentage of time spent playing video games?"))
    datingDataMat, datingLabels = file2matrix('datingTestSet2.txt')
    normDataSet, ranges, minVals = autoNorm(datingDataMat)
    inArr = array([ffMiles,percentTats,iceCream])
    classifierResult = classify0((inArr-minVals)/ranges,normDataSet,datingLabels,3)
    print("you will probaly like this person:",resultList[classifierResult-1])

if __name__=='__main__':
    datingDataMat, datingLabels = file2matrix('./datingTestSet2.txt')
    print(datingDataMat[0:3])
    print(datingLabels[0:20])
    scatter(datingDataMat, datingLabels)
    normDataSet, ranges, minVals = autoNorm(datingDataMat)
    datingClassTest()
    classifyPerson()




