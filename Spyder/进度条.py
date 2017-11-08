# -*- coding: utf-8 -*-
"""
Created on Wed Aug 30 16:24:17 2017

@author: HanKin
"""

'''
import time

for i in range(11):
    string = 'loading... ' + str(i) + '%'
    print(string, end='')    # 不换行
    print('\b' * len(string), end='', flush=False)    # 删除前面打印的字符
    time.sleep(0.2)

N = 1000
for i in range(N):
    print("进度:{0}%".format(round((i + 1) * 100 / N)), end="\r")
    time.sleep(0.1)
'''
    
#import time
#N = 1000
#st = time.clock()
#for i in range(N):
#    p = round((i + 1) * 100 / N)
#    duration = round(time.clock() - st, 2)
#    remaining = round(duration * 100 / (0.01 + p) - duration, 2)
#    print("进度:{0}%，已耗时:{1}s，预计剩余时间:{2}s".format(p, duration, remaining), end="\r")
#    time.sleep(0.01)
'''
import sys
from time import sleep
def viewBar(i):
    """
    进度条效果
    :param i:
    :return:
    """
    output = sys.stdout
    for count in range(0, i + 1):
        second = 0.1
        sleep(second)
        output.write('\rcomplete percent ----->:%.0f%%' % count)
    output.flush()
 
viewBar(100)

import sys
import time
def view_bar(num,total):
    rate = num / total
    rate_num = int(rate * 100)
    #r = '\r %d%%' %(rate_num)
    r = '\r%s>%d%%' % ('=' * rate_num, rate_num,)
    sys.stdout.write(r)
    sys.stdout.flush
if __name__ == '__main__':
    for i in range(0, 101):
        time.sleep(0.1)
        view_bar(i, 100)
'''       
        
import sys
from time import sleep
def viewBar(i):
    for count in range(0, i + 1):
        sleep(1)
        sys.stdout.write('\rcomplete percent ----->:%.0f %%' % count)
#        sys.stdout.write('\rcomplete percent ----->:%.0f%%' % count)
    sys.stdout.flush()
 
viewBar(60)        
        
        
        
        
        