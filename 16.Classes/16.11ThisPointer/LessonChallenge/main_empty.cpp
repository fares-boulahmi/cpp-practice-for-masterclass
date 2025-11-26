#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

// ============================================================================
// Problem 1: Easy 1 - Point Distance Calculator
// ============================================================================
// Description:
// Create a Point class that represents a 2D point with x and y coordinates.
// Implement a method that calculates the distance from THIS point to another point.
// Use the this pointer to explicitly access the current object's members.
//
// Input Format:
// - Current point coordinates (x1, y1)
// - Other point coordinates (x2, y2)
//
// Output Format:
// - Distance as a double value
//
// Formula: distance = sqrt((x2-x1)^2 + (y2-y1)^2)
//
// Example 1:
// Point p1(0, 0), p2(3, 4)
// p1.distanceTo(p2) should return 5.0
// Calculation: sqrt((3-0)^2 + (4-0)^2) = sqrt(9+16) = sqrt(25) = 5.0
//
// Example 2:
// Point p1(1, 1), p2(4, 5)
// p1.distanceTo(p2) should return 5.0
// Calculation: sqrt((4-1)^2 + (5-1)^2) = sqrt(9+16) = sqrt(25) = 5.0
//
// Constraints:
// - Coordinates are integers between -1000 and 1000
// - Use this-> to access member variables

class Point
{
private:
    int x;
    int y;

public:
    Point(int xVal, int yVal) : x(xVal), y(yVal)
    {

    }

    double distanceTo(const Point &other)
    {
        // TODO: Implement using the this pointer to access x and y
        // Hint: Use this->x and this->y to calculate distance
        // Formula: sqrt((other.x - this->x)^2 + (other.y - this->y)^2)
        // cout << "other x " << other.getX() << " this x is " << this->x << endl;
        // cout << "other y " << other.getY() << " this y is " << this->y << endl;

        return 0;
    }

    int getX() const { return x; }
    int getY() const { return y; }
};

// ============================================================================
// Problem 2: Easy 2 - Method Chaining with Bank Account
// ============================================================================
// Description:
// Create a BankAccount class that supports method chaining for deposit and withdraw.
// Each method should return a reference to the current object using *this.
// This allows calling multiple operations in a single line: account.deposit(100).withdraw(50).deposit(25)
//
// Input Format:
// - Initial balance
// - Series of deposit and withdraw operations
//
// Output Format:
// - Final balance after all operations
//
// Example 1:
// BankAccount acc(100);
// acc.deposit(50).withdraw(30).getBalance() should return 120
// Step-by-step: 100 + 50 = 150, 150 - 30 = 120
//
// Example 2:
// BankAccount acc(0);
// acc.deposit(100).deposit(50).withdraw(25).getBalance() should return 125
// Step-by-step: 0 + 100 = 100, 100 + 50 = 150, 150 - 25 = 125
//
// Constraints:
// - Balance cannot go negative (withdraw should not execute if insufficient funds)
// - All amounts are positive integers

class BankAccount
{
private:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance)
    {
    }

    BankAccount &deposit(double amount)
    {
        // TODO: Add amount to balance and return *this for method chaining
        // Hint: return *this; at the end to enable chaining
        return *this;
    }

    BankAccount &withdraw(double amount)
    {
        // TODO: Subtract amount from balance if sufficient funds, return *this
        // Hint: Check if this->balance >= amount before withdrawing

        return *this;
    }

    double getBalance() const { return balance; }
};

