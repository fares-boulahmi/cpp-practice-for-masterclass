#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// Problem 1: Easy 1 - Price Tag Formatter
// You work at a store and need to format product prices for display.
// Given a product name and price (as a double), format the output to show:
// - Product name left-aligned in a field of width 20
// - Price right-aligned with exactly 2 decimal places, preceded by '$'
// - Total width should be exactly 30 characters
//
// Input Format: string productName, double price
// Output Format: Display the formatted line
//
// Example 1: formatPrice("Apple", 1.5) should display:
// "Apple               $1.50"
// Example 2: formatPrice("Banana Split", 12.345) should display:
// "Banana Split        $12.35"
// Example 3: formatPrice("Expensive Item", 999.99) should display:
// "Expensive Item     $999.99"
//
// Constraints: 1 <= productName.length() <= 18, 0.01 <= price <= 9999.99
void problem1Solution(string productName, double price) {
    // TODO: Implement your solution here using Output formatting
    // Hint: Use setw(), left, right manipulators and fixed/setprecision for decimals
    price += 1e-9; // tiny bump to avoid tie-to-even
    cout << endl;
    cout << left <<  setw(20) << productName << right << setw(10) << fixed << setprecision(2)  << "$" << price <<endl;
}

// Problem 2: Easy 2 - Student Grade Report
// Create a formatted report showing student information in a table format.
// Given student name, ID (integer), and grade percentage (double), format as:
// - Name: left-aligned, width 15
// - ID: right-aligned, width 8, filled with leading zeros if needed
// - Grade: right-aligned, width 8, show 1 decimal place, followed by '%'
//
// Input Format: string name, int studentID, double gradePercent
// Output Format: Display the formatted row
//
// Example 1: formatGrade("John Doe", 123, 85.7) should display:
// "John Doe       00000123    85.7%"
// Example 2: formatGrade("Alice Smith", 45678, 92.0) should display:
// "Alice Smith    00045678    92.0%"
// Example 3: formatGrade("Bob", 7, 78.25) should display:
// "Bob            00000007    78.3%"
//
// Constraints: 1 <= name.length() <= 14, 1 <= studentID <= 99999999, 0.0 <= gradePercent <= 100.0
void problem2Solution(string name, int studentID, double gradePercent) {
    // TODO: Implement your solution here using Output formatting
    // Hint: Use setw(), setfill('0'), left, right, and fixed/setprecision
    cout << setfill(' ') <<  left <<  setw(15) <<  name << right << setfill('0') << setw(8) << studentID << setw(8) << right << setfill(' ') << setw(8) << fixed << setprecision(1) << gradePercent << "%" << endl;
}

// Problem 3: Medium - Financial Statement Formatter
// Create a formatted financial statement showing income and expenses.
// Given arrays of descriptions and amounts, format each line and show a total.
// Requirements:
// - Description: left-aligned, width 25
// - Amount: right-aligned, width 12, 2 decimal places
// - Positive amounts prefixed with '+', negative with '-'
// - After all items, show "TOTAL:" followed by the sum
// - If total is negative, show in parentheses: (amount)
//
// Input Format: vector<string> descriptions, vector<double> amounts
// Output Format: Display formatted lines and total
//
// Example: descriptions = ["Salary", "Rent", "Groceries"], amounts = [3000.0, -1200.0, -300.50]
// Should display:
// "Salary                   +3000.00"
// "Rent                     -1200.00" 
// "Groceries                 -300.50"
// "TOTAL:                   +1499.50"
//
// Constraints: 1 <= descriptions.size() <= 10, descriptions.size() == amounts.size()
void problem3Solution(vector<string> descriptions, vector<double> amounts) {
    // TODO: Implement your solution here using Output formatting
    // Hint: Calculate total first, then format each line. Handle negative total specially.
}

// Problem 4: Hard - Scientific Data Table
// Format a table of scientific measurements with proper alignment and precision.
// Given experiment names, measured values, and error margins, create a formatted table with:
// - Header row with column titles
// - Experiment name: left-aligned, width 20
// - Value: right-aligned, width 15, scientific notation with 3 decimal places
// - Error: right-aligned, width 12, scientific notation with 2 decimal places
// - Ratio (Value/Error): right-aligned, width 10, fixed-point with 1 decimal place
//
// Input Format: vector<string> experiments, vector<double> values, vector<double> errors
// Output Format: Display formatted table with header
//
// Example: experiments = ["Experiment A", "Test B"], values = [0.001234, 1500000], errors = [0.000012, 50000]
// Should display:
// "Experiment          Value                Error      Ratio"
// "Experiment A        1.234e-03        1.20e-05      102.8"
// "Test B              1.500e+06        5.00e+04       30.0"
//
// Constraints: 1 <= experiments.size() <= 8, all arrays same size, errors[i] > 0
void problem4Solution(vector<string> experiments, vector<double> values, vector<double> errors) {
    // TODO: Implement your solution here using Output formatting
    // Hint: Use scientific manipulator for scientific notation, calculate ratios carefully
}

