#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// ============================================================================
// Problem 1: Easy 1 - Basic Header and Implementation Split
// ============================================================================
// Description:
// You need to understand how to declare functions in a header-like section
// and implement them separately. Create a simple calculator module.
//
// Task: Implement basic arithmetic operations (add, subtract, multiply, divide)
// that would typically be split across .h and .cpp files.
//
// Input Format:
// - Two double numbers and an operation character (+, -, *, /)
//
// Output Format:
// - Result of the operation as a double
// - For division by zero, return -999999.0 as error indicator
//
// Example 1:
// Input: calculate(10.0, 5.0, '+')
// Output: 15.0
//
// Example 2:
// Input: calculate(10.0, 5.0, '/')
// Output: 2.0
//
// Example 3:
// Input: calculate(10.0, 0.0, '/')
// Output: -999999.0 (error: division by zero)
//
// Constraints:
// - -1000.0 <= numbers <= 1000.0
// - Operation must be one of: +, -, *, /

// Function Declaration (would be in .h file)
double calculate(double a, double b, char op);

// Function Implementation (would be in .cpp file)
double calculate(double a, double b, char op) {
    // TODO: Implement your solution here
    // Hint: Use switch statement to handle different operations
    // Remember to check for division by zero
}

// ============================================================================
// Problem 2: Easy 2 - Multiple Related Functions Module
// ============================================================================
// Description:
// Create a string utility module with multiple related functions.
// This simulates how utility functions are organized in separate files.
//
// Task: Implement string manipulation functions that would be in a
// StringUtils module (StringUtils.h and StringUtils.cpp)
//
// Function 1: countVowels - Count vowels (a,e,i,o,u, case insensitive)
// Function 2: reverseString - Reverse the input string
// Function 3: isPalindrome - Check if string is palindrome (ignore case)
//
// Input Format:
// - A string (may contain spaces, letters, numbers)
//
// Output Format:
// - countVowels: integer count
// - reverseString: reversed string
// - isPalindrome: true/false
//
// Example 1:
// Input: countVowels("Hello World")
// Output: 3 (e, o, o)
//
// Example 2:
// Input: reverseString("Hello")
// Output: "olleH"
//
// Example 3:
// Input: isPalindrome("Racecar")
// Output: true
//
// Constraints:
// - 0 <= string length <= 1000
// - String may contain any printable ASCII characters

// Function Declarations (would be in StringUtils.h)
int countVowels(const string& str);
string reverseString(const string& str);
bool isPalindrome(const string& str);

// Function Implementations (would be in StringUtils.cpp)
int countVowels(const string& str) {
    // TODO: Implement your solution here
    // Hint: Loop through string and check each character
    // Convert to lowercase for case-insensitive comparison
}

string reverseString(const string& str) {
    // TODO: Implement your solution here
    // Hint: Create new string and build it backwards
    // Or use two-pointer approach
}

bool isPalindrome(const string& str) {
    // TODO: Implement your solution here
    // Hint: Compare characters from both ends moving inward
    // Convert to lowercase for case-insensitive comparison
}

// ============================================================================
// Problem 3: Medium - Array Operations Module with Multiple Dependencies
// ============================================================================
// Description:
// Create an array statistics module that demonstrates function dependencies.
// Some functions will call other functions in the same module.
//
// Task: Implement statistical functions for integer arrays
// Function 1: calculateSum - Sum all elements
// Function 2: calculateAverage - Average of elements (uses calculateSum)
// Function 3: findRange - Difference between max and min values
// Function 4: countAboveAverage - Count elements above average (uses calculateAverage)
//
// Input Format:
// - Vector of integers
//
// Output Format:
// - calculateSum: integer sum
// - calculateAverage: double average
// - findRange: integer (max - min)
// - countAboveAverage: integer count
//
// Example 1:
// Input: {10, 20, 30, 40, 50}
// calculateSum: 150
// calculateAverage: 30.0
// findRange: 40 (50-10)
// countAboveAverage: 2 (40 and 50 are above 30.0)
//
// Example 2:
// Input: {5}
// calculateSum: 5
// calculateAverage: 5.0
// findRange: 0
// countAboveAverage: 0
//
// Constraints:
// - 1 <= array size <= 1000
// - -10000 <= elements <= 10000

