#include <iostream>
#include <vector>
#include <string>
#include <concepts>
#include <type_traits>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <sstream>
#include <iterator>

using namespace std;

//=== SECTION A: INTEGRATION PROBLEMS ===

// Problem A1: Foundation Integration - Generic Container Statistics
// Create a generic function template that calculates basic statistics (sum, average, min, max)
// for any container of numeric types. Use C++20 concepts to constrain the template.
//
// Requirements:
// - Use a concept to ensure the type is numeric (integral or floating_point)
// - Return a struct containing sum, average, min, and max values
// - Handle empty containers appropriately
//
// Examples:
// vector<int>{1, 2, 3, 4, 5} -> sum=15, avg=3.0, min=1, max=5
// vector<double>{1.5, 2.5, 3.5} -> sum=7.5, avg=2.5, min=1.5, max=3.5
// vector<int>{} -> sum=0, avg=0.0, min=0, max=0 (empty case)
//
// Input: Container of numeric values
// Output: Statistics struct with sum, average, min, max
// Constraints: Container must not be empty for meaningful results

template <typename T>
struct Statistics
{
    T sum;
    double average;
    T min;
    T max;
};

template <typename T>
Statistics<T> problemA1Solution(const vector<T> &data)
    requires integral<T> || floating_point<T>
{
    // TODO: Solve using C++20 concepts (integral/floating_point), standard algorithms
    // Hint: Use std::accumulate for sum, std::min_element/max_element for extremes
    Statistics<T> statistics;
    statistics.average = {};
    statistics.max = {};
    statistics.min = {};
    statistics.sum = {};
    if (data.size() == 0)
        return statistics;
    statistics.max = data[0];
    statistics.min = data[0];
    statistics.sum = data[0];
    for (size_t i = 1; i < data.size(); i++)
    {
        statistics.sum += data[i];
        if (data[i] > statistics.max)
        {
            statistics.max = data[i];
        }
        if (data[i] < statistics.min)
        {
            statistics.min = data[i];
        }
    }
    statistics.average = static_cast<double>(statistics.sum) / static_cast<double>(data.size());
    return statistics;
}

// Problem A2: Intermediate Synthesis - Concept-Constrained Function Overloading
// Create overloaded function templates for processing different types of data:
// 1. For integral types: Calculate factorial (if value <= 20, else return -1)
// 2. For floating point types: Calculate square root
// 3. For string types: Return length and first character
//
// Requirements:
// - Use C++20 concepts to disambiguate overloads (no SFINAE)
// - Each overload should return a different type
// - Use requires clause to constrain templates
//
// Examples:
// processValue(5) -> 120 (factorial)
// processValue(4.0) -> 2.0 (sqrt)
// processValue("Hello") -> "Length: 5, First: H"
// processValue(25) -> -1 (factorial too large)
//
// Input: Value of integral, floating point, or string type
// Output: Processed result based on type
// Constraints: Factorial only for n <= 20

template <typename T>
auto problemA2Solution(T value)
    requires integral<T>
{
    // TODO: Implement factorial for integral types (return -1 if value > 20)
    // Hint: Use iterative approach to avoid recursion depth issues
    if (value > 20)
        return -1;
    if (value == 0)
        return 1;
    int factorial = value;
    int temp = value;
    for (int i = 1; i < temp; i++)
    {
        value--;
        factorial = factorial * value;
    }

    return factorial;
}

template <typename T>
auto problemA2Solution(T value)
    requires floating_point<T>
{
    // TODO: Implement square root for floating point types
    // Hint: Use std::sqrt from <cmath>
    return sqrt(value);
}

string problemA2Solution(const string &value)
{
    // TODO: Return formatted string with length and first character
    // Hint: Handle empty string case
    if (value.size() == 0)
        return "Length: 0, First: (empty)";
    string result = {"Length: "};
    // string first = {", First: "};
    result += char('0' + value.size());
    result = result + ", First: ";
    result.push_back(value[0]);
    return result;
}

// Problem A3: Advanced Integration - Custom Concept Builder
// Create a custom concept "Sortable" that requires a type to:
// 1. Be copy constructible
// 2. Support operator< for comparison
// 3. Be default constructible
//
// Then create a function template that sorts any container of Sortable types
// and returns a new sorted container. Also create a concept "Container" that
// requires begin(), end(), and value_type member.
//
// Requirements:
// - Define Sortable concept combining multiple standard concepts
// - Define Container concept for container types
// - Function should work with vector, array-like structures
// - Use requires clause with both custom concepts
//
// Examples:
// vector<int>{5, 2, 8, 1} -> {1, 2, 5, 8}
// vector<string>{"dog", "cat", "ant"} -> {"ant", "cat", "dog"}
// vector<double>{3.3, 1.1, 2.2} -> {1.1, 2.2, 3.3}
//
// Input: Container of Sortable elements
// Output: New sorted container
// Constraints: Elements must satisfy Sortable concept

template <typename T>
/* TODO: Define concept combining copy_constructible,
default_constructible, and requires operator< */

concept Sortable = std::copy_constructible<T> &&
                   std::default_initializable<T> &&
                   requires(const T &a, const T &b) {
                       { a < b } -> std::convertible_to<bool>;
                   };

template <typename C>
/* TODO: Define concept requiring begin(), end(), value_type */
concept Container = requires(const C &container) {
    container.begin();
    container.end();
    typename C::value_type;
};

template <typename C>
C problemA3Solution(const C &container)
    requires Container<C> && Sortable<typename C::value_type>
{
    // TODO: Create sorted copy of container
    // Hint: Create new container, copy elements, use std::sort
    C result = container;
    sort(result.begin(), result.end());
    return result;
}

// Problem A4: Complex Synthesis - Requires Clause with Compound Requirements
// Create a generic algorithm that performs element-wise operations on containers.
// Use requires clause with compound requirements to ensure:
// 1. Both containers have the same value_type
// 2. The value_type supports the required operation (+, -, *, /)
// 3. Containers support iteration
//
// Requirements:
// - Create 4 function templates: add, subtract, multiply, divide
// - Use requires expression to check operation validity
// - Handle division by zero (return 0 for that element)
// - Containers must have same size
//
// Examples:
// add({1, 2, 3}, {4, 5, 6}) -> {5, 7, 9}
// multiply({2, 3, 4}, {5, 6, 7}) -> {10, 18, 28}
// divide({10, 20, 30}, {2, 4, 0}) -> {5, 5, 0} (handle division by zero)
//
// Input: Two containers of same type and size
// Output: New container with element-wise operation results
// Constraints: Containers must have same size, value_type must support operation

template <typename C>
concept Arithmetic = requires(C a, C b) {
    { a + b } -> convertible_to<C>;
    { a - b } -> convertible_to<C>;
    { a * b } -> convertible_to<C>;
    { a / b } -> convertible_to<C>;
};

template <typename T>
vector<T> problemA4Add(const vector<T> &v1, const vector<T> &v2)
    requires Arithmetic<T>
{
    // TODO: Implement element-wise addition
    // Hint: Check sizes match, use loop or transform

    return {T(), T()};
}

template <typename T>
vector<T> problemA4Subtract(const vector<T> &v1, const vector<T> &v2)
    requires Arithmetic<T>
{
    // TODO: Implement element-wise subtraction
    return {T(), T()};
}

template <typename T>
vector<T> problemA4Multiply(const vector<T> &v1, const vector<T> &v2)
    requires Arithmetic<T>
{
    // TODO: Implement element-wise multiplication
    return {T(), T()};
}

template <typename T>
vector<T> problemA4Divide(const vector<T> &v1, const vector<T> &v2)
    requires Arithmetic<T>
{
    // TODO: Implement element-wise division with zero check
    // Hint: If divisor is 0, result element should be 0
    return {T(), T()};
}

// Problem A5: Mastery Challenge - Combining Concepts with Auto Parameters
// Create a versatile data processor that:
// 1. Accepts containers with auto parameters
// 2. Uses concept constraints on auto parameters
// 3. Filters elements based on a predicate (also using concepts)
// 4. Transforms filtered elements
// 5. Returns results in a new container
//
// Requirements:
// - Use auto with concepts for parameters (Concept auto param)
// - Create custom concept for Predicate (callable returning bool)
// - Create custom concept for Transformer (callable returning convertible type)
// - Combine all concepts learned: auto, requires, custom concepts
//
// Examples:
// filterTransform({1,2,3,4,5}, [](int x){return x > 2;}, [](int x){return x*2;})
//   -> {6, 8, 10}
// filterTransform({"a","bb","ccc"}, [](string s){return s.size()>1;}, [](string s){return s.size();})
//   -> {2, 3}
//
// Input: Container, predicate function, transform function
// Output: New container with filtered and transformed elements
// Constraints: Predicate must return bool, transformer must return compatible type

