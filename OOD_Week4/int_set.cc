#include "int_set.h"

IntSet::IntSet(int capacity) {
    IntSet::capacity_ = capacity;
    IntSet::size_ = 0;
    IntSet::elements_ = new int[capacity_];
}

IntSet::IntSet(const IntSet& int_set) {
    IntSet::capacity_ = int_set.capacity_;
    IntSet::size_ = int_set.size_;
    IntSet::elements_ = new int[int_set.capacity_];
    for (int i = 0; i < int_set.capacity_; i++) {
        IntSet::elements_[i] = int_set.elements_[i];
    }
}

int IntSet::capacity() const {
    return IntSet::capacity_;
}

int IntSet::size() const {
    return IntSet::size_;
}

const int* IntSet::elements() const {
    return IntSet::elements_;
}

void IntSet::Add(int value) {

    for (int i = 0; i < size(); i++)
        if (IntSet::elements_[i] == value) return;

    assert((capacity() != size())  && "Exceeded capacity");

    IntSet::elements_[size()] = value;
    IntSet::size_++;

    return;
}

void IntSet::Add(const IntSet& int_set) {
    int check = 0;

    for (int i = 0; i < int_set.size(); i++) {
        for (int j = 0; j < size(); j++) {
            if (elements()[j] == int_set.elements()[i]) {
                check++;
                break;
            }
        }
    }

    check = size() + int_set.size() - check;
    assert((check <= capacity()) && "Exceeded capacity");

    for (int i = 0; i < int_set.size(); i++) {
        Add(int_set.elements()[i]);
    }

    return;
}

void IntSet::Map(std::function<int(int)> f) {
    for (int i = 0; i < size(); i++) {
        IntSet::elements_[i] = f(IntSet::elements_[i]);
    }
}

bool IntSet::ForAll(std::function<bool(int)> f) {
    bool result = true;

    for (int i = 0; i < size(); i++) {
        if (f(IntSet::elements_[i]) == true) {
            continue;
        } else {
            result = false;
            break;
        }
    }

    return result;
}
