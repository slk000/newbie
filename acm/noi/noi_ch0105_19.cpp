#include <cstdio>
#include <cstdlib>
int main (){
	int pre[12];
	int saving = 0;
	for (int i = 0; i < 12; ++i)
	{
		scanf("%d", &pre[i]);
	}
	int lastmonth=0;


	for (int i = 0; i < 12; ++i)
	{
		int amount = (lastmonth + 300 - pre[i]);
		saving += (amount/100)*100;
		lastmonth = amount%100;
		if(amount < 0){
			printf("-%d\n", i+1);
			return 0;
		}
		// printf("amount :%d\nsaving:%d\nrest:%d\n",amount,saving,lastmonth );
		// system("pause");
	}
	// saving+=lastmonth;
	printf("%.0lf",saving*1.2+lastmonth);



	

	return 0;
}