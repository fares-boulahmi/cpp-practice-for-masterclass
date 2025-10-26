#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <climits>

using namespace std;

// Problem 1: Easy 1 - Swap Two Numbers
// Description: Write a function that swaps two integer values using pass by reference.
// This is the classic example demonstrating how pass by reference allows a function
// to modify the original variables passed to it.
//
// Input Format: Two integers a and b
// Output Format: The function should swap the values (no return value needed)
//
// Example 1:
//   Before: a = 5, b = 10
//   After:  a = 10, b = 5
//
// Example 2:
//   Before: a = -3, b = 7
//   After:  a = 7, b = -3
//
// Constraints:
//   -1000 <= a, b <= 1000
void swapNumbers(int &a, int &b)
{
     // TODO: Implement your solution here using pass by reference
     // Hint: You'll need a temporary variable to hold one value during the swap
     int reserve = a;
     a = b;
     b = reserve;
}

// Problem 2: Easy 2 - Calculate Circle Properties
// Description: Write a function that calculates both the area and circumference of a circle
// given its radius. Since we need to return TWO values, use pass by reference for the
// area and circumference parameters.
//
// Formula: Area = π * r² (use 3.14159 for π)
//          Circumference = 2 * π * r
//
// Input Format: radius (double), area (double&), circumference (double&)
// Output Format: The function modifies area and circumference through references
//
// Example 1:
//   Input: radius = 5.0
//   Output: area = 78.53975, circumference = 31.4159
//
// Example 2:
//   Input: radius = 10.0
//   Output: area = 314.159, circumference = 62.8318
//
// Constraints:
//   0 < radius <= 1000.0
void calculateCircle(double radius, double &area, double &circumference)
{
     // TODO: Implement your solution here using pass by reference
     // Hint: Calculate both values and assign them to the reference parameters
     double p = 3.14159;
     area = p * (radius * radius);
     circumference = 2 * radius * p;
}

// Problem 3: Medium - Find Min and Max in Array
// Description: Write a function that finds both the minimum and maximum values in an array.
// Use pass by reference to return both values. Also, use pass by reference for the array
// to avoid copying large amounts of data.
//
// Input Format: vector of integers (passed by reference), min (int&), max (int&)
// Output Format: The function modifies min and max through references
//
// Example 1:
//   Input: arr = {3, 7, 1, 9, 2}
//   Output: min = 1, max = 9
//
// Example 2:
//   Input: arr = {-5, -2, -10, -1}
//   Output: min = -10, max = -1
//
// Constraints:
//   1 <= arr.size() <= 10000
//   -10000 <= arr[i] <= 10000
void findMinMax(const vector<int> &arr, int &minVal, int &maxVal)
{
     // TODO: Implement your solution here using pass by reference
     // Hint: Initialize min and max with the first element, then iterate through the array
     // Note: The array is passed by const reference (read-only) for efficiency
     if (arr.size() == 0)
     {
          minVal = 0;
          maxVal = 0;
          return;
     }
     minVal = INT_MAX;
     maxVal = INT_MIN;
     for (size_t i = 0; i < arr.size(); i++)
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
}

