#!/usr/bin/env python

class EntryExit(object):
	def __init__(self, func):
		print "calling __init__"
		self.f = func
	def __call__(self):
		print "entering " + self.f.__name__
		self.f()
		print id(self)
		print "exiting " + self.f.__name__

@EntryExit
def func1():
	print "inside func1"

@EntryExit
def func2():
	print "inside func2"

func1()
func2()
