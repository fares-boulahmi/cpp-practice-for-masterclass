#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// ============================================================================
// Problem 1: Easy 1 - Basic Inheritance Chain Tracker
// ============================================================================
// Description:
// Create a class hierarchy with Base -> Derived. Track the order of
// constructor and destructor calls when creating and destroying objects.
//
// Task: Complete the classes to output constructor/destructor messages.
// When a Derived object is created, Base constructor runs first, then Derived.
// When destroyed, Derived destructor runs first, then Base destructor.
//
// Input Format: A name string for the object
// Output Format: Return a string with all constructor/destructor messages
//                separated by commas (no spaces after commas)
//
// Example 1:
// Input: "obj1"
// Process: Create Derived object, then it goes out of scope
// Expected Output: "Base(obj1),Derived(obj1),~Derived(obj1),~Base(obj1)"
//
// Example 2:
// Input: "test"
// Expected Output: "Base(test),Derived(test),~Derived(test),~Base(test)"
//
// Constraints:
// - Name length: 1-20 characters
// - No spaces in the name

class Base1
{
public:
    string name;
    static string *output;

    // TODO: Implement constructor that appends "Base(name)," to *output
    Base1(string n)
    {

    }

    // TODO: Implement destructor that appends "~Base(name)," to *output
    ~Base1()
    {

    }
};

class Derived1 : public Base1
{
public:
    // TODO: Implement constructor that appends "Derived(name)," to *output
    Derived1(string n) : Base1(n)
    {

    }

    // TODO: Implement destructor that appends "~Derived(name)," to *output
    ~Derived1()
    {

    }
};

string *Base1::output = nullptr;

string problem1Solution(string objectName)
{
    // TODO: Implement your solution here
    // Hint: Create a string to collect output, set Base1::output to point to it,
    // create a Derived1 object in a scope block so it destructs,
    // remove trailing comma and return the result


    return *Base1::output; // Placeholder
}

// ============================================================================
// Problem 2: Easy 2 - Multiple Objects Creation Order
// ============================================================================
// Description:
// Track constructor/destructor calls when creating multiple objects.
// Objects are destroyed in REVERSE order of creation (LIFO - Last In First Out)
//
// Task: Complete the SimpleClass and predict the exact order when creating
// N objects sequentially.
//
// Input Format: Number of objects N
// Output Format: String showing all constructor then all destructor calls
//                Format: "C(1),C(2),...,C(N),D(N),...,D(2),D(1)"
//                where C = Constructor, D = Destructor
//
// Example 1:
// Input: 3
// Process: Create obj1, obj2, obj3, then they destruct in reverse: obj3, obj2, obj1
// Calculation:
//   - Constructors: C(1), C(2), C(3)
//   - Destructors: D(3), D(2), D(1)
// Expected Output: "C(1),C(2),C(3),D(3),D(2),D(1)"
//
// Example 2:
// Input: 1
// Expected Output: "C(1),D(1)"
//
// Example 3:
// Input: 5
// Expected Output: "C(1),C(2),C(3),C(4),C(5),D(5),D(4),D(3),D(2),D(1)"
//
// Constraints:
// - 1 <= N <= 10

class SimpleClass
{
public:
    int id;
    static string *output;

    // TODO: Implement constructor that takes an id and appends "C(id)," to *output

    // TODO: Implement destructor that appends "D(id)," to *output
};

string *SimpleClass::output = nullptr;

string problem2Solution(int n)
{
    // TODO: Implement your solution here
    // Hint: Create a string for output, create N objects in a scope block,
    // they will destruct in reverse order when exiting the block

    return ""; // Placeholder
}

