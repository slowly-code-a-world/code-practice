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

using namespace std;

class Foo {
public:
	mutex *mtx1, *mtx2, *mtx3;
	Foo():mtx1(NULL), mtx2(NULL), mtx3(NULL) {
		mtx1 = new mutex();
		mtx2 = new mutex();
		mtx3 = new mutex();
		(*mtx1).lock();
		(*mtx2).lock();
		(*mtx3).lock();	
	}
	void first() { cout << "first" << endl; }
	void second() { cout << "second" << endl; }
	void third() { cout << "third" << endl; }

}; 

int func(Foo f, int id) {
	if (0 == id) {
		f.first();
		f.mtx1->unlock();
	} else if (1 == id) {
		f.mtx1->lock();
		f.mtx1->unlock();
		f.second();
		f.mtx2->unlock();
	} else {
		f.mtx2->lock();
		f.mtx2->unlock();
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
