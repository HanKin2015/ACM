# -*- coding: utf-8 -*-
"""
Created on Mon Sep  4 17:35:09 2017

@author: HanKin
"""

"""
cnt = 0
while cnt < 9:
    print(cnt)
    cnt += 1
else:
    print(32)
    
#else:
#    print('会出错吗?')
    
print('还有这种操作?')
"""

import webbrowser as web  
import time  
import os  
  
cnt = 1  
while cnt <= 9:  
    web.open_new_tab('https://hankin2017.coding.me/')  
    cnt += 1  
    time.sleep(1)  
else:  
#    os.system('taskkill /F /IM chrome.exe') 
    print('博客点击量增加了10！')