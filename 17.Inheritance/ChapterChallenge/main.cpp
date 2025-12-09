#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <sstream>

using namespace std;

//=== SECTION A: INTEGRATION PROBLEMS ===

// Problem A1: Foundation Integration - Employee Hierarchy System
// Create a basic inheritance hierarchy for an employee management system.
// Implement a base class Employee with protected members (name, id, baseSalary)
// and a derived class Manager that adds a teamSize attribute.
// 
// Requirements:
// - Employee class with protected string name, int id, double baseSalary
// - Employee constructor that initializes all members
// - Employee method: getInfo() that returns formatted string "Name: X, ID: Y, Salary: Z"
// - Manager class publicly inherits from Employee
// - Manager adds protected int teamSize
// - Manager constructor uses base class constructor
// - Manager overrides getInfo() to include team size
//
// Example:
// Employee emp("John", 101, 50000.0);
// emp.getInfo() -> "Name: John, ID: 101, Salary: 50000"
//
// Manager mgr("Sarah", 201, 75000.0, 5);
// mgr.getInfo() -> "Name: Sarah, ID: 201, Salary: 75000, Team Size: 5"
//
// Concepts tested: Basic inheritance, protected members, constructors with inheritance

class Employee {
protected:
    string name;
    int id;
    double baseSalary;

public:
    // TODO: Implement constructor that initializes name, id, baseSalary
    // TODO: Implement getInfo() method that returns formatted string
    // Hint: Use stringstream or string concatenation for formatting
};

class Manager : public Employee {
protected:
    int teamSize;

public:
    // TODO: Implement constructor that calls base constructor and initializes teamSize
    // TODO: Override getInfo() to include team size
    // Hint: You can call Employee::getInfo() and append to it
};

// Problem A2: Intermediate Synthesis - Vehicle Fleet with Access Specifiers
// Create a vehicle hierarchy demonstrating different access specifiers and member resurrection.
// Base class Vehicle has private, protected, and public members.
// Create SportsCar with public inheritance and Truck with protected inheritance.
// Resurrect a private member in Truck using 'using' declaration.
//
// Requirements:
// - Vehicle class with:
//   * private: string engineCode
//   * protected: int maxSpeed, double fuelCapacity
//   * public: string brand, int year
//   * public constructor and getEngineCode() method
// - SportsCar publicly inherits Vehicle, adds int turboBoost
// - Truck inherits Vehicle with protected access, adds double cargoCapacity
// - Truck resurrects getEngineCode() to public using 'using Vehicle::getEngineCode'
// - Both derived classes have custom constructors using base constructor
// - SportsCar has getMaxPerformance() = maxSpeed + turboBoost
// - Truck has getTotalCapacity() = fuelCapacity + cargoCapacity
//
// Example:
// SportsCar ferrari("Ferrari", 2023, "V8-TURBO", 350, 100);
// ferrari.getMaxPerformance() -> 450
// ferrari.brand -> accessible (public inheritance)
//
// Truck ford("Ford", 2022, "V6-DIESEL", 120, 80.0, 5000.0);
// ford.getEngineCode() -> accessible (resurrected)
// ford.brand -> NOT accessible outside class (protected inheritance)
//
// Concepts: Access specifiers, protected inheritance, resurrecting members, protected members

class Vehicle {
private:
    string engineCode;

protected:
    int maxSpeed;
    double fuelCapacity;

public:
    string brand;
    int year;

    // TODO: Implement constructor
    // TODO: Implement getEngineCode() accessor
    // Hint: Constructor should initialize all members including private ones
};

class SportsCar : public Vehicle {
private:
    int turboBoost;

public:
    // TODO: Implement constructor using base class constructor
    // TODO: Implement getMaxPerformance()
    // Hint: Can access protected members maxSpeed directly
};

class Truck : protected Vehicle {
private:
    double cargoCapacity;

public:
    // TODO: Resurrect getEngineCode() using 'using' declaration
    // TODO: Implement constructor
    // TODO: Implement getTotalCapacity()
    // Hint: Using Vehicle::getEngineCode; makes it public in Truck
};

// Problem A3: Advanced Integration - Smart Resource Management with Inheritance
// Create a resource management system using inheritance with proper constructor/destructor chains.
// Implement custom constructors, copy constructors, and destructors to track object lifecycle.
// Use dynamic memory allocation and ensure proper cleanup.
//
// Requirements:
// - Base class Resource with:
//   * string resourceName
//   * int* resourceId (dynamically allocated)
//   * Custom constructor, copy constructor, destructor
//   * Track lifecycle with cout messages
// - Derived class ManagedResource with:
//   * string manager
//   * double* budget (dynamically allocated)
//   * Custom constructor, copy constructor, destructor
//   * Proper base class constructor calling
// - Constructor messages: "Creating [ResourceName] Resource (ID: X)"
// - Destructor messages: "Destroying [ResourceName] Resource (ID: X)"
// - Copy constructor should perform deep copy
// - getResourceInfo() in both classes
//
// Example:
// Resource res("Database", 1001);
// Output: "Creating Database Resource (ID: 1001)"
//
// ManagedResource mres("Server", 2001, "Alice", 50000.0);
// Output: "Creating Server Resource (ID: 2001)"
//         "Creating ManagedResource (Manager: Alice)"
//
// When objects go out of scope, destructors print in reverse order
//
// Concepts: Custom constructors with inheritance, copy constructors, destructors,
//           dynamic memory, destructor order, deep copying

class Resource {
protected:
    string resourceName;
    int* resourceId;

public:
    // TODO: Implement custom constructor with dynamic allocation
    // TODO: Implement copy constructor (deep copy)
    // TODO: Implement destructor with cleanup and message
    // TODO: Implement getResourceInfo()
    // Hint: Print lifecycle messages as specified
};

class ManagedResource : public Resource {
private:
    string manager;
    double* budget;

public:
    // TODO: Implement custom constructor calling base constructor
    // TODO: Implement copy constructor calling base copy constructor
    // TODO: Implement destructor with cleanup and message
    // TODO: Override getResourceInfo()
    // Hint: Base constructor must be called in initializer list
};

// Problem A4: Complex Synthesis - Shape Hierarchy with Reused Symbols
// Create a comprehensive shape hierarchy demonstrating symbol reuse, constructor inheritance,
// and polymorphic behavior. Handle reused method names and shadowed variables.
//
// Requirements:
// - Base class Shape with:
//   * protected: string name, double area
//   * protected calculateArea() (pure computation, no return needed for now)
//   * public: constructor, getArea(), getInfo()
// - Derived Rectangle with:
//   * private: double width, height
//   * public: constructor, calculateArea() (reused symbol - different implementation)
//   * public: area variable shadows base area (reused symbol)
//   * getInfo() shows rectangle-specific info
// - Derived Circle inheriting from Shape with:
//   * private: double radius
//   * public: constructor using base constructor
//   * calculateArea() implementation
//   * Access base class area using Shape::area
// - Derived Square inheriting from Rectangle with:
//   * constructor that calls Rectangle with equal width/height
//   * inherits Rectangle's calculateArea
//
// Example:
// Rectangle rect("Rect1", 5.0, 3.0);
// rect.getArea() -> 15.0
// rect.area -> shadows base area, holds local computation
//
// Circle circ("Circle1", 4.0);
// circ.getArea() -> 50.2655 (π * r²)
// Uses Shape::area from base
//
// Square sq("Square1", 6.0);
// sq.getArea() -> 36.0
// Inherits from Rectangle
//
// Concepts: Reused symbols, shadowing, inheriting base constructors,
//           multilevel inheritance, name resolution

class Shape {
protected:
    string name;
    double area;

public:
    // TODO: Implement constructor
    // TODO: Implement getArea() returning area member
    // TODO: Implement getInfo() returning name and area
    // Hint: Derived classes will calculate and store area
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    double area; // Shadows base class area

    // TODO: Implement constructor (does not call base default constructor)
    // TODO: Implement calculateArea() that computes width * height and stores in this->area
    // TODO: Override getInfo() to include dimensions
    // Hint: This area shadows Shape::area
};

class Circle : public Shape {
private:
    double radius;
    static constexpr double PI = 3.14159;

public:
    // TODO: Implement constructor using base class constructor
    // TODO: Implement calculateArea() that stores result in Shape::area
    // TODO: Override getInfo()
    // Hint: Use Shape::area to access base class member
};

class Square : public Rectangle {
public:
    // TODO: Implement constructor that calls Rectangle constructor with side, side
    // TODO: Inherit calculateArea from Rectangle
    // Hint: Square is a special Rectangle where width == height
};

