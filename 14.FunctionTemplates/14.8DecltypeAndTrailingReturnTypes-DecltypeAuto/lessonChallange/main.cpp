#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

// ============================================================================
// Problem 1: Easy 1 - Type-Safe Addition
// ============================================================================
// Description:
// Create a function template that adds two values and returns the result.
// The return type should be automatically deduced based on the addition result.
// Use trailing return type with decltype to determine the return type.
//
// Input Format:
// Two parameters of potentially different types (int, double, float, etc.)
//
// Output Format:
// The sum with the correct deduced type
//
// Example 1:
// Input: add(5, 3)
// Output: 8 (type: int)
//
// Example 2:
// Input: add(5, 3.5)
// Output: 8.5 (type: double)
//
// Example 3:
// Input: add(2.5f, 3.5f)
// Output: 6.0 (type: float)
//
// Constraints:
// - Must use trailing return type with decltype
// - Should work with any numeric types
// ============================================================================
template <typename T, typename U>
auto add(T a, U b) -> decltype(a + b)
{
     // TODO: Implement your solution here using trailing return type with decltype
     // Hint: Simply return the addition of the two parameters
     // The return type is automatically deduced from a + b
     return a + b;
}

// ============================================================================
// Problem 2: Easy 2 - Array Element Access Return Type
// ============================================================================
// Description:
// Create a function template that takes a container (array/vector) and an index,
// then returns the element at that index. The return type should be automatically
// deduced using decltype(auto) to preserve references and cv-qualifiers.
//
// Input Format:
// - A container (vector, array, or C-style array)
// - An index (size_t)
//
// Output Format:
// Reference to the element at the given index
//
// Example 1:
// Input: vector<int> v = {10, 20, 30}; getElement(v, 1)
// Output: 20
//
// Example 2:
// Input: int arr[] = {5, 15, 25, 35}; getElement(arr, 3)
// Output: 35
//
// Constraints:
// - Must use decltype(auto) for return type
// - Should preserve reference type
// - Assume valid indices (no bounds checking required)
// ============================================================================
template <typename Container>
decltype(auto) getElement(Container &container, size_t index)
{
     // TODO: Implement your solution here using decltype(auto)
     // Hint: Return container[index] to preserve the reference type
     return container[index];
}

// ============================================================================
// Problem 3: Medium - Conditional Operation with Type Deduction
// ============================================================================
// Description:
// Create a function template that takes three parameters: a condition (bool),
// and two values of potentially different types. Return the first value if
// condition is true, otherwise return the second value. Use trailing return
// type with decltype to deduce the correct return type from the ternary operator.
//
// Input Format:
// - condition: bool
// - value1: any numeric type
// - value2: any numeric type
//
// Output Format:
// Either value1 or value2 based on condition, with proper type deduction
//
// Example 1:
// Input: conditionalReturn(true, 10, 20.5)
// Output: 10.0 (type promoted to double)
//
// Example 2:
// Input: conditionalReturn(false, 5, 7)
// Output: 7 (type: int)
//
// Example 3:
// Input: conditionalReturn(true, 3.14, 2)
// Output: 3.14 (type: double)
//
// Constraints:
// - Must use trailing return type with decltype
// - Should handle type promotion correctly
// ============================================================================
template <typename T, typename U>
auto conditionalReturn(bool condition, T value1, U value2) -> decltype(condition ? value1 : value2)
{
     // TODO: Implement your solution here using trailing return type
     // Hint: Use the ternary operator (condition ? value1 : value2)
     // The decltype will automatically deduce the common type
     return (condition ? value1 : value2);
}

