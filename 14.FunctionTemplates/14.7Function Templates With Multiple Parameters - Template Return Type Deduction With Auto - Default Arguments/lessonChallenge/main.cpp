#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <climits>

using namespace std;

// ============================================================================
// Problem 1: Easy 1 - Generic Calculator with Default Operation
// ============================================================================
// Description:
//   Create a function template that performs basic arithmetic operations on two
//   numbers of any type. The function should have a default parameter for the
//   operation type.
//
// Input Format:
//   - Two values of the same type (int, double, float, etc.)
//   - Operation character: '+', '-', '*', '/' (default is '+')
//
// Output Format:
//   - Result of the operation (auto return type)
//
// Examples:
//   calculate(10, 5, '+') -> 15
//   calculate(10, 5, '-') -> 5
//   calculate(10, 5, '*') -> 50
//   calculate(10, 5)      -> 15 (default is addition)
//
// Constraints:
//   - Both input values must be of the same type
//   - Division by zero should return 0
//   - Only +, -, *, / operations are supported
//
template <typename T>
auto calculate(T a, T b, char op = '+')
{
    // TODO: Implement your solution here
    // Hint: Use a switch statement or if-else to handle different operations
    // Hint: Return type is automatically deduced using 'auto'
    // Hint: Handle division by zero case
    T result{};
    if (op == '+')
    {
        result = a + b;
    }
    else if (op == '-')
    {
        result = a - b;
    }
    else if (op == '*')
    {
        result = a * b;
    }
    else if (op == '/')
    {
        if (b == 0)
        {
            result = 0;
        }
        else
        {
            result = a / b;
        }
    }

    return result;
}

// ============================================================================
// Problem 2: Easy 2 - Range Value Checker with Default Bounds
// ============================================================================
// Description:
//   Create a function template that checks if a value falls within a specified
//   range. The function should have default parameters for the minimum and
//   maximum bounds.
//
// Input Format:
//   - A value to check
//   - Minimum bound (default = 0)
//   - Maximum bound (default = 100)
//
// Output Format:
//   - true if value is within [min, max], false otherwise
//
// Examples:
//   inRange(50) -> true (checks if 50 is in [0, 100])
//   inRange(150) -> false (150 is not in [0, 100])
//   inRange(5, 1, 10) -> true (5 is in [1, 10])
//   inRange(-5, -10, -1) -> true (-5 is in [-10, -1])
//
// Constraints:
//   - Value and bounds must be comparable types
//   - Range is inclusive [min, max]
//
template <typename T>
auto inRange(T value, T minBound = 0, T maxBound = 100)
{
    // TODO: Implement your solution here
    // Hint: Check if value >= minBound AND value <= maxBound
    // Hint: Return type is bool (automatically deduced)
    if (value >= minBound && value <= maxBound)
        return true;
    return false;
}

// ============================================================================
// Problem 3: Medium - Generic Array Statistics with Multiple Types
// ============================================================================
// Description:
//   Create a function template that calculates statistics from an array. The
//   function takes an array, its size, and a statistic type to calculate.
//   It should support different numeric types and have a default stat type.
//
// Input Format:
//   - Array of numeric values
//   - Size of the array
//   - Statistic type: 's' (sum), 'a' (average), 'm' (max), 'n' (min)
//   - Default statistic type is 's' (sum)
//
// Output Format:
//   - The calculated statistic value (auto return type)
//
// Examples:
//   int arr[] = {1, 2, 3, 4, 5};
//   arrayStats(arr, 5, 's') -> 15 (sum)
//   arrayStats(arr, 5, 'a') -> 3 (average: 15/5)
//   arrayStats(arr, 5, 'm') -> 5 (max)
//   arrayStats(arr, 5, 'n') -> 1 (min)
//   arrayStats(arr, 5) -> 15 (default is sum)
//
// Constraints:
//   - Array size > 0
//   - For average, integer division is acceptable
//   - Invalid stat type should return 0
//
template <typename T>
auto arrayStats(T arr[], int size, char statType = 's')
{
    // TODO: Implement your solution here
    // Hint: Use a switch statement for different statistics
    // Hint: For sum, iterate and accumulate values
    // Hint: For average, divide sum by size
    // Hint: For max/min, track the largest/smallest value seen
    // Hint: Return type is automatically deduced based on T
    if (size == 0)
        return 0;
    T maxValue = arr[0];
    T minValue = arr[0];
    T sum{};
    T Avr{};
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > maxValue)
        {
            maxValue = arr[i];
        }

        if (arr[i] < minValue)
        {
            minValue = arr[i];
        }
        sum += arr[i];
    }
    Avr = sum / size;
    if (statType == 's')
    {
        return sum;
    }
    else if (statType == 'a')
    {
        return Avr;
    }
    else if (statType == 'm')
    {
        return maxValue;
    }
    else if (statType == 'n')
    {
        return minValue;
    }
    else
    {
        return 0;
    }
}