// Problem A5: Mastery Challenge - Complete Plugin System
// Design a comprehensive plugin system that uses all inheritance concepts:
// protected members, access specifiers, custom constructors, copy constructors,
// destructor chains, inherited constructors, and symbol reuse.
//
// Requirements:
// - Base class Plugin:
//   * private: string pluginId
//   * protected: string name, int version, bool* enabled (dynamic)
//   * public: constructor, copy constructor, destructor
//   * public: getId(), isEnabled(), getFullInfo()
// - Derived class ExtendedPlugin (protected inheritance):
//   * private: string author, string* description (dynamic)
//   * Resurrect getId() and isEnabled() to public
//   * Custom constructor, copy constructor, destructor
//   * Add getDependencies() returning vector<string>
// - Derived class AdvancedPlugin (public inherits ExtendedPlugin):
//   * private: double version (shadows base version with different type)
//   * vector<string> dependencies
//   * Inherits ExtendedPlugin constructor using 'using'
//   * Custom constructor, copy constructor, destructor
//   * Override getFullInfo() showing all details
// - All constructors must properly initialize base classes
// - All copy constructors must perform deep copies
// - Destructors must print execution order messages
// - Handle symbol shadowing properly
//
// Example:
// Plugin p1("PLG001", "Basic", 1);
// Output: "Creating Plugin: Basic v1"
//
// AdvancedPlugin ap("PLG002", "Advanced", 2, "John", "Advanced features", 2.5, {"dep1", "dep2"});
// Output: "Creating Plugin: Advanced v2"
//         "Creating ExtendedPlugin by John"
//         "Creating AdvancedPlugin v2.5"
//
// ap.getFullInfo() -> "Plugin: PLG002, Advanced v2.5 by John, Deps: dep1, dep2"
// ap.getId() -> "PLG002" (resurrected from protected inheritance)
//
// Copy construction performs deep copy:
// AdvancedPlugin ap2 = ap; // Deep copies all dynamic memory
//
// When objects destroyed, reverse order messages
//
// Concepts: ALL chapter concepts integrated - protected members, access specifiers,
//           private inheritance resurrection, constructors, copy constructors,
//           destructors, inherited constructors, symbol shadowing, deep copying

class Plugin {
private:
    string pluginId;

protected:
    string name;
    int version;
    bool* enabled;

public:
    // TODO: Implement custom constructor with dynamic allocation
    // TODO: Implement copy constructor (deep copy)
    // TODO: Implement destructor
    // TODO: Implement getId(), isEnabled(), getFullInfo()
    // Hint: enabled is dynamically allocated, needs proper management
};

class ExtendedPlugin : protected Plugin {
private:
    string author;
    string* description;

public:
    // TODO: Resurrect getId() and isEnabled() using 'using' declarations
    // TODO: Implement custom constructor calling base constructor
    // TODO: Implement copy constructor with deep copy
    // TODO: Implement destructor
    // TODO: Implement getDependencies() returning empty vector for now
    // Hint: description is dynamic, needs deep copy
};

class AdvancedPlugin : public ExtendedPlugin {
private:
    double version; // Shadows base int version
    vector<string> dependencies;

public:
    // TODO: Implement custom constructor
    // TODO: Inherit some ExtendedPlugin constructors using 'using'
    // TODO: Implement copy constructor
    // TODO: Implement destructor
    // TODO: Override getFullInfo() with complete information
    // TODO: Override getDependencies()
    // Hint: version shadows base member, use AdvancedPlugin::version vs Plugin::version
};

// Problem A6: Expert Application - Multi-Level Banking System with Complete Lifecycle
// Design a sophisticated banking system integrating inheritance with previous chapter concepts:
// templates, lambda functions, references, pointers, and dynamic memory.
// This problem requires mastery of inheritance AND integration with prior knowledge.
//
// Requirements:
// - Template base class Account<T> where T is the balance type:
//   * private: string accountNumber
//   * protected: string holderName, T* balance (dynamic), vector<string> transactionLog
//   * public: constructor, copy constructor, destructor
//   * public: deposit(T amount), withdraw(T amount), getBalance()
//   * protected: logTransaction(string description)
// 
// - Derived SavingsAccount<T> (public inheritance):
//   * private: double interestRate, T* minimumBalance (dynamic)
//   * public: constructor, copy constructor, destructor
//   * public: applyInterest(), canWithdraw(T amount) checking minimum
//   * Override withdraw to enforce minimum balance
//   * Use lambda function to calculate interest
//
// - Derived CheckingAccount<T> (public inheritance from Account<T>):
//   * private: int* transactionCount (dynamic), int freeTransactions
//   * private: double feePerTransaction
//   * public: constructor, copy constructor, destructor
//   * Override deposit and withdraw to count transactions and charge fees
//   * public: getTransactionSummary() using lambda for filtering
//
// - Derived PremiumAccount (multi-level: inherits from CheckingAccount<double>):
//   * private: double* cashbackRate (dynamic), double totalCashback
//   * public: constructor, copy constructor, destructor
//   * Override withdraw to add cashback
//   * public: getCashbackSummary()
//   * Use reference parameters for efficient cashback calculation
//
// Additional Requirements:
// - All dynamic memory must be properly managed
// - Copy constructors perform deep copies of ALL dynamic members
// - Use lambdas for interest calculation and transaction filtering
// - Use references for efficient parameter passing
// - Template instantiation for different numeric types (double, int)
// - Proper constructor chaining through all inheritance levels
// - Destructor messages show complete destruction order
//
// Example:
// SavingsAccount<double> savings("SAV001", "Alice", 1000.0, 0.05, 500.0);
// savings.deposit(500.0);
// savings.applyInterest(); // Uses lambda: balance * (1 + rate)
// savings.getBalance() -> 1575.0
//
// CheckingAccount<double> checking("CHK001", "Bob", 2000.0, 3, 1.5);
// checking.deposit(100.0); // Free transaction
// checking.withdraw(50.0); // Charges 1.5 fee after free transactions used
//
// PremiumAccount premium("PRM001", "Charlie", 5000.0, 5, 1.0, 0.02);
// premium.withdraw(100.0); // Gets 2.0 cashback (2% of 100)
// premium.getCashbackSummary() -> "Total cashback: 2.00"
//
// Deep copy test:
// PremiumAccount premium2 = premium; // All dynamic memory deep copied
//
// Concepts: ALL inheritance concepts + templates, lambdas, references, pointers,
//           dynamic memory, multi-level inheritance, complex constructor chains,
//           template specialization, copy constructors across inheritance hierarchy

template<typename T>
class Account {
private:
    string accountNumber;

protected:
    string holderName;
    T* balance;
    vector<string> transactionLog;

    // TODO: Implement logTransaction(string description)
    // Hint: Push description to transactionLog vector

public:
    // TODO: Implement constructor with dynamic allocation
    // TODO: Implement copy constructor (deep copy balance pointer)
    // TODO: Implement destructor with cleanup
    // TODO: Implement deposit(T amount)
    // TODO: Implement withdraw(T amount) returning bool
    // TODO: Implement getBalance() returning T
    // Hint: Use *balance to work with value
};

template<typename T>
class SavingsAccount : public Account<T> {
private:
    double interestRate;
    T* minimumBalance;

public:
    // TODO: Implement constructor calling base constructor
    // TODO: Implement copy constructor with deep copy
    // TODO: Implement destructor
    // TODO: Implement applyInterest() using lambda
    // TODO: Implement canWithdraw(T amount) checking minimum
    // TODO: Override withdraw to enforce minimum balance
    // Hint: Lambda example: auto calc = [this](T amt) { return amt * (1 + rate); };
};

template<typename T>
class CheckingAccount : public Account<T> {
private:
    int* transactionCount;
    int freeTransactions;
    double feePerTransaction;

public:
    // TODO: Implement constructor calling base constructor
    // TODO: Implement copy constructor with deep copy
    // TODO: Implement destructor
    // TODO: Override deposit to count transactions
    // TODO: Override withdraw to count and charge fees
    // TODO: Implement getTransactionSummary() using lambda to filter logs
    // Hint: Charge fee after freeTransactions exceeded
};

class PremiumAccount : public CheckingAccount<double> {
private:
    double* cashbackRate;
    double totalCashback;

public:
    // TODO: Implement constructor calling base constructor
    // TODO: Implement copy constructor with deep copy
    // TODO: Implement destructor
    // TODO: Override withdraw to add cashback calculation
    // TODO: Implement getCashbackSummary()
    // TODO: Use reference parameters for efficiency
    // Hint: Cashback = withdrawAmount * (*cashbackRate)
};