// Function Declarations (would be in ArrayStats.h)
int calculateSum(const vector<int>& arr);
double calculateAverage(const vector<int>& arr);
int findRange(const vector<int>& arr);
int countAboveAverage(const vector<int>& arr);

// Function Implementations (would be in ArrayStats.cpp)
int calculateSum(const vector<int>& arr) {
    // TODO: Implement your solution here
    // Hint: Loop through array and accumulate sum
}

double calculateAverage(const vector<int>& arr) {
    // TODO: Implement your solution here
    // Hint: Use calculateSum and divide by size
    // Remember to cast to double for proper division
}

int findRange(const vector<int>& arr) {
    // TODO: Implement your solution here
    // Hint: Find max and min elements, then subtract
}

int countAboveAverage(const vector<int>& arr) {
    // TODO: Implement your solution here
    // Hint: First calculate average using calculateAverage
    // Then count elements greater than average
}

// ============================================================================
// Problem 4: Hard - Multi-Module Geometry System
// ============================================================================
// Description:
// Create a geometry system with multiple interdependent modules:
// - Point module: Represents 2D points
// - Distance module: Calculates distances (uses Point)
// - Shape module: Calculates perimeters and areas (uses Point and Distance)
//
// This demonstrates how multiple files depend on each other through headers.
//
// Task: Implement a system to work with 2D geometric shapes
//
// Function 1: calculateDistance - Distance between two points
//             Formula: sqrt((x2-x1)^2 + (y2-y1)^2)
//
// Function 2: calculateTrianglePerimeter - Perimeter of triangle from 3 points
//             Uses calculateDistance three times
//
// Function 3: calculateTriangleArea - Area using Heron's formula
//             Formula: sqrt(s(s-a)(s-b)(s-c)) where s = (a+b+c)/2
//             Uses calculateDistance and calculateTrianglePerimeter
//
// Function 4: isValidTriangle - Check if three points form valid triangle
//             Triangle inequality: sum of any two sides > third side
//             Uses calculateDistance
//
// Input Format:
// - Six doubles representing three points: x1,y1, x2,y2, x3,y3
//
// Output Format:
// - calculateDistance: double distance
// - calculateTrianglePerimeter: double perimeter
// - calculateTriangleArea: double area
// - isValidTriangle: bool
//
// Example 1:
// Points: (0,0), (3,0), (0,4)
// Distance from (0,0) to (3,0): 3.0
// Distance from (0,0) to (0,4): 4.0
// Distance from (3,0) to (0,4): 5.0
// Perimeter: 12.0
// Area: 6.0 (s=6, sqrt(6*3*2*1) = 6.0)
// isValidTriangle: true (3+4>5, 3+5>4, 4+5>3)
//
// Example 2:
// Points: (0,0), (1,0), (2,0) - collinear points
// isValidTriangle: false
//
// Constraints:
// - -1000.0 <= coordinates <= 1000.0
// - Area calculation: return 0.0 for invalid triangles

// Function Declarations (would be split across multiple .h files)
double calculateDistance(double x1, double y1, double x2, double y2);
double calculateTrianglePerimeter(double x1, double y1, double x2, double y2, double x3, double y3);
double calculateTriangleArea(double x1, double y1, double x2, double y2, double x3, double y3);
bool isValidTriangle(double x1, double y1, double x2, double y2, double x3, double y3);

// Function Implementations (would be split across multiple .cpp files)
double calculateDistance(double x1, double y1, double x2, double y2) {
    // TODO: Implement your solution here
    // Hint: Use the distance formula with sqrt and pow
    // Remember to include <cmath> for sqrt and pow functions
}

double calculateTrianglePerimeter(double x1, double y1, double x2, double y2, double x3, double y3) {
    // TODO: Implement your solution here
    // Hint: Calculate three distances using calculateDistance
    // Side 1: point1 to point2, Side 2: point2 to point3, Side 3: point3 to point1
}

