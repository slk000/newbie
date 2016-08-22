//http://acm.bjfu.edu.cn/acmhome/problemdetail.do?&method=showdetail&id=1090
//AC
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main ()

{	
	int T;
	
	int carry[8] = {10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};
	scanf("%d", &T);

	char strRes[9];
	int intRes[T];
	int i, k;
	
		for (i = 0; i < T; ++i)
		{

			scanf("%s", strRes);
			intRes[i] = atoi(strRes);//为了快速得到数字长度使用字符串先存一遍
			int len = strlen(strRes);

			int j;

			for (j = len-1; j > 0; --j)//遍历每一位数
			{

				int carryIndex = j+8-len-1;
				int chkCarry = (intRes[i]/carry[carryIndex+1])%10;//取出当前位的数字
				intRes[i] /= carry[carryIndex];
				// printf("a:%d\n", intRes[i]);
				if (chkCarry >= 5)
				{
					intRes[i]++;
					// printf("b:%d\n", intRes[i]);
				}
				intRes[i]*= carry[carryIndex];
				// printf("c:%d\n\n", intRes[i]);
			}

		}
		for (i = 0; i < T; ++i)
		{
			printf("%d\n", intRes[i]);
		}


	return 0;
}
