#include <bits/stdc++.h>
using namespace std;
// 从右往左看，把递减区间换成[x-1][9][9]其中x-1是原来数位上的数-1   1(998) -> 1899
// 18(98) -> 1889
// 1(887) -> 1799
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        // if (n == 0) return 0;
        int oldN = n;
        vector<int> digits;
        bool alreadyOrdered = true; // 判断原来的数字是否有序，如果有直接返回
        while (oldN) {
            alreadyOrdered &= (digits.empty() || (oldN % 10) <= digits.back());
            digits.push_back(oldN%10);
            oldN = oldN/10;
        }
        if (alreadyOrdered) {
            return n;
        }

        int x9 = 0; // 构造的后半截数字x9999...
        int x = 1; // 构造的后半截数字的最高这位数x应该再减去1,用x凑出1000...一是为了得到这一数位，二是为了将数字后半截清零
        int pos = digits.size()-1; // 如果下面的循环没找到这个区间的分界点，就指向原数的最高位

        // 从低数位开始遍历，注意数组中数位是逆序存放的
        for (int i = 0; i < digits.size() - 1; i++) {
            if (digits[i] > digits[i+1]) {
               pos = i;
               break;
            }
            x9 = x9*10 + 9;
            x = x*10;
        }
        x9 += (digits[pos]-1) * x; // 构造的部分加上最高位
        cout << "x9" << x9 << endl;
        
        //
        int res = (n / x / 10)  * (x*10)  +x9;
        return res;
    }
};

int main() {
    int n;
    while (cin >> n ) {
        cout << Solution().monotoneIncreasingDigits(n) << endl;
    }
}
