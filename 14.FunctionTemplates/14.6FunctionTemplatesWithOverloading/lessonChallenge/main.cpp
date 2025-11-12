#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;

// ============================================================================
// Problem 1: Easy 1 - Maximum Finder with Type Specialization
// ============================================================================
// Description:
// Create a template function 'maximum' that finds the maximum of two values.
// Overload it with:
// 1. A template version for generic types (int, double, etc.)
// 2. A specialized version for C-strings (char*) that compares by length
// 3. A specialized version for std::string that compares alphabetically
//
// Input/Output Format:
// - For numbers: Returns the larger number
// - For C-strings: Returns the longer string (or first if equal length)
// - For std::string: Returns the alphabetically later string
//
// Example 1: maximum(5, 10) -> returns 10
// Example 2: maximum(3.14, 2.71) -> returns 3.14
// Example 3: maximum("cat", "dog") -> returns "cat" (both length 3, return first)
// Example 4: maximum(string("apple"), string("banana")) -> returns "banana"
//
// Constraints:
// - Works with int, double, char*, and std::string
// - For C-strings, compare by length only
// - For std::string, compare alphabetically

// Template version for generic types
template <typename T>
T maximum(T a, T b)
{
    // TODO: Implement your solution here
    // Hint: Use comparison operator to return the larger value
    return (a > b) ? a : b;
}

// Overload for C-strings (char*) - compare by length
const char *maximum(const char *a, const char *b)
{
    // TODO: Implement your solution here
    // Hint: Use strlen or manual length calculation, return longer string
    return (strlen(a) > strlen(b)) ? a : b;
}

// Overload for std::string - compare alphabetically
string maximum(const string &a, const string &b)
{
    // TODO: Implement your solution here
    // Hint: Use string comparison operators for alphabetical order
    return (a > b) ? a : b;
}

// ============================================================================
// Problem 2: Easy 2 - Array Sum Calculator with Different Types
// ============================================================================
// Description:
// Create a template function 'arraySum' that calculates the sum of array elements.
// Overload it with:
// 1. A template version for numeric arrays (int, double)
// 2. A specialized version for char arrays that counts total ASCII values
// 3. A specialized version for bool arrays that counts 'true' values
//
// Input/Output Format:
// - For int/double arrays: Returns sum of all elements
// - For char arrays: Returns sum of ASCII values
// - For bool arrays: Returns count of true values
//
// Example 1: arraySum({1, 2, 3, 4, 5}, 5) -> returns 15
// Example 2: arraySum({1.5, 2.5, 3.0}, 3) -> returns 7.0
// Example 3: arraySum({'A', 'B', 'C'}, 3) -> returns 198 (65+66+67)
// Example 4: arraySum({true, false, true, true}, 4) -> returns 3
//
// Constraints:
// - Array size is passed as parameter
// - Array size >= 0

// Template version for numeric types
template <typename T>
T arraySum(const T arr[], int size)
{
    // TODO: Implement your solution here
    // Hint: Loop through array and accumulate sum
    T sum{};
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum;
}

// Overload for char arrays - sum ASCII values
int arraySum(const char arr[], int size)
{
    // TODO: Implement your solution here
    // Hint: Cast each char to int and sum
    int sum{};
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum;
}

// Overload for bool arrays - count true values
int arraySum(const bool arr[], int size)
{
    // TODO: Implement your solution here
    // Hint: Count how many elements are true
    int sum{};
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum;
}

// ============================================================================
// Problem 3: Medium - Smart Swap Function with Special Cases
// ============================================================================
// Description:
// Create a template function 'smartSwap' that swaps two values.
// Overload it with special behavior:
// 1. Template version: Normal swap for generic types
// 2. Overload for pointers: Swap what they point to (not the pointers themselves)
// 3. Overload for arrays: Swap first and last elements only
// 4. Overload for const char*: Swap the strings by copying content
//
// Input/Output Format:
// - For regular types: Swaps the two values
// - For pointers: Swaps the values they point to
// - For arrays: Swaps first and last elements, size passed as 3rd parameter
// - For const char*: Returns true if swap successful, false otherwise
//
// Example 1: int a=5, b=10; smartSwap(a,b); -> a=10, b=5
// Example 2: int x=1, y=2; int *p1=&x, *p2=&y; smartSwap(p1,p2); -> x=2, y=1
// Example 3: int arr[]={1,2,3,4,5}; smartSwap(arr,5); -> arr={5,2,3,4,1}
//
// Constraints:
// - For arrays, size must be >= 2
// - For pointers, they must not be nullptr

