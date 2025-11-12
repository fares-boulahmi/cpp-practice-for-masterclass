#include <iostream>
#include <vector>
#include <string>
#include <concepts>
#include <cmath>

using namespace std;

// ============================================================================
// Problem 1: Easy 1 - Type-Safe Arithmetic Calculator
// ============================================================================
// Description:
// Create a template function that adds two numbers together, but ONLY accepts
// integral types (int, long, short, char, etc.) using a requires clause.
// The function should reject floating-point types at compile time.
//
// Input Format: Two parameters of the same integral type
// Output Format: Return their sum
//
// Examples:
// calculate(5, 10) -> 15
// calculate(100, -50) -> 50
// calculate('A', 2) -> 'C' (ASCII: 65 + 2 = 67)
//
// Constraints:
// - Must use requires clause with std::integral concept
// - Both parameters must be the same type
// - Function should NOT compile with floating-point types
template <typename To, typename From>
concept intAcceptal = requires(To a, From b) {
    requires integral<To> && integral<From>;
    (sizeof(To) < 4) && // Type To must be smaller than 4 bytes
        requires(To a, From b)
    {
        {a + b}->std::convertible_to<int>; // Ensure addition is valid and convertible to int
        requires(a + b) < 256;             // Ensure result of a+b is less than 256
    };
};
template <typename To, typename From>
    requires intAcceptal<To, From>
To problem1Solution(To a, From b)
{
    // TODO: Implement your solution here using requires clause
    // Hint: Simply return the sum of the two parameters
    To result = a + b;
    return result;
}

// ============================================================================
// Problem 2: Easy 2 - Safe Division Function
// ============================================================================
// Description:
// Create a template function that divides two numbers, but uses a requires
// clause to ensure the type is a floating-point type (float, double, long double).
// This ensures precision in division operations.
//
// Input Format: Two parameters of the same floating-point type
// Output Format: Return the result of a/b
//
// Examples:
// safeDivide(10.0, 2.0) -> 5.0
// safeDivide(7.5, 2.5) -> 3.0
// safeDivide(1.0, 3.0) -> 0.333333...
//
// Constraints:
// - Must use requires clause with std::floating_point concept
// - Assume divisor is never zero (we won't test with zero)
// - Should NOT compile with integral types

template <typename T>
    requires std::floating_point<T>
T problem2Solution(T a, T b)
{
    // TODO: Implement your solution here using requires clause
    // Hint: Return the quotient of a divided by b
    return a / b;
}

// ============================================================================
// Problem 3: Medium - Constrained Array Sum
// ============================================================================
// Description:
// Create a template function that calculates the sum of all elements in an array.
// Use a requires clause with a compound requirement to ensure:
// 1. The type T is an integral type
// 2. The type T supports the addition operator (+)
// 3. The type T can be compared (for potential future extensions)
//
// Input Format: Pointer to array of type T, and size of array
// Output Format: Return sum of all elements
//
// Examples:
// int arr1[] = {1, 2, 3, 4, 5}; -> sum = 15
// int arr2[] = {10, -5, 3, -2}; -> sum = 6
// long arr3[] = {100, 200, 300}; -> sum = 600
//
// Constraints:
// - Must use requires clause with multiple requirements
// - Array size is always >= 1
// - Use compound requirements to check operations

template <typename T>
    requires std::integral<T> && requires(T a, T b) {
        { a + b } -> std::convertible_to<T>;
        { a < b } -> std::convertible_to<bool>;
    }
T problem3Solution(T *arr, int size)
{
    // TODO: Implement your solution here using requires clause
    // Hint: Loop through the array and accumulate the sum
    T sum{};
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum;
}

// ============================================================================
// Problem 4: Hard - Generic Container Statistical Analyzer
// ============================================================================
// Description:
// Create a template function that calculates the average of numeric values.
// Use advanced requires clause with multiple compound requirements to ensure:
// 1. The type supports arithmetic operations (+, /)
// 2. The type can be constructed from int (for initialization)
// 3. The type can be divided to produce a double result
//
// The function should work with both integral and floating-point types, and
// return a double for precision.
//
// Input Format: Pointer to array of type T, and size of array
// Output Format: Return average as double
//
// Examples:
// int arr1[] = {10, 20, 30, 40}; -> average = 25.0
// double arr2[] = {1.5, 2.5, 3.5}; -> average = 2.5
// int arr3[] = {7, 8, 9}; -> average = 8.0
//
// Constraints:
// - Must use requires clause with compound requirements
// - Array size is always >= 1
// - Return type must be double for precision
// - Type must support arithmetic and conversion operations

