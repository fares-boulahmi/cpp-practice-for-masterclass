#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <limits>
#include <cctype>

using namespace std;

//=== SECTION A: INTEGRATION PROBLEMS ===

// Problem A1: Foundation Integration - Smart Calculator with Input Validation
// Create a calculator that uses if-else statements for operation selection and ternary operators for result formatting.
// The calculator should handle basic operations (+, -, *, /) with proper error checking.
// Examples:
//   Input: 10, 5, '+' → Output: "10 + 5 = 15 (positive)"
//   Input: 8, 4, '/' → Output: "8 / 4 = 2 (positive)"
//   Input: 5, 0, '/' → Output: "Error: Division by zero"
//   Input: 3, 7, '-' → Output: "3 - 7 = -4 (negative)"
// Input Format: Two numbers (double) and an operator (char)
// Output Format: String with formatted result and sign indication
// Constraints: Handle division by zero, invalid operators
// Edge Cases: Zero results, negative numbers, floating point precision
string problemA1Solution(double num1, double num2, char operation) {
    // TODO: Solve using if-else statements, ternary operators, and proper input validation
    // Hint: Use if-else for operation selection, ternary for sign formatting, check for division by zero
    int result {};
    int number1 = round(num1) ;
    int number2 = round(num2) ;
    int rest_divide {};
    string result_range{};
    if (operation == '+')
    {
       result = number1 + number2 ;
    }
    else if (operation == '-')
    {
         result = number1 - number2 ;
    }
    else if (operation == '*')
    {
        result = number1 * number2 ;
    }
    else if (operation == '/')
    {
        if (number2 == 0)
        {
            return "Error: Division by zero";
        }
        
        result = num1 / num2 ;
        if (number1 % number2 != 0 ) {
            rest_divide = ((num1 / num2 ) - result ) * 100000 ;
        }
    }
    else if (operation == '%')
    {
        return "Error: Invalid operator";
    }

    result_range = result > 0 ? "(positive)" : result == 0 ? "(zero)" :  "(negative)" ;
    string result_change = rest_divide ? to_string(result) + "." + to_string(rest_divide) :  to_string(result);

    string end_format =  to_string(number1) + " " + operation + " " + to_string(number2) + " = " + result_change+ " " + result_range;
    return end_format;
}

// Problem A2: Intermediate Synthesis - Grade Calculator with Multiple Decision Points
// Build a comprehensive grade calculator that uses if-else chains, switch statements, and ternary operators.
// Calculate final grade from multiple components, assign letter grades, and determine pass/fail status.
// Examples:
//   Input: midterm=85, final=92, assignments=88, participation=95 → Output: "Final: 90.0, Grade: A-, Status: Pass"
//   Input: midterm=45, final=55, assignments=60, participation=70 → Output: "Final: 57.5, Grade: F, Status: Fail"
// Weights: Midterm 30%, Final 40%, Assignments 20%, Participation 10%
// Grading Scale: A(90-100), B(80-89), C(70-79), D(60-69), F(0-59)
// Pass/Fail: Pass if >= 60, Fail if < 60
// Input Format: Four integer scores (0-100)
// Output Format: String with calculated average, letter grade, and pass/fail status
// Constraints: All scores must be 0-100, handle edge cases for grade boundaries
string problemA2Solution(int midterm, int final, int assignments, int participation) {
    // TODO: Solve using if-else chains for validation, weighted calculation, switch for letter grades, ternary for pass/fail
    // Hint: Validate inputs first, calculate weighted average, use switch for letter grades, ternary for final status
  if (midterm > 100 || final > 100 || assignments > 100 || participation > 100 ) {
    return "Error: Invalid input scores";
  } 
    
    int  result = ((midterm * 30 ) + (final * 40 ) + (assignments * 20 ) + (participation * 10 )) ;
    int result_under = result / 100;
    int result_above = (result - (result_under * 100 )) / 10 ;
    string grade{};
    switch (result_under / 10)
    {
    case 10:
    case 9:
        grade = "A";
        break;
    case 8:
        grade = (result_under >= 89) ? "B+" : "B";
        break;
    case 7:
        grade = "C";
        break;
    case 6:
        grade = "D";
        break;
    default:
    grade = "F" ;
        break;
    }
    string pass = (result_under >= 60) ? "Pass" : "Fail";
    string final_output = "Final: " + to_string(result_under) + "." + to_string(result_above) + ", Grade: " + grade + ", Status: " + pass;
    
    return final_output;
}

// Problem A3: Advanced Integration - Smart Traffic Light Controller
// Design a traffic light system that uses nested if-else, switch statements, and ternary operators.
// Handle emergency vehicles, pedestrian crossing, time-based scheduling, and sensor-based decisions.
// Examples:
//   Input: time=8, emergency=false, pedestrian=true, traffic=3 → Output: "Yellow-3s then Red-30s (Peak + Pedestrian)"
//   Input: time=2, emergency=true, pedestrian=false, traffic=1 → Output: "Green-Immediate (Emergency Override)"
// Traffic levels: 1=Light, 2=Moderate, 3=Heavy
// Time schedule: Peak(7-9, 17-19), Normal(9-17), Night(19-7)
// Priority: Emergency > Pedestrian > Time-based > Traffic-based
// Input Format: hour (0-23), emergency flag, pedestrian flag, traffic level (1-3)
// Output Format: String describing light color, duration, and reason
string problemA3Solution(int hour, bool emergency, bool pedestrian, int trafficLevel) {
    // TODO: Solve using nested if-else for priority logic, switch for time periods, ternary for duration calculation
    // Hint: Handle emergency first, then pedestrian, then time-based rules, finally traffic-based adjustments
    return "yaho";
}

