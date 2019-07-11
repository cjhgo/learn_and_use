/**
 * demo to demonstrate the basic usage of pthread
 * */
#include<iostream>
#include<pthread.h>
#include <unistd.h>

using namespace std;

#define NUM_THREADS 5

int global_count=0;

void *add(void *threadid) {
   pthread_detach(pthread_self());
   long tid;
   tid = (long)threadid;
   for(int i =0; i < 10000;i++)
   ++global_count;
   std::cout<<usleep(3000*1000)<<endl;

   cout<<"the global count is"<<global_count<<" in the end at thread "<< tid<<endl;
   pthread_exit(NULL);
}

int main () {
   pthread_t threads[NUM_THREADS];
   int rc;   
       

   for(int i = 0; i < NUM_THREADS; i++ ) {
      cout << "main() : creating thread, " << i << endl;
      rc = pthread_create(&threads[i], NULL, add, (void *)i);
      if( i == 2)
      pthread_detach(threads[i]);
      if (rc) {
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
      }
   }
   // for(int j = 0; j < NUM_THREADS; j++ )
   // {
   //     pthread_join(threads[j], NULL);
   // }
   
   
   cout<<"finally, the global count is :"<<global_count<<endl;
   // pthread_exit(NULL);
   
}