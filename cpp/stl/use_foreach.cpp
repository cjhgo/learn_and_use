#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int main(int argc, char const *argv[])
{
    vector<int> v = {1,2,3,4};
    for_each(v.begin(), v.end(), [](int& val){
        val = val*val;
    });
    for(auto e: v)cout<<e<<"\t";
    cout<<endl;
    for_each(v.begin(), v.end(), [](int val){
        val = val*val;
    });    
    for(auto e: v)cout<<e<<"\t";
    return 0;
}
