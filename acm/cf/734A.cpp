//AC
//http://codeforces.com/problemset/problem/734/A
//Codeforces Round #379 (Div. 2), problem: (A) Anton and Danik
#include <cstdio>
int main (){
	int a;
	scanf("%d", &a);
	getchar();
	char ch;
	int cntD = 0, cntA = 0;
	for(int i = 0; i < a;i++){
		scanf("%c", &ch);
		if(ch=='A')cntA++;
		else if(ch=='D')cntD++;
	}
	if(cntA > cntD){
		printf("Anton\n");
	}
	else if(cntA < cntD){
		printf("Danik\n");
		
	}
	else{
		printf("Friendship\n");
	}
	return 0;
} 