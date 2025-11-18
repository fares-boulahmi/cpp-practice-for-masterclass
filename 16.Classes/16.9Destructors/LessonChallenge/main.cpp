#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// ============================================================================
// Problem 1: Easy 1 - Resource Counter
// ============================================================================
// Description:
// Create a class called "Resource" that tracks how many instances are created
// and destroyed. The constructor should increment a static counter, and the
// destructor should decrement it.
//
// Your task: Implement a function that creates N Resource objects and returns
// how many are still "alive" after the function completes (should be 0 since
// local objects are destroyed when function ends).
//
// Input Format:
// - An integer N (number of Resource objects to create)
//
// Output Format:
// - Return the count of Resource objects still alive after function execution
//
// Example 1:
// Input: N = 5
// Process: Create 5 Resource objects in function scope
// When function ends, all 5 are destroyed
// Output: 0 (no objects remain alive)
//
// Example 2:
// Input: N = 1
// Process: Create 1 Resource object in function scope
// When function ends, it is destroyed
// Output: 0
//
// Constraints:
// - 1 <= N <= 100
// - Use a static counter in the Resource class
// - Constructor increments, destructor decrements
//
// Note: You need to define the Resource class with proper constructor/destructor

class Resource
{
public:
    static int count;

    Resource()
    {
        count++;
    }

    ~Resource()
    {
        count--;
    }
};

int Resource::count = 0;
void instances_funct()
{
    Resource resource;
}
int problem1Solution(int n)
{
    // TODO: Implement your solution here using Destructors
    // Hint: Create n Resource objects in this function scope
    // When function returns, destructors are called automatically
    // Return Resource::count after objects are destroyed

    for (int i = 0; i < n; i++)
    {
        instances_funct();
    }
    return Resource::count; // Placeholder
}

// ============================================================================
// Problem 2: Easy 2 - Dynamic Array Manager
// ============================================================================
// Description:
// Create a class "ArrayManager" that manages a dynamically allocated integer array.
// The constructor allocates memory, and the destructor must free it to prevent
// memory leaks.
//
// Your task: Implement a function that creates an ArrayManager with size N,
// fills it with values 1 to N, calculates the sum, and returns the sum.
// The destructor should automatically clean up memory when function ends.
//
// Input Format:
// - An integer N (size of array)
//
// Output Format:
// - Return the sum of numbers from 1 to N
//
// Example 1:
// Input: N = 5
// Array: [1, 2, 3, 4, 5]
// Sum: 1 + 2 + 3 + 4 + 5 = 15
// Output: 15
//
// Example 2:
// Input: N = 3
// Array: [1, 2, 3]
// Sum: 1 + 2 + 3 = 6
// Output: 6
//
// Example 3:
// Input: N = 1
// Array: [1]
// Sum: 1
// Output: 1
//
// Constraints:
// - 1 <= N <= 1000
// - Must use dynamic memory allocation (new/delete)
// - Destructor must free the allocated memory

class ArrayManager
{
private:
    int *arr;
    int size;

public:
    ArrayManager(int n) : size(n)
    {
        arr = new int[size];
    }

    ~ArrayManager()
    {
        delete[] arr;
    }

    void fillSequential()
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = i + 1;
        }
    }

    int calculateSum()
    {
        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += arr[i];
        }
        return sum;
    }
};

int problem2Solution(int n)
{
    // TODO: Implement your solution here using Destructors
    // Hint: Create an ArrayManager object, fill it, calculate sum, and return
    // The destructor will automatically clean up when function returns
    ArrayManager arr(n);
    arr.fillSequential();
    return arr.calculateSum(); // Placeholder
}

