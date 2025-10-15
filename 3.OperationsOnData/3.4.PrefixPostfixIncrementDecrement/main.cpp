#include <iostream>
using namespace std;

int main(){

	int value { 5 };
    
    //Increment by one
    value = value + 1; //6
    cout << "The value is : " << value << endl; // 6
    
    value = 5; // Reset value to 5
    
    //Decrement by one
    value = value - 1; // 4
    cout << "The value is : " << value << endl; //4
    
    //===================================================================

    
    cout << "======Postfix increment and decrement======"<< endl;
    //Reset value to 5
    value = 5;
    
    cout << "The value is (incrementing) : " << value++ << endl; // 5
    cout << "The value is : " << value << endl; // 6
    
    cout << endl;
    
    //Decrement with postfix
    
    //Reset value to 5
    value = 5;
    
    cout << "The value is (decrementing) : " << value-- << endl; //5
    cout << "The value is : " << value << endl; // 4


    //===================================================================

    
    cout << "======Prefix increment and decrement======"<< endl;

    //Reset value to 5
    value = 5;
    
    ++value;
    cout << "The value is (prefix++) : " << value << endl; // 6
    
    //Reset value to 5
    value = 5;
    cout << "The value is (prefix++ in place) : " << ++value << endl; // 6
    
    cout << endl;
    
    //Prefix : Decrementing
    
    //Reset value to 5;
    value = 5;
    --value;
    cout << "The value is (prefix--) : " << value << endl; // 4
    
    //Reset value to 5;
    value = 5;
    cout << "The value is (prefix-- in place) : " << --value << endl;//4

   
    return 0;
}