#include <stdio.h>
int main(int argc, char const *argv[])
{
	int T, a, b, i, j, k;
	scanf("%d",&T);
	for (i = 0; i < T; ++i)
	{
		scanf("%d%d",&a,&b);
		if(!((  (a>b?a:b) < 10) && ((a<b?a:b) > 0) && (a <= b)) ){
			printf("Input Error!");
			if((i == T-1 ) )
			{
				return 0;				
			}
			else
				printf("\n");
		}
		else
		{
			for (j = a; j <= b; ++j)
			{
				for (k = 1; k <= j; ++k)
				{
					printf("%d*%d=%-2d ",j,k,j*k);
					
				}
				if((i == T-1 && j == b) )
				{
					return 1;
				}
				else
					printf("\n");

			}
		}
			printf("\n");
	}
	return 0;
}