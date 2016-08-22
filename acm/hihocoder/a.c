#include <stdio.h>
#include <memory.h>
int main(int argc, char const *argv[])
{
	int lie[100] , tmp;
	memset(lie,0,sizeof lie);
	int m, n, min = 0;
	scanf("%d%d",&m,&n);
	int data[m][n+1];
	for (int i = 0; i < m; ++i)
	{

		for (int j = 0; j < n; ++j)
		{

			if(!lie[j]){
				scanf("%d",&data[i][j]);
				if(!j)  data[i][n] = data[i][j];
				else if(data[i][j] <= data[i][n]) {
					data[i][n] = data[i][j];
					lie[j] = 1;
				}
			}
			else{
				scanf("%d",&tmp);
			}

		}
	}

//	for (int i = 0; i < m; ++i)
//	{
//		printf("%d\n", data[i][n]);
//	}
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%d ",data[i][j]);
		}
		printf("\n");
	}
	return 0;
}