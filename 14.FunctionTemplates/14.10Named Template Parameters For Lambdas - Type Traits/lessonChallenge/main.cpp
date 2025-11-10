#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <cmath>

using namespace std;

// ============================================================================
// Problem 1: Easy 1 - Fixed-Size Array Sum
// ============================================================================
// Description:
// Create a template function that takes an array of integers with a
// compile-time known size N and returns the sum of all elements.
// Use Non Type Template Parameters to specify the array size.
//
// Input Format:
// - An array of integers with size N (compile-time constant)
//
// Output Format:
// - Integer representing the sum of all array elements
//
// Example 1:
// Input: array = {1, 2, 3, 4, 5}, N = 5
// Output: 15
// Explanation: 1 + 2 + 3 + 4 + 5 = 15
//
// Example 2:
// Input: array = {10, 20, 30}, N = 3
// Output: 60
// Explanation: 10 + 20 + 30 = 60
//
// Constraints:
// - 1 <= N <= 1000
// - -10000 <= array[i] <= 10000
//
// Template signature: template<size_t N>
// ============================================================================

template <size_t N>
int arraySum(const int (&arr)[N])
{
    // TODO: Implement your solution here using Non Type Template Parameters
    // Hint: Iterate through the array and accumulate the sum
    int sum{};
    for (size_t i = 0; i < size(arr); i++)
    {
        sum += arr[i];
    }

    return sum;
}

// ============================================================================
// Problem 2: Easy 2 - Matrix Dimensions Validator
// ============================================================================
// Description:
// Create a template function that validates if a 2D array has the expected
// dimensions ROWS x COLS using Non Type Template Parameters.
// The function should print the dimensions and return true if valid.
//
// Input Format:
// - A 2D array of integers with dimensions ROWS x COLS
//
// Output Format:
// - Boolean: true (dimensions match template parameters)
// - Side effect: Print "Matrix is ROWSxCOLS"
//
// Example 1:
// Input: array[3][4], Template<3, 4>
// Output: Prints "Matrix is 3x4", returns true
//
// Example 2:
// Input: array[2][2], Template<2, 2>
// Output: Prints "Matrix is 2x2", returns true
//
// Constraints:
// - 1 <= ROWS, COLS <= 100
// - Function always returns true (dimensions are compile-time verified)
//
// Template signature: template<size_t ROWS, size_t COLS>
// ============================================================================

template <size_t ROWS, size_t COLS>
bool validateMatrixDimensions(const int (&matrix)[ROWS][COLS])
{
    // TODO: Implement your solution here using Non Type Template Parameters
    // Hint: Print the dimensions using ROWS and COLS, then return true
    if (size(matrix) == ROWS && size(matrix[0]) == COLS)
        return true;
    return false;
}

// ============================================================================
// Problem 3: Medium - Power Calculator with Compile-Time Exponent
// ============================================================================
// Description:
// Create a template function that calculates base^exponent where the exponent
// is a compile-time constant (Non Type Template Parameter).
// The base is provided at runtime.
//
// Input Format:
// - int base (runtime parameter)
// - int EXPONENT (compile-time template parameter)
//
// Output Format:
// - long long representing base^EXPONENT
//
// Example 1:
// Input: base = 2, EXPONENT = 3
// Output: 8
// Explanation: 2^3 = 2 * 2 * 2 = 8
//
// Example 2:
// Input: base = 5, EXPONENT = 0
// Output: 1
// Explanation: Any number to power 0 is 1
//
// Example 3:
// Input: base = -3, EXPONENT = 3
// Output: -27
// Explanation: (-3)^3 = -3 * -3 * -3 = -27
//
// Constraints:
// - -100 <= base <= 100
// - 0 <= EXPONENT <= 10
// - Handle negative bases correctly
// - 0^0 should return 1
//
// Template signature: template<int EXPONENT>
// ============================================================================

template <int EXPONENT>
long long power(int base)
{
    // TODO: Implement your solution here using Non Type Template Parameters
    // Hint: Use a loop to multiply base by itself EXPONENT times
    // Special case: handle EXPONENT == 0
    if (EXPONENT == 0)
        return 1;
    long long result = base;
    for (size_t i = 1; i < EXPONENT; i++)
    {
        result = result * base;
    }

    return result;
}

