#!/usr/bin/env python

def print_line():
	print '+',
	for i in range(4):
		print '-',
	print '+',
	for i in range(4):
		print '-',
	print '+'

def print_others():
	print '|',
	for i in range(4):
		print ' ',
	print '|',
	for i in range(4):
		print ' ',
	print '|'

def draw():
	print_line()
	for i in range(4):
		print_others()
	print_line()
	for i in range(4):
		print_others()
	print_line()	
	

draw()
