#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// ==================== PROBLEM 1: EASY 1 ====================
// Problem 1: Book and TextBook Copy Test
// 
// Description:
// You have a base class 'Book' with title and pages, and a derived class 
// 'TextBook' that adds subject. Implement proper copy constructors for both.
// The function should create copies and return the total pages of all books.
//
// Input Format:
// - Book title, pages
// - TextBook title, pages, subject
//
// Output Format:
// - Return total pages after copying
//
// Example 1:
// Book: "C++ Basics", 300 pages
// TextBook: "Data Structures", 450 pages, "Computer Science"
// After copying both, total = 300 + 450 + 300 + 450 = 1500
//
// Constraints:
// - Pages: 1 to 1000
// - Titles and subjects are non-empty strings

class Book {
protected:
    string title;
    int pages;
    
public:
    Book(const string& t, int p) : title(t), pages(p) {
        cout << "Book Constructor: " << title << endl;
    }
    
    // TODO: Implement copy constructor for Book
    Book(const Book& other) : title(other.title) , pages(other.pages)  {
        // TODO: Copy all Book members from other
        // TODO: Print "Book Copy Constructor: [title]"
    }
    
    int getPages() const { return pages; }
    string getTitle() const { return title; }
};

class TextBook : public Book {
private:
    string subject;
    
public:
    TextBook(const string& t, int p, const string& s) 
        : Book(t, p), subject(s) {
        cout << "TextBook Constructor: " << title << endl;
    }
    
    // TODO: Implement copy constructor for TextBook
    TextBook(const TextBook& other) : Book(other) {
        // TODO: Copy TextBook-specific members from other
        // TODO: Print "TextBook Copy Constructor: [title]"
    }
    
    string getSubject() const { return subject; }
};

int problem1Solution(const Book& b, const TextBook& tb) {
    // TODO: Create copies of both objects using copy constructors
    // TODO: Calculate and return total pages of all 4 books (2 originals + 2 copies)
    // Hint: Use the copy constructor syntax: Book bookCopy = b;
    return 0; // Placeholder
}

// ==================== PROBLEM 2: EASY 2 ====================
// Problem 2: Vehicle Inventory System
//
// Description:
// Create a Vehicle base class and a Car derived class. Implement copy constructors
// that properly handle copying of vehicle data. Count how many times copy 
// constructors are called when creating a fleet.
//
// Input Format:
// - Vector of Vehicle objects
// - Vector of Car objects
//
// Output Format:
// - Return total number of copy constructor calls
//
// Example 1:
// 2 Vehicles, 3 Cars
// Creating copies of all objects:
// Vehicle copies = 2, Car copies = 3 (includes base Vehicle copy calls)
// Total copy calls = 2 + 3 + 3 = 8
//
// Constraints:
// - 1 to 10 vehicles
// - Valid year: 1900 to 2024

class Vehicle {
protected:
    string brand;
    int year;
    static int vehicleCopyCount;
    
public:
    Vehicle(const string& b, int y) : brand(b), year(y) {
        cout << "Vehicle Constructor: " << brand << endl;
    }
    
    // TODO: Implement copy constructor
    Vehicle(const Vehicle& other) {
        // TODO: Copy all members
        // TODO: Increment vehicleCopyCount
        // TODO: Print "Vehicle Copy Constructor: [brand]"
    }
    
    static int getVehicleCopyCount() { return vehicleCopyCount; }
    static void resetVehicleCopyCount() { vehicleCopyCount = 0; }
    string getBrand() const { return brand; }
};

int Vehicle::vehicleCopyCount = 0;

class Car : public Vehicle {
private:
    int doors;
    static int carCopyCount;
    
public:
    Car(const string& b, int y, int d) 
        : Vehicle(b, y), doors(d) {
        cout << "Car Constructor: " << brand << endl;
    }
    
    // TODO: Implement copy constructor
    Car(const Car& other) : Vehicle(other) {
        // TODO: Copy Car-specific members
        // TODO: Increment carCopyCount
        // TODO: Print "Car Copy Constructor: [brand]"
    }
    
    static int getCarCopyCount() { return carCopyCount; }
    static void resetCarCopyCount() { carCopyCount = 0; }
    int getDoors() const { return doors; }
};

