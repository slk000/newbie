//AC
//IDA*
//http://acm.hdu.edu.cn/showproblem.php?pid=1667
//http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=2396
//http://bailian.openjudge.cn/practice/2286/
//http://bailian.openjudge.cn/2016acmmid/e/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>

using namespace std;
#define INF 0x3f3f3f3f
const int indexs[8][7] = {
    { 0,2,6,11,15,20,22 },    //AF
    { 1,3,8,12,17,21,23 },    //BE
    { 10,9,8,7,6,5,4 },       //CH
    { 19,18,17,16,15,14,13 }, //DG

    { 23,21,17,12,8,3,1 },
    { 22,20,15,11,6,2,0 },
    { 13,14,15,16,17,18,19 },
    { 4,5,6,7,8,9,10 },
};
const int reverseOp[] = { 5,4,7,6,1,0,3,2,-1 };
const int center[] = { 6,7,8,11,12,15,16,17 };
int min(int a, int b) { return a>b ? b : a; }
int max(int a, int b) { return a<b ? b : a; }
char map[24];
char tmpRoute[101];
bool hasSolution;

void pull(int op) {
    int tmp = map[indexs[op][0]];
    for (int i = 0; i < 7 - 1; i++) {
        map[indexs[op][i]] = map[indexs[op][i + 1]];
    }
    map[indexs[op][6]] = tmp;
}

int h() {
    int cnt[3] = { 0,0,0 }; // count for 1, 2, 3
    int maxStep = -1;
    for (int i = 0; i < 8; i++) {
        cnt[map[center[i]] - 1]++;
        maxStep = max(maxStep, cnt[map[center[i]] - 1]);
    }
    return 8 - maxStep;
}

void d(int depth, int lastOp, int maxDepth) {
    if (hasSolution)return;
    if (h() == 0) {
        hasSolution = true;
        tmpRoute[depth] = '\0';
        printf("%s\n%d\n",tmpRoute, map[center[0]]);
        return;
    }
    if (depth > maxDepth || depth + h() > maxDepth) return;
    int stepsAfterNextOp = INF;
    for (int nextOp = 0; nextOp < 8; nextOp++) {
        if (nextOp != reverseOp[lastOp]) {
            pull(nextOp);
            tmpRoute[depth] = nextOp + 'A';
            d(depth + 1, nextOp, maxDepth);
            pull(reverseOp[nextOp]);
        }
    }
}
int main() {
    while (1) {
        for (int i = 0; i < 24; i++) {
            scanf("%d", &map[i]);
            if (map[i] == 0) return 0;
        }
        hasSolution = false;
        if (h() == 0) {
            printf("No moves needed\n%d\n",map[center[0]]);
            continue;
        }
        for (int depth = 1; !hasSolution; depth++) {
            d(0, 8, depth);
        }
    }
    return 0;
}