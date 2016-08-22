//http://bailian.openjudge.cn/2016acmmid/g/
//http://bailian.openjudge.cn/practice/1753/
#include <cstdio>
#include <memory.h>
#define MAX 4
using namespace std;
bool all[1<<16];
bool vis[1<<16];
int cnt;
int flipCnt;
int rr[] = {-1, 1, 0, 0, 0};
int cc[] = {0, 0, -1, 1, 0};

int change(int r, int c, int status) {
    status^=(1<<((MAX-1-r)*MAX))<<(MAX-1-c);
    return status;
}
bool get(int r, int c, int status) {
    return (status>>(MAX-1-c))>>(r*MAX) & 1;
}
int flip(int r, int c, int status){

    for (int i = 0; i < 5; i++) {
        int nr = r+rr[i], nc = c+cc[i];
        if (nr >= 0 && nc < MAX && nc >= 0 && nc < MAX) {
            status = change(nr, nc, status);
        }
    }
    return status;
}
void d(int r, int c,int status) {

    if (flipCnt >=16 ) return;
    status = flip(r,c,status);
    flipCnt++;
    printf("%x\n", status );
    //return;
    if (status == 0xFFFF){
        cnt++;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nr = r+rr[i], nc = c+cc[i];
        if (nr>=0 && nr<MAX && nc>=0 && nc<MAX && !vis[status]){
            vis[status] = true;
            flipCnt++;
            d(nr, nc, status);

            vis[status] = false;

            flipCnt--;
        }

    }

}
int main (){
    int input = 0;
    d(0,0,0);
    printf("%d\n", cnt);
    for (int i = 0 ; i < MAX; i++) {
        for (int j = 0; j < MAX+1; j++) {
            char tmp;
            scanf("%c", &tmp);
            if (tmp=='\n') {
                break;
            }

            if (tmp == 'b') {
                input = change(i, j, input);
            }
        }

    }
    input = flip(1,1,input);
    printf("%d\n", input);
    return 0;
}

