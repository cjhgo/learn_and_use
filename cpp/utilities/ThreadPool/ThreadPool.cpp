#include "ThreadPool.hpp"


void ThreadPool::worker()
{
  while(true)
  {
    if(task_queue.empty())
    std::this_thread::sleep_for(std::chrono::milliseconds(10000));
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
      pool.emplace_back([this] { worker(); });
    }
    for(auto& thread : pool)
    thread.join();
}

ThreadPool::~ThreadPool()
{

}