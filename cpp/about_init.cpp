#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

typedef struct Bar
{
    int b;
    Bar(int bb):b(bb){};
}Bar;

class Foo
{
public:       
    const static int a = 1;    
    enum { arrsize = 2 };//
    const static int  b[2];
    constexpr static int c[2] = {1,2};

    //error for 必须in-class initialization
    //constexpr static int d[2]; 

    //error for 必须是const
    //static int e = 3;

    //non-const-integral,non enum,non literaltype,不能in-class initialization
    const static int f[2];
    //non-static array ,since c++11 ,可以 in-class initialization
    //但是,必须指明size
    //在函数中,int z[]={1,2,3}是允许的
    int z[3]={1,2,3};

    vector<int> v{1,2,3,4};//since c++11
    static vector<int> vv;
    const static vector<int> vvv;
    //不能这么写,Bar yourbar(33);因为这会被优先处理为一个函数声明
    Bar yourbar = Bar(33);
    Bar mybar{33};//since c++11
    
    int arr[3];

    Foo():arr{1,2,3}//member initialization
    {
        int x[]={1,2,3};//在函数中,不指明size的array initialization是允许的
    };
};
const int Foo::f[2] = {1,2};
vector<int> Foo::vv{3,5,6,7};
const vector<int> Foo::vvv{8,8,8,8};
int main(int argc, char const *argv[])
{
    Foo f;
    Foo::vv[0] = 9;//ok    
    //Foo::vvv[0] = 10; error
    return 0;
}