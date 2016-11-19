//AC
//http://hihocoder.com/problemset/problem/1077
//线段树
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f

struct Node{
	int l, r;
	int minVal;
	int Mid(){return (l+r)/2;}
	Node(){minVal=INF;}
};
#define MAX_N 1000010

//Node tree[(1<<MAX_N)+1];
Node tree[4*MAX_N];
int minVal = INF;
int data[MAX_N+1];
void init(int root, int l, int r, int *data){
	int mid = (l+r)/2;
	tree[root].l = l;
	tree[root].r = r;
	tree[root].minVal = INF;
	if (r != l){
		init(2*root+1, l, mid, data);
		init(2*root+2, mid+1, r, data);
	}
	else{
		tree[root].minVal = data[l];
	}
	if(root%2==0) //每两个子节点更新一个父节点
		tree[root/2-1].minVal = min(tree[root].minVal, tree[root-1].minVal);
}

void update(int root, int i, int v){
	if (tree[root].minVal > v) tree[root].minVal = v;
	if (tree[root].l != tree[root].r) {
		if (i <= tree[root].Mid()){
			update(2*root+1,i,v);
		}
		else{
			update(2*root+2,i,v);
		}
	}
	else {
		tree[root].minVal = v;  //更新叶子
	}
	if(root%2==0) //节点是右儿子
		tree[root/2-1].minVal = min(tree[root].minVal, tree[root-1].minVal); //用 它 和 它左边兄弟更新父节点
	else  //左
		tree[root/2].minVal = min(tree[root].minVal, tree[root+1].minVal); ////用 它 和 它右边兄弟更新父节点
}
void query(int root, int l, int r) {
	if (tree[root].minVal >= minVal) return; //可剪
	if (tree[root].l == l && tree[root].r == r){
		minVal = min(minVal, tree[root].minVal);
		return;
	}
	if (r <= tree[root].Mid()){
		query(2*root+1, l, r);
	}
	else if(l > tree[root].Mid()){
		query(2*root+2, l, r);
	}
	else{
		query(2*root+1, l, tree[root].Mid());
		query(2*root+2, tree[root].Mid()+1, r);
	}

}
int main(){
	//freopen("20.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		int v;
		scanf("%d", &data[i]);
	}
	init(0,1,n,data);
	int cmdCnt;
	//freopen("CON", "r", stdin);
	scanf("%d", &cmdCnt);
	//while(1){
	for (int i = 0; i < cmdCnt; i++) {
		int cmd=0, a, b;
		scanf("%d%d%d", &cmd, &a, &b);
		if (cmd == 0) {
			minVal = INF;
			query(0,a,b);
			printf("%d\n", minVal);
		}
		else if (cmd ==1) {
			update(0,a,b);
		}
	}
	
	return 0;
}