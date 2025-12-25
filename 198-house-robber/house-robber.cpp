class Solution {
public:
    int recursivePro(vector<int>& nums,int i){
        if(i>= nums.size()) return 0;

        int include = nums[i]+ recursivePro(nums,i+2);
        int exclude = recursivePro(nums,i+1);
        return max(include,exclude);
    }
    int solveByMemo(vector<int>& nums,vector<int>& dp,int i){
        if(i>= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int include = nums[i] + solveByMemo(nums,dp,i+2);
        int exclude = solveByMemo(nums,dp,i+1);
        dp[i]= max(include,exclude);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        // return recursivePro(nums,0);
        vector<int>dp(nums.size()+1 ,-1);
        return solveByMemo(nums,dp,0);
    }
};