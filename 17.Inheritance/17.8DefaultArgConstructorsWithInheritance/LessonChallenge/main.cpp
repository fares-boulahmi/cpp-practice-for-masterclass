#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// ============================================================================
// Problem 1: Easy 1 - Basic Vehicle Inheritance
// ============================================================================
// Description:
// Create a base class 'Vehicle' with default constructor that initializes
// wheels to 4 and a derived class 'Car' with default constructor that
// initializes doors to 4. When you create a Car object, both constructors
// should be called automatically.
//
// Task: Implement a function that creates a Car object and returns the
// total sum of wheels + doors.
//
// Input Format: None (uses default constructors)
// Output Format: Single integer (wheels + doors)
//
// Example:
// Car object created -> Vehicle constructor sets wheels=4, Car constructor sets doors=4
// Output: 8
//
// Constraints:
// - Use only default constructors
// - Vehicle base class, Car derived class
// ============================================================================

class Vehicle
{
public:
    int wheels;
    Vehicle()
    {
        wheels = 4;
        cout << "Vehicle default constructor called" << endl;
    }
};

class Car : public Vehicle
{
public:
    int doors;
    Car()
    {
        doors = 4;
        cout << "Car default constructor called" << endl;
    }
};

int problem1Solution()
{
    // TODO: Implement your solution here
    // Create a Car object and return wheels + doors
    // Hint: When you create a Car object, the Vehicle constructor is called first automatically
    return 0; // Replace with your solution
}

// ============================================================================
// Problem 2: Easy 2 - Employee Hierarchy Counter
// ============================================================================
// Description:
// Create a base class 'Person' that counts total persons created (use static)
// and a derived class 'Employee' that counts total employees created.
// Both use default constructors.
//
// Task: Create N Car objects and M Employee objects (in that order),
// then return the total count of all persons created.
//
// Input Format: Two integers N (cars) and M (employees)
// Output Format: Single integer (total person count)
//
// Example 1:
// Input: N=2, M=3
// Create 2 Employee objects: Person count becomes 2
// Create 3 more Employee objects: Person count becomes 5
// Output: 5
//
// Example 2:
// Input: N=0, M=5
// Output: 5
//
// Constraints:
// - 0 <= N, M <= 100
// - Use static variable in Person class
// - Each Employee creation increments Person count
// ============================================================================

class Person
{
public:
    static int personCount;
    Person()
    {
        personCount++;
        cout << "Person default constructor called" << endl;
    }
};

int Person::personCount = 0;

class Employee : public Person
{
public:
    static int employeeCount;
    Employee()
    {
        employeeCount++;
        cout << "Employee default constructor called" << endl;
    }
};

int Employee::employeeCount = 0;

int problem2Solution(int n, int m)
{
    // TODO: Implement your solution here
    // Create n+m Employee objects total and return Person::personCount
    // Hint: You may need to reset the static counters first or account for previous counts
    // Note: Each Employee object automatically calls Person constructor first
    return 0; // Replace with your solution
}

// ============================================================================
// Problem 3: Medium - Shape Hierarchy with Multiple Levels
// ============================================================================
// Description:
// Create a 3-level inheritance hierarchy:
// - Shape (base): default constructor sets dimension = 2
// - Polygon (derived from Shape): default constructor sets sides = 0
// - Rectangle (derived from Polygon): default constructor sets sides = 4, length = 5, width = 3
//
// Task: Create a Rectangle object and calculate:
// (dimension * sides) + (length * width)
//
// Input Format: None (uses default constructors)
// Output Format: Single integer result
//
// Example:
// Rectangle created:
//   - Shape constructor: dimension = 2
//   - Polygon constructor: sides = 0 (but Rectangle will override)
//   - Rectangle constructor: sides = 4, length = 5, width = 3
// Calculation: (2 * 4) + (5 * 3) = 8 + 15 = 23
// Output: 23
//
// Constraints:
// - Must use 3-level inheritance
// - All default constructors
// - Rectangle sets sides to 4 (overriding Polygon's 0)
// ============================================================================

