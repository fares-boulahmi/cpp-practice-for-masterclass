#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>
#include <iomanip>

using namespace std;

// Problem 1: Easy 1 - Point Initialization Checker
//
// You are building a 2D graphics system. Create a Point class that represents
// a point in 2D space with x and y coordinates.
//
// Requirements:
// - The class should have a defaulted default constructor
// - The class should have a parameterized constructor Point(int x, int y)
// - The class should have public member variables: x and y (both int)
// - Implement isOrigin() method that returns true if point is at (0,0)
//
// Input: Test will create points and check if they're at origin
// Output: Return true if point is at origin (0,0), false otherwise
//
// Example 1:
// Point p1;  // Uses default constructor
// p1.isOrigin() → true (because default values are 0,0)
//
// Example 2:
// Point p2(3, 4);
// p2.isOrigin() → false (because x=3, y=4)
//
// Example 3:
// Point p3(0, 0);
// p3.isOrigin() → true
//
// Constraints:
// - -1000 <= x, y <= 1000

class Point
{
public:
    int x{};
    int y{};

    // TODO: Add defaulted default constructor here
    Point() = default;

    // TODO: Add parameterized constructor Point(int x, int y) here
    Point(int X, int Y)
    {
        x = X;
        y = Y;
    }

    // TODO: Implement isOrigin() method here
    // Hint: Check if both x and y are 0
    bool isOrigin()
    {
        if (x == 0 && y == 0)
            return true;
        return false;
    }
};

// Problem 2: Easy 2 - Student Record Manager
//
// Create a Student class that manages student information.
//
// Requirements:
// - The class should have: name (string), age (int), gpa (double)
// - Provide a defaulted default constructor
// - Provide a parameterized constructor Student(string n, int a, double g)
// - Implement isHonorStudent() that returns true if gpa >= 3.5
// - Implement getInfo() that returns string in format: "Name: [name], Age: [age], GPA: [gpa]"
//
// Input: Various student objects with different data
// Output: Boolean for honor status, string for info
//
// Example 1:
// Student s1;  // Default constructor
// s1.name is "", age is 0, gpa is 0.0
// s1.isHonorStudent() → false
//
// Example 2:
// Student s2("Alice", 20, 3.8);
// s2.isHonorStudent() → true
// s2.getInfo() → "Name: Alice, Age: 20, GPA: 3.8"
//
// Example 3:
// Student s3("Bob", 19, 3.4);
// s3.isHonorStudent() → false
//
// Constraints:
// - 0 <= age <= 150
// - 0.0 <= gpa <= 4.0

class Student
{
public:
    string name;
    int age;
    double gpa;

    // TODO: Add defaulted default constructor here
    Student() = default;

    // TODO: Add parameterized constructor here
    Student(string name_p, int age_p, double gpa_p)
    {
        name = name_p;
        age = age_p;
        gpa = gpa_p;
    }

    // TODO: Implement isHonorStudent() method here
    // Hint: Check if gpa >= 3.5
    bool isHonorStudent()
    {
        if (gpa >= 3.5)
            return true;
        return false;
    }
    // TODO: Implement getInfo() method here
    // Hint: Use string concatenation or a stringstream
    string getInfo()
    {
        // this command store the double the format output needed
        ostringstream gpaStream;
        gpaStream << fixed << setprecision(1) << gpa;

        string result = "Name: " + name + ", Age: " + to_string(age) + ", GPA: " + to_string(gpa);
        return "Name: " + name + ", Age: " + to_string(age) + ", GPA: " + gpaStream.str();
    };
};

// Problem 3: Medium - Bank Account System
//
// Create a BankAccount class that manages account balances and transactions.
//
// Requirements:
// - Members: accountNumber (string), balance (double), isActive (bool)
// - Defaulted default constructor
// - Parameterized constructor BankAccount(string accNum, double initialBalance)
//   that also sets isActive to true
// - deposit(double amount) - adds to balance if account is active, returns new balance or -1 if inactive
// - withdraw(double amount) - subtracts from balance if active and sufficient funds, returns new balance or -1 if failed
// - getBalance() - returns current balance
// - deactivate() - sets isActive to false
//
// Input: Various banking operations
// Output: Balance after operations or -1 for failures
//
// Example 1:
// BankAccount acc1;
// acc1.accountNumber is "", balance is 0.0, isActive is false
// acc1.deposit(100) → -1 (account not active)
//
// Example 2:
// BankAccount acc2("ACC001", 1000.0);
// acc2.deposit(500) → 1500.0
// acc2.withdraw(200) → 1300.0
//
// Example 3:
// BankAccount acc3("ACC002", 100.0);
// acc3.withdraw(150) → -1 (insufficient funds)
//
// Constraints:
// - amount >= 0 for deposit/withdraw
// - balance >= 0

