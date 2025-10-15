#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <limits>
#include <chrono>
using namespace std;

class PrecedenceAssociativityTutor {
private:
    int currentLevel;
    int score;

public:
    PrecedenceAssociativityTutor() : currentLevel(1), score(0) {}

    // Utility function to clear input buffer
    void clearInputBuffer() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Utility function to get validated integer input
    int getValidatedInt(int min = INT_MIN, int max = INT_MAX) {
        int value;
        while (true) {
            if (cin >> value && value >= min && value <= max) {
                clearInputBuffer();
                return value;
            }
            cout << "Invalid input! Please enter a number between " 
                      << min << " and " << max << ": ";
            clearInputBuffer();
        }
    }

    // Display the main menu
    void displayMainMenu() {
        cout << "\n" << string(60, '=') << endl;
        cout << "    C++ OPERATOR PRECEDENCE & ASSOCIATIVITY TUTOR" << endl;
        cout << string(60, '=') << endl;
        cout << "Current Level: " << currentLevel << " | Score: " << score << endl;
        cout << string(60, '-') << endl;
        cout << "1. Basic Arithmetic Precedence" << endl;
        cout << "2. Logical and Comparison Operators" << endl;
        cout << "3. Assignment and Increment Operators" << endl;
        cout << "4. Bitwise Operations" << endl;
        cout << "5. Pointer and Member Access" << endl;
        cout << "6. Complex Expression Evaluator" << endl;
        cout << "7. Real-World Scenarios" << endl;
        cout << "8. Interactive Quiz Mode" << endl;
        cout << "9. Precedence Table Reference" << endl;
        cout << "10. Performance Comparison" << endl;
        cout << "0. Exit Program" << endl;
        cout << string(60, '-') << endl;
        cout << "Enter your choice (0-10): ";
    }

    // Lesson 1: Basic Arithmetic Precedence
    void basicArithmeticPrecedence() {
        cout << "\n" << string(50, '=') << endl;
        cout << "LESSON 1: BASIC ARITHMETIC PRECEDENCE" << endl;
        cout << string(50, '=') << endl;

        cout << "\nOperator Precedence Hierarchy (High to Low):" << endl;
        cout << "1. () - Parentheses (highest)" << endl;
        cout << "2. *, /, % - Multiplication, Division, Modulo" << endl;
        cout << "3. +, - - Addition, Subtraction (lowest)" << endl;

        cout << "\nAssociativity: Left-to-Right for same precedence operators" << endl;

        // Interactive demonstration
        cout << "\n--- Interactive Demonstration ---" << endl;
        
        int a, b, c;
        cout << "Enter three integers (a b c): ";
        a = getValidatedInt();
        b = getValidatedInt();
        c = getValidatedInt();

        // Expression: a + b * c
        int result1 = a + b * c;
        int step1 = b * c;
        cout << "\nExpression: " << a << " + " << b << " * " << c << endl;
        cout << "Step 1: " << b << " * " << c << " = " << step1 
                  << " (multiplication first)" << endl;
        cout << "Step 2: " << a << " + " << step1 << " = " << result1 << endl;
        cout << "Final Result: " << result1 << endl;

        // Expression with parentheses: (a + b) * c
        int result2 = (a + b) * c;
        int step2 = a + b;
        cout << "\nExpression: (" << a << " + " << b << ") * " << c << endl;
        cout << "Step 1: (" << a << " + " << b << ") = " << step2 
                  << " (parentheses first)" << endl;
        cout << "Step 2: " << step2 << " * " << c << " = " << result2 << endl;
        cout << "Final Result: " << result2 << endl;

        // Complex expression: a + b * c / d - e
        cout << "\nEnter two more integers (d e): ";
        int d = getValidatedInt();
        int e = getValidatedInt();

        if (d != 0) {
            int result3 = a + b * c / d - e;
            int mul_result = b * c;
            int div_result = mul_result / d;
            int add_result = a + div_result;
            int final_result = add_result - e;

            cout << "\nComplex Expression: " << a << " + " << b << " * " 
                      << c << " / " << d << " - " << e << endl;
            cout << "Step 1: " << b << " * " << c << " = " << mul_result 
                      << " (multiplication)" << endl;
            cout << "Step 2: " << mul_result << " / " << d << " = " << div_result 
                      << " (division)" << endl;
            cout << "Step 3: " << a << " + " << div_result << " = " << add_result 
                      << " (addition)" << endl;
            cout << "Step 4: " << add_result << " - " << e << " = " << final_result 
                      << " (subtraction)" << endl;
            cout << "Final Result: " << result3 << endl;
        } else {
            cout << "Division by zero avoided!" << endl;
        }

        score += 10;
        cout << "\n+10 points! Total score: " << score << endl;
        cout << "Press Enter to continue...";
        cin.get();
    }

