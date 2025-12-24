class Solution {
public:
    int recursiveOp(int n){
        if(n==0) return 0;
        if(n==1) return 1;

        int ans = recursiveOp(n-1)+ recursiveOp(n-2);
        return ans;
    }

    int memoOp(int n,vector<int>&dp){
        if(n== 0) return 0;
        if(n==1) return 1;
        if(dp[n] != -1)return dp[n];

        int ans = memoOp(n-1,dp)+ memoOp(n-2,dp);
        dp[n]= ans;
        return dp[n];
    }
    int fib(int n) {
        // return recursiveOp(n);
        vector<int>dp(n+1,-1);
        return memoOp(n,dp);
    }
};