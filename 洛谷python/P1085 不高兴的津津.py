https://www.luogu.org/problemnew/solution/P1085?page=2
ans = 0
maxValue = 0
for i in range(7):
	a, b = map(int, input().split())
	if (a + b > 8 and a + b > maxValue):
		maxValue = a + b
		ans = i + 1
print(ans)

##  一行流
print(max(__import__('itertools').chain(((i, sum(map(int, input().split(' ')))) for i in range(1, 8)), ((0, 9), )), key=lambda x:x[1])[0])