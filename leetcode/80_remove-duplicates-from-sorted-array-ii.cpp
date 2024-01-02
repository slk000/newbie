#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
    
        int fast = 0, slow = 0; // two read pointers
        int write = slow;
        while (fast < n) {
            // cout << "slow: " << slow << " fast: " << fast << " write:" << write << endl;
            for (;fast < n && nums[fast] == nums[slow];fast++);
            // cout << "\tslow: " << slow << " fast: " << fast << endl;

            int cnt = fast - slow;
            if (cnt <= 2) {
                // cout << "Cnt < 2" << endl;
                for (int i = 0; i < cnt; i++) {
                    nums[write] = nums[slow];
                    slow++;
                    write++;
                }
                // slow === fast; 
                continue;
            }

            // 此时取到一个长于2的区间，直接搬运两个元素
            nums[write++] = nums[slow++];
            nums[write++] = nums[slow++];

            // 不用循环找下一个区间,fast即是下一个区间开头
            slow = fast;
        }
        return write;
    }
};
int main (int argc, char *argv[]) {
    // vector<int> arr {0,0,1,1,1,1,2,2,2,3,3};
    vector<int> arr {1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,3,4,4,4,4,4,5,5,6,7,8,9,9,9,10};
    int cnt = Solution().removeDuplicates(arr);
    for (int i = 0; i < cnt; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
    

    return 0;
}
