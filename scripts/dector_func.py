#!/usr/bin/env python

def entryExit(f):
	def new_f():
		print "Entering " + f.__name__
		f()
		print "Exiting" + f.__name__
	return new_f

@entryExit
def func1():
	print "inside function 1"

@entryExit
def func2():
	print "inside function 2"

func1()
func2()
print func1.__name__