// ============================================================================
// Problem 4: Hard - Generic Interpolation with Multiple Parameters
// ============================================================================
// Description:
//   Create a function template that performs linear interpolation between two
//   values. It should support different numeric types and have default parameters
//   for the interpolation factor and rounding preference.
//
// Linear Interpolation Formula: result = start + (end - start) * factor
//
// Input Format:
//   - Start value (type T1)
//   - End value (type T2)
//   - Interpolation factor (0.0 to 1.0, default = 0.5)
//   - Should round result? (default = false)
//
// Output Format:
//   - Interpolated value (auto return type)
//
// Examples:
//   interpolate(0, 10, 0.5) -> 5.0 (midpoint)
//   interpolate(0, 10, 0.0) -> 0.0 (start)
//   interpolate(0, 10, 1.0) -> 10.0 (end)
//   interpolate(0, 10, 0.25) -> 2.5
//   interpolate(0, 10) -> 5.0 (default factor 0.5)
//   interpolate(0.0, 100.0, 0.75, true) -> 75 (rounded)
//
// Constraints:
//   - Factor should be between 0.0 and 1.0 (clamp if outside)
//   - Support mixing integer and floating-point types
//   - When rounding, use standard rounding (0.5 rounds up)
//
template <typename T1, typename T2>
auto interpolate(T1 start, T2 end, double factor = 0.5, bool shouldRound = false)
{
    // TODO: Implement your solution here
    // Hint: Clamp factor to [0.0, 1.0] range first
    // Hint: Calculate: result = start + (end - start) * factor
    // Hint: If shouldRound is true, use round() function from <cmath>
    // Hint: Return type is automatically deduced (will be double in most cases)
    // Hint: Handle type conversion properly when mixing int and double
    return factor;
}

// ============================================================================
// TEST FUNCTIONS
// ============================================================================

void testProblem1()
{
    cout << "\n========================================" << endl;
    cout << "Testing Problem 1: Generic Calculator" << endl;
    cout << "========================================" << endl;

    // Test Case 1: Basic addition (default operation)
    // Calculation: 10 + 5 = 15
    // Expected output: 15
    cout << "Test 1 (10 + 5, default): " << (calculate(10, 5) == 15 ? "PASS" : "FAIL") << endl;

    // Test Case 2: Explicit addition
    // Calculation: 20 + 15 = 35
    // Expected output: 35
    cout << "Test 2 (20 + 15): " << (calculate(20, 15, '+') == 35 ? "PASS" : "FAIL") << endl;

    // Test Case 3: Subtraction
    // Calculation: 50 - 30 = 20
    // Expected output: 20
    cout << "Test 3 (50 - 30): " << (calculate(50, 30, '-') == 20 ? "PASS" : "FAIL") << endl;

    // Test Case 4: Multiplication
    // Calculation: 7 * 8 = 56
    // Expected output: 56
    cout << "Test 4 (7 * 8): " << (calculate(7, 8, '*') == 56 ? "PASS" : "FAIL") << endl;

    // Test Case 5: Division
    // Calculation: 100 / 4 = 25
    // Expected output: 25
    cout << "Test 5 (100 / 4): " << (calculate(100, 4, '/') == 25 ? "PASS" : "FAIL") << endl;

    // Test Case 6: Division by zero (edge case)
    // Calculation: 10 / 0 = undefined (should return 0)
    // Expected output: 0
    cout << "Test 6 (10 / 0): " << (calculate(10, 0, '/') == 0 ? "PASS" : "FAIL") << endl;

    // Test Case 7: Floating point addition
    // Calculation: 3.5 + 2.5 = 6.0
    // Expected output: 6.0
    cout << "Test 7 (3.5 + 2.5): " << (abs(calculate(3.5, 2.5, '+') - 6.0) < 0.001 ? "PASS" : "FAIL") << endl;

    // Test Case 8: Floating point multiplication
    // Calculation: 2.5 * 4.0 = 10.0
    // Expected output: 10.0
    cout << "Test 8 (2.5 * 4.0): " << (abs(calculate(2.5, 4.0, '*') - 10.0) < 0.001 ? "PASS" : "FAIL") << endl;
}

