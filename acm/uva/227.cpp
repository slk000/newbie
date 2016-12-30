//AC
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=830&page=show_problem&problem=163
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

char Map[7][10];
inline bool chk(int i, int j){
    return i>=1&&i<=5&&j>=1&&j<=5;
}
int main(){
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    //int T;
    //cin >> T;
    int si, sj;
    int cnt = 0;
    bool first = true;
    while(1){

        for (int i = 1; i <= 5; i++){
            //gets(Map[i]);
            //cin.get(Map[i], 6);
            //fflush(stdin);
            gets(&Map[i][1]);
            while (!Map[i][1] || '\n' == Map[i][1]) gets(&Map[i][1]);
            if ('Z' == Map[i][1] && Map[i][2]=='\0') return 0;
            for (int j = 1; j <= 5; j++){
                //cin.getline((char*)Map[i],1);
                if (' ' == Map[i][j]){
                    si = i;
                    sj = j;
                }
            }

        }
        if(!first)cout << '\n';
        first = false;
        bool isOk = true;
        char buf[100];
        while(EOF!=scanf("%s", buf)){
            int n = strlen(buf);
            for (int i = 0; i < n; i++){
                switch(buf[i]){
                    case 'A':
                        isOk &= chk(si-1,sj);
                        if(isOk)
                            swap(Map[si-1][sj],Map[si][sj]);
                        si-=1;
                        break;
                    case 'B':
                        isOk &= chk(si+1,sj);
                        if(isOk)
                            swap(Map[si+1][sj],Map[si][sj]);
                        si+=1;
                        break;
                    case 'L':
                        isOk &= chk(si,sj-1);
                        if(isOk)
                            swap(Map[si][sj-1],Map[si][sj]);
                        sj-=1;
                        break;
                    case 'R':
                        isOk &= chk(si,sj+1);
                        if(isOk)
                            swap(Map[si][sj+1],Map[si][sj]);
                        sj+=1;
                        break;
                    case '0':
                        getchar();
                        goto tag;
                        break;
                    default:
                        isOk = false;
                        break;
                }
            }
        }
        tag:;
        cout << "Puzzle #" << ++cnt << ":\n";
        if(isOk){
            for (int i = 1; i <= 5; i++){
                for (int j = 1; j <= 5; j++){
                    cout << Map[i][j];
                    if(j!=5) cout << ' ';
                }
                cout << '\n';
            }
        }
        else{
            cout << "This puzzle has no final configuration.\n";
        }

    }


    return 0;
}