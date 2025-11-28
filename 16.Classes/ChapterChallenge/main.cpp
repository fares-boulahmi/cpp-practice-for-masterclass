#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <iomanip>
#include <memory>

using namespace std;

//=== SECTION A: INTEGRATION PROBLEMS ===

// Problem A1: Foundation Integration - Student Record Manager
// Create a Student class that manages basic student information with proper encapsulation.
// The class should have:
// - Private members: name (string), id (int), gpa (double)
// - A constructor that initializes all members
// - Getter methods for all members
// - Setter methods with validation (gpa must be 0.0-4.0, id must be positive)
// - A method to display student information
//
// Example 1:
// Student s1("Alice", 12345, 3.8);
// s1.display(); // Output: "Student: Alice, ID: 12345, GPA: 3.80"
//
// Example 2:
// Student s2("Bob", 54321, 4.0);
// s2.setGpa(4.5); // Should not update (invalid)
// s2.getGpa(); // Returns 4.0
//
// Input/Output format:
// - Constructor parameters: string name, int id, double gpa
// - Setters return bool (true if valid, false if invalid)
// - Display prints formatted information
//
// Constraints:
// - GPA range: 0.0 to 4.0 (inclusive)
// - ID must be positive (> 0)
// - Name cannot be empty

class Student
{
    // TODO: Solve using class structure, constructors, setters/getters, encapsulation
    // Hint: Use private members with public interface, validate in setters
    string name;
    int id;
    double gpa;

public:
    Student(string name, int id, double gpa)
    {
        this->name = name;
        this->id = id;
        this->gpa = gpa;
    }
    string getName()
    {
        return this->name;
    }
    int getId()
    {
        return this->id;
    }
    double getGpa()
    {
        return this->gpa;
    }
    bool setName(string name)
    {
        if (name.size() == 0)
            return false;
        this->name = name;
        return true;
    }
    bool setId(int id)
    {
        if (id <= 0)
            return false;
        this->id = id;
        return true;
    }
    bool setGpa(double gpa)
    {
        if (gpa < 0 || gpa > 4)
            return false;
        this->gpa = gpa;
        return true;
    }
};

// Problem A2: Intermediate Synthesis - Dynamic Inventory System
// Create an Inventory class that manages a dynamic array of items.
// The class should:
// - Use dynamic memory allocation for storing item names and quantities
// - Implement a constructor that takes initial capacity
// - Implement a destructor to prevent memory leaks
// - Have methods to add items, remove items, and display inventory
// - Track current size and capacity
// - Use the 'this' pointer in at least one method
//
// Example 1:
// Inventory inv(5);
// inv.addItem("Apple", 10);
// inv.addItem("Banana", 5);
// inv.getTotalItems(); // Returns 2
//
// Example 2:
// Inventory inv(2);
// inv.addItem("Orange", 3);
// inv.addItem("Grape", 7);
// inv.addItem("Mango", 2); // Should handle capacity limitation
//
// Input/Output format:
// - Constructor takes capacity (int)
// - addItem returns bool (true if added, false if full)
// - removeItem takes item name, returns bool
// - getTotalItems returns int
//
// Constraints:
// - Initial capacity must be positive
// - Quantity must be non-negative
// - Must properly manage dynamic memory

class Inventory
{
    // TODO: Solve using dynamic memory, constructors, destructors, this pointer
    // Hint: Use new[] for arrays, implement proper cleanup in destructor
    pair<string, int> *arr;
    int totalReserve{};
    int used{};

public:
    Inventory(unsigned int reserve)
    {
        this->arr = new pair<string, int>[reserve];
        this->totalReserve = reserve;
        this->used = 0;
    }
    bool addItem(string item, int quantity)
    {
        if (this->used >= this->totalReserve)
        {
            return false;
        }
        this->arr[used++] = {item, quantity};
        return true;
    }
    bool removeItem(string item)
    {
        if (this->used == 0)
            return false;
        int itemToDelete = -1;
        for (size_t i = 0; i < this->used - 1; i++)
        {
            if (this->arr[i].first == item)
            {
                itemToDelete = i;
                i = this->totalReserve;
            }
        }
        if (itemToDelete == -1)
            return false;
        for (size_t i = itemToDelete; i < this->used - 1; i++)
        {
            this->arr[i] = this->arr[i + 1];
        }
        used--;
        return true;
    }
    int getTotalItems()
    {
        return used;
    }
    int getQuantity(string item)
    {
        int Quantity = -1;
        for (size_t i = 0; i <= this->used - 1; i++)
        {
            if (this->arr[i].first == item)
            {
                Quantity = this->arr[i].second;
                i = this->used;
            }
        }
        return Quantity;
    }
    ~Inventory()
    {
        delete[] this->arr;
    }
};

// Problem A3: Advanced Integration - Banking System with Multiple Classes
// Create a BankAccount base functionality and Transaction record system.
// Implement:
// - BankAccount class with account number, holder name, balance
// - Transaction struct to record transaction details (type, amount, date)
// - Methods to deposit, withdraw (with validation), and get balance
// - A method that returns a dynamically allocated array of transactions
// - Proper constructor/destructor management
// - Use of arrow operator for pointer operations
//
// Example 1:
// BankAccount acc("John Doe", 1001, 1000.0);
// acc.deposit(500.0); // balance becomes 1500.0
// acc.withdraw(200.0); // balance becomes 1300.0
// acc.withdraw(2000.0); // Should fail, insufficient funds
//
// Example 2:
// BankAccount* pAcc = new BankAccount("Jane Smith", 1002, 500.0);
// pAcc->deposit(100.0); // Use arrow operator
// pAcc->getBalance(); // Returns 600.0
//
// Input/Output format:
// - Constructor: (string name, int accountNum, double initialBalance)
// - deposit returns bool (true if successful)
// - withdraw returns bool (true if successful, false if insufficient)
// - getTransactionCount returns int
//
// Constraints:
// - Initial balance must be non-negative
// - Cannot withdraw more than balance
// - Account number must be positive

struct Transaction
{
    // TODO: Define struct with transaction details
};

class BankAccount
{
    // TODO: Solve using class design, struct, dynamic memory, arrow operator
    // Hint: Store transactions dynamically, validate all operations
};

// Problem A4: Complex Synthesis - Library Management with Object Relationships
// Create a comprehensive library system with multiple interacting classes:
// - Book class: title, author, ISBN, available status
// - Member class: name, member ID, borrowed books array
// - Library class: manages books and members, tracks checkouts
// Implement:
// - Proper constructor chains and initialization
// - Defaulted constructors where appropriate
// - Methods across multiple conceptual files (simulate with comments)
// - Size calculations for objects
// - Complex interactions between objects using pointers and references
//
// Example 1:
// Library lib;
// lib.addBook("C++ Primer", "Lippman", "123456", true);
// Member m1("Alice", 2001);
// lib.checkoutBook("123456", m1); // Alice borrows the book
//
// Example 2:
// Book* pBook = new Book("Effective C++", "Meyers", "789012");
// Library lib;
// lib.addBook(*pBook); // Add using dereferenced pointer
// lib.findBookByISBN("789012")->isAvailable(); // Use arrow operator
//
// Input/Output format:
// - Various constructors for each class
// - Methods return appropriate types (bool for success, pointers for lookups)
// - Display methods for formatted output
//
// Constraints:
// - ISBN must be unique in library
// - Member can borrow maximum 5 books
// - Cannot checkout unavailable books

