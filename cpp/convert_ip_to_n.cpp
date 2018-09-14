#include<iostream>
#include<sstream>
#include<bitset>
#include<string>
#include<vector>
using namespace std;
int main(int argc, char const *argv[])
{
    string ip = "138.128.211.153";
    string temp;
    bitset<32> nip;
    vector<bitset<8> > sip;
    stringstream ss;
    for(size_t i = 0; i < ip.length();i++)    
    {
        temp += ip[i];
        if( ip[i] == '.' or i == ip.length()-1 )
        {
            int a = std::stoi(temp);
            sip.push_back(bitset<8>(a));  
            //method 1 ,clean 
            ss<<bitset<8>(a);
            temp="";            
        }
    }    
    cout<<ss.str()<<endl;
    cout<<bitset<32>(ss.str())<<endl;
    cout<<bitset<32>(ss.str()).to_ulong()<<endl;
    //methond 2 , normal
    for(size_t i = 0; i < sip.size();i++)
    {
        for(size_t j = 0; j< 8;j++)
        {
            nip[24-i*8+j]=sip[i][j];
        }
    }
    cout<<nip<<endl<<nip.to_ulong()<<endl;
    return 0;
}
