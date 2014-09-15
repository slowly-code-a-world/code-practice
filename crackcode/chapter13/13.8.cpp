/*
Write a smart pointer class. A smart pointer is a data type, usually imple-
mented with templates, that simulates a pointer while also providing auto-
matic garbage collection. It automatically counts the number of references to a
SmartPointer<T*> object and frees the object of type T when the reference
count hits zero.
*/

template <class T>
class SmartPointer<T*> {
private:
	int count;
public:
	SmartPointer<T*>() {
		count = 0;
	}

	
};
