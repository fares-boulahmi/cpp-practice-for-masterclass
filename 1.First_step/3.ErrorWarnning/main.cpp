#include <iostream>
using namespace std;

int main() {

    // compile time  error missing ; 
    cout << "hallo world!" << endl;

    // run time error 
    int value = 56471423677/0;

    cout << "test after run time error " << value << endl;

    // warnning 
    cout << 7/0 << endl;
    return 0;
}