#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// Problem 1: Easy 1 - Dynamic Array Sum Calculator
// Create a function that dynamically allocates an array of integers, 
// fills it with user input, calculates the sum, and properly deallocates memory.
// 
// Input Format: First line contains n (size of array), followed by n integers
// Output Format: Return the sum of all elements
// 
// Example 1:
// Input: n=3, elements: 5, 10, 15
// Output: 30
// 
// Example 2:
// Input: n=1, element: 42
// Output: 42
// 
// Constraints: 1 <= n <= 1000, -1000 <= elements <= 1000
int problem1Solution(int n, int* inputArray) {
    // TODO: Implement your solution here using Dynamic Memory Allocation
    // Hint: Use 'new' to allocate array, calculate sum, then use 'delete[]' to free memory
    int* arr = new int[n];
    int sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        arr[i] = inputArray[i];
        sum += arr[i];
    }
    delete[] arr;
    return sum;
}

// Problem 2: Easy 2 - Dynamic String Concatenator
// Create a function that dynamically allocates memory for two strings,
// concatenates them into a new dynamically allocated string, and returns the result.
// The function should handle proper memory management.
//
// Input Format: Two strings (each up to 100 characters)
// Output Format: Return pointer to the concatenated string
//
// Example 1:
// Input: str1="Hello", str2="World" 
// Output: "HelloWorld"
//
// Example 2:
// Input: str1="C++", str2="Programming"
// Output: "C++Programming"
//
// Constraints: Each string length <= 100 characters
char* problem2Solution(const char* str1, const char* str2) {
    // TODO: Implement your solution here using Dynamic Memory Allocation
    // Hint: Calculate total length needed, allocate with 'new char[]', copy strings, return pointer
    // Remember: Caller is responsible for deleting the returned memory
    char* format = new char[strlen(str1) + strlen(str2) + 1];
    strcpy(format , str1);
    strcat(format , str2);
    char* result = format;
    return result; 
}

// Problem 3: Medium - Dynamic 2D Matrix Operations
// Create a function that dynamically allocates a 2D matrix, fills it with values,
// and returns the sum of all elements in the matrix. Handle proper deallocation.
//
// Input Format: rows, cols, followed by rows*cols integers
// Output Format: Return sum of all matrix elements
//
// Example 1:
// Input: 2 rows, 3 cols, matrix: [[1,2,3], [4,5,6]]
// Output: 21 (1+2+3+4+5+6 = 21)
//
// Example 2:  
// Input: 1 row, 2 cols, matrix: [[10, 20]]
// Output: 30
//
// Constraints: 1 <= rows,cols <= 100, -100 <= elements <= 100
int problem3Solution(int rows, int cols, int** inputMatrix) {
    // TODO: Implement your solution here using Dynamic Memory Allocation
    // Hint: Allocate array of int* pointers, then allocate each row, calculate sum, deallocate properly
    int** solution = new int*[rows];
    int result = 0;
    for (size_t i = 0; i < rows; i++)
    {
        solution[i] = new int[cols];
        for (size_t j = 0; j < cols; j++)
        {
            solution[i][j] = inputMatrix[i][j];
            result += solution[i][j];
        }
        
    }
    
    return result;
}

// Problem 4: Hard - Dynamic Memory Manager with Resizing
// Create a dynamic array that can grow and shrink. Implement functions to:
// - Add element (resize if needed)
// - Remove element at index (resize down if less than 50% full)
// - Get current sum of all elements
// Start with capacity 2, double when full, halve when 25% full (minimum capacity 2)
//
// Input Format: Series of operations: 'A value' (add), 'R index' (remove), 'S' (sum)
// Output Format: For each 'S' operation, return the current sum
//
// Example:
// Operations: A 5, A 10, S, A 15, S, R 1, S
// Outputs: 15, 30, 20
//
// Constraints: -1000 <= values <= 1000, valid indices for remove operations
class DynamicArray {
private:
    int* data;
    int size;
    int capacity;
    
public:
    DynamicArray() {
        // TODO: Initialize with capacity 2
    }
    
