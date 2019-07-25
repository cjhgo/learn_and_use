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


void funfoo()
{
    int array[]={1,3,4};
    int a,b;
    cout<<"!!!"<<array[0]<<endl;
}

class Barr
{
public:    
  std::vector<int> vv={1,2,3};
  Barr(){};//这种情况vv根据类内初始化
  Barr(int v):vv{4,5,6}{};//这种情况成员列表初始化优先级高于类内初始化
};


class Fuu
{
public:
    int array[3]={3,5,7};
    int n = 99;
    int ba{44};
    const static int  bb[2];//static的const int[2]不能类内初始化={3,9};
    constexpr static int d[2]={3,9}; //static constexpr必须类内初始化
    static const int a = 1;    
    enum { arrsize = 2 };
    static const char b = 'b';
    
    
    vector<int> v{1,2,3,4};//since c++11,普通变量可以类内初始化
    static vector<int> vv;//static类变量不能类内初始化

//     //non-const-integral,non enum,non literaltype,不能in-class initialization
//     const static int f[2];
//     //non-static array ,since c++11 ,可以 in-class initialization
//     //但是,必须指明size
//     //在函数中,int z[]={1,2,3}是允许的
//     int z[3]={1,2,3};

    
    //不能值初始化,Bar yourbar(33);因为这会被优先处理为一个函数声明
    Bar yourbar = Bar(33);//直接初始化
    Bar mybar{33};//初始化列表
    
    Fuu():array{1,2,3}//member initialization
    {
        //在函数中,可以从初始化列表中推断x的size
        int x[]={1,2,3};
    };
};
// const int Foo::f[2] = {1,2};
// vector<int> Foo::vv{3,5,6,7};
// const vector<int> Foo::vvv{8,8,8,8};
int main(int argc, char const *argv[])
{
    // Foo f;
    // Foo::vv[0] = 9;//ok    
    //Foo::vvv[0] = 10; error
    Fuu fu;
    funfoo();
    Barr b, bb(3);
    std::cout<<b.vv[0]<<"\t"<<bb.vv[0]<<std::endl;
    return 0;
}