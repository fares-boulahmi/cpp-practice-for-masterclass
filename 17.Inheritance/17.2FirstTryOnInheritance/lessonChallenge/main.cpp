#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// ============================================================================
// Problem 1: Easy 1 - Animal Sound System
// ============================================================================
// Description:
// Create a base class Animal with a name attribute and a method makeSound().
// Create a derived class Dog that inherits from Animal and overrides makeSound().
// The Dog class should also have an additional attribute: breed.
//
// Input Format:
// - Dog's name (string)
// - Dog's breed (string)
//
// Output Format:
// - Print the dog's name, breed, and the sound it makes
//
// Example 1:
// Input: name = "Buddy", breed = "Golden Retriever"
// Output: "Buddy the Golden Retriever says: Woof!"
//
// Example 2:
// Input: name = "Max", breed = "Bulldog"
// Output: "Max the Bulldog says: Woof!"
//
// Constraints:
// - Name and breed are non-empty strings
// - All dogs make the same sound "Woof!"

class Animal
{
public:
    string name;

    Animal() = default;
    Animal(string n) : name(n) {}

    void makeSound()
    {
        cout << name << " makes a sound" << endl;
    }
};

class Dog : public Animal
{
    // TODO: Inherit from Animal
    // TODO: Add breed attribute
    // TODO: Implement constructor that takes name and breed
    // TODO: Override makeSound() to print: "[name] the [breed] says: Woof!"
    // Hint: Use the base class constructor in the initialization list

public:
    Dog() = default;
    Dog(string name, string breed)
    {
        this->name = name;
        this->breed = breed;
    };
    void makeSound()
    {
        cout << this->name << " the " << this->breed << " says: Woof!" << endl;
    }

private:
    string breed{};
};

void problem1Solution(string name, string breed)
{
    // TODO: Create a Dog object and call its makeSound() method
    // Hint: Dog myDog(name, breed); then call the method
    Dog myDog(name, breed);
    myDog.makeSound();
}

// ============================================================================
// Problem 2: Easy 2 - Shape Area Calculator
// ============================================================================
// Description:
// Create a base class Shape with attributes for width and height.
// Create derived classes Rectangle and Triangle that inherit from Shape.
// Each derived class should calculate its area differently:
// - Rectangle area = width * height
// - Triangle area = (width * height) / 2.0
//
// Input Format:
// - Shape type (string: "rectangle" or "triangle")
// - Width (double)
// - Height (double)
//
// Output Format:
// - Return the area as a double
//
// Example 1:
// Input: type = "rectangle", width = 5.0, height = 3.0
// Calculation: 5.0 * 3.0 = 15.0
// Output: 15.0
//
// Example 2:
// Input: type = "triangle", width = 4.0, height = 6.0
// Calculation: (4.0 * 6.0) / 2.0 = 24.0 / 2.0 = 12.0
// Output: 12.0
//
// Constraints:
// - Width and height are positive numbers
// - Type is either "rectangle" or "triangle"

class Shape
{
public:
    double width;
    double height;
    Shape() = default;
    Shape(double w, double h) : width(w), height(h) {}
};

class Rectangle : public Shape
{
    // TODO: Inherit from Shape
    // TODO: Implement constructor
    // TODO: Implement getArea() method that returns width * height
    // Hint: Use base class members directly
public:
    Rectangle() = default;
    Rectangle(double width, double height)
    {
        this->height = height;
        this->width = width;
    }
    double getArea()
    {
        return this->height * this->width;
    }
};

class Triangle : public Shape
{
    // TODO: Inherit from Shape
    // TODO: Implement constructor
    // TODO: Implement getArea() method that returns (width * height) / 2.0
    // Hint: Remember to use 2.0 (not 2) for proper division
public:
    Triangle() = default;
    Triangle(double width, double height)
    {
        this->height = height;
        this->width = width;
    }
    double getArea()
    {
        return (this->height * this->width) / 2.0;
    }
};

double problem2Solution(string type, double width, double height)
{
    // TODO: Create appropriate shape object based on type and return its area
    // Hint: Use if-else to check type, create object, call getArea()
    double result;
    if (type == "rectangle")
    {
        Rectangle rectangle(width, height);
        result = rectangle.getArea();
    }
    else
    {
        Triangle triangle(width, height);
        result = triangle.getArea();
    }
    return result;
}