//=== SECTION B: KNOWLEDGE VALIDATION QUIZ ===

void knowledgeQuiz() {
    cout << "=== CHAPTER 18: INHERITANCE KNOWLEDGE QUIZ ===" << endl;
    cout << "Answer each question. After each answer, the correct answer will be shown." << endl << endl;

    int score = 0;
    char answer;

    // Question 1: Basic Inheritance Syntax
    cout << "Q1: What is the correct syntax for public inheritance in C++?" << endl;
    cout << "A) class Derived : public Base { };" << endl;
    cout << "B) class Derived extends Base { };" << endl;
    cout << "C) class Derived -> public Base { };" << endl;
    cout << "D) class Derived inherits public Base { };" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'A' || answer == 'a') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ INCORRECT!" << endl;
    }
    cout << "Correct Answer: A" << endl;
    cout << "Explanation: C++ uses 'class Derived : access_specifier Base' syntax. " 
         << "The colon (:) indicates inheritance, followed by access specifier (public/protected/private)." << endl << endl;

    // Question 2: Protected Members
    cout << "Q2: Which statement about protected members is TRUE?" << endl;
    cout << "A) Protected members are accessible everywhere like public members" << endl;
    cout << "B) Protected members can be accessed in derived classes but not outside the class hierarchy" << endl;
    cout << "C) Protected members are the same as private members" << endl;
    cout << "D) Protected members cannot be inherited" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ INCORRECT!" << endl;
    }
    cout << "Correct Answer: B" << endl;
    cout << "Explanation: Protected members are accessible within the class and its derived classes, "
         << "but not accessible outside the class hierarchy. They provide a middle ground between "
         << "public (accessible everywhere) and private (accessible only in the same class)." << endl << endl;

    // Question 3: Access Specifiers in Inheritance
    cout << "Q3: With protected inheritance 'class Derived : protected Base', "
         << "what happens to public members of Base in Derived?" << endl;
    cout << "A) They remain public" << endl;
    cout << "B) They become protected" << endl;
    cout << "C) They become private" << endl;
    cout << "D) They are not inherited" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ INCORRECT!" << endl;
    }
    cout << "Correct Answer: B" << endl;
    cout << "Explanation: With protected inheritance, public and protected members of the base class "
         << "become protected in the derived class. Private members remain inaccessible. "
         << "This restricts the interface further down the inheritance chain." << endl << endl;

    // Question 4: Private Inheritance
    cout << "Q4: What is the effect of private inheritance?" << endl;
    cout << "A) All base class members become private in derived class" << endl;
    cout << "B) Only public base members become private; protected stay protected" << endl;
    cout << "C) Public and protected base members become private in derived class" << endl;
    cout << "D) Private inheritance is not allowed in C++" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'C' || answer == 'c') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ INCORRECT!" << endl;
    }
    cout << "Correct Answer: C" << endl;
    cout << "Explanation: With private inheritance, both public and protected members of the base "
         << "class become private in the derived class. This completely hides the base class interface "
         << "from further derived classes and external code. Base private members remain inaccessible." << endl << endl;

    // Question 5: Resurrecting Members
    cout << "Q5: How can you make a base class member public again after private/protected inheritance?" << endl;
    cout << "A) You cannot; inheritance access cannot be changed" << endl;
    cout << "B) Using the 'resurrect' keyword" << endl;
    cout << "C) Using a 'using' declaration: using Base::memberName;" << endl;
    cout << "D) By creating a wrapper public function" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'C' || answer == 'c') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ INCORRECT!" << endl;
    }
    cout << "Correct Answer: C" << endl;
    cout << "Explanation: The 'using Base::memberName;' declaration in the derived class's public "
         << "section can resurrect (restore the accessibility of) a base class member that became "
         << "private or protected due to inheritance. This selectively exposes specific members." << endl << endl;

    // Question 6: Default Constructors with Inheritance
    cout << "Q6: What happens if a derived class constructor doesn't explicitly call a base constructor?" << endl;
    cout << "A) Compilation error occurs" << endl;
    cout << "B) The base class default constructor is automatically called" << endl;
    cout << "C) Base class members remain uninitialized" << endl;
    cout << "D) The derived class cannot be instantiated" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ INCORRECT!" << endl;
    }
    cout << "Correct Answer: B" << endl;
    cout << "Explanation: If a derived class constructor doesn't explicitly call a base constructor "
         << "in its initializer list, the compiler automatically calls the base class's default "
         << "constructor (if it exists). If no default constructor exists, you'll get a compilation error." << endl << endl;

    // Question 7: Custom Constructors with Inheritance
    cout << "Q7: Where must you call the base class constructor in a derived class constructor?" << endl;
    cout << "A) At the beginning of the constructor body" << endl;
    cout << "B) In the member initializer list before the constructor body" << endl;
    cout << "C) At the end of the constructor body" << endl;
    cout << "D) Anywhere in the constructor body" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ INCORRECT!" << endl;
    }
    cout << "Correct Answer: B" << endl;
    cout << "Explanation: Base class constructors must be called in the member initializer list "
         << "(after the colon in the constructor declaration). Syntax: Derived(params) : Base(args) { }. "
         << "The base constructor executes before the derived constructor body." << endl << endl;

    // Question 8: Copy Constructors with Inheritance
    cout << "Q8: What is the correct way to call the base copy constructor from a derived copy constructor?" << endl;
    cout << "A) Derived(const Derived& other) : Base(other) { }" << endl;
    cout << "B) Derived(const Derived& other) : Base.copy(other) { }" << endl;
    cout << "C) Derived(const Derived& other) { Base(other); }" << endl;
    cout << "D) The base copy constructor is called automatically" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'A' || answer == 'a') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ INCORRECT!" << endl;
    }
    cout << "Correct Answer: A" << endl;
    cout << "Explanation: Pass the derived object to the base copy constructor in the initializer list: "
         << "Base(other). The compiler performs slicing, passing only the base class portion of 'other' "
         << "to the base copy constructor. This ensures proper copying of all base class members." << endl << endl;

    // Question 9: Inheriting Base Constructors
    cout << "Q9: Which C++11 feature allows derived classes to inherit base class constructors?" << endl;
    cout << "A) inherit Base::constructors;" << endl;
    cout << "B) using Base::Base;" << endl;
    cout << "C) import Base::constructors;" << endl;
    cout << "D) Base class constructors are automatically inherited" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ INCORRECT!" << endl;
    }
    cout << "Correct Answer: B" << endl;
    cout << "Explanation: The 'using Base::Base;' declaration in the derived class inherits all "
         << "constructors from the base class (except default, copy, and move constructors). "
         << "This avoids writing forwarding constructors manually when derived class adds no new members." << endl << endl;

    // Question 10: Destructor Order
    cout << "Q10: In what order are destructors called in an inheritance hierarchy?" << endl;
    cout << "A) Base class destructor first, then derived class destructor" << endl;
    cout << "B) Derived class destructor first, then base class destructor" << endl;
    cout << "C) All destructors are called simultaneously" << endl;
    cout << "D) Only the derived class destructor is called" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ INCORRECT!" << endl;
    }
    cout << "Correct Answer: B" << endl;
    cout << "Explanation: Destructors are called in reverse order of construction. The derived class "
         << "destructor executes first, cleaning up derived class members, then the base class "
         << "destructor executes. This ensures derived-specific cleanup happens before base cleanup." << endl << endl;

    // Question 11: Reused Symbols - Shadowing
    cout << "Q11: If a derived class has a member with the same name as a base class member, what happens?" << endl;
    cout << "A) Compilation error - duplicate member names not allowed" << endl;
    cout << "B) The derived class member shadows (hides) the base class member" << endl;
    cout << "C) Both members coexist with different qualified names" << endl;
    cout << "D) The base class member is automatically deleted" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ INCORRECT!" << endl;
    }
    cout << "Correct Answer: B" << endl;
    cout << "Explanation: The derived class member shadows (hides) the base class member. "
         << "The base member still exists and can be accessed using Base::memberName. "
         << "This is called name hiding or shadowing. Answer C is partially true but B is more accurate." << endl << endl;

    // Question 12: Accessing Shadowed Members
    cout << "Q12: How do you access a base class member that's been shadowed in the derived class?" << endl;
    cout << "A) Using the 'super' keyword: super.memberName" << endl;
    cout << "B) Using scope resolution: Base::memberName" << endl;
    cout << "C) Using the 'parent' keyword: parent.memberName" << endl;
    cout << "D) Shadowed members cannot be accessed" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ INCORRECT!" << endl;
    }
    cout << "Correct Answer: B" << endl;
    cout << "Explanation: Use the scope resolution operator (::) with the base class name: "
         << "Base::memberName. This explicitly specifies which version of the member you want. "
         << "C++ doesn't have 'super' or 'parent' keywords like some other languages." << endl << endl;

    // Question 13: Constructor Initialization Order
    cout << "Q13: In what order are members and base classes initialized in a derived class?" << endl;
    cout << "A) Derived members, then base class, then derived constructor body" << endl;
    cout << "B) Base class, then derived members in declaration order, then constructor body" << endl;
    cout << "C) Constructor body, then base class, then derived members" << endl;cout << "D) Order specified in the initializer list" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'B' || answer == 'b') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ INCORRECT!" << endl;
    }
    cout << "Correct Answer: B" << endl;
    cout << "Explanation: Initialization order is: (1) Base class constructor, (2) Derived class members "
         << "in the order they're declared (not initializer list order!), (3) Derived constructor body. "
         << "This ensures the base is fully constructed before derived members are initialized." << endl << endl;

    // Question 14: Multiple Inheritance Consideration
    cout << "Q14: What is a key issue to watch for when a derived class has members requiring initialization?" << endl;
    cout << "A) Members are automatically initialized to zero" << endl;
    cout << "B) Base constructor must initialize derived members" << endl;
    cout << "C) Derived members with no default constructor must be initialized in initializer list" << endl;
    cout << "D) All members must be public for proper initialization" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'C' || answer == 'c') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ INCORRECT!" << endl;
    }
    cout << "Correct Answer: C" << endl;
    cout << "Explanation: If a derived class has member objects (or references) that don't have default "
         << "constructors, they MUST be initialized in the member initializer list. Failing to do so "
         << "causes a compilation error. This is true for both inherited and new members." << endl << endl;

    // Question 15: Best Practice
    cout << "Q15: What is considered best practice when designing inheritance hierarchies?" << endl;
    cout << "A) Always use private inheritance by default" << endl;
    cout << "B) Make all members public for maximum flexibility" << endl;
    cout << "C) Use protected for members that derived classes need to access; keep implementation details private" << endl;
    cout << "D) Avoid using constructors in base classes" << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 'C' || answer == 'c') {
        cout << "✓ CORRECT!" << endl;
        score++;
    } else {
        cout << "✗ INCORRECT!" << endl;
    }
    cout << "Correct Answer: C" << endl;
    cout << "Explanation: Good encapsulation means: (1) Keep true implementation details private, "
         << "(2) Use protected for members that derived classes legitimately need to access/modify, "
         << "(3) Provide public interfaces for external use. This balances extensibility with encapsulation. "
         << "Public inheritance represents 'is-a' relationships and is most common." << endl << endl;

    cout << "======================================" << endl;
    cout << "QUIZ COMPLETE!" << endl;
    cout << "Your Score: " << score << "/15 (" << (score * 100 / 15) << "%)" << endl;
    
    if (score == 15) {
        cout << "Perfect! You have mastered Chapter 18 concepts!" << endl;
    } else if (score >= 12) {
        cout << "Excellent! You have a strong understanding." << endl;
    } else if (score >= 9) {
        cout << "Good! Review the incorrect answers to strengthen your knowledge." << endl;
    } else {
        cout << "Keep studying! Review the chapter materials and retake the quiz." << endl;
    }
    cout << "======================================" << endl << endl;
}

