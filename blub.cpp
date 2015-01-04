#include <iostream>


namespace bla
{
 void test()
 {
  std::cout << "bla" << std::endl;
 }
}

namespace foo
{
 void test()
 {
  std::cout << "foo" << std::endl;
 }
}

using namespace foo;
using namespace bla;

int main()
{
 test();
}
