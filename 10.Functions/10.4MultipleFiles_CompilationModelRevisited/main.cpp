#include <iostream>
#include "compare.h" // Preprocessor
#include "operations.h"
using namespace std;

int main(){

    int maximum = max(134,56);
    cout << "max : " << maximum << endl;

    int minimum = min(146,23);
    cout << "min : " << minimum << endl;

    int x{4}; // 5
    int y{5}; // 6

    int result = incr_mult(x,y);
    cout << "result : " << result << endl;
   
    return 0;
}