class BankAccount
{
    string accountNumber;
    double balance;
    bool isActive{};

public:
    // TODO: Add defaulted default constructor here
    BankAccount() = default;
    // TODO: Add parameterized constructor here
    // Hint: Set isActive to true when account is created with details
    BankAccount(string accountNumber, double balance)
    {
        this->accountNumber = accountNumber;
        this->balance = balance;
        this->isActive = true;
    }
    // TODO: Implement deposit(double amount) method here
    // Hint: Check if account is active first
    double deposit(double amount)
    {
        if (!this->isActive)
            return -1;
        this->balance += amount;
        return this->balance;
    }

    // TODO: Implement withdraw(double amount) method here
    // Hint: Check if account is active AND has sufficient balance
    double withdraw(double amount)
    {
        if (amount > this->balance || !this->isActive)
        {
            return -1;
        }
        this->balance -= amount;
        return this->balance;
    }

    // TODO: Implement getBalance() method here
    double getBalance()
    {
        return this->balance;
    }

    // TODO: Implement deactivate() method here
    bool deactivate()
    {
        this->isActive = false;
        return this->isActive;
    }
};

// Problem 4: Hard - Game Character Stats Manager
//
// Create a GameCharacter class for an RPG game with complex stat calculations.
//
// Requirements:
// - Members: name (string), level (int), baseHealth (int), baseMana (int),
//   strength (int), intelligence (int)
// - Defaulted default constructor
// - Parameterized constructor GameCharacter(string n, int str, int intel)
//   Sets: name=n, level=1, strength=str, intelligence=intel
//   Calculates: baseHealth = 100 + (strength * 5), baseMana = 50 + (intelligence * 3)
// - getMaxHealth() returns: baseHealth + ((level - 1) * 10)
// - getMaxMana() returns: baseMana + ((level - 1) * 5)
// - levelUp() increments level and returns new max health
// - getTotalPower() returns: (strength * 2) + intelligence + level
// - canCastSpell(int manaCost) returns true if maxMana >= manaCost
//
// Input: Character creation and various stat queries
// Output: Calculated stats based on formulas
//
// Example 1:
// GameCharacter gc1;
// All members are default initialized (0 or empty string)
// gc1.getMaxHealth() → 0
// gc1.getTotalPower() → 0
//
// Example 2:
// GameCharacter gc2("Warrior", 20, 10);
// level = 1, strength = 20, intelligence = 10
// baseHealth = 100 + (20 * 5) = 200
// baseMana = 50 + (10 * 3) = 80
// gc2.getMaxHealth() → 200 + ((1-1) * 10) = 200
// gc2.getMaxMana() → 80 + ((1-1) * 5) = 80
// gc2.getTotalPower() → (20 * 2) + 10 + 1 = 51
//
// Example 3:
// GameCharacter gc3("Mage", 5, 30);
// baseHealth = 100 + (5 * 5) = 125
// baseMana = 50 + (30 * 3) = 140
// gc3.levelUp() (now level 2)
// gc3.getMaxHealth() → 125 + ((2-1) * 10) = 135
// gc3.canCastSpell(150) → false (maxMana is 145)
//
// Constraints:
// - 0 <= strength, intelligence <= 100
// - 1 <= level <= 100

class GameCharacter
{
public:
    string name;
    int level;
    int baseHealth;
    int baseMana;
    int strength;
    int intelligence;

    // TODO: Add defaulted default constructor here

    // TODO: Add parameterized constructor here
    // Hint: Calculate baseHealth = 100 + (strength * 5)
    // Hint: Calculate baseMana = 50 + (intelligence * 3)
    // Hint: Set level to 1

    // TODO: Implement getMaxHealth() method here
    // Hint: baseHealth + ((level - 1) * 10)

    // TODO: Implement getMaxMana() method here
    // Hint: baseMana + ((level - 1) * 5)

    // TODO: Implement levelUp() method here
    // Hint: Increment level, then return getMaxHealth()

    // TODO: Implement getTotalPower() method here
    // Hint: (strength * 2) + intelligence + level