template <typename T>
concept Predicate = requires(T pred, typename T::argument_type arg) {
    { pred(arg) } -> convertible_to<bool>;
};

template <typename Cont, typename Pred, typename Trans>
auto problemA5Solution(const Cont &container, Pred predicate, Trans transformer)
    requires Container<Cont> && requires(Pred p, typename Cont::value_type v) { { p(v) } -> convertible_to<bool>; } && requires(Trans t, typename Cont::value_type v) { t(v); }
{
    // TODO: Filter elements using predicate, transform them, return new container
    // Hint: Iterate, test predicate, apply transformer to passing elements
    vector<int> result = {0, 0};
    return result;
}

// Problem A6: Expert Application - Generic Algorithm Library with Concept Composition
// Design a mini-library for container operations using ALL concepts learned:
// 1. Custom concepts: Numeric, Comparable, Printable
// 2. Concept composition and combination (&&, ||)
// 3. Requires clauses with compound requirements
// 4. Integration with lambdas and auto
// 5. Function template specialization with concepts
//
// Create these operations:
// - aggregateIf: Sum/product of elements matching predicate
// - findPattern: Find sequences matching a pattern
// - transformConditional: Transform only elements meeting condition
//
// Requirements:
// - Use concept combinations (Numeric && Comparable)
// - Support both integral and floating_point in single template
// - Use requires expressions for type checking
// - Integrate with previous knowledge (lambdas, references, templates)
//
// Examples:
// aggregateIf({1,2,3,4,5}, [](int x){return x%2==0;}, "sum") -> 6 (2+4)
// aggregateIf({2,3,4}, [](int x){return x>2;}, "product") -> 12 (3*4)
// findPattern({1,2,3,2,3,4}, {2,3}) -> returns vector of starting indices {1, 3}
// transformConditional({1,2,3,4}, [](int x){return x>2;}, [](int x){return x*10;})
//   -> {1, 2, 30, 40}

template <typename T>
concept Numeric = integral<T> || floating_point<T>;

template <typename T>
concept Comparable = requires(T a, T b) {
    { a < b } -> convertible_to<bool>;
    { a > b } -> convertible_to<bool>;
    { a == b } -> convertible_to<bool>;
};

template <typename T>
concept Printable = requires(T a, ostream &os) {
    { os << a } -> convertible_to<ostream &>;
};

template <typename T>
T problemA6AggregateIf(const vector<T> &data, auto predicate, const string &operation)
    requires Numeric<T> && Comparable<T>
{
    // TODO: Aggregate (sum or product) elements matching predicate
    // operation is "sum" or "product"
    // Hint: Filter first, then accumulate with appropriate operation
    return 0;
}

template <typename T>
vector<int> problemA6FindPattern(const vector<T> &data, const vector<T> &pattern)
    requires Comparable<T>
{
    // TODO: Find all starting indices where pattern appears in data
    // Return vector of indices
    // Hint: Slide pattern across data, compare sequences
    return {0, 0};
}

template <typename T>
vector<T> problemA6TransformConditional(const vector<T> &data, auto predicate, auto transformer)
    requires Comparable<T>
{
    // TODO: Transform only elements that match predicate, leave others unchanged
    // Hint: Test each element, apply transformer conditionally
    return {0, 0};
}

//=== SECTION B: KNOWLEDGE VALIDATION QUIZ ===

