class Solution {
public:
    int recursiveSol(vector<int>&nums,int i){
        if(i>=nums.size()) return 0;

        int incl = nums[i] + recursiveSol(nums,i+2);
        int excl = 0 + recursiveSol(nums,i+1);

        return max(incl,excl);
    }
    int solveByMemo(vector<int>& nums,int i,vector<int>&dp){
        if(i>=nums.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int incl = nums[i] + solveByMemo(nums,i+2,dp);
        int excl = solveByMemo(nums,i+1,dp);

        dp[i] = max(incl,excl);
        return dp[i];
    }
    int solveByTabu(vector<int>& nums)
    {
        vector<int>dp(nums.size()+1,0);
        int n = nums.size();
        for(int i = n-1;i>=0;i--){
            int incl = 0;
            if(i+2<n){
                incl = nums[i]+ dp[i+2];
            }else{
                incl = nums[i];
            }
            int excl = dp[i+1];
            dp[i]= max(incl,excl);
        }
        return dp[0];
    }
    int rob(vector<int>& nums) {
        // return recursiveSol(nums,0);
        // vector<int>dp(nums.size()+1,-1);
        // return solveByMemo(nums,0,dp);

        return solveByTabu(nums);

    }
};