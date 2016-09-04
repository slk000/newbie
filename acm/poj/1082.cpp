//AC
//http://poj.org/problem?id=1028
//water
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <stack>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX 5
stack<string> forward, backward;
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	string cmd;
	string  cur = "http://www.acm.org/";
	while (cin >> cmd) {
		if (cmd == "QUIT")break;
		else if (cmd == "VISIT") {
			backward.push(cur);
			cin >> cur;
			while (!::forward.empty()) ::forward.pop();
		}
		else if (cmd == "BACK") {
			
			if (backward.empty()) {
				cout << "Ignored" << endl;
				continue;
			}
			else {
				::forward.push(cur);
				cur = backward.top();
				backward.pop();
			}
		}
		else if (cmd == "FORWARD") {
			
			if (::forward.empty()) {
				cout << "Ignored" << endl;
				continue;
			}
			else {
				backward.push(cur);
				cur = ::forward.top();
				::forward.pop();
			}
		}
		cout << cur << endl;
	}
	return 0;
}