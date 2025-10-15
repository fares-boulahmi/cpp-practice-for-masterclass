#include <iostream>
using namespace std;

int main(){

	//Declare array
    char message [5]  {"Hello"};
    //int data[5] {1,2,3,3,3};

    //cout << "data : " << data << endl;
    
  
    //Print out the array through looping
    /*
    cout << "message : ";
    for( auto c : message){
        cout << c ;
    }
    cout << endl;
    */

    
   /*
    //Change characters in our array
    message[1] = 'a';

    //Print out the array through looping
    cout << "message : ";
    for( auto c : message){
        cout << c ;
    }
    cout << endl;
    */

   
   
    // Will probably print garbage after your char array
    /*
    cout << "message : " << message << endl;
    */
   

 
    //If a character array is null terminated, it's called as C-String
    /*
    char message1 [] {'H','e','l','l','o','\0'};
    cout << "message1 : " << message1 << endl;
    cout << "sizeof(message1) : " << sizeof(message1) << endl;
    */

  
   /*
    char message2 [6] {'H','e','l','l','o'};
    cout << "message2 : " << message2 << endl;
    cout << "sizeof(message2) : " << sizeof(message2) << endl;

    char message3 [] {'H','e','l','l','o'}; // This is not a c string ,
											//as there is not null character
    cout << "message3 : " << message3 << endl;
    cout << "sizeof(message3) : " << sizeof(message3) << endl;
    */

    

    //String literal
    /*
    char message4 [] {"Hello"};
    cout << "message4 : " << message4 << endl;
    cout << "sizeof(message4) : " << sizeof(message4) << endl;
    */



    //Can't safely print out arrays other than those of characters
    int numbers [] {1,2,3,4,5};
    cout << "numbers :  " << numbers << endl;
 

    
    return 0;
}