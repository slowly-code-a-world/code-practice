#include <iostream>
using namespace std;

class Operation {
private:
	double _numberA;
	double _numberB;
	
public:
	double getNumberA(void) {
		return _numberA;
	}
	void setNumberA(double A) {
		_numberA = A;
	}
	double getNumberB(void) {
		return _numberB;
	}
	void setNumberB(double B) {
		_numberB = B;
	}
	virtual double GetResult() {
		return 0;
	}
};

class OperationAdd: public Operation {
public:
	double GetResult() {
		double result = 0;
		result = getNumberA() + getNumberB();
		return result;
	}
};

class OperationSub: public Operation {
public:
	double GetResult() {
		double result = 0;
		result = getNumberA() - getNumberB();
		return result;
	}
};

class OperationMul: public Operation {
public:
	double GetResult() {	
		double result = 0;
		result = getNumberA() * getNumberB();
		return result;
	}
};

class OperationDiv: public Operation {
public:
	double GetResult() {
		double result = 0;
		if (0 == getNumberB())
			cout << "divisor cannot be zero" << endl;
		result = getNumberA() / getNumberB();
		return result;
	}
};

class OperationFactory {
public:
	static Operation* createOperate(string operate) {

		if (0 == operate.compare("+")) 
			return new OperationAdd();
		else if (0 == operate.compare("-"))
			return new OperationSub();
		else if (0 == operate.compare("*"))
			return new OperationMul();
		else if (0 == operate.compare("/"))
			return new OperationDiv();
		else return NULL;
	}
};

int main(void) {

	Operation* oper;
	oper = OperationFactory::createOperate("/");
	oper->setNumberA(1);
	oper->setNumberB(2);
	double result = oper->GetResult();

	cout << result << endl;

	return 0;
}
