#include <iostream>
#include <thread>
#include"TaskQueue.hpp"
#include <cstdio>
#include <mutex>
#include <condition_variable>
typedef void (*FunType)(void);
struct Task{
  Task(){};
  Task(FunType fun, int id=0)
  :fun(fun),taskid(id){};
  FunType fun;
  int taskid;
};


class ThreadPool
{
public:
  //void launch();
  void run();
  void worker();
  void add(Task t);
  ThreadPool(std::size_t thread_cnt)
  :thread_cnt(thread_cnt)
  {};
  ~ThreadPool();
private:
  std::mutex queue_mutex;
  std::condition_variable condiation;
  size_t thread_cnt;
  std::vector<std::thread> pool;
  TaskQueue<Task> task_queue;  
};