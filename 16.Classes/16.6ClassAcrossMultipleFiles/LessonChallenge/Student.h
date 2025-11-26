#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <vector>
using namespace std;
class Student
{
private:
    string name;
    vector<int> grades;

public:
    Student(string n);
    void addGrade(int grade);
    double getAverage();
    char getLetterGrade();
    int getHighestGrade();
    int getLowestGrade();
};
#endif