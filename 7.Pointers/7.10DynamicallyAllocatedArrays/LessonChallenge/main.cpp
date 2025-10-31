#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

// Problem 1: Easy 1 - Dynamic Array Sum Calculator
// Create a dynamic array of integers, fill it with user input, and calculate the sum
// Input Format: First line contains n (size), next n lines contain integers
// Output Format: Single integer representing the sum of all elements
// Example 1: n=3, elements=[5, 10, 15] → Output: 30
// Example 2: n=4, elements=[1, 2, 3, 4] → Output: 10
// Example 3: n=1, elements=[42] → Output: 42
// Constraints: 1 ≤ n ≤ 1000, -1000 ≤ elements ≤ 1000
int problem1Solution(int n, int* values) {
    // TODO: Implement your solution here using Dynamically allocated arrays
    // Hint: Use 'new int[n]' to create the array, iterate to sum, don't forget 'delete[]'
    int result {};
    int *p_arr = new int[n];
    for (size_t i = 0; i < n; i++)
    {
        p_arr[i] = values[i];
        result += p_arr[i];
    }
    delete [] p_arr;
    p_arr = nullptr;
    return result; // Placeholder return
}

// Problem 2: Easy 2 - Dynamic Array Reversal
// Create a dynamic array, fill it with values, and return a new reversed dynamic array
// Input Format: First line contains n, next line contains n space-separated integers
// Output Format: Print the reversed array elements space-separated
// Example 1: n=4, input=[1, 2, 3, 4] → Output: [4, 3, 2, 1]
// Example 2: n=5, input=[10, 20, 30, 40, 50] → Output: [50, 40, 30, 20, 10]
// Example 3: n=1, input=[7] → Output: [7]
// Constraints: 1 ≤ n ≤ 500, -100 ≤ elements ≤ 100
int* problem2Solution(int n, int* input) {
    // TODO: Implement your solution here using Dynamically allocated arrays
    // Hint: Create new array with 'new int[n]', copy elements in reverse order
    int *p_arr = new int[n];
    for (size_t i = 0 ; i < n ; i++)
    {
            p_arr[n - i - 1] = input[i];
    }
    
    return p_arr; // Placeholder return
}

// Problem 3: Medium - Dynamic 2D Array Matrix Sum
// Create a dynamic 2D array (array of pointers), fill with values, calculate row sums
// Input Format: First line contains rows and cols, next 'rows' lines contain 'cols' integers each
// Output Format: Print sum of each row on separate lines
// Example 1: 2x3 matrix [[1,2,3],[4,5,6]] → Output: 6, 15
// Example 2: 3x2 matrix [[10,20],[30,40],[50,60]] → Output: 30, 70, 110
// Constraints: 1 ≤ rows, cols ≤ 100, -50 ≤ elements ≤ 50
int* problem3Solution(int rows, int cols, int** matrix) {
    // TODO: Implement your solution here using Dynamically allocated arrays
    // Hint: Use 'new int*[rows]' for row pointers, 'new int[cols]' for each row
    int * result = new int[rows]{};
    int** p_matrix = new int*[rows];
    for (size_t i = 0; i < rows; i++)
    {
        p_matrix[i] = new int[cols];
        for (size_t j = 0; j < cols; j++)
        {
           p_matrix[i][j] = matrix[i][j];
           result[i] += p_matrix[i][j] ;
        }
        delete [] p_matrix[i];
    }
    delete [] p_matrix ;
    return result; // Placeholder return
}