    ~DynamicArray() {
        // TODO: Deallocate memory
    }
    
    void add(int value) {
        // TODO: Add element, resize if needed (double capacity when full)
    }
    
    void remove(int index) {
        // TODO: Remove element at index, resize if needed (halve when 25% full, min capacity 2)
    }
    
    int getSum() {
        // TODO: Return sum of all current elements
        return 0;
    }
};

int problem4Solution(string* operations, int numOps) {
    // TODO: Process operations and return final sum
    // Hint: Create DynamicArray instance, process each operation, return sum after last 'S'
    return 0;
}

void testProblem1() {
    cout << "Testing Problem 1: Dynamic Array Sum Calculator..." << endl;
    
    // Test Case 1: Basic positive numbers
    // Manual calculation: 5 + 10 + 15 = 30
    int test1[] = {5, 10, 15};
    cout << "Test 1: " << (problem1Solution(3, test1) == 30 ? "PASS" : "FAIL") << " (Expected: 30)" << endl;
    
    // Test Case 2: Single element
    // Manual calculation: 42
    int test2[] = {42};
    cout << "Test 2: " << (problem1Solution(1, test2) == 42 ? "PASS" : "FAIL") << " (Expected: 42)" << endl;
    
    // Test Case 3: Mix of positive and negative
    // Manual calculation: -5 + 10 + (-3) + 8 = 10
    int test3[] = {-5, 10, -3, 8};
    cout << "Test 3: " << (problem1Solution(4, test3) == 10 ? "PASS" : "FAIL") << " (Expected: 10)" << endl;
    
    // Test Case 4: All zeros
    // Manual calculation: 0 + 0 + 0 = 0
    int test4[] = {0, 0, 0};
    cout << "Test 4: " << (problem1Solution(3, test4) == 0 ? "PASS" : "FAIL") << " (Expected: 0)" << endl;
    
    // Test Case 5: All negative numbers
    // Manual calculation: -1 + (-2) + (-3) + (-4) = -10
    int test5[] = {-1, -2, -3, -4};
    cout << "Test 5: " << (problem1Solution(4, test5) == -10 ? "PASS" : "FAIL") << " (Expected: -10)" << endl;
    
    // Test Case 6: Large numbers
    // Manual calculation: 100 + 200 + 300 + 400 + 500 = 1500
    int test6[] = {100, 200, 300, 400, 500};
    cout << "Test 6: " << (problem1Solution(5, test6) == 1500 ? "PASS" : "FAIL") << " (Expected: 1500)" << endl;
    
    // Test Case 7: Two elements
    // Manual calculation: 25 + 75 = 100
    int test7[] = {25, 75};
    cout << "Test 7: " << (problem1Solution(2, test7) == 100 ? "PASS" : "FAIL") << " (Expected: 100)" << endl;
    
    // Test Case 8: Boundary values
    // Manual calculation: -1000 + 1000 = 0
    int test8[] = {-1000, 1000};
    cout << "Test 8: " << (problem1Solution(2, test8) == 0 ? "PASS" : "FAIL") << " (Expected: 0)" << endl;
    
    cout << endl;
}

