#include<iostream>
#include<vector>
#include<string>
#include<map>
#include "observer.hpp"
using namespace std;


class ObserverA : public Observer
{
  void update()
  {
    std::cout<<"i am class A"<<std::endl;
  }
};

class ObserverB : public Observer
{
  void update()
  {
    std::cout<<"i am class B"<<std::endl;
  }
};



void test1()
{
  
}

int main(int argc, char const *argv[])
{
  Observable *obj = new Observable;
  ObserverA *a = new ObserverA;
  ObserverB *b = new ObserverB;
  a->observe(obj);
  b->observe(obj);
  obj->notifyObservers();
  delete a;
  delete b;
  obj->notifyObservers();
  return 0;
}