void knowledgeQuiz()
{
    cout << "=== CHAPTER 16: C++20 CONCEPTS KNOWLEDGE QUIZ ===" << endl;
    cout << "Answer each question and check your understanding:" << endl
         << endl;

    int score = 0;

    // Question 1: Core Concept Definition
    cout << "Q1: What is the primary purpose of C++20 concepts?" << endl;
    cout << "A) To replace templates entirely" << endl;
    cout << "B) To constrain template parameters with semantic requirements" << endl;
    cout << "C) To improve runtime performance" << endl;
    cout << "D) To add new data types" << endl;
    cout << "Your answer: ";
    char answer1;
    cin >> answer1;
    if (answer1 == 'B' || answer1 == 'b')
    {
        cout << "✓ Correct!" << endl;
        score++;
    }
    else
    {
        cout << "✗ Incorrect." << endl;
    }
    cout << "Correct Answer: B - Concepts provide compile-time constraints on template parameters, "
         << "making templates more expressive and generating clearer error messages." << endl
         << endl;

    // Question 2: Standard Concepts
    cout << "Q2: Which standard concept checks if a type is an integral type?" << endl;
    cout << "A) is_integral<T>" << endl;
    cout << "B) integral<T>" << endl;
    cout << "C) integer<T>" << endl;
    cout << "D) int_type<T>" << endl;
    cout << "Your answer: ";
    char answer2;
    cin >> answer2;
    if (answer2 == 'B' || answer2 == 'b')
    {
        cout << "✓ Correct!" << endl;
        score++;
    }
    else
    {
        cout << "✗ Incorrect." << endl;
    }
    cout << "Correct Answer: B - std::integral<T> is the C++20 concept. "
         << "is_integral<T> is a type trait from C++11." << endl
         << endl;

    // Question 3: Requires Clause Syntax
    cout << "Q3: Where can the 'requires' clause be placed in a function template?" << endl;
    cout << "A) Only after the template parameter list" << endl;
    cout << "B) Only after the function signature" << endl;
    cout << "C) Both after template parameters and after function signature" << endl;
    cout << "D) Only inside the function body" << endl;
    cout << "Your answer: ";
    char answer3;
    cin >> answer3;
    if (answer3 == 'C' || answer3 == 'c')
    {
        cout << "✓ Correct!" << endl;
        score++;
    }
    else
    {
        cout << "✗ Incorrect." << endl;
    }
    cout << "Correct Answer: C - Requires clause can appear in multiple locations:\n"
         << "  template<typename T> requires integral<T> void f(T x) {}\n"
         << "  template<typename T> void f(T x) requires integral<T> {}" << endl
         << endl;

    // Question 4: Concept Definition
    cout << "Q4: What is the correct syntax to define a custom concept?" << endl;
    cout << "A) concept MyType = requires(T a) { ... };" << endl;
    cout << "B) template<typename T> concept MyType = requires(T a) { ... };" << endl;
    cout << "C) template<typename T> requires MyType = (T a) { ... };" << endl;
    cout << "D) concept<typename T> MyType = { ... };" << endl;
    cout << "Your answer: ";
    char answer4;
    cin >> answer4;
    if (answer4 == 'B' || answer4 == 'b')
    {
        cout << "✓ Correct!" << endl;
        score++;
    }
    else
    {
        cout << "✗ Incorrect." << endl;
    }
    cout << "Correct Answer: B - Concepts are defined as: template<typename T> concept Name = constraint_expression;" << endl
         << endl;

    // Question 5: Compound Requirements
    cout << "Q5: In a requires expression, what does '{ expr } -> concept_name;' check?" << endl;
    cout << "A) That expr compiles successfully" << endl;
    cout << "B) That expr returns void" << endl;
    cout << "C) That the result of expr satisfies the concept" << endl;
    cout << "D) That expr is a constant expression" << endl;
    cout << "Your answer: ";
    char answer5;
    cin >> answer5;
    if (answer5 == 'C' || answer5 == 'c')
    {
        cout << "✓ Correct!" << endl;
        score++;
    }
    else
    {
        cout << "✗ Incorrect." << endl;
    }
    cout << "Correct Answer: C - This is a compound requirement that checks both that expr is valid "
         << "and that its result satisfies the specified concept." << endl
         << endl;

    // Question 6: Combining Concepts
    cout << "Q6: How do you combine two concepts to require BOTH are satisfied?" << endl;
    cout << "A) concept1<T> | concept2<T>" << endl;
    cout << "B) concept1<T> & concept2<T>" << endl;
    cout << "C) concept1<T> && concept2<T>" << endl;
    cout << "D) concept1<T> + concept2<T>" << endl;
    cout << "Your answer: ";
    char answer6;
    cin >> answer6;
    if (answer6 == 'C' || answer6 == 'c')
    {
        cout << "✓ Correct!" << endl;
        score++;
    }
    else
    {
        cout << "✗ Incorrect." << endl;
    }
    cout << "Correct Answer: C - Use && for logical AND, || for logical OR when combining concepts." << endl
         << endl;

    // Question 7: Auto with Concepts
    cout << "Q7: What does 'void func(std::integral auto x)' mean?" << endl;
    cout << "A) x must be the auto keyword" << endl;
    cout << "B) x can be any type, checked at runtime" << endl;
    cout << "C) x must be an integral type, deduced automatically" << endl;
    cout << "D) x must be explicitly specified as int" << endl;
    cout << "Your answer: ";
    char answer7;
    cin >> answer7;
    if (answer7 == 'C' || answer7 == 'c')
    {
        cout << "✓ Correct!" << endl;
        score++;
    }
    else
    {
        cout << "✗ Incorrect." << endl;
    }
    cout << "Correct Answer: C - This is abbreviated function template syntax. "
         << "The parameter type is deduced and must satisfy std::integral." << endl
         << endl;

    // Question 8: Concept vs Type Trait
    cout << "Q8: What is a key advantage of concepts over SFINAE with type traits?" << endl;
    cout << "A) Concepts are faster at runtime" << endl;
    cout << "B) Concepts provide clearer error messages" << endl;
    cout << "C) Concepts use less memory" << endl;
    cout << "D) Concepts work with older compilers" << endl;
    cout << "Your answer: ";
    char answer8;
    cin >> answer8;
    if (answer8 == 'B' || answer8 == 'b')
    {
        cout << "✓ Correct!" << endl;
        score++;
    }
    else
    {
        cout << "✗ Incorrect." << endl;
    }
    cout << "Correct Answer: B - Concepts provide much clearer, more readable error messages "
         << "and make template constraints explicit in the interface." << endl
         << endl;

    // Question 9: Requires Expression
    cout << "Q9: What does a requires expression evaluate to?" << endl;
    cout << "A) void" << endl;
    cout << "B) true or false (bool)" << endl;
    cout << "C) The type being checked" << endl;
    cout << "D) A concept object" << endl;
    cout << "Your answer: ";
    char answer9;
    cin >> answer9;
    if (answer9 == 'B' || answer9 == 'b')
    {
        cout << "✓ Correct!" << endl;
        score++;
    }
    else
    {
        cout << "✗ Incorrect." << endl;
    }
    cout << "Correct Answer: B - A requires expression is a prvalue of type bool "
         << "that is true if all requirements are satisfied." << endl
         << endl;

    // Question 10: Standard Library Concepts
    cout << "Q10: Which header contains the standard C++20 concepts?" << endl;
    cout << "A) <type_traits>" << endl;
    cout << "B) <concepts>" << endl;
    cout << "C) <concept>" << endl;
    cout << "D) <template>" << endl;
    cout << "Your answer: ";
    char answer10;
    cin >> answer10;
    if (answer10 == 'B' || answer10 == 'b')
    {
        cout << "✓ Correct!" << endl;
        score++;
    }
    else
    {
        cout << "✗ Incorrect." << endl;
    }
    cout << "Correct Answer: B - The <concepts> header provides standard concepts like "
         << "integral, floating_point, convertible_to, etc." << endl
         << endl;

    // Question 11: Concept Subsumption
    cout << "Q11: When two function templates differ only in their concepts, which is chosen?" << endl;
    cout << "A) The one defined first" << endl;
    cout << "B) The one with the most restrictive (most specific) concept" << endl;
    cout << "C) Neither - it's always ambiguous" << endl;
    cout << "D) The one with fewer template parameters" << endl;
    cout << "Your answer: ";
    char answer11;
    cin >> answer11;
    if (answer11 == 'B' || answer11 == 'b')
    {
        cout << "✓ Correct!" << endl;
        score++;
    }
    else
    {
        cout << "✗ Incorrect." << endl;
    }
    cout << "Correct Answer: B - This is called concept subsumption. The more constrained "
         << "(more specific) template is preferred." << endl
         << endl;

    // Question 12: Simple Requirements
    cout << "Q12: In 'requires(T x) { x++; }', what is being checked?" << endl;
    cout << "A) That x can be incremented at runtime" << endl;
    cout << "B) That the expression x++ is valid (compiles)" << endl;
    cout << "C) That x is an integer" << endl;
    cout << "D) That x is a constant" << endl;
    cout << "Your answer: ";
    char answer12;
    cin >> answer12;
    if (answer12 == 'B' || answer12 == 'b')
    {
        cout << "✓ Correct!" << endl;
        score++;
    }
    else
    {
        cout << "✗ Incorrect." << endl;
    }
    cout << "Correct Answer: B - This is a simple requirement checking that the expression "
         << "is valid. It doesn't evaluate it, just checks it compiles." << endl
         << endl;

    // Question 13: Type Requirements
    cout << "Q13: What does 'requires { typename T::value_type; }' check?" << endl;
    cout << "A) That T has a member function value_type()" << endl;
    cout << "B) That T has a nested type named value_type" << endl;
    cout << "C) That T inherits from value_type" << endl;
    cout << "D) That T can be converted to value_type" << endl;
    cout << "Your answer: ";
    char answer13;
    cin >> answer13;
    if (answer13 == 'B' || answer13 == 'b')
    {
        cout << "✓ Correct!" << endl;
        score++;
    }
    else
    {
        cout << "✗ Incorrect." << endl;
    }
    cout << "Correct Answer: B - This is a type requirement, checking that T has a nested "
         << "type member named value_type (common in containers)." << endl
         << endl;

    // Question 14: Common Pitfall
    cout << "Q14: What happens if a function template's concept is not satisfied?" << endl;
    cout << "A) Runtime error" << endl;
    cout << "B) Warning is issued but code compiles" << endl;
    cout << "C) Compile-time error with clear message" << endl;
    cout << "D) Function is skipped silently" << endl;
    cout << "Your answer: ";
    char answer14;
    cin >> answer14;
    if (answer14 == 'C' || answer14 == 'c')
    {
        cout << "✓ Correct!" << endl;
        score++;
    }
    else
    {
        cout << "✗ Incorrect." << endl;
    }
    cout << "Correct Answer: C - Concepts are checked at compile-time and produce clear "
         << "error messages explaining which requirements were not satisfied." << endl
         << endl;

    // Question 15: Best Practice
    cout << "Q15: When should you create a custom concept instead of using requires directly?" << endl;
    cout << "A) Never - always use requires directly" << endl;
    cout << "B) When the constraint is complex and reused multiple times" << endl;
    cout << "C) Only for standard library types" << endl;
    cout << "D) Only when using auto parameters" << endl;
    cout << "Your answer: ";
    char answer15;
    cin >> answer15;
    if (answer15 == 'B' || answer15 == 'b')
    {
        cout << "✓ Correct!" << endl;
        score++;
    }
    else
    {
        cout << "✗ Incorrect." << endl;
    }
    cout << "Correct Answer: B - Create named concepts for complex, reusable constraints. "
         << "This improves code readability and maintainability." << endl
         << endl;

    cout << "=== QUIZ COMPLETE ===" << endl;
    cout << "Your score: " << score << "/15 (" << (score * 100 / 15) << "%)" << endl;
    if (score >= 13)
        cout << "Excellent! You have mastered C++20 Concepts!" << endl;
    else if (score >= 10)
        cout << "Good job! Review the questions you missed." << endl;
    else if (score >= 7)
        cout << "Fair. Consider reviewing the chapter material." << endl;
    else
        cout << "Keep studying! C++20 Concepts require practice." << endl;
}

//=== MANDATORY COMPLETE TEST FUNCTIONS ===

