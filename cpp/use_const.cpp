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
    //error for ra是一个引用常量/常引用/指向常量的引用, 引用本身不可以改变指向
    //ra = b;
    int & rr = a;
    rr = b;//这里不是rr这个引用指向了a,而是把b的值赋给了rr指向的a
    cout<<a<<b<<ra<<rr<<endl;

    const int c = 55;
    const int d = 60;
    int e = 90;
    const int * p = &c; //指向 const int 的指针    
    cout<<p<<"\t"<<*p<<endl;
    p = &d;    //可以改变指向
    cout<<p<<"\t"<<*p<<endl;
    int const * p2 = &c;//还是指向const int的指针
    p2 = &d;//改变指向
    int * const p3 = &e;  //指向 int 的常指针
    *p3 = 999; //可以用来修改指向的int
    cout<<e<<"\t";
    //p3 = &e; 不能改变指向
    const int * const p4 = &c;  //指向 const int 的 常指针
    return 0;
}