// ============================================================================
// Problem 3: Medium - Member Object Construction Order
// ============================================================================
// Description:
// When a class contains other objects as members, member constructors are
// called BEFORE the containing class constructor, in the order they are
// DECLARED (not initialized). Destructors run in reverse order.
//
// Task: Given a class Container with multiple members, track the exact order.
//
// Class Structure:
// class Container {
//     Member m1;  // declared first
//     Member m2;  // declared second
//     Member m3;  // declared third
// };
//
// Input Format: Three member names (name1, name2, name3)
// Output Format: String showing all constructor/destructor calls
//                Format: "M(name1),M(name2),M(name3),Container,~Container,~M(name3),~M(name2),~M(name1)"
//                where M = Member class
//
// Example 1:
// Input: "A", "B", "C"
// Process:
//   Step 1: Member m1("A") constructor runs -> "M(A),"
//   Step 2: Member m2("B") constructor runs -> "M(B),"
//   Step 3: Member m3("C") constructor runs -> "M(C),"
//   Step 4: Container constructor runs -> "Container,"
//   Step 5: Container destructor runs -> "~Container,"
//   Step 6: Member m3 destructor runs -> "~M(C),"
//   Step 7: Member m2 destructor runs -> "~M(B),"
//   Step 8: Member m1 destructor runs -> "~M(A)"
// Expected Output: "M(A),M(B),M(C),Container,~Container,~M(C),~M(B),~M(A)"
//
// Example 2:
// Input: "X", "Y", "Z"
// Expected Output: "M(X),M(Y),M(Z),Container,~Container,~M(Z),~M(Y),~M(X)"
//
// Constraints:
// - Each name: 1-10 characters
// - No commas in names

class Member
{
public:
    string name;
    static string *output;

    // TODO: Implement constructor taking a name, appends "M(name)," to *output

    // TODO: Implement destructor that appends "~M(name)," to *output
};

string *Member::output = nullptr;

class Container
{
public:
    // TODO: Declare three Member objects m1, m2, m3
    static string *output;

    // TODO: Implement constructor taking three names, initializes members in
    // member initializer list, appends "Container," to *output

    // TODO: Implement destructor that appends "~Container," to *output
};

string *Container::output = nullptr;

string problem3Solution(string name1, string name2, string name3)
{
    // TODO: Implement your solution here
    // Hint: Set up output string, create Container object in a scope,
    // observe the order of member construction before container construction

    return ""; // Placeholder
}

// ============================================================================
// Problem 4: Hard - Complex Multi-Level Inheritance with Members
// ============================================================================
// Description:
// Combine inheritance and member objects. Construction order:
// 1. Base class members (in declaration order)
// 2. Base class constructor
// 3. Derived class members (in declaration order)
// 4. Derived class constructor
// Destruction is exact reverse.
//
// Class Hierarchy:
// class BaseComplex {
//     Component c1;
//     Component c2;
// };
//
// class DerivedComplex : public BaseComplex {
//     Component c3;
//     Component c4;
// };
//
// Input Format: Four component names (comp1, comp2, comp3, comp4)
// Output Format: Complete construction/destruction sequence
//
// Example 1:
// Input: "W", "X", "Y", "Z"
// Process (step by step):
//   Construction phase:
//   Step 1: BaseComplex::c1("W") -> "Comp(W),"
//   Step 2: BaseComplex::c2("X") -> "Comp(X),"
//   Step 3: BaseComplex constructor -> "BaseComplex,"
//   Step 4: DerivedComplex::c3("Y") -> "Comp(Y),"
//   Step 5: DerivedComplex::c4("Z") -> "Comp(Z),"
//   Step 6: DerivedComplex constructor -> "DerivedComplex,"
//
//   Destruction phase (reverse order):
//   Step 7: DerivedComplex destructor -> "~DerivedComplex,"
//   Step 8: DerivedComplex::c4 destructor -> "~Comp(Z),"
//   Step 9: DerivedComplex::c3 destructor -> "~Comp(Y),"
//   Step 10: BaseComplex destructor -> "~BaseComplex,"
//   Step 11: BaseComplex::c2 destructor -> "~Comp(X),"
//   Step 12: BaseComplex::c1 destructor -> "~Comp(W)"
//
// Expected Output: "Comp(W),Comp(X),BaseComplex,Comp(Y),Comp(Z),DerivedComplex,~DerivedComplex,~Comp(Z),~Comp(Y),~BaseComplex,~Comp(X),~Comp(W)"
//
// Example 2:
// Input: "A", "B", "C", "D"
// Expected Output: "Comp(A),Comp(B),BaseComplex,Comp(C),Comp(D),DerivedComplex,~DerivedComplex,~Comp(D),~Comp(C),~BaseComplex,~Comp(B),~Comp(A)"
//
// Constraints:
// - Each component name: 1-10 characters
// - No special characters in names

class Component
{
public:
    string name;
    static string *output;

    // TODO: Implement constructor taking name, appends "Comp(name)," to *output

    // TODO: Implement destructor that appends "~Comp(name)," to *output
};

string *Component::output = nullptr;

