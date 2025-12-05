#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// ============================================================================
// Problem 1: Easy 1 - Vehicle Registration System
// ============================================================================
// Description:
// Create a base class Vehicle with brand (string) and year (int).
// Create a derived class Car that adds model (string).
//
// Vehicle constructor should accept brand and year.
// Car constructor should accept brand, year, and model, and use the base
// class constructor to initialize brand and year.
//
// Implement a function that creates a Car object and returns a formatted
// string: "Brand: [brand], Year: [year], Model: [model]"
//
// Input Format: brand (string), year (int), model (string)
// Output Format: Formatted string as shown above
//
// Example 1:
// Input: "Toyota", 2020, "Camry"
// Output: "Brand: Toyota, Year: 2020, Model: Camry"
//
// Example 2:
// Input: "Honda", 2019, "Civic"
// Output: "Brand: Honda, Year: 2019, Model: Civic"
//
// Constraints:
// - brand and model are non-empty strings
// - year is a positive integer (1900-2025)

class Vehicle
{
protected:
    string brand;
    int year;

public:
    Vehicle() = default;
    Vehicle(string b, int y) : brand(b), year(y) {}
    Vehicle(const Vehicle &source) : brand(source.brand), year(source.year) {}
};

class Car : public Vehicle
{
private:
    string model;

public:
    // TODO: Implement constructor using base class constructor
    Car(string b, int y, string m) : Vehicle(b, y), model(m)
    {
        // TODO: Initialize base class and model
    }
    Car(const Car &source) : Vehicle(source), model(source.model)
    {
    }

    string getInfo()
    {
        // TODO: Return formatted string
        return "Brand: " + this->brand + ", Year: " + to_string(this->year) + ", Model: " + this->model;
    }
};

string problem1Solution(string brand, int year, string model)
{
    // TODO: Create a Car object and return its info
    // Hint: Use the Car constructor to initialize all members, then call getInfo()
    Car c1(brand, year, model);
    Car c2(c1);
    return c2.getInfo();
}

// ============================================================================
// Problem 2: Easy 2 - Employee Salary Calculator
// ============================================================================
// Description:
// Create a base class Employee with name (string) and baseSalary (double).
// Create a derived class Manager that adds bonus (double).
//
// Employee constructor accepts name and baseSalary.
// Manager constructor accepts name, baseSalary, and bonus, using base constructor.
//
// Calculate total salary for a Manager (baseSalary + bonus).
//
// Input Format: name (string), baseSalary (double), bonus (double)
// Output Format: Total salary (double) rounded to 2 decimal places
//
// Example 1:
// Input: "John", 5000.0, 1500.0
// Output: 6500.0
//
// Example 2:
// Input: "Sarah", 7500.50, 2000.25
// Output: 9500.75
//
// Constraints:
// - name is non-empty
// - baseSalary >= 0
// - bonus >= 0

class Employee
{
protected:
    string name;
    double baseSalary;

public:
    Employee() = default;
    Employee(string n, double salary) : name(n), baseSalary(salary) {}
    Employee(const Employee &source) : name(source.name), baseSalary(source.baseSalary) {}
};

class Manager : public Employee
{
private:
    double bonus;

public:
    // TODO: Implement constructor using base class constructor
    Manager(string n, double salary, double b) : Employee(n, salary), bonus(b)
    {
        // TODO: Initialize base class and bonus
    }
    Manager(const Manager &source) : Employee(source), bonus(source.bonus) {}

    double getTotalSalary()
    {
        // TODO: Return baseSalary + bonus
        return this->baseSalary + this->bonus;
    }
};

double problem2Solution(string name, double baseSalary, double bonus)
{
    // TODO: Create a Manager object and return total salary
    // Hint: Use Manager constructor, then call getTotalSalary()
    Manager m1(name, baseSalary, bonus);
    Manager m2(m1);
    return m2.getTotalSalary();
}

// ============================================================================
// Problem 3: Medium - Shape Area Calculator with Inheritance
// ============================================================================
// Description:
// Create a base class Shape with color (string) and a position x, y (int).
// Create a derived class Rectangle that adds width and height (double).
//
// Shape constructor accepts color, x, and y.
// Rectangle constructor accepts color, x, y, width, and height.
//
// Calculate the area of the rectangle and return it along with position info.
// Format: "Color: [color], Position: ([x],[y]), Area: [area]"
//
// Input Format: color (string), x (int), y (int), width (double), height (double)
// Output Format: Formatted string with area rounded to 2 decimal places
//
// Example 1:
// Input: "Red", 10, 20, 5.0, 4.0
// Calculation: Area = 5.0 * 4.0 = 20.00
// Output: "Color: Red, Position: (10,20), Area: 20.00"
//
// Example 2:
// Input: "Blue", 0, 0, 3.5, 2.5
// Calculation: Area = 3.5 * 2.5 = 8.75
// Output: "Color: Blue, Position: (0,0), Area: 8.75"
//
// Constraints:
// - color is non-empty
// - x, y can be any integer
// - width > 0, height > 0

