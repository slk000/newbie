//AC
#include <cstdio>
#include <string.h>
int main(){
	char *str1[]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
	char *str10[]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
	char *str100[]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
	char *str1000[]={"","M","MM","MMM"};
	char num[5];
	scanf("%s", num);
	int length = strlen(num);
	for (int i = 0; i < length; ++i)
	{
		int base=length-i;
		char **pstr[]={str1,str10,str100,str1000};
		// switch(base){
		// 	case 4:
		// 		printf("%s", str1000[num[i]-'0']);
		// 		break;
		// 	case 3:
		// 		printf("%s", str100[num[i]-'0']);
		// 		break;
		// 	case 2:
		// 		printf("%s", str10[num[i]-'0']);
		// 		break;
		// 	case 1:
		// 		printf("%s", str1[num[i]-'0']);
		// 		break;
		// }
		printf("%s", pstr[base-1][num[i]-'0']);
	}
	printf("\n");
}