int Car::carCopyCount = 0;

int problem2Solution(const vector<Vehicle>& vehicles, const vector<Car>& cars) {
    // TODO: Reset both copy counts to 0
    // TODO: Create copies of all vehicles in a new vector
    // TODO: Create copies of all cars in a new vector
    // TODO: Return total of vehicleCopyCount + carCopyCount
    // Hint: Pushing objects into vectors triggers copy constructors
    return 0; // Placeholder
}

// ==================== PROBLEM 3: MEDIUM ====================
// Problem 3: Employee Payroll with Deep Copy
//
// Description:
// Create an Employee base class with dynamically allocated salary history,
// and a Manager derived class with dynamically allocated team member list.
// Implement proper deep copy constructors to avoid shallow copy issues.
//
// Input Format:
// - Employee with salary history array
// - Manager with salary history and team size
//
// Output Format:
// - Return sum of all salaries after proper deep copying
//
// Example 1:
// Employee: 3 salaries [5000, 5500, 6000]
// After copying, modify original: [9999, 5500, 6000]
// Copy should still have: [5000, 5500, 6000]
// Sum from copy = 16500
//
// Constraints:
// - Salary: 1000 to 100000
// - History size: 1 to 12 months
// - Must use dynamic memory allocation

class Employee {
protected:
    string name;
    int* salaryHistory;
    int historySize;
    
public:
    Employee(const string& n, const int* salaries, int size) 
        : name(n), historySize(size) {
        salaryHistory = new int[historySize];
        for(int i = 0; i < historySize; i++) {
            salaryHistory[i] = salaries[i];
        }
        cout << "Employee Constructor: " << name << endl;
    }
    
    // TODO: Implement deep copy constructor
    Employee(const Employee& other) {
        // TODO: Copy name and historySize
        // TODO: Allocate NEW memory for salaryHistory
        // TODO: Copy each salary value from other.salaryHistory
        // TODO: Print "Employee Copy Constructor: [name]"
    }
    
    ~Employee() {
        delete[] salaryHistory;
    }
    
    int* getSalaryHistory() { return salaryHistory; }
    int getHistorySize() const { return historySize; }
    string getName() const { return name; }
};

class Manager : public Employee {
private:
    string* teamMembers;
    int teamSize;
    
public:
    Manager(const string& n, const int* salaries, int salSize,
            const string* team, int tSize)
        : Employee(n, salaries, salSize), teamSize(tSize) {
        teamMembers = new string[teamSize];
        for(int i = 0; i < teamSize; i++) {
            teamMembers[i] = team[i];
        }
        cout << "Manager Constructor: " << name << endl;
    }
    
    // TODO: Implement deep copy constructor
    Manager(const Manager& other) : Employee(other) {
        // TODO: Copy teamSize
        // TODO: Allocate NEW memory for teamMembers
        // TODO: Copy each team member name from other.teamMembers
        // TODO: Print "Manager Copy Constructor: [name]"
    }
    
    ~Manager() {
        delete[] teamMembers;
    }
    
    string* getTeamMembers() { return teamMembers; }
    int getTeamSize() const { return teamSize; }
};

int problem3Solution(Employee& emp) {
    // TODO: Create a copy of the employee using copy constructor
    // TODO: Modify the ORIGINAL employee's first salary to 9999
    // TODO: Calculate sum of all salaries from the COPY (should be unchanged)
    // TODO: Return the sum from the copy
    // Hint: The copy should have independent memory, so changes to original don't affect it
    return 0; // Placeholder
}

// ==================== PROBLEM 4: HARD ====================
// Problem 4: University Course System with Multiple Levels
//
// Description:
// Implement a three-level inheritance hierarchy: Course -> GraduateCourse -> PhDCourse
// Each level has dynamically allocated data. Implement proper copy constructors
// that chain correctly through all levels and perform deep copies.
//
// Input Format:
// - PhDCourse object with research topics, prerequisites, and credits
//
// Output Format:
// - After copying and modifying original, return sum of all credits from copy
//
// Example 1:
// Course: "Advanced AI", 4 credits, 3 prerequisites [101, 201, 301]
// GraduateCourse: adds 2 research topics ["ML", "NLP"]
// PhDCourse: adds advisor "Dr. Smith"
// After copy, modify original prerequisites to [999, 999, 999]
// Copy should still have [101, 201, 301]
// Return sum = 101 + 201 + 301 = 603
//
// Constraints:
// - Credits: 1 to 6
// - Prerequisites: 0 to 10 courses
// - Research topics: 1 to 5