class Shape
{
protected:
    string color;
    int x, y;

public:
    Shape() = default;

    Shape(string c, int posX, int posY) : color(c), x(posX), y(posY) {}
};

class Rectangle : public Shape
{
private:
    double width, height;

public:
    // TODO: Implement constructor using base class constructor
    Rectangle(string c, int posX, int posY, double w, double h)
    {
        // TODO: Initialize base class and dimensions
    }

    string getShapeInfo()
    {
        // TODO: Calculate area and return formatted string
        // Use cout with fixed and setprecision(2) or similar formatting
        return "";
    }
};

string problem3Solution(string color, int x, int y, double width, double height)
{
    // TODO: Create a Rectangle object and return its info
    // Hint: Use Rectangle constructor with all 5 parameters
    return "";
}

// ============================================================================
// Problem 4: Hard - Bank Account Inheritance with Transaction History
// ============================================================================
// Description:
// Create a base class Account with accountNumber (int) and balance (double).
// Create a derived class SavingsAccount that adds interestRate (double) and
// a transaction counter (int) that tracks number of deposits.
//
// Account constructor accepts accountNumber and initialBalance.
// SavingsAccount constructor accepts accountNumber, initialBalance, and interestRate.
// Transaction counter should start at 0.
//
// Implement deposit method that adds to balance and increments counter.
// Implement calculateInterest that returns balance * interestRate / 100.
// Return format: "Account: [number], Balance: [balance], Transactions: [count], Interest: [interest]"
//
// Input Format: accountNumber (int), initialBalance (double), interestRate (double),
//               depositAmount (double)
// Output Format: Formatted string after one deposit
//
// Example 1:
// Input: 1001, 1000.0, 5.0, 500.0
// After deposit: balance = 1000.0 + 500.0 = 1500.0, transactions = 1
// Interest: 1500.0 * 5.0 / 100 = 75.00
// Output: "Account: 1001, Balance: 1500.00, Transactions: 1, Interest: 75.00"
//
// Example 2:
// Input: 2002, 2500.50, 3.5, 1000.25
// After deposit: balance = 2500.50 + 1000.25 = 3500.75, transactions = 1
// Interest: 3500.75 * 3.5 / 100 = 122.52625 ≈ 122.53
// Output: "Account: 2002, Balance: 3500.75, Transactions: 1, Interest: 122.53"
//
// Constraints:
// - accountNumber > 0
// - initialBalance >= 0
// - interestRate >= 0
// - depositAmount >= 0

class Account
{
protected:
    int accountNumber;
    double balance;

public:
    Account() = default;
    Account(int accNum, double initialBalance)
        : accountNumber(accNum), balance(initialBalance) {}
};

class SavingsAccount : public Account
{
private:
    double interestRate;
    int transactionCount;

public:
    // TODO: Implement constructor using base class constructor
    SavingsAccount(int accNum, double initialBalance, double rate)
    {
        // TODO: Initialize base class, interestRate, and set transactionCount to 0
    }

    void deposit(double amount)
    {
        // TODO: Add amount to balance and increment transactionCount
    }

    double calculateInterest()
    {
        // TODO: Return balance * interestRate / 100
        return 0.0;
    }

    string getAccountInfo()
    {
        // TODO: Return formatted string with all information
        return "";
    }
};

string problem4Solution(int accountNumber, double initialBalance,
                        double interestRate, double depositAmount)
{
    // TODO: Create SavingsAccount, make deposit, return account info
    // Hint: Create object, call deposit(), then getAccountInfo()
    return "";
}

// ============================================================================
// TEST FUNCTIONS
// ============================================================================

