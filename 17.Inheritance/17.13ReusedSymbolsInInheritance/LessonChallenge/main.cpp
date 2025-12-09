#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// ============================================================================
// Problem 1: Easy 1 - Member Variable Shadow Counter
// ============================================================================
// Problem Description:
// Create a base class "Counter" with a public integer member "count" initialized to 0.
// Create a derived class "AdvancedCounter" that also has a public integer member "count" initialized to 100.
//
// Implement a function that takes an AdvancedCounter object and returns the SUM of:
// - The derived class's count value
// - The base class's count value (accessed using scope resolution)
//
// Input: An AdvancedCounter object with specific count values
// Output: Integer sum of both count values
//
// Example 1:
// AdvancedCounter ac;
// ac.count = 50;           // Derived class count
// ac.Counter::count = 30;  // Base class count
// Result: 50 + 30 = 80
//
// Example 2:
// AdvancedCounter ac;
// ac.count = 0;            // Derived class count
// ac.Counter::count = 100; // Base class count
// Result: 0 + 100 = 100
//
// Constraints:
// - Count values can be 0 to 1000

class Counter
{
public:
    int count;
    Counter() : count(0) {}
};

class AdvancedCounter : public Counter
{
public:
    int count;
    AdvancedCounter() : count(100) {}
};

int problem1Solution(AdvancedCounter &ac)
{
    // TODO: Implement your solution here using Reused Symbols in Inheritance
    // Hint: Use scope resolution operator (::) to access the base class member
    // Return the sum of both count values
}

// ============================================================================
// Problem 2: Easy 2 - Method Override Price Calculator
// ============================================================================
// Problem Description:
// Create a base class "Product" with:
// - public double member "price"
// - public method "getPrice()" that returns the price
//
// Create a derived class "DiscountedProduct" with:
// - public double member "price" (represents discount percentage, 0-100)
// - public method "getPrice()" that returns the ORIGINAL price minus discount
//
// Implement a function that calculates the total savings when buying a discounted product.
// Savings = Original Price - Discounted Price
//
// Input: A DiscountedProduct object
// Output: Double representing the savings amount
//
// Example 1:
// DiscountedProduct dp;
// dp.Product::price = 100.0;  // Original price
// dp.price = 20.0;             // 20% discount
// getPrice() returns: 100.0 - (100.0 * 20.0 / 100.0) = 80.0
// Savings: 100.0 - 80.0 = 20.0
//
// Example 2:
// DiscountedProduct dp;
// dp.Product::price = 250.0;   // Original price
// dp.price = 15.0;              // 15% discount
// getPrice() returns: 250.0 - (250.0 * 15.0 / 100.0) = 212.5
// Savings: 250.0 - 212.5 = 37.5
//
// Constraints:
// - Price: 0.0 to 10000.0
// - Discount: 0.0 to 100.0

class Product
{
public:
    double price;
    Product() : price(0.0) {}
    double getPrice()
    {
        return price;
    }
};

class DiscountedProduct : public Product
{
public:
    double price; // discount percentage
    DiscountedProduct() : price(0.0) {}

    double getPrice()
    {
        // TODO: Implement this method
        // Calculate: original_price - (original_price * discount_percentage / 100)
        // Use Product::price to access the base class price
    }
};

double problem2Solution(DiscountedProduct &dp)
{
    // TODO: Implement your solution here
    // Hint: Calculate savings = Base class getPrice() - Derived class getPrice()
    // Use scope resolution to call the base class method
}