// Problem 4: Hard - Dynamic Array String Concatenation
// Create dynamic arrays to store strings, concatenate them with separators
// Input Format: First line contains n (number of strings), next n lines contain strings
// Output Format: Single concatenated string with " | " as separator
// Example 1: n=3, strings=["hello", "world", "test"] → Output: "hello | world | test"
// Example 2: n=2, strings=["C++", "Programming"] → Output: "C++ | Programming"
// Constraints: 1 ≤ n ≤ 50, 1 ≤ string_length ≤ 100
char* problem4Solution(int n, char** strings) {
    // TODO: Implement your solution here using Dynamically allocated arrays
    // Hint: Calculate total length needed, use 'new char[total_length]', use strcpy/strcat
    char separator[] = " | ";
    int length {};
    for (size_t i = 0; i < n; i++)
    {
        string tem = strings[i];
        length += tem.size();
    }
    char * solution = new char[length];
    for (size_t i = 0; i < n; i++)
    {
        if (i == 0)
        {
            strcpy(solution , strings[i]);
            strcat(solution , separator);
            /* code */
        } else if (i + 1 != n ) {
             strcat(solution , strings[i]);
             strcat(solution , separator);
        } else {
             strcat(solution , strings[i]);
        }
        
    }
    cout << "the result is :" << solution << endl;
    return solution; // Placeholder return
}

void testProblem1() {
    cout << "Testing Problem 1 - Dynamic Array Sum Calculator..." << endl;
    
    // Test Case 1: Basic positive numbers
    // Calculation: 5 + 10 + 15 = 30
    int test1[] = {5, 10, 15};
    cout << "Test 1: " << (problem1Solution(3, test1) == 30 ? "PASS" : "FAIL") << " (Expected: 30)" << endl;
    
    // Test Case 2: Mixed positive and negative
    // Calculation: 1 + (-2) + 3 + (-4) = -2
    int test2[] = {1, -2, 3, -4};
    cout << "Test 2: " << (problem1Solution(4, test2) == -2 ? "PASS" : "FAIL") << " (Expected: -2)" << endl;
    
    // Test Case 3: Single element
    // Calculation: 42
    int test3[] = {42};
    cout << "Test 3: " << (problem1Solution(1, test3) == 42 ? "PASS" : "FAIL") << " (Expected: 42)" << endl;
    
    // Test Case 4: All zeros
    // Calculation: 0 + 0 + 0 + 0 + 0 = 0
    int test4[] = {0, 0, 0, 0, 0};
    cout << "Test 4: " << (problem1Solution(5, test4) == 0 ? "PASS" : "FAIL") << " (Expected: 0)" << endl;
    
    // Test Case 5: All negative
    // Calculation: (-1) + (-2) + (-3) = -6
    int test5[] = {-1, -2, -3};
    cout << "Test 5: " << (problem1Solution(3, test5) == -6 ? "PASS" : "FAIL") << " (Expected: -6)" << endl;
    
    // Test Case 6: Large numbers
    // Calculation: 100 + 200 + 300 + 400 = 1000
    int test6[] = {100, 200, 300, 400};
    cout << "Test 6: " << (problem1Solution(4, test6) == 1000 ? "PASS" : "FAIL") << " (Expected: 1000)" << endl;
    
    // Test Case 7: Sequential numbers
    // Calculation: 1 + 2 + 3 + 4 + 5 + 6 = 21
    int test7[] = {1, 2, 3, 4, 5, 6};
    cout << "Test 7: " << (problem1Solution(6, test7) == 21 ? "PASS" : "FAIL") << " (Expected: 21)" << endl;
    
    // Test Case 8: Edge case with boundary values
    // Calculation: 1000 + (-1000) = 0
    int test8[] = {1000, -1000};
    cout << "Test 8: " << (problem1Solution(2, test8) == 0 ? "PASS" : "FAIL") << " (Expected: 0)" << endl;
    
    cout << endl;
}

