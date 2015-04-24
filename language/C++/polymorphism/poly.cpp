#include <iostream>

using namespace std;


class Polygon {
protected:
	int width, height;
public:
	Polygon() {}
	Polygon(int a, int b) : width(a), height(b) {}
	virtual int area(void) {return 0;}
	void printarea() {
		cout << this->area() << "\n" << endl;
	}
	Polygon& operator= (Polygon&) { cout << "copy assignment" << endl; return *this;}
};

class Example {
public:
	Example() {}
	Example(Polygon&) {}
        operator Polygon() {cout << "casting" << endl; return Polygon();}
};

class Rectangle: public Polygon {
public:
	Rectangle(int a, int b): Polygon(a, b) {}
	int area() {
		return width*height;
	}
};	 

class Triangle: public Polygon {
public:
	Triangle(int a, int b): Polygon(a, b) {}
	int area() {
		return width*height/2;
	}	
};

void ref(Polygon &poly) {
	poly.printarea();
}

int main(void) {

	Polygon poly(4,5);
	Rectangle rect(4, 5);
	Triangle tri(4, 5);
	Example ex;
	ex = poly;
	poly.printarea();
	ref(rect);
	ref(tri);
	return 0;
} 
