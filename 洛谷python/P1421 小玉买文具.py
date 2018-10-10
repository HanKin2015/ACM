if __name__ == '__main__':
	s = input().split()
	money = int(s[0]) * 10 + int(s[1])
	print(int(money / 19))
	print(money // 19)