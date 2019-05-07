#include<iostream>
#include<string>
#include<memory>
using namespace std;

int main(int argc, char const *argv[])
{
  unique_ptr<string> p1(new string("abcedf"));
  unique_ptr<string> p2,p3;
  cout<<*p1.get()<<endl;
  p2 = std::move(p1);
  cout<<*p2.get()<<endl;
  p3.reset(p2.release());
  cout<<*p3.get()<<endl;
  return 0;
}