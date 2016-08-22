#include <time.h>
#include <math.h>
#include <iostream>
using namespace std;
int randnum();
int main(){
	int i=0;
	char d[3] = {'O','r','z'};
	srand(time(NULL));
	for(i = 0; i <10;i++){
		

		cout << d[randnum()];

	}
	cout <<endl;
}

int randnum(){
	 //初始化种子，只需要初始化一次
	int c;
	c=rand()%3;
	return c;
}