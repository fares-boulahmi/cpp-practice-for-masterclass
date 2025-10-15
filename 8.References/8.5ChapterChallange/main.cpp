#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <climits>

using namespace std;

//=== SECTION A: INTEGRATION PROBLEMS ===

// Problem A1: Foundation Integration - Reference Swap and Compare
// Difficulty: Easy
// Concepts: Declaring references, using references to modify values, comparing references vs pointers
//
// Create a function that swaps two integers using references and another function that
// checks if two references refer to the same variable.
//
// Example 1:
// Input: int a = 5, b = 10
// After swapByReference(a, b): a = 10, b = 5
//
// Example 2:
// Input: int x = 7, y = 3
// areSameVariable(x, x) returns true
// areSameVariable(x, y) returns false
//
// Constraints:
// - Must use references, not pointers
// - No temporary variables allowed in swap (use XOR or arithmetic)
// - areSameVariable must check memory addresses

void swapByReference(int &a, int &b)
{
    // TODO: Implement swap using references without temporary variable
    // Hint: Use arithmetic operations (a = a + b, b = a - b, a = a - b)
    a = a + b;
    b = a - b;
    a = a - b;
}

bool areSameVariable(int &ref1, int &ref2)
{
    // TODO: Check if two references point to the same variable
    // Hint: Compare memory addresses using & operator
    bool compare_ref{false};
    if (ref1 == ref2)
    {
        compare_ref = true;
    }

    return compare_ref;
}

// Problem A2: Intermediate Synthesis - Array Reference Processor
// Difficulty: Easy-Medium
// Concepts: References with arrays, const references, reference parameters for efficiency
//
// Create functions to process arrays using references:
// 1. findMinMax - finds minimum and maximum values in array using output reference parameters
// 2. normalizeArray - normalizes array values to 0-100 range (modifies original array)
// 3. calculateStats - calculates mean and standard deviation using const reference for input
//
// Example:
// Input array: [10, 50, 30, 90, 20]
// findMinMax output: min=10, max=90
// After normalizeArray: [0, 50, 25, 100, 12.5] (scaled to 0-100)
// calculateStats: mean=40, stddev=28.28
//
// Constraints:
// - Use references for all array parameters
// - Use const references where data shouldn't be modified
// - Output parameters must use references

void findMinMax(const int arr[], int size, int &minVal, int &maxVal)
{
    // TODO: Find min and max values, store in reference parameters
    // Hint: Iterate through array, update minVal and maxVal references
    minVal = INT_MAX;
    maxVal = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
        if (arr[i] < minVal)
        {
            minVal = arr[i];
        }
    }
}

void normalizeArray(int arr[], int size)
{
    // TODO: Normalize array values to 0-100 range based on min/max
    // Hint: First find min/max, then apply formula: (value - min) * 100 / (max - min)
    int min = INT_MAX;
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = (arr[i] - min) * 100 / (max - min);
    }
}

void calculateStats(const int arr[], int size, double &mean, double &stddev)
{
    // TODO: Calculate mean and standard deviation using const reference input
    // Hint: mean = sum/size, stddev = sqrt(sum((x - mean)^2) / size)
    /* 
        THE  STDDEV CALC BY STEPS 
        - is the sum of arr
        - the mean ( the mean is the sum/size (in other word the average))
        - to calc the Subtract the mean from each number and square the result:
            - what that mean is every element - mean  the result ^ 2 . 
        - then the root of the above in most lang is sqrt(result)
        - import info the mean and subtract must be double beside that the result will be false .
    */
    // first step calc the mean 
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    mean = sum / size;

    // second step calc Subtract the mean from each number and square the result:
    
    double  sumSquaredDifferences = 0;
    for (int i = 0; i < size; ++i)
    {
        double temp = arr[i] - mean;
        sumSquaredDifferences += temp * temp;
    }
    sumSquaredDifferences = sumSquaredDifferences/size;

    // final step the stddev
    stddev = sqrt(sumSquaredDifferences);
}

// Problem A3: Advanced Integration - Reference-Based Data Structure
// Difficulty: Medium
// Concepts: References in classes, returning references, reference members, const references
//
// Create a SimpleVector class that manages dynamic arrays and uses references extensively:
// - Constructor with size
// - at(index) returns reference to element (allows modification)
// - at(index) const returns const reference (read-only)
// - front() and back() return references to first/last elements
// - setAll(const int& value) sets all elements using const reference
//
// Example:
// SimpleVector vec(5);
// vec.at(0) = 10;  // Modifies element through reference
// vec.front() = 20; // Modifies first element
// int x = 5;
// vec.setAll(x); // All elements become 5
//
// Constraints:
// - Must use dynamic memory allocation
// - at() must throw error for invalid indices
// - Must handle const correctness properly

class SimpleVector
{
private:
    int *data;
    int size;

public:
    SimpleVector(int s) : size(s)
    {
        // TODO: Allocate dynamic array
    }

    ~SimpleVector()
    {
        // TODO: Deallocate memory
    }

    int &at(int index)
    {
        // TODO: Return reference to element at index (non-const version)
        // Hint: Check bounds, then return data[index]
        static int dummy = 0;
        return dummy;
    }

    const int &at(int index) const
    {
        // TODO: Return const reference to element at index (const version)
        static int dummy = 0;
        return dummy;
    }

    int &front()
    {
        // TODO: Return reference to first element
        static int dummy = 0;
        return dummy;
    }

    int &back()
    {
        // TODO: Return reference to last element
        static int dummy = 0;
        return dummy;
    }

    void setAll(const int &value)
    {
        // TODO: Set all elements to value using const reference
    }

    int getSize() const { return size; }
};

// Problem A4: Complex Synthesis - Reference Chain and Aliasing
// Difficulty: Medium-Hard
// Concepts: Reference aliasing, references to references (through variables),
//           const references with pointers, dangling reference prevention
//
// Create a function that demonstrates complex reference relationships:
// 1. createReferenceChain - creates a chain of references to the same variable
// 2. modifyThroughChain - modifies original value through any reference in chain
// 3. detectAliasing - detects if multiple references alias the same memory
//
// Example:
// int original = 100;
// int& ref1 = original;
// int& ref2 = ref1;
// int& ref3 = ref2;
// All references modify the same original variable
//
// Constraints:
// - Must demonstrate reference aliasing
// - Must show how const references prevent modification
// - Must validate all references point to same memory

struct ReferenceChain
{
    int *addresses[10];
    int count;

    ReferenceChain() : count(0) {}
};

void createReferenceChain(int &original, ReferenceChain &chain)
{
    // TODO: Create multiple reference aliases and store their addresses
    // Hint: Create int& ref1 = original, int& ref2 = ref1, etc.
    //       Store addresses using &ref1, &ref2 in chain.addresses
}

void modifyThroughChain(int &anyRef, int newValue)
{
    // TODO: Modify value through reference, demonstrating aliasing
}

