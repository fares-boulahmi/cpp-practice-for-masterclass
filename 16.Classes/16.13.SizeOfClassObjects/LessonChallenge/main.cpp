#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

// Problem 1: Easy 1 - Basic Class Size Calculator
//
// Description:
// Create a function that calculates and returns the size of a simple class object.
// You are given a class definition with different data members. Calculate the total
// size of the object in bytes.
//
// Input Format:
// No input needed - the class is already defined in the test cases
//
// Output Format:
// Return the size of the object in bytes as size_t
//
// Example 1:
// class SimpleClass {
//     int a;
//     double b;
// };
// Expected Output: Size depends on system (typically 16 bytes due to padding)
//
// Example 2:
// class TinyClass {
//     char c;
// };
// Expected Output: 1 byte
//
// Constraints:
// - Use sizeof() operator
// - Consider that sizeof returns size_t type
//
// Hint: Use the sizeof operator on the class type itself, not on individual members

template <typename T>
size_t problem1Solution(T obj)
{
    // TODO: Implement your solution here using sizeof operator
    // Hint: The sizeof operator can be applied to types and objects
    size_t i = sizeof(obj);
    return i;
}

// Problem 2: Easy 2 - Array vs Single Object Size
//
// Description:
// Given an array of objects, calculate how many objects fit in the array.
// You need to return the number of elements by dividing the total array size
// by the size of a single element.
//
// Input Format:
// An array (passed as reference) and you need to calculate its element count
//
// Output Format:
// Return the number of elements in the array as size_t
//
// Example 1:
// int arr[5] = {1, 2, 3, 4, 5};
// Total array size: 5 * 4 = 20 bytes (assuming int is 4 bytes)
// Single element size: 4 bytes
// Expected Output: 20 / 4 = 5 elements
//
// Example 2:
// double arr[3] = {1.1, 2.2, 3.3};
// Total array size: 3 * 8 = 24 bytes (assuming double is 8 bytes)
// Single element size: 8 bytes
// Expected Output: 24 / 8 = 3 elements
//
// Constraints:
// - Array size is at least 1
// - Use sizeof on array and element type
//
// Hint: sizeof(array) gives total bytes, sizeof(array[0]) gives one element's bytes

template <typename T, size_t N>
size_t problem2Solution(T (&arr)[N])
{
    // TODO: Implement your solution here
    // Hint: Divide the total array size by the size of one element

    return sizeof(arr) / sizeof(arr[0]);
}

// Problem 3: Medium - Struct Padding Calculator
//
// Description:
// Calculate the total size of a struct and identify how much padding is added.
// Return the difference between the actual struct size and the sum of its members.
//
// The function receives a struct type and should return the padding bytes.
// Padding bytes = sizeof(struct) - sum of sizeof(all members)
//
// Input Format:
// Template parameter with struct type
//
// Output Format:
// Return the number of padding bytes as size_t
//
// Example 1:
// struct PaddedStruct {
//     char a;    // 1 byte
//     int b;     // 4 bytes
//     char c;    // 1 byte
// };
// Sum of members: 1 + 4 + 1 = 6 bytes
// Actual size (with padding): typically 12 bytes
// Expected Output: 12 - 6 = 6 padding bytes
//
// Example 2:
// struct NoPadding {
//     int a;     // 4 bytes
//     int b;     // 4 bytes
// };
// Sum of members: 4 + 4 = 8 bytes
// Actual size: 8 bytes
// Expected Output: 8 - 8 = 0 padding bytes
//
// Constraints:
// - Struct has at least one member
// - Consider structure alignment rules
//
// Hint: You'll need to manually sum the sizes of individual members and subtract from total

struct TestStruct1
{
    char a;
    int b;
    char c;
};

struct TestStruct2
{
    int a;
    int b;
};

struct TestStruct3
{
    char a;
    double b;
    char c;
};

size_t problem3Solution(size_t structSize, size_t memberSum)
{
    // TODO: Implement your solution here
    // Hint: Padding = total struct size - sum of individual member sizes
    return structSize - memberSum;
}

