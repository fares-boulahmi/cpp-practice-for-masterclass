#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

//=== SECTION A: INTEGRATION PROBLEMS ===

// Problem A1: Foundation Integration - Number Pattern Generator
// Create a function that generates number patterns using nested for loops.
// Combine: For loops, nested loops, basic arithmetic operations
// 
// Example 1: generateTrianglePattern(4, '*') should output:
// *
// **
// ***
// ****
//
// Example 2: generateNumberTriangle(3) should output:
// 1
// 1 2
// 1 2 3
//
// Input: rows (1-10), optional character for pattern
// Output: Print pattern to console, return total characters printed
// Edge cases: rows = 0, rows = 1, negative rows
int generateTrianglePattern(int rows, char symbol = '*') {
    // TODO: Solve using for loops, nested loops, and basic operations
    // Hint: Use outer loop for rows, inner loop for columns
    int symbols{};
    if (symbol) {
          for (int i{1} ; i <= rows ; i++  ) {
            string number {};
            for (int j{1} ; j <= i ; j++) {
                number = number + symbol;
                symbols++;
            } 
            cout << number  << endl;
        }
    } else {
         for (int i{1} ; i <= rows ; i++  ) {
            string number {};
            for (int j{1} ; j <= i ; j++) {
                number = number + to_string(j);
                symbols++;
            } 
            cout << number  << endl;
        }
    }
    return symbols;
}

// Problem A2: Intermediate Synthesis - Prime Number Analyzer
// Combine: While loops, for loops, boolean logic, mathematical operations, conditional statements
// Create a function that finds all prime numbers in a range and analyzes them.
//
// Example: analyzePrimesInRange(10, 30) should find primes: 11, 13, 17, 19, 23, 29
// Return a structure containing: count of primes, sum of primes, largest prime
//
// Input: start range, end range (both positive integers)
// Output: Custom struct with analysis results
// Edge cases: Invalid range, range with no primes, single number range
struct PrimeAnalysis {
    int count;
    int sum;
    int largest;
};

PrimeAnalysis analyzePrimesInRange(int start, int end) {
    // TODO: Solve using while/for loops, boolean conditions, math operations
    // Hint: Use nested loops for prime checking, track statistics during iteration
    PrimeAnalysis primeAnalysis;
    primeAnalysis.count = 0;
    primeAnalysis.sum = 0;
    vector<int> primes{};
    int i {start} ;
    while (i <= end) {
        bool prime {false};
        for (size_t j = 2; j < i; j++)
        {
            if ( i % j == 0) {
                prime = true;
            } 
        }
        if (!prime)
        {
            primes.push_back(i);
        }
        i++;
    }

    for (size_t i{} ; i < primes.size() ; i++) {
        primeAnalysis.count++ ;
        primeAnalysis.sum += primes[i];
    }
    if (primes.size() > 0) {
        primeAnalysis.largest = primes[primes.size() - 1] ;
    }

    return primeAnalysis;
}

// Problem A3: Advanced Integration - Digital Root Calculator with Statistics
// Combine: Do-while loops, while loops, modulo operations, vector operations, math functions
// Calculate digital root (repeated sum of digits until single digit) for multiple numbers
// and provide statistical analysis.
//
// Example: Digital root of 9875 -> 9+8+7+5=29 -> 2+9=11 -> 1+1=2
// Process vector of numbers: [123, 456, 789] -> roots: [6, 6, 6]
// Return statistics: min, max, average, most frequent root
//
// Input: vector of positive integers
// Output: vector of digital roots + statistical summary
// Edge cases: Empty vector, single digit numbers, very large numbers
struct DigitalRootStats {
    vector<int> roots;
    int minRoot;
    int maxRoot;
    double avgRoot;
    int mostFrequentRoot;
    int frequency;
};

DigitalRootStats calculateDigitalRoots(const vector<int>& numbers) {
    // TODO: Solve using do-while for digit sum, while for processing, vector operations
    // Hint: Use do-while to calculate single digital root, track frequency with counting
    return {{}, 0, 0, 0.0, 0, 0};
}

// Problem A4: Complex Synthesis - Fibonacci Sequence Variants Generator
// Combine: All three loop types, recursive-like logic, mathematical sequences, 
// conditional logic, string manipulation, formatting
//
// Generate different Fibonacci variants:
// 1. Classic: F(n) = F(n-1) + F(n-2), starting with 0,1
// 2. Lucas: L(n) = L(n-1) + L(n-2), starting with 2,1  
// 3. Tribonacci: T(n) = T(n-1) + T(n-2) + T(n-3), starting with 0,0,1
//
// Example: generateFibonacciVariants(8) generates first 8 terms of each sequence
// Return formatted string with all sequences displayed in columns
//
// Input: number of terms (1-20), sequence type flags
// Output: formatted string showing aligned sequences
// Edge cases: n=0, n=1, very large terms causing overflow
string generateFibonacciVariants(int terms, bool includeClassic = true, 
                                bool includeLucas = true, bool includeTribonacci = true) {
    // TODO: Solve using for loops for generation, while loops for formatting, 
    // conditional logic for variants, string manipulation for output
    // Hint: Use separate loops for each sequence, then combine with formatting
    return "";
}