class Course {
protected:
    string courseName;
    int credits;
    int* prerequisites;
    int prereqCount;
    
public:
    Course(const string& name, int cred, const int* prereqs, int count)
        : courseName(name), credits(cred), prereqCount(count) {
        prerequisites = new int[prereqCount];
        for(int i = 0; i < prereqCount; i++) {
            prerequisites[i] = prereqs[i];
        }
        cout << "Course Constructor: " << courseName << endl;
    }
    
    // TODO: Implement deep copy constructor
    Course(const Course& other) {
        // TODO: Copy courseName, credits, prereqCount
        // TODO: Allocate NEW memory for prerequisites
        // TODO: Copy each prerequisite from other
        // TODO: Print "Course Copy Constructor: [courseName]"
    }
    
    ~Course() {
        delete[] prerequisites;
    }
    
    int* getPrerequisites() { return prerequisites; }
    int getPrereqCount() const { return prereqCount; }
    int getCredits() const { return credits; }
};

class GraduateCourse : public Course {
protected:
    string* researchTopics;
    int topicCount;
    
public:
    GraduateCourse(const string& name, int cred, const int* prereqs, int pCount,
                   const string* topics, int tCount)
        : Course(name, cred, prereqs, pCount), topicCount(tCount) {
        researchTopics = new string[topicCount];
        for(int i = 0; i < topicCount; i++) {
            researchTopics[i] = topics[i];
        }
        cout << "GraduateCourse Constructor: " << courseName << endl;
    }
    
    // TODO: Implement deep copy constructor
    GraduateCourse(const GraduateCourse& other) : Course(other) {
        // TODO: Copy topicCount
        // TODO: Allocate NEW memory for researchTopics
        // TODO: Copy each topic from other
        // TODO: Print "GraduateCourse Copy Constructor: [courseName]"
    }
    
    ~GraduateCourse() {
        delete[] researchTopics;
    }
    
    string* getResearchTopics() { return researchTopics; }
    int getTopicCount() const { return topicCount; }
};

class PhDCourse : public GraduateCourse {
private:
    string advisor;
    
public:
    PhDCourse(const string& name, int cred, const int* prereqs, int pCount,
              const string* topics, int tCount, const string& adv)
        : GraduateCourse(name, cred, prereqs, pCount, topics, tCount), advisor(adv) {
        cout << "PhDCourse Constructor: " << courseName << endl;
    }
    
    // TODO: Implement copy constructor
    PhDCourse(const PhDCourse& other) : GraduateCourse(other) {
        // TODO: Copy advisor
        // TODO: Print "PhDCourse Copy Constructor: [courseName]"
    }
    
    string getAdvisor() const { return advisor; }
};

int problem4Solution(PhDCourse& phd) {
    // TODO: Create a copy of PhDCourse using copy constructor
    // TODO: Modify ALL prerequisites in the ORIGINAL to 999
    // TODO: Calculate sum of all prerequisites from the COPY
    // TODO: Return the sum (copy should have original values)
    // Hint: The copy constructor chain should go PhDCourse -> GraduateCourse -> Course
    return 0; // Placeholder
}

// ==================== TEST FUNCTIONS ====================

