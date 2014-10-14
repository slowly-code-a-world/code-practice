#!/usr/bin/env python

def entryExit(f, a, b):
	def new_f():
		print "Entering " + f.__name__
		f(a, b)
		print "Existing " + f.__name__
	return new_f

def f(a, b):
	print "inside f()"
	print a + b

g = entryExit(f, 5, 6)
g()
