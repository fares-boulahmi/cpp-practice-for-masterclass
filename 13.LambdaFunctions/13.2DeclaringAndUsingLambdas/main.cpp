#include <iostream>
using namespace std;


int main(){
    /*
    Lambda function signature : 
                                [capture list] (parameters) ->return type{
                                        // Function body
                                }
    */

   //Declaring a lambda function and calling it through a name
   /*
   auto func = [](){
       cout << "Hello World!" << endl;
   };
   func();
   func();
   */


    //Declare a lambda function and call it directly
    /*
    [](){
       cout << "Hello World!" << endl;
    }();
    */


    //Lambda function that takes parameters

    /*
    [](double a, double b){
       cout << "a + b : " << (a + b)  << endl;
    }(10.0,50.0);
    */

   /*
    auto func1 = [](double a, double b){
       cout << "a + b : " << (a + b)  << endl;
    };

    func1(10,20);
    func1(5,7);
    */


   //Lambda function that returns something
    /*
    auto result = [](double a, double b){
        return a + b;
    }(10,60);

    //cout << "result : " << result << endl;
    cout << "result : " << [](double a, double b){
        return a + b;
    }(10,60) << endl;
    */


   /*
    auto func1 = [](double a, double b){
        return a + b;
    };

    auto result1 = func1(23,7);
    auto result2 = func1(9,45);

    cout << "result1 : " << result1 << endl;
    cout << "result2 : " << result2 << endl;
    cout  <<"direct call : " << func1(5,2) << endl;
    */

    //Explicitly specify the return type
    
    auto func3 = [](double a, double b)-> int{
        return a + b;
    };

    auto func4 = [](double a, double b){
        return a + b;
    };

    double a{6.9};
    double b{3.5};

    auto result3 = func3(a,b);
    auto result4 = func4(a,b);

    cout << "result3 : " << result3 << endl;
    cout << "result4 : " << result4 << endl;
    cout << "sizeof(result3) : " << sizeof(result3) << endl; // 4
    cout << "sizeof(result4) : " << sizeof(result4) << endl; // 8


   cout << "Done!" << endl;
   
    return 0;
}