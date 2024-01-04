#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findLength_(vector<int>& nums1, vector<int>& nums2) {
        //        i=0                i=1                   i=2
        // nums1  1  2  3  2  1      1  2  3  2  1         1  2  3  2  1
        // nums2  3  2  1  4  7  0      3  2  1  4  7  0         3  2  1  4  7 0
        // cnt    0  1  0  0  0         0  0  0  0               1  2  3
        int n1 = nums1.size(); 
        int n2 = nums2.size();
        int res = 0;
        int cnt = 0; // 遍历过程中累加的重复子数组长度
        for (int i = 0; i < n1; i++) {
            cnt = 0;
            for (int j = 0; i+j < n1 && j < n2; j++) {
                if (nums1[i+j] == nums2[j]) {
                    cnt++;
                }
                else {
                    cnt = 0;
                }
                res = max(res, cnt);
            }
        }
        return res;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2){
        return max(findLength_(nums1, nums2),findLength_(nums2, nums1)); // 交换两个数组再算一遍 nums1[0,0,0,0,1] nums2[1,0,0,0,0]
    }
};
int main() {
    vector<int> nums1{1,2,3,2,1};
    vector<int> nums2{3,2,1,4};
    cout << Solution().findLength_(nums1, nums2) << endl;
}
