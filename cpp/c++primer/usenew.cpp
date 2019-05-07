#include<iostream>
#include<string>
using namespace std;

int main(int argc, char const *argv[])
{
  string * y = new string("abcdef\n");
  cout<<y<<"\t"<<*y<<endl;
  delete y;
  y=nullptr;
  cout<<y<<"\t"<<endl;
  string *a, *b,*c,*d,*e;
  cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<endl;
  return 0;
}