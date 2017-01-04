//AC
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=430
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int cnt[26];
int main(){
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    string str1, str2;
    while(cin >> T && T!=-1){
        memset(cnt, 0, sizeof(cnt));
        cin >> str1 >> str2;
        int cntErr = 0;
        int len1 = str1.length();
        int kind = 0;
        for (int i = 0; i < len1; i++){
            kind += cnt[str1[i]-'a']==0;
            cnt[str1[i]-'a']++;
        }
        int len2 = str2.length();
        for (int i = 0; i < len2; i++){
            if (cnt[str2[i]-'a']>0){
                cnt[str2[i]-'a'] = 0;
                kind--;
            }
            else{
                cntErr++;
            }
            if (kind == 0){
                break;
            }
        }
        cout << "Round " << T << '\n';
        if (cntErr >= 7){
            cout << "You lose.\n";
        }
        else {
            int isClear = true;
            for (int i = 0; i < 26; i++){
                isClear &= !cnt[i];
            }
            if (isClear){
                cout << "You win.\n";
            }
            else {
                cout << "You chickened out.\n";
            }
        }
    }
    return 0;
}