#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

// ============================================================================
// Problem 1: Easy 1 - Generic Maximum Finder
// ============================================================================
// Description:
// Create a template function that finds the maximum of two values.
// The function should work with any comparable type (int, double, char, etc.)
// Practice: Basic template type deduction - let the compiler figure out types
//
// Input Format: Two values of the same type
// Output Format: The maximum value
//
// Example 1: max_value(5, 10) -> 10
// Example 2: max_value(3.14, 2.71) -> 3.14
// Example 3: max_value('a', 'z') -> 'z'
//
// Constraints: Both parameters must be of the same comparable type
// ============================================================================
template <typename T>
T max_value(T a, T b)
{
    // TODO: Implement your solution here using template type deduction
    // Hint: Use a simple comparison operator to determine which value is larger
    return (a > b) ? a : b;
}

// ============================================================================
// Problem 2: Easy 2 - Array Sum with Multiple Types
// ============================================================================
// Description:
// Create a template function that calculates the sum of all elements in an array.
// The function should work with different numeric types (int, double, float).
// Practice: Template type deduction with arrays and explicit type specification
//
// Input Format: Array and its size
// Output Format: Sum of all elements
//
// Example 1: array_sum({1, 2, 3, 4, 5}, 5) -> 15
// Example 2: array_sum({1.5, 2.5, 3.0}, 3) -> 7.0
// Example 3: array_sum({-5, -3, 8}, 3) -> 0
//
// Constraints: Array size >= 0, elements must be numeric
// ============================================================================
template <typename T>
T array_sum(T arr[], int size)
{
    // TODO: Implement your solution here using template type deduction
    // Hint: Initialize a sum variable and loop through the array
    T sum{};
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

// ============================================================================
// Problem 3: Medium - Type-Safe Swap with Counter
// ============================================================================
// Description:
// Create a template function that swaps two values and returns how many bytes
// were swapped. Sometimes you need to explicitly specify the template type
// to avoid ambiguity or to force a specific type conversion.
// Practice: Both automatic type deduction and explicit template arguments
//
// Input Format: Two references to values of the same type
// Output Format: Number of bytes swapped (using sizeof)
//
// Example 1: swap_and_count(a=5, b=10) -> swaps values, returns sizeof(int) = 4
// Example 2: swap_and_count(a=3.14, b=2.71) -> swaps values, returns sizeof(double) = 8
// Example 3: swap_and_count<int>(a=5, b=10) -> explicit type, returns 4
//
// Constraints: Both parameters must be of the same type
// ============================================================================
template <typename T>
int swap_and_count(T &a, T &b)
{
    // TODO: Implement your solution here
    // Hint: Swap the values using a temporary variable, then return sizeof(T)
    /*  a = a + b;
     b = a - b;
     a = a - b;
     // the double has little fraction in end make the result sometimes wrong
     */
    T c = a;
    a = b;
    b = c;
    return sizeof(T);
}

// ============================================================================
// Problem 4: Hard - Generic Array Searcher with Explicit Type Control
// ============================================================================
// Description:
// Create a template function that searches for a target value in an array
// and returns the index of the first occurrence (or -1 if not found).
// The challenge: handle cases where explicit template arguments are needed
// to avoid type mismatches (e.g., searching for int in double array).
// Practice: Advanced template type deduction and explicit template arguments
//
// Input Format: Array, size, and target value to search for
// Output Format: Index of first occurrence (0-based) or -1 if not found
//
// Example 1: find_first({1,2,3,4,5}, 5, 3) -> 2 (found at index 2)
// Example 2: find_first({1.1,2.2,3.3}, 3, 2.2) -> 1
// Example 3: find_first({5,5,5,5}, 4, 5) -> 0 (first occurrence)
//
// Constraints:
// - Array size >= 0
// - Return -1 if element not found or array is empty
// - Template type T must support equality comparison (==)
// ============================================================================
template <typename T>
int find_first(T arr[], int size, T target)
{
    // TODO: Implement your solution here
    // Hint: Loop through array and compare each element with target
    // Return the index immediately when found, or -1 after checking all
    int position = 0;
    if (size == 0)
        return -1;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            i = size;
        }
        else
        {
            position++;
        }
    }
    if (arr[size - 1] != target && position == size )
    {
        return -1;
    }
    return position;
}

// ============================================================================
// TEST FUNCTIONS WITH MANUALLY VERIFIED TEST CASES
// ============================================================================

