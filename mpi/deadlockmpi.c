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
	    MPI_Request r;
	    MPI_Isend(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &r);
	} else if (world_rank == 1) {
	    MPI_Irecv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD,
	             MPI_STATUS_IGNORE);
	    printf("Process 1 received number %d from process 0\n",
	           number);
	}

	MPI_Finalize();
	return 0;
}