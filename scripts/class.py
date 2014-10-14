#!/usr/bin/env python

class TestClass(object):
	def __init__(self):
		print "at __init__ function"
	def __call__(self):
		print "at __call__ function"

print "before creating an object"
a = TestClass()
print "after creating an object"
