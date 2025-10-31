#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

//=== SECTION A: INTEGRATION PROBLEMS ===

// Problem A1: Foundation Integration - Array Statistics Calculator
// Create a function that takes an integer array and its size, then calculates and returns
// basic statistics. This combines array declaration, array traversal, and basic operations.
//
// Examples:
// Input: arr = [1, 2, 3, 4, 5], size = 5
// Output: sum = 15, average = 3.0, min = 1, max = 5
//
// Input: arr = [10, -5, 0, 8], size = 4
// Output: sum = 13, average = 3.25, min = -5, max = 10
//
// The function should store results in reference parameters:
// void calculateArrayStats(int arr[], int size, int& sum, double& average, int& min, int& max)
//
// Input/Output format:
// - Input: integer array and size
// - Output: sum (int), average (double), minimum (int), maximum (int) via reference
//
// Constraints:
// - Array size: 1 ≤ size ≤ 100
// - Array elements: -1000 ≤ element ≤ 1000
// - Handle single element arrays correctly
void calculateArrayStats(int arr[], int size, int &sum, double &average, int &min, int &max)
{
    // TODO: Solve using array traversal, arithmetic operations, and conditional statements
    // Hint: Initialize min and max to first element, then iterate through remaining elements
    min = INT_MAX ;
    max= INT_MIN;
    sum= 0;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        } 
        if (arr[i] > max) {
            max = arr[i];
        }
        sum += arr[i];
     }
     double sum_double = sum * 1.0;
     double size_double = size * 1.0;
     average = sum_double / size_double  ;
    
}

// Problem A2: Intermediate Synthesis - Character Array Word Counter
// Create a function that analyzes a character array (C-string) and counts various elements.
// This combines character arrays, string processing, and control flow.
//
// The function should count: total characters (excluding null terminator), vowels,
// consonants, digits, spaces, and words.
//
// Examples:
// Input: "Hello World 123"
// Output: chars=13, vowels=3, consonants=7, digits=3, spaces=2, words=3
//
// Input: "Programming is fun!"
// Output: chars=18, vowels=6, consonants=10, digits=0, spaces=2, words=3
//
// Function signature:
// void analyzeCharArray(char str[], int& totalChars, int& vowels, int& consonants,
//                       int& digits, int& spaces, int& words)
//
// Input/Output format:
// - Input: null-terminated character array
// - Output: counts via reference parameters
//
// Constraints:
// - String length: 1 ≤ length ≤ 200
// - Only ASCII characters
// - Words are separated by spaces
// - Count only alphabetic characters as vowels/consonants
void analyzeCharArray(char str[], int &totalChars, int &vowels, int &consonants,
                      int &digits, int &spaces, int &words)
{
    // TODO: Solve using character array traversal, character classification, and counting logic
    // Hint: Use ASCII values or character comparisons to classify each character
    totalChars = 0;
    vowels = 0;
    consonants = 0 ;
    digits = 0;
    spaces = 0;
    words = 0;
    int alpha_number = 0;
    string word = str;
    string vowel = {"aeiouAEIOU"};
    for (size_t i = 0; i < word.size(); i++)
    {
        if (isalpha(word[i]))
        {
            alpha_number++;
        }
        if (word[i] == ' ')
        {
            spaces++;
        }
        if (isdigit(word[i]))
        {
            digits++;
        }
        for (size_t j = 0; j < vowel.size(); j++)
        {
            if (word[i] == vowel[j])
            {
                vowels++;
            }
            
        }
        
        
    }
    
    totalChars = word.size();
    consonants = alpha_number - vowels ;
    words = (!consonants && !vowels && !digits) ? 0 : spaces + 1;


}

// Problem A3: Advanced Integration - Array Rotation and Searching
// Create a function that rotates an integer array to the right by k positions,
// then searches for a target value. This combines array manipulation, loops, and searching.
//
// The rotation should be performed in-place, and the search should return the index
// of the target after rotation (-1 if not found).
//
// Examples:
// Input: arr = [1, 2, 3, 4, 5], size = 5, k = 2, target = 3
// Process: [1, 2, 3, 4, 5] → [4, 5, 1, 2, 3] (rotate right by 2)
// Search for 3: found at index 4
// Output: 4
//
// Input: arr = [7, 8, 9, 1, 2], size = 5, k = 3, target = 7
// Process: [7, 8, 9, 1, 2] → [9, 1, 2, 7, 8] (rotate right by 3)
// Search for 7: found at index 3
// Output: 3
//
// Function signature:
// int rotateAndSearch(int arr[], int size, int k, int target)
//
// Input/Output format:
// - Input: array, size, rotation amount k, target value
// - Output: index of target after rotation (-1 if not found)
//
// Constraints:
// - Array size: 1 ≤ size ≤ 50
// - Rotation amount: 0 ≤ k ≤ 1000
// - Handle k > size by using modulo operation
int rotateAndSearch(int arr[], int size, int k, int target)
{
    // TODO: Solve using array manipulation, modulo arithmetic, and linear search
    // Hint: k % size gives effective rotation, use temporary storage or reverse technique
    return 0;
}

// Problem A4: Complex Synthesis - Multi-Array Pattern Matching
// Create a function that finds if a pattern array exists as a contiguous subsequence
// in a main array. This combines nested loops, array comparison, and pattern matching.
//
// The function should return the starting index where the pattern begins in the main array,
// or -1 if the pattern is not found.
//
// Examples:
// Input: main = [1, 2, 3, 4, 5, 6], mainSize = 6, pattern = [3, 4, 5], patternSize = 3
// Process: Check [1,2,3] ≠ [3,4,5], [2,3,4] ≠ [3,4,5], [3,4,5] = [3,4,5] ✓
// Output: 2 (pattern starts at index 2)
//
// Input: main = [7, 8, 9, 1, 2], mainSize = 5, pattern = [9, 1, 3], patternSize = 3
// Process: No match found
// Output: -1
//
// Function signature:
// int findPatternInArray(int mainArr[], int mainSize, int pattern[], int patternSize)
//
// Input/Output format:
// - Input: main array with size, pattern array with size
// - Output: starting index of pattern (-1 if not found)
//
// Constraints:
// - Main array size: 1 ≤ mainSize ≤ 100
// - Pattern array size: 1 ≤ patternSize ≤ mainSize
// - Array elements: -100 ≤ element ≤ 100
int findPatternInArray(int mainArr[], int mainSize, int pattern[], int patternSize)
{
    // TODO: Solve using nested loops, array comparison, and early termination
    // Hint: For each position in main array, check if pattern matches starting from that position
    return 0;
}

