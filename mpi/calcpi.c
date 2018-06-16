#include <stdio.h>
#include <math.h>

int main(int argc, char  *argv[])
{
	int n = pow(10,9);
	double w =  1.0/n;
	double S = 0;
	for (int i = 1; i <= n; ++i)
	{
		double s = w*sqrt(1-pow(i*1.0/n,2));
		S +=s;
	}
	printf("%.16f\n", 4*S);
	return 0;
}