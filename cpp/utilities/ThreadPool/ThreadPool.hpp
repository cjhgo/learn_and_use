#include <thread>
#include"TaskQueue.hpp"
#include <cstdio>
typedef void (*FunType)(void);
struct Task{
  Task(){};
  Task(FunType fun):fun(fun){};
  FunType fun;
};


class ThreadPool
{
public:
  //void launch();
  void run();
  void worker();
  void add(Task t);
  ThreadPool(std::size_t thread_cnt)
  :thread_cnt(thread_cnt),pool(thread_cnt)
  {};
  ~ThreadPool();
private:
  size_t thread_cnt;
  std::vector<std::thread> pool;
  TaskQueue<Task> task_queue;  
};