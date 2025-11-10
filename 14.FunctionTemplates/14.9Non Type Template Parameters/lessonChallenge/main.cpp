#include <iostream>
#include <array>
#include <string>

using namespace std;

// ============================================================================
// Problem 1: Easy 1 - Fixed Size Array Sum
// ============================================================================
// Description:
//   Create a template function that takes a fixed-size array and returns
//   the sum of all its elements. The array size is a non-type template parameter.
//
// Input Format:
//   An array of integers with compile-time known size
//
// Output Format:
//   Single integer representing the sum
//
// Examples:
//   Input: array = {1, 2, 3, 4, 5}, SIZE = 5
//   Output: 15
//   Explanation: 1 + 2 + 3 + 4 + 5 = 15
//
//   Input: array = {10, -5, 3}, SIZE = 3
//   Output: 8
//   Explanation: 10 + (-5) + 3 = 8
//
// Constraints:
//   - 1 <= SIZE <= 100
//   - -1000 <= array[i] <= 1000
//
template <int SIZE>
int arraySum(int (&arr)[SIZE])
{
     // TODO: Implement your solution here using Non-Type Template Parameters
     // Hint: Use a simple loop to iterate through SIZE elements
     int sum{};
     for (int i = 0; i < size(arr); i++)
     {
          sum += arr[i];
     }
     return sum;
}

// ============================================================================
// Problem 2: Easy 2 - Fixed Buffer String Formatter
// ============================================================================
// Description:
//   Create a template function that formats a string into a fixed-size buffer.
//   If the string is shorter than the buffer, pad with spaces.
//   If longer, truncate it. The buffer size is a non-type template parameter.
//
// Input Format:
//   A string to format
//
// Output Format:
//   A string of exactly BUFFER_SIZE characters
//
// Examples:
//   Input: str = "Hello", BUFFER_SIZE = 10
//   Output: "Hello     " (5 letters + 5 spaces = 10 total)
//
//   Input: str = "LongStringHere", BUFFER_SIZE = 8
//   Output: "LongStri" (truncated to 8 characters)
//
//   Input: str = "Test", BUFFER_SIZE = 4
//   Output: "Test" (exact fit)
//
// Constraints:
//   - 1 <= BUFFER_SIZE <= 100
//   - 0 <= str.length() <= 200
//
template <int BUFFER_SIZE>
string formatString(const string &str)
{
     // TODO: Implement your solution here using Non-Type Template Parameters
     // Hint: Check if string length < BUFFER_SIZE (pad) or >= BUFFER_SIZE (truncate)
     string format{};
     for (int i = 0; i < BUFFER_SIZE; i++)
     {
          if (i >= str.size())
          {
               format.push_back(' ');
          }
          else
          {
               format.push_back(str[i]);
          }
     }

     return format;
}

// ============================================================================
// Problem 3: Medium - Power Calculator with Compile-Time Exponent
// ============================================================================
// Description:
//   Create a template function that calculates base^exponent where the exponent
//   is a compile-time constant (non-type template parameter).
//   Implement this using a loop (not recursion or built-in pow).
//
// Input Format:
//   An integer base, and EXPONENT as template parameter
//
// Output Format:
//   Integer result of base^EXPONENT
//
// Examples:
//   Input: base = 2, EXPONENT = 5
//   Output: 32
//   Explanation: 2^5 = 2*2*2*2*2 = 32
//
//   Input: base = 3, EXPONENT = 3
//   Output: 27
//   Explanation: 3^3 = 3*3*3 = 27
//
//   Input: base = 5, EXPONENT = 0
//   Output: 1
//   Explanation: Any number^0 = 1
//
// Constraints:
//   - -10 <= base <= 10
//   - 0 <= EXPONENT <= 10
//   - Result will fit in int range
//
template <int EXPONENT>
int power(int base)
{
     // TODO: Implement your solution here using Non-Type Template Parameters
     // Hint: Handle EXPONENT = 0 case, then multiply base EXPONENT times
     if (EXPONENT == 0)
          return 1;
     int result = base;
     for (size_t i = 1; i < EXPONENT; i++)
     {
          result = result * base;
     }

     return result;
}

