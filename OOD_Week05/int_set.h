#ifndef _INT_SET_H_
#define _INT_SET_H_

#include <assert.h>
#include <iostream>

class IntSet {
 public:
  explicit IntSet(int capacity);
  IntSet(const IntSet& int_set);

  int capacity() const;
  int size() const;
  const int* elements() const;

  int operator[](int index);  // operator overloading

  void Add(int value);
  void Add(const IntSet& int_set);
  void Map(std::function<int(int)> f);
  bool ForAll(std::function<bool(int)> f);

 private:
  int capacity_;
  int size_;
  int* elements_;
};

#endif  // _INT_SET_H
