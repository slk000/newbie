/*#include <stdio.h>
int main(int argc, char const *argv[])
{
	int N;
	while(scanf("%d",&N) != EOF)
	{	
		int data[N], i, j, res = 0;
		for (i = 0; i < N; ++i)
		{
			scanf("%d",&data[i]);
		}

		for (i = 0; i < N - 1; ++i)
		{
			for (j = 0; j < N - i - 1; ++j)
			{
				if(data[j] > data[j+1])
				{
					int tmp = data[j];
					data[j] = data[j+1];
					data[j+1] = tmp;
				}
			}
		}

		for (i = 0, res = 0; i < N; i++)
		{
			for (j = 0; j <= i; j++)
			{
				res += data[j];
			}
		}
		if(res > 240)
			printf("No\n");
		else
			printf("%d\n", res);
	}
	return 0;
}
*/
#include <stdio.h>
void Qsort(int a[],int low,int high)
{
 if(low>=high) return;
 int first=low;
 int last=high;
 int key=a[first];/*用字表的第一个记录作为枢轴*/
 while(first<last)
 {
 while(first<last&&a[last]>=key) --last;
 a[first]=a[last];/*将比第一个小的移到低端*/
 while(first<last&&a[first]<=key) ++first;
 a[last]=a[first];/*将比第一个大的移到高端*/
 }
 a[first]=key;/*枢轴记录到位*/
 Qsort(a,low,first-1);
 Qsort(a,first+1,high);
}
int main(int argc, char const *argv[])
{
	int N;
	//scanf("%d",&N);
	while(EOF != scanf("%d",&N)){
		int data[N], i, res = 0;
		for (i = 0; i < N; ++i)
		{
			scanf("%d",&data[i]);
		}
		Qsort(data,0,N-1);
		for (i = 0; i < N; ++i)
		{
			res += data[i] * (N - i);
		}

		if(res<=240)printf("%d\n", res);
		else printf("No\n");
	}
	return 0;
}