// Problem 4: Hard - Solve Quadratic Equation
// Description: Write a function that solves a quadratic equation ax² + bx + c = 0
// The function should find both roots (if they exist) and indicate how many real roots exist.
// Use pass by reference for the two roots and return the number of real roots.
//
// Formula: x = (-b ± √(b²-4ac)) / 2a
//          Discriminant = b² - 4ac
//          If discriminant > 0: two distinct real roots
//          If discriminant = 0: one real root (both roots are the same)
//          If discriminant < 0: no real roots
//
// Input Format: a, b, c (coefficients), root1 (double&), root2 (double&)
// Output Format: Returns number of real roots (0, 1, or 2)
//                Modifies root1 and root2 through references
//
// Example 1:
//   Input: a=1, b=-5, c=6  (equation: x² - 5x + 6 = 0)
//   Discriminant: 25 - 24 = 1
//   Output: 2 roots, root1 = 3.0, root2 = 2.0
//
// Example 2:
//   Input: a=1, b=-4, c=4  (equation: x² - 4x + 4 = 0)
//   Discriminant: 16 - 16 = 0
//   Output: 1 root, root1 = 2.0, root2 = 2.0
//
// Example 3:
//   Input: a=1, b=0, c=1  (equation: x² + 1 = 0)
//   Discriminant: 0 - 4 = -4
//   Output: 0 roots
//
// Constraints:
//   a != 0 (not a linear equation)
//   -1000 <= a, b, c <= 1000
int solveQuadratic(double a, double b, double c, double &root1, double &root2)
{
     // TODO: Implement your solution here using pass by reference
     // Hint: Calculate discriminant first, then determine number of roots
     // Hint: Use sqrt() from <cmath> for square root
     // Hint: root1 should be the larger root, root2 the smaller (or both equal)
     return 0;
}

void testProblem1()
{
     cout << "\n=== Testing Problem 1: Swap Two Numbers ===" << endl;

     // Test Case 1: Basic positive numbers
     // Before: a=5, b=10
     // After: a=10, b=5
     int a1 = 5, b1 = 10;
     swapNumbers(a1, b1);
     cout << "Test 1: " << ((a1 == 10 && b1 == 5) ? "PASS" : "FAIL")
          << " (Expected: a=10, b=5, Got: a=" << a1 << ", b=" << b1 << ")" << endl;

     // Test Case 2: Negative and positive
     // Before: a=-3, b=7
     // After: a=7, b=-3
     int a2 = -3, b2 = 7;
     swapNumbers(a2, b2);
     cout << "Test 2: " << ((a2 == 7 && b2 == -3) ? "PASS" : "FAIL")
          << " (Expected: a=7, b=-3, Got: a=" << a2 << ", b=" << b2 << ")" << endl;

     // Test Case 3: Both negative
     // Before: a=-15, b=-20
     // After: a=-20, b=-15
     int a3 = -15, b3 = -20;
     swapNumbers(a3, b3);
     cout << "Test 3: " << ((a3 == -20 && b3 == -15) ? "PASS" : "FAIL")
          << " (Expected: a=-20, b=-15, Got: a=" << a3 << ", b=" << b3 << ")" << endl;

     // Test Case 4: Same values
     // Before: a=100, b=100
     // After: a=100, b=100
     int a4 = 100, b4 = 100;
     swapNumbers(a4, b4);
     cout << "Test 4: " << ((a4 == 100 && b4 == 100) ? "PASS" : "FAIL")
          << " (Expected: a=100, b=100, Got: a=" << a4 << ", b=" << b4 << ")" << endl;

     // Test Case 5: Zero and positive
     // Before: a=0, b=50
     // After: a=50, b=0
     int a5 = 0, b5 = 50;
     swapNumbers(a5, b5);
     cout << "Test 5: " << ((a5 == 50 && b5 == 0) ? "PASS" : "FAIL")
          << " (Expected: a=50, b=0, Got: a=" << a5 << ", b=" << b5 << ")" << endl;

     // Test Case 6: Large numbers
     // Before: a=999, b=-999
     // After: a=-999, b=999
     int a6 = 999, b6 = -999;
     swapNumbers(a6, b6);
     cout << "Test 6: " << ((a6 == -999 && b6 == 999) ? "PASS" : "FAIL")
          << " (Expected: a=-999, b=999, Got: a=" << a6 << ", b=" << b6 << ")" << endl;

     // Test Case 7: One is zero
     // Before: a=42, b=0
     // After: a=0, b=42
     int a7 = 42, b7 = 0;
     swapNumbers(a7, b7);
     cout << "Test 7: " << ((a7 == 0 && b7 == 42) ? "PASS" : "FAIL")
          << " (Expected: a=0, b=42, Got: a=" << a7 << ", b=" << b7 << ")" << endl;

     // Test Case 8: Both zero
     // Before: a=0, b=0
     // After: a=0, b=0
     int a8 = 0, b8 = 0;
     swapNumbers(a8, b8);
     cout << "Test 8: " << ((a8 == 0 && b8 == 0) ? "PASS" : "FAIL")
          << " (Expected: a=0, b=0, Got: a=" << a8 << ", b=" << b8 << ")" << endl;
}