// Template version - normal swap
template <typename T>
void smartSwap(T &a, T &b)
{
    // TODO: Implement your solution here
    // Hint: Use a temporary variable to swap values
    T c = a;
    a = b;
    b = c;
    return;
}

// Overload for pointers - swap what they point to
template <typename T>
void smartSwap(T *a, T *b)
{
    // TODO: Implement your solution here
    // Hint: Check for nullptr, then swap the dereferenced values
    if (a != nullptr && b != nullptr)
    {
        T c = *a;
        *a = *b;
        *b = c;
    }
    return;
}

// Overload for arrays - swap first and last elements
template <typename T>
void smartSwap(T arr[], int size)
{
    // TODO: Implement your solution here
    // Hint: Swap arr[0] and arr[size-1]
    if (size >= 2)
    {
        T temp = arr[0];
        arr[0] = arr[size - 1];
        arr[size - 1] = temp;
    }

    return;
}

// ============================================================================
// Problem 4: Hard - Generic Range Validator with Type-Specific Rules
// ============================================================================
// Description:
// Create a template function 'isInRange' that checks if a value is within range.
// Overload it with different validation rules:
// 1. Template version: Check if value is between min and max (inclusive)
// 2. Overload for double: Check range with tolerance (absolute difference)
// 3. Overload for char: Check if ASCII value is in range
// 4. Overload for string: Check if string length is in range
// 5. Overload for pointers: Check if dereferenced value is in range
//
// Input/Output Format:
// - Returns true if value meets range criteria, false otherwise
// - For double: tolerance parameter allows fuzzy matching at boundaries
// - For char: compares ASCII values
// - For string: compares length
// - For pointers: checks dereferenced value
//
// Example 1: isInRange(5, 1, 10) -> returns true
// Example 2: isInRange(10.001, 10.0, 20.0, 0.01) -> returns true (within tolerance)
// Example 3: isInRange('M', 'A', 'Z') -> returns true (ASCII 77 between 65-90)
// Example 4: isInRange(string("hello"), 3, 6) -> returns true (length 5)
// Example 5: int x=15; isInRange(&x, 10, 20) -> returns true
//
// Constraints:
// - min <= max for all versions
// - tolerance >= 0 for double version
// - For pointers, must not be nullptr

// Template version - basic range check
template <typename T>
bool isInRange(T value, T minVal, T maxVal)
{
    // TODO: Implement your solution here
    // Hint: Check if minVal <= value <= maxVal
    return 0;
}

// Overload for double with tolerance
bool isInRange(double value, double minVal, double maxVal, double tolerance)
{
    // TODO: Implement your solution here
    // Hint: Check if value is within [minVal-tolerance, maxVal+tolerance]
    return 0;
}

// Overload for char - check ASCII value range
bool isInRange(char value, char minVal, char maxVal)
{
    // TODO: Implement your solution here
    // Hint: Compare character ASCII values
    return 0;
}

// Overload for string - check length range
bool isInRange(const string &value, int minLen, int maxLen)
{
    // TODO: Implement your solution here
    // Hint: Get string length and check if it's within range
    return 0;
}

// Overload for pointers - check dereferenced value
template <typename T>
bool isInRange(T *value, T minVal, T maxVal)
{
    // TODO: Implement your solution here
    // Hint: Check for nullptr first, then check *value against range
    return 0;
}

// ============================================================================
// TEST FUNCTIONS
// ============================================================================

