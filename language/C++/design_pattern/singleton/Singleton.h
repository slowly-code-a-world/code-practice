#include <iostream>

using namespace std;

class Singleton {
public:
	static Singleton* getInstance() { 
		if (NULL != pInstance)
			pInstance = new Singleton();

		return pInstance;
	}

private:
	Singleton() {};

	Singleton(Singleton const &) {};
	
	Singleton& operator=(Singleton const &) {};
 
	~Singleton() {};
	
	static Singleton *pInstance;
};

Singleton* Singleton::pInstance = NULL;

