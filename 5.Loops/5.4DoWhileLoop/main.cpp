#include <iostream>
using namespace std;

int main(){

	//Print I love C++ 10 times
    /*
    cout << "I love C++" << endl;
    cout << "I love C++" << endl;
    cout << "I love C++" << endl;
    cout << "I love C++" << endl;
    cout << "I love C++" << endl;
    cout << "I love C++" << endl;
    cout << "I love C++" << endl;
    cout << "I love C++" << endl;
    cout << "I love C++" << endl;
    cout << "I love C++" << endl;
    */

    const int COUNT{0};
    size_t i{0}; // Iterator declaration

    do{
        cout << i << " : I love C++" << endl;
        ++i; // Incrementation
    }while( i < COUNT);

    cout << "Loop done!" << endl;
    
    return 0;
}