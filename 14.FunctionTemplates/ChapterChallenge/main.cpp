#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

//=== SECTION A: INTEGRATION PROBLEMS ===

// Problem A1: Foundation Integration - Generic Array Statistics
// Create a function template that calculates both the sum and average of any numeric array.
// This problem combines: basic function templates, template type deduction, and working with arrays.
// 
// Example 1: int array = {1, 2, 3, 4, 5}
//            Output: Sum = 15, Average = 3.0
// 
// Example 2: double array = {2.5, 3.5, 4.0}
//            Output: Sum = 10.0, Average = 3.33333
// 
// Input: Array of numeric type T and size
// Output: Pair-like structure or use reference parameters for sum and average
// Constraints: Array size > 0, must work with int, double, float
// Edge Cases: Single element, negative numbers, mixed positive/negative
template<typename T>
void calculateStats(const T* arr, size_t size, T& sum, double& average) {
    // TODO: Solve using function template with template type deduction
    // Hint: Iterate through array, accumulate sum, then calculate average
    // Remember to handle the conversion to double for average calculation
     sum = 0;
     average = 0;
     if (size == 0 ) return ;
     for (int i = 0; i < size; i++)
     {
          sum += arr[i];
     }
     double temp_sum = sum;
     double temp_size = size;
     average = temp_sum / temp_size;
     return ;
     
}

// Problem A2: Intermediate Synthesis - Generic Comparator with Multiple Operations
// Create a set of function templates that work with any comparable type:
// - findMax: returns the maximum of three values
// - findMin: returns the minimum of three values
// - inRange: checks if a value is between min and max (inclusive)
// This combines: function templates, template type deduction, function overloading concepts
// 
// Example 1: findMax(5, 10, 3) -> 10
//            findMin(5, 10, 3) -> 3
//            inRange(7, 5, 10) -> true
// 
// Example 2: findMax('a', 'z', 'm') -> 'z'
//            findMin(3.14, 2.71, 1.41) -> 1.41
// 
// Input: Three values of same type for max/min, value and range for inRange
// Output: Maximum/minimum value or boolean for range check
// Constraints: Must work with int, double, char, string
// Edge Cases: All values equal, negative numbers, empty strings
template<typename T>
T findMax(T a, T b, T c) {
    // TODO: Solve using function template with comparison operators
    // Hint: Compare pairs and return the largest
    return T{};
}

template<typename T>
T findMin(T a, T b, T c) {
    // TODO: Solve using function template with comparison operators
    return T{};
}

template<typename T>
bool inRange(T value, T minVal, T maxVal) {
    // TODO: Solve using function template with comparison operators
    // Hint: Check if value >= minVal && value <= maxVal
    return 0;
}

// Problem A3: Advanced Integration - Generic Array Search with Multiple Criteria
// Create a function template that searches an array and returns:
// - Index of first occurrence of a value
// - Count of how many times the value appears
// - Boolean indicating if value exists
// This combines: function templates, template parameters by reference (for output params),
// template type deduction, and array processing
// 
// Example 1: array = {1, 2, 3, 2, 4, 2}, search = 2
//            Output: firstIndex = 1, count = 3, found = true
// 
// Example 2: array = {"hello", "world", "hello"}, search = "hello"
//            Output: firstIndex = 0, count = 2, found = true
// 
// Input: Array pointer, size, search value, reference parameters for results
// Output: Results through reference parameters (firstIndex, count, found)
// Constraints: Works with any type that supports ==, returns -1 if not found
// Edge Cases: Empty array, value not found, value at beginning/end, all elements same
template<typename T>
void searchArray(const T* arr, size_t size, T searchValue, 
                 int& firstIndex, int& count, bool& found) {
    // TODO: Solve using template parameters by reference for output
    // Hint: Initialize firstIndex to -1, count to 0, found to false
    // Then iterate and update these values accordingly
}

// Problem A4: Complex Synthesis - Generic Swap with Type Transformation
// Create a function template system that:
// 1. swapValues: Generic swap for any type
// 2. swapAndTransform: Swaps two values and applies a transformation function
// 3. conditionalSwap: Only swaps if a condition is met
// This combines: function templates, template type deduction, lambda functions (Chapter 14),
// function pointers, and references
// 
// Example 1: swapValues(a=5, b=10) -> a=10, b=5
// 
// Example 2: swapAndTransform(a=3, b=7, [](int x){return x*2;})
//            After swap: a=7, b=3, then transform: a=14, b=6
// 
// Example 3: conditionalSwap(a=5, b=10, [](int x, int y){return x < y;})
//            Swaps because 5 < 10 is true
// 
// Input: Two values by reference, optional transformation/condition functions
// Output: Modified values through references
// Constraints: Must work with various types, safe with self-swap
// Edge Cases: Swapping equal values, complex objects, negative numbers
template<typename T>
void swapValues(T& a, T& b) {
    // TODO: Solve using template parameters by reference
    // Hint: Use a temporary variable to hold one value during swap
}

template<typename T, typename Func>
void swapAndTransform(T& a, T& b, Func transform) {
    // TODO: Solve using function templates with lambda integration
    // Hint: First swap, then apply transform to both values
}

template<typename T, typename Pred>
void conditionalSwap(T& a, T& b, Pred condition) {
    // TODO: Solve using function templates with predicate function
    // Hint: Check condition(a, b) before swapping
}

// Problem A5: Mastery Challenge - Generic Data Processor with Specialization
// Create a template system with:
// 1. Generic process() function that doubles any numeric value
// 2. Specialized version for strings that converts to uppercase
// 3. Specialized version for char that converts to uppercase
// 4. processArray() that processes all elements in an array
// This combines: ALL chapter concepts - templates, type deduction, template specialization,
// references, and integration with character manipulation (Chapter 10)
// 
// Example 1: process(5) -> 10 (doubled)
//            process(3.5) -> 7.0 (doubled)
// 
// Example 2: process("hello") -> "HELLO" (uppercase)
//            process('a') -> 'A' (uppercase)
// 
// Example 3: processArray({1,2,3}) -> {2,4,6}
//            processArray({"hi","bye"}) -> {"HI","BYE"}
// 
// Input: Single value or array of values
// Output: Processed value(s)
// Constraints: Numeric types doubled, strings/chars uppercased
// Edge Cases: Zero values, empty strings, already uppercase, negative numbers
template<typename T>
T process(T value) {
    // TODO: Generic implementation - multiply numeric values by 2
    // This will be used for all numeric types (int, double, float, etc.)
    return T{};
}

// TODO: Create template specialization for string
// template<>
// string process<string>(string value) {
//     // Convert string to uppercase
// }

// TODO: Create template specialization for char
// template<>
// char process<char>(char value) {
//     // Convert char to uppercase
// }

template<typename T>
void processArray(T* arr, size_t size) {
    // TODO: Apply process() to each element in the array
    // Hint: Use a loop and call process() for each element
}