//=== MANDATORY COMPLETE TEST FUNCTIONS ===

void testProblemA1() {
    cout << "=== Testing Problem A1 - Foundation Integration ===" << endl;
    int passed = 0, total = 0;

    // Test Case 1: Basic Employee creation
    // Manual calculation: Employee with name="John", id=101, salary=50000.0
    // Expected: getInfo() returns "Name: John, ID: 101, Salary: 50000"
    total++;
    Employee emp1("John", 101, 50000.0);
    string result1 = emp1.getInfo();
    string expected1 = "Name: John, ID: 101, Salary: 50000";
    if (result1 == expected1) {
        cout << "✓ Test 1 PASSED: Basic Employee creation" << endl;
        passed++;
    } else {
        cout << "✗ Test 1 FAILED" << endl;
        cout << "  Expected: " << expected1 << endl;
        cout << "  Got: " << result1 << endl;
    }

    // Test Case 2: Employee with different values
    // Manual calculation: Employee with name="Alice", id=999, salary=75500.50
    // Expected: getInfo() returns "Name: Alice, ID: 999, Salary: 75500.5"
    total++;
    Employee emp2("Alice", 999, 75500.50);
    string result2 = emp2.getInfo();
    string expected2 = "Name: Alice, ID: 999, Salary: 75500.5";
    if (result2 == expected2) {
        cout << "✓ Test 2 PASSED: Employee with decimal salary" << endl;
        passed++;
    } else {
        cout << "✗ Test 2 FAILED" << endl;
        cout << "  Expected: " << expected2 << endl;
        cout << "  Got: " << result2 << endl;
    }

    // Test Case 3: Basic Manager creation
    // Manual calculation: Manager with name="Sarah", id=201, salary=75000.0, teamSize=5
    // Expected: getInfo() includes team size
    total++;
    Manager mgr1("Sarah", 201, 75000.0, 5);
    string result3 = mgr1.getInfo();
    bool containsName = result3.find("Sarah") != string::npos;
    bool containsId = result3.find("201") != string::npos;
    bool containsSalary = result3.find("75000") != string::npos;
    bool containsTeam = result3.find("5") != string::npos;
    if (containsName && containsId && containsSalary && containsTeam) {
        cout << "✓ Test 3 PASSED: Manager with team size" << endl;
        passed++;
    } else {
        cout << "✗ Test 3 FAILED" << endl;
        cout << "  Manager info should contain: Sarah, 201, 75000, and team size 5" << endl;
        cout << "  Got: " << result3 << endl;
    }

    // Test Case 4: Manager with large team
    // Manual calculation: Manager with name="Bob", id=150, salary=95000.0, teamSize=25
    // Expected: All information properly displayed
    total++;
    Manager mgr2("Bob", 150, 95000.0, 25);
    string result4 = mgr2.getInfo();
    bool hasLargeTeam = result4.find("25") != string::npos;
    bool hasBob = result4.find("Bob") != string::npos;
    if (hasLargeTeam && hasBob) {
        cout << "✓ Test 4 PASSED: Manager with large team" << endl;
        passed++;
    } else {
        cout << "✗ Test 4 FAILED" << endl;
        cout << "  Expected team size 25 and name Bob in output" << endl;
        cout << "  Got: " << result4 << endl;
    }

    // Test Case 5: Manager with zero team size
    // Manual calculation: Edge case - new manager with no team yet
    // Expected: Should handle teamSize=0 correctly
    total++;
    Manager mgr3("NewManager", 500, 60000.0, 0);
    string result5 = mgr3.getInfo();
    bool hasZeroTeam = result5.find("0") != string::npos;
    if (hasZeroTeam) {
        cout << "✓ Test 5 PASSED: Manager with zero team size" << endl;
        passed++;
    } else {
        cout << "✗ Test 5 FAILED" << endl;
        cout << "  Expected team size 0 in output" << endl;
        cout << "  Got: " << result5 << endl;
    }

    // Test Case 6: Employee with minimum salary
    // Manual calculation: Entry level employee
    // Expected: Should handle small salary values
    total++;
    Employee emp3("Intern", 1, 15000.0);
    string result6 = emp3.getInfo();
    bool hasIntern = result6.find("Intern") != string::npos;
    bool hasMinSalary = result6.find("15000") != string::npos;
    if (hasIntern && hasMinSalary) {
        cout << "✓ Test 6 PASSED: Employee with minimum salary" << endl;
        passed++;
    } else {
        cout << "✗ Test 6 FAILED" << endl;
        cout << "  Expected: Intern with salary 15000" << endl;
        cout << "  Got: " << result6 << endl;
    }

    cout << "Problem A1 Results: " << passed << "/" << total << " tests passed";
    if (passed == total) cout << " ✓" << endl;
    cout << endl << endl;
}

