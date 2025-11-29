#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// ============================================================================
// Problem 1: Easy 1 - Protected Grade Manager
// ============================================================================
// Description:
// Create a base class 'Student' with a protected member 'grades' (vector of int).
// Create a derived class 'GradeCalculator' that can access and calculate the
// average of the protected grades.
//
// Input Format:
// - Number of grades (n)
// - n grade values (integers between 0-100)
//
// Output Format:
// - Average grade as a double (rounded to 2 decimal places)
//
// Example 1:
// Input: grades = {85, 90, 78}
// Output: 84.33
// Explanation: (85 + 90 + 78) / 3 = 253 / 3 = 84.333...
//
// Example 2:
// Input: grades = {100}
// Output: 100.00
// Explanation: Single grade, average is itself
//
// Constraints:
// - 1 <= n <= 100
// - 0 <= grade <= 100

class Student
{
protected:
    vector<int> grades;

public:
    Student(vector<int> g) : grades(g) {}
};

class GradeCalculator : public Student
{
public:
    GradeCalculator(vector<int> g) : Student(g) {}

    double calculateAverage()
    {
        // TODO: Implement your solution here using protected members
        // Hint: Access the protected 'grades' vector from the base class
        // and calculate the sum divided by count
        if (this->grades.size() == 0)
            return 0;
        double sum{};
        double total = this->grades.size();
        for (size_t i = 0; i < this->grades.size(); i++)
        {
            sum += this->grades[i];
        }
        return sum / total;
    }
};

double problem1Solution(vector<int> grades)
{
    // TODO: Create a GradeCalculator object and return the average
    // Hint: Use the GradeCalculator class and call calculateAverage()
    GradeCalculator gradeCalculator(grades);
    return gradeCalculator.calculateAverage();
}

// ============================================================================
// Problem 2: Easy 2 - Protected Bank Account Hierarchy
// ============================================================================
// Description:
// Create a base class 'BankAccount' with protected members: balance (double)
// and accountHolder (string). Create a derived class 'SavingsAccount' that
// adds interest to the balance. The derived class should access the protected
// balance to calculate and add interest.
//
// Input Format:
// - Initial balance (double)
// - Account holder name (string)
// - Interest rate (double, as percentage, e.g., 5.0 for 5%)
//
// Output Format:
// - New balance after interest is added (rounded to 2 decimal places)
//
// Example 1:
// Input: balance = 1000.0, rate = 5.0
// Output: 1050.00
// Explanation: 1000 + (1000 * 5.0 / 100) = 1000 + 50 = 1050.00
//
// Example 2:
// Input: balance = 500.0, rate = 10.0
// Output: 550.00
// Explanation: 500 + (500 * 10.0 / 100) = 500 + 50 = 550.00
//
// Constraints:
// - 0 <= balance <= 1000000
// - 0 <= rate <= 100

class BankAccount
{
protected:
    double balance;
    string accountHolder;

public:
    BankAccount(double bal, string holder) : balance(bal), accountHolder(holder) {}
};

class SavingsAccount : public BankAccount
{
public:
    SavingsAccount(double bal, string holder) : BankAccount(bal, holder) {}

    double addInterest(double rate)
    {
        // TODO: Implement your solution here using protected members
        // Hint: Access protected 'balance', calculate interest, add it to balance
        // Interest = balance * (rate / 100)
        return 0;
    }
};

double problem2Solution(double balance, string holder, double rate)
{
    // TODO: Create a SavingsAccount object and return balance after interest
    // Hint: Create SavingsAccount, call addInterest(), return the result
    return 0;
}

