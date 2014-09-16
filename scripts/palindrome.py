#!/usr/bin/env python

def first(word):
	return word[0]

def last(word):
	return word[-1]

def middle(word):
	return word[1:-1]

def is_palindrome(word):
	if len(word) <= 1:
		return True
	if len(word) == 2:
		if first(word) == last(word):
			return True
		return False
	return first(word) == last(word) and is_palindrome(middle(word))
	
def is_palindrome_v2(word):
	return word[::-1] == word[::]
	 
if __name__ == '__main__':
	word = '1231'
	print is_palindrome_v2(word)
