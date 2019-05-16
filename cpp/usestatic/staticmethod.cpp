#include <iostream>

class Foo
{
public:
  void bar();
  static int l;
  static void foo();
};

void Foo::bar()
{
  std::cout<<this<<std::endl;
}

void Foo::foo()
{
  static int a;
  a++;
  std::cout<<a<<std::endl;
}
int main(int argc, char const *argv[])
{
  Foo f;
  f.bar();  
  Foo::foo();
  Foo::foo();
  Foo::foo();
  Foo::foo();
  return 0;
}
