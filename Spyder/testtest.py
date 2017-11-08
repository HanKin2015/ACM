# -*- coding: utf-8 -*-
"""
Created on Sat Sep 16 19:32:56 2017

@author: HanKin
"""

import networkx as nx
import pylab 
import numpy as np
import pandas as pd
#自定义网络
row=np.array([1,1,1,2,2,3,3,4,5,2])
col=np.array([2,3,6,3,4,4,6,5,6,4])
value=np.array([7,9,14,10,15,11,2,6,9,4])

print('生成一个空的无向图')
G=nx.Graph()
print('为这个网络添加节点...')
for i in range(1,7):
    G.add_node(i)
print('在网络中添加带权中的边...')
for i in range(np.size(row)):
    G.add_weighted_edges_from([(row[i],col[i],value[i])])

print('给网路设置布局...')
pos=nx.shell_layout(G)
print('画出网络图像：')
nx.draw(G,pos,with_labels=True, node_color='white', edge_color='red', node_size=400, alpha=0.5 )
pylab.title('Self_Define Net',fontsize=15)
pylab.show()

'''
Shortest Path with dijkstra_path
'''
print('dijkstra方法寻找最短路径：')
path=nx.dijkstra_path(G, source=1, target=5)
print('节点1到5的路径：', path)
print('dijkstra方法寻找最短距离：')
distance=nx.dijkstra_path_length(G, source=1, target=5)
print('节点1到5的距离为：', distance)

df = pd.DataFrame({"df":row})
print(type(df))
print(df.shape)
print(df)

arr = [2,3,4,1,2,3]
arr.sort()                        #把列表永久性的排序
print(arr)
brr = [2,3,4,1,2,3]
print(sorted(brr))                #对列表进行临时性的排序
print(brr)






