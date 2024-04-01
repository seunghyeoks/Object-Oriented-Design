#ifndef _SORT_H_
#define _SORT_H_

#include <utility>

template <typename T, typename N>
void Sort(typename T::iterator begin, typename T::iterator end) {
    N comparator;
    for (typename T::iterator i = begin; i != end; ++i) {
        for (typename T::iterator j = begin; j != end; ++j) {
            typename T::iterator next = j;
            ++next;

            if (next != end  && comparator(*j, *next)) {
                std::swap(*j, *next);
            }
        }
    }
}

#endif  // _SORT_H_
