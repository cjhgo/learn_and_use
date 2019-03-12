#include <queue>

template<typename Task>
class TaskQueue
{
public:
  bool waitAndpop(Task& t)
  {
    if( tasks.empty() )
      return false;
    else
    {
      t = tasks.front();
      tasks.pop();//_front();
      return true;
    }
  }
  void push_back(const Task& val)
  {
      //tasks.push_back(val);
      tasks.push(val);
  }  
private:
  std::queue<Task> tasks;

};