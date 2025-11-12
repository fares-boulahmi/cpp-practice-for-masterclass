#include <iostream>
#include <vector>
#include <string>
#include <concepts>
#include <type_traits>

using namespace std;

// ============================================================================
// Problem 1: Easy 1 - Numeric Type Validator
// ============================================================================
// Description:
// Create a concept called 'Numeric' that accepts only arithmetic types
// (integers and floating-point numbers). Then write a function template
// that uses this concept to add two numbers.
//
// Input: Two numbers of the same numeric type
// Output: Their sum
//
// Examples:
// add(5, 3) -> 8
// add(2.5, 1.5) -> 4.0
// add('a', 'b') -> Should NOT compile (chars are not intended here)
//
// Constraints:
// - Must use your own custom concept
// - Works with int, long, float, double, etc.
// ============================================================================

// TODO: Define your Numeric concept here
// Hint: Use std::is_arithmetic to check if a type is numeric

template <typename T>
concept Numeric = integral<T> || floating_point<T>; // Replace 'false' with your concept definition

template <Numeric T>
T add(T a, T b)
{
     // TODO: Implement your solution here
     // Hint: This should be a simple addition operation
     return a + b; // Replace with actual implementation
}

// ============================================================================
// Problem 2: Easy 2 - Container Size Checker
// ============================================================================
// Description:
// Create a concept called 'HasSize' that checks if a type has a size() method
// that returns an integral value. Then implement a function that returns
// whether a container is empty based on its size.
//
// Input: A container (vector, string, etc.)
// Output: true if size is 0, false otherwise
//
// Examples:
// vector<int> v = {1, 2, 3}; isEmpty(v) -> false
// vector<int> empty; isEmpty(empty) -> true
// string s = "hello"; isEmpty(s) -> false
// string s2 = ""; isEmpty(s2) -> true
//
// Constraints:
// - Must work with any container that has size() method
// - Must use requires expression in your concept
// ============================================================================

// TODO: Define your HasSize concept here
// Hint: Use requires expression to check for size() method
// Hint: Check that size() returns an integral type

template <typename T>
concept HasSize = requires(T &container) {
     size(container);
}; // Replace with your concept definition

template <HasSize T>
bool isEmpty(const T &container)
{
     // TODO: Implement your solution here
     // Hint: Check if size() equals 0
     if (size(container) == 0)
          return true;
     return false; // Replace with actual implementation
}

// ============================================================================
// Problem 3: Medium - Comparable Range Finder
// ============================================================================
// Description:
// Create a concept 'Comparable' that ensures a type supports comparison
// operators (<, >, <=, >=, ==, !=). Then implement a function that finds
// the minimum and maximum values in a vector of comparable elements.
//
// Input: A vector of comparable elements
// Output: A pair containing {min, max}
//
// Examples:
// vector<int> v = {5, 2, 8, 1, 9} -> findMinMax returns pair with min=1, max=9
// vector<double> v = {3.5, 1.2, 7.8} -> pair with min=1.2, max=7.8
//
// Note: Return {first_element, first_element} for single-element vectors
// Return {default_value, default_value} for empty vectors
//
// Constraints:
// - Vector size: 0 to 1000 elements
// - Must use custom Comparable concept
// - Must handle edge cases (empty, single element)
// ============================================================================

// TODO: Define your Comparable concept here
// Hint: Use requires expression to check for < and > operators
// Hint: You need to ensure T can be compared with T

template <typename T>
concept Comparable = requires(const vector<T> &vec) {
     vec[0] <= vec[0];
     vec[0] >= vec[0];
     vec[0] == vec[0];
     vec[0] < vec[0];
     vec[0] > vec[0];
     vec[0] != vec[0];
}; // Replace with your concept definition

template <Comparable T>
pair<T, T> findMinMax(const vector<T> &vec)
{
     // TODO: Implement your solution here
     // Hint: Handle empty vector case first
     // Hint: Initialize min and max with first element, then iterate
     // Hint: Compare each element and update min/max accordingly
     if (vec.size() == 0)
          return {T{}, T{}};
     T maxValue = vec[0];
     T minValue = vec[0];
     for (int i = 1; i < vec.size(); i++)
     {
          if (vec[i] > maxValue)
          {
               maxValue = vec[i];
          }
          if (vec[i] < minValue)
          {
               minValue = vec[i];
          }
     }
     T difference = maxValue - minValue;
     return {minValue, maxValue}; // Replace with actual implementation
}

