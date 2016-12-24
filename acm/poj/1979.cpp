//AC
//http://poj.org/problem?id=1979
#include <cstdio>
#include <cstring>//no memory.h for memset in POJ using G++
#include <cstdlib>
#include <stack>
#include <set>
#define MAX 21
using namespace std;
char map[MAX][MAX];
bool d[MAX][MAX];
typedef struct {int x, y;} P;
int w, h;
stack<P> st;
int res = 0;

void dfs(){
	int offset_x[] = {0, 0, -1, 1};
	int offset_y[] = {-1,1, 0, 0};
	while (!st.empty()){
		P cur = st.top();
		st.pop();
		map[cur.y][cur.x] = 'a';

		for (int i = 0; i < 4; i++){
			P next = {cur.x+offset_x[i], cur.y+offset_y[i]};
			if (next.x < 0 || next.x >= w || next.y < 0 || next.y >= h) continue;
			if (map[next.y][next.x] == '.'){
				st.push(next);
				if (!d[next.y][next.x]) res++;
				d[next.y][next.x] = true;
			}
		}
	}
	
}
int main(){
	
	
	while (EOF != scanf("%d %d", &w, &h)) {
		if (!w || !h) return 0;
		res = 0;
		memset(d, false, sizeof(d));
		P start;
		for (int i = 0; i < h; i++) {
			scanf("%s", &map[i]);
			for (int j = 0; j < w; j++) {
				if (map[i][j] == '@'){
					start.x = j;
					start.y = i;
				}
			}
		}
		

		st.push(start);
		map[start.y][start.x] = 'a';
		res = 1;
		dfs();

		printf("%d\n", res);
	}


	return 0;
}