    // Lesson 2: Logical and Comparison Operators
    void logicalComparisonOperators() {
        cout << "\n" << string(50, '=') << endl;
        cout << "LESSON 2: LOGICAL & COMPARISON OPERATORS" << endl;
        cout << string(50, '=') << endl;

        cout << "\nPrecedence Order (High to Low):" << endl;
        cout << "1. ! (NOT) - Unary logical NOT" << endl;
        cout << "2. <, <=, >, >= - Relational operators" << endl;
        cout << "3. ==, != - Equality operators" << endl;
        cout << "4. && (AND) - Logical AND" << endl;
        cout << "5. || (OR) - Logical OR" << endl;

        cout << "\nShort-Circuit Evaluation:" << endl;
        cout << "&& stops if left operand is false" << endl;
        cout << "|| stops if left operand is true" << endl;

        // Interactive demonstration
        cout << "\n--- Age and Score Validation Example ---" << endl;
        int age, score_input;
        cout << "Enter age: ";
        age = getValidatedInt(0, 120);
        cout << "Enter test score: ";
        score_input = getValidatedInt(0, 100);

        // Complex boolean expression
        bool isAdult = age >= 18;
        bool hasGoodScore = score_input >= 70;
        bool isEligible = isAdult && hasGoodScore;
        bool needsReview = age < 18 || score_input < 50;

        cout << "\nEvaluation Process:" << endl;
        cout << "age >= 18: " << age << " >= 18 = " << boolalpha << isAdult << endl;
        cout << "score >= 70: " << score_input << " >= 70 = " << hasGoodScore << endl;
        cout << "isEligible = " << isAdult << " && " << hasGoodScore 
                  << " = " << isEligible << endl;
        cout << "needsReview = " << (age < 18) << " || " << (score_input < 50) 
                  << " = " << needsReview << endl;

        // Demonstrate short-circuit evaluation
        cout << "\n--- Short-Circuit Evaluation Demo ---" << endl;
        int x = 5, y = 0;
        cout << "x = " << x << ", y = " << y << endl;
        
        // This won't cause division by zero due to short-circuit
        bool safe = (y != 0) && (x / y > 2);
        cout << "(y != 0) && (x / y > 2) = " << safe << endl;
        cout << "Short-circuit prevented division by zero!" << endl;

        // Precedence example
        bool complex = x > 3 && y == 0 || x < 10;
        cout << "\nComplex: " << x << " > 3 && " << y << " == 0 || " 
                  << x << " < 10" << endl;
        cout << "Step 1: " << x << " > 3 = " << (x > 3) << endl;
        cout << "Step 2: " << y << " == 0 = " << (y == 0) << endl;
        cout << "Step 3: " << (x > 3) << " && " << (y == 0) << " = " 
                  << ((x > 3) && (y == 0)) << endl;
        cout << "Step 4: " << x << " < 10 = " << (x < 10) << endl;
        cout << "Step 5: " << ((x > 3) && (y == 0)) << " || " << (x < 10) 
                  << " = " << complex << endl;

        score += 15;
        cout << "\n+15 points! Total score: " << score << endl;
        cout << "Press Enter to continue...";
        cin.get();
    }

    // Lesson 3: Assignment and Increment Operators
    void assignmentIncrementOperators() {
        cout << "\n" << string(50, '=') << endl;
        cout << "LESSON 3: ASSIGNMENT & INCREMENT OPERATORS" << endl;
        cout << string(50, '=') << endl;

        cout << "\nPrecedence & Associativity:" << endl;
        cout << "1. ++ -- (postfix) - Left-to-Right" << endl;
        cout << "2. ++ -- (prefix) - Right-to-Left" << endl;
        cout << "3. = += -= *= /= %= - Right-to-Left" << endl;

        cout << "\n--- Prefix vs Postfix Demonstration ---" << endl;
        int a, b;
        cout << "Enter two integers: ";
        a = getValidatedInt();
        b = getValidatedInt();

        cout << "\nInitial values: a = " << a << ", b = " << b << endl;

        // Postfix increment
        int original_a = a;
        int result1 = a++;
        cout << "\nPostfix: result1 = a++ where a was " << original_a << endl;
        cout << "result1 = " << result1 << " (original value used)" << endl;
        cout << "a is now = " << a << " (incremented after use)" << endl;

        // Reset a
        a = original_a;
        
        // Prefix increment
        int result2 = ++a;
        cout << "\nPrefix: result2 = ++a where a was " << original_a << endl;
        cout << "result2 = " << result2 << " (incremented value used)" << endl;
        cout << "a is now = " << a << " (incremented before use)" << endl;

        // Complex expression with mixed operators
        a = original_a; // Reset
        int c = b;
        int complex_result = ++a * b-- + c++;
        
        cout << "\n--- Complex Expression Analysis ---" << endl;
        cout << "Expression: ++a * b-- + c++" << endl;
        cout << "Where initial: a=" << original_a << ", b=" << b+1 << ", c=" << c-1 << endl;
        cout << "Step 1: ++a = " << a << " (prefix increment)" << endl;
        cout << "Step 2: b-- uses " << (b+1) << " then becomes " << b << " (postfix decrement)" << endl;
        cout << "Step 3: c++ uses " << (c-1) << " then becomes " << c << " (postfix increment)" << endl;
        cout << "Calculation: " << a << " * " << (b+1) << " + " << (c-1) 
                  << " = " << complex_result << endl;

        // Chained assignment
        cout << "\n--- Chained Assignment (Right-to-Left) ---" << endl;
        int x, y, z;
        cout << "Enter value for chained assignment: ";
        int value = getValidatedInt();
        
        x = y = z = value; // Right-to-left associativity
        cout << "x = y = z = " << value << endl;
        cout << "Result: x=" << x << ", y=" << y << ", z=" << z << endl;
        cout << "All variables get the same value due to right-to-left associativity" << endl;

        // Compound assignment
        cout << "\n--- Compound Assignment Operators ---" << endl;
        int num;
        cout << "Enter a number for compound operations: ";
        num = getValidatedInt();
        
        int original_num = num;
        cout << "Original number: " << original_num << endl;
        
        num += 5;
        cout << "After += 5: " << num << endl;
        
        num *= 2;
        cout << "After *= 2: " << num << endl;
        
        num /= 3;
        cout << "After /= 3: " << num << endl;

        score += 20;
        cout << "\n+20 points! Total score: " << score << endl;
        cout << "Press Enter to continue...";
        cin.get();
    }