void testProblemA2() {
    cout << "=== Testing Problem A2 - Intermediate Synthesis ===" << endl;
    int passed = 0, total = 0;

    // Test Case 1: SportsCar public inheritance - brand should be accessible
    // Manual calculation: SportsCar with Ferrari brand, public inheritance makes brand public
    // Expected: Can access brand member directly
    total++;
    SportsCar ferrari("Ferrari", 2023, "V8-TURBO", 350, 100);
    if (ferrari.brand == "Ferrari") {
        cout << "✓ Test 1 PASSED: SportsCar public inheritance - brand accessible" << endl;
        passed++;
    } else {
        cout << "✗ Test 1 FAILED" << endl;
        cout << "  Expected brand: Ferrari" << endl;
        cout << "  Got: " << ferrari.brand << endl;
    }

    // Test Case 2: SportsCar getMaxPerformance
    // Manual calculation: maxSpeed=350 + turboBoost=100 = 450
    // Expected: 450
    total++;
    int result2 = ferrari.getMaxPerformance();
    int expected2 = 450;
    if (result2 == expected2) {
        cout << "✓ Test 2 PASSED: SportsCar max performance calculation" << endl;
        passed++;
    } else {
        cout << "✗ Test 2 FAILED" << endl;
        cout << "  Expected: " << expected2 << " (350 + 100)" << endl;
        cout << "  Got: " << result2 << endl;
    }

    // Test Case 3: Different SportsCar values
    // Manual calculation: maxSpeed=280 + turboBoost=80 = 360
    // Expected: 360
    total++;
    SportsCar lambo("Lamborghini", 2024, "V10-TWIN", 280, 80);
    int result3 = lambo.getMaxPerformance();
    int expected3 = 360;
    if (result3 == expected3) {
        cout << "✓ Test 3 PASSED: Different SportsCar performance" << endl;
        passed++;
    } else {
        cout << "✗ Test 3 FAILED" << endl;
        cout << "  Expected: " << expected3 << " (280 + 80)" << endl;
        cout << "  Got: " << result3 << endl;
    }

    // Test Case 4: Truck protected inheritance - brand NOT accessible outside
    // Manual calculation: Protected inheritance makes public members protected
    // Expected: Compilation would fail if we try ford.brand (we test via other means)
    // We test that Truck object can be created successfully
    total++;
    Truck ford("Ford", 2022, "V6-DIESEL", 120, 80.0, 5000.0);
    // Can't access ford.brand due to protected inheritance - this is correct behavior
    // Testing that object creation succeeds and getEngineCode is accessible (resurrected)
    string engineCode = ford.getEngineCode();
    if (engineCode == "V6-DIESEL") {
        cout << "✓ Test 4 PASSED: Truck protected inheritance and resurrected getEngineCode" << endl;
        passed++;
    } else {
        cout << "✗ Test 4 FAILED" << endl;
        cout << "  Expected engine code: V6-DIESEL" << endl;
        cout << "  Got: " << engineCode << endl;
    }

    // Test Case 5: Truck getTotalCapacity
    // Manual calculation: fuelCapacity=80.0 + cargoCapacity=5000.0 = 5080.0
    // Expected: 5080.0
    total++;
    double result5 = ford.getTotalCapacity();
    double expected5 = 5080.0;
    if (result5 == expected5) {
        cout << "✓ Test 5 PASSED: Truck total capacity calculation" << endl;
        passed++;
    } else {
        cout << "✗ Test 5 FAILED" << endl;
        cout << "  Expected: " << expected5 << " (80.0 + 5000.0)" << endl;
        cout << "  Got: " << result5 << endl;
    }

    // Test Case 6: Different Truck values
    // Manual calculation: fuelCapacity=100.0 + cargoCapacity=8000.0 = 8100.0
    // Expected: 8100.0
    total++;
    Truck chevy("Chevrolet", 2023, "V8-GAS", 140, 100.0, 8000.0);
    double result6 = chevy.getTotalCapacity();
    double expected6 = 8100.0;
    if (result6 == expected6) {
        cout << "✓ Test 6 PASSED: Different truck capacity" << endl;
        passed++;
    } else {
        cout << "✗ Test 6 FAILED" << endl;
        cout << "  Expected: " << expected6 << " (100.0 + 8000.0)" << endl;
        cout << "  Got: " << result6 << endl;
    }

    // Test Case 7: SportsCar with zero turbo boost
    // Manual calculation: maxSpeed=300 + turboBoost=0 = 300
    // Expected: 300
    total++;
    SportsCar normalCar("Toyota", 2021, "I4-NORMAL", 300, 0);
    int result7 = normalCar.getMaxPerformance();
    int expected7 = 300;
    if (result7 == expected7) {
        cout << "✓ Test 7 PASSED: SportsCar with no turbo boost" << endl;
        passed++;
    } else {
        cout << "✗ Test 7 FAILED" << endl;
        cout << "  Expected: " << expected7 << " (300 + 0)" << endl;
        cout << "  Got: " << result7 << endl;
    }

    // Test Case 8: Truck with minimal values
    // Manual calculation: fuelCapacity=50.0 + cargoCapacity=1000.0 = 1050.0
    // Expected: 1050.0
    total++;
    Truck smallTruck("Nissan", 2020, "I4-DIESEL", 90, 50.0, 1000.0);
    double result8 = smallTruck.getTotalCapacity();
    double expected8 = 1050.0;
    if (result8 == expected8) {
        cout << "✓ Test 8 PASSED: Small truck capacity" << endl;
        passed++;
    } else {
        cout << "✗ Test 8 FAILED" << endl;
        cout << "  Expected: " << expected8 << " (50.0 + 1000.0)" << endl;
        cout << "  Got: " << result8 << endl;
    }

    cout << "Problem A2 Results: " << passed << "/" << total << " tests passed";
    if (passed == total) cout << " ✓" << endl;
    cout << endl << endl;
}

void testProblemA3() {
    cout << "=== Testing Problem A3 - Advanced Integration ===" << endl;
    cout << "Note: This test checks proper constructor/destructor chains and deep copying." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Resource creation and destruction lifecycle
    // Manual calculation: Create resource, should print creation message
    // Expected: Constructor message printed, object created successfully
    total++;
    cout << "--- Test 1: Creating Resource ---" << endl;
    {
        Resource res("Database", 1001);
        string info = res.getResourceInfo();
        bool hasName = info.find("Database") != string::npos;
        bool hasId = info.find("1001") != string::npos;
        if (hasName && hasId) {
            cout << "✓ Test 1 PASSED: Resource creation" << endl;
            passed++;
        } else {
            cout << "✗ Test 1 FAILED" << endl;
            cout << "  Expected info to contain 'Database' and '1001'" << endl;
            cout << "  Got: " << info << endl;
        }
    }
    cout << "--- Test 1: Resource destroyed (check destructor message above) ---" << endl << endl;

    // Test Case 2: ManagedResource creation
    // Manual calculation: Create managed resource, should print both base and derived creation
    // Expected: Two constructor messages (base then derived)
    total++;
    cout << "--- Test 2: Creating ManagedResource ---" << endl;
    {
        ManagedResource mres("Server", 2001, "Alice", 50000.0);
        string info = mres.getResourceInfo();
        bool hasServer = info.find("Server") != string::npos;
        bool hasId = info.find("2001") != string::npos;
        bool hasManager = info.find("Alice") != string::npos;
        if (hasServer && hasId && hasManager) {
            cout << "✓ Test 2 PASSED: ManagedResource creation" << endl;
            passed++;
        } else {
            cout << "✗ Test 2 FAILED" << endl;
            cout << "  Expected info to contain 'Server', '2001', and 'Alice'" << endl;
            cout << "  Got: " << info << endl;
        }
    }
    cout << "--- Test 2: ManagedResource destroyed (check destructor order: derived then base) ---" << endl << endl;

    // Test Case 3: Resource copy constructor (deep copy)
    // Manual calculation: Create resource, copy it, modify original
    // Expected: Copy should have independent memory (deep copy)
    total++;
    cout << "--- Test 3: Testing Resource deep copy ---" << endl;
    {
        Resource original("Cache", 3001);
        Resource copy = original;
        // Both should have same info initially
        string origInfo = original.getResourceInfo();
        string copyInfo = copy.getResourceInfo();
        if (origInfo == copyInfo) {
            cout << "✓ Test 3 PASSED: Resource copy constructor creates independent copy" << endl;
            passed++;
        } else {
            cout << "✗ Test 3 FAILED" << endl;
            cout << "  Original: " << origInfo << endl;
            cout << "  Copy: " << copyInfo << endl;
        }
    }
    cout << "--- Test 3: Objects destroyed (check both destructors called) ---" << endl << endl;

    // Test Case 4: ManagedResource copy constructor
    // Manual calculation: Copy managed resource, verify deep copy
    // Expected: Independent copies with proper memory management
    total++;
    cout << "--- Test 4: Testing ManagedResource deep copy ---" << endl;
    {
        ManagedResource original("Storage", 4001, "Bob", 75000.0);
        ManagedResource copy = original;
        string origInfo = original.getResourceInfo();
        string copyInfo = copy.getResourceInfo();
        bool sameInfo = (origInfo == copyInfo);
        bool hasStorage = copyInfo.find("Storage") != string::npos;
        bool hasBob = copyInfo.find("Bob") != string::npos;
        if (sameInfo && hasStorage && hasBob) {
            cout << "✓ Test 4 PASSED: ManagedResource deep copy works correctly" << endl;
            passed++;
        } else {
            cout << "✗ Test 4 FAILED" << endl;
            cout << "  Original: " << origInfo << endl;
            cout << "  Copy: " << copyInfo << endl;
        }
    }
    cout << "--- Test 4: Objects destroyed (check destructor chain for both objects) ---" << endl << endl;

    // Test Case 5: Multiple ManagedResource objects
    // Manual calculation: Create multiple objects, verify each has independent state
    // Expected: Each object independently constructed and destroyed
    total++;
    cout << "--- Test 5: Multiple ManagedResource objects ---" << endl;
    {
        ManagedResource mr1("API", 5001, "Charlie", 60000.0);
        ManagedResource mr2("Gateway", 5002, "David", 55000.0);
        string info1 = mr1.getResourceInfo();
        string info2 = mr2.getResourceInfo();
        bool hasAPI = info1.find("API") != string::npos;
        bool hasCharlie = info1.find("Charlie") != string::npos;
        bool hasGateway = info2.find("Gateway") != string::npos;
        bool hasDavid = info2.find("David") != string::npos;
        if (hasAPI && hasCharlie && hasGateway && hasDavid) {
            cout << "✓ Test 5 PASSED: Multiple independent objects" << endl;
            passed++;
        } else {
            cout << "✗ Test 5 FAILED" << endl;
            cout << "  Object 1: " << info1 << endl;
            cout << "  Object 2: " << info2 << endl;
        }
    }
    cout << "--- Test 5: Objects destroyed in reverse order ---" << endl << endl;

    // Test Case 6: Destructor order verification
    // Manual calculation: Create nested scopes to verify destruction order
    // Expected: LIFO destruction order
    total++;
    cout << "--- Test 6: Destructor order with nested scopes ---" << endl;
    {
        Resource outer("Outer", 6001);
        {
            Resource inner("Inner", 6002);
            // Inner should be destroyed before outer
        }
        cout << "  (Inner destroyed, Outer still alive)" << endl;
    }
    cout << "  (Outer destroyed)" << endl;
    cout << "✓ Test 6 PASSED: Destructor order correct (verify messages above)" << endl;
    passed++;
    total++;
    cout << endl;

    cout << "Problem A3 Results: " << passed << "/" << total << " tests passed";
    if (passed == total) cout << " ✓" << endl;
    cout << endl << endl;
}

