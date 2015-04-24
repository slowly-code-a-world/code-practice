#include <iostream>
using namespace std;

class B;

class A {
public:
	A(void) {cout << "construct A" << endl;}
	A(const A& a) {cout << "copy construct A" << endl;}
	A& operator=(const A &) {cout << "copy assignment A" << endl;}
	operator B();
};

class B {
public:
	B () {}
	B (const A& a) {}	
        B(const B& b) {cout << "copy construct B" << endl;}
        B& operator=(const B &) {cout << "copy assignment B" << endl;}
	operator A() {cout << "casting to A" << endl; return A();}
};

A::operator B() {cout << "casting to B" << endl; return B();}

int main ()
{

	A foo;
  	B bar = foo;    // calls constructor
  	bar = foo;      // calls assignment
  	foo = bar;      // calls type-cast operator
	
	A ta;
	B tb(ta);
	tb = ta;
	
  	return 0;
}
