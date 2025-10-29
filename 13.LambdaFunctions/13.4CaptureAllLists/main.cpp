#include <iostream>
using namespace std;

int main()
{

    // Capture everything by value
    /*
     int c{42};

     auto func = [=](){
         cout << "Inner value : " << c << endl;
     };

     for(size_t i{} ; i < 5 ;++i){
         cout << "Outer value : " << c << endl;
         func();
         ++c;
     }
     */

    // Capturing all reference
    int c{42};
    int d{5};

    auto func = [&]()
    {
        cout << "Inner value : " << c << endl;
        cout << "Inner value(d) : " << d << endl;
    };

    for (size_t i{}; i < 5; ++i)
    {
        cout << "Outer value : " << c << endl;
        func();
        ++c;
    }

    return 0;
}