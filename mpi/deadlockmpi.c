#include <stdio.h>
#include "mpi.h"
//it turns out the deadlock does not happen,,,
//https://www.dartmouth.edu/~rc/classes/intro_mpi/mpi_race_conditions.html

int main(int argc, char  *argv[])
{
	MPI_Init(&argc, &argv);

	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	int a[10000] ,b[10000];
	MPI_Status s;
	if (world_rank == 0) {
	    MPI_Send(&a, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
	    MPI_Recv(&b, 1, MPI_INT, 1, 0, MPI_COMM_WORLD,
	    		&s);
	} 
	else if (world_rank == 1) {
		MPI_Send(&a, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
		MPI_Recv(&b, 1, MPI_INT, 0, 0, MPI_COMM_WORLD,
				&s);

	}
	printf("rank %d now with %d,%d\n",world_rank,(int)a,(int)b);
	MPI_Finalize();
	return 0;
}