#include <stdio.h>
int main(int argc, char const *argv[])
{
	int i,ii;

	for(i = 1,ii = i * i; ii <10000; i++){
		
		if((ii/1000 == ii%1000/100)&&(ii%100/10 == ii%10))
		{
			printf("%d\n", ii);
		}
		//2211
	}
	return 0;
}