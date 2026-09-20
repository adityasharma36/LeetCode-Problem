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
    int rob(vector<int>& nums) {
        // int ans = solveByRec(nums,0);
        int n = nums.size();
        vector<int>dp(n+1,-1);
        int ans = solveByMemo(nums,0,dp);
        return ans;
    }
};