#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int num,i,j;

	cin >> num;
	string data[num];
	int chk[num];
	for (i = 0; i < num; i++)
	{
		chk[i] = 0;
		int k = 0;
		cin >> data[i];
		for (j = 0,k = 1; j < 11; j++)
		{
			if(data[i][j] == '-')
			{
				continue;
			}
			else{
				if(data[i][j] == 'X')
					chk[i] += 10 * k;
				else
					chk[i] += (data[i][j] - 48) * k;
				k++;
			}
			
		}
		chk[i] %= 11;
		if(data[i][12] - 48 == chk[i] ||(data[i][12]=='X'&&chk[i] == 10) ){
			data[i] = "Right";
		}
		else{
			if(chk[i] == 10)
				data[i][12] = 'X';
			else
				data[i][12] = chk[i] + 48;
		}
	}

	for (i = 0; i < num; i++)
	{
		cout << data[i] << endl;
	}


	return 0;
}