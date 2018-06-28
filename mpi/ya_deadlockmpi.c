#include "mpi.h"

#include <stdio.h>

   

int main( int argc, char * argv[  ] )

{

   int datum1 = 19, datum2 = 23, datum3 = 27;

   int datum4, datum5, datum6;

   int noProcesses, processId;

   MPI_Status status;

 

   /* MPI setup */

   MPI_Init(&argc, &argv);

   MPI_Comm_size(MPI_COMM_WORLD, &noProcesses);

   MPI_Comm_rank(MPI_COMM_WORLD, &processId);

    

   if (processId == 0)          /* for rank 0 */

   {  MPI_Recv(&datum4, 1, MPI_INT, 2, 3, MPI_COMM_WORLD, &status);

      MPI_Send(&datum1, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);

      fprintf (stderr, "Received: %d\n", datum4);

   } 

   else if (processId == 1)     /* for rank 1 */

   {  MPI_Recv(&datum5, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);

      MPI_Send(&datum2, 1, MPI_INT, 2, 1, MPI_COMM_WORLD);

      fprintf (stderr, "Received: %d\n", datum5);   

   }

   else                         /* for rank 2 */

   {  MPI_Recv(&datum6, 1, MPI_INT, 1, 1, MPI_COMM_WORLD, &status);

      MPI_Send(&datum3, 1, MPI_INT, 0, 3, MPI_COMM_WORLD);

      fprintf (stderr, "Received: %d\n", datum6);   

    }

   

   MPI_Finalize( );

   return 0;

}