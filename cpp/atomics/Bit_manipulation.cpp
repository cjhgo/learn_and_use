#include<iostream>
#include<bitset>
using namespace std;
int main(int argc, char const *argv[])
{
    int x = 34;
    bitset<8> t(x);
    cout<<t<<endl;    
    cout<<"toggle bit at pos 5"<<endl;
    t=(34 ^ (1<<5));
    cout<<t<<endl;
    cout<<"set bit at pos 5"<<endl;
    t=(34 | (1<<5));
    cout<<t<<endl;
    cout<<"clear bit at pos 5"<<endl;
    t=(34 & ~(1<<5));
    cout<<t<<endl;
    cout<<"test bit at pos 5"<<endl;
    t=(34 & (1<<5));
    cout<<t<<endl;
    auto a = 0b1010 & 0b0111;
    auto b = 0b1010 && 0b0111;
    cout<< a<<endl;//bitwise and -> 0b0010, 2
    cout<< b<<endl;//logic and ->1
    int y = 0;
    cout<<(0 & (++y))<<endl;
    cout<<y<<endl;
    int z = 0;
    cout<<(0 && (++z))<<endl;
    cout<<z<<endl;
    return 0;
}