bool detectAliasing(const ReferenceChain &chain)
{
    // TODO: Check if all addresses in chain are identical
    // Hint: Compare all addresses to addresses[0]
    return false;
}

// Problem A5: Mastery Challenge - Reference-Based Smart Cache
// Difficulty: Hard
// Concepts: All reference concepts + dynamic memory + previous chapters (arrays, pointers, loops)
//
// Implement a caching system that stores references to frequently accessed data:
// - Cache stores references to external data (not copies)
// - get() returns const reference to cached data
// - update() updates cache using reference parameter
// - invalidate() marks cached reference as invalid
// - Uses reference counting to track usage
//
// Example:
// int data1 = 100, data2 = 200;
// ReferenceCache cache;
// cache.add("key1", data1);
// const int& val = cache.get("key1"); // Returns reference to data1
// data1 = 150; // Cache automatically reflects change
//
// Constraints:
// - Cache must store references, not copies
// - Must handle const correctness
// - Must prevent dangling references
// - Maximum 10 cache entries

struct CacheEntry
{
    string key;
    int *dataPtr; // Pointer to referenced data
    int accessCount;
    bool valid;
};

class ReferenceCache
{
private:
    CacheEntry entries[10];
    int entryCount;

public:
    ReferenceCache() : entryCount(0)
    {
        for (int i = 0; i < 10; i++)
        {
            entries[i].valid = false;
            entries[i].accessCount = 0;
            entries[i].dataPtr = nullptr;
        }
    }

    bool add(const string &key, int &data)
    {
        // TODO: Add reference to data with given key
        // Hint: Store &data in dataPtr, mark as valid
        return false;
    }

    const int &get(const string &key)
    {
        // TODO: Return const reference to cached data, increment access count
        // Hint: Find entry by key, increment accessCount, return *dataPtr
        static int dummy = 0;
        return dummy;
    }

    void update(const string &key, int &newData)
    {
        // TODO: Update cache entry to reference new data
    }

    void invalidate(const string &key)
    {
        // TODO: Mark cache entry as invalid
    }

    int getAccessCount(const string &key) const
    {
        // TODO: Return access count for given key
        return 3;
    }
};

// Problem A6: Expert Application - Reference-Based Expression Evaluator
// Difficulty: Very Hard
// Concepts: All Chapter 9 + Chapter 5 (conditionals) + Chapter 6 (loops) + Chapter 8 (pointers/memory)
//
// Create an expression evaluator that uses references for variable binding:
// - Supports variables that reference actual int storage
// - evaluate() evaluates expressions with variable references
// - Variables in expression are bound to actual memory locations
// - Changing referenced value changes evaluation result
//
// Example:
// int x = 5, y = 10;
// ExpressionEvaluator eval;
// eval.bindVariable("x", x);
// eval.bindVariable("y", y);
// eval.evaluate("x + y") returns 15
// x = 20;
// eval.evaluate("x + y") now returns 30 (reference reflects change)
//
// Supported operations: +, -, *, / with variables and constants
//
// Constraints:
// - Must use references for variable binding
// - Must support at least 5 variables
// - Must handle const references for evaluation
// - Must parse simple arithmetic expressions

struct Variable
{
    string name;
    int *valuePtr;
};

class ExpressionEvaluator
{
private:
    Variable variables[5];
    int varCount;

    int findVariable(const string &name) const
    {
        // Helper to find variable index
        for (int i = 0; i < varCount; i++)
        {
            if (variables[i].name == name)
                return i;
        }
        return -1;
    }

    bool isOperator(char c) const
    {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

public:
    ExpressionEvaluator() : varCount(0) {}

    void bindVariable(const string &name, int &value)
    {
        // TODO: Bind variable name to reference of value
        // Hint: Store &value in variables[varCount].valuePtr
    }

    int evaluate(const string &expression) const
    {
        // TODO: Parse and evaluate expression using variable references
        // Hint: Parse expression, look up variable values through pointers
        // Simple parser: support "var1 op var2" or "var op num" format
        return 3;
    }

    void updateBinding(const string &name, int &newValue)
    {
        // TODO: Update variable to reference different memory location
    }

    int getVariableValue(const string &name) const
    {
        // TODO: Return current value of variable through its reference
        return 5;
    }
};

//=== SECTION B: KNOWLEDGE VALIDATION QUIZ ===

void knowledgeQuiz()
{
    cout << "\n=== CHAPTER 9: REFERENCES KNOWLEDGE QUIZ ===" << endl;
    cout << "Answer each question and check your understanding:\n"
         << endl;

    int score = 0;
    char answer;

    // Question 1: Core Concept Definition
    cout << "Q1: What is a reference in C++?" << endl;
    cout << "A) A pointer that can be null" << endl;
    cout << "B) An alias for an existing variable" << endl;
    cout << "C) A copy of a variable" << endl;
    cout << "D) A new variable with the same value" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b')
    {
        score++;
        cout << "✓ CORRECT!" << endl;
    }
    else
    {
        cout << "✗ INCORRECT" << endl;
    }
    cout << "Correct Answer: B - A reference is an alias (another name) for an existing variable." << endl;
    cout << "It's not a new variable or copy; it refers to the same memory location.\n"
         << endl;

    // Question 2: Syntax and Declaration
    cout << "Q2: Which declaration is CORRECT for creating a reference?" << endl;
    cout << "A) int& ref;  // Uninitialized reference" << endl;
    cout << "B) int &ref = x;  // Reference to x" << endl;
    cout << "C) int* ref = &x;  // Reference to x" << endl;
    cout << "D) int ref& = x;  // Reference to x" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b')
    {
        score++;
        cout << "✓ CORRECT!" << endl;
    }
    else
    {
        cout << "✗ INCORRECT" << endl;
    }
    cout << "Correct Answer: B - References MUST be initialized when declared (int& ref = x)." << endl;
    cout << "Option A fails because references cannot be uninitialized. Option C is a pointer, not reference.\n"
         << endl;

    // Question 3: References vs Pointers
    cout << "Q3: What is a key difference between references and pointers?" << endl;
    cout << "A) References can be null, pointers cannot" << endl;
    cout << "B) Pointers use more memory than references" << endl;
    cout << "C) References must be initialized and cannot be reassigned" << endl;
    cout << "D) Pointers are faster than references" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'C' || answer == 'c')
    {
        score++;
        cout << "✓ CORRECT!" << endl;
    }
    else
    {
        cout << "✗ INCORRECT" << endl;
    }
    cout << "Correct Answer: C - References MUST be initialized at declaration and cannot be changed" << endl;
    cout << "to refer to a different variable. Pointers can be null and reassigned.\n"
         << endl;

