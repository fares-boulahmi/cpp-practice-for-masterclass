#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ============================================================================
// Problem 1: Easy 1 - Accessing Hidden Public Members
// ============================================================================
// You have a base class 'Device' with a public member 'deviceID'.
// A derived class 'Laptop' uses private inheritance, hiding 'deviceID'.
// Your task: Resurrect 'deviceID' to make it publicly accessible in Laptop.
//
// Input Format: No input needed for this problem
// Output Format: Return the deviceID from a Laptop object
//
// Example:
// Laptop laptop;
// laptop.deviceID = 12345;  // Should be accessible after resurrecting
// getDeviceID(laptop) should return 12345
//
// Constraints: Use 'using' declaration to resurrect the member
// ============================================================================

class Device {
public:
    int deviceID;
    Device() : deviceID(0) {}
};

class Laptop : private Device {
    // TODO: Resurrect deviceID here using 'using Device::deviceID;'
public:
    Laptop() {}
};

int problem1Solution(Laptop& laptop) {
    // TODO: Implement your solution here
    // Hint: Simply return the resurrected deviceID member
    return 0; // Replace with actual implementation
}

// ============================================================================
// Problem 2: Easy 2 - Selective Member Resurrection
// ============================================================================
// Base class 'BankAccount' has public members: accountNumber, balance, withdraw()
// Derived class 'SavingsAccount' uses private inheritance.
// Your task: Resurrect ONLY accountNumber and balance (not withdraw) to be public.
//
// Input Format: accountNumber (int), balance (double)
// Output Format: Return the sum of accountNumber and balance as a double
//
// Example:
// SavingsAccount sa;
// sa.accountNumber = 1000;
// sa.balance = 250.50;
// Result: 1000 + 250.50 = 1250.50
//
// Constraints: Resurrect only specified members, keep withdraw() private
// ============================================================================

class BankAccount {
public:
    int accountNumber;
    double balance;
    BankAccount() : accountNumber(0), balance(0.0) {}
    void withdraw(double amount) { balance -= amount; }
};

class SavingsAccount : private BankAccount {
    // TODO: Resurrect ONLY accountNumber and balance using 'using' declarations
public:
    SavingsAccount() {}
};

double problem2Solution(SavingsAccount& sa) {
    // TODO: Implement your solution here
    // Hint: Access the resurrected members and return their sum
    return 0.0; // Replace with actual implementation
}

// ============================================================================
// Problem 3: Medium - Resurrection Chain with Protected Inheritance
// ============================================================================
// Class hierarchy: Animal (public: name, age) -> Mammal (protected inheritance)
//                  -> Dog (private inheritance from Mammal)
// Your task: In Dog class, resurrect 'name' as public and 'age' as protected.
// Then create a method that uses both resurrected members.
//
// Input Format: name (string), age (int), dogYears multiplier (int)
// Output Format: Return a string: "Name: [name], Human Years: [age], Dog Years: [age*multiplier]"
//
// Example:
// name = "Buddy", age = 5, multiplier = 7
// Result: "Name: Buddy, Human Years: 5, Dog Years: 35"
//
// Constraints: 
// - name must be public in Dog
// - age must be protected in Dog
// - Use resurrected members to calculate result
// ============================================================================

class Animal {
public:
    string name;
    int age;
    Animal() : name(""), age(0) {}
};

class Mammal : protected Animal {
public:
    Mammal() {}
};

class Dog : private Mammal {
    // TODO: Resurrect 'name' as public and 'age' as protected
protected:
    // age should be accessible here after resurrection
public:
    Dog() {}
    
    string getDogInfo(int multiplier) {
        // TODO: Implement using resurrected members
        // Hint: Build the string using name and age members
        return ""; // Replace with actual implementation
    }
};

string problem3Solution(Dog& dog, const string& dogName, int dogAge, int multiplier) {
    // TODO: Set the dog's name and age, then call getDogInfo
    // Hint: Use the resurrected public 'name' member directly
    return ""; // Replace with actual implementation
}

