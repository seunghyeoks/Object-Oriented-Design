#include "queue.h"

#include <assert.h>

Queue::Queue() : List() {}

Queue::Queue(const Queue& queue) : List(queue) {}

void Queue::operator=(const Queue& queue) {
    List::operator=(queue);
}

int Queue::size() const {
    return List::size();
}

void Queue::Add(int elem) {
    List::PushBack(elem);
    return;
}

int Queue::Poll() {
    int temp = (*this).At(0);
    List::PopFront();
    return temp;
}

bool Queue::IsEmpty() const {
    return List::IsEmpty();
}