class Shape
{
public:
    int dimension;
    Shape()
    {
        dimension = 2;
        cout << "Shape default constructor called" << endl;
    }
};

class Polygon : public Shape
{
public:
    int sides;
    Polygon()
    {
        sides = 0;
        cout << "Polygon default constructor called" << endl;
    }
};

class Rectangle : public Polygon
{
public:
    int length;
    int width;
    Rectangle()
    {
        sides = 4; // Override the 0 from Polygon
        length = 5;
        width = 3;
        cout << "Rectangle default constructor called" << endl;
    }
};

int problem3Solution()
{
    // TODO: Implement your solution here
    // Create a Rectangle object and return (dimension * sides) + (length * width)
    // Hint: All three constructors are called in order: Shape -> Polygon -> Rectangle
    return 0; // Replace with your solution
}

// ============================================================================
// Problem 4: Hard - Complex Initialization Chain Calculator
// ============================================================================
// Description:
// Create a hierarchy that simulates initialization steps:
// - Base (base class): multiplier = 1
// - Level1 (derived from Base): multiplier *= 2, adds 10 to sum
// - Level2 (derived from Level1): multiplier *= 3, adds 20 to sum
// - Level3 (derived from Level2): multiplier *= 5, adds 30 to sum
//
// Each class has a default constructor. Base has sum=0.
// Each derived class modifies the multiplier and adds to sum in its constructor.
//
// Task: Given a starting value V, create a Level3 object and calculate:
// V * multiplier + sum
//
// Input Format: Single integer V (starting value)
// Output Format: Single integer result
//
// Example 1:
// Input: V = 2
// Level3 object created:
//   - Base: multiplier=1, sum=0
//   - Level1: multiplier=1*2=2, sum=0+10=10
//   - Level2: multiplier=2*3=6, sum=10+20=30
//   - Level3: multiplier=6*5=30, sum=30+30=60
// Calculation: 2 * 30 + 60 = 60 + 60 = 120
// Output: 120
//
// Example 2:
// Input: V = 5
// Calculation: 5 * 30 + 60 = 150 + 60 = 210
// Output: 210
//
// Constraints:
// - -100 <= V <= 100
// - Use 4-level inheritance hierarchy
// - Each constructor modifies inherited members
// ============================================================================

class Base
{
public:
    int multiplier;
    int sum;
    Base()
    {
        multiplier = 1;
        sum = 0;
        cout << "Base default constructor called" << endl;
    }
};

class Level1 : public Base
{
public:
    Level1()
    {
        multiplier *= 2;
        sum += 10;
        cout << "Level1 default constructor called" << endl;
    }
};

class Level2 : public Level1
{
public:
    Level2()
    {
        multiplier *= 3;
        sum += 20;
        cout << "Level2 default constructor called" << endl;
    }
};

class Level3 : public Level2
{
public:
    Level3()
    {
        multiplier *= 5;
        sum += 30;
        cout << "Level3 default constructor called" << endl;
    }
};

int problem4Solution(int v)
{
    // TODO: Implement your solution here
    // Create a Level3 object and return v * multiplier + sum
    // Hint: Constructors are called in order Base->Level1->Level2->Level3
    // Each constructor modifies the inherited members
    return 0; // Replace with your solution
}

// ============================================================================
// TEST FUNCTIONS
// ============================================================================

void testProblem1()
{
    cout << "\n========== Testing Problem 1 ==========" << endl;

    // Test Case 1: Basic test - Car object creation
    // Step-by-step: Vehicle constructor sets wheels=4, Car constructor sets doors=4
    // Expected: 4 + 4 = 8
    cout << "\nTest 1: Basic Car creation" << endl;
    int result1 = problem1Solution();
    cout << "Expected: 8, Got: " << result1 << " -> "
         << (result1 == 8 ? "PASS" : "FAIL") << endl;

    // Test Case 2: Second Car object (should give same result)
    // Expected: 8
    cout << "\nTest 2: Another Car creation" << endl;
    int result2 = problem1Solution();
    cout << "Expected: 8, Got: " << result2 << " -> "
         << (result2 == 8 ? "PASS" : "FAIL") << endl;

    // Test Case 3: Third verification
    // Expected: 8
    cout << "\nTest 3: Third Car creation" << endl;
    int result3 = problem1Solution();
    cout << "Expected: 8, Got: " << result3 << " -> "
         << (result3 == 8 ? "PASS" : "FAIL") << endl;
}

