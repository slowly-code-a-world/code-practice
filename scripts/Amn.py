#!/usr/bin/env python

def A(m, n, record):
	if m == 0:
		return n + 1
		
	if (m, n) in record:
		return record[(m, n)]

	if m > 0 and n == 0:
		record[(m, n)] = A(m-1, 1, record)	
		return record[(m, n)]

	if m > 0 and n > 0:
		record[(m, n)] = A(m-1, A(m, n-1, record), record)
		return record[(m, n)]

if __name__ == '__main__':
	record = {}
	print A(3, 4, record)
