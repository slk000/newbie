//http://dsalgo.openjudge.cn/201409week2/1/
#include <cstdio>
#include <cstdlib>
struct Node
{
	int NO;
	Node * next;
};
int main (){

	int m, n;
	scanf("%d%d", &n, &m);

	Node circle[n];
	circle[n-1].next = circle;
	int i;
	for (i = 0; i < n-1; ++i)
	{
		circle[i].NO = i + 1;
		circle[i].next = &circle[i+1];
	}
	circle[n-1].NO = i + 1;

	// Node * cur = circle;
	// while (1){
	// 	printf("%d\n", cur->NO);
	// 	cur = cur->next;
	// }
	int counter = 1, rest = n;
	Node * cur = circle;
	while (rest != 1){
		// printf("cur:%d\ncnt:%d\n", cur->NO, counter);
		
		if (counter == m-1)
		{
			counter = 1;
			cur->next = cur->next->next;
			cur = cur->next;
			rest--;
			continue;
		}
		cur = cur->next;
		counter++;
		// system("pause");
	}
	printf("%d\n", cur->NO);

	return 0;
}