// ============================================================================
// Problem 4: Hard - Matrix Transposer with Compile-Time Dimensions
// ============================================================================
// Description:
//   Create a template function that transposes a 2D array (matrix).
//   Both ROWS and COLS are non-type template parameters.
//   Transpose means converting rows to columns and columns to rows.
//
// Input Format:
//   A 2D array of integers with dimensions ROWS x COLS
//
// Output Format:
//   Print the transposed matrix (COLS x ROWS) to console
//
// Examples:
//   Input: matrix = {{1, 2, 3},    ROWS = 2, COLS = 3
//                    {4, 5, 6}}
//   Output:
//   1 4
//   2 5
//   3 6
//   Explanation: First row of output is first column of input
//
//   Input: matrix = {{1, 2},       ROWS = 3, COLS = 2
//                    {3, 4},
//                    {5, 6}}
//   Output:
//   1 3 5
//   2 4 6
//
// Constraints:
//   - 1 <= ROWS, COLS <= 10
//   - -100 <= matrix[i][j] <= 100
//
template <int ROWS, int COLS>
void transposeMatrix(int (&matrix)[ROWS][COLS])
{
     // TODO: Implement your solution here using Non-Type Template Parameters
     // Hint: Iterate with nested loops - outer loop for new rows (0 to COLS-1),
     //       inner loop for new columns (0 to ROWS-1)
}

// ============================================================================
// TEST FUNCTIONS
// ============================================================================

void testProblem1()
{
     cout << "\n=== Testing Problem 1: Fixed Size Array Sum ===" << endl;

     // Test Case 1: Simple positive numbers
     // Calculation: 1 + 2 + 3 + 4 + 5 = 15
     int arr1[] = {1, 2, 3, 4, 5};
     cout << "Test 1: " << (arraySum(arr1) == 15 ? "PASS" : "FAIL")
          << " (Expected: 15, Got: " << arraySum(arr1) << ")" << endl;

     // Test Case 2: Array with negative numbers
     // Calculation: 10 + (-5) + 3 = 8
     int arr2[] = {10, -5, 3};
     cout << "Test 2: " << (arraySum(arr2) == 8 ? "PASS" : "FAIL")
          << " (Expected: 8, Got: " << arraySum(arr2) << ")" << endl;

     // Test Case 3: Single element
     // Calculation: 42
     int arr3[] = {42};
     cout << "Test 3: " << (arraySum(arr3) == 42 ? "PASS" : "FAIL")
          << " (Expected: 42, Got: " << arraySum(arr3) << ")" << endl;

     // Test Case 4: All zeros
     // Calculation: 0 + 0 + 0 + 0 = 0
     int arr4[] = {0, 0, 0, 0};
     cout << "Test 4: " << (arraySum(arr4) == 0 ? "PASS" : "FAIL")
          << " (Expected: 0, Got: " << arraySum(arr4) << ")" << endl;

     // Test Case 5: All negative numbers
     // Calculation: (-1) + (-2) + (-3) = -6
     int arr5[] = {-1, -2, -3};
     cout << "Test 5: " << (arraySum(arr5) == -6 ? "PASS" : "FAIL")
          << " (Expected: -6, Got: " << arraySum(arr5) << ")" << endl;

     // Test Case 6: Large array
     // Calculation: 10 + 20 + 30 + 40 + 50 + 60 + 70 + 80 = 360
     int arr6[] = {10, 20, 30, 40, 50, 60, 70, 80};
     cout << "Test 6: " << (arraySum(arr6) == 360 ? "PASS" : "FAIL")
          << " (Expected: 360, Got: " << arraySum(arr6) << ")" << endl;

     // Test Case 7: Mixed positive and negative
     // Calculation: 100 + (-50) + 25 + (-25) + 50 = 100
     int arr7[] = {100, -50, 25, -25, 50};
     cout << "Test 7: " << (arraySum(arr7) == 100 ? "PASS" : "FAIL")
          << " (Expected: 100, Got: " << arraySum(arr7) << ")" << endl;

     // Test Case 8: Two elements
     // Calculation: 15 + 85 = 100
     int arr8[] = {15, 85};
     cout << "Test 8: " << (arraySum(arr8) == 100 ? "PASS" : "FAIL")
          << " (Expected: 100, Got: " << arraySum(arr8) << ")" << endl;
}

