    #include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Problem 1: Easy 1 - Basic Pointer Declaration and Value Access
// Given an integer variable, declare a pointer to it, and return the value accessed through the pointer.
// This problem focuses on basic pointer syntax: declaring pointers, assigning addresses, and dereferencing.
//
// Input Format: An integer value
// Output Format: The same integer value accessed through a pointer
//
// Example 1:
// Input: 42
// Output: 42 (accessed via pointer)
//
// Example 2:
// Input: -15
// Output: -15 (accessed via pointer)
//
// Constraints: -1000 ≤ input ≤ 1000
int problem1Solution(int value) {
    // TODO: Implement your solution here using pointer declaration and dereferencing
    // Hint: Declare a pointer, assign the address of value to it, then dereference to get the value
    int* p_value = &value;
    return *p_value;
}

// Problem 2: Easy 2 - Pointer Arithmetic and Array Access
// Given an array of integers and an index, use pointer arithmetic to access the element at that index.
// This builds on basic pointers by introducing pointer arithmetic concepts.
//
// Input Format: An array of integers, array size, and target index
// Output Format: The value at the specified index accessed using pointer arithmetic
//
// Example 1:
// Array: [10, 20, 30, 40, 50], Index: 2
// Output: 30 (arr_ptr + 2 points to third element)
//
// Example 2:
// Array: [1, 3, 5, 7], Index: 0
// Output: 1 (arr_ptr + 0 points to first element)
//
// Constraints: 0 ≤ index < array_size, 1 ≤ array_size ≤ 100
int problem2Solution(int arr[], int size, int index) {
    // TODO: Implement your solution here using pointer arithmetic
    // Hint: Use a pointer to the first element and add the index to access the target element
    int* p_arr = &arr[0] ;
    p_arr += index;
    return *p_arr;
}

// Problem 3: Medium - Swap Two Values Using Pointers
// Implement a function that swaps two integer values using pointers.
// The function should modify the original variables passed to it.
//
// Input Format: Two integer values to be swapped
// Output Format: Print both values before and after swapping
//
// Example 1:
// Input: a = 5, b = 10
// Before swap: a = 5, b = 10
// After swap: a = 10, b = 5
//
// Example 2:
// Input: a = -3, b = 7
// Before swap: a = -3, b = 7
// After swap: a = 7, b = -3
//
// Constraints: -1000 ≤ values ≤ 1000
void problem3Solution(int* a, int* b) {
    // TODO: Implement your solution here using pointers to swap values
    // Hint: Use a temporary variable and dereference the pointers to access and modify values
    int s = *a ;
    *a = *b;
    *b = s;
}

// Problem 4: Hard - Find Maximum Element Using Pointers
// Given an array of integers, find the maximum element and return a pointer to it.
// Also, calculate how many elements from the beginning of the array this maximum element is located.
//
// Input Format: An array of integers and its size
// Output Format: Return pointer to maximum element, and print its position (0-based index)
//
// Example 1:
// Array: [3, 7, 2, 9, 1], Size: 5
// Maximum element: 9 at position 3
// Return: pointer to the element containing 9
//
// Example 2:
// Array: [15, 8, 23, 4], Size: 4
// Maximum element: 23 at position 2
// Return: pointer to the element containing 23
//
// Constraints: 1 ≤ size ≤ 100, -1000 ≤ array elements ≤ 1000
int* problem4Solution(int arr[], int size, int& position) {
    // TODO: Implement your solution here using pointers to find maximum element
    // Hint: Use pointer arithmetic to traverse array and keep track of maximum element's address
    int* p_value {nullptr};
    int max  {INT_MIN} ;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            p_value = &arr[i];
            position = i;
        }
        
    }
    return p_value;
}

