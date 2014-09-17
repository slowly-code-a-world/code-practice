/*
16.3 In the famous dining philosophers problem, a bunch of philosophers are sitting
    around a circular table with one chopstick between each of them. A philosopher
   needs both chopsticks to eat, and always picks up the left chopstick before the
  right one. A deadlock could potentially occur if all the philosophers reached for
 the left chopstick at the same time. Using threads and locks, implement a simu-
lation of the dining philosophers problem that prevents deadlocks.
*/
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

thread* threads[10];
mutex locks[10];
void dining(int i) {	
	if (0 == i%2) {
		locks[(i + 9)%10].lock();
		locks[i].lock();
		locks[i].unlock();
                locks[(i + 9)%10].unlock();
	} else {
		locks[i].lock();
		locks[i-1].lock();
		locks[i-1].unlock();
                locks[i].unlock();
	}
}

int main() {
	for (int i = 0; i<10; i++) 
		threads[i] = new thread(dining, i);

	for (int i = 0; i<10; i++)
		(*threads[i]).join();

	return 0;		
}