void testProblem2()
{
     cout << "\n=== Testing Problem 2: Fixed Buffer String Formatter ===" << endl;

     // Test Case 1: String shorter than buffer - needs padding
     // "Hello" has 5 chars, buffer is 10, so add 5 spaces
     // Expected: "Hello     " (Hello + 5 spaces)
     string result1 = formatString<10>("Hello");
     cout << "Test 1: " << (result1 == "Hello     " && result1.length() == 10 ? "PASS" : "FAIL")
          << " (Expected: 'Hello     ', Got: '" << result1 << "', Length: " << result1.length() << ")" << endl;

     // Test Case 2: String longer than buffer - needs truncation
     // "LongStringHere" has 14 chars, buffer is 8, truncate to first 8
     // Expected: "LongStri"
     string result2 = formatString<8>("LongStringHere");
     cout << "Test 2: " << (result2 == "LongStri" && result2.length() == 8 ? "PASS" : "FAIL")
          << " (Expected: 'LongStri', Got: '" << result2 << "', Length: " << result2.length() << ")" << endl;

     // Test Case 3: Exact fit
     // "Test" has 4 chars, buffer is 4, no padding or truncation
     // Expected: "Test"
     string result3 = formatString<4>("Test");
     cout << "Test 3: " << (result3 == "Test" && result3.length() == 4 ? "PASS" : "FAIL")
          << " (Expected: 'Test', Got: '" << result3 << "', Length: " << result3.length() << ")" << endl;

     // Test Case 4: Empty string
     // "" has 0 chars, buffer is 5, add 5 spaces
     // Expected: "     " (5 spaces)
     string result4 = formatString<5>("");
     cout << "Test 4: " << (result4 == "     " && result4.length() == 5 ? "PASS" : "FAIL")
          << " (Expected: '     ', Got: '" << result4 << "', Length: " << result4.length() << ")" << endl;

     // Test Case 5: Single character buffer
     // "ABC" truncated to buffer size 1
     // Expected: "A"
     string result5 = formatString<1>("ABC");
     cout << "Test 5: " << (result5 == "A" && result5.length() == 1 ? "PASS" : "FAIL")
          << " (Expected: 'A', Got: '" << result5 << "', Length: " << result5.length() << ")" << endl;

     // Test Case 6: Large buffer with short string
     // "Hi" has 2 chars, buffer is 15, add 13 spaces
     // Expected: "Hi             " (Hi + 13 spaces)
     string result6 = formatString<15>("Hi");
     cout << "Test 6: " << (result6 == "Hi             " && result6.length() == 15 ? "PASS" : "FAIL")
          << " (Expected: 'Hi             ', Got: '" << result6 << "', Length: " << result6.length() << ")" << endl;

     // Test Case 7: Numbers and special chars
     // "C++20" has 5 chars, buffer is 8, add 3 spaces
     // Expected: "C++20   " (C++20 + 3 spaces)
     string result7 = formatString<8>("C++20");
     cout << "Test 7: " << (result7 == "C++20   " && result7.length() == 8 ? "PASS" : "FAIL")
          << " (Expected: 'C++20   ', Got: '" << result7 << "', Length: " << result7.length() << ")" << endl;

     // Test Case 8: Truncate at exact boundary
     // "12345678901234567890" (20 chars) truncated to 12
     // Expected: "123456789012"
     string result8 = formatString<12>("12345678901234567890");
     cout << "Test 8: " << (result8 == "123456789012" && result8.length() == 12 ? "PASS" : "FAIL")
          << " (Expected: '123456789012', Got: '" << result8 << "', Length: " << result8.length() << ")" << endl;
}

