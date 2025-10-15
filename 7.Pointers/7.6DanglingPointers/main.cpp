#include <iostream>
using namespace std;

int main()
{

    // Case1 : Uninitialized pointer
    /*
    int * p_number; // Dangling uninitialized pointer

    cout << endl;
    cout << "Case 1 : Uninitialized pointer : ." << endl;
    cout << "p_number : " << p_number << endl;
    cout << "*p_number : " << *p_number << endl; //CRASH!
    */

    // Case 2 : deleted pointer
    /*
    cout << endl;
    cout << "Case 2 : Deleted pointer" << endl;
    int * p_number1 {new int{67}};

    cout << "*p_number1 (before delete) : " << *p_number1 << endl;

    delete p_number1;

    cout << "*p_number1(after delete) : " << *p_number1 << endl;
    */

    // Case 3 : Multiple pointers pointing to same address
    /*
    cout << endl;
    cout << "Case 3 : Multiple pointers pointing to same address : " << endl;

    int *p_number3 {new int{83}};
    int *p_number4 {p_number3};

    cout << "p_number3 - " << p_number3 << " - " << *p_number3 << endl;
    cout << "p_number4 - " << p_number4 << " - " << *p_number4 << endl;

    //Deleting p_number3
    delete p_number3;

    //p_number4 points to deleted memory. Dereferncing it will lead to
    //undefined behaviour : Crash/ garbage or whatever
    cout<< "p_number4(after deleting p_number3) - " << p_number4 << " - " << *p_number4 << endl;
    */

    // Solution1 : Initialize your pointers immediately upon declaration
    /*
    cout << endl;
    cout << "Solution 1 : " << endl;
    int *p_number5{nullptr};
    int *p_number6{new int(87)};

    //Check for nullptr before use

    if(p_number6!= nullptr){
        cout << "*p_number6 : " << *p_number6 << endl;
    }else{
        cout << "Invalid address" << endl;
    }
    */

    // Solution 2 :
    // Right after you call delete on a pointer, remember to reset
    // the pointer to nullptr to make it CLEAR it doesn't point anywere
    /*
    cout << endl;
    cout << "Solution 2 : " << endl;
    int *p_number7{new int{82}};

    //Use the pointer however you want
    cout << "p_number7 - " << p_number7 << " - " << *p_number7 << endl;

    delete p_number7;
    p_number7 = nullptr; // Reset the pointer

    //Check for nullptr before use
    if(p_number7!= nullptr){
        cout << "*p_number7 : " << *p_number7 << endl;
    }else{
        cout << "Invalid memory access!" << endl;
    }
    */

    // Solution 3
    // For multiple pointers pointing to the same address ,  Make sure there is
    // one clear pointer (master pointer) that owns the memory ( responsible for releasing when
    //  necessary) , other pointers should only be able to dereference when the master pointer is valid

    cout << endl;
    cout << "Solution 3 : " << endl;
    int *p_number8{new int{382}}; // Let's say p_number8 is the master pointer
    int *p_number9{p_number8};

    // Dereference the pointers and use them
    cout << "p_number8 - " << p_number8 << " - " << *p_number8 << endl;

    if (!(p_number8 == nullptr))
    { // Only use slave pointers when master pointer is valid
        cout << "p_number9 - " << p_number9 << " - " << *p_number9 << endl;
    }

    delete p_number8; // Master releases the memory
    p_number8 = nullptr;

    if (!(p_number8 == nullptr))
    { // Only use slave pointers when master pointer is valid
        cout << "p_number9 - " << p_number9 << " - " << *p_number9 << endl;
    }
    else
    {
        cerr << "WARNING : Trying to use an invalid pointer" << endl;
    }

    cout << "Program is ending well" << endl;

    return 0;
}