#include <iostream>
#include <vector>
#include <string>
#include <concepts>
#include <cmath>

using namespace std;

// ============================================================================
// Problem 1: Easy 1 - Type-Safe Addition with Concepts
// ============================================================================
// Description:
// Create a function that adds two numbers, but ONLY accepts arithmetic types
// (int, double, float, etc.). Use C++20 concepts to constrain the template.
//
// Input: Two values of the same arithmetic type
// Output: The sum of the two values
//
// Examples:
// add(5, 3) -> 8
// add(3.5, 2.1) -> 5.6
// add(10, -5) -> 5
//
// Constraints:
// - Must use std::integral or std::floating_point concepts
// - Should work with any arithmetic type
// ============================================================================

template <typename T>
concept Arithmetic = integral<T> || floating_point<T>;

template <Arithmetic T>
T problem1Solution(T a, T b)
{
    // TODO: Implement your solution here using C++20 Concepts
    // Hint: Simply return the sum of a and b. The concept already constrains the types!
    return a + b;
}

// ============================================================================
// Problem 2: Easy 2 - Constrained Array Processor
// ============================================================================
// Description:
// Create a function that counts how many elements in an array are greater than
// a given threshold. Use concepts to ensure only numeric types are accepted.
//
// Input:
// - Array of numeric values
// - Size of array
// - Threshold value
// Output: Count of elements greater than threshold
//
// Examples:
// arr = [1, 5, 3, 8, 2], threshold = 3 -> 2 (5 and 8 are > 3)
// arr = [10, 20, 30], threshold = 15 -> 2 (20 and 30 are > 15)
// arr = [1.5, 2.5, 3.5], threshold = 2.0 -> 2 (2.5 and 3.5 are > 2.0)
//
// Constraints:
// - Use concepts to constrain the template parameter
// - Handle empty arrays (return 0)
// ============================================================================

template <typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

template <Numeric T>
int problem2Solution(T arr[], int size, T threshold)
{
    // TODO: Implement your solution here using C++20 Concepts
    // Hint: Loop through the array and count elements greater than threshold
    int greater{};
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > threshold)
            greater++;
    }
    return greater;
}

// ============================================================================
// Problem 3: Medium - Generic Min-Max Finder with Concepts
// ============================================================================
// Description:
// Create a function that finds both the minimum and maximum values in an array.
// Use concepts to ensure the type supports comparison operators.
// Return the difference between max and min.
//
// Input: Array of comparable values and its size
// Output: The difference (max - min)
//
// Examples:
// arr = [3, 1, 4, 1, 5] -> max=5, min=1, difference=4
// arr = [10, 10, 10] -> max=10, min=10, difference=0
// arr = [-5, -2, -8, -1] -> max=-1, min=-8, difference=7
//
// Constraints:
// - Use std::totally_ordered concept
// - Handle arrays with single element (return 0)
// - Array size >= 1
// ============================================================================

template <typename T>
concept Comparable = std::totally_ordered<T>;

template <Comparable T>
T problem3Solution(T arr[], int size)
{
    // TODO: Implement your solution here using C++20 Concepts
    // Hint: Initialize min and max with first element, then iterate through
    // the rest to find actual min and max values, return their difference
    if (size == 0)
        return 0;
    T maxValue = arr[0];
    T minValue = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > maxValue)
        {
            maxValue = arr[i];
        }
        if (arr[i] < minValue)
        {
            minValue = arr[i];
        }
    }
    T difference = maxValue - minValue;
    return difference;
}

// ============================================================================
// Problem 4: Hard - Generic Statistics Calculator with Multiple Concepts
// ============================================================================
// Description:
// Create a function that calculates the sum of squares of differences from mean.
// Formula: Σ(xi - mean)² where mean = (Σxi) / n
// Use concepts to ensure the type is both numeric and supports required operations.
//
// Input: Array of numeric values and its size
// Output: Sum of squared differences from mean (as double)
//
// Examples:
// arr = [2, 4, 6] -> mean=4, sum=(2-4)²+(4-4)²+(6-4)² = 4+0+4 = 8.0
// arr = [1, 2, 3, 4, 5] -> mean=3, sum=(-2)²+(-1)²+0²+1²+2² = 4+1+0+1+4 = 10.0
// arr = [10] -> mean=10, sum=(10-10)² = 0.0
//
// Constraints:
// - Must use concepts to constrain template
// - Return type is always double for precision
// - Handle single element arrays
// ============================================================================

template <typename T>
concept NumericType = (std::integral<T> || std::floating_point<T>) && requires(T a, T b) {
    { a + b } -> std::convertible_to<T>;
    { a - b } -> std::convertible_to<T>;
    { a * b } -> std::convertible_to<T>;
};

