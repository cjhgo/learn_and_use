#include "ThreadPool.hpp"


void ThreadPool::worker()
{
  while(true)
  {
    Task t;
    if(task_queue.waitAndpop(t))
    {
        t.fun();
    }
  }
}

void ThreadPool::add(Task t)
{
  task_queue.push_back(t);
}

void ThreadPool::run()
{
    for(std::size_t i = 0; i < thread_cnt; i++)
    {
        //pool.emplace_back([this] { worker(); });
        pool[i]=std::thread([this] { worker(); });
    }
}

ThreadPool::~ThreadPool()
{
  for(auto& thread : pool)
  thread.join();
}