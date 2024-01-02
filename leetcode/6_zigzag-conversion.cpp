#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int cnt = 0;
        int len = s.length();
        if(numRows == 1) return s;
        int lenPerPair = 2*numRows-2;
        int pairCnt = (len / lenPerPair) + (bool)(len%lenPerPair);
        /*
            P
            A   L
            Y A
            P 
            is a pair
        */
        vector<string> cols(2*pairCnt); 
        /*
            colums:
            [0]: "PAYP"
            [1]: "LA"
            [2]: "ISHI"
        */

        int pair = 0; // idx of pair
        while(cnt < len) {
            for(int i = 0; i < numRows && cnt < len; i++) {
                // first col in a pair
                cols[pair] += s[cnt];
                cnt++;
            }
            // if(cnt >= len) break;
            for(int i = 0; i < numRows-2 && cnt < len; i++) {
                // second
                cols[pair+1] = s[cnt] + cols[pair+1]; // reverse order
                cnt++;
            }
            pair+=2;
        }

        for(string &str : cols) {
            cout << str << endl;
        }

        string res = "";
        // first line i=0: P     I    N
        for(int j = 0; j < 2*pairCnt; j+=2) {
            res += cols[j][0];
        }
        // middle lines
        for(int i = 1; i < numRows-1; i++) {
            for(int j = 0; j < cols.size(); j++) {
                // cout << i <<' '<<j<<endl;
                if(j & 1) { //   '/'
                    if(i-1 >= cols[j].length()) continue;
                    res += cols[j][i-1];
                }
                else {      //   '|'
                    if(i >= cols[j].length()) continue;
                    res += cols[j][i];
                }
            }
        }
        // last line i = numRows-1
        for(int j = 0; j < cols.size() && numRows-1 < cols[j].length(); j+=2) {
            res += cols[j][numRows-1];
        }

        return res;
    }

};

int main() {
    string s = "ABCDE";

    cout << Solution().convert(s, 4) << endl;
    return 0;
}