// ============================================================================
// Problem 3: Medium - Employee Comparison System
// ============================================================================
// Description:
// Create an Employee class with name and salary. Implement methods that use
// the this pointer to compare the current employee with another employee.
// Implement: isHigherPaidThan(), hasSameSalaryAs(), and getHigherPaid()
//
// Input Format:
// - Employee name (string)
// - Employee salary (double)
//
// Output Format:
// - Boolean comparison results or pointer to higher paid employee
//
// Example 1:
// Employee e1("Alice", 50000), e2("Bob", 60000)
// e1.isHigherPaidThan(e2) should return false
// e2.isHigherPaidThan(e1) should return true
// e1.hasSameSalaryAs(e2) should return false
//
// Example 2:
// Employee e1("Alice", 50000), e2("Bob", 50000)
// e1.hasSameSalaryAs(e2) should return true
//
// Example 3:
// Employee e1("Alice", 50000), e2("Bob", 60000)
// e1.getHigherPaid(e2) should return pointer to e2
//
// Constraints:
// - Salary is a positive double value
// - Names are non-empty strings

class Employee
{
private:
    string name;
    double salary;

public:
    Employee(string n, double s) : name(n), salary(s) {}

    bool isHigherPaidThan(const Employee &other) const
    {
        // TODO: Compare this employee's salary with other's salary
        // Hint: return this->salary > other.salary;
        return 0;
    }

    bool hasSameSalaryAs(const Employee &other) const
    {
        // TODO: Check if salaries are equal
        // Hint: Use this->salary and other.salary
        return 0;
    }

    const Employee *getHigherPaid(const Employee &other) const
    {
        // TODO: Return pointer to employee with higher salary
        // Hint: if this->salary >= other.salary return this; else return &other;
        return this;
    }

    string getName() const { return name; }
    double getSalary() const { return salary; }
};

// ============================================================================
// Problem 4: Hard - Dynamic String Builder with this Pointer
// ============================================================================
// Description:
// Create a StringBuilder class that builds strings efficiently using method chaining.
// The class should dynamically allocate memory and use the this pointer for all operations.
// Implement: append(), prepend(), clear(), and getString() methods.
// All methods except getString() should return *this for chaining.
//
// Input Format:
// - Series of string operations (append, prepend)
//
// Output Format:
// - Final concatenated string
//
// Example 1:
// StringBuilder sb;
// sb.append("World").prepend("Hello ").append("!").getString()
// Step-by-step:
//   - After append("World"): "World"
//   - After prepend("Hello "): "Hello World"
//   - After append("!"): "Hello World!"
// Output: "Hello World!"
//
// Example 2:
// StringBuilder sb;
// sb.append("C++").append(" is").append(" awesome").getString()
// Step-by-step:
//   - After append("C++"): "C++"
//   - After append(" is"): "C++ is"
//   - After append(" awesome"): "C++ is awesome"
// Output: "C++ is awesome"
//
// Constraints:
// - Must use dynamic memory allocation (new/delete)
// - Must implement proper copy constructor and destructor
// - Strings can be up to 1000 characters

class StringBuilder
{
private:
    char *data;
    size_t length;
    size_t capacity;

    void resize(size_t newCapacity)
    {
        char *newData = new char[newCapacity];
        if (data != nullptr)
        {
            strcpy(newData, data);
            delete[] data;
        }
        else
        {
            newData[0] = '\0';
        }
        data = newData;
        capacity = newCapacity;
    }

public:
    StringBuilder() : data(nullptr), length(0), capacity(0)
    {
        resize(10);
    }

    ~StringBuilder()
    {
        delete[] data;
    }

    StringBuilder &append(const char *str)
    {
        // TODO: Append str to the end of current string
        // Hint: Calculate needed size, resize if necessary, use strcat
        // Return *this for method chaining
        return *this;
    }

    StringBuilder &prepend(const char *str)
    {
        // TODO: Add str to the beginning of current string
        // Hint: Calculate needed size, create temp string, resize, copy
        // Return *this for method chaining
        return *this;
    }

    StringBuilder &clear()
    {
        // TODO: Clear the string (set to empty)
        // Hint: Set data[0] = '\0' and length = 0
        // Return *this for method chaining
        return *this;
    }

    const char *getString() const
    {
        return data;
    }
};

// ============================================================================
// TEST FUNCTIONS
// ============================================================================

