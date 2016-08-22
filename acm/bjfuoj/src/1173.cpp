#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int sum,fifty=0,twenty=0,ten=0,five=0,i=0,count,tmp=0;
	cin >> count;
	for(i = 0; i < count ;i++)
	{
		cin >> sum;
		fifty = twenty = ten = five = tmp = 0;
		while(tmp = sum / 50)
		{
			fifty++;
			sum -= 50;
		}
		while(tmp = sum / 20)
		{
			twenty++;
			sum -= 20;
		}
		while(tmp = sum / 10)
		{
			ten++;
			sum -= 10;
		}
		while(tmp = sum / 5)
		{
			five++;
			sum -= 5;
		}
		cout << fifty << endl << twenty << endl << ten << endl  << five << endl  << sum << endl;
	}
	
	return 0;
}