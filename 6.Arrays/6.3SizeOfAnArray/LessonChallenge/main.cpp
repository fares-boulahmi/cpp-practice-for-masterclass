#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

// Problem 1: Easy 1 - Array Size Calculator
// Write a function that takes an array and returns its size.
// You need to determine the size of different types of arrays.
// Input: An integer array (passed by reference)
// Output: The number of elements in the array
// Example 1: array = {1, 2, 3, 4, 5} → output = 5
// Example 2: array = {10, 20} → output = 2
// Example 3: array = {7} → output = 1
// Constraints: 1 ≤ array size ≤ 100
int problem1Solution(int arr[], int actualSize) {
    // TODO: Implement your solution here using sizeof() or parameter
    // Hint: Remember that sizeof(arr) won't work for array parameters - use the actualSize parameter
    return actualSize;
}

// Problem 2: Easy 2 - Valid Index Checker
// Write a function that checks if a given index is valid for an array of given size.
// An index is valid if it's >= 0 and < array_size
// Input: array_size (int), index (int)
// Output: true if index is valid, false otherwise
// Example 1: array_size = 5, index = 2 → output = true (valid)
// Example 2: array_size = 5, index = 5 → output = false (out of bounds)
// Example 3: array_size = 3, index = -1 → output = false (negative)
// Example 4: array_size = 1, index = 0 → output = true (edge case)
// Constraints: 1 ≤ array_size ≤ 1000, -100 ≤ index ≤ 1000
bool problem2Solution(int array_size, int index) {
    // TODO: Implement your solution here using array size bounds checking
    // Hint: Check if index is within the range [0, array_size-1]
    return (index >= 0 && index < array_size ) ? true : false ;
}

// Problem 3: Medium - Array Resize Simulator
// Simulate dynamic array resizing. Given an initial array size and a series of operations,
// calculate the final array size. Operations: 'A' (add element), 'R' (remove element)
// Input: initial_size (int), operations (string of 'A' and 'R' characters)
// Output: final array size after all operations
// Example 1: initial_size = 3, operations = "AAR" → 3+2-1 = 4
// Example 2: initial_size = 5, operations = "RRAA" → 5-2+2 = 5
// Example 3: initial_size = 1, operations = "RAAA" → max(1-1, 0)+3 = 3
// Note: Array size cannot go below 0
// Constraints: 1 ≤ initial_size ≤ 100, 1 ≤ operations.length ≤ 50
int problem3Solution(int initial_size, string operations) {
    // TODO: Implement your solution here using array size tracking
    // Hint: Process each operation and update size, ensure size never goes below 0
    for (size_t i = 0; i < operations.size() ; i++)
    {
        if (operations[i] == 'A')
        {
            initial_size++;
        } else if (operations[i] == 'R')
        {
            initial_size--;
        } 
        
    }
    
    return initial_size;
}

// Problem 4: Hard - Multi-Array Size Analyzer
// Given multiple arrays represented as their sizes, find how many pairs of arrays
// have the property that one array's size is exactly double the other's size.
// Input: array_sizes (array of integers representing different array sizes)
// Input: num_arrays (number of arrays)
// Output: count of pairs where one size is exactly double of another
// Example 1: sizes = {2, 4, 8, 16} → pairs: (2,4), (4,8), (8,16) = 3 pairs
// Example 2: sizes = {1, 3, 5, 10} → pairs: (5,10) = 1 pair
// Example 3: sizes = {2, 6, 12, 3} → pairs: (3,6), (6,12) = 2 pairs
// Constraints: 2 ≤ num_arrays ≤ 20, 1 ≤ array_sizes[i] ≤ 1000
int problem4Solution(int array_sizes[], int num_arrays) {
    // TODO: Implement your solution here using array size comparison
    // Hint: For each pair, check if one size is exactly double the other (or half)
    int pairs {};
    for (size_t i = 0; i < num_arrays ; i++)
    {
        for (size_t j = i + 1 ; j < num_arrays ; j++)
        {
            if ((array_sizes[i] * 2) == array_sizes[j])
            {
             pairs++;
            }
        }
        
       
    }
    return pairs;
}

