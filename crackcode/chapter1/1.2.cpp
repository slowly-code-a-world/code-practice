/*
Write code to reverse a C-Style String. (C-String means that “abcd” is represented as
   five characters, including the null character.)
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


using namespace std;

class Solution {
public:
	char* reverse(char *input) {
		if ('\0' == *input) return input;
		if (1 == strlen(input)) return input;
		for (int i = 0; i < strlen(input)/2; i++) {
			char tmp = input[i];
			input[i] = input[strlen(input) - 1 - i];
			input[strlen(input) - 1 - i] = tmp;
		}
		return input;
	}	 
};


int main(void) {
	Solution S;
	
	char *r = (char*)malloc(4); // should force in C++ 
	memset(r, '\0', 4);
	r[0] = 'a'; r[1] = 'b'; r[2] = 'c';	
	printf("%s\n", S.reverse(r));
	
	return 0;
}
