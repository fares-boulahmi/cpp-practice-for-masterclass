#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstdint>

using namespace std;

//=== SECTION A: INTEGRATION PROBLEMS ===

// Problem A1: Foundation Integration - Smart Calculator with Formatting
// Create a calculator that performs basic arithmetic operations (+, -, *, /, %) with proper
// output formatting. The calculator should handle precedence correctly and format results
// based on operation type. Integer operations show whole numbers, division shows decimals
// with 2 decimal places, and modulo shows remainders with special formatting.
//
// Examples:
// calculateAndFormat(15, 3, '+') → "15 + 3 = 18"
// calculateAndFormat(22, 7, '/') → "22 / 7 = 3.14"  
// calculateAndFormat(17, 5, '%') → "17 % 5 = 2 (remainder)"
//
// Input: Two integers and an operation character (+, -, *, /, %)
// Output: Formatted string with proper decimal places and labels
// Constraints: Handle division by zero, ensure modulo only with positive numbers
string doubleFormat(int a , int b) {
    return "halo";
}
string calculateAndFormat(int a, int b, char op) {
    // TODO: Solve using [Basic Operations, Output Formatting, Precedence]
    // Hint: Use stringstream or cout with setprecision for formatting
    string format{};
    int result;

    if (op == '+')
    {
        result = a + b ;
    }
    else if (op == '-')
    {
        result = a - b ;
    }
    else if (op == '*')
    {
        result = a * b ;
    }

    if (op == '%') {
        format = to_string(a) + " " + op + " " + to_string(b) + " = " + to_string(a % b) + " (remainder)" ;
    } else if (op == '/' ){
        int result_double = ((round(a) / round(b)) - ( a / b ) )* 100 ;
        result = a / b;
        format = to_string(a) + " " + op + " " + to_string(b) + " = " + to_string(result) + "." + to_string(result_double);
    } else if (b == 0) {
        format = "Error: Division by zero";
    } else {
        format = to_string(a) + " " + op + " " + to_string(b) + " = " + to_string(result) ;  
    }
    
    return format ;
}

// Problem A2: Intermediate Synthesis - Advanced Counter System
// Build a counter system that uses compound assignment operators and prefix/postfix
// increment/decrement. The system tracks multiple counters with different step sizes
// and provides detailed statistics. It should handle numeric limits checking and
// use logical operators for validation.
//
// Features needed:
// - Initialize counter with start value and step size
// - Increment/decrement with bounds checking (within int limits)
// - Use compound operators for bulk operations
// - Return statistics: current value, operations count, overflow warnings
//
// Input: Starting value, step size, series of operations
// Output: Final counter state with complete statistics
// Constraints: Must prevent overflow, track all operations, validate inputs
struct CounterStats {
    int current_value;
    int operations_count;
    bool overflow_warning;
    bool underflow_warning;
};

CounterStats advancedCounterSystem(int start_val, int step_size, const vector<string>& operations) {
    // TODO: Solve using [Compound Assignment, Prefix/Postfix, Numeric Limits, Logical Operators]
    // Hint: Check limits before operations, use compound assignment for efficiency
    // first step make the struct
    CounterStats counterStats ;
    counterStats.current_value = start_val;
    counterStats.operations_count = 0 ;

    // if operations empty out direct 
    if (operations.size() == 0)
    {
        counterStats.current_value = start_val;
        counterStats.operations_count = 0;
        return counterStats ;
    } else  {
        // counterStats.operations_count = operations.size() ; 
        // loop for every operations
        for (int i = 0 ; i < operations.size() ; i++) {
            // check if operations just normal == , += , -- one or have int with it like +=10 , /=20
            if (operations[i].size() == 2) {
                if (operations[i] == "++") {
                    if (counterStats.current_value > ( counterStats.current_value +  step_size) )
                    {
                        counterStats.overflow_warning = true;
                        return counterStats;
                    } else {
                        counterStats.current_value += step_size ;
                        counterStats.operations_count++;
                    }
                    
                } else if (operations[i] == "--") {
                    if (counterStats.current_value < ( counterStats.current_value -  step_size) )
                    {
                        counterStats.underflow_warning = true;
                        return counterStats;

                    } else {
                        counterStats.current_value -= step_size ;
                        counterStats.operations_count++;
                    }
                    
                } else if (operations[i] == "*=") {
                    if (counterStats.current_value > (INT_MAX / step_size))
                    {
                        counterStats.overflow_warning = true;
                        return counterStats;
                    } else if (counterStats.current_value < (INT_MIN / step_size)) {

                        counterStats.underflow_warning = true;
                        return counterStats;
                    } else {
                        counterStats.current_value *= step_size ;
                        counterStats.operations_count++;
                    }
                } else if (operations[i] == "/=") {
                    counterStats.current_value /= step_size ;
                    counterStats.operations_count++;
                } else {
                    counterStats.current_value %= step_size ;
                    counterStats.operations_count++;
                }
            } else {
                string opr =  operations[i].substr(0 , 2);
                string remain_number = operations[i].substr(2 , operations[i].size() ) ;
                int int_value = stoi(remain_number) ;
                if (opr == "+=") {
                    if (counterStats.current_value > ( counterStats.current_value +  int_value)  )
                    {
                        counterStats.overflow_warning = true;
                        return counterStats;
                    } else {
                        counterStats.current_value += int_value ;
                        counterStats.operations_count++;
                    }
                } else if (opr == "-=") {
                    if ( counterStats.current_value < ( counterStats.current_value -  int_value)   )
                    {
                        counterStats.underflow_warning = true;
                        return counterStats;
                    } else {
                        counterStats.current_value -= int_value ;
                        counterStats.operations_count++;
                    }
                } else if (opr == "*=")  {
                     if (counterStats.current_value > (INT_MAX / int_value))
                    {
                        counterStats.overflow_warning = true;
                        return counterStats;
                    } else if (counterStats.current_value < (INT_MIN / int_value)) {

                        counterStats.underflow_warning = true;
                        return counterStats;
                    } else {
                        counterStats.current_value *= int_value ;
                        counterStats.operations_count++;
                    }
                } else if (opr == "/=") {
                    counterStats.current_value /= int_value ;
                    counterStats.operations_count++;
                } else  {
                    counterStats.current_value %= int_value ;
                    counterStats.operations_count++;
                }
                
            }
        
        }
    }
    
    return counterStats ;
}