void testProblem1() {
    cout << "Testing Problem 1: Array Size Calculator..." << endl;
    // MANUALLY VERIFIED TEST CASES:

    // Test Case 1: Regular array with 5 elements
    // Expected: 5 (straightforward count)
    int test1[] = {1, 2, 3, 4, 5};
    cout << "Test 1: " << (problem1Solution(test1, 5) == 5 ? "PASS" : "FAIL") << " - Expected: 5" << endl;

    // Test Case 2: Array with 2 elements
    // Expected: 2 (straightforward count)
    int test2[] = {10, 20};
    cout << "Test 2: " << (problem1Solution(test2, 2) == 2 ? "PASS" : "FAIL") << " - Expected: 2" << endl;

    // Test Case 3: Single element array
    // Expected: 1 (minimum valid size)
    int test3[] = {7};
    cout << "Test 3: " << (problem1Solution(test3, 1) == 1 ? "PASS" : "FAIL") << " - Expected: 1" << endl;

    // Test Case 4: Larger array with 10 elements
    // Expected: 10 (straightforward count)
    int test4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Test 4: " << (problem1Solution(test4, 10) == 10 ? "PASS" : "FAIL") << " - Expected: 10" << endl;

    // Test Case 5: Array with 7 elements
    // Expected: 7 (straightforward count)
    int test5[] = {100, 200, 300, 400, 500, 600, 700};
    cout << "Test 5: " << (problem1Solution(test5, 7) == 7 ? "PASS" : "FAIL") << " - Expected: 7" << endl;

    // Test Case 6: Array with 3 elements
    // Expected: 3 (straightforward count)
    int test6[] = {-1, 0, 1};
    cout << "Test 6: " << (problem1Solution(test6, 3) == 3 ? "PASS" : "FAIL") << " - Expected: 3" << endl;

    // Test Case 7: Array with 8 elements
    // Expected: 8 (straightforward count)
    int test7[] = {2, 4, 6, 8, 10, 12, 14, 16};
    cout << "Test 7: " << (problem1Solution(test7, 8) == 8 ? "PASS" : "FAIL") << " - Expected: 8" << endl;
    cout << endl;
}

void testProblem2() {
    cout << "Testing Problem 2: Valid Index Checker..." << endl;
    // MANUALLY VERIFIED TEST CASES:

    // Test Case 1: Valid index in middle of array
    // array_size=5, valid indices: 0,1,2,3,4. index=2 is valid
    // Expected: true
    cout << "Test 1: " << (problem2Solution(5, 2) == true ? "PASS" : "FAIL") << " - Expected: true (index 2 in size 5)" << endl;

    // Test Case 2: Index equals array size (out of bounds)
    // array_size=5, valid indices: 0,1,2,3,4. index=5 is out of bounds
    // Expected: false
    cout << "Test 2: " << (problem2Solution(5, 5) == false ? "PASS" : "FAIL") << " - Expected: false (index 5 in size 5)" << endl;

    // Test Case 3: Negative index
    // array_size=3, valid indices: 0,1,2. index=-1 is invalid
    // Expected: false
    cout << "Test 3: " << (problem2Solution(3, -1) == false ? "PASS" : "FAIL") << " - Expected: false (negative index)" << endl;

    // Test Case 4: Edge case - index 0 in size 1 array
    // array_size=1, valid indices: 0. index=0 is valid
    // Expected: true
    cout << "Test 4: " << (problem2Solution(1, 0) == true ? "PASS" : "FAIL") << " - Expected: true (index 0 in size 1)" << endl;

    // Test Case 5: Last valid index
    // array_size=10, valid indices: 0-9. index=9 is the last valid index
    // Expected: true
    cout << "Test 5: " << (problem2Solution(10, 9) == true ? "PASS" : "FAIL") << " - Expected: true (last valid index)" << endl;

    // Test Case 6: First valid index
    // array_size=7, valid indices: 0-6. index=0 is the first valid index
    // Expected: true
    cout << "Test 6: " << (problem2Solution(7, 0) == true ? "PASS" : "FAIL") << " - Expected: true (first valid index)" << endl;

    // Test Case 7: Way out of bounds positive
    // array_size=4, valid indices: 0,1,2,3. index=100 is way out of bounds
    // Expected: false
    cout << "Test 7: " << (problem2Solution(4, 100) == false ? "PASS" : "FAIL") << " - Expected: false (way out of bounds)" << endl;

    // Test Case 8: Way out of bounds negative
    // array_size=6, valid indices: 0-5. index=-50 is way out of bounds negative
    // Expected: false
    cout << "Test 8: " << (problem2Solution(6, -50) == false ? "PASS" : "FAIL") << " - Expected: false (way negative)" << endl;
    cout << endl;
}

