//AC
//http://hihocoder.com/problemset/problem/1043
//完全背包
#include <stdio.h>
#include <cstring>
#define MAX_N 500
#define MAX_BAG 100000
int max(int a, int b) { return a>b ? a : b; }
int bagMap[MAX_BAG + 1],
    weight[MAX_N],
    value[MAX_N];
int main(int argc, char const *argv[])
{
    int num, bagMax; //物品数量、背包最大大小
    int i, j;
    scanf("%d%d", &num, &bagMax);


    memset(bagMap, 0, sizeof(bagMap));
    for (i = 0; i < num; ++i) {
        scanf("%d%d", &weight[i], &value[i]);
    }

    for (i = 1; i <= num; ++i)
    {
        for (j = bagMax; j >= 1; --j)
        {
            if (j - weight[i - 1] < 0)
            {
                bagMap[j] = bagMap[j];
            }
            else
            {
				for (int k = 1; k*weight[i-1]<=j; k++)
					bagMap[j] = max(bagMap[j], bagMap[j - weight[i - 1]*k] + value[i - 1]*k);
            }
        }
    }
    printf("%d\n", bagMap[bagMax]); 
    return 0;
}