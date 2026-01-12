class Solution {
public:
    int robber(vector<int>& nums,int index){
        if(index>=nums.size()) return 0;

        int inclde = nums[index] + robber(nums,index+2);
        int exlucde = 0 + robber(nums,index+1);
        return max(inclde,exlucde);
    }
    int memo(vector<int>& nums, int index, vector<int>& dp) {
        if(index >= nums.size()) return 0;

        if(dp[index] != -1) return dp[index];

        int include = nums[index] + memo(nums, index + 2, dp);
        int exclude = memo(nums, index + 1, dp);

        dp[index] = max(include, exclude);
        return dp[index];
    }
    int tabu(vector<int>& nums){

        vector<int>dp(nums.size()+2,0);

        for(int i = nums.size()-1;i>=0;i--){

        int include = nums[i] + dp[i + 2];

        int exclude = dp[i + 1];

        dp[i] = max(include, exclude);

        }
        return dp[0];
    }
    int rob(vector<int>& nums) {
        // vector<int> dp(nums.size(), -1);
        // return memo(nums, 0, dp);
        return tabu(nums);
    }
};