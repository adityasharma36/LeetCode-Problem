class Solution {
public:
    int solveByRec(int start,int end){
        if(start>end) return 1;
        int ans = 0;
        for(int i = start;i<=end;i++){
            int left= solveByRec(start,i-1);
            int right = solveByRec(i+1,end);
            ans += left*right;
        }
        return ans;
    }
    int solveByMemo(int start,int end,vector<vector<int>>&dp){
        if(start>end) return 1;
        if(dp[start][end] != -1) return dp[start][end];
        int ans = 0;
        for(int i = start;i<=end;i++){
            int leftSide = solveByMemo(start,i-1,dp);
            int rightSide = solveByMemo(i+1,end,dp);
            ans += leftSide* rightSide;
        }
        return dp[start][end]= ans;
        
    }
    int numTrees(int n) {
        // int ans = solveByRec(1,n);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans = solveByMemo(1,n,dp);
        return ans;
    }
};