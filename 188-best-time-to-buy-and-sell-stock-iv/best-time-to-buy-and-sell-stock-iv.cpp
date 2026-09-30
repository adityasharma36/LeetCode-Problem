class Solution {
public:

    int solveByRec(int k, vector<int>& nums, int i, int sell) {

        if(i >= nums.size() || k <= 0) {
            return 0;
        }

        int profit = 0;

        if(sell) {

            int inclBuy =
                -nums[i] + solveByRec(k, nums, i + 1, 0);

            int exclBuy =
                solveByRec(k, nums, i + 1, 1);

            profit = max(inclBuy, exclBuy);

        }
        else {

            int inclSell =
                nums[i] + solveByRec(k - 1, nums, i + 1, 1);

            int exclSell =
                solveByRec(k, nums, i + 1, 0);

            profit = max(inclSell, exclSell);
        }

        return profit;
    }


    int solveByMemo(
        vector<int>& prices,
        int i,
        int sell,
        int k,
        vector<vector<vector<int>>>& dp
    ) {

        if(i >= prices.size() || k <= 0) {
            return 0;
        }

        if(dp[i][sell][k] != -1) {
            return dp[i][sell][k];
        }

        int profit = 0;

        if(sell) {

            int inclBuy =
                -prices[i] +
                solveByMemo(prices, i + 1, 0, k, dp);

            int exclBuy =
                solveByMemo(prices, i + 1, 1, k, dp);

            profit = max(inclBuy, exclBuy);

        }
        else {

            int inclSell =
                prices[i] +
                solveByMemo(prices, i + 1, 1, k - 1, dp);

            int exclSell =
                solveByMemo(prices, i + 1, 0, k, dp);

            profit = max(inclSell, exclSell);
        }

        return dp[i][sell][k] = profit;
    }


    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(2, vector<int>(k + 1, -1))
        );

        // Recursion
        // int ans = solveByRec(k, prices, 0, 1);

        // Memoization
        int ans = solveByMemo(prices, 0, 1, k, dp);

        return ans;
    }
};