// ============================================================================
// Problem 4: Hard - Multiple Inheritance with Selective Resurrection
// ============================================================================
// Classes: Printer (public: print, paperCount), Scanner (public: scan, resolution)
// Derived class 'MultiDevice' inherits PRIVATELY from both Printer and Scanner.
// Your task: 
// 1. Resurrect 'print' and 'scan' methods as public
// 2. Resurrect 'paperCount' as public but 'resolution' as protected
// 3. Implement a method that uses all resurrected members
//
// Input Format: paperCount (int), resolution (int), printJobs (int), scanJobs (int)
// Output Format: Return total operations count as: printJobs + scanJobs + (paperCount/10) + (resolution/100)
//
// Example:
// paperCount = 500, resolution = 1200, printJobs = 10, scanJobs = 5
// Calculation: 10 + 5 + (500/10) + (1200/100) = 10 + 5 + 50 + 12 = 77
//
// Constraints: 
// - Use integer division
// - Resurrect members with correct access levels
// - Must handle both base classes properly
// ============================================================================

class Printer {
public:
    int paperCount;
    Printer() : paperCount(0) {}
    void print() { paperCount--; }
};

class Scanner {
public:
    int resolution;
    Scanner() : resolution(0) {}
    void scan() {}
};

class MultiDevice : private Printer, private Scanner {
    // TODO: Resurrect print(), scan(), paperCount as public
    // TODO: Resurrect resolution as protected
protected:
    // resolution should be accessible here after resurrection
public:
    MultiDevice() {}
    
    int calculateOperations(int printJobs, int scanJobs) {
        // TODO: Implement calculation using resurrected members
        // Hint: Use paperCount, resolution, and the formula given
        return 0; // Replace with actual implementation
    }
};

int problem4Solution(MultiDevice& md, int paperCount, int resolution, int printJobs, int scanJobs) {
    // TODO: Set paperCount and resolution, then call calculateOperations
    // Hint: Use the resurrected public members
    return 0; // Replace with actual implementation
}

// ============================================================================
// TEST FUNCTIONS
// ============================================================================

void testProblem1() {
    cout << "\n========================================" << endl;
    cout << "Testing Problem 1: Accessing Hidden Public Members" << endl;
    cout << "========================================" << endl;
    
    // Test Case 1: Basic device ID
    // Expected: deviceID = 100, return 100
    {
        Laptop laptop;
        laptop.deviceID = 100;
        int result = problem1Solution(laptop);
        cout << "Test 1 (deviceID=100): " << (result == 100 ? "PASS" : "FAIL") 
             << " | Expected: 100, Got: " << result << endl;
    }
    
    // Test Case 2: Zero device ID
    // Expected: deviceID = 0, return 0
    {
        Laptop laptop;
        laptop.deviceID = 0;
        int result = problem1Solution(laptop);
        cout << "Test 2 (deviceID=0): " << (result == 0 ? "PASS" : "FAIL") 
             << " | Expected: 0, Got: " << result << endl;
    }
    
    // Test Case 3: Large device ID
    // Expected: deviceID = 999999, return 999999
    {
        Laptop laptop;
        laptop.deviceID = 999999;
        int result = problem1Solution(laptop);
        cout << "Test 3 (deviceID=999999): " << (result == 999999 ? "PASS" : "FAIL") 
             << " | Expected: 999999, Got: " << result << endl;
    }
    
    // Test Case 4: Negative device ID
    // Expected: deviceID = -500, return -500
    {
        Laptop laptop;
        laptop.deviceID = -500;
        int result = problem1Solution(laptop);
        cout << "Test 4 (deviceID=-500): " << (result == -500 ? "PASS" : "FAIL") 
             << " | Expected: -500, Got: " << result << endl;
    }
    
    // Test Case 5: Small positive ID
    // Expected: deviceID = 7, return 7
    {
        Laptop laptop;
        laptop.deviceID = 7;
        int result = problem1Solution(laptop);
        cout << "Test 5 (deviceID=7): " << (result == 7 ? "PASS" : "FAIL") 
             << " | Expected: 7, Got: " << result << endl;
    }
}

