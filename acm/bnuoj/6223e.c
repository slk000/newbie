#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	int T;
	scanf("%d", &T);
	while(T--){
		int contests, scoreA=1500, scoreB=1500;
		scanf("%d", &contests);
		
		while(contests--){
			char rate[5];
			scanf("%s", rate);
			if(strcmp(rate, "good") == 0){
				if(scoreA >= scoreB)
					scoreB += 100;
				else
					scoreA += 100;
			}
			else if(strcmp(rate, "bad") == 0){
				if(scoreA >= scoreB)
					scoreB -= 100;
				else
					scoreA -= 100;
			}

		}
		int out;
		if ((scoreA>scoreB?scoreA:scoreB)>3299)
		{
			out = 3299;
		}
		else if((scoreA>scoreB?scoreA:scoreB)<0){
			out = 0;
		}
		else{
			out = scoreA>scoreB?scoreA:scoreB;
		}
		printf("%d\n", out);
	}
	return 0;
}