void testProblem3() {
    cout << "Testing Problem 3: Array Resize Simulator..." << endl;
    // MANUALLY VERIFIED TEST CASES:

    // Test Case 1: initial_size=3, operations="AAR"
    // Step by step: 3 → +1(A) = 4 → +1(A) = 5 → -1(R) = 4
    // Expected: 4
    cout << "Test 1: " << (problem3Solution(3, "AAR") == 4 ? "PASS" : "FAIL") << " - Expected: 4 (3+2-1)" << endl;

    // Test Case 2: initial_size=5, operations="RRAA"  
    // Step by step: 5 → -1(R) = 4 → -1(R) = 3 → +1(A) = 4 → +1(A) = 5
    // Expected: 5
    cout << "Test 2: " << (problem3Solution(5, "RRAA") == 5 ? "PASS" : "FAIL") << " - Expected: 5 (5-2+2)" << endl;

    // Test Case 3: initial_size=1, operations="RAAA"
    // Step by step: 1 → -1(R) = max(0,0) = 0 → +1(A) = 1 → +1(A) = 2 → +1(A) = 3
    // Expected: 3
    cout << "Test 3: " << (problem3Solution(1, "RAAA") == 3 ? "PASS" : "FAIL") << " - Expected: 3 (max(1-1,0)+3)" << endl;

    // Test Case 4: initial_size=10, operations="AAAA"
    // Step by step: 10 → +1(A) = 11 → +1(A) = 12 → +1(A) = 13 → +1(A) = 14
    // Expected: 14
    cout << "Test 4: " << (problem3Solution(10, "AAAA") == 14 ? "PASS" : "FAIL") << " - Expected: 14 (10+4)" << endl;

    // Test Case 5: initial_size=8, operations="RRRR"
    // Step by step: 8 → -1(R) = 7 → -1(R) = 6 → -1(R) = 5 → -1(R) = 4
    // Expected: 4
    cout << "Test 5: " << (problem3Solution(8, "RRRR") == 4 ? "PASS" : "FAIL") << " - Expected: 4 (8-4)" << endl;

    // Test Case 6: initial_size=2, operations="RRRAA"
    // Step by step: 2 → -1(R) = 1 → -1(R) = 0 → -1(R) = max(0,-1) = 0 → +1(A) = 1 → +1(A) = 2
    // Expected: 2
    cout << "Test 6: " << (problem3Solution(2, "RRRAA") == 2 ? "PASS" : "FAIL") << " - Expected: 2 (underflow protection)" << endl;

    // Test Case 7: initial_size=4, operations="ARAR"
    // Step by step: 4 → +1(A) = 5 → -1(R) = 4 → +1(A) = 5 → -1(R) = 4
    // Expected: 4
    cout << "Test 7: " << (problem3Solution(4, "ARAR") == 4 ? "PASS" : "FAIL") << " - Expected: 4 (alternating ops)" << endl;

    // Test Case 8: initial_size=1, operations="A"
    // Step by step: 1 → +1(A) = 2
    // Expected: 2
    cout << "Test 8: " << (problem3Solution(1, "A") == 2 ? "PASS" : "FAIL") << " - Expected: 2 (single add)" << endl;
    cout << endl;
}

