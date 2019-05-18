
#include <iostream>
#include <vector>
using namespace std;


void change(int& a)
{
  a+=1200;
}

int main(int argc, char const *argv[])
{
  int x = 10;
  cout<<x<<endl;
  change(x);
  cout<<x<<endl;
  vector<int> a{5,6,7,8};
  cout<<a[1]<<endl;
  int& a1=a[1];
  a1 = 99;
  cout<<a[1]<<endl;
  return 0;
}