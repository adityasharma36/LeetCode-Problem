class Solution {
public:
    void convertAll(vector<string>& strs, vector<pair<int,int>>&mp){
        for(auto str : strs){
            int m = 0;
            int n = 0;
            for(auto s: str){
                if(s == '0'){
                m++;
                }else{
                    n++;
                }
            }
            mp.push_back({m,n});
        }
    }
    int solveByRec(int m,int n,int i,vector<pair<int,int>>& mp){
        if(i >= mp.size()) return 0;
        int incl = 0;
        auto front = mp[i];
        int zero = front.first;
        int one = front.second;
        if(m-zero >= 0 && n-one >= 0){
             incl = 1+ solveByRec(m-zero,n-one,i+1,mp);
        }
        int excl = solveByRec(m,n,i+1,mp);
        return max(incl,excl);
    }
    int solveByMemo(int m, int n, int i,
                    vector<pair<int,int>>& mp,
                    vector<vector<vector<int>>>& dp) {

        if(i >= mp.size()) return 0;

        // Memoization
        if(dp[i][m][n] != -1) {
            return dp[i][m][n];
        }

        int incl = 0;

        auto front = mp[i];

        int zero = front.first;
        int one = front.second;

        if(m - zero >= 0 && n - one >= 0) {
            incl = 1 + solveByMemo(
                m - zero, n - one, i + 1, mp, dp
            );
        }

        int excl = solveByMemo(m, n, i + 1, mp, dp);

        return dp[i][m][n] = max(incl, excl);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>mp;
        convertAll(strs,mp);

        // int ans = solveByRec(m,n,0,mp);
          int sz = strs.size();

        vector<vector<vector<int>>> dp(
            sz,
            vector<vector<int>>(
                m + 1,
                vector<int>(n + 1, -1)
            )
        );
        int ans = solveByMemo(m,n,0,mp,dp);
        return ans;
    }
};