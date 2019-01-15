#include<iostream>
#include<pthread.h>
#include<thread>

static pthread_barrier_t barrier;
void * foo(void* threadid)
{
    int tid=(long) threadid;
    std::cout<<tid<<std::endl;
    pthread_barrier_wait(&barrier);
    std::cout<<tid+10<<std::endl;
}

void bar(int n)
{
    std::cout<<"the n is :"<<n<<std::endl;
    pthread_barrier_wait(&barrier);
    std::cout<<"the n + 10 is :"<<n+10<<std::endl;
}


void use_pthread()
{
    pthread_t t1,t2;
    pthread_barrier_init(&barrier, NULL, 2);
    pthread_create(&t1, NULL, foo, (void *)1);
    pthread_create(&t2, NULL, foo, (void *)2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}

void use_stdthread()
{
    pthread_barrier_init(&barrier, NULL, 2);
    std::thread t(bar, 55), s(bar, 20);
    t.join();
    s.join();
}
int main(int argc, char const *argv[])
{
    use_pthread();
    use_stdthread();
    return 0;
}
