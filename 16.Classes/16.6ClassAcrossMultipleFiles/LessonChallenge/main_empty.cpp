#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// ============================================================================
// Problem 1: Easy 1 - Book Library System
// ============================================================================
// You need to create a Book class split across multiple files:
// - Book.h (header file with class declaration)
// - Book.cpp (implementation file with method definitions)
//
// The Book class should have:
// - Private members: title (string), author (string), pages (int)
// - Constructor that takes all three parameters
// - Getter methods: getTitle(), getAuthor(), getPages()
// - Method: getTotalWords() that returns pages * 250 (average words per page)
//
// For this exercise, simulate the structure in a single file but think about
// how you would split it into .h and .cpp files.
//
// Input: Book details (title, author, pages)
// Output: Total estimated word count
//
// Example 1:
// Input: Book("The Hobbit", "J.R.R. Tolkien", 310)
// Output: 77500 (310 * 250 = 77500)
//
// Example 2:
// Input: Book("1984", "George Orwell", 328)
// Output: 82000 (328 * 250 = 82000)
//
// Constraints:
// - 1 <= pages <= 10000
// - title and author are non-empty strings

// Book Class Declaration (would be in Book.h)

// Book Class Implementation (would be in Book.cpp)

class Book
{
private:
    string title;
    string author;
    int pages;

public:
    Book(string t, string a, int p);
    string getTitle();
    string getAuthor();
    int getPages();
    int getTotalWords();
};

// ============================================================================
// Problem 2: Easy 2 - Rectangle Calculator
// ============================================================================
// Create a Rectangle class split across multiple files with:
// - Private members: length (double), width (double)
// - Constructor with length and width parameters
// - Methods: getArea(), getPerimeter(), getDiagonal()
// - area = length * width
// - perimeter = 2 * (length + width)
// - diagonal = sqrt(length² + width²)
//
// Input: Rectangle dimensions
// Output: Area, perimeter, and diagonal length
//
// Example 1:
// Input: Rectangle(3.0, 4.0)
// getArea() = 12.0, getPerimeter() = 14.0, getDiagonal() = 5.0
//
// Example 2:
// Input: Rectangle(5.0, 12.0)
// getArea() = 60.0, getPerimeter() = 34.0, getDiagonal() = 13.0
//
// Constraints:
// - 0.1 <= length, width <= 1000.0
// - Round diagonal to 2 decimal places for comparison

class Rectangle
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w);
    double getArea();
    double getPerimeter();
    double getDiagonal();
};


// ============================================================================
// Problem 3: Medium - Student Grade Manager
// ============================================================================
// Create a Student class with:
// - Private members: name (string), grades (vector<int>)
// - Constructor with name parameter
// - Method: addGrade(int grade) - adds a grade to the vector
// - Method: getAverage() - returns average of all grades (as double)
// - Method: getLetterGrade() - returns letter grade based on average:
//   * A: 90-100
//   * B: 80-89
//   * C: 70-79
//   * D: 60-69
//   * F: 0-59
// - Method: getHighestGrade() - returns the highest grade
// - Method: getLowestGrade() - returns the lowest grade
//
// Input: Student name and sequence of grades
// Output: Average, letter grade, highest and lowest grades
//
// Example 1:
// Student s("Alice");
// s.addGrade(85), s.addGrade(90), s.addGrade(78)
// Average: 84.33, Letter: B, Highest: 90, Lowest: 78
//
// Example 2:
// Student s("Bob");
// s.addGrade(95), s.addGrade(92), s.addGrade(88), s.addGrade(91)
// Average: 91.5, Letter: A, Highest: 95, Lowest: 88
//
// Constraints:
// - 0 <= grade <= 100
// - At least 1 grade will be added before calling methods

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

Student::Student(string n)
{
    // TODO: Implement constructor
    // Hint: Initialize name, grades vector is automatically initialized
}

void Student::addGrade(int grade)
{
    // TODO: Implement adding grade to vector
    // Hint: Use push_back()
}

double Student::getAverage()
{
    // TODO: Implement average calculation
    // Hint: Sum all grades and divide by size()
    return 0;
}

char Student::getLetterGrade()
{
    // TODO: Implement letter grade determination
    // Hint: Use getAverage() and if-else statements
    return 0;
}

int Student::getHighestGrade()
{
    // TODO: Implement finding maximum grade
    // Hint: Loop through grades vector
    return 0;
}

