#include <iostream>
#include <vector>
#include <string>
#include <type_traits>
#include <cmath>

using namespace std;

// ============================================================================
// Problem 1: Easy 1 - Type-Safe Printer
// ============================================================================
// Description:
// Create a generic function that prints values differently based on their type.
// - If the type is an integer type (int, long, short, etc.), print "Integer: [value]"
// - If the type is a floating point type (float, double), print "Float: [value]"
// - Otherwise, print "Other: [value]"
//
// Input Format: A single value of any type
// Output Format: A string indicating the type category and the value
//
// Example 1:
// Input: 42
// Output: "Integer: 42"
//
// Example 2:
// Input: 3.14
// Output: "Float: 3.14"
//
// Example 3:
// Input: 'A'
// Output: "Other: A"
//
// Constraints:
// - Use constexpr if to check type at compile time
// - Use std::is_integral and std::is_floating_point type traits

template <typename T>
void problem1Solution(T value)
{
     // TODO: Implement your solution here using Constexpr If
     // Hint: Use if constexpr with std::is_integral_v<T> and std::is_floating_point_v<T>
     if constexpr (is_integral_v<T> && !is_same_v<T, bool> &&
                   !is_same_v<T, char> &&
                   !is_same_v<T, signed char> &&
                   !is_same_v<T, unsigned char>)
          cout << "Integer: " << value << endl;
     else if constexpr (is_floating_point_v<T>)
          cout << "Float: " << value << endl;
     else
          cout << "Other: " << value << endl;
}

// ============================================================================
// Problem 2: Easy 2 - Smart Container Size Calculator
// ============================================================================
// Description:
// Create a generic function that returns the size of different containers.
// - If it's an array, return the number of elements
// - If it's a container with .size() method (vector, string), return .size()
// - If it's a pointer, return -1 (size unknown)
// - Otherwise, return 1 (single value)
//
// Input Format: Any type of variable
// Output Format: Integer representing the size
//
// Example 1:
// Input: int arr[5] = {1,2,3,4,5}
// Output: 5
//
// Example 2:
// Input: vector<int> v = {1,2,3}
// Output: 3
//
// Example 3:
// Input: int* ptr
// Output: -1
//
// Constraints:
// - Use constexpr if with std::is_array, std::is_pointer
// - For containers, check if .size() exists using SFINAE or requires clause simulation

template <typename T>
concept checkVector = requires(T &t) {
     t.size();
};
template <typename T>
int problem2Solution(const T &value)
{
     // TODO: Implement your solution here using Constexpr If
     // Hint: Use if constexpr with std::is_array_v<T>, std::is_pointer_v<T>
     // For arrays: use std::extent_v<T> to get size
     if constexpr (is_array_v<T>)
     {
          if constexpr (checkVector<T>)
          {
               return extent_v<decltype(value)>;
          }
          else
          {
               return size(value);
          }
     }
     else if constexpr (is_pointer_v<T>)
          return -1;
     return 1;
}

// ============================================================================
// Problem 3: Medium - Generic Math Operation Optimizer
// ============================================================================
// Description:
// Create a function that performs addition differently based on type:
// - For integer types: Perform regular addition and check for overflow
//   If a + b would overflow, return the maximum value for that type
// - For floating point types: Perform regular addition (no overflow check needed)
// - For pointer types: Return nullptr (invalid operation)
//
// Input Format: Two values of the same type
// Output Format: Result of the addition with type-specific handling
//
// Example 1:
// Input: int a = 2147483647, b = 1 (INT_MAX + 1)
// Output: 2147483647 (capped at INT_MAX)
//
// Example 2:
// Input: double a = 1.5, b = 2.3
// Output: 3.8
//
// Example 3:
// Input: int a = 100, b = 200
// Output: 300
//
// Constraints:
// - Use constexpr if to handle different type categories
// - Use numeric_limits for overflow detection
// - Handle signed and unsigned integers differently

template <typename T>
T problem3Solution(T a, T b)
{
     // TODO: Implement your solution here using Constexpr If
     // Hint: Use if constexpr with std::is_integral_v, std::is_floating_point_v, std::is_pointer_v
     // For overflow check: if a > numeric_limits<T>::max() - b, then overflow occurs
     if constexpr (is_integral_v<T>)
     {
          if (a < 0)
               return (a > (numeric_limits<T>::min() + b)) ? a : a + b;
          else
               return (a > (numeric_limits<T>::max() - b)) ? a : a + b;
     }
     else if constexpr (is_floating_point_v<T>)
          return a + b;
     else if constexpr (is_pointer_v<T>)
          return *a + *b;

     return T{};
}

