#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ===== PART 1: WHAT IS A STRUCT? =====
// Think of struct as a way to group related variables together
// Like creating your own custom data type!

// Basic struct - like a container holding related data
struct Student {
    string name;
    int age;
    double gpa;
};

// ===== PART 2: CREATING AND USING STRUCTS =====
void basicStructExample() {
    cout << "\n=== BASIC STRUCT USAGE ===\n";
    
    // Create a struct variable (like creating int x = 5)
    Student student1;
    
    // Access members using dot operator (.)
    student1.name = "Ahmed";
    student1.age = 20;
    student1.gpa = 3.75;
    
    // Print the data
    cout << "Student: " << student1.name << endl;
    cout << "Age: " << student1.age << endl;
    cout << "GPA: " << student1.gpa << endl;
    
    // You can also initialize directly
    Student student2 = {"Fatima", 19, 3.9};
    cout << "\nStudent 2: " << student2.name << ", Age: " << student2.age << endl;
}

// ===== PART 3: STRUCTS AS FUNCTION PARAMETERS =====
// You can pass structs to functions just like int, string, etc.

void printStudent(Student s) {
    cout << s.name << " (Age: " << s.age << ", GPA: " << s.gpa << ")" << endl;
}

// Functions can also RETURN structs
Student createStudent(string name, int age, double gpa) {
    Student newStudent;
    newStudent.name = name;
    newStudent.age = age;
    newStudent.gpa = gpa;
    return newStudent;  // Return the whole struct!
}

// ===== PART 4: VECTORS OF STRUCTS =====
void structVectorExample() {
    cout << "\n=== VECTORS OF STRUCTS ===\n";
    
    // Vector of structs - like array of custom objects
    vector<Student> classroom;
    
    // Add students to vector
    classroom.push_back({"Ali", 21, 3.8});
    classroom.push_back({"Nour", 20, 3.6});
    classroom.push_back({"Omar", 22, 3.9});
    
    // Loop through vector of structs
    cout << "Classroom roster:\n";
    for(int i = 0; i < classroom.size(); i++) {
        cout << i+1 << ". ";
        printStudent(classroom[i]);
    }
    
    // Or using range-based for loop (modern C++)
    cout << "\nUsing modern for loop:\n";
    for(Student s : classroom) {
        printStudent(s);
    }
}

// ===== PART 5: MORE COMPLEX STRUCTS (LIKE IN YOUR ASSIGNMENT) =====

// This is similar to CounterStats in your assignment
struct GameStats {
    int score;
    int lives;
    bool game_over;
    string player_name;
    vector<int> level_scores;  // Structs can contain vectors too!
};

// This is similar to what you'll see in your physics problem
struct Point2D {
    double x, y;
};

struct PhysicsObject {
    Point2D position;      // Struct inside struct!
    Point2D velocity;
    double mass;
    bool active;
};

void complexStructExample() {
    cout << "\n=== COMPLEX STRUCTS ===\n";
    
    // Create game stats
    GameStats game;
    game.score = 1500;
    game.lives = 3;
    game.game_over = false;
    game.player_name = "Player1";
    game.level_scores = {200, 450, 850};  // Initialize vector
    
    cout << "Player: " << game.player_name << endl;
    cout << "Score: " << game.score << ", Lives: " << game.lives << endl;
    cout << "Game Over: " << (game.game_over ? "Yes" : "No") << endl;
    
    // Create physics object
    PhysicsObject bullet;
    bullet.position = {10.5, 20.3};  // Initialize struct inside struct
    bullet.velocity = {5.0, -2.1};
    bullet.mass = 0.1;
    bullet.active = true;
    
    cout << "\nBullet position: (" << bullet.position.x << ", " << bullet.position.y << ")" << endl;
    cout << "Bullet velocity: (" << bullet.velocity.x << ", " << bullet.velocity.y << ")" << endl;
}

// ===== PART 6: UNDERSTANDING YOUR ASSIGNMENT STRUCTS =====

// Let's look at the structs from your assignment and explain them:

// This is like CounterStats from Problem A2
struct MyCounterStats {
    int current_value;        // Simple integer - current counter value
    int operations_count;     // How many operations were performed
    bool overflow_warning;    // True if we hit limits
    bool underflow_warning;   // True if we went below limits
};

