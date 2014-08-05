#include <iostream>

using namespace std;

class Base {
private:
	int private_count;
protected:
	int protected_count;
public:
	int public_count;

        int get_private_count(void) { return private_count; }
        void set_private_count(int count) { private_count = count; }
        int get_protected_count(void) { return protected_count; }
        void set_protected_count(int count) { protected_count = count; }
	int get_public_count(void) { return public_count; }
	void set_public_count(int count) { public_count = count; }
};

class Child: private Base {
public:
	void print(void) {
		/* private_count cannot be accessed as it is private */
		//cout << private_count << endl;
		cout << protected_count << endl;
		cout << public_count << endl;	
	}
};

int main(void) {

	Base myBase;
	//cout << myBase.private_count << endl;
	//cout << myBase.protected_count << endl;
	cout << myBase.public_count << endl;
	myBase.set_private_count(1);
	myBase.set_protected_count(2);
	myBase.set_public_count(3);
	
	Child myChild;

	/* protected variables become private in child */
	//cout << myChild.public_count << endl; 
	//myChild.set_public_count(4) << endl;
	//myChild.set_protected_count(5);
	//myChild.set_public_count(6);
	myChild.print();

}
