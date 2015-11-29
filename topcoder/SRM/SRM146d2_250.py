class YahtzeeScore:
	def maxPoints(self, toss):
		hashTable = {1:0, 2:0, 3:0, 4:0, 5:0, 6:0}
		for elem in toss:
			hashTable[elem] += elem
		ret = 0
		for elem in range(6):
			ret = max(ret, hashTable[elem+1])
		return ret	
