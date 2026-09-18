class Solution {
public:
    int solveByRec(string s1,string s2,int i,int j){
        int minAns = 0;
        if(i>=s1.size() || j>=s2.size()){
            for(int x= i ;x<s1.size();x++) minAns+=s1[x];
            for(int x = j;x<s2.size();x++) minAns+=s2[x];
        }else if(s1[i] == s2[j]){
            minAns = solveByRec(s1,s2,i+1,j+1);
        }else{
            int st = s1[i] + solveByRec(s1,s2,i+1,j);
            int nd = s2[j] + solveByRec(s1,s2,i,j+1);
            
            minAns = min(st,nd);
        }
        return minAns;
    }
    int solveByMemo(string s1,string s2,int i,int j,vector<vector<int>>&dp){
        if(dp[i][j] != -1) return dp[i][j];
        int minAns = 0;
        if(i>=s1.size() || j>=s2.size()){
            for(int x= i ;x<s1.size();x++) minAns+=s1[x];
            for(int x = j;x<s2.size();x++) minAns+=s2[x];
        }else if(s1[i] == s2[j]){
            minAns = solveByMemo(s1,s2,i+1,j+1,dp);
        }else{
            int st = s1[i] + solveByMemo(s1,s2,i+1,j,dp);
            int nd = s2[j] + solveByMemo(s1,s2,i,j+1,dp);
            
            minAns = min(st,nd);
        }
        return dp[i][j]= minAns;
        
    }
    int solveByTabu(string s1,string s2){
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i = s1.size();i>=0;i--){
            for(int j = s2.size();j>=0;j--){
                int minAns = 0;
            if(i>=s1.size() || j>=s2.size()){
                for(int x= i ;x<s1.size();x++) minAns+=s1[x];
                for(int x = j;x<s2.size();x++) minAns+=s2[x];
            }else if(s1[i] == s2[j]){
                minAns = dp[i+1][j+1];
            }else{
                int st = s1[i] + dp[i+1][j];
                int nd = s2[j] + dp[i][j+1];
            
                minAns = min(st,nd);
            }
            dp[i][j]= minAns;
            }
        }
        return dp[0][0];
    }
    int minimumDeleteSum(string s1, string s2) {
        // int ans= solveByRec(s1,s2,0,0);
        // int n = s1.size();
        // int m = s2.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // int ans= solveByMemo(s1,s2,0,0,dp);
        int ans= solveByTabu(s1,s2);
        return ans;
    }
};