
#include <gtest/gtest.h>

#include "HelloWorld.h"

TEST(HelloWorld, can_say_hello) {
  ASSERT_EQ(HelloWorld("John").sayHello(), "Hello, John");
}

TEST(HelloWorld, can_build_no_name) {
  ASSERT_EQ(HelloWorld().sayHello(), "Hello, World");
}
