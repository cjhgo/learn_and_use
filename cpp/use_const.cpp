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
    //error for ra是一个引用常量,不可指向其他变量
    //ra = b;
    int & rr = a;
    rr = b;
    cout<<a<<b<<ra<<rr<<endl;
    return 0;
}