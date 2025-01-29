#ifndef Vector_H
#define Vector_H
#include <iostream>
template <typename T>
class Vector
{
private:
    T *data;
    int capacity;
    int size;

public:
    Vector();
    Vector(const Vector<T> &other);
    Vector<T> &operator=(const Vector<T> &other);
    ~Vector();
    void resize(int newSize);
    void resize();
    T *begin();
    T *end();
    void push_back(T element);
    void insert(int index, T element);
    int Size();
    T &operator[](int index);
    void assign(T *begin, T *end);
};

#endif
