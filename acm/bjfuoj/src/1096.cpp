//AC
//http://acm.bjfu.edu.cn/acmhome/problemdetail.do?&method=showdetail&id=1096
//DP
#include <cstdio>
#include <memory.h>
#include <cstdlib>
int MAX(int a, int b){return a>b?a:b;}
int main(){
	int n;
	scanf("%d", &n);
	int *data;
	int *max;
	

	while (n--){
		int mi;
		scanf("%d", &mi);
		int sum = mi+mi*(mi-1)/2;
		data = new int[sum];
		max = new int[sum];
		
		
		for (int i = 0;i < sum; i++){
			scanf("%d", &data[i]);
			max[i] = data[i];
		}

		max[0] = data[0];
		
		for (int i = 1; i < mi; i++){
			for (int j = 0; j <= i; j++){
				int cur = i*(i+1)/2 + j;
				//printf("%d ", data[cur]);
				if (j == 0) {
					max[cur] = max[cur] + max[cur - i];
				}
				else if (j == i) {
					max[cur] = max[cur] + max[cur - i - 1];
				}
				else {
					max[cur] = max[cur] + MAX(max[cur - i -1], max[cur - i]);
				}
			}
		}
		int res = 0;
		for (int i = 0; i < sum; i++){
			res = MAX(res, max[i]);
		}
		printf("%d\n", res);
		delete[] data;
		delete[] max;
	}
	//system("pause");
	return 0;
}