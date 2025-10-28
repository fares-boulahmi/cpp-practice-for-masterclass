// is the for the only lesson basicly lesson challenge not chapter
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

// ============================================================================
// Problem 1: Easy 1 - Area Calculator
// ============================================================================
// Description:
// Create overloaded functions named 'calculateArea' that compute areas of:
// 1. Square (takes 1 int parameter: side)
// 2. Rectangle (takes 2 int parameters: length, width)
// 3. Circle (takes 1 double parameter: radius)
//
// Input Format:
// - For square: one integer (side length)
// - For rectangle: two integers (length and width)
// - For circle: one double (radius)
//
// Output Format:
// - Return the calculated area as appropriate type (int for square/rectangle, double for circle)
//
// Example 1: calculateArea(5) => 25 (square: 5*5)
// Example 2: calculateArea(4, 6) => 24 (rectangle: 4*6)
// Example 3: calculateArea(3.0) => 28.27 (circle: π*3*3, where π≈3.14159)
//
// Constraints:
// - Side/length/width will be positive integers (1 to 100)
// - Radius will be positive double (0.1 to 100.0)
// - Use 3.14159 for π

// TODO: Implement these three overloaded functions
int calculateArea(int side) {
    // TODO: Implement square area calculation
    // Hint: Area of square = side * side
}

int calculateArea(int length, int width) {
    // TODO: Implement rectangle area calculation
    // Hint: Area of rectangle = length * width
}

double calculateArea(double radius) {
    // TODO: Implement circle area calculation
    // Hint: Area of circle = π * radius * radius (use 3.14159 for π)
}

// ============================================================================
// Problem 2: Easy 2 - Temperature Converter
// ============================================================================
// Description:
// Create overloaded functions named 'convertTemperature' that convert:
// 1. Single temperature from Celsius to Fahrenheit (int celsius)
// 2. Single temperature from Fahrenheit to Celsius (int fahrenheit, char scale)
//    - scale will be 'F' to indicate Fahrenheit input
// 3. Array of temperatures from Celsius to Fahrenheit (int* temps, int size)
//    - Modifies the array in-place
//
// Formulas:
// - Fahrenheit = (Celsius * 9/5) + 32
// - Celsius = (Fahrenheit - 32) * 5/9
//
// Input Format:
// - Single int: Celsius temperature
// - Int and char 'F': Fahrenheit temperature with scale indicator
// - Array pointer and size: array of Celsius temperatures
//
// Output Format:
// - Return converted temperature as int for single conversions
// - Modify array in-place for array conversion (no return)
//
// Example 1: convertTemperature(0) => 32 (0°C to °F)
// Example 2: convertTemperature(32, 'F') => 0 (32°F to °C)
// Example 3: convertTemperature({0, 100}, 2) => modifies array to {32, 212}
//
// Constraints:
// - Temperature range: -100 to 200
// - Array size: 1 to 50
// - Use integer division where applicable

// TODO: Implement these three overloaded functions
int convertTemperature(int celsius) {
    // TODO: Convert Celsius to Fahrenheit
    // Hint: F = (C * 9/5) + 32
}

int convertTemperature(int fahrenheit, char scale) {
    // TODO: Convert Fahrenheit to Celsius (scale will be 'F')
    // Hint: C = (F - 32) * 5/9
}

void convertTemperature(int* temps, int size) {
    // TODO: Convert array of Celsius to Fahrenheit in-place
    // Hint: Loop through array and apply conversion to each element
}

// ============================================================================
// Problem 3: Medium - String Processor
// ============================================================================
// Description:
// Create overloaded functions named 'processString' that:
// 1. Count vowels in a string (string text)
// 2. Count specific character in a string (string text, char target)
// 3. Count words in a string (string text, bool countWords)
//    - countWords will be true to indicate word counting mode
//
// Input Format:
// - String only: count vowels (a, e, i, o, u - case insensitive)
// - String and char: count occurrences of specific character (case sensitive)
// - String and bool: count words (words separated by spaces)
//
// Output Format:
// - Return count as integer
//
// Example 1: processString("Hello World") => 3 (vowels: e, o, o)
// Example 2: processString("Hello World", 'l') => 3 (three 'l's)
// Example 3: processString("Hello World", true) => 2 (two words)
//
// Constraints:
// - String length: 1 to 1000 characters
// - May contain letters, digits, spaces, and punctuation
// - Empty strings return 0
// - Multiple spaces count as single separator