    // Lesson 4: Bitwise Operations
    void bitwiseOperations() {
        cout << "\n" << string(50, '=') << endl;
        cout << "LESSON 4: BITWISE OPERATIONS" << endl;
        cout << string(50, '=') << endl;

        cout << "\nBitwise Operator Precedence:" << endl;
        cout << "1. ~ (NOT) - Unary bitwise complement" << endl;
        cout << "2. << >> (SHIFT) - Left and right shift" << endl;
        cout << "3. & (AND) - Bitwise AND" << endl;
        cout << "4. ^ (XOR) - Bitwise exclusive OR" << endl;
        cout << "5. | (OR) - Bitwise inclusive OR" << endl;

        cout << "\n--- Interactive Bitwise Demo ---" << endl;
        unsigned int a, b;
        cout << "Enter two positive integers (0-255): ";
        a = getValidatedInt(0, 255);
        b = getValidatedInt(0, 255);

        // Helper function to display binary
        auto displayBinary = [](unsigned int num, const string& label) {
            cout << label << setw(3) << num << " = ";
            for (int i = 7; i >= 0; i--) {
                cout << ((num >> i) & 1);
                if (i == 4) cout << " ";
            }
            cout << "₂" << endl;
        };

        cout << "\nBinary Representation:" << endl;
        displayBinary(a, "a = ");
        displayBinary(b, "b = ");

        // Bitwise operations
        unsigned int and_result = a & b;
        unsigned int or_result = a | b;
        unsigned int xor_result = a ^ b;
        unsigned int not_a = ~a & 0xFF; // Mask to 8 bits
        unsigned int left_shift = (a << 2) & 0xFF;
        unsigned int right_shift = a >> 1;

        cout << "\nBitwise Operations:" << endl;
        displayBinary(and_result, "a & b = ");
        displayBinary(or_result, "a | b = ");
        displayBinary(xor_result, "a ^ b = ");
        displayBinary(not_a, "~a = ");
        displayBinary(left_shift, "a << 2 = ");
        displayBinary(right_shift, "a >> 1 = ");

        // Complex bitwise expression
        unsigned int complex = (a & b) | (~a ^ b);
        cout << "\n--- Complex Expression: (a & b) | (~a ^ b) ---" << endl;
        unsigned int step1 = a & b;
        unsigned int step2 = ~a & 0xFF;
        unsigned int step3 = step2 ^ b;
        unsigned int final_result = step1 | step3;

        cout << "Step 1: a & b = " << step1 << endl;
        displayBinary(step1, "");
        cout << "Step 2: ~a = " << step2 << endl;
        displayBinary(step2, "");
        cout << "Step 3: (~a) ^ b = " << step3 << endl;
        displayBinary(step3, "");
        cout << "Step 4: (a & b) | ((~a) ^ b) = " << final_result << endl;
        displayBinary(final_result, "");

        // Practical application: Bit flags
        cout << "\n--- Practical Application: Permission Flags ---" << endl;
        const unsigned int READ = 1;    // 001
        const unsigned int WRITE = 2;   // 010
        const unsigned int EXECUTE = 4; // 100

        cout << "Permission bits: READ=1, WRITE=2, EXECUTE=4" << endl;
        cout << "Set permissions (0-7): ";
        unsigned int permissions = getValidatedInt(0, 7);

        cout << "\nYour permissions (" << permissions << "):" << endl;
        cout << "READ: " << ((permissions & READ) ? "YES" : "NO") << endl;
        cout << "WRITE: " << ((permissions & WRITE) ? "YES" : "NO") << endl;
        cout << "EXECUTE: " << ((permissions & EXECUTE) ? "YES" : "NO") << endl;

        score += 25;
        cout << "\n+25 points! Total score: " << score << endl;
        cout << "Press Enter to continue...";
        cin.get();
    }