// ============================================================================
// Problem 3: Medium - Employee Salary System
// ============================================================================
// Description:
// Create a base class Employee with name and baseSalary attributes.
// Create derived classes:
// - Manager: has teamSize attribute, total salary = baseSalary + (teamSize * 500)
// - Developer: has programmingLanguage attribute, total salary = baseSalary + 1000
// - Intern: has monthsCompleted attribute, total salary = baseSalary * (monthsCompleted / 12.0)
//
// Input Format:
// - Employee type (string: "manager", "developer", or "intern")
// - Name (string)
// - Base salary (double)
// - Additional parameter (int: teamSize, or months, or 0 for developer)
//
// Output Format:
// - Return total salary as double
//
// Example 1:
// Input: type = "manager", name = "John", baseSalary = 5000.0, teamSize = 10
// Calculation: 5000.0 + (10 * 500) = 5000.0 + 5000.0 = 10000.0
// Output: 10000.0
//
// Example 2:
// Input: type = "developer", name = "Alice", baseSalary = 4000.0, extra = 0
// Calculation: 4000.0 + 1000 = 5000.0
// Output: 5000.0
//
// Example 3:
// Input: type = "intern", name = "Bob", baseSalary = 2400.0, monthsCompleted = 6
// Calculation: 2400.0 * (6 / 12.0) = 2400.0 * 0.5 = 1200.0
// Output: 1200.0
//
// Constraints:
// - Base salary is positive
// - Team size is non-negative
// - Months completed is between 0 and 12

class Employee
{
public:
    string name;
    double baseSalary;

    Employee(string n, double salary) : name(n), baseSalary(salary) {}
};

class Manager
{
    // TODO: Inherit from Employee
    // TODO: Add teamSize attribute
    // TODO: Implement constructor
    // TODO: Implement getTotalSalary() that returns baseSalary + (teamSize * 500)
    // Hint: Initialize base class in constructor initialization list
};

class Developer
{
    // TODO: Inherit from Employee
    // TODO: Add programmingLanguage attribute (you can set it in constructor)
    // TODO: Implement constructor
    // TODO: Implement getTotalSalary() that returns baseSalary + 1000
};

class Intern
{
    // TODO: Inherit from Employee
    // TODO: Add monthsCompleted attribute
    // TODO: Implement constructor
    // TODO: Implement getTotalSalary() that returns baseSalary * (monthsCompleted / 12.0)
    // Hint: Use 12.0 (not 12) for proper floating-point division
};

double problem3Solution(string type, string name, double baseSalary, int extra)
{
    // TODO: Create appropriate employee object and return total salary
    // Hint: Use if-else to determine type, for Developer use extra = 0
    return 0.0;
}

// ============================================================================
// Problem 4: Hard - Vehicle Fleet Management
// ============================================================================
// Description:
// Create a base class Vehicle with brand, year, and basePrice attributes.
// Create derived classes:
// - Car: has numDoors, finalPrice = basePrice + (numDoors * 200)
// - Motorcycle: has engineCC, finalPrice = basePrice + (engineCC * 2.5)
// - Truck: has cargoCapacity, finalPrice = basePrice + (cargoCapacity * 50)
//
// Calculate the total value of a fleet of mixed vehicles.
//
// Input Format:
// - Number of vehicles (int)
// - For each vehicle:
//   - Type (string: "car", "motorcycle", or "truck")
//   - Brand (string)
//   - Year (int)
//   - Base price (double)
//   - Extra parameter (int: doors, engineCC, or capacity)
//
// Output Format:
// - Return total fleet value as double
//
// Example 1:
// Input: 3 vehicles
//   Vehicle 1: type = "car", brand = "Toyota", year = 2020, basePrice = 20000.0, doors = 4
//   Vehicle 2: type = "motorcycle", brand = "Harley", year = 2021, basePrice = 15000.0, engineCC = 1200
//   Vehicle 3: type = "truck", brand = "Ford", year = 2019, basePrice = 30000.0, capacity = 500
//
// Calculation:
//   Car: 20000.0 + (4 * 200) = 20000.0 + 800.0 = 20800.0
//   Motorcycle: 15000.0 + (1200 * 2.5) = 15000.0 + 3000.0 = 18000.0
//   Truck: 30000.0 + (500 * 50) = 30000.0 + 25000.0 = 55000.0
//   Total: 20800.0 + 18000.0 + 55000.0 = 93800.0
// Output: 93800.0
//
// Constraints:
// - Number of vehicles: 1-100
// - Base price is positive
// - Year is between 1900 and 2025
// - All extra parameters are non-negative