// TODO: Implement these three overloaded functions
int processString(string text) {
    // TODO: Count vowels (a, e, i, o, u) case-insensitive
    // Hint: Loop through string, check if each char is a vowel
}

int processString(string text, char target) {
    // TODO: Count occurrences of target character (case-sensitive)
    // Hint: Loop through string, count matches with target
}

int processString(string text, bool countWords) {
    // TODO: Count words separated by spaces
    // Hint: Count transitions from space to non-space character
}

// ============================================================================
// Problem 4: Hard - Statistical Calculator
// ============================================================================
// Description:
// Create overloaded functions named 'calculate' that compute:
// 1. Sum of integers in array (int* arr, int size)
// 2. Average of integers in array (int* arr, int size, char mode)
//    - mode 's' returns sum, mode 'a' returns average (integer division)
// 3. Range (max - min) of integers (int* arr, int size, bool findRange)
//    - findRange will be true to indicate range calculation
// 4. Standard deviation (double* arr, int size, double mean)
//    - Formula: sqrt(sum((x - mean)²) / size)
//
// Input Format:
// - Array and size: compute sum
// - Array, size, and char: compute sum ('s') or average ('a')
// - Array, size, and bool: compute range (max - min)
// - Double array, size, and mean: compute standard deviation
//
// Output Format:
// - Return appropriate type (int or double)
//
// Example 1: calculate({1,2,3,4,5}, 5) => 15 (sum)
// Example 2: calculate({1,2,3,4,5}, 5, 'a') => 3 (average: 15/5)
// Example 3: calculate({1,2,3,4,5}, 5, true) => 4 (range: 5-1)
// Example 4: calculate({1.0,2.0,3.0}, 3, 2.0) => 0.816 (std dev)
//
// Constraints:
// - Array size: 1 to 100
// - Array values: -1000 to 1000
// - For std dev, mean is pre-calculated

// TODO: Implement these four overloaded functions
int calculate(int* arr, int size) {
    // TODO: Calculate sum of array elements
    // Hint: Loop and accumulate
}

int calculate(int* arr, int size, char mode) {
    // TODO: If mode is 's' return sum, if mode is 'a' return average
    // Hint: Reuse sum logic, divide for average
}

int calculate(int* arr, int size, bool findRange) {
    // TODO: Find range (max - min)
    // Hint: Find max and min values, then subtract
}

double calculate(double* arr, int size, double mean) {
    // TODO: Calculate standard deviation
    // Hint: sqrt(sum((x - mean)²) / size)
    // Use sqrt() from cmath
}

// ============================================================================
// TEST FUNCTIONS
// ============================================================================

void testProblem1() {
    cout << "\n========================================" << endl;
    cout << "Testing Problem 1: Area Calculator" << endl;
    cout << "========================================" << endl;
    
    // Test Case 1: Square with side 5
    // Calculation: 5 * 5 = 25
    cout << "Test 1 (Square side=5): " 
         << (calculateArea(5) == 25 ? "PASS" : "FAIL") 
         << " (Expected: 25)" << endl;
    
    // Test Case 2: Square with side 1
    // Calculation: 1 * 1 = 1
    cout << "Test 2 (Square side=1): " 
         << (calculateArea(1) == 1 ? "PASS" : "FAIL") 
         << " (Expected: 1)" << endl;
    
    // Test Case 3: Square with side 10
    // Calculation: 10 * 10 = 100
    cout << "Test 3 (Square side=10): " 
         << (calculateArea(10) == 100 ? "PASS" : "FAIL") 
         << " (Expected: 100)" << endl;
    
    // Test Case 4: Rectangle 4x6
    // Calculation: 4 * 6 = 24
    cout << "Test 4 (Rectangle 4x6): " 
         << (calculateArea(4, 6) == 24 ? "PASS" : "FAIL") 
         << " (Expected: 24)" << endl;
    
    // Test Case 5: Rectangle 5x5 (same as square)
    // Calculation: 5 * 5 = 25
    cout << "Test 5 (Rectangle 5x5): " 
         << (calculateArea(5, 5) == 25 ? "PASS" : "FAIL") 
         << " (Expected: 25)" << endl;
    
    // Test Case 6: Rectangle 1x100
    // Calculation: 1 * 100 = 100
    cout << "Test 6 (Rectangle 1x100): " 
         << (calculateArea(1, 100) == 100 ? "PASS" : "FAIL") 
         << " (Expected: 100)" << endl;
    
    // Test Case 7: Circle with radius 3.0
    // Calculation: 3.14159 * 3.0 * 3.0 = 28.27431
    cout << "Test 7 (Circle r=3.0): " 
         << (abs(calculateArea(3.0) - 28.27431) < 0.01 ? "PASS" : "FAIL") 
         << " (Expected: ~28.27)" << endl;
    
    // Test Case 8: Circle with radius 1.0
    // Calculation: 3.14159 * 1.0 * 1.0 = 3.14159
    cout << "Test 8 (Circle r=1.0): " 
         << (abs(calculateArea(1.0) - 3.14159) < 0.01 ? "PASS" : "FAIL") 
         << " (Expected: ~3.14)" << endl;
    
    // Test Case 9: Circle with radius 5.5
    // Calculation: 3.14159 * 5.5 * 5.5 = 95.03317
    cout << "Test 9 (Circle r=5.5): " 
         << (abs(calculateArea(5.5) - 95.03317) < 0.01 ? "PASS" : "FAIL") 
         << " (Expected: ~95.03)" << endl;
}