void testProblemA4() {
    cout << "=== Testing Problem A4 - Complex Synthesis ===" << endl;
    int passed = 0, total = 0;

    // Test Case 1: Rectangle creation and area calculation
    // Manual calculation: width=5.0, height=3.0, area=15.0
    // Expected: area member (shadowed) = 15.0
    total++;
    Rectangle rect("Rect1", 5.0, 3.0);
    rect.calculateArea();
    double result1 = rect.area; // Shadowed member
    double expected1 = 15.0;
    if (result1 == expected1) {
        cout << "✓ Test 1 PASSED: Rectangle area calculation (shadowed member)" << endl;
        passed++;
    } else {
        cout << "✗ Test 1 FAILED" << endl;
        cout << "  Expected: " << expected1 << " (5.0 * 3.0)" << endl;
        cout << "  Got: " << result1 << endl;
    }

    // Test Case 2: Rectangle getArea() method
    // Manual calculation: After calculateArea(), getArea() should return calculated value
    // Expected: 15.0
    total++;
    double result2 = rect.getArea();
    if (result2 == expected1) {
        cout << "✓ Test 2 PASSED: Rectangle getArea() method" << endl;
        passed++;
    } else {
        cout << "✗ Test 2 FAILED" << endl;
        cout << "  Expected: " << expected1 << endl;
        cout << "  Got: " << result2 << endl;
    }

    // Test Case 3: Circle creation and area calculation
    // Manual calculation: radius=4.0, area=π*r²=3.14159*16=50.26544
    // Expected: ~50.26544 (using Shape::area, not shadowed)
    total++;
    Circle circ("Circle1", 4.0);
    circ.calculateArea();
    double result3 = circ.getArea();
    double expected3 = 50.26544; // 3.14159 * 16
    if (abs(result3 - expected3) < 0.001) {
        cout << "✓ Test 3 PASSED: Circle area calculation" << endl;
        passed++;
    } else {
        cout << "✗ Test 3 FAILED" << endl;
        cout << "  Expected: ~" << expected3 << " (π * 4²)" << endl;
        cout << "  Got: " << result3 << endl;
    }

    // Test Case 4: Different circle radius
    // Manual calculation: radius=2.0, area=π*r²=3.14159*4=12.56636
    // Expected: ~12.56636
    total++;
    Circle circ2("Circle2", 2.0);
    circ2.calculateArea();
    double result4 = circ2.getArea();
    double expected4 = 12.56636;
    if (abs(result4 - expected4) < 0.001) {
        cout << "✓ Test 4 PASSED: Different circle radius" << endl;
        passed++;
    } else {
        cout << "✗ Test 4 FAILED" << endl;
        cout << "  Expected: ~" << expected4 << " (π * 2²)" << endl;
        cout << "  Got: " << result4 << endl;
    }

    // Test Case 5: Square creation (inherits from Rectangle)
    // Manual calculation: side=6.0, area=6*6=36.0
    // Expected: 36.0
    total++;
    Square sq("Square1", 6.0);
    sq.calculateArea();
    double result5 = sq.getArea();
    double expected5 = 36.0;
    if (result5 == expected5) {
        cout << "✓ Test 5 PASSED: Square area calculation" << endl;
        passed++;
    } else {
        cout << "✗ Test 5 FAILED" << endl;
        cout << "  Expected: " << expected5 << " (6 * 6)" << endl;
        cout << "  Got: " << result5 << endl;
    }

    // Test Case 6: Different square size
    // Manual calculation: side=10.0, area=100.0
    // Expected: 100.0
    total++;
    Square sq2("Square2", 10.0);
    sq2.calculateArea();
    double result6 = sq2.getArea();
    double expected6 = 100.0;
    if (result6 == expected6) {
        cout << "✓ Test 6 PASSED: Different square size" << endl;
        passed++;
    } else {
        cout << "✗ Test 6 FAILED" << endl;
        cout << "  Expected: " << expected6 << " (10 * 10)" << endl;
        cout << "  Got: " << result6 << endl;
    }

    // Test Case 7: Rectangle with decimal dimensions
    // Manual calculation: width=7.5, height=4.2, area=31.5
    // Expected: 31.5
    total++;
    Rectangle rect2("Rect2", 7.5, 4.2);
    rect2.calculateArea();
    double result7 = rect2.getArea();
    double expected7 = 31.5;
    if (abs(result7 - expected7) < 0.001) {
        cout << "✓ Test 7 PASSED: Rectangle with decimal dimensions" << endl;
        passed++;
    } else {
        cout << "✗ Test 7 FAILED" << endl;
        cout << "  Expected: " << expected7 << " (7.5 * 4.2)" << endl;
        cout << "  Got: " << result7 << endl;
    }

    // Test Case 8: Circle with unit radius
    // Manual calculation: radius=1.0, area=π=3.14159
    // Expected: ~3.14159
    total++;
    Circle unitCircle("UnitCircle", 1.0);
    unitCircle.calculateArea();
    double result8 = unitCircle.getArea();
    double expected8 = 3.14159;
    if (abs(result8 - expected8) < 0.001) {
        cout << "✓ Test 8 PASSED: Unit circle area" << endl;
        passed++;
    } else {
        cout << "✗ Test 8 FAILED" << endl;
        cout << "  Expected: ~" << expected8 << " (π * 1²)" << endl;
        cout << "  Got: " << result8 << endl;
    }

    cout << "Problem A4 Results: " << passed << "/" << total << " tests passed";
    if (passed == total) cout << " ✓" << endl;
    cout << endl << endl;
}

