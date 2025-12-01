#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// ==================== PROBLEM 1: Easy 1 ====================
// Problem 1: Basic Private Inheritance - Employee Access Control
//
// DESCRIPTION:
// You need to create a base class "Person" with protected members (name, age).
// Create a derived class "Employee" that PRIVATELY inherits from Person.
// Private inheritance means the public/protected members of Person become private in Employee.
// Employee should have its own public interface through its own methods.
// The key challenge: demonstrate that Person's public methods are NOT accessible
// through an Employee object, but protected members ARE accessible within Employee's methods.
//
// INPUT/OUTPUT FORMAT:
// Function creates Employee object and returns whether member access is properly restricted
// Output: boolean (1 = properly restricted, 0 = not restricted)
//
// CONSTRAINTS:
// - Use only protected members in base class
// - Employee must not expose Person's methods publicly
// - Employee adds a salary member
//
// EXAMPLES:
// Employee emp("John", 30, 50000);
// emp.getName();  // SHOULD NOT COMPILE - private inheritance hides public methods
// emp.displayInfo(); // Should work - Employee's own public method
//
int problem1Solution(string &employeeName, int &employeeAge, double &employeeSalary)
{
    // TODO: Implement your solution here using Private Inheritance
    // Create a Person base class with protected: name, age
    // Create Employee derived class with PRIVATE inheritance from Person
    // Employee should have its own displayInfo() method that uses Person's protected members
    // Hint: Private inheritance hides all public/protected members of base class in derived class
    // Return 1 if properly implemented, use employee data to store values
    return 0;
}

// ==================== PROBLEM 2: Easy 2 ====================
// Problem 2: Private Inheritance with Constructor Initialization
//
// DESCRIPTION:
// Extend Problem 1 to properly initialize the base class through derived class constructor.
// With private inheritance, you must explicitly call the base class constructor.
// Create a "Manager" class that privately inherits from "Employee".
// Manager adds a department member.
// The challenge: correctly initialize the entire inheritance chain (Person -> Employee -> Manager)
//
// INPUT/OUTPUT FORMAT:
// Function returns total compensation (salary + department bonus calculation)
// Bonus = 15% if department is "Finance", 10% if "IT", 5% otherwise
//
// CONSTRAINTS:
// - Three-level inheritance chain
// - Must properly initialize all levels
// - Calculate bonus based on department string
//
// EXAMPLES WITH MANUAL VERIFICATION:
// Manager m("Alice", 28, 80000, "Finance");
// Calculation: Base salary = 80000, Finance bonus = 80000 * 0.15 = 12000
// Total = 80000 + 12000 = 92000
//
double problem2Solution(string name, int age, double salary, string department)
{
    // TODO: Implement your solution here using Private Inheritance
    // Create Manager class that PRIVATELY inherits from Employee
    // Employee PRIVATELY inherits from Person
    // Manager constructor must initialize entire chain
    // Calculate: salary + (department-based bonus)
    // Hint: Use initialization lists with private inheritance: Employee(name, age, salary)
    return 0.0;
}

