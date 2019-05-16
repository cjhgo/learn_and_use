#include <iostream>



static void common()
{
  extern int x;
  x+=100;
  std::cout<<"i am common in foo \n";
}

void funfoo()
{
  extern int x;
  x+=10;
  std::cout<<"i am funfoo \n";
  common();
}