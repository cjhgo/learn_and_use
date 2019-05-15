#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  int a = 3;
  int * b = &a;
  uint64_t c = 5;
  std::cout<<sizeof(a)<<"\t"<<sizeof(b)<<"\t"<<sizeof(c);
  return 0;
}