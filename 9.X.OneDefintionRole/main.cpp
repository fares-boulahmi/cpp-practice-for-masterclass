#include <iostream>
#include "../9.X.OneDefintionRole/person.h"
using namespace std;

double weight{};

double add(double a, double b);

struct Point
{
    double m_x{};
    double m_y{};
    double add(double a, double b)
    {
        return a + b;
    }
};

int main()
{
    const double result = add(10.0, 30.0);
    cout << "result is :" << result << endl;
    Point p1;
    // p1.m_x = 17;
    // p1.m_y = 13;
    cout << "enter the y value " << endl;
    cin >> p1.m_y;
    cout << "enter the x value " << endl;
    cin >> p1.m_x;
    cout << "the p1 add is " << p1.add(p1.m_x, p1.m_y) << endl;

    Person p2("john wich" , 35);
    p2.print_info();
    return 0;
}

double add(double a, double b)
{
    return a + b;
}