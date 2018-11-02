#include<iostream>
#include<iterator>
#include<algorithm>
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
    vector<int> nums = {2,4,5,8,7,0,9,1,3,6};
    auto it = max_element(nums.begin(), nums.end());
    size_t pos = distance(nums.begin(), it);
    cout<<*it<<"\t"<<nums[pos]<<endl;
    return 0;
}