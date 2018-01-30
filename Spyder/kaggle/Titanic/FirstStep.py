import numpy as np  
import pandas as pd  
import matplotlib.pyplot as plt  
  
dt_train=pd.read_csv('train.csv')  
dt_test=pd.read_csv('test.csv')  #读取csv  

print(dt_train.shape)
  
dt_train_p=dt_train.drop(['Name','Ticket','Cabin'],axis=1)  
dt_test_p=dt_test.drop(['Name','Ticket','Cabin'],axis=1)  #去除乘客姓名、船票信息和客舱编号三个不打算使用的列  

print(dt_train_p.shape)

# 这里我先进行的是舱位和性别，两者结合分析，万一那个时代地位观念比女士优先更高一级呢：
Pclass_Gender_grouped=dt_train_p.groupby(['Sex','Pclass'])  #按照性别和舱位分组聚合  
PG_Survival_Rate=(Pclass_Gender_grouped.sum()/Pclass_Gender_grouped.count())['Survived']  #计算存活率  
  
x=np.array([1,2,3])  
width=0.3 
# 这里很有意思，x-width相当于左移了 
plt.bar(x-width,PG_Survival_Rate.female,width,color='r')  
plt.bar(x,PG_Survival_Rate.male,width,color='b')  
plt.title('Survival Rate by Gender and Pclass')  
plt.xlabel('Pclass')  
plt.ylabel('Survival Rate')  
plt.xticks([1,2,3])  
plt.yticks(np.arange(0.0, 1.1, 0.1))  
plt.grid(True,linestyle='-',color='0.7')  
plt.legend(['Female','Male'])  
plt.show()  #画图  

# 然后是年龄，由于年龄数据比较散，所以要分段处理（传说中的离散化和面元划分？），我是按照每5岁一段来划分的：
age_train_p=dt_train_p[~np.isnan(dt_train_p['Age'])]  #去除年龄数据中的NaN  
ages=np.arange(0,85,5)  #0~85岁，每5岁一段（年龄最大80岁）  
age_cut=pd.cut(age_train_p.Age,ages)  
age_cut_grouped=age_train_p.groupby(age_cut)  #这个cut卡了我好久，后来才知道可以直接传给groupby  
age_Survival_Rate=(age_cut_grouped.sum()/age_cut_grouped.count())['Survived']  #计算每年龄段的存活率  
age_count=age_cut_grouped.count()['Survived']  #计算每年龄段的总人数  

ax1=age_count.plot(kind='bar')  
ax2=ax1.twinx()  #使两者共用X轴  
ax2.plot(age_Survival_Rate.values,color='r')  
ax1.set_xlabel('Age')  
ax1.set_ylabel('Number')  
ax2.set_ylabel('Survival Rate')  
plt.title('Survival Rate by Age')  
plt.grid(True,linestyle='-',color='0.7')  
plt.show()
print(dt_train_p.describe() )

# 接着是兄弟姐妹配偶（SibSP）以及父母子女（ParCh），在此我将两者数字加和，作为亲属的数据（没有什么必要分开计算吧），模式也是与上一个类似的，分组聚合，然后画图：
dt_train_p['Relatives']=dt_train_p['SibSp']+dt_train_p['Parch']  
Rela_grouped=dt_train_p.groupby(['Relatives'])  
Rela_Survival_Rate=(Rela_grouped.sum()/Rela_grouped.count())['Survived']  
Rela_count=Rela_grouped.count()['Survived']  
  
ax1=Rela_count.plot(kind='bar',color='g')  
ax2=ax1.twinx()  
ax2.plot(Rela_Survival_Rate.values,color='r')  
ax1.set_xlabel('Relatives')  
ax1.set_ylabel('Number')  
ax2.set_ylabel('Survival Rate')  
plt.title('Survival Rate by Relatives')  
plt.grid(True,linestyle='-',color='0.7')  
plt.show()  

# 最后是上船地点，照理来说这个应该对最后的生存率不影响，但结论还是略有差别，原因不太清楚：
Ebk_train_p=dt_train_p['Embarked'].dropna()  #Embarked内的内容为object类型，不能用np.isnan()  
Ebk_grouped=dt_train_p.groupby(['Embarked'])  
Ebk_Survival_Rate=(Ebk_grouped.sum()/Ebk_grouped.count())['Survived']  
  
xE=np.array([1,2,3])  
width=0.3  
plt.bar(xE,Ebk_Survival_Rate,color='r',align='center')  
plt.title('Survival Rate by Embarked')  
plt.xlabel('Embarked')  
plt.ylabel('Survival Rate')  
plt.xticks([1,2,3],['C','Q','S'])  #xticks不能直接设置字符串，只能像这样设置对应关系  
plt.yticks(np.arange(0.0, 1.1, 0.1))  
plt.grid(True,linestyle='-',color='0.7')  
plt.show()  

















