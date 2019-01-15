#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;
struct barrier_type1
{
    std::mutex lock;
    bool exit_flag;
    int arrive_counter;
    int leave_counter;
    int thread_numb;
    barrier_type1(int n)
    :exit_flag(true), thread_numb(n),arrive_counter(0),leave_counter(n)
    {}
    void wait()
    {
        lock.lock();
        if( arrive_counter == 0)
        {
            if( leave_counter == thread_numb)
            {
                exit_flag=false;
            }
            else
            {
                lock.unlock();
                while(leave_counter != thread_numb);
                lock.lock();
                exit_flag=false;
            }
        }
        int arrived = ++arrive_counter;        
        lock.unlock();
        if( arrived == thread_numb)
        {
            //std::cout<<"last thread arrive \n";
            exit_flag=true;
            arrive_counter=0;
            leave_counter=1;
        }
        else
        {
            while(exit_flag == false)
            {
                //std::cout<<"thread waitting \n";
            };
            lock.lock();
            leave_counter++;
            lock.unlock();
        }        
    }
};
struct barrier_type2
{
    std::mutex lock;
    std::condition_variable cv;
    bool flag;
    int arrive_counter;
    int leave_counter;
    int thread_numb;
    barrier_type2(int n)
    :thread_numb(n),arrive_counter(0),leave_counter(n)
    {}
    void wait()
    {
        std::unique_lock<std::mutex> lk(lock);
        if( arrive_counter == 0)
        {
            if( leave_counter != thread_numb)
            {
                while(leave_counter != thread_numb);
            }
        }        
        ++arrive_counter;
        if( arrive_counter == thread_numb)
        {
            cv.notify_all();
        }
        else
        {
            cv.wait(lk);
        }
    }
};
static barrier_type1 barrier1(2);
static barrier_type2 barrier2(2);
void foo(int tid)
{
    std::cout<<"i am the thread "<<tid<<std::endl;
    barrier1.wait();
    std::cout<<"after wait one i am the thread "<<tid+10<<std::endl;
    barrier1.wait();
    std::cout<<"after wait two i am the thread "<<tid+100<<std::endl;
    barrier1.wait();
    std::cout<<"after wait three i am the thread "<<tid+1000<<std::endl<<std::endl;
}
int main(int argc, char const *argv[])
{        
    std::thread t1(foo, 3), t2(foo,5);
    t1.join();
    t2.join();
    std::cout<<"---------------\n";
    return 0;
}