template <typename T>
    requires requires(T a, T b, int i) {
        { a + b } -> std::convertible_to<T>;
        { T(i) } -> std::convertible_to<T>;
        { a / i } -> std::convertible_to<double>;
    }
double problem4Solution(T *arr, int size)
{
    // TODO: Implement your solution here using requires clause
    // Hint: Calculate sum, then divide by size. Cast appropriately to double.
    return 0;
}

// ============================================================================
// TEST FUNCTIONS
// ============================================================================

void testProblem1()
{
    cout << "\n=== Testing Problem 1: Type-Safe Arithmetic Calculator ===" << endl;

    // Test Case 1: Basic positive integers
    // Calculation: 5 + 10 = 15
    // Expected: 15
    cout << "Test 1 (5 + 10): " << (problem1Solution(5, 10) == 15 ? "PASS" : "FAIL") << endl;

    // Test Case 2: Negative and positive
    // Calculation: 100 + (-50) = 50
    // Expected: 50
    cout << "Test 2 (100 + (-50)): " << (problem1Solution(100, -50) == 50 ? "PASS" : "FAIL") << endl;

    // Test Case 3: Both negative
    // Calculation: (-20) + (-30) = -50
    // Expected: -50
    cout << "Test 3 ((-20) + (-30)): " << (problem1Solution(-20, -30) == -50 ? "PASS" : "FAIL") << endl;

    // Test Case 4: Zero addition
    // Calculation: 0 + 42 = 42
    // Expected: 42
    cout << "Test 4 (0 + 42): " << (problem1Solution(0, 42) == 42 ? "PASS" : "FAIL") << endl;

    // Test Case 5: Character arithmetic
    // Calculation: 'A' (65) + 2 = 67 = 'C'
    // Expected: 'C'
    cout << "Test 5 ('A' + 2): " << (problem1Solution('A', 2) == 'C' ? "PASS" : "FAIL") << endl;

    // Test Case 6: Large numbers
    // Calculation: 1000000 + 2000000 = 3000000
    // Expected: 3000000
    cout << "Test 6 (1000000 + 2000000): " << (problem1Solution(1000000, 2000000) == 3000000 ? "PASS" : "FAIL") << endl;

    // Test Case 7: Small negative numbers
    // Calculation: (-1) + (-1) = -2
    // Expected: -2
    cout << "Test 7 ((-1) + (-1)): " << (problem1Solution(-1, -1) == -2 ? "PASS" : "FAIL") << endl;

    // Test Case 8: Long type
    // Calculation: 999999999L + 1L = 1000000000L
    // Expected: 1000000000L
    cout << "Test 8 (999999999L + 1L): " << (problem1Solution(999999999L, 1L) == 1000000000L ? "PASS" : "FAIL") << endl;
}

