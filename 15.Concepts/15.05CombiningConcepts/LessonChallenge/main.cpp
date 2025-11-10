#include <iostream>
#include <vector>
#include <string>
#include <concepts>
#include <type_traits>
#include <cmath>

using namespace std;

// ==================== CUSTOM CONCEPTS ====================
// These concepts will be used in the problems below

// Concept: Type must be numeric (integral or floating point)
template <typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

// Concept: Type must be signed
template <typename T>
concept Signed = std::signed_integral<T> || std::floating_point<T>;

// Concept: Type must be unsigned integral
template <typename T>
concept Unsigned = std::unsigned_integral<T>;

// Concept: Type must be an integral type
template <typename T>
concept IntegralType = std::integral<T>;

// Concept: Type must be a floating point type
template <typename T>
concept FloatingType = std::floating_point<T>;

// Combined Concept: Signed Numeric (signed integers or floating point)
template <typename T>
concept SignedNumeric = Numeric<T> && Signed<T>;

// Combined Concept: Unsigned Integral only
template <typename T>
concept UnsignedIntegral = Numeric<T> && Unsigned<T>;

// Combined Concept: Arithmetic (excludes bool from integral types)
template <typename T>
concept Arithmetic = (std::integral<T> && !std::same_as<T, bool>) || std::floating_point<T>;

// ==================== PROBLEM 1: EASY ====================
// Problem 1: Absolute Value Calculator
//
// Create a template function that calculates the absolute value of a number.
// The function should only accept SIGNED numeric types (signed integers or floating point).
//
// INPUT FORMAT: A single signed numeric value
// OUTPUT FORMAT: The absolute value of the input
//
// EXAMPLES:
// Input: -5      Output: 5
// Input: -3.14   Output: 3.14
// Input: 7       Output: 7
// Input: 0       Output: 0
//
// CONSTRAINTS:
// - Must use a combined concept (SignedNumeric)
// - Should work with int, long, float, double
// - Should NOT compile with unsigned types
//
// HINT: Use conditional logic to handle negative values
template <SignedNumeric T>
    requires Numeric<T>
T absoluteValue(T value)
{
    // TODO: Implement your solution here
    // Hint: Check if the value is negative and return the appropriate result
    if (value < 0)
        return -value;
    return value;
}

// ==================== PROBLEM 2: EASY-MEDIUM ====================
// Problem 2: Safe Division Calculator
//
// Create a template function that performs division and returns a floating-point result.
// The function should accept any two NUMERIC types (integral or floating point).
// The function should return 0.0 if the divisor is zero (safe division).
//
// INPUT FORMAT: Two numeric values (dividend and divisor)
// OUTPUT FORMAT: A double representing the result of division, or 0.0 if divisor is zero
//
// EXAMPLES:
// Input: 10, 2        Output: 5.0
// Input: 7, 2         Output: 3.5
// Input: 5, 0         Output: 0.0 (safe division)
// Input: 9.6, 3.2     Output: 3.0
//
// CONSTRAINTS:
// - Must use combined concept (Numeric for both parameters)
// - Must handle division by zero safely
// - Return type must be double
//
// HINT: Check if divisor is zero before dividing, use static_cast for type conversion
template <Numeric T1, Numeric T2>
    requires Numeric<T1> && Numeric<T2>
double safeDivide(T1 dividend, T2 divisor)
{
    // TODO: Implement your solution here
    // Hint: First check if divisor is zero, then perform the division with proper casting
    if (divisor == 0)
        return 0.0;

    return static_cast<double>(dividend) / static_cast<double>(divisor);
}