void testProblem1()
{
    cout << "\n=== Testing Problem 1: Vehicle Registration System ===" << endl;

    // Test Case 1: Basic Toyota Camry
    // Expected: "Brand: Toyota, Year: 2020, Model: Camry"
    string result1 = problem1Solution("Toyota", 2020, "Camry");
    cout << "Test 1: " << (result1 == "Brand: Toyota, Year: 2020, Model: Camry" ? "PASS" : "FAIL") << endl;
    if (result1 != "Brand: Toyota, Year: 2020, Model: Camry")
    {
        cout << "  Expected: Brand: Toyota, Year: 2020, Model: Camry" << endl;
        cout << "  Got: " << result1 << endl;
    }

    // Test Case 2: Honda Civic
    // Expected: "Brand: Honda, Year: 2019, Model: Civic"
    string result2 = problem1Solution("Honda", 2019, "Civic");
    cout << "Test 2: " << (result2 == "Brand: Honda, Year: 2019, Model: Civic" ? "PASS" : "FAIL") << endl;

    // Test Case 3: Ford Mustang
    // Expected: "Brand: Ford, Year: 2021, Model: Mustang"
    string result3 = problem1Solution("Ford", 2021, "Mustang");
    cout << "Test 3: " << (result3 == "Brand: Ford, Year: 2021, Model: Mustang" ? "PASS" : "FAIL") << endl;

    // Test Case 4: Tesla Model3
    // Expected: "Brand: Tesla, Year: 2023, Model: Model3"
    string result4 = problem1Solution("Tesla", 2023, "Model3");
    cout << "Test 4: " << (result4 == "Brand: Tesla, Year: 2023, Model: Model3" ? "PASS" : "FAIL") << endl;

    // Test Case 5: Old car (boundary)
    // Expected: "Brand: Chevrolet, Year: 1965, Model: Impala"
    string result5 = problem1Solution("Chevrolet", 1965, "Impala");
    cout << "Test 5: " << (result5 == "Brand: Chevrolet, Year: 1965, Model: Impala" ? "PASS" : "FAIL") << endl;

    // Test Case 6: Recent year
    // Expected: "Brand: BMW, Year: 2024, Model: X5"
    string result6 = problem1Solution("BMW", 2024, "X5");
    cout << "Test 6: " << (result6 == "Brand: BMW, Year: 2024, Model: X5" ? "PASS" : "FAIL") << endl;

    // Test Case 7: Mercedes
    // Expected: "Brand: Mercedes, Year: 2022, Model: C-Class"
    string result7 = problem1Solution("Mercedes", 2022, "C-Class");
    cout << "Test 7: " << (result7 == "Brand: Mercedes, Year: 2022, Model: C-Class" ? "PASS" : "FAIL") << endl;

    // Test Case 8: Audi
    // Expected: "Brand: Audi, Year: 2020, Model: A4"
    string result8 = problem1Solution("Audi", 2020, "A4");
    cout << "Test 8: " << (result8 == "Brand: Audi, Year: 2020, Model: A4" ? "PASS" : "FAIL") << endl;
}

void testProblem2()
{
    cout << "\n=== Testing Problem 2: Employee Salary Calculator ===" << endl;

    // Test Case 1: Basic calculation
    // baseSalary: 5000.0, bonus: 1500.0
    // Total: 5000.0 + 1500.0 = 6500.0
    double result1 = problem2Solution("John", 5000.0, 1500.0);
    cout << "Test 1: " << (result1 == 6500.0 ? "PASS" : "FAIL") << endl;
    if (result1 != 6500.0)
    {
        cout << "  Expected: 6500.0, Got: " << result1 << endl;
    }

    // Test Case 2: Decimal values
    // baseSalary: 7500.50, bonus: 2000.25
    // Total: 7500.50 + 2000.25 = 9500.75
    double result2 = problem2Solution("Sarah", 7500.50, 2000.25);
    cout << "Test 2: " << (result2 == 9500.75 ? "PASS" : "FAIL") << endl;

    // Test Case 3: Zero bonus
    // baseSalary: 3000.0, bonus: 0.0
    // Total: 3000.0 + 0.0 = 3000.0
    double result3 = problem2Solution("Mike", 3000.0, 0.0);
    cout << "Test 3: " << (result3 == 3000.0 ? "PASS" : "FAIL") << endl;

    // Test Case 4: Large numbers
    // baseSalary: 15000.0, bonus: 5000.0
    // Total: 15000.0 + 5000.0 = 20000.0
    double result4 = problem2Solution("Emma", 15000.0, 5000.0);
    cout << "Test 4: " << (result4 == 20000.0 ? "PASS" : "FAIL") << endl;

    // Test Case 5: Small decimals
    // baseSalary: 4250.75, bonus: 850.25
    // Total: 4250.75 + 850.25 = 5101.0
    double result5 = problem2Solution("David", 4250.75, 850.25);
    cout << "Test 5: " << (result5 == 5101.0 ? "PASS" : "FAIL") << endl;

    // Test Case 6: High bonus
    // baseSalary: 6000.0, bonus: 4000.0
    // Total: 6000.0 + 4000.0 = 10000.0
    double result6 = problem2Solution("Lisa", 6000.0, 4000.0);
    cout << "Test 6: " << (result6 == 10000.0 ? "PASS" : "FAIL") << endl;

    // Test Case 7: Complex decimals
    // baseSalary: 8123.45, bonus: 1876.55
    // Total: 8123.45 + 1876.55 = 10000.0
    double result7 = problem2Solution("Tom", 8123.45, 1876.55);
    cout << "Test 7: " << (result7 == 10000.0 ? "PASS" : "FAIL") << endl;

    // Test Case 8: Minimum salary
    // baseSalary: 2500.0, bonus: 500.0
    // Total: 2500.0 + 500.0 = 3000.0
    double result8 = problem2Solution("Anna", 2500.0, 500.0);
    cout << "Test 8: " << (result8 == 3000.0 ? "PASS" : "FAIL") << endl;
}

