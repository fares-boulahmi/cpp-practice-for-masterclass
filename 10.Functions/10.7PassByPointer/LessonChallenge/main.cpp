#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// Problem 1: Easy 1 - Swap Two Numbers
// Write a function that swaps two integer values using pass by pointer.
// The function should take two pointers to integers and swap their values.
//
// Input Format: Two integers a and b
// Output Format: The function modifies the values through pointers (void return)
//
// Example 1:
// Before: a = 5, b = 10
// After: a = 10, b = 5
//
// Example 2:
// Before: a = -3, b = 7
// After: a = 7, b = -3
//
// Constraints:
// - -1000 <= a, b <= 1000
void swapNumbers(int* a, int* b) {
    // TODO: Implement your solution here using pass by pointer
    // Hint: Use a temporary variable to hold one value while swapping
}

// Problem 2: Easy 2 - Find Min and Max
// Write a function that finds both the minimum and maximum values in an array.
// Since a function can only return one value, use pointers to return both min and max.
//
// Input Format: 
// - An array of integers
// - Size of the array
// - Pointer to store minimum value
// - Pointer to store maximum value
//
// Output Format: The function modifies min and max through pointers (void return)
//
// Example 1:
// Array: [3, 7, 1, 9, 2]
// Min: 1, Max: 9
//
// Example 2:
// Array: [-5, -2, -10, -1]
// Min: -10, Max: -1
//
// Constraints:
// - 1 <= array size <= 100
// - -1000 <= array elements <= 1000
void findMinMax(int arr[], int size, int* minVal, int* maxVal) {
    // TODO: Implement your solution here using pass by pointer
    // Hint: Initialize min and max with the first element, then iterate through the array
}

// Problem 3: Medium - Calculate Statistics
// Write a function that calculates multiple statistics for an array of integers:
// sum, average (as integer division), count of positive numbers, and count of negative numbers.
// Use pointers to return all four values.
//
// Input Format:
// - An array of integers
// - Size of the array
// - Pointer to store sum
// - Pointer to store average
// - Pointer to store positive count
// - Pointer to store negative count
//
// Output Format: The function modifies all statistics through pointers (void return)
//
// Example 1:
// Array: [5, -3, 8, -2, 0, 4]
// Sum: 12, Average: 2 (12/6), Positive: 3, Negative: 2
//
// Example 2:
// Array: [10, 20, 30]
// Sum: 60, Average: 20 (60/3), Positive: 3, Negative: 0
//
// Constraints:
// - 1 <= array size <= 100
// - -1000 <= array elements <= 1000
// - Average is calculated using integer division (truncated)
// - Zero is neither positive nor negative
void calculateStats(int arr[], int size, int* sum, int* avg, int* posCount, int* negCount) {
    // TODO: Implement your solution here using pass by pointer
    // Hint: Use a single loop to calculate all statistics, use if-else to categorize numbers
}

// Problem 4: Hard - Partition Array Around Pivot
// Write a function that partitions an array around a pivot value.
// All elements less than pivot should come before elements greater than or equal to pivot.
// Use pointers to return the count of elements less than pivot and the modified array position.
//
// Input Format:
// - An array of integers
// - Size of the array
// - Pivot value
// - Pointer to store count of elements less than pivot
//
// Output Format: The function modifies the array in-place and returns count through pointer (void return)
//
// Example 1:
// Array: [7, 2, 9, 3, 5, 1, 8], Pivot: 5
// After: [2, 3, 1, 7, 9, 5, 8] (or any arrangement with small numbers first)
// Count less than pivot: 3
//
// Example 2:
// Array: [4, 8, 2, 9, 1], Pivot: 5
// After: [4, 2, 1, 9, 8] (or any arrangement with small numbers first)
// Count less than pivot: 3
//
// Constraints:
// - 1 <= array size <= 100
// - -1000 <= array elements <= 1000
// - The relative order within partitions doesn't matter
void partitionArray(int arr[], int size, int pivot, int* countLess) {
    // TODO: Implement your solution here using pass by pointer
    // Hint: Use two index pointers - one for position to place small elements, one to scan array
}

