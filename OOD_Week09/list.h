#ifndef _LIST_H_
#define _LIST_H_

class List {
 public:
    List();
    List(const List& list);
    virtual ~List();
    void operator=(const List& list);
    int size() const;
    void PushBack(int elem);
    void PushFront(int elem);
    void PopBack();
    void PopFront();
    int& At(int index) const;
    bool IsEmpty() const;
 private:
    struct Elem {
        int value;
        Elem* next;
    };
    Elem* head_;
    int size_;
};

#endif  // _LIST_H_
