/*
Write a smart pointer class. A smart pointer is a data type, usually imple-
mented with templates, that simulates a pointer while also providing auto-
matic garbage collection. It automatically counts the number of references to a
SmartPointer<T*> object and frees the object of type T when the reference
count hits zero.
*/

template <class T>
class SmartPointer {
private:
	T *obj;
	unsigned *ref_count;
	void remove() {
		--(*ref_count);
		if (*ref_count == 0) {
			delete obj;
			free(ref_count);
			obj = NULL;
			ref_count = NULL;
		}
	}
public:
	SmartPointer(T *ptr) {
		obj = ptr;
		ref_count = (unsigned*) malloc(sizeof(unsigned));
		*ref_count = 1;
	}

	SmartPointer(SmartPointer<T>& sptr) {
		obj = sptr.obj;
		ref_count = sptr.ref_count;
		++(*ref_count);
	}

	SmartPointer<T> &operator=(SmartPointer<T> &sptr) {
		if (this == &sptr) return *this;
		if (*ref_count > 0) remove();
		obj = sptr.obj;
		ref_count = sptr.ref_count;
		++(*ref_count);
		return *this;
	}

	~SmartPointer() {
		remove();
	}

	
};

int main(void) {
	int a = 5;
	SmartPointer<int> p (&a);
}