// ============================================================================
// Problem 4: Hard - Fixed-Size Circular Buffer
// ============================================================================
// Description:
// Create a template class for a circular buffer with a compile-time fixed
// capacity using Non Type Template Parameters. Implement add() and getAverage()
// methods. When the buffer is full, new elements overwrite the oldest ones.
//
// Input Format:
// - CAPACITY: compile-time template parameter for buffer size
// - Multiple add(value) operations
// - getAverage() calls to compute average of current elements
//
// Output Format:
// - getAverage() returns double: average of all elements in buffer
//
// Example 1:
// CircularBuffer<3> buffer;
// buffer.add(10); buffer.add(20); buffer.add(30);
// buffer.getAverage() -> 20.0
// Explanation: (10 + 20 + 30) / 3 = 20.0
//
// Example 2:
// CircularBuffer<3> buffer;
// buffer.add(10); buffer.add(20); buffer.add(30); buffer.add(40);
// buffer.getAverage() -> 30.0
// Explanation: Buffer = [40, 20, 30], (40 + 20 + 30) / 3 = 30.0
//
// Constraints:
// - 1 <= CAPACITY <= 1000
// - -10000 <= value <= 10000
// - getAverage() called only when buffer has at least 1 element
//
// Template signature: template<size_t CAPACITY>
// ============================================================================

template <size_t CAPACITY>
class CircularBuffer
{
private:
    int buffer[CAPACITY];
    size_t currentSize;
    size_t nextIndex;

public:
    CircularBuffer() : currentSize(0), nextIndex(0) {}

    void add(int value)
    {
        // TODO: Implement add method
        // Hint: Use nextIndex to track where to insert next element
        // Update currentSize (max is CAPACITY) and nextIndex (wrap around)
    }

    double getAverage()
    {
        // TODO: Implement getAverage method
        // Hint: Sum all valid elements (first currentSize elements)
        // Divide by currentSize to get average
        return 0;
    }
};

// ============================================================================
// TEST CASES - ALL MANUALLY VERIFIED
// ============================================================================

