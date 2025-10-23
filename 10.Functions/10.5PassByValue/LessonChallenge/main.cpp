#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// ============================================================================
// Problem 1: Easy 1 - Triple Number Calculator
// ============================================================================
// Description:
// Write a function that takes an integer by value and returns its triple (multiplied by 3).
// This demonstrates basic pass by value where the original variable remains unchanged.
//
// Input Format: Single integer n
// Output Format: Integer (n * 3)
//
// Example 1:
//   Input: 5
//   Output: 15
//   Explanation: 5 * 3 = 15
//
// Example 2:
//   Input: -4
//   Output: -12
//   Explanation: -4 * 3 = -12
//
// Constraints:
//   -1000 <= n <= 1000
//
int tripleNumber(int n) {
    // TODO: Implement your solution here using Pass by value
    // Hint: Simply multiply the parameter by 3 and return the result
    // Note: The original variable passed to this function won't be modified
}

// ============================================================================
// Problem 2: Easy 2 - Character Grade Converter
// ============================================================================
// Description:
// Write a function that takes a character grade (A, B, C, D, F) by value
// and returns the corresponding grade point (A=4, B=3, C=2, D=1, F=0).
// Handle both uppercase and lowercase letters.
//
// Input Format: Single character representing a grade
// Output Format: Integer grade point
//
// Example 1:
//   Input: 'A'
//   Output: 4
//
// Example 2:
//   Input: 'b'
//   Output: 3
//
// Example 3:
//   Input: 'F'
//   Output: 0
//
// Constraints:
//   Valid grades: A, B, C, D, F (case insensitive)
//   Return -1 for invalid input
//
int gradeToPoint(char grade) {
    // TODO: Implement your solution here using Pass by value
    // Hint: Use if-else or switch statement to match the grade character
    // Remember to handle both uppercase and lowercase using logical operators
}

// ============================================================================
// Problem 3: Medium - Sum of Digits Calculator
// ============================================================================
// Description:
// Write a function that takes a positive integer by value and returns
// the sum of all its digits. For example, 1234 -> 1+2+3+4 = 10
//
// Input Format: Positive integer n
// Output Format: Integer (sum of digits)
//
// Example 1:
//   Input: 1234
//   Output: 10
//   Explanation: 1 + 2 + 3 + 4 = 10
//
// Example 2:
//   Input: 999
//   Output: 27
//   Explanation: 9 + 9 + 9 = 27
//
// Example 3:
//   Input: 5
//   Output: 5
//   Explanation: Single digit returns itself
//
// Constraints:
//   0 <= n <= 1000000
//
int sumOfDigits(int n) {
    // TODO: Implement your solution here using Pass by value
    // Hint: Use a while loop with modulo (%) to extract each digit
    // Use integer division (/) to remove the last digit in each iteration
}

// ============================================================================
// Problem 4: Hard - Prime Factor Count
// ============================================================================
// Description:
// Write a function that takes a positive integer by value and returns
// the count of its distinct prime factors. For example:
// 12 = 2 × 2 × 3, so it has 2 distinct prime factors (2 and 3)
// 30 = 2 × 3 × 5, so it has 3 distinct prime factors (2, 3, and 5)
//
// Input Format: Positive integer n (n >= 2)
// Output Format: Integer (count of distinct prime factors)
//
// Example 1:
//   Input: 12
//   Output: 2
//   Explanation: 12 = 2² × 3, distinct primes: {2, 3}
//
// Example 2:
//   Input: 30
//   Output: 3
//   Explanation: 30 = 2 × 3 × 5, distinct primes: {2, 3, 5}
//
// Example 3:
//   Input: 17
//   Output: 1
//   Explanation: 17 is prime itself
//
// Constraints:
//   2 <= n <= 10000
//
int countPrimeFactors(int n) {
    // TODO: Implement your solution here using Pass by value
    // Hint: Divide n by each potential factor starting from 2
    // When a factor divides evenly, keep dividing by it until it doesn't
    // Count each unique factor only once
    // Optimize by only checking up to sqrt(n)
}

// ============================================================================
// TEST FUNCTIONS WITH MANUALLY VERIFIED TEST CASES
// ============================================================================