// ============================================================================
// Problem 4: Hard - Complex Expression Type Deduction
// ============================================================================
// Description:
// Create a function template that performs a complex calculation:
// (a * b) + (c / d)
// Use trailing return type with decltype to automatically deduce the return type
// based on the complete expression. This tests understanding of how decltype
// handles complex expressions with multiple operations and type promotions.
//
// Input Format:
// Four parameters of potentially different numeric types
//
// Output Format:
// Result of the calculation with properly deduced type
//
// Example 1:
// Input: complexCalc(2, 3, 10, 2)
// Output: 11 (calculation: 2*3 + 10/2 = 6 + 5 = 11, type: int)
//
// Example 2:
// Input: complexCalc(2.5, 4.0, 15.0, 3.0)
// Output: 15.0 (calculation: 2.5*4.0 + 15.0/3.0 = 10.0 + 5.0 = 15.0, type: double)
//
// Example 3:
// Input: complexCalc(3, 5, 20.0, 4)
// Output: 20.0 (calculation: 3*5 + 20.0/4 = 15 + 5.0 = 20.0, type: double)
//
// Constraints:
// - Must use trailing return type with decltype
// - Should handle mixed type arithmetic correctly
// - Assume d is never zero
// ============================================================================
template <typename T1, typename T2, typename T3, typename T4>
auto complexCalc(T1 a, T2 b, T3 c, T4 d) -> decltype((a * b) + (c / d))
{
     // TODO: Implement your solution here using trailing return type
     // Hint: Return the expression (a * b) + (c / d)
     // The decltype handles all type promotions automatically
     return a;
}

// ============================================================================
// TEST FUNCTIONS
// ============================================================================

void testProblem1()
{
     cout << "\n========================================" << endl;
     cout << "Testing Problem 1: Type-Safe Addition" << endl;
     cout << "========================================" << endl;

     // Test Case 1: Two positive integers
     // Calculation: 5 + 3 = 8
     // Expected: 8
     auto result1 = add(5, 3);
     cout << "Test 1 (5 + 3): " << result1 << " | Expected: 8 | "
          << (result1 == 8 ? "PASS" : "FAIL") << endl;

     // Test Case 2: Integer and double (type promotion)
     // Calculation: 5 + 3.5 = 8.5
     // Expected: 8.5
     auto result2 = add(5, 3.5);
     cout << "Test 2 (5 + 3.5): " << result2 << " | Expected: 8.5 | "
          << (abs(result2 - 8.5) < 0.0001 ? "PASS" : "FAIL") << endl;

     // Test Case 3: Two floats
     // Calculation: 2.5 + 3.5 = 6.0
     // Expected: 6.0
     auto result3 = add(2.5f, 3.5f);
     cout << "Test 3 (2.5f + 3.5f): " << result3 << " | Expected: 6.0 | "
          << (abs(result3 - 6.0f) < 0.0001f ? "PASS" : "FAIL") << endl;

     // Test Case 4: Two doubles
     // Calculation: 10.25 + 5.75 = 16.0
     // Expected: 16.0
     auto result4 = add(10.25, 5.75);
     cout << "Test 4 (10.25 + 5.75): " << result4 << " | Expected: 16.0 | "
          << (abs(result4 - 16.0) < 0.0001 ? "PASS" : "FAIL") << endl;

     // Test Case 5: Negative numbers
     // Calculation: -5 + 3 = -2
     // Expected: -2
     auto result5 = add(-5, 3);
     cout << "Test 5 (-5 + 3): " << result5 << " | Expected: -2 | "
          << (result5 == -2 ? "PASS" : "FAIL") << endl;

     // Test Case 6: Zero values
     // Calculation: 0 + 0 = 0
     // Expected: 0
     auto result6 = add(0, 0);
     cout << "Test 6 (0 + 0): " << result6 << " | Expected: 0 | "
          << (result6 == 0 ? "PASS" : "FAIL") << endl;

     // Test Case 7: Double and int
     // Calculation: 7.8 + 2 = 9.8
     // Expected: 9.8
     auto result7 = add(7.8, 2);
     cout << "Test 7 (7.8 + 2): " << result7 << " | Expected: 9.8 | "
          << (abs(result7 - 9.8) < 0.0001 ? "PASS" : "FAIL") << endl;

     // Test Case 8: Large numbers
     // Calculation: 1000 + 2000 = 3000
     // Expected: 3000
     auto result8 = add(1000, 2000);
     cout << "Test 8 (1000 + 2000): " << result8 << " | Expected: 3000 | "
          << (result8 == 3000 ? "PASS" : "FAIL") << endl;
}

