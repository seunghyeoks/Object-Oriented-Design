#include "vector.h"

#include <assert.h>

Vector::Vector(std::size_t capacity) {
    capacity_ = capacity;
    elements_ = new int[capacity_];
    size_ = 0;
}

Vector::Vector(const Vector& vector) {
    capacity_ = vector.capacity();
    elements_ = new int[capacity_];
    for (int i=0; i < vector.size(); i++) {
        elements_[i] = vector.elements_[i];
    }
    size_ = vector.size();
}

Vector::~Vector() {}

void Vector::operator=(const Vector& vector) {
    delete[] elements_;

    capacity_ = vector.capacity();
    elements_ = new int[capacity_];
    for (int i=0; i < vector.size(); i++) {
        elements_[i] = vector.elements_[i];
    }
    size_ = vector.size();

    return;
}

int& Vector::operator[](const int index) {
    assert((index >= 0 && index < size()) && "Out-of-bound");

    return elements_[index];
}

int Vector::size() const {
    return size_;
}

int Vector::capacity() const {
    return capacity_;
}

void Vector::PushBack(int elem) {
    if (size() == capacity()) {
        capacity_ += 4;
        int* elements_2 = new int[capacity()];
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

void Vector::PopBack() {
    assert(!IsEmpty() && "Out-of-bound");
    size_--;
    return;
}

bool Vector::IsEmpty() const {
    return size() == 0;
}
