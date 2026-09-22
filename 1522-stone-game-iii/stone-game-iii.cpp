class Solution {
public:
    int solveByRec(vector<int>& stoneValue,int i){
        if(i== stoneValue.size()) return 0;
        int ans = INT_MIN;
        int sum = 0;
        for(int x = 1;x<=3;x++){
            if(i+x-1 >=stoneValue.size()) break;
            sum+=stoneValue[i+x-1];
            ans = max(ans,sum - solveByRec(stoneValue,i+x));
        }
        return ans;
    }
    int solveByMemo(vector<int>&stone,int i,vector<int>& dp){
        if(i == stone.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = INT_MIN;
        int sum = 0;
        for(int x = 1;x<=3;x++){
            if(x+i-1 >= stone.size()) break;
            sum+=stone[x+i-1];
            ans = max(ans,sum- solveByMemo(stone,i+x,dp));
        }
        return dp[i]= ans;
    }
    int solveByTabu(vector<int>& stone){
        int n = stone.size();
        vector<int>dp(n+1,0);
        for(int i = n-1;i>=0;i--){
            int ans = INT_MIN;
            int sum = 0;
            for(int x = 1;x<=3;x++){
                if(x+i-1 >= stone.size()) break;
                sum+=stone[x+i-1];
                ans = max(ans,sum- dp[i+x]);
            }
            dp[i]= ans;
        }
        return dp[0];
    }
    string stoneGameIII(vector<int>& stoneValue) {
        // int ans = solveByRec(stoneValue,0);
        // int n = stoneValue.size();
        // vector<int>dp(n+1,-1);
        // int ans = solveByMemo(stoneValue,0,dp);
        int ans = solveByTabu(stoneValue);
        if(ans >0) return "Alice";
        if(ans<0) return "Bob";
        return "Tie";
    }
};