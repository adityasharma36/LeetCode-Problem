class Solution {
public:
    set<string> mp;

    bool solveByRec(string s, int i, int j){
        if(i >= s.size()) return true;

        if(j >= s.size()) return false;

        string str = s.substr(i, j-i+1);

        bool ans = false;

        if(mp.find(str) != mp.end()){
            ans = ans || solveByRec(s, j+1, j+1);
        }

        bool excl = solveByRec(s, i, j+1);

        return ans || excl;
    }
    bool solveByMemo(string s,int i,int j,vector<vector<int>>& dp){
        if(i>=s.size()) return true;
        if(j>=s.size()) return false;
        if(dp[i][j] != -1) return dp[i][j];
        string str = s.substr(i,j-i+1);
        bool ans = false;
        if(mp.find(str) != mp.end()){
            ans = ans || solveByMemo(s,j+1,j+1,dp);
        }
        bool excl = solveByMemo(s,i,j+1,dp);
        dp[i][j]= ans || excl;

        return dp[i][j];

    }
    bool solveByTabu(string s){
        int n = s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i = 0;i<=n;i++){
            dp[n][i]= 1;
        }
        for(int i = n-1;i>=0;i--){
            for(int j = n-1;j>=i;j--){
                string str = s.substr(i,j-i+1);
                bool ans = false;
            if(mp.find(str) != mp.end()){
                ans = ans || dp[j+1][j+1];
            }
            bool excl = dp[i][j+1];
            dp[i][j]= ans || excl;
            }
        }
        return dp[0][0];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto i : wordDict){
            mp.insert(i);
        }

        // int ans = solveByRec(s,0,0);
        int n = s.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // int ans = solveByMemo(s,0,0,dp);

        bool ans = solveByTabu(s);
        return ans;
    }
};