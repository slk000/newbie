//http://bailian.openjudge.cn/2016acm/01/
//01
#include <cstdio>
#include <cstring>
#define MAX_WEIGHT 12880
#define MAX_ITEM 3402
int bag[MAX_WEIGHT+1];//滚动数组
int itemsW;
int itemsV;
inline int max(int a, int b) {return a>b?a:b;}
int main() {
	int item, maxW;

	scanf("%d %d", &item, &maxW);
	for (int i = 1; i <= item; i++) {
        scanf("%d %d", &itemsW, &itemsV);
		for (int j = maxW; j >= 0; j--) { //从右往左更新，避免要使用的旧左上角数据被覆盖
            if (j-itemsW >= 0)
            {
                bag[j] = max(bag[j-itemsW]+itemsV,bag[j]);
            }

		}//for (int j = 1; j <= maxW; j++)  printf("%d ",bag[j]);
		//printf("\n");
	}
	printf("%d\n", bag[maxW]);
	return 0;
}
