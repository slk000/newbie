#include <cstdio>
using namespace std;
bool a[1000][1000];
int count = 0;
int N, M;
int ones = 0;
void f(int x)
{
	if (x + M > N) 
	{
		if (ones != N*N) count=-1;
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (a[x][i] == 1)
			continue;
		else{
			if (i + M > N)
			{
				count = -1; return;
			}
			count++;
			for (int g = x; g < x + M; g++) {
				for (int j = i; j < i + M; j++) {
					a[g][j]?ones--:ones++;
					a[g][j] = !a[g][j];
				}
			}
		}
	}
	f(x + 1);
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j]) ones++;
		}
	f(0);
	printf("%d\n", count);
	return(0);
}
