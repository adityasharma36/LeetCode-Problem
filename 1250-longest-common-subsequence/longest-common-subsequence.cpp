class Solution {
public:
    int solveByRec(string text1,string text2,int i ,int j){
        if(i>=text1.size() || j>=text2.size()) return 0;
        int incl = 0;
        if(text1[i] == text2[j]){
            incl = 1+ solveByRec(text1,text2,i+1,j+1);
        }
        int excl = max(solveByRec(text1,text2,i+1,j),solveByRec( text1,text2,i,j+1));

        return max(incl,excl);
    }
    int solveByMemo(string text1,string text2,int i ,int j , vector<vector<int>>&dp){

        if(i>=text1.size() || j>= text2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int incl = 0;
        if(text1[i] == text2[j]){
            incl = 1+ solveByMemo(text1,text2,i+1,j+1,dp);
        }
        int excl = max(solveByMemo(text1,text2,i+1,j,dp), solveByMemo(text1,text2,i,j+1,dp));

        dp[i][j]= max(incl,excl);
        return dp[i][j];
    }
    int solveByTabu(string text1,string text2){
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                int incl = 0;
                if(text1[i] == text2[j]){
                    incl = 1+ dp[i+1][j+1];
                }
                int excl = max(dp[i+1][j], dp[i][j+1]);

                dp[i][j]= max(incl,excl);
            }
        }
        return dp[0][0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        // return solveByRec(text1,text2,0,0);
        // int n = text1.size();
        // int m = text2.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return solveByMemo(text1,text2,0,0,dp);
        return solveByTabu(text1,text2);
    }
};