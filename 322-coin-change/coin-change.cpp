class Solution {
public:
    int solveByRec(vector<int>& coins,int amount){
       if(amount ==0) return 0;
        int minAns = INT_MAX;
        for(int j = 0;j<coins.size();j++){
            int coin = coins[j];
            if(amount>=coin){
                int recursiveAns = solveByRec(coins,amount-coin);
                if(recursiveAns != INT_MAX){
                    int coinUsed = 1+ recursiveAns;
                    minAns = min(minAns,coinUsed);
                }
            }
        }
        return minAns;
    }
    int solveByMemo(vector<int>& coins,int amount,vector<int>&dp){
        if(amount == 0) return 0;
        if(dp[amount] != -1) return dp[amount];
        int ans = INT_MAX;
        for(int i = 0;i<coins.size();i++){
            int coin = coins[i];
            if(amount>= coin){
                int recursiveAns = solveByMemo(coins,amount-coin,dp);
                if(recursiveAns!= INT_MAX){
                    int currAns= 1+ recursiveAns;
                    ans = min(ans,currAns);
                }
            }
        }
        return dp[amount]= ans;
    }
    int solveByTabu(vector<int>& coins,int amount){
       
        vector<int>dp(amount+1 , -1);

       dp[0]= 0;
       for(int amt = 1;amt<=amount;amt++){
            int ans = INT_MAX;
            for(int i = 0;i<coins.size();i++){
                int coin = coins[i];
                if(amt>= coin){
                    int recursiveAns = dp[amt-coin];
                    if(recursiveAns!= INT_MAX){
                        int currAns= 1+ recursiveAns;
                        ans = min(ans,currAns);
                    }
                }
                        dp[amt] = ans;
            }
       }
       return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        // int ans =  solveByRec(coins,amount);
        int n = coins.size();
        vector<int>dp(amount+1,-1); 
        // int ans =  solveByMemo(coins,amount,dp);
        int ans = solveByTabu(coins,amount);
        return ans == INT_MAX ? -1 : ans;
    
    }


};