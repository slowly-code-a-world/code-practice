#!/usr/bin/python

handler = open("test2.in", "r") 
record = {}
for line in handler:
	res = line.split(',')
	if res[0] not in record:
		record[res[0]] = [set(), set()]
		record[res[0]][0].add(res[1])
		record[res[0]][1].add(res[2])	
	else:
		record[res[0]][0].add(res[1])
		record[res[0]][1].add(res[2])
		
for key in record:
	if len(record[key][0]) >= 2 and len(record[key][1]) >= 2:
		print key

handler.close()	
