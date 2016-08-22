#include <iostream>
#include <stack>
using namespace std;
struct Point
{
	int x,y;
};
stack<Point> crosses;
int map[9][9];
int checkCross(Point p){
	int i, count=0;
	int dx[]={0,-1,0,1};
	int dy[]={-1,0,1,0};
	for (i = 0; i < 4; ++i)
	{
		if (map[p.x+dx[i]][p.y+dy[i]] == 0 && p.x+dx[i] < 9 && p.y+dy[i]<9)
		{
			Point tmp = {p.x+dx[i],p.y+dy[i]};
			crosses.push(tmp);
			count++;
		}
	}
	return count;
}
int main(int argc, char const *argv[])
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		while(!crosses.empty()) crosses.pop();

		Point curPos = {4,4},
	    	  exitPos;
		scanf("%d%d", &exitPos.x, &exitPos.y);
		exitPos.x--;
		exitPos.y--;
	
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				scanf("%d",&map[i][j]);
			}
		}	
		//printf("exitPos:(%d,%d)\n", exitPos.x,exitPos.y);
		while(checkCross(curPos) || !crosses.empty() ){
			map[curPos.x][curPos.y] = 1;
			//printf("(%d,%d)\n",curPos.x,curPos.y);
			curPos = crosses.top();

			crosses.pop();
			if(curPos.x == exitPos.x && curPos.y == exitPos.y){
				map[curPos.x][curPos.y] = 1;
				break;
			}
		}
/*
	printf("\n");
	
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}*/
		printf("%s\n", map[exitPos.x][exitPos.y]?"Yes":"No");
	}
	return 0;
}