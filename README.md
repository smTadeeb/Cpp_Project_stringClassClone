# Custom C++ String Class (STR)

This project implements a custom `STR` class in C++ that mimics the functionality of the standard `std::string`, providing dynamic memory management, operator overloading, and deep copy/move semantics. It is designed for educational purposes to understand the internals of how strings and resource management work in C++.

---

## Features

- ✅ **Dynamic memory management** using raw pointers (`char*`)
- ✅ **Constructors**:
  - Default constructor
  - Parameterized constructor (from `const char*`)
  - Copy constructor
  - Move constructor
- ✅ **Assignment operators**:
  - Copy assignment
  - Move assignment
  - Assignment from C-string
- ✅ **Comparison operators**:
  - `<`, `<=`, `>`, `>=`, `==`, `!=`
- ✅ **Concatenation support** via `operator+`
- ✅ **Safe memory release** with destructor
- ✅ **Friend function `operator<<`** to support easy printing with `cout`

---

## Usage

Include the `STR` class implementation in your C++ project, compile it with any standard C++ compiler (e.g., g++, clang++), and start using `STR` objects just like `std::string`.

### Example:

```cpp
#include <iostream>
using namespace std;

int main() {
    STR a("Hello");
    STR b("World");
    STR c = a + b;

    cout << "Combined: " << c << endl;

    if (a < b) {
        cout << "a is less than b" << endl;
    }

    return 0;
}
```
## Notes
All heap allocations are manually managed.
Every copy or move operation ensures deep copy to avoid memory leaks or dangling pointers.
operator+ modifies a copy of the first operand (*this) and concatenates the second string to it. It returns the result by value.
Error checking is in place for null pointers and memory allocation failures.

## Known Limitations
operator+ uses strcat which requires pre-allocated memory, but currently doesn’t allocate extra space—this may cause undefined behavior. Should be fixed in future versions.
No bounds checking or exception safety.
operator== incorrectly returns 0 when both strings are NULL—this may be logically flawed depending on intended semantics.

## Future Improvements
Add bounds-safe character access (like operator[]).
Implement a custom strlen and strcpy to avoid using <cstring>.
Support Unicode/UTF-8.
Add input support via istream operator overload (operator>>).
Introduce exception-safe memory handling using smart pointers (e.g., std::unique_ptr).

## Author
This class was written from scratch as a hands-on exploration into C++ memory handling, deep copy/move semantics, and operator overloading.
It serves as a building block for deeper understanding of the internals behind the STL string class.

