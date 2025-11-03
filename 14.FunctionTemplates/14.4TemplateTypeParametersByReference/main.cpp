#include <iostream>
using namespace std;

template <typename T> const T& maximum(const T& a, const T& b); // Declaration
//template <typename T> T maximum(T a, T b); // Declaration

int main(){

    double a {23.5};
    double b {51.2};

    cout << "Out - &a: " << &a << endl; // 0x111abc
    auto result = maximum(a,b);
    cout << "Out - &a: " << &a << endl; // 0x111abc
  
    return 0;
}


//Definition
template <typename T> const T& maximum(const T& a, const T& b){
    cout << "In - &a: " << &a << endl; // // 0x111abc
    return (a > b ) ? a : b ;
}

/*
template <typename T> T maximum(T a, T b){
    cout << "In - &a: " << &a << endl; // // 0x111abc
    return (a > b ) ? a : b ;
}
*/