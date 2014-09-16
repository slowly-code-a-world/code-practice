#!/usr/bin/env python

def is_power(a, b):
	if b == 1:
		if a == 1: return True
		return False

	if a % b != 0 return False
	return is_power(a/b, b)

def GCD(a, b):
	if b == 0: return a
	r = a % b
	return GCD(b, r)
