// Copyright 2021 Yakov xaxaxaxa232@mail.ru
//Last-In-First-Out(LIFO) Primer: pistol
#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include "iostream"
#include "iomanip"

template <typename T>
class Stack
{
 public:

  Stack(const Stack&) = delete;
  Stack operator=(const Stack&) = delete;

  Stack()
      :_size(0), _top(nullptr){}


  void push(T&& value);
  void push(const T& value);
  void pop();

 private:
  struct Cell
  {
    T _value;
    Cell* _next;
   public:
    Cell(T value = T(), Cell* next = nullptr)
        :_next{next}, _value{value}{}
  };

  Cell* _top;
  size_t _size;
};



#endif // INCLUDE_HEADER_HPP_
