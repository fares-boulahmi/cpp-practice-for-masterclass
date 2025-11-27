#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ============================================================================
// Problem 1: Easy 1 - Access Level Checker
// ============================================================================
// Description:
// Create a base class 'Vehicle' with public, protected, and private members.
// Create a derived class 'Car' that inherits from Vehicle using PUBLIC inheritance.
// Implement a function that returns which members are accessible in the derived class.
//
// Input Format:
// No input required - this is a design problem
//
// Output Format:
// Return an integer representing the count of accessible members (public + protected)
// from the base class inside the derived class
//
// Example:
// Base class Vehicle has:
// - 1 public member (wheels)
// - 1 protected member (engine)
// - 1 private member (chassis)
// With PUBLIC inheritance, Car can access: public (becomes public) + protected (becomes protected) = 2 members
// Output: 2
//
// Constraints:
// - Use only public inheritance
// - Count only direct member variables, not methods

class Vehicle {
public:
    int wheels;
protected:
    string engine;
private:
    string chassis;
};

class Car : public Vehicle {
public:
    int countAccessibleMembers() {
        // TODO: Implement your solution here
        // Hint: In public inheritance, you can access public and protected members of base class
        // Try to access each member and count how many are accessible
        return 0;
    }
};

int problem1Solution() {
    Car c;
    return c.countAccessibleMembers();
}

// ============================================================================
// Problem 2: Easy 2 - Inheritance Access Transformer
// ============================================================================
// Description:
// Create a base class 'Shape' with public and protected members.
// Create THREE derived classes with DIFFERENT access specifiers:
// - PublicCircle (public inheritance)
// - ProtectedCircle (protected inheritance)
// - PrivateCircle (private inheritance)
//
// Implement a function that returns the access level of base class's PUBLIC member
// in each derived class.
//
// Input Format:
// Integer type (1 = public inheritance, 2 = protected inheritance, 3 = private inheritance)
//
// Output Format:
// Return integer representing final access level:
// 1 = public, 2 = protected, 3 = private/inaccessible
//
// Example 1:
// Input: 1 (public inheritance)
// Base class public member remains public in derived class
// Output: 1
//
// Example 2:
// Input: 2 (protected inheritance)
// Base class public member becomes protected in derived class
// Output: 2
//
// Example 3:
// Input: 3 (private inheritance)
// Base class public member becomes private in derived class
// Output: 3
//
// Constraints:
// - Use all three types of inheritance
// - Focus on PUBLIC member of base class only

class Shape {
public:
    double area;
protected:
    double perimeter;
};

int problem2Solution(int inheritanceType) {
    // TODO: Implement your solution here
    // Hint: Create three derived classes with different inheritance specifiers
    // Return the access level based on the inheritance type
    // Remember: public->public(1), public->protected(2), public->private(3)
    return 0;
}

// ============================================================================
// Problem 3: Medium - Multi-Level Inheritance Access Chain
// ============================================================================
// Description:
// Create a three-level inheritance hierarchy:
// Animal (base) -> Mammal (derived) -> Dog (derived from Mammal)
// 
// Animal has: public memberCount, protected speciesName, private internalID
// Mammal inherits from Animal using PROTECTED inheritance
// Dog inherits from Mammal using PUBLIC inheritance
//
// Calculate how many members from Animal class are accessible in Dog class
// and what their final access levels are.
//
// Input Format:
// No input required
//
// Output Format:
// Return total count of members from Animal that Dog can access
//
// Example:
// Animal: public memberCount, protected speciesName, private internalID
// After protected inheritance to Mammal:
//   - public memberCount becomes protected
//   - protected speciesName stays protected
//   - private internalID is NOT accessible
// After public inheritance to Dog:
//   - protected memberCount stays protected (accessible)
//   - protected speciesName stays protected (accessible)
//   - private internalID still NOT accessible
// Output: 2 (memberCount and speciesName are accessible in Dog)
//
// Constraints:
// - Use multi-level inheritance
// - Use mixed access specifiers
// - Count only members accessible in the final derived class

class Animal {
public:
    int memberCount;
protected:
    string speciesName;
private:
    int internalID;
};

int problem3Solution() {
    // TODO: Implement your solution here
    // Hint: Create Mammal class with protected inheritance from Animal
    // Then create Dog class with public inheritance from Mammal
    // Count accessible members in Dog from Animal
    return 0;
}

