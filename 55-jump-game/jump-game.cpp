class Solution {
public:
    
    // bool isPossible(vector<int>& nums,int index){

    //     if(index == nums.size()-1) return true;

    //     if(index>= nums.size()) return false;

    //     bool ans  = false;

    //     for(int i = 1;i<= nums[index];i++){

    //         ans = ans || isPossible(nums,index+i);

    //     }
    //     return ans;
    // }

    bool solveByMemo(vector<int>& nums,int index,vector<int>& dp){

        if(index == nums.size()-1) return true;

        if(index>= nums.size()) return false;

        if(dp[index] != -1) return dp[index];

        bool ans  = false;

        for(int i = 1;i<= nums[index];i++){

            ans = ans || solveByMemo(nums,index+i,dp);

        }
        dp[index]= ans;

        return dp[index];
    }
    bool solveByTab(vector<int>& nums){
        vector<int>dp(nums.size()+1,0);
        dp[nums.size()-1] = 1;

        for(int index = nums.size()-2;index>=0;index--){
              bool ans  = false;

            for(int i = 1;i<= nums[index];i++){

                if(index + i<nums.size()){

                ans = ans || dp[index+i];
             }

            }
            dp[index]= ans;   
        }
        return dp[0];
    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        // return solveByMemo(nums,0,dp);
        return solveByTab(nums);
    }
};