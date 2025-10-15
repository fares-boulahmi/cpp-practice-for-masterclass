#include <iostream>
#include <vector>
#include <string>
using namespace std;

int chaos(vector<int> arr)
{
    int result = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        result += arr[i];
    }
    return result / arr.size();
}

int main()
{

    int type{0};

    cout << "type 1 to show the chaos function just some the arr number and divide by the size " << endl;
    cout << "type 2 to show the getline of how can type more than word and show in in dynamic result " << endl;
    cout << "type 3 to show the clog (log ) cerr (error ) message  " << endl;
    cout << "type 4 to show the input accept value  " << endl;
    cout << "type 5 to show all above  " << endl;
    cout << "type anything else to show nothing " << endl;

    cin >> type ;

    if (type == 1)
    {
        cout << "the chaos function return is :" << chaos({4, 854, 545, 4, 544, 5, 44, 686, 94, 98, 498, 4, 6}) << endl;
        cout << "the second  chaos function return is :" << chaos({4, 854, 545, 4, 686, 545, 4, 544, 94, 98, 498, 4, 6}) << endl;
    }
    else if (type == 2)
    {
        cout << "now realy type your full name" << endl;
        string full_name;
        getline(cin, full_name);
        // cin >> full_name;

        cout << "your ful name is " << full_name << endl;
    }
    else if (type == 3)
    {
        /*
    in terminal support the colorise and different type message
    the clog will show as log and
    the cerr will show as error
    */
        clog << "log message : testing clog what reurn " << endl;
        cerr << "error message :testing cerr what reurn " << endl;
        // cin << "testing cin what reurn " << endl;
    }
    else if (type == 4)
    {
        int age{18};
        string name;
        cout << "please type your name" << endl;
        cin >> name;

        cout << "please type your age " << endl;
        cin >> age;

        cout << "hay " << name << "is this realy your age " << age << "you old go and retire " << endl;

        cout << "hay old wall type your name with charecter not number and your age with number in same line with spaces don't be dumb just make it easy " << endl;

        cin >> name >> age;

        cout << "haha you name is : " << name << " and your old is : " << age << " good for you but that wierd "  << endl;
    }
    else if (type == 5)
    {
        cout << "chaos start" << endl;

        cout << "the chaos function return is :" << chaos({4, 854, 545, 4, 544, 5, 44, 686, 94, 98, 498, 4, 6}) << endl;
        cout << "the second  chaos function return is :" << chaos({4, 854, 545, 4, 686, 545, 4, 544, 94, 98, 498, 4, 6}) << endl;

        cout << "getline start" << endl;
        cout << "now realy type your full name" << endl;
        string full_name;
        getline(cin, full_name);
        // cin >> full_name;

        cout << "your ful name is " << full_name << endl;
        cout << "clog ,  cerr start" << endl;

        /*
          in terminal support the colorise and different type message
          the clog will show as log and
          the cerr will show as error
          */
        clog << "log message : testing clog what reurn " << endl;
        cerr << "error message :testing cerr what reurn " << endl;
        // cin << "testing cin what reurn " << endl;

        cout << "input accept value start" << endl;

        int age{18};
        string name;
        cout << "please type your name" << endl;
        cin >> name;

        cout << "please type your age " << endl;
        cin >> age;

        cout << "hay " << name << "is this realy your age " << age << "you old go and retire " << endl;

        cout << "hay old wall type your name with charecter not number and your age with number in same line with spaces don't be dumb just make it easy " << endl;

        cin >> name >> age;

        cout << "haha you name is : " << name << " and your old is : " << age << " good for you but that wierd is that realy your full name " << full_name << endl;
    }
    else
    {
        cout << "you didn't choose anything above " << endl;
    }

    return 0;
}