    // Lesson 5: Pointer and Member Access
    void pointerMemberAccess() {
        cout << "\n" << string(50, '=') << endl;
        cout << "LESSON 5: POINTER & MEMBER ACCESS OPERATORS" << endl;
        cout << string(50, '=') << endl;

        cout << "\nPrecedence (High to Low):" << endl;
        cout << "1. [] () . -> - Postfix operators" << endl;
        cout << "2. * & - Dereference and Address-of (Prefix)" << endl;

        // Simple struct for demonstration
        struct Point {
            int x, y;
            void display() const {
                cout << "(" << x << ", " << y << ")";
            }
        };

        cout << "\n--- Pointer Operations Demo ---" << endl;
        
        // Create objects
        Point p1;
        cout << "Enter coordinates for point (x y): ";
        p1.x = getValidatedInt();
        p1.y = getValidatedInt();

        Point* ptr = &p1;  // Pointer to p1
        Point& ref = p1;   // Reference to p1

        cout << "\nDifferent ways to access the same point:" << endl;
        cout << "Direct access (p1): ";
        p1.display();
        cout << endl;

        cout << "Pointer access (ptr->): ";
        ptr->display();
        cout << endl;

        cout << "Pointer dereference ((*ptr).): ";
        (*ptr).display();
        cout << endl;

        cout << "Reference access (ref): ";
        ref.display();
        cout << endl;

        // Array access demonstration
        cout << "\n--- Array Access Precedence ---" << endl;
        int arr[5] = {10, 20, 30, 40, 50};
        int* arr_ptr = arr;

        cout << "Array: [10, 20, 30, 40, 50]" << endl;
        cout << "Enter index (0-4): ";
        int index = getValidatedInt(0, 4);

        cout << "\nDifferent ways to access arr[" << index << "]:" << endl;
        cout << "arr[" << index << "] = " << arr[index] << endl;
        cout << "*(arr + " << index << ") = " << *(arr + index) << endl;
        cout << "arr_ptr[" << index << "] = " << arr_ptr[index] << endl;
        cout << "*(arr_ptr + " << index << ") = " << *(arr_ptr + index) << endl;

        // Complex pointer expression
        cout << "\n--- Complex Pointer Expression ---" << endl;
        int* ptr_arr[3] = {&arr[0], &arr[2], &arr[4]};
        
        cout << "ptr_arr points to arr[0], arr[2], arr[4]" << endl;
        cout << "Expression: *ptr_arr[1] + 5" << endl;
        cout << "Step 1: ptr_arr[1] gets pointer to arr[2]" << endl;
        cout << "Step 2: *ptr_arr[1] dereferences to get " << *ptr_arr[1] << endl;
        cout << "Step 3: " << *ptr_arr[1] << " + 5 = " << (*ptr_arr[1] + 5) << endl;

        // Address arithmetic
        cout << "\n--- Pointer Arithmetic ---" << endl;
        int* start_ptr = arr;
        int* end_ptr = arr + 4;
        
        cout << "start_ptr points to arr[0]: " << *start_ptr << endl;
        cout << "end_ptr points to arr[4]: " << *end_ptr << endl;
        cout << "Pointer difference: " << (end_ptr - start_ptr) << " elements" << endl;
        
        cout << "\nIncrementing start_ptr:" << endl;
        ++start_ptr;
        cout << "After ++start_ptr: " << *start_ptr << " (now arr[1])" << endl;

        score += 20;
        cout << "\n+20 points! Total score: " << score << endl;
        cout << "Press Enter to continue...";
        cin.get();
    }

    // Lesson 6: Complex Expression Evaluator
    void complexExpressionEvaluator() {
        cout << "\n" << string(50, '=') << endl;
        cout << "LESSON 6: COMPLEX EXPRESSION EVALUATOR" << endl;
        cout << string(50, '=') << endl;

        cout << "Let's evaluate complex expressions step by step!" << endl;
        
        // Get user input for variables
        cout << "\nEnter values for variables:" << endl;
        int a, b, c, d;
        cout << "a = "; a = getValidatedInt();
        cout << "b = "; b = getValidatedInt();
        cout << "c = "; c = getValidatedInt();
        cout << "d = "; d = getValidatedInt();

        // Expression 1: Mixed arithmetic and comparison
        cout << "\n--- Expression 1: a + b * c > d && b != 0 ---" << endl;
        cout << "Values: a=" << a << ", b=" << b << ", c=" << c << ", d=" << d << endl;
        
        int step1 = b * c;
        int step2 = a + step1;
        bool step3 = step2 > d;
        bool step4 = b != 0;
        bool final1 = step3 && step4;
        
        cout << "Step 1: b * c = " << b << " * " << c << " = " << step1 << endl;
        cout << "Step 2: a + (b * c) = " << a << " + " << step1 << " = " << step2 << endl;
        cout << "Step 3: (a + b * c) > d = " << step2 << " > " << d << " = " << boolalpha << step3 << endl;
        cout << "Step 4: b != 0 = " << b << " != 0 = " << step4 << endl;
        cout << "Step 5: (" << step3 << ") && (" << step4 << ") = " << final1 << endl;

        // Expression 2: Assignment with side effects
        cout << "\n--- Expression 2: c = a++ + --b * d ---" << endl;
        int orig_a = a, orig_b = b, orig_c = c;
        cout << "Initial: a=" << orig_a << ", b=" << orig_b << ", c=" << orig_c << ", d=" << d << endl;
        
        int temp_a = a++;  // Use current value, then increment
        int temp_b = --b;  // Decrement first, then use
        int mult_result = temp_b * d;
        c = temp_a + mult_result;
        
        cout << "Step 1: a++ uses " << temp_a << ", then a becomes " << a << endl;
        cout << "Step 2: --b becomes " << temp_b << " (b is now " << b << ")" << endl;
        cout << "Step 3: --b * d = " << temp_b << " * " << d << " = " << mult_result << endl;
        cout << "Step 4: c = " << temp_a << " + " << mult_result << " = " << c << endl;
        cout << "Final values: a=" << a << ", b=" << b << ", c=" << c << ", d=" << d << endl;

        // Expression 3: Conditional operator
        cout << "\n--- Expression 3: Conditional Operator ---" << endl;
        int x, y;
        cout << "Enter two more integers (x y): ";
        x = getValidatedInt();
        y = getValidatedInt();
        
        // Complex conditional: (x > y) ? (x + y) : (x * y)
        bool condition = x > y;
        int true_value = x + y;
        int false_value = x * y;
        int conditional_result = condition ? true_value : false_value;
        
        cout << "Expression: (x > y) ? (x + y) : (x * y)" << endl;
        cout << "Where x=" << x << ", y=" << y << endl;
        cout << "Condition: x > y = " << x << " > " << y << " = " << boolalpha << condition << endl;
        cout << "True branch: x + y = " << x << " + " << y << " = " << true_value << endl;
        cout << "False branch: x * y = " << x << " * " << y << " = " << false_value << endl;
        cout << "Result: " << conditional_result << endl;

        // Expression 4: Comma operator (lowest precedence)
        cout << "\n--- Expression 4: Comma Operator ---" << endl;
        int result = (a = 5, b = 10, a + b);
        cout << "Expression: (a = 5, b = 10, a + b)" << endl;
        cout << "Step 1: a = 5 (a is now " << a << ")" << endl;
        cout << "Step 2: b = 10 (b is now " << b << ")" << endl;
        cout << "Step 3: a + b = " << a << " + " << b << " = " << result << endl;
        cout << "The comma operator returns the value of the rightmost expression" << endl;

        score += 30;
        cout << "\n+30 points! Total score: " << score << endl;
        cout << "Press Enter to continue...";
        cin.get();
    }

