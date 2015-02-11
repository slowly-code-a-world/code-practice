#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Pizza {
private:
	int size;
	int prices;
	vector<toppings> allToppings;
public:
	Pizza(int size, int prices) {
		this->size = size;
		this->prices = prices;
		allToppings.clear();
	}
	int getSize() {return size};
	void setSize(int size) {this->size = size};
	int getPrices() {return prices;}
	void addOneTopping(Topping t) {
		allToppings.push_back(t);
	}
	int calPrices(int base) {
		prices = base;
		for (int i = 0; i<allToppings.size(); i++)
			prices += allToppings[i].prices;
	}
};

class Topping {
private:
	int prices;
	int type;
public:
	Topping(int prices, int type) {
		this->prices = prices;
		this->type = type;
	}
	int getPrices() {return prices;}
	int getType() {return type};
}
