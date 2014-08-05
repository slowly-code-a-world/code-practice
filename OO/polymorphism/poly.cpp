#include <iostream>

using namespace std;

/* abstact class */
class Polygon {
protected:
	int width, height;
public:
	Polygon(int a, int b) : width(a), height(b) {}
	virtual int area(void) = 0;
	void printarea() {
		cout << this->area() << "\n" << endl;
	}
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

int main(void) {

	//Polygon a;
	Polygon *p1 = new Rectangle(4, 5);
	Polygon *p2 = new Triangle(4, 5);
	p1->printarea();
	p2->printarea();
	delete p1;
	delete p2;

	return 0;
} 
