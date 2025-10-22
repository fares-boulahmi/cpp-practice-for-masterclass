#ifndef PERSON_H
#define PERSON_H

#include <iostream>

using namespace std;

class Person
{
public:

    Person(const string &names_param, int age_param);

    void print_info() const
    {
        cout << "name : " << full_name << ", age : " << age << endl;
    }

private:
    string full_name;
    int age;

public:
    static int person_count;
};

#endif