void testProblem2()
{
     cout << "\n=== Testing Problem 2: Calculate Circle Properties ===" << endl;
     const double PI = 3.14159;
     const double EPSILON = 0.001; // Tolerance for floating point comparison

     // Test Case 1: radius = 5.0
     // Area = π * 5² = 3.14159 * 25 = 78.53975
     // Circumference = 2 * π * 5 = 2 * 3.14159 * 5 = 31.4159
     double area1, circ1;
     calculateCircle(5.0, area1, circ1);
     cout << "Test 1: " << ((abs(area1 - 78.53975) < EPSILON && abs(circ1 - 31.4159) < EPSILON) ? "PASS" : "FAIL")
          << " (Expected: area=78.53975, circ=31.4159, Got: area=" << area1 << ", circ=" << circ1 << ")" << endl;

     // Test Case 2: radius = 10.0
     // Area = π * 10² = 3.14159 * 100 = 314.159
     // Circumference = 2 * π * 10 = 2 * 3.14159 * 10 = 62.8318
     double area2, circ2;
     calculateCircle(10.0, area2, circ2);
     cout << "Test 2: " << ((abs(area2 - 314.159) < EPSILON && abs(circ2 - 62.8318) < EPSILON) ? "PASS" : "FAIL")
          << " (Expected: area=314.159, circ=62.8318, Got: area=" << area2 << ", circ=" << circ2 << ")" << endl;

     // Test Case 3: radius = 1.0
     // Area = π * 1² = 3.14159 * 1 = 3.14159
     // Circumference = 2 * π * 1 = 2 * 3.14159 * 1 = 6.28318
     double area3, circ3;
     calculateCircle(1.0, area3, circ3);
     cout << "Test 3: " << ((abs(area3 - 3.14159) < EPSILON && abs(circ3 - 6.28318) < EPSILON) ? "PASS" : "FAIL")
          << " (Expected: area=3.14159, circ=6.28318, Got: area=" << area3 << ", circ=" << circ3 << ")" << endl;

     // Test Case 4: radius = 7.5
     // Area = π * 7.5² = 3.14159 * 56.25 = 176.714625
     // Circumference = 2 * π * 7.5 = 2 * 3.14159 * 7.5 = 47.12385
     double area4, circ4;
     calculateCircle(7.5, area4, circ4);
     cout << "Test 4: " << ((abs(area4 - 176.714625) < EPSILON && abs(circ4 - 47.12385) < EPSILON) ? "PASS" : "FAIL")
          << " (Expected: area=176.714625, circ=47.12385, Got: area=" << area4 << ", circ=" << circ4 << ")" << endl;

     // Test Case 5: radius = 0.5
     // Area = π * 0.5² = 3.14159 * 0.25 = 0.7853975
     // Circumference = 2 * π * 0.5 = 2 * 3.14159 * 0.5 = 3.14159
     double area5, circ5;
     calculateCircle(0.5, area5, circ5);
     cout << "Test 5: " << ((abs(area5 - 0.7853975) < EPSILON && abs(circ5 - 3.14159) < EPSILON) ? "PASS" : "FAIL")
          << " (Expected: area=0.7853975, circ=3.14159, Got: area=" << area5 << ", circ=" << circ5 << ")" << endl;

     // Test Case 6: radius = 20.0
     // Area = π * 20² = 3.14159 * 400 = 1256.636
     // Circumference = 2 * π * 20 = 2 * 3.14159 * 20 = 125.6636
     double area6, circ6;
     calculateCircle(20.0, area6, circ6);
     cout << "Test 6: " << ((abs(area6 - 1256.636) < EPSILON && abs(circ6 - 125.6636) < EPSILON) ? "PASS" : "FAIL")
          << " (Expected: area=1256.636, circ=125.6636, Got: area=" << area6 << ", circ=" << circ6 << ")" << endl;

     // Test Case 7: radius = 3.0
     // Area = π * 3² = 3.14159 * 9 = 28.27431
     // Circumference = 2 * π * 3 = 2 * 3.14159 * 3 = 18.84954
     double area7, circ7;
     calculateCircle(3.0, area7, circ7);
     cout << "Test 7: " << ((abs(area7 - 28.27431) < EPSILON && abs(circ7 - 18.84954) < EPSILON) ? "PASS" : "FAIL")
          << " (Expected: area=28.27431, circ=18.84954, Got: area=" << area7 << ", circ=" << circ7 << ")" << endl;

     // Test Case 8: radius = 100.0
     // Area = π * 100² = 3.14159 * 10000 = 31415.9
     // Circumference = 2 * π * 100 = 2 * 3.14159 * 100 = 628.318
     double area8, circ8;
     calculateCircle(100.0, area8, circ8);
     cout << "Test 8: " << ((abs(area8 - 31415.9) < EPSILON && abs(circ8 - 628.318) < EPSILON) ? "PASS" : "FAIL")
          << " (Expected: area=31415.9, circ=628.318, Got: area=" << area8 << ", circ=" << circ8 << ")" << endl;
}