void testProblemA1()
{
    cout << "Testing Problem A1 - Foundation Integration (Generic Container Statistics)..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Basic integer vector
    // Manual calculation: sum = 1+2+3+4+5 = 15, avg = 15/5 = 3.0, min = 1, max = 5
    // Expected: Statistics{15, 3.0, 1, 5}
    total++;
    vector<int> test1 = {1, 2, 3, 4, 5};
    auto result1 = problemA1Solution(test1);
    if (result1.sum == 15 && abs(result1.average - 3.0) < 0.001 &&
        result1.min == 1 && result1.max == 5)
    {
        cout << "Test 1 PASS: Basic integer vector" << endl;
        passed++;
    }
    else
    {
        cout << "Test 1 FAIL: Expected sum=15, avg=3.0, min=1, max=5, Got sum="
             << result1.sum << ", avg=" << result1.average << ", min=" << result1.min
             << ", max=" << result1.max << endl;
    }

    // Test Case 2: Floating point vector
    // Manual calculation: sum = 1.5+2.5+3.5 = 7.5, avg = 7.5/3 = 2.5, min = 1.5, max = 3.5
    // Expected: Statistics{7.5, 2.5, 1.5, 3.5}
    total++;
    vector<double> test2 = {1.5, 2.5, 3.5};
    auto result2 = problemA1Solution(test2);
    if (abs(result2.sum - 7.5) < 0.001 && abs(result2.average - 2.5) < 0.001 &&
        abs(result2.min - 1.5) < 0.001 && abs(result2.max - 3.5) < 0.001)
    {
        cout << "Test 2 PASS: Floating point vector" << endl;
        passed++;
    }
    else
    {
        cout << "Test 2 FAIL: Expected sum=7.5, avg=2.5, min=1.5, max=3.5, Got sum="
             << result2.sum << ", avg=" << result2.average << ", min=" << result2.min
             << ", max=" << result2.max << endl;
    }

    // Test Case 3: Single element
    // Manual calculation: sum = 42, avg = 42/1 = 42.0, min = 42, max = 42
    // Expected: Statistics{42, 42.0, 42, 42}
    total++;
    vector<int> test3 = {42};
    auto result3 = problemA1Solution(test3);
    if (result3.sum == 42 && abs(result3.average - 42.0) < 0.001 &&
        result3.min == 42 && result3.max == 42)
    {
        cout << "Test 3 PASS: Single element" << endl;
        passed++;
    }
    else
    {
        cout << "Test 3 FAIL: Expected sum=42, avg=42.0, min=42, max=42, Got sum="
             << result3.sum << ", avg=" << result3.average << ", min=" << result3.min
             << ", max=" << result3.max << endl;
    }

    // Test Case 4: Negative numbers
    // Manual calculation: sum = -5+(-2)+3 = -4, avg = -4/3 ≈ -1.333, min = -5, max = 3
    // Expected: Statistics{-4, -1.333, -5, 3}
    total++;
    vector<int> test4 = {-5, -2, 3};
    auto result4 = problemA1Solution(test4);
    if (result4.sum == -4 && abs(result4.average - (-1.333)) < 0.01 &&
        result4.min == -5 && result4.max == 3)
    {
        cout << "Test 4 PASS: Negative numbers" << endl;
        passed++;
    }
    else
    {
        cout << "Test 4 FAIL: Expected sum=-4, avg≈-1.333, min=-5, max=3, Got sum="
             << result4.sum << ", avg=" << result4.average << ", min=" << result4.min
             << ", max=" << result4.max << endl;
    }

    // Test Case 5: All same values
    // Manual calculation: sum = 7+7+7+7 = 28, avg = 28/4 = 7.0, min = 7, max = 7
    // Expected: Statistics{28, 7.0, 7, 7}
    total++;
    vector<int> test5 = {7, 7, 7, 7};
    auto result5 = problemA1Solution(test5);
    if (result5.sum == 28 && abs(result5.average - 7.0) < 0.001 &&
        result5.min == 7 && result5.max == 7)
    {
        cout << "Test 5 PASS: All same values" << endl;
        passed++;
    }
    else
    {
        cout << "Test 5 FAIL: Expected sum=28, avg=7.0, min=7, max=7, Got sum="
             << result5.sum << ", avg=" << result5.average << ", min=" << result5.min
             << ", max=" << result5.max << endl;
    }

    // Test Case 6: Large numbers
    // Manual calculation: sum = 100+200+300 = 600, avg = 600/3 = 200.0, min = 100, max = 300
    // Expected: Statistics{600, 200.0, 100, 300}
    total++;
    vector<int> test6 = {100, 200, 300};
    auto result6 = problemA1Solution(test6);
    if (result6.sum == 600 && abs(result6.average - 200.0) < 0.001 &&
        result6.min == 100 && result6.max == 300)
    {
        cout << "Test 6 PASS: Large numbers" << endl;
        passed++;
    }
    else
    {
        cout << "Test 6 FAIL: Expected sum=600, avg=200.0, min=100, max=300, Got sum="
             << result6.sum << ", avg=" << result6.average << ", min=" << result6.min
             << ", max=" << result6.max << endl;
    }

    // Test Case 7: Empty vector (edge case)
    // Manual calculation: sum = 0, avg = 0.0, min = 0, max = 0
    // Expected: Statistics{0, 0.0, 0, 0}
    total++;
    vector<int> test7 = {};
    auto result7 = problemA1Solution(test7);
    if (result7.sum == 0 && abs(result7.average - 0.0) < 0.001 &&
        result7.min == 0 && result7.max == 0)
    {
        cout << "Test 7 PASS: Empty vector" << endl;
        passed++;
    }
    else
    {
        cout << "Test 7 FAIL: Expected sum=0, avg=0.0, min=0, max=0, Got sum="
             << result7.sum << ", avg=" << result7.average << ", min=" << result7.min
             << ", max=" << result7.max << endl;
    }

    // Test Case 8: Mixed positive/negative doubles
    // Manual calculation: sum = 2.5+(-1.5)+3.0 = 4.0, avg = 4.0/3 ≈ 1.333, min = -1.5, max = 3.0
    // Expected: Statistics{4.0, 1.333, -1.5, 3.0}
    total++;
    vector<double> test8 = {2.5, -1.5, 3.0};
    auto result8 = problemA1Solution(test8);
    if (abs(result8.sum - 4.0) < 0.001 && abs(result8.average - 1.333) < 0.01 &&
        abs(result8.min - (-1.5)) < 0.001 && abs(result8.max - 3.0) < 0.001)
    {
        cout << "Test 8 PASS: Mixed positive/negative doubles" << endl;
        passed++;
    }
    else
    {
        cout << "Test 8 FAIL: Expected sum=4.0, avg≈1.333, min=-1.5, max=3.0, Got sum="
             << result8.sum << ", avg=" << result8.average << ", min=" << result8.min
             << ", max=" << result8.max << endl;
    }

    cout << "Problem A1 Results: " << passed << "/" << total << " tests passed" << endl
         << endl;
}

void testProblemA2()
{
    cout << "Testing Problem A2 - Intermediate Synthesis (Concept-Constrained Overloading)..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Factorial of 5
    // Manual calculation: 5! = 5*4*3*2*1 = 120
    // Expected: 120
    total++;
    auto result1 = problemA2Solution(5);
    if (result1 == 120)
    {
        cout << "Test 1 PASS: Factorial of 5" << endl;
        passed++;
    }
    else
    {
        cout << "Test 1 FAIL: Expected 120, Got " << result1 << endl;
    }

    // Test Case 2: Factorial of 0
    // Manual calculation: 0! = 1 (by definition)
    // Expected: 1
    total++;
    auto result2 = problemA2Solution(0);
    if (result2 == 1)
    {
        cout << "Test 2 PASS: Factorial of 0" << endl;
        passed++;
    }
    else
    {
        cout << "Test 2 FAIL: Expected 1, Got " << result2 << endl;
    }

    // Test Case 3: Factorial too large (25 > 20)
    // Manual calculation: 25 > 20, so return -1
    // Expected: -1
    total++;
    auto result3 = problemA2Solution(25);
    if (result3 == -1)
    {
        cout << "Test 3 PASS: Factorial too large" << endl;
        passed++;
    }
    else
    {
        cout << "Test 3 FAIL: Expected -1, Got " << result3 << endl;
    }

    // Test Case 4: Square root of 4.0
    // Manual calculation: sqrt(4.0) = 2.0
    // Expected: 2.0
    total++;
    auto result4 = problemA2Solution(4.0);
    if (abs(result4 - 2.0) < 0.001)
    {
        cout << "Test 4 PASS: Square root of 4.0" << endl;
        passed++;
    }
    else
    {
        cout << "Test 4 FAIL: Expected 2.0, Got " << result4 << endl;
    }

    // Test Case 5: Square root of 9.0
    // Manual calculation: sqrt(9.0) = 3.0
    // Expected: 3.0
    total++;
    auto result5 = problemA2Solution(9.0);
    if (abs(result5 - 3.0) < 0.001)
    {
        cout << "Test 5 PASS: Square root of 9.0" << endl;
        passed++;
    }
    else
    {
        cout << "Test 5 FAIL: Expected 3.0, Got " << result5 << endl;
    }

    // Test Case 6: String "Hello"
    // Manual calculation: Length = 5, First char = 'H'
    // Expected: "Length: 5, First: H"
    total++;
    auto result6 = problemA2Solution(string("Hello"));
    if (result6 == "Length: 5, First: H")
    {
        cout << "Test 6 PASS: String Hello" << endl;
        passed++;
    }
    else
    {
        cout << "Test 6 FAIL: Expected 'Length: 5, First: H', Got '" << result6 << "'" << endl;
    }

    // Test Case 7: Empty string
    // Manual calculation: Length = 0, no first character
    // Expected: "Length: 0, First: (empty)"
    total++;
    auto result7 = problemA2Solution(string(""));
    if (result7 == "Length: 0, First: (empty)")
    {
        cout << "Test 7 PASS: Empty string" << endl;
        passed++;
    }
    else
    {
        cout << "Test 7 FAIL: Expected 'Length: 0, First: (empty)', Got '" << result7 << "'" << endl;
    }

    // Test Case 8: Factorial of 10
    // Manual calculation: 10! = 10*9*8*7*6*5*4*3*2*1 = 3628800
    // Expected: 3628800
    total++;
    auto result8 = problemA2Solution(10);
    if (result8 == 3628800)
    {
        cout << "Test 8 PASS: Factorial of 10" << endl;
        passed++;
    }
    else
    {
        cout << "Test 8 FAIL: Expected 3628800, Got " << result8 << endl;
    }

    // Test Case 9: Square root of 2.0
    // Manual calculation: sqrt(2.0) ≈ 1.414
    // Expected: ≈1.414
    total++;
    auto result9 = problemA2Solution(2.0);
    if (abs(result9 - 1.414) < 0.01)
    {
        cout << "Test 9 PASS: Square root of 2.0" << endl;
        passed++;
    }
    else
    {
        cout << "Test 9 FAIL: Expected ≈1.414, Got " << result9 << endl;
    }

    // Test Case 10: String "A"
    // Manual calculation: Length = 1, First char = 'A'
    // Expected: "Length: 1, First: A"
    total++;
    auto result10 = problemA2Solution(string("A"));
    if (result10 == "Length: 1, First: A")
    {
        cout << "Test 10 PASS: Single character string" << endl;
        passed++;
    }
    else
    {
        cout << "Test 10 FAIL: Expected 'Length: 1, First: A', Got '" << result10 << "'" << endl;
    }

    cout << "Problem A2 Results: " << passed << "/" << total << " tests passed" << endl
         << endl;
}

