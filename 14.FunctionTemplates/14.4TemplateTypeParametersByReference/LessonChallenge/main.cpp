#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

// Problem 1: Easy 1 - Swap Two Values
// Write a template function that swaps two values of any type by reference.
// The function should work with integers, doubles, strings, and other types.
//
// Input Format: Two values of the same type
// Output Format: Values are swapped in place (no return value)
//
// Example 1:
//   Input: a = 5, b = 10
//   Output: a = 10, b = 5
//
// Example 2:
//   Input: a = "hello", b = "world"
//   Output: a = "world", b = "hello"
//
// Constraints:
//   - Must use template parameters by reference
//   - Should work with any copyable type
//   - No return value needed (void function)

template <typename T>
void swapValues(T &a, T &b)
{
     // TODO: Implement your solution here using Template parameters by reference
     // Hint: Use a temporary variable to hold one value during the swap
     T c = a;
     a = b;
     b = c;
}

// Problem 2: Easy 2 - Find Maximum and Minimum
// Write a template function that finds both the maximum and minimum values
// in an array and stores them in reference parameters.
//
// Input Format: Array of values, size, two reference parameters for max and min
// Output Format: max and min are updated with the largest and smallest values
//
// Example 1:
//   Input: arr = {3, 7, 1, 9, 2}, size = 5
//   Output: max = 9, min = 1
//
// Example 2:
//   Input: arr = {-5, -2, -10, -1}, size = 4
//   Output: max = -1, min = -10
//
// Constraints:
//   - Array will have at least 1 element
//   - Must use template parameters by reference for max and min
//   - Array size is provided as a parameter

template <typename T>
void findMinMax(T arr[], int size, T &minVal, T &maxVal)
{
     // TODO: Implement your solution here using Template parameters by reference
     // Hint: Initialize min and max with the first element, then iterate through the rest
     if (size == 0)
     {
          minVal = 0;
          maxVal = 0;
          return;
     }
     minVal = INT_MAX;
     maxVal = INT_MIN;
     for (int i = 0; i < size; i++)
     {
          if (arr[i] > maxVal)
          {
               maxVal = arr[i];
          }
          if (arr[i] < minVal)
          {
               minVal = arr[i];
          }
     }
     return ;
}

// Problem 3: Medium - Update Array Statistics
// Write a template function that calculates multiple statistics for an array:
// sum, average, and count of elements greater than average.
// All results should be returned via reference parameters.
//
// Input Format: Array of numeric values, size, three reference parameters
// Output Format: sum, average, and countAboveAvg are updated
//
// Example 1:
//   Input: arr = {10, 20, 30, 40}, size = 4
//   Calculation: sum = 100, avg = 25.0, elements > 25.0 are {30, 40} = 2
//   Output: sum = 100, average = 25.0, countAboveAvg = 2
//
// Example 2:
//   Input: arr = {5, 5, 5, 5}, size = 4
//   Calculation: sum = 20, avg = 5.0, elements > 5.0 are {} = 0
//   Output: sum = 20, average = 5.0, countAboveAvg = 0
//
// Constraints:
//   - Array will have at least 1 element
//   - Must use template parameters by reference
//   - Average should be a double type

template <typename T>
void calculateStats(T arr[], int size, T &sum, double &average, int &countAboveAvg)
{
     // TODO: Implement your solution here using Template parameters by reference
     // Hint: First calculate sum and average, then count elements greater than average
     sum = 0;
     average = 0;
     countAboveAvg = 0;
     if (size == 0 ) return ;
     for (int i = 0; i < size; i++)
     {
          sum += arr[i];
     }
     double temp_sum = sum;
     double temp_size = size;
     average = temp_sum / temp_size;
     for (int i = 0; i < size; i++)
     {
          if (arr[i] > average)
          {
               countAboveAvg += 1;
          }
          
     }
     return ;
     
     
}