void testProblem2()
{
    cout << "\n=== Testing Problem 2: Safe Division Function ===" << endl;

    // Test Case 1: Basic division
    // Calculation: 10.0 / 2.0 = 5.0
    // Expected: 5.0
    cout << "Test 1 (10.0 / 2.0): " << (problem2Solution(10.0, 2.0) == 5.0 ? "PASS" : "FAIL") << endl;

    // Test Case 2: Decimal division
    // Calculation: 7.5 / 2.5 = 3.0
    // Expected: 3.0
    cout << "Test 2 (7.5 / 2.5): " << (problem2Solution(7.5, 2.5) == 3.0 ? "PASS" : "FAIL") << endl;

    // Test Case 3: Result less than 1
    // Calculation: 1.0 / 4.0 = 0.25
    // Expected: 0.25
    cout << "Test 3 (1.0 / 4.0): " << (problem2Solution(1.0, 4.0) == 0.25 ? "PASS" : "FAIL") << endl;

    // Test Case 4: Large numbers
    // Calculation: 1000.0 / 10.0 = 100.0
    // Expected: 100.0
    cout << "Test 4 (1000.0 / 10.0): " << (problem2Solution(1000.0, 10.0) == 100.0 ? "PASS" : "FAIL") << endl;

    // Test Case 5: Negative division
    // Calculation: (-20.0) / 4.0 = -5.0
    // Expected: -5.0
    cout << "Test 5 ((-20.0) / 4.0): " << (problem2Solution(-20.0, 4.0) == -5.0 ? "PASS" : "FAIL") << endl;

    // Test Case 6: Both negative
    // Calculation: (-15.0) / (-3.0) = 5.0
    // Expected: 5.0
    cout << "Test 6 ((-15.0) / (-3.0)): " << (problem2Solution(-15.0, -3.0) == 5.0 ? "PASS" : "FAIL") << endl;

    // Test Case 7: Float type
    // Calculation: 9.0f / 3.0f = 3.0f
    // Expected: 3.0f
    cout << "Test 7 (9.0f / 3.0f): " << (problem2Solution(9.0f, 3.0f) == 3.0f ? "PASS" : "FAIL") << endl;

    // Test Case 8: Small division
    // Calculation: 0.5 / 0.25 = 2.0
    // Expected: 2.0
    cout << "Test 8 (0.5 / 0.25): " << (problem2Solution(0.5, 0.25) == 2.0 ? "PASS" : "FAIL") << endl;
}