// ============================================================================
// Problem 3: Medium - String Buffer with Cleanup
// ============================================================================
// Description:
// Create a "StringBuffer" class that manages a dynamically allocated character
// array. It should support appending characters and have a proper destructor.
//
// Your task: Implement a function that creates a StringBuffer, appends N
// characters (starting from 'A'), and returns how many uppercase letters
// were successfully added before the buffer is destroyed.
//
// Input Format:
// - An integer N (number of characters to append, starting from 'A')
//
// Output Format:
// - Return count of uppercase letters added (A-Z are 26 letters, wrap around if N > 26)
//
// Example 1:
// Input: N = 5
// Process: Append 'A', 'B', 'C', 'D', 'E'
// All are uppercase: 5
// Output: 5
//
// Example 2:
// Input: N = 26
// Process: Append 'A' through 'Z'
// All 26 are uppercase
// Output: 26
//
// Example 3:
// Input: N = 28
// Process: Append 'A' through 'Z', then 'A', 'B' (wraps around)
// All 28 are uppercase
// Output: 28
//
// Example 4:
// Input: N = 0
// Process: No characters appended
// Output: 0
//
// Constraints:
// - 0 <= N <= 1000
// - Characters cycle: A, B, C, ..., Z, A, B, C, ...
// - Use dynamic memory allocation
// - Destructor must properly clean up

class StringBuffer
{
private:
    char *buffer;
    int capacity;
    int length;

public:
    StringBuffer(int cap) : capacity(cap), length(0)
    {
        buffer = new char[capacity + 1]; // +1 for null terminator
        buffer[0] = '\0';
    }

    ~StringBuffer()
    {
        delete[] buffer;
    }

    void append(char c)
    {
        if (length < capacity)
        {
            buffer[length] = c;
            length++;
            buffer[length] = '\0';
        }
    }

    int countUppercase()
    {
        int count = 0;
        for (int i = 0; i < length; i++)
        {
            if (buffer[i] >= 'A' && buffer[i] <= 'Z')
            {
                count++;
            }
        }
        return count;
    }
};

int problem3Solution(int n)
{
    // TODO: Implement your solution here using Destructors
    // Hint: Create a StringBuffer with capacity n
    // Append n characters starting from 'A' (use modulo 26 to wrap)
    // Count uppercase letters and return the count
    // Destructor automatically cleans up when function returns

    return 0; // Placeholder
}

// ============================================================================
// Problem 4: Hard - Matrix Memory Manager
// ============================================================================
// Description:
// Create a "Matrix" class that manages a 2D dynamically allocated integer array.
// The class needs a proper destructor to prevent memory leaks.
//
// Your task: Implement a function that creates an M x N matrix, fills it with
// values in row-major order (1, 2, 3, ...), calculates the sum of all elements
// on the main diagonal and anti-diagonal, and returns this sum.
// The destructor must properly deallocate the 2D array.
//
// Input Format:
// - Two integers M and N (rows and columns)
//
// Output Format:
// - Return sum of main diagonal + anti-diagonal
// - Main diagonal: elements where row == col
// - Anti-diagonal: elements where row + col == N - 1
// - If an element is on both diagonals, count it once
//
// Example 1:
// Input: M = 3, N = 3
// Matrix:  1  2  3
//          4  5  6
//          7  8  9
// Main diagonal: 1, 5, 9 (sum = 15)
// Anti-diagonal: 3, 5, 7 (sum = 15)
// Element 5 is on both, so: 1+5+9+3+7 = 25 (or 15+15-5 = 25)
// Output: 25
//
// Example 2:
// Input: M = 2, N = 2
// Matrix:  1  2
//          3  4
// Main diagonal: 1, 4 (sum = 5)
// Anti-diagonal: 2, 3 (sum = 5)
// No overlap, so: 5 + 5 = 10
// Output: 10
//
// Example 3:
// Input: M = 4, N = 4
// Matrix:  1  2  3  4
//          5  6  7  8
//          9 10 11 12
//         13 14 15 16
// Main diagonal: 1, 6, 11, 16 (sum = 34)
// Anti-diagonal: 4, 7, 10, 13 (sum = 34)
// No overlap, so: 34 + 34 = 68
// Output: 68
//
// Example 4:
// Input: M = 1, N = 1
// Matrix: 1
// Main diagonal: 1
// Anti-diagonal: 1
// Same element, so: 1
// Output: 1
//
// Constraints:
// - 1 <= M, N <= 100
// - Must properly allocate/deallocate 2D array
// - Handle both square and non-square matrices

