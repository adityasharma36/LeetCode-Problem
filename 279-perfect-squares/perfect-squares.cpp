class Solution {
public:
    int solveByRec(int n) {
        if(n == 0) return 0;

        int ans = INT_MAX;

        for(int i = 1; i*i <= n; i++){
            int sqt = i*i;

            int recursionAns = 1 + solveByRec(n - sqt);

            ans = min(ans, recursionAns);
        }

        return ans;
    }
    int solveByMemo(int n ,vector<int>&dp){
        if(n == 0){
            return 0;
        }
        if(dp[n] != -1) return dp[n];
        int ans = INT_MAX;
        for(int i = 1;i*i<=n;i++){
            int sqt = i*i;
            int recursionAns = 1 + solveByMemo(n-sqt,dp);
            ans = min(ans,recursionAns);
            dp[n]= ans;
        }
        return dp[n];
    }
    int solveByTabu(int n){
    vector<int> dp(n+1, 0);

    for(int i = 1; i <= n; i++){

        int ans = INT_MAX;

        for(int j = 1; j*j <= i; j++){

            int sqt = j*j;

            int recursionAns = 1 + dp[i-sqt];

            ans = min(ans, recursionAns);
        }

        dp[i] = ans;
    }

    return dp[n];
}
    int numSquares(int n) {
        // int ans = solveByRec(n);
        // vector<int>dp(n+1,-1);
        // int ans = solveByMemo(n,dp);
        int ans = solveByTabu(n);
        return ans;
    }
};