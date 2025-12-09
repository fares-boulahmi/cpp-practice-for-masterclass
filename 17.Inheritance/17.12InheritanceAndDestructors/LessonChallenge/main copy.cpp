#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

// ============================================================================
// Problem 1: Easy 1 - Resource Tracker
// ============================================================================
// Description:
// Create a base class 'Resource' and a derived class 'File' to track when
// objects are created and destroyed. The base class destructor should print
// "Resource destroyed" and the derived class destructor should print
// "File closed: [filename]" before the base destructor is called.
//
// Input Format:
// - A filename (string)
//
// Output Format:
// - When object is created: "File opened: [filename]"
// - When object is destroyed: "File closed: [filename]" followed by "Resource destroyed"
//
// Example:
// Input: "data.txt"
// Output (during destruction):
// File closed: data.txt
// Resource destroyed
//
// Constraints:
// - Filename length: 1-100 characters
// - Test object creation and destruction in different scopes

class Resource {
public:
    Resource() {
        cout << "Resource created" << endl;
    }
    
    ~Resource() {
        // TODO: Implement destructor
        // Hint: Print destruction message for base class
        cout << " Resource destroyed" << endl;
    }
};

class File : public Resource {
private:
    string filename;
public:
    File(const string& name) : Resource(), filename(name) {
        // TODO: Implement constructor
        // Hint: Print file opening message
        cout << "File opened: " << filename << endl;
    } 
    
    ~File() {
        // TODO: Implement destructor
        // Hint: Print file closing message (derived destructor is called first)
        cout << " File closed: " << filename << endl;
    }
    
    string getFilename() const {
        return filename;
    }
};

void problem1Solution() {
    // TODO: Create File objects in different scopes to test destructor order
    // Hint: Use curly braces {} to create local scopes
    File fl;
}

// ============================================================================
// Problem 2: Easy 2 - Shape Area Calculator with Cleanup
// ============================================================================
// Description:
// Create a base class 'Shape' with a virtual destructor and derived classes
// 'Rectangle' and 'Circle'. Each class should track how many objects exist
// using a static counter. Destructors should decrement the counter.
//
// Input Format:
// - For Rectangle: width (double), height (double)
// - For Circle: radius (double)
//
// Output Format:
// - Constructor: "Rectangle created" or "Circle created"
// - Destructor: "Rectangle destroyed" or "Circle destroyed"
// - getArea(): returns the calculated area
// - getCount(): returns current object count for that type
//
// Example:
// Rectangle(5.0, 3.0) -> area = 15.0
// Circle(2.0) -> area = 12.5664 (using pi = 3.14159)
//
// Constraints:
// - Dimensions > 0
// - Use virtual destructor in base class

class Shape {
public:
    Shape() {}
    
    virtual ~Shape() {
        // TODO: Implement virtual destructor
        // Hint: Virtual destructor ensures derived destructors are called
    }
    
    virtual double getArea() const = 0;
};

class Rectangle : public Shape {
private:
    double width;
    double height;
    static int count;
    
public:
    Rectangle(double w, double h) : Shape(), width(w), height(h) {
        // TODO: Implement constructor
        // Hint: Increment count and print creation message
    }
    
    ~Rectangle() {
        // TODO: Implement destructor
        // Hint: Decrement count and print destruction message
    }
    
    double getArea() const override {
        // TODO: Implement area calculation
        // Hint: width * height
        return 0.0;
    }
    
    static int getCount() {
        return count;
    }
};

class Circle : public Shape {
private:
    double radius;
    static int count;
    
public:
    Circle(double r) : Shape(), radius(r) {
        // TODO: Implement constructor
        // Hint: Increment count and print creation message
    }
    
    ~Circle() {
        // TODO: Implement destructor
        // Hint: Decrement count and print destruction message
    }
    
    double getArea() const override {
        // TODO: Implement area calculation
        // Hint: pi * radius * radius (use 3.14159)
        return 0.0;
    }
    
    static int getCount() {
        return count;
    }
};

int Rectangle::count = 0;
int Circle::count = 0;

void problem2Solution() {
    // TODO: Create shapes, calculate areas, and verify counts
    // Hint: Use scopes to test destructor behavior
}

