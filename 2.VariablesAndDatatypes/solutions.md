Great! Here's a clean **solution set** for the 10 mini DSA-style C++ challenges using only basic knowledge: **variables, loops, conditionals, vectors, and strings**.

---

## ✅ 1. **Second Largest Element**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {10, 20, 5, 8, 40};
    int max1 = INT_MIN, max2 = INT_MIN;
    
    for (int num : arr) {
        if (num > max1) {
            max2 = max1;
            max1 = num;
        } else if (num > max2 && num < max1) {
            max2 = num;
        }
    }
    
    cout << "Second largest: " << max2 << endl;
    return 0;
}
```

---

## ✅ 2. **Reverse Vector In-Place**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    
    for (int i = 0; i < n / 2; i++) {
        swap(arr[i], arr[n - 1 - i]);
    }

    for (int num : arr) cout << num << " ";
    return 0;
}
```

---

## ✅ 3. **Check If Sorted (Ascending)**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4};
    bool isSorted = true;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) {
            isSorted = false;
            break;
        }
    }

    cout << (isSorted ? "Yes" : "No") << endl;
    return 0;
}
```

---

## ✅ 4. **Merge Two Sorted Arrays**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a = {1, 3, 5}, b = {2, 4, 6}, result;
    int i = 0, j = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) result.push_back(a[i++]);
        else result.push_back(b[j++]);
    }

    while (i < a.size()) result.push_back(a[i++]);
    while (j < b.size()) result.push_back(b[j++]);

    for (int num : result) cout << num << " ";
    return 0;
}
```

---

## ✅ 5. **Count Frequency of Element**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 3, 2, 3, 4, 3};
    int x, count = 0;
    cin >> x;

    for (int num : arr) {
        if (num == x) count++;
    }

    cout << "Frequency of " << x << ": " << count << endl;
    return 0;
}
```

---

## ✅ 6. **Print Unique Elements**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 2, 3, 4, 4, 5};

    for (int i = 0; i < arr.size(); i++) {
        int count = 0;
        for (int j = 0; j < arr.size(); j++) {
            if (arr[i] == arr[j]) count++;
        }
        if (count == 1) cout << arr[i] << " ";
    }

    return 0;
}
```

---

## ✅ 7. **Check Palindrome (Vector)**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 2, 1};
    bool isPalin = true;

    for (int i = 0; i < arr.size() / 2; i++) {
        if (arr[i] != arr[arr.size() - 1 - i]) {
            isPalin = false;
            break;
        }
    }

    cout << (isPalin ? "Palindrome" : "Not Palindrome") << endl;
    return 0;
}
```

---

## ✅ 8. **Find Missing Number**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 4, 5};
    int n = 5;
    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;

    for (int num : arr) actualSum += num;

    cout << "Missing number: " << (expectedSum - actualSum) << endl;
    return 0;
}
```

---

## ✅ 9. **First Non-Repeating Character**

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "aabbcdeff";

    for (int i = 0; i < s.length(); i++) {
        bool unique = true;
        for (int j = 0; j < s.length(); j++) {
            if (i != j && s[i] == s[j]) {
                unique = false;
                break;
            }
        }
        if (unique) {
            cout << "First non-repeating: " << s[i] << endl;
            break;
        }
    }

    return 0;
}
```

---

## ✅ 10. **String Compression**

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "aaabbbbcc", compressed = "";
    int count = 1;

    for (int i = 1; i <= s.length(); i++) {
        if (s[i] == s[i - 1]) {
            count++;
        } else {
            compressed += s[i - 1];
            compressed += to_string(count);
            count = 1;
        }
    }

    cout << compressed << endl;
    return 0;
}
```

