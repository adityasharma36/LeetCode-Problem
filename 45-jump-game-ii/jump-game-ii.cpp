class Solution {
public:
    int minJump(vector<int>& nums,int i ){
        
        if(i>=nums.size()-1) return 0;

        int min_jump = 1e9;
        for(int j = 1;j<=nums[i];j++){
            int jumps = minJump(nums,j+i);

            if(jumps != 1e9){
                min_jump = min(min_jump,1+ jumps);
            }
        }   

        return min_jump;

    }
    int memo(vector<int>& nums,int i ,vector<int>&dp){
           if(i>=nums.size()-1) return 0;

           if(dp[i]!=-1) return dp[i];

        int min_jump = 1e9;
        for(int j = 1;j<=nums[i];j++){
            int jumps = memo(nums,j+i,dp);

            if(jumps != 1e9){
                min_jump = min(min_jump,1+ jumps);
            }
        }   

        return dp[i] = min_jump;
    }
    int jump(vector<int>& nums) {
        // return minJump(nums,0);
        int n = nums.size();
        vector<int>dp(n,-1);
        return memo(nums,0,dp);
    }
};