void testProblem1() {
    cout << "\n=== Testing Problem 1: Swap Two Numbers ===" << endl;
    
    // Test Case 1: Positive numbers
    // Before: a=5, b=10
    // After: a=10, b=5
    int a1 = 5, b1 = 10;
    swapNumbers(&a1, &b1);
    cout << "Test 1: " << ((a1 == 10 && b1 == 5) ? "PASS" : "FAIL") 
         << " (Expected: a=10, b=5, Got: a=" << a1 << ", b=" << b1 << ")" << endl;
    
    // Test Case 2: Negative and positive
    // Before: a=-3, b=7
    // After: a=7, b=-3
    int a2 = -3, b2 = 7;
    swapNumbers(&a2, &b2);
    cout << "Test 2: " << ((a2 == 7 && b2 == -3) ? "PASS" : "FAIL")
         << " (Expected: a=7, b=-3, Got: a=" << a2 << ", b=" << b2 << ")" << endl;
    
    // Test Case 3: Both negative
    // Before: a=-15, b=-8
    // After: a=-8, b=-15
    int a3 = -15, b3 = -8;
    swapNumbers(&a3, &b3);
    cout << "Test 3: " << ((a3 == -8 && b3 == -15) ? "PASS" : "FAIL")
         << " (Expected: a=-8, b=-15, Got: a=" << a3 << ", b=" << b3 << ")" << endl;
    
    // Test Case 4: Same numbers
    // Before: a=42, b=42
    // After: a=42, b=42
    int a4 = 42, b4 = 42;
    swapNumbers(&a4, &b4);
    cout << "Test 4: " << ((a4 == 42 && b4 == 42) ? "PASS" : "FAIL")
         << " (Expected: a=42, b=42, Got: a=" << a4 << ", b=" << b4 << ")" << endl;
    
    // Test Case 5: Zero and positive
    // Before: a=0, b=100
    // After: a=100, b=0
    int a5 = 0, b5 = 100;
    swapNumbers(&a5, &b5);
    cout << "Test 5: " << ((a5 == 100 && b5 == 0) ? "PASS" : "FAIL")
         << " (Expected: a=100, b=0, Got: a=" << a5 << ", b=" << b5 << ")" << endl;
    
    // Test Case 6: Large numbers
    // Before: a=999, b=-999
    // After: a=-999, b=999
    int a6 = 999, b6 = -999;
    swapNumbers(&a6, &b6);
    cout << "Test 6: " << ((a6 == -999 && b6 == 999) ? "PASS" : "FAIL")
         << " (Expected: a=-999, b=999, Got: a=" << a6 << ", b=" << b6 << ")" << endl;
    
    // Test Case 7: Both zero
    // Before: a=0, b=0
    // After: a=0, b=0
    int a7 = 0, b7 = 0;
    swapNumbers(&a7, &b7);
    cout << "Test 7: " << ((a7 == 0 && b7 == 0) ? "PASS" : "FAIL")
         << " (Expected: a=0, b=0, Got: a=" << a7 << ", b=" << b7 << ")" << endl;
    
    // Test Case 8: One is 1, other is -1
    // Before: a=1, b=-1
    // After: a=-1, b=1
    int a8 = 1, b8 = -1;
    swapNumbers(&a8, &b8);
    cout << "Test 8: " << ((a8 == -1 && b8 == 1) ? "PASS" : "FAIL")
         << " (Expected: a=-1, b=1, Got: a=" << a8 << ", b=" << b8 << ")" << endl;
}

