#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

// ============================================================================
// Problem 1: Easy 1 - Type-Specific Printer
// ============================================================================
// Description:
// Create a generic template function 'printValue' that prints any value.
// Then create specialized versions for:
// - int: prints "Integer: <value>"
// - double: prints "Decimal: <value>" with 2 decimal places
// - char: prints "Character: '<value>'"
// - bool: prints "Boolean: true" or "Boolean: false"
//
// Input Format: Various types of values
// Output Format: Type-specific formatted string
//
// Example 1: printValue(42) -> "Integer: 42"
// Example 2: printValue(3.14159) -> "Decimal: 3.14"
// Example 3: printValue('A') -> "Character: 'A'"
// Example 4: printValue(true) -> "Boolean: true"
//
// Constraints: Use template specialization for each type

// Generic template
template<typename T>
T printValue(T value) { 
    // TODO: Implement generic version
    // Hint: This is the fallback for types without specialization
    cout << endl;
    cout << "the value is : " << value << endl;
    return ;
}

// TODO: Create template specialization for int
// Hint: Use template<> syntax
template <>
int printValue<int> (int value) {
     cout << endl;
     cout << "\"Integer: "<< value << "\"" << endl;
     return value;
}

// TODO: Create template specialization for double
// Hint: Use cout << fixed << setprecision(2)
template <>
double printValue<double> (double value) {
     cout << endl;     
     cout << "\"Decimal: "<< fixed << setprecision(2) << value << "\"" << endl;
     return value;
}
// TODO: Create template specialization for char
// Hint: Print with single quotes around the character
template <>
char printValue<char> (char value) {
     cout << endl;
     cout << "\"Character: '"<< value << "' \"" << endl;
     return value;
}
// TODO: Create template specialization for bool
// Hint: Use conditional to print "true" or "false" as text
template <>
bool printValue<bool> (bool value) {
     cout << endl;
     if (value )
     {
          cout << "\"Boolean: true \"" << endl;
     }
     else
     {
          cout << "\"Boolean: false \"" << endl;
     }
     
     return value;
}
// ============================================================================
// Problem 2: Easy 2 - Array Size Calculator
// ============================================================================
// Description:
// Create a template function 'getSize' that returns the number of elements.
// - Generic version: returns 1 (for single values)
// - Specialization for arrays: returns actual array length
// - Specialization for C-strings (char*): returns string length (not counting null)
//
// Input Format: Various types - single values, arrays, C-strings
// Output Format: Integer representing size/count
//
// Example 1: int x = 5; getSize(x) -> 1
// Example 2: int arr[] = {1,2,3,4,5}; getSize(arr) -> 5
// Example 3: char* str = "Hello"; getSize(str) -> 5
//
// Constraints: 
// - Use template specialization
// - For C-strings, don't count the null terminator

// Generic template
template<typename T>
T getSize(T value) {
    // TODO: Implement generic version - return 1 for single values
    // Hint: Single values have size 1
    return 1;
}


// TODO: Create specialization for C-style arrays
// Hint: Use template<typename T, int N> for arrays, return N
 template<typename T, int N> 
 int getSize(T (&value)[N]) {

     return size(value);
}
// TODO: Create specialization for char* (C-strings)
// Hint: Loop through until '\0' and count characters
template<int N> 
int getSize(char (&value)[N]) {
     int sizes = size(value) - 1;
     return sizes;
 }
// ============================================================================
// Problem 3: Medium - Smart Comparator
// ============================================================================
// Description:
// Create a template function 'isEqual' that compares two values.
// - Generic version: uses == operator
// - Specialization for double: considers two doubles equal if difference < 0.0001
// - Specialization for C-strings (char*): compares string content, not pointers
// - Specialization for arrays: compares element by element
//
// Input Format: Two values of the same type
// Output Format: Boolean (true if equal, false otherwise)
//
// Example 1: isEqual(5, 5) -> true
// Example 2: isEqual(3.14159, 3.14160) -> true (within tolerance)
// Example 3: isEqual("hello", "hello") -> true (content match)
// Example 4: isEqual(3.1, 3.2) -> false
//
// Constraints:
// - Use template specialization for each type
// - For doubles, use tolerance of 0.0001
// - For C-strings, compare content not pointer addresses

// Generic template
template<typename T>
bool isEqual(T a, T b) {
    // TODO: Implement generic version using == operator
    // Hint: Simple equality check
    if (a != b) return false;
    return true;
}

// TODO: Create specialization for double
// Hint: Use abs(a - b) < 0.0001 for floating point comparison
template<>
bool isEqual<double> (double a , double b) {
     if (abs(a - b ) < 0.0001) return true;
     return false;
}

