class Solution {
public:
    int solveByRec(string s,int start ,int end){
        if(start>end) return 0;
        int incl = 0;
        if(s[start] == s[end]){
            incl+=solveByRec(s,start+1,end-1);
        }else{
            incl = 1+ min(solveByRec(s,start+1,end),solveByRec(s,start,end-1));

        }
        return incl;
    }
    int solveByMemo(string s,int start,int end, vector<vector<int>>&dp){
        if(start>end) return 0;
        if(dp[start][end] != -1) return dp[start][end];
        int incl = 0;
        if(s[start] == s[end]){
            incl += solveByMemo(s,start+1,end-1,dp);
        }else{
            incl = 1+ min(solveByMemo(s,start+1,end,dp),solveByMemo(s,start,end-1,dp));
        }
        return dp[start][end]= incl;
    }
    int solveByTabu(string s){
        int n = s.size();
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        for(int i = n-1;i>=0;i--){
            for(int j = i;j<n;j++){
                unsigned long long incl = 0;
                if(s[i] == s[j]){
                    if(i+1 <= j-1){
                    incl += dp[i+1][j-1];

                    }
                }else{
                    incl = 1+ min(dp[i+1][j],dp[i][j-1]);
                }
            dp[i][j]= incl;
            }
        }
        return dp[0][n-1];
    }
    int minInsertions(string s) {
        // int n = s.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // int ans = solveByRec(s,0,n-1);
        // int ans = solveByMemo(s,0,n-1,dp);
        int ans = solveByTabu(s);

        return ans;
    }
};