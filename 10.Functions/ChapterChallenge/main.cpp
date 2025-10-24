#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cassert>
#include "A1.h"
#include "A2.h"
#include "A3.h"
#include "A4.h"
#include "A5.h"
#include "A6.h"


using namespace std;

//=== SECTION A: INTEGRATION PROBLEMS ===

// Problem A1: Foundation Integration - Memory Safe String Processor
// CONCEPTS: Function Declaration/Definition, Pass by Value, Pass by Pointer
//
// Create a function that processes C-strings and std::strings safely.
// The function should count vowels in a string, modify the original string
// to uppercase (only for C-strings passed by pointer), and return the vowel count.
//
// Examples:
// Input: "hello" (C-string) -> Output: 2, string becomes "HELLO"
// Input: "programming" (std::string) -> Output: 3, original unchanged
// Input: "" (empty) -> Output: 0
// Input: "AEIOU" -> Output: 5
//
// Requirements:
// - Create separate functions for C-string and std::string processing
// - C-string version modifies original via pointer
// - std::string version uses pass by value (no modification)
// - Handle null pointers safely
// - Count both uppercase and lowercase vowels
//
// Constraints:
// - String length: 0-1000 characters
// - Only consider A, E, I, O, U as vowels (case insensitive)
//************************************************************************************ */
//************************************************************************************ */
//************************************************************************************ */
//************************************************************************************ */
//************************************************************************************ */
//************************************************************************************ */

// Problem A2: Intermediate Synthesis - Array Statistics with Multiple Parameter Types
// CONCEPTS: Pass by Pointer, Pass by Reference, Function Overloading, Dynamic Memory
//
// Create functions to calculate array statistics using different parameter passing methods.
// Implement functions that calculate: sum, average, min, max, and median.
// Use pass by pointer for input arrays, pass by reference for output parameters.
//
// Examples:
// Input: arr[] = {5, 2, 8, 1, 9}, size = 5
// Output: sum=25, avg=5.0, min=1, max=9, median=5
//
// Input: arr[] = {10, 20, 30, 40}, size = 4
// Output: sum=100, avg=25.0, min=10, max=40, median=25
//
// Input: arr[] = {7}, size = 1
// Output: sum=7, avg=7.0, min=7, max=7, median=7
//
// Requirements:
// - calculateStats function takes array pointer and size
// - Uses reference parameters for all output values
// - Handles edge cases (empty array, single element)
// - For median: sort a copy of array (don't modify original)
// - Create helper function to sort array copy
//
// Constraints:
// - Array size: 0-1000 elements
// - Array values: -10000 to 10000

//************************************************************************************ */
//************************************************************************************ */
//************************************************************************************ */
//************************************************************************************ */
//************************************************************************************ */
//************************************************************************************ */


// Problem A3: Advanced Integration - Multi-File Simulation with ODR
// CONCEPTS: One Definition Rule, Function Declarations, Multiple Files, Pass by Reference
//
// Simulate a multi-file project with proper function declarations and definitions.
// Create a "database" of student records where functions manipulate data via references.
//
// Functions needed:
// - addStudent: adds student with name and score (pass by reference to vector)
// - updateScore: updates student score by name (pass by reference)
// - getAverageScore: calculates average (pass by const reference)
// - findTopStudent: returns name of highest scoring student
//
// Examples:
// After adding: {"Alice", 85}, {"Bob", 92}, {"Charlie", 78}
// getAverageScore() -> 85.0
// findTopStudent() -> "Bob"
// After updateScore("Alice", 95)
// getAverageScore() -> 88.33
// findTopStudent() -> "Bob"
//
// Requirements:
// - Use struct for Student {string name; int score;}
// - Pass vectors by reference (avoid copies)
// - Use const reference where data shouldn't be modified
// - Demonstrate ODR compliance (declare once, define once)
//
// Constraints:
// - Student names: 1-50 characters
// - Scores: 0-100
// - Database size: 0-100 students
// struct Student {
//     string name;
//     int score;
// };

//************************************************************************************ */
//************************************************************************************ */
//************************************************************************************ */
//************************************************************************************ */
//************************************************************************************ */
//************************************************************************************ */


// Problem A4: Complex Synthesis - Dynamic Matrix Operations with Mixed Passing
// CONCEPTS: Dynamic Memory, Pass by Pointer, Pass by Reference, Pass by Value, Memory Safety
//
// Create a matrix calculator that uses dynamic memory allocation and various parameter
// passing techniques. Implement matrix operations with proper memory management.
//
// Functions:
// - createMatrix: allocates 2D array dynamically (returns pointer)
// - fillMatrix: fills matrix with values (pass by pointer)
// - transposeMatrix: creates transposed copy (dynamic allocation, return pointer)
// - calculateRowSums: computes sum of each row (output via reference to vector)
// - deleteMatrix: frees memory (pass by reference to set pointer to nullptr)
//
// Example:
// Original 3x2 matrix:  Transposed 2x3 matrix:
// 1  2                  1  3  5
// 3  4                  2  4  6
// 5  6
// Row sums: [3, 7, 11]
//
// Requirements:
// - Proper dynamic allocation/deallocation
// - No memory leaks
// - Handle allocation failures
// - Set pointers to nullptr after deletion
// - Use references to return multiple values
//
// Constraints:
// - Matrix dimensions: 1x1 to 100x100
// - Values: -1000 to 1000


//************************************************************************************ */
//************************************************************************************ */
//************************************************************************************ */
//************************************************************************************ */
//************************************************************************************ */
//************************************************************************************ */

// Problem A5: Mastery Challenge - Function Pointer System with All Concepts
// CONCEPTS: ALL Chapter 11 concepts + Function Pointers + Previous Chapters
//
// Build a text processing system that uses function pointers, multiple parameter
// passing methods, dynamic memory, and demonstrates the One Definition Rule.
//
// Create a system where users can register text transformation functions:
// - toUpperCase: converts text to uppercase
// - toLowerCase: converts text to lowercase
// - reverseText: reverses the text
// - encryptCaesar: Caesar cipher encryption (shift by n)
//
// Main function: processText
// - Takes original text (const reference)
// - Takes operation type (pass by value)
// - Takes additional parameter (pass by value, for encryption shift)
// - Returns modified text (pass result by value)
//
// Example:
// processText("Hello World", UPPERCASE, 0) -> "HELLO WORLD"
// processText("Hello World", ENCRYPT, 3) -> "Khoor Zruog"
// processText("Hello World", REVERSE, 0) -> "dlroW olleH"
//
// Advanced Requirements:
// - Use enum for operation types
// - Implement function registry with function pointers
// - Chain operations: apply multiple transformations
// - Handle edge cases (empty string, large shifts)
// - Memory efficient (no unnecessary copies)
//
// Constraints:
// - Text length: 0-10000 characters
// - Caesar shift: -26 to 26
// enum TextOperation { UPPERCASE, LOWERCASE, REVERSE, ENCRYPT };


//************************************************************************************ */
//************************************************************************************ */
//************************************************************************************ */
//************************************************************************************ */
//************************************************************************************ */
//************************************************************************************ */

