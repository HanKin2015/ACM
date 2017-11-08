import numpy as np
import matplotlib.pyplot as plt

if __name__ == '__main__':
    # for i in range(10):
    #     print(i)
    # print(i)   # i值还是存在的
    #
    # plt.title("I'm a scatter diagram.")
    # plt.xlim(xmax=7, xmin=0)
    # plt.ylim(ymax=7, ymin=0)
    # # 第一个参数是批注内容，xy是批注点，xytext是批注写在的位置
    # plt.annotate("(3,6)", xy=(3, 6), xytext=(4, 5), arrowprops=dict(facecolor='black', shrink=0.1))
    # plt.xlabel("x")
    # plt.ylabel("y")
    # plt.plot([1, 2, 3], [4, 5, 6], 'ro')
    # plt.show()

    points = np.array([[1,2],[3,4],[1,5],[5,3]])
    print(points.shape)
    fig = plt.figure()
    ax = fig.add_subplot(111)
    a = 9; b = 4
    # ax.annotate("(%d,%d)"%(a,b), xy=(3, 4), xytext=(3, 4))
    for i in range(4):
        ax.annotate("(%d,%d)"%(points[i,0],points[i,1]),xy=(points[i,0],points[i,1]), xytext=(points[i,0],points[i,1]))
    ax.scatter(points[:,0],points[:,1])
    plt.xlabel("x")
    plt.ylabel("y")
    plt.show()

    # N = 50  # 点的个数
    # x = np.random.rand(N) * 2  # 随机产生50个0~2之间的x坐标
    # y = np.random.rand(N) * 2  # 随机产生50个0~2之间的y坐标
    # colors = np.random.rand(N)  # 随机产生50个0~1之间的颜色值
    # area = np.pi * (15 * np.random.rand(N)) ** 2  # 点的半径范围:0~15
    # # 画散点图
    # plt.scatter(x, y, s=area, c=colors, alpha=0.5, marker=(9, 3, 30))
    # plt.show()