void testProblem1() {
    cout << "\n========== Testing Problem 1 ==========" << endl;
    
    // Test Case 1: Basic book and textbook
    // Book: 300 pages, TextBook: 450 pages
    // Total after copying = 300 + 450 + 300 + 450 = 1500
    {
        cout << "\n--- Test 1: Basic copy ---" << endl;
        Book b1("C++ Basics", 300);
        TextBook tb1("Data Structures", 450, "CS");
        int result = problem1Solution(b1, tb1);
        cout << "Expected: 1500, Got: " << result << " - " 
             << (result == 1500 ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 2: Minimum pages
    // Book: 1 page, TextBook: 1 page
    // Total = 1 + 1 + 1 + 1 = 4
    {
        cout << "\n--- Test 2: Minimum pages ---" << endl;
        Book b2("Short", 1);
        TextBook tb2("Mini", 1, "Math");
        int result = problem1Solution(b2, tb2);
        cout << "Expected: 4, Got: " << result << " - " 
             << (result == 4 ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 3: Maximum pages
    // Book: 1000 pages, TextBook: 1000 pages
    // Total = 1000 + 1000 + 1000 + 1000 = 4000
    {
        cout << "\n--- Test 3: Maximum pages ---" << endl;
        Book b3("Encyclopedia", 1000);
        TextBook tb3("Advanced Physics", 1000, "Physics");
        int result = problem1Solution(b3, tb3);
        cout << "Expected: 4000, Got: " << result << " - " 
             << (result == 4000 ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 4: Different values
    // Book: 250 pages, TextBook: 380 pages
    // Total = 250 + 380 + 250 + 380 = 1260
    {
        cout << "\n--- Test 4: Different values ---" << endl;
        Book b4("History", 250);
        TextBook tb4("Biology", 380, "Science");
        int result = problem1Solution(b4, tb4);
        cout << "Expected: 1260, Got: " << result << " - " 
             << (result == 1260 ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 5: Same page count
    // Book: 500 pages, TextBook: 500 pages
    // Total = 500 + 500 + 500 + 500 = 2000
    {
        cout << "\n--- Test 5: Same page count ---" << endl;
        Book b5("Novel", 500);
        TextBook tb5("Chemistry", 500, "Science");
        int result = problem1Solution(b5, tb5);
        cout << "Expected: 2000, Got: " << result << " - " 
             << (result == 2000 ? "PASS" : "FAIL") << endl;
    }
}

void testProblem2() {
    cout << "\n========== Testing Problem 2 ==========" << endl;
    
    // Test Case 1: 2 vehicles, 3 cars
    // Vehicle copies when copying vehicles = 2
    // Car copies when copying cars = 3
    // Vehicle copies from Car copy constructors = 3
    // Total = 2 + 3 + 3 = 8
    {
        cout << "\n--- Test 1: 2 vehicles, 3 cars ---" << endl;
        vector<Vehicle> vehicles;
        vehicles.push_back(Vehicle("Toyota", 2020));
        vehicles.push_back(Vehicle("Honda", 2019));
        
        vector<Car> cars;
        cars.push_back(Car("BMW", 2021, 4));
        cars.push_back(Car("Audi", 2022, 2));
        cars.push_back(Car("Tesla", 2023, 4));
        
        int result = problem2Solution(vehicles, cars);
        cout << "Expected: 8, Got: " << result << " - " 
             << (result == 8 ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 2: 1 vehicle, 1 car
    // Vehicle copy = 1, Car copy = 1, Vehicle from Car = 1
    // Total = 1 + 1 + 1 = 3
    {
        cout << "\n--- Test 2: 1 vehicle, 1 car ---" << endl;
        vector<Vehicle> vehicles;
        vehicles.push_back(Vehicle("Ford", 2018));
        
        vector<Car> cars;
        cars.push_back(Car("Mazda", 2020, 4));
        
        int result = problem2Solution(vehicles, cars);
        cout << "Expected: 3, Got: " << result << " - " 
             << (result == 3 ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 3: 0 vehicles, 5 cars
    // Vehicle copy = 0, Car copy = 5, Vehicle from Car = 5
    // Total = 0 + 5 + 5 = 10
    {
        cout << "\n--- Test 3: 0 vehicles, 5 cars ---" << endl;
        vector<Vehicle> vehicles; // Empty
        
        vector<Car> cars;
        for(int i = 0; i < 5; i++) {
            cars.push_back(Car("Car" + to_string(i), 2020, 4));
        }
        
        int result = problem2Solution(vehicles, cars);
        cout << "Expected: 10, Got: " << result << " - " 
             << (result == 10 ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 4: 4 vehicles, 0 cars
    // Vehicle copy = 4, Car copy = 0, Vehicle from Car = 0
    // Total = 4 + 0 + 0 = 4
    {
        cout << "\n--- Test 4: 4 vehicles, 0 cars ---" << endl;
        vector<Vehicle> vehicles;
        for(int i = 0; i < 4; i++) {
            vehicles.push_back(Vehicle("Vehicle" + to_string(i), 2015));
        }
        
        vector<Car> cars; // Empty
        
        int result = problem2Solution(vehicles, cars);
        cout << "Expected: 4, Got: " << result << " - " 
             << (result == 4 ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 5: 3 vehicles, 2 cars
    // Vehicle copy = 3, Car copy = 2, Vehicle from Car = 2
    // Total = 3 + 2 + 2 = 7
    {
        cout << "\n--- Test 5: 3 vehicles, 2 cars ---" << endl;
        vector<Vehicle> vehicles;
        vehicles.push_back(Vehicle("Chevy", 2017));
        vehicles.push_back(Vehicle("Dodge", 2018));
        vehicles.push_back(Vehicle("Jeep", 2019));
        
        vector<Car> cars;
        cars.push_back(Car("Lexus", 2021, 4));
        cars.push_back(Car("Acura", 2022, 2));
        
        int result = problem2Solution(vehicles, cars);
        cout << "Expected: 7, Got: " << result << " - " 
             << (result == 7 ? "PASS" : "FAIL") << endl;
    }
}

void testProblem3() {
    cout << "\n========== Testing Problem 3 ==========" << endl;
    
    // Test Case 1: 3 salaries [5000, 5500, 6000]
    // Sum = 5000 + 5500 + 6000 = 16500
    {
        cout << "\n--- Test 1: Basic 3 salaries ---" << endl;
        int salaries1[] = {5000, 5500, 6000};
        Employee emp1("John", salaries1, 3);
        int result = problem3Solution(emp1);
        cout << "Expected: 16500, Got: " << result << " - " 
             << (result == 16500 ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 2: 1 salary [10000]
    // Sum = 10000
    {
        cout << "\n--- Test 2: Single salary ---" << endl;
        int salaries2[] = {10000};
        Employee emp2("Alice", salaries2, 1);
        int result = problem3Solution(emp2);
        cout << "Expected: 10000, Got: " << result << " - " 
             << (result == 10000 ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 3: 5 salaries [3000, 3500, 4000, 4500, 5000]
    // Sum = 3000 + 3500 + 4000 + 4500 + 5000 = 20000
    {
        cout << "\n--- Test 3: 5 salaries ---" << endl;
        int salaries3[] = {3000, 3500, 4000, 4500, 5000};
        Employee emp3("Bob", salaries3, 5);
        int result = problem3Solution(emp3);
        cout << "Expected: 20000, Got: " << result << " - " 
             << (result == 20000 ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 4: 4 salaries [7000, 7200, 7400, 7600]
    // Sum = 7000 + 7200 + 7400 + 7600 = 29200
    {
        cout << "\n--- Test 4: 4 equal-increment salaries ---" << endl;
        int salaries4[] = {7000, 7200, 7400, 7600};
        Employee emp4("Carol", salaries4, 4);
        int result = problem3Solution(emp4);
        cout << "Expected: 29200, Got: " << result << " - " 
             << (result == 29200 ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 5: 6 salaries [2000, 2500, 3000, 3500, 4000, 4500]
    // Sum = 2000 + 2500 + 3000 + 3500 + 4000 + 4500 = 19500
    {
        cout << "\n--- Test 5: 6 salaries ---" << endl;
        int salaries5[] = {2000, 2500, 3000, 3500, 4000, 4500};
        Employee emp5("David", salaries5, 6);
        int result = problem3Solution(emp5);
        cout << "Expected: 19500, Got: " << result << " - " 
             << (result == 19500 ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 6: 2 salaries [8000, 8500]
    // Sum = 8000 + 8500 = 16500
    {
        cout << "\n--- Test 6: 2 salaries ---" << endl;
        int salaries6[] = {8000, 8500};
        Employee emp6("Emma", salaries6, 2);
        int result = problem3Solution(emp6);
        cout << "Expected: 16500, Got: " << result << " - " 
             << (result == 16500 ? "PASS" : "FAIL") << endl;
    }
}

void testProblem4() {
    cout << "\n========== Testing Problem 4 ==========" << endl;
    
    // Test Case 1: 3 prerequisites [101, 201, 301]
    // Sum = 101 + 201 + 301 = 603
    {
        cout << "\n--- Test 1: 3 prerequisites ---" << endl;
        int prereqs1[] = {101, 201, 301};
        string topics1[] = {"ML", "NLP"};
        PhDCourse phd1("Advanced AI", 4, prereqs1, 3, topics1, 2, "Dr. Smith");
        int result = problem4Solution(phd1);
        cout << "Expected: 603, Got: " << result << " - " 
             << (result == 603 ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 2: 1 prerequisite [150]
    // Sum = 150
    {
        cout << "\n--- Test 2: Single prerequisite ---" << endl;
        int prereqs2[] = {150};
        string topics2[] = {"Quantum Computing"};
        PhDCourse phd2("Quantum Physics", 3, prereqs2, 1, topics2, 1, "Dr. Johnson");
        int result = problem4Solution(phd2);
        cout << "Expected: 150, Got: " << result << " - " 
             << (result == 150 ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 3: 5 prerequisites [100, 200, 300, 400, 500]
    // Sum = 100 + 200 + 300 + 400 + 500 = 1500
    {
        cout << "\n--- Test 3: 5 prerequisites ---" << endl;
        int prereqs3[] = {100, 200, 300, 400, 500};
        string topics3[] = {"Algorithms", "Complexity", "Theory"};
        PhDCourse phd3("Theoretical CS", 5, prereqs3, 5, topics3, 3, "Dr. Lee");
        int result = problem4Solution(phd3);
        cout << "Expected: 1500, Got: " << result << " - " 
             << (result == 1500 ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 4: 4 prerequisites [111, 222, 333, 444]
    // Sum = 111 + 222 + 333 + 444 = 1110
    {
        cout << "\n--- Test 4: 4 prerequisites with pattern ---" << endl;
        int prereqs4[] = {111, 222, 333, 444};
        string topics4[] = {"Robotics", "AI"};
        PhDCourse phd4("Advanced Robotics", 4, prereqs4, 4, topics4, 2, "Dr. Brown");
        int result = problem4Solution(phd4);
        cout << "Expected: 1110, Got: " << result << " - " 
             << (result == 1110 ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 5: 2 prerequisites [250, 350]
    // Sum = 250 + 350 = 600
    {
        cout << "\n--- Test 5: 2 prerequisites ---" << endl;
        int prereqs5[] = {250, 350};
        string topics5[] = {"Cryptography"};
        PhDCourse phd5("Security", 3, prereqs5, 2, topics5, 1, "Dr. Garcia");
        int result = problem4Solution(phd5);
        cout << "Expected: 600, Got: " << result << " - " 
             << (result == 600 ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 6: 6 prerequisites [50, 100, 150, 200, 250, 300]
    // Sum = 50 + 100 + 150 + 200 + 250 + 300 = 1050
    {
        cout << "\n--- Test 6: 6 prerequisites ---" << endl;
        int prereqs6[] = {50, 100, 150, 200, 250, 300};
        string topics6[] = {"Bioinformatics", "Genomics", "DataScience"};
        PhDCourse phd6("Computational Biology", 6, prereqs6, 6, topics6, 3, "Dr. Wilson");
        int result = problem4Solution(phd6);
        cout << "Expected: 1050, Got: " << result << " - " 
             << (result == 1050 ? "PASS" : "FAIL") << endl;
    }
}

int main() {
    int choice;
    cout << "========================================" << endl;
    cout << "Copy Constructors with Inheritance" << endl;
    cout << "Practice Problems" << endl;
    cout << "========================================" << endl;
    cout << "\nChoose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy 1) - Book and TextBook Copy" << endl;
    cout << "2. Problem 2 (Easy 2) - Vehicle Inventory System" << endl;
    cout << "3. Problem 3 (Medium) - Employee Payroll Deep Copy" << endl;
    cout << "4. Problem 4 (Hard) - University Course System" << endl;
    cout << "5. Test All Problems" << endl;
    cout << "\nEnter your choice: ";
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
        default:cout << "Invalid choice!" << endl;
    }

    return 0;
}