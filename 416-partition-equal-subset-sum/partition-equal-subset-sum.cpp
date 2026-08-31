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
    bool solveByTabu(vector<int>&nums,int sum){
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        for(int i = 0;i<n;i++){
            dp[i][0]= true;
        }
        for(int i= n-1;i>=0;i--){
            for(int j = 1;j<=sum;j++){
                bool take = false;
                if(j>=nums[i]){
                    take = dp[i+1][j-nums[i]];
                }
                bool notTake = dp[i+1][j];

                dp[i][j]= take || notTake;
            }
        }

        return dp[0][sum];
    }
    bool spaceOpti(vector<int>& nums,int sum){
        int n = nums.size();
        vector<int>prev(sum+1,0);
        vector<int> curr(sum+1,0);
        for(int i= n-1;i>=0;i--){
            curr[0]= 1;
            for(int j = 1;j<=sum;j++){
                bool take = false;
                if(j>=nums[i]){
                    take = prev[j-nums[i]];
                }
                bool notTake = prev[j];

                curr[j]= take || notTake;
            }
           prev = curr;
        }
        return prev[sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(begin(nums),end(nums),0);
        if(sum%2!=0) return false;

        int half = sum/2;
        // return solveByRec(nums,half,0);
        // int n = nums.size(); 
        // vector<vector<int>>dp(n+1,vector<int>(half+1,-1));
        // return solveByMemo(nums,half,0,dp);
        // return solveByTabu(nums,half);
        return spaceOpti(nums,half);
    }
};