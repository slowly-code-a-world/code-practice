#!/usr/bin/env python

class myDecorator(object):
	def __init__(self, func):
		print "inside myDecorator.__init__()"
		func()
	def __call__(self):
		print "inside myDecorator.__call__()"

@myDecorator
def aFunction():
	print "inside aFunction()"

print "Finished decorating aFunction()"
aFunction()
