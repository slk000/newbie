//AC
//http://codeforces.com/problemset/problem/734/B
//Codeforces Round #379 (Div. 2), problem: (B) Anton and Digits
#include <cstdio>
#include <algorithm> 
using namespace std;
int main (){
	int k2, k3, k5, k6;
	int ans = 0;
	scanf("%d %d %d %d", &k2, &k3, &k5, &k6);
	int m = min(k5,k6);
	if (k2>=m){
		ans+=256*m;
		k2-=m;
		k5-=m;
		k6-=m;
		
		m=min(k2,k3);
		ans+=m*32;
		k2-=m;
		k3-=m;
	}
	else{
		ans+=256*k2;
		k2-=k2;
		k5-=k2;
		k6-=k2;
		
	}
	printf("%d\n", ans);
	return 0;
} 