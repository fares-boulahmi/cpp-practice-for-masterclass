#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

//=== SECTION A: INTEGRATION PROBLEMS ===

// Problem A1: Foundation Integration - Number Pattern Generator
// Create a function that generates and prints number patterns using nested loops.
// The function should take a pattern type (1-4) and size parameter.
// Pattern 1: Right triangle of numbers (1, 12, 123, etc.)
// Pattern 2: Reverse right triangle starting from size down to 1
// Pattern 3: Diamond pattern with numbers
// Pattern 4: Hollow square with border numbers and spaces inside
// 
// Examples:
// generatePattern(1, 4) should print:
// 1
// 12
// 123
// 1234
//
// generatePattern(2, 3) should print:
// 321
// 32
// 3
//
// Input: pattern type (1-4), size (1-10)
// Output: Print the pattern to console
// Constraints: Handle invalid inputs gracefully, use appropriate loop types
void generatePattern(int patternType, int size) {
    // TODO: Solve using nested for loops, conditional statements, and output formatting
    // Hint: Consider which loop type is most appropriate for each pattern
    switch (patternType)
    {
    case 1:
        for (int i{1} ; i <= size ; i++  ) {
            string number {};
            for (int j{1} ; j <= i ; j++) {
                number = number + to_string(j);
            } 
            cout << number  << endl;
        }
        break;
    case 2:
        for (int i{size} ; i > 0 ; i--  ) {
            string number {};
            for (int j{i} ; j > 0 ; j--) {
                number = number + to_string(j);
            } 
            cout << number  << endl;
        }
        break;
    // TODO : complete the diamond case and hollow square case i stoped cause very hungry 
    // case 3:
    //     for (int i{1} ; i <= size ; i++  ) {
    //         string number {};
    //         for (int j{1} ; j <= i ; j++) {
    //             number = number + to_string(j);
    //         } 
    //         cout << number << endl;
    //     }
    //     break;
    // case 4:
    //     for (int i{1} ; i <= size ; i++  ) {
    //         string number {};
    //         for (int j{1} ; j <= i ; j++) {
    //             number = number + to_string(j);
    //         } 
    //         cout << number << endl;
    //     }
    //     break;    
    default:
    cout << "Invalid pattern"  << endl;
        break;
    }
}

// Problem A2: Intermediate Synthesis - Interactive Number Analyzer
// Create a program that continuously reads integers from user until they enter 0.
// For each session, calculate and return a struct/multiple values containing:
// - Sum of all positive numbers
// - Count of negative numbers  
// - Average of all numbers (excluding 0)
// - Largest and smallest numbers entered
// - Count of even and odd numbers
//
// Example session: Input: 5, -3, 8, -1, 2, 0
// Output: Sum positives: 15, Negatives count: 2, Average: 2.2, 
//         Max: 8, Min: -3, Evens: 2, Odds: 3
//
// Input: Sequence of integers ending with 0
// Output: Statistical analysis of the numbers
// Constraints: Handle empty input (only 0), division by zero for average
struct NumberStats {
    int sumPositive;
    int countNegative;
    double average;
    int maxNum;
    int minNum;
    int countEven;
    int countOdd;
};

NumberStats analyzeNumbers() {
    // TODO: Solve using while loop, conditional statements, arithmetic operations, and input validation
    // Hint: Initialize min/max carefully and handle the first number specially
    NumberStats numberStats;
    return numberStats;
}

// Problem A3: Advanced Integration - Matrix Spiral Traversal
// Given an n x n matrix filled with numbers 1 to n², traverse and return the elements
// in spiral order (clockwise from outside to inside).
// Create the matrix first, then traverse it in spiral pattern.
//
// Example: For n=3, matrix:
// 1 2 3
// 4 5 6  
// 7 8 9
// Spiral order: 1, 2, 3, 6, 9, 8, 7, 4, 5
//
// Example: For n=4, matrix:
// 1  2  3  4
// 5  6  7  8
// 9  10 11 12
// 13 14 15 16
// Spiral order: 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10
//
// Input: Integer n (size of matrix, 1 ≤ n ≤ 10)
// Output: Vector containing elements in spiral order
// Constraints: Handle edge cases (n=1), use efficient boundary tracking
vector<int> spiralTraversal(int n) {
    // TODO: Solve using nested for loops, 2D array/vector, boundary variables, and directional logic
    // Hint: Track four boundaries (top, bottom, left, right) and update them as you spiral inward
    return {n};
}

