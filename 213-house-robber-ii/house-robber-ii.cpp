class Solution {
public:
    int solveByRec(vector<int>& nums,int start,int end){
        if(start>end) return 0;
        int incl = nums[start] + solveByRec(nums,start+2,end);
        int excl = solveByRec(nums,start+1,end);
        return max(incl,excl);
    }
    int solveByMemo(vector<int>& nums,int start,int end,vector<int>&dp){
        if(start>end) return 0;
        if(dp[start]!= -1) return dp[start];
        int incl = nums[start] + solveByMemo(nums,start+2,end,dp);
        int excl = solveByMemo(nums,start+1,end,dp);
        dp[start]= max(incl,excl);
        return dp[start];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        // int sol1 = solveByRec(nums,0,n-2);
        // int sol2 = solveByRec(nums,1,n-1);
        vector<int>dp(n+1,-1);
        vector<int>dp2(n+1,-1);

        int sol1 = solveByMemo(nums,0,n-2,dp);
        int sol2 = solveByMemo(nums,1,n-1,dp2);
        int ans = max(sol1,sol2);
        return ans;
    }
};