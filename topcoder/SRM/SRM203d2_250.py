__author__ = 'yan.cui'

class UserName:
	def parse(self, name):
		base, number = "", ""
		parseNumber = True
		for index in range(len(name)):
			if name[len(name) - index - 1] >= '0' and name[len(name) - index - 1] <= '9' and parseNumber:
				number = name[len(name) - index - 1] + number
			else:
				base = name[len(name) - index - 1] + base
				parseNumber = False if parseNumber else False
		if number == "":
			number = 0
		return base, int(number)

	def newMember(self, existingNames, newName):
		if newName not in existingNames:
			return newName
		base, number = self.parse(newName)
		if base not in existingNames:
			return base
		for index in range(50):
			if index == number:
				continue
			newName = base + str(index)
			if newName not in existingNames:
				return newName
		print "cannot be here"
		return "none"

if __name__ == "__main__":
    existingNames = ("MasterOfDisaster", "TygerTyger1", "DingBat", "Orpheus", "TygerTyger", "WolfMan", "MrKnowItAll")
    newName = "TygerTyger"
    test = UserName()
    print test.newMember(existingNames, newName)