int Student::getLowestGrade()
{
    // TODO: Implement finding minimum grade
    // Hint: Loop through grades vector
    return 0;
}

// ============================================================================
// Problem 4: Hard - Bank Account with Transaction History
// ============================================================================
// Create a BankAccount class with:
// - Private members:
//   * accountNumber (string)
//   * balance (double)
//   * transactionHistory (vector<string>)
// - Constructor with accountNumber and initialBalance
// - Method: deposit(double amount) - adds to balance, records transaction
// - Method: withdraw(double amount) - subtracts from balance if sufficient funds
//   * Returns true if successful, false if insufficient funds
//   * Records transaction only if successful
// - Method: getBalance() - returns current balance
// - Method: applyInterest(double rate) - applies interest rate (e.g., 0.05 for 5%)
//   * new_balance = balance * (1 + rate)
//   * Records transaction
// - Method: getTransactionCount() - returns number of transactions
// - Method: getTransactionHistory() - returns the transaction history vector
//
// Transaction format: "DEPOSIT: +amount" or "WITHDRAW: -amount" or "INTEREST: +amount"
//
// Example 1:
// BankAccount acc("ACC001", 1000.0);
// acc.deposit(500.0); // balance = 1500.0
// acc.withdraw(200.0); // balance = 1300.0
// acc.applyInterest(0.1); // balance = 1430.0 (1300 * 1.1)
// getTransactionCount() = 3
//
// Example 2:
// BankAccount acc("ACC002", 500.0);
// acc.withdraw(600.0); // fails, balance stays 500.0
// acc.deposit(300.0); // balance = 800.0
// acc.withdraw(250.0); // balance = 550.0
// getTransactionCount() = 2 (failed withdrawal not counted)
//
// Constraints:
// - initialBalance >= 0
// - amount > 0 for deposit/withdraw
// - 0 <= rate <= 1.0

class BankAccount
{
private:
    string accountNumber;
    double balance;
    vector<string> transactionHistory;

public:
    BankAccount(string accNum, double initialBalance);
    void deposit(double amount);
    bool withdraw(double amount);
    double getBalance();
    void applyInterest(double rate);
    int getTransactionCount();
    vector<string> getTransactionHistory();
};

BankAccount::BankAccount(string accNum, double initialBalance)
{
    // TODO: Implement constructor
    // Hint: Initialize accountNumber and balance
}

void BankAccount::deposit(double amount)
{
    // TODO: Implement deposit
    // Hint: Add to balance, record "DEPOSIT: +amount" in history
}

bool BankAccount::withdraw(double amount)
{
    // TODO: Implement withdraw with validation
    // Hint: Check if balance >= amount, then subtract and record transaction
    return 0;
}

double BankAccount::getBalance()
{
    // TODO: Implement getter
    // Hint: Return balance
    return 0;
}

void BankAccount::applyInterest(double rate)
{
    // TODO: Implement interest calculation
    // Hint: Calculate interest amount, add to balance, record transaction
}

int BankAccount::getTransactionCount()
{
    // TODO: Implement transaction count
    // Hint: Return size of transactionHistory vector
    return 0;
}

vector<string> BankAccount::getTransactionHistory()
{
    // TODO: Implement getter
    // Hint: Return transactionHistory vector
    return {0, 0};
}

// ============================================================================
// TEST FUNCTIONS
// ============================================================================

