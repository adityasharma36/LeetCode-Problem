class Solution {
public:
    int solveByRec(string &s,string& t,int i ,int j){
        if(j>= t.size()) return 1;
        if(i >= s.size()) return 0;

        int ans = 0;
        if(s[i] == t[j]){
            ans+= solveByRec(s,t,i+1,j+1);
        }
            ans+=solveByRec(s,t,i+1,j);
        return ans;
    }
    int solveByMemo(string s,string t,int i ,int j,vector<vector<int>>&dp){
        if(j>=t.size()) return 1;
        if(i>=s.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(s[i] == t[j]){
             ans += solveByMemo(s,t,i+1,j+1,dp);
        }
        ans+=solveByMemo(s,t,i+1,j,dp);
        dp[i][j] = ans;
        return dp[i][j];
    }
    int solveByTabu(string s,string t){
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i = 0;i<=n;i++){
            dp[i][m] = 1;
        }

        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                long long ans = 0;
                if(s[i] == t[j]){
                    ans += dp[i+1][j+1];
                }
                ans+=dp[i+1][j];
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    int numDistinct(string s, string t) {
        // int ans = solveByRec(s,t,0,0);
        // int n = s.size();
        // int m = t.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // int ans = solveByMemo(s,t,0,0,dp);
        int ans = solveByTabu(s,t);
        return ans;
    }
};