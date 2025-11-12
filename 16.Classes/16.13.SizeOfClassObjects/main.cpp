#include <iostream>
using namespace std;

class Dog
{
public:
    Dog() = default;
    void prin_info()
    {
    }
    void do_something()
    {
    }

private:
    size_t leg_count; // 8
    size_t arm_count; // 8
    int *p_age;       // 8
};

int main()
{

    Dog dog1;
    cout << "sizeof(size_t) : " << sizeof(size_t) << endl;
    cout << "sizeof(int*) : " << sizeof(int *) << endl;
    cout << "sizeof(Dog) : " << sizeof(dog1) << endl;

    string name{"I am the king of the universe!"};

    cout << "sizeof(name) : " << sizeof(name) << endl;

    return 0;
}