    // Lesson 7: Real-World Scenarios
    void realWorldScenarios() {
        cout << "\n" << string(50, '=') << endl;
        cout << "LESSON 7: REAL-WORLD SCENARIOS" << endl;
        cout << string(50, '=') << endl;

        cout << "1. Game Development - Health and Damage Calculation" << endl;
        cout << "2. Financial Software - Interest Calculation" << endl;
        cout << "3. Graphics Programming - Pixel Manipulation" << endl;
        cout << "Enter scenario choice (1-3): ";
        
        int choice = getValidatedInt(1, 3);
        
        switch (choice) {
            case 1: {
                // Game Development Scenario
                cout << "\n--- GAME DEVELOPMENT SCENARIO ---" << endl;
                cout << "Calculate final damage with armor reduction and critical hits" << endl;
                
                int baseDamage, armor, critMultiplier;
                bool isCritical;
                
                cout << "Enter base damage: ";
                baseDamage = getValidatedInt(1, 1000);
                cout << "Enter armor value: ";
                armor = getValidatedInt(0, 100);
                cout << "Is critical hit? (1=yes, 0=no): ";
                isCritical = getValidatedInt(0, 1);
                cout << "Enter critical multiplier (default 2): ";
                critMultiplier = getValidatedInt(1, 10);
                
                // Complex damage calculation with precedence
                double armorReduction = 1.0 - (armor * 0.01);
                int modifiedDamage = isCritical ? baseDamage * critMultiplier : baseDamage;
                double finalDamage = modifiedDamage * armorReduction;
                
                cout << "\n--- Damage Calculation Steps ---" << endl;
                cout << "Base damage: " << baseDamage << endl;
                cout << "Critical hit: " << boolalpha << isCritical << endl;
                cout << "Step 1: Apply critical = " << baseDamage;
                if (isCritical) {
                    cout << " * " << critMultiplier << " = " << modifiedDamage;
                } else {
                    cout << " (no crit) = " << modifiedDamage;
                }
                cout << endl;
                
                cout << "Step 2: Calculate armor reduction = 1.0 - (" << armor 
                          << " * 0.01) = " << armorReduction << endl;
                cout << "Step 3: Apply armor = " << modifiedDamage << " * " 
                          << armorReduction << " = " << finalDamage << endl;
                
                // Show the precedence in the actual expression
                cout << "\nExpression: (isCritical ? baseDamage * critMult : baseDamage) * (1.0 - armor * 0.01)" << endl;
                cout << "Final damage dealt: " << static_cast<int>(finalDamage) << endl;
                break;
            }
            
            case 2: {
                // Financial Software Scenario
                cout << "\n--- FINANCIAL SOFTWARE SCENARIO ---" << endl;
                cout << "Compound interest calculation with fees" << endl;
                
                double principal, rate, fee;
                int years;
                
                cout << "Enter principal amount: $";
                principal = getValidatedInt(100, 1000000);
                cout << "Enter annual interest rate (%): ";
                rate = getValidatedInt(1, 20) / 100.0;
                cout << "Enter annual fee: $";
                fee = getValidatedInt(0, 1000);
                cout << "Enter number of years: ";
                years = getValidatedInt(1, 50);
                
                // Complex financial calculation
                double yearlyMultiplier = 1.0 + rate;
                double compoundAmount = principal * pow(yearlyMultiplier, years);
                double totalFees = fee * years;
                double finalAmount = compoundAmount - totalFees;
                double totalReturn = finalAmount - principal;
                
                cout << "\n--- Compound Interest Calculation ---" << endl;
                cout << "Principal: $" << fixed << setprecision(2) << principal << endl;
                cout << "Annual rate: " << (rate * 100) << "%" << endl;
                cout << "Step 1: Yearly multiplier = 1.0 + " << rate << " = " << yearlyMultiplier << endl;
                cout << "Step 2: Compound for " << years << " years = " << principal 
                          << " * " << yearlyMultiplier << "^" << years << " = $" << compoundAmount << endl;
                cout << "Step 3: Total fees = " << fee << " * " << years << " = $" << totalFees << endl;
                cout << "Step 4: Final amount = " << compoundAmount << " - " << totalFees 
                          << " = $" << finalAmount << endl;
                cout << "Total return: $" << totalReturn << endl;
                
                cout << "\nExpression breakdown shows precedence of:" << endl;
                cout << "1. Exponentiation (pow function)" << endl;
                cout << "2. Multiplication" << endl;
                cout << "3. Subtraction" << endl;
                break;
            }
            
            case 3: {
                // Graphics Programming Scenario
                cout << "\n--- GRAPHICS PROGRAMMING SCENARIO ---" << endl;
                cout << "RGB color blending and bit manipulation" << endl;
                
                unsigned int color1, color2;
                double alpha;
                
                cout << "Enter first color (RGB as hex, e.g., 0xFF0000 for red): 0x";
                cin >> hex >> color1;
                cout << "Enter second color (RGB as hex): 0x";
                cin >> hex >> color2;
                cout << "Enter alpha blend factor (0.0-1.0): ";
                cin >> alpha;
                clearInputBuffer();
                
                // Extract RGB components using bitwise operations
                unsigned int r1 = (color1 >> 16) & 0xFF;
                unsigned int g1 = (color1 >> 8) & 0xFF;
                unsigned int b1 = color1 & 0xFF;
                
                unsigned int r2 = (color2 >> 16) & 0xFF;
                unsigned int g2 = (color2 >> 8) & 0xFF;
                unsigned int b2 = color2 & 0xFF;
                
                // Alpha blending calculation
                unsigned int blended_r = (unsigned int)(r1 * (1.0 - alpha) + r2 * alpha);
                unsigned int blended_g = (unsigned int)(g1 * (1.0 - alpha) + g2 * alpha);
                unsigned int blended_b = (unsigned int)(b1 * (1.0 - alpha) + b2 * alpha);
                
                unsigned int blended_color = (blended_r << 16) | (blended_g << 8) | blended_b;
                
                cout << dec; // Switch back to decimal
                cout << "\n--- Color Blending Steps ---" << endl;
                cout << "Color 1: R=" << r1 << ", G=" << g1 << ", B=" << b1 << endl;
                cout << "Color 2: R=" << r2 << ", G=" << g2 << ", B=" << b2 << endl;
                cout << "Alpha: " << alpha << endl;
                
                cout << "\nBit extraction (showing precedence):" << endl;
                cout << "R1 = (color1 >> 16) & 0xFF = (" << hex << color1 
                          << " >> 16) & 0xFF = " << dec << r1 << endl;
                
                cout << "\nBlending calculation:" << endl;
                cout << "Blended R = " << r1 << " * " << (1.0 - alpha) << " + " 
                          << r2 << " * " << alpha << " = " << blended_r << endl;
                
                cout << "\nFinal color: 0x" << hex << uppercase << blended_color << dec << endl;
                cout << "RGB(" << blended_r << ", " << blended_g << ", " << blended_b << ")" << endl;
                break;
            }
        }
        
        score += 25;
        cout << "\n+25 points! Total score: " << score << endl;
        cout << "Press Enter to continue...";
        cin.get();
    }