// Problem 4: Hard - Partition Array Around Pivot
// Write a template function that partitions an array around a pivot value.
// Elements less than pivot go to the left, greater or equal go to the right.
// Return the count of elements less than pivot via reference parameter.
// The array should be modified in place.
//
// Input Format: Array, size, pivot value, reference parameter for count
// Output Format: Array is rearranged, leftCount contains number of elements < pivot
//
// Example 1:
//   Input: arr = {7, 2, 9, 1, 5, 3}, size = 6, pivot = 5
//   After partition: arr = {2, 1, 3, 7, 9, 5} (order within partitions may vary)
//   Output: leftCount = 3 (elements 2, 1, 3 are < 5)
//
// Example 2:
//   Input: arr = {10, 20, 30}, size = 3, pivot = 5
//   After partition: arr = {10, 20, 30} (no elements < 5)
//   Output: leftCount = 0
//
// Constraints:
//   - Array will have at least 1 element
//   - Must use template parameters by reference
//   - Relative order within partitions doesn't matter
//   - Pivot may or may not be in the array

template <typename T>
void partitionArray(T arr[], int size, T pivot, int &leftCount)
{
     // TODO: Implement your solution here using Template parameters by reference
     // Hint: Use two pointers or indices to swap elements as you scan through the array
}

// ==================== TEST FUNCTIONS ====================

void testProblem1()
{
     cout << "\n=== Testing Problem 1: Swap Two Values ===" << endl;

     // Test Case 1: Basic integer swap
     // Initial: a = 5, b = 10
     // After swap: a = 10, b = 5
     int a1 = 5, b1 = 10;
     swapValues(a1, b1);
     cout << "Test 1 (int swap): " << (a1 == 10 && b1 == 5 ? "PASS" : "FAIL")
          << " (Expected: a=10, b=5; Got: a=" << a1 << ", b=" << b1 << ")" << endl;

     // Test Case 2: Double swap
     // Initial: a = 3.14, b = 2.71
     // After swap: a = 2.71, b = 3.14
     double a2 = 3.14, b2 = 2.71;
     swapValues(a2, b2);
     cout << "Test 2 (double swap): " << (a2 == 2.71 && b2 == 3.14 ? "PASS" : "FAIL")
          << " (Expected: a=2.71, b=3.14; Got: a=" << a2 << ", b=" << b2 << ")" << endl;

     // Test Case 3: String swap
     // Initial: a = "hello", b = "world"
     // After swap: a = "world", b = "hello"
     string a3 = "hello", b3 = "world";
     swapValues(a3, b3);
     cout << "Test 3 (string swap): " << (a3 == "world" && b3 == "hello" ? "PASS" : "FAIL")
          << " (Expected: a=\"world\", b=\"hello\"; Got: a=\"" << a3 << "\", b=\"" << b3 << "\")" << endl;

     // Test Case 4: Negative numbers
     // Initial: a = -15, b = -7
     // After swap: a = -7, b = -15
     int a4 = -15, b4 = -7;
     swapValues(a4, b4);
     cout << "Test 4 (negative int): " << (a4 == -7 && b4 == -15 ? "PASS" : "FAIL")
          << " (Expected: a=-7, b=-15; Got: a=" << a4 << ", b=" << b4 << ")" << endl;

     // Test Case 5: Same values
     // Initial: a = 42, b = 42
     // After swap: a = 42, b = 42
     int a5 = 42, b5 = 42;
     swapValues(a5, b5);
     cout << "Test 5 (same values): " << (a5 == 42 && b5 == 42 ? "PASS" : "FAIL")
          << " (Expected: a=42, b=42; Got: a=" << a5 << ", b=" << b5 << ")" << endl;

     // Test Case 6: Zero and positive
     // Initial: a = 0, b = 100
     // After swap: a = 100, b = 0
     int a6 = 0, b6 = 100;
     swapValues(a6, b6);
     cout << "Test 6 (zero swap): " << (a6 == 100 && b6 == 0 ? "PASS" : "FAIL")
          << " (Expected: a=100, b=0; Got: a=" << a6 << ", b=" << b6 << ")" << endl;

     // Test Case 7: Large numbers
     // Initial: a = 999999, b = 1000000
     // After swap: a = 1000000, b = 999999
     int a7 = 999999, b7 = 1000000;
     swapValues(a7, b7);
     cout << "Test 7 (large numbers): " << (a7 == 1000000 && b7 == 999999 ? "PASS" : "FAIL")
          << " (Expected: a=1000000, b=999999; Got: a=" << a7 << ", b=" << b7 << ")" << endl;
}