void testProblem2()
{
     cout << "\n========================================" << endl;
     cout << "Testing Problem 2: Array Element Access" << endl;
     cout << "========================================" << endl;

     // Test Case 1: Vector access - middle element
     // Array: {10, 20, 30, 40, 50}, Index: 2
     // Expected: 30
     vector<int> v1 = {10, 20, 30, 40, 50};
     auto result1 = getElement(v1, 2);
     cout << "Test 1 (vector[2]): " << result1 << " | Expected: 30 | "
          << (result1 == 30 ? "PASS" : "FAIL") << endl;

     // Test Case 2: Vector access - first element
     // Array: {100, 200, 300}, Index: 0
     // Expected: 100
     vector<int> v2 = {100, 200, 300};
     auto result2 = getElement(v2, 0);
     cout << "Test 2 (vector[0]): " << result2 << " | Expected: 100 | "
          << (result2 == 100 ? "PASS" : "FAIL") << endl;

     // Test Case 3: Vector access - last element
     // Array: {5, 15, 25, 35}, Index: 3
     // Expected: 35
     vector<int> v3 = {5, 15, 25, 35};
     auto result3 = getElement(v3, 3);
     cout << "Test 3 (vector[3]): " << result3 << " | Expected: 35 | "
          << (result3 == 35 ? "PASS" : "FAIL") << endl;

     // Test Case 4: Vector with doubles
     // Array: {1.1, 2.2, 3.3, 4.4}, Index: 1
     // Expected: 2.2
     vector<double> v4 = {1.1, 2.2, 3.3, 4.4};
     auto result4 = getElement(v4, 1);
     cout << "Test 4 (vector<double>[1]): " << result4 << " | Expected: 2.2 | "
          << (abs(result4 - 2.2) < 0.0001 ? "PASS" : "FAIL") << endl;

     // Test Case 5: Single element vector
     // Array: {42}, Index: 0
     // Expected: 42
     vector<int> v5 = {42};
     auto result5 = getElement(v5, 0);
     cout << "Test 5 (single element[0]): " << result5 << " | Expected: 42 | "
          << (result5 == 42 ? "PASS" : "FAIL") << endl;

     // Test Case 6: Vector with negative numbers
     // Array: {-10, -20, -30}, Index: 1
     // Expected: -20
     vector<int> v6 = {-10, -20, -30};
     auto result6 = getElement(v6, 1);
     cout << "Test 6 (negative numbers[1]): " << result6 << " | Expected: -20 | "
          << (result6 == -20 ? "PASS" : "FAIL") << endl;

     // Test Case 7: Large vector - middle element
     // Array: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, Index: 5
     // Expected: 6
     vector<int> v7 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
     auto result7 = getElement(v7, 5);
     cout << "Test 7 (large vector[5]): " << result7 << " | Expected: 6 | "
          << (result7 == 6 ? "PASS" : "FAIL") << endl;

     // Test Case 8: Vector with zeros
     // Array: {0, 0, 5, 0}, Index: 2
     // Expected: 5
     vector<int> v8 = {0, 0, 5, 0};
     auto result8 = getElement(v8, 2);
     cout << "Test 8 (with zeros[2]): " << result8 << " | Expected: 5 | "
          << (result8 == 5 ? "PASS" : "FAIL") << endl;
}

