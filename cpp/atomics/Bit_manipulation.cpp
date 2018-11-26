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
    return 0;
}