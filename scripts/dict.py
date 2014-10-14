#!/usr/bin/env python

foo = bar = {}

foo[1] = '2'
foo[2] = '4'

for key in foo:
	print key, foo[key]

for key in bar:
	print key, bar[key]