void testProblem2()
{
    cout << "\n========== Testing Problem 2 ==========" << endl;

    // Reset counters before testing
    Person::personCount = 0;
    Employee::employeeCount = 0;

    // Test Case 1: Create 3 employees
    // Step-by-step: Each Employee calls Person constructor first
    // Employee 1: Person count = 1
    // Employee 2: Person count = 2
    // Employee 3: Person count = 3
    // Expected: 3
    cout << "\nTest 1: N=0, M=3" << endl;
    int result1 = problem2Solution(0, 3);
    cout << "Expected: 3, Got: " << result1 << " -> "
         << (result1 == 3 ? "PASS" : "FAIL") << endl;

    // Reset counters
    Person::personCount = 0;
    Employee::employeeCount = 0;

    // Test Case 2: Create 5 employees
    // Expected: 5
    cout << "\nTest 2: N=0, M=5" << endl;
    int result2 = problem2Solution(0, 5);
    cout << "Expected: 5, Got: " << result2 << " -> "
         << (result2 == 5 ? "PASS" : "FAIL") << endl;

    // Reset counters
    Person::personCount = 0;
    Employee::employeeCount = 0;

    // Test Case 3: Create 0 employees
    // Expected: 0
    cout << "\nTest 3: N=0, M=0" << endl;
    int result3 = problem2Solution(0, 0);
    cout << "Expected: 0, Got: " << result3 << " -> "
         << (result3 == 0 ? "PASS" : "FAIL") << endl;

    // Reset counters
    Person::personCount = 0;
    Employee::employeeCount = 0;

    // Test Case 4: Create 10 employees
    // Expected: 10
    cout << "\nTest 4: N=0, M=10" << endl;
    int result4 = problem2Solution(0, 10);
    cout << "Expected: 10, Got: " << result4 << " -> "
         << (result4 == 10 ? "PASS" : "FAIL") << endl;

    // Reset counters
    Person::personCount = 0;
    Employee::employeeCount = 0;

    // Test Case 5: Create 1 employee
    // Expected: 1
    cout << "\nTest 5: N=0, M=1" << endl;
    int result5 = problem2Solution(0, 1);
    cout << "Expected: 1, Got: " << result5 << " -> "
         << (result5 == 1 ? "PASS" : "FAIL") << endl;
}

void testProblem3()
{
    cout << "\n========== Testing Problem 3 ==========" << endl;

    // Test Case 1: Basic Rectangle creation
    // Step-by-step:
    // Shape constructor: dimension = 2
    // Polygon constructor: sides = 0
    // Rectangle constructor: sides = 4 (override), length = 5, width = 3
    // Calculation: (2 * 4) + (5 * 3) = 8 + 15 = 23
    // Expected: 23
    cout << "\nTest 1: Basic Rectangle calculation" << endl;
    int result1 = problem3Solution();
    cout << "Expected: 23, Got: " << result1 << " -> "
         << (result1 == 23 ? "PASS" : "FAIL") << endl;

    // Test Case 2: Second Rectangle (should be same)
    // Expected: 23
    cout << "\nTest 2: Second Rectangle calculation" << endl;
    int result2 = problem3Solution();
    cout << "Expected: 23, Got: " << result2 << " -> "
         << (result2 == 23 ? "PASS" : "FAIL") << endl;

    // Test Case 3: Third verification
    // Expected: 23
    cout << "\nTest 3: Third Rectangle calculation" << endl;
    int result3 = problem3Solution();
    cout << "Expected: 23, Got: " << result3 << " -> "
         << (result3 == 23 ? "PASS" : "FAIL") << endl;
}

