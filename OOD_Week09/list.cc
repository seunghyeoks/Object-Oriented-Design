#include "list.h"

#include <assert.h>

List::List() {
    size_ = 0;
    head_ = nullptr;
}

List::List(const List& list) {
    size_ = 0;

    for (int i=0; i < list.size(); i++) {
        PushBack(list.At(i));
    }
}

List::~List() {}

void List::operator=(const List& list) {
    Elem* temp = head_;
    Elem* temp2;
    for (int i=0; i < size(); i++) {
        temp2 = temp;
        temp = temp->next;
        delete temp2;
    }


    size_ = 0;

    for (int i=0; i < list.size(); i++) {
        PushBack(list.At(i));
    }

    return;
}

int List::size() const {
    return size_;
}

void List::PushBack(int elem) {
    Elem* temp = new Elem;
    temp->value = elem;
    temp->next = nullptr;

    if (size() == 0) {
        head_ = temp;
    } else {
        Elem* pre = head_;
        for (int i=0; i < size()-1; i++) {
            pre = pre->next;
        }
        pre->next = temp;
    }

    size_++;
    return;
}

void List::PushFront(int elem) {
    Elem* temp = new Elem;
    temp->value = elem;
    if (size() != 0)
        temp->next = head_;

    head_ = temp;


    size_++;
    return;
}

void List::PopBack() {
    assert(!IsEmpty() && "Out-of-bound");

    Elem* pre = head_;
    for (int i=0; i < size()-2; i++) {
        pre = pre->next;
    }
    delete pre->next;
    pre->next = nullptr;

    size_--;
    return;
}

void List::PopFront() {
    assert(!IsEmpty() && "Out-of-bound");

    Elem* temp = head_;
    head_ = head_->next;
    delete temp;

    size_--;
    return;
}

int& List::At(int index) const {
    assert(!IsEmpty() && "Out-of-bound");
    assert((size() > index && index >= 0) && "Out-of-bound");


    Elem* temp = head_;
    for (int i=0; i < index; i++) {
        temp = temp->next;
    }

    return temp->value;
}

bool List::IsEmpty() const {
    return size() == 0;
}