// ==================== PROBLEM 3: Medium ====================
// Problem 3: Private Inheritance with Access Control and Reuse
//
// DESCRIPTION:
// Create a "Vehicle" base class with protected data (brand, year, mileage)
// and protected method calculateDepreciation().
// Create "Car" class that PRIVATELY inherits from Vehicle.
// Car should expose a public method getCarValue() which internally uses the
// protected calculateDepreciation() method inherited from Vehicle.
// The key insight: Even though Vehicle methods are private to Car,
// Car's methods can still access them internally.
//
// INPUT/OUTPUT FORMAT:
// Input: brand (string), year (int), mileage (int)
// Output: current car value (double) after depreciation calculation
// Initial value: 100000
// Depreciation: 5% per year + 0.001 per mileage
//
// CONSTRAINTS:
// - Current year is 2024
// - Mileage must be >= 0
// - Value cannot be negative
//
// EXAMPLES WITH MANUAL VERIFICATION:
// Example 1: Car("Toyota", 2020, 50000)
// Step 1: Years passed = 2024 - 2020 = 4
// Step 2: Year depreciation = 4 * 5% = 20%
// Step 3: Mileage depreciation = 50000 * 0.001 = 50%
// Step 4: Total depreciation = 20% + 50% = 70%
// Step 5: Final value = 100000 * (1 - 0.70) = 100000 * 0.30 = 30000
// Expected output: 30000
//
// Example 2: Car("BMW", 2024, 1000)
// Step 1: Years passed = 2024 - 2024 = 0
// Step 2: Year depreciation = 0 * 5% = 0%
// Step 3: Mileage depreciation = 1000 * 0.001 = 1%
// Step 4: Total depreciation = 0% + 1% = 1%
// Step 5: Final value = 100000 * (1 - 0.01) = 100000 * 0.99 = 99000
// Expected output: 99000
//
double problem3Solution(string brand, int year, int mileage)
{
    // TODO: Implement your solution here using Private Inheritance
    // Create Vehicle base class with protected: brand, year, mileage
    // Create protected method: calculateDepreciation()
    // Create Car class with PRIVATE inheritance from Vehicle
    // Implement public getCarValue() that uses calculateDepreciation()
    // Hint: Use protected methods within derived class methods to hide implementation details
    // Formula: value = 100000 * (1 - (yearDepreciation + mileageDepreciation))
    return 0.0;
}

// ==================== PROBLEM 4: Hard ====================
// Problem 4: Complex Private Inheritance - Multiple Chains and Re-exposure
//
// DESCRIPTION:
// Create a base class "Device" with protected members (id, powerConsumption)
// Create "Computer" that PRIVATELY inherits from Device
// Create "Laptop" that PRIVATELY inherits from Computer
// The challenge: Laptop needs to re-expose ONLY certain methods from the inheritance chain
// using public interface while keeping others hidden. This tests understanding of:
// 1) How private inheritance hides base class interface
// 2) How to selectively expose functionality through wrapper methods
// 3) Data flow through multi-level private inheritance
//
// INPUT/OUTPUT FORMAT:
// Input: id (int), powerConsumption (double), laptopModel (string), batteryCapacity (int)
// Output: Structure with total power usage and battery life estimation
//
// CONSTRAINTS:
// - Multi-level private inheritance (Device -> Computer -> Laptop)
// - Battery life = (batteryCapacity / powerConsumption) hours
// - Total power = powerConsumption + gaming_boost (20% if model contains "Gaming")
// - Must properly initialize entire chain
//
// EXAMPLES WITH MANUAL VERIFICATION:
// Example 1: Laptop(101, 50.0, "Gaming Pro", 10000)
// Step 1: Is "Gaming" in model? YES (contains "Gaming")
// Step 2: Gaming boost = 50.0 * 0.20 = 10.0
// Step 3: Total power = 50.0 + 10.0 = 60.0 W
// Step 4: Battery life = 10000 / 60.0 = 166.666... hours
// Step 5: Format to 2 decimals = 166.67
// Expected output: totalPower = 60.0, batteryLife = 166.67
//
// Example 2: Laptop(202, 45.0, "UltraBook", 8000)
// Step 1: Is "Gaming" in model? NO
// Step 2: Gaming boost = 0
// Step 3: Total power = 45.0 + 0 = 45.0 W
// Step 4: Battery life = 8000 / 45.0 = 177.777... hours
// Step 5: Format to 2 decimals = 177.78
// Expected output: totalPower = 45.0, batteryLife = 177.78
//
struct LaptopStats
{
    double totalPower;
    double batteryLife;
};

