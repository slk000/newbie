#include <cstdio>
using namespace std;
int main (){
	int length;
	while(EOF != scanf("%d", &length)) {
//		printf("222\n");
		int rates[length];
		for (int i = 0; i < length; i++) {
			scanf("%d", &rates[i]);
		}
		
		int cnt = 0;
		int cur = 0;
		for (int i = 0; i < length; i++) {
			
			if (i == 0 || rates[i] == rates[i-1]) {
				cur = 1;
			}
			// else if (rates[i] > rates[i-1]) {
			else if (/*i+1 < length && */rates[i] > rates[i-1]){
				cur++;	
			// 	int incLength = 1;
			// 	cur += rates[i];
			// 	for (int j = i; j < length && rates[j] > rates[j-1];incLength++, j++)
			// 		printf("incLenght:%d\nj:%d\n",incLength,j);
			// 	incLength--;
			// 	cur += (incLength + 1) * incLength / 2;
			// 	i = j-1;
			}
			if (i + 1 < length && rates[i] > rates[i+1]) {
				int decLength = 1;
				int j;
				for (j = i+1; j < length && rates[j] < rates[j-1]; j++,decLength++);
				if (decLength > cur ) {
					cnt += (decLength + 1) * decLength / 2;
				}
				else {
					cnt += (decLength - 1) * decLength / 2 + cur;
				}
				cur = 1;
				i = j - 1;
			}
			else {
				cnt += cur;
			}
		}
	printf("%d\n", cnt);
	}
	return 0;
}
