# -*- coding: utf-8 -*-
"""
Created on Fri Aug 11 19:36:18 2017

@author: HanKin
"""

import urllib
import os
import time
import Image
import win32api,win32con,win32gui
import re

def getPicFromBing():
    url='http://cn.bing.com'
    urlFile=urllib.urlopen(url)
    data=urlFile.read()
    urlFile.close()
    data=data.decode('utf-8')
    #找出下载地址imgURL
    pre = 'g_img={url:\''
    index1 = data.find(pre) + len(pre)
    index2 = data.find('\'', index1)
    imgUrl = data[index1 : index2]
    print(imgUrl)
    #声明下载存储路径imgName
    imgName=time.strftime('%Y-%m-%d',time.localtime(time.time()))+u'.jpg'
    urllib.urlretrieve(imgUrl,imgName)
    print('Download complete')
    return(imgName)

def set_wallpaper_from_bmp(bmp_path):
    #打开指定注册表路径
    reg_key = win32api.RegOpenKeyEx(win32con.HKEY_CURRENT_USER,"Control Panel\\Desktop",0,win32con.KEY_SET_VALUE)
    #最后的参数:2拉伸,0居中,6适应,10填充,0平铺
    win32api.RegSetValueEx(reg_key, "WallpaperStyle", 0, win32con.REG_SZ, "2")
    #最后的参数:1表示平铺,拉伸居中等都是0
    win32api.RegSetValueEx(reg_key, "TileWallpaper", 0, win32con.REG_SZ, "0")
    #刷新桌面
    win32gui.SystemParametersInfo(win32con.SPI_SETDESKWALLPAPER,bmp_path, win32con.SPIF_SENDWININICHANGE)

def set_wallpaper(img_path):
    #把图片格式统一转换成bmp格式,并放在源图片的同一目录
    img_dir = os.path.dirname(img_path)
    bmpImage = Image.open(img_path)
    new_bmp_path = os.path.join(img_dir,'wallpaper.bmp')
    bmpImage.save(new_bmp_path, "BMP")
    set_wallpaper_from_bmp(new_bmp_path)

if __name__ == '__main__':
    img_path=getPicFromBing();
    set_wallpaper(img_path);
       

