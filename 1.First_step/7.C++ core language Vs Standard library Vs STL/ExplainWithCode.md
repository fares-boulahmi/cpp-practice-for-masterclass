# C++ STL, Standard Library & Core Features - Comprehensive Guide

## Table of Contents
1. [Overview](#overview)
2. [Containers](#containers)
3. [Iterators](#iterators)
4. [Algorithms](#algorithms)
5. [Function Objects (Functors)](#function-objects-functors)
6. [Standard Library Components](#standard-library-components)
7. [Memory Management](#memory-management)
8. [Input/Output Streams](#inputoutput-streams)
9. [String Handling](#string-handling)
10. [Utilities](#utilities)

## Overview

The C++ Standard Template Library (STL) is a collection of template classes and functions that provide common data structures and algorithms. It's part of the larger C++ Standard Library and consists of four main components:

1. **Containers** - Data structures to store objects
2. **Iterators** - Objects that point to elements in containers
3. **Algorithms** - Functions that perform operations on containers
4. **Function Objects** - Objects that behave like functions

## Containers

### Sequence Containers

#### 1. Vector
Dynamic array that can resize automatically.

```cpp
#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    // Adding elements
    vec.push_back(6);
    vec.insert(vec.begin() + 2, 10); // Insert 10 at index 2
    
    // Accessing elements
    std::cout << "Element at index 0: " << vec[0] << std::endl;
    std::cout << "Element at index 1: " << vec.at(1) << std::endl;
    
    // Size and capacity
    std::cout << "Size: " << vec.size() << std::endl;
    std::cout << "Capacity: " << vec.capacity() << std::endl;
    
    // Iterating
    for (const auto& element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
```

#### 2. List
Doubly-linked list for efficient insertion/deletion.

```cpp
#include <list>
#include <iostream>

int main() {
    std::list<int> lst = {1, 2, 3, 4, 5};
    
    // Adding elements
    lst.push_front(0);
    lst.push_back(6);
    
    // Inserting
    auto it = lst.begin();
    std::advance(it, 3);
    lst.insert(it, 99);
    
    // Removing elements
    lst.remove(2); // Remove all elements with value 2
    lst.pop_front();
    lst.pop_back();
    
    // Display
    for (const auto& element : lst) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
```

#### 3. Deque
Double-ended queue allowing efficient insertion/deletion at both ends.

```cpp
#include <deque>
#include <iostream>

int main() {
    std::deque<int> dq = {3, 4, 5};
    
    // Adding at both ends
    dq.push_front(2);
    dq.push_front(1);
    dq.push_back(6);
    dq.push_back(7);
    
    // Accessing elements
    std::cout << "Front: " << dq.front() << std::endl;
    std::cout << "Back: " << dq.back() << std::endl;
    std::cout << "At index 3: " << dq[3] << std::endl;
    
    // Removing from both ends
    dq.pop_front();
    dq.pop_back();
    
    for (const auto& element : dq) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
```

### Associative Containers

#### 1. Set
Sorted collection of unique elements.

```cpp
#include <set>
#include <iostream>

int main() {
    std::set<int> s = {5, 2, 8, 2, 1, 9}; // Duplicates automatically removed
    
    // Inserting elements
    s.insert(3);
    s.insert(7);
    
    // Finding elements
    auto it = s.find(5);
    if (it != s.end()) {
        std::cout << "Found: " << *it << std::endl;
    }
    
    // Checking existence
    if (s.count(8)) {
        std::cout << "8 exists in the set" << std::endl;
    }
    
    // Range operations
    auto lower = s.lower_bound(3);
    auto upper = s.upper_bound(7);
    
    std::cout << "Elements from 3 to 7: ";
    for (auto it = lower; it != upper; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Display all elements (automatically sorted)
    std::cout << "All elements: ";
    for (const auto& element : s) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
```

#### 2. Map
Key-value pairs with unique keys, sorted by key.

```cpp
#include <map>
#include <iostream>
#include <string>

int main() {
    std::map<std::string, int> ages;
    
    // Inserting elements
    ages["Alice"] = 25;
    ages["Bob"] = 30;
    ages.insert(std::make_pair("Charlie", 35));
    ages.emplace("David", 28);
    
    // Accessing elements
    std::cout << "Alice's age: " << ages["Alice"] << std::endl;
    
    // Safe access with at()
    try {
        std::cout << "Bob's age: " << ages.at("Bob") << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Key not found!" << std::endl;
    }
    
    // Finding elements
    auto it = ages.find("Charlie");
    if (it != ages.end()) {
        std::cout << it->first << " is " << it->second << " years old" << std::endl;
    }
    
    // Iterating
    std::cout << "All ages:" << std::endl;
    for (const auto& pair : ages) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    
    return 0;
}
```

### Unordered Containers (Hash Tables)

#### 1. Unordered Set
Hash-based set for O(1) average insertion/lookup.

```cpp
#include <unordered_set>
#include <iostream>

int main() {
    std::unordered_set<int> us = {1, 2, 3, 4, 5};
    
    // Inserting
    us.insert(6);
    us.insert(3); // Duplicate, won't be added
    
    // Finding
    if (us.find(4) != us.end()) {
        std::cout << "4 found in unordered_set" << std::endl;
    }
    
    // Performance info
    std::cout << "Size: " << us.size() << std::endl;
    std::cout << "Bucket count: " << us.bucket_count() << std::endl;
    std::cout << "Load factor: " << us.load_factor() << std::endl;
    
    // Display elements (order not guaranteed)
    for (const auto& element : us) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
```

## Iterators

Iterators provide a uniform way to access container elements.

```cpp
#include <vector>
#include <list>
#include <iostream>
#include <iterator>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    // Forward iterator
    std::cout << "Forward iteration: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Reverse iterator
    std::cout << "Reverse iteration: ";
    for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Const iterator
    std::cout << "Const iteration: ";
    for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
        std::cout << *it << " ";
        // *it = 10; // Error: cannot modify through const iterator
    }
    std::cout << std::endl;
    
    // Iterator arithmetic (for random access iterators)
    auto it = vec.begin();
    std::cout << "Element at position 2: " << *(it + 2) << std::endl;
    
    // Distance between iterators
    std::cout << "Distance from begin to end: " 
              << std::distance(vec.begin(), vec.end()) << std::endl;
    
    return 0;
}
```

## Algorithms

The STL provides numerous algorithms that work with iterators.

```cpp
#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>
#include <functional>

int main() {
    std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    
    // Sorting
    std::sort(vec.begin(), vec.end());
    std::cout << "Sorted: ";
    for (const auto& x : vec) std::cout << x << " ";
    std::cout << std::endl;
    
    // Binary search (requires sorted container)
    bool found = std::binary_search(vec.begin(), vec.end(), 5);
    std::cout << "5 found: " << (found ? "Yes" : "No") << std::endl;
    
    // Finding elements
    auto it = std::find(vec.begin(), vec.end(), 4);
    if (it != vec.end()) {
        std::cout << "Found 4 at position: " 
                  << std::distance(vec.begin(), it) << std::endl;
    }
    
    // Count occurrences
    int count = std::count(vec.begin(), vec.end(), 1);
    std::cout << "Number of 1s: " << count << std::endl;
    
    // Transform elements
    std::vector<int> squared(vec.size());
    std::transform(vec.begin(), vec.end(), squared.begin(),
                   [](int x) { return x * x; });
    
    std::cout << "Squared: ";
    for (const auto& x : squared) std::cout << x << " ";
    std::cout << std::endl;
    
    // Accumulate (sum)
    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    std::cout << "Sum: " << sum << std::endl;
    
    // Remove duplicates
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
    std::cout << "Unique elements: ";
    for (const auto& x : vec) std::cout << x << " ";
    std::cout << std::endl;
    
    // Partition
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto partition_point = std::partition(numbers.begin(), numbers.end(),
                                         [](int x) { return x % 2 == 0; });
    
    std::cout << "Even numbers: ";
    for (auto it = numbers.begin(); it != partition_point; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
```

## Function Objects (Functors)

Function objects are objects that can be called like functions.

```cpp
#include <functional>
#include <algorithm>
#include <vector>
#include <iostream>

// Custom functor class
class Multiply {
private:
    int factor;
public:
    Multiply(int f) : factor(f) {}
    int operator()(int x) const {
        return x * factor;
    }
};

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    // Using custom functor
    Multiply multiply_by_3(3);
    std::transform(vec.begin(), vec.end(), vec.begin(), multiply_by_3);
    
    std::cout << "Multiplied by 3: ";
    for (const auto& x : vec) std::cout << x << " ";
    std::cout << std::endl;
    
    // Using standard functors
    std::vector<int> vec2 = {1, 2, 3, 4, 5};
    std::transform(vec2.begin(), vec2.end(), vec2.begin(),
                   std::bind(std::multiplies<int>(), std::placeholders::_1, 2));
    
    std::cout << "Multiplied by 2: ";
    for (const auto& x : vec2) std::cout << x << " ";
    std::cout << std::endl;
    
    // Using lambda functions
    std::vector<int> vec3 = {1, 2, 3, 4, 5};
    std::transform(vec3.begin(), vec3.end(), vec3.begin(),
                   [](int x) { return x * x; });
    
    std::cout << "Squared: ";
    for (const auto& x : vec3) std::cout << x << " ";
    std::cout << std::endl;
    
    return 0;
}
```

## Standard Library Components

### Smart Pointers

```cpp
#include <memory>
#include <iostream>

class Resource {
public:
    Resource(int id) : id_(id) {
        std::cout << "Resource " << id_ << " created" << std::endl;
    }
    ~Resource() {
        std::cout << "Resource " << id_ << " destroyed" << std::endl;
    }
    void use() {
        std::cout << "Using resource " << id_ << std::endl;
    }
private:
    int id_;
};

int main() {
    // unique_ptr - exclusive ownership
    std::unique_ptr<Resource> unique_res = std::make_unique<Resource>(1);
    unique_res->use();
    
    // Move ownership
    std::unique_ptr<Resource> another_unique = std::move(unique_res);
    // unique_res is now nullptr
    
    // shared_ptr - shared ownership
    std::shared_ptr<Resource> shared_res1 = std::make_shared<Resource>(2);
    {
        std::shared_ptr<Resource> shared_res2 = shared_res1;
        std::cout << "Reference count: " << shared_res1.use_count() << std::endl;
        shared_res2->use();
    } // shared_res2 goes out of scope
    
    std::cout << "Reference count after scope: " << shared_res1.use_count() << std::endl;
    
    // weak_ptr - non-owning observer
    std::weak_ptr<Resource> weak_res = shared_res1;
    
    if (auto locked = weak_res.lock()) {
        locked->use();
        std::cout << "Resource still alive" << std::endl;
    }
    
    return 0;
}
```

### Threads and Concurrency

```cpp
#include <thread>
#include <mutex>
#include <atomic>
#include <future>
#include <iostream>
#include <vector>

std::mutex mtx;
std::atomic<int> atomic_counter(0);
int shared_counter = 0;

void thread_function(int id) {
    for (int i = 0; i < 1000; ++i) {
        // Using mutex for thread-safe access
        {
            std::lock_guard<std::mutex> lock(mtx);
            shared_counter++;
        }
        
        // Using atomic for lock-free access
        atomic_counter++;
    }
    
    std::cout << "Thread " << id << " finished" << std::endl;
}

int calculate_sum(int start, int end) {
    int sum = 0;
    for (int i = start; i <= end; ++i) {
        sum += i;
    }
    return sum;
}

int main() {
    // Basic thread creation
    std::vector<std::thread> threads;
    
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(thread_function, i);
    }
    
    // Wait for all threads to complete
    for (auto& t : threads) {
        t.join();
    }
    
    std::cout << "Shared counter: " << shared_counter << std::endl;
    std::cout << "Atomic counter: " << atomic_counter << std::endl;
    
    // Using std::async for future-based concurrency
    std::vector<std::future<int>> futures;
    
    for (int i = 0; i < 4; ++i) {
        int start = i * 250 + 1;
        int end = (i + 1) * 250;
        futures.push_back(std::async(std::launch::async, calculate_sum, start, end));
    }
    
    int total_sum = 0;
    for (auto& future : futures) {
        total_sum += future.get();
    }
    
    std::cout << "Sum of 1 to 1000: " << total_sum << std::endl;
    
    return 0;
}
```

## Memory Management

### Custom Allocators and Memory Pools

```cpp
#include <memory>
#include <vector>
#include <iostream>
#include <chrono>

// Simple memory pool allocator
template<typename T>
class PoolAllocator {
private:
    struct Block {
        alignas(T) char data[sizeof(T)];
        Block* next;
    };
    
    Block* free_list;
    std::vector<std::unique_ptr<Block[]>> pools;
    size_t pool_size;
    
public:
    using value_type = T;
    
    PoolAllocator(size_t pool_size = 1000) : free_list(nullptr), pool_size(pool_size) {}
    
    template<typename U>
    PoolAllocator(const PoolAllocator<U>& other) : free_list(nullptr), pool_size(other.pool_size) {}
    
    T* allocate(size_t n) {
        if (n != 1) {
            throw std::bad_alloc();
        }
        
        if (!free_list) {
            // Allocate new pool
            auto new_pool = std::make_unique<Block[]>(pool_size);
            for (size_t i = 0; i < pool_size - 1; ++i) {
                new_pool[i].next = &new_pool[i + 1];
            }
            new_pool[pool_size - 1].next = nullptr;
            free_list = &new_pool[0];
            pools.push_back(std::move(new_pool));
        }
        
        Block* block = free_list;
        free_list = free_list->next;
        return reinterpret_cast<T*>(block);
    }
    
    void deallocate(T* ptr, size_t n) {
        if (n != 1) return;
        
        Block* block = reinterpret_cast<Block*>(ptr);
        block->next = free_list;
        free_list = block;
    }
};

int main() {
    const size_t num_elements = 100000;
    
    // Timing standard allocator
    auto start = std::chrono::high_resolution_clock::now();
    
    std::vector<int, std::allocator<int>> vec1;
    for (size_t i = 0; i < num_elements; ++i) {
        vec1.push_back(i);
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    std::cout << name << " insertion time: " << duration.count() << " μs" << std::endl;
}

int main() {
    const size_t data_size = 10000;
    std::vector<int> test_data;
    test_data.reserve(data_size);
    
    // Generate random test data
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000);
    
    for (size_t i = 0; i < data_size; ++i) {
        test_data.push_back(dis(gen));
    }
    
    // Benchmark different containers
    std::vector<int> vec;
    vec.reserve(data_size);
    benchmark_insertion("Vector", vec, test_data);
    
    std::list<int> lst;
    benchmark_insertion("List", lst, test_data);
    
    std::deque<int> dq;
    benchmark_insertion("Deque", dq, test_data);
    
    return 0;
}
```

## Advanced STL Features

### Custom Comparators and Hash Functions

```cpp
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iostream>
#include <string>
#include <functional>

// Custom struct
struct Person {
    std::string name;
    int age;
    
    Person(const std::string& n, int a) : name(n), age(a) {}
};

// Custom comparator for set/map
struct PersonComparator {
    bool operator()(const Person& lhs, const Person& rhs) const {
        if (lhs.age != rhs.age) {
            return lhs.age < rhs.age;
        }
        return lhs.name < rhs.name;
    }
};

// Custom hash function for unordered containers
struct PersonHash {
    std::size_t operator()(const Person& p) const {
        return std::hash<std::string>{}(p.name) ^ 
               (std::hash<int>{}(p.age) << 1);
    }
};

// Custom equality for unordered containers
struct PersonEqual {
    bool operator()(const Person& lhs, const Person& rhs) const {
        return lhs.name == rhs.name && lhs.age == rhs.age;
    }
};

int main() {
    // Using custom comparator with set
    std::set<Person, PersonComparator> person_set;
    person_set.emplace("Alice", 30);
    person_set.emplace("Bob", 25);
    person_set.emplace("Charlie", 30);
    person_set.emplace("Alice", 25);
    
    std::cout << "Sorted persons (by age, then name):" << std::endl;
    for (const auto& person : person_set) {
        std::cout << person.name << " (" << person.age << ")" << std::endl;
    }
    
    // Using custom hash with unordered_set
    std::unordered_set<Person, PersonHash, PersonEqual> person_uset;
    person_uset.emplace("David", 35);
    person_uset.emplace("Eve", 28);
    person_uset.emplace("David", 35); // Duplicate, won't be added
    
    std::cout << "\nUnordered set persons:" << std::endl;
    for (const auto& person : person_uset) {
        std::cout << person.name << " (" << person.age << ")" << std::endl;
    }
    
    // Lambda comparator
    auto lambda_comp = [](const Person& lhs, const Person& rhs) {
        return lhs.name.length() < rhs.name.length();
    };
    
    std::set<Person, decltype(lambda_comp)> name_length_set(lambda_comp);
    name_length_set.emplace("Al", 20);
    name_length_set.emplace("Bob", 25);
    name_length_set.emplace("Alexander", 30);
    
    std::cout << "\nSorted by name length:" << std::endl;
    for (const auto& person : name_length_set) {
        std::cout << person.name << " (" << person.age << ")" << std::endl;
    }
    
    return 0;
}
```

### Template Metaprogramming with STL

```cpp
#include <type_traits>
#include <iostream>
#include <vector>
#include <list>
#include <string>

// SFINAE example - enable function only for integral types
template<typename T>
typename std::enable_if<std::is_integral<T>::value, T>::type
safe_add(T a, T b) {
    if (a > 0 && b > std::numeric_limits<T>::max() - a) {
        throw std::overflow_error("Addition overflow");
    }
    if (a < 0 && b < std::numeric_limits<T>::min() - a) {
        throw std::underflow_error("Addition underflow");
    }
    return a + b;
}

// Template specialization for different container types
template<typename Container>
void print_container_info(const Container& c) {
    std::cout << "Generic container with " << c.size() << " elements" << std::endl;
}

template<>
void print_container_info<std::vector<int>>(const std::vector<int>& c) {
    std::cout << "Vector<int> with " << c.size() << " elements, capacity: " 
              << c.capacity() << std::endl;
}

template<>
void print_container_info<std::list<int>>(const std::list<int>& c) {
    std::cout << "List<int> with " << c.size() << " elements (doubly-linked)" << std::endl;
}

// Concept-like template constraints (C++11 version using SFINAE)
template<typename T>
using has_push_back = decltype(std::declval<T>().push_back(std::declval<typename T::value_type>()));

template<typename Container>
auto add_element_if_possible(Container& c, typename Container::value_type value)
    -> decltype(c.push_back(value), void()) {
    c.push_back(value);
    std::cout << "Added element using push_back" << std::endl;
}

template<typename Container>
auto add_element_if_possible(Container& c, typename Container::value_type value)
    -> decltype(c.insert(value), void()) {
    c.insert(value);
    std::cout << "Added element using insert" << std::endl;
}

int main() {
    // Type traits examples
    std::cout << "Is int integral? " << std::is_integral<int>::value << std::endl;
    std::cout << "Is float integral? " << std::is_integral<float>::value << std::endl;
    std::cout << "Is string arithmetic? " << std::is_arithmetic<std::string>::value << std::endl;
    
    // SFINAE function
    try {
        int result = safe_add(5, 10);
        std::cout << "Safe add result: " << result << std::endl;
        
        // This would cause compilation error:
        // safe_add(3.14, 2.71); // Error: not integral type
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Template specialization
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::list<int> lst = {1, 2, 3};
    std::vector<std::string> str_vec = {"hello", "world"};
    
    print_container_info(vec);
    print_container_info(lst);
    print_container_info(str_vec);
    
    return 0;
}
```

### Exception Safety and RAII

```cpp
#include <iostream>
#include <memory>
#include <vector>
#include <stdexcept>
#include <fstream>

// RAII wrapper for file handling
class FileGuard {
private:
    std::FILE* file_;
    
public:
    explicit FileGuard(const char* filename, const char* mode) 
        : file_(std::fopen(filename, mode)) {
        if (!file_) {
            throw std::runtime_error("Failed to open file");
        }
    }
    
    ~FileGuard() {
        if (file_) {
            std::fclose(file_);
        }
    }
    
    // Delete copy constructor and assignment
    FileGuard(const FileGuard&) = delete;
    FileGuard& operator=(const FileGuard&) = delete;
    
    // Move constructor and assignment
    FileGuard(FileGuard&& other) noexcept : file_(other.file_) {
        other.file_ = nullptr;
    }
    
    FileGuard& operator=(FileGuard&& other) noexcept {
        if (this != &other) {
            if (file_) {
                std::fclose(file_);
            }
            file_ = other.file_;
            other.file_ = nullptr;
        }
        return *this;
    }
    
    std::FILE* get() const { return file_; }
    
    explicit operator bool() const { return file_ != nullptr; }
};

// Exception-safe vector operations
class SafeVector {
private:
    std::vector<int> data_;
    
public:
    // Strong exception safety guarantee
    void safe_resize_and_fill(size_t new_size, int value) {
        std::vector<int> temp = data_; // Copy current data
        temp.resize(new_size, value);  // May throw
        data_ = std::move(temp);       // No-throw move
    }
    
    // Basic exception safety
    void push_back_safe(int value) {
        try {
            data_.push_back(value);
        } catch (...) {
            // Log error or cleanup if needed
            throw; // Re-throw
        }
    }
    
    // No-throw guarantee
    size_t size() const noexcept {
        return data_.size();
    }
    
    void print() const {
        std::cout << "Vector contents: ";
        for (const auto& item : data_) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
};

// Custom exception class
class CustomException : public std::exception {
private:
    std::string message_;
    
public:
    explicit CustomException(const std::string& message) : message_(message) {}
    
    const char* what() const noexcept override {
        return message_.c_str();
    }
};

int main() {
    // RAII file handling
    try {
        FileGuard file("test.txt", "w");
        if (file) {
            std::fprintf(file.get(), "Hello, RAII!\n");
            std::fprintf(file.get(), "File will be automatically closed.\n");
        }
        // File automatically closed when FileGuard goes out of scope
    } catch (const std::exception& e) {
        std::cout << "File error: " << e.what() << std::endl;
    }
    
    // Exception-safe operations
    SafeVector safe_vec;
    
    try {
        safe_vec.push_back_safe(1);
        safe_vec.push_back_safe(2);
        safe_vec.push_back_safe(3);
        safe_vec.print();
        
        safe_vec.safe_resize_and_fill(10, 42);
        safe_vec.print();
        
        // Simulate an exception
        throw CustomException("Simulated error");
        
    } catch (const CustomException& e) {
        std::cout << "Custom exception caught: " << e.what() << std::endl;
        std::cout << "Vector size after exception: " << safe_vec.size() << std::endl;
    }
    
    // Smart pointer RAII
    {
        auto ptr = std::make_unique<int[]>(1000);
        // Memory automatically freed when ptr goes out of scope
        std::cout << "Large array allocated and will be automatically freed" << std::endl;
    }
    
    return 0;
}
```

## Key Takeaways and Best Practices

### Performance Guidelines

1. **Choose the right container:**
   - `vector`: Random access, cache-friendly, prefer for most cases
   - `list`: Frequent insertion/deletion in middle, no random access needed
   - `deque`: Insertion/deletion at both ends
   - `set/map`: Sorted data, O(log n) operations
   - `unordered_set/map`: Fast lookup, O(1) average case

2. **Reserve capacity** for vectors when size is known
3. **Use const references** in range-based for loops for non-trivial types
4. **Prefer algorithms** over hand-written loops
5. **Use move semantics** for expensive-to-copy objects

### Memory Management Best Practices

1. **Prefer smart pointers** over raw pointers
2. **Use RAII** for resource management
3. **Avoid memory leaks** with proper exception handling
4. **Consider custom allocators** for performance-critical code

### Modern C++ Features Integration

1. **Auto keyword** for type deduction
2. **Range-based for loops** for cleaner iteration
3. **Lambda functions** with algorithms
4. **Move semantics** for performance
5. **Smart pointers** for memory safety

This comprehensive guide covers the essential aspects of C++ STL, Standard Library, and core features with practical examples and best practices for efficient C++ programming.chrono::high_resolution_clock::now();
    auto standard_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    // Timing pool allocator
    start = std::chrono::high_resolution_clock::now();
    
    std::vector<int, PoolAllocator<int>> vec2;
    for (size_t i = 0; i < num_elements; ++i) {
        vec2.push_back(i);
    }
    
    end = std::chrono::high_resolution_clock::now();
    auto pool_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    std::cout << "Standard allocator time: " << standard_time.count() << " μs" << std::endl;
    std::cout << "Pool allocator time: " << pool_time.count() << " μs" << std::endl;
    
    return 0;
}
```

## Input/Output Streams

### File I/O and String Streams

```cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

int main() {
    // Writing to file
    std::ofstream output_file("example.txt");
    if (output_file.is_open()) {
        output_file << "Hello, World!" << std::endl;
        output_file << "Line 2" << std::endl;
        output_file << "Numbers: " << 42 << " " << 3.14 << std::endl;
        output_file.close();
    }
    
    // Reading from file
    std::ifstream input_file("example.txt");
    if (input_file.is_open()) {
        std::string line;
        while (std::getline(input_file, line)) {
            std::cout << "Read: " << line << std::endl;
        }
        input_file.close();
    }
    
    // String streams for parsing
    std::string data = "John 25 Engineer 75000.50";
    std::istringstream iss(data);
    
    std::string name, profession;
    int age;
    double salary;
    
    iss >> name >> age >> profession >> salary;
    
    std::cout << "Parsed data:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Profession: " << profession << std::endl;
    std::cout << "Salary: $" << std::fixed << std::setprecision(2) << salary << std::endl;
    
    // Using stringstream for formatting
    std::ostringstream oss;
    oss << "Employee: " << name << ", Age: " << age 
        << ", Salary: $" << std::fixed << std::setprecision(2) << salary;
    
    std::cout << "Formatted: " << oss.str() << std::endl;
    
    // CSV parsing example
    std::string csv_line = "Apple,5,2.50,Fruit";
    std::istringstream csv_stream(csv_line);
    std::vector<std::string> tokens;
    std::string token;
    
    while (std::getline(csv_stream, token, ',')) {
        tokens.push_back(token);
    }
    
    std::cout << "CSV tokens: ";
    for (const auto& t : tokens) {
        std::cout << "[" << t << "] ";
    }
    std::cout << std::endl;
    
    return 0;
}
```

## String Handling

### Advanced String Operations

```cpp
#include <string>
#include <iostream>
#include <algorithm>
#include <regex>
#include <sstream>

int main() {
    std::string text = "  Hello, World! This is a sample text.  ";
    
    // Basic string operations
    std::cout << "Original: '" << text << "'" << std::endl;
    std::cout << "Length: " << text.length() << std::endl;
    
    // Trimming whitespace
    auto trim_left = [](std::string& s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                [](unsigned char ch) { return !std::isspace(ch); }));
    };
    
    auto trim_right = [](std::string& s) {
        s.erase(std::find_if(s.rbegin(), s.rend(),
                [](unsigned char ch) { return !std::isspace(ch); }).base(), s.end());
    };
    
    std::string trimmed = text;
    trim_left(trimmed);
    trim_right(trimmed);
    std::cout << "Trimmed: '" << trimmed << "'" << std::endl;
    
    // String searching
    size_t pos = trimmed.find("World");
    if (pos != std::string::npos) {
        std::cout << "Found 'World' at position: " << pos << std::endl;
    }
    
    // String replacement
    std::string replaced = trimmed;
    std::string::size_type start_pos = 0;
    while ((start_pos = replaced.find("sample", start_pos)) != std::string::npos) {
        replaced.replace(start_pos, 6, "example");
        start_pos += 7;
    }
    std::cout << "Replaced: " << replaced << std::endl;
    
    // Regular expressions
    std::regex word_regex(R"(\b\w+\b)");
    std::sregex_iterator words_begin(trimmed.begin(), trimmed.end(), word_regex);
    std::sregex_iterator words_end;
    
    std::cout << "Words: ";
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::cout << "'" << (*i).str() << "' ";
    }
    std::cout << std::endl;
    
    // Email validation with regex
    std::regex email_regex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    std::vector<std::string> emails = {
        "user@example.com",
        "invalid.email",
        "test@domain.org",
        "not_an_email"
    };
    
    std::cout << "Valid emails:" << std::endl;
    for (const auto& email : emails) {
        if (std::regex_match(email, email_regex)) {
            std::cout << "  " << email << std::endl;
        }
    }
    
    return 0;
}
```

## Utilities

### Utility Classes and Functions

```cpp
#include <utility>
#include <tuple>
#include <optional>
#include <variant>
#include <any>
#include <iostream>
#include <string>
#include <vector>

// Function returning multiple values using tuple
std::tuple<std::string, int, double> get_person_info() {
    return std::make_tuple("Alice", 30, 75000.0);
}

// Function that might fail
std::optional<int> safe_divide(int a, int b) {
    if (b == 0) {
        return std::nullopt;
    }
    return a / b;
}

int main() {
    // Pair
    std::pair<std::string, int> name_age("Bob", 25);
    std::cout << "Name: " << name_age.first << ", Age: " << name_age.second << std::endl;
    
    // Tuple
    auto [name, age, salary] = get_person_info(); // Structured binding (C++17)
    std::cout << "Person: " << name << ", " << age << " years old, $" << salary << std::endl;
    
    // Alternative tuple access
    auto person_info = get_person_info();
    std::cout << "Name: " << std::get<0>(person_info) << std::endl;
    std::cout << "Age: " << std::get<1>(person_info) << std::endl;
    std::cout << "Salary: " << std::get<2>(person_info) << std::endl;
    
    // Optional
    auto result1 = safe_divide(10, 2);
    auto result2 = safe_divide(10, 0);
    
    if (result1.has_value()) {
        std::cout << "10 / 2 = " << result1.value() << std::endl;
    }
    
    if (!result2) {
        std::cout << "Division by zero detected" << std::endl;
    }
    
    // Optional with default value
    std::cout << "Result with default: " << result2.value_or(-1) << std::endl;
    
    // Variant (type-safe union)
    std::variant<int, double, std::string> data;
    
    data = 42;
    std::cout << "Variant holds int: " << std::get<int>(data) << std::endl;
    
    data = 3.14;
    std::cout << "Variant holds double: " << std::get<double>(data) << std::endl;
    
    data = std::string("Hello");
    std::cout << "Variant holds string: " << std::get<std::string>(data) << std::endl;
    
    // Visitor pattern with variant
    std::visit([](const auto& value) {
        std::cout << "Visited value: " << value << std::endl;
    }, data);
    
    // Any (type-erased container)
    std::any anything;
    
    anything = 42;
    std::cout << "Any holds: " << std::any_cast<int>(anything) << std::endl;
    
    anything = std::string("World");
    std::cout << "Any holds: " << std::any_cast<std::string>(anything) << std::endl;
    
    // Check type
    if (anything.type() == typeid(std::string)) {
        std::cout << "Any currently holds a string" << std::endl;
    }
    
    return 0;
}
```

## Performance Considerations and Best Practices

### Container Performance Comparison

```cpp
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <unordered_set>
#include <chrono>
#include <iostream>
#include <random>

template<typename Container>
void benchmark_insertion(const std::string& name, Container& container, 
                        const std::vector<int>& data) {
    auto start = std::chrono::high_resolution_clock::now();
    
    for (const auto& value : data) {
        container.insert(container.end(), value);
    }
    
    auto end = std::
```  
--- 
### Key Takeaways and Best Practices

Performance guidelines for container selection
Memory management best practices
Modern C++ features integration

The guide now provides a complete reference covering:

#### All major STL containers with detailed examples
Iterator concepts and usage patterns
Algorithm library with practical applications
Function objects and lambda expressions
Smart pointers and memory management
Concurrency features (threads, futures, atomics)
I/O streams and file handling
String processing with regex support
Utility classes (optional, variant, any, tuple)
Advanced template techniques
Exception safety and RAII patterns
Performance optimization strategies

Each section includes working code examples that demonstrate real-world usage patterns and best practices for modern C++ development.