#include <queue>

template<typename Task>
class TaskQueue
{
public:
  bool empty()
  {
    return tasks.empty();
  }
  bool waitAndpop(Task& t)
  {
    if( tasks.empty() )
      return false;
    else
    {
      t = tasks.front();
      tasks.pop();
      return true;
    }
  }
  void push_back(const Task& val)
  {
      tasks.push(val);
  }  
private:
  std::queue<Task> tasks;

};