#include <stdio.h>
int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	while(T--){
		int map[11][11];

		int enterX, enterY,curX,curY,lastX,lastY, i, j, nextFlag = 0;
		scanf("%d%d",&enterX, &enterY);

		for (i = 0; i < 10; ++i)
		{
			for (j = 0; j < 10; ++j)
			{
				if(i==0||j==0||i==10||j==10)
					map[i][j] = -1;
				else{

					scanf("%d",&map[i][j]);
					if (map[i][j])
					{
						map[i][j]=-1;
					}
				}
			}
		}
		curY = enterY;
		curX = enterX;
		
		int bushu = 0;
	//do{
		while(map[curX-1][curY] == nextFlag || map[curX][curY+1] == nextFlag || map[curX+1][curY] == nextFlag || map[curX][curY-1] == nextFlag)
		{	
			
			if(map[curX-1][curY] == nextFlag){	//up
				lastX = curX;
				lastY = curY;
				map[curX][curY]++;
				curX--;
				printf("up ");
			}
			else if(map[curX][curY+1] == nextFlag){	//right
				lastX = curX;
				lastY = curY;
				map[curX][curY]++;
				curY++;
				printf("ri ");
			}
			else if(map[curX+1][curY] == nextFlag){	//down
				lastX = curX;
				lastY = curY;
				map[curX][curY]++;
				curX++;
				printf("do ");
			}
			else if(map[curX][curY-1] == nextFlag){
				lastX = curX;
				lastY = curY;
				map[curX][curY]++;
				curY--;
				printf("le ");
			}
			if(map[curX-1][curY] * map[curX][curY+1] * map[curX+1][curY] * map[curX][curY-1] == 0)
				nextFlag = 0;
			if(map[curX-1][curY] != nextFlag && map[curX][curY+1] != nextFlag && map[curX+1][curY]  != nextFlag && map[curX][curY-1]  != nextFlag)
			{
				map[curX][curY]++;
				nextFlag = 1;
			}

			//map[enterX][enterY] = 0;
			//else
			//	nextFlag = 1;
		};
		map[curX][curY]++;
	//}while(map[5][5] == 0);

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
		printf("curpos;(%d,%d)\n",curX,curY);
		if(map[5][5])
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}