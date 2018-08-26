#include<iostream>
#include<boost/function.hpp>
#include<boost/bind.hpp>
using namespace std;
class pr
{
public:
    void apply()
    {
        cout<<" i am apply at pr"<<endl;
    };
};

template<typename vp>
class use_template
{
public:
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
        boost::function<void(void)> invoke = boost::bind(fn, this);
        cout<<0<<endl;
        invoke();
    }
    
    void use()
    {
        callfun(&use_template::fun);
        callfun(&use_template::bar);
    };
};

int main () 
{
    use_template<pr> ut;
    ut.use();   
    return 0;
}