void testProblem1()
{
    cout << "\n========================================" << endl;
    cout << "Testing Problem 1: Point Distance Calculator" << endl;
    cout << "========================================\n"
         << endl;

    // Test Case 1: Origin to (3,4) - Classic 3-4-5 triangle
    // Calculation: sqrt((3-0)^2 + (4-0)^2) = sqrt(9 + 16) = sqrt(25) = 5.0
    Point p1_1(0, 0);
    Point p1_2(3, 4);
    cout << "Test 1 - (0,0) to (3,4): ";
    cout << (p1_1.distanceTo(p1_2) == 5.0 ? "PASS" : "FAIL") << " (Expected: 5.0)" << endl;

    // Test Case 2: (1,1) to (4,5) - Another 3-4-5 triangle
    // Calculation: sqrt((4-1)^2 + (5-1)^2) = sqrt(9 + 16) = sqrt(25) = 5.0
    Point p2_1(1, 1);
    Point p2_2(4, 5);
    cout << "Test 2 - (1,1) to (4,5): ";
    cout << (p2_1.distanceTo(p2_2) == 5.0 ? "PASS" : "FAIL") << " (Expected: 5.0)" << endl;

    // Test Case 3: Same point - distance should be 0
    // Calculation: sqrt((5-5)^2 + (5-5)^2) = sqrt(0) = 0.0
    Point p3_1(5, 5);
    Point p3_2(5, 5);
    cout << "Test 3 - (5,5) to (5,5): ";
    cout << (p3_1.distanceTo(p3_2) == 0.0 ? "PASS" : "FAIL") << " (Expected: 0.0)" << endl;

    // Test Case 4: Horizontal distance
    // Calculation: sqrt((10-0)^2 + (0-0)^2) = sqrt(100) = 10.0
    Point p4_1(0, 0);
    Point p4_2(10, 0);
    cout << "Test 4 - (0,0) to (10,0): ";
    cout << (p4_1.distanceTo(p4_2) == 10.0 ? "PASS" : "FAIL") << " (Expected: 10.0)" << endl;

    // Test Case 5: Vertical distance
    // Calculation: sqrt((0-0)^2 + (8-0)^2) = sqrt(64) = 8.0
    Point p5_1(0, 0);
    Point p5_2(0, 8);
    cout << "Test 5 - (0,0) to (0,8): ";
    cout << (p5_1.distanceTo(p5_2) == 8.0 ? "PASS" : "FAIL") << " (Expected: 8.0)" << endl;

    // Test Case 6: Negative coordinates
    // Calculation: sqrt((-3-0)^2 + (-4-0)^2) = sqrt(9 + 16) = sqrt(25) = 5.0
    Point p6_1(0, 0);
    Point p6_2(-3, -4);
    cout << "Test 6 - (0,0) to (-3,-4): ";
    cout << (p6_1.distanceTo(p6_2) == 5.0 ? "PASS" : "FAIL") << " (Expected: 5.0)" << endl;

    // Test Case 7: Both negative coordinates
    // Calculation: sqrt(((-2)-(-5))^2 + ((-3)-(-7))^2) = sqrt(9 + 16) = sqrt(25) = 5.0
    Point p7_1(-5, -7);
    Point p7_2(-2, -3);
    cout << "Test 7 - (-5,-7) to (-2,-3): ";
    cout << (p7_1.distanceTo(p7_2) == 5.0 ? "PASS" : "FAIL") << " (Expected: 5.0)" << endl;

    // Test Case 8: 5-12-13 triangle
    // Calculation: sqrt((5-0)^2 + (12-0)^2) = sqrt(25 + 144) = sqrt(169) = 13.0
    Point p8_1(0, 0);
    Point p8_2(5, 12);
    cout << "Test 8 - (0,0) to (5,12): ";
    cout << (p8_1.distanceTo(p8_2) == 13.0 ? "PASS" : "FAIL") << " (Expected: 13.0)" << endl;
}