// Problem 4: Hard - Memory Layout Analyzer
//
// Description:
// Given a class with various data members, analyze the memory layout and return
// a string describing which members would be stored together without padding between them.
//
// You need to identify consecutive members that have no padding between them.
// Return the count of "padding-free segments" in the class layout.
//
// A padding-free segment is a sequence of members where no padding exists between them.
//
// Input Format:
// Information about member types and their order
//
// Output Format:
// Return the number of padding-free segments as int
//
// Example 1:
// class LayoutClass {
//     int a;      // Segment 1 starts
//     int b;      // Continues segment 1 (no padding)
//     char c;     // Ends segment 1
//     // [padding]
//     double d;   // Segment 2 (new segment after padding)
// };
// Expected Output: 2 segments
//
// Example 2:
// class SequentialClass {
//     char a;
//     char b;
//     char c;
//     char d;
// };
// All members are consecutive with no padding
// Expected Output: 1 segment
//
// Constraints:
// - Class has at least 2 members
// - Consider alignment requirements of different types
//
// Hint: Check if current member's size would cause the next member to need alignment padding

int problem4Solution(vector<size_t> memberSizes, vector<size_t> memberAlignments)
{
    // TODO: Implement your solution here
    // Hint: Track when padding would be inserted between members based on alignment rules
    // A new segment starts when padding is needed before a member
    return 0;
}

void testProblem1()
{
    cout << "\n=== Testing Problem 1: Basic Class Size Calculator ===" << endl;

    // Test Case 1: Simple int class
    // Class with single int member
    // Calculation: sizeof(int) = 4 bytes (typical)
    // Expected: 4 bytes
    class Test1
    {
        int a;
    };
    Test1 t1;
    cout << "Test 1 - Single int: " << (problem1Solution(t1) == sizeof(Test1) ? "PASS" : "FAIL") << endl;
    cout << "  Expected: " << sizeof(Test1) << ", Got: " << problem1Solution(t1) << endl;

    // Test Case 2: Single char class
    // Calculation: sizeof(char) = 1 byte
    // Expected: 1 byte
    class Test2
    {
        char c;
    };
    Test2 t2;
    cout << "Test 2 - Single char: " << (problem1Solution(t2) == sizeof(Test2) ? "PASS" : "FAIL") << endl;
    cout << "  Expected: " << sizeof(Test2) << ", Got: " << problem1Solution(t2) << endl;

    // Test Case 3: Single double class
    // Calculation: sizeof(double) = 8 bytes (typical)
    // Expected: 8 bytes
    class Test3
    {
        double d;
    };
    Test3 t3;
    cout << "Test 3 - Single double: " << (problem1Solution(t3) == sizeof(Test3) ? "PASS" : "FAIL") << endl;
    cout << "  Expected: " << sizeof(Test3) << ", Got: " << problem1Solution(t3) << endl;

    // Test Case 4: Two ints class
    // Calculation: 2 * sizeof(int) = 2 * 4 = 8 bytes
    // Expected: 8 bytes
    class Test4
    {
        int a;
        int b;
    };
    Test4 t4;
    cout << "Test 4 - Two ints: " << (problem1Solution(t4) == sizeof(Test4) ? "PASS" : "FAIL") << endl;
    cout << "  Expected: " << sizeof(Test4) << ", Got: " << problem1Solution(t4) << endl;

    // Test Case 5: Int and double (with potential padding)
    // Calculation: int(4) + padding(4) + double(8) = 16 bytes (typical alignment)
    // Expected: 16 bytes
    class Test5
    {
        int a;
        double d;
    };
    Test5 t5;
    cout << "Test 5 - Int and double: " << (problem1Solution(t5) == sizeof(Test5) ? "PASS" : "FAIL") << endl;
    cout << "  Expected: " << sizeof(Test5) << ", Got: " << problem1Solution(t5) << endl;

    // Test Case 6: Four chars
    // Calculation: 4 * sizeof(char) = 4 * 1 = 4 bytes
    // Expected: 4 bytes
    class Test6
    {
        char a;
        char b;
        char c;
        char d;
    };
    Test6 t6;
    cout << "Test 6 - Four chars: " << (problem1Solution(t6) == sizeof(Test6) ? "PASS" : "FAIL") << endl;
    cout << "  Expected: " << sizeof(Test6) << ", Got: " << problem1Solution(t6) << endl;

    // Test Case 7: Empty class
    // Calculation: Empty class has size 1 (C++ standard)
    // Expected: 1 byte
    class Test7
    {
    };
    Test7 t7;
    cout << "Test 7 - Empty class: " << (problem1Solution(t7) == sizeof(Test7) ? "PASS" : "FAIL") << endl;
    cout << "  Expected: " << sizeof(Test7) << ", Got: " << problem1Solution(t7) << endl;

    // Test Case 8: Class with bool
    // Calculation: sizeof(bool) = 1 byte
    // Expected: 1 byte
    class Test8
    {
        bool b;
    };
    Test8 t8;
    cout << "Test 8 - Single bool: " << (problem1Solution(t8) == sizeof(Test8) ? "PASS" : "FAIL") << endl;
    cout << "  Expected: " << sizeof(Test8) << ", Got: " << problem1Solution(t8) << endl;
}

