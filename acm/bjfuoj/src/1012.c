//http://acm.bjfu.edu.cn/acmhome/problemdetail.do?&method=showdetail&id=1012
//AC
//素筛
#include <stdio.h>
#include <memory.h>
int prime[5000002];

int main(int argc, char const *argv[])
{
	long long i,j;
		memset(prime,1,sizeof prime);
		for (i = 3; i <= 10000000; i+=2)
		{
			if (prime[(i-1)/2])
			{
				for (j = i*i; j <= 10000000; j+=2*i)
				{
					prime[(j-1)/2] = 0;
				}
			}
		}
	
	int T=1;
int i,j;
	scanf("%d",&T);
	while(T--)
	{
		int M=1,N=10000000;
		scanf("%d%d",&M,&N);
		
		int count =0;
		for (i = (M==1?2:M); i <= N ; ++i)
		{
			if ((i!=2 && i%2 == 0 )|| !prime[(i-1)/2]) continue;
			count++;
		}
		for (i = (M==1?2:M); i <= N ; ++i)
		{
			if ((i!=2 && i%2 == 0 )|| !prime[(i-1)/2]) continue;
			printf("%d",i);
			if(--count) printf(",");
		}
		printf("\n");
		
	}
	return 0;
}