void testProblem1() {
    cout << "Testing Problem 1: Basic Pointer Declaration and Value Access..." << endl;
    
    // Test Case 1: Positive integer
    // Input: 42, Expected output: 42
    // Calculation: Simple value access through pointer dereference
    cout << "Test 1: " << (problem1Solution(42) == 42 ? "PASS" : "FAIL") << " - Input: 42, Expected: 42" << endl;

    // Test Case 2: Negative integer
    // Input: -15, Expected output: -15
    // Calculation: Simple value access through pointer dereference
    cout << "Test 2: " << (problem1Solution(-15) == -15 ? "PASS" : "FAIL") << " - Input: -15, Expected: -15" << endl;

    // Test Case 3: Zero
    // Input: 0, Expected output: 0
    // Calculation: Simple value access through pointer dereference
    cout << "Test 3: " << (problem1Solution(0) == 0 ? "PASS" : "FAIL") << " - Input: 0, Expected: 0" << endl;

    // Test Case 4: Large positive number
    // Input: 999, Expected output: 999
    // Calculation: Simple value access through pointer dereference
    cout << "Test 4: " << (problem1Solution(999) == 999 ? "PASS" : "FAIL") << " - Input: 999, Expected: 999" << endl;

    // Test Case 5: Large negative number
    // Input: -500, Expected output: -500
    // Calculation: Simple value access through pointer dereference
    cout << "Test 5: " << (problem1Solution(-500) == -500 ? "PASS" : "FAIL") << " - Input: -500, Expected: -500" << endl;

    // Test Case 6: Single digit
    // Input: 7, Expected output: 7
    // Calculation: Simple value access through pointer dereference
    cout << "Test 6: " << (problem1Solution(7) == 7 ? "PASS" : "FAIL") << " - Input: 7, Expected: 7" << endl;

    // Test Case 7: Boundary value
    // Input: -1000, Expected output: -1000
    // Calculation: Simple value access through pointer dereference (minimum constraint)
    cout << "Test 7: " << (problem1Solution(-1000) == -1000 ? "PASS" : "FAIL") << " - Input: -1000, Expected: -1000" << endl;

    // Test Case 8: Boundary value
    // Input: 1000, Expected output: 1000
    // Calculation: Simple value access through pointer dereference (maximum constraint)
    cout << "Test 8: " << (problem1Solution(1000) == 1000 ? "PASS" : "FAIL") << " - Input: 1000, Expected: 1000" << endl;

    cout << endl;
}

void testProblem2() {
    cout << "Testing Problem 2: Pointer Arithmetic and Array Access..." << endl;
    
    // Test Case 1: Access middle element
    // Array: [10, 20, 30, 40, 50], Index: 2
    // Calculation: arr_ptr + 2 points to arr[2] = 30
    int arr1[] = {10, 20, 30, 40, 50};
    cout << "Test 1: " << (problem2Solution(arr1, 5, 2) == 30 ? "PASS" : "FAIL") << " - Array: [10,20,30,40,50], Index: 2, Expected: 30" << endl;

    // Test Case 2: Access first element
    // Array: [1, 3, 5, 7], Index: 0
    // Calculation: arr_ptr + 0 points to arr[0] = 1
    int arr2[] = {1, 3, 5, 7};
    cout << "Test 2: " << (problem2Solution(arr2, 4, 0) == 1 ? "PASS" : "FAIL") << " - Array: [1,3,5,7], Index: 0, Expected: 1" << endl;

    // Test Case 3: Access last element
    // Array: [100, 200, 300], Index: 2
    // Calculation: arr_ptr + 2 points to arr[2] = 300
    int arr3[] = {100, 200, 300};
    cout << "Test 3: " << (problem2Solution(arr3, 3, 2) == 300 ? "PASS" : "FAIL") << " - Array: [100,200,300], Index: 2, Expected: 300" << endl;

    // Test Case 4: Single element array
    // Array: [42], Index: 0
    // Calculation: arr_ptr + 0 points to arr[0] = 42
    int arr4[] = {42};
    cout << "Test 4: " << (problem2Solution(arr4, 1, 0) == 42 ? "PASS" : "FAIL") << " - Array: [42], Index: 0, Expected: 42" << endl;

    // Test Case 5: Array with negative numbers
    // Array: [-5, -10, -15, -20], Index: 1
    // Calculation: arr_ptr + 1 points to arr[1] = -10
    int arr5[] = {-5, -10, -15, -20};
    cout << "Test 5: " << (problem2Solution(arr5, 4, 1) == -10 ? "PASS" : "FAIL") << " - Array: [-5,-10,-15,-20], Index: 1, Expected: -10" << endl;

    // Test Case 6: Mixed positive/negative numbers
    // Array: [0, -1, 2, -3, 4], Index: 3
    // Calculation: arr_ptr + 3 points to arr[3] = -3
    int arr6[] = {0, -1, 2, -3, 4};
    cout << "Test 6: " << (problem2Solution(arr6, 5, 3) == -3 ? "PASS" : "FAIL") << " - Array: [0,-1,2,-3,4], Index: 3, Expected: -3" << endl;

    // Test Case 7: Large array, access middle
    // Array: [11, 22, 33, 44, 55, 66, 77], Index: 3
    // Calculation: arr_ptr + 3 points to arr[3] = 44
    int arr7[] = {11, 22, 33, 44, 55, 66, 77};
    cout << "Test 7: " << (problem2Solution(arr7, 7, 3) == 44 ? "PASS" : "FAIL") << " - Array: [11,22,33,44,55,66,77], Index: 3, Expected: 44" << endl;

    // Test Case 8: Array with zeros
    // Array: [0, 0, 5, 0], Index: 2
    // Calculation: arr_ptr + 2 points to arr[2] = 5
    int arr8[] = {0, 0, 5, 0};
    cout << "Test 8: " << (problem2Solution(arr8, 4, 2) == 5 ? "PASS" : "FAIL") << " - Array: [0,0,5,0], Index: 2, Expected: 5" << endl;

    cout << endl;
}

