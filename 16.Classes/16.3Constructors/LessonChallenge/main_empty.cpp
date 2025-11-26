#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// ============================================================================
// Problem 1: Easy 1 - Rectangle Class with Constructors
// ============================================================================
// Create a Rectangle class that stores length and width.
// Implement multiple constructors:
// 1. Default constructor: sets length=1, width=1
// 2. Parameterized constructor: takes length and width
// 3. Constructor that takes only one parameter (creates a square)
//
// Add a method getArea() that returns the area of the rectangle.
//
// Input Format: Constructor parameters (length, width or single value)
// Output Format: Area of rectangle (length * width)
//
// Example 1: Rectangle() -> area = 1 (default 1x1)
// Example 2: Rectangle(5, 3) -> area = 15 (5*3)
// Example 3: Rectangle(4) -> area = 16 (4*4 square)
//
// Constraints: 
// - length, width >= 0
// - All measurements are integers

class Rectangle {
private:
    int length;
    int width;

public:
    // TODO: Implement default constructor (length=1, width=1)
    
    // TODO: Implement parameterized constructor (length, width)
    
    // TODO: Implement single parameter constructor (creates square)
    
    int getArea() {
        // TODO: Return area (length * width)
        return 0;
    }
};

// ============================================================================
// Problem 2: Easy 2 - Bank Account with Constructor Validation
// ============================================================================
// Create a BankAccount class that stores account holder name and balance.
// Implement constructors with validation:
// 1. Constructor with name and initial balance
// 2. Constructor with only name (default balance = 0)
// 3. If initial balance is negative, set it to 0 instead
//
// Add methods:
// - getBalance(): returns current balance
// - deposit(amount): adds amount to balance (if amount > 0)
// - withdraw(amount): subtracts amount if sufficient balance, returns true if successful
//
// Input Format: Constructor parameters (name, balance)
// Output Format: Balance after operations
//
// Example 1: BankAccount("Alice", 100) -> balance = 100
// Example 2: BankAccount("Bob", -50) -> balance = 0 (negative rejected)
// Example 3: BankAccount("Carol") -> balance = 0 (default)
// Example 4: account.deposit(50) then account.withdraw(30) -> balance = 20
//
// Constraints:
// - name is non-empty string
// - balance operations use integers

class BankAccount {
private:
    string accountHolder;
    int balance;

public:
    // TODO: Implement constructor with name and balance (validate balance >= 0)
    
    // TODO: Implement constructor with only name (default balance = 0)
    
    int getBalance() {
        // TODO: Return current balance
        return 0;
    }
    
    void deposit(int amount) {
        // TODO: Add amount to balance if amount > 0
    }
    
    bool withdraw(int amount) {
        // TODO: Subtract amount if balance >= amount, return success status
        return false;
    }
};

// ============================================================================
// Problem 3: Medium - Student Grade Manager with Copy Constructor
// ============================================================================
// Create a Student class that stores:
// - Student name
// - Dynamic array of grades (use pointer)
// - Number of grades
//
// Implement:
// 1. Parameterized constructor: takes name and number of grades to allocate
// 2. Copy constructor: performs deep copy of grades array
// 3. Destructor: deallocates dynamic memory
// 4. setGrade(index, grade): sets grade at index
// 5. getAverage(): returns average of all grades
//
// Input Format: Constructor (name, count), setGrade operations
// Output Format: Average grade (rounded to integer)
//
// Example: 
// Student s1("John", 3)
// s1.setGrade(0, 85), s1.setGrade(1, 90), s1.setGrade(2, 75)
// Average = (85+90+75)/3 = 250/3 = 83.33... = 83 (integer division)
//
// Constraints:
// - 1 <= number of grades <= 100
// - 0 <= grade <= 100
// - Must use dynamic memory allocation
// - Must implement deep copy in copy constructor

class Student {
private:
    string name;
    int* grades;
    int numGrades;

public:
    // TODO: Implement parameterized constructor (allocate dynamic array)
    
    // TODO: Implement copy constructor (deep copy the grades array)
    
    // TODO: Implement destructor (deallocate dynamic memory)
    
    void setGrade(int index, int grade) {
        // TODO: Set grade at index (validate index)
    }
    
    int getAverage() {
        // TODO: Calculate and return average (integer division)
        return 0;
    }
};