double calculateTriangleArea(double x1, double y1, double x2, double y2, double x3, double y3) {
    // TODO: Implement your solution here
    // Hint: Use Heron's formula
    // Step 1: Get perimeter using calculateTrianglePerimeter
    // Step 2: Calculate semi-perimeter s = perimeter / 2
    // Step 3: Calculate three sides using calculateDistance
    // Step 4: Area = sqrt(s * (s-a) * (s-b) * (s-c))
    // Return 0.0 if triangle is invalid
}

bool isValidTriangle(double x1, double y1, double x2, double y2, double x3, double y3) {
    // TODO: Implement your solution here
    // Hint: Calculate three sides using calculateDistance
    // Check triangle inequality: a+b>c, b+c>a, c+a>b
    // Use small epsilon (0.0001) for floating point comparison
}

// ============================================================================
// TEST FUNCTIONS
// ============================================================================

void testProblem1() {
    cout << "\n========================================" << endl;
    cout << "Testing Problem 1: Basic Calculator" << endl;
    cout << "========================================\n" << endl;
    
    // Test Case 1: Basic addition
    // Calculation: 10.0 + 5.0 = 15.0
    cout << "Test 1 (10.0 + 5.0): " << (calculate(10.0, 5.0, '+') == 15.0 ? "PASS" : "FAIL") << endl;
    
    // Test Case 2: Basic subtraction
    // Calculation: 20.0 - 8.0 = 12.0
    cout << "Test 2 (20.0 - 8.0): " << (calculate(20.0, 8.0, '-') == 12.0 ? "PASS" : "FAIL") << endl;
    
    // Test Case 3: Basic multiplication
    // Calculation: 7.0 * 6.0 = 42.0
    cout << "Test 3 (7.0 * 6.0): " << (calculate(7.0, 6.0, '*') == 42.0 ? "PASS" : "FAIL") << endl;
    
    // Test Case 4: Basic division
    // Calculation: 100.0 / 4.0 = 25.0
    cout << "Test 4 (100.0 / 4.0): " << (calculate(100.0, 4.0, '/') == 25.0 ? "PASS" : "FAIL") << endl;
    
    // Test Case 5: Division by zero (edge case)
    // Calculation: Should return -999999.0 as error indicator
    cout << "Test 5 (10.0 / 0.0): " << (calculate(10.0, 0.0, '/') == -999999.0 ? "PASS" : "FAIL") << endl;
    
    // Test Case 6: Negative numbers addition
    // Calculation: -15.0 + 10.0 = -5.0
    cout << "Test 6 (-15.0 + 10.0): " << (calculate(-15.0, 10.0, '+') == -5.0 ? "PASS" : "FAIL") << endl;
    
    // Test Case 7: Negative numbers multiplication
    // Calculation: -5.0 * -3.0 = 15.0
    cout << "Test 7 (-5.0 * -3.0): " << (calculate(-5.0, -3.0, '*') == 15.0 ? "PASS" : "FAIL") << endl;
    
    // Test Case 8: Zero operations
    // Calculation: 0.0 + 0.0 = 0.0
    cout << "Test 8 (0.0 + 0.0): " << (calculate(0.0, 0.0, '+') == 0.0 ? "PASS" : "FAIL") << endl;
}

