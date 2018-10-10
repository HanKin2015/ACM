https://www.luogu.org/problemnew/solution/P1909?page=2
import math

ans = 1e9
n = int(input())
for i in range(3):
	num, price = map(int, input().split())
	tmp = math.ceil(n / num) * price
	if tmp < ans:
		ans = tmp
print(ans)



from math import ceil
n = int(input())
l = (tuple(map(int, input().split())) for i in range(3))
r = min(ceil(n/number)*price for number, price in l)
print(r)