    // Lesson 8: Interactive Quiz Mode
    void interactiveQuiz() {
        cout << "\n" << string(50, '=') << endl;
        cout << "LESSON 8: INTERACTIVE QUIZ MODE" << endl;
        cout << string(50, '=') << endl;

        int quizScore = 0;
        int totalQuestions = 5;
        
        // Quiz questions with multiple choice
        struct Question {
            string question;
            vector<string> options;
            int correctAnswer;
            string explanation;
        };
        
        vector<Question> questions = {
            {
                "What is the result of: 2 + 3 * 4?",
                {"20", "14", "24", "10"},
                1, // Index 1 = "14"
                "Multiplication has higher precedence than addition: 3 * 4 = 12, then 2 + 12 = 14"
            },
            {
                "What happens with: int x = 5; int y = ++x * 2;",
                {"y = 10, x = 5", "y = 12, x = 6", "y = 10, x = 6", "Compilation error"},
                1, // Index 1 = "y = 12, x = 6"
                "++x increments x to 6 first, then multiplies: 6 * 2 = 12"
            },
            {
                "Which operator has the LOWEST precedence?",
                {"&&", "||", "=", ","},
                3, // Index 3 = ","
                "The comma operator has the lowest precedence of all operators"
            },
            {
                "What is: true && false || true?",
                {"true", "false", "Compilation error", "Undefined"},
                0, // Index 0 = "true"
                "&& has higher precedence: (true && false) = false, then false || true = true"
            },
            {
                "What is the associativity of assignment operators?",
                {"Left-to-right", "Right-to-left", "No associativity", "Depends on type"},
                1, // Index 1 = "Right-to-left"
                "Assignment operators associate right-to-left: a = b = c assigns c to b, then b to a"
            }
        };
        
        for (int i = 0; i < totalQuestions; i++) {
            cout << "\n--- Question " << (i + 1) << " of " << totalQuestions << " ---" << endl;
            cout << questions[i].question << endl;
            
            for (size_t j = 0; j < questions[i].options.size(); j++) {
                cout << (j + 1) << ". " << questions[i].options[j] << endl;
            }
            
            cout << "Your answer (1-" << questions[i].options.size() << "): ";
            int userAnswer = getValidatedInt(1, static_cast<int>(questions[i].options.size())) - 1;
            
            if (userAnswer == questions[i].correctAnswer) {
                cout << "✓ CORRECT! +10 points" << endl;
                quizScore += 10;
            } else {
                cout << "✗ INCORRECT. The correct answer was: " 
                          << questions[i].options[questions[i].correctAnswer] << endl;
            }
            
            cout << "Explanation: " << questions[i].explanation << endl;
        }
        
        cout << "\n" << string(50, '=') << endl;
        cout << "QUIZ COMPLETED!" << endl;
        cout << "Your quiz score: " << quizScore << "/" << (totalQuestions * 10) << endl;
        
        double percentage = (static_cast<double>(quizScore) / (totalQuestions * 10)) * 100;
        cout << "Percentage: " << fixed << setprecision(1) << percentage << "%" << endl;
        
        if (percentage >= 80) {
            cout << "Excellent! You have a strong understanding of precedence!" << endl;
            currentLevel = min(currentLevel + 1, 5);
            cout << "Level up! Current level: " << currentLevel << endl;
        } else if (percentage >= 60) {
            cout << "Good job! Consider reviewing the concepts you missed." << endl;
        } else {
            cout << "Keep practicing! Review the lessons and try again." << endl;
        }
        
        score += quizScore;
        cout << "\nTotal program score: " << score << endl;
        cout << "Press Enter to continue...";
        cin.get();
    }