// Problem A4: Complex Synthesis - Prime Number Sieve and Analysis
// Implement the Sieve of Eratosthenes algorithm to find all prime numbers up to N.
// Then analyze the primes found:
// - Count twin primes (primes that differ by 2, like 3,5 or 11,13)
// - Find the largest gap between consecutive primes
// - Calculate the sum of all primes
// - Find all prime numbers that are also palindromes
//
// Example: For N=30
// Primes: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29
// Twin prime pairs: (3,5), (5,7), (11,13), (17,19)
// Largest gap: 4 (between 23 and 29)
// Sum: 129
// Prime palindromes: 2, 3, 5, 7, 11
//
// Input: Integer N (upper limit, 2 ≤ N ≤ 1000)
// Output: Struct containing all analysis results
// Constraints: Optimize for performance, handle edge cases properly
struct PrimeAnalysis {
    vector<int> primes;
    int twinPrimeCount;
    int largestGap;
    long long sumPrimes;
    vector<int> palindromePrimes;
};

PrimeAnalysis analyzePrimes(int N) {
    // TODO: Solve using Sieve algorithm (nested loops), vector operations, number theory, and palindrome checking
    // Hint: Use boolean array for sieve, then analyze the resulting prime list with additional loops
    PrimeAnalysis primeAnalysis;
    return primeAnalysis;
}

// Problem A5: Mastery Challenge - ASCII Art Generator with Animation
// Create a function that generates animated ASCII art patterns.
// The function should create multiple "frames" of a bouncing ball animation
// within a rectangular border. The ball moves diagonally and bounces off walls.
//
// Parameters:
// - width, height: dimensions of the playing field
// - frames: number of animation frames to generate
// - ballChar: character representing the ball
//
// Rules:
// - Ball starts at position (1,1) moving down-right
// - When ball hits a wall, it bounces (reverses appropriate direction)
// - Border is made of '+' for corners, '-' for top/bottom, '|' for sides
// - Empty spaces filled with ' '
// - Each frame shows ball position at that time step
//
// Example: 5x4 field, 8 frames might show ball moving and bouncing
//
// Input: width (3-20), height (3-15), frames (1-50), ballChar
// Output: Vector of strings, each representing one frame
// Constraints: Handle bouncing logic correctly, validate parameters
vector<string> generateBouncingBall(int width, int height, int frames, char ballChar) {
    // TODO: Solve using nested loops, 2D coordinate tracking, collision detection, and string manipulation
    // Hint: Track ball position and velocity, update position each frame, reverse velocity components on wall hits
    
    return {""};
}

// Problem A6: Expert Application - Advanced Factorization Calculator
// Create a comprehensive integer factorization system that combines multiple algorithms
// and provides detailed analysis. The system should:
//
// 1. Find prime factorization using trial division with optimizations
// 2. Calculate all divisors efficiently  
// 3. Determine if the number is perfect, abundant, or deficient
// 4. Find the largest proper divisor
// 5. Calculate Euler's totient function φ(n)
// 6. Determine if the number is a power of a prime
//
// Mathematical definitions:
// - Perfect number: sum of proper divisors equals the number (e.g., 6 = 1+2+3)
// - Abundant: sum of proper divisors > number
// - Deficient: sum of proper divisors < number  
// - φ(n): count of integers ≤ n that are coprime to n
// - Proper divisors: all divisors except the number itself
//
// Example: For n = 12
// Prime factorization: 2² × 3¹
// All divisors: 1, 2, 3, 4, 6, 12
// Proper divisors sum: 1+2+3+4+6 = 16 > 12 (abundant)
// Largest proper divisor: 6
// φ(12) = 4 (numbers 1,5,7,11 are coprime to 12)
// Not a prime power
//
// Input: Integer n (2 ≤ n ≤ 100000)
// Output: Comprehensive factorization analysis
// Constraints: Optimize for large numbers, handle edge cases, mathematical accuracy
struct FactorizationResult {
    vector<pair<int, int>> primeFactors; // (prime, exponent) pairs
    vector<int> allDivisors;
    string numberType; // "perfect", "abundant", or "deficient"
    int largestProperDivisor;
    int totientValue;
    bool isPrimePower;
    string primeFactorization; // formatted string like "2² × 3¹"
};

FactorizationResult advancedFactorization(int n) {
    // TODO: Solve using optimized trial division, sieve concepts, mathematical algorithms, and number theory
    // Hint: Use sqrt(n) optimization for prime finding, generate divisors from prime factors, implement totient formula
    FactorizationResult factorizationResult;
    return factorizationResult;
}

//=== SECTION B: KNOWLEDGE VALIDATION QUIZ ===