template <NumericType T>
double problem4Solution(T arr[], int size)
{
    // TODO: Implement your solution here using C++20 Concepts
    // Hint:
    // 1. Calculate the mean (sum of all elements / size)
    // 2. For each element, calculate (element - mean)²
    // 3. Sum all the squared differences
    // 4. Return the sum as double
    return 0;
}

// ============================================================================
// TEST FUNCTIONS
// ============================================================================

void testProblem1()
{
    cout << "\n=== Testing Problem 1: Type-Safe Addition ===" << endl;

    // Test Case 1: Basic positive integers
    // Calculation: 5 + 3 = 8
    // Expected: 8
    cout << "Test 1 (5 + 3): " << (problem1Solution(5, 3) == 8 ? "PASS" : "FAIL") << endl;

    // Test Case 2: Negative integers
    // Calculation: -10 + 7 = -3
    // Expected: -3
    cout << "Test 2 (-10 + 7): " << (problem1Solution(-10, 7) == -3 ? "PASS" : "FAIL") << endl;

    // Test Case 3: Both negative
    // Calculation: -5 + (-3) = -8
    // Expected: -8
    cout << "Test 3 (-5 + -3): " << (problem1Solution(-5, -3) == -8 ? "PASS" : "FAIL") << endl;

    // Test Case 4: Zero handling
    // Calculation: 0 + 15 = 15
    // Expected: 15
    cout << "Test 4 (0 + 15): " << (problem1Solution(0, 15) == 15 ? "PASS" : "FAIL") << endl;

    // Test Case 5: Floating point
    // Calculation: 3.5 + 2.5 = 6.0
    // Expected: 6.0
    cout << "Test 5 (3.5 + 2.5): " << (problem1Solution(3.5, 2.5) == 6.0 ? "PASS" : "FAIL") << endl;

    // Test Case 6: Negative floats
    // Calculation: -1.5 + 4.5 = 3.0
    // Expected: 3.0
    cout << "Test 6 (-1.5 + 4.5): " << (problem1Solution(-1.5, 4.5) == 3.0 ? "PASS" : "FAIL") << endl;

    // Test Case 7: Large numbers
    // Calculation: 1000 + 2000 = 3000
    // Expected: 3000
    cout << "Test 7 (1000 + 2000): " << (problem1Solution(1000, 2000) == 3000 ? "PASS" : "FAIL") << endl;

    // Test Case 8: Same numbers
    // Calculation: 7 + 7 = 14
    // Expected: 14
    cout << "Test 8 (7 + 7): " << (problem1Solution(7, 7) == 14 ? "PASS" : "FAIL") << endl;
}

void testProblem2()
{
    cout << "\n=== Testing Problem 2: Constrained Array Processor ===" << endl;

    // Test Case 1: Basic case
    // Array: [1, 5, 3, 8, 2], threshold: 3
    // Elements > 3: 5, 8 = 2 elements
    // Expected: 2
    int arr1[] = {1, 5, 3, 8, 2};
    cout << "Test 1 ([1,5,3,8,2] > 3): " << (problem2Solution(arr1, 5, 3) == 2 ? "PASS" : "FAIL") << endl;

    // Test Case 2: None greater
    // Array: [1, 2, 3], threshold: 5
    // Elements > 5: none = 0 elements
    // Expected: 0
    int arr2[] = {1, 2, 3};
    cout << "Test 2 ([1,2,3] > 5): " << (problem2Solution(arr2, 3, 5) == 0 ? "PASS" : "FAIL") << endl;

    // Test Case 3: All greater
    // Array: [10, 20, 30], threshold: 5
    // Elements > 5: 10, 20, 30 = 3 elements
    // Expected: 3
    int arr3[] = {10, 20, 30};
    cout << "Test 3 ([10,20,30] > 5): " << (problem2Solution(arr3, 3, 5) == 3 ? "PASS" : "FAIL") << endl;

    // Test Case 4: Negative numbers
    // Array: [-5, -2, 3, 7], threshold: 0
    // Elements > 0: 3, 7 = 2 elements
    // Expected: 2
    int arr4[] = {-5, -2, 3, 7};
    cout << "Test 4 ([-5,-2,3,7] > 0): " << (problem2Solution(arr4, 4, 0) == 2 ? "PASS" : "FAIL") << endl;

    // Test Case 5: Single element greater
    // Array: [100], threshold: 50
    // Elements > 50: 100 = 1 element
    // Expected: 1
    int arr5[] = {100};
    cout << "Test 5 ([100] > 50): " << (problem2Solution(arr5, 1, 50) == 1 ? "PASS" : "FAIL") << endl;

    // Test Case 6: Equal to threshold
    // Array: [5, 5, 5, 6], threshold: 5
    // Elements > 5: 6 = 1 element (equal doesn't count)
    // Expected: 1
    int arr6[] = {5, 5, 5, 6};
    cout << "Test 6 ([5,5,5,6] > 5): " << (problem2Solution(arr6, 4, 5) == 1 ? "PASS" : "FAIL") << endl;

    // Test Case 7: Floating point
    // Array: [1.5, 2.5, 3.5], threshold: 2.0
    // Elements > 2.0: 2.5, 3.5 = 2 elements
    // Expected: 2
    double arr7[] = {1.5, 2.5, 3.5};
    cout << "Test 7 ([1.5,2.5,3.5] > 2.0): " << (problem2Solution(arr7, 3, 2.0) == 2 ? "PASS" : "FAIL") << endl;

    // Test Case 8: All equal to threshold
    // Array: [3, 3, 3], threshold: 3
    // Elements > 3: none = 0 elements
    // Expected: 0
    int arr8[] = {3, 3, 3};
    cout << "Test 8 ([3,3,3] > 3): " << (problem2Solution(arr8, 3, 3) == 0 ? "PASS" : "FAIL") << endl;
}