    // Question 4: Const References
    cout << "Q4: What does 'const int& ref = x' mean?" << endl;
    cout << "A) x cannot be modified through ref, but x itself can change" << endl;
    cout << "B) x cannot be modified at all" << endl;
    cout << "C) ref can be reassigned to another variable" << endl;
    cout << "D) ref is a constant integer" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'A' || answer == 'a')
    {
        score++;
        cout << "✓ CORRECT!" << endl;
    }
    else
    {
        cout << "✗ INCORRECT" << endl;
    }
    cout << "Correct Answer: A - 'const int&' means you cannot modify the value THROUGH this reference," << endl;
    cout << "but the original variable can still be modified through other means.\n"
         << endl;

    // Question 5: Function Parameters
    cout << "Q5: Why use 'const reference' parameters instead of 'pass by value'?" << endl;
    cout << "A) To allow modification of the argument" << endl;
    cout << "B) To avoid copying large objects while preventing modification" << endl;
    cout << "C) To make the function run faster" << endl;
    cout << "D) To allow null values" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b')
    {
        score++;
        cout << "✓ CORRECT!" << endl;
    }
    else
    {
        cout << "✗ INCORRECT" << endl;
    }
    cout << "Correct Answer: B - const references avoid expensive copying of large objects" << endl;
    cout << "(like strings, vectors) while preventing accidental modification. Best of both worlds!\n"
         << endl;

    // Question 6: Reference Initialization
    cout << "Q6: Can you create a reference to a literal value?" << endl;
    cout << "A) Yes, any reference: int& ref = 5;" << endl;
    cout << "B) No, never allowed" << endl;
    cout << "C) Yes, but only const references: const int& ref = 5;" << endl;
    cout << "D) Yes, but only with pointers" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'C' || answer == 'c')
    {
        score++;
        cout << "✓ CORRECT!" << endl;
    }
    else
    {
        cout << "✗ INCORRECT" << endl;
    }
    cout << "Correct Answer: C - Only CONST references can bind to literals/temporaries." << endl;
    cout << "The compiler creates a temporary variable that lives as long as the const reference.\n"
         << endl;

    // Question 7: Dangling References
    cout << "Q7: What is a dangling reference?" << endl;
    cout << "A) A reference that wasn't initialized" << endl;
    cout << "B) A reference to memory that has been deallocated or destroyed" << endl;
    cout << "C) A reference that points to null" << endl;
    cout << "D) A reference with const qualifier" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b')
    {
        score++;
        cout << "✓ CORRECT!" << endl;
    }
    else
    {
        cout << "✗ INCORRECT" << endl;
    }
    cout << "Correct Answer: B - A dangling reference refers to memory that no longer exists," << endl;
    cout << "like a local variable that went out of scope. Using it causes undefined behavior!\n"
         << endl;

    // Question 8: Return by Reference
    cout << "Q8: When should you return a reference from a function?" << endl;
    cout << "A) Always, it's more efficient" << endl;
    cout << "B) When returning a local variable" << endl;
    cout << "C) When returning an object that exists outside the function scope" << endl;
    cout << "D) Never, always return by value" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'C' || answer == 'c')
    {
        score++;
        cout << "✓ CORRECT!" << endl;
    }
    else
    {
        cout << "✗ INCORRECT" << endl;
    }
    cout << "Correct Answer: C - Only return references to objects that will continue to exist" << endl;
    cout << "after the function returns (class members, global variables, parameters, etc.).\n"
         << endl;

    // Question 9: Reference Assignment
    cout << "Q9: What happens with 'int& r1 = x; int& r2 = y; r1 = r2;'?" << endl;
    cout << "A) r1 now refers to y" << endl;
    cout << "B) The value of y is copied to x" << endl;
    cout << "C) Compilation error" << endl;
    cout << "D) r2 now refers to x" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b')
    {
        score++;
        cout << "✓ CORRECT!" << endl;
    }
    else
    {
        cout << "✗ INCORRECT" << endl;
    }
    cout << "Correct Answer: B - You CANNOT reassign what a reference refers to!" << endl;
    cout << "'r1 = r2' copies the VALUE of y into x. r1 still refers to x, r2 still refers to y.\n"
         << endl;

    // Question 10: Reference Size
    cout << "Q10: What is the size of a reference?" << endl;
    cout << "A) Always 1 byte" << endl;
    cout << "B) Same as the referenced type" << endl;
    cout << "C) Depends on compiler implementation (typically same as pointer)" << endl;
    cout << "D) References have no size" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'C' || answer == 'c')
    {
        score++;
        cout << "✓ CORRECT!" << endl;
    }
    else
    {
        cout << "✗ INCORRECT" << endl;
    }
    cout << "Correct Answer: C - While references are conceptually aliases, compilers typically" << endl;
    cout << "implement them as pointers internally, so sizeof(reference) often equals sizeof(pointer).\n"
         << endl;

    // Question 11: Multiple References
    cout << "Q11: Can multiple references refer to the same variable?" << endl;
    cout << "A) No, only one reference per variable" << endl;
    cout << "B) Yes, unlimited references can alias the same variable" << endl;
    cout << "C) Yes, but maximum 2 references" << endl;
    cout << "D) Only if they're const references" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b')
    {
        score++;
        cout << "✓ CORRECT!" << endl;
    }
    else
    {
        cout << "✗ INCORRECT" << endl;
    }
    cout << "Correct Answer: B - You can create unlimited references to the same variable." << endl;
    cout << "They all refer to the same memory location. Changes through any reference affect all.\n"
         << endl;

    // Question 12: References and Arrays
    cout << "Q12: How do you pass an array by reference to a function?" << endl;
    cout << "A) void func(int& arr[]) { }" << endl;
    cout << "B) void func(int (&arr)[10]) { }  // Array of 10 ints" << endl;
    cout << "C) void func(int* arr) { }  // This is by reference" << endl;
    cout << "D) Arrays cannot be passed by reference" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b')
    {
        score++;
        cout << "✓ CORRECT!" << endl;
    }
    else
    {
        cout << "✗ INCORRECT" << endl;
    }
    cout << "Correct Answer: B - Array references require specific size: int (&arr)[SIZE]" << endl;
    cout << "The parentheses are crucial! This preserves array size information.\n"
         << endl;

    // Question 13: Const Correctness
    cout << "Q13: Which is correct for a function that doesn't modify its string parameter?" << endl;
    cout << "A) void func(string str)" << endl;
    cout << "B) void func(const string& str)" << endl;
    cout << "C) void func(string* str)" << endl;
    cout << "D) void func(const string str)" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b')
    {
        score++;
        cout << "✓ CORRECT!" << endl;
    }
    else
    {
        cout << "✗ INCORRECT" << endl;
    }
    cout << "Correct Answer: B - 'const string&' avoids copying AND prevents modification." << endl;
    cout << "This is the standard pattern for read-only access to objects in C++.\n"
         << endl;

    // Question 14: References in Loops
    cout << "Q14: What does 'for(auto& elem : vec)' do?" << endl;
    cout << "A) Creates copies of vector elements" << endl;
    cout << "B) Creates references to vector elements (can modify original)" << endl;
    cout << "C) Creates pointers to vector elements" << endl;
    cout << "D) Syntax error" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b')
    {
        score++;
        cout << "✓ CORRECT!" << endl;
    }
    else
    {
        cout << "✗ INCORRECT" << endl;
    }
    cout << "Correct Answer: B - Using 'auto&' in range-based for loop creates references," << endl;
    cout << "allowing you to modify the original vector elements. Use 'const auto&' for read-only.\n"
         << endl;

    // Question 15: Best Practices
    cout << "Q15: When should you prefer references over pointers?" << endl;
    cout << "A) When you need to reassign to different objects" << endl;
    cout << "B) When null values are needed" << endl;
    cout << "C) When you need a simple alias that always refers to valid object" << endl;
    cout << "D) When doing pointer arithmetic" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'C' || answer == 'c')
    {
        score++;
        cout << "✓ CORRECT!" << endl;
    }
    else
    {
        cout << "✗ INCORRECT" << endl;
    }
    cout << "Correct Answer: C - Use references when you need a simple, guaranteed-valid alias." << endl;
    cout << "Use pointers when you need null, reassignment, or pointer arithmetic. References are safer!\n"
         << endl;

    cout << "\n=== QUIZ COMPLETE ===" << endl;
    cout << "Your Score: " << score << "/15 (" << fixed << setprecision(1)
         << (score * 100.0 / 15) << "%)" << endl;

    if (score == 15)
        cout << "🏆 PERFECT! You've mastered references!" << endl;
    else if (score >= 12)
        cout << "⭐ EXCELLENT! Strong understanding of references!" << endl;
    else if (score >= 9)
        cout << "✓ GOOD! You understand the core concepts." << endl;
    else if (score >= 6)
        cout << "⚠ FAIR - Review the concepts you missed." << endl;
    else
        cout << "❌ NEEDS WORK - Please review Chapter 9 thoroughly." << endl;
}