void testProblem2() {
    cout << "\n=== Testing Problem 2: Find Min and Max ===" << endl;
    
    // Test Case 1: Mixed positive numbers
    // Array: [3, 7, 1, 9, 2]
    // Min: 1 (smallest), Max: 9 (largest)
    int arr1[] = {3, 7, 1, 9, 2};
    int min1, max1;
    findMinMax(arr1, 5, &min1, &max1);
    cout << "Test 1: " << ((min1 == 1 && max1 == 9) ? "PASS" : "FAIL")
         << " (Expected: min=1, max=9, Got: min=" << min1 << ", max=" << max1 << ")" << endl;
    
    // Test Case 2: All negative numbers
    // Array: [-5, -2, -10, -1]
    // Min: -10 (smallest), Max: -1 (largest)
    int arr2[] = {-5, -2, -10, -1};
    int min2, max2;
    findMinMax(arr2, 4, &min2, &max2);
    cout << "Test 2: " << ((min2 == -10 && max2 == -1) ? "PASS" : "FAIL")
         << " (Expected: min=-10, max=-1, Got: min=" << min2 << ", max=" << max2 << ")" << endl;
    
    // Test Case 3: Single element
    // Array: [42]
    // Min: 42, Max: 42
    int arr3[] = {42};
    int min3, max3;
    findMinMax(arr3, 1, &min3, &max3);
    cout << "Test 3: " << ((min3 == 42 && max3 == 42) ? "PASS" : "FAIL")
         << " (Expected: min=42, max=42, Got: min=" << min3 << ", max=" << max3 << ")" << endl;
    
    // Test Case 4: All same values
    // Array: [5, 5, 5, 5]
    // Min: 5, Max: 5
    int arr4[] = {5, 5, 5, 5};
    int min4, max4;
    findMinMax(arr4, 4, &min4, &max4);
    cout << "Test 4: " << ((min4 == 5 && max4 == 5) ? "PASS" : "FAIL")
         << " (Expected: min=5, max=5, Got: min=" << min4 << ", max=" << max4 << ")" << endl;
    
    // Test Case 5: Min at beginning, max at end
    // Array: [1, 5, 3, 7, 10]
    // Min: 1, Max: 10
    int arr5[] = {1, 5, 3, 7, 10};
    int min5, max5;
    findMinMax(arr5, 5, &min5, &max5);
    cout << "Test 5: " << ((min5 == 1 && max5 == 10) ? "PASS" : "FAIL")
         << " (Expected: min=1, max=10, Got: min=" << min5 << ", max=" << max5 << ")" << endl;
    
    // Test Case 6: Min at end, max at beginning
    // Array: [100, 50, 25, 75, 10]
    // Min: 10, Max: 100
    int arr6[] = {100, 50, 25, 75, 10};
    int min6, max6;
    findMinMax(arr6, 5, &min6, &max6);
    cout << "Test 6: " << ((min6 == 10 && max6 == 100) ? "PASS" : "FAIL")
         << " (Expected: min=10, max=100, Got: min=" << min6 << ", max=" << max6 << ")" << endl;
    
    // Test Case 7: With zeros
    // Array: [0, -5, 3, 0, -2]
    // Min: -5, Max: 3
    int arr7[] = {0, -5, 3, 0, -2};
    int min7, max7;
    findMinMax(arr7, 5, &min7, &max7);
    cout << "Test 7: " << ((min7 == -5 && max7 == 3) ? "PASS" : "FAIL")
         << " (Expected: min=-5, max=3, Got: min=" << min7 << ", max=" << max7 << ")" << endl;
    
    // Test Case 8: Two elements
    // Array: [15, 8]
    // Min: 8, Max: 15
    int arr8[] = {15, 8};
    int min8, max8;
    findMinMax(arr8, 2, &min8, &max8);
    cout << "Test 8: " << ((min8 == 8 && max8 == 15) ? "PASS" : "FAIL")
         << " (Expected: min=8, max=15, Got: min=" << min8 << ", max=" << max8 << ")" << endl;
}