// ============================================================================
// Problem 4: Hard - Access Specifier Matrix Calculator
// ============================================================================
// Description:
// Given a base class with n public, m protected, and p private members,
// and a derived class with a specific inheritance type, calculate:
// 1. How many members are accessible in derived class
// 2. How many are public in derived class
// 3. How many are protected in derived class
// 4. Return sum of (accessible_count * 100 + public_count * 10 + protected_count)
//
// Input Format:
// Four integers: n (public), m (protected), p (private), inheritanceType (1/2/3)
// inheritanceType: 1=public, 2=protected, 3=private
//
// Output Format:
// Integer: accessible*100 + public*10 + protected
//
// Example 1:
// Input: n=2, m=3, p=1, inheritanceType=1 (public inheritance)
// Base: 2 public, 3 protected, 1 private
// After public inheritance:
//   - 2 public members stay public (accessible)
//   - 3 protected members stay protected (accessible)
//   - 1 private member NOT accessible
// Accessible = 5, Public in derived = 2, Protected in derived = 3
// Output: 5*100 + 2*10 + 3 = 523
//
// Example 2:
// Input: n=2, m=3, p=1, inheritanceType=2 (protected inheritance)
// Base: 2 public, 3 protected, 1 private
// After protected inheritance:
//   - 2 public members become protected (accessible)
//   - 3 protected members stay protected (accessible)
//   - 1 private member NOT accessible
// Accessible = 5, Public in derived = 0, Protected in derived = 5
// Output: 5*100 + 0*10 + 5 = 505
//
// Example 3:
// Input: n=2, m=3, p=1, inheritanceType=3 (private inheritance)
// Base: 2 public, 3 protected, 1 private
// After private inheritance:
//   - 2 public members become private (accessible in derived class itself)
//   - 3 protected members become private (accessible in derived class itself)
//   - 1 private member NOT accessible
// Accessible = 5, Public in derived = 0, Protected in derived = 0
// Output: 5*100 + 0*10 + 0 = 500
//
// Constraints:
// - 0 <= n, m, p <= 10
// - inheritanceType is 1, 2, or 3

int problem4Solution(int n, int m, int p, int inheritanceType) {
    // TODO: Implement your solution here
    // Hint: Use the access specifier transformation rules:
    // Public inheritance: public->public, protected->protected, private->inaccessible
    // Protected inheritance: public->protected, protected->protected, private->inaccessible
    // Private inheritance: public->private, protected->private, private->inaccessible
    // Calculate: accessible, public_in_derived, protected_in_derived
    // Return: accessible*100 + public_in_derived*10 + protected_in_derived
    return 0;
}

// ============================================================================
// TEST FUNCTIONS
// ============================================================================

void testProblem1() {
    cout << "\n=== Testing Problem 1: Access Level Checker ===" << endl;
    
    // Test Case 1: Basic public inheritance
    // Vehicle has 3 members total: 1 public (wheels), 1 protected (engine), 1 private (chassis)
    // Car with PUBLIC inheritance can access: public + protected = 2 members
    // Expected: 2
    cout << "Test 1 - Basic access count: " << (problem1Solution() == 2 ? "PASS" : "FAIL") << endl;
    cout << "  Expected: 2 (public + protected members accessible)" << endl;
    cout << "  Explanation: wheels (public) and engine (protected) are accessible in Car" << endl;
}

void testProblem2() {
    cout << "\n=== Testing Problem 2: Inheritance Access Transformer ===" << endl;
    
    // Test Case 1: Public inheritance
    // Base public member with public inheritance stays public
    // Expected: 1
    cout << "Test 1 - Public inheritance: " << (problem2Solution(1) == 1 ? "PASS" : "FAIL") << endl;
    cout << "  Input: 1 (public inheritance)" << endl;
    cout << "  Expected: 1 (base public stays public)" << endl;
    
    // Test Case 2: Protected inheritance
    // Base public member with protected inheritance becomes protected
    // Expected: 2
    cout << "Test 2 - Protected inheritance: " << (problem2Solution(2) == 2 ? "PASS" : "FAIL") << endl;
    cout << "  Input: 2 (protected inheritance)" << endl;
    cout << "  Expected: 2 (base public becomes protected)" << endl;
    
    // Test Case 3: Private inheritance
    // Base public member with private inheritance becomes private
    // Expected: 3
    cout << "Test 3 - Private inheritance: " << (problem2Solution(3) == 3 ? "PASS" : "FAIL") << endl;
    cout << "  Input: 3 (private inheritance)" << endl;
    cout << "  Expected: 3 (base public becomes private)" << endl;
    
    // Test Case 4: Verify public inheritance again
    // Expected: 1
    cout << "Test 4 - Public inheritance recheck: " << (problem2Solution(1) == 1 ? "PASS" : "FAIL") << endl;
    cout << "  Input: 1" << endl;
    cout << "  Expected: 1" << endl;
    
    // Test Case 5: Verify protected inheritance again
    // Expected: 2
    cout << "Test 5 - Protected inheritance recheck: " << (problem2Solution(2) == 2 ? "PASS" : "FAIL") << endl;
    cout << "  Input: 2" << endl;
    cout << "  Expected: 2" << endl;
}

