#include "ThreadPool.hpp"
#include <thread>
#include <chrono>
#include <cstdio>
#include <iostream>
void long_task()
{
  std::cout<<"iiii\n";
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  std::cout<<"jjjj\n";
}

int main(int argc, char const *argv[])
{
  ThreadPool tp(std::thread::hardware_concurrency());
  for(size_t i = 0; i < 100; i++)
  {
      tp.add(Task(long_task,i));
  }  
  tp.run();
  return 0;
}