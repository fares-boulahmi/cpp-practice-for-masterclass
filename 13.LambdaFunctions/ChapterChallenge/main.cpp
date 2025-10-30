#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>
#include <map>
#include <cmath>

using namespace std;

//=== SECTION A: INTEGRATION PROBLEMS ===

// Problem A1: Foundation Integration - Lambda Calculator with Capture
// Create a function that takes two numbers and returns a lambda that performs
// different operations based on captured values.
// 
// Example 1: createOperation(10, 5, '+') returns a lambda that when called
//            with no arguments returns 15
// Example 2: createOperation(20, 4, '*') returns a lambda that returns 80
// Example 3: createOperation(100, 25, '-') returns a lambda that returns 75
//
// Input: Two integers (a, b) and a char operation (+, -, *, /)
// Output: A lambda function that captures these values and returns the result
// Constraints: Handle division by zero by returning 0
// Edge cases: Negative numbers, zero operands, invalid operators
function<int()> problemA1Solution(int a, int b, char op) {
    // TODO: Solve using lambda functions and capture by value
    // Hint: Capture the operands and operator, then perform calculation in lambda body
    // function<int()>
     auto result = [a , b , op]()-> int {
        if (op == '*')
    {
        return a * b;
    } else if (op == '-')
    {
        return a - b;
    } else if (op == '+')
    {
        return a + b;
    } else 
    {
        if (b == 0) return 0;
        return a / b;
    } 
     };
    return result;
}

// Problem A2: Intermediate Synthesis - Lambda Comparator Factory
// Create a function that generates custom comparison lambdas for sorting strings.
// The function should support multiple comparison modes: length, alphabetical,
// reverse alphabetical, and custom (ignore case).
//
// Example 1: mode = "length", data = {"cat", "elephant", "dog"}
//            Returns lambda that sorts by length: {"cat", "dog", "elephant"}
// Example 2: mode = "alpha", data = {"zebra", "apple", "mango"}
//            Returns lambda for alphabetical: {"apple", "mango", "zebra"}
// Example 3: mode = "ignore_case", data = {"Apple", "banana", "Cherry"}
//            Returns lambda that ignores case: {"Apple", "banana", "Cherry"}
//
// Input: string mode (comparison type), vector<string> to sort
// Output: A lambda that can be used with std::sort
// Constraints: Handle empty strings and vectors
// Edge cases: Same length strings, identical strings, single character strings
function<bool(const string&, const string&)> problemA2Solution(const string& mode) {
    // TODO: Solve using lambda functions with different comparison logic
    // Hint: Use capture by value for mode, implement different comparisons in lambda
    function<bool(const string&, const string&)> result;
    return result;
}

// Problem A3: Advanced Integration - Lambda Pipeline Processor
// Create a data processing pipeline using lambdas. Given a vector of integers,
// apply a series of transformations using lambdas: filter, map, and reduce.
//
// Example 1: Input = {1, 2, 3, 4, 5}, filter(even), map(*2), reduce(sum)
//            Step 1: Filter evens -> {2, 4}
//            Step 2: Map *2 -> {4, 8}
//            Step 3: Reduce sum -> 12
//
// Example 2: Input = {10, 15, 20, 25, 30}, filter(>15), map(/5), reduce(product)
//            Step 1: Filter >15 -> {20, 25, 30}
//            Step 2: Map /5 -> {4, 5, 6}
//            Step 3: Reduce product -> 120
//
// Input: vector<int>, filter lambda, map lambda, reduce lambda
// Output: Final reduced value
// Constraints: Handle empty vectors, division by zero
// Edge cases: All elements filtered out, single element, negative numbers
int problemA3Solution(const vector<int>& data,
                      function<bool(int)> filterFunc,
                      function<int(int)> mapFunc,
                      function<int(int, int)> reduceFunc,
                      int initialValue) {
    // TODO: Solve using lambda functions and STL algorithms
    // Hint: Chain operations - filter first, then transform, finally accumulate
    // auto even_numbers
    vector<int> even_numbers{};
    for (size_t i = 0; i < data.size(); i++)
    {
        if (filterFunc(data[i])) {
            even_numbers.push_back(data[i]);
        }
    }
    
    if (even_numbers.size() != 0)
    {
        even_numbers[0] = mapFunc(even_numbers[0]);
        initialValue = even_numbers[0];
        for (size_t i = 1; i < even_numbers.size(); i++)
        {
            even_numbers[i] = mapFunc(even_numbers[i]);
            initialValue = reduceFunc(initialValue , even_numbers[i]);
        }
        return initialValue;
    }
    
    return initialValue;
}

// Problem A4: Complex Synthesis - Lambda-Based Event Handler System
// Create an event handler system where lambdas with different captures handle events.
// Events have a type and value. Handlers are lambdas that capture state and modify it.
//
// Example 1: Initialize counter=0, add handler that increments counter by event value
//            Process events: {10, 20, 30} -> Final counter: 60
//
// Example 2: Initialize state with multiplier=2 and sum=0
//            Handler 1: adds value to sum
//            Handler 2: adds (value * multiplier) to sum
//            Process event value 5 -> sum becomes 5 + 10 = 15
//
// Input: Initial state, vector of handler lambdas, vector of event values
// Output: Map of state variable names to their final values
// Constraints: Handlers must capture by reference to modify shared state
// Edge cases: No handlers, no events, negative values, multiple handlers
map<string, int> problemA4Solution(map<string, int> initialState,
                                   vector<function<void(int)>> handlers,
                                   vector<int> events) {
    // TODO: Solve using lambda functions with capture by reference
    // Hint: Lambdas should capture state variables by reference to modify them
    map<string, int>  result;
    return result;
}

// Problem A5: Mastery Challenge - Generic Lambda Template System
// Create a flexible computation system using generic lambdas and all capture modes.
// The system should handle different data types and perform complex operations
// combining filtering, transformation, and aggregation with stateful lambdas.
//
// Example 1: Process vector<double> {1.5, 2.7, 3.2, 4.8, 5.1}
//            Filter: values > 3.0
//            Transform: square each value
//            Aggregate: sum with running count
//            Result: {sum: 66.25, count: 3, average: 22.083}
//
// Example 2: Process vector<int> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
//            Filter: odd numbers
//            Transform: cube each value
//            Aggregate: product of all with max tracking
//            Result: {product: 1890000000, count: 5, max: 729}
//
// Input: Data vector, filter criteria, transform operation, aggregation type
// Output: Structure with computed results
// Constraints: Handle type conversions, overflow, empty results
// Edge cases: All filtered, single element, type boundaries
struct ComputeResult {
    double primaryValue;
    int count;
    double secondaryValue;
};

ComputeResult problemA5Solution(const vector<double>& data,
                                double filterThreshold,
                                const string& transformType,
                                const string& aggregateType) {
    // TODO: Solve using generic lambdas, all capture modes, and complex operations
    // Hint: Use [=], [&], [this], and specific captures; chain multiple lambdas
    ComputeResult result;
    return result;
}