void testProblem2() {
    cout << "\n========================================" << endl;
    cout << "Testing Problem 2: Temperature Converter" << endl;
    cout << "========================================" << endl;
    
    // Test Case 1: 0°C to Fahrenheit
    // Calculation: (0 * 9/5) + 32 = 0 + 32 = 32
    cout << "Test 1 (0°C to °F): " 
         << (convertTemperature(0) == 32 ? "PASS" : "FAIL") 
         << " (Expected: 32)" << endl;
    
    // Test Case 2: 100°C to Fahrenheit
    // Calculation: (100 * 9/5) + 32 = 180 + 32 = 212
    cout << "Test 2 (100°C to °F): " 
         << (convertTemperature(100) == 212 ? "PASS" : "FAIL") 
         << " (Expected: 212)" << endl;
    
    // Test Case 3: -40°C to Fahrenheit
    // Calculation: (-40 * 9/5) + 32 = -72 + 32 = -40
    cout << "Test 3 (-40°C to °F): " 
         << (convertTemperature(-40) == -40 ? "PASS" : "FAIL") 
         << " (Expected: -40)" << endl;
    
    // Test Case 4: 25°C to Fahrenheit
    // Calculation: (25 * 9/5) + 32 = 45 + 32 = 77
    cout << "Test 4 (25°C to °F): " 
         << (convertTemperature(25) == 77 ? "PASS" : "FAIL") 
         << " (Expected: 77)" << endl;
    
    // Test Case 5: 32°F to Celsius
    // Calculation: (32 - 32) * 5/9 = 0 * 5/9 = 0
    cout << "Test 5 (32°F to °C): " 
         << (convertTemperature(32, 'F') == 0 ? "PASS" : "FAIL") 
         << " (Expected: 0)" << endl;
    
    // Test Case 6: 212°F to Celsius
    // Calculation: (212 - 32) * 5/9 = 180 * 5/9 = 100
    cout << "Test 6 (212°F to °C): " 
         << (convertTemperature(212, 'F') == 100 ? "PASS" : "FAIL") 
         << " (Expected: 100)" << endl;
    
    // Test Case 7: 68°F to Celsius
    // Calculation: (68 - 32) * 5/9 = 36 * 5/9 = 20
    cout << "Test 7 (68°F to °C): " 
         << (convertTemperature(68, 'F') == 20 ? "PASS" : "FAIL") 
         << " (Expected: 20)" << endl;
    
    // Test Case 8: Array conversion {0, 100, -40}
    // Calculations: 0->32, 100->212, -40->-40
    int temps1[3] = {0, 100, -40};
    convertTemperature(temps1, 3);
    cout << "Test 8 (Array {0,100,-40}): " 
         << (temps1[0] == 32 && temps1[1] == 212 && temps1[2] == -40 ? "PASS" : "FAIL") 
         << " (Expected: {32,212,-40})" << endl;
    
    // Test Case 9: Array conversion {25}
    // Calculation: 25->77
    int temps2[1] = {25};
    convertTemperature(temps2, 1);
    cout << "Test 9 (Array {25}): " 
         << (temps2[0] == 77 ? "PASS" : "FAIL") 
         << " (Expected: {77})" << endl;
}

