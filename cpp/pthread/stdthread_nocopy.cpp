#include <iostream>
#include <utility>
#include <thread>
#include <chrono>
 
void f1(int n)
{
    for (int i = 0; i < 5; ++i) {
        std::cout << "Thread 1 executing "<<i<<std::endl;
        ++n;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
 
void f2(int& n)
{
    for (int i = 0; i < 5; ++i) {
        std::cout << "Thread 2 executing "<<i<<std::endl;
        ++n;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
 

 
int main()
{
    int n = 0;

    std::thread t1(f1, n + 1); // pass by value
    std::thread t2(f1, n + 1); // pass by value
    std::thread t3;
    //std thread can assign  rvalue, can not assign lvalue
    //t3=t2, wrong
    t3=std::thread(f1,n+1);
    t1.join();
    t2.join();
    t3.join();
    std::cout << "Final value of n is " << n << '\n';
}