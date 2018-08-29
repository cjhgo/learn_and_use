#include "mpi.h"
#include <stdio.h>
#include <math.h>
#define master 0
int main(int argc, char  *argv[])
{
	int n,myid,numprocs;
	double sum,w,Sum;
	double PI25DT = 3.141592653589793238462643;
	double startwtime = 0.0, endwtime;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD,&myid);
	
	n=pow(10,8);
	Sum=sum = 0.0;
	w = 1.0/n;
	printf("%d\n", numprocs);
	if (myid == 0)
		startwtime = MPI_Wtime();
	for (int i = myid+1; i <= n; i+=numprocs)
	{	
		double s = w*sqrt(1-pow(i*1.0/n,2));
		sum += s;
	}

	MPI_Reduce(&sum,&Sum,1,MPI_DOUBLE ,MPI_SUM,master,MPI_COMM_WORLD);
	double pi = 4*Sum;
	if (myid == 0) 
	{
		endwtime = MPI_Wtime();
		printf("%.16f\n", numprocs*sum*4);
		printf("%.16f\n", pi);
		printf("pi is approximately %.16f, Error is %.16f\n",
		       pi, fabs(pi - PI25DT));
		printf("wall clock time = %f\n", endwtime-startwtime);	       	
	}
	
	MPI_Finalize();
	return 0;
}