void testProblem1()
{
    cout << "\n=== Testing Problem 1: Book Library System ===" << endl;

    // Test Case 1: Standard book
    // Calculation: 310 pages * 250 words/page = 77500 words
    {
        Book b1("The Hobbit", "J.R.R. Tolkien", 310);
        cout << "Test 1: " << (b1.getTotalWords() == 77500 ? "PASS" : "FAIL")
             << " (Expected: 77500, Got: " << b1.getTotalWords() << ")" << endl;
    }

    // Test Case 2: Another standard book
    // Calculation: 328 pages * 250 words/page = 82000 words
    {
        Book b2("1984", "George Orwell", 328);
        cout << "Test 2: " << (b2.getTotalWords() == 82000 ? "PASS" : "FAIL")
             << " (Expected: 82000, Got: " << b2.getTotalWords() << ")" << endl;
    }

    // Test Case 3: Small book
    // Calculation: 50 pages * 250 words/page = 12500 words
    {
        Book b3("Short Story", "Author", 50);
        cout << "Test 3: " << (b3.getTotalWords() == 12500 ? "PASS" : "FAIL")
             << " (Expected: 12500, Got: " << b3.getTotalWords() << ")" << endl;
    }

    // Test Case 4: Large book
    // Calculation: 1200 pages * 250 words/page = 300000 words
    {
        Book b4("War and Peace", "Leo Tolstoy", 1200);
        cout << "Test 4: " << (b4.getTotalWords() == 300000 ? "PASS" : "FAIL")
             << " (Expected: 300000, Got: " << b4.getTotalWords() << ")" << endl;
    }

    // Test Case 5: Minimum pages
    // Calculation: 1 page * 250 words/page = 250 words
    {
        Book b5("Tiny Book", "Author", 1);
        cout << "Test 5: " << (b5.getTotalWords() == 250 ? "PASS" : "FAIL")
             << " (Expected: 250, Got: " << b5.getTotalWords() << ")" << endl;
    }

    // Test Case 6: Testing getters
    {
        Book b6("Test Book", "Test Author", 100);
        bool titlePass = (b6.getTitle() == "Test Book");
        bool authorPass = (b6.getAuthor() == "Test Author");
        bool pagesPass = (b6.getPages() == 100);
        cout << "Test 6: " << (titlePass && authorPass && pagesPass ? "PASS" : "FAIL")
             << " (Testing all getters)" << endl;
    }

    // Test Case 7: Medium sized book
    // Calculation: 450 pages * 250 words/page = 112500 words
    {
        Book b7("Harry Potter", "J.K. Rowling", 450);
        cout << "Test 7: " << (b7.getTotalWords() == 112500 ? "PASS" : "FAIL")
             << " (Expected: 112500, Got: " << b7.getTotalWords() << ")" << endl;
    }

    // Test Case 8: Edge case - 999 pages
    // Calculation: 999 pages * 250 words/page = 249750 words
    {
        Book b8("Long Book", "Prolific Author", 999);
        cout << "Test 8: " << (b8.getTotalWords() == 249750 ? "PASS" : "FAIL")
             << " (Expected: 249750, Got: " << b8.getTotalWords() << ")" << endl;
    }
}

 void testProblem2()
{
    cout << "\n=== Testing Problem 2: Rectangle Calculator ===" << endl;

    // Test Case 1: Classic 3-4-5 triangle
    // Area: 3 * 4 = 12.0
    // Perimeter: 2 * (3 + 4) = 14.0
    // Diagonal: sqrt(3² + 4²) = sqrt(9 + 16) = sqrt(25) = 5.0
    {
        Rectangle r1(3.0, 4.0);
        bool areaPass = (r1.getArea() == 12.0);
        bool perimeterPass = (r1.getPerimeter() == 14.0);
        bool diagonalPass = (abs(r1.getDiagonal() - 5.0) < 0.01);
        cout << "Test 1: " << (areaPass && perimeterPass && diagonalPass ? "PASS" : "FAIL")
             << " (3x4 rectangle)" << endl;
    }

    // Test Case 2: 5-12-13 triangle
    // Area: 5 * 12 = 60.0
    // Perimeter: 2 * (5 + 12) = 34.0
    // Diagonal: sqrt(5² + 12²) = sqrt(25 + 144) = sqrt(169) = 13.0
    {
        Rectangle r2(5.0, 12.0);
        bool areaPass = (r2.getArea() == 60.0);
        bool perimeterPass = (r2.getPerimeter() == 34.0);
        bool diagonalPass = (abs(r2.getDiagonal() - 13.0) < 0.01);
        cout << "Test 2: " << (areaPass && perimeterPass && diagonalPass ? "PASS" : "FAIL")
             << " (5x12 rectangle)" << endl;
    }

    // Test Case 3: Square
    // Area: 6 * 6 = 36.0
    // Perimeter: 2 * (6 + 6) = 24.0
    // Diagonal: sqrt(6² + 6²) = sqrt(36 + 36) = sqrt(72) = 8.485...
    {
        Rectangle r3(6.0, 6.0);
        bool areaPass = (r3.getArea() == 36.0);
        bool perimeterPass = (r3.getPerimeter() == 24.0);
        bool diagonalPass = (abs(r3.getDiagonal() - 8.485) < 0.01);
        cout << "Test 3: " << (areaPass && perimeterPass && diagonalPass ? "PASS" : "FAIL")
             << " (6x6 square)" << endl;
    }

    // Test Case 4: Small rectangle
    // Area: 2 * 3 = 6.0
    // Perimeter: 2 * (2 + 3) = 10.0
    // Diagonal: sqrt(2² + 3²) = sqrt(4 + 9) = sqrt(13) = 3.606...
    {
        Rectangle r4(2.0, 3.0);
        bool areaPass = (r4.getArea() == 6.0);
        bool perimeterPass = (r4.getPerimeter() == 10.0);
        bool diagonalPass = (abs(r4.getDiagonal() - 3.606) < 0.01);
        cout << "Test 4: " << (areaPass && perimeterPass && diagonalPass ? "PASS" : "FAIL")
             << " (2x3 rectangle)" << endl;
    }

    // Test Case 5: Unit square
    // Area: 1 * 1 = 1.0
    // Perimeter: 2 * (1 + 1) = 4.0
    // Diagonal: sqrt(1² + 1²) = sqrt(2) = 1.414...
    {
        Rectangle r5(1.0, 1.0);
        bool areaPass = (r5.getArea() == 1.0);
        bool perimeterPass = (r5.getPerimeter() == 4.0);
        bool diagonalPass = (abs(r5.getDiagonal() - 1.414) < 0.01);
        cout << "Test 5: " << (areaPass && perimeterPass && diagonalPass ? "PASS" : "FAIL")
             << " (1x1 unit square)" << endl;
    }

    // Test Case 6: Large rectangle
    // Area: 10 * 20 = 200.0
    // Perimeter: 2 * (10 + 20) = 60.0
    // Diagonal: sqrt(10² + 20²) = sqrt(100 + 400) = sqrt(500) = 22.36...
    {
        Rectangle r6(10.0, 20.0);
        bool areaPass = (r6.getArea() == 200.0);
        bool perimeterPass = (r6.getPerimeter() == 60.0);
        bool diagonalPass = (abs(r6.getDiagonal() - 22.36) < 0.01);
        cout << "Test 6: " << (areaPass && perimeterPass && diagonalPass ? "PASS" : "FAIL")
             << " (10x20 rectangle)" << endl;
    }

    // Test Case 7: Decimal values
    // Area: 2.5 * 4.5 = 11.25
    // Perimeter: 2 * (2.5 + 4.5) = 14.0
    // Diagonal: sqrt(2.5² + 4.5²) = sqrt(6.25 + 20.25) = sqrt(26.5) = 5.147...
    {
        Rectangle r7(2.5, 4.5);
        bool areaPass = (abs(r7.getArea() - 11.25) < 0.01);
        bool perimeterPass = (abs(r7.getPerimeter() - 14.0) < 0.01);
        bool diagonalPass = (abs(r7.getDiagonal() - 5.147) < 0.01);
        cout << "Test 7: " << (areaPass && perimeterPass && diagonalPass ? "PASS" : "FAIL")
             << " (2.5x4.5 rectangle with decimals)" << endl;
    }

    // Test Case 8: 8-15-17 triangle
    // Area: 8 * 15 = 120.0
    // Perimeter: 2 * (8 + 15) = 46.0
    // Diagonal: sqrt(8² + 15²) = sqrt(64 + 225) = sqrt(289) = 17.0
    {
        Rectangle r8(8.0, 15.0);
        bool areaPass = (r8.getArea() == 120.0);
        bool perimeterPass = (r8.getPerimeter() == 46.0);
        bool diagonalPass = (abs(r8.getDiagonal() - 17.0) < 0.01);
        cout << "Test 8: " << (areaPass && perimeterPass && diagonalPass ? "PASS" : "FAIL")
             << " (8x15 rectangle)" << endl;
    }
}