// ==================== PROBLEM 3: MEDIUM ====================
// Problem 3: Array Statistics Calculator
//
// Create a template function that calculates statistics (sum and average) for an array.
// The function should only accept ARITHMETIC types (integers except bool, or floating point).
// The function should return the sum as the same type, and average as double.
//
// INPUT FORMAT: A vector of arithmetic values
// OUTPUT FORMAT: Print the sum and average
//
// EXAMPLES:
// Input: {1, 2, 3, 4, 5}           Sum: 15, Average: 3.0
// Input: {10, 20, 30}              Sum: 60, Average: 20.0
// Input: {-5, -10, 15}             Sum: 0, Average: 0.0
// Input: {2.5, 3.5, 4.0}           Sum: 10.0, Average: 3.333...
//
// CONSTRAINTS:
// - Must use Arithmetic concept
// - Must handle empty arrays (return sum=0, average=0.0)
// - Average should be calculated as double
//
// HINT: Iterate through the vector to calculate sum, then divide by size for average
template <Arithmetic T>
void calculateStats(const vector<T> &numbers)
{
    // TODO: Implement your solution here
    // Hint: Check if vector is empty first, then sum all elements and calculate average
    // Output format: cout << "Sum: " << sum << ", Average: " << average << endl;
}

// ==================== PROBLEM 4: HARD ====================
// Problem 4: Power Calculator with Type Constraints
//
// Create a template function that calculates base^exponent with specific type constraints:
// - Base must be a SIGNED NUMERIC type (signed integers or floating point)
// - Exponent must be an UNSIGNED INTEGRAL type
// - Return type should be double for precision
//
// The function should handle negative bases correctly with even/odd exponents.
//
// INPUT FORMAT: A signed numeric base and an unsigned integral exponent
// OUTPUT FORMAT: A double representing base raised to the power of exponent
//
// EXAMPLES:
// Input: base=2, exp=3        Output: 8.0    (2^3 = 8)
// Input: base=-2, exp=3       Output: -8.0   ((-2)^3 = -8)
// Input: base=-2, exp=2       Output: 4.0    ((-2)^2 = 4)
// Input: base=5, exp=0        Output: 1.0    (5^0 = 1)
// Input: base=3.0, exp=2      Output: 9.0    (3.0^2 = 9)
//
// CONSTRAINTS:
// - Base: Must use SignedNumeric concept
// - Exponent: Must use UnsignedIntegral concept
// - Must handle exponent = 0 (any number^0 = 1)
// - Must handle negative bases correctly
//
// HINT: Use a loop to multiply base by itself exponent times, handle exp=0 case first
template <SignedNumeric Base, UnsignedIntegral Exp>
double power(Base base, Exp exponent)
{
    // TODO: Implement your solution here
    // Hint: Handle exponent=0 first (return 1.0), then use a loop to multiply
    return 0;
}

// ==================== TEST FUNCTIONS ====================

void testProblem1()
{
    cout << "\n=== Testing Problem 1: Absolute Value Calculator ===" << endl;

    // Test Case 1: Negative integer
    // Input: -5
    // Expected: 5 (absolute value of -5)
    cout << "Test 1: " << (absoluteValue(-5) == 5 ? "PASS" : "FAIL") << " (Expected: 5)" << endl;

    // Test Case 2: Positive integer
    // Input: 7
    // Expected: 7 (already positive)
    cout << "Test 2: " << (absoluteValue(7) == 7 ? "PASS" : "FAIL") << " (Expected: 7)" << endl;

    // Test Case 3: Zero
    // Input: 0
    // Expected: 0 (absolute value of 0 is 0)
    cout << "Test 3: " << (absoluteValue(0) == 0 ? "PASS" : "FAIL") << " (Expected: 0)" << endl;

    // Test Case 4: Negative floating point
    // Input: -3.14
    // Expected: 3.14
    cout << "Test 4: " << (abs(absoluteValue(-3.14) - 3.14) < 0.001 ? "PASS" : "FAIL") << " (Expected: 3.14)" << endl;

    // Test Case 5: Positive floating point
    // Input: 2.718
    // Expected: 2.718
    cout << "Test 5: " << (abs(absoluteValue(2.718) - 2.718) < 0.001 ? "PASS" : "FAIL") << " (Expected: 2.718)" << endl;

    // Test Case 6: Large negative integer
    // Input: -1000
    // Expected: 1000
    cout << "Test 6: " << (absoluteValue(-1000) == 1000 ? "PASS" : "FAIL") << " (Expected: 1000)" << endl;

    // Test Case 7: Negative long
    // Input: -999999L
    // Expected: 999999
    cout << "Test 7: " << (absoluteValue(-999999L) == 999999L ? "PASS" : "FAIL") << " (Expected: 999999)" << endl;

    // Test Case 8: Small negative double
    // Input: -0.001
    // Expected: 0.001
    cout << "Test 8: " << (abs(absoluteValue(-0.001) - 0.001) < 0.0001 ? "PASS" : "FAIL") << " (Expected: 0.001)" << endl;
}

