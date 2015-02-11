/*
Design classes to represent abstract syntax tree for simple arthitmatic 
language supporting '+', '-', '*'
Operations +,-,*
Example: 1 + (2 * 3)
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Node {
public:
	bool isNumber;
	char content;
	Node* left, *right;
	Node(bool isNum, char content) {
		this->isNumber = isNumber;
		this->content = content;
	}
}