/* void testProblem3()
{
    cout << "\n=== Testing Problem 3: Student Grade Manager ===" << endl;

    // Test Case 1: Three grades - B average
    // Grades: 85, 90, 78
    // Average: (85 + 90 + 78) / 3 = 253 / 3 = 84.333...
    // Letter: B (80-89)
    // Highest: 90, Lowest: 78
    {
        Student s1("Alice");
        s1.addGrade(85);
        s1.addGrade(90);
        s1.addGrade(78);
        bool avgPass = (abs(s1.getAverage() - 84.333) < 0.01);
        bool letterPass = (s1.getLetterGrade() == 'B');
        bool highPass = (s1.getHighestGrade() == 90);
        bool lowPass = (s1.getLowestGrade() == 78);
        cout << "Test 1: " << (avgPass && letterPass && highPass && lowPass ? "PASS" : "FAIL")
             << " (Alice: B average)" << endl;
    }

    // Test Case 2: Four grades - A average
    // Grades: 95, 92, 88, 91
    // Average: (95 + 92 + 88 + 91) / 4 = 366 / 4 = 91.5
    // Letter: A (90-100)
    // Highest: 95, Lowest: 88
    {
        Student s2("Bob");
        s2.addGrade(95);
        s2.addGrade(92);
        s2.addGrade(88);
        s2.addGrade(91);
        bool avgPass = (abs(s2.getAverage() - 91.5) < 0.01);
        bool letterPass = (s2.getLetterGrade() == 'A');
        bool highPass = (s2.getHighestGrade() == 95);
        bool lowPass = (s2.getLowestGrade() == 88);
        cout << "Test 2: " << (avgPass && letterPass && highPass && lowPass ? "PASS" : "FAIL")
             << " (Bob: A average)" << endl;
    }

    // Test Case 3: C average
    // Grades: 72, 75, 70
    // Average: (72 + 75 + 70) / 3 = 217 / 3 = 72.333...
    // Letter: C (70-79)
    // Highest: 75, Lowest: 70
    {
        Student s3("Charlie");
        s3.addGrade(72);
        s3.addGrade(75);
        s3.addGrade(70);
        bool avgPass = (abs(s3.getAverage() - 72.333) < 0.01);
        bool letterPass = (s3.getLetterGrade() == 'C');
        bool highPass = (s3.getHighestGrade() == 75);
        bool lowPass = (s3.getLowestGrade() == 70);
        cout << "Test 3: " << (avgPass && letterPass && highPass && lowPass ? "PASS" : "FAIL")
             << " (Charlie: C average)" << endl;
    }

    // Test Case 4: F average
    // Grades: 55, 48, 52
    // Average: (55 + 48 + 52) / 3 = 155 / 3 = 51.666...
    // Letter: F (0-59)
    // Highest: 55, Lowest: 48
    {
        Student s4("Diana");
        s4.addGrade(55);
        s4.addGrade(48);
        s4.addGrade(52);
        bool avgPass = (abs(s4.getAverage() - 51.666) < 0.01);
        bool letterPass = (s4.getLetterGrade() == 'F');
        bool highPass = (s4.getHighestGrade() == 55);
        bool lowPass = (s4.getLowestGrade() == 48);
        cout << "Test 4: " << (avgPass && letterPass && highPass && lowPass ? "PASS" : "FAIL")
             << " (Diana: F average)" << endl;
    }

    // Test Case 5: D average
    // Grades: 65, 62, 68, 60
    // Average: (65 + 62 + 68 + 60) / 4 = 255 / 4 = 63.75
    // Letter: D (60-69)
    // Highest: 68, Lowest: 60
    {
        Student s5("Eve");
        s5.addGrade(65);
        s5.addGrade(62);
        s5.addGrade(68);
        s5.addGrade(60);
        bool avgPass = (abs(s5.getAverage() - 63.75) < 0.01);
        bool letterPass = (s5.getLetterGrade() == 'D');
        bool highPass = (s5.getHighestGrade() == 68);
        bool lowPass = (s5.getLowestGrade() == 60);
        cout << "Test 5: " << (avgPass && letterPass && highPass && lowPass ? "PASS" : "FAIL")
             << " (Eve: D average)" << endl;
    }

    // Test Case 6: Perfect scores
    // Grades: 100, 100, 100
    // Average: 300 / 3 = 100.0
    // Letter: A
    // Highest: 100, Lowest: 100
    {
        Student s6("Frank");
        s6.addGrade(100);
        s6.addGrade(100);
        s6.addGrade(100);
        bool avgPass = (abs(s6.getAverage() - 100.0) < 0.01);
        bool letterPass = (s6.getLetterGrade() == 'A');
        bool highPass = (s6.getHighestGrade() == 100);
        bool lowPass = (s6.getLowestGrade() == 100);
        cout << "Test 6: " << (avgPass && letterPass && highPass && lowPass ? "PASS" : "FAIL")
             << " (Frank: Perfect scores)" << endl;
    }

    // Test Case 7: Boundary case - exactly 90
    // Grades: 90, 90
    // Average: 180 / 2 = 90.0
    // Letter: A (90-100)
    // Highest: 90, Lowest: 90
    {
        Student s7("Grace");
        s7.addGrade(90);
        s7.addGrade(90);
        bool avgPass = (abs(s7.getAverage() - 90.0) < 0.01);
        bool letterPass = (s7.getLetterGrade() == 'A');
        bool highPass = (s7.getHighestGrade() == 90);
        bool lowPass = (s7.getLowestGrade() == 90);
        cout << "Test 7: " << (avgPass && letterPass && highPass && lowPass ? "PASS" : "FAIL")
             << " (Grace: Boundary A)" << endl;
    }

    // Test Case 8: Single grade
    // Grades: 85
    // Average: 85.0
    // Letter: B
    // Highest: 85, Lowest: 85
    {
        Student s8("Henry");
        s8.addGrade(85);
        bool avgPass = (abs(s8.getAverage() - 85.0) < 0.01);
        bool letterPass = (s8.getLetterGrade() == 'B');
        bool highPass = (s8.getHighestGrade() == 85);
        bool lowPass = (s8.getLowestGrade() == 85);
        cout << "Test 8: " << (avgPass && letterPass && highPass && lowPass ? "PASS" : "FAIL")
             << " (Henry: Single grade)" << endl;
    }
}
 */