class Book
{
    // TODO: Solve using complete class design with proper encapsulation
};

class Member
{
    // TODO: Solve using arrays, constructors, member management
};

class Library
{
    // TODO: Solve using object relationships, pointers, references, complex logic
    // Hint: Manage collections of Books and Members, validate all operations
};

// Problem A5: Mastery Challenge - Memory-Safe Resource Manager
// Design a ResourcePool template-style class that manages a pool of reusable objects.
// This should integrate ALL major concepts from the chapter:
// - Class design with full encapsulation
// - Multiple constructors (default, parameterized, copy considerations)
// - Destructor with proper cleanup verification
// - Setters/getters with comprehensive validation
// - The 'this' pointer for method chaining
// - Arrow operator usage with pointers
// - Struct for metadata tracking
// - Size calculations and memory management
// - Order of constructor/destructor calls demonstration
//
// Create a Resource struct and ResourcePool class:
// - Resource tracks: ID, in-use status, allocation timestamp
// - ResourcePool manages: capacity, current usage, allocation/deallocation
// - Implement: acquire(), release(), status reporting
// - Demonstrate constructor/destructor call order
// - Method chaining for configuration
//
// Example 1:
// ResourcePool pool(10);
// int id1 = pool.acquire(); // Get resource ID
// pool.release(id1); // Return resource
// pool.getAvailableCount(); // Check availability
//
// Example 2:
// ResourcePool* pPool = new ResourcePool(5);
// pPool->acquire(); // Use arrow operator
// pPool->setMaxCapacity(10)->acquire(); // Method chaining
//
// Constraints:
// - Must prevent resource leaks
// - Track all allocations/deallocations
// - Demonstrate proper object lifecycle

struct Resource
{
    // TODO: Define resource metadata structure
};

class ResourcePool
{
    // TODO: Integrate ALL chapter concepts in comprehensive design
    // Hint: This is the culmination - use every technique learned
};

// Problem A6: Expert Application - Smart Configuration System with Previous Chapter Integration
// Create an advanced configuration management system that integrates Chapter 17 classes
// with previous chapters' concepts (templates, lambda functions, references, pointers).
// Implement:
// - ConfigEntry class: stores key-value pairs with type information
// - ConfigSection class: manages groups of entries with validation rules
// - ConfigManager class: handles multiple sections with file simulation
// - Use function pointers/lambdas for custom validation
// - Template-like behavior with type handling
// - Complex reference and pointer manipulation
// - Integration with strings, arrays, and memory management
//
// The system should:
// - Support different data types (int, double, string, bool)
// - Allow custom validation rules using function pointers
// - Provide safe access with bounds checking
// - Demonstrate proper memory management across complex operations
// - Show understanding of object lifetime in complex scenarios
//
// Example 1:
// ConfigManager cfg;
// cfg.addSection("Database");
// cfg.setValue("Database", "port", "3306", [](const string& val) {
//     int port = stoi(val);
//     return port > 0 && port < 65536;
// });
//
// Example 2:
// ConfigSection* sec = cfg.getSection("Database");
// sec->getValue("port"); // Safe pointer access
//
// Constraints:
// - Must handle invalid accesses safely
// - Validation rules must be enforced
// - No memory leaks despite complex operations

class ConfigEntry
{
    // TODO: Advanced class design with type handling
};

class ConfigSection
{
    // TODO: Container class managing ConfigEntry objects
};

class ConfigManager
{
    // TODO: Master integration of all concepts including previous chapters
    // Hint: This tests your complete C++ understanding - combine everything
};

//=== SECTION B: KNOWLEDGE VALIDATION QUIZ ===