void testProblem2() {
    cout << "Testing Problem 2 - Dynamic Array Reversal..." << endl;
    
    // Helper function to compare arrays
    auto compareArrays = [](int* arr1, int* arr2, int size) -> bool {
        for(int i = 0; i < size; i++) {
            if(arr1[i] != arr2[i]) return false;
        }
        return true;
    };
    
    // Test Case 1: Basic array reversal
    // Input: [1, 2, 3, 4] → Expected: [4, 3, 2, 1]
    int test1[] = {1, 2, 3, 4};
    int expected1[] = {4, 3, 2, 1};
    int* result1 = problem2Solution(4, test1);
    cout << "Test 1: " << (result1 && compareArrays(result1, expected1, 4) ? "PASS" : "FAIL") << " (Expected: [4,3,2,1])" << endl;
    if(result1) delete[] result1;
    
    // Test Case 2: Single element
    // Input: [7] → Expected: [7]
    int test2[] = {7};
    int expected2[] = {7};
    int* result2 = problem2Solution(1, test2);
    cout << "Test 2: " << (result2 && compareArrays(result2, expected2, 1) ? "PASS" : "FAIL") << " (Expected: [7])" << endl;
    if(result2) delete[] result2;
    
    // Test Case 3: Negative numbers
    // Input: [-1, -2, -3] → Expected: [-3, -2, -1]
    int test3[] = {-1, -2, -3};
    int expected3[] = {-3, -2, -1};
    int* result3 = problem2Solution(3, test3);
    cout << "Test 3: " << (result3 && compareArrays(result3, expected3, 3) ? "PASS" : "FAIL") << " (Expected: [-3,-2,-1])" << endl;
    if(result3) delete[] result3;
    
    // Test Case 4: Mixed positive and negative
    // Input: [10, -20, 30, -40, 50] → Expected: [50, -40, 30, -20, 10]
    int test4[] = {10, -20, 30, -40, 50};
    int expected4[] = {50, -40, 30, -20, 10};
    int* result4 = problem2Solution(5, test4);
    cout << "Test 4: " << (result4 && compareArrays(result4, expected4, 5) ? "PASS" : "FAIL") << " (Expected: [50,-40,30,-20,10])" << endl;
    if(result4) delete[] result4;
    
    // Test Case 5: All zeros
    // Input: [0, 0, 0] → Expected: [0, 0, 0]
    int test5[] = {0, 0, 0};
    int expected5[] = {0, 0, 0};
    int* result5 = problem2Solution(3, test5);
    cout << "Test 5: " << (result5 && compareArrays(result5, expected5, 3) ? "PASS" : "FAIL") << " (Expected: [0,0,0])" << endl;
    if(result5) delete[] result5;
    
    // Test Case 6: Two elements
    // Input: [100, 200] → Expected: [200, 100]
    int test6[] = {100, 200};
    int expected6[] = {200, 100};
    int* result6 = problem2Solution(2, test6);
    cout << "Test 6: " << (result6 && compareArrays(result6, expected6, 2) ? "PASS" : "FAIL") << " (Expected: [200,100])" << endl;
    if(result6) delete[] result6;
    
    // Test Case 7: Palindromic array
    // Input: [1, 2, 3, 2, 1] → Expected: [1, 2, 3, 2, 1]
    int test7[] = {1, 2, 3, 2, 1};
    int expected7[] = {1, 2, 3, 2, 1};
    int* result7 = problem2Solution(5, test7);
    cout << "Test 7: " << (result7 && compareArrays(result7, expected7, 5) ? "PASS" : "FAIL") << " (Expected: [1,2,3,2,1])" << endl;
    if(result7) delete[] result7;
    
    // Test Case 8: Large array
    // Input: [1, 2, 3, 4, 5, 6, 7, 8] → Expected: [8, 7, 6, 5, 4, 3, 2, 1]
    int test8[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int expected8[] = {8, 7, 6, 5, 4, 3, 2, 1};
    int* result8 = problem2Solution(8, test8);
    cout << "Test 8: " << (result8 && compareArrays(result8, expected8, 8) ? "PASS" : "FAIL") << " (Expected: [8,7,6,5,4,3,2,1])" << endl;
    if(result8) delete[] result8;
    
    cout << endl;
}

void testProblem3() {
    cout << "Testing Problem 3 - Dynamic 2D Array Matrix Sum..." << endl;
    
    // Helper function to create 2D array
    auto create2DArray = [](int rows, int cols, int* data) -> int** {
        int** matrix = new int*[rows];
        for(int i = 0; i < rows; i++) {
            matrix[i] = new int[cols];
            for(int j = 0; j < cols; j++) {
                matrix[i][j] = data[i * cols + j];
            }
        }
        return matrix;
    };
    
    // Helper function to delete 2D array
    auto delete2DArray = [](int** matrix, int rows) {
        for(int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    };
    
    // Helper function to compare arrays
    auto compareArrays = [](int* arr1, int* arr2, int size) -> bool {
        for(int i = 0; i < size; i++) {
            if(arr1[i] != arr2[i]) return false;
        }
        return true;
    };
    
    // Test Case 1: Basic 2x3 matrix
    // Matrix: [[1,2,3],[4,5,6]] → Row sums: [6, 15]
    // Calculation: Row 0: 1+2+3=6, Row 1: 4+5+6=15
    int data1[] = {1, 2, 3, 4, 5, 6};
    int** matrix1 = create2DArray(2, 3, data1);
    int expected1[] = {6, 15};
    int* result1 = problem3Solution(2, 3, matrix1);
    cout << "Test 1: " << (result1 && compareArrays(result1, expected1, 2) ? "PASS" : "FAIL") << " (Expected: [6,15])" << endl;
    if(result1) delete[] result1;
    delete2DArray(matrix1, 2);
    
    // Test Case 2: Single row
    // Matrix: [[10,20,30,40]] → Row sums: [100]
    // Calculation: Row 0: 10+20+30+40=100
    int data2[] = {10, 20, 30, 40};
    int** matrix2 = create2DArray(1, 4, data2);
    int expected2[] = {100};
    int* result2 = problem3Solution(1, 4, matrix2);
    cout << "Test 2: " << (result2 && compareArrays(result2, expected2, 1) ? "PASS" : "FAIL") << " (Expected: [100])" << endl;
    if(result2) delete[] result2;
    delete2DArray(matrix2, 1);
    
    // Test Case 3: Single column
    // Matrix: [[5],[10],[15]] → Row sums: [5, 10, 15]
    // Calculation: Row 0: 5, Row 1: 10, Row 2: 15
    int data3[] = {5, 10, 15};
    int** matrix3 = create2DArray(3, 1, data3);
    int expected3[] = {5, 10, 15};
    int* result3 = problem3Solution(3, 1, matrix3);
    cout << "Test 3: " << (result3 && compareArrays(result3, expected3, 3) ? "PASS" : "FAIL") << " (Expected: [5,10,15])" << endl;
    if(result3) delete[] result3;
    delete2DArray(matrix3, 3);
    
    // Test Case 4: Matrix with negative numbers
    // Matrix: [[-1,2],[-3,4],[5,-6]] → Row sums: [1, 1, -1]
    // Calculation: Row 0: -1+2=1, Row 1: -3+4=1, Row 2: 5+(-6)=-1
    int data4[] = {-1, 2, -3, 4, 5, -6};
    int** matrix4 = create2DArray(3, 2, data4);
    int expected4[] = {1, 1, -1};
    int* result4 = problem3Solution(3, 2, matrix4);
    cout << "Test 4: " << (result4 && compareArrays(result4, expected4, 3) ? "PASS" : "FAIL") << " (Expected: [1,1,-1])" << endl;
    if(result4) delete[] result4;
    delete2DArray(matrix4, 3);
    
    // Test Case 5: All zeros
    // Matrix: [[0,0,0],[0,0,0]] → Row sums: [0, 0]
    // Calculation: Row 0: 0+0+0=0, Row 1: 0+0+0=0
    int data5[] = {0, 0, 0, 0, 0, 0};
    int** matrix5 = create2DArray(2, 3, data5);
    int expected5[] = {0, 0};
    int* result5 = problem3Solution(2, 3, matrix5);
    cout << "Test 5: " << (result5 && compareArrays(result5, expected5, 2) ? "PASS" : "FAIL") << " (Expected: [0,0])" << endl;
    if(result5) delete[] result5;
    delete2DArray(matrix5, 2);
    
    // Test Case 6: 1x1 matrix
    // Matrix: [[42]] → Row sums: [42]
    // Calculation: Row 0: 42
    int data6[] = {42};
    int** matrix6 = create2DArray(1, 1, data6);
    int expected6[] = {42};
    int* result6 = problem3Solution(1, 1, matrix6);
    cout << "Test 6: " << (result6 && compareArrays(result6, expected6, 1) ? "PASS" : "FAIL") << " (Expected: [42])" << endl;
    if(result6) delete[] result6;
    delete2DArray(matrix6, 1);
    
    // Test Case 7: Large positive numbers
    // Matrix: [[100,200],[300,400],[500,600]] → Row sums: [300, 700, 1100]
    // Calculation: Row 0: 100+200=300, Row 1: 300+400=700, Row 2: 500+600=1100
    int data7[] = {100, 200, 300, 400, 500, 600};
    int** matrix7 = create2DArray(3, 2, data7);
    int expected7[] = {300, 700, 1100};
    int* result7 = problem3Solution(3, 2, matrix7);
    cout << "Test 7: " << (result7 && compareArrays(result7, expected7, 3) ? "PASS" : "FAIL") << " (Expected: [300,700,1100])" << endl;
    if(result7) delete[] result7;
    delete2DArray(matrix7, 3);
    
    // Test Case 8: Square matrix
    // Matrix: [[1,2,3],[4,5,6],[7,8,9]] → Row sums: [6, 15, 24]
    // Calculation: Row 0: 1+2+3=6, Row 1: 4+5+6=15, Row 2: 7+8+9=24
    int data8[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int** matrix8 = create2DArray(3, 3, data8);
    int expected8[] = {6, 15, 24};
    int* result8 = problem3Solution(3, 3, matrix8);
    cout << "Test 8: " << (result8 && compareArrays(result8, expected8, 3) ? "PASS" : "FAIL") << " (Expected: [6,15,24])" << endl;
    if(result8) delete[] result8;
    delete2DArray(matrix8, 3);
    
    cout << endl;
}

void testProblem4() {
    cout << "Testing Problem 4 - Dynamic Array String Concatenation..." << endl;
    
    // Helper function to create string array
    auto createStringArray = [](int n, const char* strs[]) -> char** {
        char** strings = new char*[n];
        for(int i = 0; i < n; i++) {
            int len = strlen(strs[i]);
            strings[i] = new char[len + 1];
            strcpy(strings[i], strs[i]);
        }
        return strings;
    };
    
    // Helper function to delete string array
    auto deleteStringArray = [](char** strings, int n) {
        for(int i = 0; i < n; i++) {
            delete[] strings[i];
        }
        delete[] strings;
    };
    
    // Test Case 1: Basic three strings
    // Input: ["hello", "world", "test"] → Output: "hello | world | test"
    // Calculation: 5 + 3 + 5 + 3 + 4 + 1 = 21 characters
    const char* test1_input[] = {"hello", "world", "test"};
    char** strings1 = createStringArray(3, test1_input);
    char* result1 = problem4Solution(3, strings1);
    bool pass1 = result1 && strcmp(result1, "hello | world | test") == 0;
    cout << "Test 1: " << (pass1 ? "PASS" : "FAIL") << " (Expected: \"hello | world | test\")" << endl;
    if(result1) delete[] result1;
    deleteStringArray(strings1, 3);
    
    // Test Case 2: Two strings
    // Input: ["C++", "Programming"] → Output: "C++ | Programming"
    // Calculation: 3 + 3 + 11 + 1 = 18 characters
    const char* test2_input[] = {"C++", "Programming"};
    char** strings2 = createStringArray(2, test2_input);
    char* result2 = problem4Solution(2, strings2);
    bool pass2 = result2 && strcmp(result2, "C++ | Programming") == 0;
    cout << "Test 2: " << (pass2 ? "PASS" : "FAIL") << " (Expected: \"C++ | Programming\")" << endl;
    if(result2) delete[] result2;
    deleteStringArray(strings2, 2);
    
    // Test Case 3: Single string
    // Input: ["Solo"] → Output: "Solo"
    // Calculation: 4 + 1 = 5 characters
    const char* test3_input[] = {"Solo"};
    char** strings3 = createStringArray(1, test3_input);
    char* result3 = problem4Solution(1, strings3);
    bool pass3 = result3 && strcmp(result3, "Solo") == 0;
    cout << "Test 3: " << (pass3 ? "PASS" : "FAIL") << " (Expected: \"Solo\")" << endl;
    if(result3) delete[] result3;
    deleteStringArray(strings3, 1);
    
    // Test Case 4: Empty strings
    // Input: ["", "test", ""] → Output: " | test | "
    // Calculation: 0 + 3 + 4 + 3 + 0 + 1 = 11 characters
    const char* test4_input[] = {"", "test", ""};
    char** strings4 = createStringArray(3, test4_input);
    char* result4 = problem4Solution(3, strings4);
    bool pass4 = result4 && strcmp(result4, " | test | ") == 0;
    cout << "Test 4: " << (pass4 ? "PASS" : "FAIL") << " (Expected: \" | test | \")" << endl;
    if(result4) delete[] result4;
    deleteStringArray(strings4, 3);
    
    // Test Case 5: Numbers as strings
    // Input: ["1", "2", "3", "4"] → Output: "1 | 2 | 3 | 4"
    // Calculation: 1 + 3 + 1 + 3 + 1 + 3 + 1 + 1 = 14 characters
    const char* test5_input[] = {"1", "2", "3", "4"};
    char** strings5 = createStringArray(4, test5_input);
    char* result5 = problem4Solution(4, strings5);
    bool pass5 = result5 && strcmp(result5, "1 | 2 | 3 | 4") == 0;
    cout << "Test 5: " << (pass5 ? "PASS" : "FAIL") << " (Expected: \"1 | 2 | 3 | 4\")" << endl;
    if(result5) delete[] result5;
    deleteStringArray(strings5, 4);
    
    // Test Case 6: Long strings
    // Input: ["Dynamic", "Arrays"] → Output: "Dynamic | Arrays"
    // Calculation: 7 + 3 + 6 + 1 = 17 characters
    const char* test6_input[] = {"Dynamic", "Arrays"};
    char** strings6 = createStringArray(2, test6_input);
    char* result6 = problem4Solution(2, strings6);
    bool pass6 = result6 && strcmp(result6, "Dynamic | Arrays") == 0;
    cout << "Test 6: " << (pass6 ? "PASS" : "FAIL") << " (Expected: \"Dynamic | Arrays\")" << endl;
    if(result6) delete[] result6;
    deleteStringArray(strings6, 2);
    
    // Test Case 7: Special characters
    // Input: ["@", "#", "$"] → Output: "@ | # | $"
    // Calculation: 1 + 3 + 1 + 3 + 1 + 1 = 10 characters
    const char* test7_input[] = {"@", "#", "$"};
    char** strings7 = createStringArray(3, test7_input);
    char* result7 = problem4Solution(3, strings7);
    bool pass7 = result7 && strcmp(result7, "@ | # | $") == 0;
    cout << "Test 7: " << (pass7 ? "PASS" : "FAIL") << " (Expected: \"@ | # | $\")" << endl;
    if(result7) delete[] result7;
    deleteStringArray(strings7, 3);
    
    // Test Case 8: Mixed case and spaces
    // Input: ["Hello World", "C++ is Fun"] → Output: "Hello World | C++ is Fun"
    // Calculation: 11 + 3 + 10 + 1 = 25 characters
    const char* test8_input[] = {"Hello World", "C++ is Fun"};
    char** strings8 = createStringArray(2, test8_input);
    char* result8 = problem4Solution(2, strings8);
    bool pass8 = result8 && strcmp(result8, "Hello World | C++ is Fun") == 0;
    cout << "Test 8: " << (pass8 ? "PASS" : "FAIL") << " (Expected: \"Hello World | C++ is Fun\")" << endl;
    if(result8) delete[] result8;
    deleteStringArray(strings8, 2);
    
    cout << endl;
}

int main() {
    int choice;
    cout << "=== Dynamic Arrays Practice Problems ===" << endl;
    cout << "Choose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy) - Dynamic Array Sum Calculator" << endl;
    cout << "2. Problem 2 (Easy-Medium) - Dynamic Array Reversal" << endl;
    cout << "3. Problem 3 (Medium) - Dynamic 2D Array Matrix Sum" << endl;
    cout << "4. Problem 4 (Hard) - Dynamic Array String Concatenation" << endl;
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
            cout << "All tests completed!" << endl;
            break;
        default: 
            cout << "Invalid choice! Please select 1-5." << endl;
    }

    return 0;
}