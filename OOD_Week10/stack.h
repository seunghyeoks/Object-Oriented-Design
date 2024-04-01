#ifndef _STACK_H_
#define _STACK_H_

#include <cstddef>

#include "vector.h"

template <typename T>
class Stack : private Vector<T> {
 public:
    explicit Stack(std::size_t capacity) : Vector<T>(capacity) {}

    Stack(const Stack& stack) : Vector<T>(stack) {}

    void operator=(const Stack& stack) {
        Vector<T>::operator=(stack);
    }

    int size() const {
        return Vector<T>::size();
    }

    int capacity() const {
        return Vector<T>::capacity();
    }

    void Push(T elem)  {
        Vector<T>::PushBack(elem);
        return;
    }

    T Pop() {
        T temp = (*this)[size()-1];
        Vector<T>::PopBack();
        return temp;
    }

    bool IsEmpty() const {
        return Vector<T>::IsEmpty();
    }
};

#endif  // _STACK_H_
