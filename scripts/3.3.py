#!/usr/bin/env python

def right_justify(string):
	if len(string) > 70:
		return string
	for i in range(70 - len(string)):
		print ' ',
	print string


right_justify('abdafdasfadsf')
