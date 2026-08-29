class Solution {
public:
    int recursiveSol(vector<int>&nums,int i){
        if(i>=nums.size()) return 0;

        int incl = nums[i] + recursiveSol(nums,i+2);
        int excl = 0 + recursiveSol(nums,i+1);

        return max(incl,excl);
    }
    int solveByMemo(vector<int>& nums,int i,vector<int>&dp){
        if(i>=nums.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int incl = nums[i] + solveByMemo(nums,i+2,dp);
        int excl = solveByMemo(nums,i+1,dp);

        dp[i] = max(incl,excl);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        // return recursiveSol(nums,0);
        vector<int>dp(nums.size()+1,-1);
        return solveByMemo(nums,0,dp);

    }
};