void testProblem3()
{
     cout << "\n=== Testing Problem 3: Find Min and Max in Array ===" << endl;

     // Test Case 1: Mixed positive numbers
     // Array: {3, 7, 1, 9, 2}
     // Min = 1, Max = 9
     vector<int> arr1 = {3, 7, 1, 9, 2};
     int min1, max1;
     findMinMax(arr1, min1, max1);
     cout << "Test 1: " << ((min1 == 1 && max1 == 9) ? "PASS" : "FAIL")
          << " (Expected: min=1, max=9, Got: min=" << min1 << ", max=" << max1 << ")" << endl;

     // Test Case 2: All negative numbers
     // Array: {-5, -2, -10, -1}
     // Min = -10, Max = -1
     vector<int> arr2 = {-5, -2, -10, -1};
     int min2, max2;
     findMinMax(arr2, min2, max2);
     cout << "Test 2: " << ((min2 == -10 && max2 == -1) ? "PASS" : "FAIL")
          << " (Expected: min=-10, max=-1, Got: min=" << min2 << ", max=" << max2 << ")" << endl;

     // Test Case 3: Single element
     // Array: {42}
     // Min = 42, Max = 42
     vector<int> arr3 = {42};
     int min3, max3;
     findMinMax(arr3, min3, max3);
     cout << "Test 3: " << ((min3 == 42 && max3 == 42) ? "PASS" : "FAIL")
          << " (Expected: min=42, max=42, Got: min=" << min3 << ", max=" << max3 << ")" << endl;

     // Test Case 4: All same values
     // Array: {5, 5, 5, 5}
     // Min = 5, Max = 5
     vector<int> arr4 = {5, 5, 5, 5};
     int min4, max4;
     findMinMax(arr4, min4, max4);
     cout << "Test 4: " << ((min4 == 5 && max4 == 5) ? "PASS" : "FAIL")
          << " (Expected: min=5, max=5, Got: min=" << min4 << ", max=" << max4 << ")" << endl;

     // Test Case 5: Min at start, Max at end
     // Array: {1, 5, 3, 7, 10}
     // Min = 1, Max = 10
     vector<int> arr5 = {1, 5, 3, 7, 10};
     int min5, max5;
     findMinMax(arr5, min5, max5);
     cout << "Test 5: " << ((min5 == 1 && max5 == 10) ? "PASS" : "FAIL")
          << " (Expected: min=1, max=10, Got: min=" << min5 << ", max=" << max5 << ")" << endl;

     // Test Case 6: Max at start, Min at end
     // Array: {100, 50, 25, 10, -5}
     // Min = -5, Max = 100
     vector<int> arr6 = {100, 50, 25, 10, -5};
     int min6, max6;
     findMinMax(arr6, min6, max6);
     cout << "Test 6: " << ((min6 == -5 && max6 == 100) ? "PASS" : "FAIL")
          << " (Expected: min=-5, max=100, Got: min=" << min6 << ", max=" << max6 << ")" << endl;

     // Test Case 7: Contains zero
     // Array: {-3, 0, 5, -8, 12}
     // Min = -8, Max = 12
     vector<int> arr7 = {-3, 0, 5, -8, 12};
     int min7, max7;
     findMinMax(arr7, min7, max7);
     cout << "Test 7: " << ((min7 == -8 && max7 == 12) ? "PASS" : "FAIL")
          << " (Expected: min=-8, max=12, Got: min=" << min7 << ", max=" << max7 << ")" << endl;

     // Test Case 8: Two elements
     // Array: {15, 3}
     // Min = 3, Max = 15
     vector<int> arr8 = {15, 3};
     int min8, max8;
     findMinMax(arr8, min8, max8);
     cout << "Test 8: " << ((min8 == 3 && max8 == 15) ? "PASS" : "FAIL")
          << " (Expected: min=3, max=15, Got: min=" << min8 << ", max=" << max8 << ")" << endl;
}

