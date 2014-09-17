/*
16.5
The same instance of Foo will be passed to three different threads. ThreadA will
call first, threads will call second, and threadC will call third. Design a
mechanism to ensure that first is called before second and second is called
before third.
*/

#include <iostream>
#include <thread>
#include <mutex>

mutex mtx;
volatile int start = 0;

class Foo {
public:
	Foo() {}
	void first() { cout << "first" << endl; }
	void second() { cout << "second" << endl; }
	void third() { cout << "third" << endl; }
} 

int func(Foo f, int id) {
	if (0 == id) {
		f.first();
		start = 1;
	} else if (1 == id) {
		while (1 != start);
		f.second();
		start = 2;
	} else {
		while(2 != start);
		f.third();
	}
}

int main() {
	thread *ths[3];
	Foo f;
	for (int i = 0; i<3; i++) 
		ths[i] = new thread(func, f, i);
	for (int i = 0; i<3; i++)
		(*ths[i]).join();
}	