void testProblem2()
{
    cout << "\n=== Testing Problem 2: Array vs Single Object Size ===" << endl;

    // Test Case 1: Integer array of 5 elements
    // Calculation: 5 elements
    // Expected: 5
    int arr1[5] = {1, 2, 3, 4, 5};
    cout << "Test 1 - Int array[5]: " << (problem2Solution(arr1) == 5 ? "PASS" : "FAIL") << endl;
    cout << "  Expected: 5, Got: " << problem2Solution(arr1) << endl;

    // Test Case 2: Double array of 3 elements
    // Calculation: 3 elements
    // Expected: 3
    double arr2[3] = {1.1, 2.2, 3.3};
    cout << "Test 2 - Double array[3]: " << (problem2Solution(arr2) == 3 ? "PASS" : "FAIL") << endl;
    cout << "  Expected: 3, Got: " << problem2Solution(arr2) << endl;

    // Test Case 3: Char array of 10 elements
    // Calculation: 10 elements
    // Expected: 10
    char arr3[10] = "Hello";
    cout << "Test 3 - Char array[10]: " << (problem2Solution(arr3) == 10 ? "PASS" : "FAIL") << endl;
    cout << "  Expected: 10, Got: " << problem2Solution(arr3) << endl;

    // Test Case 4: Single element array
    // Calculation: 1 element
    // Expected: 1
    int arr4[1] = {42};
    cout << "Test 4 - Single element: " << (problem2Solution(arr4) == 1 ? "PASS" : "FAIL") << endl;
    cout << "  Expected: 1, Got: " << problem2Solution(arr4) << endl;

    // Test Case 5: Large int array
    // Calculation: 100 elements
    // Expected: 100
    int arr5[100] = {};
    cout << "Test 5 - Large array[100]: " << (problem2Solution(arr5) == 100 ? "PASS" : "FAIL") << endl;
    cout << "  Expected: 100, Got: " << problem2Solution(arr5) << endl;

    // Test Case 6: Bool array
    // Calculation: 8 elements
    // Expected: 8
    bool arr6[8] = {true, false, true, false, true, false, true, false};
    cout << "Test 6 - Bool array[8]: " << (problem2Solution(arr6) == 8 ? "PASS" : "FAIL") << endl;
    cout << "  Expected: 8, Got: " << problem2Solution(arr6) << endl;

    // Test Case 7: Float array
    // Calculation: 7 elements
    // Expected: 7
    float arr7[7] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f};
    cout << "Test 7 - Float array[7]: " << (problem2Solution(arr7) == 7 ? "PASS" : "FAIL") << endl;
    cout << "  Expected: 7, Got: " << problem2Solution(arr7) << endl;

    // Test Case 8: Long array
    // Calculation: 4 elements
    // Expected: 4
    long arr8[4] = {1000L, 2000L, 3000L, 4000L};
    cout << "Test 8 - Long array[4]: " << (problem2Solution(arr8) == 4 ? "PASS" : "FAIL") << endl;
    cout << "  Expected: 4, Got: " << problem2Solution(arr8) << endl;
}

