#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(int argc, char const *argv[])
{
  typedef string sArr[11];
  string* a = new string[4] ;
  string* b = new sArr;
  cout<<a<<"\n"<<a+1<<endl;
  string *c[4];
  string d[11];
  sArr e;
  cout<<b<<endl<<c<<endl;
  cout<<sizeof(c[1])<<"\t"<<sizeof(e[0])<<"\n"<<sizeof(e)/sizeof(e[0])<<"\t"<<sizeof(b)<<endl;
  return 0;
}