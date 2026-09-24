class Solution {
public:
    int solveByRec(vector<int>& nums,int start,int end){
        if(start>end) return 0;
        int ans = INT_MIN;
        for(int i = start;i<=end;i++){
            ans = max(ans,nums[i]* nums[start-1]* nums[end+1]+ solveByRec(nums,start,i-1)+ solveByRec(nums,i+1,end));
        }
        return ans;
    }
    int solveByMemo(vector<int>& nums,int start,int end , vector<vector<int>>&dp){
        if(start>end) return 0;
        if(dp[start][end] != -1) return dp[start][end];
        int ans = INT_MIN;
        for(int i = start;i<=end;i++){
            ans = max(ans,nums[start-1]*nums[i]*nums[end+1] + solveByMemo(nums,start,i-1,dp) + solveByMemo(nums,i+1,end,dp));
        }
       return  dp[start][end]= ans;

    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        // int ans = solveByRec(nums,1,nums.size()-2);
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans = solveByMemo(nums,1,nums.size()-2,dp);
        return ans;
    }
};