void testProblem2() {
    cout << "\n========================================" << endl;
    cout << "Testing Problem 2: Selective Member Resurrection" << endl;
    cout << "========================================" << endl;
    
    // Test Case 1: Basic sum
    // Calculation: 1000 + 250.50 = 1250.50
    {
        SavingsAccount sa;
        sa.accountNumber = 1000;
        sa.balance = 250.50;
        double result = problem2Solution(sa);
        cout << "Test 1 (1000 + 250.50): " << (result == 1250.50 ? "PASS" : "FAIL") 
             << " | Expected: 1250.50, Got: " << result << endl;
    }
    
    // Test Case 2: Zero balance
    // Calculation: 5000 + 0.0 = 5000.0
    {
        SavingsAccount sa;
        sa.accountNumber = 5000;
        sa.balance = 0.0;
        double result = problem2Solution(sa);
        cout << "Test 2 (5000 + 0.0): " << (result == 5000.0 ? "PASS" : "FAIL") 
             << " | Expected: 5000.0, Got: " << result << endl;
    }
    
    // Test Case 3: Large values
    // Calculation: 100000 + 99999.99 = 199999.99
    {
        SavingsAccount sa;
        sa.accountNumber = 100000;
        sa.balance = 99999.99;
        double result = problem2Solution(sa);
        cout << "Test 3 (100000 + 99999.99): " << (result == 199999.99 ? "PASS" : "FAIL") 
             << " | Expected: 199999.99, Got: " << result << endl;
    }
    
    // Test Case 4: Decimal balance
    // Calculation: 12345 + 0.01 = 12345.01
    {
        SavingsAccount sa;
        sa.accountNumber = 12345;
        sa.balance = 0.01;
        double result = problem2Solution(sa);
        cout << "Test 4 (12345 + 0.01): " << (result == 12345.01 ? "PASS" : "FAIL") 
             << " | Expected: 12345.01, Got: " << result << endl;
    }
    
    // Test Case 5: Small account number
    // Calculation: 1 + 1000000.50 = 1000001.50
    {
        SavingsAccount sa;
        sa.accountNumber = 1;
        sa.balance = 1000000.50;
        double result = problem2Solution(sa);
        cout << "Test 5 (1 + 1000000.50): " << (result == 1000001.50 ? "PASS" : "FAIL") 
             << " | Expected: 1000001.50, Got: " << result << endl;
    }
    
    // Test Case 6: Both zero
    // Calculation: 0 + 0.0 = 0.0
    {
        SavingsAccount sa;
        sa.accountNumber = 0;
        sa.balance = 0.0;
        double result = problem2Solution(sa);
        cout << "Test 6 (0 + 0.0): " << (result == 0.0 ? "PASS" : "FAIL") 
             << " | Expected: 0.0, Got: " << result << endl;
    }
}

