#include <iostream>
#include <vector>
#include <string>
#include <concepts>
#include <cmath>

using namespace std;

// Problem 1: Easy 1 - Concept-Constrained Sum
// Description:
// Write a function that takes two numeric values and returns their sum.
// The function should use C++20 concepts to ensure only arithmetic types are accepted.
// Use 'auto' for the return type with a concept constraint.
//
// Input Format: Two numeric values (int, double, float, etc.)
// Output Format: Sum of the two values
//
// Example 1: sumValues(5, 3) -> 8
// Example 2: sumValues(2.5, 1.5) -> 4.0
// Example 3: sumValues(-10, 5) -> -5
//
// Constraints:
// - Must work with any arithmetic type (int, float, double, etc.)
// - Use std::integral or std::floating_point concepts
// - Return type should be deduced with auto
template <typename T, typename U>
     requires std::integral<T> || std::floating_point<T>
auto problem1Solution(T a, U b)
{
     // TODO: Implement your solution here using C++20 Concepts and auto
     // Hint: Simply return the sum, let auto deduce the type
     return a + b;
}

// Problem 2: Easy 2 - Generic Maximum with Concept
// Description:
// Write a function template that finds the maximum of two values.
// The function should use C++20 concepts to ensure the types are comparable.
// Use 'auto' for parameters and return type with appropriate concepts.
//
// Input Format: Two values of any comparable type
// Output Format: The larger of the two values
//
// Example 1: findMax(10, 20) -> 20
// Example 2: findMax(3.14, 2.71) -> 3.14
// Example 3: findMax('a', 'z') -> 'z'
//
// Constraints:
// - Must work with any type that supports comparison operators
// - Use auto with concept constraints for parameters
// - Return the larger value
template <typename T>
     requires requires(T a, T b) { a > b; }
auto problem2Solution(T a, T b)
{
     // TODO: Implement your solution here using C++20 Concepts and auto
     // Hint: Use the comparison operator and return the appropriate value
     return (a > b) ? a : b;
}

// Problem 3: Medium - Vector Statistics Calculator
// Description:
// Write a function that calculates the average of numeric values in a vector.
// The function should use C++20 concepts to constrain the element type.
// Use 'auto' for local variables and return type.
//
// Input Format: A vector of numeric values
// Output Format: The average as a double
//
// Example 1: calculateAverage({10, 20, 30}) -> 20.0
//   Calculation: (10 + 20 + 30) / 3 = 60 / 3 = 20.0
//
// Example 2: calculateAverage({5, 10, 15, 20}) -> 12.5
//   Calculation: (5 + 10 + 15 + 20) / 4 = 50 / 4 = 12.5
//
// Constraints:
// - Vector contains at least 1 element
// - Elements must be arithmetic types
// - Return 0.0 for empty vector
// - Use auto with range-based for loop
template <typename T>
     requires std::integral<T> || std::floating_point<T>
auto problem3Solution(const vector<T> &numbers)
{
     // TODO: Implement your solution here using C++20 Concepts and auto
     // Hint: Sum all elements using auto in a range-based for loop, then divide by size
     if (numbers.size() == 0)
          return 0.0;
     auto sum = numbers[0];
     for (size_t i = 1; i < numbers.size(); i++)
     {
          sum += numbers[i];
     }
     double average = static_cast<double>(sum) / static_cast<double>(numbers.size());

     return average;
}

// Problem 4: Hard - Generic Container Processor
// Description:
// Write a function template that processes a container and counts elements satisfying a condition.
// The function should accept any container type and use C++20 concepts to ensure:
// 1. The container is iterable (has begin() and end())
// 2. Use 'auto' extensively for iterators and intermediate values
// 3. Accept a predicate function and count matching elements
//
// Input Format: A container and a predicate function
// Output Format: Count of elements satisfying the predicate
//
// Example 1: countIf(vector{1,2,3,4,5}, [](auto x){ return x > 3; }) -> 2
//   Elements > 3: 4, 5 (count = 2)
//
// Example 2: countIf(vector{10,20,30,40}, [](auto x){ return x % 20 == 0; }) -> 2
//   Elements divisible by 20: 20, 40 (count = 2)
//
// Constraints:
// - Container must be iterable
// - Use auto for iterator and element types
// - Predicate takes element and returns bool
template <typename Container, typename Predicate>
     requires requires(Container c) { c.begin(); c.end(); }
auto problem4Solution(const Container &container, Predicate pred)
{
     // TODO: Implement your solution here using C++20 Concepts and auto
     // Hint: Iterate through container with auto, apply predicate, count matches
     return 0;
}