void knowledgeQuiz() {
    cout << "=== CHAPTER KNOWLEDGE QUIZ ===" << endl;
    cout << "Answer each question and check your understanding:" << endl << endl;
    
    int score = 0;
    char answer;
    
    // Question 1: Loop Types and Usage
    cout << "Q1: Which loop type is best when you know the exact number of iterations needed?" << endl;
    cout << "A) while loop  B) for loop  C) do-while loop  D) All are equally good" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "Correct! ✓" << endl;
        score++;
    } else {
        cout << "Incorrect. Correct Answer: B" << endl;
    }
    cout << "Explanation: For loops are ideal when iteration count is known because they keep initialization, condition, and increment in one place." << endl << endl;

    // Question 2: Loop Control Statements
    cout << "Q2: What happens when 'continue' is encountered in a loop?" << endl;
    cout << "A) Loop terminates completely  B) Current iteration stops, next iteration begins" << endl;
    cout << "C) Loop pauses indefinitely  D) Compiler error occurs" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "Correct! ✓" << endl;
        score++;
    } else {
        cout << "Incorrect. Correct Answer: B" << endl;
    }
    cout << "Explanation: 'continue' skips the rest of the current iteration and jumps to the next iteration." << endl << endl;

    // Question 3: Infinite Loop Identification
    cout << "Q3: Which of these creates an infinite loop?" << endl;
    cout << "A) for(int i=0; i<10; i++)  B) while(true)  C) do{...}while(false)  D) for(;;)" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b' || answer == 'D' || answer == 'd') {
        cout << "Correct! ✓" << endl;
        score++;
    } else {
        cout << "Incorrect. Correct Answer: B and D" << endl;
    }
    cout << "Explanation: while(true) and for(;;) both create infinite loops. Option C runs only once." << endl << endl;

    // Question 4: Nested Loop Complexity
    cout << "Q4: What is the time complexity of nested loops: for(i=0;i<n;i++) for(j=0;j<m;j++)?" << endl;
    cout << "A) O(n)  B) O(m)  C) O(n+m)  D) O(n*m)" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'D' || answer == 'd') {
        cout << "Correct! ✓" << endl;
        score++;
    } else {
        cout << "Incorrect. Correct Answer: D" << endl;
    }
    cout << "Explanation: Nested loops multiply their complexities. Outer loop runs n times, inner m times each." << endl << endl;

    // Question 5: Do-While vs While
    cout << "Q5: What's the key difference between while and do-while loops?" << endl;
    cout << "A) Performance  B) Syntax only  C) do-while executes at least once  D) No difference" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'C' || answer == 'c') {
        cout << "Correct! ✓" << endl;
        score++;
    } else {
        cout << "Incorrect. Correct Answer: C" << endl;
    }
    cout << "Explanation: do-while checks condition after execution, guaranteeing at least one iteration." << endl << endl;

    // Question 6: Loop Variable Scope
    cout << "Q6: In 'for(int i=0; i<10; i++)', where is variable 'i' accessible?" << endl;
    cout << "A) Entire program  B) Only inside the for loop  C) Until program ends  D) In all functions" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "Correct! ✓" << endl;
        score++;
    } else {
        cout << "Incorrect. Correct Answer: B" << endl;
    }
    cout << "Explanation: Loop variables declared in for statement have loop scope only." << endl << endl;

    // Question 7: Break vs Continue
    cout << "Q7: In nested loops, what does 'break' affect?" << endl;
    cout << "A) All loops  B) Only innermost loop  C) Only outermost loop  D) Random loop" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "Correct! ✓" << endl;
        score++;
    } else {
        cout << "Incorrect. Correct Answer: B" << endl;
    }
    cout << "Explanation: 'break' only exits the immediate enclosing loop, not outer loops." << endl << endl;

    // Question 8: Loop Initialization
    cout << "Q8: What happens if you forget to initialize a loop counter?" << endl;
    cout << "A) Compiler error  B) Undefined behavior  C) Automatic initialization to 0  D) Loop won't execute" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "Correct! ✓" << endl;
        score++;
    } else {
        cout << "Incorrect. Correct Answer: B" << endl;
    }
    cout << "Explanation: Uninitialized variables contain garbage values, leading to unpredictable behavior." << endl << endl;

    // Question 9: Loop Increment Patterns
    cout << "Q9: Which increment pattern is valid in a for loop?" << endl;
    cout << "A) i++  B) i+=2  C) i*=2  D) All of the above" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'D' || answer == 'd') {
        cout << "Correct! ✓" << endl;
        score++;
    } else {
        cout << "Incorrect. Correct Answer: D" << endl;
    }
    cout << "Explanation: Any valid C++ expression can be used as the increment in a for loop." << endl << endl;

    // Question 10: Loop Performance
    cout << "Q10: Which is more efficient for iterating through an array of known size?" << endl;
    cout << "A) while loop with counter  B) for loop with direct indexing  C) do-while loop  D) All same performance" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'D' || answer == 'd') {
        cout << "Correct! ✓" << endl;
        score++;
    } else {
        cout << "Incorrect. Correct Answer: D" << endl;
    }
    cout << "Explanation: Modern compilers optimize all loop types similarly for simple iterations." << endl << endl;

    // Question 11: Range-Based Loops
    cout << "Q11: What C++ feature provides simpler syntax for iterating collections?" << endl;
    cout << "A) while loops  B) Range-based for loops (for-each)  C) goto statements  D) Switch statements" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "Correct! ✓" << endl;
        score++;
    } else {
        cout << "Incorrect. Correct Answer: B" << endl;
    }
    cout << "Explanation: Range-based for loops (for(auto x : container)) simplify collection iteration." << endl << endl;

    // Question 12: Loop Condition Evaluation
    cout << "Q12: When is the condition in a while loop evaluated?" << endl;
    cout << "A) Once before the loop  B) Before each iteration  C) After each iteration  D) Only when break occurs" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "Correct! ✓" << endl;
        score++;
    } else {
        cout << "Incorrect. Correct Answer: B" << endl;
    }
    cout << "Explanation: while loop condition is checked before each iteration, including the first." << endl << endl;

    // Question 13: Common Loop Pitfalls
    cout << "Q13: What's a common mistake in this loop: for(int i=0; i<10; i--) ?" << endl;
    cout << "A) Wrong initialization  B) Wrong condition  C) Wrong increment (creates infinite loop)  D) Syntax error" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'C' || answer == 'c') {
        cout << "Correct! ✓" << endl;
        score++;
    } else {
        cout << "Incorrect. Correct Answer: C" << endl;
    }
    cout << "Explanation: Decrementing (i--) while condition is i<10 creates infinite loop since i starts at 0." << endl << endl;

    // Question 14: Loop Design Principles
    cout << "Q14: What's the most important principle when designing loops?" << endl;
    cout << "A) Use shortest code possible  B) Ensure loop will terminate  C) Always use for loops  D) Avoid nested loops" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "Correct! ✓" << endl;
        score++;
    } else {
        cout << "Incorrect. Correct Answer: B" << endl;
    }
    cout << "Explanation: Ensuring termination prevents infinite loops, which freeze programs." << endl << endl;

    // Question 15: Advanced Loop Applications
    cout << "Q15: Which algorithm commonly uses nested loops?" << endl;
    cout << "A) Linear search  B) Binary search  C) Bubble sort  D) Hash table lookup" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'C' || answer == 'c') {
        cout << "Correct! ✓" << endl;
        score++;
    } else {
        cout << "Incorrect. Correct Answer: C" << endl;
    }
    cout << "Explanation: Bubble sort uses nested loops to compare and swap adjacent elements repeatedly." << endl << endl;

    cout << "=== QUIZ COMPLETE ===" << endl;
    cout << "Your Score: " << score << "/15 (" << fixed << setprecision(1) << (score * 100.0 / 15) << "%)" << endl;
    
    if (score >= 13) cout << "Excellent! You have mastered this chapter!" << endl;
    else if (score >= 10) cout << "Good work! Review the missed concepts." << endl;
    else if (score >= 7) cout << "Fair understanding. More practice needed." << endl;
    else cout << "Please review the chapter material and practice more." << endl;
}