// Problem A3: Advanced Integration - Scientific Expression Evaluator  
// Create a scientific calculator that evaluates complex expressions using math functions,
// proper operator precedence, and handles different data types. Must format output
// based on the magnitude of results and handle edge cases like domain errors.
//
// Supported operations:
// - Basic arithmetic with proper precedence
// - Math functions: sqrt(), pow(), sin(), cos(), log(), abs()
// - Mixed integer/floating-point arithmetic
// - Scientific notation for very large/small numbers
//
// Examples:
// evaluate("2 + 3 * sqrt(16)") → "14.00"
// evaluate("pow(2.5, 3) / 4") → "3.91"  
// evaluate("sin(3.14159/2) + cos(0)") → "2.00"
//
// Input: Mathematical expression as string
// Output: Formatted result with appropriate precision
// Constraints: Handle domain errors, overflow, maintain precision
double scientificExpressionEvaluator(const string& expression) {
    // TODO: Solve using [Math Functions, Precedence, Output Formatting, Data Types, Numeric Limits]
    // Hint: Parse operators by precedence, handle function calls first
    return 1.2 ;
}

// Problem A4: Complex Synthesis - Multi-Type Data Processor
// Design a data processing system that handles various integer types (int8_t, int16_t, 
// int32_t, int64_t), performs operations respecting their limits, and provides detailed
// analysis. Must use all types of operators and handle type promotions correctly.
//
// Process requirements:
// - Accept data in different integer sizes
// - Perform arithmetic operations with overflow detection
// - Apply relational and logical operations for data validation
// - Use bitwise operations for data manipulation
// - Format output showing type information and limits
//
// Input: Vector of mixed integer types with operations
// Output: Processed results with type safety analysis
// Constraints: Prevent overflow, maintain type information, validate all operations
struct DataProcessingResult {
    vector<int64_t> processed_values;
    vector<string> type_info;
    vector<bool> overflow_detected;
    int valid_operations_count;
};

DataProcessingResult multiTypeDataProcessor(const vector<pair<int64_t, string>>& data, 
                                          const vector<string>& operations) {
    // TODO: Solve using [Weird Integral Types, All Operator Types, Numeric Limits, Logical Operators]
    // Hint: Use templates or function overloads for different types
    DataProcessingResult dataProcessingResult;
    return dataProcessingResult;
}

// Problem A5: Mastery Challenge - Advanced Statistics Engine
// Build a comprehensive statistics engine that integrates ALL chapter concepts:
// arithmetic operations, all operator types, formatting, math functions, type handling,
// and numeric limits. Calculate advanced statistics with error handling and detailed reporting.
//
// Required statistics:
// - Basic: mean, median, mode, range
// - Advanced: standard deviation, variance, correlation
// - Data validation using all logical/relational operators
// - Formatted output with appropriate precision
// - Handle edge cases: empty data, overflow, invalid operations
//
// Must demonstrate:
// - All arithmetic and compound operators
// - Prefix/postfix operations in calculations  
// - Math functions for complex calculations
// - Multiple data types and their limits
// - Comprehensive output formatting
//
// Input: Dataset with various numeric types, operation specifications
// Output: Complete statistical report with formatting and error analysis
struct StatisticsReport {
    double mean, median, std_deviation, variance;
    vector<double> mode_values;
    double min_value, max_value, range;
    int data_points_processed;
    vector<string> warnings;
    string formatted_report;
};

StatisticsReport advancedStatisticsEngine(const vector<double>& dataset, 
                                        const string& format_specification) {
    // TODO: Solve using [ALL MAJOR CHAPTER CONCEPTS]
    // - Basic Operations, Precedence, Prefix/Postfix, Compound Assignment
    // - Relational Operators, Logical Operators, Output Formatting
    // - Numeric Limits, Math Functions, Integral Types
    // Hint: Break into smaller functions, validate at each step
    StatisticsReport statisticsReport;
    return statisticsReport;
}

// Problem A6: Expert Application - Game Physics Calculator
// Create a physics calculation system for a 2D game that combines current chapter
// knowledge with previous chapters (variables, data types, vectors, functions).
// Handle projectile motion, collision detection, and real-time calculations.
//
// Physics features:
// - Projectile trajectory calculations using math functions
// - Collision detection using relational/logical operators
// - Force calculations with proper operator precedence
// - Real-time updates using increment/decrement operations
// - Performance optimization using appropriate data types
// - Vector operations from previous chapter knowledge
//
// Game integration requirements:
// - Handle different object types (player, projectiles, obstacles)
// - Time-based calculations with frame rate considerations
// - Boundary checking and collision responses
// - Score calculations with compound assignments
//
// Input: Game objects with physics properties, time delta
// Output: Updated positions, collision results, physics state
struct GameObject {
    double x, y;           // Position
    double vx, vy;         // Velocity
    double mass;           // Mass for physics
    int type;              // Object type identifier
    bool active;           // Active state
};

struct PhysicsResult {
    vector<GameObject> updated_objects;
    vector<pair<int, int>> collisions;  // Indices of colliding objects
    double total_energy;
    int active_objects_count;
    string physics_report;
};

PhysicsResult gamePhysicsCalculator(vector<GameObject>& objects, 
                                  double time_delta, 
                                  double gravity,
                                  const vector<GameObject>& boundaries) {
    // TODO: Solve using [Chapter Concepts + Previous Knowledge]
    // Current: All operators, math functions, formatting, numeric limits
    // Previous: Variables, data types, vectors, functions, loops, conditions
    // Hint: Use physics formulas, check limits for realistic values
    PhysicsResult physicsResult;
    return physicsResult;
}

