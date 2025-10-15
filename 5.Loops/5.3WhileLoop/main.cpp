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


    const size_t COUNT{100};
    size_t i{0}; // Iterator declaration

    while(i < COUNT ){ // Test
       cout << i << " : I love C++" << endl;

       ++i; // Incrementation 
    }
    cout << "Loop done!" << endl;
   
    return 0;
}