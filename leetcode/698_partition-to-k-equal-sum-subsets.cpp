#include <iostream>
#include <numeric>
#include <bitset>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    int targetSum;
    int k;
    int sumOfBucket[16+1];
    // int dp[65536+10]; // 2^16
    // status: status of one turn
    bool dfs(uint32_t &status, vector<int> &nums, int start,int cnt){
        // cout <<  std::bitset<16>(status).to_string() << endl;
        if(cnt == k) return true;
        if(sumOfBucket[cnt] == targetSum) {
            bool res = dfs(status, nums, 0, cnt+1);// fill next partition
            dp[status] = res;
            return res;
        }
        if(dp[status] >= 0) return dp[status];

        uint32_t mask = 1 << start;
        for(int i = start; i < nums.size(); i++,mask<<=1){
            if(!(status & mask)){ // find a unused num
                if(sumOfBucket[cnt]+nums[i] > targetSum) continue;
                sumOfBucket[cnt] += nums[i];
                status |= mask; 
                if(dfs(status, nums, i+1, cnt)){
                    return true;
                }
                status &= ~mask;
                sumOfBucket[cnt] -= nums[i];

            }
        }

        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), sum);
        if(sum % k != 0) return false;
        targetSum = sum / k;
        
        this->k = k;
        uint32_t status = 0;
        int partSum = 0;
        memset(sumOfBucket, 0, sizeof(sumOfBucket));
        // memset(dp, -1, sizeof(dp));
        // sort(nums.begin(), nums.end());
        return dfs(status, nums, 0, 0);
    }
};

int main(){
    // vector<int> nums = {2,2,2,2,3,4,5};intk=4;
    // vector<int> nums = {4, 3, 2, 3, 5, 2, 1};int k= 4;
    // vector<int> nums = {10,12,1,2,10,7,5,19,13,1};int k=4;
    vector<int> nums = {12,1,2,3,18,2,5,2,11,1};int k = 3;
    cout << Solution().canPartitionKSubsets(nums, k) << endl;
    return 0;
}
