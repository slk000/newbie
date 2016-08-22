#include <stdio.h>
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	while(n--){
		int data[3],max=0,min=100,i,sum=0;
		for (i = 0; i < 3; ++i)
		{	
			scanf("%d",&data[i]);
			sum += data[i];
			if (data[i]>max) max = data[i];
			if (data[i]<min) min = data[i];
		}
		sum = sum - max -min;
		if(min*min+sum*sum==max*max)
			printf("Y\n");
		else
			printf("N\n");
	}
	return 0;
}