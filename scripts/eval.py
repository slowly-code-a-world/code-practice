#!/usr/bin/env python

def eval_loop():
	while True:
		string = raw_input('input expression\n');
		print eval(string)

if __name__ == '__main__':
	eval_loop()	
