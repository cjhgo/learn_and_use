/**
 * demo to demonstrate the impact of atomic
 * */


#include<iostream>
#include<pthread.h>
#include<atomic>
using namespace std;

#define NUM_THREADS 5

int global_count=0;
atomic<int> global_count2;

void *add(void *threadid) {
   long tid;
   tid = (long)threadid;
   for(int i =0; i < 10000;i++)
   ++global_count;
   cout<<"the global count is"<<global_count<<" in the end at thread "<< tid<<endl;
   pthread_exit(NULL);
}
void *atomic_add(void *threadid) {
   long tid;
   tid = (long)threadid;
   for(int i =0; i < 10000;i++)
   ++global_count2;
   cout<<"the global count is"<<global_count2<<" in the end at thread "<< tid<<endl;
   pthread_exit(NULL);
}
int main () 
{
	global_count2=0;
	pthread_t threads[NUM_THREADS];
	int rc;   
	int i,j;
	for(i = 0; i < NUM_THREADS; i++ ) {
		cout << "main() : creating thread, " << i << endl;
		rc = pthread_create(&threads[i], NULL, add, (void *)i);		
		if (rc) {
			cout << "Error:unable to create thread," << rc << endl;
			exit(-1);
		}
	}
	for(j = 0; j < NUM_THREADS; j++ )
	{
		pthread_join(threads[j], NULL);
	}

	cout<<"finally, the global count is :"<<global_count<<endl;
	for(i = 0; i < NUM_THREADS; i++ ) 
	{
		cout << "main() : creating thread, " << i << endl;
		rc = pthread_create(&threads[i], NULL, atomic_add, (void *)i);
		
		if (rc) {
			cout << "Error:unable to create thread," << rc << endl;
			exit(-1);
		}
	}
   for(j = 0; j < NUM_THREADS; j++ )
   {
       pthread_join(threads[j], NULL);
   }
   cout<<"finally, the global count is :"<<global_count2<<endl;
}