void testProblem3()
{
    cout << "\n=== Testing Problem 3: Shape Area Calculator ===" << endl;

    // Test Case 1: Basic rectangle
    // Area = 5.0 * 4.0 = 20.00
    string result1 = problem3Solution("Red", 10, 20, 5.0, 4.0);
    cout << "Test 1: " << (result1 == "Color: Red, Position: (10,20), Area: 20.00" ? "PASS" : "FAIL") << endl;
    if (result1 != "Color: Red, Position: (10,20), Area: 20.00")
    {
        cout << "  Expected: Color: Red, Position: (10,20), Area: 20.00" << endl;
        cout << "  Got: " << result1 << endl;
    }

    // Test Case 2: Decimal dimensions
    // Area = 3.5 * 2.5 = 8.75
    string result2 = problem3Solution("Blue", 0, 0, 3.5, 2.5);
    cout << "Test 2: " << (result2 == "Color: Blue, Position: (0,0), Area: 8.75" ? "PASS" : "FAIL") << endl;

    // Test Case 3: Square
    // Area = 6.0 * 6.0 = 36.00
    string result3 = problem3Solution("Green", 5, 5, 6.0, 6.0);
    cout << "Test 3: " << (result3 == "Color: Green, Position: (5,5), Area: 36.00" ? "PASS" : "FAIL") << endl;

    // Test Case 4: Negative position
    // Area = 10.0 * 2.0 = 20.00
    string result4 = problem3Solution("Yellow", -5, -10, 10.0, 2.0);
    cout << "Test 4: " << (result4 == "Color: Yellow, Position: (-5,-10), Area: 20.00" ? "PASS" : "FAIL") << endl;

    // Test Case 5: Large rectangle
    // Area = 100.0 * 50.0 = 5000.00
    string result5 = problem3Solution("Purple", 100, 200, 100.0, 50.0);
    cout << "Test 5: " << (result5 == "Color: Purple, Position: (100,200), Area: 5000.00" ? "PASS" : "FAIL") << endl;

    // Test Case 6: Small decimals
    // Area = 1.5 * 2.5 = 3.75
    string result6 = problem3Solution("Orange", 0, 1, 1.5, 2.5);
    cout << "Test 6: " << (result6 == "Color: Orange, Position: (0,1), Area: 3.75" ? "PASS" : "FAIL") << endl;

    // Test Case 7: Mixed position
    // Area = 7.5 * 4.2 = 31.50
    string result7 = problem3Solution("Pink", -3, 8, 7.5, 4.2);
    cout << "Test 7: " << (result7 == "Color: Pink, Position: (-3,8), Area: 31.50" ? "PASS" : "FAIL") << endl;

    // Test Case 8: Unit square
    // Area = 1.0 * 1.0 = 1.00
    string result8 = problem3Solution("Black", 0, 0, 1.0, 1.0);
    cout << "Test 8: " << (result8 == "Color: Black, Position: (0,0), Area: 1.00" ? "PASS" : "FAIL") << endl;
}

