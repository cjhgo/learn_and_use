#include <memory>
#include <mutex>
#include <thread>
#include <iostream>

#define CNT 1000


std::shared_ptr<int> g,g2;
std::mutex mut;
void readg()
{
  std::shared_ptr<int> temp;  
  int sum=0;
  
  for(int i = 0; i < CNT; i++)
  {
    temp.reset();
    {
      // std::lock_guard<std::mutex> lock(mut);      
      temp=g;
    }
    
    sum += *temp;
  }
  std::cout<<sum<<std::endl;
}

wrtieg2()
{

}
void writeg()
{
  
  for(int i = 0; i < CNT;i++)
  {    
    std::shared_ptr<int> temp(new int(3));
    {
      // std::lock_guard<std::mutex> lock(mut);      
      g=temp;
    }
    
  }
}


int main(int argc, char const *argv[])
{

  g.reset(new int(3));
  std::thread t1(readg),t2(writeg);
  t1.join();
  t2.join();
  return 0;
}


