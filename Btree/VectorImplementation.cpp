#include "Vector.h"
template <typename T>
Vector<T>::Vector()
{
    capacity = 1;
    size = 0;
    data = new T[capacity];
}
template <typename T>
Vector<T>::Vector(const Vector<T> &other)
{
    capacity = other.capacity;
    size = other.size;
    data = new T[capacity];
    for (int i = 0; i < size; i++)
    {
        data[i] = other.data[i];
    }
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &other)
{
    if (this != &other)
    {
        delete[] data;

        capacity = other.capacity;
        size = other.size;
        data = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template <typename T>
Vector<T>::~Vector()
{
    if (data)
    {
        delete[] data;
        data = nullptr;
    }
}

template <typename T>
void Vector<T>::resize()
{
    capacity *= 2;
    T *newData = new T[capacity];
    for (int i = 0; i < size; i++)
    {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

template <typename T>
void Vector<T>::resize(int newCapacity)
{
    if (newCapacity <= 0)
        return;
    capacity = newCapacity;
    T *newData = new T[capacity];
    int minimum = std::min(size, newCapacity);
    for (int i = 0; i < minimum; i++)
    {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    size = minimum;
}
template <typename T>
T *Vector<T>::begin()
{
    return data;
}
template <typename T>
T *Vector<T>::end()
{
    return data + size;
}
template <typename T>
void Vector<T>::push_back(T element)
{
    if (size == capacity)
        resize();
    data[size++] = element;
}
template <typename T>
void Vector<T>::insert(int index, T element)
{
    if (index < 0 || index > size)
    {
        throw std::out_of_range("Index out of range");
    }
    if (size == capacity)
    {
        resize();
    }
    for (int i = size; i > index; i--)
    {
        data[i] = data[i - 1];
    }
    data[index] = element;
    size++;
}

template <typename T>
int Vector<T>::Size()
{
    return size;
}
template <typename T>
T &Vector<T>::operator[](int index)
{

    return data[index];
}
template <typename T>
void Vector<T>::assign(T *begin, T *end)
{
    int newSize = end - begin;
    if (newSize > capacity)
    {
        capacity = newSize;
        delete[] data;
        data = new T[capacity];
    }
    for (int i = 0; i < newSize; i++)
    {
        data[i] = begin[i];
    }
    size = newSize;
}