// ============================================================================
// Problem 3: Medium - Protected Shape Dimension Validator
// ============================================================================
// Description:
// Create a base class 'Shape' with protected members: width (double) and
// height (double). Create derived classes 'Rectangle' and 'Triangle' that
// validate their dimensions differently. Rectangle needs both width and height
// to be positive. Triangle needs width + height to be less than a given
// perimeter constraint, and both must be positive.
//
// Input Format:
// - Shape type (1 for Rectangle, 2 for Triangle)
// - Width (double)
// - Height (double)
// - For Triangle: perimeter constraint (double)
//
// Output Format:
// - Return 1 if valid, 0 if invalid
//
// Example 1:
// Input: Rectangle, width = 5.0, height = 10.0
// Output: 1
// Explanation: Both dimensions positive, valid rectangle
//
// Example 2:
// Input: Rectangle, width = -5.0, height = 10.0
// Output: 0
// Explanation: Width is negative, invalid
//
// Example 3:
// Input: Triangle, width = 3.0, height = 4.0, perimeter = 20.0
// Output: 1
// Explanation: 3 + 4 = 7 < 20, and both positive, valid
//
// Example 4:
// Input: Triangle, width = 10.0, height = 15.0, perimeter = 20.0
// Output: 0
// Explanation: 10 + 15 = 25 > 20, exceeds perimeter constraint
//
// Constraints:
// - -1000 <= width, height <= 1000
// - For triangle: 0 < perimeter <= 1000

class Shape
{
protected:
    double width;
    double height;

public:
    Shape(double w, double h) : width(w), height(h) {}
};

class Rectangle : public Shape
{
public:
    Rectangle(double w, double h) : Shape(w, h) {}

    int isValid()
    {
        // TODO: Implement validation for rectangle
        // Hint: Check if both protected width and height are positive
        return 0;
    }
};

class Triangle : public Shape
{
private:
    double perimeterConstraint;

public:
    Triangle(double w, double h, double perimeter) : Shape(w, h), perimeterConstraint(perimeter) {}

    int isValid()
    {
        // TODO: Implement validation for triangle
        // Hint: Check if both dimensions positive AND width + height < perimeterConstraint
        return 0;
    }
};

int problem3Solution(int shapeType, double width, double height, double perimeter = 0)
{
    // TODO: Create appropriate shape object and return validation result
    // Hint: Use shapeType to decide between Rectangle (1) or Triangle (2)
    return 0;
}

// ============================================================================
// Problem 4: Hard - Protected Multi-Level Inheritance: Employee Bonus System
// ============================================================================
// Description:
// Create a 3-level inheritance hierarchy:
// 1. Base class 'Person' with protected: name (string), age (int)
// 2. Derived class 'Employee' with protected: baseSalary (double), yearsOfService (int)
// 3. Derived class 'Manager' with protected: teamSize (int)
//
// Calculate total compensation:
// - Base salary
// - Service bonus: 2% of base salary per year of service
// - Age bonus: If age >= 50, add 5% of base salary
// - Management bonus: If teamSize > 5, add 10% of base salary; if teamSize > 10, add 15%
//
// Input Format:
// - Name (string)
// - Age (int)
// - Base salary (double)
// - Years of service (int)
// - Team size (int)
//
// Output Format:
// - Total compensation (double, rounded to 2 decimal places)
//
// Example 1:
// Input: name = "John", age = 45, baseSalary = 50000, yearsOfService = 10, teamSize = 3
// Calculation:
//   Base: 50000
//   Service bonus: 50000 * 0.02 * 10 = 50000 * 0.20 = 10000
//   Age bonus: 0 (age < 50)
//   Management bonus: 0 (teamSize <= 5)
//   Total: 50000 + 10000 = 60000.00
// Output: 60000.00
//
// Example 2:
// Input: name = "Alice", age = 52, baseSalary = 80000, yearsOfService = 15, teamSize = 12
// Calculation:
//   Base: 80000
//   Service bonus: 80000 * 0.02 * 15 = 80000 * 0.30 = 24000
//   Age bonus: 80000 * 0.05 = 4000 (age >= 50)
//   Management bonus: 80000 * 0.15 = 12000 (teamSize > 10)
//   Total: 80000 + 24000 + 4000 + 12000 = 120000.00
// Output: 120000.00
//
// Constraints:
// - Age: 18-100
// - Base salary: 10000-1000000
// - Years of service: 0-50
// - Team size: 0-100

class Person
{
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}
};

class Employee : public Person
{
protected:
    double baseSalary;
    int yearsOfService;

public:
    Employee(string n, int a, double salary, int years)
        : Person(n, a), baseSalary(salary), yearsOfService(years) {}
};

class Manager : public Employee
{
protected:
    int teamSize;

public:
    Manager(string n, int a, double salary, int years, int team)
        : Employee(n, a, salary, years), teamSize(team) {}

    double calculateTotalCompensation()
    {
        // TODO: Implement total compensation calculation
        // Hint: Access all protected members from the inheritance chain
        // Calculate each bonus component and sum them with base salary
        return 0;
    }
};

