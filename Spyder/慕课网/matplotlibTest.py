# -*- coding: utf-8 -*-
"""
Created on Mon Aug 14 10:48:45 2017

@author: HanKin
"""

import numpy as np
def main():
    '''
    #line
    import matplotlib.pyplot as plt
    x=np.linspace(-np.pi,np.pi,256,endpoint=True)
    c,s=np.cos(x),np.sin(x)
    plt.figure(1)
    plt.plot(x,c,color="blue",linewidth=1.0,linestyle="-",label="COS",alpha=0.5)
    plt.plot(x,s,"r*",label="SIN")  #r表示红色，用*进行绘制
    plt.title("sin&cos")
    ax=plt.gca()    #轴的编辑器
    ax.spines["right"].set_color("none")
    ax.spines["top"].set_color("none")
    ax.spines["left"].set_position(("data",0))
    ax.spines["bottom"].set_position(("data",0))

    ax.xaxis.set_ticks_position("bottom")
    ax.yaxis.set_ticks_position("left")
    
    plt.xticks([-np.pi,-np.pi/2,0,np.pi/2,np.pi],[r'$-\pi$',r'$-\pi/2$',r'$0$',r'$+\pi/2$',r'$+\pi$'])
    plt.yticks(np.linspace(-1,1,5,endpoint=True))
    for label in ax.get_xticklabels()+ax.get_yticklabels():
        label.set_fontsize(16)
        label.set_bbox(dict(facecolor="white",edgecolor="None",alpha=0.2))
    plt.legend(loc="upper left")    #图例
    plt.grid()      #网格线
    # plt.axis([-1,1,-0.5,1])  #显示范围
    plt.fill_between(x,np.abs(x)<0.5,c,c>0.2,color="green",alpha=0.25)
    t=1
    plt.plot([t,t],[0,np.cos(t)],"y",linewidth=3,linestyle="--")
    plt.annotate("cos(1)",xy=(t,np.cos(1)),xycoords="data",xytext=(+10,+30),textcoords="offset points",arrowprops=dict(arrowstyle="->",facecolor="black",connectionstyle="arc3,rad=0.2"))
    
    plt.show()
    '''
    #catter
    import matplotlib.pyplot as plt
    fig = plt.figure()
    fig.add_subplot(3,3,1) #直接的话会画在3行3列表格中
    n = 128
    X = np.random.normal(0, 1, n)
    Y = np.random.normal(0, 1, n)
    T = np.arctan2(Y, X)        #上色,Y/X
    plt.axes([0.025, 0.025, 0.95, 0.95])
    plt.scatter(X, Y, s=75, c=T, alpha=.5) #s=size,c=color
    plt.xlim(-1.5,1.5), plt.xticks([])
    plt.ylim(-1.5,1.5), plt.yticks([])
    plt.axis()
    plt.title("scatter")
    plt.xlabel("X")
    plt.ylabel("Y")
    
    #bar
    ax = fig.add_subplot(332)  #数字没有上10可以省略逗号
    n = 10
    X = np.arange(n)
    Y1 = (1 - X / float(n)) * np.random.uniform(0.5, 1.0, n)
    Y2 = (1 - X / float(n)) * np.random.uniform(0.5, 1.0, n)
    ax.bar(X, +Y1, facecolor="#9999ff", edgecolor='white')
    ax.bar(X, -Y2, facecolor="#ff9999", edgecolor='white')
    for x,y in zip(X, Y1):
        plt.text(x + 0.4, y + 0.05, '%.2f' % y, ha='center', va='bottom')
    for x,y in zip(X, Y2):
        plt.text(x + 0.4, - y - 0.05, '%.2f' % y, ha='center', va='top')
    
    #pie
    fig.add_subplot(333)  #数字没有上10可以省略逗号
    n = 20
    Z = np.ones(n)
    Z[-1] *= 2  #最后一个元素设置为2   
    plt.pie(Z, explode=Z * .05, colors=['%f' % (i/float(n)) for i in range(n)], labels=['%.2f'% (i/float(n)) for i in range(n)])
    plt.gca().set_aspect('equal')
    plt.xticks([]), plt.yticks([])
    
    #折线图
    fig.add_subplot(334)
    n = 20
    theta = np.arange(0.0, 2*np.pi, 2 * np.pi/n)
    radii = 10 * np.random.rand(n)
    plt.plot(theta, radii)
    
    #polar
    fig.add_subplot(335, polar=True)
    n = 20
    theta = np.arange(0.0, 2*np.pi, 2 * np.pi/n)
    radii = 10 * np.random.rand(n)
    plt.plot(theta, radii)
    
    #polar
    fig.add_subplot(336, polar=True)
    n = 20
    theta = np.arange(0.0, 2*np.pi, 2 * np.pi/n)
    radii = 10 * np.random.rand(n)
    plt.polar(theta, radii)
    
    #heatmap
    fig.add_subplot(337)
    from matplotlib import cm
    data = np.random.rand(3, 3)
    cmap = cm.Blues
    map = plt.imshow(data, interpolation='nearest', cmap=cmap, aspect='auto', vmin=0, vmax=1)
    
    #3D
    from mpl_toolkits.mplot3d import Axes3D
    ax = fig.add_subplot(338, projection="3d")
    ax.scatter(1,1,3,s=100)
    
    #hot map
    fig.add_subplot(313)
    def f(x,y):
        return (1-x/2+x**5+y**3) * np.exp(-x**2-y**2)
    n = 256
    x = np.linspace(-3,3,n)
    y = np.linspace(-3,3,n)
    X,Y = np.meshgrid(x,y)
    plt.contourf(X,Y,f(X,Y),8,alpha=.75,cmap=plt.cm.hot)
    
    plt.savefig("./fig.png")
    plt.show()   

if __name__=='__main__':
    main()
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    