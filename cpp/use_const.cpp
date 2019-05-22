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


void const_and_pointer()
{
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
}

void const_and_reference()
{
    int a = 5, b = 6;
    const int & ra = a;
    int const & rb = b;        
    //error for ra是一个引用常量/常引用/指向常量的引用, 引用本身不可以改变指向
    //ra = b;
    int & rr = a;
    rr = b;//这里不是rr这个引用指向了a,而是把b的值赋给了rr指向的a
    cout<<a<<b<<ra<<rr<<endl;
}

int getsize() 
{
    int d;
    cin>>d;
    return d;
}

void use_constexpr()
{
    int d = 22;
    const int & e = d*3;
    //int& f =d*4;
    double dd = 23.01;
    // int & f = dd;
    const int & f = 3.14;
    cout<<e<<endl;
    char x[5]{0};
    int l = getsize();
    char y[l]{0};
    cout<<sizeof(y);
}
int main(int argc, char const *argv[])
{
    
    const_and_reference();
    const_and_pointer();
    use_constexpr();
    return 0;
}