//=== SECTION B: KNOWLEDGE VALIDATION QUIZ ===

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void knowledgeQuiz() {
    cout << "=== OPERATIONS ON DATA KNOWLEDGE QUIZ ===" << endl;
    cout << "Answer each question by typing A, B, C, or D:" << endl << endl;
    
    char userAnswer;
    int correctAnswers = 0;
    int totalQuestions = 15;

    // Question 1: Operator Precedence
    cout << "Q1: What is the result of the expression: 2 + 3 * 4 - 6 / 2 ?" << endl;
    cout << "A) 11  B) 14  C) 17  D) 20" << endl;
    cout << "Your answer: ";
    cin >> userAnswer;
    userAnswer = toupper(userAnswer);
    cout << "Correct Answer: A) 11" << endl;
    cout << "Explanation: Multiplication and division first: 3*4=12, 6/2=3, then 2+12-3=11" << endl;
    if (userAnswer == 'A') {
        cout << "✓ Correct!" << endl;
        correctAnswers++;
    } else {
        cout << "✗ Incorrect!" << endl;
    }
    cout << endl;

    // Question 2: Prefix vs Postfix
    cout << "Q2: Given int x = 5; What's the value of (++x) + (x++) after execution?" << endl;
    cout << "A) 11  B) 12  C) 13  D) 14" << endl;
    cout << "Your answer: ";
    cin >> userAnswer;
    userAnswer = toupper(userAnswer);
    cout << "Correct Answer: C) 13" << endl;
    cout << "Explanation: x starts as 5. ++x increments to 6 and returns 6. x++ returns 6 then increments x to 7. So 6+7=13" << endl;
    if (userAnswer == 'C') {
        cout << "✓ Correct!" << endl;
        correctAnswers++;
    } else {
        cout << "✗ Incorrect!" << endl;
    }
    cout << endl;

    // Question 3: Compound Assignment
    cout << "Q3: If int a = 15; a *= 2; a /= 3; a += 5; What is the final value of a?" << endl;
    cout << "A) 10  B) 15  C) 20  D) 25" << endl;
    cout << "Your answer: ";
    cin >> userAnswer;
    userAnswer = toupper(userAnswer);
    cout << "Correct Answer: B) 15" << endl;
    cout << "Explanation: a=15, a*=2→a=30, a/=3→a=10, a+=5→a=15" << endl;
    if (userAnswer == 'B') {
        cout << "✓ Correct!" << endl;
        correctAnswers++;
    } else {
        cout << "✗ Incorrect!" << endl;
    }
    cout << endl;

    // Question 4: Logical Operators
    cout << "Q4: What is the result of: (5 > 3) && (2 < 4) || (1 == 1) && false ?" << endl;
    cout << "A) true  B) false  C) compiler error  D) undefined" << endl;
    cout << "Your answer: ";
    cin >> userAnswer;
    userAnswer = toupper(userAnswer);
    cout << "Correct Answer: A) true" << endl;
    cout << "Explanation: (true) && (true) || (true) && false = true || false = true" << endl;
    if (userAnswer == 'A') {
        cout << "✓ Correct!" << endl;
        correctAnswers++;
    } else {
        cout << "✗ Incorrect!" << endl;
    }
    cout << endl;

    // Question 5: Modulo Operation
    cout << "Q5: What happens with the expression (-17) % 5 in C++?" << endl;
    cout << "A) 3  B) -2  C) 2  D) Implementation defined" << endl;
    cout << "Your answer: ";
    cin >> userAnswer;
    userAnswer = toupper(userAnswer);
    cout << "Correct Answer: B) -2" << endl;
    cout << "Explanation: In C++, result of % has same sign as dividend. -17 = 5*(-4) + 1, but sign follows dividend, so -2" << endl;
    if (userAnswer == 'B') {
        cout << "✓ Correct!" << endl;
        correctAnswers++;
    } else {
        cout << "✗ Incorrect!" << endl;
    }
    cout << endl;

    // Question 6: Floating Point Precision
    cout << "Q6: Which header provides FLT_MAX and DBL_EPSILON constants?" << endl;
    cout << "A) <climits>  B) <cfloat>  C) <limits>  D) <numeric>" << endl;
    cout << "Your answer: ";
    cin >> userAnswer;
    userAnswer = toupper(userAnswer);
    cout << "Correct Answer: B) <cfloat>" << endl;
    cout << "Explanation: <cfloat> provides floating-point limits, <climits> for integers" << endl;
    if (userAnswer == 'B') {
        cout << "✓ Correct!" << endl;
        correctAnswers++;
    } else {
        cout << "✗ Incorrect!" << endl;
    }
    cout << endl;

    // Question 7: Math Functions
    cout << "Q7: What's the result of pow(2, 3) + sqrt(16) - abs(-5) ?" << endl;
    cout << "A) 7  B) 8  C) 9  D) 11" << endl;
    cout << "Your answer: ";
    cin >> userAnswer;
    userAnswer = toupper(userAnswer);
    cout << "Correct Answer: A) 7" << endl;
    cout << "Explanation: 8 + 4 - 5 = 7" << endl;
    if (userAnswer == 'A') {
        cout << "✓ Correct!" << endl;
        correctAnswers++;
    } else {
        cout << "✗ Incorrect!" << endl;
    }
    cout << endl;

    // Question 8: Output Formatting
    cout << "Q8: To display 3.14159 with 2 decimal places, which is correct?" << endl;
    cout << "A) cout << setw(2) << 3.14159;" << endl;
    cout << "B) cout << setprecision(2) << 3.14159;" << endl;
    cout << "C) cout << fixed << setprecision(2) << 3.14159;" << endl;
    cout << "D) cout << precision(2) << 3.14159;" << endl;
    cout << "Your answer: ";
    cin >> userAnswer;
    userAnswer = toupper(userAnswer);
    cout << "Correct Answer: C) cout << fixed << setprecision(2) << 3.14159;" << endl;
    cout << "Explanation: Need both fixed and setprecision for decimal places" << endl;
    if (userAnswer == 'C') {
        cout << "✓ Correct!" << endl;
        correctAnswers++;
    } else {
        cout << "✗ Incorrect!" << endl;
    }
    cout << endl;

    // Question 9: Integer Types
    cout << "Q9: Which type is guaranteed to be exactly 16 bits?" << endl;
    cout << "A) short  B) int16_t  C) int  D) long" << endl;
    cout << "Your answer: ";
    cin >> userAnswer;
    userAnswer = toupper(userAnswer);
    cout << "Correct Answer: B) int16_t" << endl;
    cout << "Explanation: Fixed-width integer types guarantee exact bit counts" << endl;
    if (userAnswer == 'B') {
        cout << "✓ Correct!" << endl;
        correctAnswers++;
    } else {
        cout << "✗ Incorrect!" << endl;
    }
    cout << endl;

    // Question 10: Operator Associativity
    cout << "Q10: In the expression a = b = c = 5, which direction is the evaluation?" << endl;
    cout << "A) Left to right  B) Right to left  C) Undefined  D) Compiler dependent" << endl;
    cout << "Your answer: ";
    cin >> userAnswer;
    userAnswer = toupper(userAnswer);
    cout << "Correct Answer: B) Right to left" << endl;
    cout << "Explanation: Assignment operator is right-associative" << endl;
    if (userAnswer == 'B') {
        cout << "✓ Correct!" << endl;
        correctAnswers++;
    } else {
        cout << "✗ Incorrect!" << endl;
    }
    cout << endl;

    // Question 11: Relational Operators
    cout << "Q11: What's the issue with comparing floating-point numbers using == ?" << endl;
    cout << "A) Syntax error  B) Precision issues  C) Performance  D) No issues" << endl;
    cout << "Your answer: ";
    cin >> userAnswer;
    userAnswer = toupper(userAnswer);
    cout << "Correct Answer: B) Precision issues" << endl;
    cout << "Explanation: Floating-point representation can cause tiny differences" << endl;
    if (userAnswer == 'B') {
        cout << "✓ Correct!" << endl;
        correctAnswers++;
    } else {
        cout << "✗ Incorrect!" << endl;
    }
    cout << endl;

    // Question 12: Short-Circuit Evaluation
    cout << "Q12: In (x != 0) && (y/x > 2), when is y/x NOT evaluated?" << endl;
    cout << "A) When x is 0  B) When x is not 0  C) Always evaluated  D) Never evaluated" << endl;
    cout << "Your answer: ";
    cin >> userAnswer;
    userAnswer = toupper(userAnswer);
    cout << "Correct Answer: A) When x is 0" << endl;
    cout << "Explanation: && short-circuits when left side is false" << endl;
    if (userAnswer == 'A') {
        cout << "✓ Correct!" << endl;
        correctAnswers++;
    } else {
        cout << "✗ Incorrect!" << endl;
    }
    cout << endl;

    // Question 13: Numeric Limits
    cout << "Q13: What happens when you increment INT_MAX?" << endl;
    cout << "A) Compiler error  B) Runtime error  C) Undefined behavior  D) Wraps to INT_MIN" << endl;
    cout << "Your answer: ";
    cin >> userAnswer;
    userAnswer = toupper(userAnswer);
    cout << "Correct Answer: C) Undefined behavior" << endl;
    cout << "Explanation: Signed integer overflow is undefined behavior in C++" << endl;
    if (userAnswer == 'C') {
        cout << "✓ Correct!" << endl;
        correctAnswers++;
    } else {
        cout << "✗ Incorrect!" << endl;
    }
    cout << endl;

    // Question 14: Type Conversion
    cout << "Q14: What's the result of 7 / 2 compared to 7.0 / 2 ?" << endl;
    cout << "A) Both give 3.5  B) 3 and 3.5  C) Both give 3  D) 3.5 and 3" << endl;
    cout << "Your answer: ";
    cin >> userAnswer;
    userAnswer = toupper(userAnswer);
    cout << "Correct Answer: B) 3 and 3.5" << endl;
    cout << "Explanation: Integer division vs floating-point division" << endl;
    if (userAnswer == 'B') {
        cout << "✓ Correct!" << endl;
        correctAnswers++;
    } else {
        cout << "✗ Incorrect!" << endl;
    }
    cout << endl;

    // Question 15: Best Practices
    cout << "Q15: Which is the most maintainable way to check if a number is even?" << endl;
    cout << "A) x % 2 == 0  B) (x & 1) == 0  C) x / 2 * 2 == x  D) x == (x / 2) * 2" << endl;
    cout << "Your answer: ";
    cin >> userAnswer;
    userAnswer = toupper(userAnswer);
    cout << "Correct Answer: A) x % 2 == 0" << endl;
    cout << "Explanation: Most readable and clear intent, compiler optimizes anyway" << endl;
    if (userAnswer == 'A') {
        cout << "✓ Correct!" << endl;
        correctAnswers++;
    } else {
        cout << "✗ Incorrect!" << endl;
    }
    cout << endl;

    // Display final score
    cout << "=== QUIZ COMPLETE ===" << endl;
    cout << "Your Score: " << correctAnswers << "/" << totalQuestions << " (" 
         << (correctAnswers * 100 / totalQuestions) << "%)" << endl;
    
    if (correctAnswers == totalQuestions) {
        cout << "Perfect score! Excellent work!" << endl;
    } else if (correctAnswers >= totalQuestions * 0.8) {
        cout << "Great job! You have a solid understanding." << endl;
    } else if (correctAnswers >= totalQuestions * 0.6) {
        cout << "Good effort! Review the concepts you missed." << endl;
    } else {
        cout << "Keep studying! Focus on the areas where you had difficulties." << endl;
    }
    
    cout << "Review any questions you got wrong and revisit those concepts!" << endl;
}

