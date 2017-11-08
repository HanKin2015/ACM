# -*- coding: utf-8 -*-
"""
Created on Tue Aug 15 14:24:30 2017

@author: HanKin
"""

import pandas as pd
from pylab import *

def main():
    #Data Structure
    s=pd.Series([i*2 for i in range(1,11)])
    print(type(s))
    dates=pd.date_range("20170301",periods=8)
    df=pd.DataFrame(np.random.randn(8,5),index=dates,columns=list("ABCDE"))
    print(df)
#    df=pd.DataFrame() #自定义每一个属性值
    
    #1---Basic
    print(df.head(3)) #前3行
    print(df.tail(3))   #后3行
    print(df.index) #索引
    print(df.values)  #     
    print(df.T)     #转置矩阵
#    最新版本的pandas，这里用print(df.sort(columns="C"))会报错，dataframe对象没有sort方法。解决办法是改成print(df.sort_values(by='C'))或者print(df.sort_values('C'))就可以了。
    print(df.sort_values(by="C"))    #以C列排序
    print(df.sort_index(axis=1,ascending=False)) #降序 
    print(df.describe())  #一些信息
    #2---Select切片
    print(df['A'])
    print(type(df['A']))
    print(df[:3])
    print(df['20170301':'20170304'])
    print(df.loc[dates[0]])
    print(df.loc["20170301":"20170304",["B","D"]])
    print(df.at[dates[0],"C"])
    #以下标筛选
    print(df.iloc[1:3,2:4])
    print(df.iloc[1,4])
    print(df.iat[1,4])
    #条件取值
    print(df[df.B>0][df.A<0])
    print(df[df>0])
    print(df[df["E"].isin([1,2])])
    
    #3---set
    s1=pd.Series(list(range(10,18)),index=pd.date_range("20170301",periods=8))
    df["F"] = s1
    print(df)
    df.at[dates[0],"A"] = 0
    print(df)
    df.iat[1,1]=1
    df.loc[:,"D"]=np.array([4]*len(df))
    print(df)
    df2=df.copy()
    df2[df2>0]=-df2
    print(df2)
    
    #4---缺失值处理Minssing Values
    df1=df.reindex(index=dates[:4],columns=list("ABCD")+["G"])
    df1.loc[dates[0]:dates[1],"G"] = 1
    print(df1)
    print(df1.dropna())  #丢弃处理
    print(df1.fillna(value=2))  #填充
    
    #5---表统计和整合Statistic
    print(df.mean())  #均值
    print(df.var())   #方差
    s = pd.Series([1,9,4,np.nan,5,7,9,10],index=dates)
    print(s)
    print(s.shift(2))  #把所有的值向下移动两个
    print(s.diff()) #当前数字减去前一个数字
    print(s.value_counts())
    print(df.apply(np.cumsum)) #看D列，累加
    print(df.apply(lambda x:x.max()-x.min()))
    
    #concat
    pieces = [df[:3],df[-3:]]  #将前三行和后三行链接在一起
    print(pd.concat(pieces))
    left=pd.DataFrame({"key":["x","y"],"value":[1,2]})
    right=pd.DataFrame({"key":["x","z"],"value":[3,4]})
    print("LEFT:",left)
    print("RIGHT:",right)
    print(pd.merge(left,right,on="key",how="left")) #看左边的
    print(pd.merge(left,right,on="key",how="inner"))#只显示共同的
    print(pd.merge(left,right,on="key",how="outer"))#输出全部，没有用NAN代替
    df3=pd.DataFrame({"A":["a","b","c","c"],"B":list(range(4))})
    print(df3.groupby("A").sum()) #A列不变，把B列对应的数字相加
    
    #透视表pivot_table
#    df4=pd.DataFrame({})

    #Time Series
    t_exam = pd.date_range("20170301",periods=10,freq="S") #S表示秒
    print(t_exam)
    
    #Graph
    ts=pd.Series(np.random.randn(1000),index=pd.date_range("20170301",periods=1000))
    ts=ts.cumsum()
#    from pylab import *
    ts.plot()
    show()
    
    #File
    df6 = pd.read_csv('./hejian.csv')
    print(df6)
    df7 = pd.read_excel('./hejian.xlsx','Sheet1')
    print(df7)
    df6.to_csv('./hejian.csv')
    df7.to_excel('./hejian.xlsx')
    
if __name__=="__main__":
    main()
    
    
    
    
    
    
    
    
    
    
    