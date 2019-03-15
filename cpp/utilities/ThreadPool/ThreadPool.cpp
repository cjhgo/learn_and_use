#include "ThreadPool.hpp"


void ThreadPool::worker()
{
  while(true)
  {
    Task t;
    {
      std::unique_lock<std::mutex> lock(this->queue_mutex);
      if( this->task_queue.empty())
        this->condiation.wait(lock, [this]
          {
            return !this->task_queue.empty();
          });
      this->task_queue.waitAndpop(t);
    }
    t.fun();
    std::cout<<t.taskid<<std::endl;
  }
}

void ThreadPool::add(Task t)
{
  {
    std::unique_lock<std::mutex> lock(this->queue_mutex);
    task_queue.push_back(t);
  }
  this->condiation.notify_one();
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