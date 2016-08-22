#include <stdio.h>
int main()
{
	int k;
	while(scanf("%d",&k) != EOF) printf("%d\n",(k*(k+1)/2)*(k*(k+1)/2));
	return 0;
}