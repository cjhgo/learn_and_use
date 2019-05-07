#include <memory>
#include <iostream>
#include <string>
using namespace std;

struct Obj
{
  Obj(){cout<<"wow i created\n";}
  void bar(){cout<<"i am bar\n";}
  ~Obj(){cout<<"wow i destory\n";}
};

void bar(shared_ptr<Obj> s)
{
  cout<<"look:"<<s.use_count()<<endl;
}

shared_ptr<Obj> foo()
{
  auto a = make_shared<Obj>();
  return a;
}
int main(int argc, char const *argv[])
{
  foo()->bar();
  bar(make_shared<Obj>());

  {//shared_ptr 释放内存后得到的是悬空指针,即指针值还是分配的地址
    string * s = new string("abcde");
    cout<<s<<"\t"<<*s<<endl;
    {
      shared_ptr<string> ps(s);
    }
    cout<<s<<"\t"<<endl;  
    //string x = *s;使用悬空指针会出现段错误
  }

  {//use reset method
    cout<<endl<<endl;
    auto b = make_shared<Obj>();
    auto c (b);
    cout<<c.use_count()<<endl;
    b.reset();
    cout<<c.use_count()<<endl;
  }

  return 0;
}