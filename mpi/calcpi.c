#include <stdio.h>
#include <math.h>

int main(int argc, char  *argv[])
{
	int n = pow(10,8);
	double w =  1.0/n;
	double S = 0;
	double PI25DT = 3.141592653589793238462643;
	for (int i = 1; i <= n; ++i)
	{
		double s = w*sqrt(1-pow(i*1.0/n,2));
		S +=s;
	}
	double pi = 4*S;
	printf("%.16f\n", pi);
	printf("pi is approximately %.16f, Error is %.16f\n",
		       pi, fabs(pi - PI25DT));	
	return 0;
}