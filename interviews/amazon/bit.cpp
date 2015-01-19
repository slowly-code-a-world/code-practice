#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int cases;
    cin >> cases;
    for (int i = 0; i<cases; i++) {
        unsigned int number;
        cin >> number;
        cout << ~number << endl;
    }
        
    return 0;
}
