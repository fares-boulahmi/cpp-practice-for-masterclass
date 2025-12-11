#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

// ============================================================================
// Problem 1: Easy 1 - Resource Counter
// ============================================================================
// DESCRIPTION:
// Create a base class "Resource" that tracks total resource count.
// Each constructor increments a static counter, each destructor decrements it.
// Implement a method to get current active resource count.
//
// EXAMPLE:
// Create 3 resources -> count = 3
// Destroy 1 resource -> count = 2
// Destroy 2 resources -> count = 0
//
// CONSTRAINTS:
// - Must use static member variable for counting
// - Constructor increments, destructor decrements
//

class Resource {
protected:
    static int totalResources;
    int id;
public:
    Resource() {
        // TODO: Increment totalResources counter
        // TODO: Print "Resource Constructor called"
        totalResources++;
        cout << "Resource Constructor called" << endl;
    }
    
    ~Resource() {
        // TODO: Decrement totalResources counter
        // TODO: Print "Resource Destructor called"
        totalResources--;
        cout << "Resource Destructor called" << endl;
    }
    
    static int getActiveCount() {
        // TODO: Return totalResources
        return totalResources;
    }
};

// Initialize static member
int Resource::totalResources = 0;

// ============================================================================
// Problem 2: Easy 2 - Inheritance Destructor Order
// ============================================================================
// DESCRIPTION:
// Create a base class "Base" and derived class "Derived".
// Each should print a message in constructor and destructor.
// Observe the order: Derived constructor -> Base constructor (for creation)
//                    Derived destructor -> Base destructor (for destruction)
//
// EXAMPLE:
// Creating Derived object prints:
//   "Base Constructor"
//   "Derived Constructor"
// Destroying prints:
//   "Derived Destructor"
//   "Base Destructor"
//

class Base {
protected:
    int baseValue;
public:
    Base(int val) : baseValue(val) {
        // TODO: Print "Base Constructor: value = " << val
    }
    
    ~Base() {
        // TODO: Print "Base Destructor: value = " << baseValue
    }
};

class Derived : public Base {
private:
    int derivedValue;
public:
    Derived(int bVal, int dVal) : Base(bVal), derivedValue(dVal) {
        // TODO: Print "Derived Constructor: value = " << dVal
    }
    
    ~Derived() {
        // TODO: Print "Derived Destructor: value = " << derivedValue
    }
};

void problem2Solution(int baseVal, int derivedVal) {
    // TODO: Create a Derived object with given values
    // It will be automatically destroyed when function ends
}

// ============================================================================
// Problem 3: Medium - Shape Hierarchy with Dynamic Memory
// ============================================================================
// DESCRIPTION:
// Create Shape base class and Rectangle/Circle derived classes.
// Each shape dynamically allocates memory for its properties.
// Must properly clean up in destructors.
// Calculate and return area.
//
// Rectangle: area = width * height
// Circle: area = π * radius² (use 3.14159)
//
// CONSTRAINTS:
// - Must use dynamic memory allocation
// - Must have virtual destructor in base class
// - width, height, radius > 0
//

class Shape {
protected:
    string* name;
    static int shapeCount;
public:
    Shape(const string& n) {
        // TODO: Dynamically allocate name and copy n into it
        // TODO: Increment shapeCount
        // TODO: Print "Shape Constructor: " << name
    }
    
    virtual ~Shape() {
        // TODO: Print "Shape Destructor: " << name
        // TODO: Delete name
        // TODO: Decrement shapeCount
    }
    
    virtual double getArea() const = 0; // Pure virtual
    
    static int getShapeCount() {
        // TODO: Return shapeCount
        return 0;
    }
};

int Shape::shapeCount = 0;

class Rectangle : public Shape {
private:
    double* width;
    double* height;
public:
    Rectangle(double w, double h) : Shape("Rectangle") {
        // TODO: Dynamically allocate width and height
        // TODO: Set their values
        // TODO: Print "Rectangle Constructor: " << w << "x" << h
    }
    
    ~Rectangle() {
        // TODO: Print "Rectangle Destructor"
        // TODO: Delete width and height
    }
    
    double getArea() const override {
        // TODO: Return (*width) * (*height)
        return 0.0;
    }
};

