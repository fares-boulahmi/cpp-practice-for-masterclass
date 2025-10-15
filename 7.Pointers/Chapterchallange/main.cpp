#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <limits>
#include <climits>
#include <iomanip>

using namespace std;

//=== SECTION A: INTEGRATION PROBLEMS ===

// Problem A1: Foundation Integration - Basic Pointer Operations with Arrays
// Create a function that takes an array of integers and its size through pointers.
// The function should find the maximum value, minimum value, and calculate the average.
// Use pointer arithmetic to traverse the array and dynamic memory for temporary storage.
// Example: array = [10, 5, 8, 20, 3], size = 5
// Output: max = 20, min = 3, average = 9.2
// Input: int* arr - pointer to array, int* size - pointer to size, 
//        double** results - pointer to pointer for storing [max, min, avg]
// Output: void (results stored in dynamically allocated array)
// Constraints: Array size 1-1000, handle null pointers safely
void problemA1Solution(int* arr, int* size, double** results) {
    // TODO: Solve using basic pointers, pointer arithmetic, dynamic allocation
    // Hint: Allocate memory for 3 doubles, use pointer arithmetic to traverse array
    if (arr == nullptr || size == nullptr )
    {
        return ;
    }
    double max {INT_MIN};
    double min {INT_MAX};
    double sum {0};
    *results = new double[3];
    for (int i = 0; i < *size; i++)
    {
        sum +=  *(arr + i);
        if (*(arr + i) < min  )
        {
            min = *(arr + i) ;
        }
        if (*(arr + i) > max)
        {
            max = *(arr + i) ;
        }
    }
    (*results)[0] = max;
    (*results)[1] = min;
    (*results)[2] = sum / *size;
    
}

// Problem A2: Intermediate Synthesis - Dynamic String Manipulation
// Create a function that processes an array of C-style strings using pointers.
// Find the longest string, reverse it, and create a new dynamic array containing
// the original strings plus the reversed longest string at the end.
// Example: strings = ["hello", "world", "programming"], count = 3
// Output: ["hello", "world", "programming", "gnimmargorp"] (programming reversed)
// Input: char** strings - array of string pointers, int count
// Output: char** - new dynamic array with count+1 strings
// Constraints: Handle empty strings, manage memory properly, max string length 100
char** problemA2Solution(char** strings, int count) {
    // TODO: Solve using char pointers, dynamic allocation, string manipulation, pointer arrays
    // Hint: Use strlen, strcpy, create new array of char*, allocate each string separately
    char** rev_arr = new char*[count + 1];
    int longest {};
    int rev_size {};
    for (int i = 0; i < count; i++)
    {
        // *(rev_arr + i) = *(strings + i);
        rev_arr[i] = new char[strlen(strings[i])];
        strcpy(rev_arr[i] , strings[i]);
        if (strlen(strings[i]) > rev_size )
        {
            longest = i;
            rev_size = strlen(strings[i]);
        }  
    }
    char* rev = new char[rev_size];
    rev_arr[count] = new char[rev_size];
    for (int i = 0; i < rev_size; i++)
    {
        rev_arr[count][i] = strings[longest][rev_size - i - 1];
    }
    
    
    return rev_arr;
}

// Problem A3: Advanced Integration - Smart Array Manager
// Implement a dynamic array manager that handles integer arrays with automatic resizing.
// The function should take operations (1=add, 2=remove, 3=insert, 4=get stats) and
// manage memory efficiently. Return a structure containing the array and metadata.
// Operations array format: [operation, value, position] (position used for insert)
// Example: operations = [[1,10,0], [1,20,0], [1,15,0], [3,25,1], [4,0,0]]
// After ops: array contains [10,25,20,15], size=4, capacity>=4
struct ArrayManager {
    int* data;
    int size;
    int capacity;
    double average;
    int min_val;
    int max_val;
};
ArrayManager* problemA3Solution(int operations[][3], int op_count) {
    // TODO: Solve using dynamic allocation, reallocation, pointer manipulation, struct pointers
    // Hint: Start with capacity 2, double when needed, update stats after each operation
    ArrayManager* arrp;
    return arrp;
}

// Problem A4: Complex Synthesis - Memory Pool Allocator
// Create a simple memory pool that pre-allocates a large block and manages smaller allocations.
// Implement allocate and deallocate functions that work with the pool. Track fragmentation.
// The function should process allocation/deallocation requests and return pool statistics.
// Request format: [type, size] where type: 1=allocate, 0=deallocate, size=bytes needed
// Example: pool_size=1024, requests=[[1,100], [1,200], [0,100], [1,150]]
// Track: total_allocated, total_freed, fragmentation_count, largest_free_block
struct MemoryPool {
    char* pool;
    int pool_size;
    int total_allocated;
    int total_freed;
    int fragmentation_count;
    int largest_free_block;
    void** allocation_table;  // Track active allocations
    int allocation_count;
};
MemoryPool* problemA4Solution(int pool_size, int requests[][2], int request_count) {
    // TODO: Solve using void pointers, memory management, pointer arrays, complex allocation logic
    // Hint: Use a simple first-fit algorithm, maintain free list, calculate fragmentation
    MemoryPool* poll;
    return poll;
}

// Problem A5: Mastery Challenge - Multi-Dimensional Dynamic Matrix Operations
// Create a function that manages 2D dynamic matrices and performs complex operations.
// Support operations: create, transpose, multiply, add, and statistical analysis.
// Handle matrices of different sizes and manage all memory dynamically.
// Operation codes: 1=transpose, 2=add with second matrix, 3=multiply, 4=stats, 5=reshape
// Example: matrix1 = [[1,2,3], [4,5,6]] (2x3), operation=1 (transpose)
// Result: [[1,4], [2,5], [3,6]] (3x2)
struct Matrix {
    double** data;
    int rows;
    int cols;
    double determinant;  // For square matrices
    double trace;        // Sum of diagonal elements
    double frobenius_norm; // Square root of sum of squares of all elements
};
Matrix* problemA5Solution(double** matrix1, int rows1, int cols1, 
                         double** matrix2, int rows2, int cols2, 
                         int operation, int* new_rows, int* new_cols) {
    // TODO: Solve using 2D dynamic arrays, complex pointer manipulation, mathematical operations
    // Hint: Allocate array of row pointers, then allocate each row, handle different operations
    Matrix* mtt;
    return mtt;
}

// Problem A6: Expert Application - Advanced Memory Debugger
// Implement a memory tracking system that monitors all dynamic allocations and deallocations.
// Track allocation patterns, detect memory leaks, double frees, and buffer overflows.
// Process a series of memory operations and generate a comprehensive report.
// Operation format: [type, size, id] where type: 1=malloc, 2=free, 3=realloc, 4=access
// For access: size=offset, id=allocation_id to check bounds
// Example: ops=[[1,100,1], [1,200,2], [4,150,1], [2,0,1], [2,0,1]] (double free detected)
struct MemoryTracker {
    void** active_allocations;
    int* allocation_sizes;
    int* allocation_ids;
    int active_count;
    int total_allocations;
    int total_frees;
    int memory_leaks;
    int double_frees;
    int buffer_overflows;
    int peak_memory_usage;
    int current_memory_usage;
};
MemoryTracker* problemA6Solution(int operations[][3], int op_count) {
    // TODO: Solve using advanced pointer tracking, error detection, memory analysis
    // Hint: Maintain allocation table, track sizes, detect invalid operations, calculate statistics
    MemoryTracker* track;
    return track;
}