class Vehicle
{
public:
    string brand;
    int year;
    double basePrice;

    Vehicle(string b, int y, double price) : brand(b), year(y), basePrice(price) {}
};

class Car
{
    // TODO: Inherit from Vehicle
    // TODO: Add numDoors attribute
    // TODO: Implement constructor
    // TODO: Implement getFinalPrice() that returns basePrice + (numDoors * 200)
};

class Motorcycle
{
    // TODO: Inherit from Vehicle
    // TODO: Add engineCC attribute
    // TODO: Implement constructor
    // TODO: Implement getFinalPrice() that returns basePrice + (engineCC * 2.5)
};

class Truck
{
    // TODO: Inherit from Vehicle
    // TODO: Add cargoCapacity attribute
    // TODO: Implement constructor
    // TODO: Implement getFinalPrice() that returns basePrice + (cargoCapacity * 50)
};

double problem4Solution(vector<string> &types, vector<string> &brands,
                        vector<int> &years, vector<double> &basePrices,
                        vector<int> &extras)
{
    // TODO: Calculate total fleet value by creating appropriate vehicle objects
    // Hint: Loop through vectors, create objects based on type, sum all final prices
    return 0.0;
}

// ============================================================================
// TEST FUNCTIONS
// ============================================================================

void testProblem1()
{
    cout << "\n=== Testing Problem 1: Animal Sound System ===" << endl;

    // Test Case 1: Basic dog
    cout << "Test 1 (Basic dog): ";
    cout << "Expected: 'Buddy the Golden Retriever says: Woof!'" << endl;
    cout << "Your output: ";
    problem1Solution("Buddy", "Golden Retriever");

    // Test Case 2: Single word breed
    cout << "\nTest 2 (Single word breed): ";
    cout << "Expected: 'Max the Bulldog says: Woof!'" << endl;
    cout << "Your output: ";
    problem1Solution("Max", "Bulldog");

    // Test Case 3: Long name
    cout << "\nTest 3 (Long name): ";
    cout << "Expected: 'Sir Barksalot the Poodle says: Woof!'" << endl;
    cout << "Your output: ";
    problem1Solution("Sir Barksalot", "Poodle");

    // Test Case 4: Multiple word breed
    cout << "\nTest 4 (Multiple word breed): ";
    cout << "Expected: 'Charlie the German Shepherd says: Woof!'" << endl;
    cout << "Your output: ";
    problem1Solution("Charlie", "German Shepherd");

    // Test Case 5: Short name
    cout << "\nTest 5 (Short name): ";
    cout << "Expected: 'Rex the Husky says: Woof!'" << endl;
    cout << "Your output: ";
    problem1Solution("Rex", "Husky");

    cout << "\n";
}

