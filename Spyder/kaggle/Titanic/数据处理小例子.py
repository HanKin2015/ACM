import pandas as pd  
import csv  
from sklearn.ensemble import RandomForestClassifier  
from sklearn.cross_validation import cross_val_score  
from sklearn.grid_search import GridSearchCV, RandomizedSearchCV  
   
# read in the training and testing data into Pandas.DataFrame objects  
input_df = pd.read_csv('train.csv', header=0)  
submit_df  = pd.read_csv('test.csv',  header=0)  
  
# merge the two DataFrames into one  
df = pd.concat([input_df, submit_df])  
df = df .reset_index()  
df = df.drop('index', axis=1)  
df = df.reindex_axis(input_df.columns, axis=1)  
  
#print df.info()  
#print df.describe()  
  
""" cope with the missing data """  
  
# 1.'Cabin', seems useless, too much missing, two ways to handle it  
# (1) drop this feature  
df = df.drop('Cabin', axis=1)  
# (2) assign a value represent it's missing  
#df[df['Cabin'].isnull()] = 'missing'  
  
# 2. 'Age', a important feature, we can't just drop it, two ways to handle it  
# (1) fill it with median  
df['Age'][df['Age'].isnull()] = df['Age'].median()  
# (2) use a simple model to predict it, after everything else is fixed.In this case,  
#  the accuracy of the experiment consequence is too low,so we give up this method.  
  
# 3. 'Fare', only one miss, just use the median  
df['Fare'][df['Fare'].isnull()] = df['Fare'].median()  
  
# 4.'Embarked', two  miss, use the most frequency word  
df['Embarked'][df['Embarked'].isnull()] = df['Embarked'].mode().values  
  
  
""" feature engineering """  
  
# 1. 'Sex', factorizing it  
df['Sex'] = pd.factorize(df['Sex'])[0]  
  
# 2. 'Name', we can drag some title from the name, for simplicity, I just drop it   
df = df.drop('Name', axis=1)  
  
# 3. 'Ticket', for simlicity, just drop it  
df = df.drop('Ticket', axis=1)  
  
# 4. 'Embarked', factorizing it    
df['Embarked'] = pd.factorize(df['Embarked'])[0]  
  
# 5. 'SibSp', 'Parch', combine them to get a new feature, 'Famliy_size'  
df['Family_size'] = df['SibSp']+df['Parch']  
  
  
""" train the model """  
  
df = df.drop(['PassengerId', 'SibSp', 'Parch'], axis=1)  
known_survived = df[df['Survived'].notnull()].values  
unknown_survived = df[df['Survived'].isnull()].values  
  
Y = known_survived[:, 0]  
X = known_survived[:, 1:]  
  
clf = RandomForestClassifier(n_estimators=1000, random_state=312, min_samples_leaf=3).fit(X, Y)  
#print cross_val_score(clf, X, Y).mean()  
#print df.columns  
#print  clf.feature_importances_  
  
  
""" predict and write to csv file """  
  
pred = clf.predict(unknown_survived[:, 1:]).astype(int)  
ids = submit_df['PassengerId']  
  
predictions_file = open("myfirstsubmission.csv", "wb")  
open_file_object = csv.writer(predictions_file)  
open_file_object.writerow(["PassengerId","Survived"])  
open_file_object.writerows(zip(ids, pred))  
predictions_file.close()  
  
print('done.')