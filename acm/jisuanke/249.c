#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{

	char str1[2000], str2[2000];
	scanf("%s%s",str1, str2);
		int i, j;
		int data[strlen(str1)+1][strlen(str2)+1];
		for (i = 0; i < strlen(str1); ++i)
			data[i][0] = 0;
		data[i][0] = 0;
		for (i = 0; i < strlen(str2); ++i)
			data[0][i] = 0;
		data[0][i] = 0;
		int re = 0;
		for (i = 0; i < strlen(str1); ++i)
		{;
			for (j = 0; j < strlen(str2); ++j)
			{
				//if(str2[j] == str2[j+1])
				//	re++;
				if(str1[i] == str1[i+1])
				{
					data[i + 1][j + 1] = data[i][j];
				}
				else
				{
					data[i + 1][j + 1] = (data[i][j + 1] > data[i + 1][j]) ? data[i][j + 1] : data[i + 1][j];
					if(str1[i] == str2[j])
						data[i + 1][j + 1]++;
				}
			}
		}

	//	for (int i = 1; i <= num1 ; ++i)
	//	{
	//		for (int j = 1; j <= num2 ; ++j)
	//		{
	//			printf("%d ",data[i][j]);
	//		}
	//		printf("\n");
	//	}

		printf("%d\n", data[strlen(str1)][strlen(str2)]+re );
	
	return 0;
}