#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	long long bigClassAmount,smlCassAmount;
	int i,j;

	while(cin >> bigClassAmount){
		long long data[bigClassAmount];
		for(i = 0; i < bigClassAmount; i++){
			cin >> smlCassAmount;
			data[i] = 0;
			for (j = 0; j < smlCassAmount; j++)
			{
				long long t;

				cin >> t;
				data[i] += t;
			}
		}
		for (i = 0; i < bigClassAmount-1; i++)
		{
			cout << data[i] << endl <<endl ;
		}
		cout << data[bigClassAmount-1] << endl;
	}
	return 0;
}