class BaseComplex
{
public:
    // TODO: Declare two Component members c1, c2
    static string *output;

    // TODO: Implement constructor taking two names, initializes c1 and c2,
    // appends "BaseComplex," to *output

    // TODO: Implement destructor that appends "~BaseComplex," to *output
};

string *BaseComplex::output = nullptr;

class DerivedComplex : public BaseComplex
{
public:
    // TODO: Declare two Component members c3, c4
    static string *output;

    // TODO: Implement constructor taking four names, initializes base and members,
    // appends "DerivedComplex," to *output

    // TODO: Implement destructor that appends "~DerivedComplex," to *output
};

string *DerivedComplex::output = nullptr;

string problem4Solution(string comp1, string comp2, string comp3, string comp4)
{
    // TODO: Implement your solution here
    // Hint: Create output string, instantiate DerivedComplex in a scope,
    // observe: base members -> base ctor -> derived members -> derived ctor
    // then reverse for destructors

    return ""; // Placeholder
}

// ============================================================================
// TEST FUNCTIONS
// ============================================================================

void testProblem1()
{
    cout << "\n=== Testing Problem 1: Basic Inheritance Chain ===" << endl;

    // Test Case 1: Simple name
    // Manual verification: Base ctor -> Derived ctor -> Derived dtor -> Base dtor
    // Expected: "Base(obj1),Derived(obj1),~Derived(obj1),~Base(obj1)"
    {
        string result = problem1Solution("obj1");
        string expected = "Base(obj1),Derived(obj1),~Derived(obj1),~Base(obj1)";
        cout << "Test 1 (obj1): " << (result == expected ? "PASS" : "FAIL") << endl;
        if (result != expected)
            cout << "  Got: " << result << "\n  Expected: " << expected << endl;
    }

    // Test Case 2: Different name
    {
        string result = problem1Solution("test");
        string expected = "Base(test),Derived(test),~Derived(test),~Base(test)";
        cout << "Test 2 (test): " << (result == expected ? "PASS" : "FAIL") << endl;
        if (result != expected)
            cout << "  Got: " << result << "\n  Expected: " << expected << endl;
    }

    // Test Case 3: Single character name
    {
        string result = problem1Solution("A");
        string expected = "Base(A),Derived(A),~Derived(A),~Base(A)";
        cout << "Test 3 (A): " << (result == expected ? "PASS" : "FAIL") << endl;
        if (result != expected)
            cout << "  Got: " << result << "\n  Expected: " << expected << endl;
    }

    // Test Case 4: Longer name
    {
        string result = problem1Solution("MyObject");
        string expected = "Base(MyObject),Derived(MyObject),~Derived(MyObject),~Base(MyObject)";
        cout << "Test 4 (MyObject): " << (result == expected ? "PASS" : "FAIL") << endl;
        if (result != expected)
            cout << "  Got: " << result << "\n  Expected: " << expected << endl;
    }

    // Test Case 5: Numeric name
    {
        string result = problem1Solution("123");
        string expected = "Base(123),Derived(123),~Derived(123),~Base(123)";
        cout << "Test 5 (123): " << (result == expected ? "PASS" : "FAIL") << endl;
        if (result != expected)
            cout << "  Got: " << result << "\n  Expected: " << expected << endl;
    }

    // Test Case 6: Mixed case name
    {
        string result = problem1Solution("TeSt");
        string expected = "Base(TeSt),Derived(TeSt),~Derived(TeSt),~Base(TeSt)";
        cout << "Test 6 (TeSt): " << (result == expected ? "PASS" : "FAIL") << endl;
        if (result != expected)
            cout << "  Got: " << result << "\n  Expected: " << expected << endl;
    }

    // Test Case 7: Name with numbers
    {
        string result = problem1Solution("obj123");
        string expected = "Base(obj123),Derived(obj123),~Derived(obj123),~Base(obj123)";
        cout << "Test 7 (obj123): " << (result == expected ? "PASS" : "FAIL") << endl;
        if (result != expected)
            cout << "  Got: " << result << "\n  Expected: " << expected << endl;
    }

    // Test Case 8: Underscore in name
    {
        string result = problem1Solution("my_obj");
        string expected = "Base(my_obj),Derived(my_obj),~Derived(my_obj),~Base(my_obj)";
        cout << "Test 8 (my_obj): " << (result == expected ? "PASS" : "FAIL") << endl;
        if (result != expected)
            cout << "  Got: " << result << "\n  Expected: " << expected << endl;
    }
}

