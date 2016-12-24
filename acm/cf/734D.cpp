//AC
//http://codeforces.com/problemset/problem/734/D
#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#define INF 0x3f3f3f3f3f3f3f3f
#define LL long long
using namespace std;
typedef struct P {
    int r, c;
    double dis;
    char type;
    P() {}
    P(int _r, int _c, double _dis, char _type) { r = _r; c = _c; dis = _dis; type = _type; }
}P;
enum { UP, DOWN, LEFT, RIGHT, LEFTUP, RIGHTUP, LEFTDOWN, RIGHTDOWN };
const double xl[] = { 0,0,0,0,1,-1,-1,1 };
inline double xielv(P &a, P &b) {
    return (double)(b.r - a.r) / (double)(b.c - a.c);
}
inline double getDis(P &a, P&b) {
    return sqrt((double)(b.r - a.r)*(double)(b.r - a.r) + (double)(b.c - a.c)*(double)(b.c - a.c));
}
inline int getPos(P &a, P &b) { //a点在white king(b点)的哪个方位
    if (a.c == b.c && a.r < b.r) return UP;
    if (a.c == b.c&&a.r > b.r) return DOWN;
    if (a.c < b.c&&a.r == b.r) return LEFT;
    if (a.c > b.c&&a.r == b.r) return RIGHT;
    if (a.c < b.c&&a.r < b.r && xielv(a, b) == xl[LEFTUP]) return LEFTUP;
    if (a.c > b.c&&a.r < b.r && xielv(a, b) == xl[RIGHTUP]) return RIGHTUP;
    if (a.c < b.c&&a.r > b.r && xielv(a, b) == xl[LEFTDOWN]) return LEFTDOWN;
    if (a.c > b.c&&a.r > b.r && xielv(a, b) == xl[RIGHTDOWN]) return RIGHTDOWN;
}

