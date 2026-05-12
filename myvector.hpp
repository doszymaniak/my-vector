#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

#include <stddef.h>
#include <string>

template<typename T>
class MyVector {
private:
    size_t size;
    size_t capacity;
    T *vec;
public:
    void print(const std::string &label) const;

    // Constructors
    MyVector(size_t cap);
    MyVector();
    MyVector(const MyVector &other);
    MyVector(MyVector &&other);

    // Destructor
    ~MyVector();

    // Operators
    MyVector &operator=(const MyVector &other);
    MyVector &operator=(MyVector &&other);

    // Other
    void reallocate(size_t min_cap);
    void push_back(const T &el);
    void pop_back();
    void reserve(size_t n);
};

#include "myvector.tpp"

#endif