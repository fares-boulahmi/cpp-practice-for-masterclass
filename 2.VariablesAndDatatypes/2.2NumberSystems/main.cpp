#include <iostream>
using namespace std;

int identical()
{

    int number1 = 15;         // Decimal
    int number2 = 017;        // Octal
    int number3 = 0x0F;       // Hexadecimal
    int number4 = 0b00001111; // Binary

    cout << "number1 : " << number1 << endl;
    cout << "number2 : " << number2 << endl;
    cout << "number3 : " << number3 << endl;
    cout << "number4 : " << number4 << endl;

    return 0;
}
int nonIdentical()
{
    int number1 = 27;          // decimal
    int number2 = 01756;       // octal
    int number3 = 0x0f;        // Hexadecimal
    int number4 = 0b001001101; // Binary
    // int number2f = 0189;       // try false octal number the limit is 7
    // int number3f = 0x0flk;     // Hexadecimal l and k not from hexadecimal system
    // int number45 = 0b0010201101 ; // will not let even try to use it

    cout << "program start of non identical number" << endl;
    cout << "start correct number " << endl;
    cout << "number1 is : " << number1 << endl;
    cout << "number2 is : " << number2 << endl;
    cout << "number3 is : " << number3 << endl;
    cout << "number4 is : " << number4 << endl;

    cout << "try operation in true oct hex binary number " << endl;

    cout << "the result of decimal minus octal is :" << number1 - number2 << endl;
    cout << "the result of Hexadecimal Binary octal is :" << number3 - number4 << endl;
    /*
    cout << "try false value " << endl;

    cout << "false octal is :" << number2f << endl;
    cout << "false Hexadecimal is :" << number3f << endl;
    don't try the program won't start is build in role of c++

    main.cpp:10:22: error: invalid digit '8' in octal constant
       10 |     int number2f = 0189;       // try false octal number the limit is 7
          |                      ^
    main.cpp:11:24: error: invalid suffix 'lk' on integer constant
       11 |     int number3f = 0x0flk;     // Hexadecimal l and k not from hexadeci...
          |                        ^
    2 errors generated.
    */

    cout << "end of program of  non identical number " << endl;
    return 0;
}

int main()
{

    cout << "start of program identical number " << endl;
    identical();
    cout << "end of program identical number " << endl << endl;
    cout << "start of program nonIdentical number " << endl;
    nonIdentical();
    cout << "start of program nonIdentical number " << endl;

    return 0;
}