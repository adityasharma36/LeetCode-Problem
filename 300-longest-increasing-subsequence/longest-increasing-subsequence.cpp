class Solution {
public:
    int solveByReco(vector<int>& nums,int lastIndex,int curr){
        if(curr>=nums.size()) return 0;
        int incl = 0;
        if(lastIndex == -1 || nums[curr]>nums[lastIndex]){
            incl = 1+ solveByReco(nums,curr,curr+1);
        }
        int excl = 0 + solveByReco(nums,lastIndex,curr+1);

        return max(incl,excl);
    }
    int solveByMemo(vector<int>& nums,int lastIndex,int curr,vector<vector<int>>& dp){
        if(curr>=nums.size()) return 0;
        if(dp[curr][lastIndex+1] != -1) return dp[curr][lastIndex+1];
        int incl = 0;
        if(lastIndex == -1 || nums[curr] > nums[lastIndex]){
            incl = 1+ solveByMemo(nums,curr,curr+1,dp);
        }
        int excl = solveByMemo(nums,lastIndex,curr+1,dp);

        dp[curr][lastIndex+1] = max(incl,excl);

        return dp[curr][lastIndex+1];
    }
    int lengthOfLIS(vector<int>& nums) {
        // return solveByReco(nums,-1,0);
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+2,-1));
        return solveByMemo(nums,-1,0,dp);

    }
};