#!/usr/bin/python 

handler = open("test.in", "r")
resSet = set()
for line in handler:
	res = line.split(',')
	resSet.add(res[2])
handler.close()
print resSet
