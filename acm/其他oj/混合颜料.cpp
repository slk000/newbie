//AC
//http://www.nowcoder.com/questionTerminal/5b1116081ee549f882970eca84b4785a

#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
vector<long long> v;
int hi(long long a) { //获取a的二进制长度
	int cnt = 0;
	if (a == 0LL) {
		return 1;
	}
	while (a != 1) {
		a = a >> 1;
		cnt++;
	}
	return cnt+1;
}
int main() {
	int N;
	while (EOF != scanf("%d", &N)) {
		v.clear();
		for (int i = 0; i < N; i++) {
			long long a;
			scanf("%lld", &a);
			v.push_back(a);
		}
		sort(v.begin(), v.end(),greater<int>()); 
		unique(v.begin(), v.end());
		int col = 40;
		int row = 0;
		for (;row<N && col >=0; col--,row++) {
			int tmprow;
			for (tmprow = row+1; tmprow < N; tmprow++) {
				int aaa = hi(v[row])-1;
				if (v[tmprow] & (1LL << aaa)) {
					v[tmprow] ^= v[row];
					//break;
				}
			}
		}
		int cnt = 0;
		sort(v.begin(), v.end(), greater<int>());
		unique(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++) {
			if (v[i] != 0) cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}