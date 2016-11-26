//AC
//http://codeforces.com/problemset/problem/222/A
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX 100000
int arr[MAX + 10];
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif // !ONLINE_JUDGE
    int n, k;
    scanf("%d %d", &n, &k);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bool same = true;
    for (int i = k - 1; i < n - 1; i++) {//[k,n)的数字都要相同
        same &= (arr[i] == arr[i + 1]);
    }
    if (!same) {
        puts("-1");
        return 0;
    }
    int j;
    for (j = k - 1; j >= 0 && arr[j] == arr[k - 1]; j--);//相同的那段之前的长度（其最后一位的下标）就是操作的次数
    printf("%d\n", j + 1);

    return 0;
}