void testProblem4()
{
    cout << "\n========== Testing Problem 4 ==========" << endl;

    // Test Case 1: V = 2
    // Step-by-step:
    // Base: multiplier=1, sum=0
    // Level1: multiplier=1*2=2, sum=0+10=10
    // Level2: multiplier=2*3=6, sum=10+20=30
    // Level3: multiplier=6*5=30, sum=30+30=60
    // Calculation: 2 * 30 + 60 = 60 + 60 = 120
    // Expected: 120
    cout << "\nTest 1: V=2" << endl;
    int result1 = problem4Solution(2);
    cout << "Expected: 120, Got: " << result1 << " -> "
         << (result1 == 120 ? "PASS" : "FAIL") << endl;

    // Test Case 2: V = 5
    // Calculation: 5 * 30 + 60 = 150 + 60 = 210
    // Expected: 210
    cout << "\nTest 2: V=5" << endl;
    int result2 = problem4Solution(5);
    cout << "Expected: 210, Got: " << result2 << " -> "
         << (result2 == 210 ? "PASS" : "FAIL") << endl;

    // Test Case 3: V = 0
    // Calculation: 0 * 30 + 60 = 0 + 60 = 60
    // Expected: 60
    cout << "\nTest 3: V=0" << endl;
    int result3 = problem4Solution(0);
    cout << "Expected: 60, Got: " << result3 << " -> "
         << (result3 == 60 ? "PASS" : "FAIL") << endl;

    // Test Case 4: V = -3
    // Calculation: -3 * 30 + 60 = -90 + 60 = -30
    // Expected: -30
    cout << "\nTest 4: V=-3" << endl;
    int result4 = problem4Solution(-3);
    cout << "Expected: -30, Got: " << result4 << " -> "
         << (result4 == -30 ? "PASS" : "FAIL") << endl;

    // Test Case 5: V = 10
    // Calculation: 10 * 30 + 60 = 300 + 60 = 360
    // Expected: 360
    cout << "\nTest 5: V=10" << endl;
    int result5 = problem4Solution(10);
    cout << "Expected: 360, Got: " << result5 << " -> "
         << (result5 == 360 ? "PASS" : "FAIL") << endl;

    // Test Case 6: V = 1
    // Calculation: 1 * 30 + 60 = 30 + 60 = 90
    // Expected: 90
    cout << "\nTest 6: V=1" << endl;
    int result6 = problem4Solution(1);
    cout << "Expected: 90, Got: " << result6 << " -> "
         << (result6 == 90 ? "PASS" : "FAIL") << endl;

    // Test Case 7: V = -10
    // Calculation: -10 * 30 + 60 = -300 + 60 = -240
    // Expected: -240
    cout << "\nTest 7: V=-10" << endl;
    int result7 = problem4Solution(-10);
    cout << "Expected: -240, Got: " << result7 << " -> "
         << (result7 == -240 ? "PASS" : "FAIL") << endl;

    // Test Case 8: V = 100
    // Calculation: 100 * 30 + 60 = 3000 + 60 = 3060
    // Expected: 3060
    cout << "\nTest 8: V=100" << endl;
    int result8 = problem4Solution(100);
    cout << "Expected: 3060, Got: " << result8 << " -> "
         << (result8 == 3060 ? "PASS" : "FAIL") << endl;
}

int main()
{
    int choice;
    cout << "==================================================" << endl;
    cout << "Default Constructors with Inheritance - Practice" << endl;
    cout << "==================================================" << endl;
    cout << "Choose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy) - Basic Vehicle Inheritance" << endl;
    cout << "2. Problem 2 (Easy-Medium) - Employee Counter" << endl;
    cout << "3. Problem 3 (Medium) - Shape Hierarchy" << endl;
    cout << "4. Problem 4 (Hard) - Initialization Chain" << endl;
    cout << "5. Test All Problems" << endl;
    cout << "Enter choice: ";
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