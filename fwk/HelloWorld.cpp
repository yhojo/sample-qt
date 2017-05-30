
#include "HelloWorld.h"

HelloWorld::HelloWorld()
  : HelloWorld("World") {}

HelloWorld::HelloWorld(const std::string &who)
  : m_who(who) {}

HelloWorld::~HelloWorld() {}

std::string HelloWorld::sayHello() {
    return "Hello, " + m_who;
}