// Problem A6: Expert Application - Lambda-Based Expression Evaluator with Closures
// Build an expression evaluator that uses lambdas to create closures for variable
// binding and operation chaining. Support nested scopes and multiple operations.
//
// Example 1: Bind x=10, y=5
//            Expression: (x + y) * 2 - x
//            Evaluation: (10 + 5) * 2 - 10 = 20
//            Create lambda closure that captures bindings
//
// Example 2: Outer scope: x=100, Inner scope: x=10, y=20
//            Expression in inner: x + y (should use inner x=10)
//            Expression in outer: x + y (should use outer x=100, no y->error handle)
//
// Example 3: Chain operations with intermediate captures
//            Step 1: result1 = x * 2 (x=5) -> 10
//            Step 2: result2 = result1 + y (y=3) -> 13
//            Step 3: result3 = result2 - result1 -> 3
//
// Input: Variable bindings, expression string representation (simplified)
// Output: Evaluated result using lambda closures
// Constraints: Handle undefined variables, nested scopes, operation precedence
// Edge cases: Empty expressions, undefined vars, division by zero, scope shadowing
class ExpressionEvaluator {
private:
    map<string, int> variables;
public:
    ExpressionEvaluator() = default;
    
    void bindVariable(const string& name, int value) {
        variables[name] = value;
    }
    
    // TODO: Implement using lambdas with closures
    // Create lambda that captures variable bindings and evaluates expression
    function<int()> createExpression(const string& var1, const string& var2, 
                                    char operation) {
        // TODO: Return lambda that captures variables map and evaluates expression
        // Hint: Capture by reference to access current variable values
         function<int()>  result;
         return result;
    }
    
    int evaluate(const string& var1, const string& var2, char operation) {
        // TODO: Use the lambda created above to evaluate
        // Hint: Create and immediately invoke the lambda
        return 0;
    }
};

int problemA6Solution(const vector<pair<string, int>>& bindings,
                     const vector<tuple<string, string, char>>& operations) {
    // TODO: Solve using lambda closures, capture lists, and scope management
    // Hint: Create nested lambdas for scopes, use captures for variable binding
    return 0;
}

//=== SECTION B: KNOWLEDGE VALIDATION QUIZ ===

void knowledgeQuiz() {
    cout << "=== CHAPTER 14 KNOWLEDGE QUIZ ===" << endl;
    cout << "Answer each question and check your understanding:" << endl << endl;
    
    int score = 0;
    char answer;
    
    // Question 1: Lambda Syntax
    cout << "Q1: What is the correct syntax for a lambda that takes an int and returns its square?" << endl;
    cout << "A) [](int x) { return x * x; }" << endl;
    cout << "B) lambda(int x) -> int { return x * x; }" << endl;
    cout << "C) [](x) => x * x" << endl;
    cout << "D) auto(int x) { return x * x; }" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'A' || answer == 'a') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ WRONG!" << endl;
    }
    cout << "Correct Answer: A" << endl;
    cout << "Explanation: Lambda syntax is [capture](parameters) { body }. Option A correctly" << endl;
    cout << "shows the square brackets for capture list, parameters in parentheses, and body in braces." << endl << endl;
    
    // Question 2: Capture by Value
    cout << "Q2: Given: int x = 10; auto f = [x]() { return x + 5; }; x = 20;" << endl;
    cout << "    What does f() return?" << endl;
    cout << "A) 15" << endl;
    cout << "B) 25" << endl;
    cout << "C) 20" << endl;
    cout << "D) Compilation error" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'A' || answer == 'a') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ WRONG!" << endl;
    }
    cout << "Correct Answer: A" << endl;
    cout << "Explanation: [x] captures x by value (copies it). The lambda captures x=10." << endl;
    cout << "Changing x to 20 afterwards doesn't affect the captured copy, so f() returns 10+5=15." << endl << endl;
    
    // Question 3: Capture by Reference
    cout << "Q3: Given: int count = 0; auto inc = [&count]() { count++; };" << endl;
    cout << "    After calling inc() three times, what is count?" << endl;
    cout << "A) 0" << endl;
    cout << "B) 1" << endl;
    cout << "C) 3" << endl;
    cout << "D) Undefined behavior" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'C' || answer == 'c') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ WRONG!" << endl;
    }
    cout << "Correct Answer: C" << endl;
    cout << "Explanation: [&count] captures count by reference. Each call to inc() modifies" << endl;
    cout << "the original count variable. After three calls: count becomes 3." << endl << endl;
    
    // Question 4: Capture All by Value
    cout << "Q4: What does the capture list [=] mean?" << endl;
    cout << "A) Capture nothing" << endl;
    cout << "B) Capture all variables in scope by value" << endl;
    cout << "C) Capture all variables in scope by reference" << endl;
    cout << "D) Invalid syntax" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ WRONG!" << endl;
    }
    cout << "Correct Answer: B" << endl;
    cout << "Explanation: [=] is the capture-all-by-value syntax. It captures all variables" << endl;
    cout << "used in the lambda body from the enclosing scope by making copies of them." << endl << endl;
    
    // Question 5: Capture All by Reference
    cout << "Q5: What does the capture list [&] mean?" << endl;
    cout << "A) Capture all by value" << endl;
    cout << "B) Capture all by reference" << endl;
    cout << "C) Capture first parameter by reference" << endl;
    cout << "D) Invalid syntax" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ WRONG!" << endl;
    }
    cout << "Correct Answer: B" << endl;
    cout << "Explanation: [&] captures all variables used in the lambda by reference." << endl;
    cout << "This allows the lambda to modify the original variables in the outer scope." << endl << endl;
    
    // Question 6: Mixed Capture
    cout << "Q6: Given: int a = 1, b = 2; auto f = [a, &b]() { b = a + b; };" << endl;
    cout << "    After f(), what are a and b?" << endl;
    cout << "A) a=1, b=2" << endl;
    cout << "B) a=1, b=3" << endl;
    cout << "C) a=3, b=3" << endl;
    cout << "D) a=3, b=2" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ WRONG!" << endl;
    }
    cout << "Correct Answer: B" << endl;
    cout << "Explanation: [a, &b] captures a by value (copy) and b by reference." << endl;
    cout << "The lambda uses captured a (value 1) and modifies b: b = 1 + 2 = 3." << endl;
    cout << "Original a remains unchanged at 1." << endl << endl;
    
    // Question 7: Return Type Deduction
    cout << "Q7: When does a lambda need an explicit return type?" << endl;
    cout << "A) Always" << endl;
    cout << "B) Never" << endl;
    cout << "C) When there are multiple return statements with different types" << endl;
    cout << "D) When capturing by reference" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'C' || answer == 'c') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ WRONG!" << endl;
    }
    cout << "Correct Answer: C" << endl;
    cout << "Explanation: Return types are usually deduced. However, if there are multiple" << endl;
    cout << "return statements that could return different types, you must specify the return" << endl;
    cout << "type explicitly using -> ReturnType syntax after parameters." << endl << endl;
    
    // Question 8: Lambda with STL
    cout << "Q8: Which STL algorithm commonly uses lambdas for custom behavior?" << endl;
    cout << "A) std::swap" << endl;
    cout << "B) std::sort" << endl;
    cout << "C) std::size" << endl;
    cout << "D) std::begin" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ WRONG!" << endl;
    }
    cout << "Correct Answer: B" << endl;
    cout << "Explanation: std::sort (and many other algorithms) accepts a comparison function." << endl;
    cout << "Lambdas are perfect for providing custom comparison logic inline without defining" << endl;
    cout << "a separate function. Example: sort(v.begin(), v.end(), [](int a, int b) { return a > b; });" << endl << endl;
    
    // Question 9: Mutable Lambdas
    cout << "Q9: What does the 'mutable' keyword do in a lambda?" << endl;
    cout << "A) Allows capturing by reference" << endl;
    cout << "B) Allows modifying captured-by-value variables inside the lambda" << endl;
    cout << "C) Makes the lambda return a mutable reference" << endl;
    cout << "D) Prevents the lambda from being called multiple times" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ WRONG!" << endl;
    }
    cout << "Correct Answer: B" << endl;
    cout << "Explanation: By default, captured-by-value variables are const in the lambda body." << endl;
    cout << "The 'mutable' keyword allows you to modify these copies inside the lambda." << endl;
    cout << "Syntax: [x]() mutable { x++; }. Note: only the copy is modified, not the original." << endl << endl;
    
    // Question 10: Empty Capture List
    cout << "Q10: What does an empty capture list [] mean?" << endl;
    cout << "A) Capture all variables" << endl;
    cout << "B) Capture no variables from outer scope" << endl;
    cout << "C) Invalid syntax" << endl;
    cout << "D) Capture only global variables" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ WRONG!" << endl;
    }
    cout << "Correct Answer: B" << endl;
    cout << "Explanation: An empty capture list [] means the lambda doesn't capture any" << endl;
    cout << "variables from the enclosing scope. It can only use its parameters and global variables." << endl << endl;
    
    // Question 11: Function Template
    cout << "Q11: What type should you use to store a lambda for later use?" << endl;
    cout << "A) auto" << endl;
    cout << "B) std::function" << endl;
    cout << "C) lambda_t" << endl;
    cout << "D) Both A and B" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'D' || answer == 'd') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ WRONG!" << endl;
    }
    cout << "Correct Answer: D" << endl;
    cout << "Explanation: 'auto' works for immediate storage in the same scope." << endl;
    cout << "std::function<ReturnType(ParamTypes)> is used when you need to store lambdas" << endl;
    cout << "in containers, pass them as function parameters, or return them from functions." << endl << endl;
    
    // Question 12: Dangling References
    cout << "Q12: What's the danger of capturing local variables by reference?" << endl;
    cout << "A) Performance overhead" << endl;
    cout << "B) Syntax errors" << endl;
    cout << "C) Dangling references if lambda outlives the variable" << endl;
    cout << "D) No danger, always safe" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'C' || answer == 'c') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ WRONG!" << endl;
    }
    cout << "Correct Answer: C" << endl;
    cout << "Explanation: If a lambda captures a variable by reference and that variable" << endl;
    cout << "goes out of scope (is destroyed), the lambda holds a dangling reference." << endl;
    cout << "Using it causes undefined behavior. Be careful when returning lambdas!" << endl << endl;
    
    // Question 13: Lambda vs Function Pointer
    cout << "Q13: Can a lambda with an empty capture list be converted to a function pointer?" << endl;
    cout << "A) Yes, always" << endl;
    cout << "B) No, never" << endl;
    cout << "C) Yes, but only if it has no captures" << endl;
    cout << "D) Only if marked with 'static'" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'C' || answer == 'c') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ WRONG!" << endl;
    }
    cout << "Correct Answer: C" << endl;
    cout << "Explanation: A lambda with NO captures (empty []) can be implicitly converted" << endl;
    cout << "to a function pointer. Lambdas with captures cannot, because they need storage" << endl;
    cout << "for the captured variables (closure). Example: int(*fptr)(int) = [](int x) { return x*2; };" << endl << endl;
    
    // Question 14: Capture This
    cout << "Q14: In a class member function, what does [this] capture?" << endl;
    cout << "A) The current object by value" << endl;
    cout << "B) A pointer to the current object" << endl;
    cout << "C) All member variables by value" << endl;
    cout << "D) Invalid in member functions" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ WRONG!" << endl;
    }
    cout << "Correct Answer: B" << endl;
    cout << "Explanation: [this] captures a pointer to the current object, allowing the" << endl;
    cout << "lambda to access member variables and functions. Be careful: if the object is" << endl;
    cout << "destroyed, the lambda will have a dangling pointer!" << endl << endl;
    
    // Question 15: Best Practice
    cout << "Q15: What's the best practice for capturing variables in lambdas?" << endl;
    cout << "A) Always use [=] for convenience" << endl;
    cout << "B) Always use [&] for efficiency" << endl;
    cout << "C) Be explicit and capture only what's needed" << endl;
    cout << "D) Never capture anything" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'C' || answer == 'c') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ WRONG!" << endl;
    }
    cout << "Correct Answer: C" << endl;
    cout << "Explanation: Best practice is to explicitly list what you capture: [x, &y]." << endl;
    cout << "This makes code clear, prevents accidental captures, and helps avoid dangling" << endl;
    cout << "references. Use [=] or [&] sparingly and only when you truly need all variables." << endl << endl;
    
    cout << "=== QUIZ COMPLETE ===" << endl;
    cout << "Your score: " << score << "/15 (" << (score * 100 / 15) << "%)" << endl;
    if (score >= 13) cout << "Excellent! You have mastered lambda functions!" << endl;
    else if (score >= 10) cout << "Good job! Review the questions you missed." << endl;
    else if (score >= 7) cout << "Fair understanding. More practice needed." << endl;
    else cout << "Keep studying! Review the chapter thoroughly." << endl;
}

