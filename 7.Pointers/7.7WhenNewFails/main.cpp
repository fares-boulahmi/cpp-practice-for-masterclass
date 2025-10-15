#include <iostream>
using namespace std;

int main()
{

    /*
    //int * data = new int[10000000000000000]; //

    for(size_t i{0} ; i < 10000000 ; ++i){
        int * data = new int[100000000];
    }
    */

    // exception
    /*
     for(size_t i{0} ; i < 100 ; ++i){
         try{
             int * data = new int[1000000000];
         }catch(exception& ex){
             cout << "  Something went wrong : " << ex.what() << endl;
         }
     }
     */

    // nothrow
    //  for(size_t i{0} ; i < 100 ; ++i){

    //     int * data = new(nothrow) int[1000000000];

    //     if(data!=nullptr){
    //         cout << "Data allocated" << endl;
    //     }else{
    //         cout << "Data allocation failed" << endl;
    //     }

    // }
    // real use of physical memeroy 
    for (size_t i{0}; i < 10; ++i)
    { // Reduced iterations
        int *data = new (nothrow) int[1000000000];
        if (data != nullptr)
        {
            cout << "Allocation " << i + 1 << " succeeded, writing data..." << endl;

            // Actually USE the memory - this will consume physical RAM
            for (size_t j = 0; j < 1000000000; ++j)
            {
                data[j] = static_cast<int>(j % 1000);
            }
            cout << "Data written to allocation " << i + 1 << endl;

            // Still a leak - should call delete[] data here
        }
        else
        {
            cout << "Allocation " << i + 1 << " failed" << endl;
        }
    }

    cout << "Program ending well" << endl;

    return 0;
}