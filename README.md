# cpp-vector-implementation
This is my custom implementation of a dynamic array in C++, inspired by std::vector from STL. I created it for learning purposes, to deepen my understanding of how to manually manage memory and practice implementing the Rule of Five.
## Features
It supports all the basic functionalities:
- dynamic memory management using raw pointers,
- copy constructor and move constructor,
- copy assignment and move assignment,
- push_back() / pop_back(),
- reserve(), resize(), reallocate(),
- element access via [] operator and at(),
- iterators (begin(), end()),
- basic unit testing using assertions
## How to build
Build the project using any modern C++ compiler
```bash
g++ -std=c++23 -Wall -Wextra -pedantic -O3 tests.cpp -o test
```
Run the program
```bash
./test
```