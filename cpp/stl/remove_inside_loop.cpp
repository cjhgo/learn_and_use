#include<iostream>
#include<vector>
#include<utility>
using namespace std;
void print(const vector<int>& v)
{
    cout<<"\nthe size is :"<<v.size()<<endl;
    for(auto e: v)
    cout<<e<<"\t";
    cout<<endl;
}
int main(int argc, char const *argv[])
{
    vector<int> v1={2,3,1,6,4,5,7,11,8,13,9};
    vector<vector<int>> r;    
    
    while(v1.size() > 0)
    {
        int cur_max = 0;
        vector<int> temp;
        auto it = v1.begin();
        while(it != v1.end())
        {
            if(*it > cur_max)
            {
                cur_max = *it;
                temp.push_back(*it);
                it = v1.erase(it);
            }
            else
            ++it;
        }
        r.push_back(temp);
    }
    print(r[0]);
    print(r[1]);
    print(v1);
    return 0;
}
