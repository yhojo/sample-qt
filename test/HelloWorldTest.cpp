
#include <gmock/gmock.h>

#include "HelloWorld.h"

using namespace ::testing;

TEST(HelloWorld, can_say_hello) {
  ASSERT_THAT(HelloWorld("John").sayHello(), Eq("Hello, John"));
}

TEST(HelloWorld, can_build_no_name) {
  ASSERT_THAT(HelloWorld().sayHello(), Eq("Hello, World"));
}
