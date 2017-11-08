# -*- coding: utf-8 -*-
"""
Created on Sat Sep 23 15:59:13 2017

@author: HanKin
"""

import sys

print("脚本名：", sys.argv[0])
print(len(sys.argv))
for i in range(1, len(sys.argv)):
    print("参数", i, sys.argv[i])