// ============================================================================
// Problem 4: Hard - Generic Accumulator with Custom Concepts
// ============================================================================
// Description:
// Create TWO concepts:
// 1. 'Addable' - ensures type supports += operator
// 2. 'DefaultConstructible' - ensures type can be default constructed
//
// Then implement a function template that accumulates all elements in a vector
// using the += operator. The function should work with numbers, strings, or
// any custom type that supports these operations.
//
// Input: A vector of elements
// Output: Accumulated result (sum for numbers, concatenated for strings)
//
// Examples:
// vector<int> v = {1, 2, 3, 4} -> accumulate returns 10
// vector<double> v = {1.5, 2.5, 3.0} -> accumulate returns 7.0
// vector<string> v = {"Hello", " ", "World"} -> accumulate returns "Hello World"
// vector<int> v = {} -> accumulate returns 0 (default constructed int)
//
// Constraints:
// - Must create and use BOTH custom concepts
// - Vector size: 0 to 10000 elements
// - Must handle empty vectors by returning default constructed value
// ============================================================================

// TODO: Define your Addable concept here
// Hint: Check if type T supports += operation with another T
// Hint: Use requires(T a, T b) { a += b; }

template <typename T>
concept Addable = false; // Replace with your concept definition

// TODO: Define your DefaultConstructible concept here
// Hint: Check if type can be created with T{}
// Hint: std::default_initializable might help or use requires { T{}; }

template <typename T>
concept DefaultConstructible = false; // Replace with your concept definition

template <typename T>
     requires Addable<T> && DefaultConstructible<T>
T accumulate(const vector<T> &vec)
{
     // TODO: Implement your solution here
     // Hint: Create a result variable initialized with T{}
     // Hint: Loop through vector and use += to accumulate
     // Hint: Return the accumulated result
     return T{}; // Replace with actual implementation
}

// ============================================================================
// TEST FUNCTIONS
// ============================================================================

void testProblem1()
{
     cout << "\n========================================" << endl;
     cout << "Testing Problem 1: Numeric Type Validator" << endl;
     cout << "========================================" << endl;

     // Test Case 1: Basic integer addition
     // Calculation: 5 + 3 = 8
     // Expected: 8
     int result1 = add(5, 3);
     cout << "Test 1 - add(5, 3): " << (result1 == 8 ? "PASS" : "FAIL")
          << " (Expected: 8, Got: " << result1 << ")" << endl;

     // Test Case 2: Negative integers
     // Calculation: -10 + 15 = 5
     // Expected: 5
     int result2 = add(-10, 15);
     cout << "Test 2 - add(-10, 15): " << (result2 == 5 ? "PASS" : "FAIL")
          << " (Expected: 5, Got: " << result2 << ")" << endl;

     // Test Case 3: Float addition
     // Calculation: 2.5 + 1.5 = 4.0
     // Expected: 4.0
     float result3 = add(2.5f, 1.5f);
     cout << "Test 3 - add(2.5f, 1.5f): " << (result3 == 4.0f ? "PASS" : "FAIL")
          << " (Expected: 4.0, Got: " << result3 << ")" << endl;

     // Test Case 4: Double addition with decimals
     // Calculation: 3.14 + 2.86 = 6.0
     // Expected: 6.0
     double result4 = add(3.14, 2.86);
     cout << "Test 4 - add(3.14, 2.86): " << (result4 == 6.0 ? "PASS" : "FAIL")
          << " (Expected: 6.0, Got: " << result4 << ")" << endl;

     // Test Case 5: Zero addition
     // Calculation: 0 + 0 = 0
     // Expected: 0
     int result5 = add(0, 0);
     cout << "Test 5 - add(0, 0): " << (result5 == 0 ? "PASS" : "FAIL")
          << " (Expected: 0, Got: " << result5 << ")" << endl;

     // Test Case 6: Large numbers
     // Calculation: 1000000 + 2000000 = 3000000
     // Expected: 3000000
     int result6 = add(1000000, 2000000);
     cout << "Test 6 - add(1000000, 2000000): " << (result6 == 3000000 ? "PASS" : "FAIL")
          << " (Expected: 3000000, Got: " << result6 << ")" << endl;

     // Test Case 7: Negative result
     // Calculation: 5 + (-10) = -5
     // Expected: -5
     int result7 = add(5, -10);
     cout << "Test 7 - add(5, -10): " << (result7 == -5 ? "PASS" : "FAIL")
          << " (Expected: -5, Got: " << result7 << ")" << endl;

     // Test Case 8: Long integers
     // Calculation: 100000L + 200000L = 300000L
     // Expected: 300000L
     long result8 = add(100000L, 200000L);
     cout << "Test 8 - add(100000L, 200000L): " << (result8 == 300000L ? "PASS" : "FAIL")
          << " (Expected: 300000, Got: " << result8 << ")" << endl;
}

