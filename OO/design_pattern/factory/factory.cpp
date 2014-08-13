#include <iostream>

using namespace std;

class Operator {
protected:
	int numA;
	int numB;
public:
	Operator(int A, int B) {numA = A; numB = B;}
	virtual int getResult() = 0;
};

class AddOperator : public Operator {
public:
        AddOperator(int A, int B): Operator(A, B) {}

	int getResult() {
		return numA + numB;
	}
};

class SubOperator : public Operator {
public:	
        SubOperator(int A, int B): Operator(A, B) {}

	int getResult() {
		return numA - numB;
	}
};

class Factory {
public:
	virtual Operator* createOp(int A, int B) = 0;
};

class AddFactory : public Factory {
public:
	Operator* createOp(int A, int B) {
		return new AddOperator(A, B);
	} 
};

class SubFactory : public Factory {
public:
	Operator* createOp(int A, int B) {
		return new SubOperator(A, B);
	}	
};

int main(void) {

	int num1, num2;
	char c;
	
	cout << "input two numbers" << endl;
	cin >> num1 >> num2;

	cout << "input operator" << endl;
	cin >> c;
	
	Factory *f = NULL;
	switch (c) {
		case '+':
			f = new AddFactory();
			break;
		case '-':
			f = new SubFactory();
			break;
		default:
			cout << "wrong" << endl;
			return 0;
	}			
	Operator *op = f->createOp(num1, num2);
	cout << op->getResult() << endl;

	return 0;
}
