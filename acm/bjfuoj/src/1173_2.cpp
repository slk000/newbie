#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int sum,i=0,count,tmp=0;
	cin >> count;
	for(i = 0; i < count ;i++)
	{
		tmp = 0;
		cin >> sum;
		
		while(sum / 50)
		{
			tmp++;
			sum -= 50;
		}
		while(sum / 20)
		{
			tmp++;
			sum -= 20;
		}
		while(sum / 10)
		{
			tmp++;
			sum -= 10;
		}
		while(sum / 5)
		{
			tmp++;
			sum -= 5;
		}
		tmp+=sum;
		cout << tmp << endl;
	}
	
	return 0;
}