void testProblem2()
{
    cout << "\n=== Testing Problem 2: Safe Division Calculator ===" << endl;

    // Test Case 1: Simple integer division
    // Input: 10 / 2
    // Calculation: 10.0 / 2.0 = 5.0
    cout << "Test 1: " << (abs(safeDivide(10, 2) - 5.0) < 0.001 ? "PASS" : "FAIL") << " (Expected: 5.0)" << endl;

    // Test Case 2: Integer division with remainder
    // Input: 7 / 2
    // Calculation: 7.0 / 2.0 = 3.5
    cout << "Test 2: " << (abs(safeDivide(7, 2) - 3.5) < 0.001 ? "PASS" : "FAIL") << " (Expected: 3.5)" << endl;

    // Test Case 3: Division by zero (edge case)
    // Input: 5 / 0
    // Expected: 0.0 (safe division)
    cout << "Test 3: " << (abs(safeDivide(5, 0) - 0.0) < 0.001 ? "PASS" : "FAIL") << " (Expected: 0.0)" << endl;

    // Test Case 4: Floating point division
    // Input: 9.6 / 3.2
    // Calculation: 9.6 / 3.2 = 3.0
    cout << "Test 4: " << (abs(safeDivide(9.6, 3.2) - 3.0) < 0.001 ? "PASS" : "FAIL") << " (Expected: 3.0)" << endl;

    // Test Case 5: Negative dividend
    // Input: -10 / 2
    // Calculation: -10.0 / 2.0 = -5.0
    cout << "Test 5: " << (abs(safeDivide(-10, 2) - (-5.0)) < 0.001 ? "PASS" : "FAIL") << " (Expected: -5.0)" << endl;

    // Test Case 6: Both negative
    // Input: -15 / -3
    // Calculation: -15.0 / -3.0 = 5.0
    cout << "Test 6: " << (abs(safeDivide(-15, -3) - 5.0) < 0.001 ? "PASS" : "FAIL") << " (Expected: 5.0)" << endl;

    // Test Case 7: Division resulting in decimal
    // Input: 1 / 3
    // Calculation: 1.0 / 3.0 = 0.333...
    cout << "Test 7: " << (abs(safeDivide(1, 3) - 0.333333) < 0.001 ? "PASS" : "FAIL") << " (Expected: 0.333...)" << endl;

    // Test Case 8: Zero dividend
    // Input: 0 / 5
    // Calculation: 0.0 / 5.0 = 0.0
    cout << "Test 8: " << (abs(safeDivide(0, 5) - 0.0) < 0.001 ? "PASS" : "FAIL") << " (Expected: 0.0)" << endl;
}

void testProblem3()
{
    cout << "\n=== Testing Problem 3: Array Statistics Calculator ===" << endl;

    cout << "Test 1: {1, 2, 3, 4, 5}" << endl;
    // Sum: 1+2+3+4+5 = 15
    // Average: 15/5 = 3.0
    cout << "Expected - Sum: 15, Average: 3" << endl;
    calculateStats(vector<int>{1, 2, 3, 4, 5});

    cout << "\nTest 2: {10, 20, 30}" << endl;
    // Sum: 10+20+30 = 60
    // Average: 60/3 = 20.0
    cout << "Expected - Sum: 60, Average: 20" << endl;
    calculateStats(vector<int>{10, 20, 30});

    cout << "\nTest 3: {-5, -10, 15}" << endl;
    // Sum: -5+(-10)+15 = 0
    // Average: 0/3 = 0.0
    cout << "Expected - Sum: 0, Average: 0" << endl;
    calculateStats(vector<int>{-5, -10, 15});

    cout << "\nTest 4: {2.5, 3.5, 4.0}" << endl;
    // Sum: 2.5+3.5+4.0 = 10.0
    // Average: 10.0/3 = 3.333...
    cout << "Expected - Sum: 10, Average: 3.33333" << endl;
    calculateStats(vector<double>{2.5, 3.5, 4.0});

    cout << "\nTest 5: {100}" << endl;
    // Sum: 100
    // Average: 100/1 = 100.0
    cout << "Expected - Sum: 100, Average: 100" << endl;
    calculateStats(vector<int>{100});

    cout << "\nTest 6: {-7, 14}" << endl;
    // Sum: -7+14 = 7
    // Average: 7/2 = 3.5
    cout << "Expected - Sum: 7, Average: 3.5" << endl;
    calculateStats(vector<int>{-7, 14});

    cout << "\nTest 7: {0, 0, 0, 0}" << endl;
    // Sum: 0+0+0+0 = 0
    // Average: 0/4 = 0.0
    cout << "Expected - Sum: 0, Average: 0" << endl;
    calculateStats(vector<int>{0, 0, 0, 0});

    cout << "\nTest 8: Empty array {}" << endl;
    // Sum: 0 (empty)
    // Average: 0.0 (empty)
    cout << "Expected - Sum: 0, Average: 0" << endl;
    calculateStats(vector<int>{});
}