void testProblem3() {
    cout << "Testing Problem 3: Swap Two Values Using Pointers..." << endl;
    
    // Test Case 1: Positive integers
    // Before: a = 5, b = 10
    // After swap: a should be 10, b should be 5
    cout << "Test 1: ";
    int a1 = 5, b1 = 10;
    cout << "Before swap: a = " << a1 << ", b = " << b1 << " -> ";
    problem3Solution(&a1, &b1);
    cout << "After swap: a = " << a1 << ", b = " << b1;
    cout << (a1 == 10 && b1 == 5 ? " [PASS]" : " [FAIL]") << endl;

    // Test Case 2: Negative and positive
    // Before: a = -3, b = 7
    // After swap: a should be 7, b should be -3
    cout << "Test 2: ";
    int a2 = -3, b2 = 7;
    cout << "Before swap: a = " << a2 << ", b = " << b2 << " -> ";
    problem3Solution(&a2, &b2);
    cout << "After swap: a = " << a2 << ", b = " << b2;
    cout << (a2 == 7 && b2 == -3 ? " [PASS]" : " [FAIL]") << endl;

    // Test Case 3: Both negative
    // Before: a = -15, b = -25
    // After swap: a should be -25, b should be -15
    cout << "Test 3: ";
    int a3 = -15, b3 = -25;
    cout << "Before swap: a = " << a3 << ", b = " << b3 << " -> ";
    problem3Solution(&a3, &b3);
    cout << "After swap: a = " << a3 << ", b = " << b3;
    cout << (a3 == -25 && b3 == -15 ? " [PASS]" : " [FAIL]") << endl;

    // Test Case 4: One zero
    // Before: a = 0, b = 100
    // After swap: a should be 100, b should be 0
    cout << "Test 4: ";
    int a4 = 0, b4 = 100;
    cout << "Before swap: a = " << a4 << ", b = " << b4 << " -> ";
    problem3Solution(&a4, &b4);
    cout << "After swap: a = " << a4 << ", b = " << b4;
    cout << (a4 == 100 && b4 == 0 ? " [PASS]" : " [FAIL]") << endl;

    // Test Case 5: Both zero
    // Before: a = 0, b = 0
    // After swap: a should be 0, b should be 0
    cout << "Test 5: ";
    int a5 = 0, b5 = 0;
    cout << "Before swap: a = " << a5 << ", b = " << b5 << " -> ";
    problem3Solution(&a5, &b5);
    cout << "After swap: a = " << a5 << ", b = " << b5;
    cout << (a5 == 0 && b5 == 0 ? " [PASS]" : " [FAIL]") << endl;

    // Test Case 6: Same values
    // Before: a = 50, b = 50
    // After swap: a should be 50, b should be 50
    cout << "Test 6: ";
    int a6 = 50, b6 = 50;
    cout << "Before swap: a = " << a6 << ", b = " << b6 << " -> ";
    problem3Solution(&a6, &b6);
    cout << "After swap: a = " << a6 << ", b = " << b6;
    cout << (a6 == 50 && b6 == 50 ? " [PASS]" : " [FAIL]") << endl;

    // Test Case 7: Large numbers
    // Before: a = 999, b = -999
    // After swap: a should be -999, b should be 999
    cout << "Test 7: ";
    int a7 = 999, b7 = -999;
    cout << "Before swap: a = " << a7 << ", b = " << b7 << " -> ";
    problem3Solution(&a7, &b7);
    cout << "After swap: a = " << a7 << ", b = " << b7;
    cout << (a7 == -999 && b7 == 999 ? " [PASS]" : " [FAIL]") << endl;

    // Test Case 8: Single digits
    // Before: a = 1, b = 9
    // After swap: a should be 9, b should be 1
    cout << "Test 8: ";
    int a8 = 1, b8 = 9;
    cout << "Before swap: a = " << a8 << ", b = " << b8 << " -> ";
    problem3Solution(&a8, &b8);
    cout << "After swap: a = " << a8 << ", b = " << b8;
    cout << (a8 == 9 && b8 == 1 ? " [PASS]" : " [FAIL]") << endl;

    cout << endl;
}

