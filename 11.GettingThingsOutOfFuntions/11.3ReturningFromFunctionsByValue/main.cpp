#include <iostream>
using namespace std;

int sum ( int a , int b){
    int result = a + b;
    cout << "In : &result(int) :  " << &result << endl;
 	return result;
}

string add_strings(string str1, string str2){
    string result =  str1 + str2;
    cout << "In : &result(string) :  " << &result << endl;
    return result;
}

int main(){

    
    /*
    int x{15};
    int y{9};
    int result = sum(x,y);
    cout << "Out : &result(int) :  " << &result << endl;
    cout << "result : " << result << endl;
    */
 

   
    string in_str1{"Hello"};
    string in_str2{" World!"};
    string result_str = add_strings(in_str1,in_str2);
    cout << "Out : &result_str(string) :  " << &result_str << endl;
    cout << "result_str : " << result_str << endl;
  

    return 0;
}