// Problem A5: Mastery Challenge - Dynamic Array Merger and Sorter
// Create a function that merges multiple sorted integer arrays into one sorted array.
// This integrates array processing, sorting concepts, and dynamic size handling.
//
// The function takes an array of arrays (2D array), their individual sizes, and the count
// of arrays to merge. It should return the size of the merged result array.
//
// Examples:
// Input:
// arrays[0] = [1, 4, 7], size[0] = 3
// arrays[1] = [2, 5, 8], size[1] = 3
// arrays[2] = [3, 6, 9], size[2] = 3
// arrayCount = 3
// Output: result = [1, 2, 3, 4, 5, 6, 7, 8, 9], return size = 9
//
// Input:
// arrays[0] = [1, 3, 5], size[0] = 3
// arrays[1] = [2, 4], size[1] = 2
// arrays[2] = [6, 7, 8, 9], size[2] = 4
// arrayCount = 3
// Output: result = [1, 2, 3, 4, 5, 6, 7, 8, 9], return size = 9
//
// Function signature:
// int mergeAndSortArrays(int arrays[][10], int sizes[], int arrayCount, int result[])
//
// Input/Output format:
// - Input: 2D array (max 10 elements per sub-array), array of sizes, count of arrays
// - Output: merged sorted result array, return total size
//
// Constraints:
// - Number of arrays: 1 ≤ arrayCount ≤ 10
// - Each array size: 1 ≤ size ≤ 10
// - Total elements ≤ 100
// - Each input array is already sorted
int mergeAndSortArrays(int arrays[][10], int sizes[], int arrayCount, int result[])
{
    // TODO: Solve using array traversal, comparison, and sorting algorithms
    // Hint: Either merge all then sort, or use k-way merge algorithm for efficiency
    return 0;
}

// Problem A6: Expert Application - Advanced String Processing with Multiple Arrays
// Create a comprehensive text processing system that uses multiple arrays to analyze
// and manipulate text data. This integrates all array concepts with complex algorithms.
//
// The function processes a character array (text) and:
// 1. Counts frequency of each letter (case-insensitive)
// 2. Finds the most frequent letter
// 3. Creates a "compressed" version by removing consecutive duplicates
// 4. Reverses words while maintaining word order
//
// Examples:
// Input: "Hello Programming World"
// Process:
// - Letter frequencies: H=1, E=1, L=4, O=3, P=1, R=4, G=2, A=1, M=2, I=1, N=2, W=1, D=1
// - Most frequent: 'L' and 'R' (both appear 4 times, return first alphabetically)
// - Compressed: "Helo Programing World" (consecutive duplicates removed)
// - Word reversal: "olleH gnimmargorP dlroW"
//
// Function signature:
// char processAdvancedText(char text[], int letterFreq[], char compressed[], char wordReversed[])
// Returns the most frequent letter, fills frequency array, compressed text, and word-reversed text
//
// Input/Output format:
// - Input: text array (null-terminated)
// - Output: letterFreq[26] for A-Z frequencies, compressed text, word-reversed text
// - Return: most frequent letter (lowercase)
//
// Constraints:
// - Text length: 1 ≤ length ≤ 500
// - Only alphabetic characters and spaces
// - Multiple letters can have same max frequency (return first alphabetically)
char processAdvancedText(char text[], int letterFreq[], char compressed[], char wordReversed[])
{
    // TODO: Solve using multiple array operations, frequency counting, string manipulation
    // Hint: Use separate arrays for different operations, combine character processing with array indexing
    return 'g';
}

//=== SECTION B: KNOWLEDGE VALIDATION QUIZ ===

