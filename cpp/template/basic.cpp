#include<iostream>
using namespace std;
void fun()
{
    cout<<"hello,world at fun"<<endl;
}
void bar()
{
    cout<<"hello,world at bar"<<endl;
}
template<typename foo>
void callfun(foo fn)
{
    fn();
}
template <class T>
T GetMax (T a, T b) {
  T result;
  result = (a>b)? a : b;
  return (result);
}
int main () 
{
    fun();
    callfun(fun);
    callfun(bar);
    int i=5, j=6, k;
    long l=10, m=5, n;
    k=GetMax<int>(i,j);
    n=GetMax<long>(l,m);
    cout << GetMax(i,j) << endl;
    cout << k << endl;
    cout << n << endl;
    return 0;
}