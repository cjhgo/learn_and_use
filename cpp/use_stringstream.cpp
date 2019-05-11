#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;

void test1()
{
    ifstream in("usevoid.cpp");
    stringstream ss;
    string line;
    while(getline(in, line))
    {
        cout<<"::::\t"<<line<<endl;
        cout<<"ss write state :"<< bool(ss<<line);

        cout<<"now the ss is "<<ss.str()<<endl;
        // if( ss>>line)
        // cout<<"get the line :"<<line<<endl;
        // else
        // cout<<"get the line fail"<<endl;
        cout<<"??eof??:"<<ss.eof()<<endl;
    }
}
void test2()
{
    ifstream in("use_format.cpp");
    stringstream ss;
    string line;
    while(getline(in, line))
    {
        cout<<"::::\t"<<line<<endl;
        if(ss<<line)
        {        
            cout<<"now the ss is "<<ss.str()<<endl;
            while(not ss.eof())
            {
                if( ss>>line)
                cout<<"get the line :"<<line<<endl;
                else
                cout<<"get the line fail"<<endl;
                cout<<"??eof??:"<<ss.eof()<<endl;
            }
        }
        else
        {
            cout<<"@@@ get line failed!\n";
        }
        //ss.clear();
    }
}

void test3()
{
    stringstream ss("cjh");    
    ss<<"abc";//此时abc会把构造函数中的cjh覆盖
    ss<<"123";//此时123会继续输入到ss中
    cout<<ss.str()<<endl;//最后ss里实际上是abc123
}
int main(int argc, char const *argv[])
{
    test1();
    test2();
    test3();
    return 0;
}