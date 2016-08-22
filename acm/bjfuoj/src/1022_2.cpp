#include <iostream>
#include <cmath>
using namespace std;
void shit(int);
long long a,n,numCount=0;
int main()
{
	while(cin >> a){
		shit(2);
		shit(8);
		shit(10);
		shit(16);
	}
	return 0;
}

void shit(int base){
	for (n = 0, numCount = 0; a >= pow((double)base,(double)n); n++)
		numCount += pow((double)base,(double)(n - 1)) * n * ( base - 1 );
	numCount += n * (1 + a - pow((double)base,(double)(n-1)));
	cout << numCount << endl;
}