LaptopStats problem4Solution(int id, double powerConsumption, string model, int batteryCapacity)
{
    // TODO: Implement your solution here using Private Inheritance
    // Create Device base class with protected: id, powerConsumption
    // Create Computer class with PRIVATE inheritance from Device
    // Create Laptop class with PRIVATE inheritance from Computer
    // Implement public method that calculates and returns LaptopStats
    // Hint: Use function to check if model contains "Gaming" substring
    // Re-expose functionality selectively through public methods only
    LaptopStats result = {0.0, 0.0};
    return result;
}

// ==================== TEST FRAMEWORK ====================

void testProblem1()
{
    cout << "\n========== TESTING PROBLEM 1 ==========\n";
    cout << "Private Inheritance - Basic Access Control\n\n";

    // Test Case 1: Standard employee
    // Manual verification: Create employee, verify private inheritance restricts access
    // Name: "John", Age: 30, Salary: 50000
    // Expected: Function should handle initialization correctly (return 1)
    string name1 = "John";
    int age1 = 30;
    double salary1 = 50000;
    int result1 = problem1Solution(name1, age1, salary1);
    cout << "Test 1 (Standard Employee): " << (result1 == 1 ? "PASS" : "FAIL")
         << " (Expected: 1, Got: " << result1 << ")\n";

    // Test Case 2: Young employee
    string name2 = "Sarah";
    int age2 = 22;
    double salary2 = 35000;
    int result2 = problem1Solution(name2, age2, salary2);
    cout << "Test 2 (Young Employee): " << (result2 == 1 ? "PASS" : "FAIL")
         << " (Expected: 1, Got: " << result2 << ")\n";

    // Test Case 3: Senior employee
    string name3 = "Robert";
    int age3 = 55;
    double salary3 = 120000;
    int result3 = problem1Solution(name3, age3, salary3);
    cout << "Test 3 (Senior Employee): " << (result3 == 1 ? "PASS" : "FAIL")
         << " (Expected: 1, Got: " << result3 << ")\n";

    // Test Case 4: Low salary
    string name4 = "Emma";
    int age4 = 25;
    double salary4 = 28000;
    int result4 = problem1Solution(name4, age4, salary4);
    cout << "Test 4 (Low Salary): " << (result4 == 1 ? "PASS" : "FAIL")
         << " (Expected: 1, Got: " << result4 << ")\n";

    // Test Case 5: High salary
    string name5 = "Michael";
    int age5 = 45;
    double salary5 = 150000;
    int result5 = problem1Solution(name5, age5, salary5);
    cout << "Test 5 (High Salary): " << (result5 == 1 ? "PASS" : "FAIL")
         << " (Expected: 1, Got: " << result5 << ")\n";
}

void testProblem2()
{
    cout << "\n========== TESTING PROBLEM 2 ==========\n";
    cout << "Multi-level Private Inheritance with Bonuses\n\n";

    // Test Case 1: Finance department
    // Manual Calculation: Salary = 80000, Department = "Finance"
    // Bonus = 80000 * 0.15 = 12000
    // Total = 80000 + 12000 = 92000
    double result1 = problem2Solution("Alice", 28, 80000, "Finance");
    cout << "Test 1 (Finance): " << (abs(result1 - 92000) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: 92000, Got: " << fixed << setprecision(2) << result1 << ")\n";

    // Test Case 2: IT department
    // Manual Calculation: Salary = 75000, Department = "IT"
    // Bonus = 75000 * 0.10 = 7500
    // Total = 75000 + 7500 = 82500
    double result2 = problem2Solution("Bob", 30, 75000, "IT");
    cout << "Test 2 (IT): " << (abs(result2 - 82500) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: 82500, Got: " << fixed << setprecision(2) << result2 << ")\n";

    // Test Case 3: HR department (other)
    // Manual Calculation: Salary = 60000, Department = "HR"
    // Bonus = 60000 * 0.05 = 3000
    // Total = 60000 + 3000 = 63000
    double result3 = problem2Solution("Carol", 35, 60000, "HR");
    cout << "Test 3 (HR): " << (abs(result3 - 63000) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: 63000, Got: " << fixed << setprecision(2) << result3 << ")\n";

    // Test Case 4: Marketing department (other)
    // Manual Calculation: Salary = 55000, Department = "Marketing"
    // Bonus = 55000 * 0.05 = 2750
    // Total = 55000 + 2750 = 57750
    double result4 = problem2Solution("David", 32, 55000, "Marketing");
    cout << "Test 4 (Marketing): " << (abs(result4 - 57750) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: 57750, Got: " << fixed << setprecision(2) << result4 << ")\n";

    // Test Case 5: Finance with high salary
    // Manual Calculation: Salary = 120000, Department = "Finance"
    // Bonus = 120000 * 0.15 = 18000
    // Total = 120000 + 18000 = 138000
    double result5 = problem2Solution("Eve", 40, 120000, "Finance");
    cout << "Test 5 (Finance-High): " << (abs(result5 - 138000) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: 138000, Got: " << fixed << setprecision(2) << result5 << ")\n";

    // Test Case 6: IT with medium salary
    // Manual Calculation: Salary = 90000, Department = "IT"
    // Bonus = 90000 * 0.10 = 9000
    // Total = 90000 + 9000 = 99000
    double result6 = problem2Solution("Frank", 27, 90000, "IT");
    cout << "Test 6 (IT-Medium): " << (abs(result6 - 99000) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: 99000, Got: " << fixed << setprecision(2) << result6 << ")\n";
}