void testProblem1()
{
    cout << "\n========================================" << endl;
    cout << "Testing Problem 1: Generic Maximum Finder" << endl;
    cout << "========================================" << endl;

    // Test Case 1: Basic integers - positive numbers
    // Calculation: max(5, 10) = 10
    // Expected: 10
    cout << "Test 1 (int: 5, 10): " << (max_value(5, 10) == 10 ? "PASS" : "FAIL") << endl;

    // Test Case 2: Integers where first is larger
    // Calculation: max(20, 15) = 20
    // Expected: 20
    cout << "Test 2 (int: 20, 15): " << (max_value(20, 15) == 20 ? "PASS" : "FAIL") << endl;

    // Test Case 3: Equal integers
    // Calculation: max(7, 7) = 7
    // Expected: 7
    cout << "Test 3 (int: 7, 7): " << (max_value(7, 7) == 7 ? "PASS" : "FAIL") << endl;

    // Test Case 4: Negative integers
    // Calculation: max(-5, -10) = -5 (because -5 > -10)
    // Expected: -5
    cout << "Test 4 (int: -5, -10): " << (max_value(-5, -10) == -5 ? "PASS" : "FAIL") << endl;

    // Test Case 5: Double precision numbers
    // Calculation: max(3.14, 2.71) = 3.14
    // Expected: 3.14
    cout << "Test 5 (double: 3.14, 2.71): " << (max_value(3.14, 2.71) == 3.14 ? "PASS" : "FAIL") << endl;

    // Test Case 6: Characters (ASCII comparison)
    // Calculation: max('a', 'z') = 'z' (because 'z' has higher ASCII value)
    // Expected: 'z'
    cout << "Test 6 (char: 'a', 'z'): " << (max_value('a', 'z') == 'z' ? "PASS" : "FAIL") << endl;

    // Test Case 7: Characters - uppercase vs lowercase
    // Calculation: max('A', 'a') = 'a' (lowercase 'a' = 97, uppercase 'A' = 65)
    // Expected: 'a'
    cout << "Test 7 (char: 'A', 'a'): " << (max_value('A', 'a') == 'a' ? "PASS" : "FAIL") << endl;

    // Test Case 8: Zero and negative
    // Calculation: max(0, -1) = 0
    // Expected: 0
    cout << "Test 8 (int: 0, -1): " << (max_value(0, -1) == 0 ? "PASS" : "FAIL") << endl;
}

void testProblem2()
{
    cout << "\n========================================" << endl;
    cout << "Testing Problem 2: Array Sum with Multiple Types" << endl;
    cout << "========================================" << endl;

    // Test Case 1: Simple positive integers
    // Calculation: 1 + 2 + 3 + 4 + 5 = 15
    // Expected: 15
    int arr1[] = {1, 2, 3, 4, 5};
    cout << "Test 1 (sum of 1,2,3,4,5): " << (array_sum(arr1, 5) == 15 ? "PASS" : "FAIL") << endl;

    // Test Case 2: Array with negative numbers
    // Calculation: -5 + (-3) + 8 = -8 + 8 = 0
    // Expected: 0
    int arr2[] = {-5, -3, 8};
    cout << "Test 2 (sum of -5,-3,8): " << (array_sum(arr2, 3) == 0 ? "PASS" : "FAIL") << endl;

    // Test Case 3: Single element
    // Calculation: 42
    // Expected: 42
    int arr3[] = {42};
    cout << "Test 3 (single element 42): " << (array_sum(arr3, 1) == 42 ? "PASS" : "FAIL") << endl;

    // Test Case 4: Empty array
    // Calculation: sum of nothing = 0
    // Expected: 0
    int arr4[] = {};
    cout << "Test 4 (empty array): " << (array_sum(arr4, 0) == 0 ? "PASS" : "FAIL") << endl;

    // Test Case 5: All negative numbers
    // Calculation: -1 + (-2) + (-3) = -6
    // Expected: -6
    int arr5[] = {-1, -2, -3};
    cout << "Test 5 (sum of -1,-2,-3): " << (array_sum(arr5, 3) == -6 ? "PASS" : "FAIL") << endl;

    // Test Case 6: Double array
    // Calculation: 1.5 + 2.5 + 3.0 = 7.0
    // Expected: 7.0
    double arr6[] = {1.5, 2.5, 3.0};
    cout << "Test 6 (double: 1.5,2.5,3.0): " << (array_sum(arr6, 3) == 7.0 ? "PASS" : "FAIL") << endl;

    // Test Case 7: Array with zeros
    // Calculation: 0 + 0 + 5 + 0 = 5
    // Expected: 5
    int arr7[] = {0, 0, 5, 0};
    cout << "Test 7 (with zeros: 0,0,5,0): " << (array_sum(arr7, 4) == 5 ? "PASS" : "FAIL") << endl;

    // Test Case 8: Large numbers
    // Calculation: 100 + 200 + 300 = 600
    // Expected: 600
    int arr8[] = {100, 200, 300};
    cout << "Test 8 (large: 100,200,300): " << (array_sum(arr8, 3) == 600 ? "PASS" : "FAIL") << endl;
}