void testProblem1() {
    cout << "Testing Problem 1 - Price Tag Formatter..." << endl;
    cout << "Expected format: Name(20 chars left) + Price(10 chars right with $)" << endl;
    
    // Test Case 1: Simple item
    // Calculation: "Apple" (5 chars) + 15 spaces + "$1.50" = 30 total chars
    cout << "Test 1 (Apple, 1.5) - Expected: 'Apple               $1.50'" << endl;
    cout << "Your output: '"; problem1Solution("Apple", 1.5); cout << "'" << endl;
    
    // Test Case 2: Longer name
    // Calculation: "Banana Split" (12 chars) + 8 spaces + "$12.35" = 30 total chars  
    cout << "Test 2 (Banana Split, 12.345) - Expected: 'Banana Split        $12.35'" << endl;
    cout << "Your output: '"; problem1Solution("Banana Split", 12.345); cout << "'" << endl;
    
    // Test Case 3: Expensive item
    // Calculation: "Expensive Item" (14 chars) + 6 spaces + "$999.99" = 30 total chars
    cout << "Test 3 (Expensive Item, 999.99) - Expected: 'Expensive Item     $999.99'" << endl;
    cout << "Your output: '"; problem1Solution("Expensive Item", 999.99); cout << "'" << endl;
    
    // Test Case 4: Single character name
    // Calculation: "A" (1 char) + 19 spaces + "$0.01" = 30 total chars
    cout << "Test 4 (A, 0.01) - Expected: 'A                   $0.01'" << endl;
    cout << "Your output: '"; problem1Solution("A", 0.01); cout << "'" << endl;
    
    // Test Case 5: Maximum length name
    // Calculation: "Very Long Product" (17 chars) + 3 spaces + "$55.55" = 30 total chars
    cout << "Test 5 (Very Long Product, 55.555) - Expected: 'Very Long Product   $55.56'" << endl;
    cout << "Your output: '"; problem1Solution("Very Long Product", 55.555); cout << "'" << endl;
    
    cout << endl;
}

void testProblem2() {
    cout << "Testing Problem 2 - Student Grade Report..." << endl;
    cout << "Expected format: Name(15 chars left) + ID(8 chars right, zero-padded) + Grade(8 chars right, 1 decimal)%" << endl;
    
    // Test Case 1: Regular case
    // Calculation: "John Doe" (8 chars) + 7 spaces + "00000123" + 4 spaces + "85.7%"
    cout << "Test 1 (John Doe, 123, 85.7) - Expected: 'John Doe       00000123    85.7%'" << endl;
    cout << "Your output: '"; problem2Solution("John Doe", 123, 85.7); cout << "'" << endl;
    
    // Test Case 2: Longer name
    // Calculation: "Alice Smith" (11 chars) + 4 spaces + "00045678" + 4 spaces + "92.0%"
    cout << "Test 2 (Alice Smith, 45678, 92.0) - Expected: 'Alice Smith    00045678    92.0%'" << endl;
    cout << "Your output: '"; problem2Solution("Alice Smith", 45678, 92.0); cout << "'" << endl;
    
    // Test Case 3: Short name, low ID, needs rounding
    // Calculation: "Bob" (3 chars) + 12 spaces + "00000007" + 4 spaces + "78.3%" (78.25 rounds to 78.3)
    cout << "Test 3 (Bob, 7, 78.25) - Expected: 'Bob            00000007    78.3%'" << endl;
    cout << "Your output: '"; problem2Solution("Bob", 7, 78.25); cout << "'" << endl;
    
    // Test Case 4: Maximum ID
    // Calculation: "Student" (7 chars) + 8 spaces + "99999999" + 4 spaces + "100.0%"
    cout << "Test 4 (Student, 99999999, 100.0) - Expected: 'Student        99999999   100.0%'" << endl;
    cout << "Your output: '"; problem2Solution("Student", 99999999, 100.0); cout << "'" << endl;
    
    // Test Case 5: Zero grade
    // Calculation: "Failed" (6 chars) + 9 spaces + "00001234" + 4 spaces + "0.0%"
    cout << "Test 5 (Failed, 1234, 0.0) - Expected: 'Failed         00001234     0.0%'" << endl;
    cout << "Your output: '"; problem2Solution("Failed", 1234, 0.0); cout << "'" << endl;
    
    cout << endl;
}