    // TODO: Implement canCastSpell(int manaCost) method here
    // Hint: Compare manaCost with getMaxMana()
};

void testProblem1()
{
    cout << "\n=== Testing Problem 1: Point Initialization Checker ===" << endl;

    // Test Case 1: Default constructor creates point at origin
    // Step-by-step: Default constructor should initialize x=0, y=0
    // Expected: isOrigin() returns true
    Point p1;
    cout << "Test 1 (Default at origin): " << (p1.isOrigin() == true ? "PASS" : "FAIL") << endl;

    // Test Case 2: Point at origin explicitly
    // Step-by-step: x=0, y=0, should return true
    // Expected: true
    Point p2(0, 0);
    cout << "Test 2 (Explicit origin): " << (p2.isOrigin() == true ? "PASS" : "FAIL") << endl;

    // Test Case 3: Point not at origin (positive values)
    // Step-by-step: x=3, y=4, neither is 0, should return false
    // Expected: false
    Point p3(3, 4);
    cout << "Test 3 (Positive coords): " << (p3.isOrigin() == false ? "PASS" : "FAIL") << endl;

    // Test Case 4: Point with x=0 but y!=0
    // Step-by-step: x=0, y=5, y is not 0, should return false
    // Expected: false
    Point p4(0, 5);
    cout << "Test 4 (x=0, y!=0): " << (p4.isOrigin() == false ? "PASS" : "FAIL") << endl;

    // Test Case 5: Point with x!=0 but y=0
    // Step-by-step: x=7, y=0, x is not 0, should return false
    // Expected: false
    Point p5(7, 0);
    cout << "Test 5 (x!=0, y=0): " << (p5.isOrigin() == false ? "PASS" : "FAIL") << endl;

    // Test Case 6: Negative coordinates
    // Step-by-step: x=-3, y=-4, neither is 0, should return false
    // Expected: false
    Point p6(-3, -4);
    cout << "Test 6 (Negative coords): " << (p6.isOrigin() == false ? "PASS" : "FAIL") << endl;

    // Test Case 7: Large positive values
    // Step-by-step: x=1000, y=1000, neither is 0, should return false
    // Expected: false
    Point p7(1000, 1000);
    cout << "Test 7 (Large values): " << (p7.isOrigin() == false ? "PASS" : "FAIL") << endl;

    // Test Case 8: Large negative values
    // Step-by-step: x=-1000, y=-1000, neither is 0, should return false
    // Expected: false
    Point p8(-1000, -1000);
    cout << "Test 8 (Large negative): " << (p8.isOrigin() == false ? "PASS" : "FAIL") << endl;
}

void testProblem2()
{
    cout << "\n=== Testing Problem 2: Student Record Manager ===" << endl;

    // Test Case 1: Default student is not honor student
    // Step-by-step: Default gpa = 0.0, 0.0 < 3.5, should return false
    // Expected: false
    Student s1;
    cout << "Test 1 (Default not honor): " << (s1.isHonorStudent() == false ? "PASS" : "FAIL") << endl;

    // Test Case 2: Student with high GPA is honor student
    // Step-by-step: gpa = 3.8, 3.8 >= 3.5, should return true
    // Expected: true
    Student s2("Alice", 20, 3.8);
    cout << "Test 2 (High GPA honor): " << (s2.isHonorStudent() == true ? "PASS" : "FAIL") << endl;

    // Test Case 3: Student with low GPA is not honor student
    // Step-by-step: gpa = 3.4, 3.4 < 3.5, should return false
    // Expected: false
    Student s3("Bob", 19, 3.4);
    cout << "Test 3 (Low GPA not honor): " << (s3.isHonorStudent() == false ? "PASS" : "FAIL") << endl;

    // Test Case 4: Student exactly at threshold is honor student
    // Step-by-step: gpa = 3.5, 3.5 >= 3.5, should return true
    // Expected: true
    Student s4("Charlie", 21, 3.5);
    cout << "Test 4 (Exact threshold): " << (s4.isHonorStudent() == true ? "PASS" : "FAIL") << endl;

    // Test Case 5: Perfect GPA student
    // Step-by-step: gpa = 4.0, 4.0 >= 3.5, should return true
    // Expected: true
    Student s5("Diana", 22, 4.0);
    cout << "Test 5 (Perfect GPA): " << (s5.isHonorStudent() == true ? "PASS" : "FAIL") << endl;

    // Test Case 6: Check getInfo format for valid student
    // Step-by-step: Should return "Name: Alice, Age: 20, GPA: 3.8"
    // Expected: exact string match
    Student s6("Alice", 20, 3.8);
    cout << "Test 6 (Info format): " << (s6.getInfo() == "Name: Alice, Age: 20, GPA: 3.8" ? "PASS" : "FAIL") << endl;

    // Test Case 7: Zero GPA student
    // Step-by-step: gpa = 0.0, 0.0 < 3.5, should return false
    // Expected: false
    Student s7("Eve", 18, 0.0);
    cout << "Test 7 (Zero GPA): " << (s7.isHonorStudent() == false ? "PASS" : "FAIL") << endl;

    // Test Case 8: Student with very low GPA
    // Step-by-step: gpa = 2.0, 2.0 < 3.5, should return false
    // Expected: false
    Student s8("Frank", 23, 2.0);
    cout << "Test 8 (Low GPA 2.0): " << (s8.isHonorStudent() == false ? "PASS" : "FAIL") << endl;
}