// ============================================================================
// Problem 4: Hard - Matrix Class with Multiple Constructor Types
// ============================================================================
// Create a Matrix class for 2D integer arrays with:
// - Dynamic 2D array (pointer to pointer)
// - Rows and columns count
//
// Implement:
// 1. Default constructor: creates 2x2 matrix filled with 0
// 2. Parameterized constructor: takes rows, cols (fills with 0)
// 3. Constructor with initialization value: takes rows, cols, initValue
// 4. Copy constructor: performs deep copy
// 5. Destructor: deallocates all dynamic memory
// 6. setValue(row, col, value): sets value at position
// 7. getValue(row, col): gets value at position
// 8. getSumDiagonal(): returns sum of main diagonal elements
//
// Input Format: Constructor parameters, setValue operations
// Output Format: Sum of diagonal elements
//
// Example:
// Matrix m(3, 3, 0)  // 3x3 matrix filled with 0
// m.setValue(0,0,5), m.setValue(1,1,10), m.setValue(2,2,15)
// getSumDiagonal() = 5+10+15 = 30
//
// Constraints:
// - 1 <= rows, cols <= 100
// - -1000 <= values <= 1000
// - Must properly manage dynamic 2D array
// - Must implement deep copy
// - Diagonal sum only counts min(rows,cols) elements

class Matrix {
private:
    int** data;
    int rows;
    int cols;

public:
    // TODO: Implement default constructor (2x2, filled with 0)
    
    // TODO: Implement parameterized constructor (rows, cols, filled with 0)
    
    // TODO: Implement constructor with init value (rows, cols, initValue)
    
    // TODO: Implement copy constructor (deep copy the 2D array)
    
    // TODO: Implement destructor (deallocate all memory properly)
    
    void setValue(int row, int col, int value) {
        // TODO: Set value at [row][col] (validate indices)
    }
    
    int getValue(int row, int col) {
        // TODO: Return value at [row][col]
        return 0;
    }
    
    int getSumDiagonal() {
        // TODO: Calculate sum of main diagonal (0,0), (1,1), (2,2)...
        return 0;
    }
};

// ============================================================================
// TEST FUNCTIONS
// ============================================================================

void testProblem1() {
    cout << "\n=== Testing Problem 1: Rectangle Class ===" << endl;
    
    // Test Case 1: Default constructor
    // Calculation: 1 * 1 = 1
    // Expected: 1
    Rectangle r1;
    cout << "Test 1 (default constructor): " << (r1.getArea() == 1 ? "PASS" : "FAIL") << " (Expected: 1)" << endl;
    
    // Test Case 2: Parameterized constructor - normal rectangle
    // Calculation: 5 * 3 = 15
    // Expected: 15
    Rectangle r2(5, 3);
    cout << "Test 2 (5x3 rectangle): " << (r2.getArea() == 15 ? "PASS" : "FAIL") << " (Expected: 15)" << endl;
    
    // Test Case 3: Single parameter constructor - square
    // Calculation: 4 * 4 = 16
    // Expected: 16
    Rectangle r3(4);
    cout << "Test 3 (4x4 square): " << (r3.getArea() == 16 ? "PASS" : "FAIL") << " (Expected: 16)" << endl;
    
    // Test Case 4: Large rectangle
    // Calculation: 10 * 20 = 200
    // Expected: 200
    Rectangle r4(10, 20);
    cout << "Test 4 (10x20 rectangle): " << (r4.getArea() == 200 ? "PASS" : "FAIL") << " (Expected: 200)" << endl;
    
    // Test Case 5: Single parameter - larger square
    // Calculation: 7 * 7 = 49
    // Expected: 49
    Rectangle r5(7);
    cout << "Test 5 (7x7 square): " << (r5.getArea() == 49 ? "PASS" : "FAIL") << " (Expected: 49)" << endl;
    
    // Test Case 6: Zero area rectangle
    // Calculation: 0 * 5 = 0
    // Expected: 0
    Rectangle r6(0, 5);
    cout << "Test 6 (0x5 rectangle): " << (r6.getArea() == 0 ? "PASS" : "FAIL") << " (Expected: 0)" << endl;
    
    // Test Case 7: Single dimension zero
    // Calculation: 8 * 0 = 0
    // Expected: 0
    Rectangle r7(8, 0);
    cout << "Test 7 (8x0 rectangle): " << (r7.getArea() == 0 ? "PASS" : "FAIL") << " (Expected: 0)" << endl;
    
    // Test Case 8: Large square
    // Calculation: 15 * 15 = 225
    // Expected: 225
    Rectangle r8(15);
    cout << "Test 8 (15x15 square): " << (r8.getArea() == 225 ? "PASS" : "FAIL") << " (Expected: 225)" << endl;
}

