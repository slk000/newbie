//AC
//http://hihocoder.com/problemset/problem/1039
//force
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <functional>
#include <set>
#include <string>
#include <stack>
#include <bitset>

using namespace std;
#define INF 0x3f3f3f3f
#define MAX 110
void del(string &str) {//消除字符
	
	int i = 0, j = 0;
	bool modified = false;
	for (i = 0; i < str.size(); i++) {
		j = i+1;
		while (j < str.size() && str[j] == str[i]) j++;
		j--;
		if (j == i)continue;
		str.erase(i, j - i + 1);
		modified = true;
		i--;
	}
	if (!modified) return;
	del(str);
}
int main() {
	std::ios::sync_with_stdio(false);//用这个的话不要cin/scanf cout/printf混用
	std::cin.tie(0);
	
	int T;
	//scanf("%d", &T);
	cin >> T;
	while (T--) {
		string str = "";
		cin >> str;
		
		int cntBefore = str.length() + 1;
		int res = -1;
		for (int i = 0; i <= str.length(); i++) {//枚举每个位置
			
			for (int j = 0; j < 3; j++) {//枚举三个字符
				string str2 = str;
				str2.insert(i, 1, j + 'A');
				del(str2);
				int t = cntBefore - str2.length();
				res = max(res, t);
			}
		}
		//printf("%d\n", res);
		cout << res << endl;
	}
	return 0;

}