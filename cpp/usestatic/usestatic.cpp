
#include<iostream>

using namespace std;

void foo()
{
  int b = 1;
  b++;
  static int a = 1;
  a++;
  std::cout<<a<<"\t"<<b<<std::endl;
}


void validate_static_local()
{
  foo();  
  foo();
  foo();
}

int main(int argc, char const *argv[])
{
  validate_static_local();
  return 0;
}