void testProblem1()
{
     cout << "\n=== Testing Problem 1: Concept-Constrained Sum ===" << endl;

     // Test Case 1: Positive integers
     // Calculation: 5 + 3 = 8
     auto result1 = problem1Solution(5, 3);
     cout << "Test 1 (5 + 3): " << (result1 == 8 ? "PASS" : "FAIL")
          << " (Expected: 8, Got: " << result1 << ")" << endl;

     // Test Case 2: Floating point numbers
     // Calculation: 2.5 + 1.5 = 4.0
     auto result2 = problem1Solution(2.5, 1.5);
     cout << "Test 2 (2.5 + 1.5): " << (abs(result2 - 4.0) < 0.001 ? "PASS" : "FAIL")
          << " (Expected: 4.0, Got: " << result2 << ")" << endl;

     // Test Case 3: Negative and positive
     // Calculation: -10 + 5 = -5
     auto result3 = problem1Solution(-10, 5);
     cout << "Test 3 (-10 + 5): " << (result3 == -5 ? "PASS" : "FAIL")
          << " (Expected: -5, Got: " << result3 << ")" << endl;

     // Test Case 4: Both negative
     // Calculation: -7 + -3 = -10
     auto result4 = problem1Solution(-7, -3);
     cout << "Test 4 (-7 + -3): " << (result4 == -10 ? "PASS" : "FAIL")
          << " (Expected: -10, Got: " << result4 << ")" << endl;

     // Test Case 5: Zero cases
     // Calculation: 0 + 15 = 15
     auto result5 = problem1Solution(0, 15);
     cout << "Test 5 (0 + 15): " << (result5 == 15 ? "PASS" : "FAIL")
          << " (Expected: 15, Got: " << result5 << ")" << endl;

     // Test Case 6: Mixed int and double
     // Calculation: 10 + 5.5 = 15.5
     auto result6 = problem1Solution(10, 5.5);
     cout << "Test 6 (10 + 5.5): " << (abs(result6 - 15.5) < 0.001 ? "PASS" : "FAIL")
          << " (Expected: 15.5, Got: " << result6 << ")" << endl;

     // Test Case 7: Large numbers
     // Calculation: 1000000 + 2000000 = 3000000
     auto result7 = problem1Solution(1000000, 2000000);
     cout << "Test 7 (1000000 + 2000000): " << (result7 == 3000000 ? "PASS" : "FAIL")
          << " (Expected: 3000000, Got: " << result7 << ")" << endl;

     // Test Case 8: Decimal precision
     // Calculation: 0.1 + 0.2 = 0.3 (approximately, due to floating point)
     auto result8 = problem1Solution(0.1, 0.2);
     cout << "Test 8 (0.1 + 0.2): " << (abs(result8 - 0.3) < 0.001 ? "PASS" : "FAIL")
          << " (Expected: ~0.3, Got: " << result8 << ")" << endl;
}

void testProblem2()
{
     cout << "\n=== Testing Problem 2: Generic Maximum with Concept ===" << endl;

     // Test Case 1: Integers - first larger
     // Comparison: 20 > 10 = true, return 20
     auto result1 = problem2Solution(20, 10);
     cout << "Test 1 (max(20, 10)): " << (result1 == 20 ? "PASS" : "FAIL")
          << " (Expected: 20, Got: " << result1 << ")" << endl;

     // Test Case 2: Integers - second larger
     // Comparison: 10 > 20 = false, return 20
     auto result2 = problem2Solution(10, 20);
     cout << "Test 2 (max(10, 20)): " << (result2 == 20 ? "PASS" : "FAIL")
          << " (Expected: 20, Got: " << result2 << ")" << endl;

     // Test Case 3: Floating point
     // Comparison: 3.14 > 2.71 = true, return 3.14
     auto result3 = problem2Solution(3.14, 2.71);
     cout << "Test 3 (max(3.14, 2.71)): " << (abs(result3 - 3.14) < 0.001 ? "PASS" : "FAIL")
          << " (Expected: 3.14, Got: " << result3 << ")" << endl;

     // Test Case 4: Characters
     // Comparison: 'z' > 'a' = true (122 > 97), return 'z'
     auto result4 = problem2Solution('z', 'a');
     cout << "Test 4 (max('z', 'a')): " << (result4 == 'z' ? "PASS" : "FAIL")
          << " (Expected: 'z', Got: '" << result4 << "')" << endl;

     // Test Case 5: Equal values
     // Comparison: 15 > 15 = false, but both equal
     auto result5 = problem2Solution(15, 15);
     cout << "Test 5 (max(15, 15)): " << (result5 == 15 ? "PASS" : "FAIL")
          << " (Expected: 15, Got: " << result5 << ")" << endl;

     // Test Case 6: Negative numbers
     // Comparison: -5 > -10 = true, return -5
     auto result6 = problem2Solution(-5, -10);
     cout << "Test 6 (max(-5, -10)): " << (result6 == -5 ? "PASS" : "FAIL")
          << " (Expected: -5, Got: " << result6 << ")" << endl;

     // Test Case 7: Zero and positive
     // Comparison: 100 > 0 = true, return 100
     auto result7 = problem2Solution(100, 0);
     cout << "Test 7 (max(100, 0)): " << (result7 == 100 ? "PASS" : "FAIL")
          << " (Expected: 100, Got: " << result7 << ")" << endl;

     // Test Case 8: Zero and negative
     // Comparison: 0 > -50 = true, return 0
     auto result8 = problem2Solution(0, -50);
     cout << "Test 8 (max(0, -50)): " << (result8 == 0 ? "PASS" : "FAIL")
          << " (Expected: 0, Got: " << result8 << ")" << endl;
}

