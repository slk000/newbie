#include <cstdio>
#include <cmath>
int main(){
	int n;
	scanf("%d", &n);
	double ans=0;
	for (int i = 0; i < n; ++i)
	{
		double a, b, c, anssingle = 0;
		scanf("%lf%lf%lf", &a, &b, &c);
		ans += sqrt(a*a+b*b)/50.0*2.0;
		ans += c+c*0.5;
		
	}
	ans = ceil(ans);
	printf("%d\n", (int)ans);
	return 0;
}