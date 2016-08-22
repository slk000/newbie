#include <iostream>
using namespace std;
void dashujiecheng(int N)
{ 
	int a[10000] = {1, 0}, temp, i, j, k; 
	int X = 1; 
	for(i = 2; i<= N; i++)
	{ 
		for(j = 0; j < X; j++)
			{
				a[j] *= i;
			} 
		for(k = 0; k < X; k++)
		{ 
			if(a[k] >= 10000)
			{
				if(X == k + 1) 
	                X++; 
				temp = a[k] % 10000; 
				a[k + 1] += (a[k] - temp) / 10000;
				a[k] = temp;
			}
		}
	} 

	cout << a[X-1]; 
	for(k = X - 2; k >= 0; k--)
	{ 
		if(a[k] < 1000)
			cout << 0;
		if(a[k] < 100)
			cout << 0;
		if(a[k] < 10)
			cout << 0;
			
		cout << a[k]; 
	}
	cout << endl;
} 

int main() {
	int N; 
	while(cin >> N && N >= 0)
		dashujiecheng(N);
	return 0;
}