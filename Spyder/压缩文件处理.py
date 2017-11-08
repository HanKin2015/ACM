# -*- coding: utf-8 -*-
"""
Created on Tue Sep  5 10:33:18 2017

@author: HanKin
"""
'''
import zipfile
from unrar import rarfile
 
f = open("./dict.txt", "r")
print(f.closed) #判断是否关闭
print(f.mode)
print(f.name)
print(f.encoding)
f.close()

#压缩文件
zFile = zipfile.ZipFile("./dict.zip", "w", zipfile.ZIP_DEFLATED)
zFile.write("dict.txt")
zFile.close()

#解压文件
zFile = zipfile.ZipFile("dict.zip","r")
num = len(zFile.namelist())
zFile.extractall("dict")
print(num)

#for filename in zFile.namelist():
#    data = zFile.read(filename)
#    file = open(filename, "w+b")
#    file.write(data)
#    file.close()
zFile.close()
    
#压缩文件夹
import os
f = zipfile.ZipFile('dir.zip','w',zipfile.ZIP_DEFLATED)
startdir = "./data"
for dirpath, dirnames, filenames in os.walk(startdir):
  for filename in filenames:
    f.write(os.path.join(dirpath,filename))
f.close()

#rar文件的解压，和zip类似
import os
file_name = "dict.rar"
if os.path.isfile(file_name):
    pass
else:
    os.mkdir(file_name)
    print('新建一个目录')

rFile = rarfile.RarFile(file_name,mode='r',pwd=None)
#os.chdir("dit.rar")
print(type(rFile))
print(rFile.filename)
rFile.extractall()
'''
# 文件加密解密
import base64
str1 = base64.encodebytes(bytes("hello world","utf8"))
#str2 = base64.encodestring(bytes("hello world","utf8"))
str3 = base64.decodebytes(s1)
print(str1)
#print(str2)
print(str3)

#ValueError: AES key must be either 16, 24, or 32 bytes long
#ValueError: IV must be 16 bytes long
from Crypto.Cipher import AES
obj = AES.new('This is a key123', AES.MODE_CBC, 'This is an IV456')
message = "The answer is no"
ciphertext = obj.encrypt(message)
print(ciphertext)
obj2 = AES.new('This is a key123', AES.MODE_CBC, 'This is an IV456')
data = obj2.decrypt(ciphertext)
print(data)


import zipfile
zFile = zipfile.ZipFile("./dict/hejian.zip", mode="r")
zFile.extractall(pwd = bytes("11223344", "utf8"))
zFile.close()

