void testProblem4()
{
    cout << "\n=== Testing Problem 4: Power Calculator ===" << endl;

    // Test Case 1: Positive base, small exponent
    // Input: 2^3
    // Calculation: 2 * 2 * 2 = 8.0
    cout << "Test 1: " << (abs(power(2, 3u) - 8.0) < 0.001 ? "PASS" : "FAIL") << " (Expected: 8.0)" << endl;

    // Test Case 2: Negative base, odd exponent
    // Input: (-2)^3
    // Calculation: (-2) * (-2) * (-2) = -8.0
    cout << "Test 2: " << (abs(power(-2, 3u) - (-8.0)) < 0.001 ? "PASS" : "FAIL") << " (Expected: -8.0)" << endl;

    // Test Case 3: Negative base, even exponent
    // Input: (-2)^2
    // Calculation: (-2) * (-2) = 4.0
    cout << "Test 3: " << (abs(power(-2, 2u) - 4.0) < 0.001 ? "PASS" : "FAIL") << " (Expected: 4.0)" << endl;

    // Test Case 4: Any base to power 0
    // Input: 5^0
    // Calculation: Any number^0 = 1.0
    cout << "Test 4: " << (abs(power(5, 0u) - 1.0) < 0.001 ? "PASS" : "FAIL") << " (Expected: 1.0)" << endl;

    // Test Case 5: Floating point base
    // Input: 3.0^2
    // Calculation: 3.0 * 3.0 = 9.0
    cout << "Test 5: " << (abs(power(3.0, 2u) - 9.0) < 0.001 ? "PASS" : "FAIL") << " (Expected: 9.0)" << endl;

    // Test Case 6: Base of 1
    // Input: 1^10
    // Calculation: 1 * 1 * ... (10 times) = 1.0
    cout << "Test 6: " << (abs(power(1, 10u) - 1.0) < 0.001 ? "PASS" : "FAIL") << " (Expected: 1.0)" << endl;

    // Test Case 7: Large exponent
    // Input: 2^5
    // Calculation: 2 * 2 * 2 * 2 * 2 = 32.0
    cout << "Test 7: " << (abs(power(2, 5u) - 32.0) < 0.001 ? "PASS" : "FAIL") << " (Expected: 32.0)" << endl;

    // Test Case 8: Negative floating point base, even exponent
    // Input: (-1.5)^2
    // Calculation: (-1.5) * (-1.5) = 2.25
    cout << "Test 8: " << (abs(power(-1.5, 2u) - 2.25) < 0.001 ? "PASS" : "FAIL") << " (Expected: 2.25)" << endl;
}

int main()
{
    int choice;
    cout << "=====================================" << endl;
    cout << "  C++20 Concepts Practice Problems" << endl;
    cout << "  Topic: Combining Concepts" << endl;
    cout << "=====================================" << endl;
    cout << "\nChoose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy) - Absolute Value Calculator" << endl;
    cout << "2. Problem 2 (Easy-Medium) - Safe Division Calculator" << endl;
    cout << "3. Problem 3 (Medium) - Array Statistics Calculator" << endl;
    cout << "4. Problem 4 (Hard) - Power Calculator with Type Constraints" << endl;
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

    return 0;
}