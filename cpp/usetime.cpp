#include <iostream>
#include <iomanip>
#include <sys/time.h>
#include <unistd.h>
double get_seconds()
{
  struct timeval tp;
  gettimeofday(&tp, NULL);
  return (double)(tp.tv_sec + ((1e-6) * tp.tv_usec));
}


int main(int argc, char const *argv[])
{
  std::cout<<std::setprecision(32)<<get_seconds()<<std::endl;
  usleep(6000*1000);
  std::cout<<std::setprecision(32)<<get_seconds()<<std::endl;
  return 0;
}