void testProblem2()
{
    cout << "\n========================================" << endl;
    cout << "Testing Problem 2: Range Checker" << endl;
    cout << "========================================" << endl;

    // Test Case 1: Value in default range [0, 100]
    // Calculation: Is 50 in [0, 100]? Yes
    // Expected output: true
    cout << "Test 1 (50 in [0,100]): " << (inRange(50) == true ? "PASS" : "FAIL") << endl;

    // Test Case 2: Value outside default range (above)
    // Calculation: Is 150 in [0, 100]? No
    // Expected output: false
    cout << "Test 2 (150 in [0,100]): " << (inRange(150) == false ? "PASS" : "FAIL") << endl;

    // Test Case 3: Value outside default range (below)
    // Calculation: Is -10 in [0, 100]? No
    // Expected output: false
    cout << "Test 3 (-10 in [0,100]): " << (inRange(-10) == false ? "PASS" : "FAIL") << endl;

    // Test Case 4: Custom range - value inside
    // Calculation: Is 5 in [1, 10]? Yes
    // Expected output: true
    cout << "Test 4 (5 in [1,10]): " << (inRange(5, 1, 10) == true ? "PASS" : "FAIL") << endl;

    // Test Case 5: Value at lower boundary (inclusive)
    // Calculation: Is 0 in [0, 100]? Yes (inclusive)
    // Expected output: true
    cout << "Test 5 (0 in [0,100]): " << (inRange(0) == true ? "PASS" : "FAIL") << endl;

    // Test Case 6: Value at upper boundary (inclusive)
    // Calculation: Is 100 in [0, 100]? Yes (inclusive)
    // Expected output: true
    cout << "Test 6 (100 in [0,100]): " << (inRange(100) == true ? "PASS" : "FAIL") << endl;

    // Test Case 7: Negative range
    // Calculation: Is -5 in [-10, -1]? Yes
    // Expected output: true
    cout << "Test 7 (-5 in [-10,-1]): " << (inRange(-5, -10, -1) == true ? "PASS" : "FAIL") << endl;

    // Test Case 8: Floating point range
    // Calculation: Is 3.14 in [3.0, 4.0]? Yes
    // Expected output: true
    cout << "Test 8 (3.14 in [3.0,4.0]): " << (inRange(3.14, 3.0, 4.0) == true ? "PASS" : "FAIL") << endl;
}

void testProblem3()
{
    cout << "\n========================================" << endl;
    cout << "Testing Problem 3: Array Statistics" << endl;
    cout << "========================================" << endl;

    // Test Case 1: Sum of integer array
    // Array: {1, 2, 3, 4, 5}
    // Calculation: 1 + 2 + 3 + 4 + 5 = 15
    // Expected output: 15
    int arr1[] = {1, 2, 3, 4, 5};
    cout << "Test 1 (sum {1,2,3,4,5}): " << (arrayStats(arr1, 5, 's') == 15 ? "PASS" : "FAIL") << endl;

    // Test Case 2: Average of integer array
    // Array: {1, 2, 3, 4, 5}
    // Calculation: (1+2+3+4+5)/5 = 15/5 = 3
    // Expected output: 3
    cout << "Test 2 (avg {1,2,3,4,5}): " << (arrayStats(arr1, 5, 'a') == 3 ? "PASS" : "FAIL") << endl;

    // Test Case 3: Maximum of integer array
    // Array: {1, 2, 3, 4, 5}
    // Calculation: max = 5
    // Expected output: 5
    cout << "Test 3 (max {1,2,3,4,5}): " << (arrayStats(arr1, 5, 'm') == 5 ? "PASS" : "FAIL") << endl;

    // Test Case 4: Minimum of integer array
    // Array: {1, 2, 3, 4, 5}
    // Calculation: min = 1
    // Expected output: 1
    cout << "Test 4 (min {1,2,3,4,5}): " << (arrayStats(arr1, 5, 'n') == 1 ? "PASS" : "FAIL") << endl;

    // Test Case 5: Default operation (sum)
    // Array: {10, 20, 30}
    // Calculation: 10 + 20 + 30 = 60
    // Expected output: 60
    int arr2[] = {10, 20, 30};
    cout << "Test 5 (default sum {10,20,30}): " << (arrayStats(arr2, 3) == 60 ? "PASS" : "FAIL") << endl;

    // Test Case 6: Array with negative numbers - sum
    // Array: {-5, -10, -15}
    // Calculation: -5 + (-10) + (-15) = -30
    // Expected output: -30
    int arr3[] = {-5, -10, -15};
    cout << "Test 6 (sum {-5,-10,-15}): " << (arrayStats(arr3, 3, 's') == -30 ? "PASS" : "FAIL") << endl;

    // Test Case 7: Array with mixed values - max
    // Array: {100, -50, 200, 75}
    // Calculation: max = 200
    // Expected output: 200
    int arr4[] = {100, -50, 200, 75};
    cout << "Test 7 (max {100,-50,200,75}): " << (arrayStats(arr4, 4, 'm') == 200 ? "PASS" : "FAIL") << endl;

    // Test Case 8: Single element array
    // Array: {42}
    // Calculation: sum = 42, avg = 42, max = 42, min = 42
    // Expected output: 42
    int arr5[] = {42};
    cout << "Test 8 (sum {42}): " << (arrayStats(arr5, 1, 's') == 42 ? "PASS" : "FAIL") << endl;
}

