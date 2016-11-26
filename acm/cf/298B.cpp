//AC
//http://codeforces.com/problemset/problem/298/B
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100000
char str[MAX + 10];
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif // !ONLINE_JUDGE
    int t, sx, sy, ex, ey;
    scanf("%d %d %d %d %d", &t, &sx, &sy, &ex, &ey);
    scanf("%s", str);
    int dx = abs(ex - sx), dy = abs(ey - sy);
    if (sx == ex&&sy == ey) {
        puts("0");
        return 0;
    }
    for (int i = 0; i < t; i++) {
        int nx = sx, ny = sy;
        switch (str[i])
        {
        case 'E':
            nx++;
            break;
        case 'S':
            ny--;
            break;
        case 'W':
            nx--;
            break;
        case 'N':
            ny ++ ;
            break;
        }
        if (nx == ex && ny == ey) {
            printf("%d\n", i+1);
            return 0;
        }
        if (abs(ex - nx) < dx) {
            dx = abs(ex - nx);
            sx = nx;
        }
        if (abs(ey - ny) < dy) {
            dy = abs(ey - ny);
            sy = ny;
        }
    }
    
    puts("-1");
    return 0;
}