void knowledgeQuiz()
{
    cout << "=== CHAPTER 17: CLASSES KNOWLEDGE QUIZ ===" << endl;
    cout << "Answer each question and check your understanding:" << endl
         << endl;

    // Question 1: Core Concept Definition
    cout << "Q1: What is the primary purpose of encapsulation in C++ classes?" << endl;
    cout << "A) To make code run faster" << endl;
    cout << "B) To hide implementation details and protect data integrity" << endl;
    cout << "C) To reduce memory usage" << endl;
    cout << "D) To enable multiple inheritance" << endl;
    cout << "Your answer: ";
    char answer1;
    cin >> answer1;
    cout << "Correct Answer: B" << endl;
    cout << "Explanation: Encapsulation bundles data and methods while hiding internal" << endl;
    cout << "implementation details. It protects data integrity by controlling access" << endl;
    cout << "through public interfaces (getters/setters) while keeping members private." << endl
         << endl;

    // Question 2: Constructor Syntax
    cout << "Q2: Which of the following is the correct syntax for a constructor?" << endl;
    cout << "A) void ClassName() { }" << endl;
    cout << "B) ClassName::ClassName() { }" << endl;
    cout << "C) ClassName() { } (inside class definition)" << endl;
    cout << "D) constructor ClassName() { }" << endl;
    cout << "Your answer: ";
    char answer2;
    cin >> answer2;
    cout << "Correct Answer: C" << endl;
    cout << "Explanation: Constructors have the same name as the class with no return type." << endl;
    cout << "Inside the class definition, you write ClassName() { }. Option B shows the" << endl;
    cout << "out-of-class definition syntax. Constructors never have a return type, not even void." << endl
         << endl;

    // Question 3: Destructor Rules
    cout << "Q3: When is a destructor automatically called?" << endl;
    cout << "A) When an object is created" << endl;
    cout << "B) When an object goes out of scope or is explicitly deleted" << endl;
    cout << "C) When a member function is called" << endl;
    cout << "D) When you call it manually" << endl;
    cout << "Your answer: ";
    char answer3;
    cin >> answer3;
    cout << "Correct Answer: B" << endl;
    cout << "Explanation: Destructors are called automatically when an object's lifetime ends:" << endl;
    cout << "- Stack objects: when they go out of scope" << endl;
    cout << "- Heap objects: when delete is called on them" << endl;
    cout << "Destructors clean up resources (close files, free memory, etc.)" << endl
         << endl;

    // Question 4: The 'this' Pointer
    cout << "Q4: What does the 'this' pointer represent in a member function?" << endl;
    cout << "A) A pointer to the class definition" << endl;
    cout << "B) A pointer to the current object instance calling the method" << endl;
    cout << "C) A pointer to the next object to be created" << endl;
    cout << "D) A pointer to the base class" << endl;
    cout << "Your answer: ";
    char answer4;
    cin >> answer4;
    cout << "Correct Answer: B" << endl;
    cout << "Explanation: 'this' is an implicit pointer available in non-static member" << endl;
    cout << "functions that points to the object for which the function was called." << endl;
    cout << "It allows you to access the current object's members explicitly and enables" << endl;
    cout << "method chaining (return *this;) and disambiguation in setters." << endl
         << endl;

    // Question 5: Struct vs Class
    cout << "Q5: What is the primary difference between struct and class in C++?" << endl;
    cout << "A) struct cannot have member functions" << endl;
    cout << "B) struct members are public by default, class members are private by default" << endl;
    cout << "C) struct uses less memory" << endl;
    cout << "D) struct cannot have constructors" << endl;
    cout << "Your answer: ";
    char answer5;
    cin >> answer5;
    cout << "Correct Answer: B" << endl;
    cout << "Explanation: In C++, struct and class are nearly identical. The ONLY" << endl;
    cout << "difference is default access: struct members are public by default," << endl;
    cout << "while class members are private by default. Both can have constructors," << endl;
    cout << "destructors, member functions, inheritance, etc." << endl
         << endl;

    // Question 6: Memory Management
    cout << "Q6: If a class has a pointer member allocated with 'new', what must you do?" << endl;
    cout << "A) Nothing, C++ handles it automatically" << endl;
    cout << "B) Implement a destructor to delete the pointer" << endl;
    cout << "C) Set the pointer to nullptr" << endl;
    cout << "D) Use free() instead of delete" << endl;
    cout << "Your answer: ";
    char answer6;
    cin >> answer6;
    cout << "Correct Answer: B" << endl;
    cout << "Explanation: When a class owns dynamically allocated memory (via new), you" << endl;
    cout << "MUST implement a destructor to properly delete that memory. Otherwise, you'll" << endl;
    cout << "have memory leaks. This is part of the Rule of Three (destructor, copy" << endl;
    cout << "constructor, copy assignment operator)." << endl
         << endl;

    // Question 7: Arrow Operator
    cout << "Q7: Given 'Person* ptr = new Person();', which syntax accesses member 'age'?" << endl;
    cout << "A) ptr.age" << endl;
    cout << "B) ptr->age" << endl;
    cout << "C) *ptr.age" << endl;
    cout << "D) ptr::age" << endl;
    cout << "Your answer: ";
    char answer7;
    cin >> answer7;
    cout << "Correct Answer: B" << endl;
    cout << "Explanation: The arrow operator (->) is used with pointers to access members." << endl;
    cout << "It's equivalent to (*ptr).age but more readable. The dot operator (.) is used" << endl;
    cout << "with actual objects or references, not pointers." << endl
         << endl;

    // Question 8: Constructor Order
    cout << "Q8: In what order are member variables initialized in a constructor?" << endl;
    cout << "A) In the order they appear in the constructor body" << endl;
    cout << "B) In the order they appear in the member initializer list" << endl;
    cout << "C) In the order they are declared in the class definition" << endl;
    cout << "D) Alphabetically by name" << endl;
    cout << "Your answer: ";
    char answer8;
    cin >> answer8;
    cout << "Correct Answer: C" << endl;
    cout << "Explanation: Members are ALWAYS initialized in the order they are declared" << endl;
    cout << "in the class definition, regardless of the order in the initializer list." << endl;
    cout << "This is important when one member depends on another being initialized first." << endl
         << endl;

    // Question 9: Defaulted Constructors
    cout << "Q9: What does 'ClassName() = default;' do?" << endl;
    cout << "A) Deletes the default constructor" << endl;
    cout << "B) Tells the compiler to generate the default constructor implementation" << endl;
    cout << "C) Makes the constructor private" << endl;
    cout << "D) Creates a constructor with default parameter values" << endl;
    cout << "Your answer: ";
    char answer9;
    cin >> answer9;
    cout << "Correct Answer: B" << endl;
    cout << "Explanation: '= default' explicitly requests the compiler to generate the" << endl;
    cout << "default implementation. This is useful when you've defined other constructors" << endl;
    cout << "(which would suppress the default constructor) but still want one." << endl
         << endl;

    // Question 10: Getter/Setter Best Practice
    cout << "Q10: Why should setters include validation logic?" << endl;
    cout << "A) To make the code longer" << endl;
    cout << "B) To ensure data integrity and maintain class invariants" << endl;
    cout << "C) Because C++ requires it" << endl;
    cout << "D) To slow down the program" << endl;
    cout << "Your answer: ";
    char answer10;
    cin >> answer10;
    cout << "Correct Answer: B" << endl;
    cout << "Explanation: Setters should validate input to maintain class invariants" << endl;
    cout << "(rules that must always be true). For example, a setAge() method might" << endl;
    cout << "reject negative values. This prevents objects from entering invalid states." << endl
         << endl;

    // Question 11: Object Size
    cout << "Q11: What does sizeof(object) include?" << endl;
    cout << "A) Size of all member variables including dynamically allocated memory" << endl;
    cout << "B) Size of member variables only (pointers count as pointer size)" << endl;
    cout << "C) Size of member variables plus all member functions" << endl;
    cout << "D) Always returns 1" << endl;
    cout << "Your answer: ";
    char answer11;
    cin >> answer11;
    cout << "Correct Answer: B" << endl;
    cout << "Explanation: sizeof() returns the size of the object's member variables." << endl;
    cout << "Pointers count as their own size (typically 8 bytes on 64-bit systems)," << endl;
    cout << "NOT the size of what they point to. Member functions don't add to object size." << endl;
    cout << "Dynamic memory is not included." << endl
         << endl;

    // Question 12: Multiple Files
    cout << "Q12: When splitting a class across files, what goes in the .h file?" << endl;
    cout << "A) Only member function implementations" << endl;
    cout << "B) Class declaration with member declarations" << endl;
    cout << "C) Only private members" << endl;
    cout << "D) The main() function" << endl;
    cout << "Your answer: ";
    char answer12;
    cin >> answer12;
    cout << "Correct Answer: B" << endl;
    cout << "Explanation: Header files (.h or .hpp) contain the class declaration:" << endl;
    cout << "member variables and function declarations. Implementation files (.cpp)" << endl;
    cout << "contain the actual function definitions. This separates interface from" << endl;
    cout << "implementation and allows reuse across multiple source files." << endl
         << endl;

    // Question 13: Common Pitfall
    cout << "Q13: What happens if you forget to delete a dynamically allocated member?" << endl;
    cout << "A) Compilation error" << endl;
    cout << "B) Memory leak - the memory is never freed" << endl;
    cout << "C) The program crashes immediately" << endl;
    cout << "D) C++ automatically frees it" << endl;
    cout << "Your answer: ";
    char answer13;
    cin >> answer13;
    cout << "Correct Answer: B" << endl;
    cout << "Explanation: Forgetting to delete dynamically allocated memory causes memory" << endl;
    cout << "leaks. The memory remains allocated but inaccessible, wasting system resources." << endl;
    cout << "Always implement destructors to clean up dynamic memory. Use tools like" << endl;
    cout << "Valgrind to detect leaks." << endl
         << endl;

    // Question 14: Constructor Chaining
    cout << "Q14: Can one constructor call another constructor in the same class?" << endl;
    cout << "A) No, this is not allowed in C++" << endl;
    cout << "B) Yes, using delegating constructors (C++11 onwards)" << endl;
    cout << "C) Yes, but only in the function body" << endl;
    cout << "D) Only in derived classes" << endl;
    cout << "Your answer: ";
    char answer14;
    cin >> answer14;
    cout << "Correct Answer: B" << endl;
    cout << "Explanation: C++11 introduced delegating constructors, allowing one constructor" << endl;
    cout << "to call another in the initializer list: ClassName() : ClassName(defaultVal) {}" << endl;
    cout << "This reduces code duplication. The delegation must happen in the initializer" << endl;
    cout << "list, not the body." << endl
         << endl;

    // Question 15: Design Consideration
    cout << "Q15: When should you make member variables private?" << endl;
    cout << "A) Never, always use public for simplicity" << endl;
    cout << "B) Always, unless you have a specific reason to expose them" << endl;
    cout << "C) Only for integer types" << endl;
    cout << "D) Only when using inheritance" << endl;
    cout << "Your answer: ";
    char answer15;
    cin >> answer15;
    cout << "Correct Answer: B" << endl;
    cout << "Explanation: Make members private by default (encapsulation principle)." << endl;
    cout << "This allows you to control access, add validation, and change internal" << endl;
    cout << "implementation without breaking external code. Expose only what's necessary" << endl;
    cout << "through public getters/setters. This is fundamental to good OOP design." << endl
         << endl;

    cout << "=== QUIZ COMPLETE ===" << endl;
    cout << "Review any questions you missed to strengthen your understanding!" << endl;
}

