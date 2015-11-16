class BettingMoney:
	def moneyMade(self, amounts, centsPerDollar, finalResult):
		if len(amounts) == 1:
			return -amounts[0]*centsPerDollar[0]
		sum = 0	
		for index in range(len(amounts)):
			if index == finalResult:
				continue
			sum += amounts[index]
		sum = sum* 100
		return sum - amounts[finalResult]*centsPerDollar[finalResult]			