void testProblem3()
{
    cout << "\n========================================" << endl;
    cout << "Testing Problem 3: Type-Safe Swap with Counter" << endl;
    cout << "========================================" << endl;

    // Test Case 1: Swap two integers
    // Calculation: sizeof(int) typically = 4 bytes
    // Before: a=5, b=10; After: a=10, b=5
    // Expected bytes: 4
    int a1 = 5, b1 = 10;
    int bytes1 = swap_and_count(a1, b1);
    cout << "Test 1 (int swap): " << (bytes1 == sizeof(int) && a1 == 10 && b1 == 5 ? "PASS" : "FAIL") << endl;

    // Test Case 2: Swap two doubles
    // Calculation: sizeof(double) typically = 8 bytes
    // Before: a=3.14, b=2.71; After: a=2.71, b=3.14
    // Expected bytes: 8
    double a2 = 3.14, b2 = 2.71;
    int bytes2 = swap_and_count(a2, b2);
    cout << "Test 2 (double swap): " << (bytes2 == sizeof(double) && a2 == 2.71 && b2 == 3.14 ? "PASS" : "FAIL") << endl;

    // Test Case 3: Swap two characters
    // Calculation: sizeof(char) = 1 byte
    // Before: a='x', b='y'; After: a='y', b='x'
    // Expected bytes: 1
    char a3 = 'x', b3 = 'y';
    int bytes3 = swap_and_count(a3, b3);
    cout << "Test 3 (char swap): " << (bytes3 == sizeof(char) && a3 == 'y' && b3 == 'x' ? "PASS" : "FAIL") << endl;

    // Test Case 4: Swap equal values
    // Calculation: sizeof(int) = 4 bytes
    // Before: a=7, b=7; After: a=7, b=7
    // Expected bytes: 4
    int a4 = 7, b4 = 7;
    int bytes4 = swap_and_count(a4, b4);
    cout << "Test 4 (equal values): " << (bytes4 == sizeof(int) && a4 == 7 && b4 == 7 ? "PASS" : "FAIL") << endl;

    // Test Case 5: Swap negative integers
    // Calculation: sizeof(int) = 4 bytes
    // Before: a=-10, b=-20; After: a=-20, b=-10
    // Expected bytes: 4
    int a5 = -10, b5 = -20;
    int bytes5 = swap_and_count(a5, b5);
    cout << "Test 5 (negative int): " << (bytes5 == sizeof(int) && a5 == -20 && b5 == -10 ? "PASS" : "FAIL") << endl;

    // Test Case 6: Swap with zero
    // Calculation: sizeof(int) = 4 bytes
    // Before: a=0, b=100; After: a=100, b=0
    // Expected bytes: 4
    int a6 = 0, b6 = 100;
    int bytes6 = swap_and_count(a6, b6);
    cout << "Test 6 (with zero): " << (bytes6 == sizeof(int) && a6 == 100 && b6 == 0 ? "PASS" : "FAIL") << endl;

    // Test Case 7: Swap floats
    // Calculation: sizeof(float) typically = 4 bytes
    // Before: a=1.1f, b=2.2f; After: a=2.2f, b=1.1f
    // Expected bytes: 4
    float a7 = 1.1f, b7 = 2.2f;
    int bytes7 = swap_and_count(a7, b7);
    cout << "Test 7 (float swap): " << (bytes7 == sizeof(float) && abs(a7 - 2.2f) < 0.01 && abs(b7 - 1.1f) < 0.01 ? "PASS" : "FAIL") << endl;

    // Test Case 8: Swap large integers
    // Calculation: sizeof(int) = 4 bytes
    // Before: a=1000, b=2000; After: a=2000, b=1000
    // Expected bytes: 4
    int a8 = 1000, b8 = 2000;
    int bytes8 = swap_and_count(a8, b8);
    cout << "Test 8 (large int): " << (bytes8 == sizeof(int) && a8 == 2000 && b8 == 1000 ? "PASS" : "FAIL") << endl;
}