// Problem A4: Complex Synthesis - Multi-Level Security System
// Create a security access system with multiple authentication factors and complex decision trees.
// Integrate user roles, time restrictions, location validation, and attempt tracking.
// Examples:
//   Input: role=2, hour=14, location=1, attempts=0, emergency=false → Output: "Access Granted - Standard (Office Hours)"
//   Input: role=1, hour=22, location=2, attempts=2, emergency=false → Output: "Access Denied - Time Restricted (2 attempts remaining)"
// Roles: 0=Guest, 1=Employee, 2=Manager, 3=Admin
// Locations: 0=Public, 1=Office, 2=Secure, 3=Executive
// Time restrictions vary by role and location
// Max attempts: 3 (lockout after 3 failed attempts)
// Emergency override available for Admin role
// Input Format: role (0-3), hour (0-23), location (0-3), attempt count (0-3), emergency flag
// Output Format: String with access decision, reason, and remaining attempts if applicable
string problemA4Solution(int role, int hour, int location, int attempts, bool emergency) {
    // TODO: Solve using complex nested if-else, switch for role-based rules, ternary for attempt tracking
    // Hint: Check lockout first, then emergency override, then role-location-time matrix, track attempts
     return "yaho";
}

// Problem A5: Mastery Challenge - Adaptive Game Difficulty Controller
// Build an intelligent game difficulty system that adjusts based on player performance, preferences, and game state.
// Integrate performance tracking, difficulty scaling, special conditions, and player feedback.
// Examples:
//   Input: score=85, time=120, deaths=2, level=5, preference=1, special=true → Output: "Difficulty: Hard (Performance+), Bonuses: Time+Score, Next: Expert"
//   Input: score=45, time=180, deaths=8, level=3, preference=0, special=false → Output: "Difficulty: Easy (Struggling), Hints: Enabled, Next: Easy"
// Performance factors: Score (0-100), Time efficiency, Death count, Level progress
// Difficulty levels: 0=Tutorial, 1=Easy, 2=Normal, 3=Hard, 4=Expert, 5=Master
// Player preferences: 0=Casual, 1=Balanced, 2=Challenge
// Special conditions: Boss fights, time trials, achievement attempts
// Input Format: score (0-100), time taken (seconds), deaths (0-10), current level (1-10), preference (0-2), special flag
// Output Format: String with difficulty decision, reasoning, bonuses/hints, and next level prediction
string problemA5Solution(int score, int timeSeconds, int deaths, int currentLevel, int preference, bool specialCondition) {
    // TODO: Solve using ALL flow control concepts: nested if-else, switch, ternary, complex condition evaluation
    // Hint: Calculate performance metrics first, apply preference modifiers, handle special conditions, predict next difficulty
     return "yaho";
}

// Problem A6: Expert Application - Advanced Compiler Optimization Analyzer
// Create a system that analyzes C++ code patterns and suggests optimizations using complex flow control logic.
// Integrate syntax analysis, performance prediction, memory usage estimation, and optimization recommendations.
// Examples:
//   Input: loops=3, branches=8, recursion=1, memory=2048, complexity=2 → Output: "Optimization: Loop Unroll + Branch Predict, Performance: +25%, Memory: Acceptable, Priority: High"
//   Input: loops=0, branches=15, recursion=0, memory=512, complexity=1 → Output: "Optimization: Branch Table, Performance: +15%, Memory: Optimal, Priority: Medium"
// Code metrics: Loop count, Branch count, Recursion depth, Memory usage (KB), Complexity level (1-3)
// Optimization types: Loop optimization, Branch optimization, Memory optimization, Algorithm optimization
// Performance impact: Predicted percentage improvement
// Memory impact: Increased, Same, Reduced
// Priority levels: Low, Medium, High, Critical
// Input Format: loops (0-10), branches (0-20), recursion depth (0-5), memory KB (0-4096), complexity (1-3)
// Output Format: String with optimization strategy, performance prediction, memory impact, and priority level
string problemA6Solution(int loops, int branches, int recursionDepth, int memoryKB, int complexityLevel) {
    // TODO: Solve using advanced flow control integration with previous chapter knowledge (data types, operations)
    // Hint: Use switch for optimization categories, nested if-else for metric analysis, ternary for impact calculation, combine with math operations
     return "yaho";
}

//=== SECTION B: KNOWLEDGE VALIDATION QUIZ ===

