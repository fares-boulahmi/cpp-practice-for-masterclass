#include <iostream>
using namespace std;

int main(){

    int int_data{33};
    double double_data{55};

    //References
    int& ref_int_data{int_data};
    double& ref_double_data{double_data};

    //Print stuff out
    cout << "int_data : " << int_data << endl;
    cout << "&int_data : " << &int_data << endl;
    cout << "double_data : " << double_data << endl;
    cout << "&double_data : " << &double_data << endl;

    cout << "=======================" << endl;

    cout << "ref_int_data : " << ref_int_data << endl;
    cout << "&ref_int_data : " << &ref_int_data << endl;
    cout << "ref_double_data : " << ref_double_data << endl;
    cout << "&ref_double_data : " << &ref_double_data << endl;

    int_data = 111;
    double_data = 67.2;


    //Print stuff out
    cout << endl;
    cout << "int_data : " << int_data << endl;
    cout << "&int_data : " << &int_data << endl;
    cout << "double_data : " << double_data << endl;
    cout << "&double_data : " << &double_data << endl;

    cout << "=======================" << endl;

    cout << "ref_int_data : " << ref_int_data << endl;
    cout << "&ref_int_data : " << &ref_int_data << endl;
    cout << "ref_double_data : " << ref_double_data << endl;
    cout << "&ref_double_data : " << &ref_double_data << endl;


    ref_int_data = 1012;
    ref_double_data = 1000.45;


   //Print stuff out
    cout << endl;
    cout << "int_data : " << int_data << endl;
    cout << "&int_data : " << &int_data << endl;
    cout << "double_data : " << double_data << endl;
    cout << "&double_data : " << &double_data << endl;

    cout << "=======================" << endl;

    cout << "ref_int_data : " << ref_int_data << endl;
    cout << "&ref_int_data : " << &ref_int_data << endl;
    cout << "ref_double_data : " << ref_double_data << endl;
    cout << "&ref_double_data : " << &ref_double_data << endl;
    
    return 0;
}