//=== SECTION B: KNOWLEDGE VALIDATION QUIZ ===

void knowledgeQuiz() {
    cout << "=== CHAPTER 8 POINTERS KNOWLEDGE QUIZ ===" << endl;
    cout << "Answer each question and check your understanding:" << endl << endl;

    int score = 0;
    char answer;

    // Question 1: Basic Pointer Declaration
    cout << "Q1: What is the correct way to declare a pointer to an integer?" << endl;
    cout << "A) int ptr;  B) int *ptr;  C) int &ptr;  D) ptr int;" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "Correct! int *ptr declares a pointer to int." << endl;
        score++;
    } else {
        cout << "Incorrect. Correct Answer: B - int *ptr declares a pointer variable that can hold the address of an integer." << endl;
    }
    cout << endl;

    // Question 2: Pointer Arithmetic
    cout << "Q2: If int *p points to arr[2] in array int arr[5] = {10,20,30,40,50}, what is *(p+1)?" << endl;
    cout << "A) 20  B) 30  C) 40  D) Undefined" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'C' || answer == 'c') {
        cout << "Correct! p+1 moves to arr[3], so *(p+1) = 40." << endl;
        score++;
    } else {
        cout << "Incorrect. Correct Answer: C - p points to arr[2] (30), p+1 points to arr[3] (40)." << endl;
    }
    cout << endl;

    // Question 3: Dynamic Memory Allocation
    cout << "Q3: Which operator is used to dynamically allocate memory in C++?" << endl;
    cout << "A) malloc  B) new  C) alloc  D) create" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "Correct! 'new' operator allocates memory and returns a pointer." << endl;
        score++;
    } else {
        cout << "Incorrect. Correct Answer: B - 'new' is the C++ operator for dynamic memory allocation." << endl;
    }
    cout << endl;

    // Question 4: Memory Deallocation
    cout << "Q4: What happens if you forget to use 'delete' after 'new'?" << endl;
    cout << "A) Compilation error  B) Runtime error  C) Memory leak  D) Automatic cleanup" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'C' || answer == 'c') {
        cout << "Correct! Forgetting delete causes memory leaks." << endl;
        score++;
    } else {
        cout << "Incorrect. Correct Answer: C - Memory leak occurs when allocated memory is not freed." << endl;
    }
    cout << endl;

    // Question 5: Dangling Pointers
    cout << "Q5: What is a dangling pointer?" << endl;
    cout << "A) A null pointer  B) An uninitialized pointer  C) A pointer to freed memory  D) A void pointer" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'C' || answer == 'c') {
        cout << "Correct! A dangling pointer points to memory that has been deallocated." << endl;
        score++;
    } else {
        cout << "Incorrect. Correct Answer: C - Dangling pointer points to freed/deallocated memory." << endl;
    }
    cout << endl;

    // Question 6: Null Pointer Safety
    cout << "Q6: What should you do before dereferencing a pointer?" << endl;
    cout << "A) Initialize it  B) Check if it's not null  C) Cast it  D) Both A and B" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'D' || answer == 'd') {
        cout << "Correct! Always initialize pointers and check for null before dereferencing." << endl;
        score++;
    } else {
        cout << "Incorrect. Correct Answer: D - Both initialization and null checking are essential." << endl;
    }
    cout << endl;

    // Question 7: Dynamic Arrays
    cout << "Q7: How do you allocate a dynamic array of 10 integers?" << endl;
    cout << "A) int *arr = new int(10);  B) int *arr = new int[10];  C) int *arr = new [10]int;  D) int arr = new int*10;" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "Correct! new int[10] allocates array of 10 integers." << endl;
        score++;
    } else {
        cout << "Incorrect. Correct Answer: B - new int[10] is the correct syntax for dynamic arrays." << endl;
    }
    cout << endl;

    // Question 8: Pointer vs Array
    cout << "Q8: In function parameters, what's the difference between int arr[] and int *arr?" << endl;
    cout << "A) arr[] is safer  B) No difference  C) arr[] preserves size  D) *arr is faster" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "Correct! In function parameters, both are equivalent - pointers to the first element." << endl;
        score++;
    } else {
        cout << "Incorrect. Correct Answer: B - Both notations are equivalent in function parameters." << endl;
    }
    cout << endl;

    // Question 9: Memory Layout
    cout << "Q9: Where is dynamically allocated memory stored?" << endl;
    cout << "A) Stack  B) Heap  C) Data segment  D) Code segment" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "Correct! Dynamic memory is allocated on the heap." << endl;
        score++;
    } else {
        cout << "Incorrect. Correct Answer: B - Heap is where dynamic memory allocation occurs." << endl;
    }
    cout << endl;

    // Question 10: Double Pointer
    cout << "Q10: What does int **ptr declare?" << endl;
    cout << "A) Array of pointers  B) Pointer to pointer to int  C) Invalid syntax  D) 2D array" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "Correct! **ptr is a pointer to a pointer to int." << endl;
        score++;
    } else {
        cout << "Incorrect. Correct Answer: B - Double pointer points to another pointer." << endl;
    }
    cout << endl;

    // Question 11: When new Fails
    cout << "Q11: What happens when 'new' cannot allocate requested memory?" << endl;
    cout << "A) Returns null  B) Throws std::bad_alloc  C) Program crashes  D) Returns garbage" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "Correct! Modern C++ throws std::bad_alloc exception when new fails." << endl;
        score++;
    } else {
        cout << "Incorrect. Correct Answer: B - std::bad_alloc exception is thrown when allocation fails." << endl;
    }
    cout << endl;

    // Question 12: Pointer Arithmetic Rules
    cout << "Q12: What is the result of subtracting two pointers of the same type?" << endl;
    cout << "A) Memory address difference  B) Number of elements between them  C) Size in bytes  D) Undefined" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "Correct! Pointer subtraction gives the number of elements between them." << endl;
        score++;
    } else {
        cout << "Incorrect. Correct Answer: B - Subtracting pointers gives element count, not byte difference." << endl;
    }
    cout << endl;

    // Question 13: Const Pointers
    cout << "Q13: What does 'const int* ptr' mean?" << endl;
    cout << "A) Constant pointer  B) Pointer to constant int  C) Both constant  D) Invalid syntax" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "Correct! const int* means pointer to constant integer (value cannot be changed via pointer)." << endl;
        score++;
    } else {
        cout << "Incorrect. Correct Answer: B - const int* is pointer to constant int (value immutable)." << endl;
    }
    cout << endl;

    // Question 14: Memory Management Best Practice
    cout << "Q14: Which is the best practice for preventing memory leaks?" << endl;
    cout << "A) Use global pointers  B) Always pair new with delete  C) Avoid pointers  D) Use malloc instead" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "Correct! Every 'new' should have a corresponding 'delete'." << endl;
        score++;
    } else {
        cout << "Incorrect. Correct Answer: B - Always pair new with delete to prevent memory leaks." << endl;
    }
    cout << endl;

    // Question 15: Advanced Pointer Usage
    cout << "Q15: What is the primary advantage of using pointers?" << endl;
    cout << "A) Faster execution  B) Dynamic memory management  C) Better syntax  D) Automatic cleanup" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "Correct! Pointers enable dynamic memory management and flexible data structures." << endl;
        score++;
    } else {
        cout << "Incorrect. Correct Answer: B - Dynamic memory management is the key advantage of pointers." << endl;
    }
    cout << endl;

    cout << "Quiz Complete! Your Score: " << score << "/15 (" << fixed << setprecision(1) 
         << (score * 100.0 / 15) << "%)" << endl;
    
    if (score >= 13) cout << "Excellent! You have mastered Chapter 8 concepts." << endl;
    else if (score >= 10) cout << "Good job! Review the missed concepts for full mastery." << endl;
    else if (score >= 7) cout << "Fair understanding. More practice with pointers needed." << endl;
    else cout << "Need significant review of pointer concepts before proceeding." << endl;
}