void testProblem3()
{
     cout << "\n========================================" << endl;
     cout << "Testing Problem 3: Conditional Return" << endl;
     cout << "========================================" << endl;

     // Test Case 1: True condition with int and double
     // Condition: true, Values: 10, 20.5
     // Returns first value (10), promoted to double
     // Expected: 10.0
     auto result1 = conditionalReturn(true, 10, 20.5);
     cout << "Test 1 (true, 10, 20.5): " << result1 << " | Expected: 10.0 | "
          << (abs(result1 - 10.0) < 0.0001 ? "PASS" : "FAIL") << endl;

     // Test Case 2: False condition with two ints
     // Condition: false, Values: 5, 7
     // Returns second value
     // Expected: 7
     auto result2 = conditionalReturn(false, 5, 7);
     cout << "Test 2 (false, 5, 7): " << result2 << " | Expected: 7 | "
          << (result2 == 7 ? "PASS" : "FAIL") << endl;

     // Test Case 3: True condition with double and int
     // Condition: true, Values: 3.14, 2
     // Returns first value
     // Expected: 3.14
     auto result3 = conditionalReturn(true, 3.14, 2);
     cout << "Test 3 (true, 3.14, 2): " << result3 << " | Expected: 3.14 | "
          << (abs(result3 - 3.14) < 0.0001 ? "PASS" : "FAIL") << endl;

     // Test Case 4: False condition with int and double
     // Condition: false, Values: 8, 12.5
     // Returns second value
     // Expected: 12.5
     auto result4 = conditionalReturn(false, 8, 12.5);
     cout << "Test 4 (false, 8, 12.5): " << result4 << " | Expected: 12.5 | "
          << (abs(result4 - 12.5) < 0.0001 ? "PASS" : "FAIL") << endl;

     // Test Case 5: True condition with two doubles
     // Condition: true, Values: 5.5, 7.7
     // Returns first value
     // Expected: 5.5
     auto result5 = conditionalReturn(true, 5.5, 7.7);
     cout << "Test 5 (true, 5.5, 7.7): " << result5 << " | Expected: 5.5 | "
          << (abs(result5 - 5.5) < 0.0001 ? "PASS" : "FAIL") << endl;

     // Test Case 6: False condition with negative numbers
     // Condition: false, Values: -3, -8
     // Returns second value
     // Expected: -8
     auto result6 = conditionalReturn(false, -3, -8);
     cout << "Test 6 (false, -3, -8): " << result6 << " | Expected: -8 | "
          << (result6 == -8 ? "PASS" : "FAIL") << endl;

     // Test Case 7: True condition with zero
     // Condition: true, Values: 0, 100
     // Returns first value
     // Expected: 0
     auto result7 = conditionalReturn(true, 0, 100);
     cout << "Test 7 (true, 0, 100): " << result7 << " | Expected: 0 | "
          << (result7 == 0 ? "PASS" : "FAIL") << endl;

     // Test Case 8: False condition with floats
     // Condition: false, Values: 2.5f, 8.5f
     // Returns second value
     // Expected: 8.5
     auto result8 = conditionalReturn(false, 2.5f, 8.5f);
     cout << "Test 8 (false, 2.5f, 8.5f): " << result8 << " | Expected: 8.5 | "
          << (abs(result8 - 8.5f) < 0.0001f ? "PASS" : "FAIL") << endl;
}

