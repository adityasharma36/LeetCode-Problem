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
    int solveByTabu(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int i = n-1;i>=0;i--){
            for(int j = 1;j>=0;j--){
                int profit = 0;
                if(j == 1){
                    int inclBuy = -nums[i] + dp[i+1][0];
                    int exclBuy = dp[i+1][1];
                    profit = max(inclBuy,exclBuy);
                }else{
                    int inclSell = nums[i] + dp[i+1][1];
                    int exclSell = dp[i+1][0];
                    profit = max(inclSell,exclSell);
                }
                dp[i][j] = profit;
                }
            }
        return dp[0][1];
    }
    int spaceOp(vector<int>& nums){
        vector<int>curr(2,0);
        vector<int>next(2,0);
        int n = nums.size();
        for(int i = n-1;i>=0;i--){
            for(int j = 1;j>=0;j--){
                int profit = 0;
                if(j == 1){
                    int inclBuy = -nums[i] + next[0];
                    int exclBuy =next[1];
                    profit = max(inclBuy,exclBuy);
                }else{
                    int inclSell = nums[i] + next[1];
                    int exclSell = next[0];
                    profit = max(inclSell,exclSell);
                }
                curr[j] = profit;
                }
                next = curr;
            }
        return next[1];
    }
    int maxProfit(vector<int>& prices) {
        // int ans = solveByRec(prices,0,1);
        int n = prices.size();
        // vector<vector<int>>dp(n+1,vector<int>(2,-1));
        // int ans = solveByMemo(prices,0,1,dp);
        // int ans = solveByTabu(prices);
        int ans = spaceOp(prices);
        return ans;
    }
};