// This is like StatisticsReport from Problem A5
struct MyStatsReport {
    double mean, median;           // Statistical calculations
    vector<double> mode_values;    // Can have multiple modes
    double min_value, max_value;   // Range information
    int data_points_processed;     // How much data we handled
    vector<string> warnings;       // List of any problems
    string formatted_report;       // Final formatted output
};

// Example of how you might use these in your assignment
void assignmentStructExample() {
    cout << "\n=== ASSIGNMENT-STYLE STRUCTS ===\n";
    
    // Create a counter stats result
    MyCounterStats result;
    result.current_value = 42;
    result.operations_count = 15;
    result.overflow_warning = false;
    result.underflow_warning = false;
    
    cout << "Counter Result:" << endl;
    cout << "  Current Value: " << result.current_value << endl;
    cout << "  Operations: " << result.operations_count << endl;
    cout << "  Overflow Warning: " << (result.overflow_warning ? "Yes" : "No") << endl;
    
    // Create a statistics report
    MyStatsReport stats;
    stats.mean = 45.6;
    stats.median = 44.0;
    stats.mode_values = {42, 45};  // Multiple modes possible
    stats.min_value = 12.0;
    stats.max_value = 89.0;
    stats.data_points_processed = 100;
    stats.warnings = {"No warnings"};
    stats.formatted_report = "Statistics calculated successfully";
    
    cout << "\nStatistics Report:" << endl;
    cout << "  Mean: " << stats.mean << endl;
    cout << "  Median: " << stats.median << endl;
    cout << "  Data Points: " << stats.data_points_processed << endl;
    cout << "  Report: " << stats.formatted_report << endl;
}

// ===== KEY POINTS FOR YOUR ASSIGNMENT =====
/*
1. STRUCT DEFINITION: Define the structure of your data
   struct MyStruct {
       int someNumber;
       string someText;
       bool someFlag;
   };

2. CREATING STRUCT VARIABLES: Like creating any variable
   MyStruct myData;
   MyStruct myData2 = {42, "Hello", true};

3. ACCESSING MEMBERS: Use dot operator
   myData.someNumber = 100;
   cout << myData.someText;

4. RETURNING STRUCTS FROM FUNCTIONS: Your assignment functions return structs
   MyStruct myFunction(int param) {
       MyStruct result;
       result.someNumber = param * 2;
       result.someText = "Calculated";
       result.someFlag = true;
       return result;  // Return the whole struct
   }

5. VECTORS IN STRUCTS: Common in your assignment
   struct DataResult {
       vector<int> numbers;      // Can store multiple values
       vector<string> labels;    // Can store multiple strings
   };

   DataResult result;
   result.numbers.push_back(42);
   result.labels.push_back("First");

6. INITIALIZATION: Several ways to set initial values
   // Method 1: Set after creation
   MyStruct data;
   data.someNumber = 42;
   
   // Method 2: Initialize during creation
   MyStruct data = {42, "Hello", true};
   
   // Method 3: Initialize inside function
   MyStruct data;
   data = {42, "Hello", true};
*/

int main() {
    cout << "=== C++ STRUCTS TUTORIAL ===";
    
    basicStructExample();
    structVectorExample();
    complexStructExample();
    assignmentStructExample();
    
    cout << "\n=== SUMMARY ===\n";
    cout << "- Struct groups related data together\n";
    cout << "- Access members with dot operator (.)\n";
    cout << "- Can be used like any other data type\n";
    cout << "- Perfect for returning multiple values from functions\n";
    cout << "- Can contain vectors, other structs, any data type\n";
    
    return 0;
}

// ===== HOW THIS APPLIES TO YOUR ASSIGNMENT =====
/*
In your assignment, each problem asks you to return a struct containing results.
For example, Problem A2 wants you to return CounterStats with:
- current_value: the final counter value after all operations
- operations_count: how many operations you performed
- overflow_warning: true if you detected overflow
- underflow_warning: true if you detected underflow

Your function would look like:
CounterStats advancedCounterSystem(...) {
    CounterStats result;
    
    // Do your calculations here...
    result.current_value = finalValue;
    result.operations_count = opCount;
    result.overflow_warning = overflowDetected;
    result.underflow_warning = underflowDetected;
    
    return result;  // Return the complete struct
}

The person calling your function can then access all the results:
CounterStats stats = advancedCounterSystem(10, 5, operations);
cout << "Final value: " << stats.current_value << endl;
cout << "Operations: " << stats.operations_count << endl;
*/