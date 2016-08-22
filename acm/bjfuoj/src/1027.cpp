#include <iostream>
using namespace std;
void sort(int *);
int main(int argc, char const *argv[])
{
	int classAmount,i,j,k;

	cin >> classAmount;

	int data[classAmount][3];

	for (i = 0; i < classAmount; i++)
	{
		cin >> data[i][0] >>data[i][1] >> data[i][2];

		for (j = 0; j < 2; j++){
			for(k = 0; k < 2 - j; k++){
				if(data[i][k] > data[i][k+1]){
					int t = data[i][k];
					data[i][k] = data[i][k+1];
					data[i][k+1] = t;
				}
			}
		}
	}

	for (i = 0; i < classAmount; i++)
	{
		cout << data[i][1] << " " <<data[i][0] << " " << data[i][2] << endl;
	}




	return 0;
}

