#!/usr/bin/env python

def is_triangle(a, b, c):
	assert isinstance(a, int) and isinstance(b, int) and isinstance(c, int)
	list = []
	list.append(a)
	list.append(b)
	list.append(c)
	list.sort()
	print list
	return list[0] + list[1] > list[2] 

if __name__ == '__main__':
	print is_triangle(3, 4, 5)
	print is_triangle(3, 3, 0)