void testProblem2() {
    cout << "\n========================================" << endl;
    cout << "Testing Problem 2: String Utilities" << endl;
    cout << "========================================\n" << endl;
    
    // Test Case 1: Count vowels in simple string
    // Calculation: "Hello" -> e, o = 2 vowels
    cout << "Test 1 countVowels(Hello): " << (countVowels("Hello") == 2 ? "PASS" : "FAIL") << endl;
    
    // Test Case 2: Count vowels with mixed case
    // Calculation: "Programming" -> o, a, i = 3 vowels
    cout << "Test 2 countVowels(Programming): " << (countVowels("Programming") == 3 ? "PASS" : "FAIL") << endl;
    
    // Test Case 3: Count vowels in string with spaces
    // Calculation: "Hello World" -> e, o, o = 3 vowels
    cout << "Test 3 countVowels(Hello World): " << (countVowels("Hello World") == 3 ? "PASS" : "FAIL") << endl;
    
    // Test Case 4: No vowels
    // Calculation: "xyz" -> 0 vowels
    cout << "Test 4 countVowels(xyz): " << (countVowels("xyz") == 0 ? "PASS" : "FAIL") << endl;
    
    // Test Case 5: Reverse simple string
    // Calculation: "Hello" reversed = "olleH"
    cout << "Test 5 reverseString(Hello): " << (reverseString("Hello") == "olleH" ? "PASS" : "FAIL") << endl;
    
    // Test Case 6: Reverse string with spaces
    // Calculation: "C++ Fun" reversed = "nuF ++C"
    cout << "Test 6 reverseString(C++ Fun): " << (reverseString("C++ Fun") == "nuF ++C" ? "PASS" : "FAIL") << endl;
    
    // Test Case 7: Palindrome check (true case)
    // Calculation: "Racecar" -> lowercase "racecar" = palindrome
    cout << "Test 7 isPalindrome(Racecar): " << (isPalindrome("Racecar") == true ? "PASS" : "FAIL") << endl;
    
    // Test Case 8: Palindrome check (false case)
    // Calculation: "Hello" -> not a palindrome
    cout << "Test 8 isPalindrome(Hello): " << (isPalindrome("Hello") == false ? "PASS" : "FAIL") << endl;
    
    // Test Case 9: Single character palindrome
    // Calculation: "A" -> is palindrome
    cout << "Test 9 isPalindrome(A): " << (isPalindrome("A") == true ? "PASS" : "FAIL") << endl;
    
    // Test Case 10: Empty string palindrome
    // Calculation: "" -> is palindrome (vacuously true)
    cout << "Test 10 isPalindrome(empty): " << (isPalindrome("") == true ? "PASS" : "FAIL") << endl;
}

void testProblem3() {
    cout << "\n========================================" << endl;
    cout << "Testing Problem 3: Array Statistics" << endl;
    cout << "========================================\n" << endl;
    
    // Test Case 1: Regular array
    // Array: {10, 20, 30, 40, 50}
    // Sum: 10+20+30+40+50 = 150
    // Average: 150/5 = 30.0
    // Range: 50-10 = 40
    // Above average: 40, 50 = 2 elements
    vector<int> arr1 = {10, 20, 30, 40, 50};
    cout << "Test 1 calculateSum({10,20,30,40,50}): " << (calculateSum(arr1) == 150 ? "PASS" : "FAIL") << endl;
    cout << "Test 1 calculateAverage({10,20,30,40,50}): " << (calculateAverage(arr1) == 30.0 ? "PASS" : "FAIL") << endl;
    cout << "Test 1 findRange({10,20,30,40,50}): " << (findRange(arr1) == 40 ? "PASS" : "FAIL") << endl;
    cout << "Test 1 countAboveAverage({10,20,30,40,50}): " << (countAboveAverage(arr1) == 2 ? "PASS" : "FAIL") << endl;
    
    // Test Case 2: Single element
    // Array: {5}
    // Sum: 5
    // Average: 5/1 = 5.0
    // Range: 5-5 = 0
    // Above average: none = 0 elements
    vector<int> arr2 = {5};
    cout << "Test 2 calculateSum({5}): " << (calculateSum(arr2) == 5 ? "PASS" : "FAIL") << endl;
    cout << "Test 2 calculateAverage({5}): " << (calculateAverage(arr2) == 5.0 ? "PASS" : "FAIL") << endl;
    cout << "Test 2 findRange({5}): " << (findRange(arr2) == 0 ? "PASS" : "FAIL") << endl;
    cout << "Test 2 countAboveAverage({5}): " << (countAboveAverage(arr2) == 0 ? "PASS" : "FAIL") << endl;
    
    // Test Case 3: Array with negative numbers
    // Array: {-10, -5, 0, 5, 10}
    // Sum: -10-5+0+5+10 = 0
    // Average: 0/5 = 0.0
    // Range: 10-(-10) = 20
    // Above average: 5, 10 = 2 elements
    vector<int> arr3 = {-10, -5, 0, 5, 10};
    cout << "Test 3 calculateSum({-10,-5,0,5,10}): " << (calculateSum(arr3) == 0 ? "PASS" : "FAIL") << endl;
    cout << "Test 3 calculateAverage({-10,-5,0,5,10}): " << (calculateAverage(arr3) == 0.0 ? "PASS" : "FAIL") << endl;
    cout << "Test 3 findRange({-10,-5,0,5,10}): " << (findRange(arr3) == 20 ? "PASS" : "FAIL") << endl;
    cout << "Test 3 countAboveAverage({-10,-5,0,5,10}): " << (countAboveAverage(arr3) == 2 ? "PASS" : "FAIL") << endl;
    
    // Test Case 4: All same elements
    // Array: {7, 7, 7, 7}
    // Sum: 7+7+7+7 = 28
    // Average: 28/4 = 7.0
    // Range: 7-7 = 0
    // Above average: none = 0 elements
    vector<int> arr4 = {7, 7, 7, 7};
    cout << "Test 4 calculateSum({7,7,7,7}): " << (calculateSum(arr4) == 28 ? "PASS" : "FAIL") << endl;
    cout << "Test 4 calculateAverage({7,7,7,7}): " << (calculateAverage(arr4) == 7.0 ? "PASS" : "FAIL") << endl;
    cout << "Test 4 findRange({7,7,7,7}): " << (findRange(arr4) == 0 ? "PASS" : "FAIL") << endl;
    cout << "Test 4 countAboveAverage({7,7,7,7}): " << (countAboveAverage(arr4) == 0 ? "PASS" : "FAIL") << endl;
    
    // Test Case 5: Two elements
    // Array: {100, 200}
    // Sum: 100+200 = 300
    // Average: 300/2 = 150.0
    // Range: 200-100 = 100
    // Above average: 200 = 1 element
    vector<int> arr5 = {100, 200};
    cout << "Test 5 calculateSum({100,200}): " << (calculateSum(arr5) == 300 ? "PASS" : "FAIL") << endl;
    cout << "Test 5 calculateAverage({100,200}): " << (calculateAverage(arr5) == 150.0 ? "PASS" : "FAIL") << endl;
    cout << "Test 5 findRange({100,200}): " << (findRange(arr5) == 100 ? "PASS" : "FAIL") << endl;
    cout << "Test 5 countAboveAverage({100,200}): " << (countAboveAverage(arr5) == 1 ? "PASS" : "FAIL") << endl;
}

