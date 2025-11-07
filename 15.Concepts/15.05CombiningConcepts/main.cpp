#include <iostream>
#include <concepts>
using namespace std;


template <typename T>
concept TinyType = requires ( T t){
	sizeof(T) <=4; // Simple requirement
	requires sizeof(T) <= 4; // Nested requirement
};


template <typename T>
//requires integral<T> || floating_point<T> // OR operator
//requires integral<T> && TinyType<T>
requires integral<T> && requires ( T t){
	sizeof(T) <=4; // Simple requirement
	requires sizeof(T) <= 4; // Nested requirement
}
T add(T a, T b){
    return a + b;
}



int main(){

    long long int x{7};
    long long int y{5};

    add(x,y);

   
    return 0;
}