void testProblem2() {
    cout << "\n=== Testing Problem 2: Bank Account ===" << endl;
    
    // Test Case 1: Normal initialization
    // Initial balance: 100
    // Expected: 100
    BankAccount acc1("Alice", 100);
    cout << "Test 1 (normal init): " << (acc1.getBalance() == 100 ? "PASS" : "FAIL") << " (Expected: 100)" << endl;
    
    // Test Case 2: Negative balance rejection
    // Initial balance: -50 -> should become 0
    // Expected: 0
    BankAccount acc2("Bob", -50);
    cout << "Test 2 (negative rejected): " << (acc2.getBalance() == 0 ? "PASS" : "FAIL") << " (Expected: 0)" << endl;
    
    // Test Case 3: Default balance
    // No initial balance provided -> default 0
    // Expected: 0
    BankAccount acc3("Carol");
    cout << "Test 3 (default balance): " << (acc3.getBalance() == 0 ? "PASS" : "FAIL") << " (Expected: 0)" << endl;
    
    // Test Case 4: Deposit operation
    // Start: 100, deposit 50
    // Calculation: 100 + 50 = 150
    // Expected: 150
    BankAccount acc4("David", 100);
    acc4.deposit(50);
    cout << "Test 4 (deposit): " << (acc4.getBalance() == 150 ? "PASS" : "FAIL") << " (Expected: 150)" << endl;
    
    // Test Case 5: Successful withdrawal
    // Start: 100, withdraw 30
    // Calculation: 100 - 30 = 70
    // Expected: 70
    BankAccount acc5("Eve", 100);
    acc5.withdraw(30);
    cout << "Test 5 (successful withdraw): " << (acc5.getBalance() == 70 ? "PASS" : "FAIL") << " (Expected: 70)" << endl;
    
    // Test Case 6: Failed withdrawal (insufficient funds)
    // Start: 50, try withdraw 100 (should fail)
    // Balance should remain: 50
    // Expected: 50
    BankAccount acc6("Frank", 50);
    acc6.withdraw(100);
    cout << "Test 6 (failed withdraw): " << (acc6.getBalance() == 50 ? "PASS" : "FAIL") << " (Expected: 50)" << endl;
    
    // Test Case 7: Multiple operations
    // Start: 200, deposit 100, withdraw 50, deposit 25
    // Calculation: 200 + 100 - 50 + 25 = 275
    // Expected: 275
    BankAccount acc7("Grace", 200);
    acc7.deposit(100);
    acc7.withdraw(50);
    acc7.deposit(25);
    cout << "Test 7 (multiple ops): " << (acc7.getBalance() == 275 ? "PASS" : "FAIL") << " (Expected: 275)" << endl;
    
    // Test Case 8: Negative deposit rejection
    // Start: 100, try deposit -20 (should be rejected)
    // Balance should remain: 100
    // Expected: 100
    BankAccount acc8("Henry", 100);
    acc8.deposit(-20);
    cout << "Test 8 (negative deposit): " << (acc8.getBalance() == 100 ? "PASS" : "FAIL") << " (Expected: 100)" << endl;
}