void testProblem3()
{
    cout << "\n=== Testing Problem 3: Struct Padding Calculator ===" << endl;

    // Test Case 1: char, int, char structure
    // Members: char(1) + int(4) + char(1) = 6 bytes
    // Actual size with padding: char(1) + padding(3) + int(4) + char(1) + padding(3) = 12 bytes
    // Padding: 12 - 6 = 6 bytes
    struct T1
    {
        char a;
        int b;
        char c;
    };
    size_t padding1 = problem3Solution(sizeof(T1), sizeof(char) + sizeof(int) + sizeof(char));
    cout << "Test 1 - char,int,char: " << (padding1 == (sizeof(T1) - 6) ? "PASS" : "FAIL") << endl;
    cout << "  Expected: " << (sizeof(T1) - 6) << ", Got: " << padding1 << endl;

    // Test Case 2: Two ints (no padding expected)
    // Members: int(4) + int(4) = 8 bytes
    // Actual size: 8 bytes
    // Padding: 8 - 8 = 0 bytes
    struct T2
    {
        int a;
        int b;
    };
    size_t padding2 = problem3Solution(sizeof(T2), sizeof(int) + sizeof(int));
    cout << "Test 2 - int,int: " << (padding2 == 0 ? "PASS" : "FAIL") << endl;
    cout << "  Expected: 0, Got: " << padding2 << endl;

    // Test Case 3: char and double
    // Members: char(1) + double(8) = 9 bytes
    // Actual size: char(1) + padding(7) + double(8) = 16 bytes
    // Padding: 16 - 9 = 7 bytes
    struct T3
    {
        char a;
        double b;
    };
    size_t padding3 = problem3Solution(sizeof(T3), sizeof(char) + sizeof(double));
    cout << "Test 3 - char,double: " << (padding3 == (sizeof(T3) - 9) ? "PASS" : "FAIL") << endl;
    cout << "  Expected: " << (sizeof(T3) - 9) << ", Got: " << padding3 << endl;

    // Test Case 4: Four chars (minimal padding)
    // Members: char(1) + char(1) + char(1) + char(1) = 4 bytes
    // Actual size: 4 bytes
    // Padding: 4 - 4 = 0 bytes
    struct T4
    {
        char a;
        char b;
        char c;
        char d;
    };
    size_t padding4 = problem3Solution(sizeof(T4), 4 * sizeof(char));
    cout << "Test 4 - four chars: " << (padding4 == 0 ? "PASS" : "FAIL") << endl;
    cout << "  Expected: 0, Got: " << padding4 << endl;

    // Test Case 5: double and int
    // Members: double(8) + int(4) = 12 bytes
    // Actual size: double(8) + int(4) + padding(4) = 16 bytes
    // Padding: 16 - 12 = 4 bytes
    struct T5
    {
        double a;
        int b;
    };
    size_t padding5 = problem3Solution(sizeof(T5), sizeof(double) + sizeof(int));
    cout << "Test 5 - double,int: " << (padding5 == (sizeof(T5) - 12) ? "PASS" : "FAIL") << endl;
    cout << "  Expected: " << (sizeof(T5) - 12) << ", Got: " << padding5 << endl;

    // Test Case 6: char, char, int
    // Members: char(1) + char(1) + int(4) = 6 bytes
    // Actual size: char(1) + char(1) + padding(2) + int(4) = 8 bytes
    // Padding: 8 - 6 = 2 bytes
    struct T6
    {
        char a;
        char b;
        int c;
    };
    size_t padding6 = problem3Solution(sizeof(T6), 2 * sizeof(char) + sizeof(int));
    cout << "Test 6 - char,char,int: " << (padding6 == (sizeof(T6) - 6) ? "PASS" : "FAIL") << endl;
    cout << "  Expected: " << (sizeof(T6) - 6) << ", Got: " << padding6 << endl;

    // Test Case 7: int, char, int
    // Members: int(4) + char(1) + int(4) = 9 bytes
    // Actual size: int(4) + char(1) + padding(3) + int(4) = 12 bytes
    // Padding: 12 - 9 = 3 bytes
    struct T7
    {
        int a;
        char b;
        int c;
    };
    size_t padding7 = problem3Solution(sizeof(T7), 2 * sizeof(int) + sizeof(char));
    cout << "Test 7 - int,char,int: " << (padding7 == (sizeof(T7) - 9) ? "PASS" : "FAIL") << endl;
    cout << "  Expected: " << (sizeof(T7) - 9) << ", Got: " << padding7 << endl;

    // Test Case 8: Single int (no padding)
    // Members: int(4) = 4 bytes
    // Actual size: 4 bytes
    // Padding: 4 - 4 = 0 bytes
    struct T8
    {
        int a;
    };
    size_t padding8 = problem3Solution(sizeof(T8), sizeof(int));
    cout << "Test 8 - single int: " << (padding8 == 0 ? "PASS" : "FAIL") << endl;
    cout << "  Expected: 0, Got: " << padding8 << endl;
}

