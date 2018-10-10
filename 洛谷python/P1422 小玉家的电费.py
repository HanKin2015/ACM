n = input()
n = int(n)

if n <= 150:
	ans = n * 0.4463
elif n <= 400:
	ans = 150 * 0.4463 + (n - 150) * 0.4663
else:
	ans = 150 * 0.4463 + 250 * 0.4663 + (n - 400) * 0.5663

print(round(ans, 1))