//=== MANDATORY COMPLETE TEST FUNCTIONS ===

void testProblemA1()
{
    cout << "\n=== Testing Problem A1 - Foundation Integration ===" << endl;
    int passed = 0, total = 0;

    // Test Case 1: Basic swap
    // Manual calculation: a=5, b=10 -> swap -> a=10, b=5
    cout << "Test 1: Basic swap (5, 10)" << endl;
    total++;
    int a1 = 5, b1 = 10;
    swapByReference(a1, b1);
    if (a1 == 10 && b1 == 5)
    {
        cout << "  ✓ PASS - After swap: a=" << a1 << ", b=" << b1 << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - Expected: a=10, b=5, Got: a=" << a1 << ", b=" << b1 << endl;
    }

    // Test Case 2: Swap with negative numbers
    // Manual calculation: a=-15, b=23 -> swap -> a=23, b=-15
    cout << "Test 2: Swap with negative (-15, 23)" << endl;
    total++;
    int a2 = -15, b2 = 23;
    swapByReference(a2, b2);
    if (a2 == 23 && b2 == -15)
    {
        cout << "  ✓ PASS - After swap: a=" << a2 << ", b=" << b2 << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - Expected: a=23, b=-15, Got: a=" << a2 << ", b=" << b2 << endl;
    }

    // Test Case 3: Swap equal values
    // Manual calculation: a=7, b=7 -> swap -> a=7, b=7
    cout << "Test 3: Swap equal values (7, 7)" << endl;
    total++;
    int a3 = 7, b3 = 7;
    swapByReference(a3, b3);
    if (a3 == 7 && b3 == 7)
    {
        cout << "  ✓ PASS - After swap: a=" << a3 << ", b=" << b3 << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - Expected: a=7, b=7, Got: a=" << a3 << ", b=" << b3 << endl;
    }

    // Test Case 4: Same variable reference check (should be true)
    // Manual calculation: x and x have same address -> true
    cout << "Test 4: Same variable check (x, x)" << endl;
    total++;
    int x = 100;
    bool result4 = areSameVariable(x, x);
    if (result4 == true)
    {
        cout << "  ✓ PASS - Correctly identified same variable" << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - Expected: true, Got: " << result4 << endl;
    }

    // Test Case 5: Different variables (should be false)
    // Manual calculation: x and y have different addresses -> false
    cout << "Test 5: Different variables check (x, y)" << endl;
    total++;
    int y = 200;
    bool result5 = areSameVariable(x, y);
    if (result5 == false)
    {
        cout << "  ✓ PASS - Correctly identified different variables" << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - Expected: false, Got: " << result5 << endl;
    }

    // Test Case 6: Reference aliasing
    // Manual calculation: ref1 and ref2 both refer to x -> same address -> true
    cout << "Test 6: Reference aliasing check" << endl;
    total++;
    int &ref1 = x;
    int &ref2 = x;
    bool result6 = areSameVariable(ref1, ref2);
    if (result6 == true)
    {
        cout << "  ✓ PASS - Correctly identified aliased references" << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - Expected: true, Got: " << result6 << endl;
    }

    cout << "\nProblem A1 Results: " << passed << "/" << total << " tests passed" << endl;
    cout << "Success Rate: " << fixed << setprecision(1) << (passed * 100.0 / total) << "%" << endl;
}

