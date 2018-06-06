#include <stdio.h>
#include "mpi.h"


int main(int argc, char const *argv[])
{
	int taskid;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &taskid);
	printf("i am rank %d\n", taskid);
	MPI_Finalize();
	return 0;
}