class Matrix
{
private:
    int **data;
    int rows;
    int cols;

public:
    Matrix(int m, int n) : rows(m), cols(n)
    {
        data = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols];
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;
    }

    void fillSequential()
    {
        int value = 1;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = value++;
            }
        }
    }

    int getDiagonalSum()
    {
        int sum = 0;
        bool **counted = new bool *[rows];
        for (int i = 0; i < rows; i++)
        {
            counted[i] = new bool[cols];
            for (int j = 0; j < cols; j++)
            {
                counted[i][j] = false;
            }
        }

        // Main diagonal
        for (int i = 0; i < rows && i < cols; i++)
        {
            sum += data[i][i];
            counted[i][i] = true;
        }

        // Anti-diagonal
        for (int i = 0; i < rows; i++)
        {
            int j = cols - 1 - i;
            if (j >= 0 && j < cols && !counted[i][j])
            {
                sum += data[i][j];
                counted[i][j] = true;
            }
        }

        // Cleanup temporary array
        for (int i = 0; i < rows; i++)
        {
            delete[] counted[i];
        }
        delete[] counted;

        return sum;
    }
};

int problem4Solution(int m, int n)
{
    // TODO: Implement your solution here using Destructors
    // Hint: Create a Matrix object, fill it sequentially
    // Calculate sum of main diagonal + anti-diagonal (avoid double counting)
    // Return the sum
    // Destructor will properly clean up 2D array when function returns

    return 0; // Placeholder
}

// ============================================================================
// TEST FUNCTIONS
// ============================================================================

void testProblem1()
{
    cout << "\n========================================" << endl;
    cout << "Testing Problem 1: Resource Counter" << endl;
    cout << "========================================" << endl;

    // Reset counter before testing
    Resource::count = 0;

    // Test Case 1: Create 5 resources
    // Calculation: Create 5, all destroyed when function returns
    // Expected: 0
    cout << "Test 1 (N=5): " << (problem1Solution(5) == 0 ? "PASS" : "FAIL") << endl;

    // Test Case 2: Create 1 resource
    // Calculation: Create 1, destroyed when function returns
    // Expected: 0
    cout << "Test 2 (N=1): " << (problem1Solution(1) == 0 ? "PASS" : "FAIL") << endl;

    // Test Case 3: Create 10 resources
    // Calculation: Create 10, all destroyed when function returns
    // Expected: 0
    cout << "Test 3 (N=10): " << (problem1Solution(10) == 0 ? "PASS" : "FAIL") << endl;

    // Test Case 4: Create 100 resources
    // Calculation: Create 100, all destroyed when function returns
    // Expected: 0
    cout << "Test 4 (N=100): " << (problem1Solution(100) == 0 ? "PASS" : "FAIL") << endl;

    // Test Case 5: Create 3 resources
    // Calculation: Create 3, all destroyed when function returns
    // Expected: 0
    cout << "Test 5 (N=3): " << (problem1Solution(3) == 0 ? "PASS" : "FAIL") << endl;

    // Test Case 6: Create 50 resources
    // Calculation: Create 50, all destroyed when function returns
    // Expected: 0
    cout << "Test 6 (N=50): " << (problem1Solution(50) == 0 ? "PASS" : "FAIL") << endl;

    // Test Case 7: Create 7 resources
    // Calculation: Create 7, all destroyed when function returns
    // Expected: 0
    cout << "Test 7 (N=7): " << (problem1Solution(7) == 0 ? "PASS" : "FAIL") << endl;

    // Test Case 8: Create 25 resources
    // Calculation: Create 25, all destroyed when function returns
    // Expected: 0
    cout << "Test 8 (N=25): " << (problem1Solution(25) == 0 ? "PASS" : "FAIL") << endl;
}