class Circle : public Shape {
private:
    double* radius;
public:
    Circle(double r) : Shape("Circle") {
        // TODO: Dynamically allocate radius
        // TODO: Set its value
        // TODO: Print "Circle Constructor: radius = " << r
    }
    
    ~Circle() {
        // TODO: Print "Circle Destructor"
        // TODO: Delete radius
    }
    
    double getArea() const override {
        // TODO: Return 3.14159 * (*radius) * (*radius)
        return 0.0;
    }
};

// ============================================================================
// Problem 4: Hard - Multi-Level Inheritance with Resource Management
// ============================================================================
// DESCRIPTION:
// Three-level hierarchy: Device -> Computer -> Laptop
// Each level allocates dynamic memory and must clean up properly.
// Track total memory allocated across all objects.
//
// Device: allocates device ID string
// Computer: allocates CPU info, inherits from Device
// Laptop: allocates battery info, inherits from Computer
//
// Must track total memory allocated (in bytes, approximate as string length)
//

class Device {
protected:
    string* deviceId;
    static long long totalMemoryAllocated;
public:
    Device(const string& id) {
        // TODO: Dynamically allocate deviceId
        // TODO: Add id.length() to totalMemoryAllocated
        // TODO: Print "Device Constructor: " << id
    }
    
    virtual ~Device() {
        // TODO: Print "Device Destructor: " << *deviceId
        // TODO: Subtract deviceId->length() from totalMemoryAllocated
        // TODO: Delete deviceId
    }
    
    static long long getTotalMemory() {
        // TODO: Return totalMemoryAllocated
        return 0;
    }
};

long long Device::totalMemoryAllocated = 0;

class Computer : public Device {
protected:
    string* cpuInfo;
public:
    Computer(const string& id, const string& cpu) : Device(id) {
        // TODO: Dynamically allocate cpuInfo
        // TODO: Add cpu.length() to totalMemoryAllocated
        // TODO: Print "Computer Constructor: " << cpu
    }
    
    ~Computer() {
        // TODO: Print "Computer Destructor: " << *cpuInfo
        // TODO: Subtract cpuInfo->length() from totalMemoryAllocated
        // TODO: Delete cpuInfo
    }
};

class Laptop : public Computer {
private:
    string* batteryInfo;
public:
    Laptop(const string& id, const string& cpu, const string& battery) 
        : Computer(id, cpu) {
        // TODO: Dynamically allocate batteryInfo
        // TODO: Add battery.length() to totalMemoryAllocated
        // TODO: Print "Laptop Constructor: " << battery
    }
    
    ~Laptop() {
        // TODO: Print "Laptop Destructor: " << *batteryInfo
        // TODO: Subtract batteryInfo->length() from totalMemoryAllocated
        // TODO: Delete batteryInfo
    }
};

// ============================================================================
// TEST FUNCTIONS
// ============================================================================

void testProblem1() {
    cout << "\n========== Testing Problem 1: Resource Counter ==========" << endl;
    
    // Test 1: Create and destroy in scope
    cout << "\n--- Test 1: Single resource ---" << endl;
    {
        Resource r1;
        cout << "Active resources: " << Resource::getActiveCount() << endl;
        // Expected: 1
    }
    cout << "Active resources after scope: " << Resource::getActiveCount() << endl;
    // Expected: 0
    
    // Test 2: Multiple resources
    cout << "\n--- Test 2: Three resources ---" << endl;
    {
        Resource r1, r2, r3;
        cout << "Active resources: " << Resource::getActiveCount() << endl;
        // Expected: 3
    }
    cout << "Active resources after scope: " << Resource::getActiveCount() << endl;
    // Expected: 0
    
    // Test 3: Nested scopes
    cout << "\n--- Test 3: Nested scopes ---" << endl;
    {
        Resource r1;
        cout << "Outer scope - Active: " << Resource::getActiveCount() << endl;
        // Expected: 1
        {
            Resource r2;
            cout << "Inner scope - Active: " << Resource::getActiveCount() << endl;
            // Expected: 2
        }
        cout << "After inner scope - Active: " << Resource::getActiveCount() << endl;
        // Expected: 1
    }
    cout << "After all scopes - Active: " << Resource::getActiveCount() << endl;
    // Expected: 0
    
    // Test 4: Dynamic allocation
    cout << "\n--- Test 4: Dynamic allocation ---" << endl;
    Resource* r = new Resource();
    cout << "After new - Active: " << Resource::getActiveCount() << endl;
    // Expected: 1
    delete r;
    cout << "After delete - Active: " << Resource::getActiveCount() << endl;
    // Expected: 0
    
    // Test 5: Array of resources
    cout << "\n--- Test 5: Array of resources ---" << endl;
    {
        Resource arr[5];
        cout << "Active resources: " << Resource::getActiveCount() << endl;
        // Expected: 5
    }
    cout << "After array scope - Active: " << Resource::getActiveCount() << endl;
    // Expected: 0
    
    cout << "\n=== Problem 1 Tests Complete ===" << endl;
}