bool operator<(const P &a, const P &b) {
    return a.dis < b.dis;
}
P p[8];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif // !ONLINE_JUDGE
    int n;
    scanf("%d", &n);
    fill(p, p + 8, P(-INF, -INF, INF, 0));
    P w;
    scanf("%d %d", &w.r, &w.c); w.type = 'W'; w.dis = 0;

    for (int i = 0; i < n; i++) {
        getchar();
        P t;
        scanf("%c %d %d", &t.type, &t.r, &t.c);
        int tpos = getPos(t, w);

        if (w.c - t.c == 0) { //上下方向
            int tpos = getPos(t, w);
            t.dis = getDis(t, w);
            if (t < p[tpos]) p[tpos] = t;
        }
        else { //左右，对角方向
            double txl = xielv(t, w);
            if (txl == 0 || txl == -1 || txl == 1) {
                int tpos = getPos(t, w);
                t.dis = getDis(t, w);
                if (t < p[tpos]) p[tpos] = t;
            }
        }
    }

    bool ans = false;

    for (int i = UP; i <= RIGHT; i++) {
        ans |= (p[i].type == 'R' || p[i].type == 'Q');
    }
    for (int i = LEFTUP; i <= RIGHTDOWN; i++) {
        ans |= (p[i].type == 'B' || p[i].type == 'Q');
    }

    puts(ans ? "YES" : "NO");
    return 0;
}
/*
longer ver.
#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAX 500000 
#define INF 0x3f3f3f3f3f3f3f3f
#define LL long long
using namespace std;
typedef struct P {
    int r, c;
    double dis;
    char type;
    P() {}
    P(int _r, int _c, double _dis, char _type) { r = _r; c = _c; dis = _dis; type = _type; }
}P;
enum { UP, DOWN, LEFT, RIGHT, LEFTUP, RIGHTUP, LEFTDOWN, RIGHTDOWN };
const double xl[] = { 0,0,0,0,1,-1,-1,1 };
inline double xielv(P &a, P &b) {
    return (double)(b.r - a.r) / (double)(b.c - a.c);
}
inline double getDis(P &a, P&b) {
    return sqrt((double)(b.r - a.r)*(double)(b.r - a.r) + (double)(b.c - a.c)*(double)(b.c - a.c));
}
inline int getPos(P &a, P &b) { //view from b
    if (a.c == b.c && a.r < b.r) return UP;
    if (a.c == b.c&&a.r > b.r) return DOWN;
    if (a.c < b.c&&a.r == b.r) return LEFT;
    if (a.c > b.c&&a.r == b.r) return RIGHT;
    if (a.c < b.c&&a.r < b.r && xielv(a, b) == xl[LEFTUP]) return LEFTUP;
    if (a.c > b.c&&a.r < b.r && xielv(a, b) == xl[RIGHTUP]) return RIGHTUP;
    if (a.c < b.c&&a.r > b.r && xielv(a, b) == xl[LEFTDOWN]) return LEFTDOWN;
    if (a.c > b.c&&a.r > b.r && xielv(a, b) == xl[RIGHTDOWN]) return RIGHTDOWN;
}

bool operator<(const P &a, const P &b) {
    return a.dis < b.dis;
}
P p[8] = {
    P(-INF,-INF,INF,0),
    P(-INF,-INF,INF,0),
    P(-INF,-INF,INF,0),
    P(-INF,-INF,INF,0),
    P(-INF,-INF,INF,0),
    P(-INF,-INF,INF,0),
    P(-INF,-INF,INF,0),
    P(-INF,-INF,INF,0),
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif // !ONLINE_JUDGE
    int n;
    scanf("%d", &n);
    P w;
    scanf("%d %d", &w.r, &w.c); w.type = 'W'; w.dis = 0;

    for (int i = 0; i < n; i++) {
        getchar();
        P t;
        scanf("%c %d %d", &t.type, &t.r, &t.c);


        if (w.c - t.c == 0) {
            int tpos = getPos(t, w);
            t.dis = getDis(t, w);
            if (tpos == UP) {
                if (t < p[UP]) {
                    p[UP] = t;
                }
            }
            else if (tpos == DOWN) {
                if (t < p[DOWN]) {
                    p[DOWN] = t;
                }
            }
        }
        else {

            double txl = xielv(t, w);
            if (txl == 0) {
                int tpos = getPos(t, w);
                t.dis = getDis(t, w);
                if (tpos == LEFT) {
                    if (t < p[LEFT]) {
                        p[LEFT] = t;
                    }
                }
                else if (tpos == RIGHT) {
                    if (t < p[RIGHT]) {
                        p[RIGHT] = t;
                    }
                }
            }
            else if (txl == -1) {
                int tpos = getPos(t, w);
                t.dis = getDis(t, w);
                if (tpos == RIGHTUP) {
                    if (t < p[RIGHTUP]) {
                        p[RIGHTUP] = t;
                    }
                }
                else if (tpos == LEFTDOWN) {
                    if (t < p[LEFTDOWN]) {
                        p[LEFTDOWN] = t;
                    }
                }

            }
            else if (txl == 1) {
                int tpos = getPos(t, w);
                t.dis = getDis(t, w);
                if (tpos == LEFTUP) {
                    if (t < p[LEFTUP]) {
                        p[LEFTUP] = t;
                    }
                }
                else if (tpos == RIGHTDOWN) {
                    if (t < p[RIGHTDOWN]) {
                        p[RIGHTDOWN] = t;
                    }
                }
            }
        }
    }

    bool ans = false;
    if (p[UP].type) {
        if (p[UP].type == 'R' || p[UP].type == 'Q') ans |= true;
    }
    if (p[DOWN].type) {
        if (p[DOWN].type == 'R' || p[DOWN].type == 'Q') ans |= true;
    }
    if (p[LEFT].type) {
        if (p[LEFT].type == 'R' || p[LEFT].type == 'Q') ans |= true;
    }
    if (p[RIGHT].type) {
        if (p[RIGHT].type == 'R' || p[RIGHT].type == 'Q') ans |= true;
    }
    //LEFTUP, RIGHTUP, LEFTDOWN, RIGHTDOWN
    if (p[LEFTUP].type) {
        if (p[LEFTUP].type == 'B' || p[LEFTUP].type == 'Q') ans |= true;
    }
    if (p[RIGHTUP].type) {
        if (p[RIGHTUP].type == 'B' || p[RIGHTUP].type == 'Q') ans |= true;
    }
    if (p[LEFTDOWN].type) {
        if (p[LEFTDOWN].type == 'B' || p[LEFTDOWN].type == 'Q') ans |= true;
    }
    if (p[RIGHTDOWN].type) {
        if (p[RIGHTDOWN].type == 'B' || p[RIGHTDOWN].type == 'Q') ans |= true;
    }
    puts(ans ? "YES" : "NO");
    return 0;
}
*/