void testProblem3()
{
    cout << "\n=== Testing Problem 3: Constrained Array Sum ===" << endl;

    // Test Case 1: Basic positive array
    // Calculation: 1 + 2 + 3 + 4 + 5 = 15
    // Expected: 15
    int arr1[] = {1, 2, 3, 4, 5};
    cout << "Test 1 ([1,2,3,4,5]): " << (problem3Solution(arr1, 5) == 15 ? "PASS" : "FAIL") << endl;

    // Test Case 2: Mixed positive and negative
    // Calculation: 10 + (-5) + 3 + (-2) = 6
    // Expected: 6
    int arr2[] = {10, -5, 3, -2};
    cout << "Test 2 ([10,-5,3,-2]): " << (problem3Solution(arr2, 4) == 6 ? "PASS" : "FAIL") << endl;

    // Test Case 3: Large numbers
    // Calculation: 100 + 200 + 300 = 600
    // Expected: 600
    long arr3[] = {100, 200, 300};
    cout << "Test 3 ([100,200,300]): " << (problem3Solution(arr3, 3) == 600L ? "PASS" : "FAIL") << endl;

    // Test Case 4: Single element
    // Calculation: 42 = 42
    // Expected: 42
    int arr4[] = {42};
    cout << "Test 4 ([42]): " << (problem3Solution(arr4, 1) == 42 ? "PASS" : "FAIL") << endl;

    // Test Case 5: All negative
    // Calculation: (-1) + (-2) + (-3) = -6
    // Expected: -6
    int arr5[] = {-1, -2, -3};
    cout << "Test 5 ([-1,-2,-3]): " << (problem3Solution(arr5, 3) == -6 ? "PASS" : "FAIL") << endl;

    // Test Case 6: Contains zero
    // Calculation: 5 + 0 + 10 + 0 + 5 = 20
    // Expected: 20
    int arr6[] = {5, 0, 10, 0, 5};
    cout << "Test 6 ([5,0,10,0,5]): " << (problem3Solution(arr6, 5) == 20 ? "PASS" : "FAIL") << endl;

    // Test Case 7: Large array
    // Calculation: 1+1+1+1+1+1+1+1+1+1 = 10
    // Expected: 10
    int arr7[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    cout << "Test 7 ([1,1,1,1,1,1,1,1,1,1]): " << (problem3Solution(arr7, 10) == 10 ? "PASS" : "FAIL") << endl;

    // Test Case 8: Alternating positive/negative
    // Calculation: 10 + (-10) + 20 + (-20) + 5 = 5
    // Expected: 5
    int arr8[] = {10, -10, 20, -20, 5};
    cout << "Test 8 ([10,-10,20,-20,5]): " << (problem3Solution(arr8, 5) == 5 ? "PASS" : "FAIL") << endl;
}

void testProblem4()
{
    cout << "\n=== Testing Problem 4: Generic Container Statistical Analyzer ===" << endl;

    // Test Case 1: Integer array - even division
    // Calculation: (10 + 20 + 30 + 40) / 4 = 100 / 4 = 25.0
    // Expected: 25.0
    int arr1[] = {10, 20, 30, 40};
    cout << "Test 1 ([10,20,30,40]): " << (problem4Solution(arr1, 4) == 25.0 ? "PASS" : "FAIL") << endl;

    // Test Case 2: Double array
    // Calculation: (1.5 + 2.5 + 3.5) / 3 = 7.5 / 3 = 2.5
    // Expected: 2.5
    double arr2[] = {1.5, 2.5, 3.5};
    cout << "Test 2 ([1.5,2.5,3.5]): " << (problem4Solution(arr2, 3) == 2.5 ? "PASS" : "FAIL") << endl;

    // Test Case 3: Integer array - non-even division
    // Calculation: (7 + 8 + 9) / 3 = 24 / 3 = 8.0
    // Expected: 8.0
    int arr3[] = {7, 8, 9};
    cout << "Test 3 ([7,8,9]): " << (problem4Solution(arr3, 3) == 8.0 ? "PASS" : "FAIL") << endl;

    // Test Case 4: Single element
    // Calculation: 100 / 1 = 100.0
    // Expected: 100.0
    int arr4[] = {100};
    cout << "Test 4 ([100]): " << (problem4Solution(arr4, 1) == 100.0 ? "PASS" : "FAIL") << endl;

    // Test Case 5: With negative numbers
    // Calculation: (10 + (-20) + 30) / 3 = 20 / 3 = 6.666...
    // Expected: 6.666666666666667 (approximately)
    int arr5[] = {10, -20, 30};
    double result5 = problem4Solution(arr5, 3);
    cout << "Test 5 ([10,-20,30]): " << (abs(result5 - 6.666666666666667) < 0.0001 ? "PASS" : "FAIL") << endl;

    // Test Case 6: All same values
    // Calculation: (5 + 5 + 5 + 5 + 5) / 5 = 25 / 5 = 5.0
    // Expected: 5.0
    int arr6[] = {5, 5, 5, 5, 5};
    cout << "Test 6 ([5,5,5,5,5]): " << (problem4Solution(arr6, 5) == 5.0 ? "PASS" : "FAIL") << endl;

    // Test Case 7: Float array
    // Calculation: (2.0 + 4.0 + 6.0 + 8.0) / 4 = 20.0 / 4 = 5.0
    // Expected: 5.0
    float arr7[] = {2.0f, 4.0f, 6.0f, 8.0f};
    cout << "Test 7 ([2.0,4.0,6.0,8.0]): " << (problem4Solution(arr7, 4) == 5.0 ? "PASS" : "FAIL") << endl;

    // Test Case 8: Result with decimals
    // Calculation: (1 + 2 + 3 + 4) / 4 = 10 / 4 = 2.5
    // Expected: 2.5
    int arr8[] = {1, 2, 3, 4};
    cout << "Test 8 ([1,2,3,4]): " << (problem4Solution(arr8, 4) == 2.5 ? "PASS" : "FAIL") << endl;
}

// ============================================================================
// MAIN FUNCTION
// ============================================================================

int main()
{
    int choice;
    cout << "==================================================" << endl;
    cout << "  C++20 Requires Clause Practice Problems" << endl;
    cout << "==================================================" << endl;
    cout << "Choose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy) - Type-Safe Arithmetic Calculator" << endl;
    cout << "2. Problem 2 (Easy) - Safe Division Function" << endl;
    cout << "3. Problem 3 (Medium) - Constrained Array Sum" << endl;
    cout << "4. Problem 4 (Hard) - Generic Container Statistical Analyzer" << endl;
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
        cout << "Invalid choice!" << endl;
    }

    return 0;
}