//=== MANDATORY COMPLETE TEST FUNCTIONS ===

void testProblemA1()
{
    cout << "Testing Problem A1 - Foundation Integration (Student Record Manager)..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Valid student creation and getters
    // Manual calculation: Create student with valid data, all getters should return initial values
    // Expected: name="Alice", id=12345, gpa=3.8
    total++;
    Student s1("Alice", 12345, 3.8);
    if (s1.getName() == "Alice" && s1.getId() == 12345 && abs(s1.getGpa() - 3.8) < 0.001)
    {
        cout << "Test 1 PASS: Valid student creation" << endl;
        passed++;
    }
    else
    {
        cout << "Test 1 FAIL: Expected Alice/12345/3.8, Got " << s1.getName() << "/"
             << s1.getId() << "/" << s1.getGpa() << endl;
    }

    // Test Case 2: Valid GPA setter with boundary value
    // Manual calculation: Set GPA to 4.0 (max valid), should succeed
    // Expected: setGpa returns true, getGpa returns 4.0
    total++;
    Student s2("Bob", 54321, 3.5);
    bool result = s2.setGpa(4.0);
    if (result && abs(s2.getGpa() - 4.0) < 0.001)
    {
        cout << "Test 2 PASS: Valid GPA update to boundary value" << endl;
        passed++;
    }
    else
    {
        cout << "Test 2 FAIL: Expected true/4.0, Got " << result << "/" << s2.getGpa() << endl;
    }

    // Test Case 3: Invalid GPA setter (too high)
    // Manual calculation: Try to set GPA to 4.5 (> 4.0 max), should fail, GPA stays 4.0
    // Expected: setGpa returns false, getGpa still returns 4.0
    total++;
    result = s2.setGpa(4.5);
    if (!result && abs(s2.getGpa() - 4.0) < 0.001)
    {
        cout << "Test 3 PASS: Invalid GPA rejected (too high)" << endl;
        passed++;
    }
    else
    {
        cout << "Test 3 FAIL: Expected false/4.0, Got " << result << "/" << s2.getGpa() << endl;
    }

    // Test Case 4: Invalid GPA setter (negative)
    // Manual calculation: Try to set GPA to -1.0, should fail, GPA stays 4.0
    // Expected: setGpa returns false, getGpa still returns 4.0
    total++;
    result = s2.setGpa(-1.0);
    if (!result && abs(s2.getGpa() - 4.0) < 0.001)
    {
        cout << "Test 4 PASS: Invalid GPA rejected (negative)" << endl;
        passed++;
    }
    else
    {
        cout << "Test 4 FAIL: Expected false/4.0, Got " << result << "/" << s2.getGpa() << endl;
    }

    // Test Case 5: Valid ID setter
    // Manual calculation: Change ID from 54321 to 99999, should succeed
    // Expected: setId returns true, getId returns 99999
    total++;
    result = s2.setId(99999);
    if (result && s2.getId() == 99999)
    {
        cout << "Test 5 PASS: Valid ID update" << endl;
        passed++;
    }
    else
    {
        cout << "Test 5 FAIL: Expected true/99999, Got " << result << "/" << s2.getId() << endl;
    }

    // Test Case 6: Invalid ID setter (non-positive)
    // Manual calculation: Try to set ID to 0, should fail, ID stays 99999
    // Expected: setId returns false, getId still returns 99999
    total++;
    result = s2.setId(0);
    if (!result && s2.getId() == 99999)
    {
        cout << "Test 6 PASS: Invalid ID rejected (zero)" << endl;
        passed++;
    }
    else
    {
        cout << "Test 6 FAIL: Expected false/99999, Got " << result << "/" << s2.getId() << endl;
    }

    // Test Case 7: Boundary GPA value (0.0)
    // Manual calculation: Set GPA to 0.0 (min valid), should succeed
    // Expected: setGpa returns true, getGpa returns 0.0
    total++;
    Student s3("Charlie", 11111, 2.5);
    result = s3.setGpa(0.0);
    if (result && abs(s3.getGpa() - 0.0) < 0.001)
    {
        cout << "Test 7 PASS: Boundary GPA (0.0) accepted" << endl;
        passed++;
    }
    else
    {
        cout << "Test 7 FAIL: Expected true/0.0, Got " << result << "/" << s3.getGpa() << endl;
    }

    // Test Case 8: Valid name setter
    // Manual calculation: Change name from "Charlie" to "Charles", should succeed
    // Expected: setName returns true, getName returns "Charles"
    total++;
    result = s3.setName("Charles");
    if (result && s3.getName() == "Charles")
    {
        cout << "Test 8 PASS: Valid name update" << endl;
        passed++;
    }
    else
    {
        cout << "Test 8 FAIL: Expected true/Charles, Got " << result << "/" << s3.getName() << endl;
    }

    cout << "Problem A1 Results: " << passed << "/" << total << " tests passed" << endl
         << endl;
}

