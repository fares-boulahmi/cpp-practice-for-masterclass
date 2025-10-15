`std::endl` is part of the C++ Standard Library and is used primarily with output streams like `std::cout`.

---

### 🔍 **What it Does Exactly**

```cpp
std::endl
```

**does two things**:

1. **Inserts a newline character** (`'\n'`) into the output stream (like pressing "Enter" on the keyboard).
2. **Flushes the output buffer** (forces the program to immediately write all pending output to the screen or destination).

---

### 🧪 Example

```cpp
#include <iostream>

int main() {
    std::cout << "Hello";
    std::cout << std::endl;
    std::cout << "World";
    return 0;
}
```

Output:

```
Hello
World
```

Compare with:

```cpp
std::cout << "Hello\n"; // Only inserts newline, does NOT flush
```

Both produce the same visible output, **but** `std::endl` ensures the output buffer is flushed immediately — useful in some real-time applications like logging or debugging.

---

### 🧠 Why flushing matters

By default, `std::cout` is buffered — meaning it collects output in memory and prints it in chunks (for performance). If the program crashes or pauses, you might not see the output unless it's flushed.

So:

* `std::cout << '\n';` = Just newline (buffer may not flush).
* `std::cout << std::endl;` = Newline **+** flush buffer.

---

### 📚 Official Source

From the [C++ reference](https://en.cppreference.com/w/cpp/io/manip/endl):

> `std::endl` inserts a newline character into the output sequence **and flushes the output buffer**.

---

### ⚠️ Performance Note

In **performance-critical loops**, prefer `'\n'` over `std::endl` if you don’t need flushing — flushing is **slower**.

```cpp
// Slower
for (int i = 0; i < 1000; ++i)
    std::cout << i << std::endl;

// Faster
for (int i = 0; i < 1000; ++i)
    std::cout << i << '\n';
```

---

Let me know if you want a code demo showing the difference with/without flushing!