void testProblem3() {
    cout << "\n========================================" << endl;
    cout << "Testing Problem 3: String Processor" << endl;
    cout << "========================================" << endl;
    
    // Test Case 1: Count vowels in "Hello World"
    // Vowels: e, o, o = 3 vowels
    cout << "Test 1 (Vowels in 'Hello World'): " 
         << (processString("Hello World") == 3 ? "PASS" : "FAIL") 
         << " (Expected: 3)" << endl;
    
    // Test Case 2: Count vowels in "AEIOUaeiou"
    // Vowels: all 10 characters = 10 vowels
    cout << "Test 2 (Vowels in 'AEIOUaeiou'): " 
         << (processString("AEIOUaeiou") == 10 ? "PASS" : "FAIL") 
         << " (Expected: 10)" << endl;
    
    // Test Case 3: Count vowels in "xyz"
    // Vowels: none = 0 vowels
    cout << "Test 3 (Vowels in 'xyz'): " 
         << (processString("xyz") == 0 ? "PASS" : "FAIL") 
         << " (Expected: 0)" << endl;
    
    // Test Case 4: Count vowels in "Programming"
    // Vowels: o, a, i = 3 vowels
    cout << "Test 4 (Vowels in 'Programming'): " 
         << (processString("Programming") == 3 ? "PASS" : "FAIL") 
         << " (Expected: 3)" << endl;
    
    // Test Case 5: Count 'l' in "Hello World"
    // Occurrences: l, l, l = 3
    cout << "Test 5 (Count 'l' in 'Hello World'): " 
         << (processString("Hello World", 'l') == 3 ? "PASS" : "FAIL") 
         << " (Expected: 3)" << endl;
    
    // Test Case 6: Count 'o' in "Hello World"
    // Occurrences: o, o = 2
    cout << "Test 6 (Count 'o' in 'Hello World'): " 
         << (processString("Hello World", 'o') == 2 ? "PASS" : "FAIL") 
         << " (Expected: 2)" << endl;
    
    // Test Case 7: Count 'x' in "Hello World"
    // Occurrences: none = 0
    cout << "Test 7 (Count 'x' in 'Hello World'): " 
         << (processString("Hello World", 'x') == 0 ? "PASS" : "FAIL") 
         << " (Expected: 0)" << endl;
    
    // Test Case 8: Count words in "Hello World"
    // Words: "Hello" and "World" = 2 words
    cout << "Test 8 (Words in 'Hello World'): " 
         << (processString("Hello World", true) == 2 ? "PASS" : "FAIL") 
         << " (Expected: 2)" << endl;
    
    // Test Case 9: Count words in "One Two Three Four"
    // Words: "One", "Two", "Three", "Four" = 4 words
    cout << "Test 9 (Words in 'One Two Three Four'): " 
         << (processString("One Two Three Four", true) == 4 ? "PASS" : "FAIL") 
         << " (Expected: 4)" << endl;
    
    // Test Case 10: Count words in "SingleWord"
    // Words: "SingleWord" = 1 word
    cout << "Test 10 (Words in 'SingleWord'): " 
         << (processString("SingleWord", true) == 1 ? "PASS" : "FAIL") 
         << " (Expected: 1)" << endl;
}

