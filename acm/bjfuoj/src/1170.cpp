#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
int main (){
	char stra[11], strb[11];
	while (EOF != scanf("%s %s", stra, strb)) {
		stack<char> a,b; 
		for (int i = 0; i < strlen(stra); i++) {
			a.push(stra[i]);
		}
		for (int i = 0; i < strlen(strb); i++) {
			b.push(strb[i]);
		}
		//stack<char> res;
		string res;
		while (!b.empty() && !a.empty()) {
			char digi = a.top()-'0' + b.top()-'0';
			if (digi >= 10) digi -= 10;
			digi += '0';
			a.pop();b.pop();
			res.push_back(digi);
		}
		while (!b.empty()) {
			res.push_back(b.top());
			b.pop();
		}
		while (!a.empty()) {
			res.push_back(a.top());
			a.pop();
		}
		while(res.length() > 1 && res[res.size()-1] == '0') res.erase(res.size()-1,1);
		reverse(res.begin(),res.end());
		cout << res << endl;
	}
}
