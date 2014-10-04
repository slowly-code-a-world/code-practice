#include <iostream>
#include <cmath>
using namespace std;

class QuadraticLaw{
	public:
		long getTime(long d);
};

long QuadraticLaw::getTime(long d){
	if(d<=2) return d-1;
	long res = sqrt(d);
	res--;
	while(res*(res+1)<d){
		res++;
	}
	if(res*(res+1)==d) return res;
	res--;
	return res;
}

int main(){
	QuadraticLaw ql;
	long d = 1;
	cout << "0: " << ql.getTime(d) << endl;
	d = 2;
	cout << "1: " << ql.getTime(d) << endl;
	d = 5;
	cout << "2: " << ql.getTime(d) << endl;
	d = 6;
	cout << "3: " << ql.getTime(d) << endl;
	d = 7;
	cout << "4: " << ql.getTime(d) << endl;
	d = 1482;
	cout << "5: " << ql.getTime(d) << endl;
	d = 1000000000000000000;
	cout << "6: " << ql.getTime(d) << endl;
	d = 31958809614643170;
	cout << "7: " << ql.getTime(d) << endl;
	return 0;
}
