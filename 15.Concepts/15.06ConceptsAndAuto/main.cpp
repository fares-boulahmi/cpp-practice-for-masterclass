#include <iostream>
#include <concepts>
using namespace std;

//This syntax constrains the auto parameters you pass in 
//to comply with the integral concept
integral auto add (integral auto a,integral auto b){
	return a + b;
}


int main(){

    floating_point auto x = add(5,8);
  
    return 0;
}