void testProblem3()
{
    cout << "\n=== Testing Problem 3: Bank Account System ===" << endl;

    // Test Case 1: Default account cannot accept deposits
    // Step-by-step: Default account has isActive=false, deposit should return -1
    // Expected: -1
    BankAccount acc1;
    cout << "Test 1 (Default inactive): " << (acc1.deposit(100) == -1 ? "PASS" : "FAIL") << endl;

    // Test Case 2: Active account accepts deposit
    // Step-by-step: Initial balance = 1000, deposit 500, new balance = 1000 + 500 = 1500
    // Expected: 1500.0
    BankAccount acc2("ACC001", 1000.0);
    cout << "Test 2 (Deposit success): " << (acc2.deposit(500) == 1500.0 ? "PASS" : "FAIL") << endl;

    // Test Case 3: Successful withdrawal
    // Step-by-step: Balance after deposit = 1500, withdraw 200, new balance = 1500 - 200 = 1300
    // Expected: 1300.0
    cout << "Test 3 (Withdraw success): " << (acc2.withdraw(200) == 1300.0 ? "PASS" : "FAIL") << endl;

    // Test Case 4: Insufficient funds withdrawal
    // Step-by-step: Balance = 100, try to withdraw 150, 100 < 150, should return -1
    // Expected: -1
    BankAccount acc3("ACC002", 100.0);
    cout << "Test 4 (Insufficient funds): " << (acc3.withdraw(150) == -1 ? "PASS" : "FAIL") << endl;

    // Test Case 5: Exact balance withdrawal
    // Step-by-step: Balance = 100, withdraw 100, new balance = 100 - 100 = 0
    // Expected: 0.0
    BankAccount acc4("ACC003", 100.0);
    cout << "Test 5 (Exact withdrawal): " << (acc4.withdraw(100) == 0.0 ? "PASS" : "FAIL") << endl;

    // Test Case 6: Deactivated account cannot deposit
    // Step-by-step: Create account, deactivate it, try to deposit, should return -1
    // Expected: -1
    BankAccount acc5("ACC004", 500.0);
    acc5.deactivate();
    cout << "Test 6 (Deactivated deposit): " << (acc5.deposit(100) == -1 ? "PASS" : "FAIL") << endl;

    // Test Case 7: Deactivated account cannot withdraw
    // Step-by-step: Account is deactivated, try to withdraw, should return -1
    // Expected: -1
    cout << "Test 7 (Deactivated withdraw): " << (acc5.withdraw(50) == -1 ? "PASS" : "FAIL") << endl;

    // Test Case 8: Multiple operations sequence
    // Step-by-step: Start with 1000, deposit 250 (=1250), withdraw 100 (=1150), deposit 50 (=1200)
    // Expected: 1200.0
    BankAccount acc6("ACC005", 1000.0);
    acc6.deposit(250);
    acc6.withdraw(100);
    cout << "Test 8 (Multiple ops): " << (acc6.deposit(50) == 1200.0 ? "PASS" : "FAIL") << endl;
}

