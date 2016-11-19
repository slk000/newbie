//AC
//http://hihocoder.com/problemset/problem/1051
#include <cstdio>
int main (){
	int T;
	scanf("%d", &T);
	while (T--){
		int dayNum, cardNum;
		int res=0;
		scanf("%d %d", &dayNum, &cardNum);
		if (cardNum >= dayNum){//如果提交卡很多就全连
			for (int i = 0;i<dayNum;i++)scanf("%*d");
			printf("100\n");
			continue;
		}
		int *days = new int[dayNum];
		for (int i = 0; i < dayNum; i++) {
			scanf("%d", &days[i]);
		}
		for (int i = cardNum-1; i < dayNum; i++) {//最多情况肯定是卡全用完时，则从cardNum-1天开始枚举
			int start, end;
			start = i-cardNum < 0?0:days[i-cardNum];
			end = i+1>=dayNum?100:days[i+1];
			if (res < end-start-1) res = end-start-1;

			//printf("i: %d\t%d\n",i,end-start-1);
			
		}
		printf("%d\n", res);
		delete[] days;
	}
	return 0;
}