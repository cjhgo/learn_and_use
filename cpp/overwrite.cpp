#include<iostream>
#include<vector>
using namespace std;

class Base
{
public:
  void foo()
  {
    cout<<"i am foo in base \n";
  };
};


class Derived: public Base
{

public:
  void foo()
  {
    Base::foo();
    cout<<"i am foo in derived\n";
  }
  void foo(int a)
  {

  }
};

int main(int argc, char const *argv[])
{
  Base* p = new Derived;
  p->foo();  
  Derived * pp =new Derived;
  pp->foo();
  return 0;
}