void testProblemA2()
{
    cout << "Testing Problem A2 - Intermediate Synthesis (Dynamic Inventory System)..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Create inventory and add items
    // Manual calculation: Create capacity 5, add 2 items, total should be 2
    // Expected: addItem returns true twice, getTotalItems returns 2
    total++;
    Inventory inv1(5);
    bool add1 = inv1.addItem("Apple", 10);
    bool add2 = inv1.addItem("Banana", 5);
    int itemCount = inv1.getTotalItems();
    if (add1 && add2 && itemCount == 2)
    {
        cout << "Test 1 PASS: Items added successfully" << endl;
        passed++;
    }
    else
    {
        cout << "Test 1 FAIL: Expected true/true/2, Got " << add1 << "/" << add2 << "/" << itemCount << endl;
    }

    // Test Case 2: Add items to capacity limit
    // Manual calculation: Capacity 3, add 3 items, all should succeed
    // Expected: All three addItem calls return true, getTotalItems returns 3
    total++;
    Inventory inv2(3);
    bool a1 = inv2.addItem("Orange", 3);
    bool a2 = inv2.addItem("Grape", 7);
    bool a3 = inv2.addItem("Mango", 2);
    if (a1 && a2 && a3 && inv2.getTotalItems() == 3)
    {
        cout << "Test 2 PASS: Fill to capacity" << endl;
        passed++;
    }
    else
    {
        cout << "Test 2 FAIL: Expected all true/3, Got " << a1 << "/" << a2 << "/" << a3 << "/" << inv2.getTotalItems() << endl;
    }

    // Test Case 3: Exceed capacity
    // Manual calculation: Already at capacity 3, try to add 4th item, should fail
    // Expected: addItem returns false, getTotalItems still 3
    total++;
    bool a4 = inv2.addItem("Peach", 5);
    if (!a4 && inv2.getTotalItems() == 3)
    {
        cout << "Test 3 PASS: Capacity limit enforced" << endl;
        passed++;
    }
    else
    {
        cout << "Test 3 FAIL: Expected false/3, Got " << a4 << "/" << inv2.getTotalItems() << endl;
    }

    // Test Case 4: Remove existing item
    // Manual calculation: Have 2 items (Apple, Banana), remove Apple, should have 1
    // Expected: removeItem returns true, getTotalItems returns 1
    total++;
    bool removed = inv1.removeItem("Apple");
    if (removed && inv1.getTotalItems() == 1)
    {
        cout << "Test 4 PASS: Item removed successfully" << endl;
        passed++;
    }
    else
    {
        cout << "Test 4 FAIL: Expected true/1, Got " << removed << "/" << inv1.getTotalItems() << endl;
    }

    // Test Case 5: Remove non-existent item
    // Manual calculation: Try to remove "Peach" which was never added, should fail
    // Expected: removeItem returns false, getTotalItems stays 1
    total++;
    bool removed2 = inv1.removeItem("Peach");
    if (!removed2 && inv1.getTotalItems() == 1)
    {
        cout << "Test 5 PASS: Non-existent item removal handled" << endl;
        passed++;
    }
    else
    {
        cout << "Test 5 FAIL: Expected false/1, Got " << removed2 << "/" << inv1.getTotalItems() << endl;
    }

    // Test Case 6: Get quantity of existing item
    // Manual calculation: Banana quantity was set to 5
    // Expected: getQuantity returns 5
    total++;
    int qty = inv1.getQuantity("Banana");
    if (qty == 5)
    {
        cout << "Test 6 PASS: Correct quantity retrieved" << endl;
        passed++;
    }
    else
    {
        cout << "Test 6 FAIL: Expected 5, Got " << qty << endl;
    }

    // Test Case 7: Empty inventory operations
    // Manual calculation: Create inventory capacity 2, no items added yet
    // Expected: getTotalItems returns 0, removeItem fails
    total++;
    Inventory inv3(2);
    bool empty = (inv3.getTotalItems() == 0) && (!inv3.removeItem("Any"));
    if (empty)
    {
        cout << "Test 7 PASS: Empty inventory handled correctly" << endl;
        passed++;
    }
    else
    {
        cout << "Test 7 FAIL: Empty inventory operations incorrect" << endl;
    }

    // Test Case 8: Add item after removal creates space
    // Manual calculation: inv2 was at capacity 3, now add after removing is tested implicitly
    // For inv1: had 2 items, removed 1, now have 1, capacity 5, add should succeed
    // Expected: addItem returns true, getTotalItems becomes 2
    total++;
    bool addAfterRemove = inv1.addItem("Strawberry", 8);
    if (addAfterRemove && inv1.getTotalItems() == 2)
    {
        cout << "Test 8 PASS: Item added after removal" << endl;
        passed++;
    }
    else
    {
        cout << "Test 8 FAIL: Expected true/2, Got " << addAfterRemove << "/" << inv1.getTotalItems() << endl;
    }

    cout << "Problem A2 Results: " << passed << "/" << total << " tests passed" << endl
         << endl;
}