void testProblem3() {
    cout << "\n=== Testing Problem 3: Student Grade Manager ===" << endl;
    
    // Test Case 1: Simple average
    // Grades: 85, 90, 75
    // Calculation: (85 + 90 + 75) / 3 = 250 / 3 = 83 (integer division)
    // Expected: 83
    Student s1("John", 3);
    s1.setGrade(0, 85);
    s1.setGrade(1, 90);
    s1.setGrade(2, 75);
    cout << "Test 1 (simple average): " << (s1.getAverage() == 83 ? "PASS" : "FAIL") << " (Expected: 83)" << endl;
    
    // Test Case 2: Perfect scores
    // Grades: 100, 100, 100, 100
    // Calculation: (100 + 100 + 100 + 100) / 4 = 400 / 4 = 100
    // Expected: 100
    Student s2("Alice", 4);
    s2.setGrade(0, 100);
    s2.setGrade(1, 100);
    s2.setGrade(2, 100);
    s2.setGrade(3, 100);
    cout << "Test 2 (perfect scores): " << (s2.getAverage() == 100 ? "PASS" : "FAIL") << " (Expected: 100)" << endl;
    
    // Test Case 3: Low scores
    // Grades: 50, 60
    // Calculation: (50 + 60) / 2 = 110 / 2 = 55
    // Expected: 55
    Student s3("Bob", 2);
    s3.setGrade(0, 50);
    s3.setGrade(1, 60);
    cout << "Test 3 (low scores): " << (s3.getAverage() == 55 ? "PASS" : "FAIL") << " (Expected: 55)" << endl;
    
    // Test Case 4: Single grade
    // Grades: 88
    // Calculation: 88 / 1 = 88
    // Expected: 88
    Student s4("Carol", 1);
    s4.setGrade(0, 88);
    cout << "Test 4 (single grade): " << (s4.getAverage() == 88 ? "PASS" : "FAIL") << " (Expected: 88)" << endl;
    
    // Test Case 5: Copy constructor test
    // Original: 70, 80, 90
    // Calculation: (70 + 80 + 90) / 3 = 240 / 3 = 80
    // Expected: Both original and copy should have average 80
    Student s5("David", 3);
    s5.setGrade(0, 70);
    s5.setGrade(1, 80);
    s5.setGrade(2, 90);
    Student s5_copy = s5;
    cout << "Test 5 (copy constructor): " << (s5_copy.getAverage() == 80 ? "PASS" : "FAIL") << " (Expected: 80)" << endl;
    
    // Test Case 6: Mixed grades
    // Grades: 95, 78, 82, 91, 88
    // Calculation: (95 + 78 + 82 + 91 + 88) / 5 = 434 / 5 = 86 (integer division)
    // Expected: 86
    Student s6("Eve", 5);
    s6.setGrade(0, 95);
    s6.setGrade(1, 78);
    s6.setGrade(2, 82);
    s6.setGrade(3, 91);
    s6.setGrade(4, 88);
    cout << "Test 6 (mixed grades): " << (s6.getAverage() == 86 ? "PASS" : "FAIL") << " (Expected: 86)" << endl;
    
    // Test Case 7: All zeros
    // Grades: 0, 0, 0
    // Calculation: (0 + 0 + 0) / 3 = 0 / 3 = 0
    // Expected: 0
    Student s7("Frank", 3);
    s7.setGrade(0, 0);
    s7.setGrade(1, 0);
    s7.setGrade(2, 0);
    cout << "Test 7 (all zeros): " << (s7.getAverage() == 0 ? "PASS" : "FAIL") << " (Expected: 0)" << endl;
    
    // Test Case 8: Larger set
    // Grades: 85, 92, 78, 88, 95, 82
    // Calculation: (85 + 92 + 78 + 88 + 95 + 82) / 6 = 520 / 6 = 86 (integer division)
    // Expected: 86
    Student s8("Grace", 6);
    s8.setGrade(0, 85);
    s8.setGrade(1, 92);
    s8.setGrade(2, 78);
    s8.setGrade(3, 88);
    s8.setGrade(4, 95);
    s8.setGrade(5, 82);
    cout << "Test 8 (larger set): " << (s8.getAverage() == 86 ? "PASS" : "FAIL") << " (Expected: 86)" << endl;
}

