#作者：SunnyMarkLiu
#链接：https://www.zhihu.com/question/37146648/answer/80425957
#来源：知乎
#著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

#!/usr/bin/python2.7
# _*_ coding: utf-8 _*_

from matplotlib import pyplot as plt
from matplotlib import font_manager

# 准备数据
def file2matrix(filename):
    fr = open(filename)
    arrayOLines = fr.readlines()
#    print(type(arrayOLines))
#    print(arrayOLines[1:10])
    numberOfLines = len(arrayOLines)         #get the number of lines in the file
#    print(numberOfLines)
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

matrix, labels = file2matrix('datingTestSet2.txt')
#print(matrix)
#print(labels)
#zhfont = matplotlib.font_manager.FontProperties(fname='/usr/share/fonts/truetype/arphic/ukai.ttc')

""" 比较好看的绘制方法 """

plt.figure(figsize=(8, 5), dpi=80)
axes = plt.subplot(111)
# 将三类数据分别取出来
# x轴代表飞行的里程数
# y轴代表玩视频游戏的百分比
type1_x = []
type1_y = []
type2_x = []
type2_y = []
type3_x = []
type3_y = []
#print('range(len(labels)):')
#print(range(len(labels)))
for i in range(len(labels)):
    if labels[i] == 1:  # 不喜欢
        type1_x.append(matrix[i][0])
        type1_y.append(matrix[i][1])

    if labels[i] == 2:  # 魅力一般
        type2_x.append(matrix[i][0])
        type2_y.append(matrix[i][1])

    if labels[i] == 3:  # 极具魅力
#        print(i, '：', labels[i], ':', type(labels[i]))
        type3_x.append(matrix[i][0])
        type3_y.append(matrix[i][1])

type1 = axes.scatter(type1_x, type1_y, s=20, c='red')
type2 = axes.scatter(type2_x, type2_y, s=40, c='green')
type3 = axes.scatter(type3_x, type3_y, s=50, c='blue')
# plt.scatter(matrix[:, 0], matrix[:, 1], s=20 * numpy.array(labels),
#             c=50 * numpy.array(labels), marker='o',
#             label='test')
plt.xlabel(u'每年获取的飞行里程数')
plt.ylabel(u'玩视频游戏所消耗的事件百分比')
axes.legend((type1, type2, type3), (u'不喜欢', u'魅力一般', u'极具魅力'), loc=2)
#axes.legend((type1, type2, type3), (u'不喜欢', u'魅力一般', u'极具魅力'), loc=2, prop=zhfont)

plt.show()