// ============================================================================
// Problem 3: Medium - Bank Account Hierarchy with Transaction Log
// ============================================================================
// Description:
// Create a banking system with base class 'Account' and derived classes
// 'SavingsAccount' and 'CheckingAccount'. Each account maintains a transaction
// log (vector of strings). When an account is destroyed, it should print
// a summary of all transactions before cleanup.
//
// Input Format:
// - Account type: "savings" or "checking"
// - Initial balance (double)
// - Transactions: "deposit [amount]" or "withdraw [amount]"
//
// Output Format:
// - Each transaction: "Transaction: [type] [amount]"
// - On destruction: "Account Summary for [account_type]:"
//                   followed by all transactions
//                   then "Final balance: [balance]"
//                   then "Account closed"
//
// Example:
// SavingsAccount(1000.0)
// deposit(500.0) -> balance = 1500.0
// withdraw(200.0) -> balance = 1300.0
// On destruction:
// Account Summary for Savings:
// Transaction: deposit 500
// Transaction: withdraw 200
// Final balance: 1300
// Account closed
//
// Constraints:
// - Initial balance >= 0
// - Cannot withdraw more than current balance
// - Maximum 100 transactions per account

class Account {
protected:
    double balance;
    vector<string> transactions;
    string accountType;
    
public:
    Account(double initialBalance, const string& type) 
        : balance(initialBalance), accountType(type) {
        // TODO: Implement constructor
    }
    
    virtual ~Account() {
        // TODO: Implement destructor
        // Hint: Print account summary with all transactions and final balance
    }
    
    virtual void deposit(double amount) {
        // TODO: Implement deposit
        // Hint: Add to balance and log transaction
    }
    
    virtual void withdraw(double amount) {
        // TODO: Implement withdraw
        // Hint: Check sufficient balance, subtract, and log transaction
    }
    
    double getBalance() const {
        return balance;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;
    
public:
    SavingsAccount(double initialBalance, double rate = 0.02) 
        : Account(initialBalance, "Savings"), interestRate(rate) {
        // TODO: Implement constructor
    }
    
    ~SavingsAccount() {
        // TODO: Implement destructor
        // Hint: Print savings-specific cleanup message
    }
    
    void applyInterest() {
        // TODO: Implement interest calculation
        // Hint: balance += balance * interestRate, then log transaction
    }
};

class CheckingAccount : public Account {
private:
    double overdraftLimit;
    
public:
    CheckingAccount(double initialBalance, double limit = 100.0) 
        : Account(initialBalance, "Checking"), overdraftLimit(limit) {
        // TODO: Implement constructor
    }
    
    ~CheckingAccount() {
        // TODO: Implement destructor
        // Hint: Print checking-specific cleanup message
    }
    
    void withdraw(double amount) override {
        // TODO: Implement withdraw with overdraft protection
        // Hint: Allow withdrawal up to (balance + overdraftLimit)
    }
};

void problem3Solution() {
    // TODO: Create accounts, perform transactions, and test destruction
    // Hint: Use scopes to trigger destructors and verify output
}

// ============================================================================
// Problem 4: Hard - Game Entity System with Resource Management
// ============================================================================
// Description:
// Create a game entity hierarchy where base class 'Entity' manages a unique ID,
// derived class 'Character' manages health/inventory, and further derived classes
// 'Player' and 'Enemy' manage specific resources. Implement proper destructor
// chain that cleans up resources in correct order and tracks total entities.
//
// Requirements:
// - Entity: assigns unique ID, tracks total entity count
// - Character: manages health, inventory (vector of item names)
// - Player: manages experience points, level, active quests
// - Enemy: manages loot table, AI state
// - All destructors must print cleanup messages in correct order
// - Static method to get current entity count
//
// Input Format:
// - Entity type: "player" or "enemy"
// - Name (string)
// - Initial health (int)
// - Type-specific data (exp/loot)
//
// Output Format:
// On creation: "Entity [ID] created: [name]"
// On destruction (in order):
//   Player/Enemy specific: "Player [name] cleanup: [exp] exp, [level] level"
//   Character: "Character [name] cleanup: [items] items in inventory"
//   Entity: "Entity [ID] destroyed"
//   Then: "Total entities: [count]"
//
// Example:
// Player("Hero", 100, 0)
// - addItem("Sword")
// - gainExp(50)
// On destruction:
// Player Hero cleanup: 50 exp, 1 level
// Character Hero cleanup: 1 items in inventory
// Entity 1 destroyed
// Total entities: 0
//
// Constraints:
// - Health: 1-1000
// - Max inventory: 50 items
// - Experience: 0-10000
// - Level calculated as: (exp / 100) + 1

class Entity {
protected:
    static int nextID;
    static int totalEntities;
    int id;
    string name;
    
public:
    Entity(const string& entityName) : id(nextID++), name(entityName) {
        // TODO: Implement constructor
        // Hint: Increment totalEntities and print creation message
    }
    
