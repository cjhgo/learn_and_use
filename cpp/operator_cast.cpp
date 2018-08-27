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
    operator A()
    {
        return A(a);
    }
};
int main(int argc, char const *argv[])
{

    B x(55);
    A y(x);
    std::cout<<y.a<<std::endl;
    return 0;
}
