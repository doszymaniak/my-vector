#include <iostream>

using namespace std;

template <typename T>
void MyVector<T>::print(const string &label) const
{
    cout << label;
    for (size_t i = 0; i < m_size; i++) cout << vec[i] << " ";
    cout << '\n';
}

template <typename T>
MyVector<T>::MyVector(size_t cap) : m_size(0), m_capacity(cap), vec(new T[m_capacity]) {}

template <typename T>
MyVector<T>::MyVector() : m_size(0), m_capacity(10), vec(new T[m_capacity]) {}

template <typename T>
MyVector<T>::MyVector(const MyVector &other) : m_size(other.m_size), m_capacity(other.m_capacity),
vec(new T[m_capacity])
{
    for (size_t i = 0; i < m_size; i++) vec[i] = other.vec[i];
}

template <typename T>
MyVector<T>::MyVector(MyVector &&other) : m_size(other.m_size), m_capacity(other.m_capacity),
vec(other.vec)
{
    other.vec = nullptr;
    other.m_capacity = 0;
    other.m_size = 0;
}

template <typename T>
MyVector<T>::~MyVector()
{
    m_capacity = 0;
    m_size = 0;
    delete [] vec;
    vec = nullptr;
}

template <typename T>
MyVector<T> &MyVector<T>::operator=(const MyVector &other)
{
    if (this == &other) return *this;
    T *new_vec = new T[other.m_capacity];
    try
    {
        for (size_t i = 0; i < other.m_size; i++) new_vec[i] = other.vec[i];
    }
    catch (...)
    {
        delete [] new_vec;
        throw;
    }
    delete [] vec;
    vec = new_vec;
    m_capacity = other.m_capacity;
    m_size = other.m_size;
    return *this;
}

template <typename T>
MyVector<T> &MyVector<T>::operator=(MyVector &&other)
{
    if (this == &other) return *this;
    delete [] vec;
    vec = other.vec;
    m_capacity = other.m_capacity;
    m_size = other.m_size;
    other.vec = nullptr;
    other.m_capacity = 0;
    other.m_size = 0;
    return *this;
}

template <typename T>
void MyVector<T>::reallocate(size_t min_cap)
{
    size_t new_capacity = (m_capacity == 0) ? 10 : m_capacity * 2;
    if (new_capacity < min_cap) new_capacity = min_cap;
    T *new_vec = new T[new_capacity];
    try
    {
        for (size_t i = 0; i < m_size; i++) new_vec[i] = vec[i];
    }
    catch (...)
    {
        delete [] new_vec;
        throw;
    }
    m_capacity = new_capacity;
    delete [] vec;
    vec = new_vec;
}

template <typename T>
void MyVector<T>::push_back(const T &el)
{
    if (m_size + 1 > m_capacity) reallocate(m_size + 1);
    vec[m_size++] = el;
}

template <typename T>
void MyVector<T>::pop_back()
{
    if (m_size == 0) return;
    m_size--;
}

template <typename T>
void MyVector<T>::reserve(size_t n)
{
    if (m_capacity >= n) return;
    reallocate(n);
}

template <typename T>
void MyVector<T>::resize(size_t n, const T &val)
{
    if (n < m_size)
    {
        m_size = n;
        return;
    }
    if (n > m_capacity) reallocate(n);
    for (size_t i = m_size; i < n; i++) vec[i] = val;
    m_size = n;
}

template <typename T>
T &MyVector<T>::operator[](size_t idx)
{
    return vec[idx];
}

template <typename T>
const T &MyVector<T>::operator[](size_t idx) const
{
    return vec[idx];
}

template <typename T>
T &MyVector<T>::at(size_t idx)
{
    if (idx >= m_size) throw out_of_range("Index out of range!");
    return vec[idx];
}

template <typename T>
const T &MyVector<T>::at(size_t idx) const
{
    if (idx >= m_size) throw out_of_range("Index out of range!");
    return vec[idx];
}

template <typename T>
size_t MyVector<T>::size() const
{
    return m_size;
}

template <typename T>
size_t MyVector<T>::capacity() const
{
    return m_capacity;
}

template <typename T>
bool MyVector<T>::empty() const
{
    return (m_size == 0);
}

template <typename T>
T *MyVector<T>::begin() 
{
    return vec;
}

template <typename T>
const T *MyVector<T>::begin() const
{
    return vec;
}

template <typename T>
T *MyVector<T>::end()
{
    return vec + m_size;
}

template <typename T>
const T *MyVector<T>::end() const
{
    return vec + m_size;
}