void testProblem4() {
    cout << "\n========================================" << endl;
    cout << "Testing Problem 4: Geometry System" << endl;
    cout << "========================================\n" << endl;
    
    // Test Case 1: Right triangle (3-4-5 triangle)
    // Points: (0,0), (3,0), (0,4)
    // Distance (0,0) to (3,0): sqrt((3-0)^2 + (0-0)^2) = sqrt(9) = 3.0
    // Distance (0,0) to (0,4): sqrt((0-0)^2 + (4-0)^2) = sqrt(16) = 4.0
    // Distance (3,0) to (0,4): sqrt((0-3)^2 + (4-0)^2) = sqrt(9+16) = sqrt(25) = 5.0
    // Perimeter: 3 + 4 + 5 = 12.0
    // Semi-perimeter s: 12/2 = 6.0
    // Area: sqrt(6 * (6-3) * (6-4) * (6-5)) = sqrt(6*3*2*1) = sqrt(36) = 6.0
    // Valid: 3+4>5 (7>5), 3+5>4 (8>4), 4+5>3 (9>3) = true
    cout << "Test 1 calculateDistance((0,0) to (3,0)): " << (calculateDistance(0, 0, 3, 0) == 3.0 ? "PASS" : "FAIL") << endl;
    cout << "Test 1 calculateTrianglePerimeter((0,0),(3,0),(0,4)): " << (calculateTrianglePerimeter(0, 0, 3, 0, 0, 4) == 12.0 ? "PASS" : "FAIL") << endl;
    cout << "Test 1 calculateTriangleArea((0,0),(3,0),(0,4)): " << (calculateTriangleArea(0, 0, 3, 0, 0, 4) == 6.0 ? "PASS" : "FAIL") << endl;
    cout << "Test 1 isValidTriangle((0,0),(3,0),(0,4)): " << (isValidTriangle(0, 0, 3, 0, 0, 4) == true ? "PASS" : "FAIL") << endl;
    
    // Test Case 2: Collinear points (not a valid triangle)
    // Points: (0,0), (1,0), (2,0) - all on x-axis
    // Distance (0,0) to (1,0): 1.0
    // Distance (1,0) to (2,0): 1.0
    // Distance (0,0) to (2,0): 2.0
    // Valid: 1+1=2, not > 2, so false
    cout << "Test 2 isValidTriangle((0,0),(1,0),(2,0)): " << (isValidTriangle(0, 0, 1, 0, 2, 0) == false ? "PASS" : "FAIL") << endl;
    
    // Test Case 3: Equilateral triangle approximation
    // Points: (0,0), (2,0), (1,1.732)
    // Distance (0,0) to (2,0): 2.0
    // Distance (0,0) to (1,1.732): sqrt(1 + 3.0) = 2.0
    // Distance (2,0) to (1,1.732): sqrt(1 + 3.0) = 2.0
    // Perimeter: 2 + 2 + 2 = 6.0
    cout << "Test 3 calculateTrianglePerimeter((0,0),(2,0),(1,1.732)): " << (fabs(calculateTrianglePerimeter(0, 0, 2, 0, 1, 1.732) - 6.0) < 0.01 ? "PASS" : "FAIL") << endl;
    
    // Test Case 4: Distance between identical points
    // Points: (5,5) to (5,5)
    // Distance: sqrt(0 + 0) = 0.0
    cout << "Test 4 calculateDistance((5,5) to (5,5)): " << (calculateDistance(5, 5, 5, 5) == 0.0 ? "PASS" : "FAIL") << endl;
    
    // Test Case 5: Distance with negative coordinates
    // Points: (-3,-4) to (0,0)
    // Distance: sqrt(9 + 16) = sqrt(25) = 5.0
    cout << "Test 5 calculateDistance((-3,-4) to (0,0)): " << (calculateDistance(-3, -4, 0, 0) == 5.0 ? "PASS" : "FAIL") << endl;
    
    // Test Case 6: Large triangle
    // Points: (0,0), (10,0), (0,10)
    // Distance (0,0) to (10,0): 10.0
    // Distance (0,0) to (0,10): 10.0
    // Distance (10,0) to (0,10): sqrt(100+100) = sqrt(200) = 14.142135...
    // Perimeter: 10 + 10 + 14.142135 = 34.142135
    cout << "Test 6 calculateTrianglePerimeter((0,0),(10,0),(0,10)): " << (fabs(calculateTrianglePerimeter(0, 0, 10, 0, 0, 10) - 34.142135) < 0.001 ? "PASS" : "FAIL") << endl;
    
    // Test Case 7: Triangle area with integer result
    // Points: (0,0), (4,0), (0,3)
    // Sides: 4, 3, 5 (another 3-4-5 triangle)
    // Perimeter: 12, s = 6
    // Area: sqrt(6*2*3*1) = sqrt(36) = 6.0
    cout << "Test 7 calculateTriangleArea((0,0),(4,0),(0,3)): " << (calculateTriangleArea(0, 0, 4, 0, 0, 3) == 6.0 ? "PASS" : "FAIL") << endl;
    
    // Test Case 8: Valid triangle with all different sides
    // Points: (0,0), (5,0), (2,3)
    // Distance (0,0) to (5,0): 5.0
    // Distance (0,0) to (2,3): sqrt(4+9) = sqrt(13) = 3.606
    // Distance (5,0) to (2,3): sqrt(9+9) = sqrt(18) = 4.243
    // Valid: 5+3.606>4.243, 5+4.243>3.606, 3.606+4.243>5 all true
    cout << "Test 8 isValidTriangle((0,0),(5,0),(2,3)): " << (isValidTriangle(0, 0, 5, 0, 2, 3) == true ? "PASS" : "FAIL") << endl;
}

int main() {
    int choice;
    cout << "========================================" << endl;
    cout << "C++ Multi-File Compilation Practice" << endl;
    cout << "========================================" << endl;
    cout << "Choose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy): Basic Calculator Module" << endl;
    cout << "2. Problem 2 (Easy-Medium): String Utilities Module" << endl;
    cout << "3. Problem 3 (Medium): Array Statistics Module" << endl;
    cout << "4. Problem 4 (Hard): Geometry System with Dependencies" << endl;
    cout << "5. Test All Problems" << endl;
    cout << "Enter choice: ";
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