void testProblem1() {
    cout << "\n========================================" << endl;
    cout << "Testing Problem 1: Triple Number Calculator" << endl;
    cout << "========================================" << endl;

    // Test Case 1: Positive number
    // Calculation: 5 * 3 = 15
    cout << "Test 1 (n=5): " << (tripleNumber(5) == 15 ? "PASS" : "FAIL") << " (Expected: 15)" << endl;

    // Test Case 2: Negative number
    // Calculation: -4 * 3 = -12
    cout << "Test 2 (n=-4): " << (tripleNumber(-4) == -12 ? "PASS" : "FAIL") << " (Expected: -12)" << endl;

    // Test Case 3: Zero
    // Calculation: 0 * 3 = 0
    cout << "Test 3 (n=0): " << (tripleNumber(0) == 0 ? "PASS" : "FAIL") << " (Expected: 0)" << endl;

    // Test Case 4: Large positive number
    // Calculation: 333 * 3 = 999
    cout << "Test 4 (n=333): " << (tripleNumber(333) == 999 ? "PASS" : "FAIL") << " (Expected: 999)" << endl;

    // Test Case 5: Large negative number
    // Calculation: -100 * 3 = -300
    cout << "Test 5 (n=-100): " << (tripleNumber(-100) == -300 ? "PASS" : "FAIL") << " (Expected: -300)" << endl;

    // Test Case 6: One
    // Calculation: 1 * 3 = 3
    cout << "Test 6 (n=1): " << (tripleNumber(1) == 3 ? "PASS" : "FAIL") << " (Expected: 3)" << endl;

    // Test Case 7: Negative one
    // Calculation: -1 * 3 = -3
    cout << "Test 7 (n=-1): " << (tripleNumber(-1) == -3 ? "PASS" : "FAIL") << " (Expected: -3)" << endl;

    // Test Case 8: Larger number
    // Calculation: 250 * 3 = 750
    cout << "Test 8 (n=250): " << (tripleNumber(250) == 750 ? "PASS" : "FAIL") << " (Expected: 750)" << endl;
}

void testProblem2() {
    cout << "\n========================================" << endl;
    cout << "Testing Problem 2: Character Grade Converter" << endl;
    cout << "========================================" << endl;

    // Test Case 1: Uppercase A
    // A = 4 points
    cout << "Test 1 (grade='A'): " << (gradeToPoint('A') == 4 ? "PASS" : "FAIL") << " (Expected: 4)" << endl;

    // Test Case 2: Lowercase b
    // b = B = 3 points
    cout << "Test 2 (grade='b'): " << (gradeToPoint('b') == 3 ? "PASS" : "FAIL") << " (Expected: 3)" << endl;

    // Test Case 3: Uppercase C
    // C = 2 points
    cout << "Test 3 (grade='C'): " << (gradeToPoint('C') == 2 ? "PASS" : "FAIL") << " (Expected: 2)" << endl;

    // Test Case 4: Lowercase d
    // d = D = 1 point
    cout << "Test 4 (grade='d'): " << (gradeToPoint('d') == 1 ? "PASS" : "FAIL") << " (Expected: 1)" << endl;

    // Test Case 5: Uppercase F
    // F = 0 points
    cout << "Test 5 (grade='F'): " << (gradeToPoint('F') == 0 ? "PASS" : "FAIL") << " (Expected: 0)" << endl;

    // Test Case 6: Lowercase f
    // f = F = 0 points
    cout << "Test 6 (grade='f'): " << (gradeToPoint('f') == 0 ? "PASS" : "FAIL") << " (Expected: 0)" << endl;

    // Test Case 7: Invalid character (number)
    // '5' is not a valid grade = -1
    cout << "Test 7 (grade='5'): " << (gradeToPoint('5') == -1 ? "PASS" : "FAIL") << " (Expected: -1)" << endl;

    // Test Case 8: Invalid character (letter)
    // 'X' is not a valid grade = -1
    cout << "Test 8 (grade='X'): " << (gradeToPoint('X') == -1 ? "PASS" : "FAIL") << " (Expected: -1)" << endl;

    // Test Case 9: Lowercase a
    // a = A = 4 points
    cout << "Test 9 (grade='a'): " << (gradeToPoint('a') == 4 ? "PASS" : "FAIL") << " (Expected: 4)" << endl;
}

void testProblem3() {
    cout << "\n========================================" << endl;
    cout << "Testing Problem 3: Sum of Digits Calculator" << endl;
    cout << "========================================" << endl;

    // Test Case 1: Multiple digits
    // Calculation: 1234 -> 1 + 2 + 3 + 4 = 10
    cout << "Test 1 (n=1234): " << (sumOfDigits(1234) == 10 ? "PASS" : "FAIL") << " (Expected: 10)" << endl;

    // Test Case 2: All same digits
    // Calculation: 999 -> 9 + 9 + 9 = 27
    cout << "Test 2 (n=999): " << (sumOfDigits(999) == 27 ? "PASS" : "FAIL") << " (Expected: 27)" << endl;

    // Test Case 3: Single digit
    // Calculation: 5 -> 5 = 5
    cout << "Test 3 (n=5): " << (sumOfDigits(5) == 5 ? "PASS" : "FAIL") << " (Expected: 5)" << endl;

    // Test Case 4: Zero
    // Calculation: 0 -> 0 = 0
    cout << "Test 4 (n=0): " << (sumOfDigits(0) == 0 ? "PASS" : "FAIL") << " (Expected: 0)" << endl;

    // Test Case 5: Two digits
    // Calculation: 45 -> 4 + 5 = 9
    cout << "Test 5 (n=45): " << (sumOfDigits(45) == 9 ? "PASS" : "FAIL") << " (Expected: 9)" << endl;

    // Test Case 6: Large number
    // Calculation: 123456 -> 1 + 2 + 3 + 4 + 5 + 6 = 21
    cout << "Test 6 (n=123456): " << (sumOfDigits(123456) == 21 ? "PASS" : "FAIL") << " (Expected: 21)" << endl;

    // Test Case 7: Number with zeros
    // Calculation: 1001 -> 1 + 0 + 0 + 1 = 2
    cout << "Test 7 (n=1001): " << (sumOfDigits(1001) == 2 ? "PASS" : "FAIL") << " (Expected: 2)" << endl;

    // Test Case 8: All zeros except last
    // Calculation: 1000 -> 1 + 0 + 0 + 0 = 1
    cout << "Test 8 (n=1000): " << (sumOfDigits(1000) == 1 ? "PASS" : "FAIL") << " (Expected: 1)" << endl;

    // Test Case 9: Another multi-digit
    // Calculation: 8765 -> 8 + 7 + 6 + 5 = 26
    cout << "Test 9 (n=8765): " << (sumOfDigits(8765) == 26 ? "PASS" : "FAIL") << " (Expected: 26)" << endl;
}