void testProblem1()
{
    cout << "\n=== Testing Problem 1: Fixed-Size Array Sum ===" << endl;

    // Test Case 1: Basic positive numbers
    // Calculation: 1 + 2 + 3 + 4 + 5 = 15
    {
        int arr1[] = {1, 2, 3, 4, 5};
        int result = arraySum(arr1);
        cout << "Test 1 - Basic positive: " << (result == 15 ? "PASS" : "FAIL")
             << " (Expected: 15, Got: " << result << ")" << endl;
    }

    // Test Case 2: Array with single element
    // Calculation: 42 = 42
    {
        int arr2[] = {42};
        int result = arraySum(arr2);
        cout << "Test 2 - Single element: " << (result == 42 ? "PASS" : "FAIL")
             << " (Expected: 42, Got: " << result << ")" << endl;
    }

    // Test Case 3: Array with negative numbers
    // Calculation: -5 + (-10) + (-15) = -30
    {
        int arr3[] = {-5, -10, -15};
        int result = arraySum(arr3);
        cout << "Test 3 - Negative numbers: " << (result == -30 ? "PASS" : "FAIL")
             << " (Expected: -30, Got: " << result << ")" << endl;
    }

    // Test Case 4: Mixed positive and negative
    // Calculation: 10 + (-5) + 20 + (-10) + 5 = 20
    {
        int arr4[] = {10, -5, 20, -10, 5};
        int result = arraySum(arr4);
        cout << "Test 4 - Mixed signs: " << (result == 20 ? "PASS" : "FAIL")
             << " (Expected: 20, Got: " << result << ")" << endl;
    }

    // Test Case 5: Array with zeros
    // Calculation: 0 + 0 + 0 + 0 = 0
    {
        int arr5[] = {0, 0, 0, 0};
        int result = arraySum(arr5);
        cout << "Test 5 - All zeros: " << (result == 0 ? "PASS" : "FAIL")
             << " (Expected: 0, Got: " << result << ")" << endl;
    }

    // Test Case 6: Large positive numbers
    // Calculation: 100 + 200 + 300 = 600
    {
        int arr6[] = {100, 200, 300};
        int result = arraySum(arr6);
        cout << "Test 6 - Large numbers: " << (result == 600 ? "PASS" : "FAIL")
             << " (Expected: 600, Got: " << result << ")" << endl;
    }

    // Test Case 7: Two elements
    // Calculation: 50 + 50 = 100
    {
        int arr7[] = {50, 50};
        int result = arraySum(arr7);
        cout << "Test 7 - Two elements: " << (result == 100 ? "PASS" : "FAIL")
             << " (Expected: 100, Got: " << result << ")" << endl;
    }

    // Test Case 8: Larger array
    // Calculation: 1+2+3+4+5+6+7+8+9+10 = 55
    {
        int arr8[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int result = arraySum(arr8);
        cout << "Test 8 - Ten elements: " << (result == 55 ? "PASS" : "FAIL")
             << " (Expected: 55, Got: " << result << ")" << endl;
    }
}

void testProblem2()
{
    cout << "\n=== Testing Problem 2: Matrix Dimensions Validator ===" << endl;

    // Test Case 1: 3x4 matrix
    {
        int matrix1[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
        cout << "Test 1 - 3x4 matrix: ";
        bool result = validateMatrixDimensions(matrix1);
        cout << (result == true ? "PASS" : "FAIL") << endl;
    }

    // Test Case 2: 2x2 matrix
    {
        int matrix2[2][2] = {{1, 2}, {3, 4}};
        cout << "Test 2 - 2x2 matrix: ";
        bool result = validateMatrixDimensions(matrix2);
        cout << (result == true ? "PASS" : "FAIL") << endl;
    }

    // Test Case 3: 1x1 matrix (single element)
    {
        int matrix3[1][1] = {{42}};
        cout << "Test 3 - 1x1 matrix: ";
        bool result = validateMatrixDimensions(matrix3);
        cout << (result == true ? "PASS" : "FAIL") << endl;
    }

    // Test Case 4: 5x3 matrix
    {
        int matrix4[5][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15}};
        cout << "Test 4 - 5x3 matrix: ";
        bool result = validateMatrixDimensions(matrix4);
        cout << (result == true ? "PASS" : "FAIL") << endl;
    }

    // Test Case 5: 1x5 matrix (row vector)
    {
        int matrix5[1][5] = {{10, 20, 30, 40, 50}};
        cout << "Test 5 - 1x5 matrix: ";
        bool result = validateMatrixDimensions(matrix5);
        cout << (result == true ? "PASS" : "FAIL") << endl;
    }

    // Test Case 6: 5x1 matrix (column vector)
    {
        int matrix6[5][1] = {{1}, {2}, {3}, {4}, {5}};
        cout << "Test 6 - 5x1 matrix: ";
        bool result = validateMatrixDimensions(matrix6);
        cout << (result == true ? "PASS" : "FAIL") << endl;
    }

    // Test Case 7: 4x4 matrix (square)
    {
        int matrix7[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
        cout << "Test 7 - 4x4 matrix: ";
        bool result = validateMatrixDimensions(matrix7);
        cout << (result == true ? "PASS" : "FAIL") << endl;
    }

    // Test Case 8: 6x2 matrix
    {
        int matrix8[6][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}, {11, 12}};
        cout << "Test 8 - 6x2 matrix: ";
        bool result = validateMatrixDimensions(matrix8);
        cout << (result == true ? "PASS" : "FAIL") << endl;
    }
}

void testProblem3()
{
    cout << "\n=== Testing Problem 3: Power Calculator ===" << endl;

    // Test Case 1: 2^3
    // Calculation: 2 * 2 * 2 = 8
    {
        long long result = power<3>(2);
        cout << "Test 1 - 2^3: " << (result == 8 ? "PASS" : "FAIL")
             << " (Expected: 8, Got: " << result << ")" << endl;
    }

    // Test Case 2: 5^0 (any number to power 0)
    // Calculation: 1
    {
        long long result = power<0>(5);
        cout << "Test 2 - 5^0: " << (result == 1 ? "PASS" : "FAIL")
             << " (Expected: 1, Got: " << result << ")" << endl;
    }

    // Test Case 3: 3^1 (any number to power 1)
    // Calculation: 3
    {
        long long result = power<1>(3);
        cout << "Test 3 - 3^1: " << (result == 3 ? "PASS" : "FAIL")
             << " (Expected: 3, Got: " << result << ")" << endl;
    }

    // Test Case 4: -3^3 (negative base, odd exponent)
    // Calculation: (-3) * (-3) * (-3) = 9 * (-3) = -27
    {
        long long result = power<3>(-3);
        cout << "Test 4 - (-3)^3: " << (result == -27 ? "PASS" : "FAIL")
             << " (Expected: -27, Got: " << result << ")" << endl;
    }

    // Test Case 5: -2^4 (negative base, even exponent)
    // Calculation: (-2) * (-2) * (-2) * (-2) = 4 * 4 = 16
    {
        long long result = power<4>(-2);
        cout << "Test 5 - (-2)^4: " << (result == 16 ? "PASS" : "FAIL")
             << " (Expected: 16, Got: " << result << ")" << endl;
    }

    // Test Case 6: 10^2
    // Calculation: 10 * 10 = 100
    {
        long long result = power<2>(10);
        cout << "Test 6 - 10^2: " << (result == 100 ? "PASS" : "FAIL")
             << " (Expected: 100, Got: " << result << ")" << endl;
    }

    // Test Case 7: 1^5 (one to any power)
    // Calculation: 1 * 1 * 1 * 1 * 1 = 1
    {
        long long result = power<5>(1);
        cout << "Test 7 - 1^5: " << (result == 1 ? "PASS" : "FAIL")
             << " (Expected: 1, Got: " << result << ")" << endl;
    }

    // Test Case 8: 0^5 (zero to positive power)
    // Calculation: 0 * 0 * 0 * 0 * 0 = 0
    {
        long long result = power<5>(0);
        cout << "Test 8 - 0^5: " << (result == 0 ? "PASS" : "FAIL")
             << " (Expected: 0, Got: " << result << ")" << endl;
    }

    // Test Case 9: 0^0 (special case)
    // Mathematical convention: 0^0 = 1
    {
        long long result = power<0>(0);
        cout << "Test 9 - 0^0: " << (result == 1 ? "PASS" : "FAIL")
             << " (Expected: 1, Got: " << result << ")" << endl;
    }

    // Test Case 10: 7^2
    // Calculation: 7 * 7 = 49
    {
        long long result = power<2>(7);
        cout << "Test 10 - 7^2: " << (result == 49 ? "PASS" : "FAIL")
             << " (Expected: 49, Got: " << result << ")" << endl;
    }
}

void testProblem4()
{
    cout << "\n=== Testing Problem 4: Circular Buffer ===" << endl;

    // Test Case 1: Basic usage - not full
    // Buffer capacity: 3, Add: 10, 20, 30
    // Calculation: (10 + 20 + 30) / 3 = 60 / 3 = 20.0
    {
        CircularBuffer<3> buffer;
        buffer.add(10);
        buffer.add(20);
        buffer.add(30);
        double result = buffer.getAverage();
        cout << "Test 1 - Basic usage: " << (abs(result - 20.0) < 0.001 ? "PASS" : "FAIL")
             << " (Expected: 20.0, Got: " << result << ")" << endl;
    }

    // Test Case 2: Overflow - circular behavior
    // Buffer capacity: 3, Add: 10, 20, 30, 40
    // Buffer becomes: [40, 20, 30]
    // Calculation: (40 + 20 + 30) / 3 = 90 / 3 = 30.0
    {
        CircularBuffer<3> buffer;
        buffer.add(10);
        buffer.add(20);
        buffer.add(30);
        buffer.add(40);
        double result = buffer.getAverage();
        cout << "Test 2 - Circular overflow: " << (abs(result - 30.0) < 0.001 ? "PASS" : "FAIL")
             << " (Expected: 30.0, Got: " << result << ")" << endl;
    }

    // Test Case 3: Single element
    // Buffer capacity: 5, Add: 100
    // Calculation: 100 / 1 = 100.0
    {
        CircularBuffer<5> buffer;
        buffer.add(100);
        double result = buffer.getAverage();
        cout << "Test 3 - Single element: " << (abs(result - 100.0) < 0.001 ? "PASS" : "FAIL")
             << " (Expected: 100.0, Got: " << result << ")" << endl;
    }

    // Test Case 4: Capacity 1 - constant override
    // Buffer capacity: 1, Add: 5, 10, 15
    // Buffer becomes: [15]
    // Calculation: 15 / 1 = 15.0
    {
        CircularBuffer<1> buffer;
        buffer.add(5);
        buffer.add(10);
        buffer.add(15);
        double result = buffer.getAverage();
        cout << "Test 4 - Capacity 1: " << (abs(result - 15.0) < 0.001 ? "PASS" : "FAIL")
             << " (Expected: 15.0, Got: " << result << ")" << endl;
    }

    // Test Case 5: Negative numbers
    // Buffer capacity: 4, Add: -10, -20, -30, -40
    // Calculation: (-10 + -20 + -30 + -40) / 4 = -100 / 4 = -25.0
    {
        CircularBuffer<4> buffer;
        buffer.add(-10);
        buffer.add(-20);
        buffer.add(-30);
        buffer.add(-40);
        double result = buffer.getAverage();
        cout << "Test 5 - Negative numbers: " << (abs(result - (-25.0)) < 0.001 ? "PASS" : "FAIL")
             << " (Expected: -25.0, Got: " << result << ")" << endl;
    }

    // Test Case 6: Multiple overwrites
    // Buffer capacity: 2, Add: 1, 2, 3, 4, 5
    // Buffer becomes: [5, 4]
    // Calculation: (5 + 4) / 2 = 9 / 2 = 4.5
    {
        CircularBuffer<2> buffer;
        buffer.add(1);
        buffer.add(2);
        buffer.add(3);
        buffer.add(4);
        buffer.add(5);
        double result = buffer.getAverage();
        cout << "Test 6 - Multiple overwrites: " << (abs(result - 4.5) < 0.001 ? "PASS" : "FAIL")
             << " (Expected: 4.5, Got: " << result << ")" << endl;
    }

    // Test Case 7: Mixed positive and negative
    // Buffer capacity: 4, Add: 10, -5, 20, -10
    // Calculation: (10 + -5 + 20 + -10) / 4 = 15 / 4 = 3.75
    {
        CircularBuffer<4> buffer;
        buffer.add(10);
        buffer.add(-5);
        buffer.add(20);
        buffer.add(-10);
        double result = buffer.getAverage();
        cout << "Test 7 - Mixed signs: " << (abs(result - 3.75) < 0.001 ? "PASS" : "FAIL")
             << " (Expected: 3.75, Got: " << result << ")" << endl;
    }

    // Test Case 8: Partial fill then overflow
    // Buffer capacity: 5, Add: 2, 4, 6, 8, 10, 12
    // Buffer becomes: [12, 4, 6, 8, 10]
    // Calculation: (12 + 4 + 6 + 8 + 10) / 5 = 40 / 5 = 8.0
    {
        CircularBuffer<5> buffer;
        buffer.add(2);
        buffer.add(4);
        buffer.add(6);
        buffer.add(8);
        buffer.add(10);
        buffer.add(12);
        double result = buffer.getAverage();
        cout << "Test 8 - Partial then overflow: " << (abs(result - 8.0) < 0.001 ? "PASS" : "FAIL")
             << " (Expected: 8.0, Got: " << result << ")" << endl;
    }
}

int main()
{
    int choice;
    cout << "=== Non Type Template Parameters - Practice Problems ===" << endl;
    cout << "Choose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy) - Fixed-Size Array Sum" << endl;
    cout << "2. Problem 2 (Easy) - Matrix Dimensions Validator" << endl;
    cout << "3. Problem 3 (Medium) - Power Calculator" << endl;
    cout << "4. Problem 4 (Hard) - Circular Buffer" << endl;
    cout << "5. Test All Problems" << endl;
    cout << "Enter choice: ";
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