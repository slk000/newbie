#include <stdio.h>
int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		int out = 2*n+1;
		int in = 2*n-3;
		int i,j;
		for (i = 0; i < out; ++i) printf("*"); 	//1
		printf("\n*");							//2
		for (i = 0; i < out-2; ++i) printf(" ");//2
		printf("*\n");							//2
		if(n!=2){
			printf("* ");
			for (i = 0; i < in; ++i) printf("*");
			printf(" *\n");
		}
		
		for (i = 0; i < in-2; ++i)
		{
			printf("* *");
			for (j = 0; j < in-2; ++j) printf(" ");
			printf("* *\n");
		}
		printf("* ");
		for (i = 0; i < in; ++i) printf("*");
		printf(" *\n*");
		for (i = 0; i < out-2; ++i) printf(" ");//-2
		printf("*\n");//-2
		for (i = 0; i < out; ++i) printf("*");//-1
		printf("\n");
	}
	return 0;
}