void knowledgeQuiz() {
    cout << "=== CHAPTER KNOWLEDGE QUIZ ===" << endl;
    cout << "Answer each question and check your understanding:" << endl << endl;
    
    int score = 0, total = 15;
    char answer;
    
    // Question 1: Core Concept Definition
    cout << "Q1: Which flow control statement is most efficient for testing a single variable against multiple constant values?" << endl;
    cout << "A) if-else chain  B) switch statement  C) nested if  D) ternary operator" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ INCORRECT" << endl;
    }
    cout << "Correct Answer: B - Switch statements use jump tables for O(1) constant-time lookups vs O(n) if-else chains" << endl << endl;

    // Question 2: Syntax and Best Practices
    cout << "Q2: What happens if you omit 'break' statements in a switch case?" << endl;
    cout << "A) Compile error  B) Runtime error  C) Fall-through behavior  D) Undefined behavior" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'C' || answer == 'c') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ INCORRECT" << endl;
    }
    cout << "Correct Answer: C - Fall-through behavior occurs, executing subsequent cases until break is found" << endl << endl;

    // Question 3: Edge Cases
    cout << "Q3: In the ternary operator 'condition ? value1 : value2', when is value2 evaluated?" << endl;
    cout << "A) Always  B) Only when condition is false  C) Only when condition is true  D) Never" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ INCORRECT" << endl;
    }
    cout << "Correct Answer: B - Ternary operator uses short-circuit evaluation; only one branch is evaluated" << endl << endl;

    // Question 4: Performance Considerations
    cout << "Q4: Which is generally faster for simple assignments?" << endl;
    cout << "A) if-else statement  B) ternary operator  C) switch statement  D) They're identical" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ INCORRECT" << endl;
    }
    cout << "Correct Answer: B - Ternary operators often compile to conditional move instructions, avoiding branches" << endl << endl;

    // Question 5: Integration with Previous Chapters
    cout << "Q5: What type should be used for switch statement expressions?" << endl;
    cout << "A) Any type  B) Integral types only  C) Floating-point types  D) String types only" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ INCORRECT" << endl;
    }
    cout << "Correct Answer: B - Switch works with integral types (int, char, enum) and converts to integral values" << endl << endl;

    // Question 6: Common Pitfalls
    cout << "Q6: What's wrong with this code? 'if (x = 5) { ... }'" << endl;
    cout << "A) Syntax error  B) Assignment instead of comparison  C) Missing semicolon  D) Nothing wrong" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ INCORRECT" << endl;
    }
    cout << "Correct Answer: B - Single '=' assigns 5 to x and tests if 5 is true (always true); use '==' for comparison" << endl << endl;

    // Question 7: Logical Operators Integration
    cout << "Q7: In 'if (a && b || c)', what's the evaluation order?" << endl;
    cout << "A) (a && b) || c  B) a && (b || c)  C) Left to right  D) Undefined" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'A' || answer == 'a') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ INCORRECT" << endl;
    }
    cout << "Correct Answer: A - && has higher precedence than ||, so (a && b) || c with short-circuit evaluation" << endl << endl;

    // Question 8: Nested Structures
    cout << "Q8: What's the recommended maximum nesting depth for if-else statements?" << endl;
    cout << "A) No limit  B) 2-3 levels  C) 5 levels  D) 10 levels" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ INCORRECT" << endl;
    }
    cout << "Correct Answer: B - 2-3 levels max for readability; deeper nesting should use functions or early returns" << endl << endl;

    // Question 9: Code Analysis
    cout << "Q9: What does this output? 'int x=3; cout << (x>2 ? x++ : --x);'" << endl;
    cout << "A) 3  B) 4  C) 2  D) Undefined" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'A' || answer == 'a') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ INCORRECT" << endl;
    }
    cout << "Correct Answer: A - Condition (3>2) is true, so x++ is evaluated; post-increment returns 3, then x becomes 4" << endl << endl;

    // Question 10: Debugging Scenarios
    cout << "Q10: Which helps prevent the 'dangling else' problem?" << endl;
    cout << "A) Comments  B) Braces { }  C) Indentation  D) Parentheses" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ INCORRECT" << endl;
    }
    cout << "Correct Answer: B - Always use braces to make if-else associations explicit and prevent ambiguity" << endl << endl;

    // Question 11: Advanced Switch Usage
    cout << "Q11: Can you use variables as case labels in switch statements?" << endl;
    cout << "A) Yes, always  B) No, never  C) Only const variables  D) Only static variables" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'C' || answer == 'c') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ INCORRECT" << endl;
    }
    cout << "Correct Answer: C - Only compile-time constants (const, enum, literals) can be case labels" << endl << endl;

    // Question 12: Performance Analysis
    cout << "Q12: When should you prefer if-else over switch?" << endl;
    cout << "A) Never  B) Few cases with ranges  C) Many cases  D) Always" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ INCORRECT" << endl;
    }
    cout << "Correct Answer: B - if-else is better for range comparisons, few cases, or non-constant conditions" << endl << endl;

    // Question 13: Memory Considerations
    cout << "Q13: What's the scope of variables declared inside if-statement blocks?" << endl;
    cout << "A) Global  B) Function scope  C) Block scope only  D) File scope" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'C' || answer == 'c') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ INCORRECT" << endl;
    }
    cout << "Correct Answer: C - Variables declared in { } blocks have block scope and are destroyed when leaving the block" << endl << endl;

    // Question 14: Error Prevention
    cout << "Q14: What's the safest way to compare floating-point numbers in conditions?" << endl;
    cout << "A) ==  B) !=  C) Epsilon comparison  D) No safe way" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'C' || answer == 'c') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ INCORRECT" << endl;
    }
    cout << "Correct Answer: C - Use abs(a-b) < epsilon due to floating-point precision limitations" << endl << endl;

    // Question 15: Best Practices
    cout << "Q15: Which is the recommended style for if-statement conditions?" << endl;
    cout << "A) if(condition)  B) if (condition)  C) if( condition )  D) Any style" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ INCORRECT" << endl;
    }
    cout << "Correct Answer: B - Space after 'if' keyword, no spaces inside parentheses (most C++ style guides)" << endl << endl;

    cout << "=== QUIZ COMPLETE ===" << endl;
    cout << "Final Score: " << score << "/" << total << " (" << (score*100/total) << "%)" << endl;
    
    if (score >= 13) {
        cout << "🏆 EXCELLENT! You have mastered this chapter!" << endl;
    } else if (score >= 10) {
        cout << "👍 GOOD! You understand most concepts well!" << endl;
    } else if (score >= 7) {
        cout << "📚 FAIR! Review the concepts and try again!" << endl;
    } else {
        cout << "⚠️  NEEDS WORK! Please review the chapter material!" << endl;
    }
}