/* void testProblem4()
{
    cout << "\n=== Testing Problem 4: Game Character Stats Manager ===" << endl;

    // Test Case 1: Default character has zero stats
    // Step-by-step: All values default to 0, getMaxHealth() should return 0
    // Expected: 0
    GameCharacter gc1;
    cout << "Test 1 (Default max health): " << (gc1.getMaxHealth() == 0 ? "PASS" : "FAIL") << endl;

    // Test Case 2: Default character power is zero
    // Step-by-step: (0 * 2) + 0 + 0 = 0
    // Expected: 0
    cout << "Test 2 (Default power): " << (gc1.getTotalPower() == 0 ? "PASS" : "FAIL") << endl;

    // Test Case 3: Warrior initial max health calculation
    // Step-by-step: strength=20, baseHealth = 100 + (20*5) = 100 + 100 = 200
    //               level=1, maxHealth = 200 + ((1-1)*10) = 200 + 0 = 200
    // Expected: 200
    GameCharacter gc2("Warrior", 20, 10);
    cout << "Test 3 (Warrior max health): " << (gc2.getMaxHealth() == 200 ? "PASS" : "FAIL") << endl;

    // Test Case 4: Warrior initial max mana calculation
    // Step-by-step: intelligence=10, baseMana = 50 + (10*3) = 50 + 30 = 80
    //               level=1, maxMana = 80 + ((1-1)*5) = 80 + 0 = 80
    // Expected: 80
    cout << "Test 4 (Warrior max mana): " << (gc2.getMaxMana() == 80 ? "PASS" : "FAIL") << endl;

    // Test Case 5: Warrior total power calculation
    // Step-by-step: strength=20, intelligence=10, level=1
    //               power = (20*2) + 10 + 1 = 40 + 10 + 1 = 51
    // Expected: 51
    cout << "Test 5 (Warrior power): " << (gc2.getTotalPower() == 51 ? "PASS" : "FAIL") << endl;

    // Test Case 6: Mage initial calculations
    // Step-by-step: strength=5, intelligence=30
    //               baseHealth = 100 + (5*5) = 100 + 25 = 125
    //               baseMana = 50 + (30*3) = 50 + 90 = 140
    //               level=1, maxHealth = 125 + 0 = 125
    // Expected: 125
    GameCharacter gc3("Mage", 5, 30);
    cout << "Test 6 (Mage max health): " << (gc3.getMaxHealth() == 125 ? "PASS" : "FAIL") << endl;

    // Test Case 7: Level up increases max health correctly
    // Step-by-step: After levelUp(), level=2
    //               maxHealth = 125 + ((2-1)*10) = 125 + 10 = 135
    // Expected: 135
    cout << "Test 7 (Mage after levelup): " << (gc3.levelUp() == 135 ? "PASS" : "FAIL") << endl;

    // Test Case 8: Spell casting check - insufficient mana
    // Step-by-step: level=2, baseMana=140, maxMana = 140 + ((2-1)*5) = 140 + 5 = 145
    //               manaCost=150, 145 < 150, should return false
    // Expected: false
    cout << "Test 8 (Cannot cast spell): " << (gc3.canCastSpell(150) == false ? "PASS" : "FAIL") << endl;

    // Test Case 9: Spell casting check - sufficient mana
    // Step-by-step: maxMana=145, manaCost=100, 145 >= 100, should return true
    // Expected: true
    cout << "Test 9 (Can cast spell): " << (gc3.canCastSpell(100) == true ? "PASS" : "FAIL") << endl;

    // Test Case 10: Power increases with level
    // Step-by-step: strength=5, intelligence=30, level=2 (after levelup)
    //               power = (5*2) + 30 + 2 = 10 + 30 + 2 = 42
    // Expected: 42
    cout << "Test 10 (Mage power after levelup): " << (gc3.getTotalPower() == 42 ? "PASS" : "FAIL") << endl;
}
 */
int main()
{
    int choice;
    cout << "==================================================" << endl;
    cout << "   C++ Defaulted Constructors Practice Problems   " << endl;
    cout << "==================================================" << endl;
    cout << "\nChoose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy) - Point Initialization Checker" << endl;
    cout << "2. Problem 2 (Easy) - Student Record Manager" << endl;
    cout << "3. Problem 3 (Medium) - Bank Account System" << endl;
    cout << "4. Problem 4 (Hard) - Game Character Stats Manager" << endl;
    cout << "5. Test All Problems" << endl;
    cout << "\nEnter your choice: ";
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
        // testProblem4();
        break;
    case 5:
        testProblem1();
        testProblem2();
        testProblem3();
        // testProblem4();
        break;
    default:
        cout << "Invalid choice!" << endl;
    }

    return 0;
}