
#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

class HasPtr
{
public:  
  HasPtr(const string &s=string()):
    ps(new string(s)),i(0){}
  HasPtr(const HasPtr&p):
    ps(new string(*p.ps)),i(p.i)
    {
      cout<<"\nrun once\n";
    }
  HasPtr& operator=(const HasPtr&);
  ~HasPtr(){delete ps;}
  void Rep()
  {
    cout<<i<<"\t"<<*ps<<endl;
  }
private:
  int i;
  string* ps;
};

HasPtr& HasPtr::operator=(const HasPtr& right)
{
  cout<<"execute here!\n";
  this->i = right.i;
  *this->ps = *right.ps;
  return *this;
}


class HasPtrLikeptr
{
public:
  HasPtrLikeptr(const string&s=string()):
  ps(new string(s)),i(0),counter(new int(1)){}
  HasPtrLikeptr(const HasPtrLikeptr&);
  HasPtrLikeptr& operator=(const HasPtrLikeptr&);
  ~HasPtrLikeptr();
  void Rep()
  {
    cout<<i<<"\t"<<*counter<<"\t"<<*ps<<endl;
  }
private:
  int i;
  string* ps;
  int* counter;
};
HasPtrLikeptr::HasPtrLikeptr(const HasPtrLikeptr& from)
{
  this->ps=from.ps;
  this->i=from.i;
  this->counter=from.counter;
  ++(*this->counter);
}
HasPtrLikeptr& HasPtrLikeptr::operator=(const HasPtrLikeptr& from)
{
  ++(*from.counter);
  if(--(*this->counter) == 0)
  {
    delete counter;
    delete ps;
  }
  this->counter=from.counter;
  this->ps=from.ps;
  this->i=from.i;
  return *this;
}
HasPtrLikeptr::~HasPtrLikeptr()
{
  if(--(*this->counter)==0)
  {
    delete counter;
    delete ps;
  }
}
void foo(HasPtr p)
{
  p.Rep();
}
void testhp()
{
  HasPtr hp1("hp1");
  HasPtr hp2("hp2");
  hp2=hp1;
  hp2=hp2;
  hp2=hp1=hp2;
  hp1.Rep();
  hp2.Rep();
  HasPtr hp3(hp2);
  hp3.Rep();
  foo(hp3);
}
void testhpl()
{
  HasPtrLikeptr hpl1("hpl1");
  hpl1.Rep();    
  {
  HasPtrLikeptr hpl2(hpl1);
  hpl2.Rep();
  hpl2=hpl1;
  hpl2=hpl1;
  hpl1=hpl2;
  hpl1.Rep();
  }
  hpl1.Rep();
  HasPtrLikeptr hpl3=hpl1;
  hpl1.Rep();
  hpl1=hpl3;
  hpl1.Rep();
}
int main(int argc, char const *argv[])
{

  // testhp();
  testhpl();
  return 0;
}