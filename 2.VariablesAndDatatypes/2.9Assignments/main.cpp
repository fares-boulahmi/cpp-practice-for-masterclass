#include <iostream>
using namespace std;

int main(){

	int var1{123}; // Declare and initialize
    cout << "var1 : "  << var1 << endl;
    
    var1 = 55; // Assign
    cout << "var1 : "  << var1 << endl;
    
    cout << endl;

    cout << "----------------" << endl;

    double var2 {44.55}; // Declare and initialize
    cout << "var2 : " << var2 << endl;
    
    var2 = 99.99; // Assign
    cout << "var2 : " << var2 << endl;
    
    cout << endl;

    cout << "----------------" << endl;

    cout << endl;
    bool state{false}; // Declare and initialize
    cout << boolalpha;
    cout << "state : " << state << endl;
    
    state = true; // Assign
    
    cout << "state : " << state << endl;


    //Auto type deduction
    //Careful about auto assignments
    auto var3 {333u}; // Declare and initialize with type deduction
    
    var3 = -22; // Assign negative number. DANGER!
    
    cout << "var3 : " << var3 << endl;

   
    return 0;
}