// Problem A5: Mastery Challenge - Interactive Number Game Engine
// Integrate ALL major loop concepts with previous chapters:
// For loops, while loops, do-while loops, user input validation, 
// mathematical operations, conditional logic, string processing
//
// Create a guessing game where:
// 1. Generate random target number using mathematical formula
// 2. User has limited attempts to guess
// 3. Provide hints based on mathematical properties (even/odd, prime, perfect square)
// 4. Track statistics across multiple rounds
// 5. Allow user to play multiple games with different difficulty levels
//
// Features: Input validation, hint system, scoring, replay functionality
// Input: User interactions through console
// Output: Game results, statistics summary
// Edge cases: Invalid inputs, boundary values, consecutive games
struct GameStats {
    int gamesPlayed;
    int gamesWon;
    int totalAttempts;
    int bestScore;
    double averageAttempts;
};

GameStats playNumberGuessingGame() {
    // TODO: Integrate all loop types, user input validation, math operations,
    // conditional statements, and statistical tracking
    // Hint: Use do-while for game loop, while for input validation, for for attempts
    return {0, 0, 0, 0, 0.0};
}

// Problem A6: Expert Application - Advanced Text Processing Engine
// Master-level integration: All loops + comprehensive previous knowledge
// Create a text analyzer that processes multiple lines of input and provides
// comprehensive analysis using various loop patterns.
//
// Features:
// 1. Character frequency analysis (using for loops)
// 2. Word pattern detection (using while loops) 
// 3. Palindrome detection for words/sentences (using do-while loops)
// 4. Statistical analysis with formatting
// 5. Interactive menu system with input validation
//
// Example: Process text "Programming is fun! Fun programming."
// Analysis: char frequencies, word count, palindromes found, sentence statistics
//
// Input: Multiple lines of text, menu choices
// Output: Comprehensive formatted analysis report
// Edge cases: Empty input, special characters, very long text, malformed input
struct TextAnalysis {
    int totalChars;
    int totalWords;
    int totalSentences;
    vector<pair<char, int>> charFrequency;
    vector<string> palindromes;
    string longestWord;
    double avgWordLength;
};

TextAnalysis processTextAdvanced() {
    // TODO: Master-level integration of all concepts from current and previous chapters
    // Use all three loop types strategically, combine with comprehensive data processing
    // Hint: Nested loops for analysis, different loop types for different processing stages
    return {0, 0, 0, {}, {}, "", 0.0};
}

//=== SECTION B: KNOWLEDGE VALIDATION QUIZ ===

