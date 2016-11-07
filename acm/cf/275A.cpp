//AC
//http://codeforces.com/problemset/problem/275/A
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define SIZE 3

const int rr[] = { 0,0,-1,1,0 };
const int cc[] = { -1,1,0,0,0 };
int main() {
    bool matrix[SIZE][SIZE] = { {1,1,1}, {1,1,1}, {1,1,1} };

    int num;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &num);
            if (num & 1) {
                for (int k = 0; k < 5; k++) {
                    int r = i + rr[k];
                    int c = j + cc[k];
                    if (r >= 0 && r < SIZE&&c >= 0 && c < SIZE) {
                        matrix[r][c] = !matrix[r][c];
                    }
                }
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d", (int)matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