void testProblem4() {
    cout << "\n========================================" << endl;
    cout << "Testing Problem 4: Prime Factor Count" << endl;
    cout << "========================================" << endl;

    // Test Case 1: Number with two distinct prime factors
    // Calculation: 12 = 2 × 2 × 3 = 2² × 3
    // Distinct prime factors: 2, 3 -> Count = 2
    cout << "Test 1 (n=12): " << (countPrimeFactors(12) == 2 ? "PASS" : "FAIL") << " (Expected: 2)" << endl;

    // Test Case 2: Number with three distinct prime factors
    // Calculation: 30 = 2 × 3 × 5
    // Distinct prime factors: 2, 3, 5 -> Count = 3
    cout << "Test 2 (n=30): " << (countPrimeFactors(30) == 3 ? "PASS" : "FAIL") << " (Expected: 3)" << endl;

    // Test Case 3: Prime number
    // Calculation: 17 is prime
    // Distinct prime factors: 17 -> Count = 1
    cout << "Test 3 (n=17): " << (countPrimeFactors(17) == 1 ? "PASS" : "FAIL") << " (Expected: 1)" << endl;

    // Test Case 4: Power of a prime
    // Calculation: 16 = 2 × 2 × 2 × 2 = 2⁴
    // Distinct prime factors: 2 -> Count = 1
    cout << "Test 4 (n=16): " << (countPrimeFactors(16) == 1 ? "PASS" : "FAIL") << " (Expected: 1)" << endl;

    // Test Case 5: Small composite number
    // Calculation: 6 = 2 × 3
    // Distinct prime factors: 2, 3 -> Count = 2
    cout << "Test 5 (n=6): " << (countPrimeFactors(6) == 2 ? "PASS" : "FAIL") << " (Expected: 2)" << endl;

    // Test Case 6: Smallest prime
    // Calculation: 2 is prime
    // Distinct prime factors: 2 -> Count = 1
    cout << "Test 6 (n=2): " << (countPrimeFactors(2) == 1 ? "PASS" : "FAIL") << " (Expected: 1)" << endl;

    // Test Case 7: Another composite
    // Calculation: 100 = 2 × 2 × 5 × 5 = 2² × 5²
    // Distinct prime factors: 2, 5 -> Count = 2
    cout << "Test 7 (n=100): " << (countPrimeFactors(100) == 2 ? "PASS" : "FAIL") << " (Expected: 2)" << endl;

    // Test Case 8: Four distinct prime factors
    // Calculation: 210 = 2 × 3 × 5 × 7
    // Distinct prime factors: 2, 3, 5, 7 -> Count = 4
    cout << "Test 8 (n=210): " << (countPrimeFactors(210) == 4 ? "PASS" : "FAIL") << " (Expected: 4)" << endl;

    // Test Case 9: Large prime
    // Calculation: 97 is prime
    // Distinct prime factors: 97 -> Count = 1
    cout << "Test 9 (n=97): " << (countPrimeFactors(97) == 1 ? "PASS" : "FAIL") << " (Expected: 1)" << endl;
}

// ============================================================================
// MAIN FUNCTION WITH INTERACTIVE MENU
// ============================================================================

int main() {
    int choice;
    
    cout << "===========================================" << endl;
    cout << "  C++ Pass by Value Practice Problems" << endl;
    cout << "===========================================" << endl;
    cout << "Choose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy) - Triple Number Calculator" << endl;
    cout << "2. Problem 2 (Easy) - Character Grade Converter" << endl;
    cout << "3. Problem 3 (Medium) - Sum of Digits Calculator" << endl;
    cout << "4. Problem 4 (Hard) - Prime Factor Count" << endl;
    cout << "5. Test All Problems" << endl;
    cout << "Enter your choice: ";
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
            cout << "\n===========================================" << endl;
            cout << "  All Tests Completed!" << endl;
            cout << "===========================================" << endl;
            break;
        default: 
            cout << "Invalid choice! Please enter 1-5." << endl;
    }

    return 0;
}