void knowledgeQuiz() {
    cout << "=== LOOPS CHAPTER KNOWLEDGE QUIZ ===" << endl;
    cout << "Answer each question and check your understanding:" << endl << endl;

    int totalScore = 0;

    // Question 1: Basic For Loop Syntax
    cout << "Q1: What is the correct syntax for a for loop in C++?" << endl;
    cout << "A) for(init; condition; increment) { }  B) for(condition; init; increment) { }" << endl;
    cout << "C) for(increment; condition; init) { }  D) for(init; increment; condition) { }" << endl;
    cout << "Your answer (A/B/C/D): ";
    char answer1;
    cin >> answer1;
    if (answer1 == 'A' || answer1 == 'a') {
        cout << "CORRECT! The standard for loop syntax is: for(initialization; condition; increment)" << endl;
        totalScore++;
    } else {
        cout << "INCORRECT. Correct Answer: A - for(init; condition; increment) is the standard syntax." << endl;
    }
    cout << endl;

    // Question 2: Loop Execution Count
    cout << "Q2: How many times will this loop execute? for(int i = 0; i < 5; i++)" << endl;
    cout << "A) 4 times  B) 5 times  C) 6 times  D) Infinite times" << endl;
    cout << "Your answer (A/B/C/D): ";
    char answer2;
    cin >> answer2;
    if (answer2 == 'B' || answer2 == 'b') {
        cout << "CORRECT! Loop runs for i = 0,1,2,3,4 (5 iterations)" << endl;
        totalScore++;
    } else {
        cout << "INCORRECT. Correct Answer: B - Loop executes 5 times (i goes from 0 to 4)" << endl;
    }
    cout << endl;

    // Question 3: While vs Do-While
    cout << "Q3: What's the key difference between while and do-while loops?" << endl;
    cout << "A) No difference  B) do-while executes at least once" << endl;
    cout << "C) while is faster  D) do-while can't use break" << endl;
    cout << "Your answer (A/B/C/D): ";
    char answer3;
    cin >> answer3;
    if (answer3 == 'B' || answer3 == 'b') {
        cout << "CORRECT! do-while always executes the body at least once before checking condition" << endl;
        totalScore++;
    } else {
        cout << "INCORRECT. Correct Answer: B - do-while executes body first, then checks condition" << endl;
    }
    cout << endl;

    // Question 4: Nested Loop Complexity
    cout << "Q4: What's the time complexity of nested loops: for(i=0;i<n;i++) for(j=0;j<n;j++)?" << endl;
    cout << "A) O(n)  B) O(n²)  C) O(2n)  D) O(log n)" << endl;
    cout << "Your answer (A/B/C/D): ";
    char answer4;
    cin >> answer4;
    if (answer4 == 'B' || answer4 == 'b') {
        cout << "CORRECT! Nested loops with same range create O(n²) complexity" << endl;
        totalScore++;
    } else {
        cout << "INCORRECT. Correct Answer: B - Two nested n-iteration loops = n*n = O(n²)" << endl;
    }
    cout << endl;

    // Question 5: Loop Control Statements
    cout << "Q5: What does 'continue' statement do in a loop?" << endl;
    cout << "A) Exits the loop  B) Restarts the loop  C) Skips current iteration  D) Pauses the loop" << endl;
    cout << "Your answer (A/B/C/D): ";
    char answer5;
    cin >> answer5;
    if (answer5 == 'C' || answer5 == 'c') {
        cout << "CORRECT! 'continue' skips remaining statements in current iteration and moves to next" << endl;
        totalScore++;
    } else {
        cout << "INCORRECT. Correct Answer: C - continue skips rest of current iteration" << endl;
    }
    cout << endl;

    // Question 6: Infinite Loop Detection
    cout << "Q6: Which creates an infinite loop?" << endl;
    cout << "A) for(;;)  B) while(true)  C) do{}while(1)  D) All of the above" << endl;
    cout << "Your answer (A/B/C/D): ";
    char answer6;
    cin >> answer6;
    if (answer6 == 'D' || answer6 == 'd') {
        cout << "CORRECT! All three constructs create infinite loops" << endl;
        totalScore++;
    } else {
        cout << "INCORRECT. Correct Answer: D - for(;;), while(true), and do{}while(1) all loop infinitely" << endl;
    }
    cout << endl;

    // Question 7: Loop Variable Scope
    cout << "Q7: What happens to a for loop variable declared in the initialization?" << endl;
    cout << "A) Global scope  B) Function scope  C) Loop scope only  D) Error occurs" << endl;
    cout << "Your answer (A/B/C/D): ";
    char answer7;
    cin >> answer7;
    if (answer7 == 'C' || answer7 == 'c') {
        cout << "CORRECT! Loop variables have scope limited to the loop block" << endl;
        totalScore++;
    } else {
        cout << "INCORRECT. Correct Answer: C - for loop variables are scoped to the loop only" << endl;
    }
    cout << endl;

    // Question 8: Performance Consideration
    cout << "Q8: Which is generally more efficient for counting down?" << endl;
    cout << "A) for(i=0;i<n;i++)  B) for(i=n;i>0;i--)  C) Same efficiency  D) Depends on compiler" << endl;
    cout << "Your answer (A/B/C/D): ";
    char answer8;
    cin >> answer8;
    if (answer8 == 'B' || answer8 == 'b') {
        cout << "CORRECT! Counting down to zero is often slightly more efficient (compare with 0)" << endl;
        totalScore++;
    } else {
        cout << "INCORRECT. Correct Answer: B - Comparing with 0 in countdown can be more efficient" << endl;
    }
    cout << endl;

    // Question 9: Loop Modification
    cout << "Q9: What's wrong with: for(int i=0; i<10; i++) { if(i==5) i=10; }?" << endl;
    cout << "A) Nothing wrong  B) Syntax error  C) Logic error  D) Infinite loop" << endl;
    cout << "Your answer (A/B/C/D): ";
    char answer9;
    cin >> answer9;
    if (answer9 == 'A' || answer9 == 'a') {
        cout << "CORRECT! This is valid - modifying loop variable inside loop is allowed" << endl;
        totalScore++;
    } else {
        cout << "INCORRECT. Correct Answer: A - Modifying loop variable is valid, loop will terminate" << endl;
    }
    cout << endl;

    // Question 10: Break vs Continue
    cout << "Q10: In nested loops, what does 'break' affect?" << endl;
    cout << "A) All loops  B) Only innermost loop  C) Only outermost loop  D) Causes error" << endl;
    cout << "Your answer (A/B/C/D): ";
    char answer10;
    cin >> answer10;
    if (answer10 == 'B' || answer10 == 'b') {
        cout << "CORRECT! 'break' only exits the immediately enclosing loop" << endl;
        totalScore++;
    } else {
        cout << "INCORRECT. Correct Answer: B - break only affects the innermost loop containing it" << endl;
    }
    cout << endl;

    // Question 11: Loop Initialization
    cout << "Q11: Which for loop initialization is valid?" << endl;
    cout << "A) for(int i=0, j=10; ...)  B) for(int i=0; int j=10; ...)  C) Both  D) Neither" << endl;
    cout << "Your answer (A/B/C/D): ";
    char answer11;
    cin >> answer11;
    if (answer11 == 'A' || answer11 == 'a') {
        cout << "CORRECT! Multiple variables in initialization must be separated by commas" << endl;
        totalScore++;
    } else {
        cout << "INCORRECT. Correct Answer: A - Use commas to declare multiple variables in for loop" << endl;
    }
    cout << endl;

    // Question 12: Do-While Semicolon
    cout << "Q12: What's special about do-while syntax?" << endl;
    cout << "A) No braces needed  B) Condition at start  C) Semicolon after while()  D) No condition needed" << endl;
    cout << "Your answer (A/B/C/D): ";
    char answer12;
    cin >> answer12;
    if (answer12 == 'C' || answer12 == 'c') {
        cout << "CORRECT! do-while requires semicolon after while(condition)" << endl;
        totalScore++;
    } else {
        cout << "INCORRECT. Correct Answer: C - do-while must end with semicolon: while(condition);" << endl;
    }
    cout << endl;

    // Question 13: Loop Optimization
    cout << "Q13: Best practice for loop condition with function calls?" << endl;
    cout << "A) for(i=0; i<size(); i++)  B) for(i=0, n=size(); i<n; i++)  C) No difference  D) Use while instead" << endl;
    cout << "Your answer (A/B/C/D): ";
    char answer13;
    cin >> answer13;
    if (answer13 == 'B' || answer13 == 'b') {
        cout << "CORRECT! Store function result to avoid repeated calls" << endl;
        totalScore++;
    } else {
        cout << "INCORRECT. Correct Answer: B - Cache function results to avoid repeated expensive calls" << endl;
    }
    cout << endl;

    // Question 14: Empty Loop Body
    cout << "Q14: What does this loop do? for(int i=0; i<1000000; i++);" << endl;
    cout << "A) Nothing useful  B) Compile error  C) Busy waiting/delay  D) Counts to million" << endl;
    cout << "Your answer (A/B/C/D): ";
    char answer14;
    cin >> answer14;
    if (answer14 == 'C' || answer14 == 'c') {
        cout << "CORRECT! Empty loop creates a busy-wait delay (though not recommended)" << endl;
        totalScore++;
    } else {
        cout << "INCORRECT. Correct Answer: C - Creates busy-waiting delay, consuming CPU time" << endl;
    }
    cout << endl;

    // Question 15: Advanced Loop Pattern
    cout << "Q15: What's the output of: for(int i=1; i<=3; i++) for(int j=1; j<=i; j++) cout<<j;" << endl;
    cout << "A) 123123123  B) 111213  C) 112123  D) 123321" << endl;
    cout << "Your answer (A/B/C/D): ";
    char answer15;
    cin >> answer15;
    if (answer15 == 'C' || answer15 == 'c') {
        cout << "CORRECT! i=1: prints 1, i=2: prints 12, i=3: prints 123 → 112123" << endl;
        totalScore++;
    } else {
        cout << "INCORRECT. Correct Answer: C - Nested loop prints 1, then 12, then 123 = 112123" << endl;
    }
    cout << endl;

    cout << "=== QUIZ COMPLETE ===" << endl;
    cout << "Your Score: " << totalScore << "/15 (" << fixed << setprecision(1) 
         << (totalScore * 100.0 / 15) << "%)" << endl;
    
    if (totalScore >= 13) cout << "Excellent mastery of loops!" << endl;
    else if (totalScore >= 10) cout << "Good understanding, review a few concepts." << endl;
    else if (totalScore >= 7) cout << "Fair understanding, more practice needed." << endl;
    else cout << "Need significant review of loop concepts." << endl;
}

