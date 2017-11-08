    # -*- coding: utf-8 -*-
    """
    Created on Mon Aug 14 19:53:47 2017

    @author: HanKin
    """

    import json
    import re

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
    #    data = con.replace('\n', "\\n").replace("\'", "\\'").replace('\"', "\\\"").replace('\&',
         "\\&").replace('\r',"\\r").replace('\t', "\\t").replace('\b', "\\b") .replace('\f', "\\f")
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
        
    #    import json
        records = [json.loads(line) for line in open(path)]
        print(records[0])
---
废话不多说。直接上代码。  
+ 首先，json解析时有中文时，需要加入encoding
+ json.load和jsons的区别
+ open语句单独写出来和写在一起有区别
+ json文件内容有换行符需要特别注意，一般一行由大括号包围起来
+ 20170815