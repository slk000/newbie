#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        char lastInTyped = '0';
        int i = 0, j = 0;
        if (typed[j] != name[i]) {
            return false;
        }
        while (i < name.length() && j < typed.length()) {
            while (i < name.length() && j < typed.length() && name[i] == typed[j]) {
                i++;
                j++;
                lastInTyped = typed[j-1];
            }
            // 此时name[i]typed[j]不相等，typed中有多余的相同字符,跳过这些多余字符
            while (i < name.length() && j < typed.length() && lastInTyped == typed[j]) {
                j++;
            }
        }
        return true;
    }
};
int main() {
    string name = "alex";
    string typed = "aaleex";
    cout << Solution().isLongPressedName(name, typed);
}
