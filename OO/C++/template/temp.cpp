#include <iostream>

using namespace std;

template <class T>
T sum(T a, T b) {
	return a + b;
}

int main(void) {
	cout << sum(5, 6) << endl;
}
