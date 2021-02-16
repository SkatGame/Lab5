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