//=== MANDATORY COMPLETE TEST FUNCTIONS ===

void testProblemA1() {
    cout << "Testing Problem A1 - Foundation Integration..." << endl;
    int passed = 0, total = 0;
    
    // Test Case 1: Basic addition
    // Manual calculation: 10 + 5 = 15
    // Expected: 15
    total++;
    auto lambda1 = problemA1Solution(10, 5, '+');
    int result1 = lambda1();
    if (result1 == 15) {
        cout << "Test 1 PASS: Addition 10+5" << endl;
        passed++;
    } else {
        cout << "Test 1 FAIL: Expected 15, Got " << result1 << endl;
    }
    
    // Test Case 2: Multiplication
    // Manual calculation: 20 * 4 = 80
    // Expected: 80
    total++;
    auto lambda2 = problemA1Solution(20, 4, '*');
    int result2 = lambda2();
    if (result2 == 80) {
        cout << "Test 2 PASS: Multiplication 20*4" << endl;
        passed++;
    } else {
        cout << "Test 2 FAIL: Expected 80, Got " << result2 << endl;
    }
    
    // Test Case 3: Subtraction
    // Manual calculation: 100 - 25 = 75
    // Expected: 75
    total++;
    auto lambda3 = problemA1Solution(100, 25, '-');
    int result3 = lambda3();
    if (result3 == 75) {
        cout << "Test 3 PASS: Subtraction 100-25" << endl;
        passed++;
    } else {
        cout << "Test 3 FAIL: Expected 75, Got " << result3 << endl;
    }
    
    // Test Case 4: Division
    // Manual calculation: 50 / 10 = 5
    // Expected: 5
    total++;
    auto lambda4 = problemA1Solution(50, 10, '/');
    int result4 = lambda4();
    if (result4 == 5) {
        cout << "Test 4 PASS: Division 50/10" << endl;
        passed++;
    } else {
        cout << "Test 4 FAIL: Expected 5, Got " << result4 << endl;
    }
    
    // Test Case 5: Division by zero
    // Manual calculation: 100 / 0 -> should return 0 (error handling)
    // Expected: 0
    total++;
    auto lambda5 = problemA1Solution(100, 0, '/');
    int result5 = lambda5();
    if (result5 == 0) {
        cout << "Test 5 PASS: Division by zero handled" << endl;
        passed++;
    } else {
        cout << "Test 5 FAIL: Expected 0 for division by zero, Got " << result5 << endl;
    }
    
    // Test Case 6: Negative numbers
    // Manual calculation: -15 + 25 = 10
    // Expected: 10
    total++;
    auto lambda6 = problemA1Solution(-15, 25, '+');
    int result6 = lambda6();
    if (result6 == 10) {
        cout << "Test 6 PASS: Negative operand -15+25" << endl;
        passed++;
    } else {
        cout << "Test 6 FAIL: Expected 10, Got " << result6 << endl;
    }
    
    // Test Case 7: Both negative
    // Manual calculation: -10 * -3 = 30
    // Expected: 30
    total++;
    auto lambda7 = problemA1Solution(-10, -3, '*');
    int result7 = lambda7();
    if (result7 == 30) {
        cout << "Test 7 PASS: Both negative -10*-3" << endl;
        passed++;
    } else {
        cout << "Test 7 FAIL: Expected 30, Got " << result7 << endl;
    }
    
    // Test Case 8: Zero operands
    // Manual calculation: 0 + 0 = 0
    // Expected: 0
    total++;
    auto lambda8 = problemA1Solution(0, 0, '+');
    int result8 = lambda8();
    if (result8 == 0) {
        cout << "Test 8 PASS: Zero operands" << endl;
        passed++;
    } else {
        cout << "Test 8 FAIL: Expected 0, Got " << result8 << endl;
    }
    
    cout << "Problem A1 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA2() {
    cout << "Testing Problem A2 - Intermediate Synthesis..." << endl;
    int passed = 0, total = 0;
    
    // Test Case 1: Sort by length
    // Manual calculation: "cat"(3), "dog"(3), "elephant"(8)
    // Sorted by length: "cat", "dog", "elephant"
    total++;
    vector<string> data1 = {"elephant", "cat", "dog"};
    auto comparator1 = problemA2Solution("length");
    sort(data1.begin(), data1.end(), comparator1);
    if (data1[0] == "cat" && data1[1] == "dog" && data1[2] == "elephant") {
        cout << "Test 1 PASS: Sort by length" << endl;
        passed++;
    } else {
        cout << "Test 1 FAIL: Expected [cat, dog, elephant], Got [" 
             << data1[0] << ", " << data1[1] << ", " << data1[2] << "]" << endl;
    }
    
    // Test Case 2: Alphabetical sort
    // Manual calculation: "apple" < "mango" < "zebra"
    // Expected: "apple", "mango", "zebra"
    total++;
    vector<string> data2 = {"zebra", "apple", "mango"};
    auto comparator2 = problemA2Solution("alpha");
    sort(data2.begin(), data2.end(), comparator2);
    if (data2[0] == "apple" && data2[1] == "mango" && data2[2] == "zebra") {
        cout << "Test 2 PASS: Alphabetical sort" << endl;
        passed++;
    } else {
        cout << "Test 2 FAIL: Expected [apple, mango, zebra], Got [" 
             << data2[0] << ", " << data2[1] << ", " << data2[2] << "]" << endl;
    }
    
    // Test Case 3: Reverse alphabetical
    // Manual calculation: "zebra" > "mango" > "apple"
    // Expected: "zebra", "mango", "apple"
    total++;
    vector<string> data3 = {"apple", "mango", "zebra"};
    auto comparator3 = problemA2Solution("reverse");
    sort(data3.begin(), data3.end(), comparator3);
    if (data3[0] == "zebra" && data3[1] == "mango" && data3[2] == "apple") {
        cout << "Test 3 PASS: Reverse alphabetical sort" << endl;
        passed++;
    } else {
        cout << "Test 3 FAIL: Expected [zebra, mango, apple], Got [" 
             << data3[0] << ", " << data3[1] << ", " << data3[2] << "]" << endl;
    }
    
    // Test Case 4: Ignore case sorting
    // Manual calculation: "Apple" and "apple" are equal, "banana" comes before "Cherry"
    // Expected: "Apple", "banana", "Cherry" (case-insensitive alphabetical)
    total++;
    vector<string> data4 = {"Cherry", "Apple", "banana"};
    auto comparator4 = problemA2Solution("ignore_case");
    sort(data4.begin(), data4.end(), comparator4);
    if (data4[0] == "Apple" && data4[1] == "banana" && data4[2] == "Cherry") {
        cout << "Test 4 PASS: Case-insensitive sort" << endl;
        passed++;
    } else {
        cout << "Test 4 FAIL: Expected [Apple, banana, Cherry], Got [" 
             << data4[0] << ", " << data4[1] << ", " << data4[2] << "]" << endl;
    }
    
    // Test Case 5: Same length strings
    // Manual calculation: "cat"(3), "dog"(3), "bat"(3) - when same length, maintain stability
    // Expected by length: all same, so depends on secondary sorting
    total++;
    vector<string> data5 = {"dog", "cat", "bat"};
    auto comparator5 = problemA2Solution("length");
    sort(data5.begin(), data5.end(), comparator5);
    // All have length 3, so order might vary but lengths should all be 3
    if (data5[0].length() == 3 && data5[1].length() == 3 && data5[2].length() == 3) {
        cout << "Test 5 PASS: Same length strings handled" << endl;
        passed++;
    } else {
        cout << "Test 5 FAIL: Length sorting failed for equal lengths" << endl;
    }
    
    // Test Case 6: Empty string handling
    // Manual calculation: ""(0) < "a"(1) < "hello"(5)
    // Expected: "", "a", "hello"
    total++;
    vector<string> data6 = {"hello", "", "a"};
    auto comparator6 = problemA2Solution("length");
    sort(data6.begin(), data6.end(), comparator6);
    if (data6[0] == "" && data6[1] == "a" && data6[2] == "hello") {
        cout << "Test 6 PASS: Empty string handled" << endl;
        passed++;
    } else {
        cout << "Test 6 FAIL: Expected ['', a, hello], Got [" 
             << data6[0] << ", " << data6[1] << ", " << data6[2] << "]" << endl;
    }
    
    // Test Case 7: Single character strings
    // Manual calculation: 'a' < 'b' < 'z'
    // Expected: "a", "b", "z"
    total++;
    vector<string> data7 = {"z", "a", "b"};
    auto comparator7 = problemA2Solution("alpha");
    sort(data7.begin(), data7.end(), comparator7);
    if (data7[0] == "a" && data7[1] == "b" && data7[2] == "z") {
        cout << "Test 7 PASS: Single character strings" << endl;
        passed++;
    } else {
        cout << "Test 7 FAIL: Expected [a, b, z], Got [" 
             << data7[0] << ", " << data7[1] << ", " << data7[2] << "]" << endl;
    }
    
    // Test Case 8: Identical strings
    // Manual calculation: "same" == "same" == "same"
    // Expected: order maintained (stable sort behavior)
    total++;
    vector<string> data8 = {"same", "same", "same"};
    auto comparator8 = problemA2Solution("alpha");
    sort(data8.begin(), data8.end(), comparator8);
    if (data8[0] == "same" && data8[1] == "same" && data8[2] == "same") {
        cout << "Test 8 PASS: Identical strings handled" << endl;
        passed++;
    } else {
        cout << "Test 8 FAIL: Identical string handling failed" << endl;
    }
    
    cout << "Problem A2 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA3() {
    cout << "Testing Problem A3 - Advanced Integration..." << endl;
    int passed = 0, total = 0;
    
    // Test Case 1: Filter evens, multiply by 2, sum
    // Manual calculation: 
    // Input: {1, 2, 3, 4, 5}
    // Filter evens: {2, 4}
    // Map *2: {4, 8}
    // Reduce sum (initial=0): 0 + 4 + 8 = 12
    // Expected: 12
    total++;
    vector<int> data1 = {1, 2, 3, 4, 5};
    auto filter1 = [](int x) { return x % 2 == 0; };
    auto map1 = [](int x) { return x * 2; };
    auto reduce1 = [](int acc, int x) { return acc + x; };
    int result1 = problemA3Solution(data1, filter1, map1, reduce1, 0);
    if (result1 == 12) {
        cout << "Test 1 PASS: Filter evens, map *2, reduce sum" << endl;
        passed++;
    } else {
        cout << "Test 1 FAIL: Expected 12, Got " << result1 << endl;
    }
    
    // Test Case 2: Filter >15, divide by 5, product
    // Manual calculation:
    // Input: {10, 15, 20, 25, 30}
    // Filter >15: {20, 25, 30}
    // Map /5: {4, 5, 6}
    // Reduce product (initial=1): 1 * 4 * 5 * 6 = 120
    // Expected: 120
    total++;
    vector<int> data2 = {10, 15, 20, 25, 30};
    auto filter2 = [](int x) { return x > 15; };
    auto map2 = [](int x) { return x / 5; };
    auto reduce2 = [](int acc, int x) { return acc * x; };
    int result2 = problemA3Solution(data2, filter2, map2, reduce2, 1);
    if (result2 == 120) {
        cout << "Test 2 PASS: Filter >15, map /5, reduce product" << endl;
        passed++;
    } else {
        cout << "Test 2 FAIL: Expected 120, Got " << result2 << endl;
    }
    
    // Test Case 3: All filtered out
    // Manual calculation:
    // Input: {1, 3, 5, 7}
    // Filter evens: {} (empty)
    // Map *2: {} (empty)
    // Reduce sum (initial=100): 100 (no elements to add)
    // Expected: 100
    total++;
    vector<int> data3 = {1, 3, 5, 7};
    auto filter3 = [](int x) { return x % 2 == 0; };
    auto map3 = [](int x) { return x * 2; };
    auto reduce3 = [](int acc, int x) { return acc + x; };
    int result3 = problemA3Solution(data3, filter3, map3, reduce3, 100);
    if (result3 == 100) {
        cout << "Test 3 PASS: All elements filtered out" << endl;
        passed++;
    } else {
        cout << "Test 3 FAIL: Expected 100, Got " << result3 << endl;
    }
    
    // Test Case 4: Single element
    // Manual calculation:
    // Input: {10}
    // Filter >5: {10}
    // Map *3: {30}
    // Reduce sum (initial=0): 0 + 30 = 30
    // Expected: 30
    total++;
    vector<int> data4 = {10};
    auto filter4 = [](int x) { return x > 5; };
    auto map4 = [](int x) { return x * 3; };
    auto reduce4 = [](int acc, int x) { return acc + x; };
    int result4 = problemA3Solution(data4, filter4, map4, reduce4, 0);
    if (result4 == 30) {
        cout << "Test 4 PASS: Single element" << endl;
        passed++;
    } else {
        cout << "Test 4 FAIL: Expected 30, Got " << result4 << endl;
    }
    
    // Test Case 5: Negative numbers
    // Manual calculation:
    // Input: {-5, -2, 3, -8, 10}
    // Filter negative: {-5, -2, -8}
    // Map abs (negate): {5, 2, 8}
    // Reduce sum (initial=0): 0 + 5 + 2 + 8 = 15
    // Expected: 15
    total++;
    vector<int> data5 = {-5, -2, 3, -8, 10};
    auto filter5 = [](int x) { return x < 0; };
    auto map5 = [](int x) { return -x; };
    auto reduce5 = [](int acc, int x) { return acc + x; };
    int result5 = problemA3Solution(data5, filter5, map5, reduce5, 0);
    if (result5 == 15) {
        cout << "Test 5 PASS: Negative numbers" << endl;
        passed++;
    } else {
        cout << "Test 5 FAIL: Expected 15, Got " << result5 << endl;
    }
    
    // Test Case 6: Empty vector
    // Manual calculation:
    // Input: {}
    // Filter: {} (empty)
    // Map: {} (empty)
    // Reduce (initial=42): 42
    // Expected: 42
    total++;
    vector<int> data6 = {};
    auto filter6 = [](int x) { return true; };
    auto map6 = [](int x) { return x; };
    auto reduce6 = [](int acc, int x) { return acc + x; };
    int result6 = problemA3Solution(data6, filter6, map6, reduce6, 42);
    if (result6 == 42) {
        cout << "Test 6 PASS: Empty vector" << endl;
        passed++;
    } else {
        cout << "Test 6 FAIL: Expected 42, Got " << result6 << endl;
    }
    
    // Test Case 7: Max reduction
    // Manual calculation:
    // Input: {5, 12, 3, 20, 8}
    // Filter all: {5, 12, 3, 20, 8}
    // Map identity: {5, 12, 3, 20, 8}
    // Reduce max (initial=-999): max(-999, 5)=5, max(5,12)=12, max(12,3)=12, max(12,20)=20, max(20,8)=20
    // Expected: 20
    total++;
    vector<int> data7 = {5, 12, 3, 20, 8};
    auto filter7 = [](int x) { return true; };
    auto map7 = [](int x) { return x; };
    auto reduce7 = [](int acc, int x) { return (x > acc) ? x : acc; };
    int result7 = problemA3Solution(data7, filter7, map7, reduce7, -999);
    if (result7 == 20) {
        cout << "Test 7 PASS: Max reduction" << endl;
        passed++;
    } else {
        cout << "Test 7 FAIL: Expected 20, Got " << result7 << endl;
    }
    
    // Test Case 8: Complex chain
    // Manual calculation:
    // Input: {2, 4, 6, 8, 10}
    // Filter >5: {6, 8, 10}
    // Map -2: {4, 6, 8}
    // Reduce product (initial=1): 1 * 4 * 6 * 8 = 192
    // Expected: 192
    total++;
    vector<int> data8 = {2, 4, 6, 8, 10};
    auto filter8 = [](int x) { return x > 5; };
    auto map8 = [](int x) { return x - 2; };
    auto reduce8 = [](int acc, int x) { return acc * x; };
    int result8 = problemA3Solution(data8, filter8, map8, reduce8, 1);
    if (result8 == 192) {
        cout << "Test 8 PASS: Complex chain" << endl;
        passed++;
    } else {
        cout << "Test 8 FAIL: Expected 192, Got " << result8 << endl;
    }
    
    cout << "Problem A3 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA4() {
    cout << "Testing Problem A4 - Complex Synthesis..." << endl;
    int passed = 0, total = 0;
    
    // Test Case 1: Single handler, single event
    // Manual calculation:
    // Initial: counter=0
    // Handler: adds event value to counter
    // Event: 10
    // Result: counter = 0 + 10 = 10
    // Expected: {"counter": 10}
    total++;
    map<string, int> state1 = {{"counter", 0}};
    vector<function<void(int)>> handlers1;
    handlers1.push_back([&state1](int value) { state1["counter"] += value; });
    vector<int> events1 = {10};
    auto result1 = problemA4Solution(state1, handlers1, events1);
    if (result1["counter"] == 10) {
        cout << "Test 1 PASS: Single handler, single event" << endl;
        passed++;
    } else {
        cout << "Test 1 FAIL: Expected counter=10, Got counter=" << result1["counter"] << endl;
    }
    
    // Test Case 2: Multiple events
    // Manual calculation:
    // Initial: counter=0
    // Handler: adds value
    // Events: {10, 20, 30}
    // Result: 0 + 10 + 20 + 30 = 60
    // Expected: {"counter": 60}
    total++;
    map<string, int> state2 = {{"counter", 0}};
    vector<function<void(int)>> handlers2;
    handlers2.push_back([&state2](int value) { state2["counter"] += value; });
    vector<int> events2 = {10, 20, 30};
    auto result2 = problemA4Solution(state2, handlers2, events2);
    if (result2["counter"] == 60) {
        cout << "Test 2 PASS: Multiple events" << endl;
        passed++;
    } else {
        cout << "Test 2 FAIL: Expected counter=60, Got counter=" << result2["counter"] << endl;
    }
    
    // Test Case 3: Multiple handlers, single event
    // Manual calculation:
    // Initial: sum=0, multiplier=2
    // Handler1: sum += value
    // Handler2: sum += (value * multiplier)
    // Event: 5
    // Handler1: sum = 0 + 5 = 5
    // Handler2: sum = 5 + (5 * 2) = 5 + 10 = 15
    // Expected: {"sum": 15, "multiplier": 2}
    total++;
    map<string, int> state3 = {{"sum", 0}, {"multiplier", 2}};
    vector<function<void(int)>> handlers3;
    handlers3.push_back([&state3](int value) { state3["sum"] += value; });
    handlers3.push_back([&state3](int value) { state3["sum"] += (value * state3["multiplier"]); });
    vector<int> events3 = {5};
    auto result3 = problemA4Solution(state3, handlers3, events3);
    if (result3["sum"] == 15 && result3["multiplier"] == 2) {
        cout << "Test 3 PASS: Multiple handlers, single event" << endl;
        passed++;
    } else {
        cout << "Test 3 FAIL: Expected sum=15, multiplier=2, Got sum=" 
             << result3["sum"] << ", multiplier=" << result3["multiplier"] << endl;
    }
    
    // Test Case 4: No handlers
    // Manual calculation:
    // Initial: value=100
    // No handlers
    // Events: {1, 2, 3}
    // Result: value unchanged = 100
    // Expected: {"value": 100}
    total++;
    map<string, int> state4 = {{"value", 100}};
    vector<function<void(int)>> handlers4; // empty
    vector<int> events4 = {1, 2, 3};
    auto result4 = problemA4Solution(state4, handlers4, events4);
    if (result4["value"] == 100) {
        cout << "Test 4 PASS: No handlers" << endl;
        passed++;
    } else {
        cout << "Test 4 FAIL: Expected value=100, Got value=" << result4["value"] << endl;
    }
    
    // Test Case 5: No events
    // Manual calculation:
    // Initial: counter=50
    // Handler: adds value
    // No events
    // Result: counter unchanged = 50
    // Expected: {"counter": 50}
    total++;
    map<string, int> state5 = {{"counter", 50}};
    vector<function<void(int)>> handlers5;
    handlers5.push_back([&state5](int value) { state5["counter"] += value; });
    vector<int> events5; // empty
    auto result5 = problemA4Solution(state5, handlers5, events5);
    if (result5["counter"] == 50) {
        cout << "Test 5 PASS: No events" << endl;
        passed++;
    } else {
        cout << "Test 5 FAIL: Expected counter=50, Got counter=" << result5["counter"] << endl;
    }
    
    // Test Case 6: Negative values
    // Manual calculation:
    // Initial: balance=100
    // Handler: subtracts value (balance -= value)
    // Events: {-10, -20}
    // Event -10: balance = 100 - (-10) = 110
    // Event -20: balance = 110 - (-20) = 130
    // Expected: {"balance": 130}
    total++;
    map<string, int> state6 = {{"balance", 100}};
    vector<function<void(int)>> handlers6;
    handlers6.push_back([&state6](int value) { state6["balance"] -= value; });
    vector<int> events6 = {-10, -20};
    auto result6 = problemA4Solution(state6, handlers6, events6);
    if (result6["balance"] == 130) {
        cout << "Test 6 PASS: Negative values" << endl;
        passed++;
    } else {
        cout << "Test 6 FAIL: Expected balance=130, Got balance=" << result6["balance"] << endl;
    }
    
    // Test Case 7: Multiple state variables
    // Manual calculation:
    // Initial: x=0, y=0, z=0
    // Handler1: x += value
    // Handler2: y += value * 2
    // Handler3: z += value * 3
    // Event: 10
    // x = 0 + 10 = 10
    // y = 0 + 20 = 20
    // z = 0 + 30 = 30
    // Expected: {"x": 10, "y": 20, "z": 30}
    total++;
    map<string, int> state7 = {{"x", 0}, {"y", 0}, {"z", 0}};
    vector<function<void(int)>> handlers7;
    handlers7.push_back([&state7](int value) { state7["x"] += value; });
    handlers7.push_back([&state7](int value) { state7["y"] += value * 2; });
    handlers7.push_back([&state7](int value) { state7["z"] += value * 3; });
    vector<int> events7 = {10};
    auto result7 = problemA4Solution(state7, handlers7, events7);
    if (result7["x"] == 10 && result7["y"] == 20 && result7["z"] == 30) {
        cout << "Test 7 PASS: Multiple state variables" << endl;
        passed++;
    } else {
        cout << "Test 7 FAIL: Expected x=10, y=20, z=30, Got x=" 
             << result7["x"] << ", y=" << result7["y"] << ", z=" << result7["z"] << endl;
    }
    
    // Test Case 8: Complex interaction
    // Manual calculation:
    // Initial: count=0, total=0
    // Handler1: count++
    // Handler2: total += value
    // Events: {5, 10, 15}
    // Event 5: count=1, total=5
    // Event 10: count=2, total=15
    // Event 15: count=3, total=30
    // Expected: {"count": 3, "total": 30}
    total++;
    map<string, int> state8 = {{"count", 0}, {"total", 0}};
    vector<function<void(int)>> handlers8;
    handlers8.push_back([&state8](int value) { state8["count"]++; });
    handlers8.push_back([&state8](int value) { state8["total"] += value; });
    vector<int> events8 = {5, 10, 15};
    auto result8 = problemA4Solution(state8, handlers8, events8);
    if (result8["count"] == 3 && result8["total"] == 30) {
        cout << "Test 8 PASS: Complex interaction" << endl;
        passed++;
    } else {
        cout << "Test 8 FAIL: Expected count=3, total=30, Got count=" 
             << result8["count"] << ", total=" << result8["total"] << endl;
    }
    
    cout << "Problem A4 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA5() {
    cout << "Testing Problem A5 - Mastery Challenge..." << endl;
    int passed = 0, total = 0;
    
    // Test Case 1: Filter, square, sum with count
    // Manual calculation:
    // Input: {1.5, 2.7, 3.2, 4.8, 5.1}
    // Filter > 3.0: {3.2, 4.8, 5.1}
    // Transform square: {10.24, 23.04, 26.01}
    // Aggregate sum: 10.24 + 23.04 + 26.01 = 59.29
    // Count: 3
    // Average: 59.29 / 3 = 19.763333...
    // Expected: {primaryValue: 59.29, count: 3, secondaryValue: ~19.76}
    total++;
    vector<double> data1 = {1.5, 2.7, 3.2, 4.8, 5.1};
    auto result1 = problemA5Solution(data1, 3.0, "square", "sum");
    if (abs(result1.primaryValue - 59.29) < 0.01 && result1.count == 3 && 
        abs(result1.secondaryValue - 19.76) < 0.01) {
        cout << "Test 1 PASS: Filter >3.0, square, sum" << endl;
        passed++;
    } else {
        cout << "Test 1 FAIL: Expected ~59.29, count=3, ~19.76, Got " 
             << result1.primaryValue << ", count=" << result1.count 
             << ", " << result1.secondaryValue << endl;
    }
    
    // Test Case 2: Filter, cube, product (using integers as doubles)
    // Manual calculation:
    // Input: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} (as doubles)
    // Filter odd (value - floor(value) == 0 && int(value) % 2 == 1): {1, 3, 5, 7, 9}
    // Transform cube: {1, 27, 125, 343, 729}
    // Aggregate product: 1 * 27 * 125 * 343 * 729 = 893,871,375
    // Count: 5
    // Max: 729
    // Expected: {primaryValue: 893871375, count: 5, secondaryValue: 729}
    total++;
    vector<double> data2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto result2 = problemA5Solution(data2, 0.0, "cube", "product");
    if (abs(result2.primaryValue - 893871375.0) < 1.0 && result2.count == 10 && 
        abs(result2.secondaryValue - 1000.0) < 1.0) {
        cout << "Test 2 PASS: Cube, product" << endl;
        passed++;
    } else {
        cout << "Test 2 FAIL: Expected ~893871375, count=10, ~1000, Got " 
             << result2.primaryValue << ", count=" << result2.count 
             << ", " << result2.secondaryValue << endl;
    }
    
    // Test Case 3: All filtered out
    // Manual calculation:
    // Input: {1.0, 1.5, 2.0, 2.5}
    // Filter > 10.0: {} (empty)
    // Result: {primaryValue: 0, count: 0, secondaryValue: 0}
    // Expected: {0, 0, 0}
    total++;
    vector<double> data3 = {1.0, 1.5, 2.0, 2.5};
    auto result3 = problemA5Solution(data3, 10.0, "square", "sum");
    if (result3.primaryValue == 0.0 && result3.count == 0 && result3.secondaryValue == 0.0) {
        cout << "Test 3 PASS: All filtered out" << endl;
        passed++;
    } else {
        cout << "Test 3 FAIL: Expected 0, count=0, 0, Got " 
             << result3.primaryValue << ", count=" << result3.count 
             << ", " << result3.secondaryValue << endl;
    }
    
    // Test Case 4: Single element
    // Manual calculation:
    // Input: {5.0}
    // Filter > 4.0: {5.0}
    // Transform square: {25.0}
    // Sum: 25.0, Count: 1, Average: 25.0
    // Expected: {25.0, 1, 25.0}
    total++;
    vector<double> data4 = {5.0};
    auto result4 = problemA5Solution(data4, 4.0, "square", "sum");
    if (abs(result4.primaryValue - 25.0) < 0.01 && result4.count == 1 && 
        abs(result4.secondaryValue - 25.0) < 0.01) {
        cout << "Test 4 PASS: Single element" << endl;
        passed++;
    } else {
        cout << "Test 4 FAIL: Expected 25.0, count=1, 25.0, Got " 
             << result4.primaryValue << ", count=" << result4.count 
             << ", " << result4.secondaryValue << endl;
    }
    
    // Test Case 5: No filter (threshold 0)
    // Manual calculation:
    // Input: {2.0, 3.0, 4.0}
    // Filter > 0.0: {2.0, 3.0, 4.0}
    // Transform square: {4.0, 9.0, 16.0}
    // Sum: 29.0, Count: 3, Average: 9.666...
    // Expected: {29.0, 3, ~9.67}
    total++;
    vector<double> data5 = {2.0, 3.0, 4.0};
    auto result5 = problemA5Solution(data5, 0.0, "square", "sum");
    if (abs(result5.primaryValue - 29.0) < 0.01 && result5.count == 3 && 
        abs(result5.secondaryValue - 9.67) < 0.01) {
        cout << "Test 5 PASS: No filter" << endl;
        passed++;
    } else {
        cout << "Test 5 FAIL: Expected 29.0, count=3, ~9.67, Got " 
             << result5.primaryValue << ", count=" << result5.count 
             << ", " << result5.secondaryValue << endl;
    }
    
    // Test Case 6: Empty vector
    // Manual calculation:
    // Input: {}
    // Result: {0, 0, 0}
    // Expected: {0, 0, 0}
    total++;
    vector<double> data6 = {};
    auto result6 = problemA5Solution(data6, 0.0, "square", "sum");
    if (result6.primaryValue == 0.0 && result6.count == 0 && result6.secondaryValue == 0.0) {
        cout << "Test 6 PASS: Empty vector" << endl;
        passed++;
    } else {
        cout << "Test 6 FAIL: Expected 0, count=0, 0, Got " 
             << result6.primaryValue << ", count=" << result6.count 
             << ", " << result6.secondaryValue << endl;
    }
    
    // Test Case 7: Negative numbers
    // Manual calculation:
    // Input: {-5.0, -2.0, 3.0, -8.0, 10.0}
    // Filter > 0.0: {3.0, 10.0}
    // Transform square: {9.0, 100.0}
    // Sum: 109.0, Count: 2, Average: 54.5
    // Expected: {109.0, 2, 54.5}
    total++;
    vector<double> data7 = {-5.0, -2.0, 3.0, -8.0, 10.0};
    auto result7 = problemA5Solution(data7, 0.0, "square", "sum");
    if (abs(result7.primaryValue - 109.0) < 0.01 && result7.count == 2 && 
        abs(result7.secondaryValue - 54.5) < 0.01) {
        cout << "Test 7 PASS: Negative numbers filtered" << endl;
        passed++;
    } else {
        cout << "Test 7 FAIL: Expected 109.0, count=2, 54.5, Got " 
             << result7.primaryValue << ", count=" << result7.count 
             << ", " << result7.secondaryValue << endl;
    }
    
    // Test Case 8: Identity transform
    // Manual calculation:
    // Input: {10.0, 20.0, 30.0}
    // Filter > 5.0: {10.0, 20.0, 30.0}
    // Transform identity: {10.0, 20.0, 30.0}
    // Sum: 60.0, Count: 3, Average: 20.0
    // Expected: {60.0, 3, 20.0}
    total++;
    vector<double> data8 = {10.0, 20.0, 30.0};
    auto result8 = problemA5Solution(data8, 5.0, "identity", "sum");
    if (abs(result8.primaryValue - 60.0) < 0.01 && result8.count == 3 && 
        abs(result8.secondaryValue - 20.0) < 0.01) {
        cout << "Test 8 PASS: Identity transform" << endl;
        passed++;
    } else {
        cout << "Test 8 FAIL: Expected 60.0, count=3, 20.0, Got " 
             << result8.primaryValue << ", count=" << result8.count 
             << ", " << result8.secondaryValue << endl;
    }
    
    cout << "Problem A5 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA6() {
    cout << "Testing Problem A6 - Expert Application..." << endl;
    int passed = 0, total = 0;
    
    // Test Case 1: Simple addition
    // Manual calculation:
    // Bindings: x=10, y=5
    // Operations: (x, y, '+')
    // Evaluation: 10 + 5 = 15
    // Expected: 15
    total++;
    vector<pair<string, int>> bindings1 = {{"x", 10}, {"y", 5}};
    vector<tuple<string, string, char>> operations1 = {make_tuple("x", "y", '+')};
    int result1 = problemA6Solution(bindings1, operations1);
    if (result1 == 15) {
        cout << "Test 1 PASS: Simple addition x+y" << endl;
        passed++;
    } else {
        cout << "Test 1 FAIL: Expected 15, Got " << result1 << endl;
    }
    
    // Test Case 2: Multiplication
    // Manual calculation:
    // Bindings: a=7, b=6
    // Operations: (a, b, '*')
    // Evaluation: 7 * 6 = 42
    // Expected: 42
    total++;
    vector<pair<string, int>> bindings2 = {{"a", 7}, {"b", 6}};
    vector<tuple<string, string, char>> operations2 = {make_tuple("a", "b", '*')};
    int result2 = problemA6Solution(bindings2, operations2);
    if (result2 == 42) {
        cout << "Test 2 PASS: Multiplication a*b" << endl;
        passed++;
    } else {
        cout << "Test 2 FAIL: Expected 42, Got " << result2 << endl;
    }
    
    // Test Case 3: Subtraction
    // Manual calculation:
    // Bindings: x=100, y=25
    // Operations: (x, y, '-')
    // Evaluation: 100 - 25 = 75
    // Expected: 75
    total++;
    vector<pair<string, int>> bindings3 = {{"x", 100}, {"y", 25}};
    vector<tuple<string, string, char>> operations3 = {make_tuple("x", "y", '-')};
    int result3 = problemA6Solution(bindings3, operations3);
    if (result3 == 75) {
        cout << "Test 3 PASS: Subtraction x-y" << endl;
        passed++;
    } else {
        cout << "Test 3 FAIL: Expected 75, Got " << result3 << endl;
    }
    
    // Test Case 4: Division
    // Manual calculation:
    // Bindings: a=50, b=10
    // Operations: (a, b, '/')
    // Evaluation: 50 / 10 = 5
    // Expected: 5
    total++;
    vector<pair<string, int>> bindings4 = {{"a", 50}, {"b", 10}};
    vector<tuple<string, string, char>> operations4 = {make_tuple("a", "b", '/')};
    int result4 = problemA6Solution(bindings4, operations4);
    if (result4 == 5) {
        cout << "Test 4 PASS: Division a/b" << endl;
        passed++;
    } else {
        cout << "Test 4 FAIL: Expected 5, Got " << result4 << endl;
    }
    
    // Test Case 5: Division by zero
    // Manual calculation:
    // Bindings: x=100, y=0
    // Operations: (x, y, '/')
    // Evaluation: 100 / 0 -> should handle error (return 0)
    // Expected: 0
    total++;
    vector<pair<string, int>> bindings5 = {{"x", 100}, {"y", 0}};
    vector<tuple<string, string, char>> operations5 = {make_tuple("x", "y", '/')};
    int result5 = problemA6Solution(bindings5, operations5);
    if (result5 == 0) {
        cout << "Test 5 PASS: Division by zero handled" << endl;
        passed++;
    } else {
        cout << "Test 5 FAIL: Expected 0 for division by zero, Got " << result5 << endl;
    }
    
    // Test Case 6: Negative numbers
    // Manual calculation:
    // Bindings: x=-10, y=5
    // Operations: (x, y, '*')
    // Evaluation: -10 * 5 = -50
    // Expected: -50
    total++;
    vector<pair<string, int>> bindings6 = {{"x", -10}, {"y", 5}};
    vector<tuple<string, string, char>> operations6 = {make_tuple("x", "y", '*')};
    int result6 = problemA6Solution(bindings6, operations6);
    if (result6 == -50) {
        cout << "Test 6 PASS: Negative operand" << endl;
        passed++;
    } else {
        cout << "Test 6 FAIL: Expected -50, Got " << result6 << endl;
    }
    
    // Test Case 7: Multiple operations (chained)
    // Manual calculation:
    // Bindings: x=10, y=5, z=2
    // Operations: (x, y, '+'), result should be 15, then somehow use z
    // This test assumes last operation result is returned
    // For simplicity: just test last operation
    // Operations: (x, y, '+') = 15
    // Expected: 15
    total++;
    vector<pair<string, int>> bindings7 = {{"x", 10}, {"y", 5}, {"z", 2}};
    vector<tuple<string, string, char>> operations7 = {make_tuple("x", "y", '+')};
    int result7 = problemA6Solution(bindings7, operations7);
    if (result7 == 15) {
        cout << "Test 7 PASS: Multiple bindings, single operation" << endl;
        passed++;
    } else {
        cout << "Test 7 FAIL: Expected 15, Got " << result7 << endl;
    }
    
    // Test Case 8: Zero operands
    // Manual calculation:
    // Bindings: x=0, y=0
    // Operations: (x, y, '+')
    // Evaluation: 0 + 0 = 0
    // Expected: 0
    total++;
    vector<pair<string, int>> bindings8 = {{"x", 0}, {"y", 0}};
    vector<tuple<string, string, char>> operations8 = {make_tuple("x", "y", '+')};
    int result8 = problemA6Solution(bindings8, operations8);
    if (result8 == 0) {
        cout << "Test 8 PASS: Zero operands" << endl;
        passed++;
    } else {
        cout << "Test 8 FAIL: Expected 0, Got " << result8 << endl;
    }
    
    cout << "Problem A6 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void runAllTests() {
    cout << "========================================" << endl;
    cout << "    RUNNING ALL INTEGRATION TESTS      " << endl;
    cout << "========================================" << endl << endl;
    
    testProblemA1();
    testProblemA2();
    testProblemA3();
    testProblemA4();
    testProblemA5();
    testProblemA6();
    
    cout << "========================================" << endl;
    cout << "      ALL TESTS COMPLETED              " << endl;
    cout << "========================================" << endl;
}

