// Copyright 2021 Yakov xaxaxaxa232@mail.ru

#include <gtest/gtest.h>
#include "header.hpp"
TEST(Example, EmptyTest) {
    EXPECT_TRUE(true);
}

TEST(Stack,Empty){
Stack<int> testStack;
bool empty = testStack.empty();
  EXPECT_EQ(true, empty);
}

TEST(Stack,Pop_Push){
  Stack<int> testStack;
  testStack.push(25);
  testStack.push(24);
  testStack.pop();
  int head = testStack.head();
  EXPECT_EQ(25, head);
}

TEST(Stack2,Empty){
  Stack2<int> testStack;
  bool empty = testStack.empty();
  EXPECT_EQ(true, empty);
}

TEST(Stack2,Pop_Push) {
  Stack2<int> testStack;
  testStack.push(25);
  testStack.push(24);
  testStack.pop();
  int head = testStack.head();
  EXPECT_EQ(25, head);
}
template <typename T>
struct test {
  T t_1;
  T t_2;
  T t_3;
};

TEST(Stack2,Push_Emp) {
  test<std::string> buffer;
  buffer.t_1 = "Helfflo";
  buffer.t_2 = "world";
  buffer.t_3 = "!";
  Stack2<test<std::string>> testStack;
  testStack.push_emplace(buffer);
  EXPECT_EQ(testStack.head().t_1, buffer.t_1);
  EXPECT_EQ(testStack.head().t_2, buffer.t_2);
  EXPECT_EQ(testStack.head().t_3, buffer.t_3);
}
