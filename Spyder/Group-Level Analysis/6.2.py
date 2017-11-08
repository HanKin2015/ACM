# -*- coding: utf-8 -*-
"""
Created on Tue Oct 10 16:47:39 2017

@author: HanKin
"""

import networkx as nx
import matplotlib.pyplot as plt

fb = nx.read_edgelist("facebook/facebook_combined_minimized.txt", create_using=nx.Graph(), nodetype=int)
print(nx.info(fb))  # the information about this graph

cliques = [x for x in nx.find_cliques(fb)]

# draw the network
#pos = nx.spring_layout(fb)
#plt.figure(figsize = (12,12))
#plt.axis('off')
#nx.draw_networkx(fb, pos=pos, with_labels=False, node_size=80)

g = nx.krackhardt_kite_graph()
nx.clustering(g)

g = nx.davis_southern_women_graph()
g.nodes()

#import warnings
#import networkx.drawing.nx_pylab
#warnings.filterwarnings("ignore",category=networkx.drawing.nx_pylab.draw)

#import warnings
#
#def fxn():
#    warnings.warn("deprecated", DeprecationWarning)
#
#with warnings.catch_warnings():
#    warnings.simplefilter("ignore")
#    fxn()
    
#import warnings
#warnings.filterwarnings("ignore")

plt.figure(figsize=(10, 10))
pos = nx.random_layout(g)
nx.draw(g, node_size = 90, node_color='cyan', with_labels=False, hold=True)

