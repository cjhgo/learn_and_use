#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std:cin.tie(nullptr);
    return nullptr;
}(); 
int main(int argc, char const *argv[])
{
    int a = 5, b = 6;
    const int & ra = a;
    int const & rb = b;
    ra = b;
    const int g = 1;
    int& h=b, j=1;
    int *k=&a,l=3;
    //error for ra是一个引用常量,不可指向其他变量
    //ra = b;
    int & rr = a;
    rr = b;
    cout<<a<<b<<ra<<rr<<endl;


    const int c = 55;
    const int d = 60;
    int e = 90;
    const int * p = &c;
    p = &d;    
    cout<<p<<"\t"<<*p<<endl;
    int const * p2 = &c;
    p2 = &d;
    int * const p3 = &e;    
    *p3 = 999;
    cout<<e<<"\t";
    
    return 0;
}