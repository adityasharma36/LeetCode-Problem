class Solution {
public:
    bool solveByRec(string s1,string s2,string s3,int i ,int j,int k){
        // base case
        if(k >= s3.size() && i >=s1.size() && j>=s2.size()) return true;

        bool incl = false;
        if(i<s1.size() && s1[i]== s3[k]){
            incl = incl || solveByRec(s1,s2,s3,i+1,j,k+1);
        }
        if(j <s2.size() && s2[j]== s3[k]){
            incl = incl || solveByRec(s1,s2,s3,i,j+1,k+1);
        }
        return incl;
    }
    bool solveByMemo(string s1, string s2, string s3,int i,int j,int k,vector<vector<vector<int>>>&dp){
        if(k >= s3.size() && i>=s1.size() && j>= s2.size()) return true;
        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }
        bool incl = false;
        if(i<s1.size() && s1[i]== s3[k]){
            incl = incl || solveByMemo(s1,s2,s3,i+1,j,k+1,dp);
        }
        if(j <s2.size() && s2[j]== s3[k]){
            incl = incl || solveByMemo(s1,s2,s3,i,j+1,k+1,dp);
        }
        return dp[i][j][k]=  incl;
    }
    bool isInterleave(string s1, string s2, string s3) {
        // bool ans = solveByRec(s1,s2,s3,0,0,0);
        int i = s1.size();
        int j = s2.size();
        int k = s3.size();
        if(i+j != k) return false;
        vector<vector<vector<int>>>dp(i+1,vector<vector<int>>(j+1,vector<int>(k+1,-1)));
        bool ans = solveByMemo(s1,s2,s3,0,0,0,dp);
        return ans;
    }
};