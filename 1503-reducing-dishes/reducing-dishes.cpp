class Solution {
public:
    int solveByRec(vector<int>&nums,int i,int time){
        if(i>=nums.size()) return 0;
        int incl = nums[i] * time + solveByRec(nums,i+1,time+1);
        int excl = solveByRec(nums,i+1,time);
        return max(incl,excl);
    }
    int solveByMemo(vector<int>& nums,int i,int time,vector<vector<int>>&dp){
        if(i>=nums.size()) return 0;
        if(dp[i][time] != -1 ) return dp[i][time];
        int incl = nums[i] * time + solveByMemo(nums,i+1,time+1,dp);
        int excl = solveByMemo(nums,i+1,time,dp);
        return dp[i][time]= max(incl,excl);
    }
    int solveByTabu(vector<int>&nums){
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+4,0));
        for(int i = n-1;i>=0;i--){
            for(int j = n+1;j>=1;j--){
               
           
                   int incl = nums[i] * j + dp[i+1][j+1];
                int excl = dp[i+1][j];
                dp[i][j]= max(incl,excl);
            }
        }
        return dp[0][1];
    }
    int spaceOp(vector<int>&nums){
        int n = nums.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+4,0));
        vector<int>curr(n+4,0);
        vector<int>next(n+4,0);
        for(int i = n-1;i>=0;i--){
            for(int j = n+1;j>=1;j--){
               
           
                   int incl = nums[i] * j + next[j+1];
                int excl =next[j];
               curr[j]= max(incl,excl);
            }
            next = curr;
        }
        return next[1];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(begin(satisfaction),end(satisfaction));
        // int ans = solveByRec(satisfaction,0,1);
        // int n = satisfaction.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // int ans = solveByMemo(satisfaction,0,1,dp);
        // int ans = solveByTabu(satisfaction);
        int ans = spaceOp(satisfaction);

        return ans;
    }
};