// ============================================================================
// Problem 3: Medium - Multi-Level Symbol Reuse Tracker
// ============================================================================
// Problem Description:
// Create a three-level inheritance hierarchy:
//
// Base class "Tracker" with:
// - public int member "value" initialized to 1
// - public method "getValue()" that returns value
//
// Derived class "ModifiedTracker" (inherits from Tracker) with:
// - public int member "value" initialized to 10
// - public method "getValue()" that returns value * 2
//
// Further derived class "AdvancedTracker" (inherits from ModifiedTracker) with:
// - public int member "value" initialized to 100
// - public method "getValue()" that returns value * 3
//
// Implement a function that takes an AdvancedTracker object and returns a string
// containing all six values in the format:
// "B:[base_value] BM:[base_method] M:[modified_value] MM:[modified_method] A:[advanced_value] AM:[advanced_method]"
//
// Input: AdvancedTracker object
// Output: String with all values
//
// Example 1:
// AdvancedTracker at;
// at.Tracker::value = 5;
// at.ModifiedTracker::value = 20;
// at.value = 50;
// Result: "B:5 BM:5 M:20 MM:40 A:50 AM:150"
// Explanation:
// - B:5 -> Tracker::value = 5
// - BM:5 -> Tracker::getValue() returns 5
// - M:20 -> ModifiedTracker::value = 20
// - MM:40 -> ModifiedTracker::getValue() returns 20*2 = 40
// - A:50 -> AdvancedTracker::value = 50
// - AM:150 -> AdvancedTracker::getValue() returns 50*3 = 150
//
// Constraints:
// - Values can be 0 to 1000

class Tracker
{
public:
    int value;
    Tracker() : value(1) {}
    int getValue()
    {
        return value;
    }
};

class ModifiedTracker : public Tracker
{
public:
    int value;
    ModifiedTracker() : value(10) {}
    int getValue()
    {
        // TODO: Implement this method
        // Return value * 2
    }
};

class AdvancedTracker : public ModifiedTracker
{
public:
    int value;
    AdvancedTracker() : value(100) {}
    int getValue()
    {
        // TODO: Implement this method
        // Return value * 3
    }
};

string problem3Solution(AdvancedTracker &at)
{
    // TODO: Implement your solution here
    // Hint: Access each level's value and getValue() using scope resolution
    // Format: "B:[base_value] BM:[base_method] M:[modified_value] MM:[modified_method] A:[advanced_value] AM:[advanced_method]"
}

// ============================================================================
// Problem 4: Hard - Name Resolver System
// ============================================================================
// Problem Description:
// Create a system that simulates variable name resolution in nested scopes.
//
// Base class "Scope" with:
// - public string member "name"
// - public int member "priority" (1-10, higher = more important)
// - public method "resolveName()" that returns: name + ":" + to_string(priority)
//
// Derived class "NestedScope" (inherits from Scope) with:
// - public string member "name"
// - public int member "priority"
// - public method "resolveName()" that returns the name from the scope with HIGHER priority
//   If priorities are equal, prefer the derived (nested) scope
//   Format: name + ":" + to_string(priority) + " [source: base/nested]"
//
// Implement a function that:
// 1. Takes a NestedScope object
// 2. Returns a string showing which name would be resolved
// 3. Also returns whether there was a conflict (both scopes had the same name but different priorities)
//
// Output format: "resolved_name [conflict: yes/no]"
//
// Example 1:
// NestedScope ns;
// ns.Scope::name = "variable";
// ns.Scope::priority = 5;
// ns.name = "variable";
// ns.priority = 8;
// Result: "variable:8 [source: nested] [conflict: yes]"
// Explanation: Same name, different priorities, higher priority (8) wins from nested scope
//
// Example 2:
// NestedScope ns;
// ns.Scope::name = "data";
// ns.Scope::priority = 7;
// ns.name = "value";
// ns.priority = 3;
// Result: "data:7 [source: base] [conflict: no]"
// Explanation: Different names, base has higher priority, no naming conflict
//
// Example 3:
// NestedScope ns;
// ns.Scope::name = "count";
// ns.Scope::priority = 5;
// ns.name = "count";
// ns.priority = 5;
// Result: "count:5 [source: nested] [conflict: yes]"
// Explanation: Same name and priority, prefer nested scope
//
// Constraints:
// - Name length: 1-20 characters
// - Priority: 1-10

class Scope
{
public:
    string name;
    int priority;
    Scope() : name(""), priority(1) {}
    string resolveName()
    {
        return name + ":" + to_string(priority);
    }
};

class NestedScope : public Scope
{
public:
    string name;
    int priority;
    NestedScope() : name(""), priority(1) {}

    string resolveName()
    {
        // TODO: Implement this method
        // Compare priorities and return the name from the scope with higher priority
        // If equal priority, prefer nested (this) scope
        // Format: name + ":" + to_string(priority) + " [source: base/nested]"
    }
};