    virtual ~Entity() {
        // TODO: Implement destructor
        // Hint: Decrement totalEntities, print destruction message and total count
    }
    
    int getID() const { return id; }
    string getName() const { return name; }
    static int getTotalEntities() { return totalEntities; }
};

int Entity::nextID = 1;
int Entity::totalEntities = 0;

class Character : public Entity {
protected:
    int health;
    vector<string> inventory;
    
public:
    Character(const string& name, int hp) : Entity(name), health(hp) {
        // TODO: Implement constructor
    }
    
    virtual ~Character() {
        // TODO: Implement destructor
        // Hint: Print character-specific cleanup with inventory count
    }
    
    void addItem(const string& item) {
        // TODO: Implement adding item to inventory
        // Hint: Check max capacity before adding
    }
    
    int getHealth() const { return health; }
    int getInventorySize() const { return inventory.size(); }
};

class Player : public Character {
private:
    int experience;
    int level;
    vector<string> activeQuests;
    
public:
    Player(const string& name, int hp, int exp = 0) 
        : Character(name, hp), experience(exp), level((exp / 100) + 1) {
        // TODO: Implement constructor
    }
    
    ~Player() {
        // TODO: Implement destructor
        // Hint: Print player-specific cleanup with exp and level
    }
    
    void gainExp(int exp) {
        // TODO: Implement experience gain
        // Hint: Add to experience, recalculate level = (experience / 100) + 1
    }
    
    void addQuest(const string& quest) {
        // TODO: Implement quest addition
    }
    
    int getLevel() const { return level; }
    int getExperience() const { return experience; }
};

class Enemy : public Character {
private:
    vector<string> lootTable;
    string aiState;
    
public:
    Enemy(const string& name, int hp, const string& state = "idle") 
        : Character(name, hp), aiState(state) {
        // TODO: Implement constructor
    }
    
    ~Enemy() {
        // TODO: Implement destructor
        // Hint: Print enemy-specific cleanup with loot count and AI state
    }
    
    void addLoot(const string& item) {
        // TODO: Implement loot addition
    }
    
    void setAIState(const string& state) {
        aiState = state;
    }
    