void testProblem4() {
    cout << "Testing Problem 4: Find Maximum Element Using Pointers..." << endl;
    
    // Test Case 1: Maximum in middle
    // Array: [3, 7, 2, 9, 1], Size: 5
    // Maximum element: 9 at position 3
    cout << "Test 1: ";
    int arr1[] = {3, 7, 2, 9, 1};
    int pos1;
    int* result1 = problem4Solution(arr1, 5, pos1);
    cout << "Array: [3,7,2,9,1] -> Max: " << (result1 ? *result1 : -999) << " at position " << pos1;
    cout << (result1 && *result1 == 9 && pos1 == 3 ? " [PASS]" : " [FAIL]") << endl;

    // Test Case 2: Maximum at end
    // Array: [15, 8, 4, 23], Size: 4
    // Maximum element: 23 at position 3
    cout << "Test 2: ";
    int arr2[] = {15, 8, 4, 23};
    int pos2;
    int* result2 = problem4Solution(arr2, 4, pos2);
    cout << "Array: [15,8,4,23] -> Max: " << (result2 ? *result2 : -999) << " at position " << pos2;
    cout << (result2 && *result2 == 23 && pos2 == 3 ? " [PASS]" : " [FAIL]") << endl;

    // Test Case 3: Maximum at beginning
    // Array: [50, 10, 20, 30], Size: 4
    // Maximum element: 50 at position 0
    cout << "Test 3: ";
    int arr3[] = {50, 10, 20, 30};
    int pos3;
    int* result3 = problem4Solution(arr3, 4, pos3);
    cout << "Array: [50,10,20,30] -> Max: " << (result3 ? *result3 : -999) << " at position " << pos3;
    cout << (result3 && *result3 == 50 && pos3 == 0 ? " [PASS]" : " [FAIL]") << endl;

    // Test Case 4: Single element
    // Array: [42], Size: 1
    // Maximum element: 42 at position 0
    cout << "Test 4: ";
    int arr4[] = {42};
    int pos4;
    int* result4 = problem4Solution(arr4, 1, pos4);
    cout << "Array: [42] -> Max: " << (result4 ? *result4 : -999) << " at position " << pos4;
    cout << (result4 && *result4 == 42 && pos4 == 0 ? " [PASS]" : " [FAIL]") << endl;

    // Test Case 5: All negative numbers
    // Array: [-5, -2, -8, -1], Size: 4
    // Maximum element: -1 at position 3
    cout << "Test 5: ";
    int arr5[] = {-5, -2, -8, -1};
    int pos5;
    int* result5 = problem4Solution(arr5, 4, pos5);
    cout << "Array: [-5,-2,-8,-1] -> Max: " << (result5 ? *result5 : -999) << " at position " << pos5;
    cout << (result5 && *result5 == -1 && pos5 == 3 ? " [PASS]" : " [FAIL]") << endl;

    // Test Case 6: Duplicate maximum values (first occurrence)
    // Array: [10, 20, 20, 5], Size: 4
    // Maximum element: 20 at position 1 (first occurrence)
    cout << "Test 6: ";
    int arr6[] = {10, 20, 20, 5};
    int pos6;
    int* result6 = problem4Solution(arr6, 4, pos6);
    cout << "Array: [10,20,20,5] -> Max: " << (result6 ? *result6 : -999) << " at position " << pos6;
    cout << (result6 && *result6 == 20 && pos6 == 1 ? " [PASS]" : " [FAIL]") << endl;

    // Test Case 7: Mixed positive and negative
    // Array: [-10, 5, -3, 0, 15, -7], Size: 6
    // Maximum element: 15 at position 4
    cout << "Test 7: ";
    int arr7[] = {-10, 5, -3, 0, 15, -7};
    int pos7;
    int* result7 = problem4Solution(arr7, 6, pos7);
    cout << "Array: [-10,5,-3,0,15,-7] -> Max: " << (result7 ? *result7 : -999) << " at position " << pos7;
    cout << (result7 && *result7 == 15 && pos7 == 4 ? " [PASS]" : " [FAIL]") << endl;

    // Test Case 8: All same values
    // Array: [7, 7, 7], Size: 3
    // Maximum element: 7 at position 0 (first occurrence)
    cout << "Test 8: ";
    int arr8[] = {7, 7, 7};
    int pos8;
    int* result8 = problem4Solution(arr8, 3, pos8);
    cout << "Array: [7,7,7] -> Max: " << (result8 ? *result8 : -999) << " at position " << pos8;
    cout << (result8 && *result8 == 7 && pos8 == 0 ? " [PASS]" : " [FAIL]") << endl;

    cout << endl;
}

int main() {
    int choice;
    cout << "=== C++ Pointers Practice Problems ===" << endl;
    cout << "Choose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy) - Basic Pointer Declaration and Value Access" << endl;
    cout << "2. Problem 2 (Easy-Medium) - Pointer Arithmetic and Array Access" << endl;
    cout << "3. Problem 3 (Medium) - Swap Two Values Using Pointers" << endl;
    cout << "4. Problem 4 (Hard) - Find Maximum Element Using Pointers" << endl;
    cout << "5. Test All Problems" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;

    switch(choice) {
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
            cout << "Running all tests..." << endl << endl;
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