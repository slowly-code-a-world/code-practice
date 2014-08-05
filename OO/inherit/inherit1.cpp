#include <iostream>
#include <vector>

using namespace std;

class Base {
public:
	int a;
	Base() {
		cout << "construct Base" << endl;
	}
	~Base() {
		cout << "deconstruct Base" << endl;
	}
	int geta(void) { return a; }
};

class P1: public virtual Base {
public:
	P1() {
		cout << "construct P1" << endl;
	}
	~P1() {
		cout << "deconstruct P1" << endl;
	}
};

class P2: public Base {
public:
	P2() {
		cout << "construct P2" << endl;
	}
	~P2() {
		cout << "deconstruct P2" << endl;
	}
};

class Child: public P1, public P2 {
public:
	Child() {
		cout << "construct Child" << endl;
	}
	~Child() {
		cout << "deconstruct Child" << endl;
	}
};

int main(void) {

	Child c;
	c.P1::geta(); 

	return 0;	
}