void testProblem3() {
    cout << "\n=== Testing Problem 3: Calculate Statistics ===" << endl;
    
    // Test Case 1: Mixed numbers with zero
    // Array: [5, -3, 8, -2, 0, 4]
    // Sum: 5+(-3)+8+(-2)+0+4 = 12
    // Average: 12/6 = 2
    // Positive: 5, 8, 4 = 3 numbers
    // Negative: -3, -2 = 2 numbers
    int arr1[] = {5, -3, 8, -2, 0, 4};
    int sum1, avg1, pos1, neg1;
    calculateStats(arr1, 6, &sum1, &avg1, &pos1, &neg1);
    cout << "Test 1: " << ((sum1 == 12 && avg1 == 2 && pos1 == 3 && neg1 == 2) ? "PASS" : "FAIL")
         << " (Expected: sum=12, avg=2, pos=3, neg=2, Got: sum=" << sum1 
         << ", avg=" << avg1 << ", pos=" << pos1 << ", neg=" << neg1 << ")" << endl;
    
    // Test Case 2: All positive
    // Array: [10, 20, 30]
    // Sum: 10+20+30 = 60
    // Average: 60/3 = 20
    // Positive: 3, Negative: 0
    int arr2[] = {10, 20, 30};
    int sum2, avg2, pos2, neg2;
    calculateStats(arr2, 3, &sum2, &avg2, &pos2, &neg2);
    cout << "Test 2: " << ((sum2 == 60 && avg2 == 20 && pos2 == 3 && neg2 == 0) ? "PASS" : "FAIL")
         << " (Expected: sum=60, avg=20, pos=3, neg=0, Got: sum=" << sum2 
         << ", avg=" << avg2 << ", pos=" << pos2 << ", neg=" << neg2 << ")" << endl;
    
    // Test Case 3: All negative
    // Array: [-5, -10, -15]
    // Sum: -5+(-10)+(-15) = -30
    // Average: -30/3 = -10
    // Positive: 0, Negative: 3
    int arr3[] = {-5, -10, -15};
    int sum3, avg3, pos3, neg3;
    calculateStats(arr3, 3, &sum3, &avg3, &pos3, &neg3);
    cout << "Test 3: " << ((sum3 == -30 && avg3 == -10 && pos3 == 0 && neg3 == 3) ? "PASS" : "FAIL")
         << " (Expected: sum=-30, avg=-10, pos=0, neg=3, Got: sum=" << sum3 
         << ", avg=" << avg3 << ", pos=" << pos3 << ", neg=" << neg3 << ")" << endl;
    
    // Test Case 4: Single positive number
    // Array: [7]
    // Sum: 7, Average: 7/1 = 7
    // Positive: 1, Negative: 0
    int arr4[] = {7};
    int sum4, avg4, pos4, neg4;
    calculateStats(arr4, 1, &sum4, &avg4, &pos4, &neg4);
    cout << "Test 4: " << ((sum4 == 7 && avg4 == 7 && pos4 == 1 && neg4 == 0) ? "PASS" : "FAIL")
         << " (Expected: sum=7, avg=7, pos=1, neg=0, Got: sum=" << sum4 
         << ", avg=" << avg4 << ", pos=" << pos4 << ", neg=" << neg4 << ")" << endl;
    
    // Test Case 5: All zeros
    // Array: [0, 0, 0, 0]
    // Sum: 0, Average: 0/4 = 0
    // Positive: 0, Negative: 0
    int arr5[] = {0, 0, 0, 0};
    int sum5, avg5, pos5, neg5;
    calculateStats(arr5, 4, &sum5, &avg5, &pos5, &neg5);
    cout << "Test 5: " << ((sum5 == 0 && avg5 == 0 && pos5 == 0 && neg5 == 0) ? "PASS" : "FAIL")
         << " (Expected: sum=0, avg=0, pos=0, neg=0, Got: sum=" << sum5 
         << ", avg=" << avg5 << ", pos=" << pos5 << ", neg=" << neg5 << ")" << endl;
    
    // Test Case 6: Integer division truncation (positive result)
    // Array: [5, 5, 5, 5, 5, 5, 5]
    // Sum: 35, Average: 35/7 = 5
    // Positive: 7, Negative: 0
    int arr6[] = {5, 5, 5, 5, 5, 5, 5};
    int sum6, avg6, pos6, neg6;
    calculateStats(arr6, 7, &sum6, &avg6, &pos6, &neg6);
    cout << "Test 6: " << ((sum6 == 35 && avg6 == 5 && pos6 == 7 && neg6 == 0) ? "PASS" : "FAIL")
         << " (Expected: sum=35, avg=5, pos=7, neg=0, Got: sum=" << sum6 
         << ", avg=" << avg6 << ", pos=" << pos6 << ", neg=" << neg6 << ")" << endl;
    
    // Test Case 7: Integer division truncation (negative result)
    // Array: [7, -5, 3]
    // Sum: 7+(-5)+3 = 5
    // Average: 5/3 = 1 (truncated)
    // Positive: 2 (7, 3), Negative: 1 (-5)
    int arr7[] = {7, -5, 3};
    int sum7, avg7, pos7, neg7;
    calculateStats(arr7, 3, &sum7, &avg7, &pos7, &neg7);
    cout << "Test 7: " << ((sum7 == 5 && avg7 == 1 && pos7 == 2 && neg7 == 1) ? "PASS" : "FAIL")
         << " (Expected: sum=5, avg=1, pos=2, neg=1, Got: sum=" << sum7 
         << ", avg=" << avg7 << ", pos=" << pos7 << ", neg=" << neg7 << ")" << endl;
    
    // Test Case 8: Larger array
    // Array: [1, -1, 2, -2, 3, -3, 0, 0]
    // Sum: 1+(-1)+2+(-2)+3+(-3)+0+0 = 0
    // Average: 0/8 = 0
    // Positive: 3 (1, 2, 3), Negative: 3 (-1, -2, -3)
    int arr8[] = {1, -1, 2, -2, 3, -3, 0, 0};
    int sum8, avg8, pos8, neg8;
    calculateStats(arr8, 8, &sum8, &avg8, &pos8, &neg8);
    cout << "Test 8: " << ((sum8 == 0 && avg8 == 0 && pos8 == 3 && neg8 == 3) ? "PASS" : "FAIL")
         << " (Expected: sum=0, avg=0, pos=3, neg=3, Got: sum=" << sum8 
         << ", avg=" << avg8 << ", pos=" << pos8 << ", neg=" << neg8 << ")" << endl;
}

