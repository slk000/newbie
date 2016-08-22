//AC
//http://nanti.jisuanke.com/t/6
//计算平均体积，大的人拿了别人的
#include <cstdio>
int main(int argc, char const *argv[])
{
	int sum = 0;
	while(scanf("%d", &sum) && sum != -1){
		int volumes[9];
		char names[9][10];
		int sumVolume = 0;
		for(int i = 0; i < sum; i++){
			int a, b, c;
			scanf("%d%d%d%s", &a, &b, &c, names+i);
			volumes[i] = a*b*c;	
			sumVolume += volumes[i];
		}
		sumVolume = sumVolume / sum;
		int max, min;
		for(int i = 0; i < sum; i++){
			if (volumes[i] == sumVolume)
			{
				continue;
			}
			if (volumes[i] < sumVolume)
			{
				min = i;
			}
			else{
				max = i;
			}
		}
		printf("%s took clay from %s.\n", names[max], names[min]);

	}
	return 0;
}