void testProblem3()
{
    cout << "\n========== TESTING PROBLEM 3 ==========\n";
    cout << "Private Inheritance with Protected Method Access\n\n";

    // Test Case 1: Car from 2020 with 50000 mileage
    // Manual Calculation:
    // Years passed = 2024 - 2020 = 4
    // Year depreciation = 4 * 5% = 20% = 0.20
    // Mileage depreciation = 50000 * 0.001 = 50 = 50% = 0.50
    // Total depreciation = 0.20 + 0.50 = 0.70
    // Final value = 100000 * (1 - 0.70) = 100000 * 0.30 = 30000
    double result1 = problem3Solution("Toyota", 2020, 50000);
    cout << "Test 1 (2020, 50k mi): " << (abs(result1 - 30000) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: 30000, Got: " << fixed << setprecision(2) << result1 << ")\n";

    // Test Case 2: Brand new car 2024 with 1000 mileage
    // Manual Calculation:
    // Years passed = 2024 - 2024 = 0
    // Year depreciation = 0 * 5% = 0% = 0.00
    // Mileage depreciation = 1000 * 0.001 = 1 = 1% = 0.01
    // Total depreciation = 0.00 + 0.01 = 0.01
    // Final value = 100000 * (1 - 0.01) = 100000 * 0.99 = 99000
    double result2 = problem3Solution("BMW", 2024, 1000);
    cout << "Test 2 (2024, 1k mi): " << (abs(result2 - 99000) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: 99000, Got: " << fixed << setprecision(2) << result2 << ")\n";

    // Test Case 3: Car from 2010 with 200000 mileage
    // Manual Calculation:
    // Years passed = 2024 - 2010 = 14
    // Year depreciation = 14 * 5% = 70% = 0.70
    // Mileage depreciation = 200000 * 0.001 = 200 = 200% = 2.00
    // Total depreciation = 0.70 + 2.00 = 2.70
    // But max value is 0, so: 100000 * (1 - 2.70) = 100000 * (-1.70) -> clamped to 0
    // Final value = 0 (cannot be negative)
    double result3 = problem3Solution("Honda", 2010, 200000);
    cout << "Test 3 (2010, 200k mi): " << (abs(result3 - 0) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: 0, Got: " << fixed << setprecision(2) << result3 << ")\n";

    // Test Case 4: Car from 2019 with 100000 mileage
    // Manual Calculation:
    // Years passed = 2024 - 2019 = 5
    // Year depreciation = 5 * 5% = 25% = 0.25
    // Mileage depreciation = 100000 * 0.001 = 100 = 100% = 1.00
    // Total depreciation = 0.25 + 1.00 = 1.25
    // 100000 * (1 - 1.25) = 100000 * (-0.25) -> clamped to 0
    // Final value = 0
    double result4 = problem3Solution("Ford", 2019, 100000);
    cout << "Test 4 (2019, 100k mi): " << (abs(result4 - 0) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: 0, Got: " << fixed << setprecision(2) << result4 << ")\n";

    // Test Case 5: Car from 2023 with 5000 mileage
    // Manual Calculation:
    // Years passed = 2024 - 2023 = 1
    // Year depreciation = 1 * 5% = 5% = 0.05
    // Mileage depreciation = 5000 * 0.001 = 5 = 5% = 0.05
    // Total depreciation = 0.05 + 0.05 = 0.10
    // Final value = 100000 * (1 - 0.10) = 100000 * 0.90 = 90000
    double result5 = problem3Solution("Audi", 2023, 5000);
    cout << "Test 5 (2023, 5k mi): " << (abs(result5 - 90000) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: 90000, Got: " << fixed << setprecision(2) << result5 << ")\n";

    // Test Case 6: Car from 2015 with 80000 mileage
    // Manual Calculation:
    // Years passed = 2024 - 2015 = 9
    // Year depreciation = 9 * 5% = 45% = 0.45
    // Mileage depreciation = 80000 * 0.001 = 80 = 80% = 0.80
    // Total depreciation = 0.45 + 0.80 = 1.25
    // 100000 * (1 - 1.25) = 100000 * (-0.25) -> clamped to 0
    // Final value = 0
    double result6 = problem3Solution("Mercedes", 2015, 80000);
    cout << "Test 6 (2015, 80k mi): " << (abs(result6 - 0) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: 0, Got: " << fixed << setprecision(2) << result6 << ")\n";
}

