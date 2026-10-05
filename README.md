*This project has been created as part of the 42 curriculum by vpoka.*

# CPP07 — Templates

A C++98 project from the 42 curriculum focused on C++ templates: function templates, generic traversal of arrays, and a fully fledged class template.

## Table of contents

- [Description](#description)
- [Instructions](#instructions)
- [Resources](#resources)
- [What this project demonstrates](#what-this-project-demonstrates)
- [Technical constraints](#technical-constraints)
- [Repository structure](#repository-structure)
- [Focus areas by exercise](#focus-areas-by-exercise)
- [Testing](#testing)
- [Status](#status)

## Description

CPP07 is the 42 C++ module dedicated to templates. Instead of writing a new class or function for every type, the exercises build generic code that works with any type, while keeping the strict C++98 rules of the Common Core. The module exists to anchor the language's compile-time generic programming features before moving on to the STL in later modules.

This module is split into three exercises:

* **ex00 — Start with a few functions**
  Implement the `swap`, `min`, and `max` function templates in a single header, usable with any type that supports comparison.
* **ex01 — Iter**
  Write a generic `iter` function template that applies any function — including an instantiated function template — to every element of an array.
* **ex02 — Array**
  Build the `Array<T>` class template: a dynamically allocated, bounds-checked array with deep-copy semantics, `size()`, and out-of-bounds detection.

| Exercise | Executable | Key files |
| --- | --- | --- |
| [ex00](ex00/) — Start with a few functions | `ex00` | `whatever.hpp` (`swap`, `min`, `max`) |
| [ex01](ex01/) — Iter | `ex01` | `iter.hpp` (`iter`, `print`) |
| [ex02](ex02/) — Array | `ex02` | `Array.hpp`, `Array.tpp` (`Array<T>`) |

## Instructions

### Prerequisites

- A C++ compiler available as `c++`, supporting `-std=c++98`.
- GNU Make and standard Unix shell utilities. The Makefiles compile with `-Wall -Wextra -Werror -std=c++98`; no external libraries are required.
- The repository and the subject specify no minimum compiler or Make versions.

### Build

Run these commands from the repository root. Each exercise has its own Makefile; there is no root Makefile.

```bash
make -C ex00
make -C ex01
make -C ex02
```

Each Makefile provides `all`, `clean` (remove build files), `fclean` (also remove the executable), `re` (rebuild), `debug` (rebuild with `-g -DDEBUG`), and `run` (rebuild and execute). For example:

```bash
make -C ex00 clean
make -C ex01 fclean
make -C ex02 re
make -C ex00 run
```

Objects are compiled into `exNN/build/` and linked into an executable named after the exercise (`ex00`, `ex01`, `ex02`). In ex02 the `debug` flags additionally enable AddressSanitizer (`-fsanitize=address`); in ex00 and ex01 `debug` only adds `-g -DDEBUG`.

### ex00 — Start with a few functions

From the repository root:

```bash
./ex00/ex00
```

`whatever.hpp` defines the three function templates in the global namespace: `swap` exchanges two values of the same type, `min` and `max` compare them. When both values are equal, `min`/`max` return the second one, as the subject requires. Both arguments of a call must have the same type and support the comparison operators.

The executable takes no arguments. Its `main.cpp` reproduces the subject's sample and prints:

```text
a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine2, d = chaine1
min(c, d) = chaine1
max(c, d) = chaine2
```

### ex01 — Iter

From the repository root:

```bash
./ex01/ex01
```

`iter` takes three parameters: the address of an array, its length as a `const` value, and a callable applied to every element. The callable parameter is a deduced template parameter, so plain functions (`add`, `subtract` in `main.cpp`) and instantiated function templates (`print<int>`) both work, and elements can be taken by const or non-const reference. A null array or a length of zero is a no-op.

The executable takes no arguments and runs five tests: an `int` array (printed, incremented, printed again), a `char` array (printed, decremented, printed again), a `std::string` array, an empty array, and a null array.

### ex02 — Array

From the repository root:

```bash
./ex02/ex02
```

`Array<T>` stores `size_` elements in a `data_` block allocated with `new T[n]`. The default constructor creates an empty array, `Array<unsigned int n>` creates `n` default-initialized elements, and copy construction and assignment produce deep copies, so later modifications never leak between an array and its copies. Elements are accessed with `operator[]` (const and non-const flavours); an out-of-bounds index throws `std::exception`. A `size()` member returns the number of elements without modifying the instance.

The executable takes no arguments and runs four tests: a default-initialized `Array<int>(5)`, the same through a `const` instance, a deep-copy scenario over `Array<std::string>` using both the copy constructor and the assignment operator, and an out-of-bounds access that reports the caught exception on standard error.

None of the three executables accepts command-line arguments, and there is no configuration and no environment variables.

## Resources

- cppreference — [Templates](https://en.cppreference.com/w/cpp/language/templates) and [Class template](https://en.cppreference.com/w/cpp/language/class_template): the language features used throughout the module.
- cppreference — [`operator new[]`](https://en.cppreference.com/w/cpp/memory/new/operator_new) and [`std::exception`](https://en.cppreference.com/w/cpp/error/exception): allocation and error reporting used by `Array<T>`.
- **David Vandevoorde, Nicolai M. Josuttis, and Douglas Gregor, *C++ Templates: The Complete Guide*** — the standard book-length treatment of templates.
- **GNU Make manual** (https://www.gnu.org/software/make/manual/make.html): targets, automatic variables, and pattern rules.

### AI usage

AI was used to help write and improve this README and project documentation, prepare commits, and, where output or data visualisation is more complex, tweak that output.

## What this project demonstrates

* Function templates and class templates written once and usable with any type
* Template definitions kept in headers — the subject's single exception to its "no implementations in headers" rule
* Orthodox Canonical Form applied to a class template that manages dynamic memory
* Deep-copy semantics, bounds checking, and exception-based error reporting
* Self-contained headers protected against double inclusion
* C++98 code under `-Wall -Wextra -Werror -std=c++98`

## Technical constraints

This project is developed under the 42 C++ module rules:

* Standard: **C++98** — the code must still compile with the `-std=c++98` flag
* Compiler flags: **`-Wall -Wextra -Werror`**
* No external libraries: C++11 (and derived forms) and Boost are forbidden, as are `*printf()`, `*alloc()` and `free()`
* `using namespace` and `friend` are forbidden unless an exercise states otherwise
* STL containers and algorithms are forbidden in this module (allowed from Module 08 on)
* No memory leaks: the `new[]` allocations in `Array<T>` must be matched by `delete[]`
* Classes follow the **Orthodox Canonical Form** (Modules 02–09)
* Any function implementation in a header is forbidden **except for function templates**
* Headers must be usable on their own and guarded against double inclusion
* Exercise directories are named `ex00`, `ex01`, `ex02`; every output message ends with a newline

## Repository structure

```text
cpp07/
├── README.md
├── ex00/   # Start with a few functions: main.cpp, whatever.hpp, Makefile
├── ex01/   # Iter: main.cpp, iter.hpp, Makefile
└── ex02/   # Array: main.cpp, Array.hpp, Array.tpp, Makefile
```

## Focus areas by exercise

### ex00 — Start with a few functions

* `swap`, `min`, and `max` as function templates defined in `whatever.hpp`
* Tie-breaking rule: equal values return the second argument
* Template deduction enforcing that both arguments share one type

### ex01 — Iter

* A three-parameter `iter` (array, length, callable) returning nothing
* Support for plain functions and instantiated function templates alike
* Const and non-const element references in the callable
* Defensive handling of null arrays and zero lengths

### ex02 — Array

* Class template `Array<T>` in Orthodox Canonical Form: default, `unsigned int n`, copy, assignment, destructor
* Memory allocated with `new T[n]` and elements initialized to `T()`; no preventive allocation
* Const and non-const `operator[]` with an `std::exception` on out-of-bounds access
* Deep copies that keep an array and its duplicates independent
* `size()` as a constant member function

## Testing

There are no separate test scripts; as the subject requires, each exercise ships a `main.cpp` test program that doubles as its test suite:

```bash
make -C ex00 && ./ex00/ex00
make -C ex01 && ./ex01/ex01
make -C ex02 && ./ex02/ex02
```

* ex00 reproduces the subject's sample with `int` and `std::string` values.
* ex01 covers `int`, `char`, and `std::string` arrays, an empty array, a null array, and callables taking const and non-const references.
* ex02 covers default-initialized elements, access through a `const` instance, deep copies via copy constructor and assignment, and an out-of-bounds access that is caught and reported.

`make -C ex02 debug` also prints construction/destruction traces (`DEBUG_MSG`) and runs the suite under AddressSanitizer.

## Status

* **Status:** Completed
* **Final grade:** **100/100 points**
