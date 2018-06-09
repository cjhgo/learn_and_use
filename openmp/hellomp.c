#include <stdio.h>
#include <omp.h>

int main(int argc, char const *argv[])
{
	omp_set_num_threads(4);
	#pragma omp parallel
	{
		int id = omp_get_thread_num();
		printf("hello, i am thread %d\n", id);
	}
	return 0;
}
