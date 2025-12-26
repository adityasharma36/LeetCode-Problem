class Solution {
public:
    // int recursiveSol(vector<int>& nums,int lastIndex,int curr){
    //     if(curr>=nums.size()) return 0;

    //     int curEle = nums[curr];
    //     int inc = 0;
    //     if(lastIndex == -1 || curEle > nums[lastIndex]){
    //         inc = 1 + recursiveSol(nums,curr,curr+1);
    //     }
    //     int exc = recursiveSol(nums,lastIndex , curr+1);

    //     int finalAns = max(inc,exc);
    //     return finalAns;
    // }
    int solveByMemo(vector<int>& nums,vector<vector<int>>& dp,int lastIndex,int curr){
        if(curr>= nums.size()) return 0;

        if(dp[lastIndex+1][curr]!= -1) return dp[lastIndex+1][curr];

        int incld = 0;
        int curEle = nums[curr];
        if(lastIndex==-1 || curEle > nums[lastIndex]){
            incld = 1+ solveByMemo(nums,dp,curr,curr+1);
        }
        int excld = solveByMemo(nums,dp,lastIndex,curr+1);

        dp[lastIndex+1][curr]= max(incld,excld);
        return dp[lastIndex+1][curr];
    }
    int solveByTab(vector<int>& nums){
         vector<vector<int>>dp(nums.size()+2,vector<int>(nums.size()+2,0));

         for(int i = nums.size()-1;i>=-1;i--){
            for(int j = nums.size()-1;j>=0;j--){
                   int incld = 0;

            int curEle = nums[j];
            if(i==-1 || curEle > nums[i]){
            incld = 1+ dp[j+1][j+1];
            }
            int excld = dp[i + 1][j + 1];

            dp[i+1][j]= max(incld,excld);
            }
         }
         return dp[0][0];
    }
    int lengthOfLIS(vector<int>& nums) {
        // return recursiveSol(nums,-1,0);
        // vector<vector<int>>dp(nums.size()+2,vector<int>(nums.size()+2,-1));
        // return solveByMemo(nums,dp,-1,0);
        return solveByTab(nums);
    }
};