//=== MANDATORY COMPLETE TEST FUNCTIONS ===

void testProblemA1() {
    cout << "Testing Problem A1 - Smart Calculator with Input Validation..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Basic addition with positive result
    // Manual calculation: 10 + 5 = 15 (positive)
    // Expected: "10 + 5 = 15 (positive)"
    total++;
    string result1 = problemA1Solution(10.0, 5.0, '+');
    string expected1 = "10 + 5 = 15 (positive)";
    if (result1 == expected1) {
        cout << "Test 1: PASS" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - Expected: '" << expected1 << "', Got: '" << result1 << "'" << endl;
    }

    // Test Case 2: Division with integer result
    // Manual calculation: 8 / 4 = 2 (positive)
    // Expected: "8 / 4 = 2 (positive)"
    total++;
    string result2 = problemA1Solution(8.0, 4.0, '/');
    string expected2 = "8 / 4 = 2 (positive)";
    if (result2 == expected2) {
        cout << "Test 2: PASS" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Expected: '" << expected2 << "', Got: '" << result2 << "'" << endl;
    }

    // Test Case 3: Division by zero error
    // Manual calculation: 5 / 0 = undefined (error case)
    // Expected: "Error: Division by zero"
    total++;
    string result3 = problemA1Solution(5.0, 0.0, '/');
    string expected3 = "Error: Division by zero";
    if (result3 == expected3) {
        cout << "Test 3: PASS" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Expected: '" << expected3 << "', Got: '" << result3 << "'" << endl;
    }

    // Test Case 4: Subtraction with negative result
    // Manual calculation: 3 - 7 = -4 (negative)
    // Expected: "3 - 7 = -4 (negative)"
    total++;
    string result4 = problemA1Solution(3.0, 7.0, '-');
    string expected4 = "3 - 7 = -4 (negative)";
    if (result4 == expected4) {
        cout << "Test 4: PASS" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Expected: '" << expected4 << "', Got: '" << result4 << "'" << endl;
    }

    // Test Case 5: Multiplication with zero result
    // Manual calculation: 0 * 25 = 0 (zero)
    // Expected: "0 * 25 = 0 (zero)"
    total++;
    string result5 = problemA1Solution(0.0, 25.0, '*');
    string expected5 = "0 * 25 = 0 (zero)";
    if (result5 == expected5) {
        cout << "Test 5: PASS" << endl;
        passed++;
    } else {
        cout << "Test 5: FAIL - Expected: '" << expected5 << "', Got: '" << result5 << "'" << endl;
    }

    // Test Case 6: Invalid operator
    // Manual calculation: N/A (invalid operator)
    // Expected: "Error: Invalid operator"
    total++;
    string result6 = problemA1Solution(4.0, 2.0, '%');
    string expected6 = "Error: Invalid operator";
    if (result6 == expected6) {
        cout << "Test 6: PASS" << endl;
        passed++;
    } else {
        cout << "Test 6: FAIL - Expected: '" << expected6 << "', Got: '" << result6 << "'" << endl;
    }

    // Test Case 7: Floating point division
    // Manual calculation: 7 / 3 = 2.33333... (positive, floating)
    // Expected: "7 / 3 = 2.33333 (positive)"
    total++;
    string result7 = problemA1Solution(7.0, 3.0, '/');
    string expected7 = "7 / 3 = 2.33333 (positive)";
    if (result7 == expected7) {
        cout << "Test 7: PASS" << endl;
        passed++;
    } else {
        cout << "Test 7: FAIL - Expected: '" << expected7 << "', Got: '" << result7 << "'" << endl;
    }

    // Test Case 8: Large negative result
    // Manual calculation: 5 - 20 = -15 (negative)
    // Expected: "5 - 20 = -15 (negative)"
    total++;
    string result8 = problemA1Solution(5.0, 20.0, '-');
    string expected8 = "5 - 20 = -15 (negative)";
    if (result8 == expected8) {
        cout << "Test 8: PASS" << endl;
        passed++;
    } else {
        cout << "Test 8: FAIL - Expected: '" << expected8 << "', Got: '" << result8 << "'" << endl;
    }

    cout << "Problem A1 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA2() {
    cout << "Testing Problem A2 - Grade Calculator with Multiple Decision Points..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: High performing student - A grade
    // Manual calculation: 
    // Final grade = (85*0.3) + (92*0.4) + (88*0.2) + (95*0.1) = 25.5 + 36.8 + 17.6 + 9.5 = 89.4
    // Grade: B+ (80-89 range), Status: Pass (>=60)
    // Expected: "Final: 89.4, Grade: B+, Status: Pass"
    total++;
    string result1 = problemA2Solution(85, 92, 88, 95);
    string expected1 = "Final: 89.4, Grade: B+, Status: Pass";
    if (result1 == expected1) {
        cout << "Test 1: PASS" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - Expected: '" << expected1 << "', Got: '" << result1 << "'" << endl;
    }

    // Test Case 2: Failing student
    // Manual calculation: 
    // Final grade = (45*0.3) + (55*0.4) + (60*0.2) + (70*0.1) = 13.5 + 22 + 12 + 7 = 54.5
    // Grade: F (0-59 range), Status: Fail (<60)
    // Expected: "Final: 54.5, Grade: F, Status: Fail"
    total++;
    string result2 = problemA2Solution(45, 55, 60, 70);
    string expected2 = "Final: 54.5, Grade: F, Status: Fail";
    if (result2 == expected2) {
        cout << "Test 2: PASS" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Expected: '" << expected2 << "', Got: '" << result2 << "'" << endl;
    }

    // Test Case 3: Perfect A student
    // Manual calculation: 
    // Final grade = (95*0.3) + (98*0.4) + (92*0.2) + (100*0.1) = 28.5 + 39.2 + 18.4 + 10 = 96.1
    // Grade: A (90-100 range), Status: Pass (>=60)
    // Expected: "Final: 96.1, Grade: A, Status: Pass"
    total++;
    string result3 = problemA2Solution(95, 98, 92, 100);
    string expected3 = "Final: 96.1, Grade: A, Status: Pass";
    if (result3 == expected3) {
        cout << "Test 3: PASS" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Expected: '" << expected3 << "', Got: '" << result3 << "'" << endl;
    }

    // Test Case 4: Boundary case - exactly 90 (A grade boundary)
    // Manual calculation: Design inputs to get exactly 90.0
    // Let's use: midterm=90, final=90, assignments=90, participation=90
    // Final grade = (90*0.3) + (90*0.4) + (90*0.2) + (90*0.1) = 27 + 36 + 18 + 9 = 90.0
    // Grade: A (90-100 range), Status: Pass (>=60)
    // Expected: "Final: 90.0, Grade: A, Status: Pass"
    total++;
    string result4 = problemA2Solution(90, 90, 90, 90);
    string expected4 = "Final: 90.0, Grade: A, Status: Pass";
    if (result4 == expected4) {
        cout << "Test 4: PASS" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Expected: '" << expected4 << "', Got: '" << result4 << "'" << endl;
    }

    // Test Case 5: Invalid input - score over 100
    // Manual calculation: Invalid input case
    // Expected: "Error: Invalid input scores"
    total++;
    string result5 = problemA2Solution(105, 90, 85, 95);
    string expected5 = "Error: Invalid input scores";
    if (result5 == expected5) {
        cout << "Test 5: PASS" << endl;
        passed++;
    } else {
        cout << "Test 5: FAIL - Expected: '" << expected5 << "', Got: '" << result5 << "'" << endl;
    }

    // Test Case 6: Boundary case - exactly 60 (pass/fail boundary)
    // Manual calculation: Design inputs to get exactly 60.0
    // Let's use: midterm=60, final=60, assignments=60, participation=60
    // Final grade = (60*0.3) + (60*0.4) + (60*0.2) + (60*0.1) = 18 + 24 + 12 + 6 = 60.0
    // Grade: D (60-69 range), Status: Pass (>=60)
    // Expected: "Final: 60.0, Grade: D, Status: Pass"
    total++;
    string result6 = problemA2Solution(60, 60, 60, 60);
    string expected6 = "Final: 60.0, Grade: D, Status: Pass";
    if (result6 == expected6) {
        cout << "Test 6: PASS" << endl;
        passed++;
    } else {
        cout << "Test 6: FAIL - Expected: '" << expected6 << "', Got: '" << result6 << "'" << endl;
    }

    cout << "Problem A2 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA3() {
    cout << "Testing Problem A3 - Smart Traffic Light Controller..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Peak hour with pedestrian request
    // Manual calculation: hour=8 (peak), emergency=false, pedestrian=true, traffic=3 (heavy)
    // Logic: Peak hours (7-9) + pedestrian request + heavy traffic
    // Expected: Extended pedestrian cycle with yellow warning
    // Expected: "Yellow-3s then Red-30s (Peak + Pedestrian)"
    total++;
    string result1 = problemA3Solution(8, false, true, 3);
    string expected1 = "Yellow-3s then Red-30s (Peak + Pedestrian)";
    if (result1 == expected1) {
        cout << "Test 1: PASS" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - Expected: '" << expected1 << "', Got: '" << result1 << "'" << endl;
    }

    // Test Case 2: Emergency override during night
    // Manual calculation: hour=2 (night), emergency=true, pedestrian=false, traffic=1 (light)
    // Logic: Emergency takes highest priority regardless of other conditions
    // Expected: "Green-Immediate (Emergency Override)"
    total++;
    string result2 = problemA3Solution(2, true, false, 1);
    string expected2 = "Green-Immediate (Emergency Override)";
    if (result2 == expected2) {
        cout << "Test 2: PASS" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Expected: '" << expected2 << "', Got: '" << result2 << "'" << endl;
    }

    // Test Case 3: Normal office hours, light traffic, no special conditions
    // Manual calculation: hour=14 (normal), emergency=false, pedestrian=false, traffic=1 (light)
    // Logic: Normal hours (9-17) with light traffic, standard timing
    // Expected: "Green-45s (Normal Hours - Light Traffic)"
    total++;
    string result3 = problemA3Solution(14, false, false, 1);
    string expected3 = "Green-45s (Normal Hours - Light Traffic)";
    if (result3 == expected3) {
        cout << "Test 3: PASS" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Expected: '" << expected3 << "', Got: '" << result3 << "'" << endl;
    }

    // Test Case 4: Evening peak with heavy traffic
    // Manual calculation: hour=18 (evening peak), emergency=false, pedestrian=false, traffic=3 (heavy)
    // Logic: Peak hours (17-19) with heavy traffic, shortened green cycle
    // Expected: "Green-30s (Peak Hours - Heavy Traffic)"
    total++;
    string result4 = problemA3Solution(18, false, false, 3);
    string expected4 = "Green-30s (Peak Hours - Heavy Traffic)";
    if (result4 == expected4) {
        cout << "Test 4: PASS" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Expected: '" << expected4 << "', Got: '" << result4 << "'" << endl;
    }

    // Test Case 5: Night time with moderate traffic
    // Manual calculation: hour=22 (night), emergency=false, pedestrian=false, traffic=2 (moderate)
    // Logic: Night hours (19-7) with moderate traffic, extended green
    // Expected: "Green-60s (Night Hours - Moderate Traffic)"
    total++;
    string result5 = problemA3Solution(22, false, false, 2);
    string expected5 = "Green-60s (Night Hours - Moderate Traffic)";
    if (result5 == expected5) {
        cout << "Test 5: PASS" << endl;
        passed++;
    } else {
        cout << "Test 5: FAIL - Expected: '" << expected5 << "', Got: '" << result5 << "'" << endl;
    }

    // Test Case 6: Emergency during peak with pedestrian (priority test)
    // Manual calculation: hour=8, emergency=true, pedestrian=true, traffic=3
    // Logic: Emergency overrides all other conditions
    // Expected: "Green-Immediate (Emergency Override)"
    total++;
    string result6 = problemA3Solution(8, true, true, 3);
    string expected6 = "Green-Immediate (Emergency Override)";
    if (result6 == expected6) {
        cout << "Test 6: PASS" << endl;
        passed++;
    } else {
        cout << "Test 6: FAIL - Expected: '" << expected6 << "', Got: '" << result6 << "'" << endl;
    }

    cout << "Problem A3 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA4() {
    cout << "Testing Problem A4 - Multi-Level Security System..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Manager access during office hours
    // Manual calculation: role=2 (manager), hour=14 (office), location=1 (office), attempts=0, emergency=false
    // Logic: Manager role can access office during business hours with no failed attempts
    // Expected: "Access Granted - Standard (Office Hours)"
    total++;
    string result1 = problemA4Solution(2, 14, 1, 0, false);
    string expected1 = "Access Granted - Standard (Office Hours)";
    if (result1 == expected1) {
        cout << "Test 1: PASS" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - Expected: '" << expected1 << "', Got: '" << result1 << "'" << endl;
    }

    // Test Case 2: Employee time restriction violation
    // Manual calculation: role=1 (employee), hour=22 (night), location=2 (secure), attempts=2, emergency=false
    // Logic: Employee cannot access secure areas at night, 2 failed attempts (1 remaining)
    // Expected: "Access Denied - Time Restricted (1 attempts remaining)"
    total++;
    string result2 = problemA4Solution(1, 22, 2, 2, false);
    string expected2 = "Access Denied - Time Restricted (1 attempts remaining)";
    if (result2 == expected2) {
        cout << "Test 2: PASS" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Expected: '" << expected2 << "', Got: '" << result2 << "'" << endl;
    }

    // Test Case 3: Account lockout
    // Manual calculation: role=1 (employee), hour=10 (office), location=1 (office), attempts=3, emergency=false
    // Logic: 3 failed attempts = locked out regardless of other factors
    // Expected: "Access Denied - Account Locked"
    total++;
    string result3 = problemA4Solution(1, 10, 1, 3, false);
    string expected3 = "Access Denied - Account Locked";
    if (result3 == expected3) {
        cout << "Test 3: PASS" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Expected: '" << expected3 << "', Got: '" << result3 << "'" << endl;
    }

    // Test Case 4: Admin emergency override
    // Manual calculation: role=3 (admin), hour=3 (night), location=3 (executive), attempts=1, emergency=true
    // Logic: Admin with emergency override can access any location any time
    // Expected: "Access Granted - Emergency Override (Admin)"
    total++;
    string result4 = problemA4Solution(3, 3, 3, 1, true);
    string expected4 = "Access Granted - Emergency Override (Admin)";
    if (result4 == expected4) {
        cout << "Test 4: PASS" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Expected: '" << expected4 << "', Got: '" << result4 << "'" << endl;
    }

    // Test Case 5: Guest access to public area
    // Manual calculation: role=0 (guest), hour=12 (office), location=0 (public), attempts=0, emergency=false
    // Logic: Guest can access public areas during office hours
    // Expected: "Access Granted - Public Area (Guest)"
    total++;
    string result5 = problemA4Solution(0, 12, 0, 0, false);
    string expected5 = "Access Granted - Public Area (Guest)";
    if (result5 == expected5) {
        cout << "Test 5: PASS" << endl;
        passed++;
    } else {
        cout << "Test 5: FAIL - Expected: '" << expected5 << "', Got: '" << result5 << "'" << endl;
    }

    // Test Case 6: Manager accessing executive area (insufficient privileges)
    // Manual calculation: role=2 (manager), hour=14 (office), location=3 (executive), attempts=0, emergency=false
    // Logic: Manager doesn't have executive access even during office hours
    // Expected: "Access Denied - Insufficient Privileges (3 attempts remaining)"
    total++;
    string result6 = problemA4Solution(2, 14, 3, 0, false);
    string expected6 = "Access Denied - Insufficient Privileges (3 attempts remaining)";
    if (result6 == expected6) {
        cout << "Test 6: PASS" << endl;
        passed++;
    } else {
        cout << "Test 6: FAIL - Expected: '" << expected6 << "', Got: '" << result6 << "'" << endl;
    }

    cout << "Problem A4 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA5() {
    cout << "Testing Problem A5 - Adaptive Game Difficulty Controller..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: High performance with challenge preference
    // Manual calculation: score=85 (high), time=120 (good), deaths=2 (low), level=5, preference=1 (balanced), special=true
    // Performance score: (85 + time_bonus + death_penalty) = high performance
    // With balanced preference and special condition (boss fight)
    // Expected: "Difficulty: Hard (Performance+), Bonuses: Time+Score, Next: Expert"
    total++;
    string result1 = problemA5Solution(85, 120, 2, 5, 1, true);
    string expected1 = "Difficulty: Hard (Performance+), Bonuses: Time+Score, Next: Expert";
    if (result1 == expected1) {
        cout << "Test 1: PASS" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - Expected: '" << expected1 << "', Got: '" << result1 << "'" << endl;
    }

    // Test Case 2: Poor performance with casual preference
    // Manual calculation: score=45 (low), time=180 (slow), deaths=8 (high), level=3, preference=0 (casual), special=false
    // Performance score: low due to poor score, slow time, many deaths
    // Casual preference should lower difficulty further
    // Expected: "Difficulty: Easy (Struggling), Hints: Enabled, Next: Easy"
    total++;
    string result2 = problemA5Solution(45, 180, 8, 3, 0, false);
    string expected2 = "Difficulty: Easy (Struggling), Hints: Enabled, Next: Easy";
    if (result2 == expected2) {
        cout << "Test 2: PASS" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Expected: '" << expected2 << "', Got: '" << result2 << "'" << endl;
    }

    // Test Case 3: Perfect performance with challenge seeker
    // Manual calculation: score=95 (excellent), time=90 (very fast), deaths=0 (perfect), level=8, preference=2 (challenge), special=false
    // Performance score: maximum due to excellent metrics
    // Challenge preference should increase difficulty
    // Expected: "Difficulty: Master (Perfect+), Bonuses: Flawless+Speed, Next: Master"
    total++;
    string result3 = problemA5Solution(95, 90, 0, 8, 2, false);
    string expected3 = "Difficulty: Master (Perfect+), Bonuses: Flawless+Speed, Next: Master";
    if (result3 == expected3) {
        cout << "Test 3: PASS" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Expected: '" << expected3 << "', Got: '" << result3 << "'" << endl;
    }

    // Test Case 4: Average performance in tutorial level
    // Manual calculation: score=70 (average), time=150 (average), deaths=3 (moderate), level=1, preference=1 (balanced), special=false
    // Performance score: average across all metrics
    // Tutorial level should have gentler scaling
    // Expected: "Difficulty: Normal (Learning), Hints: Contextual, Next: Normal"
    total++;
    string result4 = problemA5Solution(70, 150, 3, 1, 1, false);
    string expected4 = "Difficulty: Normal (Learning), Hints: Contextual, Next: Normal";
    if (result4 == expected4) {
        cout << "Test 4: PASS" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Expected: '" << expected4 << "', Got: '" << result4 << "'" << endl;
    }

    // Test Case 5: Special condition with mixed performance
    // Manual calculation: score=65 (decent), time=200 (slow), deaths=5 (many), level=6, preference=1 (balanced), special=true
    // Performance: decent score but slow time and many deaths = struggling
    // Special condition (boss fight) but struggling performance = assistance needed
    // Expected: "Difficulty: Normal (Boss-Assisted), Hints: Boss Tactics, Next: Normal"
    total++;
    string result5 = problemA5Solution(65, 200, 5, 6, 1, true);
    string expected5 = "Difficulty: Normal (Boss-Assisted), Hints: Boss Tactics, Next: Normal";
    if (result5 == expected5) {
        cout << "Test 5: PASS" << endl;
        passed++;
    } else {
        cout << "Test 5: FAIL - Expected: '" << expected5 << "', Got: '" << result5 << "'" << endl;
    }

    // Test Case 6: Maximum deaths with challenge preference (edge case)
    // Manual calculation: score=80 (good), time=100 (fast), deaths=10 (maximum), level=7, preference=2 (challenge), special=false
    // Performance: good score and time but maximum deaths = inconsistent performance
    // Challenge preference with inconsistent performance = adaptive difficulty
    // Expected: "Difficulty: Hard (Inconsistent), Bonuses: None, Next: Normal"
    total++;
    string result6 = problemA5Solution(80, 100, 10, 7, 2, false);
    string expected6 = "Difficulty: Hard (Inconsistent), Bonuses: None, Next: Normal";
    if (result6 == expected6) {
        cout << "Test 6: PASS" << endl;
        passed++;
    } else {
        cout << "Test 6: FAIL - Expected: '" << expected6 << "', Got: '" << result6 << "'" << endl;
    }

    cout << "Problem A5 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA6() {
    cout << "Testing Problem A6 - Advanced Compiler Optimization Analyzer..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Loop-heavy code with moderate complexity
    // Manual calculation: loops=3, branches=8, recursion=1, memory=2048, complexity=2
    // Analysis: Multiple loops suggest loop optimization, moderate branches, some recursion
    // Memory usage is acceptable (2MB), complexity is moderate
    // Expected: "Optimization: Loop Unroll + Branch Predict, Performance: +25%, Memory: Acceptable, Priority: High"
    total++;
    string result1 = problemA6Solution(3, 8, 1, 2048, 2);
    string expected1 = "Optimization: Loop Unroll + Branch Predict, Performance: +25%, Memory: Acceptable, Priority: High";
    if (result1 == expected1) {
        cout << "Test 1: PASS" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - Expected: '" << expected1 << "', Got: '" << result1 << "'" << endl;
    }

    // Test Case 2: Branch-heavy code with low memory
    // Manual calculation: loops=0, branches=15, recursion=0, memory=512, complexity=1
    // Analysis: No loops, many branches suggest branch table optimization
    // Low memory usage (512KB) is optimal, low complexity
    // Expected: "Optimization: Branch Table, Performance: +15%, Memory: Optimal, Priority: Medium"
    total++;
    string result2 = problemA6Solution(0, 15, 0, 512, 1);
    string expected2 = "Optimization: Branch Table, Performance: +15%, Memory: Optimal, Priority: Medium";
    if (result2 == expected2) {
        cout << "Test 2: PASS" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Expected: '" << expected2 << "', Got: '" << result2 << "'" << endl;
    }

    // Test Case 3: Recursion-heavy with high memory usage
    // Manual calculation: loops=1, branches=5, recursion=4, memory=3500, complexity=3
    // Analysis: Deep recursion suggests tail recursion optimization or iterative conversion
    // High memory usage (3.5MB) suggests memory optimization needed
    // High complexity = critical priority
    // Expected: "Optimization: Tail Recursion + Memory Pool, Performance: +40%, Memory: Reduced, Priority: Critical"
    total++;
    string result3 = problemA6Solution(1, 5, 4, 3500, 3);
    string expected3 = "Optimization: Tail Recursion + Memory Pool, Performance: +40%, Memory: Reduced, Priority: Critical";
    if (result3 == expected3) {
        cout << "Test 3: PASS" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Expected: '" << expected3 << "', Got: '" << result3 << "'" << endl;
    }

    // Test Case 4: Balanced code with minimal optimization needs
    // Manual calculation: loops=1, branches=3, recursion=0, memory=256, complexity=1
    // Analysis: Minimal loops and branches, no recursion, very low memory
    // Low complexity suggests basic optimizations only
    // Expected: "Optimization: Basic Inline, Performance: +5%, Memory: Optimal, Priority: Low"
    total++;
    string result4 = problemA6Solution(1, 3, 0, 256, 1);
    string expected4 = "Optimization: Basic Inline, Performance: +5%, Memory: Optimal, Priority: Low";
    if (result4 == expected4) {
        cout << "Test 4: PASS" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Expected: '" << expected4 << "', Got: '" << result4 << "'" << endl;
    }

    // Test Case 5: Maximum complexity scenario
    // Manual calculation: loops=8, branches=18, recursion=3, memory=4000, complexity=3
    // Analysis: High loops, high branches, recursion, near memory limit, max complexity
    // All optimization types needed, critical priority
    // Expected: "Optimization: Full Suite (Loop+Branch+Memory+Algorithm), Performance: +60%, Memory: Reduced, Priority: Critical"
    total++;
    string result5 = problemA6Solution(8, 18, 3, 4000, 3);
    string expected5 = "Optimization: Full Suite (Loop+Branch+Memory+Algorithm), Performance: +60%, Memory: Reduced, Priority: Critical";
    if (result5 == expected5) {
        cout << "Test 5: PASS" << endl;
        passed++;
    } else {
        cout << "Test 5: FAIL - Expected: '" << expected5 << "', Got: '" << result5 << "'" << endl;
    }

    // Test Case 6: Edge case - no optimization needed
    // Manual calculation: loops=0, branches=1, recursion=0, memory=128, complexity=1
    // Analysis: Minimal branching, no loops or recursion, very low memory
    // Simple code with minimal optimization potential
    // Expected: "Optimization: None Needed, Performance: +0%, Memory: Optimal, Priority: Low"
    total++;
    string result6 = problemA6Solution(0, 1, 0, 128, 1);
    string expected6 = "Optimization: None Needed, Performance: +0%, Memory: Optimal, Priority: Low";
    if (result6 == expected6) {
        cout << "Test 6: PASS" << endl;
        passed++;
    } else {
        cout << "Test 6: FAIL - Expected: '" << expected6 << "', Got: '" << result6 << "'" << endl;
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
    cout << "=== COMPREHENSIVE CHAPTER ASSESSMENT ===" << endl;
    cout << "Choose your assessment mode:" << endl << endl;

    cout << "INTEGRATION PROBLEMS:" << endl;
    cout << "1. Problem A1 - Foundation Integration (Easy)" << endl;
    cout << "2. Problem A2 - Intermediate Synthesis (Easy-Medium)" << endl;
    cout << "3. Problem A3 - Advanced Integration (Medium)" << endl;
    cout << "4. Problem A4 - Complex Synthesis (Medium-Hard)" << endl;
    cout << "5. Problem A5 - Mastery Challenge (Hard)" << endl;
    cout << "6. Problem A6 - Expert Application (Very Hard)" << endl;
    cout << "7. Test All Integration Problems" << endl << endl;

    cout << "KNOWLEDGE VALIDATION:" << endl;
    cout << "8. Chapter Knowledge Quiz (15 questions)" << endl << endl;

    cout << "COMPREHENSIVE ASSESSMENT:" << endl;
    cout << "9. Full Chapter Assessment (All problems + Quiz)" << endl << endl;

    int choice;
    cout << "Enter your choice (1-9): ";
    cin >> choice;

    switch(choice) {
        case 1: testProblemA1(); break;
        case 2: testProblemA2(); break;
        case 3: testProblemA3(); break;
        case 4: testProblemA4(); break;
        case 5: testProblemA5(); break;
        case 6: testProblemA6(); break;
        case 7: runAllTests(); break;
        case 8: knowledgeQuiz(); break;
        case 9:
            runAllTests();
            cout << endl;
            knowledgeQuiz();
            break;
        default: cout << "Invalid choice!" << endl;
    }

    return 0;
}