void knowledgeQuiz()
{
    cout << "=== CHAPTER KNOWLEDGE QUIZ ===" << endl;
    cout << "Answer each question and check your understanding:" << endl
         << endl;

    int totalScore = 0;

    // Question 1: Core Concept Definition
    cout << "Q1: What happens when you access arr[5] in an array declared as int arr[5]?" << endl;
    cout << "A) Returns the 5th element  B) Returns the 6th element  C) Undefined behavior  D) Compilation error" << endl;
    cout << "Your answer (A/B/C/D): ";
    char answer1;
    cin >> answer1;
    cout << "Correct Answer: C - Undefined behavior" << endl;
    cout << "Explanation: Array indices are 0-based, so valid indices for arr[5] are 0-4. Accessing arr[5] goes out of bounds." << endl;
    if (answer1 == 'C' || answer1 == 'c')
        totalScore++;
    cout << endl;

    // Question 2: Array Declaration Syntax
    cout << "Q2: Which declaration creates an array of 10 integers initialized to zero?" << endl;
    cout << "A) int arr[10];  B) int arr[10] = {0};  C) int arr[10] = {};  D) Both B and C" << endl;
    cout << "Your answer (A/B/C/D): ";
    char answer2;
    cin >> answer2;
    cout << "Correct Answer: D - Both B and C" << endl;
    cout << "Explanation: Both {0} and {} initialize all elements to zero. arr[10] without initializer contains garbage values." << endl;
    if (answer2 == 'D' || answer2 == 'd')
        totalScore++;
    cout << endl;

    // Question 3: Character Arrays vs String Literals
    cout << "Q3: What's the key difference between char str[] = \"hello\"; and char str[5] = {'h','e','l','l','o'}?" << endl;
    cout << "A) No difference  B) First includes null terminator  C) Second is more efficient  D) First creates string literal" << endl;
    cout << "Your answer (A/B/C/D): ";
    char answer3;
    cin >> answer3;
    cout << "Correct Answer: B - First includes null terminator" << endl;
    cout << "Explanation: String literal automatically adds '\\0', making it size 6. Second version has no null terminator." << endl;
    if (answer3 == 'B' || answer3 == 'b')
        totalScore++;
    cout << endl;

    // Question 4: Array Size Calculation
    cout << "Q4: For int arr[] = {1,2,3,4,5}; what does sizeof(arr)/sizeof(arr[0]) return?" << endl;
    cout << "A) 5  B) 20  C) 4  D) Compilation error" << endl;
    cout << "Your answer (A/B/C/D): ";
    char answer4;
    cin >> answer4;
    cout << "Correct Answer: A - 5" << endl;
    cout << "Explanation: sizeof(arr) gives total bytes, sizeof(arr[0]) gives bytes per element. Division gives element count." << endl;
    if (answer4 == 'A' || answer4 == 'a')
        totalScore++;
    cout << endl;

    // Question 5: Array Parameter Passing
    cout << "Q5: When an array is passed to a function, what actually gets passed?" << endl;
    cout << "A) Copy of entire array  B) Reference to array  C) Pointer to first element  D) Size of array" << endl;
    cout << "Your answer (A/B/C/D): ";
    char answer5;
    cin >> answer5;
    cout << "Correct Answer: C - Pointer to first element" << endl;
    cout << "Explanation: Arrays decay to pointers when passed to functions. Function receives address of first element." << endl;
    if (answer5 == 'C' || answer5 == 'c')
        totalScore++;
    cout << endl;

    // Question 6: Bounds Checking
    cout << "Q6: Which statement about array bounds checking in C++ is TRUE?" << endl;
    cout << "A) Always checked at runtime  B) Always checked at compile time  C) Never checked automatically  D) Only in debug mode" << endl;
    cout << "Your answer (A/B/C/D): ";
    char answer6;
    cin >> answer6;
    cout << "Correct Answer: C - Never checked automatically" << endl;
    cout << "Explanation: C++ doesn't provide automatic bounds checking. It's programmer's responsibility to stay within bounds." << endl;
    if (answer6 == 'C' || answer6 == 'c')
        totalScore++;
    cout << endl;

    // Question 7: Array Initialization
    cout << "Q7: What happens with int arr[5] = {1, 2}; ?" << endl;
    cout << "A) Compilation error  B) First 2 elements = 1,2; rest = garbage  C) First 2 elements = 1,2; rest = 0  D) All elements = 1" << endl;
    cout << "Your answer (A/B/C/D): ";
    char answer7;
    cin >> answer7;
    cout << "Correct Answer: C - First 2 elements = 1,2; rest = 0" << endl;
    cout << "Explanation: Partial initialization sets specified elements and zero-initializes the remaining elements." << endl;
    if (answer7 == 'C' || answer7 == 'c')
        totalScore++;
    cout << endl;

    // Question 8: Character Array Size
    cout << "Q8: For char name[] = \"John\"; what is sizeof(name)?" << endl;
    cout << "A) 4  B) 5  C) Depends on compiler  D) 8" << endl;
    cout << "Your answer (A/B/C/D): ";
    char answer8;
    cin >> answer8;
    cout << "Correct Answer: B - 5" << endl;
    cout << "Explanation: String \"John\" has 4 characters plus null terminator, total 5 bytes." << endl;
    if (answer8 == 'B' || answer8 == 'b')
        totalScore++;
    cout << endl;

    // Question 9: Array vs Pointer Arithmetic
    cout << "Q9: For int arr[10]; int *ptr = arr; what's the difference between arr+1 and ptr+1?" << endl;
    cout << "A) arr+1 is invalid  B) No difference  C) Different memory locations  D) ptr+1 moves by 1 byte, arr+1 by 4 bytes" << endl;
    cout << "Your answer (A/B/C/D): ";
    char answer9;
    cin >> answer9;
    cout << "Correct Answer: B - No difference" << endl;
    cout << "Explanation: Both arr+1 and ptr+1 point to second element. Array name decays to pointer in expressions." << endl;
    if (answer9 == 'B' || answer9 == 'b')
        totalScore++;
    cout << endl;

    // Question 10: Multi-dimensional Array Declaration
    cout << "Q10: Which correctly declares a 2D array with 3 rows and 4 columns?" << endl;
    cout << "A) int arr[3,4];  B) int arr[3][4];  C) int arr[4][3];  D) int arr(3)(4);" << endl;
    cout << "Your answer (A/B/C/D): ";
    char answer10;
    cin >> answer10;
    cout << "Correct Answer: B - int arr[3][4];" << endl;
    cout << "Explanation: First dimension is rows, second is columns. arr[3,4] uses comma operator (wrong syntax)." << endl;
    if (answer10 == 'B' || answer10 == 'b')
        totalScore++;
    cout << endl;

    // Question 11: Array Const Correctness
    cout << "Q11: What does const int arr[5] = {1,2,3,4,5}; mean?" << endl;
    cout << "A) Array size is constant  B) Array elements cannot be modified  C) Array address is constant  D) Both B and C" << endl;
    cout << "Your answer (A/B/C/D): ";
    char answer11;
    cin >> answer11;
    cout << "Correct Answer: B - Array elements cannot be modified" << endl;
    cout << "Explanation: const makes array elements read-only. Array address is already constant by nature." << endl;
    if (answer11 == 'B' || answer11 == 'b')
        totalScore++;
    cout << endl;

    // Question 12: Performance Consideration
    cout << "Q12: Which loop is generally MORE efficient for large arrays?" << endl;
    cout << "A) for(int i=0; i<size; i++) sum += arr[i];  B) for(int i=size-1; i>=0; i--) sum += arr[i];" << endl;
    cout << "C) Both same  D) Depends on array size" << endl;
    cout << "Your answer (A/B/C/D): ";
    char answer12;
    cin >> answer12;
    cout << "Correct Answer: C - Both same" << endl;
    cout << "Explanation: Modern compilers optimize both equally. Performance difference is negligible for simple operations." << endl;
    if (answer12 == 'C' || answer12 == 'c')
        totalScore++;
    cout << endl;

    // Question 13: Common Pitfall
    cout << "Q13: What's wrong with: int size = 5; int arr[size]; ?" << endl;
    cout << "A) Nothing wrong  B) Variable-length arrays not standard C++  C) Should use const  D) Size must be literal" << endl;
    cout << "Your answer (A/B/C/D): ";
    char answer13;
    cin >> answer13;
    cout << "Correct Answer: B - Variable-length arrays not standard C++" << endl;
    cout << "Explanation: Array size must be compile-time constant in standard C++. Use const int or literal values." << endl;
    if (answer13 == 'B' || answer13 == 'b')
        totalScore++;
    cout << endl;

    // Question 14: Memory Layout
    cout << "Q14: In int matrix[3][4]; elements are stored in memory as:" << endl;
    cout << "A) Column-major order  B) Row-major order  C) Scattered randomly  D) Depends on compiler" << endl;
    cout << "Your answer (A/B/C/D): ";
    char answer14;
    cin >> answer14;
    cout << "Correct Answer: B - Row-major order" << endl;
    cout << "Explanation: C++ stores 2D arrays row by row in memory. matrix[0] followed by matrix[1], etc." << endl;
    if (answer14 == 'B' || answer14 == 'b')
        totalScore++;
    cout << endl;

    // Question 15: Integration with Previous Concepts
    cout << "Q15: Which statement correctly uses a for loop to find maximum in array?" << endl;
    cout << "A) for(int i=1; int max=arr[0]; i<size; i++)  B) int max=arr[0]; for(int i=1; i<size; i++)" << endl;
    cout << "C) for(int i=0, max=arr[0]; i<size; i++)  D) All are correct" << endl;
    cout << "Your answer (A/B/C/D): ";
    char answer15;
    cin >> answer15;
    cout << "Correct Answer: B - int max=arr[0]; for(int i=1; i<size; i++)" << endl;
    cout << "Explanation: max should be declared outside loop, loop starts from index 1 to compare with initialized max." << endl;
    if (answer15 == 'B' || answer15 == 'b')
        totalScore++;
    cout << endl;

    cout << "=== QUIZ COMPLETE ===" << endl;
    cout << "Your Score: " << totalScore << "/15 (" << (totalScore * 100.0 / 15) << "%)" << endl;
    if (totalScore >= 13)
        cout << "Excellent! You have mastered arrays concepts!" << endl;
    else if (totalScore >= 10)
        cout << "Good job! Review the missed concepts." << endl;
    else if (totalScore >= 7)
        cout << "Fair understanding. More practice needed." << endl;
    else
        cout << "Need significant review of arrays concepts." << endl;
}