void testProblem3() {
    cout << "\n========================================" << endl;
    cout << "Testing Problem 3: Resurrection Chain" << endl;
    cout << "========================================" << endl;
    
    // Test Case 1: Basic dog years
    // Calculation: age=5, multiplier=7, dogYears=5*7=35
    // Expected: "Name: Buddy, Human Years: 5, Dog Years: 35"
    {
        Dog dog;
        string result = problem3Solution(dog, "Buddy", 5, 7);
        string expected = "Name: Buddy, Human Years: 5, Dog Years: 35";
        cout << "Test 1: " << (result == expected ? "PASS" : "FAIL") << endl;
        cout << "  Expected: " << expected << endl;
        cout << "  Got:      " << result << endl;
    }
    
    // Test Case 2: Age zero
    // Calculation: age=0, multiplier=7, dogYears=0*7=0
    // Expected: "Name: Puppy, Human Years: 0, Dog Years: 0"
    {
        Dog dog;
        string result = problem3Solution(dog, "Puppy", 0, 7);
        string expected = "Name: Puppy, Human Years: 0, Dog Years: 0";
        cout << "Test 2: " << (result == expected ? "PASS" : "FAIL") << endl;
        cout << "  Expected: " << expected << endl;
        cout << "  Got:      " << result << endl;
    }
    
    // Test Case 3: Old dog
    // Calculation: age=15, multiplier=7, dogYears=15*7=105
    // Expected: "Name: Max, Human Years: 15, Dog Years: 105"
    {
        Dog dog;
        string result = problem3Solution(dog, "Max", 15, 7);
        string expected = "Name: Max, Human Years: 15, Dog Years: 105";
        cout << "Test 3: " << (result == expected ? "PASS" : "FAIL") << endl;
        cout << "  Expected: " << expected << endl;
        cout << "  Got:      " << result << endl;
    }
    
    // Test Case 4: Different multiplier
    // Calculation: age=3, multiplier=10, dogYears=3*10=30
    // Expected: "Name: Luna, Human Years: 3, Dog Years: 30"
    {
        Dog dog;
        string result = problem3Solution(dog, "Luna", 3, 10);
        string expected = "Name: Luna, Human Years: 3, Dog Years: 30";
        cout << "Test 4: " << (result == expected ? "PASS" : "FAIL") << endl;
        cout << "  Expected: " << expected << endl;
        cout << "  Got:      " << result << endl;
    }
    
    // Test Case 5: Single character name
    // Calculation: age=8, multiplier=7, dogYears=8*7=56
    // Expected: "Name: Z, Human Years: 8, Dog Years: 56"
    {
        Dog dog;
        string result = problem3Solution(dog, "Z", 8, 7);
        string expected = "Name: Z, Human Years: 8, Dog Years: 56";
        cout << "Test 5: " << (result == expected ? "PASS" : "FAIL") << endl;
        cout << "  Expected: " << expected << endl;
        cout << "  Got:      " << result << endl;
    }
    
    // Test Case 6: Multiplier of 1
    // Calculation: age=12, multiplier=1, dogYears=12*1=12
    // Expected: "Name: Rocky, Human Years: 12, Dog Years: 12"
    {
        Dog dog;
        string result = problem3Solution(dog, "Rocky", 12, 1);
        string expected = "Name: Rocky, Human Years: 12, Dog Years: 12";
        cout << "Test 6: " << (result == expected ? "PASS" : "FAIL") << endl;
        cout << "  Expected: " << expected << endl;
        cout << "  Got:      " << result << endl;
    }
}