void testProblem3()
{
     cout << "\n=== Testing Problem 3: Power Calculator ===" << endl;

     // Test Case 1: Basic power calculation
     // Calculation: 2^5 = 2*2*2*2*2 = 4*2*2*2 = 8*2*2 = 16*2 = 32
     cout << "Test 1: " << (power<5>(2) == 32 ? "PASS" : "FAIL")
          << " (Expected: 32, Got: " << power<5>(2) << ")" << endl;

     // Test Case 2: Cube calculation
     // Calculation: 3^3 = 3*3*3 = 9*3 = 27
     cout << "Test 2: " << (power<3>(3) == 27 ? "PASS" : "FAIL")
          << " (Expected: 27, Got: " << power<3>(3) << ")" << endl;

     // Test Case 3: Exponent zero (edge case)
     // Calculation: 5^0 = 1 (any number to power 0 is 1)
     cout << "Test 3: " << (power<0>(5) == 1 ? "PASS" : "FAIL")
          << " (Expected: 1, Got: " << power<0>(5) << ")" << endl;

     // Test Case 4: Base one
     // Calculation: 1^7 = 1*1*1*1*1*1*1 = 1
     cout << "Test 4: " << (power<7>(1) == 1 ? "PASS" : "FAIL")
          << " (Expected: 1, Got: " << power<7>(1) << ")" << endl;

     // Test Case 5: Negative base with odd exponent
     // Calculation: (-2)^3 = (-2)*(-2)*(-2) = 4*(-2) = -8
     cout << "Test 5: " << (power<3>(-2) == -8 ? "PASS" : "FAIL")
          << " (Expected: -8, Got: " << power<3>(-2) << ")" << endl;

     // Test Case 6: Negative base with even exponent
     // Calculation: (-3)^2 = (-3)*(-3) = 9
     cout << "Test 6: " << (power<2>(-3) == 9 ? "PASS" : "FAIL")
          << " (Expected: 9, Got: " << power<2>(-3) << ")" << endl;

     // Test Case 7: Base zero with positive exponent
     // Calculation: 0^4 = 0*0*0*0 = 0
     cout << "Test 7: " << (power<4>(0) == 0 ? "PASS" : "FAIL")
          << " (Expected: 0, Got: " << power<4>(0) << ")" << endl;

     // Test Case 8: Exponent one
     // Calculation: 10^1 = 10
     cout << "Test 8: " << (power<1>(10) == 10 ? "PASS" : "FAIL")
          << " (Expected: 10, Got: " << power<1>(10) << ")" << endl;

     // Test Case 9: Large result
     // Calculation: 4^4 = 4*4*4*4 = 16*4*4 = 64*4 = 256
     cout << "Test 9: " << (power<4>(4) == 256 ? "PASS" : "FAIL")
          << " (Expected: 256, Got: " << power<4>(4) << ")" << endl;

     // Test Case 10: Negative base with zero exponent
     // Calculation: (-5)^0 = 1
     cout << "Test 10: " << (power<0>(-5) == 1 ? "PASS" : "FAIL")
          << " (Expected: 1, Got: " << power<0>(-5) << ")" << endl;
}

