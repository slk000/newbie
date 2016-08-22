#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int num,i,j,count = 0,sum = 0;
	while(cin >> num)
	{
		count = 0;
		for(i = 1; i < num; i++)
		{	
			for (j = i ; j < num; j++)
			{
				sum = ((i + j) * (j - i + 1))/2;
				if(sum == num)
				{
					count++;
					cout << i << "->" << j << endl;
					continue;
				}
			}

			sum = 0;
	
		}
		if(count == 0){
				cout << "NONE" << endl;
			}
	}
	return 0;
}