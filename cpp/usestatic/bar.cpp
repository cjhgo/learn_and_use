#include <iostream>



void common()
{
  std::cout<<" i am common in bar\n";
}

void funbar()
{
  std::cout<<"i am funbar\n";
}

void funfoo();


int x = 5;
int main(int argc, char const *argv[])
{
  funbar();
  common();
  funfoo();
  std::cout<<x<<std::endl;
  return 0;
}
