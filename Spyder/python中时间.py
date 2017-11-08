# -*- coding: utf-8 -*-
"""
Created on Thu Aug 31 21:10:36 2017

@author: HanKin
"""

import datetime

def time_1():
    begin = datetime.datetime.now()
    sum = 0
    for i in range(10000000):
        sum = sum + i
    end = datetime.datetime.now()
    return end-begin

if __name__ == '__main__':
    print(time_1())
    
    import cProfile
    cProfile.run('time_1()')
    
    import timeit

    print(timeit.timeit('sum(range(100))'))
    
    import time
    print(datetime.datetime.now())
    print(time.time())
    print(time.clock())
    
    print(time.ctime())
    
    
    