void testProblem2()
{
    cout << "\n=== Testing Problem 2: Multiple Objects Creation Order ===" << endl;

    // Test Case 1: Single object
    // Manual verification: C(1) then D(1)
    {
        string result = problem2Solution(1);
        string expected = "C(1),D(1)";
        cout << "Test 1 (n=1): " << (result == expected ? "PASS" : "FAIL") << endl;
        if (result != expected)
            cout << "  Got: " << result << "\n  Expected: " << expected << endl;
    }

    // Test Case 2: Two objects
    // Manual verification: C(1), C(2), then D(2), D(1)
    {
        string result = problem2Solution(2);
        string expected = "C(1),C(2),D(2),D(1)";
        cout << "Test 2 (n=2): " << (result == expected ? "PASS" : "FAIL") << endl;
        if (result != expected)
            cout << "  Got: " << result << "\n  Expected: " << expected << endl;
    }

    // Test Case 3: Three objects
    // Manual verification: C(1), C(2), C(3), then D(3), D(2), D(1)
    {
        string result = problem2Solution(3);
        string expected = "C(1),C(2),C(3),D(3),D(2),D(1)";
        cout << "Test 3 (n=3): " << (result == expected ? "PASS" : "FAIL") << endl;
        if (result != expected)
            cout << "  Got: " << result << "\n  Expected: " << expected << endl;
    }

    // Test Case 4: Four objects
    {
        string result = problem2Solution(4);
        string expected = "C(1),C(2),C(3),C(4),D(4),D(3),D(2),D(1)";
        cout << "Test 4 (n=4): " << (result == expected ? "PASS" : "FAIL") << endl;
        if (result != expected)
            cout << "  Got: " << result << "\n  Expected: " << expected << endl;
    }

    // Test Case 5: Five objects
    {
        string result = problem2Solution(5);
        string expected = "C(1),C(2),C(3),C(4),C(5),D(5),D(4),D(3),D(2),D(1)";
        cout << "Test 5 (n=5): " << (result == expected ? "PASS" : "FAIL") << endl;
        if (result != expected)
            cout << "  Got: " << result << "\n  Expected: " << expected << endl;
    }

    // Test Case 6: Seven objects
    {
        string result = problem2Solution(7);
        string expected = "C(1),C(2),C(3),C(4),C(5),C(6),C(7),D(7),D(6),D(5),D(4),D(3),D(2),D(1)";
        cout << "Test 6 (n=7): " << (result == expected ? "PASS" : "FAIL") << endl;
        if (result != expected)
            cout << "  Got: " << result << "\n  Expected: " << expected << endl;
    }

    // Test Case 7: Ten objects (boundary case)
    {
        string result = problem2Solution(10);
        string expected = "C(1),C(2),C(3),C(4),C(5),C(6),C(7),C(8),C(9),C(10),D(10),D(9),D(8),D(7),D(6),D(5),D(4),D(3),D(2),D(1)";
        cout << "Test 7 (n=10): " << (result == expected ? "PASS" : "FAIL") << endl;
        if (result != expected)
            cout << "  Got: " << result << "\n  Expected: " << expected << endl;
    }

    // Test Case 8: Six objects
    {
        string result = problem2Solution(6);
        string expected = "C(1),C(2),C(3),C(4),C(5),C(6),D(6),D(5),D(4),D(3),D(2),D(1)";
        cout << "Test 8 (n=6): " << (result == expected ? "PASS" : "FAIL") << endl;
        if (result != expected)
            cout << "  Got: " << result << "\n  Expected: " << expected << endl;
    }
}