void testProblem4()
{
     cout << "\n=== Testing Problem 4: Matrix Transposer ===" << endl;

     // Test Case 1: 2x3 matrix
     cout << "\nTest 1: 2x3 matrix" << endl;
     cout << "Input matrix:" << endl;
     cout << "1 2 3" << endl;
     cout << "4 5 6" << endl;
     int matrix1[2][3] = {{1, 2, 3}, {4, 5, 6}};
     cout << "Expected output:" << endl;
     cout << "1 4" << endl;
     cout << "2 5" << endl;
     cout << "3 6" << endl;
     cout << "Your output:" << endl;
     transposeMatrix(matrix1);

     // Test Case 2: 3x2 matrix
     cout << "\nTest 2: 3x2 matrix" << endl;
     cout << "Input matrix:" << endl;
     cout << "1 2" << endl;
     cout << "3 4" << endl;
     cout << "5 6" << endl;
     int matrix2[3][2] = {{1, 2}, {3, 4}, {5, 6}};
     cout << "Expected output:" << endl;
     cout << "1 3 5" << endl;
     cout << "2 4 6" << endl;
     cout << "Your output:" << endl;
     transposeMatrix(matrix2);

     // Test Case 3: 3x3 square matrix
     cout << "\nTest 3: 3x3 square matrix" << endl;
     cout << "Input matrix:" << endl;
     cout << "1 2 3" << endl;
     cout << "4 5 6" << endl;
     cout << "7 8 9" << endl;
     int matrix3[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
     cout << "Expected output:" << endl;
     cout << "1 4 7" << endl;
     cout << "2 5 8" << endl;
     cout << "3 6 9" << endl;
     cout << "Your output:" << endl;
     transposeMatrix(matrix3);

     // Test Case 4: 1x4 matrix (single row)
     cout << "\nTest 4: 1x4 matrix (single row)" << endl;
     cout << "Input matrix:" << endl;
     cout << "10 20 30 40" << endl;
     int matrix4[1][4] = {{10, 20, 30, 40}};
     cout << "Expected output:" << endl;
     cout << "10" << endl;
     cout << "20" << endl;
     cout << "30" << endl;
     cout << "40" << endl;
     cout << "Your output:" << endl;
     transposeMatrix(matrix4);

     // Test Case 5: 4x1 matrix (single column)
     cout << "\nTest 5: 4x1 matrix (single column)" << endl;
     cout << "Input matrix:" << endl;
     cout << "5" << endl;
     cout << "10" << endl;
     cout << "15" << endl;
     cout << "20" << endl;
     int matrix5[4][1] = {{5}, {10}, {15}, {20}};
     cout << "Expected output:" << endl;
     cout << "5 10 15 20" << endl;
     cout << "Your output:" << endl;
     transposeMatrix(matrix5);

     // Test Case 6: 2x2 matrix with negative numbers
     cout << "\nTest 6: 2x2 matrix with negative numbers" << endl;
     cout << "Input matrix:" << endl;
     cout << "-1 2" << endl;
     cout << "3 -4" << endl;
     int matrix6[2][2] = {{-1, 2}, {3, -4}};
     cout << "Expected output:" << endl;
     cout << "-1 3" << endl;
     cout << "2 -4" << endl;
     cout << "Your output:" << endl;
     transposeMatrix(matrix6);

     // Test Case 7: 1x1 matrix (single element)
     cout << "\nTest 7: 1x1 matrix (single element)" << endl;
     cout << "Input matrix:" << endl;
     cout << "42" << endl;
     int matrix7[1][1] = {{42}};
     cout << "Expected output:" << endl;
     cout << "42" << endl;
     cout << "Your output:" << endl;
     transposeMatrix(matrix7);

     // Test Case 8: 3x4 matrix with zeros
     cout << "\nTest 8: 3x4 matrix with zeros" << endl;
     cout << "Input matrix:" << endl;
     cout << "1 0 2 0" << endl;
     cout << "0 3 0 4" << endl;
     cout << "5 0 6 0" << endl;
     int matrix8[3][4] = {{1, 0, 2, 0}, {0, 3, 0, 4}, {5, 0, 6, 0}};
     cout << "Expected output:" << endl;
     cout << "1 0 5" << endl;
     cout << "0 3 0" << endl;
     cout << "2 0 6" << endl;
     cout << "0 4 0" << endl;
     cout << "Your output:" << endl;
     transposeMatrix(matrix8);
}

int main()
{
     int choice;
     cout << "==================================================" << endl;
     cout << "  Non-Type Template Parameters Practice Problems" << endl;
     cout << "==================================================" << endl;
     cout << "\nChoose a problem to test (1-4) or 5 to test all:" << endl;
     cout << "1. Problem 1 (Easy) - Fixed Size Array Sum" << endl;
     cout << "2. Problem 2 (Easy) - Fixed Buffer String Formatter" << endl;
     cout << "3. Problem 3 (Medium) - Power Calculator" << endl;
     cout << "4. Problem 4 (Hard) - Matrix Transposer" << endl;
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
          break;
     default:
          cout << "Invalid choice! Please enter 1-5." << endl;
     }

     return 0;
}