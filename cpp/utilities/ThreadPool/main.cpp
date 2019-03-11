#include "ThreadPool.hpp"
#include <thread>
#include <chrono>
#include <stdio.h>
void long_task()
{
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

int main(int argc, char const *argv[])
{
  ThreadPool tp(std::thread::hardware_concurrency());
  for(size_t i = 0; i < 100; i++)
  {
      Task t;
      t.fun=long_task;
      tp.add(t);
  }  
  tp.run();
  return 0;
}