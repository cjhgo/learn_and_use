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
int main(int argc, char const *argv[])
{
    test1();
    test2();
    return 0;
}