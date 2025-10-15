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
int SumTwoNumber(int argc , char **argv) {
    int firstNumber = 15;
    int secondumber = 20;

    int sumNumber = firstNumber + secondumber ;
    cout << "the sum of the two number " << firstNumber << " + " << secondumber << " is :" << sumNumber << endl;

    return 0;
}
int main() {
    int value = sumNumber({ 1 , 5, 8 ,59,3 ,9});

    cout << "result of some array [1 , 5, 8 ,59,3 ,9] is - :" << value << endl;

    cout << "declaration of function with only statment inside :" << endl << SumTwoNumber() << endl;
    return 0;
}