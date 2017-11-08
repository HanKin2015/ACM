# -*- coding: utf-8 -*-
"""
Created on Thu Aug 31 19:13:05 2017

@author: HanKin
"""

#“import  thread”问题，2.x中的模块thread在3.x中编程"_thread"(需要在前面加一个下划线).否则会出现“ImportError: No module named thread

import _thread
import time
 
# 为线程定义一个函数
def print_time( threadName, delay):
   count = 0
   while count < 5:
      time.sleep(delay)
      count += 1
      print("%s: %s" % ( threadName, time.ctime(time.time()) ))
 
# 创建两个线程
try:
   _thread.start_new_thread( print_time, ("Thread-1", 2, ) )
   _thread.start_new_thread( print_time, ("Thread-2", 4, ) )
except:
   print("Error: unable to start thread")
 
while 1:
   pass