void testProblem4() {
    cout << "\n=== Testing Problem 4: Matrix Class ===" << endl;
    
    // Test Case 1: Default constructor
    // 2x2 matrix filled with 0
    // Diagonal: (0,0)=0, (1,1)=0
    // Calculation: 0 + 0 = 0
    // Expected: 0
    Matrix m1;
    cout << "Test 1 (default constructor): " << (m1.getSumDiagonal() == 0 ? "PASS" : "FAIL") << " (Expected: 0)" << endl;
    
    // Test Case 2: 3x3 matrix with values on diagonal
    // Set (0,0)=5, (1,1)=10, (2,2)=15
    // Calculation: 5 + 10 + 15 = 30
    // Expected: 30
    Matrix m2(3, 3, 0);
    m2.setValue(0, 0, 5);
    m2.setValue(1, 1, 10);
    m2.setValue(2, 2, 15);
    cout << "Test 2 (3x3 diagonal sum): " << (m2.getSumDiagonal() == 30 ? "PASS" : "FAIL") << " (Expected: 30)" << endl;
    
    // Test Case 3: Matrix initialized with value
    // 3x3 matrix filled with 7
    // Diagonal: (0,0)=7, (1,1)=7, (2,2)=7
    // Calculation: 7 + 7 + 7 = 21
    // Expected: 21
    Matrix m3(3, 3, 7);
    cout << "Test 3 (init with value): " << (m3.getSumDiagonal() == 21 ? "PASS" : "FAIL") << " (Expected: 21)" << endl;
    
    // Test Case 4: Non-square matrix (more rows)
    // 4x2 matrix, diagonal has min(4,2)=2 elements
    // Set (0,0)=8, (1,1)=12
    // Calculation: 8 + 12 = 20
    // Expected: 20
    Matrix m4(4, 2, 0);
    m4.setValue(0, 0, 8);
    m4.setValue(1, 1, 12);
    cout << "Test 4 (4x2 non-square): " << (m4.getSumDiagonal() == 20 ? "PASS" : "FAIL") << " (Expected: 20)" << endl;
    
    // Test Case 5: Non-square matrix (more cols)
    // 2x4 matrix, diagonal has min(2,4)=2 elements
    // Set (0,0)=6, (1,1)=9
    // Calculation: 6 + 9 = 15
    // Expected: 15
    Matrix m5(2, 4, 0);
    m5.setValue(0, 0, 6);
    m5.setValue(1, 1, 9);
    cout << "Test 5 (2x4 non-square): " << (m5.getSumDiagonal() == 15 ? "PASS" : "FAIL") << " (Expected: 15)" << endl;
    
    // Test Case 6: Negative values on diagonal
    // 3x3 matrix
    // Set (0,0)=-5, (1,1)=10, (2,2)=-8
    // Calculation: -5 + 10 + (-8) = -3
    // Expected: -3
    Matrix m6(3, 3, 0);
    m6.setValue(0, 0, -5);
    m6.setValue(1, 1, 10);
    m6.setValue(2, 2, -8);
    cout << "Test 6 (negative values): " << (m6.getSumDiagonal() == -3 ? "PASS" : "FAIL") << " (Expected: -3)" << endl;
    
    // Test Case 7: Copy constructor test
    // Original 2x2 with diagonal (0,0)=4, (1,1)=6
    // Calculation: 4 + 6 = 10
    // Copy should also have sum 10
    // Expected: 10
    Matrix m7(2, 2, 0);
    m7.setValue(0, 0, 4);
    m7.setValue(1, 1, 6);
    Matrix m7_copy = m7;
    cout << "Test 7 (copy constructor): " << (m7_copy.getSumDiagonal() == 10 ? "PASS" : "FAIL") << " (Expected: 10)" << endl;
    
    // Test Case 8: Single element matrix
    // 1x1 matrix
    // Set (0,0)=42
    // Calculation: 42
    // Expected: 42
    Matrix m8(1, 1, 0);
    m8.setValue(0, 0, 42);
    cout << "Test 8 (1x1 matrix): " << (m8.getSumDiagonal() == 42 ? "PASS" : "FAIL") << " (Expected: 42)" << endl;
}

// ============================================================================
// MAIN FUNCTION
// ============================================================================

int main() {
    int choice;
    cout << "======================================" << endl;
    cout << "   C++ Constructors Practice Problems" << endl;
    cout << "======================================" << endl;
    cout << "Choose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy) - Rectangle Class" << endl;
    cout << "2. Problem 2 (Easy) - Bank Account" << endl;
    cout << "3. Problem 3 (Medium) - Student Grade Manager" << endl;
    cout << "4. Problem 4 (Hard) - Matrix Class" << endl;
    cout << "5. Test All Problems" << endl;
    cout << "Choice: ";
    cin >> choice;

    switch(choice) {
        case 1: testProblem1(); break;
        case 2: testProblem2(); break;
        case 3: testProblem3(); break;
        case 4: testProblem4(); break;
        case 5:
            testProblem1();
            testProblem2();
            testProblem3();
            testProblem4();
            break;
        default: cout << "Invalid choice!" << endl;
    }

    return 0;
}