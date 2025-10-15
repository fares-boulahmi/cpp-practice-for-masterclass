#include <iostream>
using namespace std;

int main(){

	char character1 {'a'};
    char character2 {'r'};
    char character3 {'r'};
    char character4 {'o'};
    char character5 {'w'};
    
    cout << character1 << endl;
    cout << character2 << endl;
    cout << character3 << endl;
    cout << character4 << endl;
    cout << character5 << endl;

    //One byte in memory : 2^8 = 256 different values (0 ~ 255)
    cout << endl;
    
    char value = 65 ; // ASCII character code for 'A'
    cout << "value : " << value << endl; // A
    cout << "value(int) : " << static_cast<int>(value) << endl; 

    return 0;
}