void testProblem2()
{
    cout << "\n========================================" << endl;
    cout << "Testing Problem 2: Method Chaining Bank Account" << endl;
    cout << "========================================\n"
         << endl;

    // Test Case 1: Simple deposit and withdraw
    // Calculation: 100 + 50 = 150, 150 - 30 = 120
    BankAccount acc1(100);
    cout << "Test 1 - Start:100, +50, -30: ";
    cout << (acc1.deposit(50).withdraw(30).getBalance() == 120.0 ? "PASS" : "FAIL") << " (Expected: 120.0)" << endl;

    // Test Case 2: Multiple deposits
    // Calculation: 0 + 100 = 100, 100 + 50 = 150, 150 - 25 = 125
    BankAccount acc2(0);
    cout << "Test 2 - Start:0, +100, +50, -25: ";
    cout << (acc2.deposit(100).deposit(50).withdraw(25).getBalance() == 125.0 ? "PASS" : "FAIL") << " (Expected: 125.0)" << endl;

    // Test Case 3: Insufficient funds (withdraw should not execute)
    // Calculation: 50 - 100 = 50 (withdraw fails, balance remains 50)
    BankAccount acc3(50);
    cout << "Test 3 - Start:50, -100 (insufficient): ";
    cout << (acc3.withdraw(100).getBalance() == 50.0 ? "PASS" : "FAIL") << " (Expected: 50.0)" << endl;

    // Test Case 4: Multiple operations with chaining
    // Calculation: 200 + 100 = 300, 300 - 50 = 250, 250 + 25 = 275, 275 - 75 = 200
    BankAccount acc4(200);
    cout << "Test 4 - Start:200, +100, -50, +25, -75: ";
    cout << (acc4.deposit(100).withdraw(50).deposit(25).withdraw(75).getBalance() == 200.0 ? "PASS" : "FAIL") << " (Expected: 200.0)" << endl;

    // Test Case 5: Only deposits
    // Calculation: 10 + 20 = 30, 30 + 30 = 60, 60 + 40 = 100
    BankAccount acc5(10);
    cout << "Test 5 - Start:10, +20, +30, +40: ";
    cout << (acc5.deposit(20).deposit(30).deposit(40).getBalance() == 100.0 ? "PASS" : "FAIL") << " (Expected: 100.0)" << endl;

    // Test Case 6: Exact balance withdrawal
    // Calculation: 500 - 500 = 0
    BankAccount acc6(500);
    cout << "Test 6 - Start:500, -500 (exact): ";
    cout << (acc6.withdraw(500).getBalance() == 0.0 ? "PASS" : "FAIL") << " (Expected: 0.0)" << endl;

    // Test Case 7: Mixed operations ending at zero
    // Calculation: 1000 - 300 = 700, 700 - 400 = 300, 300 - 300 = 0
    BankAccount acc7(1000);
    cout << "Test 7 - Start:1000, -300, -400, -300: ";
    cout << (acc7.withdraw(300).withdraw(400).withdraw(300).getBalance() == 0.0 ? "PASS" : "FAIL") << " (Expected: 0.0)" << endl;

    // Test Case 8: Small decimal operations
    // Calculation: 10.5 + 5.25 = 15.75, 15.75 - 3.50 = 12.25
    BankAccount acc8(10.5);
    cout << "Test 8 - Start:10.5, +5.25, -3.50: ";
    cout << (acc8.deposit(5.25).withdraw(3.5).getBalance() == 12.25 ? "PASS" : "FAIL") << " (Expected: 12.25)" << endl;
}