void testProblem2() {
    cout << "\n========== Testing Problem 2: Destructor Order ==========" << endl;
    
    // Test 1: Basic object lifecycle
    cout << "\n--- Test 1: Create and destroy (10, 20) ---" << endl;
    problem2Solution(10, 20);
    // Expected output order:
    // Base Constructor: value = 10
    // Derived Constructor: value = 20
    // Derived Destructor: value = 20
    // Base Destructor: value = 10
    
    // Test 2: Different values
    cout << "\n--- Test 2: Create and destroy (100, 200) ---" << endl;
    problem2Solution(100, 200);
    
    // Test 3: Zero values
    cout << "\n--- Test 3: Create and destroy (0, 0) ---" << endl;
    problem2Solution(0, 0);
    
    // Test 4: Negative values
    cout << "\n--- Test 4: Create and destroy (-5, -10) ---" << endl;
    problem2Solution(-5, -10);
    
    // Test 5: Large values
    cout << "\n--- Test 5: Create and destroy (99999, 88888) ---" << endl;
    problem2Solution(99999, 88888);
    
    // Test 6: Multiple sequential calls
    cout << "\n--- Test 6: Multiple sequential objects ---" << endl;
    problem2Solution(1, 2);
    problem2Solution(3, 4);
    problem2Solution(5, 6);
    
    cout << "\n=== Problem 2 Tests Complete ===" << endl;
}

void testProblem3() {
    cout << "\n========== Testing Problem 3: Shape Hierarchy ==========" << endl;
    cout << fixed << setprecision(2);
    
    // Test 1: Single rectangle
    cout << "\n--- Test 1: Rectangle 5x4 ---" << endl;
    {
        Rectangle* r = new Rectangle(5.0, 4.0);
        cout << "Area: " << r->getArea() << endl;
        // Expected: 20.00
        delete r;
    }
    cout << "Shape count: " << Shape::getShapeCount() << endl;
    // Expected: 0
    
    // Test 2: Single circle
    cout << "\n--- Test 2: Circle radius 3 ---" << endl;
    {
        Circle* c = new Circle(3.0);
        cout << "Area: " << c->getArea() << endl;
        // Expected: 28.27 (3.14159 * 9)
        delete c;
    }
    cout << "Shape count: " << Shape::getShapeCount() << endl;
    // Expected: 0
    
    // Test 3: Multiple shapes
    cout << "\n--- Test 3: Rectangle 10x2 and Circle radius 5 ---" << endl;
    {
        Rectangle* r = new Rectangle(10.0, 2.0);
        Circle* c = new Circle(5.0);
        cout << "Rectangle area: " << r->getArea() << endl;
        // Expected: 20.00
        cout << "Circle area: " << c->getArea() << endl;
        // Expected: 78.54 (3.14159 * 25)
        cout << "Shape count: " << Shape::getShapeCount() << endl;
        // Expected: 2
        delete r;
        delete c;
    }
    cout << "Shape count after cleanup: " << Shape::getShapeCount() << endl;
    // Expected: 0
    
    // Test 4: Small dimensions
    cout << "\n--- Test 4: Rectangle 0.5x0.5 ---" << endl;
    {
        Rectangle* r = new Rectangle(0.5, 0.5);
        cout << "Area: " << r->getArea() << endl;
        // Expected: 0.25
        delete r;
    }
    
    // Test 5: Large circle
    cout << "\n--- Test 5: Circle radius 100 ---" << endl;
    {
        Circle* c = new Circle(100.0);
        cout << "Area: " << c->getArea() << endl;
        // Expected: 31415.90 (3.14159 * 10000)
        delete c;
    }
    
    // Test 6: Using base pointer
    cout << "\n--- Test 6: Polymorphism test ---" << endl;
    {
        Shape* s1 = new Rectangle(6.0, 7.0);
        Shape* s2 = new Circle(4.0);
        cout << "Shape 1 area: " << s1->getArea() << endl;
        // Expected: 42.00
        cout << "Shape 2 area: " << s2->getArea() << endl;
        // Expected: 50.27 (3.14159 * 16)
        delete s1;
        delete s2;
    }
    
    cout << "\n=== Problem 3 Tests Complete ===" << endl;
}

