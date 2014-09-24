/*
17.1 Write a function to swap a number in place (that is, without temporary vari-
    ables).

*/
void swap(int& a, int &b){
	a = a ^ b;
	b = a ^ b;
	a = b ^ a;
}
