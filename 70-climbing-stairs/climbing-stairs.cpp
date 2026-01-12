class Solution {
public:
    int stairsClimb(int n){
        if(n==0){
            return 1;
        }
        if(n<0) return 0;

       int inclde = stairsClimb(n-1);
       int exclde = stairsClimb(n-2);
       return inclde+ exclde;
    }
    int solveByMemo(int n,vector<int>& dp){
        if(n == 0){
            return 1;
        }
        if(n<0) return 0;

        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n]= solveByMemo(n-1,dp)+ solveByMemo(n-2,dp);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        // return stairsClimb(n);
        return solveByMemo(n,dp);
    }
};