#include <iostream>
using namespace std;

int main(){

	//Print I love C++ 10 times : The bad way
    /*
    cout << "I love C++" << endl;
    cout << "I love C++" << endl;
    cout << "I love C++" << endl;
    cout << "I love C++" << endl;
    cout << "I love C++" << endl;
    cout << "I love C++" << endl;
    cout << "I love C++" << endl;
    cout << "I love C++" << endl;
    cout << "I love C++" << endl;
    cout << "I love C++" << endl;
    */

   //for loop : the good way
    /*
   for( unsigned int i{0} ; i < 10000 ;++i){
       //Whatever we want the loop to run
       cout << i <<  " : I love C++" << endl;
   }
   cout << "Loop done!" << endl;
   */

  //Use size_t : a representation of some unsigned int for positive numbers [sizes]
  /*
  for(size_t i{0} ; i < 10 ; ++i){
      cout << i << " : I love C++" << endl;
  }
  cout << "Loop done!" << endl;
  */
    /*
    //sizeof(size_t)
    cout << "sizeof(size_t) : " << sizeof(size_t) << endl;
    */


    //Scope of the iterator
    /*
    for(size_t i{0} ; i < 10 ; ++i){
        cout << i << " : I love C++" << endl;
    }
    cout << "Loop done!" << endl;
    // cout << "i : " << i << endl;Compiler error : i is not in scope
    */


   //Iterator declared outside the loop
   /*
    size_t i{0}; // Iterator defined outside

    for(i ; i < 10 ; ++i){
        cout << i << " : I love C++" << endl;
    }
    cout << "Loop done!" << endl;
    cout << "i : " << i << endl;
    */


    //Leave out the iterator declaration part
    /*
    size_t i{0}; // Iterator defined outside

    for(  ; i < 10 ; ++i){
        cout << i << " : I love C++" << endl;
    }
    cout << "Loop done!" << endl;
    cout << "i : " << i << endl;
    */


   //Don't hard code values : BAD!

    const size_t COUNT{100};

    for(size_t i{0} ; i < COUNT ; ++i){
        cout << i << " : I love C++" << endl;
    }
    cout << "Loop done!" << endl;
   
    return 0;
}