void testProblem2()
{
    cout << "\n========================================" << endl;
    cout << "Testing Problem 2: Dynamic Array Manager" << endl;
    cout << "========================================" << endl;

    // Test Case 1: N = 5
    // Array: [1, 2, 3, 4, 5]
    // Sum: 1 + 2 + 3 + 4 + 5 = 15
    cout << "Test 1 (N=5): " << (problem2Solution(5) == 15 ? "PASS" : "FAIL") << endl;

    // Test Case 2: N = 3
    // Array: [1, 2, 3]
    // Sum: 1 + 2 + 3 = 6
    cout << "Test 2 (N=3): " << (problem2Solution(3) == 6 ? "PASS" : "FAIL") << endl;

    // Test Case 3: N = 1
    // Array: [1]
    // Sum: 1
    cout << "Test 3 (N=1): " << (problem2Solution(1) == 1 ? "PASS" : "FAIL") << endl;

    // Test Case 4: N = 10
    // Array: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    // Sum: 1+2+3+4+5+6+7+8+9+10 = 55
    cout << "Test 4 (N=10): " << (problem2Solution(10) == 55 ? "PASS" : "FAIL") << endl;

    // Test Case 5: N = 7
    // Array: [1, 2, 3, 4, 5, 6, 7]
    // Sum: 1+2+3+4+5+6+7 = 28
    cout << "Test 5 (N=7): " << (problem2Solution(7) == 28 ? "PASS" : "FAIL") << endl;

    // Test Case 6: N = 100
    // Array: [1, 2, ..., 100]
    // Sum: (100 * 101) / 2 = 5050
    cout << "Test 6 (N=100): " << (problem2Solution(100) == 5050 ? "PASS" : "FAIL") << endl;

    // Test Case 7: N = 20
    // Array: [1, 2, ..., 20]
    // Sum: (20 * 21) / 2 = 210
    cout << "Test 7 (N=20): " << (problem2Solution(20) == 210 ? "PASS" : "FAIL") << endl;

    // Test Case 8: N = 2
    // Array: [1, 2]
    // Sum: 1 + 2 = 3
    cout << "Test 8 (N=2): " << (problem2Solution(2) == 3 ? "PASS" : "FAIL") << endl;
}

void testProblem3()
{
    cout << "\n========================================" << endl;
    cout << "Testing Problem 3: String Buffer with Cleanup" << endl;
    cout << "========================================" << endl;

    // Test Case 1: N = 5
    // Characters: A, B, C, D, E (all uppercase)
    // Count: 5
    cout << "Test 1 (N=5): " << (problem3Solution(5) == 5 ? "PASS" : "FAIL") << endl;

    // Test Case 2: N = 26
    // Characters: A through Z (all 26 uppercase)
    // Count: 26
    cout << "Test 2 (N=26): " << (problem3Solution(26) == 26 ? "PASS" : "FAIL") << endl;

    // Test Case 3: N = 28
    // Characters: A-Z, then A, B (wraps around, all uppercase)
    // Count: 28
    cout << "Test 3 (N=28): " << (problem3Solution(28) == 28 ? "PASS" : "FAIL") << endl;

    // Test Case 4: N = 0
    // Characters: none
    // Count: 0
    cout << "Test 4 (N=0): " << (problem3Solution(0) == 0 ? "PASS" : "FAIL") << endl;

    // Test Case 5: N = 1
    // Characters: A (uppercase)
    // Count: 1
    cout << "Test 5 (N=1): " << (problem3Solution(1) == 1 ? "PASS" : "FAIL") << endl;

    // Test Case 6: N = 52
    // Characters: A-Z twice (all uppercase)
    // Count: 52
    cout << "Test 6 (N=52): " << (problem3Solution(52) == 52 ? "PASS" : "FAIL") << endl;

    // Test Case 7: N = 13
    // Characters: A through M (all uppercase)
    // Count: 13
    cout << "Test 7 (N=13): " << (problem3Solution(13) == 13 ? "PASS" : "FAIL") << endl;

    // Test Case 8: N = 100
    // Characters: A-Z cycles (26*3=78, then 22 more = 100 total, all uppercase)
    // Count: 100
    cout << "Test 8 (N=100): " << (problem3Solution(100) == 100 ? "PASS" : "FAIL") << endl;
}

