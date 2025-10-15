#include <iostream>
#include <vector>
using namespace std; // if you try use cout endl anything suppose use std:: without this line you have to write the std:: or this line or will return error

// functions 
int sumNumber(vector<int> arr) {
    // statement is smallest thing can cpu ran every decalration of variable is statement 
    int result = 0;
    for ( int i = 0 ; i < arr.size() ; i++) {
        result += arr[i];
    }

return result;
}
// this function with only statment in her 
/*
the statement is called by order from top to bottom 
*/
void SumTwoNumber(string msg ) {
    int firstNumber = 15;
    int secondumber = 20;

    int sumNumber = firstNumber + secondumber ;
    cout << "the sum of the two number " << firstNumber << " + " << secondumber << " is :" << sumNumber << msg <<  endl;

}
int SumTwoNumberInt(string msg ) {
    int firstNumber = 15;
    int secondumber = 20;

    int sumNumber = firstNumber + secondumber ;
    cout << "the sum of the two number " << firstNumber << " + " << secondumber << " is :" << sumNumber << msg <<  endl;

    return 0;
}
consteval int get_value() {
    return 3;
}
/*
the voide function is require to not end with return is not return any value 
same problem when trying to cout it will return problem cause is require in cout value and the void don't return that value 
but in int function is require to return value always return 0 if want to show the cout only or return what that function require from it 
the int can declaire in cout cause is return value
*/
int main() {
    int value = sumNumber({ 1 , 5, 8 ,59,3 ,9});

    cout << "result of some array [1 , 5, 8 ,59,3 ,9] is - :" << value << endl;
    string msg = "the put of string  is worked ";
    cout << "declaration of function with only statment inside :" << SumTwoNumberInt({ msg})   << endl ;
    cout << "declaration of void" << endl;
    SumTwoNumber({ msg}) ;
    cout << "the end of declaration of void" << endl;
    return 0;
}