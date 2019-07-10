#include<iostream>
#include<vector>


struct MyVector
{
  MyVector(std::vector<int> vv):data(vv){};
  std::vector<int> data;
};


std::vector<int>::iterator begin(MyVector& v)
{
  return v.data.begin()+2;
}

std::vector<int>::iterator end(MyVector& v)
{
  return v.data.end()-1;
}

int main(int argc, char const *argv[])
{
  MyVector a({1,2,3,4,5,6,7});
  
  for(auto e : a)
  {
    std::cout<<e<<"\t";
  }

  return 0;
}