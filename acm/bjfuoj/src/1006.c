#include <stdio.h>
#include <memory.h>
int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	while(T--){
		int data[100002],tmp,i,m;
		memset(data,0,sizeof data);
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d",&tmp);
			data[tmp]++;
		}
		for (i = 0; i < 100002; ++i)
		{
			if (data[i])
			{
				printf("%d\n", i);
			}
		}
	}
	return 0;
}