void testProblem1()
{
    cout << "\n========================================" << endl;
    cout << "Testing Problem 1: Maximum Finder" << endl;
    cout << "========================================" << endl;

    // Test Case 1: Integer comparison
    // Calculation: max(5, 10) = 10
    // Expected: 10
    cout << "Test 1 (int 5, 10): " << (maximum(5, 10) == 10 ? "PASS" : "FAIL") << endl;

    // Test Case 2: Integer comparison (first larger)
    // Calculation: max(20, 15) = 20
    // Expected: 20
    cout << "Test 2 (int 20, 15): " << (maximum(20, 15) == 20 ? "PASS" : "FAIL") << endl;

    // Test Case 3: Integer equal values
    // Calculation: max(7, 7) = 7 (either is fine, should return first)
    // Expected: 7
    cout << "Test 3 (int 7, 7): " << (maximum(7, 7) == 7 ? "PASS" : "FAIL") << endl;

    // Test Case 4: Double comparison
    // Calculation: max(3.14, 2.71) = 3.14
    // Expected: 3.14
    cout << "Test 4 (double 3.14, 2.71): " << (maximum(3.14, 2.71) == 3.14 ? "PASS" : "FAIL") << endl;

    // Test Case 5: Double comparison (second larger)
    // Calculation: max(1.5, 9.8) = 9.8
    // Expected: 9.8
    cout << "Test 5 (double 1.5, 9.8): " << (maximum(1.5, 9.8) == 9.8 ? "PASS" : "FAIL") << endl;

    // Test Case 6: C-string by length (second longer)
    // Calculation: strlen("cat")=3, strlen("elephant")=8, return "elephant"
    // Expected: "elephant"
    const char *result6 = maximum("cat", "elephant");
    cout << "Test 6 (C-string 'cat', 'elephant'): " << (string(result6) == "elephant" ? "PASS" : "FAIL") << endl;

    // Test Case 7: C-string by length (first longer)
    // Calculation: strlen("programming")=11, strlen("code")=4, return "programming"
    // Expected: "programming"
    const char *result7 = maximum("programming", "code");
    cout << "Test 7 (C-string 'programming', 'code'): " << (string(result7) == "programming" ? "PASS" : "FAIL") << endl;

    // Test Case 8: C-string equal length (return first)
    // Calculation: strlen("dog")=3, strlen("cat")=3, return "dog"
    // Expected: "dog"
    const char *result8 = maximum("dog", "cat");
    cout << "Test 8 (C-string 'dog', 'cat'): " << (string(result8) == "dog" ? "PASS" : "FAIL") << endl;

    // Test Case 9: std::string alphabetical (second later)
    // Calculation: "apple" < "banana" alphabetically, return "banana"
    // Expected: "banana"
    string result9 = maximum(string("apple"), string("banana"));
    cout << "Test 9 (string 'apple', 'banana'): " << (result9 == "banana" ? "PASS" : "FAIL") << endl;

    // Test Case 10: std::string alphabetical (first later)
    // Calculation: "zebra" > "apple" alphabetically, return "zebra"
    // Expected: "zebra"
    string result10 = maximum(string("zebra"), string("apple"));
    cout << "Test 10 (string 'zebra', 'apple'): " << (result10 == "zebra" ? "PASS" : "FAIL") << endl;
}