string problem4Solution(NestedScope &ns)
{
    // TODO: Implement your solution here
    // Hint: Call resolveName() and check if there's a naming conflict
    // A conflict exists when base and nested have the SAME name but are in different scopes
    // Format: "resolved_output [conflict: yes/no]"
}

// ============================================================================
// TEST FUNCTIONS
// ============================================================================

void testProblem1()
{
    cout << "\n========== Testing Problem 1: Member Variable Shadow Counter ==========" << endl;

    // Test Case 1: Default values
    // Base: 0, Derived: 100
    // Expected: 0 + 100 = 100
    {
        AdvancedCounter ac;
        int result = problem1Solution(ac);
        cout << "Test 1 (Default values): " << (result == 100 ? "✓ PASS" : "✗ FAIL")
             << " (Expected: 100, Got: " << result << ")" << endl;
    }

    // Test Case 2: Modified values
    // Base: 30, Derived: 50
    // Expected: 30 + 50 = 80
    {
        AdvancedCounter ac;
        ac.Counter::count = 30;
        ac.count = 50;
        int result = problem1Solution(ac);
        cout << "Test 2 (Modified values): " << (result == 80 ? "✓ PASS" : "✗ FAIL")
             << " (Expected: 80, Got: " << result << ")" << endl;
    }

    // Test Case 3: Zero derived value
    // Base: 100, Derived: 0
    // Expected: 100 + 0 = 100
    {
        AdvancedCounter ac;
        ac.Counter::count = 100;
        ac.count = 0;
        int result = problem1Solution(ac);
        cout << "Test 3 (Zero derived): " << (result == 100 ? "✓ PASS" : "✗ FAIL")
             << " (Expected: 100, Got: " << result << ")" << endl;
    }

    // Test Case 4: Zero base value
    // Base: 0, Derived: 250
    // Expected: 0 + 250 = 250
    {
        AdvancedCounter ac;
        ac.Counter::count = 0;
        ac.count = 250;
        int result = problem1Solution(ac);
        cout << "Test 4 (Zero base): " << (result == 250 ? "✓ PASS" : "✗ FAIL")
             << " (Expected: 250, Got: " << result << ")" << endl;
    }

    // Test Case 5: Both zero
    // Base: 0, Derived: 0
    // Expected: 0 + 0 = 0
    {
        AdvancedCounter ac;
        ac.Counter::count = 0;
        ac.count = 0;
        int result = problem1Solution(ac);
        cout << "Test 5 (Both zero): " << (result == 0 ? "✓ PASS" : "✗ FAIL")
             << " (Expected: 0, Got: " << result << ")" << endl;
    }

    // Test Case 6: Large values
    // Base: 500, Derived: 500
    // Expected: 500 + 500 = 1000
    {
        AdvancedCounter ac;
        ac.Counter::count = 500;
        ac.count = 500;
        int result = problem1Solution(ac);
        cout << "Test 6 (Large equal values): " << (result == 1000 ? "✓ PASS" : "✗ FAIL")
             << " (Expected: 1000, Got: " << result << ")" << endl;
    }

    // Test Case 7: Different large values
    // Base: 750, Derived: 200
    // Expected: 750 + 200 = 950
    {
        AdvancedCounter ac;
        ac.Counter::count = 750;
        ac.count = 200;
        int result = problem1Solution(ac);
        cout << "Test 7 (Different large values): " << (result == 950 ? "✓ PASS" : "✗ FAIL")
             << " (Expected: 950, Got: " << result << ")" << endl;
    }

    // Test Case 8: Maximum values
    // Base: 1000, Derived: 1000
    // Expected: 1000 + 1000 = 2000
    {
        AdvancedCounter ac;
        ac.Counter::count = 1000;
        ac.count = 1000;
        int result = problem1Solution(ac);
        cout << "Test 8 (Maximum values): " << (result == 2000 ? "✓ PASS" : "✗ FAIL")
             << " (Expected: 2000, Got: " << result << ")" << endl;
    }
}

