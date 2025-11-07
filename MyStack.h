#pragma once
#include <iostream>
#include "Queue.h"
using std::cout;
using std::endl;
template <typename T>
class MyStack
{
	enum { EMPTY = -1, DEFAULT_CAPACITY = 10, };
public:
	MyStack(size_t capacity = DEFAULT_CAPACITY, size_t grow = DEFAULT_CAPACITY);
	void push(const T& element);
	void pop();
	T top() const;
	size_t size() const;
	bool empty() const;
	~MyStack();
	T operator[](size_t index) const;
	size_t getCapacity() const;
private:
	void reserve();
	bool full() const;

	int top_ = EMPTY;
	T* stack_ = nullptr;
	size_t capacity;
	size_t growStep;
};


template<typename T>
inline MyStack<T>::MyStack(size_t capacity, size_t grow)
	:capacity{ capacity }, growStep{ grow }, stack_{ new T[capacity] }
{

}

template<typename T>
inline void MyStack<T>::push(const T& element)
{
	if (full())
	{
		reserve();
	}
	stack_[++top_] = element;
}



template<typename T>
inline void MyStack<T>::pop()
{
	if (!empty())
		--top_;
}


template<typename T>
inline size_t  MyStack<T>::size() const
{
	return top_ + 1;
}

template<typename T>
inline T MyStack<T>::top() const
{
	if (!empty())
		return stack_[top_];
	cout << "top() error : stack is empty" << endl;
	exit(EXIT_FAILURE);
}

template<typename T>
inline bool MyStack<T>::empty() const {
	return top_ == EMPTY;
}

template<typename T>
inline void MyStack<T>::reserve()
{
	T* tmp = new T[capacity += growStep];
	for (size_t i = 0; i <= top_; i++)
	{
		tmp[i] = stack_[i];
	}
	delete[] stack_;
	stack_ = tmp;
}

template<typename T>
inline bool MyStack<T>::full() const
{
	return top_ == capacity - 1;
}

template<typename T>
inline MyStack<T>::~MyStack()
{
	delete[] stack_;
}

template<typename T>
inline T MyStack<T>::operator[](size_t index) const
{
	return stack_[index];
}

template<typename T>
inline size_t MyStack<T>::getCapacity() const
{
	return capacity;
}
