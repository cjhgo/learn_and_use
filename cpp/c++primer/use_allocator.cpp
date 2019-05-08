#include <memory>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Foo
{
public:
  Foo():a(100),b(new int(99)){};
  Foo(const Foo& f)
  {
    cout<<"running copy constructor\n";
    a=50;
  }
  Foo(Foo&& f)
  {
    cout<<f.b<<endl;
    cout<<"running move constructor\n";
    a=f.a;
    b=f.b;
    f.b=nullptr;
  }
  int a;
  int *b;
};

int main()
{
  allocator<Foo> aF;
  Foo* a = aF.allocate(1);
  Foo f;
  aF.construct(a,std::move(f));
  cout<<a->a<<"\n"<<a->b;
}