void testProblem2()
{
     cout << "\n========================================" << endl;
     cout << "Testing Problem 2: Container Size Checker" << endl;
     cout << "========================================" << endl;

     // Test Case 1: Non-empty vector
     // Vector: {1, 2, 3} has size = 3
     // size != 0, so isEmpty should return false
     // Expected: false
     vector<int> v1 = {1, 2, 3};
     bool result1 = isEmpty(v1);
     cout << "Test 1 - isEmpty({1,2,3}): " << (!result1 ? "PASS" : "FAIL")
          << " (Expected: false, Got: " << (result1 ? "true" : "false") << ")" << endl;

     // Test Case 2: Empty vector
     // Vector: {} has size = 0
     // size == 0, so isEmpty should return true
     // Expected: true
     vector<int> v2;
     bool result2 = isEmpty(v2);
     cout << "Test 2 - isEmpty(empty vector): " << (result2 ? "PASS" : "FAIL")
          << " (Expected: true, Got: " << (result2 ? "true" : "false") << ")" << endl;

     // Test Case 3: Non-empty string
     // String: "hello" has size = 5
     // size != 0, so isEmpty should return false
     // Expected: false
     string s1 = "hello";
     bool result3 = isEmpty(s1);
     cout << "Test 3 - isEmpty(\"hello\"): " << (!result3 ? "PASS" : "FAIL")
          << " (Expected: false, Got: " << (result3 ? "true" : "false") << ")" << endl;

     // Test Case 4: Empty string
     // String: "" has size = 0
     // size == 0, so isEmpty should return true
     // Expected: true
     string s2 = "";
     bool result4 = isEmpty(s2);
     cout << "Test 4 - isEmpty(\"\"): " << (result4 ? "PASS" : "FAIL")
          << " (Expected: true, Got: " << (result4 ? "true" : "false") << ")" << endl;

     // Test Case 5: Single element vector
     // Vector: {42} has size = 1
     // size != 0, so isEmpty should return false
     // Expected: false
     vector<int> v3 = {42};
     bool result5 = isEmpty(v3);
     cout << "Test 5 - isEmpty({42}): " << (!result5 ? "PASS" : "FAIL")
          << " (Expected: false, Got: " << (result5 ? "true" : "false") << ")" << endl;

     // Test Case 6: Large vector
     // Vector with 100 elements has size = 100
     // size != 0, so isEmpty should return false
     // Expected: false
     vector<int> v4(100, 5);
     bool result6 = isEmpty(v4);
     cout << "Test 6 - isEmpty(vector with 100 elements): " << (!result6 ? "PASS" : "FAIL")
          << " (Expected: false, Got: " << (result6 ? "true" : "false") << ")" << endl;

     // Test Case 7: String with spaces
     // String: "   " has size = 3
     // size != 0, so isEmpty should return false
     // Expected: false
     string s3 = "   ";
     bool result7 = isEmpty(s3);
     cout << "Test 7 - isEmpty(\"   \"): " << (!result7 ? "PASS" : "FAIL")
          << " (Expected: false, Got: " << (result7 ? "true" : "false") << ")" << endl;

     // Test Case 8: Vector of strings (empty)
     // Vector: {} has size = 0
     // size == 0, so isEmpty should return true
     // Expected: true
     vector<string> v5;
     bool result8 = isEmpty(v5);
     cout << "Test 8 - isEmpty(empty vector<string>): " << (result8 ? "PASS" : "FAIL")
          << " (Expected: true, Got: " << (result8 ? "true" : "false") << ")" << endl;
}

