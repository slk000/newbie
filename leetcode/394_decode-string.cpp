#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool isAlphabet(char ch) { return ch >='a' && ch <='z'; }
    bool isDigit(char ch) { return ch >= '0' && ch <= '9'; }
    string dfs(string &s, int start, int end) {
        // cout << "start: " << start << " end: " << end << endl;
        if (start >= end) return "";
        string ret = "";
        int repeatTimes = 0;
        int subStart = -1;
        int startCnt = 0;
        int subEnd = -1;


        int i = start;
        for (; i < end && isAlphabet(s[i]); i++) {// leading single char
            ret.push_back(s[i]);
        }
        

        for (; i < end && isDigit(s[i]); i++) {
            repeatTimes = repeatTimes*10 + s[i]-'0';
        }
        cout << "i: " << i << endl;
        
        for (; i < end; i++) {
            if (subStart == -1 && s[i] == '[') {
                subStart = i+1;
                startCnt++;
            }
            else if (s[i] == ']') {
                if (--startCnt == 0) {
                    subEnd = i;
                    break;
                }
            }
        }
                cout << "Segment: [" << start << ", " << end << ")\n";
        cout << "\t Sub: [" << subStart << ", " << subEnd << ")\t Times: " << repeatTimes << "*\"" <<"\""<< endl;
        string sub = dfs(s, subStart, subEnd);

        for (int k = 0; k < repeatTimes; k++) {
            ret += sub;
        }
        cout << "\t ret: " << ret << endl;
        return ret;
    }
    string decodeString(string s) {
        int len = s.length();
        return dfs(s, 0, len);

    }
};

int main() {
    string res = Solution().decodeString("3[a2[c]]");
    cout << "RES: " << res << endl;
    return 0;
}