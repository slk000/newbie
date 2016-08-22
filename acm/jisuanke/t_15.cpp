#include <cstdio>
#include <vector>
using namespace std;
int main (){
	
	int n, res;
	scanf("%d", &n);
	vector<int> v(n,0);
	vector<int> count(n,0);
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		scanf("%d", &tmp);
		count[tmp]++;
	}
	for (int i = 0; i < n; ++i)
	{
		if(!v[i]%3){
			res = i;
		}
	}
	return 0;
}