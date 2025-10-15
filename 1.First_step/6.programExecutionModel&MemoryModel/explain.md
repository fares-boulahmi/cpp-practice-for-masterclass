## ✅ 1. **Program Execution Model** (C++ — Simplified)

This is about **how your C++ code is executed** — the flow from start to end.

### 🔹 Basic Flow:

```cpp
int main() {
    // Code runs from top to bottom
    return 0;
}
```

* Execution **starts** in the `main()` function.
* Instructions run **one after the other**, **line by line**, unless you use loops or function calls.
* When you call a function, the program **jumps** to that function, runs it, then comes back.

### 🔹 Function Calls (Stack behavior):

Each time you call a function, the system:

* **Creates a frame** on the **call stack** (to store local variables, return address).
* Runs the function.
* **Pops the frame** when the function finishes.

🧠 **Why it matters in DSA**:

* **Recursion** relies on this model.
* Stack overflow errors happen if you recurse too deep (too many frames).

---

## ✅ 2. **Memory Model** (C++ — Simplified)

This tells us how memory is **divided** and **used** in a program.

### 🔹 4 Key Memory Areas:

| Area          | Use                                     | Example                        |
| ------------- | --------------------------------------- | ------------------------------ |
| **Stack**     | Stores local variables & function calls | `int x = 5;` inside a function |
| **Heap**      | Stores dynamic memory (manual control)  | `int* p = new int;`            |
| **Data**      | Global/static variables (initialized)   | `static int x = 10;`           |
| **Text/Code** | The actual machine code                 | All your compiled functions    |

---

### 🔹 Example:

```cpp
int globalVar = 10; // in Data section

void test() {
    int x = 5; // Stack
    int* p = new int(20); // Heap
}
```

### 🔹 Heap vs Stack (Quick difference):

| Feature  | Stack                      | Heap                        |
| -------- | -------------------------- | --------------------------- |
| Speed    | Fast                       | Slower                      |
| Lifespan | Auto (ends after function) | Manual (needs `delete`)     |
| Use case | Local vars, recursion      | Big arrays, dynamic storage |

🧠 **Why it matters in DSA**:

* Dynamic arrays, linked lists, trees often use the **heap**.
* Stack is used in **recursive algorithms**.
* Knowing this helps avoid memory leaks (`delete` or `smart pointers`).

---

## 🧠 Summary for DSA Use:

| Concept           | Key Takeaway for DSA                         |
| ----------------- | -------------------------------------------- |
| Program Execution | Code runs top to bottom; functions use stack |
| Stack Memory      | Local variables, function calls              |
| Heap Memory       | Use `new` for dynamic structures             |
| Memory Management | Don't forget `delete` if using raw pointers  |
| Recursion         | Uses the call stack                          |

