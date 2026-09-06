class Solution {
public:
    int solveByRec(int s,int e){
        if(s>=e) return 0;
        int ans = INT_MAX;
        for(int i = s;i<e;i++){
            ans = min(ans,i + max(solveByRec(s,i-1), solveByRec(i+1,e)));
        }
        return ans;
    }
    int solveByMemo(int s,int e , vector<vector<int>>&dp){
        if(s>=e) return 0;
        if(dp[s][e] != -1) return dp[s][e];
        int ans = INT_MAX;
        for(int i = s;i<e;i++){
            ans = min(ans,i+ max(solveByMemo(s,i-1,dp) , solveByMemo(i+1,e,dp)));
        }
        dp[s][e] = ans;
        return dp[s][e];
    }
    int solveByTabu(int n){
        vector<vector<long long>>dp(n+1,vector<long long>(n+1,0));

        for(int s = n;s>=1;s--){
            for(int e = 1;e<=n;e++){
                if(s >=e){
                    continue;
                }
                long long ans = INT_MAX;
                for(int i = s;i<e;i++){
                        ans = min(ans,i+ max(dp[s][i-1] , dp[i+1][e]));
                    }
                dp[s][e] = ans;
            }
        }
        return dp[1][n];
    }
    int getMoneyAmount(int n) {
        // int ans = solveByRec(1,n);
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // int ans = solveByMemo(1,n,dp); 
        int ans = solveByTabu(n);
        return ans;
    }
};