void testProblem2()
{
    cout << "\n=== Testing Problem 2: Shape Area Calculator ===" << endl;

    // Test Case 1: Rectangle with integers that result in whole number
    // Calculation: 5.0 * 3.0 = 15.0
    cout << "Test 1: " << (problem2Solution("rectangle", 5.0, 3.0) == 15.0 ? "PASS" : "FAIL");
    cout << " (Expected: 15.0, Rectangle 5x3)" << endl;

    // Test Case 2: Triangle with integers
    // Calculation: (4.0 * 6.0) / 2.0 = 24.0 / 2.0 = 12.0
    cout << "Test 2: " << (problem2Solution("triangle", 4.0, 6.0) == 12.0 ? "PASS" : "FAIL");
    cout << " (Expected: 12.0, Triangle 4x6)" << endl;

    // Test Case 3: Rectangle with decimals
    // Calculation: 7.5 * 2.0 = 15.0
    cout << "Test 3: " << (problem2Solution("rectangle", 7.5, 2.0) == 15.0 ? "PASS" : "FAIL");
    cout << " (Expected: 15.0, Rectangle 7.5x2)" << endl;

    // Test Case 4: Triangle with decimals
    // Calculation: (3.0 * 5.0) / 2.0 = 15.0 / 2.0 = 7.5
    cout << "Test 4: " << (problem2Solution("triangle", 3.0, 5.0) == 7.5 ? "PASS" : "FAIL");
    cout << " (Expected: 7.5, Triangle 3x5)" << endl;

    // Test Case 5: Square (rectangle with equal sides)
    // Calculation: 10.0 * 10.0 = 100.0
    cout << "Test 5: " << (problem2Solution("rectangle", 10.0, 10.0) == 100.0 ? "PASS" : "FAIL");
    cout << " (Expected: 100.0, Square 10x10)" << endl;

    // Test Case 6: Triangle with result that has decimals
    // Calculation: (7.0 * 3.0) / 2.0 = 21.0 / 2.0 = 10.5
    cout << "Test 6: " << (problem2Solution("triangle", 7.0, 3.0) == 10.5 ? "PASS" : "FAIL");
    cout << " (Expected: 10.5, Triangle 7x3)" << endl;

    // Test Case 7: Small dimensions
    // Calculation: 1.0 * 1.0 = 1.0
    cout << "Test 7: " << (problem2Solution("rectangle", 1.0, 1.0) == 1.0 ? "PASS" : "FAIL");
    cout << " (Expected: 1.0, Rectangle 1x1)" << endl;

    // Test Case 8: Large dimensions
    // Calculation: (100.0 * 50.0) / 2.0 = 5000.0 / 2.0 = 2500.0
    cout << "Test 8: " << (problem2Solution("triangle", 100.0, 50.0) == 2500.0 ? "PASS" : "FAIL");
    cout << " (Expected: 2500.0, Triangle 100x50)" << endl;

    cout << "\n";
}

void testProblem3()
{
    cout << "\n=== Testing Problem 3: Employee Salary System ===" << endl;

    // Test Case 1: Manager with 10 team members
    // Calculation: 5000.0 + (10 * 500) = 5000.0 + 5000.0 = 10000.0
    cout << "Test 1: " << (problem3Solution("manager", "John", 5000.0, 10) == 10000.0 ? "PASS" : "FAIL");
    cout << " (Expected: 10000.0, Manager with team of 10)" << endl;

    // Test Case 2: Developer with standard bonus
    // Calculation: 4000.0 + 1000 = 5000.0
    cout << "Test 2: " << (problem3Solution("developer", "Alice", 4000.0, 0) == 5000.0 ? "PASS" : "FAIL");
    cout << " (Expected: 5000.0, Developer)" << endl;

    // Test Case 3: Intern with 6 months completed (half year)
    // Calculation: 2400.0 * (6 / 12.0) = 2400.0 * 0.5 = 1200.0
    cout << "Test 3: " << (problem3Solution("intern", "Bob", 2400.0, 6) == 1200.0 ? "PASS" : "FAIL");
    cout << " (Expected: 1200.0, Intern 6 months)" << endl;

    // Test Case 4: Manager with no team (0 members)
    // Calculation: 6000.0 + (0 * 500) = 6000.0 + 0.0 = 6000.0
    cout << "Test 4: " << (problem3Solution("manager", "Sarah", 6000.0, 0) == 6000.0 ? "PASS" : "FAIL");
    cout << " (Expected: 6000.0, Manager with no team)" << endl;

    // Test Case 5: Intern with 12 months (full year)
    // Calculation: 3000.0 * (12 / 12.0) = 3000.0 * 1.0 = 3000.0
    cout << "Test 5: " << (problem3Solution("intern", "Mike", 3000.0, 12) == 3000.0 ? "PASS" : "FAIL");
    cout << " (Expected: 3000.0, Intern 12 months)" << endl;

    // Test Case 6: Manager with large team
    // Calculation: 8000.0 + (20 * 500) = 8000.0 + 10000.0 = 18000.0
    cout << "Test 6: " << (problem3Solution("manager", "David", 8000.0, 20) == 18000.0 ? "PASS" : "FAIL");
    cout << " (Expected: 18000.0, Manager with team of 20)" << endl;

    // Test Case 7: Intern with 3 months (quarter year)
    // Calculation: 2400.0 * (3 / 12.0) = 2400.0 * 0.25 = 600.0
    cout << "Test 7: " << (problem3Solution("intern", "Emma", 2400.0, 3) == 600.0 ? "PASS" : "FAIL");
    cout << " (Expected: 600.0, Intern 3 months)" << endl;

    // Test Case 8: Developer with high base salary
    // Calculation: 7000.0 + 1000 = 8000.0
    cout << "Test 8: " << (problem3Solution("developer", "Chris", 7000.0, 0) == 8000.0 ? "PASS" : "FAIL");
    cout << " (Expected: 8000.0, Developer high salary)" << endl;

    cout << "\n";
}

