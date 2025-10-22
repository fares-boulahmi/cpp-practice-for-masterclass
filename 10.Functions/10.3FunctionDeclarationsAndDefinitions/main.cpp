#include <iostream>
using namespace std;

int max(int a, int b); // Function declaration , prototype
                        // Signature doesn't include return type
int min(int a, int b);

int inc_mult( int a, int b);

int main(){

    int x {5};
    int y{12};

    int result = min(x,y);
    cout << "min : " << result << endl;

    result =inc_mult(x,y);
    cout << "result : " << result << endl;

    return 0;
}

//Function definition. Shows up after main 
int max(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}


//Function definition. Shows up after main 
int min(int a, int b){
    if(a < b)
        return a;
    else
        return b;
}

int inc_mult( int a, int b){
    return ( (++a)*(++b));
}