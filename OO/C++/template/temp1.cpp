#include <iostream>

using namespace std;

template <class T>
class A {
protected:
	T a;
public:
	virtual T geta(void) { }
};

template <class T>
class B: public A<T> {
public:
	T geta(void) { 
		
		//using A<T>::a;
		//return a; 
		
		// or
		return this->a;

		// or, (it disables poly dispatch mechanism)
		// return A<T>::a;	
	} 
};

int main(void) {
	B<int> b;
	int tmp = b.geta();
}
