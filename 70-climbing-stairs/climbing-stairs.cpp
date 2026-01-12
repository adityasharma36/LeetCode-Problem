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
    int solveByTab(int  n){
        vector<int>dp(n+1,0);

        dp[0]=1;
        if(n>=1) dp[1] = 1;

        for(int i = 2;i<=n;i++){
            
            dp[i]= dp[i-1]+ dp[i-2];
          
        }
       return dp[n];
    }
    int spaceOptimise(int n){
        if(n<=1) return 1;
        int prev = 1;
        int prev2 = 1;

        for(int i = 2;i<=n;i++){
            int curr = prev+ prev2;
            prev = prev2;
            prev2 = curr;
        }
        return prev2;
    }
    int climbStairs(int n) {
        // vector<int>dp(n+1,-1);
        // return stairsClimb(n);
        // return solveByMemo(n,dp);
        // return solveByTab(n);
        return spaceOptimise(n);
    }
};