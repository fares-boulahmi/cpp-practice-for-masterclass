Great questions! Let’s break them down clearly and simply so you can understand each part in C++:

---

### 🔹 1. What does `auto` mean in C++?

`auto` **automatically detects the variable type** based on what you assign to it.

#### Example:

```cpp
auto x = 5;  // Compiler sees this and understands: x is an int
auto y = 3.14;  // y is a double
auto name = "Fares";  // name is a const char*
```

So this line:

```cpp
auto end = std::chrono::high_resolution_clock::now();
```

means:

> "Let the compiler figure out what type `end` is, based on the return value of `now()`."

In this case, `now()` returns a time\_point type, but writing the full type would be long:

```cpp
std::chrono::time_point<std::chrono::high_resolution_clock> end;
```

So `auto` saves typing and avoids mistakes.

---

### 🔹 2. Why is `main()` declared as `int main()` instead of `void main()`?

In standard C++, `main` **must** return `int` because it tells the operating system **whether the program ran successfully or not**.

```cpp
int main() {
    // code here
    return 0;  // 0 means success
}
```

Even if you don’t write `return 0;`, many compilers will add it for you. But **you should always write it for good practice.**

✅ `int main()` → standard and correct
❌ `void main()` → not standard, only works in some compilers

---

### 🔹 3. Why do some functions use `void` instead of `int` or another type?

`void` means **the function doesn't return anything**.

#### Example:

```cpp
void sayHello() {
    std::cout << "Hello!\n";
}
```

This function **does something** (prints "Hello") but **returns nothing**.

Compare that to:

```cpp
int add(int a, int b) {
    return a + b;
}
```

This one **returns a value** (the sum).

---

### 🔸 Summary:

| Keyword      | Meaning                                           |
| ------------ | ------------------------------------------------- |
| `auto`       | Let the compiler choose the type automatically    |
| `int main()` | Standard way to start a program, returns 0 if OK  |
| `void`       | Used for functions that **do not return a value** |

---

If you want, I can show some short full examples for each. Let me know!
