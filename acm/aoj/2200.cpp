#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define INF 2000*2000
#define MAX_R 2010
#define MAX_NODE 210
int N, M;
int distS[MAX_NODE][MAX_NODE];//ˮ
int distL[MAX_NODE][MAX_NODE];//½
void init() {
	/*memset(distS, 0x3f, sizeof(distS));
	memset(distL, 0x3f, sizeof(distL));*/
	for (int i = 0; i < N; i++)for (int j = 0; j < N; j++) distS[i][j] = distL[i][j] = INF;
	for (int i = 0; i < N; i++) distL[i][i] = distS[i][i] = 0;
}
inline void insertS(int x, int y, int weight) {
#define NON_DIRECTED
	distS[x][y] = weight;
#ifdef NON_DIRECTED
	distS[y][x] = weight;    //����ͼ
#endif
}
inline void insertL(int x, int y, int weight) {
#define NON_DIRECTED
	distL[x][y] = weight;
#ifdef NON_DIRECTED
	distL[y][x] = weight;    //����ͼ
#endif
}
void floyd() {
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				distS[i][j] = min(distS[i][j], distS[i][k] + distS[k][j]);
				distL[i][j] = min(distL[i][j], distL[i][k] + distL[k][j]);
			}
		}
	}
}
int dp[MAX_R][MAX_NODE];
int city[MAX_R];
int main() {
	freopen("E:/2200-input.txt", "r", stdin);
	while (EOF != scanf("%d %d", &N, &M) && N) {
		init();
		
		for (int i = 0; i < M; i++) {
			int from, to, dis;
			
			char type;
			scanf("%d %d %d %c", &from, &to, &dis, &type);
			from--; to--;
			if (type == 'S')
				insertS(from, to, dis);
			else if (type == 'L')
				insertL(from, to, dis);
		}
		int city_cnt;
		scanf("%d", &city_cnt);
		for (int i = 0; i < city_cnt; i++) {
			scanf("%d", &city[i]);
			city[i]--;
		}
		floyd();


		for (int i = 0; i < city_cnt; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				dp[i][j] = INF;
			}
		}
		for (int i = 0; i < N; ++i)
		{
			// ��ʼ���ݷ����һ���ص�ʱ�������˵�ǰݷ���ʵֻ��ȥ�Ӵ�����Ϊһ��ʼ���ڵ�һ���ص㣩
			// ��ˮ·ȥi��ר��ȥ�Ѵ��ӵ�i= =��	+ �߻����
			dp[0][i] = distS[city[0]][i] + distL[i][city[0]];
		}
		for (int i = 1; i < city_cnt; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				for (int k = 0; k < N; ++k)
				{
					if (j != k)
					{
						//��i-1��֪�����·     + ��i-1վ��½·ȥj+ ��j��ˮ·ȥk+��k��½·ȥi ����j��kҲ��ר��ȥ�Ӵ���= =��
						dp[i][k] = min(dp[i][k], dp[i - 1][j] + distL[city[i - 1]][j] + distS[j][k] + distL[k][city[i]]);
					}
					else //j==k
					{
						//(i-1)     + ��i-1��½·ȥi����Ϊ�����ƶ�����
						dp[i][j] = min(dp[i][j], dp[i - 1][j] + distL[city[i - 1]][city[i]]);
					}
				}
			}
		}

		cout << *min_element(dp[city_cnt - 1], dp[city_cnt - 1] + N) << endl;
	}
	return 0;
}