void testProblem3()
{
    cout << "\n========================================" << endl;
    cout << "Testing Problem 3: Employee Comparison System" << endl;
    cout << "========================================\n"
         << endl;

    // Test Case 1: Different salaries - higher vs lower
    // Alice: 50000, Bob: 60000
    // Alice.isHigherPaidThan(Bob) = false (50000 < 60000)
    Employee e1_1("Alice", 50000);
    Employee e1_2("Bob", 60000);
    cout << "Test 1 - Alice(50k) vs Bob(60k) - isHigherPaidThan: ";
    cout << (e1_1.isHigherPaidThan(e1_2) == false ? "PASS" : "FAIL") << " (Expected: false)" << endl;

    // Test Case 2: Different salaries - lower vs higher
    // Bob: 60000, Alice: 50000
    // Bob.isHigherPaidThan(Alice) = true (60000 > 50000)
    cout << "Test 2 - Bob(60k) vs Alice(50k) - isHigherPaidThan: ";
    cout << (e1_2.isHigherPaidThan(e1_1) == true ? "PASS" : "FAIL") << " (Expected: true)" << endl;

    // Test Case 3: Same salaries
    // Alice: 50000, Charlie: 50000
    // Alice.hasSameSalaryAs(Charlie) = true (50000 == 50000)
    Employee e3_1("Alice", 50000);
    Employee e3_2("Charlie", 50000);
    cout << "Test 3 - Alice(50k) vs Charlie(50k) - hasSameSalaryAs: ";
    cout << (e3_1.hasSameSalaryAs(e3_2) == true ? "PASS" : "FAIL") << " (Expected: true)" << endl;

    // Test Case 4: Different salaries - hasSameSalaryAs
    // Alice: 50000, Bob: 60000
    // Alice.hasSameSalaryAs(Bob) = false (50000 != 60000)
    cout << "Test 4 - Alice(50k) vs Bob(60k) - hasSameSalaryAs: ";
    cout << (e1_1.hasSameSalaryAs(e1_2) == false ? "PASS" : "FAIL") << " (Expected: false)" << endl;

    // Test Case 5: getHigherPaid - first is higher
    // David: 75000, Eve: 70000
    // David.getHigherPaid(Eve) should return pointer to David
    Employee e5_1("David", 75000);
    Employee e5_2("Eve", 70000);
    const Employee *higher1 = e5_1.getHigherPaid(e5_2);
    cout << "Test 5 - David(75k) vs Eve(70k) - getHigherPaid: ";
    cout << (higher1->getName() == "David" ? "PASS" : "FAIL") << " (Expected: David)" << endl;

    // Test Case 6: getHigherPaid - second is higher
    // Eve: 70000, David: 75000
    // Eve.getHigherPaid(David) should return pointer to David
    const Employee *higher2 = e5_2.getHigherPaid(e5_1);
    cout << "Test 6 - Eve(70k) vs David(75k) - getHigherPaid: ";
    cout << (higher2->getName() == "David" ? "PASS" : "FAIL") << " (Expected: David)" << endl;

    // Test Case 7: getHigherPaid - same salary (returns first/this)
    // Frank: 80000, Grace: 80000
    // Frank.getHigherPaid(Grace) should return pointer to Frank
    Employee e7_1("Frank", 80000);
    Employee e7_2("Grace", 80000);
    const Employee *higher3 = e7_1.getHigherPaid(e7_2);
    cout << "Test 7 - Frank(80k) vs Grace(80k) - getHigherPaid: ";
    cout << (higher3->getName() == "Frank" ? "PASS" : "FAIL") << " (Expected: Frank)" << endl;

    // Test Case 8: All methods combined on same objects
    // Henry: 90000, Iris: 85000
    Employee e8_1("Henry", 90000);
    Employee e8_2("Iris", 85000);
    bool test8 = e8_1.isHigherPaidThan(e8_2) == true &&
                 e8_1.hasSameSalaryAs(e8_2) == false &&
                 e8_1.getHigherPaid(e8_2)->getName() == "Henry";
    cout << "Test 8 - Henry(90k) vs Iris(85k) - Combined: ";
    cout << (test8 ? "PASS" : "FAIL") << " (Expected: true, false, Henry)" << endl;
}