void testProblem4() {
    cout << "\n========================================" << endl;
    cout << "Testing Problem 4: Multiple Inheritance Resurrection" << endl;
    cout << "========================================" << endl;
    
    // Test Case 1: Basic calculation
    // Calculation: printJobs=10, scanJobs=5, paperCount=500, resolution=1200
    // Result: 10 + 5 + (500/10) + (1200/100) = 10 + 5 + 50 + 12 = 77
    {
        MultiDevice md;
        int result = problem4Solution(md, 500, 1200, 10, 5);
        cout << "Test 1 (10+5+50+12): " << (result == 77 ? "PASS" : "FAIL") 
             << " | Expected: 77, Got: " << result << endl;
    }
    
    // Test Case 2: Zero jobs
    // Calculation: printJobs=0, scanJobs=0, paperCount=1000, resolution=2000
    // Result: 0 + 0 + (1000/10) + (2000/100) = 0 + 0 + 100 + 20 = 120
    {
        MultiDevice md;
        int result = problem4Solution(md, 1000, 2000, 0, 0);
        cout << "Test 2 (0+0+100+20): " << (result == 120 ? "PASS" : "FAIL") 
             << " | Expected: 120, Got: " << result << endl;
    }
    
    // Test Case 3: Large values
    // Calculation: printJobs=100, scanJobs=50, paperCount=5000, resolution=3000
    // Result: 100 + 50 + (5000/10) + (3000/100) = 100 + 50 + 500 + 30 = 680
    {
        MultiDevice md;
        int result = problem4Solution(md, 5000, 3000, 100, 50);
        cout << "Test 3 (100+50+500+30): " << (result == 680 ? "PASS" : "FAIL") 
             << " | Expected: 680, Got: " << result << endl;
    }
    
    // Test Case 4: Small paper and resolution
    // Calculation: printJobs=7, scanJobs=3, paperCount=50, resolution=150
    // Result: 7 + 3 + (50/10) + (150/100) = 7 + 3 + 5 + 1 = 16
    {
        MultiDevice md;
        int result = problem4Solution(md, 50, 150, 7, 3);
        cout << "Test 4 (7+3+5+1): " << (result == 16 ? "PASS" : "FAIL") 
             << " | Expected: 16, Got: " << result << endl;
    }
    
    // Test Case 5: Integer division truncation
    // Calculation: printJobs=1, scanJobs=1, paperCount=99, resolution=999
    // Result: 1 + 1 + (99/10) + (999/100) = 1 + 1 + 9 + 9 = 20
    {
        MultiDevice md;
        int result = problem4Solution(md, 99, 999, 1, 1);
        cout << "Test 5 (1+1+9+9): " << (result == 20 ? "PASS" : "FAIL") 
             << " | Expected: 20, Got: " << result << endl;
    }
    
    // Test Case 6: All minimum values
    // Calculation: printJobs=0, scanJobs=0, paperCount=0, resolution=0
    // Result: 0 + 0 + (0/10) + (0/100) = 0 + 0 + 0 + 0 = 0
    {
        MultiDevice md;
        int result = problem4Solution(md, 0, 0, 0, 0);
        cout << "Test 6 (0+0+0+0): " << (result == 0 ? "PASS" : "FAIL") 
             << " | Expected: 0, Got: " << result << endl;
    }
    
    // Test Case 7: Only printJobs
    // Calculation: printJobs=25, scanJobs=0, paperCount=200, resolution=500
    // Result: 25 + 0 + (200/10) + (500/100) = 25 + 0 + 20 + 5 = 50
    {
        MultiDevice md;
        int result = problem4Solution(md, 200, 500, 25, 0);
        cout << "Test 7 (25+0+20+5): " << (result == 50 ? "PASS" : "FAIL") 
             << " | Expected: 50, Got: " << result << endl;
    }
    
    // Test Case 8: Only scanJobs
    // Calculation: printJobs=0, scanJobs=30, paperCount=300, resolution=600
    // Result: 0 + 30 + (300/10) + (600/100) = 0 + 30 + 30 + 6 = 66
    {
        MultiDevice md;
        int result = problem4Solution(md, 300, 600, 0, 30);
        cout << "Test 8 (0+30+30+6): " << (result == 66 ? "PASS" : "FAIL") 
             << " | Expected: 66, Got: " << result << endl;
    }
}

int main() {
    int choice;
    cout << "\n============================================" << endl;
    cout << "  C++ Practice: Resurrecting Members" << endl;
    cout << "============================================" << endl;
    cout << "Choose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy - Basic Resurrection)" << endl;
    cout << "2. Problem 2 (Easy - Selective Resurrection)" << endl;
    cout << "3. Problem 3 (Medium - Resurrection Chain)" << endl;
    cout << "4. Problem 4 (Hard - Multiple Inheritance)" << endl;
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

    cout << "\n============================================" << endl;
    cout << "  Testing Complete!" << endl;
    cout << "============================================\n" << endl;

    return 0;
}