void testProblem3()
{
     cout << "\n=== Testing Problem 3: Vector Statistics Calculator ===" << endl;

     // Test Case 1: Simple average
     // Calculation: (10 + 20 + 30) / 3 = 60 / 3 = 20.0
     vector<int> test1 = {10, 20, 30};
     auto result1 = problem3Solution(test1);
     cout << "Test 1 ({10,20,30}): " << (abs(result1 - 20.0) < 0.001 ? "PASS" : "FAIL")
          << " (Expected: 20.0, Got: " << result1 << ")" << endl;

     // Test Case 2: Four elements
     // Calculation: (5 + 10 + 15 + 20) / 4 = 50 / 4 = 12.5
     vector<int> test2 = {5, 10, 15, 20};
     auto result2 = problem3Solution(test2);
     cout << "Test 2 ({5,10,15,20}): " << (abs(result2 - 12.5) < 0.001 ? "PASS" : "FAIL")
          << " (Expected: 12.5, Got: " << result2 << ")" << endl;

     // Test Case 3: Single element
     // Calculation: 42 / 1 = 42.0
     vector<int> test3 = {42};
     auto result3 = problem3Solution(test3);
     cout << "Test 3 ({42}): " << (abs(result3 - 42.0) < 0.001 ? "PASS" : "FAIL")
          << " (Expected: 42.0, Got: " << result3 << ")" << endl;

     // Test Case 4: Negative numbers
     // Calculation: (-10 + -20 + -30) / 3 = -60 / 3 = -20.0
     vector<int> test4 = {-10, -20, -30};
     auto result4 = problem3Solution(test4);
     cout << "Test 4 ({-10,-20,-30}): " << (abs(result4 - (-20.0)) < 0.001 ? "PASS" : "FAIL")
          << " (Expected: -20.0, Got: " << result4 << ")" << endl;

     // Test Case 5: Mixed positive and negative
     // Calculation: (100 + -50 + 25 + -25) / 4 = 50 / 4 = 12.5
     vector<int> test5 = {100, -50, 25, -25};
     auto result5 = problem3Solution(test5);
     cout << "Test 5 ({100,-50,25,-25}): " << (abs(result5 - 12.5) < 0.001 ? "PASS" : "FAIL")
          << " (Expected: 12.5, Got: " << result5 << ")" << endl;

     // Test Case 6: All zeros
     // Calculation: (0 + 0 + 0 + 0) / 4 = 0 / 4 = 0.0
     vector<int> test6 = {0, 0, 0, 0};
     auto result6 = problem3Solution(test6);
     cout << "Test 6 ({0,0,0,0}): " << (abs(result6 - 0.0) < 0.001 ? "PASS" : "FAIL")
          << " (Expected: 0.0, Got: " << result6 << ")" << endl;

     // Test Case 7: Floating point values
     // Calculation: (1.5 + 2.5 + 3.5 + 4.5) / 4 = 12.0 / 4 = 3.0
     vector<double> test7 = {1.5, 2.5, 3.5, 4.5};
     auto result7 = problem3Solution(test7);
     cout << "Test 7 ({1.5,2.5,3.5,4.5}): " << (abs(result7 - 3.0) < 0.001 ? "PASS" : "FAIL")
          << " (Expected: 3.0, Got: " << result7 << ")" << endl;

     // Test Case 8: Large numbers
     // Calculation: (1000 + 2000 + 3000 + 4000 + 5000) / 5 = 15000 / 5 = 3000.0
     vector<int> test8 = {1000, 2000, 3000, 4000, 5000};
     auto result8 = problem3Solution(test8);
     cout << "Test 8 ({1000,2000,3000,4000,5000}): " << (abs(result8 - 3000.0) < 0.001 ? "PASS" : "FAIL")
          << " (Expected: 3000.0, Got: " << result8 << ")" << endl;
}

