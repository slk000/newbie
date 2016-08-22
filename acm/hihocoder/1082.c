#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	char str[201];
	char* mode = "marshtomp";

	while(EOF != scanf("%s", str)){
		int strLength = strlen(str);
		int isInStr = 0;
		for (int i = 0; i < strLength; ++i)
		{
			if (str[i] == mode[isInStr])
			{
				isInStr++;
			}
			else isInStr = 0;
			
			if (isInStr == 9)
			{
				printf("%d\n", isInStr);
			}
		}
	}
	return 0;
}