void testProblem4()
{
    cout << "\n========================================" << endl;
    cout << "Testing Problem 4: Matrix Memory Manager" << endl;
    cout << "========================================" << endl;

    // Test Case 1: 3x3 matrix
    // Matrix: 1  2  3
    //         4  5  6
    //         7  8  9
    // Main diagonal: 1, 5, 9 -> sum = 15
    // Anti-diagonal: 3, 5, 7 -> sum = 15
    // Element at (1,1)=5 is on both diagonals (counted once)
    // Total: 1+5+9+3+7 = 25
    cout << "Test 1 (3x3): " << (problem4Solution(3, 3) == 25 ? "PASS" : "FAIL") << endl;

    // Test Case 2: 2x2 matrix
    // Matrix: 1  2
    //         3  4
    // Main diagonal: 1, 4 -> sum = 5
    // Anti-diagonal: 2, 3 -> sum = 5
    // No overlap: 5 + 5 = 10
    cout << "Test 2 (2x2): " << (problem4Solution(2, 2) == 10 ? "PASS" : "FAIL") << endl;

    // Test Case 3: 4x4 matrix
    // Matrix:  1  2  3  4
    //          5  6  7  8
    //          9 10 11 12
    //         13 14 15 16
    // Main diagonal: 1, 6, 11, 16 -> sum = 34
    // Anti-diagonal: 4, 7, 10, 13 -> sum = 34
    // No overlap: 34 + 34 = 68
    cout << "Test 3 (4x4): " << (problem4Solution(4, 4) == 68 ? "PASS" : "FAIL") << endl;

    // Test Case 4: 1x1 matrix
    // Matrix: 1
    // Main diagonal: 1
    // Anti-diagonal: 1 (same element)
    // Total: 1
    cout << "Test 4 (1x1): " << (problem4Solution(1, 1) == 1 ? "PASS" : "FAIL") << endl;

    // Test Case 5: 5x5 matrix
    // Matrix:  1  2  3  4  5
    //          6  7  8  9 10
    //         11 12 13 14 15
    //         16 17 18 19 20
    //         21 22 23 24 25
    // Main diagonal: 1, 7, 13, 19, 25 -> sum = 65
    // Anti-diagonal: 5, 9, 13, 17, 21 -> sum = 65
    // Element at (2,2)=13 is on both (counted once)
    // Total: 1+7+13+19+25+5+9+17+21 = 117
    cout << "Test 5 (5x5): " << (problem4Solution(5, 5) == 117 ? "PASS" : "FAIL") << endl;

    // Test Case 6: 6x6 matrix
    // Main diagonal: 1, 8, 15, 22, 29, 36 -> sum = 111
    // Anti-diagonal: 6, 11, 16, 21, 26, 31 -> sum = 111
    // No overlap: 111 + 111 = 222
    cout << "Test 6 (6x6): " << (problem4Solution(6, 6) == 222 ? "PASS" : "FAIL") << endl;

    // Test Case 7: 7x7 matrix
    // Main diagonal: 1, 9, 17, 25, 33, 41, 49 -> sum = 175
    // Anti-diagonal: 7, 13, 19, 25, 31, 37, 43 -> sum = 175
    // Element at (3,3)=25 is on both
    // Total: 1+9+17+25+33+41+49+7+13+19+31+37+43 = 325
    cout << "Test 7 (7x7): " << (problem4Solution(7, 7) == 325 ? "PASS" : "FAIL") << endl;

    // Test Case 8: 10x10 matrix
    // Main diagonal: 1, 12, 23, 34, 45, 56, 67, 78, 89, 100 -> sum = 505
    // Anti-diagonal: 10, 19, 28, 37, 46, 55, 64, 73, 82, 91 -> sum = 505
    // No overlap: 505 + 505 = 1010
    cout << "Test 8 (10x10): " << (problem4Solution(10, 10) == 1010 ? "PASS" : "FAIL") << endl;
}

// ============================================================================
// MAIN FUNCTION
// ============================================================================

int main()
{
    int choice;
    cout << "========================================" << endl;
    cout << "C++ Destructors Practice Problems" << endl;
    cout << "========================================" << endl;
    cout << "Choose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy) - Resource Counter" << endl;
    cout << "2. Problem 2 (Easy-Medium) - Dynamic Array Manager" << endl;
    cout << "3. Problem 3 (Medium) - String Buffer with Cleanup" << endl;
    cout << "4. Problem 4 (Hard) - Matrix Memory Manager" << endl;
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