// Problem A6: Expert Application - Generic Algorithm Library with Multiple Constraints
// Create a comprehensive template library that implements:
// 1. accumulate: Generic accumulation with custom operation (like std::accumulate)
// 2. transform: Applies function to each element (like std::transform)
// 3. countIf: Counts elements matching a predicate
// 4. partition: Reorganizes array based on predicate (returns partition point index)
// 
// This combines: Function templates, template type deduction, explicit template arguments,
// template parameters by reference, lambdas, pointers, arrays, and algorithm design
// 
// Example 1: accumulate({1,2,3,4,5}, 0, [](int a,int b){return a+b;}) -> 15
//            accumulate({1,2,3,4,5}, 1, [](int a,int b){return a*b;}) -> 120
// 
// Example 2: transform({1,2,3}, [](int x){return x*x;}) -> {1,4,9}
// 
// Example 3: countIf({1,2,3,4,5}, [](int x){return x%2==0;}) -> 2 (even numbers)
// 
// Example 4: partition({1,2,3,4,5}, [](int x){return x%2==0;}) 
//            Result: {2,4,1,3,5}, returns index 2 (partition point)
// 
// Input: Arrays, initial values, function objects/lambdas
// Output: Accumulated value, transformed array, count, or partition index
// Constraints: Must work with various types and operations
// Edge Cases: Empty arrays, all elements match/don't match predicate, identity operations
template<typename T, typename BinaryOp>
T accumulate(const T* arr, size_t size, T init, BinaryOp op) {
    // TODO: Implement generic accumulation algorithm
    // Hint: Start with init, apply op successively: init = op(init, arr[i])
    return T{};
}

template<typename T, typename UnaryOp>
void transform(T* arr, size_t size, UnaryOp op) {
    // TODO: Apply operation to each element in place
    // Hint: arr[i] = op(arr[i]) for each element
}

template<typename T, typename Predicate>
int countIf(const T* arr, size_t size, Predicate pred) {
    // TODO: Count elements where pred(element) returns true
    // Hint: Initialize counter, increment when pred returns true
    return 0;
}

template<typename T, typename Predicate>
int partition(T* arr, size_t size, Predicate pred) {
    // TODO: Reorganize array so elements matching pred come first
    // Hint: Use two-pointer technique or create temporary arrays
    // Return the index where partition occurs
    return 0;
}

//=== SECTION B: KNOWLEDGE VALIDATION QUIZ ===