void testProblem4() {
    cout << "\n========================================" << endl;
    cout << "Testing Problem 4: Statistical Calculator" << endl;
    cout << "========================================" << endl;
    
    // Test Case 1: Sum of {1,2,3,4,5}
    // Calculation: 1+2+3+4+5 = 15
    int arr1[] = {1, 2, 3, 4, 5};
    cout << "Test 1 (Sum {1,2,3,4,5}): " 
         << (calculate(arr1, 5) == 15 ? "PASS" : "FAIL") 
         << " (Expected: 15)" << endl;
    
    // Test Case 2: Sum of {10}
    // Calculation: 10 = 10
    int arr2[] = {10};
    cout << "Test 2 (Sum {10}): " 
         << (calculate(arr2, 1) == 10 ? "PASS" : "FAIL") 
         << " (Expected: 10)" << endl;
    
    // Test Case 3: Sum of {-5, 5, -3, 3}
    // Calculation: -5+5-3+3 = 0
    int arr3[] = {-5, 5, -3, 3};
    cout << "Test 3 (Sum {-5,5,-3,3}): " 
         << (calculate(arr3, 4) == 0 ? "PASS" : "FAIL") 
         << " (Expected: 0)" << endl;
    
    // Test Case 4: Sum mode 's' for {2,4,6,8}
    // Calculation: 2+4+6+8 = 20
    int arr4[] = {2, 4, 6, 8};
    cout << "Test 4 (Sum mode {2,4,6,8}): " 
         << (calculate(arr4, 4, 's') == 20 ? "PASS" : "FAIL") 
         << " (Expected: 20)" << endl;
    
    // Test Case 5: Average mode 'a' for {2,4,6,8}
    // Calculation: (2+4+6+8)/4 = 20/4 = 5
    cout << "Test 5 (Avg mode {2,4,6,8}): " 
         << (calculate(arr4, 4, 'a') == 5 ? "PASS" : "FAIL") 
         << " (Expected: 5)" << endl;
    
    // Test Case 6: Average mode 'a' for {1,2,3,4,5}
    // Calculation: (1+2+3+4+5)/5 = 15/5 = 3
    cout << "Test 6 (Avg mode {1,2,3,4,5}): " 
         << (calculate(arr1, 5, 'a') == 3 ? "PASS" : "FAIL") 
         << " (Expected: 3)" << endl;
    
    // Test Case 7: Range for {1,2,3,4,5}
    // Calculation: max=5, min=1, range=5-1=4
    cout << "Test 7 (Range {1,2,3,4,5}): " 
         << (calculate(arr1, 5, true) == 4 ? "PASS" : "FAIL") 
         << " (Expected: 4)" << endl;
    
    // Test Case 8: Range for {-10, 5, 20, -5}
    // Calculation: max=20, min=-10, range=20-(-10)=30
    int arr5[] = {-10, 5, 20, -5};
    cout << "Test 8 (Range {-10,5,20,-5}): " 
         << (calculate(arr5, 4, true) == 30 ? "PASS" : "FAIL") 
         << " (Expected: 30)" << endl;
    
    // Test Case 9: Range for {7}
    // Calculation: max=7, min=7, range=7-7=0
    int arr6[] = {7};
    cout << "Test 9 (Range {7}): " 
         << (calculate(arr6, 1, true) == 0 ? "PASS" : "FAIL") 
         << " (Expected: 0)" << endl;
    
    // Test Case 10: Std dev for {1.0, 2.0, 3.0} with mean=2.0
    // Calculation: sqrt(((1-2)² + (2-2)² + (3-2)²)/3) = sqrt((1+0+1)/3) = sqrt(2/3) = 0.8164...
    double arr7[] = {1.0, 2.0, 3.0};
    cout << "Test 10 (StdDev {1,2,3} mean=2): " 
         << (abs(calculate(arr7, 3, 2.0) - 0.8164) < 0.01 ? "PASS" : "FAIL") 
         << " (Expected: ~0.816)" << endl;
    
    // Test Case 11: Std dev for {2.0, 4.0, 6.0, 8.0} with mean=5.0
    // Calculation: sqrt(((2-5)² + (4-5)² + (6-5)² + (8-5)²)/4) = sqrt((9+1+1+9)/4) = sqrt(20/4) = sqrt(5) = 2.236...
    double arr8[] = {2.0, 4.0, 6.0, 8.0};
    cout << "Test 11 (StdDev {2,4,6,8} mean=5): " 
         << (abs(calculate(arr8, 4, 5.0) - 2.236) < 0.01 ? "PASS" : "FAIL") 
         << " (Expected: ~2.236)" << endl;
}

int main() {
    int choice;
    cout << "\n============================================" << endl;
    cout << "  Function Overloading Practice Problems" << endl;
    cout << "============================================" << endl;
    cout << "Choose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy) - Area Calculator" << endl;
    cout << "2. Problem 2 (Easy-Medium) - Temperature Converter" << endl;
    cout << "3. Problem 3 (Medium) - String Processor" << endl;
    cout << "4. Problem 4 (Hard) - Statistical Calculator" << endl;
    cout << "5. Test All Problems" << endl;
    cout << "\nEnter your choice: ";
    cin >> choice;

    switch(choice) {
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
            cout << "\n========================================" << endl;
            cout << "All tests completed!" << endl;
            cout << "========================================" << endl;
            break;
        default: 
            cout << "Invalid choice!" << endl;
    }

    return 0;
}