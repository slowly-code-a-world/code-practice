#include <iostream>

using namespace std;

class singleton {
private:
	singleton(void) { cout << "creating instance" << endl; }
public:
	~singleton(void) { cout << "deleting instance" << endl; }

	static singleton& get_instance(void) { 

		static singleton Instance;

		return Instance;
	}	
};

int main(void) {

	singleton::get_instance();	
	singleton::get_instance();

	return 0;
}
