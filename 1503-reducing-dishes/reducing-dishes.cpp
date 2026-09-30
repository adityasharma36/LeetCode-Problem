class Solution {
public:
    int solveByRec(vector<int>&nums,int i,int time){
        if(i>=nums.size()) return 0;
        int incl = nums[i] * time + solveByRec(nums,i+1,time+1);
        int excl = solveByRec(nums,i+1,time);
        return max(incl,excl);
    }
    int solveByMemo(vector<int>& nums,int i,int time,vector<vector<int>>&dp){
        if(i>=nums.size()) return 0;
        if(dp[i][time] != -1 ) return dp[i][time];
        int incl = nums[i] * time + solveByMemo(nums,i+1,time+1,dp);
        int excl = solveByMemo(nums,i+1,time,dp);
        return dp[i][time]= max(incl,excl);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(begin(satisfaction),end(satisfaction));
        // int ans = solveByRec(satisfaction,0,1);
        int n = satisfaction.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans = solveByMemo(satisfaction,0,1,dp);
        return ans;
    }
};