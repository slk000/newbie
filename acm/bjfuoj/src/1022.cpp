#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	long long a,n,numCount=0;
	while(cin >> a){
		
		for (n = 0, numCount = 0; a >= pow(2.,(double)n); n++)
			numCount += pow(2.,(double)(n - 1)) * n;
		numCount += n * (1 + a - pow(2.,(double)(n-1)));
		cout << numCount << endl;
				
		for (n = 0, numCount = 0; a >= pow(8.,(double)n); n++)
			numCount += pow(8.,(double)(n - 1))  * n * 7;
		numCount += n * (1 + a - pow(8.,(double)(n-1)));
		cout <<  numCount << endl;
		
		for (n = 0, numCount = 0; a >= pow(10.,(double)n); n++)
			numCount += pow(10.,(double)(n - 1))  * n * 9;
		numCount += n * (1 + a - pow(10.,(double)(n-1)));
		cout << numCount << endl;

		for (n = 0, numCount = 0; a >= pow(16.,(double)n); n++)
			numCount += pow(16.,(double)(n - 1))  * n * 15;
		numCount += n * (1 + a - pow(16.,(double)(n-1)));
		cout << numCount << endl;

	}

	return 0;
}