void testProblem2()
{
    cout << "\n========================================" << endl;
    cout << "Testing Problem 2: Array Sum Calculator" << endl;
    cout << "========================================" << endl;

    // Test Case 1: Integer array sum
    // Calculation: 1 + 2 + 3 + 4 + 5 = 15
    // Expected: 15
    int arr1[] = {1, 2, 3, 4, 5};
    cout << "Test 1 (int array {1,2,3,4,5}): " << (arraySum(arr1, 5) == 15 ? "PASS" : "FAIL") << endl;

    // Test Case 2: Integer array with negative
    // Calculation: 10 + (-5) + 3 + (-2) = 6
    // Expected: 6
    int arr2[] = {10, -5, 3, -2};
    cout << "Test 2 (int array {10,-5,3,-2}): " << (arraySum(arr2, 4) == 6 ? "PASS" : "FAIL") << endl;

    // Test Case 3: Integer single element
    // Calculation: 42
    // Expected: 42
    int arr3[] = {42};
    cout << "Test 3 (int array {42}): " << (arraySum(arr3, 1) == 42 ? "PASS" : "FAIL") << endl;

    // Test Case 4: Integer empty array
    // Calculation: 0 (no elements)
    // Expected: 0
    int arr4[] = {};
    cout << "Test 4 (int empty array): " << (arraySum(arr4, 0) == 0 ? "PASS" : "FAIL") << endl;

    // Test Case 5: Double array sum
    // Calculation: 1.5 + 2.5 + 3.0 = 7.0
    // Expected: 7.0
    double arr5[] = {1.5, 2.5, 3.0};
    cout << "Test 5 (double array {1.5,2.5,3.0}): " << (arraySum(arr5, 3) == 7.0 ? "PASS" : "FAIL") << endl;

    // Test Case 6: Double array with precision
    // Calculation: 0.1 + 0.2 + 0.3 = 0.6
    // Expected: 0.6 (with floating point tolerance)
    double arr6[] = {0.1, 0.2, 0.3};
    double sum6 = arraySum(arr6, 3);
    cout << "Test 6 (double array {0.1,0.2,0.3}): " << (abs(sum6 - 0.6) < 0.0001 ? "PASS" : "FAIL") << endl;

    // Test Case 7: Char array ASCII sum
    // Calculation: 'A'=65, 'B'=66, 'C'=67, sum = 65+66+67 = 198
    // Expected: 198
    char arr7[] = {'A', 'B', 'C'};
    cout << "Test 7 (char array {'A','B','C'}): " << (arraySum(arr7, 3) == 198 ? "PASS" : "FAIL") << endl;

    // Test Case 8: Char array with lowercase
    // Calculation: 'a'=97, 'b'=98, sum = 97+98 = 195
    // Expected: 195
    char arr8[] = {'a', 'b'};
    cout << "Test 8 (char array {'a','b'}): " << (arraySum(arr8, 2) == 195 ? "PASS" : "FAIL") << endl;

    // Test Case 9: Bool array count true
    // Calculation: true, false, true, true = 3 trues
    // Expected: 3
    bool arr9[] = {true, false, true, true};
    cout << "Test 9 (bool array {T,F,T,T}): " << (arraySum(arr9, 4) == 3 ? "PASS" : "FAIL") << endl;

    // Test Case 10: Bool array all false
    // Calculation: false, false, false = 0 trues
    // Expected: 0
    bool arr10[] = {false, false, false};
    cout << "Test 10 (bool array {F,F,F}): " << (arraySum(arr10, 3) == 0 ? "PASS" : "FAIL") << endl;
}