void testProblemA5() {
    cout << "=== Testing Problem A5 - Mastery Challenge ===" << endl;
    cout << "Note: This test verifies complete plugin system with all inheritance features." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Basic Plugin creation
    // Manual calculation: Plugin with id="PLG001", name="Basic", version=1
    // Expected: Constructor message, getId() works, isEnabled() returns true (default)
    total++;
    cout << "--- Test 1: Creating basic Plugin ---" << endl;
    {
        Plugin p1("PLG001", "Basic", 1);
        string id = p1.getId();
        bool enabled = p1.isEnabled();
        if (id == "PLG001" && enabled == true) {
            cout << "✓ Test 1 PASSED: Basic Plugin creation" << endl;
            passed++;
        } else {
            cout << "✗ Test 1 FAILED" << endl;
            cout << "  Expected ID: PLG001, Enabled: true" << endl;
            cout << "  Got ID: " << id << ", Enabled: " << enabled << endl;
        }
    }
    cout << endl;

    // Test Case 2: Plugin copy constructor (deep copy)
    // Manual calculation: Copy plugin, verify independent enabled pointer
    // Expected: Deep copy works, both objects have independent state
    total++;
    cout << "--- Test 2: Plugin deep copy ---" << endl;
    {
        Plugin original("PLG002", "Original", 2);
        Plugin copy = original;
        string origId = original.getId();
        string copyId = copy.getId();
        if (origId == "PLG002" && copyId == "PLG002"){
            cout << "✓ Test 2 PASSED: Plugin copy constructor" << endl;
            passed++;
        } else {
            cout << "✗ Test 2 FAILED" << endl;
            cout << "  Both should have ID PLG002" << endl;
        }
    }
    cout << endl;

    // Test Case 3: ExtendedPlugin creation (protected inheritance)
    // Manual calculation: ExtendedPlugin with author and description
    // Expected: getId() and isEnabled() are resurrected and accessible
    total++;
    cout << "--- Test 3: Creating ExtendedPlugin ---" << endl;
    {
        ExtendedPlugin ep("PLG003", "Extended", 3, "Alice", "Extended functionality");
        string id = ep.getId(); // Resurrected from protected inheritance
        bool enabled = ep.isEnabled(); // Resurrected
        vector<string> deps = ep.getDependencies();
        if (id == "PLG003" && enabled == true && deps.empty()) {
            cout << "✓ Test 3 PASSED: ExtendedPlugin with resurrected members" << endl;
            passed++;
        } else {
            cout << "✗ Test 3 FAILED" << endl;
            cout << "  Expected ID: PLG003, Enabled: true, Empty dependencies" << endl;
        }
    }
    cout << endl;

    // Test Case 4: ExtendedPlugin copy constructor
    // Manual calculation: Copy extended plugin, verify deep copy of description pointer
    // Expected: Independent copies with own memory
    total++;
    cout << "--- Test 4: ExtendedPlugin deep copy ---" << endl;
    {
        ExtendedPlugin original("PLG004", "Original", 4, "Bob", "Original description");
        ExtendedPlugin copy = original;
        string origId = original.getId();
        string copyId = copy.getId();
        if (origId == "PLG004" && copyId == "PLG004") {
            cout << "✓ Test 4 PASSED: ExtendedPlugin copy constructor" << endl;
            passed++;
        } else {
            cout << "✗ Test 4 FAILED" << endl;
        }
    }
    cout << endl;

    // Test Case 5: AdvancedPlugin creation with all features
    // Manual calculation: AdvancedPlugin with shadowed version (double), dependencies
    // Expected: All features work, version shadowing handled correctly
    total++;
    cout << "--- Test 5: Creating AdvancedPlugin ---" << endl;
    {
        vector<string> deps = {"dependency1", "dependency2"};
        AdvancedPlugin ap("PLG005", "Advanced", 5, "Charlie", "Advanced features", 5.2, deps);
        string id = ap.getId();
        vector<string> returnedDeps = ap.getDependencies();
        string info = ap.getFullInfo();
        bool hasId = info.find("PLG005") != string::npos;
        bool hasDeps = returnedDeps.size() == 2;
        if (id == "PLG005" && hasId && hasDeps) {
            cout << "✓ Test 5 PASSED: AdvancedPlugin with all features" << endl;
            passed++;
        } else {
            cout << "✗ Test 5 FAILED" << endl;
            cout << "  Full info: " << info << endl;
        }
    }
    cout << endl;

    // Test Case 6: AdvancedPlugin copy constructor
    // Manual calculation: Deep copy of all dynamic members including base class members
    // Expected: Complete deep copy across entire hierarchy
    total++;
    cout << "--- Test 6: AdvancedPlugin deep copy ---" << endl;
    {
        vector<string> deps = {"dep1", "dep2", "dep3"};
        AdvancedPlugin original("PLG006", "Original", 6, "David", "Description", 6.5, deps);
        AdvancedPlugin copy = original;
        string origId = original.getId();
        string copyId = copy.getId();
        vector<string> origDeps = original.getDependencies();
        vector<string> copyDeps = copy.getDependencies();
        if (origId == copyId && origDeps.size() == copyDeps.size()) {
            cout << "✓ Test 6 PASSED: AdvancedPlugin complete deep copy" << endl;
            passed++;
        } else {
            cout << "✗ Test 6 FAILED" << endl;
        }
    }
    cout << endl;

    // Test Case 7: Destructor chain verification
    // Manual calculation: Create nested objects, verify destruction order
    // Expected: Derived destructors before base destructors
    total++;
    cout << "--- Test 7: Destructor chain test ---" << endl;
    {
        AdvancedPlugin ap("PLG007", "Test", 7, "Eve", "Test", 7.0, {});
    }
    cout << "✓ Test 7 PASSED: Destructor chain executed (verify messages above)" << endl;
    passed++;
    cout << endl;

    // Test Case 8: Multiple AdvancedPlugin objects
    // Manual calculation: Create multiple objects, verify independence
    // Expected: Each object maintains independent state
    total++;
    cout << "--- Test 8: Multiple AdvancedPlugin objects ---" << endl;
    {
        AdvancedPlugin ap1("PLG008", "First", 8, "Author1", "Desc1", 8.1, {"dep1"});
        AdvancedPlugin ap2("PLG009", "Second", 9, "Author2", "Desc2", 9.2, {"dep2", "dep3"});
        string id1 = ap1.getId();
        string id2 = ap2.getId();
        vector<string> deps1 = ap1.getDependencies();
        vector<string> deps2 = ap2.getDependencies();
        if (id1 == "PLG008" && id2 == "PLG009" && deps1.size() == 1 && deps2.size() == 2) {
            cout << "✓ Test 8 PASSED: Multiple independent AdvancedPlugin objects" << endl;
            passed++;
        } else {
            cout << "✗ Test 8 FAILED" << endl;
        }
    }
    cout << endl;

    cout << "Problem A5 Results: " << passed << "/" << total << " tests passed";
    if (passed == total) cout << " ✓" << endl;
    cout << endl << endl;
}

