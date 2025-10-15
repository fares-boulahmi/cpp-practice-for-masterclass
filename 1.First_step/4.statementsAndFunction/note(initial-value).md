Excellent question — you're noticing an **important C++ behavior**: **uninitialized variables have undefined values**, and that's why your function gives **random results** when you write:

```cpp
int result; // ❌ No initial value (undefined)
```

---

### 🔍 Let’s break it down

In this code:

```cpp
int result; // UNINITIALIZED — garbage value!
for (int i = 0; i < arr.size(); i++) {
    result += arr[i]; // adding to garbage = wrong total
}
```

You're adding values to `result`, but `result` is **never initialized**, so it starts with a **random value already in memory** (called *garbage* or *undefined behavior*). You're essentially doing:

```cpp
int result = ???; // maybe 32891 or -10483
result += 1;
result += 5;
...
```

So your sum is completely wrong.

---

### ✅ Correct version:

```cpp
int result = 0; // Proper initialization
```

This way, it starts at zero and accumulates correctly.

---

### 🧠 Why C++ does this:

C++ is designed for **maximum performance** and doesn’t automatically zero-initialize local variables (unless they're in global scope or marked `static`). This is **different from some other languages** like:

* Python: variables are initialized only when you assign
* JavaScript: variables get `undefined`
* Java: variables inside classes are default-initialized (e.g., `0` for int)

But in **C++**, local variables like:

```cpp
int x;
```

are **not** initialized automatically. If you don’t assign a value, it contains *whatever was in that memory location before* — that’s why you get garbage values.

---

### ✅ Summary:

| Code              | Behavior                                               |
| ----------------- | ------------------------------------------------------ |
| `int result;`     | ❌ Undefined (random) value — leads to incorrect result |
| `int result = 0;` | ✅ Starts from 0 — correct accumulation in loop         |

---

If you want safety, always **initialize your variables** before use.

Let me know if you want a version using modern C++ (like `std::accumulate`).
