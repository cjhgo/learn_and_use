
#include <iostream>
#include <omp.h>

int main(int argc, char const *argv[])
{
  std::cout<<omp_get_num_threads()<<std::endl;
  int res=0;
  omp_set_num_threads(8);
  #pragma omp forfdsjfdksjsfkd
  for(size_t i = 0; i < 20; i++)
  {
    //#pragma omp critical    
    std::cout<<"hello,world\t"<<i<<std::endl;
    // res += i;
    // std::cout<<omp_get_thread_num()<<"\t"<<res<<"\t"<<i<<std::endl<<std::endl;
  }
  std::cout<<res<<std::endl;
  return 0;
}