void testProblem4() {
    cout << "\n========== Testing Problem 4: Multi-Level Inheritance ==========" << endl;
    
    // Test 1: Single laptop
    cout << "\n--- Test 1: Create laptop DEV001 ---" << endl;
    {
        Laptop* lap = new Laptop("DEV001", "Intel i7", "8000mAh");
        cout << "Total memory allocated: " << Device::getTotalMemory() << " bytes" << endl;
        // Expected: 6 + 8 + 8 = 22 bytes
        delete lap;
    }
    cout << "Total memory after cleanup: " << Device::getTotalMemory() << " bytes" << endl;
    // Expected: 0
    
    // Test 2: Multiple devices
    cout << "\n--- Test 2: Multiple devices ---" << endl;
    {
        Device* d = new Device("DEVICE1");
        Computer* c = new Computer("COMP1", "AMD Ryzen");
        Laptop* l = new Laptop("LAP1", "Intel", "Li-ion");
        cout << "Total memory: " << Device::getTotalMemory() << " bytes" << endl;
        // Expected: 7 + (5 + 9) + (4 + 5 + 6) = 7 + 14 + 15 = 36 bytes
        delete d;
        cout << "After deleting device: " << Device::getTotalMemory() << " bytes" << endl;
        // Expected: 29
        delete c;
        cout << "After deleting computer: " << Device::getTotalMemory() << " bytes" << endl;
        // Expected: 15
        delete l;
        cout << "After deleting laptop: " << Device::getTotalMemory() << " bytes" << endl;
        // Expected: 0
    }
    
    // Test 3: Short strings
    cout << "\n--- Test 3: Minimal strings ---" << endl;
    {
        Laptop* l = new Laptop("A", "B", "C");
        cout << "Total memory: " << Device::getTotalMemory() << " bytes" << endl;
        // Expected: 1 + 1 + 1 = 3 bytes
        delete l;
    }
    
    // Test 4: Long strings
    cout << "\n--- Test 4: Long strings ---" << endl;
    {
        Laptop* l = new Laptop("VERYLONGDEVICEID", "IntelCorei9Processor", "LithiumIonBattery");
        cout << "Total memory: " << Device::getTotalMemory() << " bytes" << endl;
        // Expected: 16 + 20 + 18 = 54 bytes
        delete l;
    }
    
    // Test 5: Multiple laptops
    cout << "\n--- Test 5: Three laptops ---" << endl;
    {
        Laptop* l1 = new Laptop("LAP1", "CPU1", "BAT1");
        Laptop* l2 = new Laptop("LAP2", "CPU2", "BAT2");
        Laptop* l3 = new Laptop("LAP3", "CPU3", "BAT3");
        cout << "Total memory: " << Device::getTotalMemory() << " bytes" << endl;
        // Expected: (4+4+4)*3 = 36 bytes
        delete l1;
        delete l2;
        delete l3;
        cout << "After cleanup: " << Device::getTotalMemory() << " bytes" << endl;
        // Expected: 0
    }
    
    cout << "\n=== Problem 4 Tests Complete ===" << endl;
}

// ============================================================================
// MAIN MENU
// ============================================================================

int main() {
    int choice;
    
    cout << "======================================" << endl;
    cout << " C++ Inheritance & Destructors Practice" << endl;
    cout << "======================================" << endl;
    cout << "1. Problem 1 (Easy) - Resource Counter" << endl;
    cout << "2. Problem 2 (Easy) - Destructor Order" << endl;
    cout << "3. Problem 3 (Medium) - Shape Hierarchy" << endl;
    cout << "4. Problem 4 (Hard) - Multi-Level Inheritance" << endl;
    cout << "5. Test All Problems" << endl;
    cout << "======================================" << endl;
    cout << "Enter your choice (1-5): ";
    cin >> choice;
    
    switch(choice) {
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
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
    
    return 0;
}