double problem4Solution(string name, int age, double baseSalary, int yearsOfService, int teamSize)
{
    // TODO: Create Manager object and return total compensation
    // Hint: Create Manager with all parameters, call calculateTotalCompensation()
    return 0;
}

// ============================================================================
// TEST FUNCTIONS
// ============================================================================

void testProblem1()
{
    cout << "\n=== Testing Problem 1: Protected Grade Manager ===" << endl;

    // Test Case 1: Normal case with 3 grades
    // Calculation: (85 + 90 + 78) / 3 = 253 / 3 = 84.333...
    vector<int> test1 = {85, 90, 78};
    double expected1 = 84.33;
    double result1 = problem1Solution(test1);
    cout << "Test 1 - Three grades {85,90,78}: "
         << (abs(result1 - expected1) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: " << fixed << setprecision(2) << expected1
         << ", Got: " << result1 << ")" << endl;

    // Test Case 2: Single grade
    // Calculation: 100 / 1 = 100.00
    vector<int> test2 = {100};
    double expected2 = 100.00;
    double result2 = problem1Solution(test2);
    cout << "Test 2 - Single grade {100}: "
         << (abs(result2 - expected2) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: " << expected2 << ", Got: " << result2 << ")" << endl;

    // Test Case 3: All same grades
    // Calculation: (75 + 75 + 75 + 75) / 4 = 300 / 4 = 75.00
    vector<int> test3 = {75, 75, 75, 75};
    double expected3 = 75.00;
    double result3 = problem1Solution(test3);
    cout << "Test 3 - All same {75,75,75,75}: "
         << (abs(result3 - expected3) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: " << expected3 << ", Got: " << result3 << ")" << endl;

    // Test Case 4: Mix of high and low grades
    // Calculation: (100 + 0 + 50) / 3 = 150 / 3 = 50.00
    vector<int> test4 = {100, 0, 50};
    double expected4 = 50.00;
    double result4 = problem1Solution(test4);
    cout << "Test 4 - Mix {100,0,50}: "
         << (abs(result4 - expected4) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: " << expected4 << ", Got: " << result4 << ")" << endl;

    // Test Case 5: Five grades
    // Calculation: (88 + 92 + 76 + 85 + 90) / 5 = 431 / 5 = 86.20
    vector<int> test5 = {88, 92, 76, 85, 90};
    double expected5 = 86.20;
    double result5 = problem1Solution(test5);
    cout << "Test 5 - Five grades {88,92,76,85,90}: "
         << (abs(result5 - expected5) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: " << expected5 << ", Got: " << result5 << ")" << endl;

    // Test Case 6: Two grades
    // Calculation: (65 + 95) / 2 = 160 / 2 = 80.00
    vector<int> test6 = {65, 95};
    double expected6 = 80.00;
    double result6 = problem1Solution(test6);
    cout << "Test 6 - Two grades {65,95}: "
         << (abs(result6 - expected6) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: " << expected6 << ", Got: " << result6 << ")" << endl;

    // Test Case 7: All zeros (edge case)
    // Calculation: (0 + 0 + 0) / 3 = 0 / 3 = 0.00
    vector<int> test7 = {0, 0, 0};
    double expected7 = 0.00;
    double result7 = problem1Solution(test7);
    cout << "Test 7 - All zeros {0,0,0}: "
         << (abs(result7 - expected7) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: " << expected7 << ", Got: " << result7 << ")" << endl;

    // Test Case 8: Six grades with decimal result
    // Calculation: (70 + 80 + 85 + 90 + 75 + 95) / 6 = 495 / 6 = 82.50
    vector<int> test8 = {70, 80, 85, 90, 75, 95};
    double expected8 = 82.50;
    double result8 = problem1Solution(test8);
    cout << "Test 8 - Six grades {70,80,85,90,75,95}: "
         << (abs(result8 - expected8) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: " << expected8 << ", Got: " << result8 << ")" << endl;
}

void testProblem2()
{
    cout << "\n=== Testing Problem 2: Protected Bank Account Hierarchy ===" << endl;

    // Test Case 1: Normal case
    // Calculation: 1000 + (1000 * 5.0 / 100) = 1000 + 50 = 1050.00
    double result1 = problem2Solution(1000.0, "John", 5.0);
    double expected1 = 1050.00;
    cout << "Test 1 - Balance 1000, Rate 5%: "
         << (abs(result1 - expected1) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: " << fixed << setprecision(2) << expected1
         << ", Got: " << result1 << ")" << endl;

    // Test Case 2: Different rate
    // Calculation: 500 + (500 * 10.0 / 100) = 500 + 50 = 550.00
    double result2 = problem2Solution(500.0, "Alice", 10.0);
    double expected2 = 550.00;
    cout << "Test 2 - Balance 500, Rate 10%: "
         << (abs(result2 - expected2) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: " << expected2 << ", Got: " << result2 << ")" << endl;

    // Test Case 3: Zero interest rate
    // Calculation: 1500 + (1500 * 0.0 / 100) = 1500 + 0 = 1500.00
    double result3 = problem2Solution(1500.0, "Bob", 0.0);
    double expected3 = 1500.00;
    cout << "Test 3 - Balance 1500, Rate 0%: "
         << (abs(result3 - expected3) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: " << expected3 << ", Got: " << result3 << ")" << endl;

    // Test Case 4: Small balance
    // Calculation: 100 + (100 * 3.0 / 100) = 100 + 3 = 103.00
    double result4 = problem2Solution(100.0, "Charlie", 3.0);
    double expected4 = 103.00;
    cout << "Test 4 - Balance 100, Rate 3%: "
         << (abs(result4 - expected4) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: " << expected4 << ", Got: " << result4 << ")" << endl;

    // Test Case 5: Large balance
    // Calculation: 10000 + (10000 * 2.5 / 100) = 10000 + 250 = 10250.00
    double result5 = problem2Solution(10000.0, "Diana", 2.5);
    double expected5 = 10250.00;
    cout << "Test 5 - Balance 10000, Rate 2.5%: "
         << (abs(result5 - expected5) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: " << expected5 << ", Got: " << result5 << ")" << endl;

    // Test Case 6: High interest rate
    // Calculation: 2000 + (2000 * 15.0 / 100) = 2000 + 300 = 2300.00
    double result6 = problem2Solution(2000.0, "Eve", 15.0);
    double expected6 = 2300.00;
    cout << "Test 6 - Balance 2000, Rate 15%: "
         << (abs(result6 - expected6) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: " << expected6 << ", Got: " << result6 << ")" << endl;

    // Test Case 7: Fractional result
    // Calculation: 333.33 + (333.33 * 5.0 / 100) = 333.33 + 16.6665 = 349.9965 ≈ 350.00
    double result7 = problem2Solution(333.33, "Frank", 5.0);
    double expected7 = 350.00;
    cout << "Test 7 - Balance 333.33, Rate 5%: "
         << (abs(result7 - expected7) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: " << expected7 << ", Got: " << result7 << ")" << endl;

    // Test Case 8: 1% interest
    // Calculation: 5000 + (5000 * 1.0 / 100) = 5000 + 50 = 5050.00
    double result8 = problem2Solution(5000.0, "Grace", 1.0);
    double expected8 = 5050.00;
    cout << "Test 8 - Balance 5000, Rate 1%: "
         << (abs(result8 - expected8) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: " << expected8 << ", Got: " << result8 << ")" << endl;
}

void testProblem3()
{
    cout << "\n=== Testing Problem 3: Protected Shape Dimension Validator ===" << endl;

    // Test Case 1: Valid rectangle
    // Both dimensions positive: 5.0 > 0 and 10.0 > 0 → Valid (1)
    int result1 = problem3Solution(1, 5.0, 10.0);
    int expected1 = 1;
    cout << "Test 1 - Rectangle (5,10): "
         << (result1 == expected1 ? "PASS" : "FAIL")
         << " (Expected: " << expected1 << ", Got: " << result1 << ")" << endl;

    // Test Case 2: Invalid rectangle (negative width)
    // Width negative: -5.0 < 0 → Invalid (0)
    int result2 = problem3Solution(1, -5.0, 10.0);
    int expected2 = 0;
    cout << "Test 2 - Rectangle (-5,10): "
         << (result2 == expected2 ? "PASS" : "FAIL")
         << " (Expected: " << expected2 << ", Got: " << result2 << ")" << endl;

    // Test Case 3: Invalid rectangle (negative height)
    // Height negative: -8.0 < 0 → Invalid (0)
    int result3 = problem3Solution(1, 5.0, -8.0);
    int expected3 = 0;
    cout << "Test 3 - Rectangle (5,-8): "
         << (result3 == expected3 ? "PASS" : "FAIL")
         << " (Expected: " << expected3 << ", Got: " << result3 << ")" << endl;

    // Test Case 4: Valid triangle
    // 3 + 4 = 7 < 20 and both positive → Valid (1)
    int result4 = problem3Solution(2, 3.0, 4.0, 20.0);
    int expected4 = 1;
    cout << "Test 4 - Triangle (3,4) perimeter 20: "
         << (result4 == expected4 ? "PASS" : "FAIL")
         << " (Expected: " << expected4 << ", Got: " << result4 << ")" << endl;

    // Test Case 5: Invalid triangle (exceeds perimeter)
    // 10 + 15 = 25 > 20 → Invalid (0)
    int result5 = problem3Solution(2, 10.0, 15.0, 20.0);
    int expected5 = 0;
    cout << "Test 5 - Triangle (10,15) perimeter 20: "
         << (result5 == expected5 ? "PASS" : "FAIL")
         << " (Expected: " << expected5 << ", Got: " << result5 << ")" << endl;

    // Test Case 6: Invalid triangle (negative width)
    // Width negative → Invalid (0)
    int result6 = problem3Solution(2, -3.0, 4.0, 20.0);
    int expected6 = 0;
    cout << "Test 6 - Triangle (-3,4) perimeter 20: "
         << (result6 == expected6 ? "PASS" : "FAIL")
         << " (Expected: " << expected6 << ", Got: " << result6 << ")" << endl;

    // Test Case 7: Rectangle with zero dimension
    // Width is 0, not positive → Invalid (0)
    int result7 = problem3Solution(1, 0.0, 10.0);
    int expected7 = 0;
    cout << "Test 7 - Rectangle (0,10): "
         << (result7 == expected7 ? "PASS" : "FAIL")
         << " (Expected: " << expected7 << ", Got: " << result7 << ")" << endl;

    // Test Case 8: Triangle exactly at perimeter boundary
    // 8 + 12 = 20, not less than 20 → Invalid (0)
    int result8 = problem3Solution(2, 8.0, 12.0, 20.0);
    int expected8 = 0;
    cout << "Test 8 - Triangle (8,12) perimeter 20 (boundary): "
         << (result8 == expected8 ? "PASS" : "FAIL")
         << " (Expected: " << expected8 << ", Got: " << result8 << ")" << endl;
}

void testProblem4()
{
    cout << "\n=== Testing Problem 4: Protected Multi-Level Inheritance ===" << endl;

    // Test Case 1: Basic case, no age or management bonus
    // Base: 50000
    // Service: 50000 * 0.02 * 10 = 10000
    // Age: 0 (45 < 50)
    // Management: 0 (3 <= 5)
    // Total: 50000 + 10000 = 60000.00
    double result1 = problem4Solution("John", 45, 50000, 10, 3);
    double expected1 = 60000.00;
    cout << "Test 1 - Age 45, 10 years, team 3: "
         << (abs(result1 - expected1) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: " << fixed << setprecision(2) << expected1
         << ", Got: " << result1 << ")" << endl;

    // Test Case 2: All bonuses apply
    // Base: 80000
    // Service: 80000 * 0.02 * 15 = 24000
    // Age: 80000 * 0.05 = 4000 (52 >= 50)
    // Management: 80000 * 0.15 = 12000 (12 > 10)
    // Total: 80000 + 24000 + 4000 + 12000 = 120000.00
    double result2 = problem4Solution("Alice", 52, 80000, 15, 12);
    double expected2 = 120000.00;
    cout << "Test 2 - Age 52, 15 years, team 12: "
         << (abs(result2 - expected2) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: " << expected2 << ", Got: " << result2 << ")" << endl;

    // Test Case 3: Zero years of service
    // Base: 40000
    // Service: 40000 * 0.02 * 0 = 0
    // Age: 0 (30 < 50)
    // Management: 0 (2 <= 5)
    // Total: 40000 + 0 = 40000.00
    double result3 = problem4Solution("Bob", 30, 40000, 0, 2);
    double expected3 = 40000.00;
    cout << "Test 3 - Age 30, 0 years, team 2: "
         << (abs(result3 - expected3) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: " << expected3 << ", Got: " << result3 << ")" << endl;

    // Test Case 4: Age bonus exactly at boundary (50)
    // Base: 60000
    // Service: 60000 * 0.02 * 5 = 6000
    // Age: 60000 * 0.05 = 3000 (50 >= 50)
    // Management: 0 (4 <= 5)
    // Total: 60000 + 6000 + 3000 = 69000.00
    double result4 = problem4Solution("Charlie", 50, 60000, 5, 4);
    double expected4 = 69000.00;
    cout << "Test 4 - Age 50 (boundary), 5 years, team 4: "
         << (abs(result4 - expected4) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: " << expected4 << ", Got: " << result4 << ")" << endl;

    // Test Case 5: Team size exactly 6 (should get 10% bonus)
    // Base: 70000
    // Service: 70000 * 0.02 * 8 = 11200
    // Age: 0 (40 < 50)
    // Management: 70000 * 0.10 = 7000 (6 > 5)
    // Total: 70000 + 11200 + 7000 = 88200.00
    double result5 = problem4Solution("Diana", 40, 70000, 8, 6);
    double expected5 = 88200.00;
    cout << "Test 5 - Age 40, 8 years, team 6 (>5): "
         << (abs(result5 - expected5) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: " << expected5 << ", Got: " << result5 << ")" << endl;

    // Test Case 6: Team size exactly 11 (should get 15% bonus)
    // Base: 90000
    // Service: 90000 * 0.02 * 20 = 36000
    // Age: 90000 * 0.05 = 4500 (55 >= 50)
    // Management: 90000 * 0.15 = 13500 (11 > 10)
    // Total: 90000 + 36000 + 4500 + 13500 = 144000.00
    double result6 = problem4Solution("Eve", 55, 90000, 20, 11);
    double expected6 = 144000.00;
    cout << "Test 6 - Age 55, 20 years, team 11 (>10): "
         << (abs(result6 - expected6) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: " << expected6 << ", Got: " << result6 << ")" << endl;

    // Test Case 7: Large years of service
    // Base: 100000
    // Service: 100000 * 0.02 * 25 = 50000
    // Age: 100000 * 0.05 = 5000 (60 >= 50)
    // Management: 100000 * 0.10 = 10000 (8 > 5 but not > 10)
    // Total: 100000 + 50000 + 5000 + 10000 = 165000.00
    double result7 = problem4Solution("Frank", 60, 100000, 25, 8);
    double expected7 = 165000.00;
    cout << "Test 7 - Age 60, 25 years, team 8: "
         << (abs(result7 - expected7) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: " << expected7 << ", Got: " << result7 << ")" << endl;

    // Test Case 8: Minimum values
    // Base: 30000
    // Service: 30000 * 0.02 * 1 = 600
    // Age: 0 (25 < 50)
    // Management: 0 (0 <= 5)
    // Total: 30000 + 600 = 30600.00
    double result8 = problem4Solution("Grace", 25, 30000, 1, 0);
    double expected8 = 30600.00;
    cout << "Test 8 - Age 25, 1 year, team 0: "
         << (abs(result8 - expected8) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: " << expected8 << ", Got: " << result8 << ")" << endl;
}

// ============================================================================
// MAIN FUNCTION
// ============================================================================

int main()
{
    int choice;
    cout << "=====================================================" << endl;
    cout << "   C++ Protected Members Practice Problems" << endl;
    cout << "=====================================================" << endl;
    cout << "Choose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy) - Protected Grade Manager" << endl;
    cout << "2. Problem 2 (Easy) - Protected Bank Account Hierarchy" << endl;
    cout << "3. Problem 3 (Medium) - Protected Shape Dimension Validator" << endl;
    cout << "4. Problem 4 (Hard) - Protected Multi-Level Inheritance" << endl;
    cout << "5. Test All Problems" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        testProblem1();
        break;
    case 2:
        testProblem2();
        break;
    case 3:
        testProblem3();
        break;
    case 4:
        testProblem4();
        break;
    case 5:
        testProblem1();
        testProblem2();
        testProblem3();
        testProblem4();
        break;
    default:
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