void testProblem4() {
    cout << "\n=== Testing Problem 4: Partition Array Around Pivot ===" << endl;
    
    // Test Case 1: Standard case
    // Array: [7, 2, 9, 3, 5, 1, 8], Pivot: 5
    // Elements < 5: 2, 3, 1 (count = 3)
    // After partition: all elements < 5 come before elements >= 5
    int arr1[] = {7, 2, 9, 3, 5, 1, 8};
    int count1;
    partitionArray(arr1, 7, 5, &count1);
    bool valid1 = (count1 == 3);
    // Verify partition: first 3 elements should be < 5, rest >= 5
    for(int i = 0; i < count1 && valid1; i++) {
        if(arr1[i] >= 5) valid1 = false;
    }
    for(int i = count1; i < 7 && valid1; i++) {
        if(arr1[i] < 5) valid1 = false;
    }
    cout << "Test 1: " << (valid1 ? "PASS" : "FAIL")
         << " (Expected: count=3 with proper partition, Got: count=" << count1 << ")" << endl;
    
    // Test Case 2: Another standard case
    // Array: [4, 8, 2, 9, 1], Pivot: 5
    // Elements < 5: 4, 2, 1 (count = 3)
    int arr2[] = {4, 8, 2, 9, 1};
    int count2;
    partitionArray(arr2, 5, 5, &count2);
    bool valid2 = (count2 == 3);
    for(int i = 0; i < count2 && valid2; i++) {
        if(arr2[i] >= 5) valid2 = false;
    }
    for(int i = count2; i < 5 && valid2; i++) {
        if(arr2[i] < 5) valid2 = false;
    }
    cout << "Test 2: " << (valid2 ? "PASS" : "FAIL")
         << " (Expected: count=3 with proper partition, Got: count=" << count2 << ")" << endl;
    
    // Test Case 3: All elements less than pivot
    // Array: [1, 2, 3, 4], Pivot: 10
    // Elements < 10: all 4 elements (count = 4)
    int arr3[] = {1, 2, 3, 4};
    int count3;
    partitionArray(arr3, 4, 10, &count3);
    bool valid3 = (count3 == 4);
    for(int i = 0; i < 4 && valid3; i++) {
        if(arr3[i] >= 10) valid3 = false;
    }
    cout << "Test 3: " << (valid3 ? "PASS" : "FAIL")
         << " (Expected: count=4, Got: count=" << count3 << ")" << endl;
    
    // Test Case 4: All elements greater than or equal to pivot
    // Array: [10, 20, 30, 40], Pivot: 5
    // Elements < 5: none (count = 0)
    int arr4[] = {10, 20, 30, 40};
    int count4;
    partitionArray(arr4, 4, 5, &count4);
    bool valid4 = (count4 == 0);
    for(int i = 0; i < 4 && valid4; i++) {
        if(arr4[i] < 5) valid4 = false;
    }
    cout << "Test 4: " << (valid4 ? "PASS" : "FAIL")
         << " (Expected: count=0, Got: count=" << count4 << ")" << endl;
    
    // Test Case 5: Single element less than pivot
    // Array: [3], Pivot: 5
    // Elements < 5: 3 (count = 1)
    int arr5[] = {3};
    int count5;
    partitionArray(arr5, 1, 5, &count5);
    cout << "Test 5: " << ((count5 == 1 && arr5[0] == 3) ? "PASS" : "FAIL")
         << " (Expected: count=1, Got: count=" << count5 << ")" << endl;
    
    // Test Case 6: Single element greater than pivot
    // Array: [8], Pivot: 5
    // Elements < 5: none (count = 0)
    int arr6[] = {8};
    int count6;
    partitionArray(arr6, 1, 5, &count6);
    cout << "Test 6: " << ((count6 == 0 && arr6[0] == 8) ? "PASS" : "FAIL")
         << " (Expected: count=0, Got: count=" << count6 << ")" << endl;
    
    // Test Case 7: Pivot equals some elements
    // Array: [5, 3, 5, 1, 5, 7], Pivot: 5
    // Elements < 5: 3, 1 (count = 2)
    // Elements equal to 5 go to right partition (>= 5)
    int arr7[] = {5, 3, 5, 1, 5, 7};
    int count7;
    partitionArray(arr7, 6, 5, &count7);
    bool valid7 = (count7 == 2);
    for(int i = 0; i < count7 && valid7; i++) {
        if(arr7[i] >= 5) valid7 = false;
    }
    for(int i = count7; i < 6 && valid7; i++) {
        if(arr7[i] < 5) valid7 = false;
    }
    cout << "Test 7: " << (valid7 ? "PASS" : "FAIL")
         << " (Expected: count=2 with proper partition, Got: count=" << count7 << ")" << endl;
    
    // Test Case 8: Negative numbers
    // Array: [-5, 3, -2, 8, -10, 4], Pivot: 0
    // Elements < 0: -5, -2, -10 (count = 3)
    int arr8[] = {-5, 3, -2, 8, -10, 4};
    int count8;
    partitionArray(arr8, 6, 0, &count8);
    bool valid8 = (count8 == 3);
    for(int i = 0; i < count8 && valid8; i++) {
        if(arr8[i] >= 0) valid8 = false;
    }
    for(int i = count8; i < 6 && valid8; i++) {
        if(arr8[i] < 0) valid8 = false;
    }
    cout << "Test 8: " << (valid8 ? "PASS" : "FAIL")
         << " (Expected: count=3 with proper partition, Got: count=" << count8 << ")" << endl;
}

int main() {
    int choice;
    cout << "=== C++ Pass by Pointer Practice Problems ===" << endl;
    cout << "Choose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy): Swap Two Numbers" << endl;
    cout << "2. Problem 2 (Easy): Find Min and Max" << endl;
    cout << "3. Problem 3 (Medium): Calculate Statistics" << endl;
    cout << "4. Problem 4 (Hard): Partition Array Around Pivot" << endl;
    cout << "5. Test All Problems" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice) {
        case 1: testProblem1(); break;
        case 2: testProblem2(); break;
        case 3: testProblem3(); break;
        case 4: testProblem4(); break;
        case 5:
            testProblem1();
            testProblem2();
            testProblem3();
            testProblem4();
            break;
        default: cout << "Invalid choice!" << endl;
    }

    return 0;
}