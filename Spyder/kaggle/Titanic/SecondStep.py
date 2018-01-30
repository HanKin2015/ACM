from FirstStep import *  

dt_train_p['Relatives']=dt_train_p['SibSp']+dt_train_p['Parch']  #Relatives=SibSp+Parch，亲属人数  
dt_learn=dt_train_p.copy()  

print(dt_learn.shape)
  
sex_to_digi={'male':1,'female':0}  
ebk_to_digi={'C':-1,'Q':0,'S':1}  
  
dt_learn['Sex']=dt_learn['Sex'].map(sex_to_digi)  #将性别转化为数值  
dt_learn['Embarked']=dt_learn['Embarked'].map(ebk_to_digi)  #将上船地点转化为数值  
  
dt_learnNA=dt_learn[np.isnan(dt_learn['Age'])]  #不含Age项  
dt_learn=dt_learn.dropna()  #含Age项，与上一句顺序不要颠倒  

print(dt_learnNA.shape)
print(dt_learn.shape)
  
dt_learn_features=dt_learn[['Pclass','Sex','Age','Embarked','Relatives']]  #选取features  
dt_learnNA_features=dt_learnNA[['Pclass','Sex','Embarked','Relatives']]  #选取features  
dt_learn_target=dt_learn['Survived']  #选取target  
dt_learnNA_target=dt_learnNA['Survived']  #选取target 





from sklearn.linear_model import LogisticRegression  #导入逻辑回归模块   
from sklearn import cross_validation  #导入交叉检验  
  
classifier = LogisticRegression(C=1000)  #有Age  默认C=1
#scores=cross_validation.cross_val_score(classifier,dt_learn_features,dt_learn_target,cv=5)  #交叉检验  
#print(scores,scores.mean())  
  
classifierNA = LogisticRegression(C=1000)  #无Age  
#scoresNA=cross_validation.cross_val_score(classifierNA,dt_learnNA_features,dt_learnNA_target,cv=5)  #交叉检验  
#print(scoresNA,scoresNA.mean())

#test数据预处理  
dt_test=pd.read_csv('./testN.csv')  
dt_test['Sex']=dt_test['Sex'].map(sex_to_digi)  
dt_test['Embarked']=dt_test['Embarked'].map(ebk_to_digi)  
dt_test['Relatives']=dt_test['SibSp']+dt_test['Parch']  
dt_test['Predict']=''  #此处要先添加一列，不然后面会出错  
dt_test_features=dt_test[['Pclass','Sex','Age','Embarked','Relatives']]  
dt_test_target=dt_test['Survived']  #此为最终结果  
  
#拟合  
classifier.fit(dt_learn_features,dt_learn_target)  
classifierNA.fit(dt_learnNA_features,dt_learnNA_target)  
  
#分情况预测  
for i in range(len(dt_test)):    
    if np.isnan(dt_test['Age'][i]):  
        dt_test_features.iloc[i]=dt_test[['Pclass','Sex','Embarked','Relatives']].iloc[i]  
        dt_test['Predict'][i]=classifierNA.predict(dt_test_features.iloc[i].dropna())  
    else:  
        dt_test['Predict'][i]=classifier.predict(dt_test_features.iloc[i])  
#    print(dt_test_target[i],int(dt_test['Predict'][i]))
  
#计算正确率  
acc=1-float(sum(abs(dt_test['Predict']-dt_test_target)))/dt_test['Predict'].count()  
print(acc)