void testProblem3()
{
    cout << "\n========================================" << endl;
    cout << "Testing Problem 3: Smart Swap Function" << endl;
    cout << "========================================" << endl;

    // Test Case 1: Regular int swap
    // Initial: a=5, b=10
    // After swap: a=10, b=5
    int a1 = 5, b1 = 10;
    smartSwap(a1, b1);
    cout << "Test 1 (int swap 5,10): " << (a1 == 10 && b1 == 5 ? "PASS" : "FAIL") << endl;

    // Test Case 2: Regular double swap
    // Initial: a=3.14, b=2.71
    // After swap: a=2.71, b=3.14
    double a2 = 3.14, b2 = 2.71;
    smartSwap(a2, b2);
    cout << "Test 2 (double swap 3.14,2.71): " << (a2 == 2.71 && b2 == 3.14 ? "PASS" : "FAIL") << endl;

    // Test Case 3: Regular char swap
    // Initial: a='X', b='Y'
    // After swap: a='Y', b='X'
    char a3 = 'X', b3 = 'Y';
    smartSwap(a3, b3);
    cout << "Test 3 (char swap 'X','Y'): " << (a3 == 'Y' && b3 == 'X' ? "PASS" : "FAIL") << endl;

    // Test Case 4: Pointer swap (swap what they point to)
    // Initial: x=1, y=2, p1->x, p2->y
    // After swap: x=2, y=1 (values swapped, not pointers)
    int x4 = 1, y4 = 2;
    int *p4_1 = &x4;
    int *p4_2 = &y4;
    smartSwap(p4_1, p4_2);
    cout << "Test 4 (pointer swap): " << (x4 == 2 && y4 == 1 ? "PASS" : "FAIL") << endl;

    // Test Case 5: Pointer swap with different values
    // Initial: x=100, y=200, p1->x, p2->y
    // After swap: x=200, y=100
    int x5 = 100, y5 = 200;
    int *p5_1 = &x5;
    int *p5_2 = &y5;
    smartSwap(p5_1, p5_2);
    cout << "Test 5 (pointer swap 100,200): " << (x5 == 200 && y5 == 100 ? "PASS" : "FAIL") << endl;

    // Test Case 6: Array swap first and last
    // Initial: {1, 2, 3, 4, 5}
    // After swap: {5, 2, 3, 4, 1}
    int arr6[] = {1, 2, 3, 4, 5};
    smartSwap(arr6, 5);
    cout << "Test 6 (array {1,2,3,4,5}): " << (arr6[0] == 5 && arr6[4] == 1 && arr6[2] == 3 ? "PASS" : "FAIL") << endl;

    // Test Case 7: Array swap with 2 elements
    // Initial: {10, 20}
    // After swap: {20, 10}
    int arr7[] = {10, 20};
    smartSwap(arr7, 2);
    cout << "Test 7 (array {10,20}): " << (arr7[0] == 20 && arr7[1] == 10 ? "PASS" : "FAIL") << endl;

    // Test Case 8: Array swap with even elements
    // Initial: {7, 8, 9, 10}
    // After swap: {10, 8, 9, 7}
    int arr8[] = {7, 8, 9, 10};
    smartSwap(arr8, 4);
    cout << "Test 8 (array {7,8,9,10}): " << (arr8[0] == 10 && arr8[3] == 7 && arr8[1] == 8 ? "PASS" : "FAIL") << endl;

    // Test Case 9: Double array swap
    // Initial: {1.1, 2.2, 3.3}
    // After swap: {3.3, 2.2, 1.1}
    double arr9[] = {1.1, 2.2, 3.3};
    smartSwap(arr9, 3);
    cout << "Test 9 (double array {1.1,2.2,3.3}): " << (arr9[0] == 3.3 && arr9[2] == 1.1 ? "PASS" : "FAIL") << endl;

    // Test Case 10: Char array swap
    // Initial: {'A', 'B', 'C', 'D'}
    // After swap: {'D', 'B', 'C', 'A'}
    char arr10[] = {'A', 'B', 'C', 'D'};
    smartSwap(arr10, 4);
    cout << "Test 10 (char array {'A','B','C','D'}): " << (arr10[0] == 'D' && arr10[3] == 'A' ? "PASS" : "FAIL") << endl;
}