void testProblem2()
{
     cout << "\n=== Testing Problem 2: Find Maximum and Minimum ===" << endl;

     // Test Case 1: Mixed positive numbers
     // arr = {3, 7, 1, 9, 2}
     // min = 1, max = 9
     int arr1[] = {3, 7, 1, 9, 2};
     int min1, max1;
     findMinMax(arr1, 5, min1, max1);
     cout << "Test 1: " << (min1 == 1 && max1 == 9 ? "PASS" : "FAIL")
          << " (Expected: min=1, max=9; Got: min=" << min1 << ", max=" << max1 << ")" << endl;

     // Test Case 2: All negative numbers
     // arr = {-5, -2, -10, -1}
     // min = -10, max = -1
     int arr2[] = {-5, -2, -10, -1};
     int min2, max2;
     findMinMax(arr2, 4, min2, max2);
     cout << "Test 2: " << (min2 == -10 && max2 == -1 ? "PASS" : "FAIL")
          << " (Expected: min=-10, max=-1; Got: min=" << min2 << ", max=" << max2 << ")" << endl;

     // Test Case 3: Single element
     // arr = {42}
     // min = 42, max = 42
     int arr3[] = {42};
     int min3, max3;
     findMinMax(arr3, 1, min3, max3);
     cout << "Test 3: " << (min3 == 42 && max3 == 42 ? "PASS" : "FAIL")
          << " (Expected: min=42, max=42; Got: min=" << min3 << ", max=" << max3 << ")" << endl;

     // Test Case 4: All same values
     // arr = {5, 5, 5, 5}
     // min = 5, max = 5
     int arr4[] = {5, 5, 5, 5};
     int min4, max4;
     findMinMax(arr4, 4, min4, max4);
     cout << "Test 4: " << (min4 == 5 && max4 == 5 ? "PASS" : "FAIL")
          << " (Expected: min=5, max=5; Got: min=" << min4 << ", max=" << max4 << ")" << endl;

     // Test Case 5: Doubles with decimals
     // arr = {1.5, 3.2, 0.8, 2.7}
     // min = 0.8, max = 3.2
     double arr5[] = {1.5, 3.2, 0.8, 2.7};
     double min5, max5;
     findMinMax(arr5, 4, min5, max5);
     cout << "Test 5: " << (min5 == 0.8 && max5 == 3.2 ? "PASS" : "FAIL")
          << " (Expected: min=0.8, max=3.2; Got: min=" << min5 << ", max=" << max5 << ")" << endl;

     // Test Case 6: Min at end, max at start
     // arr = {100, 50, 75, 25, 10}
     // min = 10, max = 100
     int arr6[] = {100, 50, 75, 25, 10};
     int min6, max6;
     findMinMax(arr6, 5, min6, max6);
     cout << "Test 6: " << (min6 == 10 && max6 == 100 ? "PASS" : "FAIL")
          << " (Expected: min=10, max=100; Got: min=" << min6 << ", max=" << max6 << ")" << endl;

     // Test Case 7: With zeros
     // arr = {0, -5, 10, 0, 3}
     // min = -5, max = 10
     int arr7[] = {0, -5, 10, 0, 3};
     int min7, max7;
     findMinMax(arr7, 5, min7, max7);
     cout << "Test 7: " << (min7 == -5 && max7 == 10 ? "PASS" : "FAIL")
          << " (Expected: min=-5, max=10; Got: min=" << min7 << ", max=" << max7 << ")" << endl;

     // Test Case 8: Two elements
     // arr = {20, 10}
     // min = 10, max = 20
     int arr8[] = {20, 10};
     int min8, max8;
     findMinMax(arr8, 2, min8, max8);
     cout << "Test 8: " << (min8 == 10 && max8 == 20 ? "PASS" : "FAIL")
          << " (Expected: min=10, max=20; Got: min=" << min8 << ", max=" << max8 << ")" << endl;
}

