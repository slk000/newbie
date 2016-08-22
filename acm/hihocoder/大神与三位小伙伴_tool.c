#include <stdio.h>
int main(int argc, char const *argv[])
{
	int count = 3, sum =0;
	printf("start\n");
	for (int a = 1; a <= count; ++a)
	{
		for (int b = 1; b <= count; ++b)
		{
			for (int c = 1; c <= count; ++c)
			{
				//for (int d = 1; d <= count; ++d)
				//{
					//if(!(!(a==b&&b==c)&&(a==c||a==b||b==c))){
						sum++;
						printf("(%d,%d,%d):%d*%d*%d=%d\n",a,b,c,(count+1-a),(count+1-b),(count+1-c),(count+1-a)*(count+1-b)*(count+1-c));

					//}
				//}
			}
		}
	}
	printf("%d\n", sum);
	return 0;
}