void testProblem3()
{
    cout << "\n=== Testing Problem 3: Member Object Construction Order ===" << endl;

    // Test Case 1: Standard names
    // Verification: m1(A), m2(B), m3(C), Container, ~Container, ~m3(C), ~m2(B), ~m1(A)
    {
        string result = problem3Solution("A", "B", "C");
        string expected = "M(A),M(B),M(C),Container,~Container,~M(C),~M(B),~M(A)";
        cout << "Test 1 (A,B,C): " << (result == expected ? "PASS" : "FAIL") << endl;
        if (result != expected)
            cout << "  Got: " << result << "\n  Expected: " << expected << endl;
    }

    // Test Case 2: Different names
    {
        string result = problem3Solution("X", "Y", "Z");
        string expected = "M(X),M(Y),M(Z),Container,~Container,~M(Z),~M(Y),~M(X)";
        cout << "Test 2 (X,Y,Z): " << (result == expected ? "PASS" : "FAIL") << endl;
        if (result != expected)
            cout << "  Got: " << result << "\n  Expected: " << expected << endl;
    }

    // Test Case 3: Numbers
    {
        string result = problem3Solution("1", "2", "3");
        string expected = "M(1),M(2),M(3),Container,~Container,~M(3),~M(2),~M(1)";
        cout << "Test 3 (1,2,3): " << (result == expected ? "PASS" : "FAIL") << endl;
        if (result != expected)
            cout << "  Got: " << result << "\n  Expected: " << expected << endl;
    }

    // Test Case 4: Word names
    {
        string result = problem3Solution("first", "second", "third");
        string expected = "M(first),M(second),M(third),Container,~Container,~M(third),~M(second),~M(first)";
        cout << "Test 4 (first,second,third): " << (result == expected ? "PASS" : "FAIL") << endl;
        if (result != expected)
            cout << "  Got: " << result << "\n  Expected: " << expected << endl;
    }

    // Test Case 5: Mixed case
    {
        string result = problem3Solution("aA", "bB", "cC");
        string expected = "M(aA),M(bB),M(cC),Container,~Container,~M(cC),~M(bB),~M(aA)";
        cout << "Test 5 (aA,bB,cC): " << (result == expected ? "PASS" : "FAIL") << endl;
        if (result != expected)
            cout << "  Got: " << result << "\n  Expected: " << expected << endl;
    }

    // Test Case 6: Same names
    {
        string result = problem3Solution("obj", "obj", "obj");
        string expected = "M(obj),M(obj),M(obj),Container,~Container,~M(obj),~M(obj),~M(obj)";
        cout << "Test 6 (obj,obj,obj): " << (result == expected ? "PASS" : "FAIL") << endl;
        if (result != expected)
            cout << "  Got: " << result << "\n  Expected: " << expected << endl;
    }

    // Test Case 7: Long names
    {
        string result = problem3Solution("member1", "member2", "member3");
        string expected = "M(member1),M(member2),M(member3),Container,~Container,~M(member3),~M(member2),~M(member1)";
        cout << "Test 7 (member1,member2,member3): " << (result == expected ? "PASS" : "FAIL") << endl;
        if (result != expected)
            cout << "  Got: " << result << "\n  Expected: " << expected << endl;
    }

    // Test Case 8: Single chars
    {
        string result = problem3Solution("P", "Q", "R");
        string expected = "M(P),M(Q),M(R),Container,~Container,~M(R),~M(Q),~M(P)";
        cout << "Test 8 (P,Q,R): " << (result == expected ? "PASS" : "FAIL") << endl;
        if (result != expected)
            cout << "  Got: " << result << "\n  Expected: " << expected << endl;
    }
}

