class Solution {
public:
    int robber(vector<int>& nums,int index,int end){
        if(index > end){

            return 0;

        }

        int incl = nums[index] + robber(nums,index+2,end);
        int excl = robber(nums,index+1,end);
  
        
        return max(incl,excl);
    }
    int Memo(vector<int>& nums,int start,int end,vector<int>& dp){

        if(start>end) return 0;

        if(dp[start]!= -1) return dp[start];

         int incl = nums[start] + Memo(nums,start+2,end,dp);
        int excl = Memo(nums,start+1,end,dp);
  
        
        dp[start] = max(incl,excl);

        return dp[start];

    }
    int tabu(vector<int>&nums,int start,int end){

        int n = nums.size();

        vector<int>dp(n+2,0);

        for(int i = end;i>=start;i--){

            int incl = nums[i] + dp[i+2];
            int excl = dp[i+1];
  
        
            dp[i] = max(incl,excl);
        }
        return dp[start];
    }
    int rob(vector<int>& nums) {

        if(nums.size()==1) return nums[0];

        
        // int firstLast = robber(nums,0,nums.size()-2);
        // int secondLast = robber(nums,1,nums.size()-1);
        // return max(firstLast,secondLast);

        // Part ----> 1 Memoziation 

        // vector<int>dp1(nums.size(),-1),dp2(nums.size(),-1);

        // int firstLast = Memo(nums,0,nums.size()-2,dp1);
        // int secondLast = Memo(nums,1,nums.size()-1,dp2);
        // return max(firstLast,secondLast);

        int firstLast = tabu(nums,0,nums.size()-2);
        int secondLast = tabu(nums,1,nums.size()-1);

        return max(firstLast,secondLast);


    }
};