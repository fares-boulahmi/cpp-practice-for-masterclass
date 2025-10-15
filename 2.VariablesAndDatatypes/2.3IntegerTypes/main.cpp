#include <iostream>
#include <vector>
#include <string>
using namespace std;

// testing what will happen if try to store double in integer 
 int  floatNumber(bool brak) {

    if (brak) {
        int float_number {2};
        cout << "result of float number save in integer is :" << float_number << endl;
            // the result is this error : 
            //     main.cpp:5:23: error: type 'double' cannot be narrowed to 'int' in initializer list [-Wc++11-narrowing]
            //         5 |     int float_number {2.9};
            //         |                       ^~~
            //     main.cpp:5:23: note: insert an explicit cast to silence this issue
            //         5 |     int float_number {2.9};
            //         |                       ^~~
            //         |                       static_cast<int>( )
            //     main.cpp:5:23: warning: implicit conversion from 'double' to 'int' changes value from 2.9 to 2 [-Wliteral-conversion]
            //         5 |     int float_number {2.9};
            //         |                      ~^~~
            //     1 warning and 1 error generated.
    } else {
         int float_number (2.9);
         int long_number = 2851616511516185131; // can't store long number in int 

         cout << "result of long number save in integer is :" << long_number << endl;
            /*
                main.cpp:24:28: warning: implicit conversion from 'long long' to 'int' changes value from 2851616511516185131 to -728788437
                    [-Wconstant-conversion]
                24 |          int long_number = 2851616511516185131;
                    |              ~~~~~~~~~~~   ^~~~~~~~~~~~~~~~~~~
                2 warnings and 1 error generated.
                second result of float number save in integer is :219660544
            */

         cout << "result of float number save in integer is :" << float_number << endl;
         /*
            result of float number save in integer is :2 cut anything after the point is bad for safety 
            and loss data will only return warning but compile the program :
                main.cpp:23:28: warning: implicit conversion from 'double' to 'int' changes value from 2.9 to 2 [-Wliteral-conversion]
            23 |          int float_number (2.9);
                |              ~~~~~~~~~~~~  ^~~
         */
    }
    return 0;
}

void lecturCode() {
    
    //Braced initializers
    /*
    //Variable may contain random garbage value . WARNING
    int elephant_count;
    
    int lion_count{};//Initializes to zero
    
    int dog_count {10}; //Initializes to 10
    
    int cat_count {15}; //Initializes to 15
    
    //Can use expression as initializer
    int domesticated_animals { dog_count + cat_count };

    //
    //int new_number{doesnt_exist};

   // int narrowing_conversion {2.9};//Compiler error

    cout << "Elephant count : " << elephant_count << endl;
    cout << "Lion count : " << lion_count << endl;
    cout << "Dog count : " << dog_count << endl;
    cout << "Cat count : " << cat_count << endl;
    cout << "Domesticated animal count : " << domesticated_animals << endl;
   */




   //Functional Initialization
   /*
    int apple_count(5);
    int orange_count(10);
    int fruit_count (apple_count + orange_count);
    //int bad_initialization ( doesnt_exist3 + doesnt_exist4 );

    //Information lost. less safe than braced initializers
    int narrowing_conversion_functional (2.9);
    
    
    cout << "Apple count : " << apple_count << endl;
    cout << "Orange count : " << orange_count << endl;
    cout << "Fruit count : " << fruit_count << endl;
    cout << "Narrowing conversion : " << narrowing_conversion_functional << endl;//Will loose info
    */


   //Assignment notation
    
    int bike_count = 2;
    int truck_count = 7;
    int vehicle_count = bike_count +truck_count;
    int narrowing_conversion_assignment = 2.9;

    cout << "Bike count : " << bike_count << endl;
    cout << "Truck count : " << truck_count << endl;
    cout << "Vehicle count : " << vehicle_count << endl;
    cout << "Narrowing conversion : " << narrowing_conversion_assignment << endl;
    

    //Check the size with sizeof
    cout << "sizeof int : " << sizeof(int) << endl;
    cout << "sizeof truck_count : " << sizeof(truck_count) << endl;
}

int main() {

    cout << "try float number function with switch between {} and () " << floatNumber(false) << endl;
    cout << "size of int is : " << sizeof(int) << endl;
    cout << "size of function is " << sizeof(floatNumber(false)) << endl << endl << endl;

    cout << "lecture code is :" << endl;
    lecturCode();

    vector<int> arr {1 , 5 , 8 , 6  ,8 };
    cout << "trying vector print " << arr[2] << "size of arr is : " << sizeof(arr) << "the pure size of array is " << sizeof(vector<string>) << endl;
    return 0;
}