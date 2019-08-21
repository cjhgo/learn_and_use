#include <iostream>

int main(int argc, char const *argv[])
{
  enum Level
  {
    EVERYTHING=3,
    NONE=5
  };
  Level a = NONE, b = EVERYTHING;
  std::cout<<a<<"\t"<<b<<std::endl;
  return 0;
}