/* void testProblemA3()
{
    cout << "Testing Problem A3 - Advanced Integration (Banking System)..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Create account and check initial balance
    // Manual calculation: Initial balance 1000.0
    // Expected: getBalance returns 1000.0, account number 1001
    total++;
    BankAccount acc1("John Doe", 1001, 1000.0);
    if (abs(acc1.getBalance() - 1000.0) < 0.001 && acc1.getAccountNumber() == 1001)
    {
        cout << "Test 1 PASS: Account created with correct balance" << endl;
        passed++;
    }
    else
    {
        cout << "Test 1 FAIL: Expected 1000.0/1001, Got " << acc1.getBalance() << "/" << acc1.getAccountNumber() << endl;
    }

    // Test Case 2: Successful deposit
    // Manual calculation: 1000.0 + 500.0 = 1500.0
    // Expected: deposit returns true, balance becomes 1500.0
    total++;
    bool dep1 = acc1.deposit(500.0);
    if (dep1 && abs(acc1.getBalance() - 1500.0) < 0.001)
    {
        cout << "Test 2 PASS: Deposit successful" << endl;
        passed++;
    }
    else
    {
        cout << "Test 2 FAIL: Expected true/1500.0, Got " << dep1 << "/" << acc1.getBalance() << endl;
    }

    // Test Case 3: Successful withdrawal
    // Manual calculation: 1500.0 - 200.0 = 1300.0
    // Expected: withdraw returns true, balance becomes 1300.0
    total++;
    bool with1 = acc1.withdraw(200.0);
    if (with1 && abs(acc1.getBalance() - 1300.0) < 0.001)
    {
        cout << "Test 3 PASS: Withdrawal successful" << endl;
        passed++;
    }
    else
    {
        cout << "Test 3 FAIL: Expected true/1300.0, Got " << with1 << "/" << acc1.getBalance() << endl;
    }

    // Test Case 4: Failed withdrawal (insufficient funds)
    // Manual calculation: Balance 1300.0, try to withdraw 2000.0, should fail
    // Expected: withdraw returns false, balance remains 1300.0
    total++;
    bool with2 = acc1.withdraw(2000.0);
    if (!with2 && abs(acc1.getBalance() - 1300.0) < 0.001)
    {
        cout << "Test 4 PASS: Insufficient funds withdrawal rejected" << endl;
        passed++;
    }
    else
    {
        cout << "Test 4 FAIL: Expected false/1300.0, Got " << with2 << "/" << acc1.getBalance() << endl;
    }

    // Test Case 5: Pointer creation with arrow operator
    // Manual calculation: Initial balance 500.0, deposit 100.0 = 600.0
    // Expected: Arrow operator works, balance is 600.0
    total++;
    BankAccount *pAcc = new BankAccount("Jane Smith", 1002, 500.0);
    pAcc->deposit(100.0);
    if (abs(pAcc->getBalance() - 600.0) < 0.001)
    {
        cout << "Test 5 PASS: Arrow operator and pointer usage correct" << endl;
        passed++;
    }
    else
    {
        cout << "Test 5 FAIL: Expected 600.0, Got " << pAcc->getBalance() << endl;
    }
    delete pAcc;

    // Test Case 6: Transaction count tracking
    // Manual calculation: acc1 had 1 deposit + 2 withdrawals (1 success, 1 fail counts as attempt) = 3 transactions
    // Or if only successful: 1 deposit + 1 withdrawal = 2
    // Expected: getTransactionCount returns appropriate count (design dependent)
    total++;
    int txCount = acc1.getTransactionCount();
    if (txCount >= 2)
    { // At least successful transactions should be tracked
        cout << "Test 6 PASS: Transaction count tracked (count: " << txCount << ")" << endl;
        passed++;
    }
    else
    {
        cout << "Test 6 FAIL: Expected >= 2 transactions, Got " << txCount << endl;
    }

    // Test Case 7: Invalid deposit (negative amount)
    // Manual calculation: Try to deposit -100.0, should fail
    // Expected: deposit returns false, balance unchanged
    total++;
    double balBefore = acc1.getBalance();
    bool depNeg = acc1.deposit(-100.0);
    if (!depNeg && abs(acc1.getBalance() - balBefore) < 0.001)
    {
        cout << "Test 7 PASS: Negative deposit rejected" << endl;
        passed++;
    }
    else
    {
        cout << "Test 7 FAIL: Negative deposit should be rejected" << endl;
    }

    // Test Case 8: Exact balance withdrawal
    // Manual calculation: Create new account with 250.0, withdraw exactly 250.0, balance becomes 0.0
    // Expected: withdraw returns true, balance is 0.0
    total++;
    BankAccount acc2("Test User", 1003, 250.0);
    bool withExact = acc2.withdraw(250.0);
    if (withExact && abs(acc2.getBalance() - 0.0) < 0.001)
    {
        cout << "Test 8 PASS: Exact balance withdrawal successful" << endl;
        passed++;
    }
    else
    {
        cout << "Test 8 FAIL: Expected true/0.0, Got " << withExact << "/" << acc2.getBalance() << endl;
    }

    cout << "Problem A3 Results: " << passed << "/" << total << " tests passed" << endl
         << endl;
}
 */
/* void testProblemA4()
{
    cout << "Testing Problem A4 - Complex Synthesis (Library Management)..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Add book to library
    // Manual calculation: Add 1 book, library should have 1 book
    // Expected: addBook returns true, getBookCount returns 1
    total++;
    Library lib1;
    bool bookAdded = lib1.addBook("C++ Primer", "Lippman", "123456", true);
    if (bookAdded && lib1.getBookCount() == 1)
    {
        cout << "Test 1 PASS: Book added to library" << endl;
        passed++;
    }
    else
    {
        cout << "Test 1 FAIL: Expected true/1, Got " << bookAdded << "/" << lib1.getBookCount() << endl;
    }

    // Test Case 2: Add member to library
    // Manual calculation: Add 1 member, library should have 1 member
    // Expected: addMember returns true, getMemberCount returns 1
    total++;
    Member m1("Alice", 2001);
    bool memberAdded = lib1.addMember(m1);
    if (memberAdded && lib1.getMemberCount() == 1)
    {
        cout << "Test 2 PASS: Member added to library" << endl;
        passed++;
    }
    else
    {
        cout << "Test 2 FAIL: Expected true/1, Got " << memberAdded << "/" << lib1.getMemberCount() << endl;
    }

    // Test Case 3: Checkout available book
    // Manual calculation: Book "123456" is available, member can checkout
    // Expected: checkoutBook returns true, book becomes unavailable
    total++;
    bool checkedOut = lib1.checkoutBook("123456", 2001);
    Book *pBook = lib1.findBookByISBN("123456");
    if (checkedOut && pBook != nullptr && !pBook->isAvailable())
    {
        cout << "Test 3 PASS: Book checked out successfully" << endl;
        passed++;
    }
    else
    {
        cout << "Test 3 FAIL: Checkout should succeed and book should be unavailable" << endl;
    }

    // Test Case 4: Cannot checkout unavailable book
    // Manual calculation: Book "123456" already checked out, should fail
    // Expected: checkoutBook returns false
    total++;
    Member m2("Bob", 2002);
    lib1.addMember(m2);
    bool checkout2 = lib1.checkoutBook("123456", 2002);
    if (!checkout2)
    {
        cout << "Test 4 PASS: Unavailable book checkout prevented" << endl;
        passed++;
    }
    else
    {
        cout << "Test 4 FAIL: Should not checkout unavailable book" << endl;
    }

    // Test Case 5: Return book
    // Manual calculation: Return book "123456", should become available
    // Expected: returnBook returns true, book becomes available
    total++;
    bool returned = lib1.returnBook("123456", 2001);
    pBook = lib1.findBookByISBN("123456");
    if (returned && pBook != nullptr && pBook->isAvailable())
    {
        cout << "Test 5 PASS: Book returned successfully" << endl;
        passed++;
    }
    else
    {
        cout << "Test 5 FAIL: Return should succeed and book should be available" << endl;
    }

    // Test Case 6: Duplicate ISBN prevention
    // Manual calculation: Try to add book with same ISBN "123456"
    // Expected: addBook returns false
    total++;
    bool dupBook = lib1.addBook("Another Book", "Author", "123456", true);
    if (!dupBook && lib1.getBookCount() == 1)
    {
        cout << "Test 6 PASS: Duplicate ISBN prevented" << endl;
        passed++;
    }
    else
    {
        cout << "Test 6 FAIL: Duplicate ISBN should be rejected" << endl;
    }

    // Test Case 7: Member borrow limit (assume max 5 books)
    // Manual calculation: Add 6 books, try to checkout all 6 for one member
    // Expected: First 5 succeed, 6th fails
    total++;
    Library lib2;
    Member m3("Charlie", 3001);
    lib2.addMember(m3);
    int successfulCheckouts = 0;
    for (int i = 1; i <= 6; i++)
    {
        string isbn = "ISBN" + to_string(i);
        lib2.addBook("Book" + to_string(i), "Author", isbn, true);
        if (lib2.checkoutBook(isbn, 3001))
        {
            successfulCheckouts++;
        }
    }
    if (successfulCheckouts == 5)
    {
        cout << "Test 7 PASS: Borrow limit enforced (5 books max)" << endl;
        passed++;
    }
    else
    {
        cout << "Test 7 FAIL: Expected 5 checkouts, Got " << successfulCheckouts << endl;
    }

    // Test Case 8: Find book by ISBN with pointer
    // Manual calculation: Book with ISBN "ISBN1" exists
    // Expected: findBookByISBN returns non-null pointer, can use arrow operator
    total++;
    Book *foundBook = lib2.findBookByISBN("ISBN1");
    if (foundBook != nullptr && foundBook->getISBN() == "ISBN1")
    {
        cout << "Test 8 PASS: Book found by ISBN using pointer" << endl;
        passed++;
    }
    else
    {
        cout << "Test 8 FAIL: Book should be found" << endl;
    }

    cout << "Problem A4 Results: " << passed << "/" << total << " tests passed" << endl
         << endl;
}
 */
