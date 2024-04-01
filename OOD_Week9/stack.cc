#include "stack.h"

#include <assert.h>

Stack::Stack(std::size_t capacity) : Vector(capacity) {}

Stack::Stack(const Stack& stack) : Vector(stack) {}

void Stack::operator=(const Stack& stack) {
    Vector::operator=(stack);
}

int Stack::size() const {
    return Vector::size();
}

int Stack::capacity() const {
    return Vector::capacity();
}

void Stack::Push(int elem) {
    Vector::PushBack(elem);
    return;
}

int Stack::Pop() {
    int temp = (*this)[size()-1];
    Vector::PopBack();
    return temp;
}

bool Stack::IsEmpty() const {
    return Vector::IsEmpty();
}
