//AC
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	int N;
	vector<int> res;
	while(EOF != scanf("%d",&N) && N){
		int i, sum = 0;
		for (i = 0; i < N; ++i)
		{
			int tmp;
			scanf("%d", &tmp);
			sum += tmp;
		
		}
		res.push_back(sum);
	}
	int i;
	for (i = 0; i < res.size(); i++) {
		printf(i==res.size()-1?"%d\n":"%d\n\n", res[i]);
	}
	
	return 0;
}