void testProblem2()
{
    cout << "\n========== Testing Problem 2: Method Override Price Calculator ==========" << endl;

    // Test Case 1: 20% discount on 100
    // Original: 100.0, Discount: 20%
    // Discounted price: 100 - (100 * 20 / 100) = 100 - 20 = 80
    // Savings: 100 - 80 = 20.0
    {
        DiscountedProduct dp;
        dp.Product::price = 100.0;
        dp.price = 20.0;
        double result = problem2Solution(dp);
        cout << "Test 1 (20% off 100): " << (abs(result - 20.0) < 0.01 ? "✓ PASS" : "✗ FAIL")
             << " (Expected: 20.0, Got: " << fixed << setprecision(2) << result << ")" << endl;
    }

    // Test Case 2: 15% discount on 250
    // Original: 250.0, Discount: 15%
    // Discounted price: 250 - (250 * 15 / 100) = 250 - 37.5 = 212.5
    // Savings: 250 - 212.5 = 37.5
    {
        DiscountedProduct dp;
        dp.Product::price = 250.0;
        dp.price = 15.0;
        double result = problem2Solution(dp);
        cout << "Test 2 (15% off 250): " << (abs(result - 37.5) < 0.01 ? "✓ PASS" : "✗ FAIL")
             << " (Expected: 37.5, Got: " << fixed << setprecision(2) << result << ")" << endl;
    }

    // Test Case 3: No discount
    // Original: 150.0, Discount: 0%
    // Discounted price: 150 - (150 * 0 / 100) = 150 - 0 = 150
    // Savings: 150 - 150 = 0.0
    {
        DiscountedProduct dp;
        dp.Product::price = 150.0;
        dp.price = 0.0;
        double result = problem2Solution(dp);
        cout << "Test 3 (0% discount): " << (abs(result - 0.0) < 0.01 ? "✓ PASS" : "✗ FAIL")
             << " (Expected: 0.0, Got: " << fixed << setprecision(2) << result << ")" << endl;
    }

    // Test Case 4: 50% discount (half price)
    // Original: 200.0, Discount: 50%
    // Discounted price: 200 - (200 * 50 / 100) = 200 - 100 = 100
    // Savings: 200 - 100 = 100.0
    {
        DiscountedProduct dp;
        dp.Product::price = 200.0;
        dp.price = 50.0;
        double result = problem2Solution(dp);
        cout << "Test 4 (50% off 200): " << (abs(result - 100.0) < 0.01 ? "✓ PASS" : "✗ FAIL")
             << " (Expected: 100.0, Got: " << fixed << setprecision(2) << result << ")" << endl;
    }

    // Test Case 5: 100% discount (free)
    // Original: 75.0, Discount: 100%
    // Discounted price: 75 - (75 * 100 / 100) = 75 - 75 = 0
    // Savings: 75 - 0 = 75.0
    {
        DiscountedProduct dp;
        dp.Product::price = 75.0;
        dp.price = 100.0;
        double result = problem2Solution(dp);
        cout << "Test 5 (100% discount): " << (abs(result - 75.0) < 0.01 ? "✓ PASS" : "✗ FAIL")
             << " (Expected: 75.0, Got: " << fixed << setprecision(2) << result << ")" << endl;
    }

    // Test Case 6: Small discount on large price
    // Original: 1000.0, Discount: 5%
    // Discounted price: 1000 - (1000 * 5 / 100) = 1000 - 50 = 950
    // Savings: 1000 - 950 = 50.0
    {
        DiscountedProduct dp;
        dp.Product::price = 1000.0;
        dp.price = 5.0;
        double result = problem2Solution(dp);
        cout << "Test 6 (5% off 1000): " << (abs(result - 50.0) < 0.01 ? "✓ PASS" : "✗ FAIL")
             << " (Expected: 50.0, Got: " << fixed << setprecision(2) << result << ")" << endl;
    }

    // Test Case 7: 25% discount on 80
    // Original: 80.0, Discount: 25%
    // Discounted price: 80 - (80 * 25 / 100) = 80 - 20 = 60
    // Savings: 80 - 60 = 20.0
    {
        DiscountedProduct dp;
        dp.Product::price = 80.0;
        dp.price = 25.0;
        double result = problem2Solution(dp);
        cout << "Test 7 (25% off 80): " << (abs(result - 20.0) < 0.01 ? "✓ PASS" : "✗ FAIL")
             << " (Expected: 20.0, Got: " << fixed << setprecision(2) << result << ")" << endl;
    }

    // Test Case 8: 33.33% discount on 300
    // Original: 300.0, Discount: 33.33%
    // Discounted price: 300 - (300 * 33.33 / 100) = 300 - 99.99 = 200.01
    // Savings: 300 - 200.01 = 99.99
    {
        DiscountedProduct dp;
        dp.Product::price = 300.0;
        dp.price = 33.33;
        double result = problem2Solution(dp);
        cout << "Test 8 (33.33% off 300): " << (abs(result - 99.99) < 0.01 ? "✓ PASS" : "✗ FAIL")
             << " (Expected: 99.99, Got: " << fixed << setprecision(2) << result << ")" << endl;
    }
}