void testProblem3()
{
     cout << "\n========================================" << endl;
     cout << "Testing Problem 3: Comparable Range Finder" << endl;
     cout << "========================================" << endl;

     // Test Case 1: Normal case with integers
     // Vector: {5, 2, 8, 1, 9}
     // Min = 1 (smallest), Max = 9 (largest)
     // Expected: {1, 9}
     vector<int> v1 = {5, 2, 8, 1, 9};
     pair<int, int> result1 = findMinMax(v1);
     cout << "Test 1 - findMinMax({5,2,8,1,9}): "
          << (result1.first == 1 && result1.second == 9 ? "PASS" : "FAIL")
          << " (Expected: {1, 9}, Got: {" << result1.first << ", " << result1.second << "})" << endl;

     // Test Case 2: Single element
     // Vector: {42}
     // Only one element, so min = max = 42
     // Expected: {42, 42}
     vector<int> v2 = {42};
     pair<int, int> result2 = findMinMax(v2);
     cout << "Test 2 - findMinMax({42}): "
          << (result2.first == 42 && result2.second == 42 ? "PASS" : "FAIL")
          << " (Expected: {42, 42}, Got: {" << result2.first << ", " << result2.second << "})" << endl;

     // Test Case 3: All same elements
     // Vector: {7, 7, 7, 7}
     // All elements are 7, so min = max = 7
     // Expected: {7, 7}
     vector<int> v3 = {7, 7, 7, 7};
     pair<int, int> result3 = findMinMax(v3);
     cout << "Test 3 - findMinMax({7,7,7,7}): "
          << (result3.first == 7 && result3.second == 7 ? "PASS" : "FAIL")
          << " (Expected: {7, 7}, Got: {" << result3.first << ", " << result3.second << "})" << endl;

     // Test Case 4: Negative numbers
     // Vector: {-5, -2, -8, -1, -9}
     // Min = -9 (most negative), Max = -1 (least negative)
     // Expected: {-9, -1}
     vector<int> v4 = {-5, -2, -8, -1, -9};
     pair<int, int> result4 = findMinMax(v4);
     cout << "Test 4 - findMinMax({-5,-2,-8,-1,-9}): "
          << (result4.first == -9 && result4.second == -1 ? "PASS" : "FAIL")
          << " (Expected: {-9, -1}, Got: {" << result4.first << ", " << result4.second << "})" << endl;

     // Test Case 5: Mixed positive and negative
     // Vector: {-3, 5, -10, 8, 0}
     // Min = -10, Max = 8
     // Expected: {-10, 8}
     vector<int> v5 = {-3, 5, -10, 8, 0};
     pair<int, int> result5 = findMinMax(v5);
     cout << "Test 5 - findMinMax({-3,5,-10,8,0}): "
          << (result5.first == -10 && result5.second == 8 ? "PASS" : "FAIL")
          << " (Expected: {-10, 8}, Got: {" << result5.first << ", " << result5.second << "})" << endl;

     // Test Case 6: Doubles/floats
     // Vector: {3.5, 1.2, 7.8, 2.1}
     // Min = 1.2, Max = 7.8
     // Expected: {1.2, 7.8}
     vector<double> v6 = {3.5, 1.2, 7.8, 2.1};
     pair<double, double> result6 = findMinMax(v6);
     cout << "Test 6 - findMinMax({3.5,1.2,7.8,2.1}): "
          << (result6.first == 1.2 && result6.second == 7.8 ? "PASS" : "FAIL")
          << " (Expected: {1.2, 7.8}, Got: {" << result6.first << ", " << result6.second << "})" << endl;

     // Test Case 7: Two elements
     // Vector: {10, 20}
     // Min = 10, Max = 20
     // Expected: {10, 20}
     vector<int> v7 = {10, 20};
     pair<int, int> result7 = findMinMax(v7);
     cout << "Test 7 - findMinMax({10,20}): "
          << (result7.first == 10 && result7.second == 20 ? "PASS" : "FAIL")
          << " (Expected: {10, 20}, Got: {" << result7.first << ", " << result7.second << "})" << endl;

     // Test Case 8: Empty vector
     // Vector: {}
     // No elements, return default constructed values {0, 0}
     // Expected: {0, 0}
     vector<int> v8;
     pair<int, int> result8 = findMinMax(v8);
     cout << "Test 8 - findMinMax(empty vector): "
          << (result8.first == 0 && result8.second == 0 ? "PASS" : "FAIL")
          << " (Expected: {0, 0}, Got: {" << result8.first << ", " << result8.second << "})" << endl;
}
/*
void testProblem4() {
    cout << "\n========================================" << endl;
    cout << "Testing Problem 4: Generic Accumulator" << endl;
    cout << "========================================" << endl;

    // Test Case 1: Sum of integers
    // Vector: {1, 2, 3, 4}
    // Calculation: 0 + 1 = 1, 1 + 2 = 3, 3 + 3 = 6, 6 + 4 = 10
    // Expected: 10
    vector<int> v1 = {1, 2, 3, 4};
    int result1 = accumulate(v1);
    cout << "Test 1 - accumulate({1,2,3,4}): " << (result1 == 10 ? "PASS" : "FAIL")
         << " (Expected: 10, Got: " << result1 << ")" << endl;

    // Test Case 2: Sum of doubles
    // Vector: {1.5, 2.5, 3.0}
    // Calculation: 0.0 + 1.5 = 1.5, 1.5 + 2.5 = 4.0, 4.0 + 3.0 = 7.0
    // Expected: 7.0
    vector<double> v2 = {1.5, 2.5, 3.0};
    double result2 = accumulate(v2);
    cout << "Test 2 - accumulate({1.5,2.5,3.0}): " << (result2 == 7.0 ? "PASS" : "FAIL")
         << " (Expected: 7.0, Got: " << result2 << ")" << endl;

    // Test Case 3: String concatenation
    // Vector: {"Hello", " ", "World"}
    // Calculation: "" + "Hello" = "Hello", "Hello" + " " = "Hello ", "Hello " + "World" = "Hello World"
    // Expected: "Hello World"
    vector<string> v3 = {"Hello", " ", "World"};
    string result3 = accumulate(v3);
    cout << "Test 3 - accumulate({\"Hello\",\" \",\"World\"}): "
         << (result3 == "Hello World" ? "PASS" : "FAIL")
         << " (Expected: \"Hello World\", Got: \"" << result3 << "\")" << endl;

    // Test Case 4: Empty vector of integers
    // Vector: {}
    // No elements to add, return default constructed int (0)
    // Expected: 0
    vector<int> v4;
    int result4 = accumulate(v4);
    cout << "Test 4 - accumulate(empty int vector): " << (result4 == 0 ? "PASS" : "FAIL")
         << " (Expected: 0, Got: " << result4 << ")" << endl;

    // Test Case 5: Single element
    // Vector: {100}
    // Calculation: 0 + 100 = 100
    // Expected: 100
    vector<int> v5 = {100};
    int result5 = accumulate(v5);
    cout << "Test 5 - accumulate({100}): " << (result5 == 100 ? "PASS" : "FAIL")
         << " (Expected: 100, Got: " << result5 << ")" << endl;

    // Test Case 6: Negative numbers
    // Vector: {-5, -3, -2}
    // Calculation: 0 + (-5) = -5, -5 + (-3) = -8, -8 + (-2) = -10
    // Expected: -10
    vector<int> v6 = {-5, -3, -2};
    int result6 = accumulate(v6);
    cout << "Test 6 - accumulate({-5,-3,-2}): " << (result6 == -10 ? "PASS" : "FAIL")
         << " (Expected: -10, Got: " << result6 << ")" << endl;

    // Test Case 7: Mixed positive and negative
    // Vector: {10, -5, 3, -2}
    // Calculation: 0 + 10 = 10, 10 + (-5) = 5, 5 + 3 = 8, 8 + (-2) = 6
    // Expected: 6
    vector<int> v7 = {10, -5, 3, -2};
    int result7 = accumulate(v7);
    cout << "Test 7 - accumulate({10,-5,3,-2}): " << (result7 == 6 ? "PASS" : "FAIL")
         << " (Expected: 6, Got: " << result7 << ")" << endl;

    // Test Case 8: Empty string vector
    // Vector: {}
    // No elements, return default constructed string ("")
    // Expected: ""
    vector<string> v8;
    string result8 = accumulate(v8);
    cout << "Test 8 - accumulate(empty string vector): " << (result8 == "" ? "PASS" : "FAIL")
         << " (Expected: \"\", Got: \"" << result8 << "\")" << endl;
} */

int main()
{
     int choice;
     cout << "\n============================================" << endl;
     cout << "   C++20 Concepts Practice Problems" << endl;
     cout << "============================================" << endl;
     cout << "Choose a problem to test (1-4) or 5 to test all:" << endl;
     cout << "1. Problem 1 (Easy 1) - Numeric Type Validator" << endl;
     cout << "2. Problem 2 (Easy 2) - Container Size Checker" << endl;
     cout << "3. Problem 3 (Medium) - Comparable Range Finder" << endl;
     cout << "4. Problem 4 (Hard) - Generic Accumulator" << endl;
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
     // case 4: testProblem4(); break;
     case 5:
          testProblem1();
          testProblem2();
          testProblem3();
          // testProblem4();
          break;
     default:
          cout << "Invalid choice! Please enter 1-5." << endl;
     }

     cout << "\n============================================" << endl;
     cout << "Testing complete!" << endl;
     cout << "============================================\n"
          << endl;

     return 0;
}