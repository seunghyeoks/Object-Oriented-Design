#ifndef _LIST_H_
#define _LIST_H_

#include <assert.h>

template <typename T>
class List {
 public:
    List() {
        size_ = 0;
        head_ = nullptr;
    }

    List(const List& list) {
        size_ = 0;

        for (int i=0; i < list.size(); i++) {
            PushBack(list.At(i));
        }
    }

    virtual ~List() {}

    void operator=(const List& list) {
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

    int size() const {
        return size_;
    }

    void PushBack(T elem) {
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

    void PushFront(T elem) {
        Elem* temp = new Elem;
        temp->value = elem;
        if (size() != 0)
            temp->next = head_;

        head_ = temp;


        size_++;
        return;
    }

    void PopBack() {
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

    void PopFront() {
        assert(!IsEmpty() && "Out-of-bound");

        Elem* temp = head_;
        head_ = head_->next;
        delete temp;

        size_--;
        return;
    }

    T& At(int index) const {
        assert(!IsEmpty() && "Out-of-bound");
        assert((index >= 0 && index < size()) && "Out-of-bound");


        Elem* temp = head_;
        for (int i=0; i < index; i++) {
            temp = temp->next;
        }

        return temp->value;
    }

    bool IsEmpty() const {
        return size() == 0;
    }

 private:
    struct Elem {
        T value;
        Elem* next;
    };
    Elem* head_;
    int size_;
};

#endif  // _LIST_H_
