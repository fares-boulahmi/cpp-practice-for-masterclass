#include <iostream>
using namespace std;

int main(){

	//Verbose nullptr check
	cout << endl;
	cout << "Verbose nullptr check: " << endl;
	
    int *p_number{};//Initialized to nullptr
    //p_number = new int(7);
    
    /*
    if(!(p_number==nullptr)){
        cout << "p_number points to a VALID address : "<< p_number << endl;
        cout << "*p_number : " << *p_number << endl;
    }else{
        cout << "p_number points to an INVALID address." << endl;
    }
    */
    if(p_number){
        cout << "p_number points to a VALID address : "<< p_number << endl;
        cout << "*p_number : " << *p_number << endl;
    }else{
        cout << "p_number points to an INVALID address." << endl;
    }

    delete p_number;
    nullptr;

    //It is OK call delete on a nullptr
	//Calling delete on a nullptr is OK
    int *p_number1 {};
    
    delete p_number1;	// This won't cause any problem
						//if p_number1 contains nullptr

    // if(p_number1 != nullptr){
    //     delete p_number1;
    // }
   
    return 0;
}