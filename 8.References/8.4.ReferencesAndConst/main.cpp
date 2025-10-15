#include <iostream>
using namespace std;


int main(){

	//Non const reference
	cout << endl;
	cout << "Non const reference : " << endl;
	int age {27};
	const int& ref_age{age};
	/*
	cout << "age : " << age << endl;
	cout << "ref_age : " << ref_age << endl;
	
	
	//Can modify original variable through reference

	cout << endl;
	cout << "Modify original variable through reference : " << endl;
	
	ref_age++; //Mofify through reference
	
	cout << "age : " << age << endl;
	cout << "ref_age : " << ref_age << endl;
    */

   //Simulating reference behavior with pointers
	// the second const is to prevent from change the pointing place 
    //  int * const  p_age {&age};
	//*p_age = 45;
	// the first const is to prevent from change the value inside 
	// const int * p_age {nullptr};
   	// int hal = 44;
   	// p_age = &hal;
	// the two const is to make pointer not aple to change the value either the value only read pointer 
	// const int * const p_age  {&age};
	
   
    return 0;
}