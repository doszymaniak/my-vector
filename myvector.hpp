#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

#include <stddef.h>
#include <string>

template<typename T>
class MyVector {
private:
    size_t m_size;
    size_t m_capacity;
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
    T &operator[](size_t idx);
    const T &operator[](size_t idx) const;

    // Other
    void reallocate(size_t min_cap);
    void push_back(const T &el);
    void pop_back();
    void reserve(size_t n);
    void resize(size_t n, const T &val);
    T &at(size_t idx);
    const T &at(size_t idx) const;
    size_t size() const;
    size_t capacity() const;
    bool empty() const;
};

#include "myvector.tpp"

#endif