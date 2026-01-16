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

    bool solveByTab(vector<int>& nums){
        int total = accumulate(nums.begin(), nums.end(), 0);
         if (total % 2 != 0) return false;

        int target = total / 2;

        vector<vector<bool>> dp(target + 1, vector<bool>(nums.size()+1,false ));

        for(int i = 0;i<=nums.size();i++){
            dp[0][i] = true;
        }
        for (int sum = 1; sum <= target; sum++) {
        for (int start = nums.size() - 1; start >= 0; start--) {
            bool take = false;
            if (nums[start] <= sum) {
                take = dp[sum - nums[start]][start + 1];
            }
            bool skip = dp[sum][start + 1] ;

            dp[sum][start] = take || skip;
        }
    }
        return dp[target][0];

    }
    bool spaceOptimise(vector<int>&nums){
         int total = accumulate(nums.begin(), nums.end(), 0);
         if (total % 2 != 0) return false;
        int target = total / 2;
        vector<bool>curr(target+1,false);
        vector<bool>next(target+1,false);
        curr[0] = true;
        next[0] = true;
           for (int start = nums.size() - 1; start >= 0; start--) {
                 for (int sum = 1; sum <= target; sum++) {

                    bool take = false;

                    if (nums[start] <= sum) {

                        take = next[sum - nums[start]];
                    }
                    bool skip = next[sum] ;

                    curr[sum] = take || skip;
                }
                next = curr;
           }
           return curr[target];
    }

    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false;

        int target = total / 2;
        vector<vector<int>> dp(target + 1, vector<int>(nums.size(), -1));

        // return memo(nums, target, 0, dp);
        // return solveByTab(nums);
        return spaceOptimise(nums);
    }
};