// ============================================================================
// Problem 4: Hard - Generic Container Accumulator
// ============================================================================
// Description:
// Create a function that sums elements from different container types:
// - For C-style arrays: Sum all elements
// - For std::vector: Sum all elements
// - For std::string: Return the sum of ASCII values of all characters
// - For single numeric values: Return the value itself
// - For pointer types: Return 0 (cannot sum)
//
// The function should work with different numeric types (int, double, etc.)
//
// Input Format: Any container or value
// Output Format: Sum as appropriate type
//
// Example 1:
// Input: int arr[] = {1, 2, 3, 4, 5}
// Output: 15
//
// Example 2:
// Input: vector<double> v = {1.5, 2.5, 3.0}
// Output: 7.0
//
// Example 3:
// Input: string s = "ABC"
// Output: 198 (65 + 66 + 67)
//
// Example 4:
// Input: int x = 42
// Output: 42
//
// Constraints:
// - Use constexpr if to detect container type at compile time
// - Handle arrays, vectors, strings, and single values
// - Return type should match input type (except string returns int)

template <typename T>
auto problem4Solution(const T &value)
{
     // TODO: Implement your solution here using Constexpr If
     // Hint: Use if constexpr with std::is_array_v, std::is_same_v
     // Check for string using std::is_same_v<T, std::string>
     // For arrays: iterate using std::extent_v<T> for size
     // For vectors: use .size() and iterate
     // For string: sum static_cast<int>(char)
     if constexpr (std::is_array_v<T>)
     {
          return 0; // Replace with your implementation
     }
     else
     {
          return 0; // Replace with your implementation
     }
}

// ============================================================================
// TEST FUNCTIONS
// ============================================================================

void testProblem1()
{
     cout << "\n========================================" << endl;
     cout << "Testing Problem 1: Type-Safe Printer" << endl;
     cout << "========================================" << endl;

     // Test Case 1: Integer type (int)
     // Expected: Should print "Integer: 42"
     cout << "Test 1 (int): ";
     problem1Solution(42);

     // Test Case 2: Integer type (long)
     // Expected: Should print "Integer: 1000000"
     cout << "Test 2 (long): ";
     problem1Solution(1000000L);

     // Test Case 3: Floating point (double)
     // Expected: Should print "Float: 3.14"
     cout << "Test 3 (double): ";
     problem1Solution(3.14);

     // Test Case 4: Floating point (float)
     // Expected: Should print "Float: 2.5"
     cout << "Test 4 (float): ";
     problem1Solution(2.5f);

     // Test Case 5: Character type
     // Expected: Should print "Other: A"
     cout << "Test 5 (char): ";
     problem1Solution('A');

     // Test Case 6: Boolean type
     // Expected: Should print "Other: 1" (true is printed as 1)
     cout << "Test 6 (bool): ";
     problem1Solution(true);

     // Test Case 7: Negative integer
     // Expected: Should print "Integer: -50"
     cout << "Test 7 (negative int): ";
     problem1Solution(-50);

     // Test Case 8: Zero
     // Expected: Should print "Integer: 0"
     cout << "Test 8 (zero): ";
     problem1Solution(0);
}