/* void testProblem4()
{
    cout << "\n=== Testing Problem 4: Bank Account with Transaction History ===" << endl;

    // Test Case 1: Basic operations
    // Start: 1000.0
    // Deposit 500: 1000 + 500 = 1500.0
    // Withdraw 200: 1500 - 200 = 1300.0
    // Interest 10%: 1300 * 1.1 = 1430.0
    // Transaction count: 3
    {
        BankAccount acc1("ACC001", 1000.0);
        acc1.deposit(500.0);
        acc1.withdraw(200.0);
        acc1.applyInterest(0.1);
        bool balancePass = (abs(acc1.getBalance() - 1430.0) < 0.01);
        bool countPass = (acc1.getTransactionCount() == 3);
        cout << "Test 1: " << (balancePass && countPass ? "PASS" : "FAIL")
             << " (Basic operations - Balance: " << acc1.getBalance() << ", Count: "
             << acc1.getTransactionCount() << ")" << endl;
    }

    // Test Case 2: Failed withdrawal
    // Start: 500.0
    // Withdraw 600 (fails): 500.0
    // Deposit 300: 500 + 300 = 800.0
    // Withdraw 250: 800 - 250 = 550.0
    // Transaction count: 2 (failed withdrawal not counted)
    {
        BankAccount acc2("ACC002", 500.0);
        bool withdrawFail = !acc2.withdraw(600.0);
        acc2.deposit(300.0);
        acc2.withdraw(250.0);
        bool balancePass = (abs(acc2.getBalance() - 550.0) < 0.01);
        bool countPass = (acc2.getTransactionCount() == 2);
        bool failPass = withdrawFail;
        cout << "Test 2: " << (balancePass && countPass && failPass ? "PASS" : "FAIL")
             << " (Failed withdrawal - Balance: " << acc2.getBalance() << ", Count: "
             << acc2.getTransactionCount() << ")" << endl;
    }

    // Test Case 3: Multiple deposits
    // Start: 100.0
    // Deposit 50: 100 + 50 = 150.0
    // Deposit 75: 150 + 75 = 225.0
    // Deposit 25: 225 + 25 = 250.0
    // Transaction count: 3
    {
        BankAccount acc3("ACC003", 100.0);
        acc3.deposit(50.0);
        acc3.deposit(75.0);
        acc3.deposit(25.0);
        bool balancePass = (abs(acc3.getBalance() - 250.0) < 0.01);
        bool countPass = (acc3.getTransactionCount() == 3);
        cout << "Test 3: " << (balancePass && countPass ? "PASS" : "FAIL")
             << " (Multiple deposits - Balance: " << acc3.getBalance() << ")" << endl;
    }

    // Test Case 4: Interest calculation
    // Start: 2000.0
    // Interest 5%: 2000 * 1.05 = 2100.0
    // Transaction count: 1
    {
        BankAccount acc4("ACC004", 2000.0);
        acc4.applyInterest(0.05);
        bool balancePass = (abs(acc4.getBalance() - 2100.0) < 0.01);
        bool countPass = (acc4.getTransactionCount() == 1);
        cout << "Test 4: " << (balancePass && countPass ? "PASS" : "FAIL")
             << " (Interest 5% - Balance: " << acc4.getBalance() << ")" << endl;
    }

    // Test Case 5: Exact withdrawal (balance to zero)
    // Start: 300.0
    // Withdraw 300: 300 - 300 = 0.0
    // Transaction count: 1
    {
        BankAccount acc5("ACC005", 300.0);
        bool withdrawSuccess = acc5.withdraw(300.0);
        bool balancePass = (abs(acc5.getBalance() - 0.0) < 0.01);
        bool countPass = (acc5.getTransactionCount() == 1);
        bool successPass = withdrawSuccess;
        cout << "Test 5: " << (balancePass && countPass && successPass ? "PASS" : "FAIL")
             << " (Exact withdrawal to zero - Balance: " << acc5.getBalance() << ")" << endl;
    }

    // Test Case 6: Complex sequence
    // Start: 1500.0
    // Deposit 250: 1500 + 250 = 1750.0
    // Withdraw 500: 1750 - 500 = 1250.0
    // Interest 8%: 1250 * 1.08 = 1350.0
    // Deposit 150: 1350 + 150 = 1500.0
    // Withdraw 200: 1500 - 200 = 1300.0
    // Transaction count: 5
    {
        BankAccount acc6("ACC006", 1500.0);
        acc6.deposit(250.0);
        acc6.withdraw(500.0);
        acc6.applyInterest(0.08);
        acc6.deposit(150.0);
        acc6.withdraw(200.0);
        bool balancePass = (abs(acc6.getBalance() - 1300.0) < 0.01);
        bool countPass = (acc6.getTransactionCount() == 5);
        cout << "Test 6: " << (balancePass && countPass ? "PASS" : "FAIL")
             << " (Complex sequence - Balance: " << acc6.getBalance() << ", Count: "
             << acc6.getTransactionCount() << ")" << endl;
    }

    // Test Case 7: Starting with zero balance
    // Start: 0.0
    // Deposit 100: 0 + 100 = 100.0
    // Withdraw 50: 100 - 50 = 50.0
    // Transaction count: 2
    {
        BankAccount acc7("ACC007", 0.0);
        acc7.deposit(100.0);
        acc7.withdraw(50.0);
        bool balancePass = (abs(acc7.getBalance() - 50.0) < 0.01);
        bool countPass = (acc7.getTransactionCount() == 2);
        cout << "Test 7: " << (balancePass && countPass ? "PASS" : "FAIL")
             << " (Starting with zero - Balance: " << acc7.getBalance() << ")" << endl;
    }

    // Test Case 8: High interest rate
    // Start: 1000.0
    // Interest 25%: 1000 * 1.25 = 1250.0
    // Deposit 250: 1250 + 250 = 1500.0
    // Interest 20%: 1500 * 1.20 = 1800.0
    // Transaction count: 3
    {
        BankAccount acc8("ACC008", 1000.0);
        acc8.applyInterest(0.25);
        acc8.deposit(250.0);
        acc8.applyInterest(0.20);
        bool balancePass = (abs(acc8.getBalance() - 1800.0) < 0.01);
        bool countPass = (acc8.getTransactionCount() == 3);
        cout << "Test 8: " << (balancePass && countPass ? "PASS" : "FAIL")
             << " (High interest - Balance: " << acc8.getBalance() << ")" << endl;
    }
}
 */
int main()
{
    int choice;
    cout << "=====================================" << endl;
    cout << "   C++ Class Across Multiple Files   " << endl;
    cout << "        Practice Problems            " << endl;
    cout << "=====================================" << endl;
    cout << "\nChoose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy) - Book Library System" << endl;
    cout << "2. Problem 2 (Easy-Medium) - Rectangle Calculator" << endl;
    cout << "3. Problem 3 (Medium) - Student Grade Manager" << endl;
    cout << "4. Problem 4 (Hard) - Bank Account with Transaction History" << endl;
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
        // testProblem3();
        break;
    case 4:
        // testProblem4();
        break;
    case 5:
        testProblem1();
        testProblem2();
        // testProblem3();
        // testProblem4();
        cout << "\n=====================================" << endl;
        cout << "     All Tests Completed!            " << endl;
        cout << "=====================================" << endl;
        break;
    default:
        cout << "Invalid choice! Please select 1-5." << endl;
    }

    return 0;
}