void testProblemA3()
{
    cout << "Testing Problem A3 - Advanced Integration (Custom Concept Builder)..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Unsorted integer vector
    // Manual calculation: {5, 2, 8, 1} sorted = {1, 2, 5, 8}
    // Expected: {1, 2, 5, 8}
    total++;
    vector<int> test1 = {5, 2, 8, 1};
    auto result1 = problemA3Solution(test1);
    vector<int> expected1 = {1, 2, 5, 8};
    if (result1 == expected1)
    {
        cout << "Test 1 PASS: Unsorted integer vector" << endl;
        passed++;
    }
    else
    {
        cout << "Test 1 FAIL: Expected {1, 2, 5, 8}, Got {";
        for (size_t i = 0; i < result1.size(); i++)
        {
            cout << result1[i];
            if (i < result1.size() - 1)
                cout << ", ";
        }
        cout << "}" << endl;
    }

    // Test Case 2: String vector
    // Manual calculation: {"dog", "cat", "ant"} sorted alphabetically = {"ant", "cat", "dog"}
    // Expected: {"ant", "cat", "dog"}
    total++;
    vector<string> test2 = {"dog", "cat", "ant"};
    auto result2 = problemA3Solution(test2);
    vector<string> expected2 = {"ant", "cat", "dog"};
    if (result2 == expected2)
    {
        cout << "Test 2 PASS: String vector" << endl;
        passed++;
    }
    else
    {
        cout << "Test 2 FAIL: Expected {ant, cat, dog}, Got {";
        for (size_t i = 0; i < result2.size(); i++)
        {
            cout << result2[i];
            if (i < result2.size() - 1)
                cout << ", ";
        }
        cout << "}" << endl;
    }

    // Test Case 3: Double vector
    // Manual calculation: {3.3, 1.1, 2.2} sorted = {1.1, 2.2, 3.3}
    // Expected: {1.1, 2.2, 3.3}
    total++;
    vector<double> test3 = {3.3, 1.1, 2.2};
    auto result3 = problemA3Solution(test3);
    vector<double> expected3 = {1.1, 2.2, 3.3};
    bool test3Pass = true;
    if (result3.size() != expected3.size())
        test3Pass = false;
    else
    {
        for (size_t i = 0; i < result3.size(); i++)
        {
            if (abs(result3[i] - expected3[i]) > 0.001)
            {
                test3Pass = false;
                break;
            }
        }
    }
    if (test3Pass)
    {
        cout << "Test 3 PASS: Double vector" << endl;
        passed++;
    }
    else
    {
        cout << "Test 3 FAIL: Expected {1.1, 2.2, 3.3}, Got {";
        for (size_t i = 0; i < result3.size(); i++)
        {
            cout << result3[i];
            if (i < result3.size() - 1)
                cout << ", ";
        }
        cout << "}" << endl;
    }

    // Test Case 4: Already sorted vector
    // Manual calculation: {1, 2, 3, 4} already sorted = {1, 2, 3, 4}
    // Expected: {1, 2, 3, 4}
    total++;
    vector<int> test4 = {1, 2, 3, 4};
    auto result4 = problemA3Solution(test4);
    vector<int> expected4 = {1, 2, 3, 4};
    if (result4 == expected4)
    {
        cout << "Test 4 PASS: Already sorted vector" << endl;
        passed++;
    }
    else
    {
        cout << "Test 4 FAIL: Expected {1, 2, 3, 4}, Got {";
        for (size_t i = 0; i < result4.size(); i++)
        {
            cout << result4[i];
            if (i < result4.size() - 1)
                cout << ", ";
        }
        cout << "}" << endl;
    }

    // Test Case 5: Reverse sorted vector
    // Manual calculation: {9, 7, 5, 3, 1} sorted = {1, 3, 5, 7, 9}
    // Expected: {1, 3, 5, 7, 9}
    total++;
    vector<int> test5 = {9, 7, 5, 3, 1};
    auto result5 = problemA3Solution(test5);
    vector<int> expected5 = {1, 3, 5, 7, 9};
    if (result5 == expected5)
    {
        cout << "Test 5 PASS: Reverse sorted vector" << endl;
        passed++;
    }
    else
    {
        cout << "Test 5 FAIL: Expected {1, 3, 5, 7, 9}, Got {";
        for (size_t i = 0; i < result5.size(); i++)
        {
            cout << result5[i];
            if (i < result5.size() - 1)
                cout << ", ";
        }
        cout << "}" << endl;
    }

    // Test Case 6: Single element
    // Manual calculation: {42} sorted = {42}
    // Expected: {42}
    total++;
    vector<int> test6 = {42};
    auto result6 = problemA3Solution(test6);
    vector<int> expected6 = {42};
    if (result6 == expected6)
    {
        cout << "Test 6 PASS: Single element" << endl;
        passed++;
    }
    else
    {
        cout << "Test 6 FAIL: Expected {42}, Got {";
        for (size_t i = 0; i < result6.size(); i++)
        {
            cout << result6[i];
            if (i < result6.size() - 1)
                cout << ", ";
        }
        cout << "}" << endl;
    }

    // Test Case 7: Duplicate elements
    // Manual calculation: {3, 1, 2, 1, 3, 2} sorted = {1, 1, 2, 2, 3, 3}
    // Expected: {1, 1, 2, 2, 3, 3}
    total++;
    vector<int> test7 = {3, 1, 2, 1, 3, 2};
    auto result7 = problemA3Solution(test7);
    vector<int> expected7 = {1, 1, 2, 2, 3, 3};
    if (result7 == expected7)
    {
        cout << "Test 7 PASS: Duplicate elements" << endl;
        passed++;
    }
    else
    {
        cout << "Test 7 FAIL: Expected {1, 1, 2, 2, 3, 3}, Got {";
        for (size_t i = 0; i < result7.size(); i++)
        {
            cout << result7[i];
            if (i < result7.size() - 1)
                cout << ", ";
        }
        cout << "}" << endl;
    }

    // Test Case 8: Empty vector
    // Manual calculation: {} sorted = {}
    // Expected: {}
    total++;
    vector<int> test8 = {};
    auto result8 = problemA3Solution(test8);
    vector<int> expected8 = {};
    if (result8 == expected8)
    {
        cout << "Test 8 PASS: Empty vector" << endl;
        passed++;
    }
    else
    {
        cout << "Test 8 FAIL: Expected empty vector, Got size " << result8.size() << endl;
    }

    cout << "Problem A3 Results: " << passed << "/" << total << " tests passed" << endl
         << endl;
}