void testProblem4()
{
    cout << "\n=== Testing Problem 4: Vehicle Fleet Management ===" << endl;

    // Test Case 1: Mixed fleet of 3 vehicles
    // Car: 20000.0 + (4 * 200) = 20000.0 + 800.0 = 20800.0
    // Motorcycle: 15000.0 + (1200 * 2.5) = 15000.0 + 3000.0 = 18000.0
    // Truck: 30000.0 + (500 * 50) = 30000.0 + 25000.0 = 55000.0
    // Total: 20800.0 + 18000.0 + 55000.0 = 93800.0
    {
        vector<string> types = {"car", "motorcycle", "truck"};
        vector<string> brands = {"Toyota", "Harley", "Ford"};
        vector<int> years = {2020, 2021, 2019};
        vector<double> basePrices = {20000.0, 15000.0, 30000.0};
        vector<int> extras = {4, 1200, 500};
        cout << "Test 1: " << (problem4Solution(types, brands, years, basePrices, extras) == 93800.0 ? "PASS" : "FAIL");
        cout << " (Expected: 93800.0, Mixed fleet of 3)" << endl;
    }

    // Test Case 2: Single car with 2 doors
    // Car: 25000.0 + (2 * 200) = 25000.0 + 400.0 = 25400.0
    {
        vector<string> types = {"car"};
        vector<string> brands = {"Honda"};
        vector<int> years = {2022};
        vector<double> basePrices = {25000.0};
        vector<int> extras = {2};
        cout << "Test 2: " << (problem4Solution(types, brands, years, basePrices, extras) == 25400.0 ? "PASS" : "FAIL");
        cout << " (Expected: 25400.0, Single 2-door car)" << endl;
    }

    // Test Case 3: Two motorcycles
    // Motorcycle 1: 10000.0 + (600 * 2.5) = 10000.0 + 1500.0 = 11500.0
    // Motorcycle 2: 12000.0 + (800 * 2.5) = 12000.0 + 2000.0 = 14000.0
    // Total: 11500.0 + 14000.0 = 25500.0
    {
        vector<string> types = {"motorcycle", "motorcycle"};
        vector<string> brands = {"Yamaha", "Kawasaki"};
        vector<int> years = {2020, 2021};
        vector<double> basePrices = {10000.0, 12000.0};
        vector<int> extras = {600, 800};
        cout << "Test 3: " << (problem4Solution(types, brands, years, basePrices, extras) == 25500.0 ? "PASS" : "FAIL");
        cout << " (Expected: 25500.0, Two motorcycles)" << endl;
    }

    // Test Case 4: Fleet with minimum extras
    // Car: 15000.0 + (0 * 200) = 15000.0
    // Motorcycle: 8000.0 + (0 * 2.5) = 8000.0
    // Truck: 20000.0 + (0 * 50) = 20000.0
    // Total: 15000.0 + 8000.0 + 20000.0 = 43000.0
    {
        vector<string> types = {"car", "motorcycle", "truck"};
        vector<string> brands = {"Kia", "Suzuki", "Chevy"};
        vector<int> years = {2018, 2019, 2020};
        vector<double> basePrices = {15000.0, 8000.0, 20000.0};
        vector<int> extras = {0, 0, 0};
        cout << "Test 4: " << (problem4Solution(types, brands, years, basePrices, extras) == 43000.0 ? "PASS" : "FAIL");
        cout << " (Expected: 43000.0, Fleet with zero extras)" << endl;
    }

    // Test Case 5: Large truck fleet
    // Truck 1: 35000.0 + (1000 * 50) = 35000.0 + 50000.0 = 85000.0
    // Truck 2: 40000.0 + (800 * 50) = 40000.0 + 40000.0 = 80000.0
    // Total: 85000.0 + 80000.0 = 165000.0
    {
        vector<string> types = {"truck", "truck"};
        vector<string> brands = {"Volvo", "Scania"};
        vector<int> years = {2021, 2022};
        vector<double> basePrices = {35000.0, 40000.0};
        vector<int> extras = {1000, 800};
        cout << "Test 5: " << (problem4Solution(types, brands, years, basePrices, extras) == 165000.0 ? "PASS" : "FAIL");
        cout << " (Expected: 165000.0, Two large trucks)" << endl;
    }

    // Test Case 6: Four-car fleet
    // Car 1: 18000.0 + (4 * 200) = 18000.0 + 800.0 = 18800.0
    // Car 2: 22000.0 + (2 * 200) = 22000.0 + 400.0 = 22400.0
    // Car 3: 19000.0 + (4 * 200) = 19000.0 + 800.0 = 19800.0
    // Car 4: 16000.0 + (2 * 200) = 16000.0 + 400.0 = 16400.0
    // Total: 18800.0 + 22400.0 + 19800.0 + 16400.0 = 77400.0
    {
        vector<string> types = {"car", "car", "car", "car"};
        vector<string> brands = {"Mazda", "Subaru", "Nissan", "Hyundai"};
        vector<int> years = {2020, 2021, 2019, 2022};
        vector<double> basePrices = {18000.0, 22000.0, 19000.0, 16000.0};
        vector<int> extras = {4, 2, 4, 2};
        cout << "Test 6: " << (problem4Solution(types, brands, years, basePrices, extras) == 77400.0 ? "PASS" : "FAIL");
        cout << " (Expected: 77400.0, Four cars)" << endl;
    }

    // Test Case 7: High-end motorcycle
    // Motorcycle: 25000.0 + (2000 * 2.5) = 25000.0 + 5000.0 = 30000.0
    {
        vector<string> types = {"motorcycle"};
        vector<string> brands = {"Ducati"};
        vector<int> years = {2023};
        vector<double> basePrices = {25000.0};
        vector<int> extras = {2000};
        cout << "Test 7: " << (problem4Solution(types, brands, years, basePrices, extras) == 30000.0 ? "PASS" : "FAIL");
        cout << " (Expected: 30000.0, High-end motorcycle)" << endl;
    }

    // Test Case 8: Large mixed fleet
    // Car: 20000.0 + (4 * 200) = 20000.0 + 800.0 = 20800.0
    // Truck: 35000.0 + (600 * 50) = 35000.0 + 30000.0 = 65000.0
    // Motorcycle: 15000.0 + (1000 * 2.5) = 15000.0 + 2500.0 = 17500.0
    // Car: 18000.0 + (2 * 200) = 18000.0 + 400.0 = 18400.0
    // Truck: 32000.0 + (700 * 50) = 32000.0 + 35000.0 = 67000.0
    // Total: 20800.0 + 65000.0 + 17500.0 + 18400.0 + 67000.0 = 188700.0
    {
        vector<string> types = {"car", "truck", "motorcycle", "car", "truck"};
        vector<string> brands = {"BMW", "Mercedes", "Honda", "Audi", "MAN"};
        vector<int> years = {2021, 2020, 2022, 2021, 2019};
        vector<double> basePrices = {20000.0, 35000.0, 15000.0, 18000.0, 32000.0};
        vector<int> extras = {4, 600, 1000, 2, 700};
        cout << "Test 8: " << (problem4Solution(types, brands, years, basePrices, extras) == 188700.0 ? "PASS" : "FAIL");
        cout << " (Expected: 188700.0, Large mixed fleet of 5)" << endl;
    }

    cout << "\n";
}

// ============================================================================
// MAIN FUNCTION
// ============================================================================

int main()
{
    int choice;
    cout << "========================================" << endl;
    cout << "  C++ Inheritance Practice Problems" << endl;
    cout << "========================================" << endl;
    cout << "Choose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy 1): Animal Sound System" << endl;
    cout << "2. Problem 2 (Easy 2): Shape Area Calculator" << endl;
    cout << "3. Problem 3 (Medium): Employee Salary System" << endl;
    cout << "4. Problem 4 (Hard): Vehicle Fleet Management" << endl;
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
        cout << "Invalid choice! Please select 1-5." << endl;
    }

    return 0;
}