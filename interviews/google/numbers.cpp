/*
A book contains with pages numbered from 1 - N. Imagine now that you concatenate all page numbers in the book such that you obtain a sequence of numbers which can be represented as a string. You can compute number of occurences 'k' of certain digit 'd' in this string. 

For example, let N=12, d=1, hence 

s = '123456789101112' => k=5 

since digit '1' occure five times in that string. 

Problem: Write a method that, given a digit 'd' and number of its occurences 'k', returns a number of pages N. More precisely, return a lower and upper bound of this number N. 

Example: 
input: d=4, k=1; 
output {4, 13} - the book has 4-14 pages 

input d=4 k=0; 
output {1, 3} - the book has 1-3 pages
*/
