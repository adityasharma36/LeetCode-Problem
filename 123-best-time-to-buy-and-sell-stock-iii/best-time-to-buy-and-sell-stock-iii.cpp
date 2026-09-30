class Solution {
public:
    int solveByRec(vector<int>& nums,int i,int sell,int limit){
        if(i>=nums.size() || limit == 0){
            return 0;
        }
        int profit = 0;
        if(sell){
            int iclBuy = -nums[i] + solveByRec(nums,i+1,0,limit);
            int excBuy = solveByRec(nums,i+1,1,limit);
            profit = max(iclBuy,excBuy);
        }else{
            int incSell = nums[i] + solveByRec(nums,i+1,1,limit-1);
            int excSell = solveByRec(nums,i+1,0,limit);
            profit = max(incSell,excSell);
        }
        return profit;
    }
    int solveByMemo(vector<int>&nums,int i,int sell,int limit,vector<vector<vector<int>>>&dp){
        if(i>=nums.size() || limit <= 0){
            return 0;
        }
        if(dp[i][sell][limit] != -1) return dp[i][sell][limit];
        int profit = 0;
        if(sell){
            int iclBuy = -nums[i] + solveByMemo(nums,i+1,0,limit,dp);
            int excBuy = solveByMemo(nums,i+1,1,limit,dp);
            profit = max(iclBuy,excBuy);
        }else{
            int incSell = nums[i] + solveByMemo(nums,i+1,1,limit-1,dp);
            int excSell = solveByMemo(nums,i+1,0,limit,dp);
            profit = max(incSell,excSell);
        }
        return dp[i][sell][limit] = profit;
    }
    int solveByTabu(vector<int>& nums){
        int n = nums.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

        for(int i = n-1;i>=0;i--){
            for(int j = 0;j<2;j++){
                for(int k = 0;k<3;k++){
                      int profit = 0;
                        if(j){
                        int iclBuy = -nums[i] + dp[i+1][0][k];
                        int excBuy = dp[i+1][1][k];
                        profit = max(iclBuy,excBuy);
                        }else{
                            int incSell = 0;
                        if(k-1>=0){
                           incSell = nums[i] + dp[i+1][1][k-1];

                        }
                        int excSell = dp[i+1][0][k];
                        profit = max(incSell,excSell);
                    }
            dp[i][j][k] = profit;
                }
            }
        }
        return dp[0][1][2];

    }
    int maxProfit(vector<int>& prices) {
        // int ans = solveByRec(prices,0,1,2);
        // int n  = prices.size();
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        // int ans = solveByMemo(prices,0,1,2,dp);
        int ans = solveByTabu(prices);
        return ans;
    }
};