void testProblem4()
{
     cout << "\n=== Testing Problem 4: Solve Quadratic Equation ===" << endl;
     const double EPSILON = 0.001;

     // Test Case 1: Two distinct roots
     // Equation: x² - 5x + 6 = 0 (a=1, b=-5, c=6)
     // Discriminant = (-5)² - 4(1)(6) = 25 - 24 = 1
     // root1 = (5 + 1) / 2 = 3.0
     // root2 = (5 - 1) / 2 = 2.0
     double r1_1, r2_1;
     int roots1 = solveQuadratic(1, -5, 6, r1_1, r2_1);
     cout << "Test 1: " << ((roots1 == 2 && abs(r1_1 - 3.0) < EPSILON && abs(r2_1 - 2.0) < EPSILON) ? "PASS" : "FAIL")
          << " (Expected: 2 roots, root1=3.0, root2=2.0, Got: " << roots1 << " roots, root1=" << r1_1 << ", root2=" << r2_1 << ")" << endl;

     // Test Case 2: One root (repeated)
     // Equation: x² - 4x + 4 = 0 (a=1, b=-4, c=4)
     // Discriminant = (-4)² - 4(1)(4) = 16 - 16 = 0
     // root1 = root2 = 4 / 2 = 2.0
     double r1_2, r2_2;
     int roots2 = solveQuadratic(1, -4, 4, r1_2, r2_2);
     cout << "Test 2: " << ((roots2 == 1 && abs(r1_2 - 2.0) < EPSILON && abs(r2_2 - 2.0) < EPSILON) ? "PASS" : "FAIL")
          << " (Expected: 1 root, root1=2.0, root2=2.0, Got: " << roots2 << " roots, root1=" << r1_2 << ", root2=" << r2_2 << ")" << endl;

     // Test Case 3: No real roots
     // Equation: x² + 1 = 0 (a=1, b=0, c=1)
     // Discriminant = 0² - 4(1)(1) = 0 - 4 = -4 (negative)
     double r1_3, r2_3;
     int roots3 = solveQuadratic(1, 0, 1, r1_3, r2_3);
     cout << "Test 3: " << (roots3 == 0 ? "PASS" : "FAIL")
          << " (Expected: 0 roots, Got: " << roots3 << " roots)" << endl;

     // Test Case 4: Two distinct roots (negative coefficients)
     // Equation: x² + 2x - 8 = 0 (a=1, b=2, c=-8)
     // Discriminant = 2² - 4(1)(-8) = 4 + 32 = 36
     // root1 = (-2 + 6) / 2 = 2.0
     // root2 = (-2 - 6) / 2 = -4.0
     double r1_4, r2_4;
     int roots4 = solveQuadratic(1, 2, -8, r1_4, r2_4);
     cout << "Test 4: " << ((roots4 == 2 && abs(r1_4 - 2.0) < EPSILON && abs(r2_4 - (-4.0)) < EPSILON) ? "PASS" : "FAIL")
          << " (Expected: 2 roots, root1=2.0, root2=-4.0, Got: " << roots4 << " roots, root1=" << r1_4 << ", root2=" << r2_4 << ")" << endl;

     // Test Case 5: Two distinct roots (a=2)
     // Equation: 2x² - 8x + 6 = 0 (a=2, b=-8, c=6)
     // Discriminant = (-8)² - 4(2)(6) = 64 - 48 = 16
     // root1 = (8 + 4) / 4 = 3.0
     // root2 = (8 - 4) / 4 = 1.0
     double r1_5, r2_5;
     int roots5 = solveQuadratic(2, -8, 6, r1_5, r2_5);
     cout << "Test 5: " << ((roots5 == 2 && abs(r1_5 - 3.0) < EPSILON && abs(r2_5 - 1.0) < EPSILON) ? "PASS" : "FAIL")
          << " (Expected: 2 roots, root1=3.0, root2=1.0, Got: " << roots5 << " roots, root1=" << r1_5 << ", root2=" << r2_5 << ")" << endl;

     // Test Case 6: No real roots (positive discriminant check)
     // Equation: 2x² + 3x + 5 = 0 (a=2, b=3, c=5)
     // Discriminant = 3² - 4(2)(5) = 9 - 40 = -31 (negative)
     double r1_6, r2_6;
     int roots6 = solveQuadratic(2, 3, 5, r1_6, r2_6);
     cout << "Test 6: " << (roots6 == 0 ? "PASS" : "FAIL")
          << " (Expected: 0 roots, Got: " << roots6 << " roots)" << endl;

     // Test Case 7: One root (a=-1)
     // Equation: -x² + 6x - 9 = 0 (a=-1, b=6, c=-9)
     // Discriminant = 6² - 4(-1)(-9) = 36 - 36 = 0
     // root1 = root2 = -6 / -2 = 3.0
     double r1_7, r2_7;
     int roots7 = solveQuadratic(-1, 6, -9, r1_7, r2_7);
     cout << "Test 7: " << ((roots7 == 1 && abs(r1_7 - 3.0) < EPSILON && abs(r2_7 - 3.0) < EPSILON) ? "PASS" : "FAIL")
          << " (Expected: 1 root, root1=3.0, root2=3.0, Got: " << roots7 << " roots, root1=" << r1_7 << ", root2=" << r2_7 << ")" << endl;

     // Test Case 8: Two distinct roots (both negative)
     // Equation: x² + 7x + 10 = 0 (a=1, b=7, c=10)
     // Discriminant = 7² - 4(1)(10) = 49 - 40 = 9
     // root1 = (-7 + 3) / 2 = -2.0
     // root2 = (-7 - 3) / 2 = -5.0
     double r1_8, r2_8;
     int roots8 = solveQuadratic(1, 7, 10, r1_8, r2_8);
     cout << "Test 8: " << ((roots8 == 2 && abs(r1_8 - (-2.0)) < EPSILON && abs(r2_8 - (-5.0)) < EPSILON) ? "PASS" : "FAIL")
          << " (Expected: 2 roots, root1=-2.0, root2=-5.0, Got: " << roots8 << " roots, root1=" << r1_8 << ", root2=" << r2_8 << ")" << endl;
}

int main()
{
     int choice;
     cout << "=== C++ Pass by Reference Practice Problems ===" << endl;
     cout << "Choose a problem to test (1-4) or 5 to test all:" << endl;
     cout << "1. Problem 1 (Easy) - Swap Two Numbers" << endl;
     cout << "2. Problem 2 (Easy) - Calculate Circle Properties" << endl;
     cout << "3. Problem 3 (Medium) - Find Min and Max in Array" << endl;
     cout << "4. Problem 4 (Hard) - Solve Quadratic Equation" << endl;
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