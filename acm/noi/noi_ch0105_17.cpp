#include <cstdio>
#include <cmath>
int main(){
	double h;
	scanf("%lf", &h);
	double ans1 = 0;

	ans1 = h + h/2*2 + h/4*2 + h/8*2 + h/16*2 + h/32*2 + h/64*2 + h/128*2 + h/256*2 + h/512*2;
	printf("%g\n", ans1);
	printf("%g\n", h/1024.);
	return 0;
}

