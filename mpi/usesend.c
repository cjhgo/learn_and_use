#include <stdio.h>
#include "mpi.h"


int main(int argc, char const *argv[])
{
	MPI_Init(&argc, &argv);

	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	int number;
	if (world_rank == 0) {
	    number = -1;
	    MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
	} else if (world_rank == 1) {
	    MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD,
	             MPI_STATUS_IGNORE);
	    printf("Process 1 received number %d from process 0\n",
	           number);
	}

	MPI_Finalize();
	return 0;
}
/**
#include <stdio.h>
#include "mpi.h"


int main(int argc, char const *argv[])
{
	int taskid;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &taskid);
	printf("i am rank %d\n", taskid);
	if (taskid == 0)
	{
		MPI_Send(55,1,MPI_INT, 1, 99, MPI_COMM_WORLD);
	}
	if (taskid == 1)
	{
		int t;
		MPI_Status s;
		MPI_Recv(&t,1,MPI_INT, 0, 99, MPI_COMM_WORLD,&s);
		printf("rank %d reev %d\n", taskid, t );	
	}
	MPI_Finalize();
	return 0;
}
**/