void testProblem4() {
    cout << "Testing Problem 4: Multi-Array Size Analyzer..." << endl;
    // MANUALLY VERIFIED TEST CASES:

    // Test Case 1: sizes = {2, 4, 8, 16}
    // Pairs check: (2,4): 4=2*2 ✓, (2,8): 8≠2*2, (2,16): 16≠2*2
    //              (4,8): 8=4*2 ✓, (4,16): 16≠4*2, (8,16): 16=8*2 ✓
    // Valid pairs: (2,4), (4,8), (8,16) = 3 pairs
    int test1[] = {2, 4, 8, 16};
    cout << "Test 1: " << (problem4Solution(test1, 4) == 3 ? "PASS" : "FAIL") << " - Expected: 3 pairs (2,4), (4,8), (8,16)" << endl;

    // Test Case 2: sizes = {1, 3, 5, 10}
    // Pairs check: (1,3): 3≠1*2, (1,5): 5≠1*2, (1,10): 10≠1*2
    //              (3,5): 5≠3*2, (3,10): 10≠3*2, (5,10): 10=5*2 ✓
    // Valid pairs: (5,10) = 1 pair
    int test2[] = {1, 3, 5, 10};
    cout << "Test 2: " << (problem4Solution(test2, 4) == 1 ? "PASS" : "FAIL") << " - Expected: 1 pair (5,10)" << endl;

    // Test Case 3: sizes = {2, 6, 12, 3}
    // Pairs check: (2,6): 6=2*3≠2*2, (2,12): 12≠2*2, (2,3): 3≠2*2
    //              (6,12): 12=6*2 ✓, (6,3): 6=3*2 ✓, (12,3): 12≠3*2
    // Valid pairs: (3,6), (6,12) = 2 pairs
    int test3[] = {2, 6, 12, 3};
    cout << "Test 3: " << (problem4Solution(test3, 4) == 2 ? "PASS" : "FAIL") << " - Expected: 2 pairs (3,6), (6,12)" << endl;

    // Test Case 4: sizes = {1, 2}
    // Pairs check: (1,2): 2=1*2 ✓
    // Valid pairs: (1,2) = 1 pair
    int test4[] = {1, 2};
    cout << "Test 4: " << (problem4Solution(test4, 2) == 1 ? "PASS" : "FAIL") << " - Expected: 1 pair (1,2)" << endl;

    // Test Case 5: sizes = {3, 7, 11}
    // Pairs check: (3,7): 7≠3*2, (3,11): 11≠3*2, (7,11): 11≠7*2
    // Valid pairs: none = 0 pairs
    int test5[] = {3, 7, 11};
    cout << "Test 5: " << (problem4Solution(test5, 3) == 0 ? "PASS" : "FAIL") << " - Expected: 0 pairs (no doubles)" << endl;

    // Test Case 6: sizes = {1, 2, 4, 8}
    // Pairs check: (1,2): 2=1*2 ✓, (1,4): 4≠1*2, (1,8): 8≠1*2
    //              (2,4): 4=2*2 ✓, (2,8): 8≠2*2, (4,8): 8=4*2 ✓
    // Valid pairs: (1,2), (2,4), (4,8) = 3 pairs
    int test6[] = {1, 2, 4, 8};
    cout << "Test 6: " << (problem4Solution(test6, 4) == 3 ? "PASS" : "FAIL") << " - Expected: 3 pairs (1,2), (2,4), (4,8)" << endl;

    // Test Case 7: sizes = {5, 10, 15, 20}
    // Pairs check: (5,10): 10=5*2 ✓, (5,15): 15≠5*2, (5,20): 20≠5*2
    //              (10,15): 15≠10*2, (10,20): 20=10*2 ✓, (15,20): 20≠15*2
    // Valid pairs: (5,10), (10,20) = 2 pairs
    int test7[] = {5, 10, 15, 20};
    cout << "Test 7: " << (problem4Solution(test7, 4) == 2 ? "PASS" : "FAIL") << " - Expected: 2 pairs (5,10), (10,20)" << endl;

    // Test Case 8: sizes = {4, 4, 8}
    // Pairs check: (4,4): 4≠4*2 (same values don't count), (4,8): 8=4*2 ✓, (4,8): 8=4*2 ✓
    // Valid pairs: first 4 with 8, second 4 with 8 = 2 pairs
    int test8[] = {4, 4, 8};
    cout << "Test 8: " << (problem4Solution(test8, 3) == 2 ? "PASS" : "FAIL") << " - Expected: 2 pairs (both 4s with 8)" << endl;
    cout << endl;
}

int main() {
    int choice;
    cout << "=== C++ Array Size Practice Problems ===" << endl;
    cout << "Choose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy) - Array Size Calculator" << endl;
    cout << "2. Problem 2 (Easy-Medium) - Valid Index Checker" << endl;
    cout << "3. Problem 3 (Medium) - Array Resize Simulator" << endl;
    cout << "4. Problem 4 (Hard) - Multi-Array Size Analyzer" << endl;
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
            testProblem1();
            testProblem2();
            testProblem3();
            testProblem4();
            break;
        default: 
            cout << "Invalid choice! Please select 1-5." << endl;
    }

    return 0;
}   