void testProblem4()
{
    cout << "\n=== Testing Problem 4: Complex Multi-Level Inheritance with Members ===" << endl;

    // Test Case 1: W, X, Y, Z
    // Verification step by step:
    // Construction: c1(W), c2(X), BaseComplex, c3(Y), c4(Z), DerivedComplex
    // Destruction: ~DerivedComplex, ~c4(Z), ~c3(Y), ~BaseComplex, ~c2(X), ~c1(W)
    {
        string result = problem4Solution("W", "X", "Y", "Z");
        string expected = "Comp(W),Comp(X),BaseComplex,Comp(Y),Comp(Z),DerivedComplex,~DerivedComplex,~Comp(Z),~Comp(Y),~BaseComplex,~Comp(X),~Comp(W)";
        cout << "Test 1 (W,X,Y,Z): " << (result == expected ? "PASS" : "FAIL") << endl;
        if (result != expected)
            cout << "  Got: " << result << "\n  Expected: " << expected << endl;
    }

    // Test Case 2: A, B, C, D
    {
        string result = problem4Solution("A", "B", "C", "D");
        string expected = "Comp(A),Comp(B),BaseComplex,Comp(C),Comp(D),DerivedComplex,~DerivedComplex,~Comp(D),~Comp(C),~BaseComplex,~Comp(B),~Comp(A)";
        cout << "Test 2 (A,B,C,D): " << (result == expected ? "PASS" : "FAIL") << endl;
        if (result != expected)
            cout << "  Got: " << result << "\n  Expected: " << expected << endl;
    }

    // Test Case 3: Numbers
    {
        string result = problem4Solution("1", "2", "3", "4");
        string expected = "Comp(1),Comp(2),BaseComplex,Comp(3),Comp(4),DerivedComplex,~DerivedComplex,~Comp(4),~Comp(3),~BaseComplex,~Comp(2),~Comp(1)";
        cout << "Test 3 (1,2,3,4): " << (result == expected ? "PASS" : "FAIL") << endl;
        if (result != expected)
            cout << "  Got: " << result << "\n  Expected: " << expected << endl;
    }

    // Test Case 4: Reverse alphabet
    {
        string result = problem4Solution("D", "C", "B", "A");
        string expected = "Comp(D),Comp(C),BaseComplex,Comp(B),Comp(A),DerivedComplex,~DerivedComplex,~Comp(A),~Comp(B),~BaseComplex,~Comp(C),~Comp(D)";
        cout << "Test 4 (D,C,B,A): " << (result == expected ? "PASS" : "FAIL") << endl;
        if (result != expected)
            cout << "  Got: " << result << "\n  Expected: " << expected << endl;
    }

    // Test Case 5: Same names
    {
        string result = problem4Solution("X", "X", "X", "X");
        string expected = "Comp(X),Comp(X),BaseComplex,Comp(X),Comp(X),DerivedComplex,~DerivedComplex,~Comp(X),~Comp(X),~BaseComplex,~Comp(X),~Comp(X)";
        cout << "Test 5 (X,X,X,X): " << (result == expected ? "PASS" : "FAIL") << endl;
        if (result != expected)
            cout << "  Got: " << result << "\n  Expected: " << expected << endl;
    }

    // Test Case 6: Words
    {
        string result = problem4Solution("one", "two", "three", "four");
        string expected = "Comp(one),Comp(two),BaseComplex,Comp(three),Comp(four),DerivedComplex,~DerivedComplex,~Comp(four),~Comp(three),~BaseComplex,~Comp(two),~Comp(one)";
        cout << "Test 6 (one,two,three,four): " << (result == expected ? "PASS" : "FAIL") << endl;
        if (result != expected)
            cout << "  Got: " << result << "\n  Expected: " << expected << endl;
    }

    // Test Case 7: Mixed
    {
        string result = problem4Solution("P1", "P2", "P3", "P4");
        string expected = "Comp(P1),Comp(P2),BaseComplex,Comp(P3),Comp(P4),DerivedComplex,~DerivedComplex,~Comp(P4),~Comp(P3),~BaseComplex,~Comp(P2),~Comp(P1)";
        cout << "Test 7 (P1,P2,P3,P4): " << (result == expected ? "PASS" : "FAIL") << endl;
        if (result != expected)
            cout << "  Got: " << result << "\n  Expected: " << expected << endl;
    }

    // Test Case 8: Greek letters
    {
        string result = problem4Solution("alpha", "beta", "gamma", "delta");
        string expected = "Comp(alpha),Comp(beta),BaseComplex,Comp(gamma),Comp(delta),DerivedComplex,~DerivedComplex,~Comp(delta),~Comp(gamma),~BaseComplex,~Comp(beta),~Comp(alpha)";
        cout << "Test 8 (alpha,beta,gamma,delta): " << (result == expected ? "PASS" : "FAIL") << endl;
        if (result != expected)
            cout << "  Got: " << result << "\n  Expected: " << expected << endl;
    }
}

int main()
{
    int choice;
    cout << "==================================================" << endl;
    cout << "C++ Constructor/Destructor Order Practice Problems" << endl;
    cout << "==================================================" << endl;
    cout << "Choose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy - Basic Inheritance)" << endl;
    cout << "2. Problem 2 (Easy - Multiple Objects)" << endl;
    cout << "3. Problem 3 (Medium - Member Objects)" << endl;
    cout << "4. Problem 4 (Hard - Multi-Level Inheritance with Members)" << endl;
    cout << "5. Test All Problems" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
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
        cout << "\n==================================================" << endl;
        cout << "All tests completed!" << endl;
        cout << "==================================================" << endl;
        break;
    default:
        cout << "Invalid choice!" << endl;
    }

    return 0;
}