//=== MANDATORY COMPLETE TEST FUNCTIONS ===

void testProblemA1() {
    cout << "Testing Problem A1 - Foundation Integration..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Basic array with positive numbers
    // Manual calculation: arr=[10,5,8,20,3], size=5
    // max = 20, min = 3, sum = 10+5+8+20+3 = 46, avg = 46/5 = 9.2
    // Expected results: [20.0, 3.0, 9.2]
    total++;
    int arr1[] = {10, 5, 8, 20, 3};
    int size1 = 5;
    double* results1 = nullptr;
    problemA1Solution(arr1, &size1, &results1);
    if (results1 && results1[0] == 20.0 && results1[1] == 3.0 && abs(results1[2] - 9.2) < 0.01) {
        cout << "Test 1: PASS" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - Expected: [20.0, 3.0, 9.2], Got: [" 
             << (results1 ? results1[0] : -999) << ", " 
             << (results1 ? results1[1] : -999) << ", " 
             << (results1 ? results1[2] : -999) << "]" << endl;
    }
    delete[] results1;

    // Test Case 2: Single element array
    // Manual calculation: arr=[42], size=1
    // max = 42, min = 42, sum = 42, avg = 42/1 = 42.0
    // Expected results: [42.0, 42.0, 42.0]
    total++;
    int arr2[] = {42};
    int size2 = 1;
    double* results2 = nullptr;
    problemA1Solution(arr2, &size2, &results2);
    if (results2 && results2[0] == 42.0 && results2[1] == 42.0 && results2[2] == 42.0) {
        cout << "Test 2: PASS" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Expected: [42.0, 42.0, 42.0], Got: [" 
             << (results2 ? results2[0] : -999) << ", " 
             << (results2 ? results2[1] : -999) << ", " 
             << (results2 ? results2[2] : -999) << "]" << endl;
    }
    delete[] results2;

    // Test Case 3: Array with negative numbers
    // Manual calculation: arr=[-5,10,-15,25,-10], size=5  
    // max = 25, min = -15, sum = -5+10-15+25-10 = 5, avg = 5/5 = 1.0
    // Expected results: [25.0, -15.0, 1.0]
    total++;
    int arr3[] = {-5, 10, -15, 25, -10};
    int size3 = 5;
    double* results3 = nullptr;
    problemA1Solution(arr3, &size3, &results3);
    if (results3 && results3[0] == 25.0 && results3[1] == -15.0 && abs(results3[2] - 1.0) < 0.01) {
        cout << "Test 3: PASS" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Expected: [25.0, -15.0, 1.0], Got: [" 
             << (results3 ? results3[0] : -999) << ", " 
             << (results3 ? results3[1] : -999) << ", " 
             << (results3 ? results3[2] : -999) << "]" << endl;
    }
    delete[] results3;

    // Test Case 4: Array with duplicates
    // Manual calculation: arr=[7,7,7,7], size=4
    // max = 7, min = 7, sum = 7+7+7+7 = 28, avg = 28/4 = 7.0
    // Expected results: [7.0, 7.0, 7.0]
    total++;
    int arr4[] = {7, 7, 7, 7};
    int size4 = 4;
    double* results4 = nullptr;
    problemA1Solution(arr4, &size4, &results4);
    if (results4 && results4[0] == 7.0 && results4[1] == 7.0 && results4[2] == 7.0) {
        cout << "Test 4: PASS" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Expected: [7.0, 7.0, 7.0], Got: [" 
             << (results4 ? results4[0] : -999) << ", " 
             << (results4 ? results4[1] : -999) << ", " 
             << (results4 ? results4[2] : -999) << "]" << endl;
    }
    delete[] results4;

    // Test Case 5: Large array with mixed values
    // Manual calculation: arr=[100,-50,75,25,-25,150], size=6
    // max = 150, min = -50, sum = 100-50+75+25-25+150 = 275, avg = 275/6 = 45.833...
    // Expected results: [150.0, -50.0, 45.833]
    total++;
    int arr5[] = {100, -50, 75, 25, -25, 150};
    int size5 = 6;
    double* results5 = nullptr;
    problemA1Solution(arr5, &size5, &results5);
    if (results5 && results5[0] == 150.0 && results5[1] == -50.0 && abs(results5[2] - 45.833333) < 0.01) {
        cout << "Test 5: PASS" << endl;
        passed++;
    } else {
        cout << "Test 5: FAIL - Expected: [150.0, -50.0, 45.83], Got: [" 
             << (results5 ? results5[0] : -999) << ", " 
             << (results5 ? results5[1] : -999) << ", " 
             << (results5 ? results5[2] : -999) << "]" << endl;
    }
    delete[] results5;

    // Test Case 6: Edge case - zero values
    // Manual calculation: arr=[0,0,5,0,-5], size=5
    // max = 5, min = -5, sum = 0+0+5+0-5 = 0, avg = 0/5 = 0.0
    // Expected results: [5.0, -5.0, 0.0]
    total++;
    int arr6[] = {0, 0, 5, 0, -5};
    int size6 = 5;
    double* results6 = nullptr;
    problemA1Solution(arr6, &size6, &results6);
    if (results6 && results6[0] == 5.0 && results6[1] == -5.0 && results6[2] == 0.0) {
        cout << "Test 6: PASS" << endl;
        passed++;
    } else {
        cout << "Test 6: FAIL - Expected: [5.0, -5.0, 0.0], Got: [" 
             << (results6 ? results6[0] : -999) << ", " 
             << (results6 ? results6[1] : -999) << ", " 
             << (results6 ? results6[2] : -999) << "]" << endl;
    }
    delete[] results6;

    cout << "Problem A1 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA2() {
    cout << "Testing Problem A2 - Intermediate Synthesis..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Basic string array
    // Manual calculation: strings=["hello", "world", "programming"], count=3
    // lengths: hello=5, world=5, programming=11 (longest)
    // reversed programming = "gnimmargorp" 
    // Expected: ["hello", "world", "programming", "gnimmargorp"]
    total++;
    char* strings1[] = {(char*)"hello", (char*)"world", (char*)"programming"};
    char** result1 = problemA2Solution(strings1, 3);
    if (result1 && strcmp(result1[0], "hello") == 0 && strcmp(result1[1], "world") == 0 && 
        strcmp(result1[2], "programming") == 0 && strcmp(result1[3], "gnimmargorp") == 0) {
        cout << "Test 1: PASS" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - Expected: [\"hello\", \"world\", \"programming\", \"gnimmargorp\"], Got: [";
        if (result1) {
            for (int i = 0; i < 4; i++) {
                cout << "\"" << (result1[i] ? result1[i] : "null") << "\"";
                if (i < 3) cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    // Cleanup
    if (result1) {
        for (int i = 0; i < 4; i++) delete[] result1[i] ; ;
        delete[] result1;
    }

    // Test Case 2: Single character strings
    // Manual calculation: strings=["a", "bb", "c"], count=3
    // lengths: a=1, bb=2 (longest), c=1
    // reversed bb = "bb"
    // Expected: ["a", "bb", "c", "bb"]
    total++;
    char* strings2[] = {(char*)"a", (char*)"bb", (char*)"c"};
    char** result2 = problemA2Solution(strings2, 3);
    if (result2 && strcmp(result2[0], "a") == 0 && strcmp(result2[1], "bb") == 0 && 
        strcmp(result2[2], "c") == 0 && strcmp(result2[3], "bb") == 0) {
        cout << "Test 2: PASS" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Expected: [\"a\", \"bb\", \"c\", \"bb\"], Got: [";
        if (result2) {
            for (int i = 0; i < 4; i++) {
                cout << "\"" << (result2[i] ? result2[i] : "null") << "\"";
                if (i < 3) cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    if (result2) {
        for (int i = 0; i < 4; i++) delete[] result2[i];
        delete[] result2;
    }

    // Test Case 3: Empty string handling
    // Manual calculation: strings=["", "test", ""], count=3
    // lengths: ""=0, test=4 (longest), ""=0
    // reversed test = "tset"
    // Expected: ["", "test", "", "tset"]
    total++;
    char* strings3[] = {(char*)"", (char*)"test", (char*)""};
    char** result3 = problemA2Solution(strings3, 3);
    if (result3 && strcmp(result3[0], "") == 0 && strcmp(result3[1], "test") == 0 && 
        strcmp(result3[2], "") == 0 && strcmp(result3[3], "tset") == 0) {
        cout << "Test 3: PASS" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Expected: [\"\", \"test\", \"\", \"tset\"], Got: [";
        if (result3) {
            for (int i = 0; i < 4; i++) {
                cout << "\"" << (result3[i] ? result3[i] : "null") << "\"";
                if (i < 3) cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    if (result3) {
        for (int i = 0; i < 4; i++) delete[] result3[i];
        delete[] result3;
    }

    // Test Case 4: Single string
    // Manual calculation: strings=["reverse"], count=1
    // lengths: reverse=7 (longest and only)
    // reversed reverse = "esrever"
    // Expected: ["reverse", "esrever"]
    total++;
    char* strings4[] = {(char*)"reverse"};
    char** result4 = problemA2Solution(strings4, 1);
    if (result4 && strcmp(result4[0], "reverse") == 0 && strcmp(result4[1], "esrever") == 0) {
        cout << "Test 4: PASS" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Expected: [\"reverse\", \"esrever\"], Got: [";
        if (result4) {
            for (int i = 0; i < 2; i++) {
                cout << "\"" << (result4[i] ? result4[i] : "null") << "\"";
                if (i < 1) cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    if (result4) {
        for (int i = 0; i < 2; i++) delete[] result4[i];
        delete[] result4;
    }

    // Test Case 5: Tie in longest strings (first occurrence)
    // Manual calculation: strings=["abc", "def", "ghi"], count=3
    // lengths: abc=3, def=3, ghi=3 (all same, take first "abc")
    // reversed abc = "cba"
    // Expected: ["abc", "def", "ghi", "cba"]
    total++;
    char* strings5[] = {(char*)"abc", (char*)"def", (char*)"ghi"};
    char** result5 = problemA2Solution(strings5, 3);
    if (result5 && strcmp(result5[0], "abc") == 0 && strcmp(result5[1], "def") == 0 && 
        strcmp(result5[2], "ghi") == 0 && strcmp(result5[3], "cba") == 0) {
        cout << "Test 5: PASS" << endl;
        passed++;
    } else {
        cout << "Test 5: FAIL - Expected: [\"abc\", \"def\", \"ghi\", \"cba\"], Got: [";
        if (result5) {
            for (int i = 0; i < 4; i++) {
                cout << "\"" << (result5[i] ? result5[i] : "null") << "\"";
                if (i < 3) cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    if (result5) {
        for (int i = 0; i < 4; i++) delete[] result5[i];
        delete[] result5;
    }

    // Test Case 6: Long strings test
    // Manual calculation: strings=["short", "verylongstring", "med"], count=3
    // lengths: short=5, verylongstring=14 (longest), med=3
    // reversed verylongstring = "gnirtsgnolyrev"
    // Expected: ["short", "verylongstring", "med", "gnirtsgnolyrev"]
    total++;
    char* strings6[] = {(char*)"short", (char*)"verylongstring", (char*)"med"};
    char** result6 = problemA2Solution(strings6, 3);
    if (result6 && strcmp(result6[0], "short") == 0 && strcmp(result6[1], "verylongstring") == 0 && 
        strcmp(result6[2], "med") == 0 && strcmp(result6[3], "gnirtsgnolyrev") == 0) {
        cout << "Test 6: PASS" << endl;
        passed++;
    } else {
        cout << "Test 6: FAIL - Expected: [\"short\", \"verylongstring\", \"med\", \"gnirtsgnolyrev\"], Got: [";
        if (result6) {
            for (int i = 0; i < 4; i++) {
                cout << "\"" << (result6[i] ? result6[i] : "null") << "\"";
                if (i < 3) cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    if (result6) {
        for (int i = 0; i < 4; i++) delete[] result6[i];
        delete[] result6;
    }

    cout << "Problem A2 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA3() {
    cout << "Testing Problem A3 - Advanced Integration..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Basic add operations
    // Manual calculation: operations=[[1,10,0], [1,20,0], [1,15,0]]
    // After op1: array=[10], size=1, capacity=2 (start with 2)
    // After op2: array=[10,20], size=2, capacity=2
    // After op3: array=[10,20,15], size=3, capacity=4 (doubled)
    // Stats: min=10, max=20, avg=(10+20+15)/3=15.0
    total++;
    int ops1[][3] = {{1,10,0}, {1,20,0}, {1,15,0}};
    ArrayManager* result1 = problemA3Solution(ops1, 3);
    if (result1 && result1->size == 3 && result1->capacity >= 3 && result1->min_val == 10 && 
        result1->max_val == 20 && abs(result1->average - 15.0) < 0.01) {
        cout << "Test 1: PASS" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - Expected: size=3, min=10, max=20, avg=15.0, Got: ";
        if (result1) {
            cout << "size=" << result1->size << ", min=" << result1->min_val 
                 << ", max=" << result1->max_val << ", avg=" << result1->average << endl;
        } else {
            cout << "null result" << endl;
        }
    }
    if (result1) {
        delete[] result1->data;
        delete result1;
    }

    // Test Case 2: Add and insert operations
    // Manual calculation: operations=[[1,5,0], [1,15,0], [3,10,1]]
    // After add 5: array=[5], size=1
    // After add 15: array=[5,15], size=2  
    // After insert 10 at pos 1: array=[5,10,15], size=3
    // Stats: min=5, max=15, avg=(5+10+15)/3=10.0
    total++;
    int ops2[][3] = {{1,5,0}, {1,15,0}, {3,10,1}};
    ArrayManager* result2 = problemA3Solution(ops2, 3);
    if (result2 && result2->size == 3 && result2->min_val == 5 && 
        result2->max_val == 15 && abs(result2->average - 10.0) < 0.01) {
        cout << "Test 2: PASS" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Expected: size=3, min=5, max=15, avg=10.0, Got: ";
        if (result2) {
            cout << "size=" << result2->size << ", min=" << result2->min_val 
                 << ", max=" << result2->max_val << ", avg=" << result2->average << endl;
        } else {
            cout << "null result" << endl;
        }
    }
    if (result2) {
        delete[] result2->data;
        delete result2;
    }

    // Test Case 3: Add, remove operations
    // Manual calculation: operations=[[1,30,0], [1,40,0], [1,20,0], [2,40,0]]
    // After adds: array=[30,40,20], size=3
    // After remove 40: array=[30,20], size=2
    // Stats: min=20, max=30, avg=(30+20)/2=25.0
    total++;
    int ops3[][3] = {{1,30,0}, {1,40,0}, {1,20,0}, {2,40,0}};
    ArrayManager* result3 = problemA3Solution(ops3, 4);
    if (result3 && result3->size == 2 && result3->min_val == 20 && 
        result3->max_val == 30 && abs(result3->average - 25.0) < 0.01) {
        cout << "Test 3: PASS" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Expected: size=2, min=20, max=30, avg=25.0, Got: ";
        if (result3) {
            cout << "size=" << result3->size << ", min=" << result3->min_val 
                 << ", max=" << result3->max_val << ", avg=" << result3->average << endl;
        } else {
            cout << "null result" << endl;
        }
    }
    if (result3) {
        delete[] result3->data;
        delete result3;
    }

    // Test Case 4: Complex operations with stats call
    // Manual calculation: operations=[[1,100,0], [1,50,0], [3,75,1], [4,0,0]]
    // After adds: array=[100,50], size=2
    // After insert 75 at pos 1: array=[100,75,50], size=3
    // After stats call (op 4): stats updated
    // Stats: min=50, max=100, avg=(100+75+50)/3=75.0
    total++;
    int ops4[][3] = {{1,100,0}, {1,50,0}, {3,75,1}, {4,0,0}};
    ArrayManager* result4 = problemA3Solution(ops4, 4);
    if (result4 && result4->size == 3 && result4->min_val == 50 && 
        result4->max_val == 100 && abs(result4->average - 75.0) < 0.01) {
        cout << "Test 4: PASS" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Expected: size=3, min=50, max=100, avg=75.0, Got: ";
        if (result4) {
            cout << "size=" << result4->size << ", min=" << result4->min_val 
                 << ", max=" << result4->max_val << ", avg=" << result4->average << endl;
        } else {
            cout << "null result" << endl;
        }
    }
    if (result4) {
        delete[] result4->data;
        delete result4;
    }

    // Test Case 5: Capacity growth test (many adds)
    // Manual calculation: operations=[[1,1,0], [1,2,0], [1,3,0], [1,4,0], [1,5,0]]
    // Start capacity=2, after 2 adds: size=2, capacity=2
    // After 3rd add: size=3, capacity=4 (doubled)
    // After 4th add: size=4, capacity=4
    // After 5th add: size=5, capacity=8 (doubled again)
    // Stats: min=1, max=5, avg=(1+2+3+4+5)/5=3.0
    total++;
    int ops5[][3] = {{1,1,0}, {1,2,0}, {1,3,0}, {1,4,0}, {1,5,0}};
    ArrayManager* result5 = problemA3Solution(ops5, 5);
    if (result5 && result5->size == 5 && result5->capacity >= 5 && result5->min_val == 1 && 
        result5->max_val == 5 && abs(result5->average - 3.0) < 0.01) {
        cout << "Test 5: PASS" << endl;
        passed++;
    } else {
        cout << "Test 5: FAIL - Expected: size=5, capacity>=5, min=1, max=5, avg=3.0, Got: ";
        if (result5) {
            cout << "size=" << result5->size << ", capacity=" << result5->capacity 
                 << ", min=" << result5->min_val << ", max=" << result5->max_val 
                 << ", avg=" << result5->average << endl;
        } else {
            cout << "null result" << endl;
        }
    }
    if (result5) {
        delete[] result5->data;
        delete result5;
    }

    cout << "Problem A3 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA4() {
    cout << "Testing Problem A4 - Complex Synthesis..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Basic allocation and deallocation
    // Manual calculation: pool_size=1024, requests=[[1,100], [1,200], [0,100]]
    // After alloc 100: allocated=100, largest_free=924
    // After alloc 200: allocated=300, largest_free=724  
    // After dealloc 100: allocated=200, freed=100, fragmentation increases
    total++;
    int requests1[][2] = {{1,100}, {1,200}, {0,100}};
    MemoryPool* pool1 = problemA4Solution(1024, requests1, 3);
    if (pool1 && pool1->total_allocated >= 200 && pool1->total_freed >= 100 && 
        pool1->pool_size == 1024 && pool1->largest_free_block > 0) {
        cout << "Test 1: PASS" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - Expected: allocated>=200, freed>=100, pool_size=1024, Got: ";
        if (pool1) {
            cout << "allocated=" << pool1->total_allocated << ", freed=" << pool1->total_freed 
                 << ", pool_size=" << pool1->pool_size << ", largest_free=" << pool1->largest_free_block << endl;
        } else {
            cout << "null result" << endl;
        }
    }
    if (pool1) {
        delete[] pool1->pool;
        delete[] pool1->allocation_table;
        delete pool1;
    }

    // Test Case 2: Multiple allocations
    // Manual calculation: pool_size=512, requests=[[1,50], [1,75], [1,100], [1,25]]
    // Total allocation attempts: 50+75+100+25=250 bytes
    // Should fit in 512 byte pool
    total++;
    int requests2[][2] = {{1,50}, {1,75}, {1,100}, {1,25}};
    MemoryPool* pool2 = problemA4Solution(512, requests2, 4);
    if (pool2 && pool2->total_allocated >= 250 && pool2->pool_size == 512 && 
        pool2->allocation_count >= 4) {
        cout << "Test 2: PASS" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Expected: allocated>=250, pool_size=512, allocations>=4, Got: ";
        if (pool2) {
            cout << "allocated=" << pool2->total_allocated << ", pool_size=" << pool2->pool_size 
                 << ", allocations=" << pool2->allocation_count << endl;
        } else {
            cout << "null result" << endl;
        }
    }
    if (pool2) {
        delete[] pool2->pool;
        delete[] pool2->allocation_table;
        delete pool2;
    }

    // Test Case 3: Pool exhaustion test
    // Manual calculation: pool_size=256, requests=[[1,200], [1,100]]
    // First alloc 200: succeeds, remaining=56
    // Second alloc 100: fails (not enough space), allocation_count should be 1
    total++;
    int requests3[][2] = {{1,200}, {1,100}};
    MemoryPool* pool3 = problemA4Solution(256, requests3, 2);
    if (pool3 && pool3->total_allocated <= 200 && pool3->pool_size == 256) {
        cout << "Test 3: PASS" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Expected: allocated<=200, pool_size=256, Got: ";
        if (pool3) {
            cout << "allocated=" << pool3->total_allocated << ", pool_size=" << pool3->pool_size << endl;
        } else {
            cout << "null result" << endl;
        }
    }
    if (pool3) {
        delete[] pool3->pool;
        delete[] pool3->allocation_table;
        delete pool3;
    }

    // Test Case 4: Allocation and deallocation pattern
    // Manual calculation: pool_size=400, requests=[[1,100], [0,100], [1,150], [0,150]]
    // Alloc 100, dealloc 100, alloc 150, dealloc 150
    // Final: allocated=0, freed=250, fragmentation tracking
    total++;
    int requests4[][2] = {{1,100}, {0,100}, {1,150}, {0,150}};
    MemoryPool* pool4 = problemA4Solution(400, requests4, 4);
    if (pool4 && pool4->total_freed >= 250 && pool4->pool_size == 400) {
        cout << "Test 4: PASS" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Expected: freed>=250, pool_size=400, Got: ";
        if (pool4) {
            cout << "freed=" << pool4->total_freed << ", pool_size=" << pool4->pool_size << endl;
        } else {
            cout << "null result" << endl;
        }
    }
    if (pool4) {
        delete[] pool4->pool;
        delete[] pool4->allocation_table;
        delete pool4;
    }

    // Test Case 5: Fragmentation test
    // Manual calculation: pool_size=300, requests=[[1,50], [1,50], [1,50], [0,50], [1,80]]
    // Alloc 50, 50, 50 (total 150), dealloc middle 50, alloc 80
    // Should create fragmentation as 80 > 50 free space in middle
    total++;
    int requests5[][2] = {{1,50}, {1,50}, {1,50}, {0,50}, {1,80}};
    MemoryPool* pool5 = problemA4Solution(300, requests5, 5);
    if (pool5 && pool5->pool_size == 300 && pool5->total_allocated > 0) {
        cout << "Test 5: PASS" << endl;
        passed++;
    } else {
        cout << "Test 5: FAIL - Expected: pool_size=300, allocated>0, Got: ";
        if (pool5) {
            cout << "pool_size=" << pool5->pool_size << ", allocated=" << pool5->total_allocated << endl;
        } else {
            cout << "null result" << endl;
        }
    }
    if (pool5) {
        delete[] pool5->pool;
        delete[] pool5->allocation_table;
        delete pool5;
    }

    cout << "Problem A4 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA5() {
    cout << "Testing Problem A5 - Mastery Challenge..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Matrix transpose operation
    // Manual calculation: matrix1=[[1,2,3], [4,5,6]] (2x3)
    // Transpose: [[1,4], [2,5], [3,6]] (3x2)
    // Frobenius norm = sqrt(1+4+4+25+9+36) = sqrt(79) ≈ 8.888
    total++;
    double* row1[] = {new double[3]{1,2,3}, new double[3]{4,5,6}};
    double** matrix1 = new double*[2];
    matrix1[0] = row1[0]; matrix1[1] = row1[1];
    int new_rows1, new_cols1;
    Matrix* result1 = problemA5Solution(matrix1, 2, 3, nullptr, 0, 0, 1, &new_rows1, &new_cols1);
    if (result1 && new_rows1 == 3 && new_cols1 == 2 && result1->rows == 3 && 
        result1->cols == 2 && abs(result1->frobenius_norm - 8.888) < 0.1) {
        cout << "Test 1: PASS" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - Expected: 3x2 matrix, frobenius≈8.888, Got: ";
        if (result1) {
            cout << result1->rows << "x" << result1->cols << ", frobenius=" << result1->frobenius_norm << endl;
        } else {
            cout << "null result" << endl;
        }
    }
    delete[] row1[0]; delete[] row1[1]; delete[] matrix1;
    if (result1) {
        for (int i = 0; i < result1->rows; i++) delete[] result1->data[i];
        delete[] result1->data;
        delete result1;
    }

    // Test Case 2: Matrix addition
    // Manual calculation: matrix1=[[1,2], [3,4]] + matrix2=[[5,6], [7,8]]
    // Result: [[6,8], [10,12]], trace=6+12=18, frobenius=sqrt(36+64+100+144)=sqrt(344)≈18.547
    total++;
    double* row2a[] = {new double[2]{1,2}, new double[2]{3,4}};
    double* row2b[] = {new double[2]{5,6}, new double[2]{7,8}};
    double** matrix2a = new double*[2];
    double** matrix2b = new double*[2];
    matrix2a[0] = row2a[0]; matrix2a[1] = row2a[1];
    matrix2b[0] = row2b[0]; matrix2b[1] = row2b[1];
    int new_rows2, new_cols2;
    Matrix* result2 = problemA5Solution(matrix2a, 2, 2, matrix2b, 2, 2, 2, &new_rows2, &new_cols2);
    if (result2 && result2->rows == 2 && result2->cols == 2 && 
        abs(result2->trace - 18.0) < 0.01 && abs(result2->frobenius_norm - 18.547) < 0.1) {
        cout << "Test 2: PASS" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Expected: 2x2 matrix, trace=18, frobenius≈18.547, Got: ";
        if (result2) {
            cout << result2->rows << "x" << result2->cols << ", trace=" << result2->trace 
                 << ", frobenius=" << result2->frobenius_norm << endl;
        } else {
            cout << "null result" << endl;
        }
    }
    delete[] row2a[0]; delete[] row2a[1]; delete[] matrix2a;
    delete[] row2b[0]; delete[] row2b[1]; delete[] matrix2b;
    if (result2) {
        for (int i = 0; i < result2->rows; i++) delete[] result2->data[i];
        delete[] result2->data;
        delete result2;
    }

    // Test Case 3: Matrix multiplication
    // Manual calculation: matrix1=[[1,2], [3,4]] * matrix2=[[2,0], [1,3]]
    // Result: [[4,6], [10,12]], trace=4+12=16
    total++;
    double* row3a[] = {new double[2]{1,2}, new double[2]{3,4}};
    double* row3b[] = {new double[2]{2,0}, new double[2]{1,3}};
    double** matrix3a = new double*[2];
    double** matrix3b = new double*[2];
    matrix3a[0] = row3a[0]; matrix3a[1] = row3a[1];
    matrix3b[0] = row3b[0]; matrix3b[1] = row3b[1];
    int new_rows3, new_cols3;
    Matrix* result3 = problemA5Solution(matrix3a, 2, 2, matrix3b, 2, 2, 3, &new_rows3, &new_cols3);
    if (result3 && result3->rows == 2 && result3->cols == 2 && abs(result3->trace - 16.0) < 0.01) {
        cout << "Test 3: PASS" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Expected: 2x2 matrix, trace=16, Got: ";
        if (result3) {
            cout << result3->rows << "x" << result3->cols << ", trace=" << result3->trace << endl;
        } else {
            cout << "null result" << endl;
        }
    }
    delete[] row3a[0]; delete[] row3a[1]; delete[] matrix3a;
    delete[] row3b[0]; delete[] row3b[1]; delete[] matrix3b;
    if (result3) {
        for (int i = 0; i < result3->rows; i++) delete[] result3->data[i];
        delete[] result3->data;
        delete result3;
    }

    // Test Case 4: Single element matrix stats
    // Manual calculation: matrix1=[[42]] (1x1)
    // Stats: determinant=42, trace=42, frobenius=42
    total++;
    double* row4[] = {new double[1]{42}};
    double** matrix4 = new double*[1];
    matrix4[0] = row4[0];
    int new_rows4, new_cols4;
    Matrix* result4 = problemA5Solution(matrix4, 1, 1, nullptr, 0, 0, 4, &new_rows4, &new_cols4);
    if (result4 && result4->rows == 1 && result4->cols == 1 && 
        abs(result4->determinant - 42.0) < 0.01 && abs(result4->trace - 42.0) < 0.01 && 
        abs(result4->frobenius_norm - 42.0) < 0.01) {
        cout << "Test 4: PASS" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Expected: 1x1, det=42, trace=42, frobenius=42, Got: ";
        if (result4) {
            cout << result4->rows << "x" << result4->cols << ", det=" << result4->determinant 
                 << ", trace=" << result4->trace << ", frobenius=" << result4->frobenius_norm << endl;
        } else {
            cout << "null result" << endl;
        }
    }
    delete[] row4[0]; delete[] matrix4;
    if (result4) {
        for (int i = 0; i < result4->rows; i++) delete[] result4->data[i];
        delete[] result4->data;
        delete result4;
    }

    cout << "Problem A5 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA6() {
    cout << "Testing Problem A6 - Expert Application..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Basic allocation and free tracking
    // Manual calculation: ops=[[1,100,1], [1,200,2], [2,0,1], [2,0,2]]
    // Alloc 100 bytes (id=1), alloc 200 bytes (id=2), free id=1, free id=2
    // Expected: total_allocations=2, total_frees=2, memory_leaks=0, double_frees=0
    total++;
    int ops1[][3] = {{1,100,1}, {1,200,2}, {2,0,1}, {2,0,2}};
    MemoryTracker* tracker1 = problemA6Solution(ops1, 4);
    if (tracker1 && tracker1->total_allocations == 2 && tracker1->total_frees == 2 && 
        tracker1->memory_leaks == 0 && tracker1->double_frees == 0) {
        cout << "Test 1: PASS" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - Expected: allocs=2, frees=2, leaks=0, double_frees=0, Got: ";
        if (tracker1) {
            cout << "allocs=" << tracker1->total_allocations << ", frees=" << tracker1->total_frees 
                 << ", leaks=" << tracker1->memory_leaks << ", double_frees=" << tracker1->double_frees << endl;
        } else {
            cout << "null result" << endl;
        }
    }
    if (tracker1) {
        delete[] tracker1->active_allocations;
        delete[] tracker1->allocation_sizes;
        delete[] tracker1->allocation_ids;
        delete tracker1;
    }

    // Test Case 2: Memory leak detection
    // Manual calculation: ops=[[1,150,1], [1,250,2], [2,0,1]]
    // Alloc 150 (id=1), alloc 250 (id=2), free id=1 only
    // Expected: total_allocations=2, total_frees=1, memory_leaks=1 (id=2 not freed)
    total++;
    int ops2[][3] = {{1,150,1}, {1,250,2}, {2,0,1}};
    MemoryTracker* tracker2 = problemA6Solution(ops2, 3);
    if (tracker2 && tracker2->total_allocations == 2 && tracker2->total_frees == 1 && 
        tracker2->memory_leaks == 1 && tracker2->double_frees == 0) {
        cout << "Test 2: PASS" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Expected: allocs=2, frees=1, leaks=1, double_frees=0, Got: ";
        if (tracker2) {
            cout << "allocs=" << tracker2->total_allocations << ", frees=" << tracker2->total_frees 
                 << ", leaks=" << tracker2->memory_leaks << ", double_frees=" << tracker2->double_frees << endl;
        } else {
            cout << "null result" << endl;
        }
    }
    if (tracker2) {
        delete[] tracker2->active_allocations;
        delete[] tracker2->allocation_sizes;
        delete[] tracker2->allocation_ids;
        delete tracker2;
    }

    // Test Case 3: Double free detection
    // Manual calculation: ops=[[1,300,1], [2,0,1], [2,0,1]]
    // Alloc 300 (id=1), free id=1, free id=1 again (double free)
    // Expected: total_allocations=1, total_frees=1, memory_leaks=0, double_frees=1
    total++;
    int ops3[][3] = {{1,300,1}, {2,0,1}, {2,0,1}};
    MemoryTracker* tracker3 = problemA6Solution(ops3, 3);
    if (tracker3 && tracker3->total_allocations == 1 && tracker3->total_frees == 1 && 
        tracker3->memory_leaks == 0 && tracker3->double_frees == 1) {
        cout << "Test 3: PASS" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Expected: allocs=1, frees=1, leaks=0, double_frees=1, Got: ";
        if (tracker3) {
            cout << "allocs=" << tracker3->total_allocations << ", frees=" << tracker3->total_frees 
                 << ", leaks=" << tracker3->memory_leaks << ", double_frees=" << tracker3->double_frees << endl;
        } else {
            cout << "null result" << endl;
        }
    }
    if (tracker3) {
        delete[] tracker3->active_allocations;
        delete[] tracker3->allocation_sizes;
        delete[] tracker3->allocation_ids;
        delete tracker3;
    }

    // Test Case 4: Buffer overflow detection
    // Manual calculation: ops=[[1,100,1], [4,150,1]]
    // Alloc 100 bytes (id=1), access at offset 150 (beyond 100 byte allocation)
    // Expected: total_allocations=1, buffer_overflows=1
    total++;
    int ops4[][3] = {{1,100,1}, {4,150,1}};
    MemoryTracker* tracker4 = problemA6Solution(ops4, 2);
    if (tracker4 && tracker4->total_allocations == 1 && tracker4->buffer_overflows == 1) {
        cout << "Test 4: PASS" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Expected: allocs=1, buffer_overflows=1, Got: ";
        if (tracker4) {
            cout << "allocs=" << tracker4->total_allocations << ", buffer_overflows=" << tracker4->buffer_overflows << endl;
        } else {
            cout << "null result" << endl;
        }
    }
    if (tracker4) {
        delete[] tracker4->active_allocations;
        delete[] tracker4->allocation_sizes;
        delete[] tracker4->allocation_ids;
        delete tracker4;
    }

    // Test Case 5: Peak memory usage tracking
    // Manual calculation: ops=[[1,200,1], [1,300,2], [2,0,1], [1,100,3]]
    // Alloc 200, alloc 300 (peak=500), free 200 (current=300), alloc 100 (current=400)
    // Expected: peak_memory_usage=500, current_memory_usage=400
    total++;
    int ops5[][3] = {{1,200,1}, {1,300,2}, {2,0,1}, {1,100,3}};
    MemoryTracker* tracker5 = problemA6Solution(ops5, 4);
    if (tracker5 && tracker5->peak_memory_usage == 500 && tracker5->current_memory_usage == 400) {
        cout << "Test 5: PASS" << endl;
        passed++;
    } else {
        cout << "Test 5: FAIL - Expected: peak=500, current=400, Got: ";
        if (tracker5) {
            cout << "peak=" << tracker5->peak_memory_usage << ", current=" << tracker5->current_memory_usage << endl;
        } else {
            cout << "null result" << endl;
        }
    }
    if (tracker5) {
        delete[] tracker5->active_allocations;
        delete[] tracker5->allocation_sizes;
        delete[] tracker5->allocation_ids;
        delete tracker5;
    }

    // Test Case 6: Complex scenario with multiple error types
    // Manual calculation: ops=[[1,100,1], [1,200,2], [2,0,3], [4,250,1], [2,0,1], [1,50,2]]
    // Alloc 100 id=1, alloc 200 id=2, free id=3 (invalid), access offset 250 in id=1 (overflow), 
    // free id=1, alloc 50 id=2 (reuse id)
    // Expected: multiple errors detected
    total++;
    int ops6[][3] = {{1,100,1}, {1,200,2}, {2,0,3}, {4,250,1}, {2,0,1}, {1,50,2}};
    MemoryTracker* tracker6 = problemA6Solution(ops6, 6);
    if (tracker6 && tracker6->total_allocations >= 2 && tracker6->buffer_overflows >= 1) {
        cout << "Test 6: PASS" << endl;
        passed++;
    } else {
        cout << "Test 6: FAIL - Expected: allocs>=2, buffer_overflows>=1, Got: ";
        if (tracker6) {
            cout << "allocs=" << tracker6->total_allocations << ", buffer_overflows=" << tracker6->buffer_overflows << endl;
        } else {
            cout << "null result" << endl;
        }
    }
    if (tracker6) {
        delete[] tracker6->active_allocations;
        delete[] tracker6->allocation_sizes;
        delete[] tracker6->allocation_ids;
        delete tracker6;
    }

    cout << "Problem A6 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void runAllTests() {
    cout << "=== RUNNING ALL INTEGRATION PROBLEM TESTS ===" << endl;
    testProblemA1();
    testProblemA2();
    testProblemA3();
    testProblemA4();
    testProblemA5();
    testProblemA6();
    cout << "=== ALL TESTS COMPLETE ===" << endl;
}

int main() {
    cout << "=== COMPREHENSIVE CHAPTER 8 POINTERS ASSESSMENT ===" << endl;
    cout << "Choose your assessment mode:" << endl << endl;

    cout << "INTEGRATION PROBLEMS:" << endl;
    cout << "1. Problem A1 - Foundation Integration (Easy)" << endl;
    cout << "   Basic pointer operations with arrays - find min/max/average" << endl;
    cout << "2. Problem A2 - Intermediate Synthesis (Easy-Medium)" << endl;
    cout << "   Dynamic string manipulation with char pointers" << endl;
    cout << "3. Problem A3 - Advanced Integration (Medium)" << endl;
    cout << "   Smart array manager with dynamic resizing" << endl;
    cout << "4. Problem A4 - Complex Synthesis (Medium-Hard)" << endl;
    cout << "   Memory pool allocator with fragmentation tracking" << endl;
    cout << "5. Problem A5 - Mastery Challenge (Hard)" << endl;
    cout << "   Multi-dimensional dynamic matrix operations" << endl;
    cout << "6. Problem A6 - Expert Application (Very Hard)" << endl;
    cout << "   Advanced memory debugger with leak/overflow detection" << endl;
    cout << "7. Test All Integration Problems" << endl << endl;

    cout << "KNOWLEDGE VALIDATION:" << endl;
    cout << "8. Chapter Knowledge Quiz (15 questions)" << endl << endl;

    cout << "COMPREHENSIVE ASSESSMENT:" << endl;
    cout << "9. Full Chapter Assessment (All problems + Quiz)" << endl << endl;

    int choice;
    cout << "Enter your choice (1-9): ";
    cin >> choice;

    switch(choice) {
        case 1: 
            cout << "\n=== PROBLEM A1: Foundation Integration ===" << endl;
            cout << "Implement basic pointer operations with dynamic memory allocation" << endl;
            testProblemA1(); 
            break;
        case 2: 
            cout << "\n=== PROBLEM A2: Intermediate Synthesis ===" << endl;
            cout << "Process array of C-style strings using pointer manipulation" << endl;
            testProblemA2(); 
            break;
        case 3: 
            cout << "\n=== PROBLEM A3: Advanced Integration ===" << endl;
            cout << "Create dynamic array manager with automatic resizing" << endl;
            testProblemA3(); 
            break;
        case 4: 
            cout << "\n=== PROBLEM A4: Complex Synthesis ===" << endl;
            cout << "Implement memory pool allocator with advanced tracking" << endl;
            testProblemA4(); 
            break;
        case 5: 
            cout << "\n=== PROBLEM A5: Mastery Challenge ===" << endl;
            cout << "Manage 2D dynamic matrices with complex operations" << endl;
            testProblemA5(); 
            break;
        case 6: 
            cout << "\n=== PROBLEM A6: Expert Application ===" << endl;
            cout << "Advanced memory debugger with comprehensive error detection" << endl;
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
            cout << endl;
            knowledgeQuiz();
            break;
        default: 
            cout << "Invalid choice! Please select 1-9." << endl;
    }

    cout << "\n=== ASSESSMENT COMPLETE ===" << endl;
    cout << "Remember to implement the solution functions and run tests to verify your understanding!" << endl;

    return 0;
}