void testProblem4()
{
    cout << "\n=== Testing Problem 4: Bank Account with Transactions ===" << endl;

    // Test Case 1: Basic account
    // Initial: 1000.0, Deposit: 500.0
    // Balance after: 1000.0 + 500.0 = 1500.0
    // Interest: 1500.0 * 5.0 / 100 = 75.00
    // Transactions: 1
    string result1 = problem4Solution(1001, 1000.0, 5.0, 500.0);
    cout << "Test 1: " << (result1 == "Account: 1001, Balance: 1500.00, Transactions: 1, Interest: 75.00" ? "PASS" : "FAIL") << endl;
    if (result1 != "Account: 1001, Balance: 1500.00, Transactions: 1, Interest: 75.00")
    {
        cout << "  Expected: Account: 1001, Balance: 1500.00, Transactions: 1, Interest: 75.00" << endl;
        cout << "  Got: " << result1 << endl;
    }

    // Test Case 2: Decimal values
    // Initial: 2500.50, Deposit: 1000.25
    // Balance after: 2500.50 + 1000.25 = 3500.75
    // Interest: 3500.75 * 3.5 / 100 = 122.52625 ≈ 122.53
    // Transactions: 1
    string result2 = problem4Solution(2002, 2500.50, 3.5, 1000.25);
    cout << "Test 2: " << (result2 == "Account: 2002, Balance: 3500.75, Transactions: 1, Interest: 122.53" ? "PASS" : "FAIL") << endl;

    // Test Case 3: Zero deposit
    // Initial: 5000.0, Deposit: 0.0
    // Balance after: 5000.0 + 0.0 = 5000.0
    // Interest: 5000.0 * 2.0 / 100 = 100.00
    // Transactions: 1
    string result3 = problem4Solution(3003, 5000.0, 2.0, 0.0);
    cout << "Test 3: " << (result3 == "Account: 3003, Balance: 5000.00, Transactions: 1, Interest: 100.00" ? "PASS" : "FAIL") << endl;

    // Test Case 4: High interest rate
    // Initial: 10000.0, Deposit: 5000.0
    // Balance after: 10000.0 + 5000.0 = 15000.0
    // Interest: 15000.0 * 10.0 / 100 = 1500.00
    // Transactions: 1
    string result4 = problem4Solution(4004, 10000.0, 10.0, 5000.0);
    cout << "Test 4: " << (result4 == "Account: 4004, Balance: 15000.00, Transactions: 1, Interest: 1500.00" ? "PASS" : "FAIL") << endl;

    // Test Case 5: Low interest rate
    // Initial: 3000.0, Deposit: 1000.0
    // Balance after: 3000.0 + 1000.0 = 4000.0
    // Interest: 4000.0 * 1.5 / 100 = 60.00
    // Transactions: 1
    string result5 = problem4Solution(5005, 3000.0, 1.5, 1000.0);
    cout << "Test 5: " << (result5 == "Account: 5005, Balance: 4000.00, Transactions: 1, Interest: 60.00" ? "PASS" : "FAIL") << endl;

    // Test Case 6: Large deposit
    // Initial: 1000.0, Deposit: 9000.0
    // Balance after: 1000.0 + 9000.0 = 10000.0
    // Interest: 10000.0 * 4.0 / 100 = 400.00
    // Transactions: 1
    string result6 = problem4Solution(6006, 1000.0, 4.0, 9000.0);
    cout << "Test 6: " << (result6 == "Account: 6006, Balance: 10000.00, Transactions: 1, Interest: 400.00" ? "PASS" : "FAIL") << endl;

    // Test Case 7: Complex decimals
    // Initial: 7823.45, Deposit: 2176.55
    // Balance after: 7823.45 + 2176.55 = 10000.0
    // Interest: 10000.0 * 3.75 / 100 = 375.00
    // Transactions: 1
    string result7 = problem4Solution(7007, 7823.45, 3.75, 2176.55);
    cout << "Test 7: " << (result7 == "Account: 7007, Balance: 10000.00, Transactions: 1, Interest: 375.00" ? "PASS" : "FAIL") << endl;

    // Test Case 8: Starting from zero
    // Initial: 0.0, Deposit: 2000.0
    // Balance after: 0.0 + 2000.0 = 2000.0
    // Interest: 2000.0 * 5.5 / 100 = 110.00
    // Transactions: 1
    string result8 = problem4Solution(8008, 0.0, 5.5, 2000.0);
    cout << "Test 8: " << (result8 == "Account: 8008, Balance: 2000.00, Transactions: 1, Interest: 110.00" ? "PASS" : "FAIL") << endl;
}

int main()
{
    int choice;
    cout << "==================================================" << endl;
    cout << "  Custom Constructors With Inheritance Practice" << endl;
    cout << "==================================================" << endl;
    cout << "\nChoose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy 1) - Vehicle Registration System" << endl;
    cout << "2. Problem 2 (Easy 2) - Employee Salary Calculator" << endl;
    cout << "3. Problem 3 (Medium) - Shape Area Calculator" << endl;
    cout << "4. Problem 4 (Hard) - Bank Account with Transactions" << endl;
    cout << "5. Test All Problems" << endl;
    cout << "\nYour choice: ";
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
        cout << "\nInvalid choice! Please select 1-5." << endl;
    }

    return 0;
}