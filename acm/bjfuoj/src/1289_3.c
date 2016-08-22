#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

struct Point {int x,y;};

int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};
stack<Point> q;
bool p[10][10];
int r,c;
int mass[10][10];
bool solve(Point a)
{
    bool end;
    memset(p,false,sizeof(p));
    int i,j,x,y;
    while(!q.empty())
    {
        end=true;
        x=q.top().x;
        y=q.top().y;
        p[x][y]=true;
        for(i=0;i<4;i++)
        {
            printf("%d\n", i);
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx==r-1&&ny==c-1) return true;
            if(!mass[nx][ny])
            {
                if(!p[nx][ny])
                {
                    Point pp;
                    pp.x=nx;pp.y=ny;
                    p[nx][ny]=true;
                    q.push(pp);
                    end=false;
                    break;
                }
            }
        }
        if(end) q.pop();
    }
    return false;
}

int main()
{
#ifdef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    int T,i,j;
    bool ans;
    Point be;
    be.x=4;
    be.y=4;
    while(~scanf("%d",&T))
    {
        while(T--)
        {
            while(!q.empty()) q.pop();
            scanf("%d%d",&r,&c);
            for(i=0;i<9;i++)
                for(j=0;j<9;j++)
                    scanf("%d",&mass[i][j]);
            q.push(be);
            ans=solve(be);
            if(ans) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}