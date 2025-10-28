#include <iostream>
using namespace std;

int max(int a, int b){
    cout << "int overload called" << endl;
    return (a>b)? a : b; 
}

double max(double a, double b){
    cout << "double overload called" << endl;
    return (a>b)? a : b; 
}

double max(int a, double b){
    cout << "(int,double) overload called" << endl;
    return (a>b)? a : b; 
}

double max(double a, int b){
    cout << "(double,int) overload called" << endl;
    return (a>b)? a : b; 
}

double max(double a, int b,int c){
    cout << "(double,int,int) overload called" << endl;
    return a;
}

string_view  max(string_view a, string_view b){
    cout << "(string_view,string_view) overload called" << endl;
     return (a>b)? a : b;
}

int main(){

    int x{4};
    int y{9};
    double a{5.4};
    double b{7.4};

    auto result = max(b,x,y);

    max("Hello","World");
   
    return 0;
}