/* void testProblemA5()
{
    cout << "Testing Problem A5 - Mastery Challenge (Memory-Safe Resource Manager)..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Create pool and acquire resource
    // Manual calculation: Pool capacity 10, acquire 1 resource, available becomes 9
    // Expected: acquire returns valid ID (>= 0), getAvailableCount returns 9
    total++;
    ResourcePool pool1(10);
    int id1 = pool1.acquire();
    if (id1 >= 0 && pool1.getAvailableCount() == 9)
    {
        cout << "Test 1 PASS: Resource acquired successfully" << endl;
        passed++;
    }
    else
    {
        cout << "Test 1 FAIL: Expected valid ID and 9 available, Got " << id1 << "/" << pool1.getAvailableCount() << endl;
    }

    // Test Case 2: Release resource
    // Manual calculation: Had 9 available, release 1, becomes 10
    // Expected: release returns true, getAvailableCount returns 10
    total++;
    bool rel1 = pool1.release(id1);
    if (rel1 && pool1.getAvailableCount() == 10)
    {
        cout << "Test 2 PASS: Resource released successfully" << endl;
        passed++;
    }
    else
    {
        cout << "Test 2 FAIL: Expected true/10, Got " << rel1 << "/" << pool1.getAvailableCount() << endl;
    }

    // Test Case 3: Acquire all resources
    // Manual calculation: Pool capacity 5, acquire 5 times, available becomes 0
    // Expected: All acquires succeed, getAvailableCount returns 0
    total++;
    ResourcePool pool2(5);
    vector<int> ids;
    bool allAcquired = true;
    for (int i = 0; i < 5; i++)
    {
        int id = pool2.acquire();
        if (id < 0)
            allAcquired = false;
        ids.push_back(id);
    }
    if (allAcquired && pool2.getAvailableCount() == 0)
    {
        cout << "Test 3 PASS: All resources acquired" << endl;
        passed++;
    }
    else
    {
        cout << "Test 3 FAIL: Should acquire all 5 resources" << endl;
    }

    // Test Case 4: Acquire from empty pool
    // Manual calculation: Pool has 0 available, acquire should fail
    // Expected: acquire returns -1 (invalid ID)
    total++;
    int idFail = pool2.acquire();
    if (idFail < 0)
    {
        cout << "Test 4 PASS: Acquire from empty pool rejected" << endl;
        passed++;
    }
    else
    {
        cout << "Test 4 FAIL: Should not acquire from empty pool, Got ID " << idFail << endl;
    }

    // Test Case 5: Release invalid ID
    // Manual calculation: Try to release ID that wasn't acquired or already released
    // Expected: release returns false
    total++;
    bool relInvalid = pool2.release(9999);
    if (!relInvalid)
    {
        cout << "Test 5 PASS: Invalid release rejected" << endl;
        passed++;
    }
    else
    {
        cout << "Test 5 FAIL: Invalid release should be rejected" << endl;
    }

    // Test Case 6: Method chaining with this pointer
    // Manual calculation: Use method chaining to set capacity and acquire
    // Expected: Chain works, operations succeed
    total++;
    ResourcePool *pPool = new ResourcePool(3);
    int chainId = pPool->setMaxCapacity(5)->acquire();
    if (chainId >= 0 && pPool->getCapacity() == 5)
    {
        cout << "Test 6 PASS: Method chaining works correctly" << endl;
        passed++;
    }
    else
    {
        cout << "Test 6 FAIL: Method chaining should work" << endl;
    }
    delete pPool;

    // Test Case 7: Get usage statistics
    // Manual calculation: pool2 has 5 acquired, 0 available
    // Expected: getInUseCount returns 5
    total++;
    if (pool2.getInUseCount() == 5)
    {
        cout << "Test 7 PASS: Usage statistics correct" << endl;
        passed++;
    }
    else
    {
        cout << "Test 7 FAIL: Expected 5 in use, Got " << pool2.getInUseCount() << endl;
    }

    // Test Case 8: Release multiple and verify state
    // Manual calculation: Release 3 of 5 acquired resources, available becomes 3, in-use becomes 2
    // Expected: Counts update correctly
    total++;
    pool2.release(ids[0]);
    pool2.release(ids[1]);
    pool2.release(ids[2]);
    if (pool2.getAvailableCount() == 3 && pool2.getInUseCount() == 2)
    {
        cout << "Test 8 PASS: Multiple releases update state correctly" << endl;
        passed++;
    }
    else
    {
        cout << "Test 8 FAIL: Expected 3 available/2 in-use, Got "
             << pool2.getAvailableCount() << "/" << pool2.getInUseCount() << endl;
    }

    cout << "Problem A5 Results: " << passed << "/" << total << " tests passed" << endl
         << endl;
}
 */
