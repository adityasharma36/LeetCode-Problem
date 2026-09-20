class Solution {
public:
    int solveByRec(vector<int>& nums,int i){
        if(i>=nums.size()) return 0;
        int incl = nums[i] + solveByRec(nums,i+2);
        int excl = solveByRec(nums,i+1);
        return max(incl,excl);
    }
    int solveByMemo(vector<int>& nums,int i,vector<int>&dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!= -1) return dp[i];
        int incl = nums[i] + solveByMemo(nums,i+2,dp);
        int excl = solveByMemo(nums,i+1,dp);
        return dp[i] = max(incl,excl);
    }
    int solveByTabu(vector<int>& nums){
        int n = nums.size();
        vector<int>dp(n+3,0);
        for(int i=  n-1;i>=0;i--){
        int incl = nums[i] + dp[i+2];
        int excl = dp[i+1];
         dp[i] = max(incl,excl);
        }
        return dp[0];
    }
    int rob(vector<int>& nums) {
        // int ans = solveByRec(nums,0);
        // int n = nums.size();
        // vector<int>dp(n+1,-1);
        // int ans = solveByMemo(nums,0,dp);
        int ans = solveByTabu(nums);
        return ans;
    }
};