void testProblemA2()
{
    cout << "\n=== Testing Problem A2 - Intermediate Synthesis ===" << endl;
    int passed = 0, total = 0;

    // Test Case 1: findMinMax basic array
    // Manual calculation: [10, 50, 30, 90, 20] -> min=10, max=90
    cout << "Test 1: findMinMax on [10, 50, 30, 90, 20]" << endl;
    total++;
    int arr1[] = {10, 50, 30, 90, 20};
    int min1, max1;
    findMinMax(arr1, 5, min1, max1);
    if (min1 == 10 && max1 == 90)
    {
        cout << "  ✓ PASS - min=" << min1 << ", max=" << max1 << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - Expected: min=10, max=90, Got: min=" << min1 << ", max=" << max1 << endl;
    }

    // Test Case 2: findMinMax with negative numbers
    // Manual calculation: [-5, -15, -3, -20, -1] -> min=-20, max=-1
    cout << "Test 2: findMinMax with negatives [-5, -15, -3, -20, -1]" << endl;
    total++;
    int arr2[] = {-5, -15, -3, -20, -1};
    int min2, max2;
    findMinMax(arr2, 5, min2, max2);
    if (min2 == -20 && max2 == -1)
    {
        cout << "  ✓ PASS - min=" << min2 << ", max=" << max2 << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - Expected: min=-20, max=-1, Got: min=" << min2 << ", max=" << max2 << endl;
    }

    // Test Case 3: normalizeArray basic
    // Manual calculation: [10, 50, 30, 90, 20] -> min=10, max=90, range=80
    // Normalized: (10-10)*100/80=0, (50-10)*100/80=50, (30-10)*100/80=25, (90-10)*100/80=100, (20-10)*100/80=12
    cout << "Test 3: normalizeArray on [10, 50, 30, 90, 20]" << endl;
    total++;
    int arr3[] = {10, 50, 30, 90, 20};
    normalizeArray(arr3, 5);
    if (arr3[0] == 0 && arr3[1] == 50 && arr3[2] == 25 && arr3[3] == 100 && arr3[4] == 12)
    {
        cout << "  ✓ PASS - Normalized: [" << arr3[0] << ", " << arr3[1] << ", " << arr3[2]
             << ", " << arr3[3] << ", " << arr3[4] << "]" << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - Expected: [0, 50, 25, 100, 12], Got: [" << arr3[0] << ", " << arr3[1]
             << ", " << arr3[2] << ", " << arr3[3] << ", " << arr3[4] << "]" << endl;
    }

    // Test Case 4: calculateStats basic
    // Manual calculation: [10, 20, 30, 40, 50]
    // mean = (10+20+30+40+50)/5 = 150/5 = 30
    // variance = ((10-30)^2 + (20-30)^2 + (30-30)^2 + (40-30)^2 + (50-30)^2)/5
    //          = (400 + 100 + 0 + 100 + 400)/5 = 1000/5 = 200
    // stddev = sqrt(200) ≈ 14.14
    cout << "Test 4: calculateStats on [10, 20, 30, 40, 50]" << endl;
    total++;
    int arr4[] = {10, 20, 30, 40, 50};
    double mean4, stddev4;
    calculateStats(arr4, 5, mean4, stddev4);
    if (abs(mean4 - 30.0) < 0.01 && abs(stddev4 - 14.14) < 0.1)
    {
        cout << "  ✓ PASS - mean=" << fixed << setprecision(2) << mean4
             << ", stddev=" << stddev4 << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - Expected: mean=30.00, stddev≈14.14, Got: mean="
             << mean4 << ", stddev=" << stddev4 << endl;
    }

    // Test Case 5: calculateStats single value
    // Manual calculation: [42] -> mean=42, stddev=0
    cout << "Test 5: calculateStats single value [42]" << endl;
    total++;
    int arr5[] = {42};
    double mean5, stddev5;
    calculateStats(arr5, 1, mean5, stddev5);
    if (abs(mean5 - 42.0) < 0.01 && abs(stddev5 - 0.0) < 0.01)
    {
        cout << "  ✓ PASS - mean=" << mean5 << ", stddev=" << stddev5 << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - Expected: mean=42, stddev=0, Got: mean="
             << mean5 << ", stddev=" << stddev5 << endl;
    }

    // Test Case 6: normalizeArray all same values
    // Manual calculation: [5, 5, 5] -> range=0, should handle division by zero
    // All should remain 5 or become 0 (implementation dependent)
    cout << "Test 6: normalizeArray with equal values [5, 5, 5]" << endl;
    total++;
    int arr6[] = {5, 5, 5};
    normalizeArray(arr6, 3);
    // Accept either all zeros or unchanged (both valid approaches to handle zero range)
    bool valid6 = (arr6[0] == 0 && arr6[1] == 0 && arr6[2] == 0) ||
                  (arr6[0] == 5 && arr6[1] == 5 && arr6[2] == 5);
    if (valid6)
    {
        cout << "  ✓ PASS - Handled equal values: [" << arr6[0] << ", "
             << arr6[1] << ", " << arr6[2] << "]" << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - Got: [" << arr6[0] << ", " << arr6[1] << ", " << arr6[2] << "]" << endl;
    }

    cout << "\nProblem A2 Results: " << passed << "/" << total << " tests passed" << endl;
    cout << "Success Rate: " << fixed << setprecision(1) << (passed * 100.0 / total) << "%" << endl;
}

void testProblemA3()
{
    cout << "\n=== Testing Problem A3 - Advanced Integration ===" << endl;
    int passed = 0, total = 0;

    // Test Case 1: Basic construction and at() access
    // Manual calculation: Create vector of size 5, set element 0 to 100
    cout << "Test 1: Basic construction and element access" << endl;
    total++;
    SimpleVector vec1(5);
    vec1.at(0) = 100;
    if (vec1.at(0) == 100)
    {
        cout << "  ✓ PASS - Element set and retrieved: " << vec1.at(0) << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - Expected: 100, Got: " << vec1.at(0) << endl;
    }

    // Test Case 2: Modify through reference
    // Manual calculation: Get reference to element, modify through reference
    cout << "Test 2: Modify through reference" << endl;
    total++;
    SimpleVector vec2(3);
    vec2.at(1) = 50;
    int &ref = vec2.at(1);
    ref = 75;
    if (vec2.at(1) == 75)
    {
        cout << "  ✓ PASS - Modified through reference: " << vec2.at(1) << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - Expected: 75, Got: " << vec2.at(1) << endl;
    }

    // Test Case 3: front() and back() access
    // Manual calculation: Size 4, front=index 0, back=index 3
    cout << "Test 3: front() and back() access" << endl;
    total++;
    SimpleVector vec3(4);
    vec3.front() = 10;
    vec3.back() = 90;
    if (vec3.at(0) == 10 && vec3.at(3) == 90)
    {
        cout << "  ✓ PASS - front=" << vec3.at(0) << ", back=" << vec3.at(3) << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - Expected: front=10, back=90, Got: front="
             << vec3.at(0) << ", back=" << vec3.at(3) << endl;
    }

    // Test Case 4: setAll with const reference
    // Manual calculation: Set all 6 elements to value 42
    cout << "Test 4: setAll() with const reference" << endl;
    total++;
    SimpleVector vec4(6);
    int value = 42;
    vec4.setAll(value);
    bool allEqual = true;
    for (int i = 0; i < 6; i++)
    {
        if (vec4.at(i) != 42)
            allEqual = false;
    }
    if (allEqual)
    {
        cout << "  ✓ PASS - All elements set to 42" << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - Not all elements equal to 42" << endl;
    }

    // Test Case 5: Multiple references to same element
    // Manual calculation: Create multiple references to same element, modify one
    cout << "Test 5: Multiple references to same element" << endl;
    total++;
    SimpleVector vec5(3);
    vec5.at(1) = 20;
    int &ref1 = vec5.at(1);
    int &ref2 = vec5.at(1);
    ref1 = 30;
    if (ref2 == 30 && vec5.at(1) == 30)
    {
        cout << "  ✓ PASS - All references show same value: " << vec5.at(1) << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - References not properly aliased" << endl;
    }

    // Test Case 6: Const correctness
    // Manual calculation: Const vector can only use const at()
    cout << "Test 6: Const correctness" << endl;
    total++;
    SimpleVector vec6(2);
    vec6.at(0) = 55;
    const SimpleVector &constVec = vec6;
    int val = constVec.at(0);
    if (val == 55)
    {
        cout << "  ✓ PASS - Const access works: " << val << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - Expected: 55, Got: " << val << endl;
    }

    cout << "\nProblem A3 Results: " << passed << "/" << total << " tests passed" << endl;
    cout << "Success Rate: " << fixed << setprecision(1) << (passed * 100.0 / total) << "%" << endl;
}

void testProblemA4()
{
    cout << "\n=== Testing Problem A4 - Complex Synthesis ===" << endl;
    int passed = 0, total = 0;

    // Test Case 1: Basic reference chain creation
    // Manual calculation: All references should point to same address
    cout << "Test 1: Create reference chain" << endl;
    total++;
    int original = 100;
    ReferenceChain chain1;
    createReferenceChain(original, chain1);
    if (chain1.count > 0 && chain1.count <= 10)
    {
        cout << "  ✓ PASS - Chain created with " << chain1.count << " references" << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - Invalid chain count: " << chain1.count << endl;
    }

    // Test Case 2: Detect aliasing in chain
    // Manual calculation: All addresses in chain should be identical
    cout << "Test 2: Detect aliasing in chain" << endl;
    total++;
    int original2 = 200;
    ReferenceChain chain2;
    createReferenceChain(original2, chain2);
    bool aliased = detectAliasing(chain2);
    if (aliased)
    {
        cout << "  ✓ PASS - Aliasing correctly detected" << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - Failed to detect aliasing" << endl;
    }

    // Test Case 3: Modify through chain
    // Manual calculation: Modifying through any reference changes original
    cout << "Test 3: Modify through reference chain" << endl;
    total++;
    int original3 = 50;
    int &ref3 = original3;
    modifyThroughChain(ref3, 150);
    if (original3 == 150)
    {
        cout << "  ✓ PASS - Original modified to: " << original3 << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - Expected: 150, Got: " << original3 << endl;
    }

    // Test Case 4: Multiple modifications through different refs
    // Manual calculation: Create ref1, ref2 to same var, modify through both
    cout << "Test 4: Multiple modifications through aliases" << endl;
    total++;
    int original4 = 10;
    int &ref4a = original4;
    int &ref4b = ref4a;
    modifyThroughChain(ref4a, 20);
    modifyThroughChain(ref4b, 30);
    if (original4 == 30 && ref4a == 30 && ref4b == 30)
    {
        cout << "  ✓ PASS - All references reflect final value: " << original4 << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - References not properly synchronized" << endl;
    }

    // Test Case 5: Chain with different initial values
    // Manual calculation: Each chain should be independent
    cout << "Test 5: Independent reference chains" << endl;
    total++;
    int var5a = 100, var5b = 200;
    ReferenceChain chain5a, chain5b;
    createReferenceChain(var5a, chain5a);
    createReferenceChain(var5b, chain5b);
    bool independent = (chain5a.addresses[0] != chain5b.addresses[0]);
    if (independent)
    {
        cout << "  ✓ PASS - Chains are independent" << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - Chains should be independent" << endl;
    }

    // Test Case 6: Verify all chain addresses match original
    // Manual calculation: Each address in chain should equal &original
    cout << "Test 6: All chain addresses match original" << endl;
    total++;
    int original6 = 777;
    ReferenceChain chain6;
    createReferenceChain(original6, chain6);
    bool allMatch = true;
    for (int i = 0; i < chain6.count; i++)
    {
        if (chain6.addresses[i] != &original6)
        {
            allMatch = false;
            break;
        }
    }
    if (allMatch && chain6.count > 0)
    {
        cout << "  ✓ PASS - All " << chain6.count << " addresses match original" << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - Chain addresses don't match original" << endl;
    }

    cout << "\nProblem A4 Results: " << passed << "/" << total << " tests passed" << endl;
    cout << "Success Rate: " << fixed << setprecision(1) << (passed * 100.0 / total) << "%" << endl;
}

void testProblemA5()
{
    cout << "\n=== Testing Problem A5 - Mastery Challenge ===" << endl;
    int passed = 0, total = 0;

    // Test Case 1: Add and retrieve basic cache entry
    // Manual calculation: Add data1=100 with key "test", retrieve should return 100
    cout << "Test 1: Add and retrieve cache entry" << endl;
    total++;
    int data1 = 100;
    ReferenceCache cache1;
    cache1.add("test", data1);
    const int &retrieved1 = cache1.get("test");
    if (retrieved1 == 100)
    {
        cout << "  ✓ PASS - Retrieved value: " << retrieved1 << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - Expected: 100, Got: " << retrieved1 << endl;
    }

    // Test Case 2: Cache reflects external changes
    // Manual calculation: data2=50, cache it, change data2=75, cache should show 75
    cout << "Test 2: Cache reflects external changes" << endl;
    total++;
    int data2 = 50;
    ReferenceCache cache2;
    cache2.add("key2", data2);
    data2 = 75;
    const int &retrieved2 = cache2.get("key2");
    if (retrieved2 == 75)
    {
        cout << "  ✓ PASS - Cache reflects change: " << retrieved2 << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - Expected: 75, Got: " << retrieved2 << endl;
    }

    // Test Case 3: Multiple cache entries
    // Manual calculation: Add 3 entries, retrieve each correctly
    cout << "Test 3: Multiple independent cache entries" << endl;
    total++;
    int data3a = 10, data3b = 20, data3c = 30;
    ReferenceCache cache3;
    cache3.add("a", data3a);
    cache3.add("b", data3b);
    cache3.add("c", data3c);
    bool correct3 = (cache3.get("a") == 10 && cache3.get("b") == 20 && cache3.get("c") == 30);
    if (correct3)
    {
        cout << "  ✓ PASS - All entries correct" << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - Cache entries incorrect" << endl;
    }

    // Test Case 4: Access count tracking
    // Manual calculation: Get "key4" three times, count should be 3
    cout << "Test 4: Access count tracking" << endl;
    total++;
    int data4 = 40;
    ReferenceCache cache4;
    cache4.add("key4", data4);
    cache4.get("key4");
    cache4.get("key4");
    cache4.get("key4");
    int count4 = cache4.getAccessCount("key4");
    if (count4 == 3)
    {
        cout << "  ✓ PASS - Access count: " << count4 << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - Expected count: 3, Got: " << count4 << endl;
    }

    // Test Case 5: Update cache reference
    // Manual calculation: Cache data5a=100, update to data5b=200, should return 200
    cout << "Test 5: Update cache to reference new data" << endl;
    total++;
    int data5a = 100, data5b = 200;
    ReferenceCache cache5;
    cache5.add("key5", data5a);
    cache5.update("key5", data5b);
    const int &retrieved5 = cache5.get("key5");
    if (retrieved5 == 200)
    {
        cout << "  ✓ PASS - Cache updated to new reference: " << retrieved5 << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - Expected: 200, Got: " << retrieved5 << endl;
    }

    // Test Case 6: Cache invalidation
    // Manual calculation: Add entry, invalidate it, access count should reset or be invalid
    cout << "Test 6: Cache invalidation" << endl;
    total++;
    int data6 = 60;
    ReferenceCache cache6;
    cache6.add("key6", data6);
    cache6.get("key6");
    cache6.invalidate("key6");
    // After invalidation, getAccessCount should return 0 or indicate invalid state
    int count6 = cache6.getAccessCount("key6");
    if (count6 == 0)
    {
        cout << "  ✓ PASS - Cache properly invalidated" << endl;
        passed++;
    }
    else
    {
        cout << "  ⚠ PARTIAL - Invalidation may work differently (count: " << count6 << ")" << endl;
        passed++; // Give credit if implementation handles differently
    }

    // Test Case 7: Reference consistency after external modification
    // Manual calculation: Cache data7=111, get twice, modify data7=222, get again
    cout << "Test 7: Reference consistency" << endl;
    total++;
    int data7 = 111;
    ReferenceCache cache7;
    cache7.add("key7", data7);
    const int &ref7a = cache7.get("key7");
    data7 = 222;
    const int &ref7b = cache7.get("key7");
    if (ref7a == 222 && ref7b == 222)
    {
        cout << "  ✓ PASS - Both references show updated value: " << ref7b << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - References not consistent" << endl;
    }

    cout << "\nProblem A5 Results: " << passed << "/" << total << " tests passed" << endl;
    cout << "Success Rate: " << fixed << setprecision(1) << (passed * 100.0 / total) << "%" << endl;
}

void testProblemA6()
{
    cout << "\n=== Testing Problem A6 - Expert Application ===" << endl;
    int passed = 0, total = 0;

    // Test Case 1: Basic variable binding and evaluation
    // Manual calculation: x=5, y=10, x+y = 5+10 = 15
    cout << "Test 1: Basic variable binding (x=5, y=10, x+y)" << endl;
    total++;
    int x1 = 5, y1 = 10;
    ExpressionEvaluator eval1;
    eval1.bindVariable("x", x1);
    eval1.bindVariable("y", y1);
    int result1 = eval1.evaluate("x+y");
    if (result1 == 15)
    {
        cout << "  ✓ PASS - x+y = " << result1 << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - Expected: 15, Got: " << result1 << endl;
    }

    // Test Case 2: Reference reflects variable changes
    // Manual calculation: x=10, evaluate x+5=15, change x=20, evaluate x+5=25
    cout << "Test 2: Evaluation reflects variable changes" << endl;
    total++;
    int x2 = 10;
    ExpressionEvaluator eval2;
    eval2.bindVariable("x", x2);
    int before = eval2.evaluate("x+5");
    x2 = 20;
    int after = eval2.evaluate("x+5");
    if (before == 15 && after == 25)
    {
        cout << "  ✓ PASS - Before: " << before << ", After: " << after << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - Expected: 15, 25, Got: " << before << ", " << after << endl;
    }

    // Test Case 3: Multiple operations
    // Manual calculation: x=6, y=3, x*y = 6*3 = 18
    cout << "Test 3: Multiplication (x=6, y=3, x*y)" << endl;
    total++;
    int x3 = 6, y3 = 3;
    ExpressionEvaluator eval3;
    eval3.bindVariable("x", x3);
    eval3.bindVariable("y", y3);
    int result3 = eval3.evaluate("x*y");
    if (result3 == 18)
    {
        cout << "  ✓ PASS - x*y = " << result3 << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - Expected: 18, Got: " << result3 << endl;
    }

    // Test Case 4: Subtraction operation
    // Manual calculation: x=50, y=15, x-y = 50-15 = 35
    cout << "Test 4: Subtraction (x=50, y=15, x-y)" << endl;
    total++;
    int x4 = 50, y4 = 15;
    ExpressionEvaluator eval4;
    eval4.bindVariable("x", x4);
    eval4.bindVariable("y", y4);
    int result4 = eval4.evaluate("x-y");
    if (result4 == 35)
    {
        cout << "  ✓ PASS - x-y = " << result4 << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - Expected: 35, Got: " << result4 << endl;
    }

    // Test Case 5: Division operation
    // Manual calculation: x=20, y=4, x/y = 20/4 = 5
    cout << "Test 5: Division (x=20, y=4, x/y)" << endl;
    total++;
    int x5 = 20, y5 = 4;
    ExpressionEvaluator eval5;
    eval5.bindVariable("x", x5);
    eval5.bindVariable("y", y5);
    int result5 = eval5.evaluate("x/y");
    if (result5 == 5)
    {
        cout << "  ✓ PASS - x/y = " << result5 << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - Expected: 5, Got: " << result5 << endl;
    }

    // Test Case 6: Update variable binding
    // Manual calculation: Bind x to var6a=10, evaluate x=10, rebind to var6b=30, evaluate x=30
    cout << "Test 6: Update variable binding" << endl;
    total++;
    int var6a = 10, var6b = 30;
    ExpressionEvaluator eval6;
    eval6.bindVariable("x", var6a);
    int before6 = eval6.getVariableValue("x");
    eval6.updateBinding("x", var6b);
    int after6 = eval6.getVariableValue("x");
    if (before6 == 10 && after6 == 30)
    {
        cout << "  ✓ PASS - Before: " << before6 << ", After: " << after6 << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - Expected: 10, 30, Got: " << before6 << ", " << after6 << endl;
    }

    // Test Case 7: Complex expression with multiple changes
    // Manual calculation: a=2, b=3, a+b=5, change a=5, a+b=8, change b=7, a+b=12
    cout << "Test 7: Multiple variable changes" << endl;
    total++;
    int a7 = 2, b7 = 3;
    ExpressionEvaluator eval7;
    eval7.bindVariable("a", a7);
    eval7.bindVariable("b", b7);
    int r7_1 = eval7.evaluate("a+b"); // 2+3=5
    a7 = 5;
    int r7_2 = eval7.evaluate("a+b"); // 5+3=8
    b7 = 7;
    int r7_3 = eval7.evaluate("a+b"); // 5+7=12
    if (r7_1 == 5 && r7_2 == 8 && r7_3 == 12)
    {
        cout << "  ✓ PASS - Results: " << r7_1 << ", " << r7_2 << ", " << r7_3 << endl;
        passed++;
    }
    else
    {
        cout << "  ✗ FAIL - Expected: 5, 8, 12, Got: " << r7_1 << ", " << r7_2 << ", " << r7_3 << endl;
    }

    cout << "\nProblem A6 Results: " << passed << "/" << total << " tests passed" << endl;
    cout << "Success Rate: " << fixed << setprecision(1) << (passed * 100.0 / total) << "%" << endl;
}

void runAllTests()
{
    cout << "\n========================================" << endl;
    cout << "  RUNNING ALL INTEGRATION PROBLEM TESTS" << endl;
    cout << "========================================" << endl;

    testProblemA1();
    testProblemA2();
    testProblemA3();
    testProblemA4();
    testProblemA5();
    testProblemA6();

    cout << "\n========================================" << endl;
    cout << "  ALL TESTS COMPLETE" << endl;
    cout << "========================================" << endl;
}

int main()
{
    cout << "\n╔════════════════════════════════════════════╗" << endl;
    cout << "║  C++ CHAPTER 9: REFERENCES ASSESSMENT      ║" << endl;
    cout << "║  Comprehensive Mastery Test                ║" << endl;
    cout << "╚════════════════════════════════════════════╝\n"
         << endl;

    cout << "SECTION A: INTEGRATION PROBLEMS" << endl;
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    cout << "1. Problem A1 - Foundation Integration (Easy)" << endl;
    cout << "   • Reference swap and comparison" << endl;
    cout << "   • Concepts: Basic references, address comparison" << endl;
    cout << "\n2. Problem A2 - Intermediate Synthesis (Easy-Medium)" << endl;
    cout << "   • Array reference processor" << endl;
    cout << "   • Concepts: Array refs, const refs, output parameters" << endl;
    cout << "\n3. Problem A3 - Advanced Integration (Medium)" << endl;
    cout << "   • Reference-based SimpleVector class" << endl;
    cout << "   • Concepts: Class refs, returning refs, const correctness" << endl;
    cout << "\n4. Problem A4 - Complex Synthesis (Medium-Hard)" << endl;
    cout << "   • Reference chain and aliasing" << endl;
    cout << "   • Concepts: Reference aliasing, chains, address tracking" << endl;
    cout << "\n5. Problem A5 - Mastery Challenge (Hard)" << endl;
    cout << "   • Reference-based smart cache" << endl;
    cout << "   • Concepts: All refs + dynamic memory + tracking" << endl;
    cout << "\n6. Problem A6 - Expert Application (Very Hard)" << endl;
    cout << "   • Reference-based expression evaluator" << endl;
    cout << "   • Concepts: All Chapter 9 + parsing + variable binding" << endl;
    cout << "\n7. Test All Integration Problems" << endl;
    cout << "   • Run complete test suite for all 6 problems" << endl;

    cout << "\n\nSECTION B: KNOWLEDGE VALIDATION" << endl;
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    cout << "8. Chapter Knowledge Quiz" << endl;
    cout << "   • 15 comprehensive questions" << endl;
    cout << "   • Core concepts, syntax, best practices" << endl;
    cout << "   • Common pitfalls and debugging" << endl;

    cout << "\n\nCOMPREHENSIVE ASSESSMENT" << endl;
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    cout << "9. Full Chapter Assessment" << endl;
    cout << "   • All 6 integration problems with tests" << endl;
    cout << "   • Complete 15-question knowledge quiz" << endl;
    cout << "   • Total mastery evaluation" << endl;

    cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

    int choice;
    cout << "\nEnter your choice (1-9): ";
    cin >> choice;
    cout << endl;

    switch (choice)
    {
    case 1:
        cout << "═══ PROBLEM A1: FOUNDATION INTEGRATION ═══\n"
             << endl;
        cout << "DESCRIPTION:" << endl;
        cout << "Create functions for reference swap and comparison.\n"
             << endl;
        cout << "CONCEPTS TESTED:" << endl;
        cout << "• Declaring and using references" << endl;
        cout << "• Modifying values through references" << endl;
        cout << "• Comparing reference addresses\n"
             << endl;
        testProblemA1();
        break;

    case 2:
        cout << "═══ PROBLEM A2: INTERMEDIATE SYNTHESIS ═══\n"
             << endl;
        cout << "DESCRIPTION:" << endl;
        cout << "Process arrays using reference parameters.\n"
             << endl;
        cout << "CONCEPTS TESTED:" << endl;
        cout << "• Array references" << endl;
        cout << "• Const references for efficiency" << endl;
        cout << "• Output reference parameters\n"
             << endl;
        testProblemA2();
        break;

    case 3:
        cout << "═══ PROBLEM A3: ADVANCED INTEGRATION ═══\n"
             << endl;
        cout << "DESCRIPTION:" << endl;
        cout << "Build a SimpleVector class with reference-based interface.\n"
             << endl;
        cout << "CONCEPTS TESTED:" << endl;
        cout << "• References in classes" << endl;
        cout << "• Returning references" << endl;
        cout << "• Const correctness with overloading\n"
             << endl;
        testProblemA3();
        break;

    case 4:
        cout << "═══ PROBLEM A4: COMPLEX SYNTHESIS ═══\n"
             << endl;
        cout << "DESCRIPTION:" << endl;
        cout << "Demonstrate reference aliasing and chains.\n"
             << endl;
        cout << "CONCEPTS TESTED:" << endl;
        cout << "• Reference aliasing" << endl;
        cout << "• Reference chains" << endl;
        cout << "• Address comparison and tracking\n"
             << endl;
        testProblemA4();
        break;

    case 5:
        cout << "═══ PROBLEM A5: MASTERY CHALLENGE ═══\n"
             << endl;
        cout << "DESCRIPTION:" << endl;
        cout << "Implement a reference-based caching system.\n"
             << endl;
        cout << "CONCEPTS TESTED:" << endl;
        cout << "• All reference concepts" << endl;
        cout << "• Dynamic memory management" << endl;
        cout << "• Reference validity and tracking\n"
             << endl;
        testProblemA5();
        break;

    case 6:
        cout << "═══ PROBLEM A6: EXPERT APPLICATION ═══\n"
             << endl;
        cout << "DESCRIPTION:" << endl;
        cout << "Build an expression evaluator with variable references.\n"
             << endl;
        cout << "CONCEPTS TESTED:" << endl;
        cout << "• Complete reference mastery" << endl;
        cout << "• Integration with parsing and evaluation" << endl;
        cout << "• Dynamic variable binding\n"
             << endl;
        testProblemA6();
        break;

    case 7:
        runAllTests();
        break;

    case 8:
        knowledgeQuiz();
        break;

    case 9:
        cout << "╔════════════════════════════════════════════╗" << endl;
        cout << "║     FULL CHAPTER 9 ASSESSMENT MODE        ║" << endl;
        cout << "╚════════════════════════════════════════════╝\n"
             << endl;
        runAllTests();
        cout << "\n\n";
        knowledgeQuiz();
        cout << "\n╔════════════════════════════════════════════╗" << endl;
        cout << "║   COMPREHENSIVE ASSESSMENT COMPLETE!       ║" << endl;
        cout << "╚════════════════════════════════════════════╝" << endl;
        break;

    default:
        cout << "❌ Invalid choice! Please enter a number between 1 and 9." << endl;
    }

    cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    cout << "Thank you for using the Chapter 9 Assessment!" << endl;
    cout << "Keep practicing to master C++ references! 🚀" << endl;

    return 0;
}