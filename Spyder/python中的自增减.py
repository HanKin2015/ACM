# -*- coding: utf-8 -*-
"""
Created on Thu Aug 31 20:28:57 2017

@author: HanKin
"""
# id函数在-5~256值中不变
a = 34
b = 34
c = 258
d = 258

print(id(a))
print(id(b))
print(id(c))
print(id(d))

print(id(34))
print(id(258))
print(id(258))
# 奇怪，在程序中是静态分配的，在命令行中则会是动态的

print(a is b)
print(c is d)