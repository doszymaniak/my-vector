#include <iostream>

using namespace std;

template <typename T>
void MyVector<T>::print(const string &label) const
{
    cout << label;
    for (size_t i = 0; i < size; i++) cout << vec[i] << " ";
    cout << '\n';
}

template <typename T>
MyVector<T>::MyVector(size_t cap) : size(0), capacity(cap), vec(new T[capacity]) {}

template <typename T>
MyVector<T>::MyVector() : size(0), capacity(10), vec(new T[capacity]) {}

template <typename T>
MyVector<T>::MyVector(const MyVector &other) : size(other.size), capacity(other.capacity),
vec(new T[capacity])
{
    for (size_t i = 0; i < size; i++) vec[i] = other.vec[i];
}

template <typename T>
MyVector<T>::MyVector(MyVector &&other) : size(other.size), capacity(other.capacity),
vec(other.vec)
{
    other.vec = nullptr;
    other.capacity = 0;
    other.size = 0;
}

template <typename T>
MyVector<T>::~MyVector()
{
    capacity = 0;
    size = 0;
    delete [] vec;
    vec = nullptr;
}

template <typename T>
MyVector<T> &MyVector<T>::operator=(const MyVector &other)
{
    if (this == &other) return *this;
    T *new_vec = new T[other.capacity];
    try
    {
        for (size_t i = 0; i < other.size; i++) new_vec[i] = other.vec[i];
    }
    catch (...)
    {
        delete [] new_vec;
        throw;
    }
    delete [] vec;
    vec = new_vec;
    capacity = other.capacity;
    size = other.size;
    return *this;
}

template <typename T>
MyVector<T> &MyVector<T>::operator=(MyVector &&other)
{
    if (this == &other) return *this;
    delete [] vec;
    vec = other.vec;
    capacity = other.capacity;
    size = other.size;
    other.vec = nullptr;
    other.capacity = 0;
    other.size = 0;
    return *this;
}

template <typename T>
void MyVector<T>::reallocate(size_t min_cap)
{
    size_t new_capacity = (capacity == 0) ? 10 : capacity * 2;
    if (new_capacity < min_cap) new_capacity = min_cap;
    T *new_vec = new T[new_capacity];
    try
    {
        for (size_t i = 0; i < size; i++) new_vec[i] = vec[i];
    }
    catch (...)
    {
        delete [] new_vec;
        throw;
    }
    capacity = new_capacity;
    delete [] vec;
    vec = new_vec;
}

template <typename T>
void MyVector<T>::push_back(const T &el)
{
    if (size + 1 > capacity) reallocate(size + 1);
    vec[size++] = el;
}

template <typename T>
void MyVector<T>::pop_back()
{
    if (size == 0) return;
    size--;
}

template <typename T>
void MyVector<T>::reserve(size_t n)
{
    if (capacity >= n) return;
    reallocate(n);
}

template <typename T>
void MyVector<T>::resize(size_t n, const T &val)
{
    if (n < size)
    {
        size = n;
        return;
    }
    if (n > capacity) reallocate(n);
    for (size_t i = size; i < n; i++) vec[i] = val;
    size = n;
}