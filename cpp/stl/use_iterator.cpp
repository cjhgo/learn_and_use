#include<vector>
#include<iterator>
#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    vector<int> v = {1,2,3,4};
    vector<int> v2;
    auto it = inserter(v, v.begin()+2);
    cout<<*(v.begin()+2)<<endl;
    *it = 9;
    *it = 10;
    for(auto e: v)
        cout<<e<<"\t";
    return 0;
}
