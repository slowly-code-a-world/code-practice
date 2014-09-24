/*
Given any integer, print an English phrase that describes the integer (e.g., "One
Thousand, Two Hundred Thirty Four").
*/

void real_print(int n) {
	if (n >= 10e9) {
		int tmp = n/10e9;
		std::cout << tmp << " billion ";
		n = tmp * 10e9;
	}	

	if (n >= 10e6) {
		int tmp = n/10e6;
		real_print(tmp);
		std::cout << " million ";
		n = n - tmp * 10e6;
	}

	if (n >= 1000) {
		int tmp = n/1000;
		real_print(tmp);
		std::cout << " thousand ";
		n = n - tmp * 1000;	
	}

	if (n >= 100) {
		int tmp = n/100;
		std::cout << tmp << " hundred ";
		n = n - tmp * 100;
	}

	if (n >= 90) {
		std::cout << " ninty ";
		n -= 90;
	} else if (n >= 80) {
		std::cout << " eighty ";
		n -= 80;
	} else if (n >= 70) {
		std::cout << " seventy ";
		n -= 70;
	} else if (n >= 60) {
		std::cout << " sixty ";
		n -= 60;
	} else if (n >= 50) {
		std::cout << " fifty ";
		n -= 50;
	} else if (n >= 40) {
		std::cout << " forthy ";
		n -= 40;
	} else if (n >= 30) {
		std::cout << " thirthy ";
		n -= 30;
	} else if (n >= 20) {
		std::cout << " twenty ";
		n -= 20;
	} 	

	switch(n) {
		case 1:
			std::cout << " one " << endl;
			break;
		// omit here
		case 2...19
		default:
			break;
	}
}

void print(int n) {
	if (0 == n) std::cout << "zero" << std::endl;
	if (n < 0) std::cout << "negative ";

	real_print(n);
}