// TODO: Create specialization for char* (C-strings)
// Hint: Compare character by character, check lengths match
template<size_t N>
bool isEqual(char (&a)[N] , char (&b)[N]) {
     if (size(a) != size(b)) return false;
     for (size_t i = 0; i < size(a); i++)
     {
          if (a[i] != b[i]) return false ;
     }
     
     return true ;
}
// TODO: Create specialization for arrays (bonus)
// Hint: template<typename T, int N>, compare each element
template<typename T , size_t N>
bool isEqual(T (&a)[N] , T (&b)[N]) {
     if (size(a) != size(b)) return false;
     for (size_t i = 0; i < size(a); i++)
     {
          if (a[i] != b[i]) return false ;
     }
     
     return true ;
}
// ============================================================================
// Problem 4: Hard - Type Converter with Validation
// ============================================================================
// Description:
// Create a template function 'convert' that converts between types safely.
// - Generic version: static_cast
// - int to char specialization: checks if value is in valid ASCII range (0-127)
//   Returns '\0' if invalid
// - double to int specialization: rounds to nearest integer
// - char to int specialization: returns ASCII value
// - bool to string specialization: returns "true" or "false"
//
// Input Format: Value of source type
// Output Format: Converted value of target type
//
// Example 1: convert<int, char>(65) -> 'A'
// Example 2: convert<int, char>(200) -> '\0' (out of range)
// Example 3: convert<double, int>(3.7) -> 4 (rounded)
// Example 4: convert<double, int>(3.2) -> 3 (rounded)
// Example 5: convert<char, int>('Z') -> 90
//
// Constraints:
// - Use template specialization for special conversions
// - Validate ranges where applicable
// - Handle edge cases properly

// Generic template with two type parameters
template<typename From, typename To>
To convert(From value) {
    // TODO: Implement generic version using static_cast
    // Hint: return static_cast<To>(value);
    return static_cast<To>(0);
}

// TODO: Create specialization for int to char
// Hint: Check if value >= 0 && value <= 127, return '\0' if invalid

// TODO: Create specialization for double to int
// Hint: Use round() function from <cmath> or add 0.5 and cast

// TODO: Create specialization for char to int
// Hint: Simply cast char to int to get ASCII value

// TODO: Create specialization for bool to string (if return type is string)
// Hint: Return value ? "true" : "false"

// ============================================================================
// TEST FUNCTIONS WITH MANUALLY VERIFIED TEST CASES
// ============================================================================

void testProblem1() {
    cout << "\n===== Testing Problem 1: Type-Specific Printer =====" << endl;
    
    // Test Case 1: Integer value
    // Input: 42
    // Expected output: "Integer: 42"
    cout << "Test 1 (int 42): ";
    printValue(42);
    cout << " -> Expected: Integer: 42" << endl;
    
    // Test Case 2: Negative integer
    // Input: -15
    // Expected output: "Integer: -15"
    cout << "Test 2 (int -15): ";
    printValue(-15);
    cout << " -> Expected: Integer: -15" << endl;
    
    // Test Case 3: Double value
    // Input: 3.14159
    // Expected output: "Decimal: 3.14" (rounded to 2 decimal places)
    cout << "Test 3 (double 3.14159): ";
    printValue(3.14159);
    cout << " -> Expected: Decimal: 3.14" << endl;
    
    // Test Case 4: Double value with rounding up
    // Input: 2.999
    // Expected output: "Decimal: 3.00"
    cout << "Test 4 (double 2.999): ";
    printValue(2.999);
    cout << " -> Expected: Decimal: 3.00" << endl;
    
    // Test Case 5: Character uppercase
    // Input: 'A'
    // Expected output: "Character: 'A'"
    cout << "Test 5 (char 'A'): ";
    printValue('A');
    cout << " -> Expected: Character: 'A'" << endl;
    
    // Test Case 6: Character lowercase
    // Input: 'z'
    // Expected output: "Character: 'z'"
    cout << "Test 6 (char 'z'): ";
    printValue('z');
    cout << " -> Expected: Character: 'z'" << endl;
    
    // Test Case 7: Boolean true
    // Input: true
    // Expected output: "Boolean: true"
    cout << "Test 7 (bool true): ";
    printValue(true);
    cout << " -> Expected: Boolean: true" << endl;
    
    // Test Case 8: Boolean false
    // Input: false
    // Expected output: "Boolean: false"
    cout << "Test 8 (bool false): ";
    printValue(false);
    cout << " -> Expected: Boolean: false" << endl;
}

