#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

 
 
int main()
{
    std::vector<int> v = {3,5,7,2,9,6,4};
    std::cout << "Original vector:\n";
    for(int elem : v) std::cout << elem << ' ';
    
    auto it = std::partition(v.begin(), v.end(), [](int e){return e < 3;});
    std::cout<<std::endl<<*it<<"\t"<<std::distance(v.begin(),it)<<std::endl;
    for(int elem : v) std::cout << elem << ' ';
}