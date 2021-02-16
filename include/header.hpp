// Copyright 2021 Yakov xaxaxaxa232@mail.ru
//Last-In-First-Out(LIFO) Primer: pistol
#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include "iostream"

template <typename T>
class Stack
{
 private:
  struct Cell
  {

    T _value;
    Cell* _nextElement;
   public:
    Cell(T value = T(), Cell* nextElement = nullptr)
        :_value{value}, _nextElement{nextElement}{}
  };

  Cell* _top;
  size_t _size;
  Cell *topElement = new Cell();

 public:

  Stack(const Stack&) = delete;
  Stack operator=(const Stack&) = delete;

  Stack()
      :_top(nullptr), _size(0){}

  bool empty(){
    return (_size == 0 && topElement);
  }

  size_t size(){
    return _size;
  }

  void push(T&& value){
    Cell * newElement = new Cell(value);
    if(_size == 0){
      topElement = newElement;
    }
    else{
      newElement->_nextElement = std::move(newElement);
      topElement = std::move(newElement);
    }
    _size++;
  }
  void push(const T& value){
    Cell * newElement = new Cell(value);
    if(_size == 0){
      topElement = newElement;
    }
    else{
      newElement->_nextElement = newElement;
      topElement = newElement;
    }
    _size++;
  }
  T top(){
    return topElement->value;
  }
  void pop(){
    if(!empty()){
      Cell* temp = topElement;
      topElement = topElement->_nextElement;
      delete temp;
      _size--;
    }
  }

  ~Stack(){
    while (!empty())
      pop();
  }
};

#endif // INCLUDE_HEADER_HPP_
