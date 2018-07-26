#include <bitset>
#include <iostream>
using namespace std;
/*
Printing numbers in binary format in C++
*/
int main()
{
  int x=998;
  cout<<bitset<32>(x)<<endl;
}