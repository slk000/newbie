//AC
//http://codeforces.com/problemset/problem/263/A
//Manhattan Distance
#include <cstdio>
using namespace std;
#define MID 3
inline int abs(int a) { return a < 0 ? -a : a; }
int main() {
    
    int r, c; // row and col of 1
    int num;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++){
            scanf("%d", &num);
            if (num == 1) {
                r = i;
                c = j;
                goto find;
            }
        }
    }
find:
    printf("%d\n", abs(r - MID) + abs(c - MID));
    return 0;
}