void testProblem3() {
    cout << "Testing Problem 3 - Financial Statement Formatter..." << endl;
    cout << "Expected format: Description(25 chars left) + Amount(12 chars right, +/- prefix, 2 decimals)" << endl;
    
    // Test Case 1: Mixed positive/negative, positive total
    // Calculation: 3000.0 + (-1200.0) + (-300.50) = 1499.50 (positive)
    cout << "Test 1: Salary/Rent/Groceries - Total should be +1499.50" << endl;
    vector<string> desc1 = {"Salary", "Rent", "Groceries"};
    vector<double> amt1 = {3000.0, -1200.0, -300.50};
    problem3Solution(desc1, amt1);
    
    // Test Case 2: All negative, negative total  
    // Calculation: (-500.0) + (-200.25) + (-100.0) = -800.25 (negative, show as (800.25))
    cout << "Test 2: All expenses - Total should be (800.25)" << endl;
    vector<string> desc2 = {"Rent", "Food", "Utils"};
    vector<double> amt2 = {-500.0, -200.25, -100.0};
    problem3Solution(desc2, amt2);
    
    // Test Case 3: Single positive item
    // Calculation: 1000.0 = 1000.00 (positive)
    cout << "Test 3: Single income - Total should be +1000.00" << endl;
    vector<string> desc3 = {"Bonus"};
    vector<double> amt3 = {1000.0};
    problem3Solution(desc3, amt3);
    
    // Test Case 4: Zero total
    // Calculation: 500.0 + (-500.0) = 0.00
    cout << "Test 4: Balanced - Total should be +0.00" << endl;
    vector<string> desc4 = {"Income", "Expense"};
    vector<double> amt4 = {500.0, -500.0};
    problem3Solution(desc4, amt4);
    
    // Test Case 5: Long description
    // Calculation: 750.5 + (-250.25) = 500.25
    cout << "Test 5: Long descriptions - Total should be +500.25" << endl;
    vector<string> desc5 = {"Very Long Description", "Short"};
    vector<double> amt5 = {750.5, -250.25};
    problem3Solution(desc5, amt5);
    
    cout << endl;
}

void testProblem4() {
    cout << "Testing Problem 4 - Scientific Data Table..." << endl;
    cout << "Expected: Header + formatted rows with scientific notation and ratios" << endl;
    
    // Test Case 1: Small and large values
    // Calculations: 
    // 0.001234 / 0.000012 = 102.833... ≈ 102.8
    // 1500000 / 50000 = 30.0
    cout << "Test 1: Small and large values" << endl;
    vector<string> exp1 = {"Experiment A", "Test B"};
    vector<double> val1 = {0.001234, 1500000};
    vector<double> err1 = {0.000012, 50000};
    problem4Solution(exp1, val1, err1);
    
    // Test Case 2: Very small numbers
    // Calculations:
    // 1.5e-9 / 2.3e-10 = 6.521... ≈ 6.5
    // 3.7e-8 / 1.1e-9 = 33.636... ≈ 33.6
    cout << "Test 2: Very small numbers" << endl;
    vector<string> exp2 = {"Nano Test", "Micro Analysis"};  
    vector<double> val2 = {1.5e-9, 3.7e-8};
    vector<double> err2 = {2.3e-10, 1.1e-9};
    problem4Solution(exp2, val2, err2);
    
    // Test Case 3: Large numbers
    // Calculations:
    // 2.5e6 / 1.2e5 = 20.833... ≈ 20.8
    cout << "Test 3: Large numbers" << endl;
    vector<string> exp3 = {"Big Experiment"};
    vector<double> val3 = {2.5e6};
    vector<double> err3 = {1.2e5};
    problem4Solution(exp3, val3, err3);
    
    // Test Case 4: Equal value and error
    // Calculations: 1.0 / 1.0 = 1.0
    cout << "Test 4: Equal value and error" << endl;
    vector<string> exp4 = {"Unity Test"};
    vector<double> val4 = {1.0};
    vector<double> err4 = {1.0};
    problem4Solution(exp4, val4, err4);
    
    // Test Case 5: Multiple experiments
    // Calculations:
    // 0.00456 / 0.00023 = 19.826... ≈ 19.8
    // 789.1 / 12.3 = 64.154... ≈ 64.2
    // 0.0987 / 0.0045 = 21.933... ≈ 21.9
    cout << "Test 5: Multiple different scales" << endl;
    vector<string> exp5 = {"Alpha", "Beta", "Gamma"};
    vector<double> val5 = {0.00456, 789.1, 0.0987};
    vector<double> err5 = {0.00023, 12.3, 0.0045};
    problem4Solution(exp5, val5, err5);
    
    cout << endl;
}

int main() {
    int choice;
    cout << "=== C++ Output Formatting Practice Problems ===" << endl;
    cout << "Choose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy) - Price Tag Formatter" << endl;
    cout << "2. Problem 2 (Easy-Medium) - Student Grade Report" << endl;
    cout << "3. Problem 3 (Medium) - Financial Statement Formatter" << endl;
    cout << "4. Problem 4 (Hard) - Scientific Data Table" << endl;
    cout << "5. Test All Problems" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;

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