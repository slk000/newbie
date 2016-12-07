//AC
//http://codeforces.com/problemset/problem/735/A
//Codeforces Round #382 (Div. 2) A
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <queue> 
using namespace std;
#define MAX 100
int n, k;
int start = -1;
int End = -1;
char str[MAX+10];
bool vis[MAX+10];
bool res = 0;
void bfs(int s){
	queue<int> qu;
	qu.push(s);
	vis[s]=1;
	while(!qu.empty()){
		int cur = qu.front();
		qu.pop();
		if(cur==End){
			res=1;
			break;
		}
		if (cur-k>=0&&!vis[cur-k]&&str[cur-k]!='#'){
			qu.push(cur-k);
			vis[cur-k]=1;
		}
		if (cur+k<n&&!vis[cur+k]&&str[cur+k]!='#'){
			qu.push(cur+k);
			vis[cur+k]=1;
		}
	}
} 
int main() {    
    scanf("%d %d", &n,&k);
    scanf("%s", str);
    
    for (int i = 0; i < n; i++){
    	if(str[i]=='G') start=i;
    	if(str[i]=='T') End=i;
	}
	
	bfs(start);
	puts(res?"YES":"NO");
    return 0;
}