void testProblem3() {
    cout << "\n=== Testing Problem 3: Multi-Level Inheritance Access Chain ===" << endl;
    
    // Test Case 1: Three-level inheritance with mixed specifiers
    // Animal: 1 public (memberCount), 1 protected (speciesName), 1 private (internalID)
    // Mammal (protected inheritance from Animal):
    //   - memberCount: public -> protected (accessible)
    //   - speciesName: protected -> protected (accessible)
    //   - internalID: private -> NOT accessible
    // Dog (public inheritance from Mammal):
    //   - memberCount: protected -> protected (accessible)
    //   - speciesName: protected -> protected (accessible)
    //   - internalID: still NOT accessible
    // Total accessible in Dog from Animal: 2
    // Expected: 2
    cout << "Test 1 - Multi-level access count: " << (problem3Solution() == 2 ? "PASS" : "FAIL") << endl;
    cout << "  Expected: 2" << endl;
    cout << "  Calculation:" << endl;
    cout << "    Animal -> Mammal (protected): public->protected, protected->protected, private->X" << endl;
    cout << "    Mammal -> Dog (public): protected->protected, protected->protected" << endl;
    cout << "    Dog can access: memberCount (protected) + speciesName (protected) = 2" << endl;
}

void testProblem4() {
    cout << "\n=== Testing Problem 4: Access Specifier Matrix Calculator ===" << endl;
    
    // Test Case 1: Public inheritance with multiple members
    // Input: n=2, m=3, p=1, type=1
    // Base: 2 public, 3 protected, 1 private
    // After PUBLIC inheritance:
    //   - 2 public stay public
    //   - 3 protected stay protected
    //   - 1 private NOT accessible
    // accessible=5, public_in_derived=2, protected_in_derived=3
    // Result: 5*100 + 2*10 + 3 = 523
    cout << "Test 1 - Public inheritance (2,3,1,1): " 
         << (problem4Solution(2, 3, 1, 1) == 523 ? "PASS" : "FAIL") << endl;
    cout << "  Input: n=2 public, m=3 protected, p=1 private, type=1 (public)" << endl;
    cout << "  Accessible=5, Public=2, Protected=3" << endl;
    cout << "  Expected: 5*100 + 2*10 + 3 = 523" << endl;
    
    // Test Case 2: Protected inheritance
    // Input: n=2, m=3, p=1, type=2
    // After PROTECTED inheritance:
    //   - 2 public become protected
    //   - 3 protected stay protected
    //   - 1 private NOT accessible
    // accessible=5, public_in_derived=0, protected_in_derived=5
    // Result: 5*100 + 0*10 + 5 = 505
    cout << "Test 2 - Protected inheritance (2,3,1,2): " 
         << (problem4Solution(2, 3, 1, 2) == 505 ? "PASS" : "FAIL") << endl;
    cout << "  Input: n=2, m=3, p=1, type=2 (protected)" << endl;
    cout << "  Accessible=5, Public=0, Protected=5" << endl;
    cout << "  Expected: 5*100 + 0*10 + 5 = 505" << endl;
    
    // Test Case 3: Private inheritance
    // Input: n=2, m=3, p=1, type=3
    // After PRIVATE inheritance:
    //   - 2 public become private
    //   - 3 protected become private
    //   - 1 private NOT accessible
    // accessible=5, public_in_derived=0, protected_in_derived=0
    // Result: 5*100 + 0*10 + 0 = 500
    cout << "Test 3 - Private inheritance (2,3,1,3): " 
         << (problem4Solution(2, 3, 1, 3) == 500 ? "PASS" : "FAIL") << endl;
    cout << "  Input: n=2, m=3, p=1, type=3 (private)" << endl;
    cout << "  Accessible=5, Public=0, Protected=0" << endl;
    cout << "  Expected: 5*100 + 0*10 + 0 = 500" << endl;
    
    // Test Case 4: Edge case - no protected members, public inheritance
    // Input: n=3, m=0, p=2, type=1
    // After PUBLIC inheritance:
    //   - 3 public stay public
    //   - 0 protected (none)
    //   - 2 private NOT accessible
    // accessible=3, public_in_derived=3, protected_in_derived=0
    // Result: 3*100 + 3*10 + 0 = 330
    cout << "Test 4 - No protected members (3,0,2,1): " 
         << (problem4Solution(3, 0, 2, 1) == 330 ? "PASS" : "FAIL") << endl;
    cout << "  Input: n=3, m=0, p=2, type=1" << endl;
    cout << "  Accessible=3, Public=3, Protected=0" << endl;
    cout << "  Expected: 3*100 + 3*10 + 0 = 330" << endl;
    
    // Test Case 5: Edge case - only private members
    // Input: n=0, m=0, p=5, type=1
    // After PUBLIC inheritance:
    //   - 0 public (none)
    //   - 0 protected (none)
    //   - 5 private NOT accessible
    // accessible=0, public_in_derived=0, protected_in_derived=0
    // Result: 0*100 + 0*10 + 0 = 0
    cout << "Test 5 - Only private members (0,0,5,1): " 
         << (problem4Solution(0, 0, 5, 1) == 0 ? "PASS" : "FAIL") << endl;
    cout << "  Input: n=0, m=0, p=5, type=1" << endl;
    cout << "  Accessible=0, Public=0, Protected=0" << endl;
    cout << "  Expected: 0*100 + 0*10 + 0 = 0" << endl;
    
    // Test Case 6: Single member of each type, protected inheritance
    // Input: n=1, m=1, p=1, type=2
    // After PROTECTED inheritance:
    //   - 1 public becomes protected
    //   - 1 protected stays protected
    //   - 1 private NOT accessible
    // accessible=2, public_in_derived=0, protected_in_derived=2
    // Result: 2*100 + 0*10 + 2 = 202
    cout << "Test 6 - Balanced members, protected (1,1,1,2): " 
         << (problem4Solution(1, 1, 1, 2) == 202 ? "PASS" : "FAIL") << endl;
    cout << "  Input: n=1, m=1, p=1, type=2" << endl;
    cout << "  Accessible=2, Public=0, Protected=2" << endl;
    cout << "  Expected: 2*100 + 0*10 + 2 = 202" << endl;
    
    // Test Case 7: Large numbers, private inheritance
    // Input: n=5, m=4, p=3, type=3
    // After PRIVATE inheritance:
    //   - 5 public become private
    //   - 4 protected become private
    //   - 3 private NOT accessible
    // accessible=9, public_in_derived=0, protected_in_derived=0
    // Result: 9*100 + 0*10 + 0 = 900
    cout << "Test 7 - Large numbers, private (5,4,3,3): " 
         << (problem4Solution(5, 4, 3, 3) == 900 ? "PASS" : "FAIL") << endl;
    cout << "  Input: n=5, m=4, p=3, type=3" << endl;
    cout << "  Accessible=9, Public=0, Protected=0" << endl;
    cout << "  Expected: 9*100 + 0*10 + 0 = 900" << endl;
    
    // Test Case 8: Only public members, all inheritance types
    // Input: n=4, m=0, p=0, type=1
    // After PUBLIC inheritance:
    //   - 4 public stay public
    // accessible=4, public_in_derived=4, protected_in_derived=0
    // Result: 4*100 + 4*10 + 0 = 440
    cout << "Test 8 - Only public, public inheritance (4,0,0,1): " 
         << (problem4Solution(4, 0, 0, 1) == 440 ? "PASS" : "FAIL") << endl;
    cout << "  Input: n=4, m=0, p=0, type=1" << endl;
    cout << "  Accessible=4, Public=4, Protected=0" << endl;
    cout << "  Expected: 4*100 + 4*10 + 0 = 440" << endl;
}

int main() {
    int choice;
    cout << "===========================================================" << endl;
    cout << "   C++ Base Class Access Specifiers - Practice Problems   " << endl;
    cout << "===========================================================" << endl;
    cout << "Choose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy) - Access Level Checker" << endl;
    cout << "2. Problem 2 (Easy-Medium) - Inheritance Access Transformer" << endl;
    cout << "3. Problem 3 (Medium) - Multi-Level Inheritance Access Chain" << endl;
    cout << "4. Problem 4 (Hard) - Access Specifier Matrix Calculator" << endl;
    cout << "5. Test All Problems" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice) {
        case 1: testProblem1(); break;
        case 2: testProblem2(); break;
        case 3: testProblem3(); break;
        case 4: testProblem4(); break;
        case 5:
            testProblem1();
            testProblem2();
            testProblem3();
            testProblem4();
            break;
        default: cout << "Invalid choice!" << endl;
    }

    return 0;
}