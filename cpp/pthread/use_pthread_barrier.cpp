#include<iostream>
#include<pthread.h>

static pthread_barrier_t barrier;
void * foo(void* threadid)
{
    int tid=(long) threadid;
    std::cout<<tid<<std::endl;
    pthread_barrier_wait(&barrier);
    std::cout<<tid+10<<std::endl;
}

int main(int argc, char const *argv[])
{
    pthread_t t1,t2;
    pthread_barrier_init(&barrier, NULL, 2);
    pthread_create(&t1, NULL, foo, (void *)1);
    pthread_create(&t2, NULL, foo, (void *)2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
