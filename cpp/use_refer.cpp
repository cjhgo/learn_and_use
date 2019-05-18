
#include<iostream>

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
  return 0;
}