void knowledgeQuiz() {
    cout << "=== CHAPTER 15: FUNCTION TEMPLATES KNOWLEDGE QUIZ ===" << endl;
    cout << "Answer each question and check your understanding:" << endl << endl;
    
    int totalScore = 0;
    char answer;
    
    // Question 1: Core Concept
    cout << "Q1: What is the primary purpose of function templates in C++?" << endl;
    cout << "A) To create faster functions" << endl;
    cout << "B) To write generic functions that work with multiple types" << endl;
    cout << "C) To replace all regular functions" << endl;
    cout << "D) To improve code readability only" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if(answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        totalScore++;
    } else {
        cout << "✗ INCORRECT." << endl;
    }
    cout << "Correct Answer: B - Function templates allow you to write a single function" << endl;
    cout << "that can work with multiple data types, promoting code reuse and type safety." << endl << endl;
    
    // Question 2: Syntax
    cout << "Q2: What is the correct syntax to declare a function template?" << endl;
    cout << "A) function<T> void myFunc(T param)" << endl;
    cout << "B) template<typename T> void myFunc(T param)" << endl;
    cout << "C) generic<T> void myFunc(T param)" << endl;
    cout << "D) void myFunc<T>(T param)" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if(answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        totalScore++;
    } else {
        cout << "✗ INCORRECT." << endl;
    }
    cout << "Correct Answer: B - The syntax is 'template<typename T>' or 'template<class T>'" << endl;
    cout << "followed by the function declaration. 'typename' and 'class' are interchangeable here." << endl << endl;
    
    // Question 3: Type Deduction
    cout << "Q3: Given template<typename T> T add(T a, T b), what happens with add(5, 3.14)?" << endl;
    cout << "A) Returns 8.14 as double" << endl;
    cout << "B) Compilation error - type mismatch" << endl;
    cout << "C) Returns 8 as int" << endl;
    cout << "D) Automatically converts both to float" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if(answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        totalScore++;
    } else {
        cout << "✗ INCORRECT." << endl;
    }
    cout << "Correct Answer: B - Template type deduction requires both parameters to be" << endl;
    cout << "the same type. Since 5 is int and 3.14 is double, the compiler cannot deduce" << endl;
    cout << "a single type T, resulting in a compilation error." << endl << endl;
    
    // Question 4: Explicit Template Arguments
    cout << "Q4: How do you explicitly specify the template type when calling a function?" << endl;
    cout << "A) myFunc(int)(value)" << endl;
    cout << "B) myFunc<int>(value)" << endl;
    cout << "C) myFunc[int](value)" << endl;
    cout << "D) myFunc::int(value)" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if(answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        totalScore++;
    } else {
        cout << "✗ INCORRECT." << endl;
    }
    cout << "Correct Answer: B - Use angle brackets after function name: myFunc<int>(value)" << endl;
    cout << "This is useful when type deduction fails or when you want to force a specific type." << endl << endl;
    
    // Question 5: Template Parameters by Reference
    cout << "Q5: What is the advantage of using template<typename T> void func(T& param)?" << endl;
    cout << "A) It's faster than by value" << endl;
    cout << "B) Allows modification of original argument and avoids copying" << endl;
    cout << "C) Required for all templates" << endl;
    cout << "D) Only works with pointers" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if(answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        totalScore++;
    } else {
        cout << "✗ INCORRECT." << endl;
    }
    cout << "Correct Answer: B - Passing by reference allows you to modify the original" << endl;
    cout << "argument and avoids expensive copying for large objects. Use const T& when" << endl;
    cout << "you don't need to modify but want to avoid copying." << endl << endl;
    
    // Question 6: Template Specialization
    cout << "Q6: What is template specialization used for?" << endl;
    cout << "A) Making templates run faster" << endl;
    cout << "B) Providing a specific implementation for a particular type" << endl;
    cout << "C) Creating multiple templates with same name" << endl;
    cout << "D) Debugging template code" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if(answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        totalScore++;
    } else {
        cout << "✗ INCORRECT." << endl;
    }
    cout << "Correct Answer: B - Template specialization allows you to provide a custom" << endl;
    cout << "implementation for specific types when the generic version isn't suitable." << endl;
    cout << "Syntax: template<> ReturnType funcName<SpecificType>(SpecificType param)" << endl << endl;
    
    // Question 7: typename vs class
    cout << "Q7: What's the difference between 'template<typename T>' and 'template<class T>'?" << endl;
    cout << "A) typename is for built-in types, class for user-defined types" << endl;
    cout << "B) No practical difference in this context" << endl;
    cout << "C) class is deprecated" << endl;
    cout << "D) typename allows multiple types" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if(answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        totalScore++;
    } else {
        cout << "✗ INCORRECT." << endl;
    }
    cout << "Correct Answer: B - In template parameter declarations, 'typename' and 'class'" << endl;
    cout << "are completely interchangeable. Modern style prefers 'typename' for clarity." << endl << endl;
    
    // Question 8: Multiple Template Parameters
    cout << "Q8: Can a function template have multiple template parameters?" << endl;
    cout << "A) No, only one template parameter allowed" << endl;
    cout << "B) Yes, syntax: template<typename T1, typename T2>" << endl;
    cout << "C) Yes, but only two maximum" << endl;
    cout << "D) Only with template specialization" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if(answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        totalScore++;
    } else {
        cout << "✗ INCORRECT." << endl;
    }
    cout << "Correct Answer: B - You can have multiple template parameters separated by commas:" << endl;
    cout << "template<typename T1, typename T2, typename T3> allows different types" << endl;
    cout << "for different parameters in the same function." << endl << endl;
    
    // Question 9: Common Pitfall
    cout << "Q9: What's wrong with this code? template<typename T> T max(T a, T b) { return a > b; }" << endl;
    cout << "A) Missing semicolon" << endl;
    cout << "B) Should return (a > b) ? a : b, not boolean" << endl;
    cout << "C) Template syntax is incorrect" << endl;
    cout << "D) Nothing is wrong" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if(answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        totalScore++;
    } else {
        cout << "✗ INCORRECT." << endl;
    }
    cout << "Correct Answer: B - The function returns a boolean (a > b) instead of the" << endl;
    cout << "larger value. Should be: return (a > b) ? a : b; or use if-else statement." << endl << endl;
    
    // Question 10: Template Instantiation
    cout << "Q10: When does the compiler actually generate code from a template?" << endl;
    cout << "A) When template is defined" << endl;
    cout << "B) At runtime" << endl;
    cout << "C) When template is used with specific type (instantiation)" << endl;
    cout << "D) During preprocessing" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if(answer == 'C' || answer == 'c') {
        cout << "✓ CORRECT!" << endl;
        totalScore++;
    } else {
        cout << "✗ INCORRECT." << endl;
    }
    cout << "Correct Answer: C - Templates are instantiated when used with specific types." << endl;
    cout << "The compiler generates actual function code for each type used. This is why" << endl;
    cout << "template definitions must be in header files." << endl << endl;
    
    // Question 11: const and Templates
    cout << "Q11: What does template<typename T> void print(const T& value) accomplish?" << endl;
    cout << "A) Makes the template constant" << endl;
    cout << "B) Prevents copying and modification of the argument" << endl;
    cout << "C) Only accepts const variables" << endl;
    cout << "D) Compiles faster" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if(answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        totalScore++;
    } else {
        cout << "✗ INCORRECT." << endl;
    }
    cout << "Correct Answer: B - const T& passes by reference (no copy) and prevents" << endl;
    cout << "modification. This is the preferred way to pass parameters when you don't" << endl;
    cout << "need to modify them, especially for large objects." << endl << endl;
    
    // Question 12: Type Requirements
    cout << "Q12: For template<typename T> T sum(T a, T b) { return a + b; }, what must type T support?" << endl;
    cout << "A) Nothing special" << endl;
    cout << "B) The + operator" << endl;
    cout << "C) Inheritance from a base class" << endl;
    cout << "D) Default constructor" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if(answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        totalScore++;
    } else {
        cout << "✗ INCORRECT." << endl;
    }
    cout << "Correct Answer: B - The type T must support the + operator. This is called" << endl;
    cout << "an implicit requirement. If you try to use sum() with a type that doesn't" << endl;
    cout << "have operator+, you'll get a compilation error." << endl << endl;
    
    // Question 13: Template Error Messages
    cout << "Q13: Template compilation errors are typically:" << endl;
    cout << "A) Easy to understand and fix" << endl;
    cout << "B) Verbose and can be difficult to interpret" << endl;
    cout << "C) Never occur if syntax is correct" << endl;
    cout << "D) Only happen at runtime" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if(answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        totalScore++;
    } else {
        cout << "✗ INCORRECT." << endl;
    }
    cout << "Correct Answer: B - Template errors are notorious for being verbose because" << endl;
    cout << "the compiler shows the entire instantiation chain. Always look for the first" << endl;
    cout << "error and the deepest point in your code mentioned." << endl << endl;
    
    // Question 14: Return Type Deduction
    cout << "Q14: What happens with template<typename T> auto mystery(T a) { return a * 2; }?" << endl;
    cout << "A) Compilation error - can't use auto" << endl;
    cout << "B) Return type automatically deduced from expression" << endl;
    cout << "C) Always returns int" << endl;
    cout << "D) Returns void" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if(answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        totalScore++;
    } else {
        cout << "✗ INCORRECT." << endl;
    }
    cout << "Correct Answer: B - 'auto' as return type works with templates (C++14+)." << endl;
    cout << "The compiler deduces the return type from the return statement. This is useful" << endl;
    cout << "when the return type depends on template parameters." << endl << endl;
    
    // Question 15: Best Practices
    cout << "Q15: Why should template definitions usually be in header files?" << endl;
    cout << "A) It's just convention" << endl;
    cout << "B) Compiler needs to see definition at each instantiation point" << endl;
    cout << "C) Templates are always inline" << endl;
    cout << "D) To make code compile faster" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if(answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        totalScore++;
    } else {
        cout << "✗ INCORRECT." << endl;
    }
    cout << "Correct Answer: B - The compiler needs to see the complete template definition" << endl;
    cout << "to generate code for each type. If the definition is in a .cpp file, other" << endl;
    cout << "translation units can't instantiate it. This is different from regular functions." << endl << endl;
    
    cout << "=====================================" << endl;
    cout << "QUIZ COMPLETE! Your score: " << totalScore << "/15" << endl;
    if(totalScore == 15) {
        cout << "Perfect score! You've mastered Function Templates!" << endl;
    } else if(totalScore >= 12) {
        cout << "Excellent! You have a strong understanding." << endl;
    } else if(totalScore >= 9) {
        cout << "Good job! Review the topics you missed." << endl;
    } else if(totalScore >= 6) {
        cout << "Fair. Consider reviewing the chapter material." << endl;
    } else {
        cout << "Keep studying! Review the chapter thoroughly." << endl;
    }
    cout << "=====================================" << endl << endl;
}

//=== MANDATORY COMPLETE TEST FUNCTIONS ===