void testProblem2() {
    cout << "Testing Problem 2: Dynamic String Concatenator..." << endl;
    
    // Test Case 1: Basic concatenation
    // Manual calculation: "Hello" + "World" = "HelloWorld"
    char* result1 = problem2Solution("Hello", "World");
    bool test1_pass = (result1 != nullptr && strcmp(result1, "HelloWorld") == 0);
    cout << "Test 1: " << (test1_pass ? "PASS" : "FAIL") << " (Expected: HelloWorld)" << endl;
    if (result1) delete[] result1;
    
    // Test Case 2: Programming example
    // Manual calculation: "C++" + "Programming" = "C++Programming"  
    char* result2 = problem2Solution("C++", "Programming");
    bool test2_pass = (result2 != nullptr && strcmp(result2, "C++Programming") == 0);
    cout << "Test 2: " << (test2_pass ? "PASS" : "FAIL") << " (Expected: C++Programming)" << endl;
    if (result2) delete[] result2;
    
    // Test Case 3: Empty first string
    // Manual calculation: "" + "Test" = "Test"
    char* result3 = problem2Solution("", "Test");
    bool test3_pass = (result3 != nullptr && strcmp(result3, "Test") == 0);
    cout << "Test 3: " << (test3_pass ? "PASS" : "FAIL") << " (Expected: Test)" << endl;
    if (result3) delete[] result3;
    
    // Test Case 4: Empty second string
    // Manual calculation: "Test" + "" = "Test"
    char* result4 = problem2Solution("Test", "");
    bool test4_pass = (result4 != nullptr && strcmp(result4, "Test") == 0);
    cout << "Test 4: " << (test4_pass ? "PASS" : "FAIL") << " (Expected: Test)" << endl;
    if (result4) delete[] result4;
    
    // Test Case 5: Both empty strings
    // Manual calculation: "" + "" = ""
    char* result5 = problem2Solution("", "");
    bool test5_pass = (result5 != nullptr && strcmp(result5, "") == 0);
    cout << "Test 5: " << (test5_pass ? "PASS" : "FAIL") << " (Expected: empty string)" << endl;
    if (result5) delete[] result5;
    
    // Test Case 6: Numbers as strings
    // Manual calculation: "123" + "456" = "123456"
    char* result6 = problem2Solution("123", "456");
    bool test6_pass = (result6 != nullptr && strcmp(result6, "123456") == 0);
    cout << "Test 6: " << (test6_pass ? "PASS" : "FAIL") << " (Expected: 123456)" << endl;
    if (result6) delete[] result6;
    
    // Test Case 7: Single characters
    // Manual calculation: "A" + "B" = "AB"
    char* result7 = problem2Solution("A", "B");
    bool test7_pass = (result7 != nullptr && strcmp(result7, "AB") == 0);
    cout << "Test 7: " << (test7_pass ? "PASS" : "FAIL") << " (Expected: AB)" << endl;
    if (result7) delete[] result7;
    
    // Test Case 8: Special characters
    // Manual calculation: "Hello " + "C++!" = "Hello C++!"
    char* result8 = problem2Solution("Hello ", "C++!");
    bool test8_pass = (result8 != nullptr && strcmp(result8, "Hello C++!") == 0);
    cout << "Test 8: " << (test8_pass ? "PASS" : "FAIL") << " (Expected: Hello C++!)" << endl;
    if (result8) delete[] result8;
    
    cout << endl;
}