//=== MANDATORY COMPLETE TEST FUNCTIONS ===

void testProblemA1() {
    cout << "Testing Problem A1 - Foundation Integration (Pattern Generator)..." << endl;
    int passed = 0, total = 0;
    
    cout << "Note: This function tests print output - visual verification required" << endl;
    
    // Test Case 1: Right triangle pattern, size 3
    // Manual calculation: Should print:
    // 1
    // 12  
    // 123
    total++;
    cout << "Test 1 - Pattern 1, Size 3:" << endl;
    cout << "Expected output:" << endl << "1" << endl << "12" << endl << "123" << endl;
    cout << "Actual output:" << endl;
    generatePattern(1, 3);
    cout << "Does output match expected? (Visual verification required)" << endl;

    // Test Case 2: Reverse triangle, size 4
    // Manual calculation: Should print:
    // 4321
    // 432
    // 43
    // 4
    total++;
    cout << "Test 2 - Pattern 2, Size 4:" << endl;
    cout << "Expected output:" << endl << "4321" << endl << "432" << endl << "43" << endl << "4" << endl;
    cout << "Actual output:" << endl;
    generatePattern(2, 4);
    
    // Test Case 3: Invalid pattern type
    total++;
    cout << "Test 3 - Invalid pattern (should handle gracefully):" << endl;
    generatePattern(5, 3);
    
    // Test Case 4: Edge case - size 1
    total++;
    cout << "Test 4 - Pattern 1, Size 1:" << endl;
    cout << "Expected: 1" << endl;
    cout << "Actual:" << endl;
    generatePattern(1, 1);
    
    cout << "Problem A1: Manual verification required for " << total << " test cases" << endl << endl;
}