void testProblem3()
{
    cout << "\n=== Testing Problem 3: Generic Min-Max Finder ===" << endl;

    // Test Case 1: Basic case
    // Array: [3, 1, 4, 1, 5]
    // Max: 5, Min: 1, Difference: 5 - 1 = 4
    // Expected: 4
    int arr1[] = {3, 1, 4, 1, 5};
    cout << "Test 1 ([3,1,4,1,5]): " << (problem3Solution(arr1, 5) == 4 ? "PASS" : "FAIL") << endl;

    // Test Case 2: All same
    // Array: [10, 10, 10]
    // Max: 10, Min: 10, Difference: 10 - 10 = 0
    // Expected: 0
    int arr2[] = {10, 10, 10};
    cout << "Test 2 ([10,10,10]): " << (problem3Solution(arr2, 3) == 0 ? "PASS" : "FAIL") << endl;

    // Test Case 3: Negative numbers
    // Array: [-5, -2, -8, -1]
    // Max: -1, Min: -8, Difference: -1 - (-8) = 7
    // Expected: 7
    int arr3[] = {-5, -2, -8, -1};
    cout << "Test 3 ([-5,-2,-8,-1]): " << (problem3Solution(arr3, 4) == 7 ? "PASS" : "FAIL") << endl;

    // Test Case 4: Single element
    // Array: [42]
    // Max: 42, Min: 42, Difference: 42 - 42 = 0
    // Expected: 0
    int arr4[] = {42};
    cout << "Test 4 ([42]): " << (problem3Solution(arr4, 1) == 0 ? "PASS" : "FAIL") << endl;

    // Test Case 5: Two elements
    // Array: [5, 15]
    // Max: 15, Min: 5, Difference: 15 - 5 = 10
    // Expected: 10
    int arr5[] = {5, 15};
    cout << "Test 5 ([5,15]): " << (problem3Solution(arr5, 2) == 10 ? "PASS" : "FAIL") << endl;

    // Test Case 6: Mix of positive and negative
    // Array: [-10, 5, 0, 20, -3]
    // Max: 20, Min: -10, Difference: 20 - (-10) = 30
    // Expected: 30
    int arr6[] = {-10, 5, 0, 20, -3};
    cout << "Test 6 ([-10,5,0,20,-3]): " << (problem3Solution(arr6, 5) == 30 ? "PASS" : "FAIL") << endl;

    // Test Case 7: Descending order
    // Array: [100, 80, 60, 40, 20]
    // Max: 100, Min: 20, Difference: 100 - 20 = 80
    // Expected: 80
    int arr7[] = {100, 80, 60, 40, 20};
    cout << "Test 7 ([100,80,60,40,20]): " << (problem3Solution(arr7, 5) == 80 ? "PASS" : "FAIL") << endl;

    // Test Case 8: Floating point
    // Array: [1.5, 3.7, 2.1]
    // Max: 3.7, Min: 1.5, Difference: 3.7 - 1.5 = 2.2
    // Expected: 2.2 (with small tolerance for floating point)
    double arr8[] = {1.5, 3.7, 2.1};
    double result8 = problem4Solution(arr8, 3);
    cout << "Test 8 ([1.5,3.7,2.1]): " << (abs(problem3Solution(arr8, 3) - 2.2) < 0.0001 ? "PASS" : "FAIL") << endl;
}