//=== MANDATORY COMPLETE TEST FUNCTIONS ===

void testProblemA1()
{
    cout << "Testing Problem A1 - Foundation Integration..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Basic positive numbers
    // Manual calculation: sum = 1+2+3+4+5 = 15, avg = 15/5 = 3.0, min = 1, max = 5
    total++;
    int arr1[] = {1, 2, 3, 4, 5};
    int sum1, min1, max1;
    double avg1;
    calculateArrayStats(arr1, 5, sum1, avg1, min1, max1);
    if (sum1 == 15 && abs(avg1 - 3.0) < 0.001 && min1 == 1 && max1 == 5)
    {
        cout << "Test 1: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 1: FAIL - Expected: sum=15, avg=3.0, min=1, max=5" << endl;
        cout << "Got: sum=" << sum1 << ", avg=" << avg1 << ", min=" << min1 << ", max=" << max1 << endl;
    }

    // Test Case 2: Mixed positive and negative
    // Manual calculation: sum = 10+(-5)+0+8 = 13, avg = 13/4 = 3.25, min = -5, max = 10
    total++;
    int arr2[] = {10, -5, 0, 8};
    int sum2, min2, max2;
    double avg2;
    calculateArrayStats(arr2, 4, sum2, avg2, min2, max2);
    if (sum2 == 13 && abs(avg2 - 3.25) < 0.001 && min2 == -5 && max2 == 10)
    {
        cout << "Test 2: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 2: FAIL - Expected: sum=13, avg=3.25, min=-5, max=10" << endl;
        cout << "Got: sum=" << sum2 << ", avg=" << avg2 << ", min=" << min2 << ", max=" << max2 << endl;
    }

    // Test Case 3: Single element
    // Manual calculation: sum = 42, avg = 42/1 = 42.0, min = 42, max = 42
    total++;
    int arr3[] = {42};
    int sum3, min3, max3;
    double avg3;
    calculateArrayStats(arr3, 1, sum3, avg3, min3, max3);
    if (sum3 == 42 && abs(avg3 - 42.0) < 0.001 && min3 == 42 && max3 == 42)
    {
        cout << "Test 3: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 3: FAIL - Expected: sum=42, avg=42.0, min=42, max=42" << endl;
        cout << "Got: sum=" << sum3 << ", avg=" << avg3 << ", min=" << min3 << ", max=" << max3 << endl;
    }

    // Test Case 4: All negative numbers
    // Manual calculation: sum = (-1)+(-3)+(-2) = -6, avg = -6/3 = -2.0, min = -3, max = -1
    total++;
    int arr4[] = {-1, -3, -2};
    int sum4, min4, max4;
    double avg4;
    calculateArrayStats(arr4, 3, sum4, avg4, min4, max4);
    if (sum4 == -6 && abs(avg4 - (-2.0)) < 0.001 && min4 == -3 && max4 == -1)
    {
        cout << "Test 4: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 4: FAIL - Expected: sum=-6, avg=-2.0, min=-3, max=-1" << endl;
        cout << "Got: sum=" << sum4 << ", avg=" << avg4 << ", min=" << min4 << ", max=" << max4 << endl;
    }

    // Test Case 5: Duplicate elements
    // Manual calculation: sum = 5+5+5+5 = 20, avg = 20/4 = 5.0, min = 5, max = 5
    total++;
    int arr5[] = {5, 5, 5, 5};
    int sum5, min5, max5;
    double avg5;
    calculateArrayStats(arr5, 4, sum5, avg5, min5, max5);
    if (sum5 == 20 && abs(avg5 - 5.0) < 0.001 && min5 == 5 && max5 == 5)
    {
        cout << "Test 5: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 5: FAIL - Expected: sum=20, avg=5.0, min=5, max=5" << endl;
        cout << "Got: sum=" << sum5 << ", avg=" << avg5 << ", min=" << min5 << ", max=" << max5 << endl;
    }

    // Test Case 6: Large numbers
    // Manual calculation: sum = 100+200+50 = 350, avg = 350/3 = 116.667, min = 50, max = 200
    total++;
    int arr6[] = {100, 200, 50};
    int sum6, min6, max6;
    double avg6;
    calculateArrayStats(arr6, 3, sum6, avg6, min6, max6);
    if (sum6 == 350 && abs(avg6 - 116.667) < 0.001 && min6 == 50 && max6 == 200)
    {
        cout << "Test 6: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 6: FAIL - Expected: sum=350, avg=116.667, min=50, max=200" << endl;
        cout << "Got: sum=" << sum6 << ", avg=" << avg6 << ", min=" << min6 << ", max=" << max6 << endl;
    }

    cout << "Problem A1 Results: " << passed << "/" << total << " tests passed" << endl
         << endl;
}

