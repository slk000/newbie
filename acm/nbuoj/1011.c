#include "stdio.h"
#include <math.h>
int main()
{
	double a,b,c,p;
	scanf("%lf%lf%lf",&a,&b,&c);
	p = (a+b+c)/2.;
	printf("%.2lf\n", sqrt(p*(p-a)*(p-b)*(p-c)));

	return 0;
}