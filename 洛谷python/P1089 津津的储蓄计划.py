handSum = 0
momSum = 0
flag = True
for i in range(1, 13):
	n = int(input())
	handSum += 300 - n
	if handSum < 0 and flag:
		print(-i)
		flag = False
	while handSum >= 100:
		handSum -= 100
		momSum += 100
if flag:
	print(int(momSum * 1.2 + handSum))