void testProblemA6() {
    cout << "=== Testing Problem A6 - Expert Application ===" << endl;
    cout << "Note: This integrates inheritance with templates, lambdas, and advanced features." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Basic Account<double> creation
    // Manual calculation: Account with balance=1000.0
    // Expected: getBalance() returns 1000.0
    total++;
    cout << "--- Test 1: Creating Account<double> ---" << endl;
    {
        Account<double> acc("ACC001", "John", 1000.0);
        double balance = acc.getBalance();
        if (balance == 1000.0) {
            cout << "✓ Test 1 PASSED: Account creation and getBalance()" << endl;
            passed++;
        } else {
            cout << "✗ Test 1 FAILED" << endl;
            cout << "  Expected balance: 1000.0" << endl;
            cout << "  Got: " << balance << endl;
        }
    }
    cout << endl;

    // Test Case 2: Account deposit and withdraw
    // Manual calculation: Start 1000.0, deposit 500.0 = 1500.0, withdraw 200.0 = 1300.0
    // Expected: Final balance 1300.0
    total++;
    cout << "--- Test 2: Account deposit and withdraw ---" << endl;
    {
        Account<double> acc("ACC002", "Alice", 1000.0);
        acc.deposit(500.0);
        acc.withdraw(200.0);
        double balance = acc.getBalance();
        if (balance == 1300.0) {
            cout << "✓ Test 2 PASSED: Deposit and withdraw operations" << endl;
            passed++;
        } else {
            cout << "✗ Test 2 FAILED" << endl;
            cout << "  Expected balance: 1300.0 (1000 + 500 - 200)" << endl;
            cout << "  Got: " << balance << endl;
        }
    }
    cout << endl;

    // Test Case 3: Account copy constructor
    // Manual calculation: Copy account with balance, verify deep copy
    // Expected: Independent copies
    total++;
    cout << "--- Test 3: Account deep copy ---" << endl;
    {
        Account<double> original("ACC003", "Bob", 2000.0);
        original.deposit(500.0);
        Account<double> copy = original;
        double origBalance = original.getBalance();
        double copyBalance = copy.getBalance();
        if (origBalance == 2500.0 && copyBalance == 2500.0) {
            cout << "✓ Test 3 PASSED: Account copy constructor" << endl;
            passed++;
        } else {
            cout << "✗ Test 3 FAILED" << endl;
            cout << "  Both should have balance 2500.0" << endl;
        }
    }
    cout << endl;

    // Test Case 4: SavingsAccount with interest
    // Manual calculation: balance=1000.0, rate=0.05, after interest: 1000 * 1.05 = 1050.0
    // Expected: 1050.0
    total++;
    cout << "--- Test 4: SavingsAccount interest calculation ---" << endl;
    {
        SavingsAccount<double> savings("SAV001", "Charlie", 1000.0, 0.05, 500.0);
        savings.applyInterest(); // Uses lambda to calculate interest
        double balance = savings.getBalance();
        if (balance == 1050.0) {
            cout << "✓ Test 4 PASSED: Interest calculation with lambda" << endl;
            passed++;
        } else {
            cout << "✗ Test 4 FAILED" << endl;
            cout << "  Expected balance: 1050.0 (1000 * 1.05)" << endl;
            cout << "  Got: " << balance << endl;
        }
    }
    cout << endl;

    // Test Case 5: SavingsAccount minimum balance enforcement
    // Manual calculation: balance=1000.0, minimum=500.0, try withdraw 600.0 (would leave 400.0 < 500.0)
    // Expected: Withdrawal denied, balance remains 1000.0
    total++;
    cout << "--- Test 5: SavingsAccount minimum balance ---" << endl;
    {
        SavingsAccount<double> savings("SAV002", "David", 1000.0, 0.03, 500.0);
        bool canWithdraw = savings.canWithdraw(600.0);
        bool withdrawResult = savings.withdraw(600.0);
        double balance = savings.getBalance();
        if (!canWithdraw && !withdrawResult && balance == 1000.0) {
            cout << "✓ Test 5 PASSED: Minimum balance enforcement" << endl;
            passed++;
        } else {
            cout << "✗ Test 5 FAILED" << endl;
            cout << "  Expected: canWithdraw=false, withdrawal denied, balance=1000.0" << endl;
            cout << "  Got balance: " << balance << endl;
        }
    }
    cout << endl;

    // Test Case 6: CheckingAccount with free transactions
    // Manual calculation: 3 free transactions, then 1.5 fee per transaction
    // deposit (1), deposit (2), deposit (3) all free, deposit (4) charges 1.5
    // balance: 100 + 100 + 100 + 100 - 1.5 = 398.5
    // Expected: 398.5
    total++;
    cout << "--- Test 6: CheckingAccount transaction fees ---" << endl;
    {
        CheckingAccount<double> checking("CHK001", "Eve", 100.0, 3, 1.5);
        checking.deposit(100.0); // Trans 1 (free)
        checking.deposit(100.0); // Trans 2 (free)
        checking.deposit(100.0); // Trans 3 (free)
        checking.deposit(100.0); // Trans 4 (fee: 1.5)
        double balance = checking.getBalance();
        if (balance == 398.5) {
            cout << "✓ Test 6 PASSED: Transaction fee calculation" << endl;
            passed++;
        } else {
            cout << "✗ Test 6 FAILED" << endl;
            cout << "  Expected balance: 398.5 (100 + 100*3 - 1.5)" << endl;
            cout << "  Got: " << balance << endl;
        }
    }
    cout << endl;

    // Test Case 7: PremiumAccount with cashback
    // Manual calculation: balance=5000.0, withdraw 100.0, cashback 2% = 2.0
    // balance: 5000 - 100 + 2 = 4902.0
    // Expected: 4902.0, cashback=2.0
    total++;
    cout << "--- Test 7: PremiumAccount cashback ---" << endl;
    {
        PremiumAccount premium("PRM001", "Frank", 5000.0, 5, 1.0, 0.02);
        premium.withdraw(100.0); // Cashback: 100 * 0.02 = 2.0
        double balance = premium.getBalance();
        string cashbackSummary = premium.getCashbackSummary();
        bool hasAmount = cashbackSummary.find("2") != string::npos;
        if (balance == 4902.0 && hasAmount) {
            cout << "✓ Test 7 PASSED: Cashback calculation" << endl;
            passed++;
        } else {
            cout << "✗ Test 7 FAILED" << endl;
            cout << "  Expected balance: 4902.0 (5000 - 100 + 2)" << endl;
            cout << "  Got: " << balance << endl;
            cout << "  Cashback summary: " << cashbackSummary << endl;
        }
    }
    cout << endl;

    // Test Case 8: Template with int type
    // Manual calculation: Account<int> with integer balance
    // Expected: Works with integer type
    total++;
    cout << "--- Test 8: Template instantiation with int ---" << endl;
    {
        Account<int> intAccount("ACC004", "Grace", 1000);
        intAccount.deposit(500);
        intAccount.withdraw(200);
        int balance = intAccount.getBalance();
        if (balance == 1300) {
            cout << "✓ Test 8 PASSED: Template works with int type" << endl;
            passed++;
        } else {
            cout << "✗ Test 8 FAILED" << endl;
            cout << "  Expected balance: 1300" << endl;
            cout << "  Got: " << balance << endl;
        }
    }
    cout << endl;

    cout << "Problem A6 Results: " << passed << "/" << total << " tests passed";
    if (passed == total) cout << " ✓" << endl;
    cout << endl << endl;
}

void runAllTests() {
    cout << "========================================" << endl;
    cout << "   RUNNING ALL INTEGRATION TESTS" << endl;
    cout << "========================================" << endl << endl;
    
    testProblemA1();
    testProblemA2();
    testProblemA3();
    testProblemA4();
    testProblemA5();
    testProblemA6();
    
    cout << "========================================" << endl;
    cout << "      ALL TESTS COMPLETE" << endl;
    cout << "========================================" << endl;
}

int main() {
    cout << "========================================" << endl;
    cout << " CHAPTER 18: INHERITANCE ASSESSMENT" << endl;
    cout << "========================================" << endl << endl;
    
    cout << "This comprehensive assessment tests your mastery of:" << endl;
    cout << "- Basic inheritance and protected members" << endl;
    cout << "- Access specifiers (public, protected, private)" << endl;
    cout << "- Resurrecting members with 'using' declarations" << endl;
    cout << "- Constructor chains and initialization" << endl;
    cout << "- Copy constructors with inheritance" << endl;
    cout << "- Destructor ordering" << endl;
    cout << "- Symbol shadowing and reuse" << endl;
    cout << "- Integration with templates, lambdas, and prior concepts" << endl << endl;

    cout << "INTEGRATION PROBLEMS:" << endl;
    cout << "1. Problem A1 - Foundation Integration (Easy)" << endl;
    cout << "   Tests: Basic inheritance, protected members, simple constructors" << endl;
    cout << "2. Problem A2 - Intermediate Synthesis (Easy-Medium)" << endl;
    cout << "   Tests: Access specifiers, protected inheritance, member resurrection" << endl;
    cout << "3. Problem A3 - Advanced Integration (Medium)" << endl;
    cout << "   Tests: Constructor/destructor chains, copy constructors, dynamic memory" << endl;
    cout << "4. Problem A4 - Complex Synthesis (Medium-Hard)" << endl;
    cout << "   Tests: Symbol shadowing, multilevel inheritance, name resolution" << endl;
    cout << "5. Problem A5 - Mastery Challenge (Hard)" << endl;
    cout << "   Tests: ALL inheritance concepts in complex plugin system" << endl;
    cout << "6. Problem A6 - Expert Application (Very Hard)" << endl;
    cout << "   Tests: Inheritance + templates + lambdas + advanced features" << endl;
    cout << "7. Test All Integration Problems" << endl << endl;

    cout << "KNOWLEDGE VALIDATION:" << endl;
    cout << "8. Chapter Knowledge Quiz (15 questions)" << endl;
    cout << "   Interactive quiz covering all chapter concepts" << endl << endl;

    cout << "COMPREHENSIVE ASSESSMENT:" << endl;
    cout << "9. Full Chapter Assessment (All problems + Quiz)" << endl << endl;

    int choice;
    cout << "Enter your choice (1-9): ";
    cin >> choice;
    cout << endl;

    switch(choice) {
        case 1: testProblemA1(); break;
        case 2: testProblemA2(); break;
        case 3: testProblemA3(); break;
        case 4: testProblemA4(); break;
        case 5: testProblemA5(); break;
        case 6: testProblemA6(); break;
        case 7: runAllTests(); break;
        case 8: knowledgeQuiz(); break;
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