void testProblemA2()
{
    cout << "Testing Problem A2 - Intermediate Synthesis..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Mixed content with vowels, consonants, digits, spaces
    // Manual calculation: "Hello World 123"
    // chars = 13, vowels = e,o,o (3), consonants = H,l,l,W,r,l,d (7), digits = 1,2,3 (3), spaces = 2, words = 3
    total++;
    char str1[] = "Hello World 123";
    int chars1, vowels1, consonants1, digits1, spaces1, words1;
    analyzeCharArray(str1, chars1, vowels1, consonants1, digits1, spaces1, words1);
    if (chars1 == 15 && vowels1 == 3 && consonants1 == 7 && digits1 == 3 && spaces1 == 2 && words1 == 3)
    {
        cout << "Test 1: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 1: FAIL - Expected: chars=15, vowels=3, consonants=7, digits=3, spaces=2, words=3" << endl;
        cout << "Got: chars=" << chars1 << ", vowels=" << vowels1 << ", consonants=" << consonants1;
        cout << ", digits=" << digits1 << ", spaces=" << spaces1 << ", words=" << words1 << endl;
    }

    // Test Case 2: Programming text
    // Manual calculation: "Programming is fun!"
    // chars = 18, vowels = o,a,i,i,u (5), consonants = P,r,g,r,m,m,n,g,s,f,n (11), digits = 0, spaces = 2, words = 3
    total++;
    char str2[] = "Programming is fun!";
    int chars2, vowels2, consonants2, digits2, spaces2, words2;
    analyzeCharArray(str2, chars2, vowels2, consonants2, digits2, spaces2, words2);
    if (chars2 == 19 && vowels2 == 5 && consonants2 == 11 && digits2 == 0 && spaces2 == 2 && words2 == 3)
    {
        cout << "Test 2: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 2: FAIL - Expected: chars=19, vowels=5, consonants=11, digits=0, spaces=2, words=3" << endl;
        cout << "Got: chars=" << chars2 << ", vowels=" << vowels2 << ", consonants=" << consonants2;
        cout << ", digits=" << digits2 << ", spaces=" << spaces2 << ", words=" << words2 << endl;
    }

    // Test Case 3: Only digits and spaces
    // Manual calculation: "123 456 789"
    // chars = 11, vowels = 0, consonants = 0, digits = 9, spaces = 2, words = 3
    total++;
    char str3[] = "123 456 789";
    int chars3, vowels3, consonants3, digits3, spaces3, words3;
    analyzeCharArray(str3, chars3, vowels3, consonants3, digits3, spaces3, words3);
    if (chars3 == 11 && vowels3 == 0 && consonants3 == 0 && digits3 == 9 && spaces3 == 2 && words3 == 3)
    {
        cout << "Test 3: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 3: FAIL - Expected: chars=11, vowels=0, consonants=0, digits=9, spaces=2, words=3" << endl;
        cout << "Got: chars=" << chars3 << ", vowels=" << vowels3 << ", consonants=" << consonants3;
        cout << ", digits=" << digits3 << ", spaces=" << spaces3 << ", words=" << words3 << endl;
    }

    // Test Case 4: Single word with special characters
    // Manual calculation: "Hello!"
    // chars = 6, vowels = e,o (2), consonants = H,l,l (3), digits = 0, spaces = 0, words = 1
    total++;
    char str4[] = "Hello!";
    int chars4, vowels4, consonants4, digits4, spaces4, words4;
    analyzeCharArray(str4, chars4, vowels4, consonants4, digits4, spaces4, words4);
    if (chars4 == 6 && vowels4 == 2 && consonants4 == 3 && digits4 == 0 && spaces4 == 0 && words4 == 1)
    {
        cout << "Test 4: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 4: FAIL - Expected: chars=6, vowels=2, consonants=3, digits=0, spaces=0, words=1" << endl;
        cout << "Got: chars=" << chars4 << ", vowels=" << vowels4 << ", consonants=" << consonants4;
        cout << ", digits=" << digits4 << ", spaces=" << spaces4 << ", words=" << words4 << endl;
    }

    // Test Case 5: Mixed case letters
    // Manual calculation: "AeIoU bcdfg"
    // chars = 11, vowels = A,e,I,o,U (5), consonants = b,c,d,f,g (5), digits = 0, spaces = 1, words = 2
    total++;
    char str5[] = "AeIoU bcdfg";
    int chars5, vowels5, consonants5, digits5, spaces5, words5;
    analyzeCharArray(str5, chars5, vowels5, consonants5, digits5, spaces5, words5);
    if (chars5 == 11 && vowels5 == 5 && consonants5 == 5 && digits5 == 0 && spaces5 == 1 && words5 == 2)
    {
        cout << "Test 5: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 5: FAIL - Expected: chars=11, vowels=5, consonants=5, digits=0, spaces=1, words=2" << endl;
        cout << "Got: chars=" << chars5 << ", vowels=" << vowels5 << ", consonants=" << consonants5;
        cout << ", digits=" << digits5 << ", spaces=" << spaces5 << ", words=" << words5 << endl;
    }

    // Test Case 6: Empty-like string with just spaces
    // Manual calculation: "   "
    // chars = 3, vowels = 0, consonants = 0, digits = 0, spaces = 3, words = 0
    total++;
    char str6[] = "   ";
    int chars6, vowels6, consonants6, digits6, spaces6, words6;
    analyzeCharArray(str6, chars6, vowels6, consonants6, digits6, spaces6, words6);
    if (chars6 == 3 && vowels6 == 0 && consonants6 == 0 && digits6 == 0 && spaces6 == 3 && words6 == 0)
    {
        cout << "Test 6: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 6: FAIL - Expected: chars=3, vowels=0, consonants=0, digits=0, spaces=3, words=0" << endl;
        cout << "Got: chars=" << chars6 << ", vowels=" << vowels6 << ", consonants=" << consonants6;
        cout << ", digits=" << digits6 << ", spaces=" << spaces6 << ", words=" << words6 << endl;
    }

    cout << "Problem A2 Results: " << passed << "/" << total << " tests passed" << endl
         << endl;
}