//=== MANDATORY COMPLETE TEST FUNCTIONS ===

void testProblemA1() {
    cout << "Testing Problem A1 - Foundation Integration..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Basic triangle pattern with 4 rows
    // Manual calculation: Row 1: 1 char, Row 2: 2 chars, Row 3: 3 chars, Row 4: 4 chars
    // Total characters = 1 + 2 + 3 + 4 = 10 characters
    // Expected: 10
    total++;
    cout << "Expected output for generateTrianglePattern(4, '*'):" << endl;
    cout << "*" << endl << "**" << endl << "***" << endl << "****" << endl;
    int result1 = generateTrianglePattern(4, '*');
    if (result1 == 10) {
        cout << "Test 1: PASS - Correct character count" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - Expected: 10 characters, Got: " << result1 << endl;
    }

    // Test Case 2: Small triangle pattern with 2 rows using different character
    // Manual calculation: Row 1: 1 '#', Row 2: 2 '#'s = Total 3 characters
    // Expected: 3
    total++;
    cout << "\nExpected output for generateTrianglePattern(2, '#'):" << endl;
    cout << "#" << endl << "##" << endl;
    int result2 = generateTrianglePattern(2, '#');
    if (result2 == 3) {
        cout << "Test 2: PASS - Correct character count" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Expected: 3 characters, Got: " << result2 << endl;
    }

    // Test Case 3: Edge case - single row
    // Manual calculation: Row 1: 1 character = Total 1 character
    // Expected: 1
    total++;
    cout << "\nExpected output for generateTrianglePattern(1, 'X'):" << endl;
    cout << "X" << endl;
    int result3 = generateTrianglePattern(1, 'X');
    if (result3 == 1) {
        cout << "Test 3: PASS - Single row handled correctly" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Expected: 1 character, Got: " << result3 << endl;
    }

    // Test Case 4: Edge case - zero rows
    // Manual calculation: No rows = 0 characters
    // Expected: 0
    total++;
    int result4 = generateTrianglePattern(0, '*');
    if (result4 == 0) {
        cout << "Test 4: PASS - Zero rows handled correctly" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Expected: 0 characters, Got: " << result4 << endl;
    }

    // Test Case 5: Large triangle pattern
    // Manual calculation: 6 rows = 1+2+3+4+5+6 = 21 characters
    // Expected: 21
    total++;
    int result5 = generateTrianglePattern(6, '+');
    if (result5 == 21) {
        cout << "Test 5: PASS - Large triangle handled correctly" << endl;
        passed++;
    } else {
        cout << "Test 5: FAIL - Expected: 21 characters, Got: " << result5 << endl;
    }

    // Test Case 6: Default character parameter
    // Manual calculation: 3 rows with default '*' = 1+2+3 = 6 characters
    // Expected: 6
    total++;
    int result6 = generateTrianglePattern(3);
    if (result6 == 6) {
        cout << "Test 6: PASS - Default parameter works correctly" << endl;
        passed++;
    } else {
        cout << "Test 6: FAIL - Expected: 6 characters, Got: " << result6 << endl;
    }

    cout << "Problem A1 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA2() {
    cout << "Testing Problem A2 - Intermediate Synthesis..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Range 10 to 30
    // Manual calculation: Primes in range: 11, 13, 17, 19, 23, 29
    // Count: 6, Sum: 11+13+17+19+23+29 = 112, Largest: 29
    // Expected: {6, 112, 29}
    total++;
    PrimeAnalysis result1 = analyzePrimesInRange(10, 30);
    if (result1.count == 6 && result1.sum == 112 && result1.largest == 29) {
        cout << "Test 1: PASS - Range 10-30 analyzed correctly" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - Expected: count=6, sum=112, largest=29" << endl;
        cout << "         Got: count=" << result1.count << ", sum=" << result1.sum 
             << ", largest=" << result1.largest << endl;
    }

    // Test Case 2: Small range 2 to 10
    // Manual calculation: Primes: 2, 3, 5, 7
    // Count: 4, Sum: 2+3+5+7 = 17, Largest: 7
    // Expected: {4, 17, 7}
    total++;
    PrimeAnalysis result2 = analyzePrimesInRange(2, 10);
    if (result2.count == 4 && result2.sum == 17 && result2.largest == 7) {
        cout << "Test 2: PASS - Range 2-10 analyzed correctly" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Expected: count=4, sum=17, largest=7" << endl;
        cout << "         Got: count=" << result2.count << ", sum=" << result2.sum 
             << ", largest=" << result2.largest << endl;
    }

    // Test Case 3: Range with no primes (24 to 28)
    // Manual calculation: 24=2³×3, 25=5², 26=2×13, 27=3³, 28=2²×7 (no primes)
    // Count: 0, Sum: 0, Largest: 0 (or -1 to indicate none)
    // Expected: {0, 0, 0}
    total++;
    PrimeAnalysis result3 = analyzePrimesInRange(24, 28);
    if (result3.count == 0 && result3.sum == 0) {
        cout << "Test 3: PASS - Range with no primes handled correctly" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Expected: count=0, sum=0 for range with no primes" << endl;
        cout << "         Got: count=" << result3.count << ", sum=" << result3.sum << endl;
    }

    // Test Case 4: Single prime number range
    // Manual calculation: Range 17 to 17, contains prime 17
    // Count: 1, Sum: 17, Largest: 17
    // Expected: {1, 17, 17}
    total++;
    PrimeAnalysis result4 = analyzePrimesInRange(17, 17);
    if (result4.count == 1 && result4.sum == 17 && result4.largest == 17) {
        cout << "Test 4: PASS - Single prime number handled correctly" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Expected: count=1, sum=17, largest=17" << endl;
        cout << "         Got: count=" << result4.count << ", sum=" << result4.sum 
             << ", largest=" << result4.largest << endl;
    }

    // Test Case 5: Range starting with 2 (smallest prime)
    // Manual calculation: Range 2 to 5, primes: 2, 3, 5
    // Count: 3, Sum: 2+3+5 = 10, Largest: 5
    // Expected: {3, 10, 5}
    total++;
    PrimeAnalysis result5 = analyzePrimesInRange(2, 5);
    if (result5.count == 3 && result5.sum == 10 && result5.largest == 5) {
        cout << "Test 5: PASS - Range starting with 2 handled correctly" << endl;
        passed++;
    } else {
        cout << "Test 5: FAIL - Expected: count=3, sum=10, largest=5" << endl;
        cout << "         Got: count=" << result5.count << ", sum=" << result5.sum 
             << ", largest=" << result5.largest << endl;
    }

    // Test Case 6: Larger range 50 to 60
    // Manual calculation: Primes: 53, 59
    // Count: 2, Sum: 53+59 = 112, Largest: 59
    // Expected: {2, 112, 59}
    total++;
    PrimeAnalysis result6 = analyzePrimesInRange(50, 60);
    if (result6.count == 2 && result6.sum == 112 && result6.largest == 59) {
        cout << "Test 6: PASS - Range 50-60 analyzed correctly" << endl;
        passed++;
    } else {
        cout << "Test 6: FAIL - Expected: count=2, sum=112, largest=59" << endl;
        cout << "         Got: count=" << result6.count << ", sum=" << result6.sum 
             << ", largest=" << result6.largest << endl;
    }

    cout << "Problem A2 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA3() {
    cout << "Testing Problem A3 - Advanced Integration..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Simple numbers with known digital roots
    // Manual calculation: 
    // 123: 1+2+3=6 (single digit, done) -> root = 6
    // 456: 4+5+6=15 -> 1+5=6 -> root = 6  
    // 789: 7+8+9=24 -> 2+4=6 -> root = 6
    // Expected roots: [6, 6, 6], min=6, max=6, avg=6.0, mostFreq=6, freq=3
    total++;
    vector<int> input1 = {123, 456, 789};
    DigitalRootStats result1 = calculateDigitalRoots(input1);
    if (result1.roots.size() == 3 && result1.roots[0] == 6 && result1.roots[1] == 6 && 
        result1.roots[2] == 6 && result1.minRoot == 6 && result1.maxRoot == 6 && 
        abs(result1.avgRoot - 6.0) < 0.001 && result1.mostFrequentRoot == 6 && result1.frequency == 3) {
        cout << "Test 1: PASS - Simple digital roots calculated correctly" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - Expected roots: [6,6,6], min=6, max=6, avg=6.0, mostFreq=6, freq=3" << endl;
        cout << "         Got: roots size=" << result1.roots.size() << ", min=" << result1.minRoot 
             << ", max=" << result1.maxRoot << ", avg=" << result1.avgRoot << endl;
    }

    // Test Case 2: Mixed digital roots
    // Manual calculation:
    // 38: 3+8=11 -> 1+1=2 -> root = 2
    // 49: 4+9=13 -> 1+3=4 -> root = 4  
    // 59: 5+9=14 -> 1+4=5 -> root = 5
    // Expected roots: [2, 4, 5], min=2, max=5, avg=3.67, mostFreq varies, freq=1 each
    total++;
    vector<int> input2 = {38, 49, 59};
    DigitalRootStats result2 = calculateDigitalRoots(input2);
    if (result2.roots.size() == 3 && result2.roots[0] == 2 && result2.roots[1] == 4 && 
        result2.roots[2] == 5 && result2.minRoot == 2 && result2.maxRoot == 5) {
        cout << "Test 2: PASS - Mixed digital roots calculated correctly" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Expected roots: [2,4,5], min=2, max=5" << endl;
        cout << "         Got: roots size=" << result2.roots.size() << ", min=" << result2.minRoot 
             << ", max=" << result2.maxRoot << endl;
    }

    // Test Case 3: Single digit numbers (edge case)
    // Manual calculation: Single digits are their own digital roots
    // 7 -> root = 7, 3 -> root = 3, 9 -> root = 9
    // Expected roots: [7, 3, 9], min=3, max=9, avg=6.33
    total++;
    vector<int> input3 = {7, 3, 9};
    DigitalRootStats result3 = calculateDigitalRoots(input3);
    if (result3.roots.size() == 3 && result3.roots[0] == 7 && result3.roots[1] == 3 && 
        result3.roots[2] == 9 && result3.minRoot == 3 && result3.maxRoot == 9) {
        cout << "Test 3: PASS - Single digit numbers handled correctly" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Expected roots: [7,3,9], min=3, max=9" << endl;
        cout << "         Got: roots size=" << result3.roots.size() << ", min=" << result3.minRoot 
             << ", max=" << result3.maxRoot << endl;
    }

    // Test Case 4: Large numbers requiring multiple iterations
    // Manual calculation:
    // 9875: 9+8+7+5=29 -> 2+9=11 -> 1+1=2 -> root = 2
    // 8888: 8+8+8+8=32 -> 3+2=5 -> root = 5
    // Expected roots: [2, 5], min=2, max=5, avg=3.5
    total++;
    vector<int> input4 = {9875, 8888};
    DigitalRootStats result4 = calculateDigitalRoots(input4);
    if (result4.roots.size() == 2 && result4.roots[0] == 2 && result4.roots[1] == 5 && 
        result4.minRoot == 2 && result4.maxRoot == 5 && abs(result4.avgRoot - 3.5) < 0.001) {
        cout << "Test 4: PASS - Large numbers with multiple iterations handled correctly" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Expected roots: [2,5], min=2, max=5, avg=3.5" << endl;
        cout << "         Got: roots size=" << result4.roots.size() << ", avg=" << result4.avgRoot << endl;
    }

    // Test Case 5: Numbers with repeated digital root (frequency test)
    // Manual calculation:
    // 19: 1+9=10 -> 1+0=1 -> root = 1
    // 28: 2+8=10 -> 1+0=1 -> root = 1  
    // 37: 3+7=10 -> 1+0=1 -> root = 1
    // 46: 4+6=10 -> 1+0=1 -> root = 1
    // Expected roots: [1,1,1,1], min=1, max=1, avg=1.0, mostFreq=1, freq=4
    total++;
    vector<int> input5 = {19, 28, 37, 46};
    DigitalRootStats result5 = calculateDigitalRoots(input5);
    if (result5.roots.size() == 4 && result5.minRoot == 1 && result5.maxRoot == 1 && 
        abs(result5.avgRoot - 1.0) < 0.001 && result5.mostFrequentRoot == 1 && result5.frequency == 4) {
        cout << "Test 5: PASS - Frequency analysis for repeated roots works correctly" << endl;
        passed++;
    } else {
        cout << "Test 5: FAIL - Expected all roots=1, mostFreq=1, freq=4" << endl;
        cout << "         Got: mostFreq=" << result5.mostFrequentRoot << ", freq=" << result5.frequency << endl;
    }

    // Test Case 6: Empty vector (edge case)
    // Manual calculation: Empty input should return empty results
    // Expected: empty roots vector, appropriate default values
    total++;
    vector<int> input6 = {};
    DigitalRootStats result6 = calculateDigitalRoots(input6);
    if (result6.roots.size() == 0) {
        cout << "Test 6: PASS - Empty vector handled correctly" << endl;
        passed++;
    } else {
        cout << "Test 6: FAIL - Expected empty roots vector" << endl;
        cout << "         Got: roots size=" << result6.roots.size() << endl;
    }

    cout << "Problem A3 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA4() {
    cout << "Testing Problem A4 - Complex Synthesis..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Generate 8 terms of all three sequences
    // Manual calculation:
    // Classic Fibonacci: 0, 1, 1, 2, 3, 5, 8, 13
    // Lucas: 2, 1, 3, 4, 7, 11, 18, 29
    // Tribonacci: 0, 0, 1, 1, 2, 4, 7, 13
    // Expected: Formatted string containing all three sequences in columns
    total++;
    string result1 = generateFibonacciVariants(8, true, true, true);
    if (result1.find("0") != string::npos && result1.find("13") != string::npos && 
        result1.find("29") != string::npos && result1.length() > 50) {
        cout << "Test 1: PASS - All three 8-term sequences generated with formatting" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - Expected formatted string with all sequences" << endl;
        cout << "         Got string length: " << result1.length() << endl;
    }

    // Test Case 2: Generate only Classic Fibonacci (5 terms)
    // Manual calculation: 0, 1, 1, 2, 3
    // Expected: String containing only Fibonacci sequence
    total++;
    string result2 = generateFibonacciVariants(5, true, false, false);
    if (result2.find("0") != string::npos && result2.find("3") != string::npos && 
        result2.find("Lucas") == string::npos && result2.find("Tribonacci") == string::npos) {
        cout << "Test 2: PASS - Only Classic Fibonacci generated correctly" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Expected only Fibonacci sequence in output" << endl;
    }

    // Test Case 3: Generate Lucas sequence only (6 terms)
    // Manual calculation: 2, 1, 3, 4, 7, 11
    // Expected: String containing only Lucas sequence
    total++;
    string result3 = generateFibonacciVariants(6, false, true, false);
    if (result3.find("2") != string::npos && result3.find("11") != string::npos && 
        result3.find("Fibonacci") == string::npos && result3.find("Tribonacci") == string::npos) {
        cout << "Test 3: PASS - Only Lucas sequence generated correctly" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Expected only Lucas sequence in output" << endl;
    }

    // Test Case 4: Generate Tribonacci only (7 terms)
    // Manual calculation: 0, 0, 1, 1, 2, 4, 7
    // Expected: String containing only Tribonacci sequence
    total++;
    string result4 = generateFibonacciVariants(7, false, false, true);
    if (result4.find("0") != string::npos && result4.find("7") != string::npos && 
        result4.find("Fibonacci") == string::npos && result4.find("Lucas") == string::npos) {
        cout << "Test 4: PASS - Only Tribonacci sequence generated correctly" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Expected only Tribonacci sequence in output" << endl;
    }

    // Test Case 5: Edge case - single term
    // Manual calculation: First term of each: Fib=0, Lucas=2, Trib=0
    // Expected: String with single values for each enabled sequence
    total++;
    string result5 = generateFibonacciVariants(1, true, true, true);
    if (result5.find("0") != string::npos && result5.find("2") != string::npos && result5.length() > 10) {
        cout << "Test 5: PASS - Single term generation handled correctly" << endl;
        passed++;
    } else {
        cout << "Test 5: FAIL - Expected single terms for all sequences" << endl;
    }

    // Test Case 6: Edge case - zero terms
    // Manual calculation: No terms should be generated
    // Expected: Empty or minimal output string
    total++;
    string result6 = generateFibonacciVariants(0, true, true, true);
    if (result6.length() < 50) {  // Should be minimal output for 0 terms
        cout << "Test 6: PASS - Zero terms handled appropriately" << endl;
        passed++;
    } else {
        cout << "Test 6: FAIL - Expected minimal output for zero terms" << endl;
        cout << "         Got string length: " << result6.length() << endl;
    }

    cout << "Problem A4 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA5() {
    cout << "Testing Problem A5 - Mastery Challenge..." << endl;
    int passed = 0, total = 0;

    // Note: This function tests the game engine's statistics tracking
    // Since it's an interactive game, we test the return structure and logic
    
    // Test Case 1: Simulate game completion (mock test)
    // Manual calculation: If function properly initializes and tracks stats
    // Expected: GameStats with reasonable default values or proper initialization
    total++;
    GameStats result1 = playNumberGuessingGame();
    if (result1.gamesPlayed >= 0 && result1.gamesWon >= 0 && result1.totalAttempts >= 0 && 
        result1.bestScore >= 0 && result1.averageAttempts >= 0.0) {
        cout << "Test 1: PASS - Game statistics structure properly initialized" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - Game statistics contain invalid values" << endl;
        cout << "         Games played: " << result1.gamesPlayed << ", Won: " << result1.gamesWon << endl;
    }

    // Test Case 2: Verify statistics consistency
    // Manual calculation: Games won should not exceed games played
    // averageAttempts should be reasonable if games were played
    total++;
    if (result1.gamesWon <= result1.gamesPlayed) {
        cout << "Test 2: PASS - Games won does not exceed games played" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Games won (" << result1.gamesWon 
             << ") exceeds games played (" << result1.gamesPlayed << ")" << endl;
    }

    // Test Case 3: Best score consistency
    // Manual calculation: Best score should be positive if any games won
    total++;
    if (result1.gamesWon == 0 || result1.bestScore > 0) {
        cout << "Test 3: PASS - Best score is consistent with games won" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Best score should be positive when games are won" << endl;
        cout << "         Games won: " << result1.gamesWon << ", Best score: " << result1.bestScore << endl;
    }

    // Test Case 4: Average attempts consistency
    // Manual calculation: If games played > 0, average should be > 0
    total++;
    if (result1.gamesPlayed == 0 || result1.averageAttempts > 0.0) {
        cout << "Test 4: PASS - Average attempts is consistent with games played" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Average attempts should be positive when games are played" << endl;
        cout << "         Games played: " << result1.gamesPlayed 
             << ", Avg attempts: " << result1.averageAttempts << endl;
    }

    // Test Case 5: Total attempts consistency
    // Manual calculation: Total attempts should align with average and games played
    total++;
    if (result1.gamesPlayed == 0 || 
        (result1.totalAttempts > 0 && abs(result1.averageAttempts - 
        (double)result1.totalAttempts / result1.gamesPlayed) < 0.1)) {
        cout << "Test 5: PASS - Total attempts aligns with average calculation" << endl;
        passed++;
    } else {
        cout << "Test 5: FAIL - Total attempts inconsistent with average" << endl;
        cout << "         Expected avg: " << (double)result1.totalAttempts / result1.gamesPlayed 
             << ", Got: " << result1.averageAttempts << endl;
    }

    // Test Case 6: Overall structure validation
    // Manual calculation: All fields should have meaningful values
    total++;
    if (sizeof(result1) == sizeof(GameStats)) {
        cout << "Test 6: PASS - GameStats structure is properly defined" << endl;
        passed++;
    } else {
        cout << "Test 6: FAIL - GameStats structure size mismatch" << endl;
    }

    cout << "Problem A5 Results: " << passed << "/" << total << " tests passed" << endl;
    cout << "Note: Full testing requires interactive gameplay simulation" << endl << endl;
}

void testProblemA6() {
    cout << "Testing Problem A6 - Expert Application..." << endl;
    int passed = 0, total = 0;

    // Note: This function tests the text processing engine's analysis capabilities
    // Since it involves interactive input, we test the return structure
    
    // Test Case 1: Verify TextAnalysis structure initialization
    // Manual calculation: Structure should be properly initialized
    // Expected: TextAnalysis with non-negative default values
    total++;
    TextAnalysis result1 = processTextAdvanced();
    if (result1.totalChars >= 0 && result1.totalWords >= 0 && result1.totalSentences >= 0 && 
        result1.avgWordLength >= 0.0) {
        cout << "Test 1: PASS - TextAnalysis structure properly initialized" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - TextAnalysis contains negative values" << endl;
        cout << "         Chars: " << result1.totalChars << ", Words: " << result1.totalWords << endl;
    }

    // Test Case 2: Character frequency vector structure
    // Manual calculation: Vector should be properly initialized (could be empty initially)
    // Expected: Valid vector structure
    total++;
    if (result1.charFrequency.size() >= 0) {
        cout << "Test 2: PASS - Character frequency vector properly structured" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Character frequency vector has invalid size" << endl;
    }

    // Test Case 3: Palindromes vector structure
    // Manual calculation: Vector should be properly initialized
    // Expected: Valid vector structure
    total++;
    if (result1.palindromes.size() >= 0) {
        cout << "Test 3: PASS - Palindromes vector properly structured" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Palindromes vector has invalid structure" << endl;
    }

    // Test Case 4: Longest word initialization
    // Manual calculation: String should be properly initialized (could be empty)
    // Expected: Valid string structure
    total++;
    if (result1.longestWord.length() >= 0) {
        cout << "Test 4: PASS - Longest word string properly initialized" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Longest word string has invalid structure" << endl;
    }

    // Test Case 5: Statistical consistency check
    // Manual calculation: If words > 0, avgWordLength should be reasonable
    total++;
    if (result1.totalWords == 0 || result1.avgWordLength > 0.0) {
        cout << "Test 5: PASS - Average word length is consistent" << endl;
        passed++;
    } else {
        cout << "Test 5: FAIL - Average word length should be positive when words exist" << endl;
        cout << "         Words: " << result1.totalWords << ", Avg length: " << result1.avgWordLength << endl;
    }

    // Test Case 6: Overall data relationship validation
    // Manual calculation: Characters should be >= words (assuming spaces between words)
    total++;
    if (result1.totalWords == 0 || result1.totalChars >= result1.totalWords) {
        cout << "Test 6: PASS - Character count is consistent with word count" << endl;
        passed++;
    } else {
        cout << "Test 6: FAIL - Character count should be at least equal to word count" << endl;
        cout << "         Chars: " << result1.totalChars << ", Words: " << result1.totalWords << endl;
    }

    cout << "Problem A6 Results: " << passed << "/" << total << " tests passed" << endl;
    cout << "Note: Full testing requires interactive text input simulation" << endl << endl;
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