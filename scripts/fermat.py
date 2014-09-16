#!/usr/bin/env python

def check_fermat(a, b, c, n):
	if n <= 2:
		print 'n should be larger than 2'
		return
	
	assert isinstance(a, int) and isinstance(b, int) and isinstance(c, int)
	if a**n + b**n != c**n:
		print 'No, that doesn\'t work'
		return

	print 'Holy smokes, Fermat was wrong!'
	return

if __name__ == '__main__':
	a = int(raw_input('input a\n'))
   	b = int(raw_input('input b\n'))	
        c = int(raw_input('input c\n'))
	n = int(raw_input('input n\n'))

	check_fermat(a, b, c, n)
