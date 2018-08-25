#include<iostream>
#include<pthread.h>
using namespace std;

#define NUM_THREADS 5

int global_count=0;

void *add(void *threadid) {
   long tid;
   tid = (long)threadid;
   for(int i =0; i < 10000;i++)
   ++global_count;
   cout<<"the global count is"<<global_count<<" in the end at thread "<< tid<<endl;
   pthread_exit(NULL);
}

int main () {
   pthread_t threads[NUM_THREADS];
   int rc;   
   for(int i = 0; i < NUM_THREADS; i++ ) {
      cout << "main() : creating thread, " << i << endl;
      rc = pthread_create(&threads[i], NULL, add, (void *)i);
      
      if (rc) {
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
      }
   }
   for(int j = 0; j < NUM_THREADS; j++ )
   {
       pthread_join(threads[j], NULL);
   }
   //pthread_exit(NULL);
   cout<<"finally, the global count is :"<<global_count<<endl;
}