void testProblemA4()
{
    cout << "Testing Problem A4 - Complex Synthesis (Element-wise Operations)..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Add integer vectors
    // Manual calculation: {1, 2, 3} + {4, 5, 6} = {5, 7, 9}
    // Expected: {5, 7, 9}
    total++;
    vector<int> v1_1 = {1, 2, 3};
    vector<int> v2_1 = {4, 5, 6};
    auto result1 = problemA4Add(v1_1, v2_1);
    vector<int> expected1 = {5, 7, 9};
    if (result1 == expected1)
    {
        cout << "Test 1 PASS: Add integer vectors" << endl;
        passed++;
    }
    else
    {
        cout << "Test 1 FAIL: Expected {5, 7, 9}, Got {";
        for (size_t i = 0; i < result1.size(); i++)
        {
            cout << result1[i];
            if (i < result1.size() - 1)
                cout << ", ";
        }
        cout << "}" << endl;
    }

    // Test Case 2: Subtract integer vectors
    // Manual calculation: {10, 20, 30} - {3, 8, 15} = {7, 12, 15}
    // Expected: {7, 12, 15}
    total++;
    vector<int> v1_2 = {10, 20, 30};
    vector<int> v2_2 = {3, 8, 15};
    auto result2 = problemA4Subtract(v1_2, v2_2);
    vector<int> expected2 = {7, 12, 15};
    if (result2 == expected2)
    {
        cout << "Test 2 PASS: Subtract integer vectors" << endl;
        passed++;
    }
    else
    {
        cout << "Test 2 FAIL: Expected {7, 12, 15}, Got {";
        for (size_t i = 0; i < result2.size(); i++)
        {
            cout << result2[i];
            if (i < result2.size() - 1)
                cout << ", ";
        }
        cout << "}" << endl;
    }

    // Test Case 3: Multiply integer vectors
    // Manual calculation: {2, 3, 4} * {5, 6, 7} = {10, 18, 28}
    // Expected: {10, 18, 28}
    total++;
    vector<int> v1_3 = {2, 3, 4};
    vector<int> v2_3 = {5, 6, 7};
    auto result3 = problemA4Multiply(v1_3, v2_3);
    vector<int> expected3 = {10, 18, 28};
    if (result3 == expected3)
    {
        cout << "Test 3 PASS: Multiply integer vectors" << endl;
        passed++;
    }
    else
    {
        cout << "Test 3 FAIL: Expected {10, 18, 28}, Got {";
        for (size_t i = 0; i < result3.size(); i++)
        {
            cout << result3[i];
            if (i < result3.size() - 1)
                cout << ", ";
        }
        cout << "}" << endl;
    }

    // Test Case 4: Divide integer vectors with zero handling
    // Manual calculation: {10, 20, 30} / {2, 4, 0} = {5, 5, 0} (0 when dividing by zero)
    // Expected: {5, 5, 0}
    total++;
    vector<int> v1_4 = {10, 20, 30};
    vector<int> v2_4 = {2, 4, 0};
    auto result4 = problemA4Divide(v1_4, v2_4);
    vector<int> expected4 = {5, 5, 0};
    if (result4 == expected4)
    {
        cout << "Test 4 PASS: Divide with zero handling" << endl;
        passed++;
    }
    else
    {
        cout << "Test 4 FAIL: Expected {5, 5, 0}, Got {";
        for (size_t i = 0; i < result4.size(); i++)
        {
            cout << result4[i];
            if (i < result4.size() - 1)
                cout << ", ";
        }
        cout << "}" << endl;
    }

    // Test Case 5: Add double vectors
    // Manual calculation: {1.5, 2.5} + {0.5, 1.5} = {2.0, 4.0}
    // Expected: {2.0, 4.0}
    total++;
    vector<double> v1_5 = {1.5, 2.5};
    vector<double> v2_5 = {0.5, 1.5};
    auto result5 = problemA4Add(v1_5, v2_5);
    vector<double> expected5 = {2.0, 4.0};
    bool test5Pass = true;
    if (result5.size() != expected5.size())
        test5Pass = false;
    else
    {
        for (size_t i = 0; i < result5.size(); i++)
        {
            if (abs(result5[i] - expected5[i]) > 0.001)
            {
                test5Pass = false;
                break;
            }
        }
    }
    if (test5Pass)
    {
        cout << "Test 5 PASS: Add double vectors" << endl;
        passed++;
    }
    else
    {
        cout << "Test 5 FAIL: Expected {2.0, 4.0}, Got {";
        for (size_t i = 0; i < result5.size(); i++)
        {
            cout << result5[i];
            if (i < result5.size() - 1)
                cout << ", ";
        }
        cout << "}" << endl;
    }

    // Test Case 6: Multiply with negatives
    // Manual calculation: {-2, 3, -4} * {5, -6, 7} = {-10, -18, -28}
    // Expected: {-10, -18, -28}
    total++;
    vector<int> v1_6 = {-2, 3, -4};
    vector<int> v2_6 = {5, -6, 7};
    auto result6 = problemA4Multiply(v1_6, v2_6);
    vector<int> expected6 = {-10, -18, -28};
    if (result6 == expected6)
    {
        cout << "Test 6 PASS: Multiply with negatives" << endl;
        passed++;
    }
    else
    {
        cout << "Test 6 FAIL: Expected {-10, -18, -28}, Got {";
        for (size_t i = 0; i < result6.size(); i++)
        {
            cout << result6[i];
            if (i < result6.size() - 1)
                cout << ", ";
        }
        cout << "}" << endl;
    }

    // Test Case 7: Single element vectors
    // Manual calculation: {100} + {50} = {150}
    // Expected: {150}
    total++;
    vector<int> v1_7 = {100};
    vector<int> v2_7 = {50};
    auto result7 = problemA4Add(v1_7, v2_7);
    vector<int> expected7 = {150};
    if (result7 == expected7)
    {
        cout << "Test 7 PASS: Single element vectors" << endl;
        passed++;
    }
    else
    {
        cout << "Test 7 FAIL: Expected {150}, Got {";
        for (size_t i = 0; i < result7.size(); i++)
        {
            cout << result7[i];
            if (i < result7.size() - 1)
                cout << ", ";
        }
        cout << "}" << endl;
    }

    // Test Case 8: Divide doubles
    // Manual calculation: {10.0, 20.0, 30.0} / {2.0, 5.0, 10.0} = {5.0, 4.0, 3.0}
    // Expected: {5.0, 4.0, 3.0}
    total++;
    vector<double> v1_8 = {10.0, 20.0, 30.0};
    vector<double> v2_8 = {2.0, 5.0, 10.0};
    auto result8 = problemA4Divide(v1_8, v2_8);
    vector<double> expected8 = {5.0, 4.0, 3.0};
    bool test8Pass = true;
    if (result8.size() != expected8.size())
        test8Pass = false;
    else
    {
        for (size_t i = 0; i < result8.size(); i++)
        {
            if (abs(result8[i] - expected8[i]) > 0.001)
            {
                test8Pass = false;
                break;
            }
        }
    }
    if (test8Pass)
    {
        cout << "Test 8 PASS: Divide doubles" << endl;
        passed++;
    }
    else
    {
        cout << "Test 8 FAIL: Expected {5.0, 4.0, 3.0}, Got {";
        for (size_t i = 0; i < result8.size(); i++)
        {
            cout << result8[i];
            if (i < result8.size() - 1)
                cout << ", ";
        }
        cout << "}" << endl;
    }

    cout << "Problem A4 Results: " << passed << "/" << total << " tests passed" << endl
         << endl;
}