void testProblem2() {
    cout << "\n===== Testing Problem 2: Array Size Calculator =====" << endl;
    
    // Test Case 1: Single integer
    // Input: int x = 42
    // Calculation: Single value -> size = 1
    // Expected: 1
    int x = 42;
    cout << "Test 1 (single int): " << getSize(x) << " -> Expected: 1" << endl;
    
    // Test Case 2: Single double
    // Input: double d = 3.14
    // Calculation: Single value -> size = 1
    // Expected: 1
    double d = 3.14;
    cout << "Test 2 (single double): " << getSize(d) << " -> Expected: 1" << endl;
    
    // Test Case 3: Array of 5 integers
    // Input: int arr1[] = {1, 2, 3, 4, 5}
    // Calculation: Array has 5 elements
    // Expected: 5
    int arr1[] = {1, 2, 3, 4, 5};
    cout << "Test 3 (int array[5]): " << getSize(arr1) << " -> Expected: 5" << endl;
    
    // Test Case 4: Array of 3 doubles
    // Input: double arr2[] = {1.1, 2.2, 3.3}
    // Calculation: Array has 3 elements
    // Expected: 3
    double arr2[] = {1.1, 2.2, 3.3};
    cout << "Test 4 (double array[3]): " << getSize(arr2) << " -> Expected: 3" << endl;
    
    // Test Case 5: C-string "Hello"
    // Input: char* str1 = "Hello"
    // Calculation: H-e-l-l-o = 5 characters (not counting \0)
    // Expected: 5
    char str1[] = "Hello";
    cout << "Test 5 (C-string \"Hello\"): " << getSize(str1) << " -> Expected: 5" << endl;
    
    // Test Case 6: C-string "C++"
    // Input: char* str2 = "C++"
    // Calculation: C-+-+ = 3 characters
    // Expected: 3
    char str2[] = "C++";
    cout << "Test 6 (C-string \"C++\"): " << getSize(str2) << " -> Expected: 3" << endl;
    
    // Test Case 7: Empty C-string
    // Input: char* str3 = ""
    // Calculation: 0 characters
    // Expected: 0
    char str3[] = "";
    cout << "Test 7 (empty C-string): " << getSize(str3) << " -> Expected: 0" << endl;
    
    // Test Case 8: Array of 1 element
    // Input: int arr3[] = {99}
    // Calculation: Array has 1 element
    // Expected: 1
    int arr3[] = {99};
    cout << "Test 8 (int array[1]): " << getSize(arr3) << " -> Expected: 1" << endl;
}

void testProblem3() {
    cout << "\n===== Testing Problem 3: Smart Comparator =====" << endl;
    
    // Test Case 1: Equal integers
    // Input: 5, 5
    // Calculation: 5 == 5 -> true
    // Expected: true
    cout << "Test 1 (5 == 5): " << (isEqual(5, 5) ? "true" : "false") 
         << " -> Expected: true" << endl;
    
    // Test Case 2: Different integers
    // Input: 10, 15
    // Calculation: 10 == 15 -> false
    // Expected: false
    cout << "Test 2 (10 == 15): " << (isEqual(10, 15) ? "true" : "false") 
         << " -> Expected: false" << endl;
    
    // Test Case 3: Doubles within tolerance
    // Input: 3.14159, 3.14160
    // Calculation: |3.14159 - 3.14160| = 0.00001 < 0.0001 -> true
    // Expected: true
    cout << "Test 3 (3.14159 == 3.14160): " << (isEqual(3.14159, 3.14160) ? "true" : "false") 
         << " -> Expected: true" << endl;
    
    // Test Case 4: Doubles outside tolerance
    // Input: 3.1, 3.2
    // Calculation: |3.1 - 3.2| = 0.1 > 0.0001 -> false
    // Expected: false
    cout << "Test 4 (3.1 == 3.2): " << (isEqual(3.1, 3.2) ? "true" : "false") 
         << " -> Expected: false" << endl;
    
    // Test Case 5: Doubles exactly at tolerance boundary
    // Input: 5.0, 5.00009
    // Calculation: |5.0 - 5.00009| = 0.00009 < 0.0001 -> true
    // Expected: true
    cout << "Test 5 (5.0 == 5.00009): " << (isEqual(5.0, 5.00009) ? "true" : "false") 
         << " -> Expected: true" << endl;
    
    // Test Case 6: C-strings equal content
    // Input: "hello", "hello"
    // Calculation: Character by character comparison -> true
    // Expected: true
    char str1[] = "hello";
    char str2[] = "hello";
    cout << "Test 6 (\"hello\" == \"hello\"): " << (isEqual(str1, str2) ? "true" : "false") 
         << " -> Expected: true" << endl;
    
    // Test Case 7: C-strings different content
    // Input: "hello", "world"
    // Calculation: Character comparison fails -> false
    // Expected: false
    char str3[] = "hello";
    char str4[] = "world";
    cout << "Test 7 (\"hello\" == \"world\"): " << (isEqual(str3, str4) ? "true" : "false") 
         << " -> Expected: false" << endl;
    
    // Test Case 8: C-strings different lengths
    // Input: "hi", "hello"
    // Calculation: Different lengths -> false
    // Expected: false
    char str5[] = "hi";
    char str6[] = "hello";
    cout << "Test 8 (\"hi\" == \"hello\"): " << (isEqual(str5, str6) ? "true" : "false") 
         << " -> Expected: false" << endl;
}

