#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;
static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std:cin.tie(nullptr);
    return nullptr;
}(); 
int main(int argc, char const *argv[])
{
    vector<int> a{1,2,3};
    vector<int> b{1,2,3};
    set<vector<int>> sv;
    sv.insert(a);
    sv.insert(b);
    cout<<sv.size()<<endl;
    return 0;
}