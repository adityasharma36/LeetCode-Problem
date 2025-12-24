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

    int tabulationOp(int n){
        vector<int>dp(n+1,-1);
        dp[0]= 0;
        if(n==0) return 0;
        
        dp[1]= 1;

        for(int i = 2;i<=n;i++){
            dp[i] = dp[i-1]+ dp[i-2];
        }
        return dp[n];
    }
    int fib(int n) {
        // return recursiveOp(n);
        vector<int>dp(n+1,-1);
        // return memoOp(n,dp);
        return tabulationOp(n);
    }
};