void testProblem4()
{
    cout << "\n=== Testing Problem 4: Statistics Calculator ===" << endl;

    // Test Case 1: Basic case
    // Array: [2, 4, 6]
    // Mean: (2+4+6)/3 = 12/3 = 4
    // Sum: (2-4)² + (4-4)² + (6-4)² = (-2)² + 0² + 2² = 4 + 0 + 4 = 8.0
    // Expected: 8.0
    int arr1[] = {2, 4, 6};
    cout << "Test 1 ([2,4,6]): " << (abs(problem4Solution(arr1, 3) - 8.0) < 0.0001 ? "PASS" : "FAIL") << endl;

    // Test Case 2: Sequential numbers
    // Array: [1, 2, 3, 4, 5]
    // Mean: (1+2+3+4+5)/5 = 15/5 = 3
    // Sum: (1-3)² + (2-3)² + (3-3)² + (4-3)² + (5-3)²
    //    = (-2)² + (-1)² + 0² + 1² + 2²
    //    = 4 + 1 + 0 + 1 + 4 = 10.0
    // Expected: 10.0
    int arr2[] = {1, 2, 3, 4, 5};
    cout << "Test 2 ([1,2,3,4,5]): " << (abs(problem4Solution(arr2, 5) - 10.0) < 0.0001 ? "PASS" : "FAIL") << endl;

    // Test Case 3: Single element
    // Array: [10]
    // Mean: 10/1 = 10
    // Sum: (10-10)² = 0² = 0.0
    // Expected: 0.0
    int arr3[] = {10};
    cout << "Test 3 ([10]): " << (abs(problem4Solution(arr3, 1) - 0.0) < 0.0001 ? "PASS" : "FAIL") << endl;

    // Test Case 4: All same values
    // Array: [5, 5, 5, 5]
    // Mean: 20/4 = 5
    // Sum: (5-5)² + (5-5)² + (5-5)² + (5-5)² = 0 + 0 + 0 + 0 = 0.0
    // Expected: 0.0
    int arr4[] = {5, 5, 5, 5};
    cout << "Test 4 ([5,5,5,5]): " << (abs(problem4Solution(arr4, 4) - 0.0) < 0.0001 ? "PASS" : "FAIL") << endl;

    // Test Case 5: Negative numbers
    // Array: [-2, 0, 2]
    // Mean: (-2+0+2)/3 = 0/3 = 0
    // Sum: (-2-0)² + (0-0)² + (2-0)² = 4 + 0 + 4 = 8.0
    // Expected: 8.0
    int arr5[] = {-2, 0, 2};
    cout << "Test 5 ([-2,0,2]): " << (abs(problem4Solution(arr5, 3) - 8.0) < 0.0001 ? "PASS" : "FAIL") << endl;

    // Test Case 6: Two elements
    // Array: [10, 20]
    // Mean: (10+20)/2 = 30/2 = 15
    // Sum: (10-15)² + (20-15)² = (-5)² + 5² = 25 + 25 = 50.0
    // Expected: 50.0
    int arr6[] = {10, 20};
    cout << "Test 6 ([10,20]): " << (abs(problem4Solution(arr6, 2) - 50.0) < 0.0001 ? "PASS" : "FAIL") << endl;

    // Test Case 7: Larger spread
    // Array: [0, 10, 20, 30]
    // Mean: (0+10+20+30)/4 = 60/4 = 15
    // Sum: (0-15)² + (10-15)² + (20-15)² + (30-15)²
    //    = (-15)² + (-5)² + 5² + 15²
    //    = 225 + 25 + 25 + 225 = 500.0
    // Expected: 500.0
    int arr7[] = {0, 10, 20, 30};
    cout << "Test 7 ([0,10,20,30]): " << (abs(problem4Solution(arr7, 4) - 500.0) < 0.0001 ? "PASS" : "FAIL") << endl;

    // Test Case 8: Floating point
    // Array: [1.0, 2.0, 3.0]
    // Mean: (1.0+2.0+3.0)/3 = 6.0/3 = 2.0
    // Sum: (1.0-2.0)² + (2.0-2.0)² + (3.0-2.0)²
    //    = (-1.0)² + 0² + 1.0²
    //    = 1.0 + 0.0 + 1.0 = 2.0
    // Expected: 2.0
    double arr8[] = {1.0, 2.0, 3.0};
    cout << "Test 8 ([1.0,2.0,3.0]): " << (abs(problem4Solution(arr8, 3) - 2.0) < 0.0001 ? "PASS" : "FAIL") << endl;
}

// ============================================================================
// MAIN MENU
// ============================================================================

int main()
{
    int choice;
    cout << "\n========================================" << endl;
    cout << "  C++20 Concepts Practice Problems" << endl;
    cout << "========================================" << endl;
    cout << "Choose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy) - Type-Safe Addition" << endl;
    cout << "2. Problem 2 (Easy-Medium) - Constrained Array Processor" << endl;
    cout << "3. Problem 3 (Medium) - Generic Min-Max Finder" << endl;
    cout << "4. Problem 4 (Hard) - Statistics Calculator" << endl;
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