void testProblemA3()
{
    cout << "Testing Problem A3 - Advanced Integration..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Basic rotation and search
    // Manual calculation: [1,2,3,4,5] rotate right by 2 → [4,5,1,2,3], search for 3 → index 4
    total++;
    int arr1[] = {1, 2, 3, 4, 5};
    int result1 = rotateAndSearch(arr1, 5, 2, 3);
    if (result1 == 4)
    {
        cout << "Test 1: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 1: FAIL - Expected: 4, Got: " << result1 << endl;
    }

    // Test Case 2: Rotation with k > size
    // Manual calculation: [7,8,9,1,2] rotate right by 3 → [9,1,2,7,8], search for 7 → index 3
    total++;
    int arr2[] = {7, 8, 9, 1, 2};
    int result2 = rotateAndSearch(arr2, 5, 3, 7);
    if (result2 == 3)
    {
        cout << "Test 2: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 2: FAIL - Expected: 3, Got: " << result2 << endl;
    }

    // Test Case 3: Target not found
    // Manual calculation: [1,2,3] rotate right by 1 → [3,1,2], search for 5 → -1
    total++;
    int arr3[] = {1, 2, 3};
    int result3 = rotateAndSearch(arr3, 3, 1, 5);
    if (result3 == -1)
    {
        cout << "Test 3: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 3: FAIL - Expected: -1, Got: " << result3 << endl;
    }

    // Test Case 4: No rotation (k = 0)
    // Manual calculation: [10,20,30] rotate right by 0 → [10,20,30], search for 20 → index 1
    total++;
    int arr4[] = {10, 20, 30};
    int result4 = rotateAndSearch(arr4, 3, 0, 20);
    if (result4 == 1)
    {
        cout << "Test 4: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 4: FAIL - Expected: 1, Got: " << result4 << endl;
    }

    // Test Case 5: Full rotation (k = size)
    // Manual calculation: [4,5,6] rotate right by 3 → [4,5,6], search for 5 → index 1
    total++;
    int arr5[] = {4, 5, 6};
    int result5 = rotateAndSearch(arr5, 3, 3, 5);
    if (result5 == 1)
    {
        cout << "Test 5: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 5: FAIL - Expected: 1, Got: " << result5 << endl;
    }

    // Test Case 6: Single element array
    // Manual calculation: [42] rotate right by 5 → [42], search for 42 → index 0
    total++;
    int arr6[] = {42};
    int result6 = rotateAndSearch(arr6, 1, 5, 42);
    if (result6 == 0)
    {
        cout << "Test 6: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 6: FAIL - Expected: 0, Got: " << result6 << endl;
    }

    // Test Case 7: Large rotation value
    // Manual calculation: [1,2,3,4] rotate right by 10 → 10%4=2, so [3,4,1,2], search for 1 → index 2
    total++;
    int arr7[] = {1, 2, 3, 4};
    int result7 = rotateAndSearch(arr7, 4, 10, 1);
    if (result7 == 2)
    {
        cout << "Test 7: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 7: FAIL - Expected: 2, Got: " << result7 << endl;
    }

    cout << "Problem A3 Results: " << passed << "/" << total << " tests passed" << endl
         << endl;
}

void testProblemA4()
{
    cout << "Testing Problem A4 - Complex Synthesis..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Pattern found at beginning
    // Manual calculation: [1,2,3,4,5,6] search for [1,2,3] → found at index 0
    total++;
    int main1[] = {1, 2, 3, 4, 5, 6};
    int pattern1[] = {1, 2, 3};
    int result1 = findPatternInArray(main1, 6, pattern1, 3);
    if (result1 == 0)
    {
        cout << "Test 1: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 1: FAIL - Expected: 0, Got: " << result1 << endl;
    }

    // Test Case 2: Pattern found in middle
    // Manual calculation: [1,2,3,4,5,6] search for [3,4,5] → found at index 2
    total++;
    int main2[] = {1, 2, 3, 4, 5, 6};
    int pattern2[] = {3, 4, 5};
    int result2 = findPatternInArray(main2, 6, pattern2, 3);
    if (result2 == 2)
    {
        cout << "Test 2: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 2: FAIL - Expected: 2, Got: " << result2 << endl;
    }

    // Test Case 3: Pattern not found
    // Manual calculation: [7,8,9,1,2] search for [9,1,3] → not found, return -1
    total++;
    int main3[] = {7, 8, 9, 1, 2};
    int pattern3[] = {9, 1, 3};
    int result3 = findPatternInArray(main3, 5, pattern3, 3);
    if (result3 == -1)
    {
        cout << "Test 3: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 3: FAIL - Expected: -1, Got: " << result3 << endl;
    }

    // Test Case 4: Single element pattern found
    // Manual calculation: [5,10,15,20] search for [15] → found at index 2
    total++;
    int main4[] = {5, 10, 15, 20};
    int pattern4[] = {15};
    int result4 = findPatternInArray(main4, 4, pattern4, 1);
    if (result4 == 2)
    {
        cout << "Test 4: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 4: FAIL - Expected: 2, Got: " << result4 << endl;
    }

    // Test Case 5: Pattern at end
    // Manual calculation: [1,2,3,4,5] search for [4,5] → found at index 3
    total++;
    int main5[] = {1, 2, 3, 4, 5};
    int pattern5[] = {4, 5};
    int result5 = findPatternInArray(main5, 5, pattern5, 2);
    if (result5 == 3)
    {
        cout << "Test 5: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 5: FAIL - Expected: 3, Got: " << result5 << endl;
    }

    // Test Case 6: Full array pattern match
    // Manual calculation: [10,20,30] search for [10,20,30] → found at index 0
    total++;
    int main6[] = {10, 20, 30};
    int pattern6[] = {10, 20, 30};
    int result6 = findPatternInArray(main6, 3, pattern6, 3);
    if (result6 == 0)
    {
        cout << "Test 6: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 6: FAIL - Expected: 0, Got: " << result6 << endl;
    }

    // Test Case 7: Overlapping patterns
    // Manual calculation: [1,1,1,2,3] search for [1,2] → found at index 2
    total++;
    int main7[] = {1, 1, 1, 2, 3};
    int pattern7[] = {1, 2};
    int result7 = findPatternInArray(main7, 5, pattern7, 2);
    if (result7 == 2)
    {
        cout << "Test 7: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 7: FAIL - Expected: 2, Got: " << result7 << endl;
    }

    cout << "Problem A4 Results: " << passed << "/" << total << " tests passed" << endl
         << endl;
}

