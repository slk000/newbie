//AC
//http://codeforces.com/problemset/problem/205/A
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
#include <set>
using namespace std;
#define INF 0x3f3f3f3f
int main() {
    //O(n)
    int n, data;
    bool isValid = true;
    scanf("%d", &n);
    int Min = INF, mini = -1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &data);
        if (Min == data) {
            isValid = false;
        }
        if (Min > data) {
            Min = data;
            isValid = true;
            mini = i;
        }
    }
    
    if (isValid)
        printf("%d\n", mini);
    else
        printf("Still Rozdil\n");
    
    return 0;
}
/*
//O(nlogn?)
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
#include <set>
using namespace std;
#define INF 0x3f3f3f3f
pair<int, int> Data[100010];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &Data[i].first);
        Data[i].second = i + 1;
    }
    sort(Data, Data + n);
    if (Data[0].first != Data[1].first) {
        printf("%d\n", Data[0].second);
    }
    else {
        printf("Still Rozdil\n");
    }
    return 0;
}
*/