#include <stdio.h>
#include <memory.h>
int main(int argc, char const *argv[])
{
	int prime[5000],i,j;
	memset(prime,1,sizeof prime);

	for (i = 3; i < 10000; i+=2)
	{
		if (prime[(i-1)/2])
		{
			for (j = i*i; j < 10000; j+=2*i)
			{
				prime[(j-1)/2] = 0;
			}
		}
	}
	/* check array prime */
	for (int i = 0; i < 5000; ++i)
	{
		printf("%d:%d\t",i*2+1,!!prime[i] );
	}

	for (int i = 1; i < 5000; i+=2)
	{
		if(prime[(i-1)/2]) printf("%d\t",i );
	}

	/* 1052 */

	int N;		
	while(scanf("%d",&N) != EOF){
		if (!N) break;
		else if(N == 2) printf("Yes\n");
		else{
			if (prime[(N-1)/2] && N&1)
			{
				printf("Yes\n");
			}
			else{
				printf("No\n");
			}
		}
	}
	/* 1052 */

	/* 1020 */
	// prime[0] = 0;
	// int n,tmp,sum = 0;
	// scanf("%d",&n);
	// while(n--){
		
	// 	scanf("%d",&tmp);
	// 	if(tmp == 2) sum += 2;
	// 	else if(prime[(tmp-1)/2] && tmp&1) sum += tmp;
	// }
	// printf("%d\n", sum);
	/* 1020 */
	return 0;
}