void testProblemA5()
{
    cout << "Testing Problem A5 - Mastery Challenge..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Three equal-sized sorted arrays
    // Manual calculation: merge [1,4,7], [2,5,8], [3,6,9] → [1,2,3,4,5,6,7,8,9], size = 9
    total++;
    int arrays1[3][10] = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
    int sizes1[] = {3, 3, 3};
    int result1[100];
    int resultSize1 = mergeAndSortArrays(arrays1, sizes1, 3, result1);
    bool test1Pass = (resultSize1 == 9);
    int expected1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 9 && test1Pass; i++)
    {
        if (result1[i] != expected1[i])
            test1Pass = false;
    }
    if (test1Pass)
    {
        cout << "Test 1: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 1: FAIL - Expected size: 9, Got size: " << resultSize1 << endl;
        cout << "Expected: [1,2,3,4,5,6,7,8,9]" << endl;
        cout << "Got: [";
        for (int i = 0; i < resultSize1; i++)
        {
            cout << result1[i] << (i < resultSize1 - 1 ? "," : "");
        }
        cout << "]" << endl;
    }

    // Test Case 2: Different sized arrays
    // Manual calculation: merge [1,3,5], [2,4], [6,7,8,9] → [1,2,3,4,5,6,7,8,9], size = 9
    total++;
    int arrays2[3][10] = {{1, 3, 5}, {2, 4}, {6, 7, 8, 9}};
    int sizes2[] = {3, 2, 4};
    int result2[100];
    int resultSize2 = mergeAndSortArrays(arrays2, sizes2, 3, result2);
    bool test2Pass = (resultSize2 == 9);
    int expected2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 9 && test2Pass; i++)
    {
        if (result2[i] != expected2[i])
            test2Pass = false;
    }
    if (test2Pass)
    {
        cout << "Test 2: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 2: FAIL - Expected size: 9, Got size: " << resultSize2 << endl;
    }

    // Test Case 3: Single array
    // Manual calculation: merge [5,10,15] → [5,10,15], size = 3
    total++;
    int arrays3[1][10] = {{5, 10, 15}};
    int sizes3[] = {3};
    int result3[100];
    int resultSize3 = mergeAndSortArrays(arrays3, sizes3, 1, result3);
    bool test3Pass = (resultSize3 == 3);
    int expected3[] = {5, 10, 15};
    for (int i = 0; i < 3 && test3Pass; i++)
    {
        if (result3[i] != expected3[i])
            test3Pass = false;
    }
    if (test3Pass)
    {
        cout << "Test 3: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 3: FAIL - Expected size: 3, Got size: " << resultSize3 << endl;
    }

    // Test Case 4: Arrays with duplicates
    // Manual calculation: merge [1,1,2], [1,2,3], [2,3,3] → [1,1,1,2,2,2,3,3,3], size = 9
    total++;
    int arrays4[3][10] = {{1, 1, 2}, {1, 2, 3}, {2, 3, 3}};
    int sizes4[] = {3, 3, 3};
    int result4[100];
    int resultSize4 = mergeAndSortArrays(arrays4, sizes4, 3, result4);
    bool test4Pass = (resultSize4 == 9);
    int expected4[] = {1, 1, 1, 2, 2, 2, 3, 3, 3};
    for (int i = 0; i < 9 && test4Pass; i++)
    {
        if (result4[i] != expected4[i])
            test4Pass = false;
    }
    if (test4Pass)
    {
        cout << "Test 4: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 4: FAIL - Expected size: 9, Got size: " << resultSize4 << endl;
    }

    // Test Case 5: Single element arrays
    // Manual calculation: merge [5], [1], [3] → [1,3,5], size = 3
    total++;
    int arrays5[3][10] = {{5}, {1}, {3}};
    int sizes5[] = {1, 1, 1};
    int result5[100];
    int resultSize5 = mergeAndSortArrays(arrays5, sizes5, 3, result5);
    bool test5Pass = (resultSize5 == 3);
    int expected5[] = {1, 3, 5};
    for (int i = 0; i < 3 && test5Pass; i++)
    {
        if (result5[i] != expected5[i])
            test5Pass = false;
    }
    if (test5Pass)
    {
        cout << "Test 5: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 5: FAIL - Expected size: 3, Got size: " << resultSize5 << endl;
    }

    cout << "Problem A5 Results: " << passed << "/" << total << " tests passed" << endl
         << endl;
}

