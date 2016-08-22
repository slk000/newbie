#include <stdio.h>
int main(int argc, char const *argv[])
{
	struct position
	{
		int x,y; 
	};
	typedef struct position Pos;
	int T;
	scanf("%d",&T);
	while(T--){
		int map[11][11], i, j, nextFlag = 0, crossCount = 0;
		Pos crossPos[49], enter, cur, last;
		

		scanf("%d%d",&enter.x, &enter.y);

		for (i = 0; i < 10; ++i)
		{
			for (j = 0; j < 10; ++j)
			{
				if(i==0||j==0||i==10||j==10)
					map[i][j] = 2;
				else{
					scanf("%d",&map[i][j]);
				}
			}
		}
		cur = enter;

		int bushu = 0;
	//do{
		while(map[cur.x-1][cur.y] == nextFlag || map[cur.x][cur.y+1] == nextFlag || map[cur.x+1][cur.y] == nextFlag || map[cur.x][cur.y-1] == nextFlag)
		{	
			if(map[cur.x-1][cur.y] == nextFlag){	//up
				last = cur;
				
				map[cur.x][cur.y]++;
				cur.x--;
				//printf("(%d,%d)->",cur.x,cur.y);
			}
			else if(map[cur.x][cur.y+1] == nextFlag){	//right
				last = cur;
				
				map[cur.x][cur.y]++;
				cur.y++;
				//printf("(%d,%d)->",cur.x,cur.y);
			}
			else if(map[cur.x+1][cur.y] == nextFlag){	//down
				last = cur;
				
				map[cur.x][cur.y]++;
				cur.x++;
				//printf("(%d,%d)->",cur.x,cur.y);
			}
			else if(map[cur.x][cur.y-1] == nextFlag){
				last = cur;
				
				map[cur.x][cur.y]++;
				cur.y--;
				//printf("(%d,%d)->",cur.x,cur.y);
			}

			if(!map[cur.x-1][cur.y] + !map[cur.x][cur.y+1] + !map[cur.x+1][cur.y] + !map[cur.x][cur.y-1] > 1)
			{
				crossCount++;
				crossPos[crossCount-1] = cur;

				//printf("\nk:(%d,%d)\n",cur.x,cur.y);

			}
			//if(map[cur.x-1][cur.y] * map[cur.x][cur.y+1] * map[cur.x+1][cur.y] * map[cur.x][cur.y-1] == 0)
			//	nextFlag = 0;
			while(map[cur.x-1][cur.y] != nextFlag && map[cur.x][cur.y+1] != nextFlag && map[cur.x+1][cur.y]  != nextFlag && map[cur.x][cur.y-1]  != nextFlag)
			{
				if(crossCount == 0)
					break;
				map[cur.x][cur.y]++;
				cur = crossPos[crossCount-1];
				crossCount--;
				//printf("(%d,%d)->",cur.x,cur.y);
			}

			//map[enterX][enterY] = 0;
			//else
			//	nextFlag = 1;
		};
		map[cur.x][cur.y]++;
	//}while(map[5][5] == 0);
/*
printf("\n");
		for (i = 0; i < 10; ++i)
		{
			for (j = 0; j < 10; ++j)
			{
				if(i==0||j==0||i==10||j==10)
					continue;
				
				printf("%2d ",map[i][j]);
			}
			printf("\n");
		}
		printf("%d\n", bushu);
		printf("curpos;(%d,%d)\n",cur.x,cur.y);
*/
		if(map[5][5])
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}