void testProblem4()
{
    cout << "\n========== TESTING PROBLEM 4 ==========\n";
    cout << "Complex Multi-level Private Inheritance\n\n";

    // Test Case 1: Gaming laptop with Gaming in model
    // Manual Calculation:
    // Model: "Gaming Pro", Contains "Gaming"? YES
    // Base power: 50.0
    // Gaming boost: 50.0 * 0.20 = 10.0
    // Total power: 50.0 + 10.0 = 60.0 W
    // Battery life: 10000 / 60.0 = 166.666... = 166.67 (2 decimals)
    LaptopStats result1 = problem4Solution(101, 50.0, "Gaming Pro", 10000);
    cout << "Test 1 (Gaming Laptop): "
         << (abs(result1.totalPower - 60.0) < 0.01 && abs(result1.batteryLife - 166.67) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: power=60.0, life=166.67 | Got: power=" << fixed << setprecision(2) << result1.totalPower
         << ", life=" << result1.batteryLife << ")\n";

    // Test Case 2: Standard ultrabook without Gaming
    // Manual Calculation:
    // Model: "UltraBook", Contains "Gaming"? NO
    // Base power: 45.0
    // Gaming boost: 0 (no boost)
    // Total power: 45.0 + 0 = 45.0 W
    // Battery life: 8000 / 45.0 = 177.777... = 177.78 (2 decimals)
    LaptopStats result2 = problem4Solution(202, 45.0, "UltraBook", 8000);
    cout << "Test 2 (UltraBook): "
         << (abs(result2.totalPower - 45.0) < 0.01 && abs(result2.batteryLife - 177.78) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: power=45.0, life=177.78 | Got: power=" << fixed << setprecision(2) << result2.totalPower
         << ", life=" << result2.batteryLife << ")\n";

    // Test Case 3: Gaming laptop with high power
    // Manual Calculation:
    // Model: "Gaming Beast", Contains "Gaming"? YES
    // Base power: 100.0
    // Gaming boost: 100.0 * 0.20 = 20.0
    // Total power: 100.0 + 20.0 = 120.0 W
    // Battery life: 12000 / 120.0 = 100.0
    LaptopStats result3 = problem4Solution(303, 100.0, "Gaming Beast", 12000);
    cout << "Test 3 (Gaming Beast): "
         << (abs(result3.totalPower - 120.0) < 0.01 && abs(result3.batteryLife - 100.0) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: power=120.0, life=100.0 | Got: power=" << fixed << setprecision(2) << result3.totalPower
         << ", life=" << result3.batteryLife << ")\n";

    // Test Case 4: Workstation laptop without Gaming
    // Manual Calculation:
    // Model: "Workstation", Contains "Gaming"? NO
    // Base power: 55.0
    // Gaming boost: 0
    // Total power: 55.0 + 0 = 55.0 W
    // Battery life: 6000 / 55.0 = 109.0909... = 109.09 (2 decimals)
    LaptopStats result4 = problem4Solution(404, 55.0, "Workstation", 6000);
    cout << "Test 4 (Workstation): "
         << (abs(result4.totalPower - 55.0) < 0.01 && abs(result4.batteryLife - 109.09) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: power=55.0, life=109.09 | Got: power=" << fixed << setprecision(2) << result4.totalPower
         << ", life=" << result4.batteryLife << ")\n";

    // Test Case 5: Business laptop
    // Manual Calculation:
    // Model: "Business Lite", Contains "Gaming"? NO
    // Base power: 30.0
    // Gaming boost: 0
    // Total power: 30.0 + 0 = 30.0 W
    // Battery life: 15000 / 30.0 = 500.0
    LaptopStats result5 = problem4Solution(505, 30.0, "Business Lite", 15000);
    cout << "Test 5 (Business): "
         << (abs(result5.totalPower - 30.0) < 0.01 && abs(result5.batteryLife - 500.0) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: power=30.0, life=500.0 | Got: power=" << fixed << setprecision(2) << result5.totalPower
         << ", life=" << result5.batteryLife << ")\n";

    // Test Case 6: Gaming ROG laptop (contains Gaming)
    // Manual Calculation:
    // Model: "ROG Gaming Edition", Contains "Gaming"? YES
    // Base power: 75.0
    // Gaming boost: 75.0 * 0.20 = 15.0
    // Total power: 75.0 + 15.0 = 90.0 W
    // Battery life: 9000 / 90.0 = 100.0
    LaptopStats result6 = problem4Solution(606, 75.0, "ROG Gaming Edition", 9000);
    cout << "Test 6 (ROG Gaming): "
         << (abs(result6.totalPower - 90.0) < 0.01 && abs(result6.batteryLife - 100.0) < 0.01 ? "PASS" : "FAIL")
         << " (Expected: power=90.0, life=100.0 | Got: power=" << fixed << setprecision(2) << result6.totalPower
         << ", life=" << result6.batteryLife << ")\n";
}

int main()
{
    int choice;

    cout << "\n╔════════════════════════════════════════════════════════════╗\n";
    cout << "║    PRIVATE INHERITANCE PRACTICE PROBLEMS (4 Levels)      ║\n";
    cout << "║    Learn by solving - Solutions intentionally hidden!    ║\n";
    cout << "╚════════════════════════════════════════════════════════════╝\n";

    cout << "\nChoose a problem to test (1-4) or 5 to test all:\n";
    cout << "1. Problem 1 (Easy) - Basic Access Control\n";
    cout << "2. Problem 2 (Easy-Medium) - Multi-level with Bonuses\n";
    cout << "3. Problem 3 (Medium) - Protected Method Access\n";
    cout << "4. Problem 4 (Hard) - Complex Multi-level Chains\n";
    cout << "5. Test All Problems\n";
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
        cout << "Invalid choice! Please run the program again.\n";
    }

    cout << "\n════════════════════════════════════════════════════════════\n";
    cout << "Good luck with your implementations!\n";
    cout << "════════════════════════════════════════════════════════════\n\n";

    return 0;
}