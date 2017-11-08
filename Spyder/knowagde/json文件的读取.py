# -*- coding: utf-8 -*-
"""
Created on Mon Aug 14 19:53:47 2017

@author: HanKin
"""

import json
import re
from collections import defaultdict

def get_counts(sequence):
    counts =defaultdict(int)  #所有的值均会初始化为0
    for x in sequence:
        counts[x] +=1
    return counts

if __name__=='__main__':
#    path = "C:\\Users\\Administrator\\Desktop\\hejian.txt"
#    path = r"C:\Users\Administrator\Desktop\json.txt"
    path = './jsondata.json'
    '''
    content = open(path,'r',encoding= 'utf-8').readline()
    print(content)
    
    text = open(path,'r',encoding= 'utf-8') 
    print(text.readline())
    for con in text:
        print(con)
    '''    

    con = open(path,'r',encoding='utf-8')
#    print(con)
#    data = con.replace('\n', "\\n").replace("\'", "\\'").replace('\"', "\\\"").replace('\&', "\\&").replace('\r', "\\r").replace('\t', "\\t").replace('\b', "\\b") .replace('\f', "\\f")
#    print(data)
#    data = con.read()
#    print(data)
#    setting = json.load(con)
#    print(setting)
#    records = [json.loads(line) for line in con]
#    print(records[0])
#    print(records[0])


#    path = './usagov_bitly_data2012-03-16-1331923249.txt'
#    con = open(path).readline()
#    print(con)
    
#----------分界线-----------
#    import json
    records = [json.loads(line) for line in open(path)]
#    print(records[0])
    time_zones = [rec['tz'] for rec in records if 'tz' in rec]
    print(time_zones[:10])
    
    counts = get_counts(time_zones)
    print(len(time_zones))
    print(counts['America/New_York'])
    
    from collections import Counter
    counts = Counter(time_zones)
    print(counts.most_common(10))
    
    from pandas import DataFrame, Series
    import pandas as pd
    import numpy as np
    frame = DataFrame(records)
#    print(frame)
    
    tz_counts = frame['tz'].value_counts()
    print(tz_counts[:10])
    
    clean_tz = frame['tz'].fillna('Missing')
    clean_tz[clean_tz == ''] = 'Unknow'
    tz_counts = clean_tz.value_counts()
    print('\n')
    print(tz_counts[:10])
    tz_counts[:10].plot(kind='barh', rot=0)
    print(frame['a'][1])  #浏览器、设备应用程序
    print(frame['a'][50])
    print(frame['a'][51])
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    