void testProblem3()
{
     cout << "\n=== Testing Problem 3: Update Array Statistics ===" << endl;

     // Test Case 1: Simple case
     // arr = {10, 20, 30, 40}, size = 4
     // sum = 10+20+30+40 = 100
     // average = 100/4 = 25.0
     // elements > 25.0: {30, 40} = 2
     int arr1[] = {10, 20, 30, 40};
     int sum1;
     double avg1;
     int count1;
     calculateStats(arr1, 4, sum1, avg1, count1);
     cout << "Test 1: " << (sum1 == 100 && avg1 == 25.0 && count1 == 2 ? "PASS" : "FAIL")
          << " (Expected: sum=100, avg=25, count=2; Got: sum=" << sum1
          << ", avg=" << avg1 << ", count=" << count1 << ")" << endl;

     // Test Case 2: All same values
     // arr = {5, 5, 5, 5}, size = 4
     // sum = 20, average = 5.0
     // elements > 5.0: {} = 0
     int arr2[] = {5, 5, 5, 5};
     int sum2;
     double avg2;
     int count2;
     calculateStats(arr2, 4, sum2, avg2, count2);
     cout << "Test 2: " << (sum2 == 20 && avg2 == 5.0 && count2 == 0 ? "PASS" : "FAIL")
          << " (Expected: sum=20, avg=5, count=0; Got: sum=" << sum2
          << ", avg=" << avg2 << ", count=" << count2 << ")" << endl;

     // Test Case 3: Single element
     // arr = {42}, size = 1
     // sum = 42, average = 42.0
     // elements > 42.0: {} = 0
     int arr3[] = {42};
     int sum3;
     double avg3;
     int count3;
     calculateStats(arr3, 1, sum3, avg3, count3);
     cout << "Test 3: " << (sum3 == 42 && avg3 == 42.0 && count3 == 0 ? "PASS" : "FAIL")
          << " (Expected: sum=42, avg=42, count=0; Got: sum=" << sum3
          << ", avg=" << avg3 << ", count=" << count3 << ")" << endl;

     // Test Case 4: With negative numbers
     // arr = {-10, 0, 10, 20}, size = 4
     // sum = -10+0+10+20 = 20
     // average = 20/4 = 5.0
     // elements > 5.0: {10, 20} = 2
     int arr4[] = {-10, 0, 10, 20};
     int sum4;
     double avg4;
     int count4;
     calculateStats(arr4, 4, sum4, avg4, count4);
     cout << "Test 4: " << (sum4 == 20 && avg4 == 5.0 && count4 == 2 ? "PASS" : "FAIL")
          << " (Expected: sum=20, avg=5, count=2; Got: sum=" << sum4
          << ", avg=" << avg4 << ", count=" << count4 << ")" << endl;

     // Test Case 5: All elements above average
     // arr = {1, 2, 3, 10}, size = 4
     // sum = 1+2+3+10 = 16
     // average = 16/4 = 4.0
     // elements > 4.0: {10} = 1
     int arr5[] = {1, 2, 3, 10};
     int sum5;
     double avg5;
     int count5;
     calculateStats(arr5, 4, sum5, avg5, count5);
     cout << "Test 5: " << (sum5 == 16 && avg5 == 4.0 && count5 == 1 ? "PASS" : "FAIL")
          << " (Expected: sum=16, avg=4, count=1; Got: sum=" << sum5
          << ", avg=" << avg5 << ", count=" << count5 << ")" << endl;

     // Test Case 6: Doubles
     // arr = {1.5, 2.5, 3.5, 4.5}, size = 4
     // sum = 12.0, average = 3.0
     // elements > 3.0: {3.5, 4.5} = 2
     double arr6[] = {1.5, 2.5, 3.5, 4.5};
     double sum6;
     double avg6;
     int count6;
     calculateStats(arr6, 4, sum6, avg6, count6);
     cout << "Test 6: " << (sum6 == 12.0 && avg6 == 3.0 && count6 == 2 ? "PASS" : "FAIL")
          << " (Expected: sum=12, avg=3, count=2; Got: sum=" << sum6
          << ", avg=" << avg6 << ", count=" << count6 << ")" << endl;

     // Test Case 7: Two elements
     // arr = {100, 200}, size = 2
     // sum = 300, average = 150.0
     // elements > 150.0: {200} = 1
     int arr7[] = {100, 200};
     int sum7;
     double avg7;
     int count7;
     calculateStats(arr7, 2, sum7, avg7, count7);
     cout << "Test 7: " << (sum7 == 300 && avg7 == 150.0 && count7 == 1 ? "PASS" : "FAIL")
          << " (Expected: sum=300, avg=150, count=1; Got: sum=" << sum7
          << ", avg=" << avg7 << ", count=" << count7 << ")" << endl;

     // Test Case 8: All below average except one
     // arr = {1, 1, 1, 97}, size = 4
     // sum = 100, average = 25.0
     // elements > 25.0: {97} = 1
     int arr8[] = {1, 1, 1, 97};
     int sum8;
     double avg8;
     int count8;
     calculateStats(arr8, 4, sum8, avg8, count8);
     cout << "Test 8: " << (sum8 == 100 && avg8 == 25.0 && count8 == 1 ? "PASS" : "FAIL")
          << " (Expected: sum=100, avg=25, count=1; Got: sum=" << sum8
          << ", avg=" << avg8 << ", count=" << count8 << ")" << endl;
}