void testProblemA5()
{
    cout << "Testing Problem A5 - Mastery Challenge (Filter and Transform)..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Filter > 2 and multiply by 2
    // Manual calculation: {1,2,3,4,5} -> filter >2 -> {3,4,5} -> *2 -> {6,8,10}
    // Expected: {6, 8, 10}
    total++;
    vector<int> test1 = {1, 2, 3, 4, 5};
    auto result1 = problemA5Solution(test1, [](int x)
                                     { return x > 2; }, [](int x)
                                     { return x * 2; });
    vector<int> expected1 = {6, 8, 10};
    if (result1 == expected1)
    {
        cout << "Test 1 PASS: Filter >2 and multiply by 2" << endl;
        passed++;
    }
    else
    {
        cout << "Test 1 FAIL: Expected {6, 8, 10}, Got {";
        for (size_t i = 0; i < result1.size(); i++)
        {
            cout << result1[i];
            if (i < result1.size() - 1)
                cout << ", ";
        }
        cout << "}" << endl;
    }

    // Test Case 2: Filter even numbers and square
    // Manual calculation: {1,2,3,4,5,6} -> filter even -> {2,4,6} -> square -> {4,16,36}
    // Expected: {4, 16, 36}
    total++;
    vector<int> test2 = {1, 2, 3, 4, 5, 6};
    auto result2 = problemA5Solution(test2, [](int x)
                                     { return x % 2 == 0; }, [](int x)
                                     { return x * x; });
    vector<int> expected2 = {4, 16, 36};
    if (result2 == expected2)
    {
        cout << "Test 2 PASS: Filter even and square" << endl;
        passed++;
    }
    else
    {
        cout << "Test 2 FAIL: Expected {4, 16, 36}, Got {";
        for (size_t i = 0; i < result2.size(); i++)
        {
            cout << result2[i];
            if (i < result2.size() - 1)
                cout << ", ";
        }
        cout << "}" << endl;
    }

    // Test Case 3: Filter strings length > 1 and return length
    // Manual calculation: {"a","bb","ccc"} -> filter len>1 -> {"bb","ccc"} -> len -> {2, 3}
    // Expected: {2, 3}
    total++;
    vector<string> test3 = {"a", "bb", "ccc"};
    auto result3 = problemA5Solution(test3, [](const string &s)
                                     { return s.size() > 1; }, [](const string &s)
                                     { return static_cast<int>(s.size()); });
    vector<int> expected3 = {2, 3};
    if (result3 == expected3)
    {
        cout << "Test 3 PASS: Filter string length >1 and get length" << endl;
        passed++;
    }
    else
    {
        cout << "Test 3 FAIL: Expected {2, 3}, Got {";
        for (size_t i = 0; i < result3.size(); i++)
        {
            cout << result3[i];
            if (i < result3.size() - 1)
                cout << ", ";
        }
        cout << "}" << endl;
    }

    // Test Case 4: Filter negative numbers and negate
    // Manual calculation: {-5, 3, -2, 7, -1} -> filter <0 -> {-5,-2,-1} -> negate -> {5, 2, 1}
    // Expected: {5, 2, 1}
    total++;
    vector<int> test4 = {-5, 3, -2, 7, -1};
    auto result4 = problemA5Solution(test4, [](int x)
                                     { return x < 0; }, [](int x)
                                     { return -x; });
    vector<int> expected4 = {5, 2, 1};
    if (result4 == expected4)
    {
        cout << "Test 4 PASS: Filter negative and negate" << endl;
        passed++;
    }
    else
    {
        cout << "Test 4 FAIL: Expected {5, 2, 1}, Got {";
        for (size_t i = 0; i < result4.size(); i++)
        {
            cout << result4[i];
            if (i < result4.size() - 1)
                cout << ", ";
        }
        cout << "}" << endl;
    }

    // Test Case 5: No elements pass filter
    // Manual calculation: {1,2,3} -> filter >10 -> {} -> transform -> {}
    // Expected: {}
    total++;
    vector<int> test5 = {1, 2, 3};
    auto result5 = problemA5Solution(test5, [](int x)
                                     { return x > 10; }, [](int x)
                                     { return x * 2; });
    vector<int> expected5 = {};
    if (result5 == expected5)
    {
        cout << "Test 5 PASS: No elements pass filter" << endl;
        passed++;
    }
    else
    {
        cout << "Test 5 FAIL: Expected empty vector, Got size " << result5.size() << endl;
    }

    // Test Case 6: All elements pass filter
    // Manual calculation: {1,2,3,4} -> filter >=1 -> {1,2,3,4} -> +10 -> {11,12,13,14}
    // Expected: {11, 12, 13, 14}
    total++;
    vector<int> test6 = {1, 2, 3, 4};
    auto result6 = problemA5Solution(test6, [](int x)
                                     { return x >= 1; }, [](int x)
                                     { return x + 10; });
    vector<int> expected6 = {11, 12, 13, 14};
    if (result6 == expected6)
    {
        cout << "Test 6 PASS: All elements pass filter" << endl;
        passed++;
    }
    else
    {
        cout << "Test 6 FAIL: Expected {11, 12, 13, 14}, Got {";
        for (size_t i = 0; i < result6.size(); i++)
        {
            cout << result6[i];
            if (i < result6.size() - 1)
                cout << ", ";
        }
        cout << "}" << endl;
    }

    // Test Case 7: Filter doubles > 2.5 and halve
    // Manual calculation: {1.0, 2.5, 3.0, 4.5} -> filter >2.5 -> {3.0, 4.5} -> /2 -> {1.5, 2.25}
    // Expected: {1.5, 2.25}
    total++;
    vector<double> test7 = {1.0, 2.5, 3.0, 4.5};
    auto result7 = problemA5Solution(test7, [](double x)
                                     { return x > 2.5; }, [](double x)
                                     { return x / 2.0; });
    vector<double> expected7 = {1.5, 2.25};
    bool test7Pass = true;
    if (result7.size() != expected7.size())
        test7Pass = false;
    else
    {
        for (size_t i = 0; i < result7.size(); i++)
        {
            if (abs(result7[i] - expected7[i]) > 0.001)
            {
                test7Pass = false;
                break;
            }
        }
    }
    if (test7Pass)
    {
        cout << "Test 7 PASS: Filter doubles and halve" << endl;
        passed++;
    }
    else
    {
        cout << "Test 7 FAIL: Expected {1.5, 2.25}, Got {";
        for (size_t i = 0; i < result7.size(); i++)
        {
            cout << result7[i];
            if (i < result7.size() - 1)
                cout << ", ";
        }
        cout << "}" << endl;
    }

    // Test Case 8: Complex transformation
    // Manual calculation: {10, 20, 30, 40, 50} -> filter divisible by 20 -> {20, 40} -> /10 -> {2, 4}
    // Expected: {2, 4}
    total++;
    vector<int> test8 = {10, 20, 30, 40, 50};
    auto result8 = problemA5Solution(test8, [](int x)
                                     { return x % 20 == 0; }, [](int x)
                                     { return x / 10; });
    vector<int> expected8 = {2, 4};
    if (result8 == expected8)
    {
        cout << "Test 8 PASS: Complex transformation" << endl;
        passed++;
    }
    else
    {
        cout << "Test 8 FAIL: Expected {2, 4}, Got {";
        for (size_t i = 0; i < result8.size(); i++)
        {
            cout << result8[i];
            if (i < result8.size() - 1)
                cout << ", ";
        }
        cout << "}" << endl;
    }

    cout << "Problem A5 Results: " << passed << "/" << total << " tests passed" << endl
         << endl;
}