void testProblem2()
{
     cout << "\n========================================" << endl;
     cout << "Testing Problem 2: Smart Container Size Calculator" << endl;
     cout << "========================================" << endl;

     // Test Case 1: C-style array of 5 integers
     // Size = 5 elements
     // Expected: 5
     int arr1[5] = {1, 2, 3, 4, 5};
     cout << "Test 1 (int[5]): " << (problem2Solution(arr1) == 5 ? "PASS" : "FAIL")
          << " (Expected: 5, Got: " << problem2Solution(arr1) << ")" << endl;

     // Test Case 2: C-style array of 10 integers
     // Size = 10 elements
     // Expected: 10
     int arr2[10] = {0};
     cout << "Test 2 (int[10]): " << (problem2Solution(arr2) == 10 ? "PASS" : "FAIL")
          << " (Expected: 10, Got: " << problem2Solution(arr2) << ")" << endl;

     // Test Case 3: Single integer (not array)
     // Size = 1 (single value)
     // Expected: 1
     int single = 42;
     cout << "Test 3 (int): " << (problem2Solution(single) == 1 ? "PASS" : "FAIL")
          << " (Expected: 1, Got: " << problem2Solution(single) << ")" << endl;

     // Test Case 4: Pointer type
     // Size = -1 (unknown size for pointers)
     // Expected: -1
     int *ptr = arr1;
     cout << "Test 4 (int*): " << (problem2Solution(ptr) == -1 ? "PASS" : "FAIL")
          << " (Expected: -1, Got: " << problem2Solution(ptr) << ")" << endl;

     // Test Case 5: Array of 1 element
     // Size = 1
     // Expected: 1
     vector<double> arr3 = {3.14};
     cout << "Test 5 (double[1]): " << (problem2Solution(arr3) == 1 ? "PASS" : "FAIL")
          << " (Expected: 1, Got: " << problem2Solution(arr3) << ")" << endl;

     // Test Case 6: Large array
     // Size = 100
     // Expected: 100
     char arr4[100] = {0};
     cout << "Test 6 (char[100]): " << (problem2Solution(arr4) == 100 ? "PASS" : "FAIL")
          << " (Expected: 100, Got: " << problem2Solution(arr4) << ")" << endl;

     // Test Case 7: Double value (single)
     // Size = 1
     // Expected: 1
     double d = 2.718;
     cout << "Test 7 (double): " << (problem2Solution(d) == 1 ? "PASS" : "FAIL")
          << " (Expected: 1, Got: " << problem2Solution(d) << ")" << endl;

     // Test Case 8: Array of 3 floats
     // Size = 3
     // Expected: 3
     float arr5[3] = {1.1f, 2.2f, 3.3f};
     cout << "Test 8 (float[3]): " << (problem2Solution(arr5) == 3 ? "PASS" : "FAIL")
          << " (Expected: 3, Got: " << problem2Solution(arr5) << ")" << endl;
}

void testProblem3()
{
     cout << "\n========================================" << endl;
     cout << "Testing Problem 3: Generic Math Operation Optimizer" << endl;
     cout << "========================================" << endl;

     // Test Case 1: Normal integer addition
     // 100 + 200 = 300
     // Expected: 300
     cout << "Test 1 (100 + 200): " << (problem3Solution(100, 200) == 300 ? "PASS" : "FAIL")
          << " (Expected: 300, Got: " << problem3Solution(100, 200) << ")" << endl;

     // Test Case 2: Integer overflow case
     // INT_MAX = 2147483647, adding 1 should cap at INT_MAX
     // Expected: 2147483647
     int max_int = 2147483647;
     cout << "Test 2 (INT_MAX + 1): " << (problem3Solution(max_int, 1) == 2147483647 ? "PASS" : "FAIL")
          << " (Expected: 2147483647, Got: " << problem3Solution(max_int, 1) << ")" << endl;

     // Test Case 3: Double addition
     // 1.5 + 2.3 = 3.8
     // Expected: 3.8
     double result3 = problem3Solution(1.5, 2.3);
     cout << "Test 3 (1.5 + 2.3): " << (abs(result3 - 3.8) < 0.001 ? "PASS" : "FAIL")
          << " (Expected: 3.8, Got: " << result3 << ")" << endl;

     // Test Case 4: Negative integer addition
     // -50 + -30 = -80
     // Expected: -80
     cout << "Test 4 (-50 + -30): " << (problem3Solution(-50, -30) == -80 ? "PASS" : "FAIL")
          << " (Expected: -80, Got: " << problem3Solution(-50, -30) << ")" << endl;

     // Test Case 5: Zero addition
     // 0 + 0 = 0
     // Expected: 0
     cout << "Test 5 (0 + 0): " << (problem3Solution(0, 0) == 0 ? "PASS" : "FAIL")
          << " (Expected: 0, Got: " << problem3Solution(0, 0) << ")" << endl;

     // Test Case 6: Float addition
     // 2.5 + 3.7 = 6.2
     // Expected: 6.2
     float result6 = problem3Solution(2.5f, 3.7f);
     cout << "Test 6 (2.5f + 3.7f): " << (abs(result6 - 6.2f) < 0.001 ? "PASS" : "FAIL")
          << " (Expected: 6.2, Got: " << result6 << ")" << endl;

     // Test Case 7: Near overflow but not quite
     // 2147483646 + 1 = 2147483647 (still valid)
     // Expected: 2147483647
     cout << "Test 7 (INT_MAX-1 + 1): " << (problem3Solution(2147483646, 1) == 2147483647 ? "PASS" : "FAIL")
          << " (Expected: 2147483647, Got: " << problem3Solution(2147483646, 1) << ")" << endl;

     // Test Case 8: Large overflow
     // INT_MAX + 100 should cap at INT_MAX
     // Expected: 2147483647
     cout << "Test 8 (INT_MAX + 100): " << (problem3Solution(max_int, 100) == 2147483647 ? "PASS" : "FAIL")
          << " (Expected: 2147483647, Got: " << problem3Solution(max_int, 100) << ")" << endl;
}