// Problem A6: Expert Application - Complete Memory Management System
// CONCEPTS: ALL Functions concepts + Pointers + References + Dynamic Memory + Previous Knowledge
//
// Implement a dynamic array class (without using std::vector) that demonstrates
// mastery of all function concepts, memory management, and parameter passing.
//
// Required functionality:
// - Constructor: allocates memory (pass capacity by value)
// - Destructor: frees memory
// - push_back: adds element (pass by value or const ref)
// - pop_back: removes last element
// - at: access element (returns by reference for modification)
// - resize: changes capacity (pass new size by value)
// - clear: removes all elements but keeps capacity
// - copyArray: deep copy another array (pass source by const reference)
//
// Example usage:
// DynamicArray arr(5);
// arr.push_back(10);
// arr.push_back(20);
// arr.at(0) = 15; // modify through reference
// arr.resize(10); // expand capacity
//
// Expert Requirements:
// - No memory leaks under any circumstances
// - Handle all edge cases (resize, copy, empty array)
// - Efficient memory usage (don't allocate more than needed)
// - Demonstrate ODR with proper header/implementation separation
// - Use references to allow element modification
// - Use pointers for dynamic allocation
// - Use const references for read-only parameters
// - Handle allocation failures gracefully
//
// Constraints:
// - Initial capacity: 1-1000
// - Max capacity: 10000
// - Element type: int
/* class DynamicArray {
private:
    int* data;
    int size;
    int capacity;
    
public:
    DynamicArray(int initialCapacity);
    ~DynamicArray();
    void push_back(int value);
    void pop_back();
    int& at(int index);
    const int& at(int index) const;
    void resize(int newCapacity);
    void clear();
    void copyArray(const DynamicArray& source);
    int getSize() const;
    int getCapacity() const;
}; */

//=== SECTION B: KNOWLEDGE VALIDATION QUIZ ===

void knowledgeQuiz() {
    cout << "=== CHAPTER 11: FUNCTIONS KNOWLEDGE QUIZ ===" << endl;
    cout << "Answer each question and check your understanding:" << endl << endl;
    
    int score = 0;
    char answer;
    
    // Question 1: One Definition Rule
    cout << "Q1: What does the One Definition Rule (ODR) state?" << endl;
    cout << "A) A function can be declared multiple times but defined only once" << endl;
    cout << "B) Each variable must be defined exactly once" << endl;
    cout << "C) Functions cannot be declared before definition" << endl;
    cout << "D) All definitions must be in the same file" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'A' || answer == 'a') {
        cout << "CORRECT!" << endl;
        score++;
    } else {
        cout << "INCORRECT. Correct Answer: A" << endl;
    }
    cout << "Explanation: The ODR allows multiple declarations (in headers/different files)" << endl;
    cout << "but requires exactly ONE definition. This prevents linker errors and ambiguity." << endl << endl;
    
    // Question 2: Function Declaration vs Definition
    cout << "Q2: Which statement correctly shows a function declaration?" << endl;
    cout << "A) int add(int a, int b) { return a + b; }" << endl;
    cout << "B) int add(int a, int b);" << endl;
    cout << "C) void add(int, int) { }" << endl;
    cout << "D) int add() { return 0; }" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "CORRECT!" << endl;
        score++;
    } else {
        cout << "INCORRECT. Correct Answer: B" << endl;
    }
    cout << "Explanation: A declaration specifies the function signature without implementation." << endl;
    cout << "It ends with a semicolon. Definitions include the function body with {}." << endl << endl;
    
    // Question 3: Pass by Value
    cout << "Q3: What happens when you pass a variable by value?" << endl;
    cout << "A) The function receives the memory address" << endl;
    cout << "B) A copy of the variable is created" << endl;
    cout << "C) The original variable can be modified" << endl;
    cout << "D) It is more efficient than pass by reference" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "CORRECT!" << endl;
        score++;
    } else {
        cout << "INCORRECT. Correct Answer: B" << endl;
    }
    cout << "Explanation: Pass by value creates a copy. Changes inside the function" << endl;
    cout << "don't affect the original. Safe but can be expensive for large objects." << endl << endl;
    
    // Question 4: Pass by Pointer
    cout << "Q4: What is the correct way to modify a value through a pointer parameter?" << endl;
    cout << "A) *ptr = newValue;" << endl;
    cout << "B) ptr = newValue;" << endl;
    cout << "C) &ptr = newValue;" << endl;
    cout << "D) ptr* = newValue;" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'A' || answer == 'a') {
        cout << "CORRECT!" << endl;
        score++;
    } else {
        cout << "INCORRECT. Correct Answer: A" << endl;
    }
    cout << "Explanation: Use the dereference operator (*) to access/modify the value" << endl;
    cout << "pointed to. ptr = newValue would change where the pointer points." << endl << endl;
    
    // Question 5: Pass by Reference
    cout << "Q5: Which statement about references is TRUE?" << endl;
    cout << "A) References can be null" << endl;
    cout << "B) References must be initialized when declared" << endl;
    cout << "C) References can be reassigned to refer to different variables" << endl;
    cout << "D) References take more memory than pointers" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "CORRECT!" << endl;
        score++;
    } else {
        cout << "INCORRECT. Correct Answer: B" << endl;
    }
    cout << "Explanation: References MUST be initialized and cannot be null or reassigned." << endl;
    cout << "They are aliases to existing variables. Safer than pointers but less flexible." << endl << endl;
    
    // Question 6: Const Parameters
    cout << "Q6: What does 'const int& param' mean in a function parameter?" << endl;
    cout << "A) The reference can be changed to refer to another variable" << endl;
    cout << "B) The value can be modified but not the reference" << endl;
    cout << "C) The referenced value cannot be modified through this parameter" << endl;
    cout << "D) The parameter is passed by value" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'C' || answer == 'c') {
        cout << "CORRECT!" << endl;
        score++;
    } else {
        cout << "INCORRECT. Correct Answer: C" << endl;
    }
    cout << "Explanation: const reference prevents modification while avoiding copies." << endl;
    cout << "Best practice for passing large objects you only need to read." << endl << endl;
    
    // Question 7: Common Pitfall - Dangling Pointer
    cout << "Q7: What problem occurs in this code?" << endl;
    cout << "int* getLocalPtr() { int x = 5; return &x; }" << endl;
    cout << "A) Memory leak" << endl;
    cout << "B) Dangling pointer (returns address of local variable)" << endl;
    cout << "C) Null pointer dereference" << endl;
    cout << "D) No problem, code is correct" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "CORRECT!" << endl;
        score++;
    } else {
        cout << "INCORRECT. Correct Answer: B" << endl;
    }
    cout << "Explanation: Local variables are destroyed when function returns." << endl;
    cout << "Returning their address creates a dangling pointer. Use dynamic allocation or pass by reference instead." << endl << endl;
    
    // Question 8: Multiple Files Compilation
    cout << "Q8: In multi-file projects, where should function declarations typically go?" << endl;
    cout << "A) In the .cpp implementation file only" << endl;
    cout << "B) In a .h header file" << endl;
    cout << "C) In the main() function" << endl;
    cout << "D) Functions don't need declarations in multi-file projects" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "CORRECT!" << endl;
        score++;
    } else {
        cout << "INCORRECT. Correct Answer: B" << endl;
    }
    cout << "Explanation: Header files (.h) contain declarations shared across files." << endl;
    cout << "Implementation (.cpp) files include headers and provide definitions." << endl << endl;
    
    // Question 9: Performance Consideration
    cout << "Q9: For a large std::vector parameter that won't be modified, what's most efficient?" << endl;
    cout << "A) Pass by value: void func(vector<int> v)" << endl;
    cout << "B) Pass by pointer: void func(vector<int>* v)" << endl;
    cout << "C) Pass by const reference: void func(const vector<int>& v)" << endl;
    cout << "D) All are equally efficient" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'C' || answer == 'c') {
        cout << "CORRECT!" << endl;
        score++;
    } else {
        cout << "INCORRECT. Correct Answer: C" << endl;
    }
    cout << "Explanation: const reference avoids copying (efficient) while preventing" << endl;
    cout << "modification (safe). Pass by value copies entire vector (expensive for large data)." << endl << endl;
    
    // Question 10: Pointer vs Reference Choice
    cout << "Q10: When should you prefer pointers over references?" << endl;
    cout << "A) When you need to represent 'no value' (nullptr)" << endl;
    cout << "B) When the parameter will never change" << endl;
    cout << "C) When you want cleaner syntax" << endl;
    cout << "D) Always prefer references over pointers" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'A' || answer == 'a') {
        cout << "CORRECT!" << endl;
        score++;
    } else {
        cout << "INCORRECT. Correct Answer: A" << endl;
    }
    cout << "Explanation: Use pointers when optional (nullable) or when reassignment needed." << endl;
    cout << "Use references when you always need a valid object. References are safer when applicable." << endl << endl;
    
    // Question 11: Array Passing
    cout << "Q11: When passing arrays to functions, what additional parameter is typically needed?" << endl;
    cout << "A) The array type" << endl;
    cout << "B) The array size" << endl;
    cout << "C) The array name" << endl;
    cout << "D) No additional parameter needed" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "CORRECT!" << endl;
        score++;
    } else {
        cout << "INCORRECT. Correct Answer: B" << endl;
    }
    cout << "Explanation: Arrays decay to pointers when passed to functions, losing size info." << endl;
    cout << "Always pass size as separate parameter: void func(int arr[], int size)" << endl << endl;
    
    // Question 12: Function Signature
    cout << "Q12: What makes two functions have different signatures?" << endl;
    cout << "A) Different return types only" << endl;
    cout << "B) Different parameter names only" << endl;
    cout << "C) Different parameter types or number of parameters" << endl;
    cout << "D) Different function body implementation" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'C' || answer == 'c') {
        cout << "CORRECT!" << endl;
        score++;
    } else {
        cout << "INCORRECT. Correct Answer: C" << endl;
    }
    cout << "Explanation: Signature = function name + parameter types (not names or return type)." << endl;
    cout << "Different signatures allow function overloading. Parameter names don't matter." << endl << endl;
    
    // Question 13: Memory Safety
    cout << "Q13: What's the danger of this code?" << endl;
    cout << "void func(int* ptr) { delete[] ptr; }" << endl;
    cout << "A) Memory leak" << endl;
    cout << "B) Caller's pointer becomes dangling after function call" << endl;
    cout << "C) Wrong delete operator (should be delete, not delete[])" << endl;
    cout << "D) No danger, code is safe" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "CORRECT!" << endl;
        score++;
    } else {
        cout << "INCORRECT. Correct Answer: B" << endl;
    }
    cout << "Explanation: Deleting memory that caller still has a pointer to creates" << endl;
    cout << "a dangling pointer. Use pass by reference (int*& ptr) to set nullptr after delete." << endl << endl;
    
    // Question 14: Const Correctness
    cout << "Q14: Which function signature is WRONG for reading but not modifying an array?" << endl;
    cout << "A) void func(const int* arr, int size)" << endl;
    cout << "B) void func(int* const arr, int size)" << endl;
    cout << "C) void func(const int arr[], int size)" << endl;
    cout << "D) All are correct" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "CORRECT!" << endl;
        score++;
    } else {
        cout << "INCORRECT. Correct Answer: B" << endl;
    }
    cout << "Explanation: 'int* const' means pointer is const (can't point elsewhere)" << endl;
    cout << "but data can be modified. Use 'const int*' to make data readonly." << endl << endl;
    
    // Question 15: Best Practices
    cout << "Q15: What is the best practice for function parameter order?" << endl;
    cout << "A) Input parameters first, then output parameters" << endl;
    cout << "B) Output parameters first, then input parameters" << endl;
    cout << "C) Random order doesn't matter" << endl;
    cout << "D) All parameters should be input only" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'A' || answer == 'a') {
        cout << "CORRECT!" << endl;
        score++;
    } else {
        cout << "INCORRECT. Correct Answer: A" << endl;
    }
    cout << "Explanation: Convention is input params first, output params last." << endl;
    cout << "Example: void calcStats(const int* input, int size, int& sum, double& avg)" << endl << endl;
    
    cout << "=== QUIZ COMPLETE ===" << endl;
    cout << "Your Score: " << score << "/15 (" << (score * 100 / 15) << "%)" << endl;
    if (score >= 13) cout << "Excellent! You have mastered Chapter 11!" << endl;
    else if (score >= 10) cout << "Good job! Review the questions you missed." << endl;
    else if (score >= 7) cout << "Fair. More study recommended." << endl;
    else cout << "Needs improvement. Please review the chapter material." << endl;
}

