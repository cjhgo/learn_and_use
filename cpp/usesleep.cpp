
#include<iostream>
#include <unistd.h>


using namespace std;

int main(int argc, char const *argv[])
{

  unsigned int usecs = 1000*1000;
  std::cout<<usleep(usecs)<<endl;
  std::cout<<"ahhhhh\n"<<endl;
  std::cout<<usleep(3000*1000)<<endl;
  std::cout<<"bhhhhh\n"<<endl;
  return 0;
}