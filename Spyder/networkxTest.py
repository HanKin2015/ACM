# -*- coding: utf-8 -*-
"""
Created on Sat Sep 16 19:27:37 2017

@author: HanKin
"""

import networkx as nx
import pylab 
import numpy as np
#自定义网络
row=np.array([0,0,0,1,2,3,6])
col=np.array([1,2,3,4,5,6,7])
value=np.array([1,2,1,8,1,3,5])

print('生成一个空的有向图')
G=nx.DiGraph()
print('为这个网络添加节点...')
for i in range(0,np.size(col)+1):
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
path=nx.dijkstra_path(G, source=0, target=7)
print('节点0到7的路径：', path)
print('dijkstra方法寻找最短距离：')
distance=nx.dijkstra_path_length(G, source=0, target=7)
print('节点0到7的距离为：', distance)





