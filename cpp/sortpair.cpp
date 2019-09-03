#include <iostream>
#include <vector>
#include <algorithm>


typedef std::pair<int,int> ele_type;
typedef std::vector<ele_type> input_type;



int main(int argc, char const *argv[])
{
  
  input_type ori_input={
    {1,1},{1,2},{1,3},{2,2},{3,2}
  };
  input_type in1 = ori_input,in2=ori_input;

  
  std::sort(in1.begin(),in1.end(),
      [](const ele_type &left, const ele_type & right)
      {
        if(left.second == right.second)
          return left.second < right.second;
        else
          return left.second < right.second;
      }
    );
  std::sort(in2.begin(),in2.end());    
  for(auto e: in1)
  {
    std::cout<<e.first<<"\t"<<e.second<<std::endl;
  }
  std::cout<<std::endl;
  for(auto e: in2)
  {
    std::cout<<e.first<<"\t"<<e.second<<std::endl;
  }  
  return 0;
}