void testProblem3() {
    cout << "Testing Problem 3: Dynamic 2D Matrix Operations..." << endl;
    
    // Test Case 1: 2x3 matrix
    // Manual calculation: 
    // Matrix: [[1,2,3], [4,5,6]]
    // Sum: 1+2+3+4+5+6 = 21
    int* row1_test1[] = {new int[3]{1,2,3}, new int[3]{4,5,6}};
    int** test1 = new int*[2];
    test1[0] = row1_test1[0]; test1[1] = row1_test1[1];
    cout << "Test 1: " << (problem3Solution(2, 3, test1) == 21 ? "PASS" : "FAIL") << " (Expected: 21)" << endl;
    delete[] test1[0]; delete[] test1[1]; delete[] test1;
    
    // Test Case 2: 1x2 matrix
    // Manual calculation:
    // Matrix: [[10, 20]]  
    // Sum: 10+20 = 30
    int* row1_test2[] = {new int[2]{10, 20}};
    int** test2 = new int*[1];
    test2[0] = row1_test2[0];
    cout << "Test 2: " << (problem3Solution(1, 2, test2) == 30 ? "PASS" : "FAIL") << " (Expected: 30)" << endl;
    delete[] test2[0]; delete[] test2;
    
    // Test Case 3: 3x1 matrix (column vector)
    // Manual calculation:
    // Matrix: [[5], [10], [15]]
    // Sum: 5+10+15 = 30  
    int** test3 = new int*[3];
    test3[0] = new int[1]{5}; test3[1] = new int[1]{10}; test3[2] = new int[1]{15};
    cout << "Test 3: " << (problem3Solution(3, 1, test3) == 30 ? "PASS" : "FAIL") << " (Expected: 30)" << endl;
    delete[] test3[0]; delete[] test3[1]; delete[] test3[2]; delete[] test3;
    
    // Test Case 4: 1x1 matrix
    // Manual calculation:
    // Matrix: [[42]]
    // Sum: 42
    int** test4 = new int*[1];
    test4[0] = new int[1]{42};
    cout << "Test 4: " << (problem3Solution(1, 1, test4) == 42 ? "PASS" : "FAIL") << " (Expected: 42)" << endl;
    delete[] test4[0]; delete[] test4;
    
    // Test Case 5: Matrix with negative numbers
    // Manual calculation:
    // Matrix: [[-1, 2], [3, -4]]  
    // Sum: -1+2+3+(-4) = 0
    int** test5 = new int*[2];
    test5[0] = new int[2]{-1, 2}; test5[1] = new int[2]{3, -4};
    cout << "Test 5: " << (problem3Solution(2, 2, test5) == 0 ? "PASS" : "FAIL") << " (Expected: 0)" << endl;
    delete[] test5[0]; delete[] test5[1]; delete[] test5;
    
    // Test Case 6: All zeros
    // Manual calculation:
    // Matrix: [[0, 0, 0], [0, 0, 0]]
    // Sum: 0+0+0+0+0+0 = 0
    int** test6 = new int*[2];
    test6[0] = new int[3]{0, 0, 0}; test6[1] = new int[3]{0, 0, 0};
    cout << "Test 6: " << (problem3Solution(2, 3, test6) == 0 ? "PASS" : "FAIL") << " (Expected: 0)" << endl;
    delete[] test6[0]; delete[] test6[1]; delete[] test6;
    
    // Test Case 7: Large positive numbers  
    // Manual calculation:
    // Matrix: [[100, 200], [300, 400]]
    // Sum: 100+200+300+400 = 1000
    int** test7 = new int*[2];
    test7[0] = new int[2]{100, 200}; test7[1] = new int[2]{300, 400};
    cout << "Test 7: " << (problem3Solution(2, 2, test7) == 1000 ? "PASS" : "FAIL") << " (Expected: 1000)" << endl;
    delete[] test7[0]; delete[] test7[1]; delete[] test7;
    
    // Test Case 8: Mixed values
    // Manual calculation:
    // Matrix: [[1, -1, 2], [-2, 3, -3], [4, -4, 5]]
    // Sum: 1+(-1)+2+(-2)+3+(-3)+4+(-4)+5 = 5
    int** test8 = new int*[3];
    test8[0] = new int[3]{1, -1, 2}; test8[1] = new int[3]{-2, 3, -3}; test8[2] = new int[3]{4, -4, 5};
    cout << "Test 8: " << (problem3Solution(3, 3, test8) == 5 ? "PASS" : "FAIL") << " (Expected: 5)" << endl;
    delete[] test8[0]; delete[] test8[1]; delete[] test8[2]; delete[] test8;
    
    cout << endl;
}