void testProblemA2() {
    cout << "Testing Problem A2 - Intermediate Synthesis (Number Analyzer)..." << endl;
    int passed = 0, total = 0;
    
    cout << "Note: This function requires interactive input - prepare test sequences" << endl;
    
    // Test Case 1: Mixed positive/negative numbers
    // Manual calculation for input sequence: 5, -3, 8, -1, 2, 0
    // Sum of positives: 5 + 8 + 2 = 15
    // Count of negatives: -3, -1 = 2 numbers
    // Average: (5 + (-3) + 8 + (-1) + 2) / 5 = 11 / 5 = 2.2
    // Max: 8, Min: -3
    // Even numbers: 8, 2 = 2 numbers
    // Odd numbers: 5, -3, -1 = 3 numbers
    total++;
    cout << "Test 1: Enter sequence: 5 -3 8 -1 2 0" << endl;
    cout << "Expected - Sum positives: 15, Count negatives: 2, Average: 2.2" << endl;
    cout << "Expected - Max: 8, Min: -3, Evens: 2, Odds: 3" << endl;
    NumberStats result1 = analyzeNumbers();
    cout << "Actual results:" << endl;
    cout << "Sum positives: " << result1.sumPositive << " (expected: 15)" << endl;
    cout << "Count negatives: " << result1.countNegative << " (expected: 2)" << endl;
    cout << "Average: " << fixed << setprecision(1) << result1.average << " (expected: 2.2)" << endl;
    cout << "Max: " << result1.maxNum << " (expected: 8)" << endl;
    cout << "Min: " << result1.minNum << " (expected: -3)" << endl;
    cout << "Evens: " << result1.countEven << " (expected: 2)" << endl;
    cout << "Odds: " << result1.countOdd << " (expected: 3)" << endl;
    
    if (result1.sumPositive == 15 && result1.countNegative == 2 && 
        abs(result1.average - 2.2) < 0.01 && result1.maxNum == 8 && 
        result1.minNum == -3 && result1.countEven == 2 && result1.countOdd == 3) {
        cout << "Test 1: PASS" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL" << endl;
    }

    // Test Case 2: Only positive numbers
    // Manual calculation for input: 2, 4, 6, 0
    // Sum positives: 2 + 4 + 6 = 12
    // Count negatives: 0
    // Average: (2 + 4 + 6) / 3 = 4.0
    // Max: 6, Min: 2
    // Evens: 3, Odds: 0
    total++;
    cout << "\nTest 2: Enter sequence: 2 4 6 0" << endl;
    cout << "Expected - Sum positives: 12, Count negatives: 0, Average: 4.0" << endl;
    cout << "Expected - Max: 6, Min: 2, Evens: 3, Odds: 0" << endl;
    NumberStats result2 = analyzeNumbers();
    
    if (result2.sumPositive == 12 && result2.countNegative == 0 && 
        abs(result2.average - 4.0) < 0.01 && result2.maxNum == 6 && 
        result2.minNum == 2 && result2.countEven == 3 && result2.countOdd == 0) {
        cout << "Test 2: PASS" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL" << endl;
    }

    cout << "Problem A2 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA3() {
    cout << "Testing Problem A3 - Advanced Integration (Matrix Spiral Traversal)..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: 3x3 matrix
    // Manual calculation: Matrix is:
    // 1 2 3
    // 4 5 6
    // 7 8 9
    // Spiral: right(1,2,3) → down(6,9) → left(8,7) → up(4) → center(5)
    // Expected result: [1, 2, 3, 6, 9, 8, 7, 4, 5]
    total++;
    vector<int> result1 = spiralTraversal(3);
    vector<int> expected1 = {1, 2, 3, 6, 9, 8, 7, 4, 5};
    bool test1Pass = (result1 == expected1);
    
    if (test1Pass) {
        cout << "Test 1: PASS" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL" << endl;
        cout << "Expected: ";
        for (int x : expected1) cout << x << " ";
        cout << endl << "Got: ";
        for (int x : result1) cout << x << " ";
        cout << endl;
    }

    // Test Case 2: 4x4 matrix  
    // Manual calculation: Matrix is:
    // 1  2  3  4
    // 5  6  7  8
    // 9  10 11 12
    // 13 14 15 16
    // Spiral: right(1,2,3,4) → down(8,12,16) → left(15,14,13) → up(9,5) → right(6,7) → down(11) → left(10)
    // Expected result: [1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]
    total++;
    vector<int> result2 = spiralTraversal(4);
    vector<int> expected2 = {1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10};
    bool test2Pass = (result2 == expected2);
    
    if (test2Pass) {
        cout << "Test 2: PASS" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL" << endl;
        cout << "Expected: ";
        for (int x : expected2) cout << x << " ";
        cout << endl << "Got: ";
        for (int x : result2) cout << x << " ";
        cout << endl;
    }

    // Test Case 3: Edge case 1x1 matrix
    // Manual calculation: Only element 1
    // Expected result: [1]
    total++;
    vector<int> result3 = spiralTraversal(1);
    vector<int> expected3 = {1};
    
    if (result3 == expected3) {
        cout << "Test 3: PASS" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Expected: [1], Got: [" << (result3.empty() ? "" : to_string(result3[0])) << "]" << endl;
    }

    // Test Case 4: 2x2 matrix
    // Manual calculation: Matrix is:
    // 1 2
    // 3 4
    // Spiral: right(1,2) → down(4) → left(3)
    // Expected result: [1, 2, 4, 3]
    total++;
    vector<int> result4 = spiralTraversal(2);
    vector<int> expected4 = {1, 2, 4, 3};
    
    if (result4 == expected4) {
        cout << "Test 4: PASS" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL" << endl;
        cout << "Expected: ";
        for (int x : expected4) cout << x << " ";
        cout << endl << "Got: ";
        for (int x : result4) cout << x << " ";
        cout << endl;
    }

    cout << "Problem A3 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA4() {
    cout << "Testing Problem A4 - Complex Synthesis (Prime Number Sieve and Analysis)..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Small range N=30
    // Manual calculation: Primes up to 30: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29
    // Twin prime pairs: (3,5), (5,7), (11,13), (17,19) = 4 pairs
    // Largest gap: 23 to 29 = 6, but also 7 to 11 = 4. Actually largest is 6.
    // Sum: 2+3+5+7+11+13+17+19+23+29 = 129
    // Prime palindromes: 2, 3, 5, 7, 11 (5 numbers)
    total++;
    PrimeAnalysis result1 = analyzePrimes(30);
    vector<int> expectedPrimes1 = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    bool primesCorrect1 = (result1.primes == expectedPrimes1);
    bool twinPrimesCorrect1 = (result1.twinPrimeCount == 4);
    bool gapCorrect1 = (result1.largestGap == 6); // gap between 23 and 29
    bool sumCorrect1 = (result1.sumPrimes == 129);
    vector<int> expectedPalindromes1 = {2, 3, 5, 7, 11};
    bool palindromesCorrect1 = (result1.palindromePrimes == expectedPalindromes1);
    
    if (primesCorrect1 && twinPrimesCorrect1 && gapCorrect1 && sumCorrect1 && palindromesCorrect1) {
        cout << "Test 1: PASS" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL" << endl;
        if (!primesCorrect1) {
            cout << "  Primes incorrect. Expected 10 primes, got " << result1.primes.size() << endl;
        }
        if (!twinPrimesCorrect1) {
            cout << "  Twin pairs incorrect. Expected: 4, Got: " << result1.twinPrimeCount << endl;
        }
        if (!gapCorrect1) {
            cout << "  Largest gap incorrect. Expected: 6, Got: " << result1.largestGap << endl;
        }
        if (!sumCorrect1) {
            cout << "  Sum incorrect. Expected: 129, Got: " << result1.sumPrimes << endl;
        }
        if (!palindromesCorrect1) {
            cout << "  Palindrome count incorrect. Expected: 5, Got: " << result1.palindromePrimes.size() << endl;
        }
    }

    // Test Case 2: Very small range N=10  
    // Manual calculation: Primes up to 10: 2, 3, 5, 7
    // Twin prime pairs: (3,5), (5,7) = 2 pairs
    // Largest gap: 5 to 7 = 2
    // Sum: 2+3+5+7 = 17
    // Prime palindromes: 2, 3, 5, 7 (4 numbers)
    total++;
    PrimeAnalysis result2 = analyzePrimes(10);
    vector<int> expectedPrimes2 = {2, 3, 5, 7};
    
    if (result2.primes == expectedPrimes2 && result2.twinPrimeCount == 2 && 
        result2.largestGap == 2 && result2.sumPrimes == 17 && 
        result2.palindromePrimes.size() == 4) {
        cout << "Test 2: PASS" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL" << endl;
        cout << "Expected: 4 primes, 2 twin pairs, gap=2, sum=17, 4 palindromes" << endl;
        cout << "Got: " << result2.primes.size() << " primes, " << result2.twinPrimeCount 
             << " twin pairs, gap=" << result2.largestGap << ", sum=" << result2.sumPrimes 
             << ", " << result2.palindromePrimes.size() << " palindromes" << endl;
    }

    // Test Case 3: Edge case N=2 (smallest valid input)
    // Manual calculation: Only prime is 2
    // No twin pairs, no gaps, sum=2, one palindrome
    total++;
    PrimeAnalysis result3 = analyzePrimes(2);
    
    if (result3.primes.size() == 1 && result3.primes[0] == 2 && 
        result3.twinPrimeCount == 0 && result3.sumPrimes == 2) {
        cout << "Test 3: PASS" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Edge case N=2 not handled correctly" << endl;
    }

    cout << "Problem A4 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA5() {
    cout << "Testing Problem A5 - Mastery Challenge (ASCII Art Animation)..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Small 5x4 field, 3 frames
    // Manual calculation: Ball starts at (1,1) moving right-down
    // Frame 0: Ball at (1,1)
    // Frame 1: Ball at (2,2) 
    // Frame 2: Ball at (3,3)
    // Expected frame dimensions: 5 wide × 4 tall
    total++;
    vector<string> result1 = generateBouncingBall(5, 4, 3, 'O');
    bool sizeCorrect1 = (result1.size() == 3);
    bool dimensionsCorrect1 = true;
    
    if (sizeCorrect1) {
        for (const string& frame : result1) {
            if (frame.find('\n') != string::npos) {
                // Count lines in frame
                int lines = 1;
                for (char c : frame) if (c == '\n') lines++;
                if (lines != 4) dimensionsCorrect1 = false;
            }
        }
    }
    
    if (sizeCorrect1 && dimensionsCorrect1) {
        cout << "Test 1: PASS" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL" << endl;
        cout << "Expected: 3 frames of 5x4 dimension" << endl;
        cout << "Got: " << result1.size() << " frames" << endl;
    }

    // Test Case 2: Minimum size 3x3, 1 frame
    // Manual calculation: Should create valid 3x3 bordered field
    // Border should be +--+ on top/bottom, |  | on sides
    total++;
    vector<string> result2 = generateBouncingBall(3, 3, 1, '*');
    bool minSizeCorrect = (result2.size() == 1);
    
    if (minSizeCorrect) {
        cout << "Test 2: PASS" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Minimum size test failed" << endl;
    }

    // Test Case 3: Edge case - 1 frame
    total++;
    vector<string> result3 = generateBouncingBall(4, 4, 1, '@');
    
    if (result3.size() == 1) {
        cout << "Test 3: PASS" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Single frame test failed" << endl;
    }

    cout << "Note: Visual verification required for animation correctness" << endl;
    cout << "Problem A5 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA6() {
    cout << "Testing Problem A6 - Expert Application (Advanced Factorization)..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: n = 12
    // Manual calculation:
    // Prime factorization: 12 = 2² × 3¹
    // All divisors: 1, 2, 3, 4, 6, 12 (6 divisors)
    // Proper divisors sum: 1+2+3+4+6 = 16 > 12 (abundant)
    // Largest proper divisor: 6
    // φ(12) = 12 × (1-1/2) × (1-1/3) = 12 × 1/2 × 2/3 = 4
    // Not a prime power (has two different prime factors)
    total++;
    FactorizationResult result1 = advancedFactorization(12);
    
    vector<pair<int, int>> expectedFactors1 = {{2, 2}, {3, 1}};
    vector<int> expectedDivisors1 = {1, 2, 3, 4, 6, 12};
    bool factors1 = (result1.primeFactors == expectedFactors1);
    bool divisors1 = (result1.allDivisors == expectedDivisors1);
    bool abundant1 = (result1.numberType == "abundant");
    bool largestDiv1 = (result1.largestProperDivisor == 6);
    bool totient1 = (result1.totientValue == 4);
    bool notPrimePower1 = (!result1.isPrimePower);
    
    if (factors1 && divisors1 && abundant1 && largestDiv1 && totient1 && notPrimePower1) {
        cout << "Test 1: PASS" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL" << endl;
        if (!factors1) cout << "  Prime factors incorrect" << endl;
        if (!divisors1) cout << "  Divisors incorrect. Expected 6 divisors" << endl;
        if (!abundant1) cout << "  Number type incorrect. Expected: abundant, Got: " << result1.numberType << endl;
        if (!largestDiv1) cout << "  Largest proper divisor incorrect. Expected: 6, Got: " << result1.largestProperDivisor << endl;
        if (!totient1) cout << "  Totient incorrect. Expected: 4, Got: " << result1.totientValue << endl;
        if (result1.isPrimePower) cout << "  Should not be prime power" << endl;
    }

    // Test Case 2: Perfect number n = 6
    // Manual calculation:
    // Prime factorization: 6 = 2¹ × 3¹  
    // All divisors: 1, 2, 3, 6
    // Proper divisors sum: 1+2+3 = 6 = 6 (perfect)
    // Largest proper divisor: 3
    // φ(6) = 6 × (1-1/2) × (1-1/3) = 6 × 1/2 × 2/3 = 2
    // Not a prime power
    total++;
    FactorizationResult result2 = advancedFactorization(6);
    
    if (result2.numberType == "perfect" && result2.largestProperDivisor == 3 && 
        result2.totientValue == 2 && !result2.isPrimePower) {
        cout << "Test 2: PASS" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL" << endl;
        cout << "Expected: perfect number, largest proper divisor=3, φ(6)=2, not prime power" << endl;
        cout << "Got: " << result2.numberType << ", largest=" << result2.largestProperDivisor 
             << ", φ=" << result2.totientValue << ", prime power=" << result2.isPrimePower << endl;
    }

    // Test Case 3: Prime power n = 8 = 2³
    // Manual calculation:
    // Prime factorization: 8 = 2³
    // All divisors: 1, 2, 4, 8
    // Proper divisors sum: 1+2+4 = 7 < 8 (deficient)
    // Largest proper divisor: 4
    // φ(8) = 8 × (1-1/2) = 4
    // Is a prime power
    total++;
    FactorizationResult result3 = advancedFactorization(8);
    
    if (result3.numberType == "deficient" && result3.largestProperDivisor == 4 && 
        result3.totientValue == 4 && result3.isPrimePower) {
        cout << "Test 3: PASS" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL" << endl;
        cout << "Expected: deficient, largest=4, φ=4, is prime power" << endl;
        cout << "Got: " << result3.numberType << ", largest=" << result3.largestProperDivisor 
             << ", φ=" << result3.totientValue << ", prime power=" << result3.isPrimePower << endl;
    }

    // Test Case 4: Prime number n = 17
    // Manual calculation:
    // Prime factorization: 17 = 17¹
    // All divisors: 1, 17
    // Proper divisors sum: 1 < 17 (deficient)
    // Largest proper divisor: 1
    // φ(17) = 17-1 = 16
    // Is a prime power
    total++;
    FactorizationResult result4 = advancedFactorization(17);
    
    if (result4.numberType == "deficient" && result4.largestProperDivisor == 1 && 
        result4.totientValue == 16 && result4.isPrimePower && 
        result4.primeFactors.size() == 1 && result4.primeFactors[0].first == 17) {
        cout << "Test 4: PASS" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Prime number test failed" << endl;
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
    cout << "=== COMPREHENSIVE C++ LOOPS CHAPTER ASSESSMENT ===" << endl;
    cout << "Choose your assessment mode:" << endl << endl;

    cout << "INTEGRATION PROBLEMS:" << endl;
    cout << "1. Problem A1 - Foundation Integration (Easy)" << endl;
    cout << "   [Pattern Generator - nested loops, conditionals, output formatting]" << endl;
    cout << "2. Problem A2 - Intermediate Synthesis (Easy-Medium)" << endl;
    cout << "   [Number Analyzer - while loops, input validation, statistical calculations]" << endl;
    cout << "3. Problem A3 - Advanced Integration (Medium)" << endl;
    cout << "   [Matrix Spiral - 2D arrays, boundary tracking, complex loop logic]" << endl;
    cout << "4. Problem A4 - Complex Synthesis (Medium-Hard)" << endl;
    cout << "   [Prime Sieve - algorithm implementation, mathematical analysis]" << endl;
    cout << "5. Problem A5 - Mastery Challenge (Hard)" << endl;
    cout << "   [ASCII Animation - coordinate tracking, collision detection, string manipulation]" << endl;
    cout << "6. Problem A6 - Expert Application (Very Hard)" << endl;
    cout << "   [Advanced Factorization - number theory, optimization, comprehensive analysis]" << endl;
    cout << "7. Test All Integration Problems" << endl << endl;

    cout << "KNOWLEDGE VALIDATION:" << endl;
    cout << "8. Chapter Knowledge Quiz (15 interactive questions)" << endl << endl;

    cout << "COMPREHENSIVE ASSESSMENT:" << endl;
    cout << "9. Full Chapter Assessment (All problems + Quiz)" << endl << endl;

    int choice;
    cout << "Enter your choice (1-9): ";
    cin >> choice;

    switch(choice) {
        case 1: 
            cout << "\n=== PROBLEM A1: FOUNDATION INTEGRATION ===" << endl;
            cout << "Implement generatePattern() function and run tests" << endl;
            testProblemA1(); 
            break;
        case 2: 
            cout << "\n=== PROBLEM A2: INTERMEDIATE SYNTHESIS ===" << endl;
            cout << "Implement analyzeNumbers() function and run tests" << endl;
            testProblemA2(); 
            break;
        case 3: 
            cout << "\n=== PROBLEM A3: ADVANCED INTEGRATION ===" << endl;
            cout << "Implement spiralTraversal() function and run tests" << endl;
            testProblemA3(); 
            break;
        case 4: 
            cout << "\n=== PROBLEM A4: COMPLEX SYNTHESIS ===" << endl;
            cout << "Implement analyzePrimes() function and run tests" << endl;
            testProblemA4(); 
            break;
        case 5: 
            cout << "\n=== PROBLEM A5: MASTERY CHALLENGE ===" << endl;
            cout << "Implement generateBouncingBall() function and run tests" << endl;
            testProblemA5(); 
            break;
        case 6: 
            cout << "\n=== PROBLEM A6: EXPERT APPLICATION ===" << endl;
            cout << "Implement advancedFactorization() function and run tests" << endl;
            testProblemA6(); 
            break;
        case 7: 
            cout << "\n=== RUNNING ALL INTEGRATION TESTS ===" << endl;
            runAllTests(); 
            break;
        case 8: 
            cout << "\n=== CHAPTER KNOWLEDGE QUIZ ===" << endl;
            knowledgeQuiz(); 
            break;
        case 9:
            cout << "\n=== COMPREHENSIVE CHAPTER ASSESSMENT ===" << endl;
            cout << "Part 1: Integration Problems Testing" << endl;
            runAllTests();
            cout << "\nPart 2: Knowledge Validation Quiz" << endl;
            knowledgeQuiz();
            cout << "\n=== ASSESSMENT COMPLETE ===" << endl;
            break;
        default: 
            cout << "Invalid choice! Please run again and select 1-9." << endl;
    }

    return 0;
}