void testProblemA1() {
    cout << "Testing Problem A1 - Generic Array Statistics..." << endl;
    int passed = 0, total = 0;
    
    // Test Case 1: Simple integer array
    // Manual calculation: array = {1, 2, 3, 4, 5}
    // Sum = 1 + 2 + 3 + 4 + 5 = 15
    // Average = 15 / 5 = 3.0
    total++;
    int arr1[] = {1, 2, 3, 4, 5};
    int sum1;
    double avg1;
    calculateStats(arr1, 5, sum1, avg1);
    if(sum1 == 15 && abs(avg1 - 3.0) < 0.001) {
        cout << "Test 1: PASS" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - Expected: Sum=15, Avg=3.0, Got: Sum=" << sum1 << ", Avg=" << avg1 << endl;
    }
    
    // Test Case 2: Double array with decimals
    // Manual calculation: array = {2.5, 3.5, 4.0}
    // Sum = 2.5 + 3.5 + 4.0 = 10.0
    // Average = 10.0 / 3 = 3.33333...
    total++;
    double arr2[] = {2.5, 3.5, 4.0};
    double sum2;
    double avg2;
    calculateStats(arr2, 3, sum2, avg2);
    if(abs(sum2 - 10.0) < 0.001 && abs(avg2 - 3.33333) < 0.001) {
        cout << "Test 2: PASS" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Expected: Sum=10.0, Avg=3.33333, Got: Sum=" << sum2 << ", Avg=" << avg2 << endl;
    }
    
    // Test Case 3: Single element array
    // Manual calculation: array = {42}
    // Sum = 42
    // Average = 42 / 1 = 42.0
    total++;
    int arr3[] = {42};
    int sum3;
    double avg3;
    calculateStats(arr3, 1, sum3, avg3);
    if(sum3 == 42 && abs(avg3 - 42.0) < 0.001) {
        cout << "Test 3: PASS" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Expected: Sum=42, Avg=42.0, Got: Sum=" << sum3 << ", Avg=" << avg3 << endl;
    }
    
    // Test Case 4: Array with negative numbers
    // Manual calculation: array = {-5, 10, -3, 8}
    // Sum = -5 + 10 + (-3) + 8 = 10
    // Average = 10 / 4 = 2.5
    total++;
    int arr4[] = {-5, 10, -3, 8};
    int sum4;
    double avg4;
    calculateStats(arr4, 4, sum4, avg4);
    if(sum4 == 10 && abs(avg4 - 2.5) < 0.001) {
        cout << "Test 4: PASS" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Expected: Sum=10, Avg=2.5, Got: Sum=" << sum4 << ", Avg=" << avg4 << endl;
    }
    
    // Test Case 5: All negative numbers
    // Manual calculation: array = {-2, -4, -6}
    // Sum = -2 + (-4) + (-6) = -12
    // Average = -12 / 3 = -4.0
    total++;
    int arr5[] = {-2, -4, -6};
    int sum5;
    double avg5;
    calculateStats(arr5, 3, sum5, avg5);
    if(sum5 == -12 && abs(avg5 - (-4.0)) < 0.001) {
        cout << "Test 5: PASS" << endl;
        passed++;
    } else {
        cout << "Test 5: FAIL - Expected: Sum=-12, Avg=-4.0, Got: Sum=" << sum5 << ", Avg=" << avg5 << endl;
    }
    
    // Test Case 6: Array with zeros
    // Manual calculation: array = {0, 0, 5, 0}
    // Sum = 0 + 0 + 5 + 0 = 5
    // Average = 5 / 4 = 1.25
    total++;
    int arr6[] = {0, 0, 5, 0};
    int sum6;
    double avg6;
    calculateStats(arr6, 4, sum6, avg6);
    if(sum6 == 5 && abs(avg6 - 1.25) < 0.001) {
        cout << "Test 6: PASS" << endl;
        passed++;
    } else {
        cout << "Test 6: FAIL - Expected: Sum=5, Avg=1.25, Got: Sum=" << sum6 << ", Avg=" << avg6 << endl;
    }
    
    // Test Case 7: Float array with precision
    // Manual calculation: array = {1.1, 2.2, 3.3}
    // Sum = 1.1 + 2.2 + 3.3 = 6.6
    // Average = 6.6 / 3 = 2.2
    total++;
    float arr7[] = {1.1f, 2.2f, 3.3f};
    float sum7;
    double avg7;
    calculateStats(arr7, 3, sum7, avg7);
    if(abs(sum7 - 6.6f) < 0.001 && abs(avg7 - 2.2) < 0.001) {
        cout << "Test 7: PASS" << endl;
        passed++;
    } else {
        cout << "Test 7: FAIL - Expected: Sum=6.6, Avg=2.2, Got: Sum=" << sum7 << ", Avg=" << avg7 << endl;
    }
    
    // Test Case 8: Large numbers
    // Manual calculation: array = {100, 200, 300}
    // Sum = 100 + 200 + 300 = 600
    // Average = 600 / 3 = 200.0
    total++;
    int arr8[] = {100, 200, 300};
    int sum8;
    double avg8;
    calculateStats(arr8, 3, sum8, avg8);
    if(sum8 == 600 && abs(avg8 - 200.0) < 0.001) {
        cout << "Test 8: PASS" << endl;
        passed++;
    } else {
        cout << "Test 8: FAIL - Expected: Sum=600, Avg=200.0, Got: Sum=" << sum8 << ", Avg=" << avg8 << endl;
    }
    
    cout << "Problem A1 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA2() {
    cout << "Testing Problem A2 - Generic Comparator with Multiple Operations..." << endl;
    int passed = 0, total = 0;
    
    // Test Case 1: findMax with integers
    // Manual calculation: max(5, 10, 3) = 10 (10 is largest)
    total++;
    int max1 = findMax(5, 10, 3);
    if(max1 == 10) {
        cout << "Test 1: PASS" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - Expected: 10, Got: " << max1 << endl;
    }
    
    // Test Case 2: findMin with integers
    // Manual calculation: min(5, 10, 3) = 3 (3 is smallest)
    total++;
    int min1 = findMin(5, 10, 3);
    if(min1 == 3) {
        cout << "Test 2: PASS" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Expected: 3, Got: " << min1 << endl;
    }
    
    // Test Case 3: inRange true case
    // Manual calculation: inRange(7, 5, 10) -> 7 >= 5 AND 7 <= 10 = true
    total++;
    bool inRange1 = inRange(7, 5, 10);
    if(inRange1 == true) {
        cout << "Test 3: PASS" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Expected: true, Got: " << (inRange1 ? "true" : "false") << endl;
    }
    
    // Test Case 4: inRange false case (below range)
    // Manual calculation: inRange(2, 5, 10) -> 2 >= 5 = false
    total++;
    bool inRange2 = inRange(2, 5, 10);
    if(inRange2 == false) {
        cout << "Test 4: PASS" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Expected: false, Got: " << (inRange2 ? "true" : "false") << endl;
    }
    
    // Test Case 5: findMax with characters
    // Manual calculation: max('a', 'z', 'm') = 'z' (ASCII: 'z'=122 > 'm'=109 > 'a'=97)
    total++;
    char max2 = findMax('a', 'z', 'm');
    if(max2 == 'z') {
        cout << "Test 5: PASS" << endl;
        passed++;
    } else {
        cout << "Test 5: FAIL - Expected: z, Got: " << max2 << endl;
    }
    
    // Test Case 6: findMin with doubles
    // Manual calculation: min(3.14, 2.71, 1.41) = 1.41
    total++;
    double min2 = findMin(3.14, 2.71, 1.41);
    if(abs(min2 - 1.41) < 0.001) {
        cout << "Test 6: PASS" << endl;
        passed++;
    } else {
        cout << "Test 6: FAIL - Expected: 1.41, Got: " << min2 << endl;
    }
    
    // Test Case 7: All equal values for max
    // Manual calculation: max(5, 5, 5) = 5 (all same)
    total++;
    int max3 = findMax(5, 5, 5);
    if(max3 == 5) {
        cout << "Test 7: PASS" << endl;
        passed++;
    } else {
        cout << "Test 7: FAIL - Expected: 5, Got: " << max3 << endl;
    }
    
    // Test Case 8: Negative numbers
    // Manual calculation: max(-5, -10, -3) = -3 (closest to zero)
    total++;
    int max4 = findMax(-5, -10, -3);
    if(max4 == -3) {
        cout << "Test 8: PASS" << endl;
        passed++;
    } else {
        cout << "Test 8: FAIL - Expected: -3, Got: " << max4 << endl;
    }
    
    // Test Case 9: inRange boundary case (exactly at min)
    // Manual calculation: inRange(5, 5, 10) -> 5 >= 5 AND 5 <= 10 = true
    total++;
    bool inRange3 = inRange(5, 5, 10);
    if(inRange3 == true) {
        cout << "Test 9: PASS" << endl;
        passed++;
    } else {
        cout << "Test 9: FAIL - Expected: true, Got: " << (inRange3 ? "true" : "false") << endl;
    }
    
    // Test Case 10: inRange boundary case (exactly at max)
    // Manual calculation: inRange(10, 5, 10) -> 10 >= 5 AND 10 <= 10 = true
    total++;
    bool inRange4 = inRange(10, 5, 10);
    if(inRange4 == true) {
        cout << "Test 10: PASS" << endl;
        passed++;
    } else {
        cout << "Test 10: FAIL - Expected: true, Got: " << (inRange4 ? "true" : "false") << endl;
    }
    
    cout << "Problem A2 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA3() {
    cout << "Testing Problem A3 - Generic Array Search with Multiple Criteria..." << endl;
    int passed = 0, total = 0;
    
    // Test Case 1: Search for value that appears multiple times
    // Manual calculation: array = {1, 2, 3, 2, 4, 2}, search = 2
    // First occurrence at index 1
    // Count = 3 (at indices 1, 3, 5)
    // Found = true
    total++;
    int arr1[] = {1, 2, 3, 2, 4, 2};
    int firstIdx1, count1;
    bool found1;
    searchArray(arr1, 6, 2, firstIdx1, count1, found1);
    if(firstIdx1 == 1 && count1 == 3 && found1 == true) {
        cout << "Test 1: PASS" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - Expected: idx=1, count=3, found=true, Got: idx=" 
             << firstIdx1 << ", count=" << count1 << ", found=" << (found1 ? "true" : "false") << endl;
    }
    
    // Test Case 2: Search for value not in array
    // Manual calculation: array = {1, 2, 3}, search = 5
    // Not found, firstIndex = -1, count = 0, found = false
    total++;
    int arr2[] = {1, 2, 3};
    int firstIdx2, count2;
    bool found2;
    searchArray(arr2, 3, 5, firstIdx2, count2, found2);
    if(firstIdx2 == -1 && count2 == 0 && found2 == false) {
        cout << "Test 2: PASS" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Expected: idx=-1, count=0, found=false, Got: idx=" 
             << firstIdx2 << ", count=" << count2 << ", found=" << (found2 ? "true" : "false") << endl;
    }
    
    // Test Case 3: Search in string array
    // Manual calculation: array = {"hello", "world", "hello"}, search = "hello"
    // First occurrence at index 0
    // Count = 2 (at indices 0, 2)
    // Found = true
    total++;
    string arr3[] = {"hello", "world", "hello"};
    int firstIdx3, count3;
    bool found3;
    searchArray(arr3, 3, string("hello"), firstIdx3, count3, found3);
    if(firstIdx3 == 0 && count3 == 2 && found3 == true) {
        cout << "Test 3: PASS" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Expected: idx=0, count=2, found=true, Got: idx=" 
             << firstIdx3 << ", count=" << count3 << ", found=" << (found3 ? "true" : "false") << endl;
    }
    
    // Test Case 4: Single element found
    // Manual calculation: array = {42}, search = 42
    // First occurrence at index 0
    // Count = 1
    // Found = true
    total++;
    int arr4[] = {42};
    int firstIdx4, count4;
    bool found4;
    searchArray(arr4, 1, 42, firstIdx4, count4, found4);
    if(firstIdx4 == 0 && count4 == 1 && found4 == true) {
        cout << "Test 4: PASS" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Expected: idx=0, count=1, found=true, Got: idx=" 
             << firstIdx4 << ", count=" << count4 << ", found=" << (found4 ? "true" : "false") << endl;
    }
    
    // Test Case 5: Value at end of array
    // Manual calculation: array = {1, 2, 3, 4, 5}, search = 5
    // First occurrence at index 4
    // Count = 1
    // Found = true
    total++;
    int arr5[] = {1, 2, 3, 4, 5};
    int firstIdx5, count5;
    bool found5;
    searchArray(arr5, 5, 5, firstIdx5, count5, found5);
    if(firstIdx5 == 4 && count5 == 1 && found5 == true) {
        cout << "Test 5: PASS" << endl;
        passed++;
    } else {
        cout << "Test 5: FAIL - Expected: idx=4, count=1, found=true, Got: idx=" 
             << firstIdx5 << ", count=" << count5 << ", found=" << (found5 ? "true" : "false") << endl;
    }
    
    // Test Case 6: All elements are the same
    // Manual calculation: array = {7, 7, 7, 7}, search = 7
    // First occurrence at index 0
    // Count = 4
    // Found = true
    total++;
    int arr6[] = {7, 7, 7, 7};
    int firstIdx6, count6;
    bool found6;
    searchArray(arr6, 4, 7, firstIdx6, count6, found6);
    if(firstIdx6 == 0 && count6 == 4 && found6 == true) {
        cout << "Test 6: PASS" << endl;
        passed++;
    } else {
        cout << "Test 6: FAIL - Expected: idx=0, count=4, found=true, Got: idx=" 
             << firstIdx6 << ", count=" << count6 << ", found=" << (found6 ? "true" : "false") << endl;
    }
    
    // Test Case 7: Search with doubles
    // Manual calculation: array = {1.5, 2.5, 1.5, 3.5}, search = 1.5
    // First occurrence at index 0
    // Count = 2
    // Found = true
    total++;
    double arr7[] = {1.5, 2.5, 1.5, 3.5};
    int firstIdx7, count7;
    bool found7;
    searchArray(arr7, 4, 1.5, firstIdx7, count7, found7);
    if(firstIdx7 == 0 && count7 == 2 && found7 == true) {
        cout << "Test 7: PASS" << endl;
        passed++;
    } else {
        cout << "Test 7: FAIL - Expected: idx=0, count=2, found=true, Got: idx=" 
             << firstIdx7 << ", count=" << count7 << ", found=" << (found7 ? "true" : "false") << endl;
    }
    
    // Test Case 8: Search with characters
    // Manual calculation: array = {'a', 'b', 'c', 'a'}, search = 'a'
    // First occurrence at index 0
    // Count = 2
    // Found = true
    total++;
    char arr8[] = {'a', 'b', 'c', 'a'};
    int firstIdx8, count8;
    bool found8;
    searchArray(arr8, 4, 'a', firstIdx8, count8, found8);
    if(firstIdx8 == 0 && count8 == 2 && found8 == true) {
        cout << "Test 8: PASS" << endl;
        passed++;
    } else {
        cout << "Test 8: FAIL - Expected: idx=0, count=2, found=true, Got: idx=" 
             << firstIdx8 << ", count=" << count8 << ", found=" << (found8 ? "true" : "false") << endl;
    }
    
    cout << "Problem A3 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA4() {
    cout << "Testing Problem A4 - Generic Swap with Type Transformation..." << endl;
    int passed = 0, total = 0;
    
    // Test Case 1: Basic swapValues with integers
    // Manual calculation: a=5, b=10 -> after swap: a=10, b=5
    total++;
    int a1 = 5, b1 = 10;
    swapValues(a1, b1);
    if(a1 == 10 && b1 == 5) {
        cout << "Test 1: PASS" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - Expected: a=10, b=5, Got: a=" << a1 << ", b=" << b1 << endl;
    }
    
    // Test Case 2: swapValues with strings
    // Manual calculation: a="hello", b="world" -> after swap: a="world", b="hello"
    total++;
    string a2 = "hello", b2 = "world";
    swapValues(a2, b2);
    if(a2 == "world" && b2 == "hello") {
        cout << "Test 2: PASS" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Expected: a=world, b=hello, Got: a=" << a2 << ", b=" << b2 << endl;
    }
    
    // Test Case 3: swapAndTransform with doubling
    // Manual calculation: a=3, b=7 -> swap: a=7, b=3 -> transform (*2): a=14, b=6
    total++;
    int a3 = 3, b3 = 7;
    swapAndTransform(a3, b3, [](int x){ return x * 2; });
    if(a3 == 14 && b3 == 6) {
        cout << "Test 3: PASS" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Expected: a=14, b=6, Got: a=" << a3 << ", b=" << b3 << endl;
    }
    
    // Test Case 4: swapAndTransform with squares
    // Manual calculation: a=2, b=5 -> swap: a=5, b=2 -> transform (square): a=25, b=4
    total++;
    int a4 = 2, b4 = 5;
    swapAndTransform(a4, b4, [](int x){ return x * x; });
    if(a4 == 25 && b4 == 4) {
        cout << "Test 4: PASS" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Expected: a=25, b=4, Got: a=" << a4 << ", b=" << b4 << endl;
    }
    
    // Test Case 5: conditionalSwap when condition is true
    // Manual calculation: a=5, b=10, condition: a<b -> true, so swap: a=10, b=5
    total++;
    int a5 = 5, b5 = 10;
    conditionalSwap(a5, b5, [](int x, int y){ return x < y; });
    if(a5 == 10 && b5 == 5) {
        cout << "Test 5: PASS" << endl;
        passed++;
    } else {
        cout << "Test 5: FAIL - Expected: a=10, b=5, Got: a=" << a5 << ", b=" << b5 << endl;
    }
    
    // Test Case 6: conditionalSwap when condition is false
    // Manual calculation: a=10, b=5, condition: a<b -> false, no swap: a=10, b=5
    total++;
    int a6 = 10, b6 = 5;
    conditionalSwap(a6, b6, [](int x, int y){ return x < y; });
    if(a6 == 10 && b6 == 5) {
        cout << "Test 6: PASS" << endl;
        passed++;
    } else {
        cout << "Test 6: FAIL - Expected: a=10, b=5, Got: a=" << a6 << ", b=" << b6 << endl;
    }
    
    // Test Case 7: swapValues with equal values
    // Manual calculation: a=7, b=7 -> after swap: a=7, b=7 (no visible change)
    total++;
    int a7 = 7, b7 = 7;
    swapValues(a7, b7);
    if(a7 == 7 && b7 == 7) {
        cout << "Test 7: PASS" << endl;
        passed++;
    } else {
        cout << "Test 7: FAIL - Expected: a=7, b=7, Got: a=" << a7 << ", b=" << b7 << endl;
    }
    
    // Test Case 8: swapValues with doubles
    // Manual calculation: a=3.14, b=2.71 -> after swap: a=2.71, b=3.14
    total++;
    double a8 = 3.14, b8 = 2.71;
    swapValues(a8, b8);
    if(abs(a8 - 2.71) < 0.001 && abs(b8 - 3.14) < 0.001) {
        cout << "Test 8: PASS" << endl;
        passed++;
    } else {
        cout << "Test 8: FAIL - Expected: a=2.71, b=3.14, Got: a=" << a8 << ", b=" << b8 << endl;
    }
    
    // Test Case 9: conditionalSwap with even check
    // Manual calculation: a=4, b=7, condition: a is even -> true, swap: a=7, b=4
    total++;
    int a9 = 4, b9 = 7;
    conditionalSwap(a9, b9, [](int x, int y){ return x % 2 == 0; });
    if(a9 == 7 && b9 == 4) {
        cout << "Test 9: PASS" << endl;
        passed++;
    } else {
        cout << "Test 9: FAIL - Expected: a=7, b=4, Got: a=" << a9 << ", b=" << b9 << endl;
    }
    
    // Test Case 10: swapAndTransform with strings (uppercase first char)
    // Manual calculation: a="cat", b="dog" -> swap: a="dog", b="cat" 
    // -> transform: a="Dog", b="Cat" (capitalize first)
    total++;
    string a10 = "cat", b10 = "dog";
    swapAndTransform(a10, b10, [](string s){ 
        if(!s.empty()) s[0] = toupper(s[0]); 
        return s; 
    });
    if(a10 == "Dog" && b10 == "Cat") {
        cout << "Test 10: PASS" << endl;
        passed++;
    } else {
        cout << "Test 10: FAIL - Expected: a=Dog, b=Cat, Got: a=" << a10 << ", b=" << b10 << endl;
    }
    
    cout << "Problem A4 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA5() {
    cout << "Testing Problem A5 - Mastery Challenge (Generic Data Processor with Specialization)..." << endl;
    int passed = 0, total = 0;
    
    // Test Case 1: process integer (double it)
    // Manual calculation: process(5) -> 5 * 2 = 10
    total++;
    int result1 = process(5);
    if(result1 == 10) {
        cout << "Test 1: PASS" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - Expected: 10, Got: " << result1 << endl;
    }
    
    // Test Case 2: process double (double it)
    // Manual calculation: process(3.5) -> 3.5 * 2 = 7.0
    total++;
    double result2 = process(3.5);
    if(abs(result2 - 7.0) < 0.001) {
        cout << "Test 2: PASS" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Expected: 7.0, Got: " << result2 << endl;
    }
    
    // Test Case 3: process string (uppercase) - requires specialization
    // Manual calculation: process("hello") -> "HELLO"
    total++;
    string result3 = process(string("hello"));
    if(result3 == "HELLO") {
        cout << "Test 3: PASS" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Expected: HELLO, Got: " << result3 << endl;
    }
    
    // Test Case 4: process char (uppercase) - requires specialization
    // Manual calculation: process('a') -> 'A'
    total++;
    char result4 = process('a');
    if(result4 == 'A') {
        cout << "Test 4: PASS" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Expected: A, Got: " << result4 << endl;
    }
    
    // Test Case 5: processArray with integers
    // Manual calculation: array = {1, 2, 3} -> {2, 4, 6}
    total++;
    int arr5[] = {1, 2, 3};
    processArray(arr5, 3);
    if(arr5[0] == 2 && arr5[1] == 4 && arr5[2] == 6) {
        cout << "Test 5: PASS" << endl;
        passed++;
    } else {
        cout << "Test 5: FAIL - Expected: {2,4,6}, Got: {" << arr5[0] << "," << arr5[1] << "," << arr5[2] << "}" << endl;
    }
    
    // Test Case 6: processArray with strings
    // Manual calculation: array = {"hi", "bye"} -> {"HI", "BYE"}
    total++;
    string arr6[] = {"hi", "bye"};
    processArray(arr6, 2);
    if(arr6[0] == "HI" && arr6[1] == "BYE") {
        cout << "Test 6: PASS" << endl;
        passed++;
    } else {
        cout << "Test 6: FAIL - Expected: {HI,BYE}, Got: {" << arr6[0] << "," << arr6[1] << "}" << endl;
    }
    
    // Test Case 7: process negative integer
    // Manual calculation: process(-5) -> -5 * 2 = -10
    total++;
    int result7 = process(-5);
    if(result7 == -10) {
        cout << "Test 7: PASS" << endl;
        passed++;
    } else {
        cout << "Test 7: FAIL - Expected: -10, Got: " << result7 << endl;
    }
    
    // Test Case 8: process zero
    // Manual calculation: process(0) -> 0 * 2 = 0
    total++;
    int result8 = process(0);
    if(result8 == 0) {
        cout << "Test 8: PASS" << endl;
        passed++;
    } else {
        cout << "Test 8: FAIL - Expected: 0, Got: " << result8 << endl;
    }
    
    // Test Case 9: process already uppercase char
    // Manual calculation: process('Z') -> 'Z' (already uppercase)
    total++;
    char result9 = process('Z');
    if(result9 == 'Z') {
        cout << "Test 9: PASS" << endl;
        passed++;
    } else {
        cout << "Test 9: FAIL - Expected: Z, Got: " << result9 << endl;
    }
    
    // Test Case 10: process mixed case string
    // Manual calculation: process("HeLLo") -> "HELLO"
    total++;
    string result10 = process(string("HeLLo"));
    if(result10 == "HELLO") {
        cout << "Test 10: PASS" << endl;
        passed++;
    } else {
        cout << "Test 10: FAIL - Expected: HELLO, Got: " << result10 << endl;
    }
    
    cout << "Problem A5 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void testProblemA6() {
    cout << "Testing Problem A6 - Expert Application (Generic Algorithm Library)..." << endl;
    int passed = 0, total = 0;
    
    // Test Case 1: accumulate with sum
    // Manual calculation: array = {1, 2, 3, 4, 5}, init = 0, operation = add
    // 0 + 1 = 1, 1 + 2 = 3, 3 + 3 = 6, 6 + 4 = 10, 10 + 5 = 15
    total++;
    int arr1[] = {1, 2, 3, 4, 5};
    int sum1 = accumulate(arr1, 5, 0, [](int a, int b){ return a + b; });
    if(sum1 == 15) {
        cout << "Test 1: PASS" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - Expected: 15, Got: " << sum1 << endl;
    }
    
    // Test Case 2: accumulate with product
    // Manual calculation: array = {1, 2, 3, 4, 5}, init = 1, operation = multiply
    // 1 * 1 = 1, 1 * 2 = 2, 2 * 3 = 6, 6 * 4 = 24, 24 * 5 = 120
    total++;
    int arr2[] = {1, 2, 3, 4, 5};
    int prod1 = accumulate(arr2, 5, 1, [](int a, int b){ return a * b; });
    if(prod1 == 120) {
        cout << "Test 2: PASS" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Expected: 120, Got: " << prod1 << endl;
    }
    
    // Test Case 3: transform with square
    // Manual calculation: array = {1, 2, 3} -> {1, 4, 9}
    total++;
    int arr3[] = {1, 2, 3};
    transform(arr3, 3, [](int x){ return x * x; });
    if(arr3[0] == 1 && arr3[1] == 4 && arr3[2] == 9) {
        cout << "Test 3: PASS" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Expected: {1,4,9}, Got: {" << arr3[0] << "," << arr3[1] << "," << arr3[2] << "}" << endl;
    }
    
    // Test Case 4: countIf for even numbers
    // Manual calculation: array = {1, 2, 3, 4, 5}, even predicate
    // 2 and 4 are even -> count = 2
    total++;
    int arr4[] = {1, 2, 3,4, 5};
    int count1 = countIf(arr4, 5, [](int x){ return x % 2 == 0; });
    if(count1 == 2) {
        cout << "Test 4: PASS" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Expected: 2, Got: " << count1 << endl;
    }
    
    // Test Case 5: partition with even numbers first
    // Manual calculation: array = {1, 2, 3, 4, 5}, even predicate
    // Even numbers: 2, 4 (should come first)
    // Result should be: {2, 4, 1, 3, 5} or {4, 2, 1, 3, 5}
    // Partition point should be 2 (index where odd numbers start)
    total++;
    int arr5[] = {1, 2, 3, 4, 5};
    int partPoint1 = partition(arr5, 5, [](int x){ return x % 2 == 0; });
    bool evenFirst = true;
    for(int i = 0; i < partPoint1; i++) {
        if(arr5[i] % 2 != 0) evenFirst = false;
    }
    for(int i = partPoint1; i < 5; i++) {
        if(arr5[i] % 2 == 0) evenFirst = false;
    }
    if(partPoint1 == 2 && evenFirst) {
        cout << "Test 5: PASS" << endl;
        passed++;
    } else {
        cout << "Test 5: FAIL - Expected: partition point=2 with evens first, Got: partition point=" 
             << partPoint1 << ", valid partition=" << (evenFirst ? "yes" : "no") << endl;
    }
    
    // Test Case 6: countIf with all matching
    // Manual calculation: array = {2, 4, 6, 8}, even predicate
    // All are even -> count = 4
    total++;
    int arr6[] = {2, 4, 6, 8};
    int count2 = countIf(arr6, 4, [](int x){ return x % 2 == 0; });
    if(count2 == 4) {
        cout << "Test 6: PASS" << endl;
        passed++;
    } else {
        cout << "Test 6: FAIL - Expected: 4, Got: " << count2 << endl;
    }
    
    // Test Case 7: countIf with none matching
    // Manual calculation: array = {1, 3, 5, 7}, even predicate
    // None are even -> count = 0
    total++;
    int arr7[] = {1, 3, 5, 7};
    int count3 = countIf(arr7, 4, [](int x){ return x % 2 == 0; });
    if(count3 == 0) {
        cout << "Test 7: PASS" << endl;
        passed++;
    } else {
        cout << "Test 7: FAIL - Expected: 0, Got: " << count3 << endl;
    }
    
    // Test Case 8: accumulate with strings (concatenation)
    // Manual calculation: array = {"Hello", " ", "World"}, init = "", operation = concat
    // "" + "Hello" = "Hello", "Hello" + " " = "Hello ", "Hello " + "World" = "Hello World"
    total++;
    string arr8[] = {"Hello", " ", "World"};
    string concat1 = accumulate(arr8, 3, string(""), [](string a, string b){ return a + b; });
    if(concat1 == "Hello World") {
        cout << "Test 8: PASS" << endl;
        passed++;
    } else {
        cout << "Test 8: FAIL - Expected: Hello World, Got: " << concat1 << endl;
    }
    
    // Test Case 9: transform with negate
    // Manual calculation: array = {1, -2, 3} -> {-1, 2, -3}
    total++;
    int arr9[] = {1, -2, 3};
    transform(arr9, 3, [](int x){ return -x; });
    if(arr9[0] == -1 && arr9[1] == 2 && arr9[2] == -3) {
        cout << "Test 9: PASS" << endl;
        passed++;
    } else {
        cout << "Test 9: FAIL - Expected: {-1,2,-3}, Got: {" << arr9[0] << "," << arr9[1] << "," << arr9[2] << "}" << endl;
    }
    
    // Test Case 10: accumulate with max operation
    // Manual calculation: array = {3, 7, 2, 9, 1}, init = arr[0], operation = max
    // Start with 3, max(3,7)=7, max(7,2)=7, max(7,9)=9, max(9,1)=9
    total++;
    int arr10[] = {3, 7, 2, 9, 1};
    int max1 = accumulate(arr10, 5, arr10[0], [](int a, int b){ return (a > b) ? a : b; });
    if(max1 == 9) {
        cout << "Test 10: PASS" << endl;
        passed++;
    } else {
        cout << "Test 10: FAIL - Expected: 9, Got: " << max1 << endl;
    }
    
    // Test Case 11: partition with positive numbers first
    // Manual calculation: array = {-1, 2, -3, 4, -5}, positive predicate
    // Positive numbers: 2, 4 (should come first)
    // Partition point should be 2
    total++;
    int arr11[] = {-1, 2, -3, 4, -5};
    int partPoint2 = partition(arr11, 5, [](int x){ return x > 0; });
    bool positiveFirst = true;
    for(int i = 0; i < partPoint2; i++) {
        if(arr11[i] <= 0) positiveFirst = false;
    }
    for(int i = partPoint2; i < 5; i++) {
        if(arr11[i] > 0) positiveFirst = false;
    }
    if(partPoint2 == 2 && positiveFirst) {
        cout << "Test 11: PASS" << endl;
        passed++;
    } else {
        cout << "Test 11: FAIL - Expected: partition point=2 with positives first, Got: partition point=" 
             << partPoint2 << ", valid partition=" << (positiveFirst ? "yes" : "no") << endl;
    }
    
    // Test Case 12: countIf with greater than threshold
    // Manual calculation: array = {1, 5, 3, 8, 2}, predicate: x > 3
    // 5 and 8 are > 3 -> count = 2
    total++;
    int arr12[] = {1, 5, 3, 8, 2};
    int count4 = countIf(arr12, 5, [](int x){ return x > 3; });
    if(count4 == 2) {
        cout << "Test 12: PASS" << endl;
        passed++;
    } else {
        cout << "Test 12: FAIL - Expected: 2, Got: " << count4 << endl;
    }
    
    // Test Case 13: transform with doubles
    // Manual calculation: array = {1.0, 2.0, 3.0} -> {0.5, 1.0, 1.5}
    total++;
    double arr13[] = {1.0, 2.0, 3.0};
    transform(arr13, 3, [](double x){ return x / 2.0; });
    if(abs(arr13[0] - 0.5) < 0.001 && abs(arr13[1] - 1.0) < 0.001 && abs(arr13[2] - 1.5) < 0.001) {
        cout << "Test 13: PASS" << endl;
        passed++;
    } else {
        cout << "Test 13: FAIL - Expected: {0.5,1.0,1.5}, Got: {" << arr13[0] << "," << arr13[1] << "," << arr13[2] << "}" << endl;
    }
    
    // Test Case 14: partition with all elements matching predicate
    // Manual calculation: array = {2, 4, 6, 8}, even predicate
    // All match -> partition point should be 4 (end of array)
    total++;
    int arr14[] = {2, 4, 6, 8};
    int partPoint3 = partition(arr14, 4, [](int x){ return x % 2 == 0; });
    if(partPoint3 == 4) {
        cout << "Test 14: PASS" << endl;
        passed++;
    } else {
        cout << "Test 14: FAIL - Expected: partition point=4, Got: " << partPoint3 << endl;
    }
    
    // Test Case 15: accumulate with single element
    // Manual calculation: array = {42}, init = 0, operation = add
    // 0 + 42 = 42
    total++;
    int arr15[] = {42};
    int sum2 = accumulate(arr15, 1, 0, [](int a, int b){ return a + b; });
    if(sum2 == 42) {
        cout << "Test 15: PASS" << endl;
        passed++;
    } else {
        cout << "Test 15: FAIL - Expected: 42, Got: " << sum2 << endl;
    }
    
    cout << "Problem A6 Results: " << passed << "/" << total << " tests passed" << endl << endl;
}