void testProblem4() {
    cout << "Testing Problem 4: Dynamic Memory Manager with Resizing..." << endl;
    
    // Test Case 1: Basic add and sum operations
    // Manual calculation:
    // A 5: array=[5], sum=5
    // A 10: array=[5,10], sum=15  
    // S: return 15
    string test1[] = {"A 5", "A 10", "S"};
    cout << "Test 1: " << (problem4Solution(test1, 3) == 15 ? "PASS" : "FAIL") << " (Expected: 15)" << endl;
    
    // Test Case 2: Add, sum, add, sum sequence
    // Manual calculation:
    // A 5: array=[5]
    // A 10: array=[5,10] (capacity doubles to 4 when full)
    // S: sum=15
    // A 15: array=[5,10,15]
    // S: return 30
    string test2[] = {"A 5", "A 10", "S", "A 15", "S"};
    cout << "Test 2: " << (problem4Solution(test2, 5) == 30 ? "PASS" : "FAIL") << " (Expected: 30)" << endl;
    
    // Test Case 3: Add, remove, sum
    // Manual calculation:
    // A 10: array=[10]
    // A 20: array=[10,20]
    // A 30: array=[10,20,30] (capacity=4)
    // R 1: remove index 1 (20), array=[10,30]
    // S: return 40
    string test3[] = {"A 10", "A 20", "A 30", "R 1", "S"};
    cout << "Test 3: " << (problem4Solution(test3, 5) == 40 ? "PASS" : "FAIL") << " (Expected: 40)" << endl;
    
    // Test Case 4: Single element operations
    // Manual calculation:
    // A 100: array=[100]
    // S: return 100
    string test4[] = {"A 100", "S"};
    cout << "Test 4: " << (problem4Solution(test4, 2) == 100 ? "PASS" : "FAIL") << " (Expected: 100)" << endl;
    
    // Test Case 5: Remove first element
    // Manual calculation:
    // A 1: array=[1]
    // A 2: array=[1,2] 
    // A 3: array=[1,2,3] (capacity=4)
    // R 0: remove index 0 (1), array=[2,3]
    // S: return 5
    string test5[] = {"A 1", "A 2", "A 3", "R 0", "S"};
    cout << "Test 5: " << (problem4Solution(test5, 5) == 5 ? "PASS" : "FAIL") << " (Expected: 5)" << endl;
    
    // Test Case 6: Negative numbers
    // Manual calculation:
    // A -5: array=[-5]
    // A 10: array=[-5,10]
    // A -3: array=[-5,10,-3] (capacity=4)
    // S: sum = -5+10+(-3) = 2
    string test6[] = {"A -5", "A 10", "A -3", "S"};
    cout << "Test 6: " << (problem4Solution(test6, 4) == 2 ? "PASS" : "FAIL") << " (Expected: 2)" << endl;
    
    // Test Case 7: Multiple removes
    // Manual calculation: 
    // A 1: array=[1]
    // A 2: array=[1,2]
    // A 3: array=[1,2,3] (capacity=4)
    // A 4: array=[1,2,3,4] (capacity=4)
    // R 2: remove index 2 (3), array=[1,2,4]
    // R 0: remove index 0 (1), array=[2,4]  
    // S: sum = 2+4 = 6
    string test7[] = {"A 1", "A 2", "A 3", "A 4", "R 2", "R 0", "S"};
    cout << "Test 7: " << (problem4Solution(test7, 7) == 6 ? "PASS" : "FAIL") << " (Expected: 6)" << endl;
    
    // Test Case 8: Capacity management test
    // Manual calculation:
    // A 5: array=[5], size=1, capacity=2
    // A 10: array=[5,10], size=2, capacity=2 (full)
    // A 15: array=[5,10,15], size=3, capacity=4 (doubled)
    // A 20: array=[5,10,15,20], size=4, capacity=4 (full)  
    // A 25: array=[5,10,15,20,25], size=5, capacity=8 (doubled)
    // S: sum = 5+10+15+20+25 = 75
    string test8[] = {"A 5", "A 10", "A 15", "A 20", "A 25", "S"};
    cout << "Test 8: " << (problem4Solution(test8, 6) == 75 ? "PASS" : "FAIL") << " (Expected: 75)" << endl;
    
    cout << endl;
}

int main() {
    int choice;
    cout << "=== Dynamic Memory Allocation Practice Problems ===" << endl;
    cout << "Choose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy): Dynamic Array Sum Calculator" << endl;
    cout << "2. Problem 2 (Easy): Dynamic String Concatenator" << endl;
    cout << "3. Problem 3 (Medium): Dynamic 2D Matrix Operations" << endl;
    cout << "4. Problem 4 (Hard): Dynamic Memory Manager with Resizing" << endl;
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
            cout << "Invalid choice! Please run the program again." << endl;
            break;
    }

    cout << "Remember to implement the solutions using proper dynamic memory allocation!" << endl;
    cout << "Use 'new' and 'delete'/'delete[]' appropriately for memory management." << endl;
    
    return 0;
}