class Solution {
public:
    int crossArea(vector<int> &nums, int s, int e, int mid){
        int leftMax = -0x3f3f3f3f;
        int rightMax = leftMax;
        int sum = 0;
        for(int i = mid; i >=s; i--){
            sum += nums[i];
            leftMax = max(sum, leftMax);
        }
        sum = 0;
        for(int i = mid+1; i < e; i++){
            sum +=nums[i];
            rightMax = max(sum, rightMax);
        }
        return max(leftMax+rightMax,max(leftMax,rightMax));
    }
    int fun(vector<int> &nums, int s, int e){
        if(e-s == 1) return nums[s];
        int mid = (s+e)/2;
        int left = fun(nums, s, mid);
        int right = fun(nums, mid, e);
        int cross = crossArea(nums, s, e, mid);
        return max(left, max(right,cross));
    }
    int maxSubArray(vector<int>& nums) {
        return fun(nums, 0, nums.size());

    }
};