void testProblem4() {
    cout << "\n===== Testing Problem 4: Type Converter with Validation =====" << endl;
    
    // Test Case 1: int to char - valid ASCII
    // Input: 65
    // Calculation: 65 is ASCII for 'A', in range [0,127]
    // Expected: 'A'
    cout << "Test 1 (int 65 to char): '" << convert<int, char>(65) 
         << "' -> Expected: 'A'" << endl;
    
    // Test Case 2: int to char - invalid (too large)
    // Input: 200
    // Calculation: 200 > 127, out of valid ASCII range
    // Expected: '\0' (displayed as empty/null)
    char result2 = convert<int, char>(200);
    cout << "Test 2 (int 200 to char): " << (int)result2 
         << " -> Expected: 0 (null char)" << endl;
    
    // Test Case 3: int to char - boundary valid
    // Input: 127
    // Calculation: 127 is at boundary, still valid
    // Expected: ASCII character 127 (DEL)
    cout << "Test 3 (int 127 to char): " << (int)convert<int, char>(127) 
         << " -> Expected: 127" << endl;
    
    // Test Case 4: int to char - invalid (negative)
    // Input: -5
    // Calculation: -5 < 0, out of valid range
    // Expected: '\0'
    char result4 = convert<int, char>(-5);
    cout << "Test 4 (int -5 to char): " << (int)result4 
         << " -> Expected: 0 (null char)" << endl;
    
    // Test Case 5: double to int - round down
    // Input: 3.2
    // Calculation: 3.2 rounds to 3
    // Expected: 3
    cout << "Test 5 (double 3.2 to int): " << convert<double, int>(3.2) 
         << " -> Expected: 3" << endl;
    
    // Test Case 6: double to int - round up
    // Input: 3.7
    // Calculation: 3.7 rounds to 4
    // Expected: 4
    cout << "Test 6 (double 3.7 to int): " << convert<double, int>(3.7) 
         << " -> Expected: 4" << endl;
    
    // Test Case 7: double to int - exactly 0.5
    // Input: 2.5
    // Calculation: 2.5 rounds to 3 (round half up) OR 2 (round half to even)
    // Note: round() typically rounds half away from zero, so 2.5 -> 3
    // Expected: 3 (if using round()) or 2 (if using truncate + 0.5)
    cout << "Test 7 (double 2.5 to int): " << convert<double, int>(2.5) 
         << " -> Expected: 3 (if using round) or 2 (depends on rounding)" << endl;
    
    // Test Case 8: char to int - get ASCII value
    // Input: 'Z'
    // Calculation: ASCII value of 'Z' is 90
    // Expected: 90
    cout << "Test 8 (char 'Z' to int): " << convert<char, int>('Z') 
         << " -> Expected: 90" << endl;
    
    // Test Case 9: char to int - lowercase
    // Input: 'a'
    // Calculation: ASCII value of 'a' is 97
    // Expected: 97
    cout << "Test 9 (char 'a' to int): " << convert<char, int>('a') 
         << " -> Expected: 97" << endl;
}

int main() {
    int choice;
    cout << "==================================================" << endl;
    cout << "    Template Specialization Practice Problems    " << endl;
    cout << "==================================================" << endl;
    cout << "\nChoose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 - Type-Specific Printer (Easy)" << endl;
    cout << "2. Problem 2 - Array Size Calculator (Easy-Medium)" << endl;
    cout << "3. Problem 3 - Smart Comparator (Medium)" << endl;
    cout << "4. Problem 4 - Type Converter with Validation (Hard)" << endl;
    cout << "5. Test All Problems" << endl;
    cout << "\nEnter your choice: ";
    cin >> choice;

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
            cout << "Invalid choice! Please run again and choose 1-5." << endl;
    }

    return 0;
}