#include "stdio.h"
#include <math.h>
int main(int argc, char const *argv[])
{
	double a, b, c;
	scanf("%lf%lf%lf",&a,&b,&c);
	if(a+b<=c||a+c<=b||b+c<=a) printf("Error\n");
	else{
	double p = (a+b+c)/2.;
	printf("%.2lf\n", sqrt(p*(p-a)*(p-b)*(p-c)));
	}
	return 0;
}