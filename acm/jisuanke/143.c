#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int num,tmp,i,k,count = 0;
	cin >> num;
	
		count = 0;

		
		for(k = num ; k > 0 ; k--)
	    	if (2*num % k == 0)
	    	{
	        	tmp = 2*num / k - k + 1;

	        	if (tmp % 2 == 0 ) 
	        	{
	            	i = tmp / 2;
	            	if(i < 0 || i == num || i == 0)
	            		continue;
		            
		            for (int p = i; p < i+k-1; p++)
		            	printf("%d ", p);
		            printf("%d\n", i+k-1);
		            count++;
	        	}
	    	}

	       
		if(count == 0){
				cout << "NONE" << endl;
			}
	
	return 0;
}