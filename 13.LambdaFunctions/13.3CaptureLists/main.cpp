#include <iostream>
using namespace std;
int main(){

    //Capture lists
    /*
     double a{10};
     double b{20};
     
     auto func = [a,b](){
         cout  << "a + b : " << a + b << endl;
     };
     func();
     */

    //Capturing by value
    /*
     int c{42};
     
     auto func = [c](){
         cout << "Inner value : " << c << " &inner : " <<&c <<  endl;
     };
     
     for(size_t i{} ; i < 5 ;++i){
         cout << "Outer value : " << c << " &outer : " << &c << endl;
         func();
         ++c;
     }

     */

    //Capture by reference
     int c{42};
     
     auto func = [&c](){
         cout << "Inner value : " << c << " &inner : " <<&c <<  endl;
     };
     
     for(size_t i{} ; i < 5 ;++i){
         cout << "Outer value : " << c << " &outer : " << &c << endl;
         func();
         ++c;
     }
    
    return 0;
}