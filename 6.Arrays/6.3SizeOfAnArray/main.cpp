#include <iostream>
using namespace std;

int main(){

    int scores [] {1,2,5};

   
    int count { size(scores)}; // size( C++17)

    cout << "sizeof(scores) : " << sizeof(scores) << endl;
    cout << "sizeof(scores[0]) : " << sizeof(scores[0]) << endl;
    cout << "count : " << count << endl;



    /*
    int count {sizeof(scores)/sizeof(scores[0])};


    for(size_t i {0} ; i < count ; ++i){
        cout << "scores [" << i << "] : " << scores[i] << endl;
    }
 

   //Range based for loop
    for ( auto i : scores){
            cout << "value  : " << i << endl;       
    }
    */
   
    
    return 0;
}