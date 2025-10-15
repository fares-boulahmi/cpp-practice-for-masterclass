#include <iostream>
#include <vector>
using namespace std;

void testing(bool go , bool stop , vector<int> arr) {
    if (go) {
        int goTime{};
        for ( int i{} ; i <= arr.size() ; i++) {
            goTime += 2;
        }
        cout << "go time add by two ended is :" << goTime << endl;
    } else if (stop)
    {
        int stopTime{};
        for ( int i{} ; i <= arr.size() ; i++) {
            stopTime += 1;
        }
        cout << "stop time decrease  ended is :" << stopTime << endl;
    } else {
        cout << "no go or stop was declaire this time" << endl;
    }
    
}
void trueFalse(bool go , bool stop , vector<int> arr) {

    cout << "--------------------" << endl;
    cout << "trying with the true and false " << endl;
    cin >> boolalpha >> go ;
    testing(go , stop , arr);
    go = false;
    cin >> boolalpha >> stop ;
    testing(go , stop , arr);
    stop = false;
    cin >> boolalpha >> go ;
    cin >> boolalpha >> stop ;
    testing(go , stop , arr);

}
void zeroOne(bool go , bool stop , vector<int> arr) {

    cout << "--------------------" << endl;
    cout << "trying with the 0 and 1 " << endl;
    cin >> noboolalpha >> go ;// stop boolalpha from work 
    cout << "go is :" << go << " and stop is :" << stop  << endl;
    testing(go , stop , arr);
    go = false;
    cin >> stop ;
    testing(go , stop , arr);
    stop = false;
    cin >> go ;
    cin >> stop ;
    testing(go , stop , arr);

}

void lessonCode() {
    bool red_light {false};
    bool green_light{true};
    
    if(red_light == true){
        cout << "Stop!" << endl;
    }else{
        cout << "Go through!" << endl;
    }

    if(green_light){
        cout << "The light is green!" << endl;
    }else{
        cout << "The light is NOT green!" << endl;
    }

    //sizeof()
    cout << "sizeof(bool) : " << sizeof(bool) << endl;


    //Printing out a bool
    //1 -->> true
    //0 -->> false
    cout << endl;
    cout << "red_light : " << red_light << endl;
    cout << "green_light : " << green_light << endl;

    cout << boolalpha;
    cout << "red_light : " << red_light << endl;
    cout << "green_light : " << green_light << endl;
}
int main() {
    vector<int> arr = { 1,2,8,5,6,3,8,2,8,6};
    bool go {true};
    bool stop {false};
    bool lesson {false};

    cout << "type true to go with lesson code or type false to go with your own code " << endl;

    cin >> boolalpha >> lesson ;

    if (lesson)
    {
        lessonCode();
    }
    else
    {
        
        zeroOne(go , stop , arr); // must the zero one be first cause the boolalpha is effect everything type in terminal

        trueFalse(go , stop , arr);
    }
    

    
    return 0;
}