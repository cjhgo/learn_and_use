#include<iostream>
class A
{
public:    
    int a;
    A(int b):a(b){}
};
class B
{
public:    
    int a;
    B(int b):a(b){}
    int operator()(void)
    {
        return 999;
    }
    operator A()
    {
        std::cout<<"execute user defined conversion!\n";
        return A(a+5);
    }

};
int main(int argc, char const *argv[])
{

    B x(55);
    A y=x;
    std::cout<<y.a<<std::endl;
    std::cout<<x()<<std::endl;
    return 0;
}