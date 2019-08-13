#include<iostream>

class A
{
public:
virtual void foo(){std::cout<<"foo in A\n";}
};
class B:public A
{
  public:
  int a;
  void foo(){std::cout<<"foo in B\n";}
  void notina()
  {
    std::cout<<"fun not in a\n";
    this->a = 55;
    std::cout<<this->a<<std::endl;
  }
};


class C
{
  public:
  double x =3;
  double y = 4;
  void bar(){std::cout<<"bar in C\n";}
  void foo(){std::cout<<"foo in C\n";}
};
class D:public C
{
  public:
  D(int a=1, int b=2)
  {
    a = a;
    b = b;
  }
  int a = 1;
  int b = 2;
  void foo()
  {
    std::cout<<"fooo in D\n";
    std::cout<<"fooo in D\n";
  }
};
int main(int argc, char const *argv[])
{
  A a;
  B b;
  C c;
  D d;
  C* pc = &d;
  
  d.foo();
  pc->foo();
  C* pcc=&c;
  D* pd =  (D*)pcc;
  pd->foo();
  std::cout<<pc<<"\t"<<&d<<std::endl;
  A* pa = &b;
  A* paa = dynamic_cast<A*>(&b);
  paa->foo();

  A* pab = new B;
  B* pb = (B*)pab;
  B* pbb = dynamic_cast<B*>(pab);

  A* reala=&a;
  B* pb3 = (B*)reala;
  pb3->notina();
  B* pb4 = dynamic_cast<B*>(reala);
  std::cout<<(pb4==nullptr)<<std::endl;
  pbb->foo();
  return 0;
}