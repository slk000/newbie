#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	long long sum, i;
	cin >> sum;
	for(i = 0; i < sum; i++)
	{
		long long n, k;
		cin >> n >> k;

		if(!(n%2)) //n为偶
		{
			if(!(k%4))
			{
				cout << "A" << endl;
				continue;
			}
			else if(!(k%2))
			{
				cout << "B" << endl;
				continue;
			}
			else
			{
				cout << "F" << endl;
				continue;
			}
		}
		else
		{
			if( !( ((long long)ceil(k/2.)) % 2) ) //偶数组
			{
				cout << "A" <<endl;
				continue;
			}
			else
			{
				cout << "B" << endl;
				continue;
			}
		}
	}
	return 0;
}