void testProblem4()
{
    cout << "\n=== Testing Problem 4: Memory Layout Analyzer ===" << endl;

    // Test Case 1: int, int, char, double
    // Layout: int(4) int(4) char(1) [pad 7] double(8)
    // Segment 1: int,int,char (no padding between these)
    // Segment 2: double (padding before this, new segment)
    // Expected: 2 segments
    vector<size_t> sizes1 = {4, 4, 1, 8}; // int, int, char, double
    vector<size_t> aligns1 = {4, 4, 1, 8};
    cout << "Test 1 - int,int,char,double: " << (problem4Solution(sizes1, aligns1) == 2 ? "PASS" : "FAIL") << endl;
    cout << "  Expected: 2 segments" << endl;

    // Test Case 2: char, char, char, char (all consecutive)
    // Layout: char(1) char(1) char(1) char(1)
    // All members fit without padding
    // Expected: 1 segment
    vector<size_t> sizes2 = {1, 1, 1, 1};
    vector<size_t> aligns2 = {1, 1, 1, 1};
    cout << "Test 2 - four chars: " << (problem4Solution(sizes2, aligns2) == 1 ? "PASS" : "FAIL") << endl;
    cout << "  Expected: 1 segment" << endl;

    // Test Case 3: char, int, char, int
    // Layout: char(1) [pad 3] int(4) char(1) [pad 3] int(4)
    // Segment 1: char
    // Segment 2: int,char (padding before int starts new segment)
    // Segment 3: int (padding before this int starts new segment)
    // Expected: 3 segments
    vector<size_t> sizes3 = {1, 4, 1, 4};
    vector<size_t> aligns3 = {1, 4, 1, 4};
    cout << "Test 3 - char,int,char,int: " << (problem4Solution(sizes3, aligns3) == 3 ? "PASS" : "FAIL") << endl;
    cout << "  Expected: 3 segments" << endl;

    // Test Case 4: int, int, int (all aligned)
    // Layout: int(4) int(4) int(4)
    // No padding needed
    // Expected: 1 segment
    vector<size_t> sizes4 = {4, 4, 4};
    vector<size_t> aligns4 = {4, 4, 4};
    cout << "Test 4 - three ints: " << (problem4Solution(sizes4, aligns4) == 1 ? "PASS" : "FAIL") << endl;
    cout << "  Expected: 1 segment" << endl;

    // Test Case 5: double, char, double
    // Layout: double(8) char(1) [pad 7] double(8)
    // Segment 1: double,char
    // Segment 2: double (padding before this)
    // Expected: 2 segments
    vector<size_t> sizes5 = {8, 1, 8};
    vector<size_t> aligns5 = {8, 1, 8};
    cout << "Test 5 - double,char,double: " << (problem4Solution(sizes5, aligns5) == 2 ? "PASS" : "FAIL") << endl;
    cout << "  Expected: 2 segments" << endl;

    // Test Case 6: char, char, int, int
    // Layout: char(1) char(1) [pad 2] int(4) int(4)
    // Segment 1: char,char
    // Segment 2: int,int (padding before first int)
    // Expected: 2 segments
    vector<size_t> sizes6 = {1, 1, 4, 4};
    vector<size_t> aligns6 = {1, 1, 4, 4};
    cout << "Test 6 - char,char,int,int: " << (problem4Solution(sizes6, aligns6) == 2 ? "PASS" : "FAIL") << endl;
    cout << "  Expected: 2 segments" << endl;

    // Test Case 7: int, double, int
    // Layout: int(4) [pad 4] double(8) int(4)
    // Segment 1: int
    // Segment 2: double,int (padding before double)
    // Expected: 2 segments
    vector<size_t> sizes7 = {4, 8, 4};
    vector<size_t> aligns7 = {4, 8, 4};
    cout << "Test 7 - int,double,int: " << (problem4Solution(sizes7, aligns7) == 2 ? "PASS" : "FAIL") << endl;
    cout << "  Expected: 2 segments" << endl;

    // Test Case 8: char, double
    // Layout: char(1) [pad 7] double(8)
    // Segment 1: char
    // Segment 2: double (padding before double)
    // Expected: 2 segments
    vector<size_t> sizes8 = {1, 8};
    vector<size_t> aligns8 = {1, 8};
    cout << "Test 8 - char,double: " << (problem4Solution(sizes8, aligns8) == 2 ? "PASS" : "FAIL") << endl;
    cout << "  Expected: 2 segments" << endl;
}

int main()
{
    int choice;
    cout << "=== C++ Size of Objects - Practice Problems ===" << endl;
    cout << "Choose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy) - Basic Class Size Calculator" << endl;
    cout << "2. Problem 2 (Easy) - Array vs Single Object Size" << endl;
    cout << "3. Problem 3 (Medium) - Struct Padding Calculator" << endl;
    cout << "4. Problem 4 (Hard) - Memory Layout Analyzer" << endl;
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