void testProblemA6()
{
    cout << "Testing Problem A6 - Expert Application (Generic Algorithm Library)..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: AggregateIf - sum of even numbers
    // Manual calculation: {1,2,3,4,5} -> filter even -> {2,4} -> sum -> 2+4 = 6
    // Expected: 6
    total++;
    vector<int> test1 = {1, 2, 3, 4, 5};
    auto result1 = problemA6AggregateIf(test1, [](int x)
                                        { return x % 2 == 0; }, "sum");
    if (result1 == 6)
    {
        cout << "Test 1 PASS: Sum of even numbers" << endl;
        passed++;
    }
    else
    {
        cout << "Test 1 FAIL: Expected 6, Got " << result1 << endl;
    }

    // Test Case 2: AggregateIf - product of numbers > 2
    // Manual calculation: {2,3,4} -> filter >2 -> {3,4} -> product -> 3*4 = 12
    // Expected: 12
    total++;
    vector<int> test2 = {2, 3, 4};
    auto result2 = problemA6AggregateIf(test2, [](int x)
                                        { return x > 2; }, "product");
    if (result2 == 12)
    {
        cout << "Test 2 PASS: Product of numbers >2" << endl;
        passed++;
    }
    else
    {
        cout << "Test 2 FAIL: Expected 12, Got " << result2 << endl;
    }

    // Test Case 3: AggregateIf - sum of all positive
    // Manual calculation: {-5, 10, -3, 20, 30} -> filter >0 -> {10,20,30} -> sum -> 60
    // Expected: 60
    total++;
    vector<int> test3 = {-5, 10, -3, 20, 30};
    auto result3 = problemA6AggregateIf(test3, [](int x)
                                        { return x > 0; }, "sum");
    if (result3 == 60)
    {
        cout << "Test 3 PASS: Sum of positive numbers" << endl;
        passed++;
    }
    else
    {
        cout << "Test 3 FAIL: Expected 60, Got " << result3 << endl;
    }

    // Test Case 4: AggregateIf - product with doubles
    // Manual calculation: {1.5, 2.0, 3.0, 4.0} -> filter >=2.0 -> {2.0, 3.0, 4.0} -> product -> 24.0
    // Expected: 24.0
    total++;
    vector<double> test4 = {1.5, 2.0, 3.0, 4.0};
    auto result4 = problemA6AggregateIf(test4, [](double x)
                                        { return x >= 2.0; }, "product");
    if (abs(result4 - 24.0) < 0.001)
    {
        cout << "Test 4 PASS: Product of doubles >=2.0" << endl;
        passed++;
    }
    else
    {
        cout << "Test 4 FAIL: Expected 24.0, Got " << result4 << endl;
    }

    // Test Case 5: FindPattern - simple pattern
    // Manual calculation: {1,2,3,2,3,4} -> find {2,3} -> appears at indices 1 and 3
    // Expected: {1, 3}
    total++;
    vector<int> test5 = {1, 2, 3, 2, 3, 4};
    vector<int> pattern5 = {2, 3};
    auto result5 = problemA6FindPattern(test5, pattern5);
    vector<int> expected5 = {1, 3};
    if (result5 == expected5)
    {
        cout << "Test 5 PASS: Find pattern {2,3}" << endl;
        passed++;
    }
    else
    {
        cout << "Test 5 FAIL: Expected {1, 3}, Got {";
        for (size_t i = 0; i < result5.size(); i++)
        {
            cout << result5[i];
            if (i < result5.size() - 1)
                cout << ", ";
        }
        cout << "}" << endl;
    }

    // Test Case 6: FindPattern - no match
    // Manual calculation: {1,2,3,4} -> find {5,6} -> no matches
    // Expected: {}
    total++;
    vector<int> test6 = {1, 2, 3, 4};
    vector<int> pattern6 = {5, 6};
    auto result6 = problemA6FindPattern(test6, pattern6);
    vector<int> expected6 = {};
    if (result6 == expected6)
    {
        cout << "Test 6 PASS: No pattern match" << endl;
        passed++;
    }
    else
    {
        cout << "Test 6 FAIL: Expected empty vector, Got size " << result6.size() << endl;
    }

    // Test Case 7: FindPattern - overlapping patterns
    // Manual calculation: {1,1,1,2} -> find {1,1} -> appears at indices 0 and 1
    // Expected: {0, 1}
    total++;
    vector<int> test7 = {1, 1, 1, 2};
    vector<int> pattern7 = {1, 1};
    auto result7 = problemA6FindPattern(test7, pattern7);
    vector<int> expected7 = {0, 1};
    if (result7 == expected7)
    {
        cout << "Test 7 PASS: Overlapping patterns" << endl;
        passed++;
    }
    else
    {
        cout << "Test 7 FAIL: Expected {0, 1}, Got {";
        for (size_t i = 0; i < result7.size(); i++)
        {
            cout << result7[i];
            if (i < result7.size() - 1)
                cout << ", ";
        }
        cout << "}" << endl;
    }

    // Test Case 8: TransformConditional - transform only elements >2
    // Manual calculation: {1,2,3,4} -> if >2 then *10 else keep -> {1, 2, 30, 40}
    // Expected: {1, 2, 30, 40}
    total++;
    vector<int> test8 = {1, 2, 3, 4};
    auto result8 = problemA6TransformConditional(test8, [](int x)
                                                 { return x > 2; }, [](int x)
                                                 { return x * 10; });
    vector<int> expected8 = {1, 2, 30, 40};
    if (result8 == expected8)
    {
        cout << "Test 8 PASS: Transform conditional >2" << endl;
        passed++;
    }
    else
    {
        cout << "Test 8 FAIL: Expected {1, 2, 30, 40}, Got {";
        for (size_t i = 0; i < result8.size(); i++)
        {
            cout << result8[i];
            if (i < result8.size() - 1)
                cout << ", ";
        }
        cout << "}" << endl;
    }

    // Test Case 9: TransformConditional - transform even numbers
    // Manual calculation: {1,2,3,4,5,6} -> if even then square else keep -> {1, 4, 3, 16, 5, 36}
    // Expected: {1, 4, 3, 16, 5, 36}
    total++;
    vector<int> test9 = {1, 2, 3, 4, 5, 6};
    auto result9 = problemA6TransformConditional(test9, [](int x)
                                                 { return x % 2 == 0; }, [](int x)
                                                 { return x * x; });
    vector<int> expected9 = {1, 4, 3, 16, 5, 36};
    if (result9 == expected9)
    {
        cout << "Test 9 PASS: Transform even numbers conditionally" << endl;
        passed++;
    }
    else
    {
        cout << "Test 9 FAIL: Expected {1, 4, 3, 16, 5, 36}, Got {";
        for (size_t i = 0; i < result9.size(); i++)
        {
            cout << result9[i];
            if (i < result9.size() - 1)
                cout << ", ";
        }
        cout << "}" << endl;
    }

    // Test Case 10: FindPattern - single element pattern
    // Manual calculation: {5,3,7,3,9,3} -> find {3} -> appears at indices 1, 3, 5
    // Expected: {1, 3, 5}
    total++;
    vector<int> test10 = {5, 3, 7, 3, 9, 3};
    vector<int> pattern10 = {3};
    auto result10 = problemA6FindPattern(test10, pattern10);
    vector<int> expected10 = {1, 3, 5};
    if (result10 == expected10)
    {
        cout << "Test 10 PASS: Single element pattern" << endl;
        passed++;
    }
    else
    {
        cout << "Test 10 FAIL: Expected {1, 3, 5}, Got {";
        for (size_t i = 0; i < result10.size(); i++)
        {
            cout << result10[i];
            if (i < result10.size() - 1)
                cout << ", ";
        }
        cout << "}" << endl;
    }

    // Test Case 11: AggregateIf - no elements match predicate
    // Manual calculation: {1,2,3} -> filter >10 -> {} -> sum -> 0
    // Expected: 0
    total++;
    vector<int> test11 = {1, 2, 3};
    auto result11 = problemA6AggregateIf(test11, [](int x)
                                         { return x > 10; }, "sum");
    if (result11 == 0)
    {
        cout << "Test 11 PASS: No elements match - sum returns 0" << endl;
        passed++;
    }
    else
    {
        cout << "Test 11 FAIL: Expected 0, Got " << result11 << endl;
    }

    // Test Case 12: AggregateIf - product with no matches
    // Manual calculation: {1,2,3} -> filter >10 -> {} -> product -> 1 (identity for multiplication)
    // Expected: 1
    total++;
    vector<int> test12 = {1, 2, 3};
    auto result12 = problemA6AggregateIf(test12, [](int x)
                                         { return x > 10; }, "product");
    if (result12 == 1)
    {
        cout << "Test 12 PASS: No elements match - product returns 1" << endl;
        passed++;
    }
    else
    {
        cout << "Test 12 FAIL: Expected 1, Got " << result12 << endl;
    }

    cout << "Problem A6 Results: " << passed << "/" << total << " tests passed" << endl
         << endl;
}

void runAllTests()
{
    cout << "\n=== RUNNING ALL INTEGRATION PROBLEM TESTS ===" << endl
         << endl;
    testProblemA1();
    testProblemA2();
    testProblemA3();
    testProblemA4();
    testProblemA5();
    testProblemA6();
    cout << "=== ALL TESTS COMPLETE ===" << endl;
}

int main()
{
    cout << "============================================" << endl;
    cout << "  CHAPTER 16: C++20 CONCEPTS ASSESSMENT" << endl;
    cout << "============================================" << endl
         << endl;

    cout << "This assessment tests your mastery of:" << endl;
    cout << "- Standard C++20 concepts (integral, floating_point, etc.)" << endl;
    cout << "- Creating custom concepts" << endl;
    cout << "- Using requires clauses" << endl;
    cout << "- Combining concepts with logical operators" << endl;
    cout << "- Concepts with auto parameters" << endl;
    cout << "- Integration with templates and lambdas" << endl
         << endl;

    cout << "Choose your assessment mode:" << endl
         << endl;

    cout << "SECTION A: INTEGRATION PROBLEMS" << endl;
    cout << "1. Problem A1 - Foundation Integration (Easy)" << endl;
    cout << "   Generic container statistics with concept constraints" << endl;
    cout << "2. Problem A2 - Intermediate Synthesis (Easy-Medium)" << endl;
    cout << "   Concept-constrained function overloading" << endl;
    cout << "3. Problem A3 - Advanced Integration (Medium)" << endl;
    cout << "   Custom concept builder (Sortable + Container)" << endl;
    cout << "4. Problem A4 - Complex Synthesis (Medium-Hard)" << endl;
    cout << "   Requires clause with compound requirements" << endl;
    cout << "5. Problem A5 - Mastery Challenge (Hard)" << endl;
    cout << "   Combining concepts with auto parameters" << endl;
    cout << "6. Problem A6 - Expert Application (Very Hard)" << endl;
    cout << "   Generic algorithm library with concept composition" << endl;
    cout << "7. Test All Integration Problems" << endl
         << endl;

    cout << "SECTION B: KNOWLEDGE VALIDATION" << endl;
    cout << "8. Chapter Knowledge Quiz (15 questions)" << endl
         << endl;

    cout << "COMPREHENSIVE ASSESSMENT" << endl;
    cout << "9. Full Chapter Assessment (All problems + Quiz)" << endl
         << endl;

    int choice;
    cout << "Enter your choice (1-9): ";
    cin >> choice;
    cout << endl;

    switch (choice)
    {
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
        cout << "\n============================================" << endl;
        cout << "  STARTING KNOWLEDGE QUIZ" << endl;
        cout << "============================================" << endl
             << endl;
        knowledgeQuiz();
        break;
    default:
        cout << "Invalid choice! Please run the program again and select 1-9." << endl;
    }

    cout << "\n============================================" << endl;
    cout << "  ASSESSMENT SESSION COMPLETE" << endl;
    cout << "============================================" << endl;
    cout << "Remember: Concepts make templates safer and more expressive!" << endl;
    cout << "Good luck with your C++20 journey!" << endl;

    return 0;
}