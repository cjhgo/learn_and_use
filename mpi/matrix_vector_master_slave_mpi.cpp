#include "mpi.h"
#include <stdio.h>
#include <iostream>
#include <algorithm>

#define  SIZE 10000

void master_code(int num_proces)
{
    
    std::cout<<"????\n";
    double**  matrix= new double *[SIZE];
    for(size_t j = 0; j < SIZE; j++)
    matrix[j]=new double[SIZE];
    //[SIZE], 
    double res[SIZE];
    double dot_prodcut;
    size_t num_sent=0;
    int sender,row;
    std::cout<<"????\n";
    MPI_Status mpi_status;
    int a;
    std::cin>>a;
    for(size_t i = 0; i < SIZE; i++)
    for(size_t j = 0; j < SIZE; j++)
        matrix[i][j] = (double)j;
    
    
    std::cout<<"????\n";
    for(size_t k=1; k < std::min(SIZE+1, num_proces); k++)
    {
        MPI_Send(matrix[k-1], SIZE, MPI_DOUBLE, k, k, MPI_COMM_WORLD);
        num_sent++;
    }
    std::cout<<"????\n";
    for(size_t k=0; k < SIZE; k++)
    {
        MPI_Recv(&dot_prodcut, 1, MPI_DOUBLE, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &mpi_status);
        sender = mpi_status.MPI_SOURCE;
        row = mpi_status.MPI_TAG -1;
        res[row] = dot_prodcut;
        if( num_sent < SIZE)
        {
            MPI_Send(matrix[num_sent], SIZE, MPI_DOUBLE, sender, num_sent+1, MPI_COMM_WORLD);
            num_sent++;
        }
        else
        {
            MPI_Send(MPI_BOTTOM, 0, MPI_DOUBLE, sender, 0, MPI_COMM_WORLD);
        }
    }       
    for(size_t i = 0; i < SIZE; i++) 
    std::cout<<res[i]<<std::endl;
}
void slave_code()
{
    double vector[SIZE], myrow[SIZE];
    MPI_Status mpi_status;
    for(size_t i = 0; i < SIZE; i++)
    vector[i]=1.0;
    int myrank;
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    if( myrank <= SIZE)
    {
        MPI_Recv(myrow, SIZE, MPI_DOUBLE, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &mpi_status);
        while( mpi_status.MPI_TAG > 0)
        {
            int row = mpi_status.MPI_TAG - 1;
            double dot_prodcut = 0;
            for(size_t i = 0; i < SIZE; i++)
                dot_prodcut = vector[i]*myrow[i];
            MPI_Send(&dot_prodcut, 1, MPI_DOUBLE, 0, row+1, MPI_COMM_WORLD);
            MPI_Recv(myrow, SIZE, MPI_DOUBLE, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &mpi_status);
        }
    }
}

int main(int argc, char * argv[])
{
    int num_proces, myrank;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &num_proces);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);


    if( myrank == 0)
    {
        std::cout<<"????\n";
        master_code(num_proces);
    }        
    else
        slave_code();
    MPI_Finalize();
    return 0;
}