    // Lesson 9: Precedence Table Reference
    void precedenceTableReference() {
        cout << "\n" << string(70, '=') << endl;
        cout << "LESSON 9: COMPLETE PRECEDENCE TABLE REFERENCE" << endl;
        cout << string(70, '=') << endl;

        cout << left << setw(5) << "Prec" << setw(20) << "Operator" 
                  << setw(25) << "Description" << "Associativity" << endl;
        cout << string(70, '-') << endl;

        // Complete precedence table
        vector<tuple<int, string, string, string>> table = {
            {1, "::", "Scope resolution", "Left-to-right"},
            {2, "() [] -> .", "Function call, array, member", "Left-to-right"},
            {3, "++ -- ~ ! - + * &", "Postfix inc/dec, unary ops", "Right-to-left"},
            {4, "++ --", "Prefix increment/decrement", "Right-to-left"},
            {5, "* / %", "Multiplicative", "Left-to-right"},
            {6, "+ -", "Additive", "Left-to-right"},
            {7, "<< >>", "Bitwise shift", "Left-to-right"},
            {8, "< <= > >=", "Relational", "Left-to-right"},
            {9, "== !=", "Equality", "Left-to-right"},
            {10, "&", "Bitwise AND", "Left-to-right"},
            {11, "^", "Bitwise XOR", "Left-to-right"},
            {12, "|", "Bitwise OR", "Left-to-right"},
            {13, "&&", "Logical AND", "Left-to-right"},
            {14, "||", "Logical OR", "Left-to-right"},
            {15, "?:", "Conditional (ternary)", "Right-to-left"},
            {16, "= += -= *= /= %=", "Assignment", "Right-to-left"},
            {17, ",", "Comma", "Left-to-right"}
        };

        for (const auto& row : table) {
            cout << left << setw(5) << get<0>(row)
                      << setw(20) << get<1>(row)
                      << setw(25) << get<2>(row)
                      << get<3>(row) << endl;
        }

        cout << "\n" << string(70, '=') << endl;
        cout << "MEMORY TIPS:" << endl;
        cout << "1. Parentheses always have the highest precedence" << endl;
        cout << "2. Unary operators come before binary operators" << endl;
        cout << "3. Arithmetic: */% before +-" << endl;
        cout << "4. Comparison before logical operators" << endl;
        cout << "5. Assignment operators are right-associative" << endl;
        cout << "6. Comma operator has the lowest precedence" << endl;

        cout << "\n--- Interactive Precedence Checker ---" << endl;
        cout << "Enter an expression to see evaluation order (or 'quit' to exit):" << endl;
        
        string expression;
        cin.ignore();
        
        while (true) {
            cout << "> ";
            getline(cin, expression);
            
            if (expression == "quit" || expression == "exit") {
                break;
            }
            
            // Simple expression analyzer (basic implementation)
            if (!expression.empty()) {
                cout << "Expression: " << expression << endl;
                cout << "Tips for evaluation:" << endl;
                
                if (expression.find("++") != string::npos || expression.find("--") != string::npos) {
                    cout << "- Watch for pre/post increment/decrement operators" << endl;
                }
                if (expression.find("*") != string::npos || expression.find("/") != string::npos) {
                    cout << "- Multiplication and division before addition/subtraction" << endl;
                }
                if (expression.find("&&") != string::npos || expression.find("||") != string::npos) {
                    cout << "- && has higher precedence than ||" << endl;
                }
                if (expression.find("=") != string::npos && expression.find("==") == string::npos) {
                    cout << "- Assignment operators are right-associative" << endl;
                }
                
                cout << "Use parentheses to make precedence explicit!" << endl;
            }
        }
        
        score += 15;
        cout << "\n+15 points! Total score: " << score << endl;
    }

