import datetime

s = input().split()

t1 = datetime.datetime(2018, 10, 2, int(s[0]), int(s[1]))
t2 = datetime.datetime(2018, 10, 2, int(s[2]), int(s[3]))
seconds = (t2 - t1).seconds
print(seconds // 3600, seconds % 3600 // 60)