    int getLootCount() const { return lootTable.size(); }
};

void problem4Solution() {
    // TODO: Create game entities, perform operations, test destruction chain
    // Hint: Use nested scopes to test destructor order carefully
}

// ============================================================================
// TEST FUNCTIONS
// ============================================================================

void testProblem1() {
    cout << "\n=== Testing Problem 1: Resource Tracker ===" << endl;
    cout << "Expected behavior:" << endl;
    cout << "1. Each File creation prints 'Resource created' then 'File opened: [name]'" << endl;
    cout << "2. Each File destruction prints 'File closed: [name]' then 'Resource destroyed'" << endl;
    cout << "3. Destructor order: Derived -> Base" << endl;
    cout << "\nTest your implementation:" << endl;
    
    // Test Case 1: Single file in scope
    cout << "\n--- Test 1: Single file ---" << endl;
    {
        // Expected: Resource created, File opened: test.txt
        // Then on scope exit: File closed: test.txt, Resource destroyed
    }
    
    // Test Case 2: Multiple files in nested scopes
    cout << "\n--- Test 2: Nested scopes ---" << endl;
    {
        // Create first file
        {
            // Create second file (destroyed first when inner scope ends)
        }
        // First file still exists here
    }
    // All files destroyed
    
    // Test Case 3: Multiple files in same scope
    cout << "\n--- Test 3: Multiple files same scope ---" << endl;
    {
        // Create 3 files
        // Expected: All created, then destroyed in reverse order (LIFO)
    }
    
    cout << "\nCall problem1Solution() to test your implementation!" << endl;
    problem1Solution();
}

void testProblem2() {
    cout << "\n=== Testing Problem 2: Shape Area Calculator ===" << endl;
    
    // Test Case 1: Single Rectangle
    // Input: width=5.0, height=3.0
    // Calculation: 5.0 * 3.0 = 15.0
    // Expected: area = 15.0
    cout << "Test 1 - Rectangle(5.0, 3.0): Expected area = 15.0" << endl;
    
    // Test Case 2: Single Circle
    // Input: radius=2.0
    // Calculation: 3.14159 * 2.0 * 2.0 = 12.56636
    // Expected: area ≈ 12.5664
    cout << "Test 2 - Circle(2.0): Expected area ≈ 12.5664" << endl;
    
    // Test Case 3: Multiple Rectangles count
    // Create 3 rectangles
    // Expected: count = 3, then after destruction count = 0
    cout << "Test 3 - Multiple Rectangles: Expected max count = 3" << endl;
    
    // Test Case 4: Mixed shapes
    // Create 2 rectangles, 2 circles
    // Expected: Rectangle::count = 2, Circle::count = 2
    cout << "Test 4 - Mixed shapes: Expected Rectangle=2, Circle=2" << endl;
    
    // Test Case 5: Rectangle with decimals
    // Input: width=7.5, height=4.2
    // Calculation: 7.5 * 4.2 = 31.5
    // Expected: area = 31.5
    cout << "Test 5 - Rectangle(7.5, 4.2): Expected area = 31.5" << endl;
    
    // Test Case 6: Circle with radius=1
    // Input: radius=1.0
    // Calculation: 3.14159 * 1.0 * 1.0 = 3.14159
    // Expected: area ≈ 3.14159
    cout << "Test 6 - Circle(1.0): Expected area ≈ 3.14159" << endl;
    
    // Test Case 7: Large Rectangle
    // Input: width=100.0, height=50.0
    // Calculation: 100.0 * 50.0 = 5000.0
    // Expected: area = 5000.0
    cout << "Test 7 - Rectangle(100.0, 50.0): Expected area = 5000.0" << endl;
    
    // Test Case 8: Small Circle
    // Input: radius=0.5
    // Calculation: 3.14159 * 0.5 * 0.5 = 0.7853975
    // Expected: area ≈ 0.785398
    cout << "Test 8 - Circle(0.5): Expected area ≈ 0.785398" << endl;
    
    cout << "\nCall problem2Solution() to test your implementation!" << endl;
    problem2Solution();
}

void testProblem3() {
    cout << "\n=== Testing Problem 3: Bank Account Hierarchy ===" << endl;
    
    // Test Case 1: SavingsAccount with deposits and withdrawals
    // Initial: 1000.0
    // Deposit 500.0 -> balance = 1500.0
    // Withdraw 200.0 -> balance = 1300.0
    // Expected final: 1300.0, 2 transactions
    cout << "Test 1 - Savings basic ops: Expected final balance = 1300.0" << endl;
    
    // Test Case 2: SavingsAccount with interest
    // Initial: 1000.0, rate = 0.05 (5%)
    // Apply interest -> balance = 1000 + (1000 * 0.05) = 1050.0
    // Expected final: 1050.0
    cout << "Test 2 - Savings with interest: Expected balance = 1050.0" << endl;
    
    // Test Case 3: CheckingAccount normal withdrawal
    // Initial: 500.0
    // Withdraw 200.0 -> balance = 300.0
    // Expected final: 300.0
    cout << "Test 3 - Checking normal withdraw: Expected balance = 300.0" << endl;
    
    // Test Case 4: CheckingAccount with overdraft
    // Initial: 100.0, overdraft = 50.0
    // Withdraw 120.0 -> balance = -20.0 (within overdraft limit)
    // Expected final: -20.0
    cout << "Test 4 - Checking overdraft: Expected balance = -20.0" << endl;
    
    // Test Case 5: Multiple transactions
    // Initial: 2000.0
    // Deposit 1000.0 -> 3000.0
    // Withdraw 500.0 -> 2500.0
    // Deposit 250.0 -> 2750.0
    // Withdraw 100.0 -> 2650.0
    // Expected final: 2650.0, 4 transactions
    cout << "Test 5 - Multiple ops: Expected final balance = 2650.0" << endl;
    
    // Test Case 6: Zero balance account
    // Initial: 0.0
    // Deposit 100.0 -> 100.0
    // Withdraw 100.0 -> 0.0
    // Expected final: 0.0
    cout << "Test 6 - Zero balance: Expected final = 0.0" << endl;
    
    // Test Case 7: Savings with multiple interest applications
    // Initial: 1000.0, rate = 0.10 (10%)
    // Apply interest -> 1100.0
    // Apply interest -> 1210.0
    // Expected final: 1210.0
    cout << "Test 7 - Multiple interest: Expected balance = 1210.0" << endl;
    
    // Test Case 8: Checking exceeding overdraft
    // Initial: 50.0, overdraft = 100.0
    // Withdraw 200.0 -> should fail (would be -150, exceeds limit)
    // Expected final: 50.0 (unchanged)
    cout << "Test 8 - Exceed overdraft: Expected balance = 50.0 (no change)" << endl;
    
    cout << "\nCall problem3Solution() to test your implementation!" << endl;
    problem3Solution();
}

void testProblem4() {
    cout << "\n=== Testing Problem 4: Game Entity System ===" << endl;
    
    // Test Case 1: Single Player creation and destruction
    // Input: name="Hero", health=100, exp=0
    // Expected: ID=1, level=1 (0/100 + 1)
    // On destruction: proper cleanup chain
    cout << "Test 1 - Single Player: Expected ID=1, level=1" << endl;
    
    // Test Case 2: Player with experience
    // Input: name="Warrior", health=150, exp=250
    // Level calculation: (250 / 100) + 1 = 2 + 1 = 3
    // Expected: level=3
    cout << "Test 2 - Player with exp: Expected level=3 (exp=250)" << endl;
    
    // Test Case 3: Player gaining experience
    // Initial: exp=0, level=1
    // Gain 150 exp -> exp=150, level=(150/100)+1=2
    // Gain 100 exp -> exp=250, level=(250/100)+1=3
    // Expected: final level=3
    cout << "Test 3 - Gain experience: Expected final level=3" << endl;
    
    // Test Case 4: Player with inventory
    // Create player, add 3 items
    // Expected: inventory size=3 on destruction
    cout << "Test 4 - Player inventory: Expected 3 items" << endl;
    
    // Test Case 5: Enemy creation
    // Input: name="Goblin", health=50, state="idle"
    // Expected: proper entity ID, cleanup shows AI state
    cout << "Test 5 - Enemy creation: Expected proper cleanup" << endl;
    
    // Test Case 6: Enemy with loot
    // Create enemy, add 5 loot items
    // Expected: loot count=5 on destruction
    cout << "Test 6 - Enemy with loot: Expected 5 loot items" << endl;
    
    // Test Case 7: Multiple entities and total count
    // Create 2 players, 3 enemies
    // Expected: total entities=5
    // Destroy all -> total entities=0
    cout << "Test 7 - Entity count: Expected max=5, final=0" << endl;
    
    // Test Case 8: Complex scenario with nested scopes
    // Outer scope: 1 player
    // Inner scope: 2 enemies (destroyed first)
    // Expected: correct destruction order and counts
    cout << "Test 8 - Nested scopes: Expected correct destruction order" << endl;
    
    // Test Case 9: Level calculation edge cases
    // exp=0 -> level=1
    // exp=99 -> level=1
    // exp=100 -> level=2
    // exp=500 -> level=6
    cout << "Test 9 - Level calculations:" << endl;
    cout << "  exp=0 -> level=1" << endl;
    cout << "  exp=99 -> level=1" << endl;
    cout << "  exp=100 -> level=2" << endl;
    cout << "  exp=500 -> level=6" << endl;
    
    cout << "\nCall problem4Solution() to test your implementation!" << endl;
    problem4Solution();
}

// ============================================================================
// MAIN FUNCTION
// ============================================================================

int main() {
    int choice;
    cout << "==================================================" << endl;
    cout << "C++ Practice: Inheritance and Destructors" << endl;
    cout << "==================================================" << endl;
    cout << "Choose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy) - Resource Tracker" << endl;
    cout << "2. Problem 2 (Easy-Medium) - Shape Area Calculator" << endl;
    cout << "3. Problem 3 (Medium) - Bank Account Hierarchy" << endl;
    cout << "4. Problem 4 (Hard) - Game Entity System" << endl;
    cout << "5. Test All Problems" << endl;
    cout << "Enter choice: ";
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
        default: 
            cout << "Invalid choice!" << endl;
    }

    return 0;
}