/* void testProblemA6()
{
    cout << "Testing Problem A6 - Expert Application (Smart Configuration System)..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Add section and set value
    // Manual calculation: Add "Database" section, set "port" to "3306"
    // Expected: Section added, value set successfully
    total++;
    ConfigManager cfg1;
    cfg1.addSection("Database");
    bool set1 = cfg1.setValue("Database", "port", "3306");
    if (set1)
    {
        cout << "Test 1 PASS: Section added and value set" << endl;
        passed++;
    }
    else
    {
        cout << "Test 1 FAIL: Should successfully set value" << endl;
    }

    // Test Case 2: Retrieve value
    // Manual calculation: Get "port" from "Database", should return "3306"
    // Expected: getValue returns "3306"
    total++;
    string val1 = cfg1.getValue("Database", "port");
    if (val1 == "3306")
    {
        cout << "Test 2 PASS: Value retrieved correctly" << endl;
        passed++;
    }
    else
    {
        cout << "Test 2 FAIL: Expected 3306, Got " << val1 << endl;
    }

    // Test Case 3: Set value with validation (valid)
    // Manual calculation: Set port with validator that checks range 1-65535, "8080" is valid
    // Expected: setValue with validator returns true
    total++;
    auto portValidator = [](const string &val)
    {
        try
        {
            int port = stoi(val);
            return port > 0 && port < 65536;
        }
        catch (...)
        {
            return false;
        }
    };
    bool set2 = cfg1.setValue("Database", "port", "8080", portValidator);
    if (set2 && cfg1.getValue("Database", "port") == "8080")
    {
        cout << "Test 3 PASS: Valid value with validation set" << endl;
        passed++;
    }
    else
    {
        cout << "Test 3 FAIL: Valid value should be accepted" << endl;
    }

    // Test Case 4: Set value with validation (invalid)
    // Manual calculation: Try to set port to "99999" (> 65535), should fail
    // Expected: setValue returns false, value remains "8080"
    total++;
    bool set3 = cfg1.setValue("Database", "port", "99999", portValidator);
    if (!set3 && cfg1.getValue("Database", "port") == "8080")
    {
        cout << "Test 4 PASS: Invalid value rejected by validator" << endl;
        passed++;
    }
    else
    {
        cout << "Test 4 FAIL: Invalid value should be rejected" << endl;
    }

    // Test Case 5: Access non-existent section
    // Manual calculation: Try to get value from non-existent section
    // Expected: Returns empty string or handles safely
    total++;
    string valNone = cfg1.getValue("NonExistent", "key");
    if (valNone.empty() || valNone == "")
    {
        cout << "Test 5 PASS: Non-existent section handled safely" << endl;
        passed++;
    }
    else
    {
        cout << "Test 5 FAIL: Should handle non-existent section" << endl;
    }

    // Test Case 6: Get section pointer
    // Manual calculation: Get pointer to "Database" section, should be non-null
    // Expected: getSection returns valid pointer, can access with arrow operator
    total++;
    ConfigSection *sec = cfg1.getSection("Database");
    if (sec != nullptr && sec->getSectionName() == "Database")
    {
        cout << "Test 6 PASS: Section pointer retrieved and arrow operator works" << endl;
        passed++;
    }
    else
    {
        cout << "Test 6 FAIL: Should return valid section pointer" << endl;
    }

    // Test Case 7: Multiple sections and values
    // Manual calculation: Add "Server" section with multiple key-value pairs
    // Expected: All values stored and retrievable correctly
    total++;
    cfg1.addSection("Server");
    cfg1.setValue("Server", "host", "localhost");
    cfg1.setValue("Server", "timeout", "30");
    bool multi = (cfg1.getValue("Server", "host") == "localhost" &&
                  cfg1.getValue("Server", "timeout") == "30");
    if (multi)
    {
        cout << "Test 7 PASS: Multiple sections and values managed" << endl;
        passed++;
    }
    else
    {
        cout << "Test 7 FAIL: Multiple values should be stored correctly" << endl;
    }

    // Test Case 8: Delete value and verify
    // Manual calculation: Delete "timeout" from "Server" section
    // Expected: deleteValue returns true, getValue returns empty
    total++;
    bool deleted = cfg1.deleteValue("Server", "timeout");
    string afterDelete = cfg1.getValue("Server", "timeout");
    if (deleted && afterDelete.empty())
    {
        cout << "Test 8 PASS: Value deleted successfully" << endl;
        passed++;
    }
    else
    {
        cout << "Test 8 FAIL: Value should be deleted" << endl;
    }

    cout << "Problem A6 Results: " << passed << "/" << total << " tests passed" << endl
         << endl;
}
 */
void runAllTests()
{
    cout << "=== RUNNING ALL INTEGRATION PROBLEM TESTS ===" << endl
         << endl;
    testProblemA1();
    testProblemA2();
    // testProblemA3();
    // testProblemA4();
    // testProblemA5();
    // testProblemA6();
    cout << "=== ALL TESTS COMPLETE ===" << endl;
}

int main()
{
    cout << "========================================" << endl;
    cout << "   CHAPTER 17: CLASSES - COMPREHENSIVE ASSESSMENT" << endl;
    cout << "========================================" << endl
         << endl;

    cout << "This assessment tests your mastery of:" << endl;
    cout << "- Class structure and encapsulation" << endl;
    cout << "- Constructors and destructors" << endl;
    cout << "- Setters and getters with validation" << endl;
    cout << "- Dynamic memory management in classes" << endl;
    cout << "- The 'this' pointer and arrow operator" << endl;
    cout << "- Struct vs class usage" << endl;
    cout << "- Object size and memory considerations" << endl;
    cout << "- Integration with previous chapter concepts" << endl
         << endl;

    cout << "Choose your assessment mode:" << endl
         << endl;

    cout << "INTEGRATION PROBLEMS:" << endl;
    cout << "1. Problem A1 - Foundation Integration (Easy)" << endl;
    cout << "   Student Record Manager - Basic class with encapsulation" << endl
         << endl;

    cout << "2. Problem A2 - Intermediate Synthesis (Easy-Medium)" << endl;
    cout << "   Dynamic Inventory System - Constructors, destructors, dynamic memory" << endl
         << endl;

    cout << "3. Problem A3 - Advanced Integration (Medium)" << endl;
    cout << "   Banking System - Multiple classes, arrow operator, validation" << endl
         << endl;

    cout << "4. Problem A4 - Complex Synthesis (Medium-Hard)" << endl;
    cout << "   Library Management - Object relationships, pointers, complex logic" << endl
         << endl;

    cout << "5. Problem A5 - Mastery Challenge (Hard)" << endl;
    cout << "   Resource Pool Manager - ALL chapter concepts integrated" << endl
         << endl;

    cout << "6. Problem A6 - Expert Application (Very Hard)" << endl;
    cout << "   Configuration System - Classes + previous chapters integration" << endl
         << endl;

    cout << "7. Test All Integration Problems" << endl
         << endl;

    cout << "KNOWLEDGE VALIDATION:" << endl;
    cout << "8. Chapter Knowledge Quiz (15 questions)" << endl;
    cout << "   Interactive quiz covering all concepts, best practices, pitfalls" << endl
         << endl;

    cout << "COMPREHENSIVE ASSESSMENT:" << endl;
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
        // testProblemA3();
        break;
    case 4:
        // testProblemA4();
        break;
    case 5:
        // testProblemA5();
        break;
    case 6:
        // testProblemA6();
        break;
    case 7:
        runAllTests();
        break;
    case 8:
        knowledgeQuiz();
        break;
    case 9:
        runAllTests();
        cout << endl
             << "========================================" << endl;
        cout << "Now proceeding to Knowledge Quiz..." << endl;
        cout << "========================================" << endl
             << endl;
        knowledgeQuiz();
        break;
    default:
        cout << "Invalid choice! Please run the program again and select 1-9." << endl;
    }

    cout << endl
         << "========================================" << endl;
    cout << "   Assessment Complete!" << endl;
    cout << "========================================" << endl;

    return 0;
}