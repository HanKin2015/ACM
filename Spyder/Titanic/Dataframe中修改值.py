import pandas
'''
df = pandas.DataFrame({'a': [1,2,3,4,5,6,7], 'b': [11,22,33,44,55,66,77]})
#print(df)
reduced_df = df[df['a'] > 3]
#print(reduced_df)

# 报错
#reduced_df.['a'] /= 3

# 方法一
df.loc[df['a']>3,'a'] = df['a']/3
print(df)

# 方法二
#reduced_df = df.copy()
#reduced_df['a'] /=3
#print(reduced_df)
'''







df = pandas.DataFrame({'a': [11,22,33,44,5,6,7], 'b': [11,22,33,44,55,66,77]})
#print(df)
#reduced_df = df[df['a'] > 3]
#print(reduced_df)

# 方法一
df.iloc[2]['a'] = 11
print(df)
print()

a = df.loc[df['a']==8].empty

print(a)