void testProblem4()
{
    cout << "\n========================================" << endl;
    cout << "Testing Problem 4: Generic Array Searcher" << endl;
    cout << "========================================" << endl;

    // Test Case 1: Find element in middle of array
    // Array: {1, 2, 3, 4, 5}, Target: 3
    // Calculation: Element 3 is at index 2 (0-based indexing)
    // Expected: 2
    int arr1[] = {1, 2, 3, 4, 5};
    cout << "Test 1 (find 3 in [1,2,3,4,5]): " << (find_first(arr1, 5, 3) == 2 ? "PASS" : "FAIL") << endl;

    // Test Case 2: Find first occurrence when duplicates exist
    // Array: {5, 5, 5, 5}, Target: 5
    // Calculation: First occurrence of 5 is at index 0
    // Expected: 0
    int arr2[] = {5, 5, 5, 5};
    cout << "Test 2 (first of duplicates): " << (find_first(arr2, 4, 5) == 0 ? "PASS" : "FAIL") << endl;

    // Test Case 3: Element not found
    // Array: {1, 2, 3, 4}, Target: 10
    // Calculation: 10 is not in the array
    // Expected: -1
    int arr3[] = {1, 2, 3, 4};
    cout << "Test 3 (element not found): " << (find_first(arr3, 4, 10) == -1 ? "PASS" : "FAIL") << endl;

    // Test Case 4: Empty array
    // Array: {}, Target: 5
    // Calculation: Empty array has no elements
    // Expected: -1
    int arr4[] = {};
    cout << "Test 4 (empty array): " << (find_first(arr4, 0, 5) == -1 ? "PASS" : "FAIL") << endl;

    // Test Case 5: Find element at beginning
    // Array: {10, 20, 30}, Target: 10
    // Calculation: Element 10 is at index 0
    // Expected: 0
    int arr5[] = {10, 20, 30};
    cout << "Test 5 (first element): " << (find_first(arr5, 3, 10) == 0 ? "PASS" : "FAIL") << endl;

    // Test Case 6: Find element at end
    // Array: {10, 20, 30}, Target: 30
    // Calculation: Element 30 is at index 2
    // Expected: 2
    int arr6[] = {10, 20, 30};
    cout << "Test 6 (last element): " << (find_first(arr6, 3, 30) == 2 ? "PASS" : "FAIL") << endl;

    // Test Case 7: Find in double array
    // Array: {1.1, 2.2, 3.3}, Target: 2.2
    // Calculation: Element 2.2 is at index 1
    // Expected: 1
    double arr7[] = {1.1, 2.2, 3.3};
    cout << "Test 7 (double array): " << (find_first(arr7, 3, 2.2) == 1 ? "PASS" : "FAIL") << endl;

    // Test Case 8: Find character in array
    // Array: {'a', 'b', 'c', 'd'}, Target: 'c'
    // Calculation: Character 'c' is at index 2
    // Expected: 2
    char arr8[] = {'a', 'b', 'c', 'd'};
    cout << "Test 8 (char array): " << (find_first(arr8, 4, 'c') == 2 ? "PASS" : "FAIL") << endl;

    // Test Case 9: Single element found
    // Array: {42}, Target: 42
    // Calculation: Element 42 is at index 0
    // Expected: 0
    int arr9[] = {42};
    cout << "Test 9 (single element): " << (find_first(arr9, 1, 42) == 0 ? "PASS" : "FAIL") << endl;
}

// ============================================================================
// MAIN FUNCTION - Interactive Menu
// ============================================================================
int main()
{
    cout << "========================================" << endl;
    cout << "Template Type Deduction Practice" << endl;
    cout << "========================================" << endl;
    cout << "\nChoose a problem to test:" << endl;
    cout << "1. Problem 1 (Easy) - Generic Maximum Finder" << endl;
    cout << "2. Problem 2 (Easy) - Array Sum with Multiple Types" << endl;
    cout << "3. Problem 3 (Medium) - Type-Safe Swap with Counter" << endl;
    cout << "4. Problem 4 (Hard) - Generic Array Searcher" << endl;
    cout << "5. Test All Problems" << endl;
    cout << "\nEnter your choice (1-5): ";

    int choice;
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
        cout << "\n========================================" << endl;
        cout << "All tests completed!" << endl;
        cout << "========================================" << endl;
        break;
    default:
        cout << "Invalid choice! Please enter 1-5." << endl;
    }

    return 0;
}