void testProblem4()
{
    cout << "\n========================================" << endl;
    cout << "Testing Problem 4: Interpolation" << endl;
    cout << "========================================" << endl;

    // Test Case 1: Midpoint interpolation (default factor)
    // Calculation: 0 + (10 - 0) * 0.5 = 0 + 10 * 0.5 = 5.0
    // Expected output: 5.0
    cout << "Test 1 (0 to 10, factor=0.5): " << (abs(interpolate(0, 10) - 5.0) < 0.001 ? "PASS" : "FAIL") << endl;

    // Test Case 2: Start point (factor = 0)
    // Calculation: 0 + (10 - 0) * 0.0 = 0
    // Expected output: 0.0
    cout << "Test 2 (0 to 10, factor=0.0): " << (abs(interpolate(0, 10, 0.0) - 0.0) < 0.001 ? "PASS" : "FAIL") << endl;

    // Test Case 3: End point (factor = 1)
    // Calculation: 0 + (10 - 0) * 1.0 = 10.0
    // Expected output: 10.0
    cout << "Test 3 (0 to 10, factor=1.0): " << (abs(interpolate(0, 10, 1.0) - 10.0) < 0.001 ? "PASS" : "FAIL") << endl;

    // Test Case 4: Quarter interpolation
    // Calculation: 0 + (10 - 0) * 0.25 = 0 + 2.5 = 2.5
    // Expected output: 2.5
    cout << "Test 4 (0 to 10, factor=0.25): " << (abs(interpolate(0, 10, 0.25) - 2.5) < 0.001 ? "PASS" : "FAIL") << endl;

    // Test Case 5: Three-quarters interpolation
    // Calculation: 0 + (100 - 0) * 0.75 = 0 + 75 = 75.0
    // Expected output: 75.0
    cout << "Test 5 (0 to 100, factor=0.75): " << (abs(interpolate(0, 100, 0.75) - 75.0) < 0.001 ? "PASS" : "FAIL") << endl;

    // Test Case 6: Negative to positive range
    // Calculation: -10 + (10 - (-10)) * 0.5 = -10 + 20 * 0.5 = -10 + 10 = 0.0
    // Expected output: 0.0
    cout << "Test 6 (-10 to 10, factor=0.5): " << (abs(interpolate(-10, 10, 0.5) - 0.0) < 0.001 ? "PASS" : "FAIL") << endl;

    // Test Case 7: Floating point values
    // Calculation: 2.5 + (7.5 - 2.5) * 0.6 = 2.5 + 5.0 * 0.6 = 2.5 + 3.0 = 5.5
    // Expected output: 5.5
    cout << "Test 7 (2.5 to 7.5, factor=0.6): " << (abs(interpolate(2.5, 7.5, 0.6) - 5.5) < 0.001 ? "PASS" : "FAIL") << endl;

    // Test Case 8: Factor clamping (factor > 1 should be clamped to 1)
    // Calculation: 0 + (10 - 0) * 1.0 (clamped from 1.5) = 10.0
    // Expected output: 10.0
    cout << "Test 8 (0 to 10, factor=1.5->clamped): " << (abs(interpolate(0, 10, 1.5) - 10.0) < 0.001 ? "PASS" : "FAIL") << endl;
}

// ============================================================================
// MAIN FUNCTION
// ============================================================================

int main()
{
    cout << "\n============================================" << endl;
    cout << "  Function Templates Practice Problems" << endl;
    cout << "============================================" << endl;
    cout << "\nTopics: Multiple Parameters, Auto Return Type," << endl;
    cout << "        Template Type Deduction, Default Arguments" << endl;
    cout << "\n============================================" << endl;

    int choice;
    cout << "\nChoose a problem to test:" << endl;
    cout << "1. Problem 1 (Easy) - Generic Calculator" << endl;
    cout << "2. Problem 2 (Easy) - Range Value Checker" << endl;
    cout << "3. Problem 3 (Medium) - Array Statistics" << endl;
    cout << "4. Problem 4 (Hard) - Generic Interpolation" << endl;
    cout << "5. Test All Problems" << endl;
    cout << "\nEnter your choice (1-5): ";
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
        cout << "\n============================================" << endl;
        cout << "  All tests completed!" << endl;
        cout << "============================================" << endl;
        break;
    default:
        cout << "\nInvalid choice! Please select 1-5." << endl;
    }

    cout << endl;
    return 0;
}