class Solution {
public:
    bool solveByRec(vector<int>& nums,int sum, int i ){
        if(sum==0) return true;
        if(i>= nums.size()) return false;

        bool take = solveByRec(nums,sum-nums[i],i+1);
        bool notTake = solveByRec(nums,sum,i+1);

        return take || notTake;
    }
    bool solveByMemo(vector<int>&nums,int sum ,int i,vector<vector<int>>&dp){
        if(sum==0) return true;
        if(i>=nums.size()) return false;
  

        if(dp[i][sum] != -1) return dp[i][sum];
        bool take = false;
        if(sum>=nums[i]){
         take = solveByMemo(nums,sum-nums[i],i+1,dp);

        }
        bool notTake = solveByMemo(nums,sum,i+1, dp);

        dp[i][sum]= take || notTake;
        return dp[i][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(begin(nums),end(nums),0);
        if(sum%2!=0) return false;

        int half = sum/2;
        // return solveByRec(nums,half,0);
        int n = nums.size(); 
        vector<vector<int>>dp(n+1,vector<int>(half+1,-1));
        return solveByMemo(nums,half,0,dp);
    }
};