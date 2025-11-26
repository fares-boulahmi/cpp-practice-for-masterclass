#include "Student.h"

Student::Student(string n)
{
    // TODO: Implement constructor
    // Hint: Initialize name, grades vector is automatically initialized
    this->name = n;
    this->grades = {};
}

void Student::addGrade(int grade)
{
    // TODO: Implement adding grade to vector
    // Hint: Use push_back()
    this->grades.push_back(grade);
}

double Student::getAverage()
{
    // TODO: Implement average calculation
    // Hint: Sum all grades and divide by size()
    if (this->grades.size() == 0)
        return 0;
    double sum{};
    for (size_t i = 0; i < this->grades.size(); i++)
    {
        sum += this->grades[i];
    }
    double total = this->grades.size();

    return sum / total;
}

char Student::getLetterGrade()
{
    // TODO: Implement letter grade determination
    // Hint: Use getAverage() and if-else statements
    int grade = this->getAverage();
    if (grade >= 90)
    {
        return 'A';
    }
    else if (grade >= 80 && grade <= 89)
    {
        return 'B';
    }
    else if (grade >= 70 && grade <= 79)
    {
        return 'C';
    }
    else if (grade >= 60 && grade <= 69)
    {
        return 'D';
    }
    else
    {
        return 'F';
    }
}

int Student::getHighestGrade()
{
    // TODO: Implement finding maximum grade
    // Hint: Loop through grades vector
    if (this->grades.size() == 0)
        return 0;
    int max = this->grades[0];
    for (size_t i = 1; i < this->grades.size(); i++)
    {
        if (this->grades[i] > max)
        {
            max = this->grades[i];
        }
    }
    return max;
}

int Student::getLowestGrade()
{
    // TODO: Implement finding minimum grade
    // Hint: Loop through grades vector
    if (this->grades.size() == 0)
        return 0;
    int min = this->grades[0];
    for (size_t i = 1; i < this->grades.size(); i++)
    {
        if (this->grades[i] < min)
        {
            min = this->grades[i];
        }
    }
    return min;
}