//=== MANDATORY COMPLETE TEST FUNCTIONS ===

void testProblemA1() {
    cout << "Testing Problem A1 - Memory Safe String Processor..." << endl;
    int passed = 0, total = 0;
    
    // Test Case 1: Basic C-string vowel counting
    // Manual calculation: "hello" has 'e' and 'o' = 2 vowels
    // Expected: return 2, string becomes "HELLO"
    total++;
    char test1[] = "hello";
    int result1 = processStringPointer(test1);
    if (result1 == 2 && strcmp(test1, "HELLO") == 0) {
        cout << "Test 1 PASS: Counted 2 vowels and converted to uppercase" << endl;
        passed++;
    } else {
        cout << "Test 1 FAIL: Expected 2 vowels and 'HELLO', Got " << result1 << " and '" << test1 << "'" << endl;
    }
    
    // Test Case 2: C-string with all vowels
    // Manual calculation: "AEIOU" has A, E, I, O, U = 5 vowels
    // Expected: return 5, already uppercase
    total++;
    char test2[] = "AEIOU";
    int result2 = processStringPointer(test2);
    if (result2 == 5 && strcmp(test2, "AEIOU") == 0) {
        cout << "Test 2 PASS: Counted all 5 vowels" << endl;
        passed++;
    } else {
        cout << "Test 2 FAIL: Expected 5, Got " << result2 << endl;
    }
    
    // Test Case 3: Empty C-string
    // Manual calculation: "" has 0 vowels
    // Expected: return 0
    total++;
    char test3[] = "";
    int result3 = processStringPointer(test3);
    if (result3 == 0) {
        cout << "Test 3 PASS: Empty string handled correctly" << endl;
        passed++;
    } else {
        cout << "Test 3 FAIL: Expected 0, Got " << result3 << endl;
    }
    
    // Test Case 4: C-string with no vowels
    // Manual calculation: "xyz" has 0 vowels
    // Expected: return 0, string becomes "XYZ"
    total++;
    char test4[] = "xyz";
    int result4 = processStringPointer(test4);
    if (result4 == 0 && strcmp(test4, "XYZ") == 0) {
        cout << "Test 4 PASS: No vowels counted, converted to uppercase" << endl;
        passed++;
    } else {
        cout << "Test 4 FAIL: Expected 0 and 'XYZ', Got " << result4 << " and '" << test4 << "'" << endl;
    }
    
    // Test Case 5: std::string processing (pass by value)
    // Manual calculation: "programming" has o, a, i = 3 vowels
    // Expected: return 3, original unchanged
    total++;
    string test5 = "programming";
    string original5 = test5;
    int result5 = processStringValue(test5);
    if (result5 == 3 && test5 == original5) {
        cout << "Test 5 PASS: std::string counted correctly, original unchanged" << endl;
        passed++;
    } else {
        cout << "Test 5 FAIL: Expected 3 with unchanged string, Got " << result5 << endl;
    }
    
    // Test Case 6: std::string with mixed case vowels
    // Manual calculation: "AeIoU" has A, e, I, o, U = 5 vowels
    // Expected: return 5
    total++;
    string test6 = "AeIoU";
    int result6 = processStringValue(test6);
    if (result6 == 5) {
        cout << "Test 6 PASS: Mixed case vowels counted" << endl;
        passed++;
    } else {
        cout << "Test 6 FAIL: Expected 5, Got " << result6 << endl;
    }
    
    // Test Case 7: Null pointer safety
    // Manual calculation: nullptr should be handled safely
    // Expected: return 0 or -1 (error code)
    total++;
    int result7 = processStringPointer(nullptr);
    if (result7 == 0 || result7 == -1) {
        cout << "Test 7 PASS: Null pointer handled safely" << endl;
        passed++;
    } else {
        cout << "Test 7 FAIL: Should handle nullptr safely" << endl;
    }
    
    // Test Case 8: Long string with multiple vowels
    // Manual calculation: "beautiful programming" has e,a,u,i,u,o,a,i = 8 vowels
    // Expected: return 8
    total++;
    char test8[] = "beautiful programming";
    int result8 = processStringPointer(test8);
    if (result8 == 8) {
        cout << "Test 8 PASS: Long string vowel count correct" << endl;
        passed++;
    } else {
        cout << "Test 8 FAIL: Expected 8, Got " << result8 << endl;
    }
    
    cout << "Problem A1 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA2() {
    cout << "Testing Problem A2 - Array Statistics with Multiple Parameter Types..." << endl;
    int passed = 0, total = 0;
    
    // Test Case 1: Basic array with odd number of elements
    // Manual calculation: arr = {5, 2, 8, 1, 9}
    // sum = 5+2+8+1+9 = 25
    // avg = 25/5 = 5.0
    // min = 1
    // max = 9
    // sorted for median: {1, 2, 5, 8, 9}, median = 5 (middle element)
    total++;
    int arr1[] = {5, 2, 8, 1, 9};
    int sum1, min1, max1, median1;
    double avg1;
    calculateStats(arr1, 5, sum1, avg1, min1, max1, median1);
    if (sum1 == 25 && abs(avg1 - 5.0) < 0.001 && min1 == 1 && max1 == 9 && median1 == 5) {
        cout << "Test 1 PASS: All statistics correct for odd-sized array" << endl;
        passed++;
    } else {
        cout << "Test 1 FAIL: Expected sum=25 avg=5.0 min=1 max=9 median=5" << endl;
        cout << "Got sum=" << sum1 << " avg=" << avg1 << " min=" << min1 << " max=" << max1 << " median=" << median1 << endl;
    }
    
    // Test Case 2: Even number of elements
    // Manual calculation: arr = {10, 20, 30, 40}
    // sum = 10+20+30+40 = 100
    // avg = 100/4 = 25.0
    // min = 10
    // max = 40
    // sorted: {10, 20, 30, 40}, median = (20+30)/2 = 25
    total++;
    int arr2[] = {10, 20, 30, 40};
    int sum2, min2, max2, median2;
    double avg2;
    calculateStats(arr2, 4, sum2, avg2, min2, max2, median2);
    if (sum2 == 100 && abs(avg2 - 25.0) < 0.001 && min2 == 10 && max2 == 40 && median2 == 25) {
        cout << "Test 2 PASS: All statistics correct for even-sized array" << endl;
        passed++;
    } else {
        cout << "Test 2 FAIL: Expected sum=100 avg=25.0 min=10 max=40 median=25" << endl;
        cout << "Got sum=" << sum2 << " avg=" << avg2 << " min=" << min2 << " max=" << max2 << " median=" << median2 << endl;
    }
    
    // Test Case 3: Single element
    // Manual calculation: arr = {7}
    // sum = 7
    // avg = 7/1 = 7.0
    // min = 7
    // max = 7
    // median = 7
    total++;
    int arr3[] = {7};
    int sum3, min3, max3, median3;
    double avg3;
    calculateStats(arr3, 1, sum3, avg3, min3, max3, median3);
    if (sum3 == 7 && abs(avg3 - 7.0) < 0.001 && min3 == 7 && max3 == 7 && median3 == 7) {
        cout << "Test 3 PASS: Single element handled correctly" << endl;
        passed++;
    } else {
        cout << "Test 3 FAIL: Expected all values = 7" << endl;
        cout << "Got sum=" << sum3 << " avg=" << avg3 << " min=" << min3 << " max=" << max3 << " median=" << median3 << endl;
    }
    
    // Test Case 4: Array with negative numbers
    // Manual calculation: arr = {-5, 3, -1, 7, 2}
    // sum = -5+3-1+7+2 = 6
    // avg = 6/5 = 1.2
    // min = -5
    // max = 7
    // sorted: {-5, -1, 2, 3, 7}, median = 2
    total++;
    int arr4[] = {-5, 3, -1, 7, 2};
    int sum4, min4, max4, median4;
    double avg4;
    calculateStats(arr4, 5, sum4, avg4, min4, max4, median4);
    if (sum4 == 6 && abs(avg4 - 1.2) < 0.001 && min4 == -5 && max4 == 7 && median4 == 2) {
        cout << "Test 4 PASS: Negative numbers handled correctly" << endl;
        passed++;
    } else {
        cout << "Test 4 FAIL: Expected sum=6 avg=1.2 min=-5 max=7 median=2" << endl;
        cout << "Got sum=" << sum4 << " avg=" << avg4 << " min=" << min4 << " max=" << max4 << " median=" << median4 << endl;
    }
    
    // Test Case 5: All same elements
    // Manual calculation: arr = {5, 5, 5, 5}
    // sum = 20
    // avg = 5.0
    // min = 5
    // max = 5
    // median = 5
    total++;
    int arr5[] = {5, 5, 5, 5};
    int sum5, min5, max5, median5;
    double avg5;
    calculateStats(arr5, 4, sum5, avg5, min5, max5, median5);
    if (sum5 == 20 && abs(avg5 - 5.0) < 0.001 && min5 == 5 && max5 == 5 && median5 == 5) {
        cout << "Test 5 PASS: Identical elements handled correctly" << endl;
        passed++;
    } else {
        cout << "Test 5 FAIL: Expected sum=20 avg=5.0 min=5 max=5 median=5" << endl;
        cout << "Got sum=" << sum5 << " avg=" << avg5 << " min=" << min5 << " max=" << max5 << " median=" << median5 << endl;
    }
    
    // Test Case 6: Two elements
    // Manual calculation: arr = {15, 25}
    // sum = 40
    // avg = 20.0
    // min = 15
    // max = 25
    // median = (15+25)/2 = 20
    total++;
    int arr6[] = {15, 25};
    int sum6, min6, max6, median6;
    double avg6;
    calculateStats(arr6, 2, sum6, avg6, min6, max6, median6);
    if (sum6 == 40 && abs(avg6 - 20.0) < 0.001 && min6 == 15 && max6 == 25 && median6 == 20) {
        cout << "Test 6 PASS: Two elements handled correctly" << endl;
        passed++;
    } else {
        cout << "Test 6 FAIL: Expected sum=40 avg=20.0 min=15 max=25 median=20" << endl;
        cout << "Got sum=" << sum6 << " avg=" << avg6 << " min=" << min6 << " max=" << max6 << " median=" << median6 << endl;
    }
    
    // Test Case 7: Large values
    // Manual calculation: arr = {1000, 2000, 3000}
    // sum = 6000
    // avg = 2000.0
    // min = 1000
    // max = 3000
    // median = 2000
    total++;
    int arr7[] = {1000, 2000, 3000};
    int sum7, min7, max7, median7;
    double avg7;
    calculateStats(arr7, 3, sum7, avg7, min7, max7, median7);
    if (sum7 == 6000 && abs(avg7 - 2000.0) < 0.001 && min7 == 1000 && max7 == 3000 && median7 == 2000) {
        cout << "Test 7 PASS: Large values handled correctly" << endl;
        passed++;
    } else {
        cout << "Test 7 FAIL: Expected sum=6000 avg=2000.0 min=1000 max=3000 median=2000" << endl;
        cout << "Got sum=" << sum7 << " avg=" << avg7 << " min=" << min7 << " max=" << max7 << " median=" << median7 << endl;
    }
    
    // Test Case 8: Unsorted array to verify median calculation
    // Manual calculation: arr = {9, 1, 5, 3, 7}
    // sum = 25
    // avg = 5.0
    // min = 1
    // max = 9
    // sorted: {1, 3, 5, 7, 9}, median = 5
    total++;
    int arr8[] = {9, 1, 5, 3, 7};
    int sum8, min8, max8, median8;
    double avg8;
    calculateStats(arr8, 5, sum8, avg8, min8, max8, median8);
    if (sum8 == 25 && abs(avg8 - 5.0) < 0.001 && min8 == 1 && max8 == 9 && median8 == 5) {
        cout << "Test 8 PASS: Median calculated correctly from unsorted array" << endl;
        passed++;
    } else {
        cout << "Test 8 FAIL: Expected sum=25 avg=5.0 min=1 max=9 median=5" << endl;
        cout << "Got sum=" << sum8 << " avg=" << avg8 << " min=" << min8 << " max=" << max8 << " median=" << median8 << endl;
    }
    
    cout << "Problem A2 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA3() {
    cout << "Testing Problem A3 - Multi-File Simulation with ODR..." << endl;
    int passed = 0, total = 0;
    
    // Test Case 1: Add students and verify
    // Manual calculation: Add 3 students
    // Expected: database size = 3
    total++;
    vector<Student> db1;
    addStudent(db1, "Alice", 85);
    addStudent(db1, "Bob", 92);
    addStudent(db1, "Charlie", 78);
    if (db1.size() == 3 && db1[0].name == "Alice" && db1[0].score == 85) {
        cout << "Test 1 PASS: Students added correctly" << endl;
        passed++;
    } else {
        cout << "Test 1 FAIL: Expected 3 students with correct data" << endl;
    }
    
    // Test Case 2: Calculate average score
    // Manual calculation: (85 + 92 + 78) / 3 = 255 / 3 = 85.0
    // Expected: 85.0
    total++;
    vector<Student> db2;
    addStudent(db2, "Alice", 85);
    addStudent(db2, "Bob", 92);
    addStudent(db2, "Charlie", 78);
    double avg = getAverageScore(db2);
    if (abs(avg - 85.0) < 0.001) {
        cout << "Test 2 PASS: Average calculated correctly" << endl;
        passed++;
    } else {
        cout << "Test 2 FAIL: Expected 85.0, Got " << avg << endl;
    }
    
    // Test Case 3: Find top student
    // Manual calculation: Bob has highest score (92)
    // Expected: "Bob"
    total++;
    vector<Student> db3;
    addStudent(db3, "Alice", 85);
    addStudent(db3, "Bob", 92);
    addStudent(db3, "Charlie", 78);
    string top = findTopStudent(db3);
    if (top == "Bob") {
        cout << "Test 3 PASS: Top student identified correctly" << endl;
        passed++;
    } else {
        cout << "Test 3 FAIL: Expected Bob, Got " << top << endl;
    }
    
    // Test Case 4: Update score and verify
    // Manual calculation: Alice 85->95, new avg = (95+92+78)/3 = 265/3 = 88.333...
    // Expected: avg = 88.333..., top still Bob (92 < 95? No, 95 > 92, so Alice is new top)
    total++;
    vector<Student> db4;
    addStudent(db4, "Alice", 85);
    addStudent(db4, "Bob", 92);
    addStudent(db4, "Charlie", 78);
    updateScore(db4, "Alice", 95);
    double newAvg = getAverageScore(db4);
    string newTop = findTopStudent(db4);
    if (abs(newAvg - 88.333) < 0.01 && newTop == "Alice") {
        cout << "Test 4 PASS: Score updated, average and top student recalculated" << endl;
        passed++;
    } else {
        cout << "Test 4 FAIL: Expected avg=88.33 and top=Alice, Got avg=" << newAvg << " top=" << newTop << endl;
    }
    
    // Test Case 5: Single student
    // Manual calculation: Only one student with score 90
    // Expected: avg = 90.0, top = "David"
    total++;
    vector<Student> db5;
    addStudent(db5, "David", 90);
    double singleAvg = getAverageScore(db5);
    string singleTop = findTopStudent(db5);
    if (abs(singleAvg - 90.0) < 0.001 && singleTop == "David") {
        cout << "Test 5 PASS: Single student handled correctly" << endl;
        passed++;
    } else {
        cout << "Test 5 FAIL: Expected avg=90.0 and top=David" << endl;
    }
    
    // Test Case 6: Empty database
    // Manual calculation: No students
    // Expected: avg = 0.0 (or handle gracefully), top = "" or error
    total++;
    vector<Student> db6;
    double emptyAvg = getAverageScore(db6);
    string emptyTop = findTopStudent(db6);
    if (abs(emptyAvg) < 0.001 && emptyTop == "") {
        cout << "Test 6 PASS: Empty database handled gracefully" << endl;
        passed++;
    } else {
        cout << "Test 6 FAIL: Should handle empty database gracefully" << endl;
    }
    
    // Test Case 7: Update non-existent student
    // Manual calculation: Try to update "Zoe" who doesn't exist
    // Expected: database unchanged, size still 2
    total++;
    vector<Student> db7;
    addStudent(db7, "Alice", 85);
    addStudent(db7, "Bob", 92);
    int sizeBefore = db7.size();
    updateScore(db7, "Zoe", 100);
    if (db7.size() == sizeBefore && db7[0].score == 85 && db7[1].score == 92) {
        cout << "Test 7 PASS: Non-existent student update handled correctly" << endl;
        passed++;
    } else {
        cout << "Test 7 FAIL: Should not modify database for non-existent student" << endl;
    }
    
    // Test Case 8: Multiple students with same score
    // Manual calculation: All have score 80, avg = 80.0
    // Expected: first one added is "top" (or any consistent behavior)
    total++;
    vector<Student> db8;
    addStudent(db8, "Alice", 80);
    addStudent(db8, "Bob", 80);
    addStudent(db8, "Charlie", 80);
    double sameAvg = getAverageScore(db8);
    string sameTop = findTopStudent(db8);
    if (abs(sameAvg - 80.0) < 0.001 && !sameTop.empty()) {
        cout << "Test 8 PASS: Same scores handled consistently" << endl;
        passed++;
    } else {
        cout << "Test 8 FAIL: Expected avg=80.0 with valid top student" << endl;
    }
    
    cout << "Problem A3 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA4() {
    cout << "Testing Problem A4 - Dynamic Matrix Operations..." << endl;
    int passed = 0, total = 0;
    
    // Test Case 1: Create and fill 2x3 matrix
    // Manual calculation: Fill with {1,2,3,4,5,6}
    // Expected: matrix[0][0]=1, matrix[0][1]=2, matrix[0][2]=3
    //           matrix[1][0]=4, matrix[1][1]=5, matrix[1][2]=6
    total++;
    int** mat1 = createMatrix(2, 3);
    int values1[] = {1, 2, 3, 4, 5, 6};
    fillMatrix(mat1, 2, 3, values1);
    if (mat1 != nullptr && mat1[0][0] == 1 && mat1[0][2] == 3 && mat1[1][0] == 4 && mat1[1][2] == 6) {
        cout << "Test 1 PASS: Matrix created and filled correctly" << endl;
        passed++;
    } else {
        cout << "Test 1 FAIL: Matrix creation or filling failed" << endl;
    }
    deleteMatrix(mat1, 2);
    
    // Test Case 2: Transpose 3x2 to 2x3
    // Manual calculation: Original:  Transposed:
    //                     1 2         1 3 5
    //                     3 4         2 4 6
    //                     5 6
    // Expected: transposed[0][0]=1, transposed[0][1]=3, transposed[0][2]=5
    //           transposed[1][0]=2, transposed[1][1]=4, transposed[1][2]=6
    total++;
    int** mat2 = createMatrix(3, 2);
    int values2[] = {1, 2, 3, 4, 5, 6};
    fillMatrix(mat2, 3, 2, values2);
    int** trans2 = transposeMatrix(mat2, 3, 2);
    if (trans2 != nullptr && trans2[0][0] == 1 && trans2[0][1] == 3 && trans2[0][2] == 5 &&
        trans2[1][0] == 2 && trans2[1][1] == 4 && trans2[1][2] == 6) {
        cout << "Test 2 PASS: Matrix transposed correctly" << endl;
        passed++;
    } else {
        cout << "Test 2 FAIL: Transpose failed" << endl;
    }
    deleteMatrix(mat2, 3);
    deleteMatrix(trans2, 2);
    
    // Test Case 3: Calculate row sums
    // Manual calculation: Matrix 2x3 with values {1,2,3,4,5,6}
    // Row 0 sum: 1+2+3 = 6
    // Row 1 sum: 4+5+6 = 15
    // Expected: sums = [6, 15]
    total++;
    int** mat3 = createMatrix(2, 3);
    int values3[] = {1, 2, 3, 4, 5, 6};
    fillMatrix(mat3, 2, 3, values3);
    vector<int> sums3;
    calculateRowSums(mat3, 2, 3, sums3);
    if (sums3.size() == 2 && sums3[0] == 6 && sums3[1] == 15) {
        cout << "Test 3 PASS: Row sums calculated correctly" << endl;
        passed++;
    } else {
        cout << "Test 3 FAIL: Expected row sums [6, 15], Got [" << (sums3.size() > 0 ? sums3[0] : 0) 
             << ", " << (sums3.size() > 1 ? sums3[1] : 0) << "]" << endl;
    }
    deleteMatrix(mat3, 2);
    
    // Test Case 4: 1x1 matrix (edge case)
    // Manual calculation: Single element = 42
    // Expected: matrix[0][0] = 42, transpose = same, row sum = 42
    total++;
    int** mat4 = createMatrix(1, 1);
    int values4[] = {42};
    fillMatrix(mat4, 1, 1, values4);
    int** trans4 = transposeMatrix(mat4, 1, 1);
    vector<int> sums4;
    calculateRowSums(mat4, 1, 1, sums4);
    if (mat4[0][0] == 42 && trans4[0][0] == 42 && sums4.size() == 1 && sums4[0] == 42) {
        cout << "Test 4 PASS: 1x1 matrix handled correctly" << endl;
        passed++;
    } else {
        cout << "Test 4 FAIL: 1x1 matrix operations failed" << endl;
    }
    deleteMatrix(mat4, 1);
    deleteMatrix(trans4, 1);
    
    // Test Case 5: Square matrix 3x3
    // Manual calculation: Matrix with values {1,2,3,4,5,6,7,8,9}
    // Row sums: 1+2+3=6, 4+5+6=15, 7+8+9=24
    // Expected: sums = [6, 15, 24]
    total++;
    int** mat5 = createMatrix(3, 3);
    int values5[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    fillMatrix(mat5, 3, 3, values5);
    vector<int> sums5;
    calculateRowSums(mat5, 3, 3, sums5);
    if (sums5.size() == 3 && sums5[0] == 6 && sums5[1] == 15 && sums5[2] == 24) {
        cout << "Test 5 PASS: Square matrix row sums correct" << endl;
        passed++;
    } else {
        cout << "Test 5 FAIL: Expected row sums [6, 15, 24]" << endl;
    }
    deleteMatrix(mat5, 3);
    
    // Test Case 6: Matrix with negative values
    // Manual calculation: 2x2 matrix {-1, 2, -3, 4}
    // Row sums: -1+2=1, -3+4=1
    // Expected: sums = [1, 1]
    total++;
    int** mat6 = createMatrix(2, 2);
    int values6[] = {-1, 2, -3, 4};
    fillMatrix(mat6, 2, 2, values6);
    vector<int> sums6;
    calculateRowSums(mat6, 2, 2, sums6);
    if (sums6.size() == 2 && sums6[0] == 1 && sums6[1] == 1) {
        cout << "Test 6 PASS: Negative values handled correctly" << endl;
        passed++;
    } else {
        cout << "Test 6 FAIL: Expected row sums [1, 1]" << endl;
    }
    deleteMatrix(mat6, 2);
    
    // Test Case 7: Verify pointer set to nullptr after delete
    // Manual calculation: After deleteMatrix, pointer should be nullptr
    // Expected: mat7 == nullptr after deletion
    total++;
    int** mat7 = createMatrix(2, 2);
    int values7[] = {1, 2, 3, 4};
    fillMatrix(mat7, 2, 2, values7);
    deleteMatrix(mat7, 2);
    if (mat7 == nullptr) {
        cout << "Test 7 PASS: Pointer set to nullptr after deletion" << endl;
        passed++;
    } else {
        cout << "Test 7 FAIL: Pointer should be nullptr after deletion" << endl;
    }
    
    // Test Case 8: Wide matrix (more columns than rows)
    // Manual calculation: 2x5 matrix, transpose becomes 5x2
    // Original[0]: 1,2,3,4,5 (sum=15)
    // Original[1]: 6,7,8,9,10 (sum=40)
    // Expected: row sums = [15, 40], transpose dimensions correct
    total++;
    int** mat8 = createMatrix(2, 5);
    int values8[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    fillMatrix(mat8, 2, 5, values8);
    vector<int> sums8;
    calculateRowSums(mat8, 2, 5, sums8);
    int** trans8 = transposeMatrix(mat8, 2, 5);
    if (sums8.size() == 2 && sums8[0] == 15 && sums8[1] == 40 && trans8 != nullptr) {
        cout << "Test 8 PASS: Wide matrix operations correct" << endl;
        passed++;
    } else {
        cout << "Test 8 FAIL: Wide matrix operations failed" << endl;
    }
    deleteMatrix(mat8, 2);
    deleteMatrix(trans8, 5);
    
    cout << "Problem A4 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA5() {
    cout << "Testing Problem A5 - Function Pointer System..." << endl;
    int passed = 0, total = 0;
    
    // Test Case 1: Uppercase transformation
    // Manual calculation: "Hello World" -> "HELLO WORLD"
    // Expected: "HELLO WORLD"
    total++;
    string result1 = processText("Hello World", UPPERCASE, 0);
    if (result1 == "HELLO WORLD") {
        cout << "Test 1 PASS: Uppercase transformation correct" << endl;
        passed++;
    } else {
        cout << "Test 1 FAIL: Expected 'HELLO WORLD', Got '" << result1 << "'" << endl;
    }
    
    // Test Case 2: Lowercase transformation
    // Manual calculation: "Hello World" -> "hello world"
    // Expected: "hello world"
    total++;
    string result2 = processText("Hello World", LOWERCASE, 0);
    if (result2 == "hello world") {
        cout << "Test 2 PASS: Lowercase transformation correct" << endl;
        passed++;
    } else {
        cout << "Test 2 FAIL: Expected 'hello world', Got '" << result2 << "'" << endl;
    }
    
    // Test Case 3: Reverse transformation
    // Manual calculation: "Hello World" -> "dlroW olleH"
    // Expected: "dlroW olleH"
    total++;
    string result3 = processText("Hello World", REVERSE, 0);
    if (result3 == "dlroW olleH") {
        cout << "Test 3 PASS: Reverse transformation correct" << endl;
        passed++;
    } else {
        cout << "Test 3 FAIL: Expected 'dlroW olleH', Got '" << result3 << "'" << endl;
    }
    
    // Test Case 4: Caesar cipher with shift 3
    // Manual calculation: "Hello World" with shift 3
    // H->K, e->h, l->o, l->o, o->r, (space stays), W->Z, o->r, r->u, l->o, d->g
    // Expected: "Khoor Zruog"
    total++;
    string result4 = processText("Hello World", ENCRYPT, 3);
    if (result4 == "Khoor Zruog") {
        cout << "Test 4 PASS: Caesar cipher encryption correct" << endl;
        passed++;
    } else {
        cout << "Test 4 FAIL: Expected 'Khoor Zruog', Got '" << result4 << "'" << endl;
    }
    
    // Test Case 5: Caesar cipher with negative shift
    // Manual calculation: "ABC" with shift -1
    // A->Z, B->A, C->B
    // Expected: "ZAB"
    total++;
    string result5 = processText("ABC", ENCRYPT, -1);
    if (result5 == "ZAB") {
        cout << "Test 5 PASS: Negative Caesar shift correct" << endl;
        passed++;
    } else {
        cout << "Test 5 FAIL: Expected 'ZAB', Got '" << result5 << "'" << endl;
    }
    
    // Test Case 6: Empty string
    // Manual calculation: "" with any operation -> ""
    // Expected: ""
    total++;
    string result6 = processText("", UPPERCASE, 0);
    if (result6 == "") {
        cout << "Test 6 PASS: Empty string handled correctly" << endl;
        passed++;
    } else {
        cout << "Test 6 FAIL: Expected empty string" << endl;
    }
    
    // Test Case 7: Chain operations (uppercase then reverse)
    // Manual calculation: "hello" -> "HELLO" -> "OLLEH"
    // Expected: "OLLEH"
    total++;
    vector<TextOperation> ops7 = {UPPERCASE, REVERSE};
    vector<int> params7 = {0, 0};
    string result7 = chainOperations("hello", ops7, params7);
    if (result7 == "OLLEH") {
        cout << "Test 7 PASS: Chained operations correct" << endl;
        passed++;
    } else {
        cout << "Test 7 FAIL: Expected 'OLLEH', Got '" << result7 << "'" << endl;
    }
    
    // Test Case 8: Chain operations (encrypt then reverse)
    // Manual calculation: "ABC" shift 1 -> "BCD" -> "DCB"
    // Expected: "DCB"
    total++;
    vector<TextOperation> ops8 = {ENCRYPT, REVERSE};
    vector<int> params8 = {1, 0};
    string result8 = chainOperations("ABC", ops8, params8);
    if (result8 == "DCB") {
        cout << "Test 8 PASS: Complex chained operations correct" << endl;
        passed++;
    } else {
        cout << "Test 8 FAIL: Expected 'DCB', Got '" << result8 << "'" << endl;
    }
    
    cout << "Problem A5 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

/* void testProblemA6() {
    cout << "Testing Problem A6 - Complete Memory Management System..." << endl;
    int passed = 0, total = 0;
    
    // Test Case 1: Constructor and basic push_back
    // Manual calculation: Create array with capacity 5, add 3 elements
    // Expected: size=3, capacity=5, elements=[10, 20, 30]
    total++;
    DynamicArray arr1(5);
    arr1.push_back(10);
    arr1.push_back(20);
    arr1.push_back(30);
    if (arr1.getSize() == 3 && arr1.getCapacity() == 5 && arr1.at(0) == 10 && arr1.at(2) == 30) {
        cout << "Test 1 PASS: Constructor and push_back work correctly" << endl;
        passed++;
    } else {
        cout << "Test 1 FAIL: Constructor or push_back failed" << endl;
    }
    
    // Test Case 2: Element modification through reference
    // Manual calculation: arr[0] = 10, modify to 15
    // Expected: arr[0] = 15
    total++;
    DynamicArray arr2(3);
    arr2.push_back(10);
    arr2.at(0) = 15;
    if (arr2.at(0) == 15) {
        cout << "Test 2 PASS: Element modification through reference works" << endl;
        passed++;
    } else {
        cout << "Test 2 FAIL: Expected arr[0]=15, Got " << arr2.at(0) << endl;
    }
    
    // Test Case 3: pop_back functionality
    // Manual calculation: Add 3 elements, pop 1
    // Expected: size=2, last element is second one added
    total++;
    DynamicArray arr3(5);
    arr3.push_back(10);
    arr3.push_back(20);
    arr3.push_back(30);
    arr3.pop_back();
    if (arr3.getSize() == 2 && arr3.at(1) == 20) {
        cout << "Test 3 PASS: pop_back works correctly" << endl;
        passed++;
    } else {
        cout << "Test 3 FAIL: Expected size=2 with last element=20" << endl;
    }
    
    // Test Case 4: Resize to larger capacity
    // Manual calculation: Initial capacity=3, add 3 elements, resize to 10
    // Expected: All elements preserved, capacity=10
    total++;
    DynamicArray arr4(3);
    arr4.push_back(1);
    arr4.push_back(2);
    arr4.push_back(3);
    arr4.resize(10);
    if (arr4.getCapacity() == 10 && arr4.getSize() == 3 && arr4.at(0) == 1 && arr4.at(2) == 3) {
        cout << "Test 4 PASS: Resize preserves data correctly" << endl;
        passed++;
    } else {
        cout << "Test 4 FAIL: Resize failed to preserve data" << endl;
    }
    
    // Test Case 5: Clear functionality
    // Manual calculation: Add 5 elements, clear
    // Expected: size=0, capacity unchanged
    total++;
    DynamicArray arr5(10);
    arr5.push_back(1);
    arr5.push_back(2);
    arr5.push_back(3);
    arr5.push_back(4);
    arr5.push_back(5);
    int capacityBefore = arr5.getCapacity();
    arr5.clear();
    if (arr5.getSize() == 0 && arr5.getCapacity() == capacityBefore) {
        cout << "Test 5 PASS: Clear works correctly, capacity preserved" << endl;
        passed++;
    } else {
        cout << "Test 5 FAIL: Expected size=0 with unchanged capacity" << endl;
    }
    
    // Test Case 6: Deep copy functionality
    // Manual calculation: Create source with [10,20,30], copy to dest
    // Expected: dest has same values, modifying dest doesn't affect source
    total++;
    DynamicArray source(5);
    source.push_back(10);
    source.push_back(20);
    source.push_back(30);
    DynamicArray dest(3);
    dest.copyArray(source);
    dest.at(0) = 99;
    if (dest.getSize() == 3 && dest.at(0) == 99 && source.at(0) == 10) {
        cout << "Test 6 PASS: Deep copy works, source unaffected" << endl;
        passed++;
    } else {
        cout << "Test 6 FAIL: Deep copy failed or affected source" << endl;
    }
    
    // Test Case 7: Fill to capacity and beyond (auto-resize)
    // Manual calculation: Capacity=2, add 3 elements (should trigger resize)
    // Expected: All 3 elements added successfully
    total++;
    DynamicArray arr7(2);
    arr7.push_back(1);
    arr7.push_back(2);
    arr7.push_back(3);  // Should trigger resize
    if (arr7.getSize() == 3 && arr7.at(2) == 3 && arr7.getCapacity() > 2) {
        cout << "Test 7 PASS: Auto-resize on overflow works" << endl;
        passed++;
    } else {
        cout << "Test 7 FAIL: Auto-resize failed" << endl;
    }
    
    // Test Case 8: Multiple pop_back until empty
    // Manual calculation: Add 3, pop 3 times
    // Expected: size=0, no crashes
    total++;
    DynamicArray arr8(5);
    arr8.push_back(10);
    arr8.push_back(20);
    arr8.push_back(30);
    arr8.pop_back();
    arr8.pop_back();
    arr8.pop_back();
    if (arr8.getSize() == 0) {
        cout << "Test 8 PASS: Multiple pop_back to empty array works" << endl;
        passed++;
    } else {
        cout << "Test 8 FAIL: Expected size=0 after popping all elements" << endl;
    }
    
    cout << "Problem A6 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}
 */
void runAllTests() {
    cout << "\n=== RUNNING ALL INTEGRATION PROBLEM TESTS ===" << endl << endl;
    testProblemA1();
    testProblemA2();
    testProblemA3();
    testProblemA4();
    testProblemA5();
    // testProblemA6();
    cout << "=== ALL TESTS COMPLETE ===" << endl << endl;
}

int main() {
    cout << "=====================================================" << endl;
    cout << "   COMPREHENSIVE CHAPTER 11 ASSESSMENT: FUNCTIONS   " << endl;
    cout << "=====================================================" << endl << endl;
    
    cout << "This assessment tests your mastery of:" << endl;
    cout << "- The One Definition Rule" << endl;
    cout << "- Function Declaration and Definition" << endl;
    cout << "- Multiple Files Compilation Model" << endl;
    cout << "- Pass by Value, Pointer, and Reference" << endl;
    cout << "- Memory Management in Functions" << endl;
    cout << "- Integration with Previous Chapters" << endl << endl;
    
    cout << "Choose your assessment mode:" << endl << endl;
    
    cout << "=== INTEGRATION PROBLEMS ===" << endl;
    cout << "1. Problem A1 - Memory Safe String Processor (Easy)" << endl;
    cout << "   Concepts: Function Declaration/Definition, Pass by Value/Pointer" << endl << endl;
    
    cout << "2. Problem A2 - Array Statistics with Multiple Parameter Types (Easy-Medium)" << endl;
    cout << "   Concepts: Pass by Pointer/Reference, Function Overloading, Dynamic Memory" << endl << endl;
    
    cout << "3. Problem A3 - Multi-File Simulation with ODR (Medium)" << endl;
    cout << "   Concepts: One Definition Rule, Function Declarations, Pass by Reference" << endl << endl;
    
    cout << "4. Problem A4 - Dynamic Matrix Operations (Medium-Hard)" << endl;
    cout << "   Concepts: Dynamic Memory, All Passing Methods, Memory Safety" << endl << endl;
    
    cout << "5. Problem A5 - Function Pointer System (Hard)" << endl;
    cout << "   Concepts: ALL Chapter 11 concepts + Function Pointers" << endl << endl;
    
    cout << "6. Problem A6 - Complete Memory Management System (Very Hard)" << endl;
    cout << "   Concepts: ALL Functions + Pointers + References + Dynamic Memory" << endl << endl;
    
    cout << "7. Test All Integration Problems" << endl << endl;
    
    cout << "=== KNOWLEDGE VALIDATION ===" << endl;
    cout << "8. Chapter Knowledge Quiz (15 questions)" << endl << endl;
    
    cout << "=== COMPREHENSIVE ASSESSMENT ===" << endl;
    cout << "9. Full Chapter Assessment (All problems + Quiz)" << endl << endl;
    
    int choice;
    cout << "Enter your choice (1-9): ";
    cin >> choice;
    cout << endl;
    
    switch(choice) {
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
        // case 6: 
        //     testProblemA6(); 
        //     break;
        case 7: 
            runAllTests(); 
            break;
        case 8: 
            knowledgeQuiz(); 
            break;
        case 9:
            runAllTests();
            cout << "\n=== NOW STARTING KNOWLEDGE QUIZ ===" << endl << endl;
            knowledgeQuiz();
            break;
        default: 
            cout << "Invalid choice! Please run again and select 1-9." << endl;
    }
    
    cout << "\n=====================================================" << endl;
    cout << "            ASSESSMENT SESSION COMPLETE             " << endl;
    cout << "=====================================================" << endl;
    cout << "\nRemember: Focus on understanding concepts, not just" << endl;
    cout << "passing tests. Review any failed tests carefully!" << endl;
    
    return 0;
}


/* ## Summary of Assessment

This comprehensive assessment thoroughly tests Chapter 11: Functions through:

### **Section A: Integration Problems**

1. **Problem A1** (Easy) - Combines function declaration/definition with pass by value and pointer, testing basic parameter passing understanding

2. **Problem A2** (Easy-Medium) - Integrates pass by pointer/reference with multiple output parameters, demonstrating when to use each passing method

3. **Problem A3** (Medium) - Simulates multi-file compilation with ODR compliance, using const references and regular references appropriately

4. **Problem A4** (Medium-Hard) - Comprehensive dynamic memory management with all three passing methods, testing memory safety and pointer manipulation

5. **Problem A5** (Hard) - Advanced system using function pointers with all parameter passing methods, chaining operations, and complex transformations

6. **Problem A6** (Very Hard) - Complete dynamic array implementation demonstrating mastery of all concepts: constructors/destructors, references for modification, pointers for dynamic allocation, ODR compliance, and memory safety

### **Section B: Knowledge Quiz**

15 carefully crafted questions covering:
- Core definitions (ODR, declarations vs definitions)
- Parameter passing mechanisms (value, pointer, reference)
- Memory safety (dangling pointers, memory leaks)
- Best practices (const correctness, parameter order)
- Performance considerations
- Common pitfalls and debugging

### **Test Framework**

Each test function includes:
- Complete executable test code (no placeholders)
- Manual calculations verified in comments
- Actual function calls with real parameters
- Expected vs actual comparisons
- Clear PASS/FAIL output
- Pass/fail counters
- Detailed debugging information

All problems integrate multiple concepts and build progressively in difficulty, ensuring comprehensive mastery of Chapter 11! */