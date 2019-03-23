#include <stdio.h>
#include <omp.h>
#define MAX_THREADS 4
//$\int_{0}^{1} \frac{4.0}{\left(1+x^{2}\right)} d x=\pi$

static int number_step=100000000;

int main(int argc, char*argv[])
{
  
  double realPI=3.141592653589793238462643;
  double step = 1.0/number_step;
    
  for(size_t j = 1 ; j <= MAX_THREADS; j++)
  {
    double start_time=omp_get_wtime();
    omp_set_num_threads(j);
    double full_sum = 0;
    #pragma omp parallel private(j)
    {
      int nthreads = omp_get_num_threads();
      #pragma omp single
      printf("the number of threads is :%d\n", nthreads);

      int id = omp_get_thread_num();
      double partial_sum = 0, x=0;
      
      for(j = id; j < number_step; j=j+nthreads)
      { 
        x = (j+0.5)*step;
        partial_sum += 4.0/(1+x*x);
      }

      #pragma omp critical
      full_sum += step*partial_sum;
    }

    printf("the res is: %.60f\n",full_sum);
    printf("the  pi is: %.60f\n",realPI);
    printf("spend time %.8f\n", omp_get_wtime()-start_time);
  }

}