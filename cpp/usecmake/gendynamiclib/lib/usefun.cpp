#include <iostream>


int myfun(int a);

int usefun(int a)
{
  std::cout<<"i am fun usefun"<<std::endl;
  std::cout<<myfun(a)+2<<std::endl;
  return a*a;
}