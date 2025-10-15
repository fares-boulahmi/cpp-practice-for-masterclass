#include <iostream>
using namespace std;

int main(){

    int a {6};
    int b {3};
    int c {8};
    int d {9};
    int e {3};
    int f {2};
    int g {5};
        
    int result = a + b * c -d/e -f + g; // 6 + 3 * 8 - 9/3 -2 +5 = 6 + 24 - 3 - 2 + 5 = 30 - 5 + 5 = 30 
    
    cout << "result : " << result << endl;

    result = a/b*c +d - e + f;  // 6/3*8 + 9  - 3 + 2 = 2*8 + 6 + 2 = 16 + 8 = 24
    cout << "result : " << result << endl;

    result = (a + b) * c -d/e -f + g; // (6 + 3) * 8 - 9/3 - 2 + 5 = 9*8 -3 - 2 + 5 = 72 - 5 + 5 = 72
    cout << "result () : " << result << endl;
   
    return 0;
}