void testProblem4()
{
     cout << "\n=== Testing Problem 4: Partition Array Around Pivot ===" << endl;

     // Test Case 1: Mixed values with pivot in middle
     // arr = {7, 2, 9, 1, 5, 3}, pivot = 5
     // Elements < 5: {2, 1, 3} = 3 elements
     // After partition: all elements < 5 should be on left
     int arr1[] = {7, 2, 9, 1, 5, 3};
     int count1;
     partitionArray(arr1, 6, 5, count1);
     bool test1_pass = (count1 == 3);
     // Verify partition: first 3 elements should be < 5, rest >= 5
     for (int i = 0; i < count1 && test1_pass; i++)
     {
          if (arr1[i] >= 5)
               test1_pass = false;
     }
     for (int i = count1; i < 6 && test1_pass; i++)
     {
          if (arr1[i] < 5)
               test1_pass = false;
     }
     cout << "Test 1: " << (test1_pass ? "PASS" : "FAIL")
          << " (Expected: leftCount=3; Got: leftCount=" << count1 << ")" << endl;

     // Test Case 2: All elements greater than pivot
     // arr = {10, 20, 30}, pivot = 5
     // Elements < 5: {} = 0 elements
     int arr2[] = {10, 20, 30};
     int count2;
     partitionArray(arr2, 3, 5, count2);
     bool test2_pass = (count2 == 0);
     for (int i = 0; i < 3 && test2_pass; i++)
     {
          if (arr2[i] < 5)
               test2_pass = false;
     }
     cout << "Test 2: " << (test2_pass ? "PASS" : "FAIL")
          << " (Expected: leftCount=0; Got: leftCount=" << count2 << ")" << endl;

     // Test Case 3: All elements less than pivot
     // arr = {1, 2, 3}, pivot = 10
     // Elements < 10: {1, 2, 3} = 3 elements
     int arr3[] = {1, 2, 3};
     int count3;
     partitionArray(arr3, 3, 10, count3);
     bool test3_pass = (count3 == 3);
     for (int i = 0; i < 3 && test3_pass; i++)
     {
          if (arr3[i] >= 10)
               test3_pass = false;
     }
     cout << "Test 3: " << (test3_pass ? "PASS" : "FAIL")
          << " (Expected: leftCount=3; Got: leftCount=" << count3 << ")" << endl;

     // Test Case 4: Single element less than pivot
     // arr = {5}, pivot = 10
     // Elements < 10: {5} = 1 element
     int arr4[] = {5};
     int count4;
     partitionArray(arr4, 1, 10, count4);
     cout << "Test 4: " << (count4 == 1 && arr4[0] == 5 ? "PASS" : "FAIL")
          << " (Expected: leftCount=1; Got: leftCount=" << count4 << ")" << endl;

     // Test Case 5: Single element greater than pivot
     // arr = {15}, pivot = 10
     // Elements < 10: {} = 0 elements
     int arr5[] = {15};
     int count5;
     partitionArray(arr5, 1, 10, count5);
     cout << "Test 5: " << (count5 == 0 && arr5[0] == 15 ? "PASS" : "FAIL")
          << " (Expected: leftCount=0; Got: leftCount=" << count5 << ")" << endl;

     // Test Case 6: Pivot equals some elements
     // arr = {5, 10, 5, 20, 5}, pivot = 10
     // Elements < 10: {5, 5, 5} = 3 elements (10 and 20 are >= 10)
     int arr6[] = {5, 10, 5, 20, 5};
     int count6;
     partitionArray(arr6, 5, 10, count6);
     bool test6_pass = (count6 == 3);
     for (int i = 0; i < count6 && test6_pass; i++)
     {
          if (arr6[i] >= 10)
               test6_pass = false;
     }
     for (int i = count6; i < 5 && test6_pass; i++)
     {
          if (arr6[i] < 10)
               test6_pass = false;
     }
     cout << "Test 6: " << (test6_pass ? "PASS" : "FAIL")
          << " (Expected: leftCount=3; Got: leftCount=" << count6 << ")" << endl;

     // Test Case 7: Negative numbers
     // arr = {-5, 3, -2, 8, -1, 0}, pivot = 0
     // Elements < 0: {-5, -2, -1} = 3 elements
     int arr7[] = {-5, 3, -2, 8, -1, 0};
     int count7;
     partitionArray(arr7, 6, 0, count7);
     bool test7_pass = (count7 == 3);
     for (int i = 0; i < count7 && test7_pass; i++)
     {
          if (arr7[i] >= 0)
               test7_pass = false;
     }
     for (int i = count7; i < 6 && test7_pass; i++)
     {
          if (arr7[i] < 0)
               test7_pass = false;
     }
     cout << "Test 7: " << (test7_pass ? "PASS" : "FAIL")
          << " (Expected: leftCount=3; Got: leftCount=" << count7 << ")" << endl;

     // Test Case 8: Already partitioned
     // arr = {1, 2, 3, 7, 8, 9}, pivot = 5
     // Elements < 5: {1, 2, 3} = 3 elements
     int arr8[] = {1, 2, 3, 7, 8, 9};
     int count8;
     partitionArray(arr8, 6, 5, count8);
     bool test8_pass = (count8 == 3);
     for (int i = 0; i < count8 && test8_pass; i++)
     {
          if (arr8[i] >= 5)
               test8_pass = false;
     }
     for (int i = count8; i < 6 && test8_pass; i++)
     {
          if (arr8[i] < 5)
               test8_pass = false;
     }
     cout << "Test 8: " << (test8_pass ? "PASS" : "FAIL")
          << " (Expected: leftCount=3; Got: leftCount=" << count8 << ")" << endl;
}

int main()
{
     int choice;
     cout << "==================================================" << endl;
     cout << "   Template Parameters by Reference - Practice   " << endl;
     cout << "==================================================" << endl;
     cout << "\nChoose a problem to test (1-4) or 5 to test all:" << endl;
     cout << "1. Problem 1 (Easy) - Swap Two Values" << endl;
     cout << "2. Problem 2 (Easy) - Find Maximum and Minimum" << endl;
     cout << "3. Problem 3 (Medium) - Update Array Statistics" << endl;
     cout << "4. Problem 4 (Hard) - Partition Array Around Pivot" << endl;
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
          cout << "Invalid choice!" << endl;
     }

     cout << "\n==================================================" << endl;
     cout << "                Testing Complete!                  " << endl;
     cout << "==================================================" << endl;

     return 0;
}