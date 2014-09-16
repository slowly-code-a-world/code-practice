/*
Why does a destructor in base class need to be declared virtual?
*/

#include <iostream>
using namespace std;
class Base {
public:
	virtual ~Base() {
		cout << "Base deconstructor" << endl;
	}	
};

class Child : public Base {
public:
	~Child() {
		cout << "child deconstructor" << endl;
	}
};

int main() {
	Base *p = new Child();
	delete p;	
}
