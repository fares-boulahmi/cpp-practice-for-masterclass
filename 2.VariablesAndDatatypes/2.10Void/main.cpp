#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

// Basic void function - no parameters, no return
void basicGreeting() {
    cout << "=== Basic Void Function ===" << endl;
    cout << "Hello! This function returns nothing (void)." << endl;
    cout << "It just performs actions and exits." << endl;
}

// Void function with parameters
void displayMessage(const string& message, int times) {
    cout << "\n=== Void Function with Parameters ===" << endl;
    for (int i = 0; i < times; i++) {
        cout << "Message " << (i + 1) << ": " << message << endl;
    }
}

// Void function modifying variables by reference
void modifyByReference(int& value, string& text) {
    cout << "\n=== Modifying by Reference ===" << endl;
    cout << "Before modification - Value: " << value << ", Text: " << text << endl;
    
    value *= 2;
    text += " (modified)";
    
    cout << "After modification - Value: " << value << ", Text: " << text << endl;
}

// Void function with array parameter
void processArray(int arr[], int size, const string& operation) {
    cout << "\n=== Processing Array ===" << endl;
    cout << "Operation: " << operation << endl;
    cout << "Original array: ";
    
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    if (operation == "double") {
        for (int i = 0; i < size; i++) {
            arr[i] *= 2;
        }
    } else if (operation == "increment") {
        for (int i = 0; i < size; i++) {
            arr[i]++;
        }
    } else if (operation == "reset") {
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }
    
    cout << "Modified array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Void function with vector reference
void processVector(vector<int>& vec, const string& operation) {
    cout << "\n=== Processing Vector ===" << endl;
    cout << "Operation: " << operation << endl;
    cout << "Original vector: ";
    
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
    
    if (operation == "square") {
        for (int& val : vec) {
            val = val * val;
        }
    } else if (operation == "add_index") {
        for (size_t i = 0; i < vec.size(); i++) {
            vec[i] += static_cast<int>(i);
        }
    } else if (operation == "reverse_sign") {
        for (int& val : vec) {
            val = -val;
        }
    }
    
    cout << "Modified vector: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

// Void function for user interaction
void getUserInput(string& name, int& age, vector<string>& hobbies) {
    cout << "\n=== User Input Collection ===" << endl;
    
    cout << "Enter your name: ";
    cin.ignore(); // Clear input buffer
    getline(cin, name);
    
    cout << "Enter your age: ";
    cin >> age;
    
    int hobbyCount;
    cout << "How many hobbies do you have? ";
    cin >> hobbyCount;
    
    cin.ignore(); // Clear buffer for getline
    hobbies.clear();
    
    for (int i = 0; i < hobbyCount; i++) {
        string hobby;
        cout << "Hobby " << (i + 1) << ": ";
        getline(cin, hobby);
        hobbies.push_back(hobby);
    }
}

// Void function to display collected data
void displayUserProfile(const string& name, int age, const vector<string>& hobbies) {
    cout << "\n=== User Profile ===" << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Hobbies: ";
    
    if (hobbies.empty()) {
        cout << "None specified" << endl;
    } else {
        for (size_t i = 0; i < hobbies.size(); i++) {
            cout << hobbies[i];
            if (i < hobbies.size() - 1) cout << ", ";
        }
        cout << endl;
    }
}

// Void function for mathematical operations (side effects)
void performCalculations(double a, double b) {
    cout << "\n=== Mathematical Operations ===" << endl;
    cout << "Input values: a = " << a << ", b = " << b << endl;
    
    cout << "Addition: " << a << " + " << b << " = " << (a + b) << endl;
    cout << "Subtraction: " << a << " - " << b << " = " << (a - b) << endl;
    cout << "Multiplication: " << a << " * " << b << " = " << (a * b) << endl;
    
    if (b != 0) {
        cout << "Division: " << a << " / " << b << " = " << (a / b) << endl;
    } else {
        cout << "Division: Cannot divide by zero!" << endl;
    }
}

// Void function demonstrating early return
void validateAndProcess(int value) {
    cout << "\n=== Validation and Processing ===" << endl;
    cout << "Processing value: " << value << endl;
    
    if (value < 0) {
        cout << "Error: Negative values are not allowed!" << endl;
        return; // Early exit from void function
    }
    
    if (value == 0) {
        cout << "Warning: Zero value detected, skipping processing." << endl;
        return; // Another early exit
    }
    
    if (value > 1000) {
        cout << "Warning: Value is very large, processing with caution." << endl;
    }
    
    // Main processing logic
    cout << "Processing successful!" << endl;
    cout << "Processed result: " << (value * 2 + 10) << endl;
}

// Void function with pointer parameters
void swapValues(int* a, int* b) {
    cout << "\n=== Swapping Values with Pointers ===" << endl;
    
    if (a == nullptr || b == nullptr) {
        cout << "Error: Null pointer detected!" << endl;
        return;
    }
    
    cout << "Before swap: *a = " << *a << ", *b = " << *b << endl;
    
    int temp = *a;
    *a = *b;
    *b = temp;
    
    cout << "After swap: *a = " << *a << ", *b = " << *b << endl;
}

// Void function for recursive operations (side effect: printing)
void printCountdown(int n) {
    if (n <= 0) {
        cout << "Blast off! 🚀" << endl;
        return;
    }
    
    cout << n << "... ";
    printCountdown(n - 1);
}

void recursiveDemo() {
    cout << "\n=== Recursive Void Function ===" << endl;
    int start;
    cout << "Enter countdown start number: ";
    cin >> start;
    cout << "Countdown: ";
    printCountdown(start);
}

// Void function demonstrating different parameter types
void parameterDemo(int by_value, int& by_reference, const int& const_reference, int* pointer) {
    cout << "\n=== Parameter Types Demonstration ===" << endl;
    cout << "Original values:" << endl;
    cout << "by_value: " << by_value << endl;
    cout << "by_reference: " << by_reference << endl;
    cout << "const_reference: " << const_reference << endl;
    cout << "pointer: " << (pointer ? to_string(*pointer) : "null") << endl;
    
    // Modify what we can
    by_value = 999;        // Won't affect original
    by_reference = 888;    // Will affect original
    // const_reference = 777;  // Compilation error!
    if (pointer) *pointer = 666;  // Will affect original
    
    cout << "\nAfter modifications inside function:" << endl;
    cout << "by_value: " << by_value << endl;
    cout << "by_reference: " << by_reference << endl;
    cout << "const_reference: " << const_reference << endl;
    cout << "pointer: " << (pointer ? to_string(*pointer) : "null") << endl;
}

void displayMenu() {
    cout << "\n======= Void Function Learning Menu =======" << endl;
    cout << "1. Basic void function" << endl;
    cout << "2. Void function with parameters" << endl;
    cout << "3. Modifying by reference" << endl;
    cout << "4. Array processing" << endl;
    cout << "5. Vector processing" << endl;
    cout << "6. User input collection" << endl;
    cout << "7. Mathematical operations" << endl;
    cout << "8. Validation and early return" << endl;
    cout << "9. Pointer operations" << endl;
    cout << "10. Recursive void function" << endl;
    cout << "11. Parameter types demo" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    bool continueProgram = true;
    
    cout << "Welcome to the Interactive Void Function Learning Program!" << endl;
    cout << "This program demonstrates various uses of void functions in C++" << endl;
    
    // Variables for demonstrations
    string userName;
    int userAge;
    vector<string> userHobbies;
    
    while (continueProgram) {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                basicGreeting();
                break;
                
            case 2: {
                string msg;
                int times;
                cout << "Enter message: ";
                cin.ignore();
                getline(cin, msg);
                cout << "How many times to display? ";
                cin >> times;
                displayMessage(msg, times);
                break;
            }
            
            case 3: {
                int value = 10;
                string text = "Original";
                cout << "Initial - Value: " << value << ", Text: " << text << endl;
                modifyByReference(value, text);
                cout << "Final - Value: " << value << ", Text: " << text << endl;
                break;
            }
            
            case 4: {
                const int size = 5;
                int arr[size] = {1, 2, 3, 4, 5};
                string operation;
                cout << "Enter operation (double/increment/reset): ";
                cin >> operation;
                processArray(arr, size, operation);
                break;
            }
            
            case 5: {
                vector<int> vec = {1, 2, 3, 4, 5};
                string operation;
                cout << "Enter operation (square/add_index/reverse_sign): ";
                cin >> operation;
                processVector(vec, operation);
                break;
            }
            
            case 6:
                getUserInput(userName, userAge, userHobbies);
                displayUserProfile(userName, userAge, userHobbies);
                break;
                
            case 7: {
                double a, b;
                cout << "Enter two numbers: ";
                cin >> a >> b;
                performCalculations(a, b);
                break;
            }
            
            case 8: {
                int value;
                cout << "Enter a value to validate: ";
                cin >> value;
                validateAndProcess(value);
                break;
            }
            
            case 9: {
                int x = 100, y = 200;
                cout << "Original values: x = " << x << ", y = " << y << endl;
                swapValues(&x, &y);
                cout << "Final values: x = " << x << ", y = " << y << endl;
                break;
            }
            
            case 10:
                recursiveDemo();
                break;
                
            case 11: {
                int val1 = 111, val2 = 222, val3 = 333, val4 = 444;
                cout << "Before function call:" << endl;
                cout << "val1: " << val1 << ", val2: " << val2 << ", val3: " << val3 << ", val4: " << val4 << endl;
                
                parameterDemo(val1, val2, val3, &val4);
                
                cout << "\nAfter function call (in main):" << endl;
                cout << "val1: " << val1 << ", val2: " << val2 << ", val3: " << val3 << ", val4: " << val4 << endl;
                break;
            }
            
            case 0:
                continueProgram = false;
                cout << "Thanks for learning about void functions!" << endl;
                break;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
        
        if (continueProgram) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
    }
    
    return 0;
}