void testProblem4()
{
    cout << "\n========================================" << endl;
    cout << "Testing Problem 4: Range Validator" << endl;
    cout << "========================================" << endl;

    // Test Case 1: Integer in range
    // Check: 5 in [1, 10] = true
    // Expected: true
    cout << "Test 1 (int 5 in [1,10]): " << (isInRange(5, 1, 10) ? "PASS" : "FAIL") << endl;

    // Test Case 2: Integer at lower boundary
    // Check: 1 in [1, 10] = true
    // Expected: true
    cout << "Test 2 (int 1 in [1,10]): " << (isInRange(1, 1, 10) ? "PASS" : "FAIL") << endl;

    // Test Case 3: Integer at upper boundary
    // Check: 10 in [1, 10] = true
    // Expected: true
    cout << "Test 3 (int 10 in [1,10]): " << (isInRange(10, 1, 10) ? "PASS" : "FAIL") << endl;

    // Test Case 4: Integer out of range (below)
    // Check: 0 in [1, 10] = false
    // Expected: false
    cout << "Test 4 (int 0 in [1,10]): " << (!isInRange(0, 1, 10) ? "PASS" : "FAIL") << endl;

    // Test Case 5: Integer out of range (above)
    // Check: 15 in [1, 10] = false
    // Expected: false
    cout << "Test 5 (int 15 in [1,10]): " << (!isInRange(15, 1, 10) ? "PASS" : "FAIL") << endl;

    // Test Case 6: Double with tolerance (within range)
    // Check: 10.001 in [10.0, 20.0] with tolerance 0.01
    // 10.001 is within [10.0-0.01, 20.0+0.01] = [9.99, 20.01] = true
    // Expected: true
    cout << "Test 6 (double 10.001 in [10,20] tol 0.01): " << (isInRange(10.001, 10.0, 20.0, 0.01) ? "PASS" : "FAIL") << endl;

    // Test Case 7: Double with tolerance (at boundary with tolerance)
    // Check: 9.995 in [10.0, 20.0] with tolerance 0.01
    // 9.995 is within [10.0-0.01, 20.0+0.01] = [9.99, 20.01] = true
    // Expected: true
    cout << "Test 7 (double 9.995 in [10,20] tol 0.01): " << (isInRange(9.995, 10.0, 20.0, 0.01) ? "PASS" : "FAIL") << endl;

    // Test Case 8: Double with tolerance (outside tolerance)
    // Check: 9.9 in [10.0, 20.0] with tolerance 0.01
    // 9.9 is NOT within [9.99, 20.01] = false
    // Expected: false
    cout << "Test 8 (double 9.9 in [10,20] tol 0.01): " << (!isInRange(9.9, 10.0, 20.0, 0.01) ? "PASS" : "FAIL") << endl;

    // Test Case 9: Char ASCII in range
    // Check: 'M' (ASCII 77) in ['A' (65), 'Z' (90)] = true
    // Expected: true
    cout << "Test 9 (char 'M' in ['A','Z']): " << (isInRange('M', 'A', 'Z') ? "PASS" : "FAIL") << endl;

    // Test Case 10: Char ASCII at boundary
    // Check: 'A' (ASCII 65) in ['A' (65), 'Z' (90)] = true
    // Expected: true
    cout << "Test 10 (char 'A' in ['A','Z']): " << (isInRange('A', 'A', 'Z') ? "PASS" : "FAIL") << endl;

    // Test Case 11: Char ASCII out of range
    // Check: 'a' (ASCII 97) in ['A' (65), 'Z' (90)] = false
    // Expected: false
    cout << "Test 11 (char 'a' in ['A','Z']): " << (!isInRange('a', 'A', 'Z') ? "PASS" : "FAIL") << endl;

    // Test Case 12: String length in range
    // Check: "hello" (length 5) in [3, 6] = true
    // Expected: true
    cout << "Test 12 (string 'hello' len [3,6]): " << (isInRange(string("hello"), 3, 6) ? "PASS" : "FAIL") << endl;

    // Test Case 13: String length at boundary
    // Check: "hi" (length 2) in [2, 5] = true
    // Expected: true
    cout << "Test 13 (string 'hi' len [2,5]): " << (isInRange(string("hi"), 2, 5) ? "PASS" : "FAIL") << endl;

    // Test Case 14: String length out of range
    // Check: "programming" (length 11) in [3, 6] = false
    // Expected: false
    cout << "Test 14 (string 'programming' len [3,6]): " << (!isInRange(string("programming"), 3, 6) ? "PASS" : "FAIL") << endl;

    // Test Case 15: Pointer in range
    // Check: *ptr (value 15) in [10, 20] = true
    // Expected: true
    int val15 = 15;
    int *ptr15 = &val15;
    cout << "Test 15 (pointer to 15 in [10,20]): " << (isInRange(ptr15, 10, 20) ? "PASS" : "FAIL") << endl;

    // Test Case 16: Pointer out of range
    // Check: *ptr (value 5) in [10, 20] = false
    // Expected: false
    int val16 = 5;
    int *ptr16 = &val16;
    cout << "Test 16 (pointer to 5 in [10,20]): " << (!isInRange(ptr16, 10, 20) ? "PASS" : "FAIL") << endl;
}

// ============================================================================
// MAIN FUNCTION
// ============================================================================

int main()
{
    int choice;
    cout << "========================================" << endl;
    cout << "Function Templates With Overloading Practice" << endl;
    cout << "========================================" << endl;
    cout << "Choose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy) - Maximum Finder" << endl;
    cout << "2. Problem 2 (Easy) - Array Sum Calculator" << endl;
    cout << "3. Problem 3 (Medium) - Smart Swap Function" << endl;
    cout << "4. Problem 4 (Hard) - Range Validator" << endl;
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
        cout << "\n==================================================" << endl;
        cout << "            All Tests Completed!                  " << endl;
        cout << "==================================================" << endl;
        break;
    default:
        cout << "Invalid choice!" << endl;
    }

    return 0;
}