void runAllTests() {
    cout << "========================================" << endl;
    cout << "=== RUNNING ALL INTEGRATION PROBLEM TESTS ===" << endl;
    cout << "========================================" << endl << endl;
    
    testProblemA1();
    testProblemA2();
    testProblemA3();
    testProblemA4();
    testProblemA5();
    testProblemA6();
    
    cout << "========================================" << endl;
    cout << "=== ALL TESTS COMPLETE ===" << endl;
    cout << "========================================" << endl;
}

int main() {
    cout << "=============================================" << endl;
    cout << "=== COMPREHENSIVE CHAPTER 15 ASSESSMENT ===" << endl;
    cout << "===    FUNCTION TEMPLATES                ===" << endl;
    cout << "=============================================" << endl << endl;
    
    cout << "Choose your assessment mode:" << endl << endl;
    
    cout << "INTEGRATION PROBLEMS:" << endl;
    cout << "1. Problem A1 - Generic Array Statistics (Easy)" << endl;
    cout << "   Combines: Basic templates, type deduction, arrays" << endl << endl;
    
    cout << "2. Problem A2 - Generic Comparator Operations (Easy-Medium)" << endl;
    cout << "   Combines: Templates, type deduction, multiple functions" << endl << endl;
    
    cout << "3. Problem A3 - Generic Array Search (Medium)" << endl;
    cout << "   Combines: Templates, reference parameters, array processing" << endl << endl;
    
    cout << "4. Problem A4 - Generic Swap with Transformations (Medium-Hard)" << endl;
    cout << "   Combines: Templates, references, lambdas, predicates" << endl << endl;
    
    cout << "5. Problem A5 - Data Processor with Specialization (Hard)" << endl;
    cout << "   Combines: ALL chapter concepts + template specialization" << endl << endl;
    
    cout << "6. Problem A6 - Generic Algorithm Library (Very Hard)" << endl;
    cout << "   Combines: Advanced templates, algorithms, function objects" << endl << endl;
    
    cout << "7. Test All Integration Problems" << endl << endl;
    
    cout << "KNOWLEDGE VALIDATION:" << endl;
    cout << "8. Chapter Knowledge Quiz (15 questions)" << endl << endl;
    
    cout << "COMPREHENSIVE ASSESSMENT:" << endl;
    cout << "9. Full Chapter Assessment (All problems + Quiz)" << endl << endl;
    
    int choice;
    cout << "Enter your choice (1-9): ";
    cin >> choice;
    cout << endl;
    
    switch(choice) {
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