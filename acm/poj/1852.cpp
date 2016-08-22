#include <cstdio>
using namespace std;
int Max(int a, int b){
	return a>b?a:b;
}
int Min(int a, int b){
	return a>b?b:a;
}
int main (){
	int T;
	scanf("%d", &T);
	int length, antsSum;
	while(T--){
		scanf("%d%d", &length, &antsSum);
		int min = 0, max = 0;
		int antPos;
		for (int i = 0; i < antsSum; ++i)
		{
			scanf("%d", &antPos);
			min = Max(min, Min(antPos, length - antPos));
			max = Max(max, Max(antPos, length - antPos));
		}

		printf("%d %d\n", min, max);

	}
	return 0;
}