void testProblem4()
{
     cout << "\n=== Testing Problem 4: Generic Container Processor ===" << endl;

     // Test Case 1: Count elements greater than 3
     // Elements: 1,2,3,4,5 -> 4,5 satisfy (x > 3) -> count = 2
     vector<int> test1 = {1, 2, 3, 4, 5};
     auto result1 = problem4Solution(test1, [](auto x)
                                     { return x > 3; });
     cout << "Test 1 (count > 3 in {1,2,3,4,5}): " << (result1 == 2 ? "PASS" : "FAIL")
          << " (Expected: 2, Got: " << result1 << ")" << endl;

     // Test Case 2: Count even numbers
     // Elements: 10,20,30,40 -> 10%20=10, 20%20=0, 30%20=10, 40%20=0 -> count = 2
     vector<int> test2 = {10, 20, 30, 40};
     auto result2 = problem4Solution(test2, [](auto x)
                                     { return x % 20 == 0; });
     cout << "Test 2 (count divisible by 20 in {10,20,30,40}): " << (result2 == 2 ? "PASS" : "FAIL")
          << " (Expected: 2, Got: " << result2 << ")" << endl;

     // Test Case 3: Count negative numbers
     // Elements: -5,10,-3,8,-1,6 -> -5,-3,-1 satisfy (x < 0) -> count = 3
     vector<int> test3 = {-5, 10, -3, 8, -1, 6};
     auto result3 = problem4Solution(test3, [](auto x)
                                     { return x < 0; });
     cout << "Test 3 (count negative in {-5,10,-3,8,-1,6}): " << (result3 == 3 ? "PASS" : "FAIL")
          << " (Expected: 3, Got: " << result3 << ")" << endl;

     // Test Case 4: Count all (always true predicate)
     // Elements: 1,2,3 -> all satisfy (x > 0) -> count = 3
     vector<int> test4 = {1, 2, 3};
     auto result4 = problem4Solution(test4, [](auto x)
                                     { return x > 0; });
     cout << "Test 4 (count all positive in {1,2,3}): " << (result4 == 3 ? "PASS" : "FAIL")
          << " (Expected: 3, Got: " << result4 << ")" << endl;

     // Test Case 5: Count none (always false predicate)
     // Elements: 5,10,15 -> none satisfy (x > 100) -> count = 0
     vector<int> test5 = {5, 10, 15};
     auto result5 = problem4Solution(test5, [](auto x)
                                     { return x > 100; });
     cout << "Test 5 (count > 100 in {5,10,15}): " << (result5 == 0 ? "PASS" : "FAIL")
          << " (Expected: 0, Got: " << result5 << ")" << endl;

     // Test Case 6: Count equal to value
     // Elements: 7,7,8,7,9 -> 7==7 three times -> count = 3
     vector<int> test6 = {7, 7, 8, 7, 9};
     auto result6 = problem4Solution(test6, [](auto x)
                                     { return x == 7; });
     cout << "Test 6 (count == 7 in {7,7,8,7,9}): " << (result6 == 3 ? "PASS" : "FAIL")
          << " (Expected: 3, Got: " << result6 << ")" << endl;

     // Test Case 7: Single element matching
     // Elements: 42 -> 42 % 2 = 0 (even) -> count = 1
     vector<int> test7 = {42};
     auto result7 = problem4Solution(test7, [](auto x)
                                     { return x % 2 == 0; });
     cout << "Test 7 (count even in {42}): " << (result7 == 1 ? "PASS" : "FAIL")
          << " (Expected: 1, Got: " << result7 << ")" << endl;

     // Test Case 8: Count in range
     // Elements: 5,15,25,35,45 -> 15,25,35 are in [10,40) -> count = 3
     vector<int> test8 = {5, 15, 25, 35, 45};
     auto result8 = problem4Solution(test8, [](auto x)
                                     { return x >= 10 && x < 40; });
     cout << "Test 8 (count in [10,40) in {5,15,25,35,45}): " << (result8 == 3 ? "PASS" : "FAIL")
          << " (Expected: 3, Got: " << result8 << ")" << endl;
}

int main()
{
     int choice;
     cout << "==================================================" << endl;
     cout << "   C++20 Concepts and Auto - Practice Problems   " << endl;
     cout << "==================================================" << endl;
     cout << "\nChoose a problem to test (1-4) or 5 to test all:" << endl;
     cout << "1. Problem 1 (Easy - Concept-Constrained Sum)" << endl;
     cout << "2. Problem 2 (Easy - Generic Maximum)" << endl;
     cout << "3. Problem 3 (Medium - Vector Statistics)" << endl;
     cout << "4. Problem 4 (Hard - Generic Container Processor)" << endl;
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
          cout << "\n==================================================" << endl;
          cout << "            All Tests Completed!                  " << endl;
          cout << "==================================================" << endl;
          break;
     default:
          cout << "Invalid choice!" << endl;
     }

     return 0;
}