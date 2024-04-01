#include <string>
#include <iostream>

#include "vector.h"
#include "stack.h"
#include "list.h"
#include "queue.h"

int main() {
    Stack<std::string> s(4);

    s.Push("A");
    s.Push("B");
    s.Push("C");
    s.Push("D");
    s.Push("E");
    s.Push("F");
    s.Push("G");
    s.Push("H");
    s.Push("I");

    std::cout << s.capacity() << std::endl;
    std::cout << s.size() << std::endl;
    std::cout << s.Pop() << std::endl;

    return 0;
}
