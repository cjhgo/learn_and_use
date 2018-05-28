#include<pthread.h>
#include<stdio.h>
#include <time.h>
// #include<stdlib.h>
// #include<string.h>
// #include<unistd.h>
// #include<pthread.h>

int cnt=0;

void*  fn(void * t)
{
	for (int i = 0; i < 1000000; ++i)
	{
		//__sync_add_and_fetch(&cnt, 1);
		cnt++;
	}
	
}


int main(int argc, char const *argv[])
{
	
	pthread_t* t[32];
	int i;
	for(i = 0; i < 32;i++)	
	{		
		pthread_create(&t[i], NULL, fn, NULL);
	}
	for(i = 0; i < 32;i++)	
	{
		
		pthread_join(t[i], NULL);
	}
	printf("%d\n", cnt);
	return 0;
}