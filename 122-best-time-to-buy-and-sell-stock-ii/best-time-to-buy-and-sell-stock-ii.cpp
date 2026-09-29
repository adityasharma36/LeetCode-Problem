class Solution {
public:
    int solveByRec(vector<int>& nums,int i,int buy){
        if(i>=nums.size()) return 0;
        int profit = 0;
        if(buy){
            int inclBuy = - nums[i] + solveByRec(nums,i+1,0);
            int exclBuy = solveByRec(nums,i+1,1);
            profit = max(inclBuy,exclBuy);
        }else{
            int incSell = nums[i] + solveByRec(nums,i+1,1);
            int excSell = solveByRec(nums,i+1,0);
            profit = max(incSell,excSell);
        }
        return profit;
    }
    int solveByMemo(vector<int>& nums,int i,int sell,vector<vector<int>>&dp){
        if(i>=nums.size()) return 0;
        if(dp[i][sell] != -1) return dp[i][sell];
        int profit = 0;
        if(sell){
            int inclBuy = -nums[i] + solveByMemo(nums,i+1,0,dp);
            int exclBuy = solveByMemo(nums,i+1,1,dp);
            profit = max(inclBuy,exclBuy);
        }else{
            int inclSell = nums[i] + solveByMemo(nums,i+1,1,dp);
            int exclSell = solveByMemo(nums,i+1,0,dp);
            profit = max(inclSell,exclSell);
        }
        return dp[i][sell] = profit;
    }
    int maxProfit(vector<int>& prices) {
        // int ans = solveByRec(prices,0,1);
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        int ans = solveByMemo(prices,0,1,dp);
        return ans;
    }
};