#include<iostream>
#include<thread>
#include<mutex>
thread_local int local_a = 0;
int global_a = 0;
std::mutex lock;
void increase(int tid)
{
    lock.lock();
    ++global_a;
    lock.unlock();
    if( tid == 0)
    local_a+= 10;
    else
    local_a+= 20;
    std::cout<<"\n"<<global_a<<"\t"<<local_a<<"\t\n";
}

int main(int argc, char const *argv[])
{
    std::thread t1(increase, 0), t2(increase, 1);
    t1.join();
    t2.join();
    std::cout<<"after the increase "<<global_a<<"\t"<<local_a<<std::endl;
    return 0;
}
