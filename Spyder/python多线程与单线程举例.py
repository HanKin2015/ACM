# -*- coding: utf-8 -*-
"""
Created on Thu Aug 31 20:14:08 2017

@author: HanKin
"""

import threading
import time
import datetime
 
exitFlag = 0
 
class myThread (threading.Thread):   #继承父类threading.Thread
    def __init__(self, threadID, name, counter):
        threading.Thread.__init__(self)
        self.threadID = threadID
        self.name = name
        self.counter = counter
    def run(self):                   #把要执行的代码写到run函数里面 线程在创建后会直接运行run函数 
        print("Starting " + self.name)
        cal()
        print("Exiting " + self.name)
 
def cal():
    ans = 0
    for i in range(100000000):
        ans += 1
   
    print(ans)
    

if __name__ == '__main__':
    s1 = datetime.datetime.now()
    # 创建新线程
    thread1 = myThread(1, "Thread-1", 1)
    thread2 = myThread(2, "Thread-2", 2)
     
    # 开启线程
    thread1.start()
    thread2.start()
#    e1 = datetime.datetime.now()
#    print()
#    print(e1 - s1)
#    print()
#    
#    s2 = datetime.datetime.now()
#    cal()
#    print('i have cal two')
#    cal()
#    e2 = datetime.datetime.now()
#    print()
#    print(e2-s2)
#    print()
    
    print("Exiting Main Thread")
    print(e2 - s1)
    # 多线程建立线程，线程会在后面默默的计算运行，同时你的main函数中的其他函数会继续运行下去，是一个显示的线程
