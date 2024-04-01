#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <cstddef>
#include <string>

#include "empty_container_exception.h"

template <typename T>
class Vector {
 public:
    explicit Vector(std::size_t capacity) {
        capacity_ = capacity;
        elements_ = new T[capacity_];
        size_ = 0;
    }

    Vector(const Vector& vector) {
        capacity_ = vector.capacity();
        elements_ = new T[capacity_];
        for (int i=0; i < vector.size(); i++) {
            elements_[i] = vector.elements_[i];
        }
        size_ = vector.size();
    }

    virtual ~Vector() {}

    void operator=(const Vector& vector) {
        delete[] elements_;

        capacity_ = vector.capacity();
        elements_ = new T[capacity_];
        for (int i=0; i < vector.size(); i++) {
            elements_[i] = vector.elements_[i];
        }
        size_ = vector.size();

        return;
    }

    T& operator[](const int index) {
        if (index < 0 || index >= size()) {
            std::string m = "The index is " + std::to_string(index);
            m += ", but the size is " + std::to_string(size()) + ".";
            throw std::out_of_range(m);
        }

        return elements_[index];
    }

    int size() const {
        return size_;
    }

    int capacity() const {
        return capacity_;
    }

    void PushBack(T elem) {
        if (size() == capacity()) {
            capacity_ += 4;
            T* elements_2 = new T[capacity()];
            for (int i=0; i < size(); i++) {
                elements_2[i] = elements_[i];
            }
            delete[] elements_;
            elements_ = elements_2;
        }
        elements_[size()] = elem;
        size_++;
        return;
    }

    void PopBack() {
        if (IsEmpty())
            throw EmptyContainerException("This vector is empty.");
        size_--;
        return;
    }

    bool IsEmpty() const {
        return size() == 0;
    }

 private:
    T* elements_;
    int capacity_;
    int size_;
};

#endif  // _VECTOR_H_