void testProblem4()
{
    cout << "\n========================================" << endl;
    cout << "Testing Problem 4: Dynamic String Builder" << endl;
    cout << "========================================\n"
         << endl;

    // Test Case 1: Simple append
    // Step: "" + "Hello" = "Hello"
    StringBuilder sb1;
    sb1.append("Hello");
    cout << "Test 1 - append('Hello'): ";
    cout << (strcmp(sb1.getString(), "Hello") == 0 ? "PASS" : "FAIL") << " (Expected: 'Hello')" << endl;

    // Test Case 2: Multiple appends
    // Step: "" + "C++" = "C++", "C++" + " is" = "C++ is", "C++ is" + " awesome" = "C++ is awesome"
    StringBuilder sb2;
    sb2.append("C++").append(" is").append(" awesome");
    cout << "Test 2 - append chaining: ";
    cout << (strcmp(sb2.getString(), "C++ is awesome") == 0 ? "PASS" : "FAIL") << " (Expected: 'C++ is awesome')" << endl;

    // Test Case 3: Prepend only
    // Step: "" + "World" = "World", "Hello " + "World" = "Hello World"
    StringBuilder sb3;
    sb3.append("World").prepend("Hello ");
    cout << "Test 3 - append then prepend: ";
    cout << (strcmp(sb3.getString(), "Hello World") == 0 ? "PASS" : "FAIL") << " (Expected: 'Hello World')" << endl;

    // Test Case 4: Mixed append and prepend with exclamation
    // Step: "" + "World" = "World", "Hello " + "World" = "Hello World", "Hello World" + "!" = "Hello World!"
    StringBuilder sb4;
    sb4.append("World").prepend("Hello ").append("!");
    cout << "Test 4 - prepend and append: ";
    cout << (strcmp(sb4.getString(), "Hello World!") == 0 ? "PASS" : "FAIL") << " (Expected: 'Hello World!')" << endl;

    // Test Case 5: Clear operation
    // Step: "" + "Test" = "Test", clear = ""
    StringBuilder sb5;
    sb5.append("Test").clear();
    cout << "Test 5 - append then clear: ";
    cout << (strcmp(sb5.getString(), "") == 0 ? "PASS" : "FAIL") << " (Expected: '')" << endl;

    // Test Case 6: Append after clear
    // Step: "" + "Old" = "Old", clear = "", "" + "New" = "New"
    StringBuilder sb6;
    sb6.append("Old").clear().append("New");
    cout << "Test 6 - clear then append: ";
    cout << (strcmp(sb6.getString(), "New") == 0 ? "PASS" : "FAIL") << " (Expected: 'New')" << endl;

    // Test Case 7: Multiple prepends
    // Step: "" + "3" = "3", "2" + "3" = "23", "1" + "23" = "123"
    StringBuilder sb7;
    sb7.append("3").prepend("2").prepend("1");
    cout << "Test 7 - multiple prepends: ";
    cout << (strcmp(sb7.getString(), "123") == 0 ? "PASS" : "FAIL") << " (Expected: '123')" << endl;

    // Test Case 8: Complex chaining
    // Step: "" + "middle" = "middle"
    //       "start-" + "middle" = "start-middle"
    //       "start-middle" + "-end" = "start-middle-end"
    StringBuilder sb8;
    sb8.append("middle").prepend("start-").append("-end");
    cout << "Test 8 - complex chaining: ";
    cout << (strcmp(sb8.getString(), "start-middle-end") == 0 ? "PASS" : "FAIL") << " (Expected: 'start-middle-end')" << endl;
}

// ============================================================================
// MAIN FUNCTION
// ============================================================================

int main()
{
    int choice;
    cout << "\n============================================" << endl;
    cout << "   C++ Practice: The this Pointer" << endl;
    cout << "============================================" << endl;
    cout << "\nChoose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy) - Point Distance Calculator" << endl;
    cout << "2. Problem 2 (Easy-Medium) - Method Chaining Bank Account" << endl;
    cout << "3. Problem 3 (Medium) - Employee Comparison System" << endl;
    cout << "4. Problem 4 (Hard) - Dynamic String Builder" << endl;
    cout << "5. Test All Problems" << endl;
    cout << "\nEnter your choice: ";
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
        cout << "\nInvalid choice!" << endl;
    }

    cout << "\n============================================" << endl;
    cout << "         Testing Complete!" << endl;
    cout << "============================================\n"
         << endl;

    return 0;
}