    // Lesson 10: Performance Comparison
    void performanceComparison() {
        cout << "\n" << string(50, '=') << endl;
        cout << "LESSON 10: PERFORMANCE CONSIDERATIONS" << endl;
        cout << string(50, '=') << endl;

        cout << "Understanding precedence affects performance in several ways:" << endl;
        
        cout << "\n1. AVOIDING UNNECESSARY PARENTHESES" << endl;
        cout << "   Good: a + b * c     (clear precedence)" << endl;
        cout << "   Bad:  a + (b * c)   (unnecessary parentheses)" << endl;
        
        cout << "\n2. SHORT-CIRCUIT EVALUATION BENEFITS" << endl;
        cout << "   if (ptr != nullptr && ptr->isValid())" << endl;
        cout << "   - Second condition only checked if first is true" << endl;
        cout << "   - Prevents crashes and improves performance" << endl;
        
        cout << "\n3. OPERATOR PRECEDENCE IN LOOPS" << endl;
        int n;
        cout << "Enter array size for performance test: ";
        n = getValidatedInt(1, 1000000);
        
        // Create test data
        vector<int> data(n);
        for (int i = 0; i < n; i++) {
            data[i] = i % 100;
        }
        
        // Demonstrate different ways to write the same logic
        cout << "\n--- Performance Test: Array Processing ---" << endl;
        cout << "Processing " << n << " elements..." << endl;
        
        // Method 1: Clear precedence
        auto start = chrono::high_resolution_clock::now();
        int sum1 = 0;
        for (int i = 0; i < n; i++) {
            if (data[i] > 50 && data[i] % 2 == 0) {
                sum1 += data[i] * 2;
            }
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration1 = chrono::duration_cast<chrono::microseconds>(end - start);
        
        // Method 2: With unnecessary parentheses
        start = chrono::high_resolution_clock::now();
        int sum2 = 0;
        for (int i = 0; i < n; i++) {
            if ((data[i] > 50) && ((data[i] % 2) == 0)) {
                sum2 += (data[i] * 2);
            }
        }
        end = chrono::high_resolution_clock::now();
        auto duration2 = chrono::duration_cast<chrono::microseconds>(end - start);
        
        cout << "Method 1 (clear precedence): " << duration1.count() << " microseconds" << endl;
        cout << "Method 2 (extra parentheses): " << duration2.count() << " microseconds" << endl;
        cout << "Both sums: " << sum1 << " and " << sum2 << " (should be equal)" << endl;
        
        // Demonstrate short-circuit evaluation impact
        cout << "\n--- Short-Circuit Evaluation Performance ---" << endl;
        
        auto expensiveOperation = [](int x) -> bool {
            // Simulate expensive operation
            volatile int temp = 0;
            for (int i = 0; i < 1000; i++) {
                temp += i * x;
            }
            return temp > 0;
        };
        
        // Test with short-circuit (efficient)
        start = chrono::high_resolution_clock::now();
        int count1 = 0;
        for (int i = 0; i < 1000; i++) {
            if (i % 2 == 0 && expensiveOperation(i)) {
                count1++;
            }
        }
        end = chrono::high_resolution_clock::now();
        auto shortCircuitTime = chrono::duration_cast<chrono::microseconds>(end - start);
        
        // Test without short-circuit advantage (less efficient)
        start = chrono::high_resolution_clock::now();
        int count2 = 0;
        for (int i = 0; i < 1000; i++) {
            if (expensiveOperation(i) && i % 2 == 0) {  // Expensive operation first
                count2++;
            }
        }
        end = chrono::high_resolution_clock::now();
        auto noShortCircuitTime = chrono::duration_cast<chrono::microseconds>(end - start);
        
        cout << "Short-circuit optimized: " << shortCircuitTime.count() << " microseconds" << endl;
        cout << "Non-optimized order: " << noShortCircuitTime.count() << " microseconds" << endl;
        cout << "Speedup factor: " << fixed << setprecision(2) 
                  << static_cast<double>(noShortCircuitTime.count()) / shortCircuitTime.count() << "x" << endl;
        
        cout << "\n--- Key Performance Insights ---" << endl;
        cout << "1. Compiler optimizes based on precedence rules" << endl;
        cout << "2. Short-circuit evaluation can prevent expensive operations" << endl;
        cout << "3. Clear precedence makes code more readable and maintainable" << endl;
        cout << "4. Understanding precedence helps write efficient conditional logic" << endl;
        
        score += 20;
        cout << "\n+20 points! Total score: " << score << endl;
        cout << "Press Enter to continue...";
        cin.get();
    }

    // Main program loop
    void run() {
        int choice;
        
        cout << "Welcome to the C++ Precedence and Associativity Learning Program!" << endl;
        cout << "This interactive tutor will help you master operator precedence." << endl;
        
        do {
            displayMainMenu();
            choice = getValidatedInt(0, 10);
            
            switch (choice) {
                case 1: basicArithmeticPrecedence(); break;
                case 2: logicalComparisonOperators(); break;
                case 3: assignmentIncrementOperators(); break;
                case 4: bitwiseOperations(); break;
                case 5: pointerMemberAccess(); break;
                case 6: complexExpressionEvaluator(); break;
                case 7: realWorldScenarios(); break;
                case 8: interactiveQuiz(); break;
                case 9: precedenceTableReference(); break;
                case 10: performanceComparison(); break;
                case 0: 
                    cout << "\nThank you for using the C++ Precedence Tutor!" << endl;
                    cout << "Final Score: " << score << endl;
                    cout << "Final Level: " << currentLevel << endl;
                    if (score >= 100) {
                        cout << "🏆 Congratulations! You've mastered precedence and associativity!" << endl;
                    }
                    break;
                default:
                    cout << "Invalid choice! Please try again." << endl;
                    break;
            }
        } while (choice != 0);
    }
};

int main() {
    PrecedenceAssociativityTutor tutor;
    tutor.run();
    return 0;
}