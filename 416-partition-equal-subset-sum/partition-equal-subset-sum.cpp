class Solution {
public:
    bool partitionSum(vector<int>& nums,int sum,int start){
        if(sum == 0){
            return true;
        }
        if (start >= nums.size() || sum < 0) return false;
        
        return (partitionSum(nums,sum-nums[start],start+1) || partitionSum(nums,sum,start+1));
     
      
    }
    bool memo(vector<int>& nums, int sum, int start, vector<vector<int>>& dp) {
        if (sum == 0) return true;
        if (start >= nums.size() || sum < 0) return false;

        if (dp[sum][start] != -1)
            return dp[sum][start];

        dp[sum][start] =
            memo(nums, sum - nums[start], start + 1, dp) ||
            memo(nums, sum, start + 1, dp);

        return dp[sum][start];
    }

    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false;

        int target = total / 2;
        vector<vector<int>> dp(target + 1, vector<int>(nums.size(), -1));

        return memo(nums, target, 0, dp);
    }
};