void testProblemA6()
{
    cout << "Testing Problem A6 - Expert Application..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Complex text processing
    // Manual calculation: "Hello Programming World"
    // Frequencies: H=1,E=1,L=4,O=3,P=1,R=4,G=2,A=1,M=2,I=1,N=2,W=1,D=1
    // Most frequent: L and R (4 each), return 'l' (first alphabetically)
    // Compressed: "Helo Programing World"
    // Word reversed: "olleH gnimmargorP dlroW"
    total++;
    char text1[] = "Hello Programming World";
    int freq1[26];
    char compressed1[500];
    char wordReversed1[500];
    char mostFreq1 = processAdvancedText(text1, freq1, compressed1, wordReversed1);

    bool test1Pass = (mostFreq1 == 'l' || mostFreq1 == 'r');
    // Check some key frequencies: L=4, R=4, O=3, G=2, M=2, N=2
    test1Pass = test1Pass && freq1[11] == 4 && freq1[17] == 4 && freq1[14] == 3; // L, R, O

    if (test1Pass)
    {
        cout << "Test 1: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 1: FAIL - Most frequent char: " << mostFreq1 << endl;
        cout << "L frequency: " << freq1[11] << ", R frequency: " << freq1[17] << endl;
    }

    // Test Case 2: Simple repeated letters
    // Manual calculation: "aabbcc"
    // Most frequent: all have frequency 2, return 'a'
    // Compressed: "abc"
    // Word reversed: "ccbbaa" (single word)
    total++;
    char text2[] = "aabbcc";
    int freq2[26];
    char compressed2[500];
    char wordReversed2[500];
    char mostFreq2 = processAdvancedText(text2, freq2, compressed2, wordReversed2);

    bool test2Pass = (mostFreq2 == 'a') && (freq2[0] == 2) && (freq2[1] == 2) && (freq2[2] == 2);

    if (test2Pass)
    {
        cout << "Test 2: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 2: FAIL - Most frequent: " << mostFreq2 << ", expected 'a'" << endl;
    }

    // Test Case 3: Single word
    // Manual calculation: "book"
    // Most frequent: 'o' (appears 2 times)
    // Compressed: "bok"
    // Word reversed: "koob"
    total++;
    char text3[] = "book";
    int freq3[26];
    char compressed3[500];
    char wordReversed3[500];
    char mostFreq3 = processAdvancedText(text3, freq3, compressed3, wordReversed3);

    bool test3Pass = (mostFreq3 == 'o') && (freq3[14] == 2); // O is at index 14

    if (test3Pass)
    {
        cout << "Test 3: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 3: FAIL - Most frequent: " << mostFreq3 << ", expected 'o'" << endl;
        cout << "O frequency: " << freq3[14] << endl;
    }

    // Test Case 4: Multiple words with same frequency letters
    // Manual calculation: "ab ba"
    // Most frequent: 'a' and 'b' both appear 2 times, return 'a'
    // Compressed: "ab ba" (no consecutive duplicates)
    // Word reversed: "ba ab"
    total++;
    char text4[] = "ab ba";
    int freq4[26];
    char compressed4[500];
    char wordReversed4[500];
    char mostFreq4 = processAdvancedText(text4, freq4, compressed4, wordReversed4);

    bool test4Pass = (mostFreq4 == 'a') && (freq4[0] == 2) && (freq4[1] == 2);

    if (test4Pass)
    {
        cout << "Test 4: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 4: FAIL - Most frequent: " << mostFreq4 << ", expected 'a'" << endl;
    }

    // Test Case 5: Text with case sensitivity
    // Manual calculation: "AaAa"
    // Most frequent: 'a' appears 4 times (case insensitive)
    // Compressed: "AaAa" (no consecutive duplicates as they alternate case)
    // Word reversed: "aAaA"
    total++;
    char text5[] = "AaAa";
    int freq5[26];
    char compressed5[500];
    char wordReversed5[500];
    char mostFreq5 = processAdvancedText(text5, freq5, compressed5, wordReversed5);

    bool test5Pass = (mostFreq5 == 'a') && (freq5[0] == 4);

    if (test5Pass)
    {
        cout << "Test 5: PASS" << endl;
        passed++;
    }
    else
    {
        cout << "Test 5: FAIL - Most frequent: " << mostFreq5 << ", expected 'a'" << endl;
        cout << "A frequency: " << freq5[0] << endl;
    }

    cout << "Problem A6 Results: " << passed << "/" << total << " tests passed" << endl
         << endl;
}

void runAllTests()
{
    cout << "=== RUNNING ALL INTEGRATION PROBLEM TESTS ===" << endl;
    testProblemA1();
    testProblemA2();
    testProblemA3();
    testProblemA4();
    testProblemA5();
    testProblemA6();
    cout << "=== ALL TESTS COMPLETE ===" << endl;
}

int main()
{
    cout << "=== COMPREHENSIVE CHAPTER ASSESSMENT ===" << endl;
    cout << "Choose your assessment mode:" << endl
         << endl;

    cout << "INTEGRATION PROBLEMS:" << endl;
    cout << "1. Problem A1 - Foundation Integration (Easy)" << endl;
    cout << "2. Problem A2 - Intermediate Synthesis (Easy-Medium)" << endl;
    cout << "3. Problem A3 - Advanced Integration (Medium)" << endl;
    cout << "4. Problem A4 - Complex Synthesis (Medium-Hard)" << endl;
    cout << "5. Problem A5 - Mastery Challenge (Hard)" << endl;
    cout << "6. Problem A6 - Expert Application (Very Hard)" << endl;
    cout << "7. Test All Integration Problems" << endl
         << endl;

    cout << "KNOWLEDGE VALIDATION:" << endl;
    cout << "8. Chapter Knowledge Quiz (15 questions)" << endl
         << endl;

    cout << "COMPREHENSIVE ASSESSMENT:" << endl;
    cout << "9. Full Chapter Assessment (All problems + Quiz)" << endl
         << endl;

    int choice;
    cout << "Enter your choice (1-9): ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        testProblemA1();
        break;
    case 2:
        testProblemA2();
        break;
    case 3:
        testProblemA3();
        break;
    case 4:
        testProblemA4();
        break;
    case 5:
        testProblemA5();
        break;
    case 6:
        testProblemA6();
        break;
    case 7:
        runAllTests();
        break;
    case 8:
        knowledgeQuiz();
        break;
    case 9:
        runAllTests();
        knowledgeQuiz();
        break;
    default:
        cout << "Invalid choice! Please run again and select 1-9." << endl;
    }
    return 0;
}