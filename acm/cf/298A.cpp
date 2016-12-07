//AC
//http://codeforces.com/problemset/problem/298/A
//Wannafly Union 2A
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX 1000
char str[MAX + 10];
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif // !ONLINE_JUDGE
    int n;
    scanf("%d", &n);
    scanf("%s", str);
    int mid = -1;
    int start = -1;
    bool hasR = false;
    bool hasL = false;
    for (int i = 0; i < n; i++) {
        hasR |= str[i] == 'R';//检查是否出现L和R
        hasL |= str[i] == 'L';
        if (start == -1 && str[i] != '.')start = i; //记录起点（钦定从左到右走）
        if (i+1<n && str[i] + str[i+1] == 'L' + 'R') {//记录终点（L和R变化的那里）
            mid = i;
        }
    }
    if (mid == -1) { //只有L或者R的时候就钦定最右边一个非'.'为终点
        mid = n-1;
        while (str[mid] == '.')mid--;
        mid--;

    }
    if (hasR && !hasL) { //然后如果全是R的话还要再往右走一步才能让钦定的终点上留下脚印
        mid++;
    }
    if (hasL && !hasR) {//同上
        start--;
    }
    if(hasR)//有R的话就可以按钦定的从左到右走
        printf("%d %d\n", start+1, mid+1);
    else {//否则交换起点和终点
        printf("%d %d\n", mid + 1, start + 1);
    }
    return 0;
}