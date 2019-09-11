#include <stdlib.h>
#include <iostream>


class RingBuffer2
{
 public:

  RingBuffer2(int capacity_):
  capacity(capacity_),size(0),head(0),tail(0)
  {
    data = (int*)malloc(capacity*sizeof(int));
  }
  void show() const
  {
    for(int i = 0; i < size; i++)
    {
      int index = (head+i)%capacity;
      std::cout<<data[index]<<"\t";
    }
    std::cout<<std::endl;
  }
  bool push(int val)
  {
    if( (tail+1)%capacity == head)
    {
      std::cout<<head<<"\t"<<tail<<"\tbuffer full\n";
      return false;
    }else
    {
      data[tail]=val;
      size++;
      tail=(tail+1)%capacity;
      return true;
    }

  }
  bool pop(int& val)
  {
    if( head == tail)
    {
      std::cout<<head<<"\t"<<tail<<"\tbuffer empty\n";
      return false;
    }else
    {
      val = data[head];
      size--;
      head = (head+1)%capacity;
      return true;
    }
  }
 private:  
  int capacity,size,head,tail;
  int* data;
};
 
class RingBuffer
{
 public:

  RingBuffer(int capacity_):
  capacity(capacity_),size(0),head(0),tail(0)
  {
    data = (int*)malloc(capacity*sizeof(int));
  }
  void show() const
  {
    for(int i = 0; i < size; i++)
    {
      int index = (head+i)%capacity;
      std::cout<<data[index]<<"\t";
    }
    std::cout<<std::endl;
  }
  bool push(int val)
  {
    if(size == capacity)
    {
      std::cout<<head<<"\t"<<tail<<"\tbuffer full\n";
      return false;
    }
    else
    {
      data[tail]=val;
      size++;
      tail = (tail+1)%capacity;
    }
  }
  bool pop(int& val)
  {
    if( size == 0)
    {
      std::cout<<head<<"\t"<<tail<<"\tbuffer empty\n";
      return false;
    }
    else
    {
      val = data[head];
      size--;
      head = (head+1)%capacity;
      return true;
    }
  }
 private:  
  int capacity,size,head,tail;
  int* data;
};

int main(int argc, char const *argv[])
{
  RingBuffer2 rb(8);
  int temp;
  rb.pop(temp);
  rb.show();
  rb.push(1);
  rb.show();
  rb.push(2);
  rb.show();
  rb.push(3);
  rb.show();
  rb.push(4);
  rb.show();
  rb.push(5);
  rb.show();
  rb.push(6);
  rb.show();
  rb.push(7);
  rb.show();
  rb.push(8);
  rb.show();
  rb.push(9);
  rb.show();
  rb.push(10);
  rb.show();  
  rb.push(11);
  rb.show();    
  
  rb.pop(temp);
  rb.pop(temp);
  rb.pop(temp);
  rb.pop(temp);
  rb.show();
  rb.push(9);
  rb.show();
  rb.push(10);
  rb.show();  
  rb.push(11);
  rb.show();      
  rb.push(11);
  rb.show();        
  rb.push(11);
  rb.show();          
  rb.pop(temp);
  rb.pop(temp);
  rb.pop(temp);
  rb.pop(temp);
  rb.pop(temp);
  rb.pop(temp);
  rb.pop(temp);
  rb.pop(temp);
  rb.pop(temp);    
  rb.pop(temp);
  rb.pop(temp);      
  rb.show();  
  return 0;
}