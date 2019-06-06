#include <vector>
#include <algorithm>

class Observer;
class Observable;

class Observer
{

private:
  Observable * subject;
public:
  virtual ~Observer();
  virtual void update()=0;
  void observe(Observable* s);
};


class Observable
{
  
public:
  void register_(Observer* x)
  {
    observers_.push_back(x);
  }
  void unregister(Observer* x)
  {
    auto it = std::find(observers_.begin(),observers_.end(),x);
    if( it != observers_.end())
    {
      observers_.erase(it);
    }
  }

  void notifyObservers()
  {
    for(Observer* x :observers_)
      x->update();
  }
private:
  std::vector<Observer*> observers_;
};


Observer::~Observer()
{
  subject->unregister(this);
}
void Observer::observe(Observable* s)
{
  s->register_(this);
  subject = s;
}