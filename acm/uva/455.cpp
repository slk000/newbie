//AC
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=830&page=show_problem&problem=396
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
bool chk(string &str, int r){
    int pieceCnt = str.length()/r;
    bool flag = true;
    for(int i = 0; i < r; i++){
        for (int j = 0; j < pieceCnt; j++){
            flag &= str[i]==str[i+j*r];
            if(!flag)return false;
        }
    }
    return true;
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    int T;
    cin >> T;

    while(T--){
        string str;
        cin >> str;
        int n = str.length();
        for (int i = 1; i <= n; i++){

            if(n%i==0&&chk(str, i)){
                cout << i << "\n";
                break;
            }
        }
        if(T) cout << "\n";
    }

    return 0;
}