void testProblem3()
{
    cout << "\n========== Testing Problem 3: Multi-Level Symbol Reuse Tracker ==========" << endl;

    // Test Case 1: Default values
    // Tracker::value = 1, getValue() = 1
    // ModifiedTracker::value = 10, getValue() = 10*2 = 20
    // AdvancedTracker::value = 100, getValue() = 100*3 = 300
    {
        AdvancedTracker at;
        string result = problem3Solution(at);
        string expected = "B:1 BM:1 M:10 MM:20 A:100 AM:300";
        cout << "Test 1 (Default values): " << (result == expected ? "✓ PASS" : "✗ FAIL")
             << "\n  Expected: " << expected << "\n  Got: " << result << endl;
    }

    // Test Case 2: Modified base value
    // Tracker::value = 5, getValue() = 5
    // ModifiedTracker::value = 20, getValue() = 20*2 = 40
    // AdvancedTracker::value = 50, getValue() = 50*3 = 150
    {
        AdvancedTracker at;
        at.Tracker::value = 5;
        at.ModifiedTracker::value = 20;
        at.value = 50;
        string result = problem3Solution(at);
        string expected = "B:5 BM:5 M:20 MM:40 A:50 AM:150";
        cout << "Test 2 (Modified values): " << (result == expected ? "✓ PASS" : "✗ FAIL")
             << "\n  Expected: " << expected << "\n  Got: " << result << endl;
    }

    // Test Case 3: All zeros
    // Tracker::value = 0, getValue() = 0
    // ModifiedTracker::value = 0, getValue() = 0*2 = 0
    // AdvancedTracker::value = 0, getValue() = 0*3 = 0
    {
        AdvancedTracker at;
        at.Tracker::value = 0;
        at.ModifiedTracker::value = 0;
        at.value = 0;
        string result = problem3Solution(at);
        string expected = "B:0 BM:0 M:0 MM:0 A:0 AM:0";
        cout << "Test 3 (All zeros): " << (result == expected ? "✓ PASS" : "✗ FAIL")
             << "\n  Expected: " << expected << "\n  Got: " << result << endl;
    }

    // Test Case 4: Equal values at all levels
    // Tracker::value = 7, getValue() = 7
    // ModifiedTracker::value = 7, getValue() = 7*2 = 14
    // AdvancedTracker::value = 7, getValue() = 7*3 = 21
    {
        AdvancedTracker at;
        at.Tracker::value = 7;
        at.ModifiedTracker::value = 7;
        at.value = 7;
        string result = problem3Solution(at);
        string expected = "B:7 BM:7 M:7 MM:14 A:7 AM:21";
        cout << "Test 4 (Equal values): " << (result == expected ? "✓ PASS" : "✗ FAIL")
             << "\n  Expected: " << expected << "\n  Got: " << result << endl;
    }

    // Test Case 5: Large values
    // Tracker::value = 100, getValue() = 100
    // ModifiedTracker::value = 200, getValue() = 200*2 = 400
    // AdvancedTracker::value = 300, getValue() = 300*3 = 900
    {
        AdvancedTracker at;
        at.Tracker::value = 100;
        at.ModifiedTracker::value = 200;
        at.value = 300;
        string result = problem3Solution(at);
        string expected = "B:100 BM:100 M:200 MM:400 A:300 AM:900";
        cout << "Test 5 (Large values): " << (result == expected ? "✓ PASS" : "✗ FAIL")
             << "\n  Expected: " << expected << "\n  Got: " << result << endl;
    }

    // Test Case 6: Incremental values
    // Tracker::value = 2, getValue() = 2
    // ModifiedTracker::value = 3, getValue() = 3*2 = 6
    // AdvancedTracker::value = 4, getValue() = 4*3 = 12
    {
        AdvancedTracker at;
        at.Tracker::value = 2;
        at.ModifiedTracker::value = 3;
        at.value = 4;
        string result = problem3Solution(at);
        string expected = "B:2 BM:2 M:3 MM:6 A:4 AM:12";
        cout << "Test 6 (Incremental values): " << (result == expected ? "✓ PASS" : "✗ FAIL")
             << "\n  Expected: " << expected << "\n  Got: " << result << endl;
    }

    // Test Case 7: Maximum values
    // Tracker::value = 1000, getValue() = 1000
    // ModifiedTracker::value = 1000, getValue() = 1000*2 = 2000
    // AdvancedTracker::value = 1000, getValue() = 1000*3 = 3000
    {
        AdvancedTracker at;
        at.Tracker::value = 1000;
        at.ModifiedTracker::value = 1000;
        at.value = 1000;
        string result = problem3Solution(at);
        string expected = "B:1000 BM:1000 M:1000 MM:2000 A:1000 AM:3000";
        cout << "Test 7 (Maximum values): " << (result == expected ? "✓ PASS" : "✗ FAIL")
             << "\n  Expected: " << expected << "\n  Got: " << result << endl;
    }

    // Test Case 8: Mixed small and large
    // Tracker::value = 3, getValue() = 3
    // ModifiedTracker::value = 50, getValue() = 50*2 = 100
    // AdvancedTracker::value = 25, getValue() = 25*3 = 75
    {
        AdvancedTracker at;
        at.Tracker::value = 3;
        at.ModifiedTracker::value = 50;
        at.value = 25;
        string result = problem3Solution(at);
        string expected = "B:3 BM:3 M:50 MM:100 A:25 AM:75";
        cout << "Test 8 (Mixed values): " << (result == expected ? "✓ PASS" : "✗ FAIL")
             << "\n  Expected: " << expected << "\n  Got: " << result << endl;
    }
}

