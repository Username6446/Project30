#pragma once
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class Queue
{
private:
    T* p;
    size_t capacity;
    size_t size;

    void expand();

public:
    Queue(size_t cap = 10);
    Queue(const Queue& other);
    Queue(Queue&& other) noexcept;
    Queue<T>& operator=(const Queue& other);
    Queue<T>& operator=(Queue&& other) noexcept;
    ~Queue();

    void push(const T& element);
    T pop();
    T GetItem() const;
    void clear();
    bool isEmpty() const;
    size_t GetN() const;
    void print() const;
};

template<typename T>
Queue<T>::Queue(size_t cap)
    : capacity(cap), size(0), p(new T[cap])
{
}

template<typename T>
Queue<T>::Queue(const Queue& other)
    : capacity(other.capacity), size(other.size), p(new T[other.capacity])
{
    for (size_t i = 0; i < size; i++)
        p[i] = other.p[i];
}

template<typename T>
Queue<T>::Queue(Queue&& other) noexcept
    : p(other.p), capacity(other.capacity), size(other.size)
{
    other.p = nullptr;
    other.size = 0;
    other.capacity = 0;
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue& other)
{
    if (this != &other)
    {
        delete[] p;
        capacity = other.capacity;
        size = other.size;
        p = new T[capacity];
        for (size_t i = 0; i < size; i++)
            p[i] = other.p[i];
    }
    return *this;
}

template<typename T>
Queue<T>& Queue<T>::operator=(Queue&& other) noexcept
{
    if (this != &other)
    {
        delete[] p;
        p = other.p;
        capacity = other.capacity;
        size = other.size;
        other.p = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    return *this;
}

template<typename T>
Queue<T>::~Queue()
{
    delete[] p;
}

template<typename T>
void Queue<T>::expand()
{
    size_t new_capacity = capacity + 5;
    T* tmp = new T[new_capacity];
    for (size_t i = 0; i < size; i++)
        tmp[i] = p[i];
    delete[] p;
    p = tmp;
    capacity = new_capacity;
    cout << "[Expand] new capacity=" << capacity << endl;
}

template<typename T>
void Queue<T>::push(const T& element)
{
    if (size >= capacity)
        expand();
    p[size++] = element;
}

template<typename T>
T Queue<T>::pop()
{
    if (isEmpty())
    {
        cout << "Queue is empty\n";
        return T();
    }
    T temp = p[0];
    for (size_t i = 0; i < size - 1; i++)
        p[i] = p[i + 1];
    size--;
    return temp;
}

template<typename T>
T Queue<T>::GetItem() const
{
    if (isEmpty())
    {
        cout << "Queue is empty\n";
        return T();
    }
    return p[0];
}

template<typename T>
void Queue<T>::clear()
{
    delete[] p;
    capacity = 10;
    size = 0;
    p = new T[capacity];
}

template<typename T>
bool Queue<T>::isEmpty() const
{
    return size == 0;
}

template<typename T>
size_t Queue<T>::GetN() const
{
    return size;
}

template<typename T>
void Queue<T>::print() const
{
    if (isEmpty())
    {
        cout << "(empty)" << endl;
        return;
    }
    for (size_t i = 0; i < size; i++)
        cout << p[i] << "\t";
    cout << endl;
}
