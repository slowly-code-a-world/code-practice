class NoOrderOfOperations:
	def parse(self, expr, start):
		ret = 0 
		index = start
		while index < len(expr):
			if expr[index]>='0' and expr[index]<='9':
				ret = 10*ret + int(expr[index])
				index += 1
			else:
				return ret, index
		return ret, len(expr)				
		
	def evaluate(self, expr):
		value, pos = self.parse(expr, 0)
		print value, pos
		if pos == len(expr):
			return value
		while pos != len(expr):	
			if expr[pos] == "+":
				second, pos = self.parse(expr, pos+1)
				value = value + second
			elif expr[pos] == "-":
				second, pos = self.parse(expr, pos+1)
				value = value - second
			elif expr[pos] == "*":
				second, pos = self.parse(expr, pos+1)
				value = value * second
			else:
				second, pos = self.parse(expr, pos+1)
				value = value / second			
		return value	