int main() {
    cout << "========================================" << endl;
    cout << "=== COMPREHENSIVE CHAPTER 14 ASSESSMENT ===" << endl;
    cout << "===     Lambda Functions           ===" << endl;
    cout << "========================================" << endl << endl;

    cout << "Choose your assessment mode:" << endl << endl;

    cout << "INTEGRATION PROBLEMS:" << endl;
    cout << "1. Problem A1 - Foundation Integration (Easy)" << endl;
    cout << "   Lambda calculator with capture by value" << endl;
    cout << "2. Problem A2 - Intermediate Synthesis (Easy-Medium)" << endl;
    cout << "   Lambda comparator factory for sorting" << endl;
    cout << "3. Problem A3 - Advanced Integration (Medium)" << endl;
    cout << "   Lambda pipeline processor (filter-map-reduce)" << endl;
    cout << "4. Problem A4 - Complex Synthesis (Medium-Hard)" << endl;
    cout << "   Lambda-based event handler system" << endl;
    cout << "5. Problem A5 - Mastery Challenge (Hard)" << endl;
    cout << "   Generic lambda template system" << endl;
    cout << "6. Problem A6 - Expert Application (Very Hard)" << endl;
    cout << "   Lambda-based expression evaluator with closures" << endl;
    cout << "7. Test All Integration Problems" << endl << endl;

    cout << "KNOWLEDGE VALIDATION:" << endl;
    cout << "8. Chapter Knowledge Quiz (15 questions)" << endl << endl;

    cout << "COMPREHENSIVE ASSESSMENT:" << endl;
    cout << "9. Full Chapter Assessment (All problems + Quiz)" << endl << endl;

    int choice;
    cout << "Enter your choice (1-9): ";
    cin >> choice;
    cout << endl;

    switch (choice) {
        case 1:
            testProblemA1();
            break;
        case 2:
            testProblemA2();
            break;
        case 3:
            testProblemA3();
            break;
        case 4:
            testProblemA4();
            break;
        case 5:
            testProblemA5();
            break;
        case 6:
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
            cout << "Invalid choice! Please run the program again and select 1-9." << endl;
    }

    return 0;
}