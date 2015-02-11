#include <iostream>
#include <vector>
using namespace std;
int main(void) {
	unsigned int i = 1;
	char *c = (char*)&i;
	if (*c == 0) cout << "big" << endl;
	else cout << "small" << endl; 
}