void testProblem4()
{
     cout << "\n========================================" << endl;
     cout << "Testing Problem 4: Generic Container Accumulator" << endl;
     cout << "========================================" << endl;

     // Test Case 1: C-style array of integers
     // Sum: 1 + 2 + 3 + 4 + 5 = 15
     // Expected: 15
     int arr1[] = {1, 2, 3, 4, 5};
     cout << "Test 1 (int[] sum): " << (problem4Solution(arr1) == 15 ? "PASS" : "FAIL")
          << " (Expected: 15, Got: " << problem4Solution(arr1) << ")" << endl;

     // Test Case 2: C-style array with negative numbers
     // Sum: 10 + (-5) + 3 + (-2) = 6
     // Expected: 6
     int arr2[] = {10, -5, 3, -2};
     cout << "Test 2 (int[] with negatives): " << (problem4Solution(arr2) == 6 ? "PASS" : "FAIL")
          << " (Expected: 6, Got: " << problem4Solution(arr2) << ")" << endl;

     // Test Case 3: Array of doubles
     // Sum: 1.5 + 2.5 + 3.0 = 7.0
     // Expected: 7.0
     double arr3[] = {1.5, 2.5, 3.0};
     double result3 = problem4Solution(arr3);
     cout << "Test 3 (double[] sum): " << (abs(result3 - 7.0) < 0.001 ? "PASS" : "FAIL")
          << " (Expected: 7.0, Got: " << result3 << ")" << endl;

     // Test Case 4: Single integer
     // Value: 42
     // Expected: 42
     int single = 42;
     cout << "Test 4 (single int): " << (problem4Solution(single) == 42 ? "PASS" : "FAIL")
          << " (Expected: 42, Got: " << problem4Solution(single) << ")" << endl;

     // Test Case 5: Single double
     // Value: 3.14159
     // Expected: 3.14159
     double single_d = 3.14159;
     double result5 = problem4Solution(single_d);
     cout << "Test 5 (single double): " << (abs(result5 - 3.14159) < 0.0001 ? "PASS" : "FAIL")
          << " (Expected: 3.14159, Got: " << result5 << ")" << endl;

     // Test Case 6: Array with zeros
     // Sum: 0 + 0 + 0 = 0
     // Expected: 0
     int arr6[] = {0, 0, 0};
     cout << "Test 6 (zeros): " << (problem4Solution(arr6) == 0 ? "PASS" : "FAIL")
          << " (Expected: 0, Got: " << problem4Solution(arr6) << ")" << endl;

     // Test Case 7: Single element array
     // Sum: 99
     // Expected: 99
     int arr7[] = {99};
     cout << "Test 7 (single element array): " << (problem4Solution(arr7) == 99 ? "PASS" : "FAIL")
          << " (Expected: 99, Got: " << problem4Solution(arr7) << ")" << endl;

     // Test Case 8: Larger array
     // Sum: 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 = 55
     // Expected: 55
     int arr8[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
     cout << "Test 8 (1-10 sum): " << (problem4Solution(arr8) == 55 ? "PASS" : "FAIL")
          << " (Expected: 55, Got: " << problem4Solution(arr8) << ")" << endl;
}

int main()
{
     int choice;
     cout << "========================================" << endl;
     cout << "   Constexpr If Practice Problems" << endl;
     cout << "========================================" << endl;
     cout << "Choose a problem to test (1-4) or 5 to test all:" << endl;
     cout << "1. Problem 1 (Easy): Type-Safe Printer" << endl;
     cout << "2. Problem 2 (Easy): Smart Container Size Calculator" << endl;
     cout << "3. Problem 3 (Medium): Generic Math Operation Optimizer" << endl;
     cout << "4. Problem 4 (Hard): Generic Container Accumulator" << endl;
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