void testProblem4()
{
     cout << "\n========================================" << endl;
     cout << "Testing Problem 4: Complex Expression" << endl;
     cout << "========================================" << endl;

     // Test Case 1: All integers
     // Calculation: (2 * 3) + (10 / 2) = 6 + 5 = 11
     // Expected: 11
     auto result1 = complexCalc(2, 3, 10, 2);
     cout << "Test 1 (2*3 + 10/2): " << result1 << " | Expected: 11 | "
          << (result1 == 11 ? "PASS" : "FAIL") << endl;

     // Test Case 2: All doubles
     // Calculation: (2.5 * 4.0) + (15.0 / 3.0) = 10.0 + 5.0 = 15.0
     // Expected: 15.0
     auto result2 = complexCalc(2.5, 4.0, 15.0, 3.0);
     cout << "Test 2 (2.5*4.0 + 15.0/3.0): " << result2 << " | Expected: 15.0 | "
          << (abs(result2 - 15.0) < 0.0001 ? "PASS" : "FAIL") << endl;

     // Test Case 3: Mixed int and double
     // Calculation: (3 * 5) + (20.0 / 4) = 15 + 5.0 = 20.0
     // Expected: 20.0
     auto result3 = complexCalc(3, 5, 20.0, 4);
     cout << "Test 3 (3*5 + 20.0/4): " << result3 << " | Expected: 20.0 | "
          << (abs(result3 - 20.0) < 0.0001 ? "PASS" : "FAIL") << endl;

     // Test Case 4: With zeros in multiplication
     // Calculation: (0 * 10) + (8 / 2) = 0 + 4 = 4
     // Expected: 4
     auto result4 = complexCalc(0, 10, 8, 2);
     cout << "Test 4 (0*10 + 8/2): " << result4 << " | Expected: 4 | "
          << (result4 == 4 ? "PASS" : "FAIL") << endl;

     // Test Case 5: Negative numbers
     // Calculation: (-2 * 3) + (12 / 4) = -6 + 3 = -3
     // Expected: -3
     auto result5 = complexCalc(-2, 3, 12, 4);
     cout << "Test 5 (-2*3 + 12/4): " << result5 << " | Expected: -3 | "
          << (result5 == -3 ? "PASS" : "FAIL") << endl;

     // Test Case 6: Division with remainder (integer division)
     // Calculation: (5 * 2) + (7 / 2) = 10 + 3 = 13 (integer division: 7/2 = 3)
     // Expected: 13
     auto result6 = complexCalc(5, 2, 7, 2);
     cout << "Test 6 (5*2 + 7/2): " << result6 << " | Expected: 13 | "
          << (result6 == 13 ? "PASS" : "FAIL") << endl;

     // Test Case 7: Large numbers with doubles
     // Calculation: (10.0 * 10.0) + (50.0 / 5.0) = 100.0 + 10.0 = 110.0
     // Expected: 110.0
     auto result7 = complexCalc(10.0, 10.0, 50.0, 5.0);
     cout << "Test 7 (10.0*10.0 + 50.0/5.0): " << result7 << " | Expected: 110.0 | "
          << (abs(result7 - 110.0) < 0.0001 ? "PASS" : "FAIL") << endl;

     // Test Case 8: Fractional result
     // Calculation: (3 * 4) + (9.0 / 2.0) = 12 + 4.5 = 16.5
     // Expected: 16.5
     auto result8 = complexCalc(3, 4, 9.0, 2.0);
     cout << "Test 8 (3*4 + 9.0/2.0): " << result8 << " | Expected: 16.5 | "
          << (abs(result8 - 16.5) < 0.0001 ? "PASS" : "FAIL") << endl;
}

int main()
{
     int choice;
     cout << "\n========================================" << endl;
     cout << "  Decltype & Trailing Return Types Practice" << endl;
     cout << "========================================" << endl;
     cout << "\nChoose a problem to test (1-4) or 5 to test all:" << endl;
     cout << "1. Problem 1 (Easy) - Type-Safe Addition" << endl;
     cout << "2. Problem 2 (Easy) - Array Element Access" << endl;
     cout << "3. Problem 3 (Medium) - Conditional Return" << endl;
     cout << "4. Problem 4 (Hard) - Complex Expression" << endl;
     cout << "5. Test All Problems" << endl;
     cout << "\nEnter your choice: ";
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
          cout << "  All Tests Complete!" << endl;
          cout << "========================================" << endl;
          break;
     default:
          cout << "\nInvalid choice! Please select 1-5." << endl;
     }

     return 0;
}