void testProblem4()
{
    cout << "\n========== Testing Problem 4: Name Resolver System ==========" << endl;

    // Test Case 1: Same name, nested has higher priority
    // Base: "variable", priority 5
    // Nested: "variable", priority 8
    // Winner: nested (higher priority)
    // Conflict: yes (same name, different scopes)
    {
        NestedScope ns;
        ns.Scope::name = "variable";
        ns.Scope::priority = 5;
        ns.name = "variable";
        ns.priority = 8;
        string result = problem4Solution(ns);
        string expected = "variable:8 [source: nested] [conflict: yes]";
        cout << "Test 1 (Same name, nested higher): " << (result == expected ? "✓ PASS" : "✗ FAIL")
             << "\n  Expected: " << expected << "\n  Got: " << result << endl;
    }

    // Test Case 2: Different names, base has higher priority
    // Base: "data", priority 7
    // Nested: "value", priority 3
    // Winner: base (higher priority)
    // Conflict: no (different names)
    {
        NestedScope ns;
        ns.Scope::name = "data";
        ns.Scope::priority = 7;
        ns.name = "value";
        ns.priority = 3;
        string result = problem4Solution(ns);
        string expected = "data:7 [source: base] [conflict: no]";
        cout << "Test 2 (Different names, base higher): " << (result == expected ? "✓ PASS" : "✗ FAIL")
             << "\n  Expected: " << expected << "\n  Got: " << result << endl;
    }

    // Test Case 3: Same name and priority (prefer nested)
    // Base: "count", priority 5
    // Nested: "count", priority 5
    // Winner: nested (tie goes to nested)
    // Conflict: yes (same name, different scopes)
    {
        NestedScope ns;
        ns.Scope::name = "count";
        ns.Scope::priority = 5;
        ns.name = "count";
        ns.priority = 5;
        string result = problem4Solution(ns);
        string expected = "count:5 [source: nested] [conflict: yes]";
        cout << "Test 3 (Same name and priority): " << (result == expected ? "✓ PASS" : "✗ FAIL")
             << "\n  Expected: " << expected << "\n  Got: " << result << endl;
    }

    // Test Case 4: Same name, base has higher priority
    // Base: "index", priority 9
    // Nested: "index", priority 2
    // Winner: base (higher priority)
    // Conflict: yes (same name, different scopes)
    {
        NestedScope ns;
        ns.Scope::name = "index";
        ns.Scope::priority = 9;
        ns.name = "index";
        ns.priority = 2;
        string result = problem4Solution(ns);
        string expected = "index:9 [source: base] [conflict: yes]";
        cout << "Test 4 (Same name, base higher): " << (result == expected ? "✓ PASS" : "✗ FAIL")
             << "\n  Expected: " << expected << "\n  Got: " << result << endl;
    }

    // Test Case 5: Different names, nested has higher priority
    // Base: "alpha", priority 4
    // Nested: "beta", priority 6
    // Winner: nested (higher priority)
    // Conflict: no (different names)
    {
        NestedScope ns;
        ns.Scope::name = "alpha";
        ns.Scope::priority = 4;
        ns.name = "beta";
        ns.priority = 6;
        string result = problem4Solution(ns);
        string expected = "beta:6 [source: nested] [conflict: no]";
        cout << "Test 5 (Different names, nested higher): " << (result == expected ? "✓ PASS" : "✗ FAIL")
             << "\n  Expected: " << expected << "\n  Got: " << result << endl;
    }

    // Test Case 6: Different names, equal priority (prefer nested)
    // Base: "x", priority 5
    // Nested: "y", priority 5
    // Winner: nested (tie goes to nested)
    // Conflict: no (different names)
    {
        NestedScope ns;
        ns.Scope::name = "x";
        ns.Scope::priority = 5;
        ns.name = "y";
        ns.priority = 5;
        string result = problem4Solution(ns);
        string expected = "y:5 [source: nested] [conflict: no]";
        cout << "Test 6 (Different names, equal priority): " << (result == expected ? "✓ PASS" : "✗ FAIL")
             << "\n  Expected: " << expected << "\n  Got: " << result << endl;
    }

    // Test Case 7: Maximum priority values
    // Base: "max", priority 10
    // Nested: "max", priority 10
    // Winner: nested (tie goes to nested)
    // Conflict: yes (same name, different scopes)
    {
        NestedScope ns;
        ns.Scope::name = "max";
        ns.Scope::priority = 10;
        ns.name = "max";
        ns.priority = 10;
        string result = problem4Solution(ns);
        string expected = "max:10 [source: nested] [conflict: yes]";
        cout << "Test 7 (Maximum priority): " << (result == expected ? "✓ PASS" : "✗ FAIL")
             << "\n  Expected: " << expected << "\n  Got: " << result << endl;
    }

    // Test Case 8: Minimum priority values
    // Base: "temp", priority 1
    // Nested: "result", priority 1
    // Winner: nested (tie goes to nested)
    // Conflict: no (different names)
    {
        NestedScope ns;
        ns.Scope::name = "temp";
        ns.Scope::priority = 1;
        ns.name = "result";
        ns.priority = 1;
        string result = problem4Solution(ns);
        string expected = "result:1 [source: nested] [conflict: no]";
        cout << "Test 8 (Minimum priority): " << (result == expected ? "✓ PASS" : "✗ FAIL")
             << "\n  Expected: " << expected << "\n  Got: " << result << endl;
    }
}

// ============================================================================
// MAIN FUNCTION
// ============================================================================

int main()
{
    cout << "==================================================================" << endl;
    cout << "      C++ Practice: Reused Symbols in Inheritance" << endl;
    cout << "==================================================================" << endl;

    int choice;
    cout << "\nChoose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy) - Member Variable Shadow Counter" << endl;
    cout << "2. Problem 2 (Easy-Medium) - Method Override Price Calculator" << endl;
    cout << "3. Problem 3 (Medium) - Multi-Level Symbol Reuse Tracker" << endl;
    cout << "4. Problem 4 (Hard) - Name Resolver System" << endl;
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

    cout << "\n==================================================================" << endl;
    cout << "                    Testing Complete!" << endl;
    cout << "==================================================================" << endl;

    return 0;
}