//=== TEST FUNCTIONS ===


void testProblemA1() {
    cout << "Testing Problem A1 - Foundation Integration (Smart Calculator)..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Basic Addition
    // Manual calculation: 15 + 3 = 18
    total++;
    string result1 = calculateAndFormat(15, 3, '+');
    string expected1 = "15 + 3 = 18";
    if (result1 == expected1) {
        cout << "Test 1: PASS" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - Expected: '" << expected1 << "', Got: '" << result1 << "'" << endl;
    }

    // Test Case 2: Division with formatting
    // Manual calculation: 22 / 7 = 3.142857... → 3.14 (2 decimal places)
    total++;
    string result2 = calculateAndFormat(22, 7, '/');
    string expected2 = "22 / 7 = 3.14";
    if (result2 == expected2) {
        cout << "Test 2: PASS" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Expected: '" << expected2 << "', Got: '" << result2 << "'" << endl;
    }

    // Test Case 3: Modulo operation
    // Manual calculation: 17 % 5 = 2
    total++;
    string result3 = calculateAndFormat(17, 5, '%');
    string expected3 = "17 % 5 = 2 (remainder)";
    if (result3 == expected3) {
        cout << "Test 3: PASS" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Expected: '" << expected3 << "', Got: '" << result3 << "'" << endl;
    }

    // Test Case 4: Multiplication
    // Manual calculation: 12 * 8 = 96
    total++;
    string result4 = calculateAndFormat(12, 8, '*');
    string expected4 = "12 * 8 = 96";
    if (result4 == expected4) {
        cout << "Test 4: PASS" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Expected: '" << expected4 << "', Got: '" << result4 << "'" << endl;
    }

    // Test Case 5: Subtraction with negative result
    // Manual calculation: 5 - 12 = -7
    total++;
    string result5 = calculateAndFormat(5, 12, '-');
    string expected5 = "5 - 12 = -7";
    if (result5 == expected5) {
        cout << "Test 5: PASS" << endl;
        passed++;
    } else {
        cout << "Test 5: FAIL - Expected: '" << expected5 << "', Got: '" << result5 << "'" << endl;
    }

    // Test Case 6: Division by zero handling
    total++;
    string result6 = calculateAndFormat(10, 0, '/');
    string expected6 = "Error: Division by zero";
    if (result6 == expected6) {
        cout << "Test 6: PASS" << endl;
        passed++;
    } else {
        cout << "Test 6: FAIL - Expected: '" << expected6 << "', Got: '" << result6 << "'" << endl;
    }

    // Test Case 7: Large numbers
    // Manual calculation: 1000000 + 2000000 = 3000000
    total++;
    string result7 = calculateAndFormat(1000000, 2000000, '+');
    string expected7 = "1000000 + 2000000 = 3000000";
    if (result7 == expected7) {
        cout << "Test 7: PASS" << endl;
        passed++;
    } else {
        cout << "Test 7: FAIL - Expected: '" << expected7 << "', Got: '" << result7 << "'" << endl;
    }

    // Test Case 8: Zero operations
    // Manual calculation: 0 * 999 = 0
    total++;
    string result8 = calculateAndFormat(0, 999, '*');
    string expected8 = "0 * 999 = 0";
    if (result8 == expected8) {
        cout << "Test 8: PASS" << endl;
        passed++;
    } else {
        cout << "Test 8: FAIL - Expected: '" << expected8 << "', Got: '" << result8 << "'" << endl;
    }

    cout << "Problem A1 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA2() {
    cout << "Testing Problem A2 - Intermediate Synthesis (Advanced Counter System)..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Basic increment operations
    // Manual calculation: start=10, step=2, operations=["++", "++", "++"]
    // 10 → 12 → 14 → 16, operations_count=3
    total++;
    vector<string> ops1 = {"++", "++", "++"};
    CounterStats result1 = advancedCounterSystem(10, 2, ops1);
    if (result1.current_value == 16 && result1.operations_count == 3 && 
        !result1.overflow_warning && !result1.underflow_warning) {
        cout << "Test 1: PASS" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - Expected: value=16, ops=3, no warnings" << endl;
        cout << "Got: value=" << result1.current_value << ", ops=" << result1.operations_count 
             << ", overflow=" << result1.overflow_warning << ", underflow=" << result1.underflow_warning << endl;
    }

    // Test Case 2: Mixed operations
    // Manual calculation: start=0, step=5, operations=["+=10", "--", "++"]  
    // 0 → 10 → 5 → 10, operations_count=3
    total++;
    vector<string> ops2 = {"+=10", "--"  , "++"};
    CounterStats result2 = advancedCounterSystem(0, 5, ops2);
    if (result2.current_value == 10 && result2.operations_count == 3) {
        cout << "Test 2: PASS" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Expected: value=10, ops=3" << endl;
        cout << "Got: value=" << result2.current_value << ", ops=" << result2.operations_count << endl;
    }

    // Test Case 3: Overflow detection
    // Manual calculation: start=INT_MAX-1, step=1, operations=["++", "++"]
    // Should detect potential overflow on second increment
    total++;
    vector<string> ops3 = {"++", "++"};
    CounterStats result3 = advancedCounterSystem(INT_MAX-1, 1, ops3);
    if (result3.overflow_warning) {
        cout << "Test 3: PASS" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Expected overflow warning" << endl;
        cout << "Got: overflow=" << result3.overflow_warning << endl;
    }

    // Test Case 4: Underflow detection  
    // Manual calculation: start=INT_MIN+2, step=2, operations=["--", "--"]
    total++;
    vector<string> ops4 = {"--", "--"};
    CounterStats result4 = advancedCounterSystem(INT_MIN+2, 2, ops4);
    if (result4.underflow_warning) {
        cout << "Test 4: PASS" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Expected underflow warning" << endl;
        cout << "Got: underflow=" << result4.underflow_warning << endl;
    }

    // Test Case 5: Compound assignments
    // Manual calculation: start=100, step=3, operations=["*=2", "/=4", "+=50"]
    // 100 → 200 → 50 → 100, operations_count=3
    total++;
    vector<string> ops5 = {"*=2", "/=4", "+=50"};
    CounterStats result5 = advancedCounterSystem(100, 3, ops5);
    if (result5.current_value == 100 && result5.operations_count == 3) {
        cout << "Test 5: PASS" << endl;
        passed++;
    } else {
        cout << "Test 5: FAIL - Expected: value=100, ops=3" << endl;
        cout << "Got: value=" << result5.current_value << ", ops=" << result5.operations_count << endl;
    }

    // Test Case 6: Empty operations vector
    total++;
    vector<string> ops6 = {};
    CounterStats result6 = advancedCounterSystem(42, 1, ops6);
    if (result6.current_value == 42 && result6.operations_count == 0) {
        cout << "Test 6: PASS" << endl;
        passed++;
    } else {
        cout << "Test 6: FAIL - Expected: value=42, ops=0" << endl;
        cout << "Got: value=" << result6.current_value << ", ops=" << result6.operations_count << endl;
    }

    cout << "Problem A2 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA3() {
    cout << "Testing Problem A3 - Advanced Integration (Scientific Expression Evaluator)..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Basic arithmetic with precedence
    // Manual calculation: 2 + 3 * sqrt(16) = 2 + 3 * 4 = 2 + 12 = 14
    total++;
    double result1 = scientificExpressionEvaluator("2 + 3 * sqrt(16)");
    if (abs(result1 - 14.0) < 0.01) {
        cout << "Test 1: PASS" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - Expected: 14.00, Got: " << result1 << endl;
    }

    // Test Case 2: Power function
    // Manual calculation: pow(2.5, 3) / 4 = 15.625 / 4 = 3.90625
    total++;
    double result2 = scientificExpressionEvaluator("pow(2.5, 3) / 4");
    if (abs(result2 - 3.90625) < 0.01) {
        cout << "Test 2: PASS" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Expected: 3.91, Got: " << result2 << endl;
    }

    // Test Case 3: Trigonometric functions
    // Manual calculation: sin(π/2) + cos(0) = 1 + 1 = 2
    total++;
    double result3 = scientificExpressionEvaluator("sin(3.14159/2) + cos(0)");
    if (abs(result3 - 2.0) < 0.01) {
        cout << "Test 3: PASS" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Expected: 2.00, Got: " << result3 << endl;
    }

    // Test Case 4: Complex expression
    // Manual calculation: sqrt(25) - abs(-3) + pow(2, 3) = 5 - 3 + 8 = 10
    total++;
    double result4 = scientificExpressionEvaluator("sqrt(25) - abs(-3) + pow(2, 3)");
    if (abs(result4 - 10.0) < 0.01) {
        cout << "Test 4: PASS" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Expected: 10.00, Got: " << result4 << endl;
    }

    // Test Case 5: Simple arithmetic
    // Manual calculation: 10 + 5 * 2 = 10 + 10 = 20
    total++;
    double result5 = scientificExpressionEvaluator("10 + 5 * 2");
    if (abs(result5 - 20.0) < 0.01) {
        cout << "Test 5: PASS" << endl;
        passed++;
    } else {
        cout << "Test 5: FAIL - Expected: 20.00, Got: " << result5 << endl;
    }

    // Test Case 6: Division and subtraction
    // Manual calculation: 100 / 4 - 5 = 25 - 5 = 20
    total++;
    double result6 = scientificExpressionEvaluator("100 / 4 - 5");
    if (abs(result6 - 20.0) < 0.01) {
        cout << "Test 6: PASS" << endl;
        passed++;
    } else {
        cout << "Test 6: FAIL - Expected: 20.00, Got: " << result6 << endl;
    }

    cout << "Problem A3 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA4() {
    cout << "Testing Problem A4 - Complex Synthesis (Multi-Type Data Processor)..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Basic type handling
    // Input: [(100, "int8_t"), (1000, "int16_t"), (100000, "int32_t")]
    // Operations: ["add_10", "multiply_2", "divide_3"]
    total++;
    vector<pair<int64_t, string>> data1 = {{100, "int8_t"}, {1000, "int16_t"}, {100000, "int32_t"}};
    vector<string> ops1 = {"add_10", "multiply_2", "divide_3"};
    DataProcessingResult result1 = multiTypeDataProcessor(data1, ops1);
    if (result1.processed_values.size() == 3 && result1.valid_operations_count >= 0) {
        cout << "Test 1: PASS" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - Expected 3 processed values" << endl;
        cout << "Got: " << result1.processed_values.size() << " values" << endl;
    }

    // Test Case 2: Overflow detection for int8_t
    // Input: [(127, "int8_t")] with operation "add_1"
    // Manual calculation: 127 + 1 = 128, but int8_t max is 127
    total++;
    vector<pair<int64_t, string>> data2 = {{127, "int8_t"}};
    vector<string> ops2 = {"add_1"};
    DataProcessingResult result2 = multiTypeDataProcessor(data2, ops2);
    if (!result2.overflow_detected.empty() && result2.overflow_detected[0]) {
        cout << "Test 2: PASS" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Expected overflow detection" << endl;
    }

    // Test Case 3: Underflow detection for int8_t
    // Input: [(-128, "int8_t")] with operation "subtract_1"
    // Manual calculation: -128 - 1 = -129, but int8_t min is -128
    total++;
    vector<pair<int64_t, string>> data3 = {{-128, "int8_t"}};
    vector<string> ops3 = {"subtract_1"};
    DataProcessingResult result3 = multiTypeDataProcessor(data3, ops3);
    if (!result3.overflow_detected.empty() && result3.overflow_detected[0]) {
        cout << "Test 3: PASS" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Expected underflow detection" << endl;
    }

    // Test Case 4: Valid operations within bounds
    // Input: [(50, "int8_t")] with operation "add_50"
    // Manual calculation: 50 + 50 = 100, within int8_t range [-128, 127]
    total++;
    vector<pair<int64_t, string>> data4 = {{50, "int8_t"}};
    vector<string> ops4 = {"add_50"};
    DataProcessingResult result4 = multiTypeDataProcessor(data4, ops4);
    if (result4.valid_operations_count >= 1) {
        cout << "Test 4: PASS" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Expected at least 1 valid operation" << endl;
        cout << "Got: " << result4.valid_operations_count << " valid operations" << endl;
    }

    // Test Case 5: Mixed types processing
    total++;
    vector<pair<int64_t, string>> data5 = {{100, "int16_t"}, {50000, "int32_t"}};
    vector<string> ops5 = {"multiply_2", "divide_2"};
    DataProcessingResult result5 = multiTypeDataProcessor(data5, ops5);
    if (result5.processed_values.size() == 2) {
        cout << "Test 5: PASS" << endl;
        passed++;
    } else {
        cout << "Test 5: FAIL - Expected 2 processed values" << endl;
    }

    cout << "Problem A4 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA5() {
    cout << "Testing Problem A5 - Mastery Challenge (Advanced Statistics Engine)..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Basic statistics
    // Dataset: [1, 2, 3, 4, 5]
    // Manual calculations: Mean=(1+2+3+4+5)/5=3.0, Median=3, Range=5-1=4
    // Variance=sum((x-mean)²)/n=((4+1+0+1+4)/5)=2.0, StdDev=sqrt(2.0)≈1.41
    total++;
    vector<double> data1 = {1, 2, 3, 4, 5};
    StatisticsReport result1 = advancedStatisticsEngine(data1, "standard");
    if (abs(result1.mean - 3.0) < 0.01 && abs(result1.std_deviation - 1.41) < 0.1 && 
        abs(result1.range - 4.0) < 0.01) {
        cout << "Test 1: PASS" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - Expected: mean=3.0, std_dev≈1.41, range=4.0" << endl;
        cout << "Got: mean=" << result1.mean << ", std_dev=" << result1.std_deviation 
             << ", range=" << result1.range << endl;
    }

    // Test Case 2: Dataset with duplicates (mode testing)
    // Dataset: [1, 2, 2, 3, 3, 3, 4]
    // Mode: 3 (appears 3 times), Mean: (1+2+2+3+3+3+4)/7 = 18/7 ≈ 2.57
    total++;
    vector<double> data2 = {1, 2, 2, 3, 3, 3, 4};
    StatisticsReport result2 = advancedStatisticsEngine(data2, "standard");
    if (abs(result2.mean - 2.57) < 0.1 && !result2.mode_values.empty() && 
        abs(result2.mode_values[0] - 3.0) < 0.01) {
        cout << "Test 2: PASS" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Expected: mean≈2.57, mode=3" << endl;
        cout << "Got: mean=" << result2.mean << ", mode=" << 
             (result2.mode_values.empty() ? -999 : result2.mode_values[0]) << endl;
    }

    // Test Case 3: Single element
    // Dataset: [42]
    // Mean=42, median=42, variance=0, std_dev=0
    total++;
    vector<double> data3 = {42};
    StatisticsReport result3 = advancedStatisticsEngine(data3, "standard");
    if (abs(result3.mean - 42.0) < 0.01 && abs(result3.median - 42.0) < 0.01 && 
        abs(result3.std_deviation) < 0.01) {
        cout << "Test 3: PASS" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Expected: mean=42, median=42, std_dev=0" << endl;
        cout << "Got: mean=" << result3.mean << ", median=" << result3.median 
             << ", std_dev=" << result3.std_deviation << endl;
    }

    // Test Case 4: Two elements
    // Dataset: [10, 20]
    // Mean=15, median=15, range=10
    total++;
    vector<double> data4 = {10, 20};
    StatisticsReport result4 = advancedStatisticsEngine(data4, "standard");
    if (abs(result4.mean - 15.0) < 0.01 && abs(result4.median - 15.0) < 0.01 && 
        abs(result4.range - 10.0) < 0.01) {
        cout << "Test 4: PASS" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Expected: mean=15, median=15, range=10" << endl;
        cout << "Got: mean=" << result4.mean << ", median=" << result4.median 
             << ", range=" << result4.range << endl;
    }

    // Test Case 5: Negative numbers
    // Dataset: [-5, -3, -1, 2, 4]
    // Mean: (-5-3-1+2+4)/5 = -3/5 = -0.6
    total++;
    vector<double> data5 = {-5, -3, -1, 2, 4};
    StatisticsReport result5 = advancedStatisticsEngine(data5, "standard");
    if (abs(result5.mean - (-0.6)) < 0.01) {
        cout << "Test 5: PASS" << endl;
        passed++;
    } else {
        cout << "Test 5: FAIL - Expected: mean=-0.6" << endl;
        cout << "Got: mean=" << result5.mean << endl;
    }

    // Test Case 6: Empty dataset error handling
    total++;
    vector<double> data6 = {};
    StatisticsReport result6 = advancedStatisticsEngine(data6, "standard");
    if (!result6.warnings.empty()) {
        cout << "Test 6: PASS" << endl;
        passed++;
    } else {
        cout << "Test 6: FAIL - Expected warning for empty dataset" << endl;
    }

    cout << "Problem A5 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA6() {
    cout << "Testing Problem A6 - Expert Application (Game Physics Calculator)..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Basic projectile motion
    // Object at (0,0) with velocity (10, 20), gravity=-9.8, time_delta=0.1
    // New position: x = 0 + 10*0.1 = 1.0
    //              y = 0 + 20*0.1 + 0.5*(-9.8)*(0.1)² = 2.0 - 0.049 = 1.951
    // New velocity: vx = 10, vy = 20 + (-9.8)*0.1 = 19.02
    total++;
    vector<GameObject> objects1 = {{0, 0, 10, 20, 1.0, 1, true}};
    vector<GameObject> boundaries1 = {};
    PhysicsResult result1 = gamePhysicsCalculator(objects1, 0.1, -9.8, boundaries1);
    if (!result1.updated_objects.empty() && 
        abs(result1.updated_objects[0].x - 1.0) < 0.01 && 
        abs(result1.updated_objects[0].y - 1.951) < 0.01) {
        cout << "Test 1: PASS" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - Expected position (1.0, 1.951)" << endl;
        if (!result1.updated_objects.empty()) {
            cout << "Got: (" << result1.updated_objects[0].x << ", " 
                 << result1.updated_objects[0].y << ")" << endl;
        }
    }

    // Test Case 2: Collision detection
    // Two objects moving toward each other
    // Object 1: (0,5) moving right at (5,0)
    // Object 2: (10,5) moving left at (-5,0)
    // After 1 second: Object1 at (5,5), Object2 at (5,5) - collision!
    total++;
    vector<GameObject> objects2 = {{0, 5, 5, 0, 1.0, 1, true}, {10, 5, -5, 0, 1.0, 2, true}};
    vector<GameObject> boundaries2 = {};
    PhysicsResult result2 = gamePhysicsCalculator(objects2, 1.0, 0, boundaries2);
    if (!result2.collisions.empty()) {
        cout << "Test 2: PASS" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Expected collision detection" << endl;
        cout << "Got " << result2.collisions.size() << " collisions" << endl;
    }

    // Test Case 3: Multiple objects with different types
    total++;
    vector<GameObject> objects3 = {{0, 0, 1, 1, 2.0, 1, true}, 
                                   {5, 5, -1, -1, 3.0, 2, true}, 
                                   {10, 10, 0, 0, 1.0, 3, true}};
    vector<GameObject> boundaries3 = {};
    PhysicsResult result3 = gamePhysicsCalculator(objects3, 0.1, -9.8, boundaries3);
    if (result3.updated_objects.size() == 3 && result3.active_objects_count >= 0) {
        cout << "Test 3: PASS" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Expected 3 updated objects" << endl;
        cout << "Got: " << result3.updated_objects.size() << " objects" << endl;
    }

    // Test Case 4: Energy calculations
    // Test that total energy is calculated properly
    total++;
    vector<GameObject> objects4 = {{0, 0, 10, 0, 5.0, 1, true}};  // mass=5, velocity=10
    vector<GameObject> boundaries4 = {};
    PhysicsResult result4 = gamePhysicsCalculator(objects4, 0.1, 0, boundaries4);
    // Expected kinetic energy: 0.5 * 5 * (10² + 0²) = 0.5 * 5 * 100 = 250
    if (abs(result4.total_energy - 250.0) < 1.0) {
        cout << "Test 4: PASS" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Expected energy≈250" << endl;
        cout << "Got: " << result4.total_energy << endl;
    }

    // Test Case 5: Boundary collision
    // Object moving toward boundary should be handled
    total++;
    vector<GameObject> objects5 = {{0, 0, 10, 10, 1.0, 1, true}};
    vector<GameObject> boundaries5 = {{5, 5, 0, 0, 0, 0, true}};  // Boundary at (5,5)
    PhysicsResult result5 = gamePhysicsCalculator(objects5, 1.0, 0, boundaries5);
    if (result5.updated_objects.size() >= 1) {
        cout << "Test 5: PASS" << endl;
        passed++;
    } else {
        cout << "Test 5: FAIL - Expected boundary handling" << endl;
    }

    // Test Case 6: Inactive objects
    // Inactive objects should not be processed
    total++;
    vector<GameObject> objects6 = {{0, 0, 5, 5, 1.0, 1, true}, 
                                   {10, 10, 5, 5, 1.0, 2, false}};  // Second object inactive
    vector<GameObject> boundaries6 = {};
    PhysicsResult result6 = gamePhysicsCalculator(objects6, 0.1, 0, boundaries6);
    if (result6.active_objects_count == 1) {
        cout << "Test 6: PASS" << endl;
        passed++;
    } else {
        cout << "Test 6: FAIL - Expected 1 active object" << endl;
        cout << "Got: " << result6.active_objects_count << " active objects" << endl;
    }

    // Test Case 7: Zero time delta
    // Should handle edge case gracefully
    total++;
    vector<GameObject> objects7 = {{0, 0, 10, 10, 1.0, 1, true}};
    vector<GameObject> boundaries7 = {};
    PhysicsResult result7 = gamePhysicsCalculator(objects7, 0.0, -9.8, boundaries7);
    if (!result7.updated_objects.empty() && 
        abs(result7.updated_objects[0].x - 0.0) < 0.01 && 
        abs(result7.updated_objects[0].y - 0.0) < 0.01) {
        cout << "Test 7: PASS" << endl;
        passed++;
    } else {
        cout << "Test 7: FAIL - Expected no position change with zero time delta" << endl;
    }

    // Test Case 8: Large time delta stability
    // Test numerical stability with larger time steps
    total++;
    vector<GameObject> objects8 = {{0, 0, 1, 1, 1.0, 1, true}};
    vector<GameObject> boundaries8 = {};
    PhysicsResult result8 = gamePhysicsCalculator(objects8, 1.0, -9.8, boundaries8);
    if (!result8.updated_objects.empty() && 
        result8.updated_objects[0].x > 0 && result8.updated_objects[0].y > -10) {
        cout << "Test 8: PASS" << endl;
        passed++;
    } else {
        cout << "Test 8: FAIL - Expected reasonable position after large time step" << endl;
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
    cout << "Implement all solutions and run the actual tests!" << endl;
}

int main() {
    cout << "=== COMPREHENSIVE OPERATIONS ON DATA ASSESSMENT ===" << endl;
    cout << "This assessment tests your mastery of ALL chapter concepts through integration!" << endl << endl;

    cout << "INTEGRATION PROBLEMS (Progressive Difficulty):" << endl;
    cout << "1. Problem A1 - Foundation Integration (Easy)" << endl;
    cout << "   Smart Calculator - Basic ops, precedence, formatting" << endl;
    cout << "2. Problem A2 - Intermediate Synthesis (Easy-Medium)" << endl;
    cout << "   Advanced Counter - Compound ops, increment/decrement, limits" << endl;
    cout << "3. Problem A3 - Advanced Integration (Medium)" << endl;
    cout << "   Scientific Calculator - Math functions, precedence, formatting" << endl;
    cout << "4. Problem A4 - Complex Synthesis (Medium-Hard)" << endl;
    cout << "   Multi-Type Processor - All integer types, all operators, limits" << endl;
    cout << "5. Problem A5 - Mastery Challenge (Hard)" << endl;
    cout << "   Statistics Engine - ALL chapter concepts integrated" << endl;
    cout << "6. Problem A6 - Expert Application (Very Hard)" << endl;
    cout << "   Game Physics - Chapter + previous knowledge integration" << endl;
    cout << "7. Test All Integration Problems" << endl << endl;

    cout << "KNOWLEDGE VALIDATION:" << endl;
    cout << "8. Chapter Knowledge Quiz (15 questions)" << endl;
    cout << "   Covers syntax, best practices, edge cases, performance" << endl << endl;

    cout << "COMPREHENSIVE ASSESSMENT:" << endl;
    cout << "9. Full Chapter Assessment (All problems + Quiz)" << endl << endl;

    cout << "CHAPTER CONCEPTS TESTED:" << endl;
    cout << "✓ Basic Operations (+, -, *, /, %)" << endl;
    cout << "✓ Precedence and Associativity" << endl;
    cout << "✓ Prefix/Postfix Increment & Decrement (++, --)" << endl;
    cout << "✓ Compound Assignment Operators (+=, -=, *=, /=, %=)" << endl;
    cout << "✓ Relational Operators (<, <=, >, >=, ==, !=)" << endl;
    cout << "✓ Logical Operators (&&, ||, !)" << endl;
    cout << "✓ Output Formatting (setprecision, fixed, scientific)" << endl;
    cout << "✓ Numeric Limits (INT_MAX, FLT_MAX, etc.)" << endl;
    cout << "✓ Math Functions (sqrt, pow, sin, cos, abs, etc.)" << endl;
    cout << "✓ Weird Integral Types (int8_t, int16_t, int32_t, int64_t)" << endl << endl;

    int choice;
    cout << "Enter your choice (1-9): ";
    cin >> choice;

    switch(choice) {
        case 1: 
            cout << "\n=== PROBLEM A1: FOUNDATION INTEGRATION ===" << endl;
            cout << "Implement calculateAndFormat() function" << endl;
            testProblemA1(); 
            break;
        case 2: 
            cout << "\n=== PROBLEM A2: INTERMEDIATE SYNTHESIS ===" << endl;
            cout << "Implement advancedCounterSystem() function" << endl;
            testProblemA2(); 
            break;
        case 3: 
            cout << "\n=== PROBLEM A3: ADVANCED INTEGRATION ===" << endl;
            cout << "Implement scientificExpressionEvaluator() function" << endl;
            testProblemA3(); 
            break;
        case 4: 
            cout << "\n=== PROBLEM A4: COMPLEX SYNTHESIS ===" << endl;
            cout << "Implement multiTypeDataProcessor() function" << endl;
            testProblemA4(); 
            break;
        case 5: 
            cout << "\n=== PROBLEM A5: MASTERY CHALLENGE ===" << endl;
            cout << "Implement advancedStatisticsEngine() function" << endl;
            testProblemA5(); 
            break;
        case 6: 
            cout << "\n=== PROBLEM A6: EXPERT APPLICATION ===" << endl;
            cout << "Implement gamePhysicsCalculator() function" << endl;
            testProblemA6(); 
            break;
        case 7: 
            cout << "\n=== ALL INTEGRATION PROBLEMS ===" << endl;
            runAllTests(); 
            break;
        case 8: 
            cout << "\n=== KNOWLEDGE VALIDATION QUIZ ===" << endl;
            knowledgeQuiz(); 
            break;
        case 9:
            cout << "\n=== COMPREHENSIVE ASSESSMENT ===" << endl;
            cout << "Running all problems and quiz..." << endl;
            runAllTests();
            cout << endl;
            knowledgeQuiz();
            break;
        default: 
            cout << "Invalid choice! Please run again and select 1-9." << endl;
    }

    cout << "\n=== ASSESSMENT COMPLETE ===" << endl;
    cout << "If you can solve all problems and ace the quiz," << endl;
    cout << "you have mastered Operations on Data in C++!" << endl;

    return 0;
}