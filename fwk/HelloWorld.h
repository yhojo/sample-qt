
#include <string>

class HelloWorld {
private:
  std::string m_who;
public:
  HelloWorld();
  HelloWorld(const std::string &who);
  virtual ~HelloWorld();

  std::string sayHello();
};
