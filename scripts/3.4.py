#!/usr/bin/env python

def do_twice(f, arg):
	for i in range(2):
		f(arg)

def print_spam(arg):
	print str(arg)

do_twice(print_spam, 'spam')
