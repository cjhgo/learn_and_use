#include <stdio.h>
#include <omp.h>
//$\int_{0}^{1} \frac{4.0}{\left(1+x^{2}\right)} d x=\pi$

static int number_step=1000000;

int main(int argc, char*argv[])
{
  double res = 0;
  double realPI=3.141592653589793238462643;
  double step = 1.0/number_step;
  #pragma omp parallel 
  {    
    #pragma omp for reduction(+:res)
    for(size_t i = 0; i < number_step; i++)
    {    
      double x = (i+0.5)*step;
      res += 4.0/(1+x*x);
    }
  }
  printf("the res is: %.60f\n",res*step);
}