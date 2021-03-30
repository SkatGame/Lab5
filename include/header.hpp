// Copyright 2021 Yakov xaxaxaxa232@mail.ru
//Last-In-First-Out(LIFO) Primer: pistol
#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include "iostream"

template <typename T>
class Stack {
 private:
  struct Cell {
    T _value;            //поле с данными
    Cell* _nextElement;  //указатель на следующий элемент
   public:
    Cell(T value = T(), Cell* nextElement = nullptr)
        : _value{value}, _nextElement{nextElement} {}
  };
  Cell* _top;

 public:
  Stack(const Stack&) = delete;
  Stack& operator = (const Stack&) = delete;

  Stack() : _top(nullptr) {}

  bool empty() { return (_top == nullptr); }

  void push(T&& value) {
    _top = new Cell {std::forward<T>(value),_top};
  }
  void push(const T& value) {
    _top = new Cell {std::forward<T>(value),_top};
  }
  T head() { return _top->_value; }

  void pop() {
    if (empty()) {
      std::cerr << ("Stack is empty!");
      return;
    }
    Cell* temp = _top;  //запомнили удаляемый узел
    _top =
        _top->_nextElement;  //вершина сместилась на следующий узел
    delete temp;
  }

  ~Stack() {
    while (!empty()) {
      Cell* temp = _top;  //запомнили удаляемый ячейку
      _top =
          _top->_nextElement;  //вершина сместилась на следующий ячейку
      delete temp;
    }
  }
};
template <typename T>
class Stack2
{
 private:
  struct Cell
  {
    T _value; //поле с данными
    Cell* _nextElement; //указатель на следующий элемент
   public:
    Cell(T value = T(), Cell* nextElement = nullptr)
        :_value{value}, _nextElement{nextElement}{}
  };
  Cell* _top;

 public:
  Stack2(const Stack2&) = delete;
  Stack2& operator = (const Stack2&) = delete;

  Stack2()
      :_top(nullptr){}

  template <typename ... Args>
  void push_emplace(Args&&... value)
  {
    auto temp = T(std::forward<Args>(value)...);
    _top = new Cell {std::move(temp),_top};
  }

  bool empty(){
    return (_top == nullptr);
  }

  void push(T&& value){
    _top = new Cell {std::forward<T>(value),_top};
  }

  const T& head() const{
    return _top->_value;
  }

  T pop(){
    if(!_top) {
      std::cerr << ("Stack is empty!");
      return T();
    }
    Cell * deleter = _top; //запомнили удаляемый узел
    T value = std::move(_top->_value); //запомнили значение, которое хотим вернуть
    _top = deleter->_nextElement; //вершина сместилась на следующий узел
    delete deleter;
    return value;
  }
  ~Stack2() {
    while (!empty()) {
      Cell* temp = _top;  //запомнили удаляемый ячейку
      _top =
          _top->_nextElement;  //вершина сместилась на следующий ячейку
      delete temp;
    }
  }
};


#endif // INCLUDE_HEADER_HPP_
